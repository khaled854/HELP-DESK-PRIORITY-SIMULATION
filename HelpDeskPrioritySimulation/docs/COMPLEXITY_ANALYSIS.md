# COMPLEXITY ANALYSIS
## CS212 Help-Desk Priority Simulation

**Purpose:** Document Big-O time and space complexity for all major operations as required by PDF Page 10, Section 8.

---

## 1. STACK - EscalationStack (Member 1)

### Implementation Choice
- **Array-based** or **Linked-node** implementation (Member 1 decides)
- Both provide O(1) operations

### Time Complexity

| Operation | Best Case | Average Case | Worst Case | Explanation |
|-----------|-----------|--------------|------------|-------------|
| push() | O(1) | O(1) | O(1) | Add to top (array index or new node) |
| pop() | O(1) | O(1) | O(1) | Remove from top, adjust pointer/index |
| peek() | O(1) | O(1) | O(1) | Access top element directly |
| isEmpty() | O(1) | O(1) | O(1) | Check size or top pointer |
| size() | O(1) | O(1) | O(1) | Return tracked size variable |
| displayHistory() | O(n) | O(n) | O(n) | Must visit all n elements |

### Space Complexity

| Implementation | Space | Notes |
|---------------|-------|-------|
| Array-based | O(n) | Fixed capacity array |
| Linked-node | O(n) | Node per element + pointers |

### Justification
- LIFO behavior requires constant-time access to top element
- Stack is ideal for escalation history (most recent first)
- O(1) push/pop enables efficient event recording

---

## 2. QUEUE - PriorityRequestQueue (Member 2)

### Implementation Choice
- Three separate FIFO queues (HIGH, MEDIUM, LOW)
- Each queue: **Array-based** or **Linked-node** (Member 2 decides)

### Time Complexity

| Operation | Best Case | Average Case | Worst Case | Explanation |
|-----------|-----------|--------------|------------|-------------|
| enqueue() | O(1) | O(1) | O(1) | Add to rear of specific queue |
| dequeue() | O(1) | O(1) | O(1) | Remove from front of highest-priority queue |
| front() | O(1) | O(1) | O(1) | Access front element directly |
| isEmpty() | O(1) | O(1) | O(1) | Check all three queues |
| size() | O(1) | O(1) | O(1) | Sum of three queue sizes |
| getNextRequest() | O(1) | O(1) | O(1) | Check HIGH→MED→LOW in order |
| removeRequestById() | O(n) | O(n) | O(n) | Must search all three queues |

### Space Complexity

| Total Requests | Space | Notes |
|---------------|-------|-------|
| n waiting | O(n) | Distributed across 3 queues |

### Justification
- FIFO preserves fairness within priority level
- Dispatcher checks queues in priority order O(1)
- removeRequestById is O(n) but infrequent (cancellations only)

### Priority Scheduling Analysis
- **Best for HIGH:** Always served first if present
- **Fairness within priority:** FIFO order maintained
- **Starvation risk:** LOW priority may wait indefinitely if HIGH/MED keep arriving
- **Acceptable tradeoff:** Business priority over absolute fairness

---

## 3. LINKED LIST - AgentLinkedList (Member 3)

### Implementation Choice
- Singly linked list (adequate for agent management)
- Head pointer, manual nodes with next pointers

### Time Complexity

| Operation | Best Case | Average Case | Worst Case | Explanation |
|-----------|-----------|--------------|------------|-------------|
| insertAgent() | O(1) | O(1) | O(n) | O(1) at head; O(n) if checking duplicates or inserting at tail |
| deleteAgent() | O(1) | O(n) | O(n) | O(1) if first; O(n) to find agent |
| searchAgent() | O(1) | O(n) | O(n) | O(1) if first; O(n) linear search |
| updateAgent() | O(1) | O(n) | O(n) | Must search first, then update |
| displayAgents() | O(n) | O(n) | O(n) | Visit all n agents |
| getAgentCount() | O(1) | O(1) | O(n) | O(1) if tracked; O(n) if counted |
| isEmpty() | O(1) | O(1) | O(1) | Check head pointer |

### Space Complexity

| Agents | Space | Notes |
|--------|-------|-------|
| n agents | O(n) | One node per agent + pointers |

### Justification
- Linear search O(n) acceptable for small agent count (<50 typical)
- Simple structure, easy to maintain
- No need for complex indexing for this use case

### Optimization Opportunity (for discussion)
- Could add agent ID index (hash table) for O(1) search
- Tradeoff: increased complexity vs performance gain
- Current O(n) acceptable for project scope

---

## 4. BST - RequestBST (Member 4)

### Implementation Choice
- Manual Binary Search Tree
- **NOT BALANCED** (important limitation)
- Request ID as key

### Time Complexity

| Operation | Best Case | Average Case | Worst Case | Explanation |
|-----------|-----------|--------------|------------|-------------|
| insertRequest() | O(log n) | O(log n) | O(n) | Balanced: O(log n); Skewed: O(n) |
| deleteRequest() | O(log n) | O(log n) | O(n) | Same as insert + restructuring |
| searchRequest() | O(log n) | O(log n) | O(n) | Binary search if balanced |
| inorderTraversal() | O(n) | O(n) | O(n) | Must visit all n nodes |
| preorderTraversal() | O(n) | O(n) | O(n) | Must visit all n nodes |
| isEmpty() | O(1) | O(1) | O(1) | Check root pointer |
| getSize() | O(1) | O(1) | O(n) | O(1) if tracked; O(n) if counted |

### Space Complexity

| Requests | Space | Notes |
|----------|-------|-------|
| n requests | O(n) | One node per request + 2 pointers each |

### Average vs Worst Case Analysis

**Average Case: O(log n)**
- Assumes random insertion order
- Tree height ≈ log₂(n)
- Each operation traverses from root to depth log(n)

**Worst Case: O(n)**
- Occurs when IDs inserted in sorted order: 1, 2, 3, 4, 5...
- Tree becomes right-skewed linked list
- Height = n, operations degrade to O(n)

### Justification
- BST provides fast O(log n) search on average
- Request IDs likely random (timestamp-based), not sorted
- Worst case unlikely in practice
- Balancing (AVL/Red-Black) adds complexity beyond project scope

### Known Limitation (Document in Report)
Unbalanced BST can degrade to O(n) if request IDs are sequential. Acceptable tradeoff for this project. Real systems would use balanced trees.

---

## 5. MERGE SORT ALGORITHM (Member 6)

### Algorithm: Divide and Conquer

**Steps:**
1. Divide array into two halves
2. Recursively sort each half
3. Merge sorted halves

### Time Complexity

| Case | Complexity | Explanation |
|------|-----------|-------------|
| Best | O(n log n) | Always divides and merges same way |
| Average | O(n log n) | Independent of input order |
| Worst | O(n log n) | Still O(n log n) even if reverse-sorted |

### Space Complexity

| Resource | Complexity | Explanation |
|----------|-----------|-------------|
| Auxiliary Space | O(n) | Temporary arrays for merging |
| Stack Space | O(log n) | Recursion depth |

### Complexity Derivation

**Recurrence Relation:**
```
T(n) = 2T(n/2) + O(n)
```

- **2T(n/2):** Two recursive calls on half-size arrays
- **O(n):** Merging two sorted halves

**Solution by Master Theorem:**
```
T(n) = O(n log n)
```

**Intuitive Explanation:**
- **Levels of recursion:** log₂(n) levels (divide by 2 each time)
- **Work per level:** O(n) to merge all elements at that level
- **Total work:** O(n) × log₂(n) = O(n log n)

### Why Merge Sort for This Project?

1. **Guaranteed O(n log n)** - No worst-case degradation
2. **Stable sort** - Maintains relative order of equal elements
3. **Course requirement** - Classic divide-and-conquer algorithm
4. **Good for reports** - Predictable performance

### Comparison with Other Sorts

| Algorithm | Average | Worst | Stable | Notes |
|-----------|---------|-------|--------|-------|
| Merge Sort | O(n log n) | O(n log n) | Yes | Used in project |
| Quick Sort | O(n log n) | O(n²) | No | Faster average, worse worst case |
| Bubble Sort | O(n²) | O(n²) | Yes | Too slow |
| Insertion Sort | O(n²) | O(n²) | Yes | Good for small n only |

---

## 6. APPLICATION-LEVEL OPERATIONS

### Create Request

```
createRequest():
    1. Validate inputs - O(1)
    2. BST.insertRequest() - O(log n) average
    3. Queue.enqueue() - O(1)
    Total: O(log n) average, O(n) worst
```

### Assign Request

```
assignRequest():
    1. Queue.dequeue() - O(1)
    2. BST.searchRequest() - O(log n) average
    3. LinkedList.searchAgent() - O(m) where m = agent count
    4. Update both - O(1)
    Total: O(m + log n) where m typically << n
```

### Escalate Request

```
escalateRequest():
    1. BST.searchRequest() - O(log n) average
    2. Stack.push() - O(1)
    3. Update BST - O(1)
    4. Queue.removeRequestById() - O(n)
    5. Queue.enqueue() - O(1)
    Total: O(n) due to queue removal
```

### Generate Report

```
generateReport():
    1. BST.inorderTraversal() - O(n)
    2. Merge Sort - O(n log n)
    3. Display - O(n)
    Total: O(n log n)
```

---

## 7. SPACE COMPLEXITY SUMMARY

| Component | Space Complexity | Notes |
|-----------|-----------------|-------|
| Stack | O(e) | e = escalation events |
| Queue | O(w) | w = waiting requests |
| LinkedList | O(a) | a = agents |
| BST | O(r) | r = total requests |
| Merge Sort | O(r) | Auxiliary space for sorting |
| **Total** | **O(r + w + a + e)** | Typically r ≈ w, so O(r) |

---

## 8. PERFORMANCE CHARACTERISTICS

### Small Scale (Typical Help Desk)
- Requests: 100-500
- Agents: 10-20
- Escalations: 10-50

**Performance:**
- All operations feel instant (<1ms)
- BST depth ≈ 7-9 (balanced case)
- Linear searches acceptable

### Large Scale (Enterprise)
- Requests: 10,000+
- Agents: 100+

**Bottlenecks:**
- Unbalanced BST could degrade
- Agent search O(n) becomes noticeable
- Queue removal O(n) slower for cancellations

**Optimizations (for discussion):**
- Balance BST (AVL, Red-Black)
- Index agents by ID (hash table)
- Better queue removal strategy

---

## 9. COMPLEXITY COMPARISON: OUR IMPLEMENTATION VS ALTERNATIVES

### Stack: Array vs Linked Node

| Implementation | push() | pop() | Space |
|---------------|--------|-------|-------|
| Array | O(1) | O(1) | O(capacity) - may waste space |
| Linked | O(1) | O(1) | O(n) - exact space |

**Our Choice:** Both acceptable; Member 1 decides based on preference.

### Queue: Array vs Linked Node

| Implementation | enqueue() | dequeue() | Space |
|---------------|-----------|-----------|-------|
| Circular Array | O(1) | O(1) | O(capacity) |
| Linked | O(1) | O(1) | O(n) exact |

**Our Choice:** Both acceptable; Member 2 decides.

### Agent Storage: LinkedList vs Array vs Hash

| Structure | Search | Insert | Delete | Space |
|-----------|--------|--------|--------|-------|
| LinkedList | O(n) | O(1) | O(n) | O(n) |
| Array | O(n) | O(1) at end | O(n) | O(capacity) |
| Hash Table | O(1) avg | O(1) | O(1) | O(n) + overhead |

**Our Choice:** LinkedList satisfies project requirement; hash table beyond scope.

### Request Index: BST vs Hash vs Array

| Structure | Search | Insert | Delete | Sorted Access |
|-----------|--------|--------|--------|--------------|
| Unbalanced BST | O(log n) avg | O(log n) avg | O(log n) avg | O(n) traversal |
| Balanced BST | O(log n) | O(log n) | O(log n) | O(n) traversal |
| Hash Table | O(1) avg | O(1) | O(1) | No |
| Sorted Array | O(log n) binary | O(n) | O(n) | Direct |

**Our Choice:** BST satisfies requirement; provides search + sorted traversal.

---

## 10. REALISTIC LIMITATIONS (For Report Conclusion)

1. **Unbalanced BST:** Can degrade to O(n) with sequential IDs
2. **Low-priority starvation:** May wait indefinitely
3. **Agent search O(n):** Slow with many agents
4. **Queue removal O(n):** Slow for cancellations
5. **No persistent storage:** Data lost on exit

**These are acceptable tradeoffs for the project scope and should be discussed during oral examination.**

---

## 11. BIG-O NOTATION REFERENCE (For Discussion)

### Common Complexities (Best to Worst)

| Complexity | Name | Example |
|-----------|------|---------|
| O(1) | Constant | Stack push, Queue enqueue |
| O(log n) | Logarithmic | BST search (balanced) |
| O(n) | Linear | LinkedList search, traversals |
| O(n log n) | Log-linear | Merge Sort |
| O(n²) | Quadratic | Bubble Sort, nested loops |
| O(2ⁿ) | Exponential | Fibonacci (naive) |

### Growth Rate Example (n=1000)

| Complexity | Operations |
|-----------|-----------|
| O(1) | 1 |
| O(log n) | ~10 |
| O(n) | 1,000 |
| O(n log n) | ~10,000 |
| O(n²) | 1,000,000 |

---

**This complexity analysis must be included in Project Report Section 8 (PDF Page 10).**

**Be prepared to explain any complexity during oral discussion.**
