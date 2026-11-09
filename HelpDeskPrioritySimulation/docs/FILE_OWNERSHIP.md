# FILE OWNERSHIP MATRIX
## CS212 Help-Desk Priority Simulation

**Purpose:** Clearly assign each source file to exactly ONE primary owner to prevent conflicts and ensure accountability.

---

## OWNERSHIP RULES

1. ✅ Every source file has **exactly ONE** primary owner
2. ✅ Only the primary owner modifies that file directly
3. ✅ Shared files (models, constants) have designated coordinators
4. ✅ Changes to shared interfaces require team agreement
5. ✅ Integration changes go through Pull Requests
6. ✅ No member modifies another's data structure implementation
7. ✅ Service layer can USE data structures but not modify their internals

---

## OWNERSHIP MATRIX

| File | Primary Owner | Dependencies | Other Allowed Editors |
|------|--------------|--------------|----------------------|
| **main.cpp** | Member 6 | HelpDeskApp | None |
| **CMakeLists.txt** | Member 6 | All | All (with approval) |
| **.gitignore** | Member 6 | None | All (with approval) |

### Application Layer (`src/app/`)

| File | Owner | Uses | Notes |
|------|-------|------|-------|
| HelpDeskApp.h | Member 6 | All services | Main orchestrator |
| HelpDeskApp.cpp | Member 6 | All services | |
| MenuController.h | Member 6 | All services, InputValidator | |
| MenuController.cpp | Member 6 | All services, InputValidator | |

### Models (`src/models/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| ServiceRequest.h | Member 5 | All | **SHARED** - coordinate changes |
| ServiceRequest.cpp | Member 5 | All | |
| Agent.h | Member 3 | AgentLinkedList, AgentService | |
| Agent.cpp | Member 3 | AgentLinkedList, AgentService | |
| EscalationEvent.h | Member 1 | EscalationStack, EscalationService | |
| EscalationEvent.cpp | Member 1 | EscalationStack, EscalationService | |
| PriorityLevel.h | Member 5 | All | **SHARED** enum - coordinate changes |
| RequestStatus.h | Member 5 | All | **SHARED** enum - coordinate changes |

### Data Structures - Stack (`src/data_structures/stack/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| EscalationStack.h | Member 1 | EscalationService | **DO NOT MODIFY** by others |
| EscalationStack.cpp | Member 1 | EscalationService | **DO NOT MODIFY** by others |

### Data Structures - Queue (`src/data_structures/queue/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| PriorityRequestQueue.h | Member 2 | RequestDispatcher | **DO NOT MODIFY** by others |
| PriorityRequestQueue.cpp | Member 2 | RequestDispatcher | **DO NOT MODIFY** by others |

### Data Structures - Linked List (`src/data_structures/linked_list/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| AgentLinkedList.h | Member 3 | AgentService | **DO NOT MODIFY** by others |
| AgentLinkedList.cpp | Member 3 | AgentService | **DO NOT MODIFY** by others |

### Data Structures - BST (`src/data_structures/bst/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| RequestBST.h | Member 4 | RequestIndexService | **DO NOT MODIFY** by others |
| RequestBST.cpp | Member 4 | RequestIndexService | **DO NOT MODIFY** by others |

### Services (`src/services/`)

| File | Owner | Uses | Notes |
|------|-------|------|-------|
| EscalationService.h | Member 1 | EscalationStack | |
| EscalationService.cpp | Member 1 | EscalationStack | |
| RequestDispatcher.h | Member 2 | PriorityRequestQueue | |
| RequestDispatcher.cpp | Member 2 | PriorityRequestQueue | |
| AgentService.h | Member 3 | AgentLinkedList | |
| AgentService.cpp | Member 3 | AgentLinkedList | |
| RequestIndexService.h | Member 4 | RequestBST | |
| RequestIndexService.cpp | Member 4 | RequestBST | |
| RequestService.h | Member 5 | All other services | **Integration coordinator** |
| RequestService.cpp | Member 5 | All other services | |
| HelpDeskCoordinator.h | Member 5 | All services | **Integration coordinator** |
| HelpDeskCoordinator.cpp | Member 5 | All services | |

### Algorithms (`src/algorithms/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| RequestSort.h | Member 6 | HelpDeskCoordinator | Merge Sort |
| RequestSort.cpp | Member 6 | HelpDeskCoordinator | |

### Utilities (`src/utils/`)

| File | Owner | Used By | Notes |
|------|-------|---------|-------|
| InputValidator.h | Member 6 | All user-facing code | **SHARED** utility |
| InputValidator.cpp | Member 6 | All user-facing code | |
| Constants.h | Member 6 | All | **SHARED** - coordinate changes |

---

## DEPENDENCY DIAGRAM

```
main.cpp (M6)
  ↓
HelpDeskApp (M6)
  ↓
MenuController (M6)
  ↓
┌────────────────────────────────────┐
│   HelpDeskCoordinator (M5)         │  ← Integration Hub
└────────────────────────────────────┘
  ↓           ↓            ↓           ↓
EscalationService  RequestService  AgentService  RequestDispatcher
    (M1)              (M5)            (M3)           (M2)
    ↓                 ↓               ↓              ↓
EscalationStack  RequestIndexService  AgentLinkedList  PriorityRequestQueue
    (M1)              (M4)              (M3)             (M2)
                      ↓
                 RequestBST
                    (M4)

Shared Models: ServiceRequest, Agent, EscalationEvent, Enums
Shared Utils: InputValidator, Constants
Shared Algorithm: RequestSort (M6)
```

---

## COLLABORATION PROTOCOLS

### Protocol 1: Direct Ownership
**Rule:** Only the file owner makes direct commits to their owned files.

**Example:**
- Member 1 is the ONLY person who modifies `EscalationStack.cpp`
- Member 2 is the ONLY person who modifies `PriorityRequestQueue.cpp`

### Protocol 2: Shared Models
**Rule:** Changes to shared models require team notification and approval.

**Shared Files:**
- `ServiceRequest.h/cpp` (Member 5 coordinates)
- `PriorityLevel.h` (Member 5 coordinates)
- `RequestStatus.h` (Member 5 coordinates)
- `Constants.h` (Member 6 coordinates)
- `InputValidator.h/cpp` (Member 6 coordinates)

**Process:**
1. Owner proposes change in team discussion or Pull Request
2. All dependent modules review
3. Unanimous approval required
4. Owner makes change
5. Dependent modules update if needed

### Protocol 3: API Changes
**Rule:** Public function signatures cannot be changed without team agreement.

**Process:**
1. Identify who depends on the function (see API_CONTRACTS.md)
2. Propose change with justification
3. All dependents must approve
4. Update API_CONTRACTS.md
5. Implement change
6. Dependents update their code

**Example:**
If Member 2 wants to change `PriorityRequestQueue.enqueue()` signature:
- Member 5 (RequestService) depends on it
- Member 5 must approve the change
- Member 2 updates API_CONTRACTS.md
- Member 2 implements change
- Member 5 updates RequestService accordingly

### Protocol 4: Integration Work
**Rule:** Member 5 coordinates integration but does NOT reimplement others' modules.

**Member 5 Responsibilities:**
- ✅ Call other services' public APIs
- ✅ Coordinate workflows across modules
- ✅ Handle integration testing
- ✅ Ensure data consistency

**Member 5 CANNOT:**
- ❌ Modify EscalationStack internals
- ❌ Modify PriorityRequestQueue internals
- ❌ Modify AgentLinkedList internals
- ❌ Modify RequestBST internals

### Protocol 5: Pull Request Review
**Rule:** Pull requests must be reviewed by affected module owners.

**Review Matrix:**

| Change Type | Required Reviewers |
|------------|-------------------|
| Data structure implementation | Module owner only |
| Service using data structure | Data structure owner + integration coordinator (M5) |
| Shared model | All dependent module owners |
| Integration workflow | Member 5 + all involved modules |
| Main app or menu | Member 6 + Member 5 |

### Protocol 6: Merge Conflicts
**Rule:** File owner resolves conflicts in their owned files.

**Process:**
1. Identify conflict file
2. Determine file owner (use this matrix)
3. File owner resolves conflict
4. If conflict involves shared file, owners discuss resolution
5. Test after resolution

---

## FORBIDDEN MODIFICATIONS

### Member 1 Cannot Modify:
- PriorityRequestQueue (Member 2's)
- AgentLinkedList (Member 3's)
- RequestBST (Member 4's)
- RequestService (Member 5's)
- HelpDeskApp, MenuController (Member 6's)

**Can Use:** Their public APIs

### Member 2 Cannot Modify:
- EscalationStack (Member 1's)
- AgentLinkedList (Member 3's)
- RequestBST (Member 4's)
- RequestService (Member 5's)
- HelpDeskApp, MenuController (Member 6's)

**Can Use:** Their public APIs

### Member 3 Cannot Modify:
- EscalationStack (Member 1's)
- PriorityRequestQueue (Member 2's)
- RequestBST (Member 4's)
- RequestService (Member 5's)
- HelpDeskApp, MenuController (Member 6's)

**Can Use:** Their public APIs

### Member 4 Cannot Modify:
- EscalationStack (Member 1's)
- PriorityRequestQueue (Member 2's)
- AgentLinkedList (Member 3's)
- RequestService (Member 5's)
- HelpDeskApp, MenuController (Member 6's)

**Can Use:** Their public APIs

### Member 5 Cannot Modify:
- EscalationStack (Member 1's)
- PriorityRequestQueue (Member 2's)
- AgentLinkedList (Member 3's)
- RequestBST (Member 4's)
- HelpDeskApp, MenuController (Member 6's)

**Can Use:** All their public APIs (integration role)

### Member 6 Cannot Modify:
- EscalationStack (Member 1's)
- PriorityRequestQueue (Member 2's)
- AgentLinkedList (Member 3's)
- RequestBST (Member 4's)
- RequestService, HelpDeskCoordinator (Member 5's)

**Can Use:** All public APIs through app interface

---

## COMMUNICATION CHANNELS

### File Change Notifications
When modifying any file, announce in team communication:

**Format:**
```
[FILE CHANGE] <filename>
Owner: <member>
Type: <implementation/API/shared>
Affects: <list dependent modules>
Description: <brief change description>
```

**Example:**
```
[FILE CHANGE] PriorityRequestQueue.h
Owner: Member 2
Type: API change
Affects: Member 5 (RequestDispatcher, RequestService)
Description: Added removeRequestById() function for cancellation support
```

### Shared File Proposals
When proposing changes to shared files:

**Format:**
```
[SHARED FILE PROPOSAL] <filename>
Proposer: <member>
Affects: <all dependent members>
Change: <detailed description>
Rationale: <why this change is needed>
Request: Approval from <list members>
```

---

## TESTING OWNERSHIP

| Test Suite | Owner | Must Test |
|------------|-------|-----------|
| Stack unit tests | Member 1 | All Stack operations |
| Queue unit tests | Member 2 | All Queue operations |
| LinkedList unit tests | Member 3 | All LinkedList operations |
| BST unit tests | Member 4 | All BST operations, all deletion cases |
| EscalationService tests | Member 1 | Escalation workflows |
| RequestDispatcher tests | Member 2 | Dispatch logic |
| AgentService tests | Member 3 | Agent management |
| RequestIndexService tests | Member 4 | Index operations |
| RequestService tests | Member 5 | Request lifecycle |
| Coordinator tests | Member 5 | Integration scenarios |
| Sort algorithm tests | Member 6 | Merge Sort correctness |
| Validation tests | Member 6 | Input validation |
| Integration tests | **All Members** | End-to-end scenarios |

---

## VERSION CONTROL BRANCH STRUCTURE

| Member | Feature Branch | Owns Files |
|--------|---------------|-----------|
| Member 1 | feature/stack-escalation | EscalationStack, EscalationService, EscalationEvent |
| Member 2 | feature/priority-queue | PriorityRequestQueue, RequestDispatcher |
| Member 3 | feature/agent-linked-list | AgentLinkedList, AgentService, Agent |
| Member 4 | feature/request-bst | RequestBST, RequestIndexService |
| Member 5 | feature/request-services | RequestService, HelpDeskCoordinator, ServiceRequest |
| Member 6 | feature/app-controller | HelpDeskApp, MenuController, InputValidator, RequestSort, main.cpp |

**Branch Rules:**
- Work on your feature branch
- Commit to your branch freely
- Create Pull Request to `develop` when ready
- Required approvers based on affected files
- Merge only after approval
- Delete feature branch after merge

---

## CONFLICT RESOLUTION

### Issue 1: Two Members Need to Edit Same File

**Solution:**
- Check FILE_OWNERSHIP.md
- Primary owner makes the change
- If legitimate shared need, discuss architecture redesign

### Issue 2: API Not Meeting Needs

**Solution:**
- Consumer explains requirement
- Provider proposes solution
- Update API_CONTRACTS.md
- Implement agreed solution

### Issue 3: Integration Not Working

**Solution:**
- Member 5 identifies interface mismatch
- Calls meeting with affected module owners
- Jointly decide on fix
- Affected owners implement their parts

---

## FINAL RULES

1. **Respect ownership** - Don't modify files you don't own
2. **Communicate changes** - Especially for shared files
3. **Use Pull Requests** - For review and approval
4. **Test your module** - Before pushing
5. **Document your code** - Inline comments
6. **Ask before changing** - APIs and shared models
7. **Integration is shared** - All participate in making modules work together

---

**When in doubt, ask the file owner or Member 5 (integration coordinator).**

**Every file has ONE owner. No exceptions.**
