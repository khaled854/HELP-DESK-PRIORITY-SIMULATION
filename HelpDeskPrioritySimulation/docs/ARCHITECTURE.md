# SYSTEM ARCHITECTURE
## Help-Desk Priority Simulation - CS212 Project #89

---

## 1. ARCHITECTURAL OVERVIEW

This document specifies the complete software architecture for the Help-Desk Priority Simulation system as required by CS212 Data Structures project guidelines (Official PDF, Project #89, Page 9).

### 1.1 System Purpose

The system manages help-desk service requests through:
- **Request registration and tracking**
- **Priority-based dispatching**
- **Agent assignment and management**
- **Escalation history tracking**
- **Search and reporting capabilities**

### 1.2 Architectural Goals

1. **Satisfy all mandatory PDF requirements** (R1-R10, Pages 2-3)
2. **Demonstrate meaningful integration** of four required data structures
3. **Enable fair six-member workload distribution**
4. **Maintain clear module boundaries and responsibilities**
5. **Support testing, demonstration, and individual discussion**

---

## 2. FOUR REQUIRED DATA STRUCTURES

### 2.1 STACK - Escalation History (LIFO)

**Official Role (PDF Page 9):** Recent escalations

**Implementation:** `EscalationStack` class  
**Owner:** Member 1  
**Files:** `src/data_structures/stack/EscalationStack.h/cpp`

**Purpose:**
- Records escalation events whenever a request priority is increased
- Maintains LIFO (Last-In-First-Out) ordering
- Enables display of recent escalation history

**Key Operations:**
```
push(escalationEvent)    - O(1)
pop()                    - O(1)
peek()                   - O(1)
isEmpty()                - O(1)
size()                   - O(1)
displayHistory()         - O(n)
```

**Data Stored:**
- Request ID
- Previous priority
- New priority
- Escalation reason
- Timestamp/sequence

**Integration Points:**
- Escalation Service uses Stack to record events
- Request Service triggers escalation
- Reports display recent escalation history

---

### 2.2 QUEUE - Priority Service Requests (FIFO)

**Official Role (PDF Page 9):** Priority service requests

**Implementation:** `PriorityRequestQueue` class  
**Owner:** Member 2  
**Files:** `src/data_structures/queue/PriorityRequestQueue.h/cpp`

**Purpose:**
- Maintains waiting service requests by priority level
- Preserves FIFO ordering within same priority
- Supports priority-based dispatching

**Architecture Decision:**

Three independent manually implemented FIFO queues:
- **High Priority Queue** (processed first)
- **Medium Priority Queue** (processed second)
- **Low Priority Queue** (processed last)

**Dispatcher Logic:**
```
Check HIGH queue → if not empty, dequeue
Else check MEDIUM queue → if not empty, dequeue
Else check LOW queue → if not empty, dequeue
Else return null (no waiting requests)
```

**Key Operations:**
```
enqueue(requestId, priority)  - O(1)
dequeue()                     - O(1)
front()                       - O(1)
isEmpty()                     - O(1)
size()                        - O(1)
getNextRequest()              - O(1)
```

**Data Stored:**
- Request ID (reference to canonical record in BST)
- Priority level
- Queue entry timestamp

**Integration Points:**
- Request Service adds new requests to appropriate queue
- Request Dispatcher retrieves next request by priority
- Status changes remove requests from queues
- Escalation may require queue membership update

**Known Limitation:**
Low-priority requests may experience starvation if high-priority requests continuously arrive. This is documented as a realistic system limitation.

---

### 2.3 LINKED LIST - Agent Records

**Official Role (PDF Page 9):** Agent records

**Implementation:** `AgentLinkedList` class  
**Owner:** Member 3  
**Files:** `src/data_structures/linked_list/AgentLinkedList.h/cpp`

**Purpose:**
- Maintains help-desk agent profiles
- Supports insertion, deletion, search, and traversal
- Tracks agent availability and specialization

**Key Operations:**
```
insertAgent(agent)       - O(1) or O(n) depending on insert position
deleteAgent(agentId)     - O(n)
searchAgent(agentId)     - O(n)
updateAgent(agentId)     - O(n)
displayAgents()          - O(n)
getAgentCount()          - O(1) or O(n)
isEmpty()                - O(1)
```

**Node Structure:**
```
AgentNode:
  - Agent data (agentId, name, specialization, availability, assignedCount)
  - Pointer to next node
```

**Data Stored:**
- Unique agent ID
- Agent name
- Specialization
- Availability status (AVAILABLE, BUSY)
- Number of assigned requests (optional)

**Integration Points:**
- Agent Service manages agent operations
- Request Service queries available agents
- Assignment workflow searches for suitable agents
- Reports display agent statistics

**Edge Cases:**
- Empty list
- Single agent
- First node deletion
- Last node deletion
- Duplicate agent ID prevention
- Missing agent ID handling

---

### 2.4 BINARY SEARCH TREE (BST) - Request Lookup

**Official Role (PDF Page 9):** Request lookup by ID

**Implementation:** `RequestBST` class  
**Owner:** Member 4  
**Files:** `src/data_structures/bst/RequestBST.h/cpp`

**Purpose:**
- Canonical searchable index for all service requests
- Fast lookup by unique request ID
- Supports insertion, deletion, and traversals

**Key Operations:**
```
insertRequest(request)        - O(log n) average, O(n) worst
deleteRequest(requestId)      - O(log n) average, O(n) worst
searchRequest(requestId)      - O(log n) average, O(n) worst
inorderTraversal()            - O(n)
preorderTraversal()           - O(n)
isEmpty()                     - O(1)
getSize()                     - O(1) or O(n)
```

**Node Structure:**
```
BSTNode:
  - ServiceRequest data (or pointer)
  - Pointer to left child
  - Pointer to right child
```

**Key Property:**
- Left subtree: all request IDs < current node ID
- Right subtree: all request IDs > current node ID
- Unique request IDs enforced

**Three Deletion Cases:**
1. **Leaf node:** Simply remove
2. **One child:** Replace with child
3. **Two children:** Replace with inorder successor/predecessor

**Integration Points:**
- All request operations use BST as primary index
- Queue stores request IDs, BST stores full records
- Search by ID uses BST
- Reports traverse BST for request summaries

**Complexity Note:**
The BST is NOT balanced. Average case is O(log n) with random insertions, but worst case degrades to O(n) with sorted insertions. This tradeoff is acceptable for this project scope and will be documented in complexity analysis.

---

## 3. SHARED DOMAIN MODELS

Located in `src/models/`

### 3.1 ServiceRequest

**Purpose:** Represents a help-desk service request

**Fields:**
- `int requestId` (unique, BST key)
- `string requesterName`
- `string issueTitle`
- `string issueDescription`
- `string category`
- `PriorityLevel priority` (HIGH, MEDIUM, LOW)
- `RequestStatus status` (OPEN, WAITING, ASSIGNED, IN_PROGRESS, RESOLVED, CLOSED)
- `int assignedAgentId` (0 if unassigned)
- `timestamp creationTime`

**Owner:** Member 5 (defines), all modules use

### 3.2 Agent

**Purpose:** Represents a help-desk agent

**Fields:**
- `int agentId` (unique)
- `string name`
- `string specialization`
- `AgentStatus availability` (AVAILABLE, BUSY)
- `int assignedRequestCount`

**Owner:** Member 3 (defines and manages)

### 3.3 EscalationEvent

**Purpose:** Represents an escalation action

**Fields:**
- `int requestId`
- `PriorityLevel previousPriority`
- `PriorityLevel newPriority`
- `string reason`
- `timestamp eventTime`

**Owner:** Member 1 (defines and manages)

### 3.4 PriorityLevel (enum)

**Values:** `HIGH`, `MEDIUM`, `LOW`

**Owner:** Member 5 or shared constants

### 3.5 RequestStatus (enum)

**Values:** `OPEN`, `WAITING`, `ASSIGNED`, `IN_PROGRESS`, `RESOLVED`, `CLOSED`

**Owner:** Member 5 or shared constants

---

## 4. MODULE ARCHITECTURE

### 4.1 Application Layer (`src/app/`)

**Classes:**
- `HelpDeskApp` - Main application orchestrator
- `MenuController` - Menu display and navigation

**Responsibilities:**
- Display main menu
- Route user choices to appropriate services
- Handle application lifecycle
- Coordinate user interaction

**Owner:** Member 6

---

### 4.2 Service Layer (`src/services/`)

**Classes:**

1. **EscalationService** (Member 1)
   - `recordEscalation(requestId, oldPriority, newPriority, reason)`
   - `getRecentEscalations(count)`
   - `displayEscalationHistory()`

2. **RequestDispatcher** (Member 2)
   - `enqueueRequest(requestId, priority)`
   - `getNextRequest()`
   - `displayWaitingRequests()`
   - `getQueueStatistics()`

3. **AgentService** (Member 3)
   - `addAgent(agent)`
   - `removeAgent(agentId)`
   - `findAgent(agentId)`
   - `findAvailableAgent()`
   - `updateAgentAvailability(agentId, status)`
   - `displayAllAgents()`

4. **RequestIndexService** (Member 4)
   - `indexRequest(request)`
   - `findRequest(requestId)`
   - `removeRequestFromIndex(requestId)`
   - `getAllRequests()`
   - `displayAllRequests()`

5. **RequestService** (Member 5)
   - `createRequest(request)`
   - `updateRequest(requestId, updates)`
   - `cancelRequest(requestId)`
   - `resolveRequest(requestId)`
   - `closeRequest(requestId)`
   - `escalateRequest(requestId, newPriority, reason)`
   - `assignRequest(requestId, agentId)`
   - `findRequestById(requestId)`

6. **HelpDeskCoordinator** (Member 5)
   - `processNextRequest()`
   - `assignRequestToAgent(requestId)`
   - `generateReports()`
   - Coordinates cross-service workflows

---

### 4.3 Algorithm Layer (`src/algorithms/`)

**Class:** `RequestSort` (Member 6)

**Sorting Algorithm:** Merge Sort

**Purpose:**
- Sort request summaries for reporting
- Demonstrate course sorting algorithm requirement
- Explain divide-and-conquer approach

**Operations:**
```
sortRequests(requestArray, sortKey)
mergeSort(array, left, right)
merge(array, left, mid, right)
```

**Sort Keys:**
- By priority (HIGH > MEDIUM > LOW)
- By request ID
- By creation time

**Complexity:**
- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)
- Space: O(n)

---

### 4.4 Utility Layer (`src/utils/`)

**InputValidator** (Member 6)
- `readInteger(prompt, min, max)`
- `readNonEmptyString(prompt)`
- `validateRequestId(id)`
- `validatePriority(priority)`
- `validateStatus(status)`
- `confirmAction(prompt)`

**Constants** (Shared)
- Application name and version
- Default values
- Menu strings
- Error messages

---

## 5. DATA FLOW AND INTEGRATION

### 5.1 Scenario 1: Create New Request

```
User Input (HelpDeskApp)
    ↓
MenuController.handleCreateRequest()
    ↓
RequestService.createRequest(request)
    ↓
[Branch A] RequestIndexService.indexRequest()  → BST.insertRequest()
[Branch B] RequestDispatcher.enqueueRequest()  → Queue.enqueue()
    ↓
Success confirmation
```

### 5.2 Scenario 2: Assign Next Request

```
User Action (HelpDeskApp)
    ↓
HelpDeskCoordinator.processNextRequest()
    ↓
RequestDispatcher.getNextRequest()  → Queue.dequeue()
    ↓
RequestIndexService.findRequest(id)  → BST.searchRequest()
    ↓
AgentService.findAvailableAgent()  → LinkedList.search()
    ↓
RequestService.assignRequest(requestId, agentId)
    ↓
Update request status and agent availability
```

### 5.3 Scenario 3: Escalate Request

```
User selects request ID
    ↓
RequestService.escalateRequest(id, newPriority, reason)
    ↓
[A] Find request: BST.searchRequest()
[B] Record escalation: EscalationStack.push()
[C] Update priority in BST
[D] If still waiting: update queue membership
    ↓
Confirm escalation
```

### 5.4 Scenario 4: Generate Report

```
User requests report
    ↓
HelpDeskCoordinator.generateReports()
    ↓
RequestIndexService.getAllRequests()  → BST.inorderTraversal()
    ↓
RequestSort.sortRequests(array, sortKey)  → MergeSort
    ↓
Display sorted summary
    ↓
EscalationService.displayEscalationHistory()  → Stack.display()
```

---

## 6. DEPENDENCY DIAGRAM

```
main.cpp
  ↓
HelpDeskApp
  ↓
MenuController
  ↓
┌────────────────────────────────────────┐
│       HelpDeskCoordinator              │
│         (Integration Hub)              │
└────────────────────────────────────────┘
  ↓         ↓          ↓          ↓
EscalationService  RequestService  AgentService  RequestDispatcher
  ↓                    ↓               ↓              ↓
EscalationStack    RequestIndexService  AgentLinkedList  PriorityRequestQueue
  (Stack)              ↓                (LinkedList)      (Queue)
                  RequestBST
                    (BST)

All services use shared models:
ServiceRequest, Agent, EscalationEvent, PriorityLevel, RequestStatus

InputValidator used by all user-facing modules
RequestSort used by reporting functions
```

---

## 7. MEMORY MANAGEMENT STRATEGY

### 7.1 Ownership Rules

1. **ServiceRequest canonical records:**
   - Owned by RequestBST
   - Queue stores request IDs only (references)
   - Stack stores escalation events (separate objects)

2. **Agent records:**
   - Owned by AgentLinkedList
   - Services query by ID, do not duplicate

3. **EscalationEvent records:**
   - Owned by EscalationStack
   - Created during escalation workflow

### 7.2 Lifecycle

- **Request creation:** Allocated, added to BST, ID added to queue
- **Request assignment:** Removed from queue, remains in BST
- **Request closure:** Remains in BST (or removed based on retention policy)
- **Request cancellation:** Removed from queue and BST

### 7.3 Pointer Safety

- Validate all pointers before dereferencing
- Handle nullptr cases gracefully
- Properly delete dynamically allocated memory
- No dangling pointers after deletion

---

## 8. ERROR HANDLING ARCHITECTURE

### 8.1 Input Validation (Member 6)

All user input validated before processing:
- Non-numeric menu choices
- Empty strings
- Out-of-range values
- Invalid priority/status values

### 8.2 Business Rule Validation

- Duplicate request ID rejection
- Duplicate agent ID rejection
- Non-existent ID error messages
- Operation preconditions (e.g., cannot assign closed request)

### 8.3 Data Structure Edge Cases

- Empty Stack: pop/peek returns error message
- Empty Queue: dequeue returns null or error
- Empty LinkedList: search returns not found
- Empty BST: search returns null

### 8.4 Consistency Rules

- Request status must match its queue presence
- Assigned agent must be marked BUSY
- Escalated request priority must be updated everywhere
- Deleted request must be removed from all structures

---

## 9. SCALABILITY AND LIMITATIONS

### 9.1 Current Scope

- Console-based application
- Single-user operation
- In-memory data only
- No persistence between runs

### 9.2 Known Limitations

1. **Queue starvation:** Low-priority requests may wait indefinitely
2. **Unbalanced BST:** Worst-case O(n) if IDs inserted in order
3. **Linear agent search:** O(n) to find available agent
4. **No concurrency:** Single-threaded operation
5. **Memory constraints:** Limited by available RAM

### 9.3 Realistic Improvements (for discussion)

- Implement priority queue with aging to prevent starvation
- Balance BST (AVL or Red-Black) for guaranteed O(log n)
- Add agent indexing by specialization
- Persist data to file or database
- Add request categorization and routing rules

---

## 10. TESTING ARCHITECTURE

Each module owner tests their own code. Integration testing shared.

See `TESTING_PLAN.md` for details.

**Test Levels:**
1. Unit tests per data structure
2. Service layer tests
3. Integration scenario tests
4. End-to-end application tests

---

## 11. COMPLIANCE MATRIX

| PDF Requirement | Architecture Element | Module | Status |
|----------------|---------------------|---------|---------|
| R1: C++ manual implementation | All data structures | All | ✅ Planned |
| R2: Stack | EscalationStack | Member 1 | ✅ Designed |
| R3: Queue | PriorityRequestQueue | Member 2 | ✅ Designed |
| R4: Linked List | AgentLinkedList | Member 3 | ✅ Designed |
| R5: BST | RequestBST | Member 4 | ✅ Designed |
| R6: Search/Sort | Merge Sort | Member 6 | ✅ Designed |
| R7: Usable application | HelpDeskApp + Menu | Member 6 | ✅ Designed |
| R8: Validation | InputValidator | Member 6 | ✅ Designed |
| R9: Integration | HelpDeskCoordinator | Member 5 | ✅ Designed |
| R10: Testing & analysis | All test plans | All | ✅ Planned |

---

## CONCLUSION

This architecture satisfies all mandatory CS212 project requirements while enabling clear module boundaries, fair team distribution, and meaningful data structure integration.

All source files are created empty and ready for implementation. Each team member should read this document, their specific assignment in `TEAM_ASSIGNMENT.md`, and the API contracts in `API_CONTRACTS.md` before beginning implementation.

**Next Step:** Implementation Phase - Each member implements their assigned module following the specified architecture.
