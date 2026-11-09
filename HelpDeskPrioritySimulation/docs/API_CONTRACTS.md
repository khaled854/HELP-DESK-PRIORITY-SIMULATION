# API CONTRACTS AND FUNCTION SPECIFICATIONS
## CS212 Help-Desk Priority Simulation

**Purpose:** Define exact function signatures, parameters, return types, preconditions, and postconditions for all modules. This allows team members to implement dependent modules independently.

---

## NAMING CONVENTIONS

- **Classes:** PascalCase (e.g., `EscalationStack`, `RequestService`)
- **Functions:** camelCase (e.g., `pushEvent`, `getNextRequest`)
- **Variables:** camelCase (e.g., `requestId`, `agentName`)
- **Constants:** UPPER_SNAKE_CASE (e.g., `MAX_QUEUE_SIZE`, `DEFAULT_PRIORITY`)
- **Enums:** PascalCase with UPPER values (e.g., `enum PriorityLevel { HIGH, MEDIUM, LOW }`)

---

## 1. ESCALATION STACK MODULE (Member 1)

### Class: EscalationStack

**File:** `src/data_structures/stack/EscalationStack.h`  
**Owner:** Member 1  
**Purpose:** Manual LIFO Stack for escalation events

#### Constructor
```cpp
EscalationStack()
```
- **Purpose:** Initialize empty stack
- **Precondition:** None
- **Postcondition:** Empty stack created

#### push
```cpp
void push(EscalationEvent event)
```
- **Purpose:** Add escalation event to top of stack
- **Parameters:** `event` - EscalationEvent object to push
- **Return:** void
- **Precondition:** Valid EscalationEvent
- **Postcondition:** Event added to stack top, size increased by 1
- **Complexity:** O(1)

#### pop
```cpp
EscalationEvent pop()
```
- **Purpose:** Remove and return top escalation event
- **Parameters:** None
- **Return:** EscalationEvent from top of stack
- **Precondition:** Stack is not empty
- **Postcondition:** Top event removed, size decreased by 1
- **Error:** Throw exception or return invalid event if empty
- **Complexity:** O(1)

#### peek
```cpp
EscalationEvent peek()
```
- **Purpose:** Return top event without removing
- **Parameters:** None
- **Return:** EscalationEvent from top of stack
- **Precondition:** Stack is not empty
- **Postcondition:** Stack unchanged
- **Error:** Throw exception or return invalid event if empty
- **Complexity:** O(1)

#### isEmpty
```cpp
bool isEmpty()
```
- **Purpose:** Check if stack has any events
- **Parameters:** None
- **Return:** true if empty, false otherwise
- **Complexity:** O(1)

#### size
```cpp
int size()
```
- **Purpose:** Return number of events in stack
- **Parameters:** None
- **Return:** Integer count of events
- **Complexity:** O(1)

#### displayHistory
```cpp
void displayHistory()
```
- **Purpose:** Print all escalation events from top to bottom
- **Parameters:** None
- **Return:** void
- **Postcondition:** Stack unchanged, events printed to console
- **Complexity:** O(n)

### Class: EscalationService

**File:** `src/services/EscalationService.h`  
**Owner:** Member 1

#### recordEscalation
```cpp
void recordEscalation(int requestId, PriorityLevel oldPriority, 
                      PriorityLevel newPriority, string reason)
```
- **Purpose:** Create escalation event and push to stack
- **Parameters:**
  - `requestId` - Request being escalated
  - `oldPriority` - Previous priority level
  - `newPriority` - New priority level (must be higher)
  - `reason` - Explanation for escalation
- **Return:** void
- **Precondition:** Valid request ID, newPriority > oldPriority
- **Postcondition:** Escalation event created and added to stack

#### getRecentEscalations
```cpp
vector<EscalationEvent> getRecentEscalations(int count)
```
- **Purpose:** Get most recent escalation events
- **Parameters:** `count` - Number of events to retrieve
- **Return:** Vector of up to `count` most recent escalation events
- **Postcondition:** Stack unchanged

#### displayEscalationHistory
```cpp
void displayEscalationHistory()
```
- **Purpose:** Display all escalation events in LIFO order
- **Return:** void
- **Postcondition:** Events printed to console, stack unchanged

---

## 2. PRIORITY QUEUE MODULE (Member 2)

### Class: PriorityRequestQueue

**File:** `src/data_structures/queue/PriorityRequestQueue.h`  
**Owner:** Member 2  
**Purpose:** Three separate FIFO queues for priority-based request dispatch

#### Constructor
```cpp
PriorityRequestQueue()
```
- **Purpose:** Initialize three empty queues (HIGH, MEDIUM, LOW)
- **Postcondition:** All queues empty

#### enqueue
```cpp
void enqueue(int requestId, PriorityLevel priority)
```
- **Purpose:** Add request ID to appropriate priority queue
- **Parameters:**
  - `requestId` - Unique request identifier
  - `priority` - HIGH, MEDIUM, or LOW
- **Return:** void
- **Precondition:** Valid request ID and priority
- **Postcondition:** Request added to back of specified priority queue
- **Complexity:** O(1)

#### dequeue
```cpp
int dequeue()
```
- **Purpose:** Remove and return next request ID based on priority
- **Parameters:** None
- **Return:** Request ID from highest-priority non-empty queue, or -1 if all empty
- **Precondition:** None
- **Postcondition:** If not empty, request removed from front of highest-priority queue
- **Priority Order:** Check HIGH → MEDIUM → LOW
- **Complexity:** O(1)

#### front
```cpp
int front(PriorityLevel priority)
```
- **Purpose:** View front request ID of specific priority queue
- **Parameters:** `priority` - Which queue to check
- **Return:** Request ID at front, or -1 if that queue is empty
- **Postcondition:** Queue unchanged
- **Complexity:** O(1)

#### isEmpty (all queues)
```cpp
bool isEmpty()
```
- **Purpose:** Check if all three queues are empty
- **Return:** true if all empty, false if any has requests
- **Complexity:** O(1)

#### isEmpty (specific priority)
```cpp
bool isEmpty(PriorityLevel priority)
```
- **Purpose:** Check if specific priority queue is empty
- **Parameters:** `priority` - Which queue to check
- **Return:** true if that queue is empty
- **Complexity:** O(1)

#### size (all queues)
```cpp
int size()
```
- **Purpose:** Return total count of waiting requests across all priorities
- **Return:** Sum of all three queue sizes
- **Complexity:** O(1)

#### size (specific priority)
```cpp
int size(PriorityLevel priority)
```
- **Purpose:** Return count of requests in specific priority queue
- **Parameters:** `priority` - Which queue to check
- **Return:** Size of that queue
- **Complexity:** O(1)

#### displayWaiting
```cpp
void displayWaiting()
```
- **Purpose:** Print all waiting requests by priority
- **Return:** void
- **Postcondition:** Requests printed, queues unchanged
- **Complexity:** O(n)

#### removeRequestById
```cpp
bool removeRequestById(int requestId)
```
- **Purpose:** Remove specific request from queues (for cancellation)
- **Parameters:** `requestId` - Request to remove
- **Return:** true if found and removed, false otherwise
- **Postcondition:** Request removed if it was waiting
- **Complexity:** O(n) - must search all three queues
- **Note:** This is the only O(n) queue operation

### Class: RequestDispatcher

**File:** `src/services/RequestDispatcher.h`  
**Owner:** Member 2

#### enqueueRequest
```cpp
void enqueueRequest(int requestId, PriorityLevel priority)
```
- **Purpose:** Add request to appropriate waiting queue
- **Parameters:**
  - `requestId` - Request to enqueue
  - `priority` - Request priority level
- **Return:** void
- **Delegates to:** PriorityRequestQueue.enqueue()

#### getNextRequest
```cpp
int getNextRequest()
```
- **Purpose:** Get next request ID to assign (highest priority)
- **Return:** Request ID or -1 if no waiting requests
- **Postcondition:** Request removed from queue
- **Delegates to:** PriorityRequestQueue.dequeue()

#### displayWaitingRequests
```cpp
void displayWaitingRequests()
```
- **Purpose:** Show all waiting requests by priority
- **Return:** void
- **Delegates to:** PriorityRequestQueue.displayWaiting()

#### getQueueStatistics
```cpp
map<PriorityLevel, int> getQueueStatistics()
```
- **Purpose:** Get count of waiting requests per priority
- **Return:** Map with HIGH/MEDIUM/LOW counts

---

## 3. AGENT LINKED LIST MODULE (Member 3)

### Class: AgentLinkedList

**File:** `src/data_structures/linked_list/AgentLinkedList.h`  
**Owner:** Member 3  
**Purpose:** Manual singly linked list for agent records

#### Constructor
```cpp
AgentLinkedList()
```
- **Purpose:** Initialize empty linked list
- **Postcondition:** head = nullptr, size = 0

#### insertAgent
```cpp
void insertAgent(Agent agent)
```
- **Purpose:** Add new agent to list
- **Parameters:** `agent` - Agent object to add
- **Return:** void
- **Precondition:** Agent ID does not already exist
- **Postcondition:** Agent added to list (at head or tail)
- **Error:** Reject duplicate agent ID
- **Complexity:** O(1) if inserting at head, O(n) if checking for duplicates

#### deleteAgent
```cpp
bool deleteAgent(int agentId)
```
- **Purpose:** Remove agent from list
- **Parameters:** `agentId` - ID of agent to remove
- **Return:** true if found and removed, false if not found
- **Postcondition:** Agent removed, node deallocated
- **Complexity:** O(n)

#### searchAgent
```cpp
Agent* searchAgent(int agentId)
```
- **Purpose:** Find agent by ID
- **Parameters:** `agentId` - ID to search for
- **Return:** Pointer to Agent if found, nullptr if not found
- **Postcondition:** List unchanged
- **Complexity:** O(n)

#### displayAgents
```cpp
void displayAgents()
```
- **Purpose:** Print all agent information
- **Return:** void
- **Postcondition:** Agents printed, list unchanged
- **Complexity:** O(n)

#### updateAgent
```cpp
bool updateAgent(int agentId, Agent updatedAgent)
```
- **Purpose:** Update existing agent's information
- **Parameters:**
  - `agentId` - Agent to update
  - `updatedAgent` - New agent data
- **Return:** true if agent found and updated, false otherwise
- **Complexity:** O(n)

#### getAgentCount
```cpp
int getAgentCount()
```
- **Purpose:** Return number of agents
- **Return:** Integer count
- **Complexity:** O(1) if tracked, O(n) if counted

#### isEmpty
```cpp
bool isEmpty()
```
- **Purpose:** Check if list has any agents
- **Return:** true if empty
- **Complexity:** O(1)

### Class: AgentService

**File:** `src/services/AgentService.h`  
**Owner:** Member 3

#### addAgent
```cpp
bool addAgent(Agent agent)
```
- **Purpose:** Add new agent to system
- **Parameters:** `agent` - Agent to add
- **Return:** true if added, false if duplicate ID
- **Delegates to:** AgentLinkedList.insertAgent()

#### removeAgent
```cpp
bool removeAgent(int agentId)
```
- **Purpose:** Remove agent from system
- **Parameters:** `agentId` - Agent to remove
- **Return:** true if removed, false if not found

#### findAgent
```cpp
Agent* findAgent(int agentId)
```
- **Purpose:** Retrieve agent by ID
- **Parameters:** `agentId` - ID to search
- **Return:** Pointer to Agent or nullptr

#### findAvailableAgent
```cpp
Agent* findAvailableAgent()
```
- **Purpose:** Find first available agent
- **Return:** Pointer to first AVAILABLE agent, or nullptr if all busy
- **Complexity:** O(n) - must traverse list

#### updateAgentAvailability
```cpp
bool updateAgentAvailability(int agentId, AgentStatus status)
```
- **Purpose:** Change agent availability (AVAILABLE/BUSY)
- **Parameters:**
  - `agentId` - Agent to update
  - `status` - New availability status
- **Return:** true if updated, false if agent not found

#### displayAllAgents
```cpp
void displayAllAgents()
```
- **Purpose:** Show all agents
- **Return:** void

---

## 4. REQUEST BST MODULE (Member 4)

### Class: RequestBST

**File:** `src/data_structures/bst/RequestBST.h`  
**Owner:** Member 4  
**Purpose:** Manual Binary Search Tree indexed by request ID

#### Constructor
```cpp
RequestBST()
```
- **Purpose:** Initialize empty BST
- **Postcondition:** root = nullptr, size = 0

#### insertRequest
```cpp
bool insertRequest(ServiceRequest request)
```
- **Purpose:** Add request to BST
- **Parameters:** `request` - ServiceRequest object
- **Return:** true if inserted, false if duplicate request ID
- **Precondition:** Unique request ID
- **Postcondition:** Request added maintaining BST property
- **Complexity:** O(log n) average, O(n) worst

#### deleteRequest
```cpp
bool deleteRequest(int requestId)
```
- **Purpose:** Remove request from BST
- **Parameters:** `requestId` - ID of request to delete
- **Return:** true if found and deleted, false if not found
- **Postcondition:** Request removed, tree restructured
- **Must Handle Three Cases:**
  1. Leaf node (no children)
  2. One child
  3. Two children (use inorder successor or predecessor)
- **Complexity:** O(log n) average, O(n) worst

#### searchRequest
```cpp
ServiceRequest* searchRequest(int requestId)
```
- **Purpose:** Find request by unique ID
- **Parameters:** `requestId` - ID to search
- **Return:** Pointer to ServiceRequest if found, nullptr otherwise
- **Postcondition:** Tree unchanged
- **Complexity:** O(log n) average, O(n) worst

#### inorderTraversal
```cpp
void inorderTraversal(vector<ServiceRequest>& result)
```
- **Purpose:** Traverse tree in sorted order (left → root → right)
- **Parameters:** `result` - Vector to fill with requests
- **Postcondition:** result contains all requests in ascending ID order
- **Complexity:** O(n)

#### preorderTraversal
```cpp
void preorderTraversal(vector<ServiceRequest>& result)
```
- **Purpose:** Traverse tree in root → left → right order
- **Parameters:** `result` - Vector to fill with requests
- **Postcondition:** result contains all requests in preorder
- **Complexity:** O(n)

#### isEmpty
```cpp
bool isEmpty()
```
- **Purpose:** Check if tree is empty
- **Return:** true if no requests
- **Complexity:** O(1)

#### getSize
```cpp
int getSize()
```
- **Purpose:** Return number of requests in tree
- **Return:** Integer count
- **Complexity:** O(1) if tracked, O(n) if counted

### Class: RequestIndexService

**File:** `src/services/RequestIndexService.h`  
**Owner:** Member 4

#### indexRequest
```cpp
bool indexRequest(ServiceRequest request)
```
- **Purpose:** Add request to BST index
- **Parameters:** `request` - Request to index
- **Return:** true if indexed, false if duplicate ID
- **Delegates to:** RequestBST.insertRequest()

#### findRequest
```cpp
ServiceRequest* findRequest(int requestId)
```
- **Purpose:** Retrieve request by ID
- **Parameters:** `requestId` - ID to find
- **Return:** Pointer to ServiceRequest or nullptr
- **Delegates to:** RequestBST.searchRequest()

#### removeRequestFromIndex
```cpp
bool removeRequestFromIndex(int requestId)
```
- **Purpose:** Delete request from BST
- **Parameters:** `requestId` - ID to remove
- **Return:** true if removed, false if not found
- **Delegates to:** RequestBST.deleteRequest()

#### getAllRequests
```cpp
vector<ServiceRequest> getAllRequests()
```
- **Purpose:** Get all requests in sorted order
- **Return:** Vector of all requests (inorder traversal)

#### displayAllRequests
```cpp
void displayAllRequests()
```
- **Purpose:** Print all requests
- **Return:** void

---

## 5. REQUEST SERVICE & INTEGRATION (Member 5)

### Class: RequestService

**File:** `src/services/RequestService.h`  
**Owner:** Member 5  
**Dependencies:** Uses services from Members 1-4

#### createRequest
```cpp
bool createRequest(ServiceRequest request)
```
- **Purpose:** Register new help-desk request
- **Parameters:** `request` - New request object
- **Return:** true if created, false if duplicate ID
- **Workflow:**
  1. Validate request
  2. Add to BST (RequestIndexService)
  3. Enqueue to appropriate priority queue (RequestDispatcher)
  4. Set status to WAITING
- **Integration:** BST + Queue

#### updateRequest
```cpp
bool updateRequest(int requestId, ServiceRequest updatedRequest)
```
- **Purpose:** Modify existing request fields
- **Parameters:**
  - `requestId` - Request to update
  - `updatedRequest` - New request data
- **Return:** true if updated, false if not found
- **Integration:** BST

#### cancelRequest
```cpp
bool cancelRequest(int requestId)
```
- **Purpose:** Cancel and remove request
- **Parameters:** `requestId` - Request to cancel
- **Return:** true if canceled, false if not found
- **Workflow:**
  1. Find in BST
  2. Remove from queue if waiting (RequestDispatcher)
  3. Remove from BST
- **Integration:** BST + Queue

#### resolveRequest
```cpp
bool resolveRequest(int requestId)
```
- **Purpose:** Mark request as resolved
- **Parameters:** `requestId` - Request to resolve
- **Return:** true if resolved, false if not found
- **Workflow:**
  1. Find in BST
  2. Update status to RESOLVED
  3. Update agent availability if assigned
- **Integration:** BST + AgentService

#### escalateRequest
```cpp
bool escalateRequest(int requestId, PriorityLevel newPriority, string reason)
```
- **Purpose:** Increase request priority
- **Parameters:**
  - `requestId` - Request to escalate
  - `newPriority` - New higher priority
  - `reason` - Escalation justification
- **Return:** true if escalated, false if not found or invalid priority
- **Workflow:**
  1. Find in BST
  2. Record escalation (EscalationService)
  3. Update priority in BST
  4. If status is WAITING, update queue membership
- **Integration:** BST + Stack + Queue

#### assignRequest
```cpp
bool assignRequest(int requestId, int agentId)
```
- **Purpose:** Assign request to agent
- **Parameters:**
  - `requestId` - Request to assign
  - `agentId` - Agent to assign to
- **Return:** true if assigned, false if error
- **Workflow:**
  1. Find request in BST
  2. Find agent in AgentService
  3. Update request (assignedAgentId, status = ASSIGNED)
  4. Update agent availability
- **Integration:** BST + AgentService

#### findRequestById
```cpp
ServiceRequest* findRequestById(int requestId)
```
- **Purpose:** Search for request
- **Parameters:** `requestId` - ID to find
- **Return:** Pointer to ServiceRequest or nullptr
- **Delegates to:** RequestIndexService.findRequest()

### Class: HelpDeskCoordinator

**File:** `src/services/HelpDeskCoordinator.h`  
**Owner:** Member 5  
**Purpose:** High-level workflows crossing multiple services

#### processNextRequest
```cpp
bool processNextRequest()
```
- **Purpose:** Assign next waiting request to available agent
- **Return:** true if successful, false if no requests or no agents
- **Workflow:**
  1. Get next request ID from RequestDispatcher
  2. Find request in BST
  3. Find available agent (AgentService)
  4. Assign request to agent
  5. Update both request and agent
- **Integration:** Queue + BST + LinkedList

#### generateStatisticsReport
```cpp
void generateStatisticsReport()
```
- **Purpose:** Display request statistics by status/priority
- **Return:** void
- **Uses:** BST traversal, sorting

#### generateEscalationReport
```cpp
void generateEscalationReport()
```
- **Purpose:** Display recent escalation history
- **Return:** void
- **Delegates to:** EscalationService

---

## 6. APPLICATION & VALIDATION (Member 6)

### Class: HelpDeskApp

**File:** `src/app/HelpDeskApp.h`  
**Owner:** Member 6

#### run
```cpp
void run()
```
- **Purpose:** Main application loop
- **Return:** void
- **Workflow:** Display menu, get choice, route to handler, repeat until exit

### Class: MenuController

**File:** `src/app/MenuController.h`  
**Owner:** Member 6

#### displayMainMenu
```cpp
void displayMainMenu()
```
- **Purpose:** Print main menu options
- **Return:** void

#### getMenuChoice
```cpp
int getMenuChoice()
```
- **Purpose:** Read and validate menu selection
- **Return:** Integer choice (1-12)
- **Error Handling:** Re-prompt on invalid input

### Class: InputValidator

**File:** `src/utils/InputValidator.h`  
**Owner:** Member 6

#### readInteger
```cpp
int readInteger(string prompt, int min, int max)
```
- **Purpose:** Read validated integer within range
- **Parameters:**
  - `prompt` - Message to display
  - `min` - Minimum valid value
  - `max` - Maximum valid value
- **Return:** Integer within [min, max]
- **Error Handling:** Re-prompt until valid

#### readNonEmptyString
```cpp
string readNonEmptyString(string prompt)
```
- **Purpose:** Read string that is not empty
- **Parameters:** `prompt` - Message to display
- **Return:** Non-empty string
- **Error Handling:** Re-prompt if empty

#### validateRequestId
```cpp
bool validateRequestId(int id)
```
- **Purpose:** Check if request ID is valid (positive)
- **Parameters:** `id` - ID to validate
- **Return:** true if valid

### Class: RequestSort

**File:** `src/algorithms/RequestSort.h`  
**Owner:** Member 6  
**Algorithm:** Merge Sort

#### sortRequests
```cpp
vector<ServiceRequest> sortRequests(vector<ServiceRequest> requests, string sortKey)
```
- **Purpose:** Sort request array using Merge Sort
- **Parameters:**
  - `requests` - Array to sort
  - `sortKey` - "priority", "id", or "time"
- **Return:** Sorted vector
- **Complexity:** O(n log n) all cases
- **Space:** O(n) auxiliary space

#### mergeSort
```cpp
void mergeSort(vector<ServiceRequest>& arr, int left, int right)
```
- **Purpose:** Recursive merge sort implementation
- **Parameters:**
  - `arr` - Array to sort (modified in place)
  - `left` - Start index
  - `right` - End index
- **Return:** void (sorts in place)

#### merge
```cpp
void merge(vector<ServiceRequest>& arr, int left, int mid, int right)
```
- **Purpose:** Merge two sorted subarrays
- **Parameters:**
  - `arr` - Array containing subarrays
  - `left` - Start of first subarray
  - `mid` - End of first subarray
  - `right` - End of second subarray
- **Return:** void (merges in place)

---

## SHARED DOMAIN MODELS

### ServiceRequest (Member 5 defines, all use)

```cpp
struct ServiceRequest {
    int requestId;              // Unique identifier (BST key)
    string requesterName;
    string issueTitle;
    string issueDescription;
    string category;
    PriorityLevel priority;     // HIGH, MEDIUM, LOW
    RequestStatus status;       // OPEN, WAITING, ASSIGNED, etc.
    int assignedAgentId;        // 0 if unassigned
    long creationTime;          // Timestamp
};
```

### Agent (Member 3 defines)

```cpp
struct Agent {
    int agentId;                // Unique identifier
    string name;
    string specialization;
    AgentStatus availability;   // AVAILABLE, BUSY
    int assignedRequestCount;
};
```

### EscalationEvent (Member 1 defines)

```cpp
struct EscalationEvent {
    int requestId;
    PriorityLevel previousPriority;
    PriorityLevel newPriority;
    string reason;
    long eventTime;             // Timestamp
};
```

### Enums (Shared in Constants.h)

```cpp
enum PriorityLevel { HIGH, MEDIUM, LOW };
enum RequestStatus { OPEN, WAITING, ASSIGNED, IN_PROGRESS, RESOLVED, CLOSED };
enum AgentStatus { AVAILABLE, BUSY };
```

---

## DEPENDENCY RULES

1. **No circular dependencies**
2. **Services use data structures, not vice versa**
3. **All modules use shared models**
4. **Member 6's controller uses all services**
5. **Member 5 coordinates services but does NOT reimplement data structures**

---

## ERROR HANDLING CONVENTIONS

- **Invalid input:** Re-prompt user
- **Null pointers:** Check before dereferencing
- **Not found:** Return nullptr or false
- **Duplicate ID:** Reject with error message
- **Empty structures:** Safe error messages, no crashes

---

**These contracts are BINDING. Do not change function signatures without team agreement.**

**Implementation begins NOW - each member implements their assigned APIs.**
