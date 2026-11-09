# INTEGRATION PLAN
## CS212 Help-Desk Priority Simulation

**Purpose:** Define how the four required data structures work together to create ONE cohesive Help-Desk application.

---

## INTEGRATION PRINCIPLE

**The four data structures are NOT isolated demonstrations.**

They must work together in realistic help-desk workflows where:
- Data flows between structures
- Operations span multiple modules
- Records remain consistent
- The user experiences a unified system

---

## FOUR INTEGRATION SCENARIOS (MANDATORY)

### SCENARIO 1: CREATE NEW SERVICE REQUEST

**User Story:** A customer reports a technical issue. The help desk registers a new service request.

**Steps:**
1. **User Input** (Member 6 - MenuController)
   - Prompt for: requester name, issue title, description, category, priority
   - Validate all inputs using InputValidator
   - Generate unique request ID

2. **Create ServiceRequest Object** (Member 5 - RequestService)
   - Build ServiceRequest with user data
   - Set status = WAITING
   - Set creationTime = current timestamp
   - assignedAgentId = 0 (unassigned)

3. **Index in BST** (Member 4 - RequestIndexService)
   - Call: `indexRequest(request)`
   - BST.insertRequest() adds to tree
   - Reject if duplicate ID
   - **BST now owns the canonical request record**

4. **Enqueue for Dispatch** (Member 2 - RequestDispatcher)
   - Call: `enqueueRequest(requestId, priority)`
   - PriorityRequestQueue.enqueue() adds ID to appropriate priority queue
   - **Queue stores request ID only, not full object**

5. **Confirmation**
   - Display success message
   - Show request ID and current position in queue

**Data Flow:**
```
User Input → RequestService → [A] RequestIndexService → RequestBST (full record stored)
                            → [B] RequestDispatcher → PriorityRequestQueue (ID stored)
```

**Integration Points:**
- BST and Queue both updated
- BST stores full record (single source of truth)
- Queue stores reference (ID only)
- Status set to WAITING

**Testing:**
- Create request with HIGH priority → verify in BST and HIGH queue
- Create request with LOW priority → verify in LOW queue
- Create duplicate ID → verify rejection
- Create 5 requests → verify all indexed and queued correctly

---

### SCENARIO 2: ASSIGN NEXT REQUEST TO AGENT

**User Story:** A help-desk supervisor assigns the next highest-priority waiting request to an available agent.

**Steps:**
1. **Get Next Request** (Member 2 - RequestDispatcher)
   - Call: `getNextRequest()`
   - Checks HIGH queue → if not empty, dequeue
   - Else checks MEDIUM queue → if not empty, dequeue
   - Else checks LOW queue → if not empty, dequeue
   - Returns request ID (e.g., 1042)

2. **Retrieve Full Request** (Member 4 - RequestIndexService)
   - Call: `findRequest(1042)`
   - BST.searchRequest() finds full ServiceRequest by ID
   - Returns pointer to request

3. **Find Available Agent** (Member 3 - AgentService)
   - Call: `findAvailableAgent()`
   - AgentLinkedList.searchAgent() traverses list
   - Returns first agent with availability = AVAILABLE
   - If none available, abort assignment with error message

4. **Assign Request to Agent** (Member 5 - RequestService)
   - Call: `assignRequest(requestId, agentId)`
   - Update request: assignedAgentId = agentId, status = ASSIGNED
   - Update agent: availability = BUSY, assignedRequestCount++

5. **Confirmation**
   - Display: "Request #1042 assigned to Agent #5 (John Smith)"

**Data Flow:**
```
RequestDispatcher.getNextRequest() → PriorityRequestQueue.dequeue() → returns ID
                ↓
RequestIndexService.findRequest(ID) → RequestBST.searchRequest() → returns full request
                ↓
AgentService.findAvailableAgent() → AgentLinkedList.search() → returns agent
                ↓
RequestService.assignRequest() → updates both BST request and LinkedList agent
```

**Integration Points:**
- Request removed from Queue
- Request remains in BST but status changes
- Agent in LinkedList updated
- Both structures modified consistently

**Testing:**
- Assign when agents available → verify success
- Assign when no agents available → verify error
- Verify request removed from queue after assignment
- Verify request status updated in BST
- Verify agent availability updated in LinkedList
- Assign multiple requests → verify FIFO within priority

---

### SCENARIO 3: ESCALATE WAITING REQUEST

**User Story:** A manager escalates a waiting request from MEDIUM to HIGH priority due to urgency.

**Steps:**
1. **Find Request** (Member 4 - RequestIndexService)
   - User provides request ID (e.g., 2058)
   - Call: `findRequest(2058)`
   - BST.searchRequest() retrieves request
   - Verify request exists

2. **Record Escalation** (Member 1 - EscalationService)
   - Call: `recordEscalation(2058, MEDIUM, HIGH, "Customer VIP status")`
   - Create EscalationEvent object
   - EscalationStack.push() adds event to top of stack
   - **Stack now has escalation history**

3. **Update Request Priority** (Member 5 - RequestService)
   - Call: `escalateRequest(2058, HIGH, "Customer VIP status")`
   - Find request in BST
   - Update request.priority = HIGH
   - BST record updated

4. **Update Queue Membership** (Member 2 - RequestDispatcher)
   - If request status = WAITING:
     - Remove request ID from MEDIUM queue
     - Add request ID to HIGH queue
   - If request already ASSIGNED or RESOLVED, queue update not needed

5. **Confirmation**
   - Display: "Request #2058 escalated from MEDIUM to HIGH"
   - Show escalation reason

**Data Flow:**
```
User selects request ID
        ↓
RequestIndexService → BST (find request)
        ↓
EscalationService → EscalationStack.push() (record history)
        ↓
RequestService updates BST (change priority)
        ↓
If WAITING: RequestDispatcher updates queues (move between queues)
```

**Integration Points:**
- **Stack** records the escalation event (LIFO history)
- **BST** priority field updated
- **Queue** membership updated if request still waiting
- All three structures modified for one escalation action

**Testing:**
- Escalate WAITING request → verify moved between queues
- Escalate ASSIGNED request → verify queue unchanged
- Display escalation history → verify LIFO order from Stack
- Multiple escalations → verify Stack has correct sequence

---

### SCENARIO 4: GENERATE SORTED REPORT

**User Story:** Supervisor requests a report showing all requests sorted by priority, then by ID.

**Steps:**
1. **Retrieve All Requests** (Member 4 - RequestIndexService)
   - Call: `getAllRequests()`
   - RequestBST.inorderTraversal() fills vector
   - Returns vector of all ServiceRequest objects

2. **Sort Requests** (Member 6 - RequestSort)
   - Call: `sortRequests(requestVector, "priority")`
   - **Merge Sort algorithm** sorts array
   - Primary key: priority (HIGH > MEDIUM > LOW)
   - Secondary key: request ID (ascending)
   - Returns sorted vector

3. **Display Report** (Member 5 - HelpDeskCoordinator)
   - Call: `generateStatisticsReport()`
   - Iterate through sorted vector
   - Display formatted table:
     - Request ID | Priority | Status | Assigned Agent | Issue Title
   - Show counts by status and priority

4. **Display Escalation History** (Member 1 - EscalationService)
   - Call: `displayEscalationHistory()`
   - EscalationStack displays recent escalations in LIFO order
   - Show top 10 escalations with reasons

5. **Output**
   - Comprehensive report showing system state
   - All requests sorted by business priority
   - Recent escalation activity

**Data Flow:**
```
RequestIndexService → BST.inorderTraversal() → unsorted vector
                ↓
RequestSort → Merge Sort O(n log n) → sorted vector
                ↓
HelpDeskCoordinator → formatted report display
                ↓
EscalationService → Stack → recent escalation history (LIFO)
```

**Integration Points:**
- **BST traversal** provides all requests
- **Merge Sort** demonstrates course algorithm requirement
- **Stack** provides escalation context
- Report combines data from multiple structures

**Testing:**
- Generate report with 10 requests → verify sorted correctly
- Verify HIGH priority before MEDIUM before LOW
- Verify escalation history shows most recent first (LIFO)
- Empty system → report shows zero requests gracefully

---

## CROSS-STRUCTURE DATA CONSISTENCY RULES

### Rule 1: BST is Canonical Source
- **BST** owns full ServiceRequest records
- **Queue** stores request IDs only (references)
- **Stack** stores escalation events (separate objects)
- When request data changes, update BST first

### Rule 2: Queue Reflects Status
- Request with status WAITING must be in appropriate priority queue
- Request with status ASSIGNED, IN_PROGRESS, RESOLVED, or CLOSED must NOT be in any queue
- When status changes from WAITING, remove from queue
- When priority changes while WAITING, update queue membership

### Rule 3: Agent Availability Matches Assignments
- Agent with availability AVAILABLE must have no assigned requests (or assignedRequestCount = 0)
- Agent with availability BUSY must have assigned requests
- When request assigned, agent becomes BUSY
- When request resolved/closed, check if agent has other assignments before setting AVAILABLE

### Rule 4: Stack is Append-Only History
- Escalation events are never removed or modified
- Stack grows with each escalation
- Stack provides audit trail

### Rule 5: Request ID Uniqueness
- Request ID is unique across entire system
- BST enforces uniqueness (rejects duplicates)
- Queue entries reference existing BST IDs
- Validation happens at creation time

---

## SYNCHRONIZATION WORKFLOWS

### Workflow: Create Request
```
1. Generate unique ID
2. BST.insert() → SUCCESS or DUPLICATE_ID
3. If SUCCESS:
     Queue.enqueue(ID, priority)
     Display confirmation
4. If DUPLICATE:
     Reject, prompt for new ID
```

### Workflow: Cancel Request
```
1. Find request in BST
2. If found and status = WAITING:
     Queue.removeRequestById(ID)
     BST.deleteRequest(ID)
3. Else if found and status = ASSIGNED:
     Update agent availability
     BST.deleteRequest(ID)
4. Display confirmation
```

### Workflow: Resolve Request
```
1. Find request in BST
2. Update status = RESOLVED
3. If assignedAgentId != 0:
     Find agent in LinkedList
     agent.availability = AVAILABLE (if no other assignments)
     agent.assignedRequestCount--
4. Request remains in BST (history)
```

### Workflow: Escalate Request
```
1. Find request in BST
2. Validate newPriority > oldPriority
3. Stack.push(escalationEvent)
4. Update request.priority in BST
5. If request.status = WAITING:
     Queue.removeRequestById(ID)  // from old queue
     Queue.enqueue(ID, newPriority) // to new queue
6. Display confirmation
```

---

## ERROR HANDLING ACROSS MODULES

### Error: BST Insert Fails (Duplicate ID)
- Do NOT enqueue to Queue
- Reject entire create operation
- Prompt user for different ID

### Error: Queue is Empty (No Waiting Requests)
- Assignment operation cannot proceed
- Display: "No waiting requests available"
- Suggest user create new request

### Error: No Available Agent
- Request remains in Queue
- Display: "All agents busy. Request remains in queue."
- Suggest retry later or add more agents

### Error: Request Not Found in BST
- Cannot escalate, assign, or update
- Display: "Request ID not found"
- Suggest search to verify ID

### Error: Agent Not Found
- Cannot assign request
- Display: "Agent ID not found"
- List available agents

---

## INTEGRATION TESTING CHECKLIST

| Test Scenario | Structures Involved | Expected Outcome |
|--------------|---------------------|------------------|
| Create 1 request | BST + Queue | Request in both |
| Create 10 requests, mixed priorities | BST + Queue | All indexed, queued by priority |
| Assign next request | Queue + BST + LinkedList | Request dequeued, assigned, agent busy |
| Escalate waiting request | Stack + BST + Queue | Event in Stack, priority updated, queue moved |
| Cancel waiting request | BST + Queue | Removed from both |
| Resolve assigned request | BST + LinkedList | Status updated, agent available |
| Generate sorted report | BST + Sort algorithm | All requests sorted correctly |
| Display escalation history | Stack | Recent escalations in LIFO order |
| Create duplicate ID | BST | Rejected, not queued |
| Assign with no agents | Queue + BST + LinkedList | Error, request stays in queue |

---

## MEMBER INTEGRATION RESPONSIBILITIES

### All Members:
- Implement your module to match API_CONTRACTS.md
- Test your module independently first
- Participate in integration testing sessions
- Fix integration issues in YOUR module
- Communicate API changes immediately

### Member 5 (Integration Coordinator):
- Design integration workflows
- Coordinate cross-module testing
- Identify inconsistencies
- Call integration meetings
- **NOT responsible for implementing other members' modules**

---

## INTEGRATION TIMELINE

**Week 2: Module Integration Begins**
- Members 1-4 complete data structure implementations
- Member 6 completes validation utilities
- Member 5 begins connecting services

**Week 3: Full Integration**
- All four scenarios working end-to-end
- Cross-module testing
- Consistency verification
- Bug fixes

**Week 4: Integration Polish**
- Edge case testing
- Error handling verification
- Performance testing
- Documentation

---

## INTEGRATION SUCCESS CRITERIA

✅ All four scenarios execute without errors  
✅ Data remains consistent across structures  
✅ No duplicate records  
✅ No dangling references  
✅ No memory leaks  
✅ Graceful error handling  
✅ Clear user feedback  
✅ Every team member understands integration  

---

**Integration is NOT one person's job. It's the team working as ONE system.**

**Start integration EARLY. Don't wait until the last week.**
