# CS212 - Data Structures Project Report

## Help Desk Priority Simulation

---

## 1. COVER PAGE

### University Information
**MISR UNIVERSITY FOR SCIENCE & TECHNOLOGY**  
**College of Information Technology**

### Course Information
- **Course Code**: CS212
- **Course Name**: Data Structures
- **Semester**: Fall 2026-2027
- **Practical Section**: [اكتب رقم الـ Section]

### Project Information
- **Project Title**: Help-Desk Priority Simulation
- **Project Number**: 89
- **Submission Date**: [اكتب التاريخ]

### Team Members
| # | Name | University ID | Role |
|---|------|---------------|------|
| 1 | عمر محمد | [ID] | Stack Implementation |
| 2 | خالد طه | [ID] | Priority Queue Implementation |
| 3 | نور محمد | [ID] | Linked List Implementation |
| 4 | هبه رجب | [ID] | BST Implementation |
| 5 | مريم علاء | [ID] | System Integration & Algorithms |
| 6 | نور وائل | [ID] | User Interface & Testing |

---

## 2. PROBLEM DEFINITION

### 2.1 Background
[اكتب هنا شرح للمشكلة]

IT help desks face challenges in managing and prioritizing service requests efficiently. With multiple requests coming from different customers, varying levels of urgency, and limited available agents, there is a need for a structured system to:
- Queue requests based on priority
- Track request escalations
- Manage agent assignments
- Maintain request history

### 2.2 Problem Statement
[اشرح المشكلة بالتفصيل]

The current manual process of handling help desk requests leads to:
1. **Delayed response times** for critical issues
2. **Inefficient agent allocation**
3. **Lost track** of escalated requests
4. **Difficulty in** searching historical requests
5. **No clear priority system**

### 2.3 Intended Users
- Help desk agents
- IT support managers
- System administrators
- End users (customers reporting issues)

### 2.4 Project Scope

**What the system INCLUDES:**
- Create and manage service requests
- Priority-based queue for request processing
- Agent management and assignment
- Request escalation tracking
- Fast request lookup by ID
- Statistical reports
- Searching and sorting capabilities

**What the system EXCLUDES:**
- Email notifications
- Database persistence
- Multi-user concurrent access
- Graphical user interface (GUI)
- Real-time chat support

---

## 3. PROJECT OBJECTIVES

[اكتب الأهداف]

The main objectives of this project are:

1. **Implement fundamental data structures** from scratch without using STL
2. **Demonstrate understanding** of Stack, Queue, Linked List, and BST
3. **Create a practical application** that integrates multiple data structures
4. **Apply searching and sorting algorithms**
5. **Develop a menu-driven console interface**
6. **Handle edge cases and validate inputs**
7. **Analyze time complexity** of operations

### Expected Outcomes
By the end of this project, the system should:
- ✅ Accept and queue service requests by priority
- ✅ Assign requests to available agents
- ✅ Track escalated requests in LIFO order
- ✅ Search requests efficiently using BST
- ✅ Display comprehensive statistics
- ✅ Handle errors gracefully

---

## 4. DATA STRUCTURES USED

### 4.1 Stack (Recent Escalations)

**Implementation**: Array-based Stack with maximum size of 100

**Data Structure**:
```cpp
struct Escalation {
    int requestId;
    string agentName;
    string reason;
    string timestamp;
    int priorityLevel;
};
```

**Role in the System**:
The Stack stores recently escalated requests following the LIFO (Last In, First Out) principle. When an agent escalates a complex request, it is pushed onto the stack. The most recent escalations can be viewed and processed first.

**Why Stack?**
- Escalations are time-sensitive - most recent ones need attention first
- LIFO behavior matches the workflow of handling urgent escalations
- Simple O(1) push and pop operations for efficiency

**Operations**:
- `push()`: Add escalation - O(1)
- `pop()`: Remove top escalation - O(1)
- `peek()`: View top without removing - O(1)
- `isEmpty()`: Check if empty - O(1)

---

### 4.2 Priority Queue (Pending Service Requests)

**Implementation**: Array-based circular queue with priority ordering

**Data Structure**:
```cpp
struct ServiceRequest {
    int requestId;
    string customerName;
    string issueType;
    string description;
    int priority;        // 1=Low, 2=Medium, 3=High, 4=Critical
    string timestamp;
    string status;
};
```

**Role in the System**:
The Priority Queue manages all pending service requests. Requests with higher priority (Critical = 4) are processed before lower priority ones. For requests with the same priority, FIFO order is maintained.

**Why Priority Queue?**
- Critical issues must be handled before routine requests
- Fair ordering for same-priority requests
- Efficient dequeue of highest priority item

**Operations**:
- `enqueue()`: Add request by priority - O(1) or O(n)
- `dequeue()`: Remove highest priority - O(1) or O(n)
- `front()`: View highest priority - O(1)
- `isEmpty()`: Check if empty - O(1)

---

### 4.3 Linked List (Agent Records)

**Implementation**: Singly Linked List with dynamic nodes

**Data Structures**:
```cpp
struct Agent {
    int agentId;
    string name;
    string specialization;
    int assignedRequests;
    bool isAvailable;
    string email;
    string phoneNumber;
};

struct Node {
    Agent data;
    Node* next;
};
```

**Role in the System**:
The Linked List maintains all agent records. It allows dynamic insertion and deletion of agents, tracking their availability and workload. The system can search for available agents with specific specializations.

**Why Linked List?**
- Dynamic size - can add/remove agents anytime
- Efficient insertion at head - O(1)
- No wasted memory (unlike fixed arrays)
- Easy traversal to find available agents

**Operations**:
- `insertAgent()`: Add new agent - O(1) at head
- `deleteAgent()`: Remove agent - O(n)
- `searchAgent()`: Find by ID - O(n)
- `findAvailableAgent()`: Find by specialization - O(n)

---

### 4.4 Binary Search Tree (Request Lookup)

**Implementation**: BST with recursive operations

**Data Structures**:
```cpp
struct RequestRecord {
    int requestId;         // Key for BST
    string customerName;
    string issueType;
    string assignedAgent;
    string status;
    string createdTime;
    string resolvedTime;
};

struct BSTNode {
    RequestRecord data;
    BSTNode* left;
    BSTNode* right;
};
```

**Role in the System**:
The BST stores all requests for fast lookup by request ID. It maintains a complete history of all requests (Waiting, InProgress, Resolved) and allows efficient searching and sorted traversal.

**Why BST?**
- Fast search: O(log n) average time complexity
- Sorted traversal (inorder) displays requests in ID order
- Efficient for frequent lookups
- Maintains complete request history

**Operations**:
- `insert()`: Add request - O(log n) average
- `search()`: Find by ID - O(log n) average
- `delete()`: Remove request - O(log n) average
- `inorderTraversal()`: Display sorted - O(n)

---

## 5. SYSTEM FEATURES

### 5.1 Main Menu Structure

```
========================================
           MAIN MENU
========================================
1. Request Management
2. Agent Management
3. View Operations
4. Search Operations
5. Display Statistics
6. Run System Tests
0. Exit
========================================
```

### 5.2 Request Management

**Features**:
1. **Create New Request**
   - Input: Customer name, issue type, description, priority
   - Output: Unique request ID assigned
   - Action: Added to Queue and BST

2. **Process Next Request**
   - Dequeues highest priority request
   - Finds available agent with matching specialization
   - Assigns agent to request
   - Updates request status to "InProgress"

3. **Escalate Request**
   - Input: Request ID, agent name, reason
   - Pushes escalation to Stack
   - Updates status to "Escalated" in BST

4. **Resolve Request**
   - Input: Request ID
   - Updates status to "Resolved"
   - Sets resolved timestamp
   - Frees assigned agent

5. **View Request Details**
   - Search request by ID in BST
   - Display complete information

### 5.3 Agent Management

**Features**:
1. **Add New Agent**
   - Input: ID, name, specialization, contact info
   - Inserts into Linked List

2. **Remove Agent**
   - Input: Agent ID
   - Deletes from Linked List

3. **View All Agents**
   - Traverses Linked List
   - Shows availability status

4. **Assign Agent to Request**
   - Manual assignment option
   - Updates both BST and Linked List

### 5.4 View Operations

**Features**:
1. **View All Requests** (BST Inorder Traversal)
2. **View Pending Requests** (Queue Display)
3. **View Escalations** (Stack Display)
4. **View All Agents** (Linked List Traversal)

### 5.5 Search and Sort

**Features**:
1. **Search Request by ID** (BST Search - O(log n))
2. **Search Agent by Name** (Linear Search - O(n))
3. **Sort Requests by Priority** (Sorting Algorithm)

### 5.6 Statistics Dashboard

**Displays**:
- Total requests created
- Pending requests count
- In-progress requests
- Resolved requests
- Escalated requests
- Total agents
- Available agents
- Busy agents

---

## 6. IMPLEMENTATION EXPLANATION

[اشرح التطبيق بالتفصيل مع Code Screenshots]

### 6.1 Stack Implementation

**Key Functions**:

```cpp
// Constructor
Stack::Stack() {
    top = -1;  // Empty stack
}

// Push operation
bool Stack::push(int requestId, string agentName, 
                 string reason, string timestamp, int priorityLevel) {
    if (isFull()) {
        cout << "Error: Stack is full!" << endl;
        return false;
    }
    
    top++;
    data[top].requestId = requestId;
    data[top].agentName = agentName;
    data[top].reason = reason;
    data[top].timestamp = timestamp;
    data[top].priorityLevel = priorityLevel;
    
    return true;
}
```

**Explanation**: [اشرح الكود]

[أضف screenshot للكود]

---

### 6.2 Priority Queue Implementation

**Key Functions**:

```cpp
// Enqueue with priority
bool Queue::enqueue(int requestId, string customerName, 
                    string issueType, string description, 
                    int priority, string timestamp) {
    if (isFull()) {
        return false;
    }
    
    rearIndex = (rearIndex + 1) % MAX_SIZE;
    data[rearIndex].requestId = requestId;
    data[rearIndex].customerName = customerName;
    data[rearIndex].priority = priority;
    // ... assign other fields
    count++;
    
    return true;
}

// Dequeue highest priority
ServiceRequest Queue::dequeue() {
    if (isEmpty()) {
        // Handle error
    }
    
    int highestIndex = getHighestPriority();
    ServiceRequest request = data[highestIndex];
    
    // Shift or mark as removed
    frontIndex = (frontIndex + 1) % MAX_SIZE;
    count--;
    
    return request;
}
```

**Explanation**: [اشرح الكود]

[أضف screenshot للكود]

---

### 6.3 Linked List Implementation

**Key Functions**:

```cpp
// Insert agent at head
bool LinkedList::insertAgent(int agentId, string name, 
                             string specialization, 
                             string email, string phoneNumber) {
    // Check for duplicate
    if (searchAgent(agentId) != NULL) {
        return false;
    }
    
    // Create new node
    Node* newNode = new Node;
    newNode->data.agentId = agentId;
    newNode->data.name = name;
    newNode->data.specialization = specialization;
    newNode->data.email = email;
    newNode->data.phoneNumber = phoneNumber;
    newNode->data.assignedRequests = 0;
    newNode->data.isAvailable = true;
    
    // Insert at head
    newNode->next = head;
    head = newNode;
    count++;
    
    return true;
}

// Delete agent
bool LinkedList::deleteAgent(int agentId) {
    if (head == NULL) {
        return false;
    }
    
    // If head node
    if (head->data.agentId == agentId) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return true;
    }
    
    // Traverse to find
    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data.agentId == agentId) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            count--;
            return true;
        }
        current = current->next;
    }
    
    return false;  // Not found
}
```

**Explanation**: [اشرح الكود]

[أضف screenshot للكود]

---

### 6.4 BST Implementation

**Key Functions**:

```cpp
// Insert (public)
bool BST::insert(int requestId, string customerName, 
                 string issueType, string assignedAgent, 
                 string status, string createdTime) {
    if (search(requestId) != NULL) {
        return false;  // Duplicate
    }
    
    RequestRecord record;
    record.requestId = requestId;
    record.customerName = customerName;
    record.issueType = issueType;
    record.assignedAgent = assignedAgent;
    record.status = status;
    record.createdTime = createdTime;
    record.resolvedTime = "";
    
    root = insertHelper(root, record);
    count++;
    return true;
}

// Insert helper (private recursive)
BSTNode* BST::insertHelper(BSTNode* node, RequestRecord record) {
    if (node == NULL) {
        BSTNode* newNode = new BSTNode;
        newNode->data = record;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (record.requestId < node->data.requestId) {
        node->left = insertHelper(node->left, record);
    } else {
        node->right = insertHelper(node->right, record);
    }
    
    return node;
}

// Delete helper (handles 3 cases)
BSTNode* BST::deleteHelper(BSTNode* node, int requestId) {
    if (node == NULL) {
        return NULL;
    }
    
    if (requestId < node->data.requestId) {
        node->left = deleteHelper(node->left, requestId);
    } else if (requestId > node->data.requestId) {
        node->right = deleteHelper(node->right, requestId);
    } else {
        // Found the node to delete
        
        // Case 1: No left child
        if (node->left == NULL) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
        
        // Case 2: No right child
        if (node->right == NULL) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        
        // Case 3: Two children
        BSTNode* minNode = findMinNode(node->right);
        node->data = minNode->data;
        node->right = deleteHelper(node->right, minNode->data.requestId);
    }
    
    return node;
}
```

**Explanation**: [اشرح الكود وخصوصاً حالات الحذف الثلاثة]

[أضف screenshot للكود]

---

### 6.5 System Integration (HelpDesk Class)

**Key Integration Points**:

```cpp
// Create request - adds to both Queue and BST
int HelpDesk::createRequest(string customerName, string issueType, 
                            string description, int priority) {
    int requestId = getNextRequestId();
    string timestamp = getCurrentTimestamp();
    
    // Add to Queue for processing
    requestQueue.enqueue(requestId, customerName, issueType, 
                         description, priority, timestamp);
    
    // Add to BST for fast lookup
    requestTree.insert(requestId, customerName, issueType, 
                       "None", "Waiting", timestamp);
    
    totalRequests++;
    return requestId;
}

// Process request - integrates Queue, BST, and LinkedList
bool HelpDesk::processNextRequest() {
    if (requestQueue.isEmpty()) {
        return false;
    }
    
    // Dequeue highest priority
    ServiceRequest request = requestQueue.dequeue();
    
    // Find available agent
    Node* agentNode = agentList.findAvailableAgent(request.issueType);
    
    if (agentNode != NULL) {
        // Assign agent
        assignAgentToRequest(request.requestId, agentNode->data.agentId);
        
        // Update BST
        requestTree.updateStatus(request.requestId, "InProgress");
        
        // Update agent in linked list
        agentList.assignRequest(agentNode->data.agentId);
        
        return true;
    }
    
    // No agent available - re-enqueue
    requestQueue.enqueue(request.requestId, request.customerName, 
                         request.issueType, request.description, 
                         request.priority, request.timestamp);
    return false;
}
```

**Explanation**: [اشرح كيف تتكامل الـ data structures مع بعض]

[أضف screenshot للكود]

---

### 6.6 Searching Algorithm (Linear Search)

**Implementation**:

```cpp
void HelpDesk::linearSearchAgent(string name) {
    Node* current = agentList.head;
    int position = 1;
    int comparisons = 0;
    bool found = false;
    
    while (current != NULL) {
        comparisons++;
        
        if (current->data.name == name) {
            found = true;
            // Display agent details
            cout << "Agent found at position " << position << endl;
            cout << "Comparisons made: " << comparisons << endl;
            // Display full agent info
            break;
        }
        
        current = current->next;
        position++;
    }
    
    if (!found) {
        cout << "Agent not found after " << comparisons << " comparisons" << endl;
    }
    
    cout << "Big-O Complexity: O(n) where n = " << agentList.getCount() << endl;
}
```

**Why Linear Search?**
- Linked List doesn't support random access
- Must traverse sequentially
- Suitable for unsorted data
- Time complexity: O(n)

[أضف screenshot للكود]

---

### 6.7 Sorting Algorithm

**Implementation**: [اختر واحد: Bubble Sort, Insertion Sort, أو Selection Sort]

```cpp
void HelpDesk::sortRequestsByPriority() {
    // Example: Bubble Sort
    
    // Get requests from queue into array
    ServiceRequest requests[100];
    int count = 0;
    
    // Extract from queue
    while (!requestQueue.isEmpty()) {
        requests[count++] = requestQueue.dequeue();
    }
    
    // Bubble Sort
    int comparisons = 0;
    int swaps = 0;
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            comparisons++;
            
            if (requests[j].priority < requests[j + 1].priority) {
                // Swap
                ServiceRequest temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
                swaps++;
            }
        }
    }
    
    // Display sorted
    cout << "Sorted by Priority (Highest to Lowest):" << endl;
    for (int i = 0; i < count; i++) {
        // Display request
    }
    
    cout << "\nAlgorithm: Bubble Sort" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Time Complexity: O(n²) where n = " << count << endl;
    cout << "Space Complexity: O(1)" << endl;
    
    // Re-enqueue in sorted order
    for (int i = 0; i < count; i++) {
        requestQueue.enqueue(requests[i].requestId, 
                             requests[i].customerName,
                             requests[i].issueType,
                             requests[i].description,
                             requests[i].priority,
                             requests[i].timestamp);
    }
}
```

**Why Bubble Sort?**
- Simple to implement
- Works well for small datasets
- In-place sorting (O(1) space)
- Demonstrates O(n²) complexity

**Alternative**: Insertion Sort or Selection Sort

[أضف screenshot للكود]

---

## 7. TESTING

[أضف نتائج الاختبارات]

### 7.1 Normal Operation Tests

**Test Case 1: Create Request**
- **Input**: 
  - Customer: "Ahmed Ali"
  - Issue: "Hardware"
  - Description: "Printer not working"
  - Priority: 3 (High)
  
- **Expected Output**:
  - Request ID assigned (e.g., 1001)
  - Added to queue successfully
  - Added to BST successfully
  
- **Actual Output**:
  [أضف screenshot]
  
- **Result**: ✅ PASS / ❌ FAIL

---

**Test Case 2: Process Request**
- **Input**: Process next request from queue
- **Expected Output**:
  - Highest priority request dequeued
  - Available agent assigned
  - Status updated to "InProgress"
  
- **Actual Output**:
  [أضف screenshot]
  
- **Result**: ✅ PASS / ❌ FAIL

---

### 7.2 Edge Case Tests

**Test Case 3: Empty Stack Pop**
- **Input**: Pop from empty stack
- **Expected Output**: Error message, no crash
- **Actual Output**:
  [أضف screenshot]
- **Result**: ✅ PASS / ❌ FAIL

---

**Test Case 4: Full Stack Push**
- **Input**: Push 101 escalations (MAX_SIZE + 1)
- **Expected Output**: 100 successful, 101st fails with error
- **Actual Output**:
  [أضف screenshot]
- **Result**: ✅ PASS / ❌ FAIL

---

### 7.3 Integration Tests

**Test Case 5: End-to-End Workflow**
- **Steps**:
  1. Add 3 agents
  2. Create 5 requests
  3. Process 3 requests
  4. Escalate 1 request
  5. Resolve 1 request
  6. View statistics
  
- **Expected Results**:
  - 2 requests in queue ✅
  - 5 requests in BST ✅
  - 1 escalation in stack ✅
  - 3 agents with correct workload ✅
  - Statistics display correctly ✅
  
- **Actual Output**:
  [أضف screenshots للخطوات المختلفة]
  
- **Result**: ✅ PASS / ❌ FAIL

---

### 7.4 Search and Sort Tests

**Test Case 6: BST Search**
- **Input**: Search for request ID=1005
- **Expected**: Found in ~3 comparisons (log2(10) ≈ 3.3)
- **Actual**:
  [أضف screenshot]
- **Result**: ✅ PASS / ❌ FAIL

---

**Test Case 7: Linear Search**
- **Input**: Search for agent "Sara Mohamed" (position 10 out of 15)
- **Expected**: Found after 10 comparisons
- **Actual**:
  [أضف screenshot]
- **Result**: ✅ PASS / ❌ FAIL

---

**Test Case 8: Sort by Priority**
- **Input**: 10 requests with random priorities
- **Expected**: Sorted in descending order (4, 4, 3, 3, 2, 2, 2, 1, 1, 1)
- **Actual**:
  [أضف screenshot]
- **Result**: ✅ PASS / ❌ FAIL

---

### 7.5 Testing Summary Table

| Test Category | Total Tests | Passed | Failed | Pass Rate |
|---------------|-------------|--------|--------|-----------|
| Stack Operations | 6 | [X] | [Y] | [%] |
| Queue Operations | 6 | [X] | [Y] | [%] |
| Linked List Operations | 11 | [X] | [Y] | [%] |
| BST Operations | 10 | [X] | [Y] | [%] |
| Integration Tests | 5 | [X] | [Y] | [%] |
| Edge Cases | 8 | [X] | [Y] | [%] |
| Search/Sort | 3 | [X] | [Y] | [%] |
| **TOTAL** | **49** | **[X]** | **[Y]** | **[%]** |

---

## 8. COMPLEXITY ANALYSIS

### 8.1 Stack Operations

| Operation | Time Complexity | Space Complexity | Explanation |
|-----------|----------------|------------------|-------------|
| push() | O(1) | O(1) | Direct array access by index |
| pop() | O(1) | O(1) | Direct array access by index |
| peek() | O(1) | O(1) | Return top element without modification |
| isEmpty() | O(1) | O(1) | Simple comparison (top == -1) |
| isFull() | O(1) | O(1) | Simple comparison (top == MAX_SIZE-1) |
| display() | O(n) | O(1) | Must traverse all n elements |

---

### 8.2 Queue Operations

| Operation | Time Complexity | Space Complexity | Explanation |
|-----------|----------------|------------------|-------------|
| enqueue() | O(1) | O(1) | Direct insertion at rear |
| dequeue() | O(n)* | O(1) | Must find highest priority |
| front() | O(n)* | O(1) | Must find highest priority |
| isEmpty() | O(1) | O(1) | Check count == 0 |
| isFull() | O(1) | O(1) | Check count == MAX_SIZE |
| display() | O(n) | O(1) | Traverse all elements |

*Note: O(n) because we search for highest priority. Alternative implementations can make this O(1) using heap or sorted insertion.

---

### 8.3 Linked List Operations

| Operation | Time Complexity | Space Complexity | Explanation |
|-----------|----------------|------------------|-------------|
| insertAgent() | O(1) | O(1) | Insert at head is constant time |
| deleteAgent() | O(n) | O(1) | Must traverse to find agent |
| searchAgent() | O(n) | O(1) | Linear search through list |
| displayAgents() | O(n) | O(1) | Traverse entire list |
| updateAgent() | O(n) | O(1) | Search + update |
| findAvailableAgent() | O(n) | O(1) | Linear search with condition |

---

### 8.4 BST Operations

| Operation | Best/Average Case | Worst Case | Explanation |
|-----------|-------------------|------------|-------------|
| insert() | O(log n) | O(n) | Balanced vs. skewed tree |
| search() | O(log n) | O(n) | Binary search on balanced tree |
| delete() | O(log n) | O(n) | Find + restructure |
| inorderTraversal() | O(n) | O(n) | Visit all nodes once |
| preorderTraversal() | O(n) | O(n) | Visit all nodes once |
| findMin() | O(log n) | O(n) | Go left until NULL |
| findMax() | O(log n) | O(n) | Go right until NULL |

**Note**: Worst case O(n) occurs when tree becomes skewed (like a linked list). Average case O(log n) assumes balanced tree.

---

### 8.5 Searching Algorithms

#### BST Search
- **Average Case**: O(log n)
- **Worst Case**: O(n) if tree is skewed
- **Best Case**: O(1) if element is root
- **Space**: O(1) iterative, O(log n) recursive (call stack)

**Example**: For 1000 requests:
- Balanced BST: ~10 comparisons (log2(1000) ≈ 9.97)
- Skewed BST: up to 1000 comparisons

#### Linear Search
- **All Cases**: O(n)
- **Space**: O(1)

**Example**: For 100 agents:
- Average: 50 comparisons
- Worst: 100 comparisons (not found or at end)
- Best: 1 comparison (first element)

---

### 8.6 Sorting Algorithm

#### [Your Chosen Algorithm - Example: Bubble Sort]

**Time Complexity**:
- **Best Case**: O(n) - already sorted (optimized version)
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - reverse sorted

**Space Complexity**: O(1) - in-place sorting

**Comparisons**: n×(n-1)/2 in worst case

**Example**: For 20 requests:
- Comparisons: 20×19/2 = 190
- Swaps: varies (0 to 190)

**Why This Algorithm**:
[اشرح ليه اخترت هذا الـ algorithm]
- Simple to implement
- Suitable for small datasets
- Demonstrates O(n²) complexity clearly
- In-place (no extra memory needed)

---

### 8.7 Overall System Complexity

**Memory Usage**:
- Stack: O(n) where n = MAX_SIZE = 100
- Queue: O(m) where m = MAX_SIZE = 100
- Linked List: O(k) where k = number of agents (dynamic)
- BST: O(p) where p = total requests (dynamic)

**Total Space**: O(n + m + k + p)

**Typical Operation Workflow**:
1. Create Request: O(1) + O(log p) = O(log p)
2. Process Request: O(n) + O(log p) + O(k) = O(n + k + log p)
3. Escalate: O(1) + O(log p) = O(log p)
4. Resolve: O(log p) + O(k) = O(log p + k)

---

## 9. TEAM CONTRIBUTIONS

### 9.1 Individual Responsibilities

#### Member 1: عمر محمد
- **Files**: Stack.h, Stack.cpp
- **Contribution**:
  - Implemented all Stack operations
  - Tested push, pop, peek functions
  - Handled empty and full stack cases
  - Added display and clear functions
  - Documented code with comments
- **Hours**: [عدد الساعات]
- **Verification**: [Screenshots of git commits]

---

#### Member 2: خالد طه
- **Files**: Queue.h, Queue.cpp
- **Contribution**:
  - Implemented Priority Queue
  - Developed priority ordering logic
  - Tested enqueue/dequeue operations
  - Handled circular array implementation
  - Implemented getHighestPriority helper
- **Hours**: [عدد الساعات]
- **Verification**: [Screenshots of git commits]

---

#### Member 3: نور محمد
- **Files**: LinkedList.h, LinkedList.cpp
- **Contribution**:
  - Implemented Singly Linked List
  - Developed insert, delete, search functions
  - Handled memory management (new/delete)
  - Implemented agent availability tracking
  - Tested with various edge cases
- **Hours**: [عدد الساعات]
- **Verification**: [Screenshots of git commits]

---

#### Member 4: هبه رجب
- **Files**: BST.h, BST.cpp
- **Contribution**:
  - Implemented Binary Search Tree
  - Developed recursive insert/search/delete
  - Handled all 3 delete cases (0, 1, 2 children)
  - Implemented inorder and preorder traversals
  - Tested BST balance and operations
- **Hours**: [عدد الساعات]
- **Verification**: [Screenshots of git commits]

---

#### Member 5: مريم علاء
- **Files**: HelpDesk.h, HelpDesk.cpp
- **Contribution**:
  - Integrated all data structures
  - Developed main help desk operations
  - Implemented searching and sorting algorithms
  - Created end-to-end workflows
  - Ensured data consistency across structures
  - Developed statistics display
- **Hours**: [عدد الساعات]
- **Verification**: [Screenshots of git commits]

---

#### Member 6: نور وائل
- **Files**: main.cpp
- **Contribution**:
  - Developed menu-driven interface
  - Implemented input validation
  - Created all submenus
  - Wrote comprehensive test suite
  - Tested all features and edge cases
  - Documented testing results
  - Created user experience flow
- **Hours**: [عدد الساعات]
- **Verification**: [Screenshots of git commits]

---

### 9.2 Team Meetings

| Date | Attendees | Topics Discussed | Decisions Made |
|------|-----------|------------------|----------------|
| [Date] | All | Project kickoff, task distribution | Agreed on structure |
| [Date] | All | Progress review, integration planning | Decided on interfaces |
| [Date] | All | Testing and debugging | Assigned bug fixes |
| [Date] | All | Final review, report writing | Divided report sections |

---

### 9.3 Collaboration Summary

All team members:
- ✅ Attended regular meetings
- ✅ Completed assigned tasks on time
- ✅ Tested their code individually
- ✅ Helped with integration
- ✅ Contributed to report writing
- ✅ Understand the complete system

---

## 10. CONCLUSION

### 10.1 Achievements

This project successfully demonstrates:

1. **Data Structure Implementation**: All four required data structures (Stack, Queue, Linked List, BST) were implemented manually from scratch without using STL.

2. **Practical Integration**: The structures work together seamlessly to create a functional help desk system.

3. **Algorithm Application**: Both searching (BST search O(log n) and Linear search O(n)) and sorting (Bubble/Insertion/Selection Sort O(n²)) algorithms were implemented and analyzed.

4. **Error Handling**: The system handles edge cases (empty structures, full capacity, invalid inputs) gracefully.

5. **User Interface**: A menu-driven console interface makes the system usable and testable.

6. **Comprehensive Testing**: Extensive testing covers normal operations, edge cases, and integration scenarios.

---

### 10.2 Learning Outcomes

Through this project, we gained:

- **Deep understanding** of how data structures work internally
- **Practical experience** in choosing appropriate structures for specific problems
- **Problem-solving skills** in debugging and integration
- **Team collaboration** experience
- **Time complexity analysis** skills
- **Software design** principles

---

### 10.3 Current Limitations

1. **Memory Limitations**: 
   - Fixed-size Stack and Queue (MAX_SIZE = 100)
   - No dynamic resizing

2. **Data Persistence**: 
   - No file or database storage
   - Data lost when program exits

3. **BST Balance**: 
   - No self-balancing (AVL or Red-Black)
   - Can degrade to O(n) in worst case

4. **Concurrency**: 
   - Single-threaded
   - No support for multiple users

5. **User Interface**: 
   - Console-only
   - No graphical interface

6. **Validation**: 
   - Basic input validation
   - Could be more comprehensive

---

### 10.4 Possible Improvements

**Short-term improvements**:
1. Add file I/O for data persistence
2. Implement dynamic resizing for Stack and Queue
3. Add more validation and error messages
4. Improve sorting efficiency (use QuickSort or MergeSort)
5. Add search history tracking

**Long-term improvements**:
1. Convert to AVL or Red-Black Tree for guaranteed O(log n)
2. Implement Heap for better Priority Queue (O(log n) operations)
3. Add GUI using Qt or similar framework
4. Add database integration (MySQL/SQLite)
5. Implement multi-user support with authentication
6. Add email notifications
7. Generate PDF reports
8. Add data analytics and visualization

---

### 10.5 Real-World Applications

This system demonstrates concepts used in:
- **IT Service Management** (ServiceNow, JIRA Service Desk)
- **Customer Support Systems** (Zendesk, Freshdesk)
- **Hospital Emergency Systems** (patient triage)
- **Call Centers** (queue management)
- **Operating Systems** (process scheduling)

---

### 10.6 Final Remarks

This project successfully meets all CS212 course requirements:
- ✅ Implements 4 required data structures manually
- ✅ Integrates structures in a meaningful application
- ✅ Includes searching and sorting algorithms
- ✅ Provides menu-driven interface
- ✅ Handles edge cases and validates inputs
- ✅ Includes comprehensive testing
- ✅ Analyzes time complexity (Big-O)
- ✅ Demonstrates teamwork and documentation

The Help Desk Priority Simulation system serves as a practical example of how fundamental data structures learned in CS212 can be applied to solve real-world problems efficiently.

---

## APPENDICES

### Appendix A: Complete Code Listings
[أضف الكود الكامل لكل الملفات]

### Appendix B: Additional Screenshots
[أضف screenshots إضافية للتشغيل]

### Appendix C: Git Commit History
[أضف screenshots من GitHub showing commits]

### Appendix D: References
[اذكر أي مراجع استخدمتها]

1. Course Textbook: [اسم الكتاب]
2. C++ Documentation: https://cplusplus.com
3. Data Structures Tutorials: [أي موارد استخدمتها]

---

## SUBMISSION CHECKLIST

- [ ] Cover Page with all names and IDs
- [ ] Problem Definition complete
- [ ] Objectives listed
- [ ] All 4 data structures explained with justification
- [ ] System features described
- [ ] Implementation explained with code excerpts
- [ ] Screenshots of execution included
- [ ] Testing table with inputs, expected, actual, results
- [ ] Complexity analysis (Big-O) for all operations
- [ ] Team contributions documented
- [ ] Conclusion with limitations and improvements
- [ ] Report is PDF or DOCX format
- [ ] Grammar and spelling checked
- [ ] Proper formatting and organization

---

**End of Report Template**

**Good Luck! 🎓**
