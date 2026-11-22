# 🔐 INTERFACE CONTRACT
## CS212 - Help Desk Priority Simulation

**Document Version**: 1.0  
**Status**: **FROZEN AFTER WEEK 1**  
**Last Updated**: November 22, 2026

---

## ⚠️ CRITICAL WARNING

**THIS DOCUMENT DEFINES THE SHARED INTERFACE FOR THE ENTIRE PROJECT.**

Once approved and frozen (end of Week 1), **NO CHANGES** are allowed without:
1. Team-wide discussion
2. Unanimous agreement
3. Coordinated updates across ALL affected files

**Changing a function signature after Week 1 = Breaking the entire project**

---

## 1. DATA STRUCTURES & TYPES

### 1.1 Escalation (Stack)

```cpp
struct Escalation {
    int requestId;           // ID of escalated request
    string agentName;        // Name of agent who escalated
    string reason;           // Reason for escalation
    string timestamp;        // Time of escalation
    int priorityLevel;       // Priority: 1=Low, 2=Medium, 3=High, 4=Critical
};
```

**Immutable After**: Week 1, Day 2

---

### 1.2 ServiceRequest (Queue)

```cpp
struct ServiceRequest {
    int requestId;           // Unique request ID
    string customerName;     // Name of customer
    string issueType;        // Type: Hardware, Software, Network, Other
    string description;      // Detailed description
    int priority;            // Priority: 1=Low, 2=Medium, 3=High, 4=Critical
    string timestamp;        // Time request was created
    string status;           // Status: Waiting, InProgress, Resolved
};
```

**Immutable After**: Week 1, Day 3

---

### 1.3 Agent (LinkedList)

```cpp
struct Agent {
    int agentId;              // Unique agent ID
    string name;              // Agent's full name
    string specialization;    // Area: Hardware, Software, Network
    int assignedRequests;     // Number of currently assigned requests
    bool isAvailable;         // Availability status
    string email;             // Contact email
    string phoneNumber;       // Contact phone
};
```

**Immutable After**: Week 1, Day 4

---

### 1.4 Node (LinkedList)

```cpp
struct Node {
    Agent data;               // Agent information
    Node* next;               // Pointer to next node
};
```

**Immutable After**: Week 1, Day 4

---

### 1.5 RequestRecord (BST)

```cpp
struct RequestRecord {
    int requestId;           // Unique ID (key for BST)
    string customerName;     // Customer name
    string issueType;        // Type of issue
    string assignedAgent;    // Name of assigned agent
    string status;           // Status: Waiting, InProgress, Resolved
    string createdTime;      // Creation timestamp
    string resolvedTime;     // Resolution timestamp (empty if not resolved)
};
```

**Immutable After**: Week 1, Day 6

---

### 1.6 BSTNode (BST)

```cpp
struct BSTNode {
    RequestRecord data;      // Request information
    BSTNode* left;           // Left child (smaller IDs)
    BSTNode* right;          // Right child (larger IDs)
};
```

**Immutable After**: Week 1, Day 6

---

## 2. CLASS INTERFACES

### 2.1 Stack Class

```cpp
class Stack {
private:
    static const int MAX_SIZE = 100;  // Maximum stack size
    Escalation data[MAX_SIZE];        // Array to store escalations
    int top;                          // Index of top element (-1 if empty)

public:
    // Constructor
    Stack();
    
    // Destructor
    ~Stack();
    
    // Push new escalation to stack
    bool push(int requestId, string agentName, string reason, 
              string timestamp, int priorityLevel);
    
    // Remove and return top escalation from stack
    Escalation pop();
    
    // View top escalation without removing it
    Escalation peek();
    
    // Check if stack has no elements
    bool isEmpty();
    
    // Check if stack is at maximum capacity
    bool isFull();
    
    // Get current number of escalations in stack
    int size();
    
    // Print all escalations in stack (top to bottom)
    void display();
    
    // Remove all escalations from stack
    void clear();
};
```

**Responsibility**: Omar Mohamed (Functions 1-5), Khaled Taha (Functions 6-9)

**Immutable After**: Week 1, Day 2

---

### 2.2 Queue Class

```cpp
class Queue {
private:
    static const int MAX_SIZE = 100;  // Maximum queue size
    ServiceRequest data[MAX_SIZE];    // Array to store requests
    int frontIndex;                   // Index of front element
    int rearIndex;                    // Index of rear element
    int count;                        // Number of elements in queue
    
    // Helper: Find index of highest priority request in queue
    int getHighestPriority();

public:
    // Constructor
    Queue();
    
    // Destructor
    ~Queue();
    
    // Add new service request to queue based on priority
    bool enqueue(int requestId, string customerName, string issueType, 
                 string description, int priority, string timestamp);
    
    // Remove and return highest priority request from queue
    ServiceRequest dequeue();
    
    // View front request without removing it
    ServiceRequest front();
    
    // Check if queue has no elements
    bool isEmpty();
    
    // Check if queue is at maximum capacity
    bool isFull();
    
    // Get current number of requests in queue
    int size();
    
    // Print all requests in queue (front to rear)
    void display();
    
    // Remove all requests from queue
    void clear();
};
```

**Responsibility**: Omar Mohamed (Functions 1-5), Khaled Taha (Functions 6-11)

**Immutable After**: Week 1, Day 3

---

### 2.3 LinkedList Class

```cpp
class LinkedList {
private:
    Node* head;               // Pointer to first node
    int count;                // Number of agents in list

public:
    // Constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Add new agent to the linked list
    bool insertAgent(int agentId, string name, string specialization, 
                     string email, string phoneNumber);
    
    // Remove agent from list by ID
    bool deleteAgent(int agentId);
    
    // Find agent by ID
    Node* searchAgent(int agentId);
    
    // Print information of all agents in list
    void displayAgents();
    
    // Modify agent information
    bool updateAgent(int agentId, string name, string specialization, 
                     string email, string phoneNumber);
    
    // Get total number of agents
    int getCount();
    
    // Check if list has no agents
    bool isEmpty();
    
    // Increment assigned requests count for an agent
    bool assignRequest(int agentId);
    
    // Decrement assigned requests count for an agent
    bool unassignRequest(int agentId);
    
    // Change agent availability status
    bool setAvailability(int agentId, bool available);
    
    // Find first available agent with matching specialization
    Node* findAvailableAgent(string specialization);
    
    // Remove all agents from list
    void clear();
};
```

**Responsibility**: Nour Mohamed (Functions 1-7), Heba Ragab (Functions 8-14)

**Immutable After**: Week 1, Day 5

---

### 2.4 BST Class

```cpp
class BST {
private:
    BSTNode* root;           // Root of the tree
    int count;               // Total number of nodes
    
    // Recursive insert helper
    BSTNode* insertHelper(BSTNode* node, RequestRecord record);
    
    // Recursive search helper
    BSTNode* searchHelper(BSTNode* node, int requestId);
    
    // Recursive delete helper
    BSTNode* deleteHelper(BSTNode* node, int requestId);
    
    // Find minimum node in subtree
    BSTNode* findMinNode(BSTNode* node);
    
    // Recursive inorder traversal helper
    void inorderHelper(BSTNode* node);
    
    // Recursive preorder traversal helper
    void preorderHelper(BSTNode* node);
    
    // Recursive clear helper
    void clearHelper(BSTNode* node);

public:
    // Constructor
    BST();
    
    // Destructor
    ~BST();
    
    // Add new request to BST
    bool insert(int requestId, string customerName, string issueType,
                string assignedAgent, string status, string createdTime);
    
    // Find request by ID
    BSTNode* search(int requestId);
    
    // Remove request from BST by ID
    bool deleteRequest(int requestId);
    
    // Display all requests in sorted order by ID (ascending)
    void inorderTraversal();
    
    // Display all requests in preorder (Root-Left-Right)
    void preorderTraversal();
    
    // Find request with smallest ID
    BSTNode* findMin();
    
    // Find request with largest ID
    BSTNode* findMax();
    
    // Check if BST has no nodes
    bool isEmpty();
    
    // Get total number of requests in BST
    int getCount();
    
    // Update status of a request
    bool updateStatus(int requestId, string newStatus);
    
    // Set resolved time for a request
    bool updateResolvedTime(int requestId, string resolvedTime);
    
    // Remove all requests from BST
    void clear();
};
```

**Responsibility**: 
- Nour Mohamed (Functions 1-7)
- Heba Ragab (Functions 8-14)
- Mariam Alaa (Functions 15-21)

**Immutable After**: Week 1, Day 7

---

### 2.5 HelpDesk Class

```cpp
class HelpDesk {
private:
    Stack escalationStack;        // For escalated requests
    Queue requestQueue;           // For pending requests
    LinkedList agentList;         // For agent management
    BST requestTree;              // For fast request lookup
    int nextRequestId;            // Auto-increment ID counter
    int totalRequests;            // Total requests created
    int resolvedRequests;         // Total resolved requests
    int escalatedRequests;        // Total escalated requests
    
    // Get current date/time as string
    string getCurrentTimestamp();
    
    // Generate next unique request ID
    int getNextRequestId();

public:
    // Constructor
    HelpDesk();
    
    // Destructor
    ~HelpDesk();
    
    // Create new service request and add to queue
    int createRequest(string customerName, string issueType, 
                      string description, int priority);
    
    // Dequeue highest priority request and assign to agent
    bool processNextRequest();
    
    // Move request to escalation stack
    bool escalateRequest(int requestId, string agentName, string reason);
    
    // Mark request as resolved
    bool resolveRequest(int requestId);
    
    // Add new agent to system
    bool addAgent(int agentId, string name, string specialization,
                  string email, string phoneNumber);
    
    // Remove agent from system
    bool removeAgent(int agentId);
    
    // Display details of specific request
    void viewRequest(int requestId);
    
    // Display all requests in system (using BST inorder)
    void viewAllRequests();
    
    // Display all requests waiting in queue
    void viewPendingRequests();
    
    // Display all escalated requests in stack
    void viewEscalations();
    
    // Display all agents in system
    void viewAllAgents();
    
    // Show system statistics and metrics
    void displayStatistics();
    
    // Search for request using BST (O(log n) average)
    bool searchRequestById(int requestId);
    
    // Implement sorting algorithm (Bubble/Insertion/Selection)
    void sortRequestsByPriority();
    
    // Search agent by name using linear search
    void linearSearchAgent(string name);
    
    // Manually assign specific agent to request
    bool assignAgentToRequest(int requestId, int agentId);
    
    // Pop escalation from stack and handle it
    bool processEscalation();
};
```

**Responsibility**: ALL team members contribute functions (see FILE_OWNERSHIP.md)

**Immutable After**: Week 1, Day 8

---

## 3. FUNCTION SIGNATURES - DETAILED SPECIFICATIONS

### 3.1 Return Type Contracts

**bool functions**:
- Return `true` if operation successful
- Return `false` if operation failed (not found, full, empty, duplicate, etc.)
- **NEVER throw exceptions** (not required for CS212)

**Pointer functions** (Node*, BSTNode*):
- Return pointer to found node if successful
- Return `NULL` if not found
- **NEVER return invalid pointer**

**Object functions** (Escalation, ServiceRequest):
- Return populated struct if successful
- Return empty struct with default values if failed
- Display error message to console if failed

**void functions**:
- Perform operation
- Display messages to console
- Handle errors internally

**int functions**:
- Return valid ID or count
- Return -1 or 0 for error cases (document which)

---

### 3.2 Parameter Passing Conventions

**Primitives** (int, bool):
```cpp
int functionName(int value, bool flag)  // Pass by value
```

**Strings**:
```cpp
bool functionName(string text)  // Pass by value (acceptable for CS212)
// OR
bool functionName(const string& text)  // Pass by const reference (preferred)
```

**Current Choice**: **Pass by value** (simpler, matches existing code)

**Pointers**:
```cpp
Node* functionName(Node* node)  // Pass by value (pointer copy)
```

---

### 3.3 Naming Conventions

**Functions**: camelCase
```cpp
createRequest()
getNextRequestId()
displayStatistics()
```

**Struct/Class Names**: PascalCase
```cpp
ServiceRequest
Agent
BSTNode
HelpDesk
```

**Variables**: camelCase
```cpp
requestId
agentName
isAvailable
```

**Constants**: UPPER_SNAKE_CASE
```cpp
MAX_SIZE
```

**Private Members**: camelCase (no underscore prefix)
```cpp
private:
    int top;
    Node* head;
```

---

### 3.4 Error Handling Conventions

**DO**:
```cpp
if (isEmpty()) {
    cout << "Error: Stack is empty!" << endl;
    return false;  // or return empty object
}
```

**DON'T**:
```cpp
throw exception();  // NOT REQUIRED
exit(1);            // DON'T EXIT PROGRAM
assert();           // DON'T USE ASSERTS IN PRODUCTION
```

**Standard Error Messages**:
- "Error: Stack is empty!"
- "Error: Queue is full!"
- "Error: Request ID not found!"
- "Error: Agent ID already exists!"
- "Error: Duplicate ID!"
- "Error: Invalid input!"

---

## 4. INCLUDE DEPENDENCIES

### 4.1 Mandatory Includes

**All header files** must include:
```cpp
#include <iostream>
#include <string>
using namespace std;
```

**Implementation files** must include:
```cpp
#include "CorrespondingHeader.h"
```

### 4.2 Include Order

```cpp
// 1. Corresponding header (for .cpp files)
#include "Stack.h"

// 2. Standard library headers
#include <iostream>
#include <string>

// 3. Other project headers (if needed)
#include "HelpDesk.h"

// 4. using declarations
using namespace std;
```

### 4.3 Forbidden Includes

**DO NOT USE**:
```cpp
#include <vector>      // Manual implementation required
#include <stack>       // Manual implementation required
#include <queue>       // Manual implementation required
#include <list>        // Manual implementation required
#include <map>         // Manual implementation required
#include <set>         // Manual implementation required
#include <algorithm>   // Manual sort/search required
```

**ALLOWED** (if needed):
```cpp
#include <ctime>       // For timestamps
#include <limits>      // For input validation
#include <iomanip>     // For output formatting
```

---

## 5. MEMORY MANAGEMENT

### 5.1 Rules

**Dynamic Memory** (LinkedList, BST):
- Every `new` must have corresponding `delete`
- Destructors must free ALL allocated memory
- `clear()` must delete all nodes

**Array-Based** (Stack, Queue):
- No dynamic allocation needed
- Destructors can be empty
- `clear()` just resets indices

### 5.2 Memory Leak Prevention

**LinkedList**:
```cpp
~LinkedList() {
    clear();  // Must implement properly
}

void LinkedList::clear() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;  // CRITICAL
    }
    count = 0;
}
```

**BST**:
```cpp
~BST() {
    clear();
}

void BST::clear() {
    clearHelper(root);
    root = NULL;
    count = 0;
}

void BST::clearHelper(BSTNode* node) {
    if (node == NULL) return;
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;  // Postorder deletion
}
```

---

## 6. CONSTANTS & MAGIC NUMBERS

### 6.1 Defined Constants

```cpp
// Stack & Queue
const int MAX_SIZE = 100;

// Priority Levels
const int PRIORITY_LOW = 1;
const int PRIORITY_MEDIUM = 2;
const int PRIORITY_HIGH = 3;
const int PRIORITY_CRITICAL = 4;

// Agent Capacity
const int MAX_REQUESTS_PER_AGENT = 5;
```

### 6.2 String Literals (Status Values)

**Request Status**:
- "Waiting"
- "InProgress"
- "Resolved"
- "Escalated"

**Issue Types**:
- "Hardware"
- "Software"
- "Network"
- "Other"

**Agent Specializations**:
- "Hardware"
- "Software"
- "Network"

**Use these EXACT strings** - consistency critical for integration.

---

## 7. COMPILATION REQUIREMENTS

### 7.1 Compiler

**Required**: g++ (MinGW or GCC)

**Command**:
```bash
g++ -o HelpDesk main.cpp Stack.cpp Queue.cpp LinkedList.cpp BST.cpp HelpDesk.cpp
```

**Flags** (optional but recommended):
```bash
g++ -Wall -Wextra -std=c++11 -o HelpDesk *.cpp
```

### 7.2 C++ Standard

**Minimum**: C++98  
**Recommended**: C++11  
**Maximum**: C++17 (no C++20 features)

**Avoid**:
- `auto` keyword (use explicit types)
- Range-based for loops (use traditional for loops)
- Lambda functions (not needed)
- Smart pointers (use raw pointers)

---

## 8. CODE STYLE CONVENTIONS

### 8.1 Indentation

**Use**: 4 spaces per indentation level  
**NOT**: Tabs

### 8.2 Braces

**Style**: K&R variant (opening brace on same line)
```cpp
if (condition) {
    // code
} else {
    // code
}

while (condition) {
    // code
}

void functionName() {
    // code
}
```

### 8.3 Comments

**Function Headers**:
```cpp
/*
 * Function: functionName
 * Purpose: Brief description
 * Parameters:
 *   - param1: description
 *   - param2: description
 * Returns: description
 */
```

**Inline Comments**:
```cpp
int top = -1;  // -1 indicates empty stack
```

**TODO Comments**:
```cpp
// TODO: Implement function body
// TODO: Add error handling
```

### 8.4 Whitespace

**Around Operators**:
```cpp
int result = a + b;  // YES
int result=a+b;      // NO
```

**After Commas**:
```cpp
function(a, b, c);   // YES
function(a,b,c);     // NO
```

**Blank Lines**:
- One blank line between functions
- No blank line at start/end of file

---

## 9. INTEGRATION CONTRACTS

### 9.1 HelpDesk Constructor

**MUST** initialize:
```cpp
HelpDesk::HelpDesk() {
    nextRequestId = 1001;  // Start IDs at 1001
    totalRequests = 0;
    resolvedRequests = 0;
    escalatedRequests = 0;
    // Data structures auto-construct
}
```

### 9.2 Request ID Assignment

**Rule**: HelpDesk owns ID generation
```cpp
int HelpDesk::createRequest(...) {
    int id = getNextRequestId();  // Centralized ID management
    // Use this ID for Queue AND BST
    requestQueue.enqueue(id, ...);
    requestTree.insert(id, ...);
    return id;
}
```

**NEVER** generate IDs in Stack, Queue, LinkedList, or BST directly.

### 9.3 Agent Assignment

**Rule**: LinkedList manages agent availability
```cpp
bool HelpDesk::processNextRequest() {
    ServiceRequest req = requestQueue.dequeue();
    Node* agent = agentList.findAvailableAgent(req.issueType);
    if (agent != NULL) {
        agentList.assignRequest(agent->data.agentId);  // Update availability
        // Assign to request in BST
    }
}
```

### 9.4 Data Consistency

**Critical**: Same request MUST have consistent data in Queue AND BST

**Example**:
```cpp
// Creating request - data goes to BOTH
requestQueue.enqueue(id, name, type, desc, priority, time);
requestTree.insert(id, name, type, "None", "Waiting", time);

// Processing request - remove from queue, update BST
ServiceRequest req = requestQueue.dequeue();
requestTree.updateStatus(req.requestId, "InProgress");
requestTree.updateAgent(req.requestId, agentName);
```

---

## 10. TESTING CONTRACTS

### 10.1 Unit Testing Requirements

**Each function** must be tested with:
1. **Normal case**: Valid input, expected behavior
2. **Edge case**: Boundary values (empty, single element, full)
3. **Error case**: Invalid input, error handling

### 10.2 Integration Testing Requirements

**Must verify**:
1. Request created → appears in BOTH Queue AND BST
2. Request dequeued → still in BST (not deleted)
3. Request escalated → moved to Stack, BST updated
4. Request resolved → BST updated, not in Queue/Stack
5. Agent assigned → availability updated in LinkedList

### 10.3 Test Data Standards

**Use consistent test data**:
```cpp
// Sample Agent IDs
101, 102, 103, 104, 105

// Sample Request IDs (auto-generated)
1001, 1002, 1003, ...

// Sample Names
"Ahmed Ali", "Sara Mohamed", "Omar Hassan"

// Sample Issue Types
"Hardware", "Software", "Network"
```

---

## 11. DOCUMENTATION REQUIREMENTS

### 11.1 Code Comments

**MUST document**:
- Every public function (purpose, parameters, returns)
- Complex algorithms (explain logic)
- Important variables (clarify purpose)

**Optional**:
- Simple getters/setters
- Obvious operations

### 11.2 README Updates

**After implementation**, update README.md with:
- Compilation instructions
- Execution instructions
- Known issues (if any)
- Team contributions

---

## 12. CHANGE MANAGEMENT

### 12.1 Before Week 1 Ends

**Allowed**:
- Any changes to interfaces
- Adding/removing functions
- Changing parameter types
- Renaming functions

**Process**:
- Propose change to team
- Update this document
- Update all affected files
- Notify all members

### 12.2 After Week 1 (FROZEN)

**Allowed Only If**:
- Critical bug found
- Impossible to implement as specified
- All 6 members agree
- Mariam approves

**Process**:
1. Document problem
2. Propose solution
3. Team discussion
4. Unanimous vote
5. Update contract
6. Update all files
7. Re-test everything

**Otherwise**: **NO CHANGES ALLOWED**

---

## 13. VIOLATION CONSEQUENCES

### 13.1 Interface Violations

**Changing function signature after freeze**:
- Breaks other members' code
- Requires coordination to fix
- Delays project
- **Responsibility**: Person who changed it must fix ALL breaks

### 13.2 Naming Violations

**Using different names than specified**:
- Integration fails
- Compiler errors
- Confusion
- **Responsibility**: Must rename to match contract

### 13.3 Type Violations

**Using different data types**:
- Type mismatch errors
- Data loss possible
- Integration broken
- **Responsibility**: Must fix to match contract

---

## 14. APPROVAL & SIGNATURES

### 14.1 Team Agreement

**By signing below, I agree to**:
- Follow all specifications in this contract
- Not change interfaces after Week 1 freeze
- Notify team immediately if problem found
- Coordinate any necessary changes with team

### 14.2 Signatures

| Name | Signature | Date |
|------|-----------|------|
| Omar Mohamed | _________ | _____ |
| Khaled Taha | _________ | _____ |
| Nour Mohamed | _________ | _____ |
| Heba Ragab | _________ | _____ |
| Mariam Alaa | _________ | _____ |
| Nour Wael | _________ | _____ |

---

## 15. DOCUMENT VERSION HISTORY

| Version | Date | Changes | Author |
|---------|------|---------|--------|
| 1.0 | 2026-11-22 | Initial creation | Senior Architect |

---

**CONTRACT STATUS**: **ACTIVE - PENDING TEAM APPROVAL**

**FREEZE DATE**: **End of Week 1 (Day 7)**

**NEXT REVIEW**: **Only if critical issue found**

---

**THIS IS A LEGALLY BINDING TECHNICAL AGREEMENT BETWEEN TEAM MEMBERS.**

**READ CAREFULLY. UNDERSTAND COMPLETELY. SIGN ONLY IF YOU AGREE.**

