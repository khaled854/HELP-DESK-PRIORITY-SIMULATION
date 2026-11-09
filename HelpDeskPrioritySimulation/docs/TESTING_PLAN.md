# TESTING PLAN
## CS212 Help-Desk Priority Simulation

**Purpose:** Define comprehensive testing strategy covering all requirements from official PDF Page 11.

---

## TESTING PHILOSOPHY

1. **Every member tests their own module** - No testing-only roles
2. **Test BEFORE integration** - Unit test your code independently
3. **Integration testing is shared** - All members participate
4. **Document test results** - Required for project report
5. **Test edge cases rigorously** - Empty, boundary, invalid inputs
6. **No fabricated test results** - Run actual tests, record real outputs

---

## REQUIRED TEST CATEGORIES (PDF Page 11)

### 1. Normal Operation
Test typical use cases with valid inputs

### 2. Empty Structure
Test operations on empty Stack, Queue, LinkedList, BST

### 3. Boundary and Single Item
Test with one element, first/last operations, capacity limits

### 4. Invalid Data
Test non-numeric input, duplicate IDs, non-existent keys, unexpected values

### 5. Integration
Test workflows crossing multiple data structures

### 6. Algorithm and Complexity
Verify sorting correctness and explain Big-O

---

## MEMBER 1: STACK TESTS

**Module:** EscalationStack, EscalationService  
**Owner:** Member 1

### Unit Tests - EscalationStack

| Test ID | Test Name | Input | Expected Output | Actual Output | Result |
|---------|-----------|-------|----------------|---------------|--------|
| S-01 | Push single event | 1 escalation | Stack size = 1, top = event | TBD | TBD |
| S-02 | Push multiple events | 5 escalations | Stack size = 5, LIFO order | TBD | TBD |
| S-03 | Pop from stack | After 3 pushes, pop once | Return top event, size = 2 | TBD | TBD |
| S-04 | Pop from empty stack | Pop when size = 0 | Error message, no crash | TBD | TBD |
| S-05 | Peek without removing | After 2 pushes, peek | Return top, size unchanged | TBD | TBD |
| S-06 | Peek empty stack | Peek when size = 0 | Error message, no crash | TBD | TBD |
| S-07 | isEmpty - empty | New stack | Returns true | TBD | TBD |
| S-08 | isEmpty - not empty | After push | Returns false | TBD | TBD |
| S-09 | Size tracking | Push 3, pop 1 | size() returns 2 | TBD | TBD |
| S-10 | Display history | 5 events in stack | Prints all in LIFO order | TBD | TBD |
| S-11 | LIFO verification | Push A, B, C; pop 3 times | Pop order: C, B, A | TBD | TBD |

### Integration Tests

| Test ID | Test Name | Workflow | Expected | Result |
|---------|-----------|----------|----------|--------|
| S-I1 | Escalation triggers stack | Escalate request priority | Event pushed to stack | TBD |
| S-I2 | Multiple escalations | Escalate 3 different requests | 3 events in stack, LIFO order | TBD |
| S-I3 | Escalation history display | Generate report | Recent escalations shown correctly | TBD |

---

## MEMBER 2: QUEUE TESTS

**Module:** PriorityRequestQueue, RequestDispatcher  
**Owner:** Member 2

### Unit Tests - PriorityRequestQueue

| Test ID | Test Name | Input | Expected Output | Actual Output | Result |
|---------|-----------|-------|----------------|---------------|--------|
| Q-01 | Enqueue HIGH | ID 101, HIGH | HIGH queue size = 1 | TBD | TBD |
| Q-02 | Enqueue MEDIUM | ID 102, MEDIUM | MEDIUM queue size = 1 | TBD | TBD |
| Q-03 | Enqueue LOW | ID 103, LOW | LOW queue size = 1 | TBD | TBD |
| Q-04 | Dequeue priority order | Enqueue 1 HIGH, 1 MED, 1 LOW, dequeue | Returns HIGH ID first | TBD | TBD |
| Q-05 | FIFO within priority | Enqueue 101, 102, 103 all HIGH, dequeue 3x | Order: 101, 102, 103 | TBD | TBD |
| Q-06 | Dequeue from empty | All queues empty, dequeue | Returns -1 or error | TBD | TBD |
| Q-07 | Front without removing | Enqueue 3 HIGH, call front(HIGH) | Returns first ID, queue unchanged | TBD | TBD |
| Q-08 | isEmpty - all empty | New queue | Returns true | TBD | TBD |
| Q-09 | isEmpty - specific priority | HIGH has items, MED empty | isEmpty(MED) = true | TBD | TBD |
| Q-10 | Size tracking | Enqueue 2 HIGH, 3 MED, 1 LOW | size() = 6 | TBD | TBD |
| Q-11 | Remove by ID | Enqueue 101,102,103 MED; remove 102 | 102 removed, queue size = 2 | TBD | TBD |
| Q-12 | Mixed priority dispatch | HIGH=2, MED=3, LOW=1; dequeue 6x | HIGH first, then MED, then LOW | TBD | TBD |

### Integration Tests

| Test ID | Test Name | Workflow | Expected | Result |
|---------|-----------|----------|----------|--------|
| Q-I1 | Create request enqueues | Create new request with MED | Request ID in MEDIUM queue | TBD |
| Q-I2 | Assignment dequeues | Assign next request | Highest priority dequeued | TBD |
| Q-I3 | Cancel removes from queue | Cancel waiting request | Removed from queue | TBD |
| Q-I4 | Escalate moves queues | Escalate MED → HIGH | ID moved from MED to HIGH queue | TBD |

---

## MEMBER 3: LINKED LIST TESTS

**Module:** AgentLinkedList, AgentService  
**Owner:** Member 3

### Unit Tests - AgentLinkedList

| Test ID | Test Name | Input | Expected Output | Actual Output | Result |
|---------|-----------|-------|----------------|---------------|--------|
| L-01 | Insert first agent | Agent ID 1 | List size = 1, head points to agent | TBD | TBD |
| L-02 | Insert multiple agents | 5 agents | List size = 5, all present | TBD | TBD |
| L-03 | Delete first agent | Insert 3, delete first | Size = 2, first agent removed | TBD | TBD |
| L-04 | Delete last agent | Insert 3, delete last | Size = 2, last agent removed | TBD | TBD |
| L-05 | Delete middle agent | Insert 5, delete 3rd | Size = 4, middle removed | TBD | TBD |
| L-06 | Delete from single-agent list | 1 agent, delete it | Size = 0, list empty | TBD | TBD |
| L-07 | Delete from empty list | Empty list, delete ID | Returns false, no crash | TBD | TBD |
| L-08 | Search existing agent | 5 agents, search for 3rd | Returns agent pointer | TBD | TBD |
| L-09 | Search non-existent | Search for invalid ID | Returns nullptr | TBD | TBD |
| L-10 | Search in empty list | Empty list, search | Returns nullptr | TBD | TBD |
| L-11 | Update agent | Insert agent, update availability | Agent updated successfully | TBD | TBD |
| L-12 | Prevent duplicate ID | Insert ID 5, insert ID 5 again | Second insert rejected | TBD | TBD |
| L-13 | Display all agents | 5 agents in list | All 5 displayed | TBD | TBD |
| L-14 | isEmpty - empty | New list | Returns true | TBD | TBD |
| L-15 | isEmpty - not empty | After insert | Returns false | TBD | TBD |

### Integration Tests

| Test ID | Test Name | Workflow | Expected | Result |
|---------|-----------|----------|----------|--------|
| L-I1 | Find available agent | 3 agents, 2 busy, 1 available | Returns available agent | TBD |
| L-I2 | Assignment updates agent | Assign request to agent | Agent marked BUSY | TBD |
| L-I3 | Resolution frees agent | Resolve request | Agent marked AVAILABLE | TBD |
| L-I4 | No available agents | All agents BUSY, try assign | Error message, no crash | TBD |

---

## MEMBER 4: BST TESTS

**Module:** RequestBST, RequestIndexService  
**Owner:** Member 4

### Unit Tests - RequestBST

| Test ID | Test Name | Input | Expected Output | Actual Output | Result |
|---------|-----------|-------|----------------|---------------|--------|
| B-01 | Insert root | Insert first request | Root created, size = 1 | TBD | TBD |
| B-02 | Insert left child | Insert ID < root | Left subtree populated | TBD | TBD |
| B-03 | Insert right child | Insert ID > root | Right subtree populated | TBD | TBD |
| B-04 | Insert multiple (balanced) | Insert 7 IDs (4,2,6,1,3,5,7) | Balanced tree created | TBD | TBD |
| B-05 | Insert sorted (worst case) | Insert 1,2,3,4,5 ascending | Right-skewed tree, still works | TBD | TBD |
| B-06 | Reject duplicate ID | Insert ID 10, insert ID 10 again | Second insert returns false | TBD | TBD |
| B-07 | Search existing | Insert 5 requests, search for middle | Returns correct request | TBD | TBD |
| B-08 | Search non-existent | Search for ID not in tree | Returns nullptr | TBD | TBD |
| B-09 | Search in empty tree | Empty tree, search | Returns nullptr | TBD | TBD |
| B-10 | Delete leaf node | Insert 3 nodes, delete leaf | Leaf removed, size = 2 | TBD | TBD |
| B-11 | Delete node with 1 child | Delete node with only left child | Child replaces parent | TBD | TBD |
| B-12 | Delete node with 2 children | Delete node with both children | Inorder successor replaces | TBD | TBD |
| B-13 | Delete root | Delete root node | Tree restructured correctly | TBD | TBD |
| B-14 | Inorder traversal | Insert 5,3,7,1,4,6,8 | Output: 1,3,4,5,6,7,8 (sorted) | TBD | TBD |
| B-15 | Preorder traversal | Insert 5,3,7,1,4,6,8 | Output: 5,3,1,4,7,6,8 | TBD | TBD |
| B-16 | isEmpty - empty | New tree | Returns true | TBD | TBD |
| B-17 | isEmpty - not empty | After insert | Returns false | TBD | TBD |

### Integration Tests

| Test ID | Test Name | Workflow | Expected | Result |
|---------|-----------|----------|----------|--------|
| B-I1 | Create request indexes | Create new request | Request added to BST | TBD |
| B-I2 | Search by ID works | Search for request by ID | BST returns full request | TBD |
| B-I3 | Cancel removes from BST | Cancel request | Request deleted from BST | TBD |
| B-I4 | Report uses traversal | Generate report | BST traversal provides all requests | TBD |

---

## MEMBER 5: REQUEST SERVICE & INTEGRATION TESTS

**Module:** RequestService, HelpDeskCoordinator  
**Owner:** Member 5  
**Focus:** Cross-module workflows

### Integration Test Scenarios

| Test ID | Scenario | Steps | Expected | Result |
|---------|----------|-------|----------|--------|
| I-01 | End-to-end: Create | User creates HIGH request | In BST and HIGH queue | TBD |
| I-02 | End-to-end: Assign | Create, then assign to agent | Dequeued, assigned, agent busy | TBD |
| I-03 | End-to-end: Escalate | Create MED, escalate to HIGH | Stack has event, moved to HIGH queue | TBD |
| I-04 | End-to-end: Cancel | Create request, then cancel | Removed from BST and queue | TBD |
| I-05 | End-to-end: Resolve | Assign request, then resolve | Status updated, agent available | TBD |
| I-06 | Multi-request workflow | Create 5 requests, assign 3 | Correct queue/BST states | TBD |
| I-07 | Priority order verification | 2 HIGH, 3 MED, 1 LOW; assign 6x | HIGH assigned first | TBD |
| I-08 | Consistency check | Various operations | BST, Queue, Stack, List consistent | TBD |
| I-09 | Error: duplicate ID | Try create duplicate | Rejected, not added | TBD |
| I-10 | Error: assign with no agents | Queue has requests, no agents | Error message | TBD |

---

## MEMBER 6: ALGORITHM & VALIDATION TESTS

**Module:** RequestSort, InputValidator, App  
**Owner:** Member 6

### Merge Sort Tests

| Test ID | Test Name | Input | Expected Output | Actual Output | Result |
|---------|-----------|-------|----------------|---------------|--------|
| A-01 | Sort 1 request | Array size 1 | Same array (trivial) | TBD | TBD |
| A-02 | Sort 2 requests | IDs [5,2] | [2,5] | TBD | TBD |
| A-03 | Sort 5 requests by priority | Mixed priorities | HIGH, MED, LOW order | TBD | TBD |
| A-04 | Sort 10 requests by ID | Random IDs | Ascending ID order | TBD | TBD |
| A-05 | Sort already sorted | [1,2,3,4,5] | [1,2,3,4,5] (stable) | TBD | TBD |
| A-06 | Sort reverse order | [5,4,3,2,1] | [1,2,3,4,5] | TBD | TBD |
| A-07 | Sort with duplicates | [3,1,2,1,3] | [1,1,2,3,3] | TBD | TBD |
| A-08 | Performance test | 20 requests | Completes in reasonable time | TBD | TBD |

### Input Validation Tests

| Test ID | Test Name | Input | Expected | Result |
|---------|-----------|-------|----------|--------|
| V-01 | Valid integer | "5" | Returns 5 | TBD |
| V-02 | Non-numeric | "abc" | Re-prompt, no crash | TBD |
| V-03 | Out of range | "999" when max=10 | Re-prompt | TBD |
| V-04 | Empty string | "" for name | Re-prompt | TBD |
| V-05 | Valid priority | "HIGH" | Returns HIGH | TBD |
| V-06 | Invalid priority | "URGENT" | Re-prompt | TBD |

---

## COMPREHENSIVE TEST RESULTS TABLE (For Project Report)

### Format:

| Test Category | Total Tests | Passed | Failed | Pass Rate |
|--------------|-------------|--------|--------|-----------|
| Stack Unit Tests | 11 | TBD | TBD | TBD% |
| Queue Unit Tests | 12 | TBD | TBD | TBD% |
| LinkedList Unit Tests | 15 | TBD | TBD | TBD% |
| BST Unit Tests | 17 | TBD | TBD | TBD% |
| Merge Sort Tests | 8 | TBD | TBD | TBD% |
| Input Validation Tests | 6 | TBD | TBD | TBD% |
| Stack Integration | 3 | TBD | TBD | TBD% |
| Queue Integration | 4 | TBD | TBD | TBD% |
| LinkedList Integration | 4 | TBD | TBD | TBD% |
| BST Integration | 4 | TBD | TBD | TBD% |
| Full Workflow Integration | 10 | TBD | TBD | TBD% |
| **TOTAL** | **94** | TBD | TBD | TBD% |

---

## TESTING WORKFLOW

### Phase 1: Unit Testing (Week 2)
- Each member tests their data structure independently
- No dependencies on other modules
- Use stub/mock data if needed
- Record results in tables above

### Phase 2: Service Testing (Week 2-3)
- Test service layer operations
- Use actual data structure implementations
- Verify service logic correctness

### Phase 3: Integration Testing (Week 3)
- All members participate
- Test cross-module workflows
- Member 5 coordinates sessions
- Fix integration bugs

### Phase 4: System Testing (Week 4)
- Full end-to-end scenarios
- User acceptance testing
- Performance verification
- Edge case hunting

---

## TESTING DOCUMENTATION FOR REPORT

**Required in Project Report (PDF Page 10, Section 7):**

1. **Test Cases Table** - Show test inputs, expected outputs, actual outputs
2. **Test Results** - Pass/fail for each test
3. **Screenshots** - Key test executions
4. **Edge Cases** - Document how edge cases were handled
5. **Integration Verification** - Show cross-module workflows working

---

## NO FABRICATED RESULTS

⚠️ **IMPORTANT:**
- Do NOT fill in "Actual Output" or "Result" columns until you ACTUALLY RUN the tests
- Do NOT claim 100% pass rate without evidence
- If tests fail, document the failure and fix
- Screenshots must show REAL execution, not mockups

---

## TESTING TOOLS

- **Manual Testing:** Console output verification
- **Debugging:** Print statements, debugger breakpoints
- **Memory Checking:** Manual review, no leaks
- **Integration:** Team testing sessions

---

## TESTING SUCCESS CRITERIA

✅ All data structures tested independently  
✅ All edge cases covered  
✅ All integration scenarios working  
✅ No crashes or undefined behavior  
✅ Results documented with evidence  
✅ Every member has tested their module  

---

**Testing is NOT optional. It's required for the project report and assessment.**

**Start testing during implementation, not after.**
