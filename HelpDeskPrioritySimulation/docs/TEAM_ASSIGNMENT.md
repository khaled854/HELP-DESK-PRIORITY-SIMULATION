# TEAM ASSIGNMENT AND RESPONSIBILITIES
## CS212 Help-Desk Priority Simulation - Six-Member Distribution

---

## IMPORTANT PRINCIPLES

1. **Every member has real programming responsibility** - No documentation-only roles
2. **Fair workload distribution** - No single member does all difficult work
3. **Clear module ownership** - Each source file has one primary owner
4. **Shared integration responsibility** - All members contribute to making modules work together
5. **Individual understanding required** - Every member must explain the complete system

---

## MEMBER 1: STACK & ESCALATION MODULE

### Primary Responsibility
Manual Stack implementation and escalation history management

### Owned Files
```
src/data_structures/stack/
  ├── EscalationStack.h          ← Manual Stack implementation
  └── EscalationStack.cpp         ← Manual Stack implementation

src/services/
  ├── EscalationService.h        ← Escalation workflow
  └── EscalationService.cpp       ← Escalation workflow

src/models/
  ├── EscalationEvent.h          ← Domain model
  └── EscalationEvent.cpp         ← Domain model

tests/unit/stack/
  └── (Create test files here)
```

### Functions to Implement

**EscalationStack class:**
```cpp
void push(EscalationEvent event)
EscalationEvent pop()
EscalationEvent peek()
bool isEmpty()
int size()
void displayHistory()
void clear()
```

**EscalationService class:**
```cpp
void recordEscalation(int requestId, PriorityLevel oldPriority, 
                      PriorityLevel newPriority, string reason)
vector<EscalationEvent> getRecentEscalations(int count)
void displayEscalationHistory()
EscalationStack* getStack()  // For demonstration
```

### Deliverables

1. **Code:**
   - Working LIFO Stack with array or linked-node implementation
   - All Stack operations implemented and tested
   - Escalation service workflow
   - Handle empty Stack edge case

2. **Testing:**
   - Push multiple escalation events
   - Pop from empty Stack (error handling)
   - Peek without removing
   - Display history in LIFO order
   - Test with 1 event, many events, and empty Stack

3. **Documentation:**
   - Stack implementation choice (array vs linked nodes) justification
   - LIFO behavior explanation
   - O(1) complexity explanation for push/pop/peek
   - Integration with Request Service

4. **Discussion Preparation:**
   - Explain Stack vs Queue difference
   - Explain LIFO meaning and importance
   - Show how escalation events are recorded
   - Describe memory management (if using pointers)
   - Answer questions about other modules

### Integration Points

- **RequestService** calls **EscalationService.recordEscalation()** when priority increases
- **HelpDeskCoordinator** displays escalation history for reports
- **EscalationEvent model** used by Stack

### Complexity Analysis (Your Responsibility)

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| push() | O(1) | O(1) |
| pop() | O(1) | O(1) |
| peek() | O(1) | O(1) |
| isEmpty() | O(1) | O(1) |
| size() | O(1) | O(1) |
| displayHistory() | O(n) | O(1) |

---

## MEMBER 2: PRIORITY QUEUE & DISPATCH MODULE

### Primary Responsibility
Manual Queue implementation and priority-based request dispatching

### Owned Files
```
src/data_structures/queue/
  ├── PriorityRequestQueue.h     ← Manual Queue implementation
  └── PriorityRequestQueue.cpp    ← Manual Queue implementation

src/services/
  ├── RequestDispatcher.h        ← Priority dispatch logic
  └── RequestDispatcher.cpp       ← Priority dispatch logic

tests/unit/queue/
  └── (Create test files here)
```

### Functions to Implement

**PriorityRequestQueue class (Three internal FIFO queues):**
```cpp
void enqueue(int requestId, PriorityLevel priority)
int dequeue()  // Returns request ID or -1 if empty
int front(PriorityLevel priority)
bool isEmpty()
bool isEmpty(PriorityLevel priority)  // Check specific queue
int size()
int size(PriorityLevel priority)  // Size of specific queue
void displayWaiting()
void removeRequestById(int requestId)  // For cancellations
```

**RequestDispatcher class:**
```cpp
void enqueueRequest(int requestId, PriorityLevel priority)
int getNextRequest()  // Dispatcher logic: HIGH → MEDIUM → LOW
void displayWaitingRequests()
map<PriorityLevel, int> getQueueStatistics()
bool isRequestWaiting(int requestId)
```

### Deliverables

1. **Code:**
   - Three separate FIFO queues (HIGH, MEDIUM, LOW)
   - All Queue operations (enqueue, dequeue, front)
   - Dispatcher selects from highest-priority non-empty queue
   - Handle empty Queue edge cases
   - Support request removal by ID (for cancellations)

2. **Testing:**
   - Enqueue requests of different priorities
   - Verify FIFO within same priority
   - Verify HIGH processed before MEDIUM/LOW
   - Dequeue from empty Queue (error handling)
   - Test single request, many requests per priority
   - Test alternating priorities
   - Test cancellation/removal

3. **Documentation:**
   - Queue implementation choice (array vs linked nodes) justification
   - FIFO behavior explanation
   - Priority scheduling policy explanation
   - O(1) complexity for enqueue/dequeue
   - Starvation limitation discussion

4. **Discussion Preparation:**
   - Explain FIFO meaning and importance
   - Explain why three separate queues were used
   - Describe priority dispatching algorithm
   - Discuss low-priority starvation problem
   - Suggest realistic improvements (aging, time limits)

### Integration Points

- **RequestService** calls **RequestDispatcher.enqueueRequest()** when new request created
- **HelpDeskCoordinator** calls **RequestDispatcher.getNextRequest()** for assignment
- **RequestService** removes requests from queue when status changes
- Queue stores **request IDs only**, not full request objects

### Complexity Analysis (Your Responsibility)

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| enqueue() | O(1) | O(1) |
| dequeue() | O(1) | O(1) |
| front() | O(1) | O(1) |
| isEmpty() | O(1) | O(1) |
| getNextRequest() | O(1) | O(1) |
| removeRequestById() | O(n) | O(1) |

### Known Limitation (Document This)
Low-priority requests may wait indefinitely if high-priority requests continuously arrive (starvation). This is a realistic tradeoff and should be explained during discussion.

---

## MEMBER 3: AGENT LINKED LIST MODULE

### Primary Responsibility
Manual Linked List for agent records management

### Owned Files
```
src/data_structures/linked_list/
  ├── AgentLinkedList.h          ← Manual Linked List
  └── AgentLinkedList.cpp         ← Manual Linked List

src/services/
  ├── AgentService.h             ← Agent management
  └── AgentService.cpp            ← Agent management

src/models/
  ├── Agent.h                    ← Agent domain model
  └── Agent.cpp                   ← Agent domain model

tests/unit/linked_list/
  └── (Create test files here)
```

### Functions to Implement

**AgentLinkedList class:**
```cpp
void insertAgent(Agent agent)  // Insert at head or tail
bool deleteAgent(int agentId)
Agent* searchAgent(int agentId)
void displayAgents()
bool updateAgent(int agentId, Agent updatedAgent)
int getAgentCount()
bool isEmpty()
void clear()
```

**AgentService class:**
```cpp
bool addAgent(Agent agent)
bool removeAgent(int agentId)
Agent* findAgent(int agentId)
Agent* findAvailableAgent()  // Search for AVAILABLE agent
Agent* findAvailableAgentBySpecialization(string spec)
bool updateAgentAvailability(int agentId, AgentStatus status)
void displayAllAgents()
int getAvailableAgentCount()
```

### Deliverables

1. **Code:**
   - Singly linked list implementation (manual nodes)
   - Proper pointer management (no memory leaks)
   - All linked list operations
   - Handle empty list, single node, first/last deletion
   - Prevent duplicate agent IDs

2. **Testing:**
   - Insert multiple agents
   - Delete first agent
   - Delete last agent
   - Delete middle agent
   - Delete from single-agent list
   - Search for existing agent
   - Search for non-existent agent
   - Search in empty list
   - Update agent availability
   - Display all agents
   - Test with 1, 3, 10 agents

3. **Documentation:**
   - Singly vs doubly linked list justification
   - Node structure explanation
   - Pointer traversal explanation
   - O(n) complexity for search/delete
   - Memory management strategy

4. **Discussion Preparation:**
   - Explain linked list vs array tradeoffs
   - Show node insertion diagram
   - Describe deletion cases (first, middle, last)
   - Explain pointer updates during deletion
   - Discuss memory deallocation

### Integration Points

- **AgentService** provides high-level agent operations
- **HelpDeskCoordinator** queries available agents for assignment
- **RequestService** updates agent availability after assignment
- Agent records owned by LinkedList (not duplicated elsewhere)

### Complexity Analysis (Your Responsibility)

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| insertAgent() | O(1) at head, O(n) at tail | O(1) |
| deleteAgent() | O(n) | O(1) |
| searchAgent() | O(n) | O(1) |
| updateAgent() | O(n) | O(1) |
| displayAgents() | O(n) | O(1) |
| getAgentCount() | O(1) if tracked, O(n) otherwise | O(1) |

---

## MEMBER 4: REQUEST BST & INDEX MODULE

### Primary Responsibility
Manual Binary Search Tree for request lookup by unique ID

### Owned Files
```
src/data_structures/bst/
  ├── RequestBST.h               ← Manual BST implementation
  └── RequestBST.cpp              ← Manual BST implementation

src/services/
  ├── RequestIndexService.h      ← Index management
  └── RequestIndexService.cpp     ← Index management

tests/unit/bst/
  └── (Create test files here)
```

### Functions to Implement

**RequestBST class:**
```cpp
bool insertRequest(ServiceRequest request)
bool deleteRequest(int requestId)
ServiceRequest* searchRequest(int requestId)
void inorderTraversal(vector<ServiceRequest>& result)
void preorderTraversal(vector<ServiceRequest>& result)
bool isEmpty()
int getSize()
ServiceRequest* findMinimum()
ServiceRequest* findMaximum()
void clear()
```

**RequestIndexService class:**
```cpp
bool indexRequest(ServiceRequest request)
ServiceRequest* findRequest(int requestId)
bool removeRequestFromIndex(int requestId)
vector<ServiceRequest> getAllRequests()
void displayAllRequests()
void displayRequestsInOrder()
RequestBST* getBST()  // For demonstration
```

### Deliverables

1. **Code:**
   - Binary Search Tree with manual nodes
   - Unique request ID as key
   - Insert, search, delete operations
   - Inorder and preorder traversals
   - Handle all three deletion cases:
     1. Leaf node
     2. Node with one child
     3. Node with two children (use inorder successor or predecessor)
   - Duplicate ID prevention
   - Empty tree handling

2. **Testing:**
   - Insert requests with random IDs
   - Insert requests with sorted IDs (show worst case)
   - Search for existing request
   - Search for non-existent request
   - Delete leaf node
   - Delete node with one child
   - Delete node with two children
   - Delete root node
   - Inorder traversal (verify sorted order)
   - Preorder traversal
   - Test with 1, 5, 10, 15 requests

3. **Documentation:**
   - BST property explanation (left < parent < right)
   - Three deletion cases with diagrams
   - Traversal algorithms explanation
   - Average O(log n) vs worst O(n) complexity
   - Why tree is not balanced (acceptable tradeoff)

4. **Discussion Preparation:**
   - Explain BST search algorithm
   - Draw example tree with insertions
   - Demonstrate inorder successor finding
   - Explain when worst-case O(n) occurs
   - Discuss balanced tree improvements (AVL, Red-Black)

### Integration Points

- **BST is the canonical request index** - all other structures reference it
- **Queue stores request IDs only** - full records live in BST
- **All request operations** (create, update, search, delete) use BST
- **Reports** traverse BST to get all requests

### Complexity Analysis (Your Responsibility)

| Operation | Average Case | Worst Case | Notes |
|-----------|-------------|------------|-------|
| insertRequest() | O(log n) | O(n) | Depends on insertion order |
| deleteRequest() | O(log n) | O(n) | Tree height dependent |
| searchRequest() | O(log n) | O(n) | Skewed tree worst case |
| inorderTraversal() | O(n) | O(n) | Visit all nodes |
| preorderTraversal() | O(n) | O(n) | Visit all nodes |

**Important:** The BST is NOT balanced. Document this limitation and explain that average case assumes random insertions.

---

## MEMBER 5: REQUEST SERVICES & INTEGRATION

### Primary Responsibility
Business logic that connects the four data structures into cohesive workflows

### Owned Files
```
src/services/
  ├── RequestService.h           ← Request lifecycle management
  ├── RequestService.cpp          ← Request lifecycle management
  ├── HelpDeskCoordinator.h      ← Cross-module integration
  └── HelpDeskCoordinator.cpp     ← Cross-module integration

src/models/
  ├── ServiceRequest.h           ← Core domain model (define)
  ├── ServiceRequest.cpp          ← Core domain model (define)
  ├── PriorityLevel.h            ← Enum
  └── RequestStatus.h            ← Enum

tests/unit/services/
tests/integration/
  └── (Create integration test scenarios)
```

### Functions to Implement

**RequestService class:**
```cpp
bool createRequest(ServiceRequest request)
bool updateRequest(int requestId, /* field updates */)
bool cancelRequest(int requestId)
bool resolveRequest(int requestId)
bool closeRequest(int requestId)
bool escalateRequest(int requestId, PriorityLevel newPriority, string reason)
bool assignRequest(int requestId, int agentId)
ServiceRequest* findRequestById(int requestId)
vector<ServiceRequest> getRequestsByStatus(RequestStatus status)
```

**HelpDeskCoordinator class:**
```cpp
bool processNextRequest()  // Get from queue, find agent, assign
void generateStatisticsReport()
void generateEscalationReport()
void synchronizeRequestState()  // Ensure consistency
int getRequestCountByStatus(RequestStatus status)
int getRequestCountByPriority(PriorityLevel priority)
```

### Deliverables

1. **Code:**
   - Implement all request lifecycle operations
   - Coordinate between BST, Queue, Stack, and Linked List
   - Maintain data consistency across structures
   - Integration scenarios:
     - **Create Request:** Add to BST, enqueue to appropriate queue
     - **Assign Request:** Dequeue, find agent, update both
     - **Escalate Request:** Update BST, push to Stack, update queue if waiting
     - **Cancel Request:** Remove from queue and BST
     - **Generate Reports:** Traverse BST, display Stack history

2. **Testing:**
   - Create request → verify in BST and Queue
   - Assign request → verify agent updated, removed from queue
   - Escalate waiting request → verify priority updated, stack pushed, queue updated
   - Cancel request → verify removed from both BST and queue
   - Full end-to-end scenario tests

3. **Documentation:**
   - Integration workflow diagrams
   - Data flow explanations
   - Consistency rules
   - Synchronization logic
   - Error handling across modules

4. **Discussion Preparation:**
   - Explain how four structures work together
   - Describe consistency challenges
   - Show example workflow trace
   - Discuss what happens if agent unavailable
   - Explain Queue-BST synchronization

### Integration Responsibilities (SHARED WITH ALL MEMBERS)

You coordinate integration but **DO NOT** reimplement other members' data structures. You **USE** their APIs.

**Dependencies:**
- Uses **Member 1's** EscalationService
- Uses **Member 2's** RequestDispatcher
- Uses **Member 3's** AgentService
- Uses **Member 4's** RequestIndexService

**Integration Testing:**
All members participate in integration testing. You coordinate the scenarios.

### Complexity Analysis (Your Responsibility)

Document complexity of composite operations:
- createRequest: O(log n) BST + O(1) enqueue = O(log n)
- assignRequest: O(1) dequeue + O(log n) BST search + O(n) agent search = O(n)
- escalateRequest: O(log n) BST + O(1) stack + O(n) queue update = O(n)

---

## MEMBER 6: APPLICATION CONTROLLER, VALIDATION & ALGORITHMS

### Primary Responsibility
User interface, input validation, menu navigation, and course sorting algorithm

### Owned Files
```
src/main.cpp                   ← Application entry point

src/app/
  ├── HelpDeskApp.h            ← Main application class
  ├── HelpDeskApp.cpp           ← Main application class
  ├── MenuController.h         ← Menu display and routing
  └── MenuController.cpp        ← Menu display and routing

src/utils/
  ├── InputValidator.h         ← Input validation
  ├── InputValidator.cpp        ← Input validation
  └── Constants.h              ← Application constants

src/algorithms/
  ├── RequestSort.h            ← Merge Sort implementation
  └── RequestSort.cpp           ← Merge Sort implementation

tests/unit/algorithms/
  └── (Create algorithm test files)
```

### Functions to Implement

**HelpDeskApp class:**
```cpp
void run()  // Main application loop
void initialize()
void shutdown()
void displayWelcome()
```

**MenuController class:**
```cpp
void displayMainMenu()
int getMenuChoice()
void handleCreateRequest()
void handleSearchRequest()
void handleAssignRequest()
void handleEscalateRequest()
void handleCancelRequest()
void handleDisplayAgents()
void handleDisplayWaiting()
void handleGenerateReports()
void handleExit()
```

**InputValidator class:**
```cpp
int readInteger(string prompt, int min, int max)
string readNonEmptyString(string prompt)
bool validateRequestId(int id)
PriorityLevel readPriority()
RequestStatus readStatus()
bool confirmAction(string prompt)
void displayError(string message)
void clearInputBuffer()
```

**RequestSort class (Merge Sort):**
```cpp
vector<ServiceRequest> sortRequests(vector<ServiceRequest> requests, 
                                    string sortKey)
void mergeSort(vector<ServiceRequest>& arr, int left, int right)
void merge(vector<ServiceRequest>& arr, int left, int mid, int right)
bool compareBySortKey(ServiceRequest a, ServiceRequest b, string sortKey)
```

### Deliverables

1. **Code:**
   - Complete menu-driven console interface
   - Robust input validation (all edge cases)
   - Clear error messages
   - Graceful recovery from invalid input
   - **Merge Sort algorithm implementation**
   - Sort by: priority, request ID, creation time
   - Menu options for all major operations:
     1. Create new request
     2. Search request by ID
     3. Display all requests
     4. Display waiting requests
     5. Assign next request to agent
     6. Escalate request
     7. Resolve/Close request
     8. Cancel request
     9. Manage agents (add/remove/display)
     10. Display escalation history
     11. Generate reports (sorted)
     12. Exit

2. **Testing:**
   - Non-numeric menu input
   - Out-of-range menu choice
   - Empty string input
   - Invalid priority/status
   - Merge Sort correctness (sorted output)
   - Merge Sort with 1, 5, 10, 20 requests
   - Sort by different keys

3. **Documentation:**
   - Menu structure
   - Input validation rules
   - **Merge Sort algorithm explanation:**
     - Divide-and-conquer approach
     - Recursive splitting
     - Merging sorted subarrays
     - Time complexity: O(n log n) all cases
     - Space complexity: O(n)
   - Comparison with other sorting algorithms
   - Why Merge Sort chosen for this application

4. **Discussion Preparation:**
   - Explain Merge Sort step-by-step
   - Draw recursion tree
   - Show merge operation
   - Explain O(n log n) complexity derivation
   - Discuss stability property
   - Compare with Quick Sort, Bubble Sort

### Integration Points

- **main.cpp** creates HelpDeskApp and calls run()
- **HelpDeskApp** coordinates all services
- **MenuController** routes to appropriate service calls
- **InputValidator** used by all user-facing operations
- **RequestSort** used by report generation

### Complexity Analysis (Your Responsibility)

**Merge Sort:**
| Case | Time Complexity | Space Complexity |
|------|----------------|------------------|
| Best | O(n log n) | O(n) |
| Average | O(n log n) | O(n) |
| Worst | O(n log n) | O(n) |

Explain why:
- Dividing array: O(log n) levels
- Merging at each level: O(n)
- Total: O(n log n)

---

## SHARED RESPONSIBILITIES (ALL MEMBERS)

### 1. Testing
- Each member tests their own module thoroughly
- All members contribute to integration testing
- Test normal, empty, boundary, and invalid cases

### 2. Code Quality
- Meaningful variable names
- Inline comments explaining logic
- Consistent naming conventions
- No magic numbers (use constants)
- Proper indentation and formatting

### 3. Documentation
- Document your module in report
- Write README instructions for compilation
- Prepare for individual discussion
- Understand complete system (not just your module)

### 4. Discussion Preparation
All members must be able to explain:
- All four data structures and their operations
- LIFO vs FIFO
- BST deletion cases
- Big-O complexity of major operations
- Merge Sort algorithm
- Integration and synchronization
- Their personal contribution
- System limitations

### 5. Git Workflow
- Work on feature branches
- Commit regularly with clear messages
- Create pull requests for review
- Merge only after approval
- Resolve conflicts collaboratively

---

## WORKLOAD FAIRNESS VERIFICATION

| Member | Data Structure | Service Layer | Algorithm | UI/Validation | Integration |
|--------|---------------|--------------|-----------|---------------|-------------|
| 1 | Stack (Manual) | EscalationService | - | - | Uses others |
| 2 | Queue (Manual) | RequestDispatcher | - | - | Uses others |
| 3 | LinkedList (Manual) | AgentService | - | - | Uses others |
| 4 | BST (Manual) | RequestIndexService | - | - | Uses others |
| 5 | - | RequestService + Coordinator | - | - | **Coordinates** |
| 6 | - | - | **Merge Sort** | **All validation + Menu** | Uses others |

**Every member has substantial programming work. ✅**

---

## COMMUNICATION AND COORDINATION

### Weekly Milestones
- **Week 1:** Implement and test individual data structures
- **Week 2:** Implement service layers, begin integration
- **Week 3:** Complete integration, full application workflow
- **Week 4:** Testing, documentation, report writing
- **Week 5:** Final review, practice demonstration

### Integration Meetings
- Coordinate API compatibility
- Resolve integration issues
- Review pull requests
- Test end-to-end scenarios

### Member 5 (Integration Coordinator) Responsibilities
- Schedule integration testing sessions
- Review cross-module pull requests
- Verify consistency rules
- Coordinate final demonstration

---

## FINAL REMINDER

**Every member must:**
1. ✅ Implement their assigned module completely
2. ✅ Test their module thoroughly
3. ✅ Document their contribution
4. ✅ Understand the ENTIRE system
5. ✅ Prepare to answer ANY question during oral discussion

**Success = Team Working as ONE integrated unit**

---

## QUESTIONS?

Refer to:
- `ARCHITECTURE.md` - System design
- `API_CONTRACTS.md` - Function specifications
- `FILE_OWNERSHIP.md` - Who owns which files
- `INTEGRATION_PLAN.md` - How modules connect
- `TESTING_PLAN.md` - Test requirements

**Start with your assigned module. Ask questions early. Communicate often.**
