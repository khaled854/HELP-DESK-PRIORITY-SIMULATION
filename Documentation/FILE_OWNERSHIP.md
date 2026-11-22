# 📂 FILE OWNERSHIP & RESPONSIBILITIES
## CS212 - Help Desk Priority Simulation

**Document Version**: 1.0  
**Last Updated**: November 22, 2026  
**Purpose**: Define clear file ownership to prevent Git conflicts

---

## ⚠️ CRITICAL RULE

**ONE FILE = ONE PRIMARY OWNER**

Even if multiple people contribute functions to a file, **only ONE person** should have commit rights at any given time.

---

## 1. SOURCE CODE FILE OWNERSHIP

### 1.1 Header Files (.h) - **READ-ONLY FOR ALL**

| File | Primary Owner | Status | Notes |
|------|---------------|--------|-------|
| Stack.h | **Omar Mohamed** | ✅ FROZEN | No modifications allowed after Week 1 |
| Queue.h | **Khaled Taha** | ✅ FROZEN | No modifications allowed after Week 1 |
| LinkedList.h | **Nour Mohamed** | ✅ FROZEN | No modifications allowed after Week 1 |
| BST.h | **Heba Ragab** | ✅ FROZEN | No modifications allowed after Week 1 |
| HelpDesk.h | **Mariam Alaa** | ✅ FROZEN | No modifications allowed after Week 1 |

**Rule**: Headers are defined by PRIMARY owners in Week 1, then **LOCKED**. No changes without team agreement.

---

### 1.2 Implementation Files (.cpp) - **SEQUENTIAL OWNERSHIP**

#### Stack.cpp

| Phase | Active Owner | Functions | Duration | Handoff |
|-------|--------------|-----------|----------|---------|
| **Phase 1** | **Omar Mohamed** | 1-5 (Constructor, push, pop, peek, isEmpty) | Days 1-2 | Commit + Push + Notify Khaled |
| **Phase 2** | **Khaled Taha** | 6-10 (Destructor, isFull, size, display, clear) | Days 2-3 | Commit + Push |

**Dependencies**: Khaled MUST wait for Omar's commit.

**Section Markers**: ✅ Already added (SECTION 1, SECTION 2)

---

#### Queue.cpp

| Phase | Active Owner | Functions | Duration | Handoff |
|-------|--------------|-----------|----------|---------|
| **Phase 1** | **Omar Mohamed** | 1-5 (Constructor, enqueue, front, isEmpty, size) | Days 2-3 | Commit + Push + Notify Khaled |
| **Phase 2** | **Khaled Taha** | 6-11 (Destructor, dequeue, isFull, display, clear, getHighestPriority) | Days 3-5 | Commit + Push |

**Dependencies**: Khaled MUST wait for Omar's commit.

**Section Markers**: ⚠️ Partially added - needs completion

---

#### LinkedList.cpp

| Phase | Active Owner | Functions | Duration | Handoff |
|-------|--------------|-----------|----------|---------|
| **Phase 1** | **Nour Mohamed** | 1-7 (Constructor, insert, search, display, isEmpty, getCount, assignRequest) | Days 3-5 | Commit + Push + Notify Heba |
| **Phase 2** | **Heba Ragab** | 8-14 (Destructor, delete, update, unassign, setAvailability, findAvailable, clear) | Days 5-7 | Commit + Push |

**Dependencies**: Heba MUST wait for Nour's commit.

**Section Markers**: ⚠️ Partially added - needs completion

---

#### BST.cpp

| Phase | Active Owner | Functions | Duration | Handoff |
|-------|--------------|-----------|----------|---------|
| **Phase 1** | **Nour Mohamed** | 1-7 (Constructor, insert, insertHelper, search, searchHelper, isEmpty, getCount) | Days 5-7 | Commit + Push + Notify Heba |
| **Phase 2** | **Heba Ragab** | 8-14 (Destructor, delete, deleteHelper, findMinNode, findMin, findMax, clear) | Days 7-9 | Commit + Push + Notify Mariam |
| **Phase 3** | **Mariam Alaa** | 15-21 (inorder, inorderHelper, preorder, preorderHelper, updateStatus, updateResolvedTime, clearHelper) | Days 9-10 | Commit + Push |

**Dependencies**: 
- Heba waits for Nour
- Mariam waits for Heba

**Section Markers**: ⚠️ Partially added - needs completion

---

#### HelpDesk.cpp - **MOST COMPLEX COORDINATION**

| Phase | Active Owner | Functions | Duration | Handoff |
|-------|--------------|-----------|----------|---------|
| **Phase 1** | **Mariam Alaa** | Constructor, Destructor, getTimestamp, getNextRequestId | Day 8 | Commit + Push + Notify Omar |
| **Phase 2** | **Omar Mohamed** | createRequest, escalateRequest, viewEscalations, viewPendingRequests | Day 9 | Commit + Push + Notify Khaled |
| **Phase 3** | **Khaled Taha** | processNextRequest, resolveRequest, processEscalation | Day 10 | Commit + Push + Notify Nour |
| **Phase 4** | **Nour Mohamed** | addAgent, searchRequestById | Day 11 | Commit + Push + Notify Heba |
| **Phase 5** | **Heba Ragab** | removeAgent, assignAgentToRequest | Day 12 | Commit + Push + Notify Mariam |
| **Phase 6** | **Mariam Alaa** | displayStatistics, sortRequestsByPriority, linearSearchAgent | Day 13 | Commit + Push + Notify Nour W |
| **Phase 7** | **Nour Wael** | viewRequest, viewAllRequests, viewAllAgents | Day 14 | Commit + Push |

**Dependencies**: **STRICT SEQUENTIAL** - each person waits for previous commit.

**Section Markers**: ❌ **NOT ADDED - HIGH PRIORITY**

**Coordinator**: **Mariam Alaa** owns this file and resolves any conflicts.

---

#### main.cpp

| Phase | Active Owner | Functions | Duration | Handoff |
|-------|--------------|-----------|----------|---------|
| **Phase 1** | **Nour Wael** | main, displayMainMenu, validation functions, runTests, clearInputBuffer, handleViewOperations, handleAgentManagement | Days 6-8 | Commit + Push + Notify Omar |
| **Phase 2** | **Omar Mohamed** | handleRequestManagement | Day 9 | Commit + Push + Notify Khaled |
| **Phase 3** | **Khaled Taha** | handleSearchOperations | Day 10 | Commit + Push |

**Dependencies**:
- Omar waits for Nour W
- Khaled waits for Omar

**Section Markers**: ❌ **NOT ADDED - HIGH PRIORITY**

**Primary Owner**: **Nour Wael** (owns file, coordinates additions)

---

## 2. DOCUMENTATION FILE OWNERSHIP

| File | Owner | Can Others Edit? |
|------|-------|------------------|
| README.md | **Mariam Alaa** | Via Pull Request only |
| BALANCED_DISTRIBUTION.md | **Mariam Alaa** | ❌ NO - Reference document |
| WORK_SEQUENCE_GUIDE.md | **Mariam Alaa** | Via Pull Request only |
| GIT_INSTRUCTIONS.md | **Khaled Taha** | Via Pull Request only |
| QUICK_START_GUIDE.md | **Nour Wael** | Via Pull Request only |
| START_HERE.md | **Nour Wael** | Via Pull Request only |
| FILE_OWNERSHIP.md (this file) | **Mariam Alaa** | Via Pull Request only |
| INTERFACE_CONTRACT.md | **Mariam Alaa** | ❌ NO - Frozen after Week 1 |
| PROJECT_AUDIT.md | **Architect** | ❌ READ-ONLY |

---

## 3. TESTING & REPORT OWNERSHIP

| File | Owner | Collaborators |
|------|-------|---------------|
| Tests/test_cases.txt | **Nour Wael** | All review |
| Report/REPORT_TEMPLATE.md | **ALL** | Each writes their section |

**Report Section Ownership**:
1. Introduction - **Mariam Alaa**
2. Stack - **Omar Mohamed** + **Khaled Taha**
3. Queue - **Omar Mohamed** + **Khaled Taha**
4. LinkedList - **Nour Mohamed** + **Heba Ragab**
5. BST - **Nour Mohamed** + **Heba Ragab** + **Mariam Alaa**
6. Integration - **Mariam Alaa**
7. Algorithms - **Mariam Alaa**
8. Testing - **Nour Wael**
9. Screenshots - **Nour Wael** (collects from all)
10. Conclusion - **Mariam Alaa**

---

## 4. GIT WORKFLOW

### 4.1 Branch Structure

```
main (protected)
├── omar-dev
├── khaled-dev
├── nour-dev
├── heba-dev
├── mariam-dev
└── nourw-dev
```

**Rules**:
- ❌ **NO direct commits to main**
- ✅ All work on personal branches
- ✅ Pull Requests for merging
- ✅ At least 1 review required (Mariam or Nour W)

### 4.2 Commit Workflow

**When finishing your assigned functions**:

```bash
# 1. Ensure you're on your branch
git checkout your-name-dev

# 2. Add only YOUR file
git add Source_Code/YourFile.cpp

# 3. Commit with clear message
git commit -m "Implemented [FunctionNames] in [File] - [YourName]"

# 4. Push to YOUR branch
git push origin your-name-dev

# 5. Create Pull Request on GitHub

# 6. Notify next person in sequence (if applicable)
# Send message: "I've committed [File], you can start now"
```

### 4.3 Pull Request Process

**Creator**:
1. Create PR from your-branch → main
2. Add description of what you implemented
3. Tag reviewer (Mariam or Nour W)
4. Wait for approval

**Reviewer**:
1. Check code compiles
2. Verify functions match specification
3. Check for obvious bugs
4. Approve or Request Changes

**Merger**:
- Only **Mariam** or **Nour W** can merge to main

---

## 5. CONFLICT RESOLUTION PROTOCOL

### If Git Conflict Occurs:

**Step 1**: **DON'T PANIC**

**Step 2**: Identify who has conflicting changes
```bash
git status
```

**Step 3**: Contact **Mariam** (Integration Lead)

**Step 4**: Mariam coordinates resolution:
- Determines whose code takes precedence
- Helps merge conflicting sections
- Tests merged code
- Approves final version

**Step 5**: Re-test before committing

### If Someone Breaks Main Branch:

**Emergency Contact**: **Mariam Alaa**

**Actions**:
1. Revert to last working commit
2. Identify breaking change
3. Fix on separate branch
4. Re-test thoroughly
5. Merge fix with extra review

---

## 6. HANDOFF CHECKLIST

### When Finishing Your Work:

- [ ] All YOUR functions implemented
- [ ] Code compiles without errors
- [ ] YOUR functions tested individually
- [ ] Comments added
- [ ] TODOs removed from YOUR section
- [ ] Git commit with clear message
- [ ] Git push to YOUR branch
- [ ] Pull Request created
- [ ] Next person notified (if sequential file)

### When Receiving Handoff:

- [ ] Previous person confirmed commit
- [ ] Pull Request merged (or pull their branch)
- [ ] `git pull` to get latest changes
- [ ] Verify their code compiles
- [ ] Read their functions (understand interface)
- [ ] Start YOUR section
- [ ] **DO NOT modify their section** without asking

---

## 7. OWNERSHIP VIOLATIONS

### ❌ **FORBIDDEN ACTIONS**:

1. **Editing someone else's assigned functions**
   - Exception: Bug fix with their permission

2. **Committing to main branch directly**
   - Exception: NEVER

3. **Modifying header files after Week 1**
   - Exception: Team agreement + Mariam approval

4. **Working on a file before receiving handoff**
   - Exception: NEVER

5. **Force pushing**
   - Exception: NEVER

### ✅ **ALLOWED ACTIONS**:

1. **Reading any file** (for understanding)
2. **Suggesting improvements** (via comments/discussion)
3. **Helping debug** (with owner's knowledge)
4. **Writing YOUR assigned functions**
5. **Testing others' functions** (report bugs, don't fix)

---

## 8. EMERGENCY CONTACTS

| Role | Name | Responsibility |
|------|------|----------------|
| **Integration Lead** | **Mariam Alaa** | Resolves conflicts, coordinates HelpDesk.cpp |
| **Testing Lead** | **Nour Wael** | Verifies all tests pass, coordinates main.cpp |
| **Git Expert** | **Khaled Taha** | Helps with Git issues |
| **Documentation Lead** | **Mariam Alaa** | Maintains consistency |

**Group Communication**: WhatsApp/Telegram group (check daily)

---

## 9. TIMELINE OVERVIEW

### Week 1: Individual Structures (Days 1-7)
- **Days 1-2**: Stack (Omar → Khaled)
- **Days 2-5**: Queue (Omar → Khaled)
- **Days 3-7**: LinkedList (Nour → Heba)
- **Days 5-10**: BST (Nour → Heba → Mariam)
- **Days 6-8**: main.cpp skeleton (Nour W)

### Week 2: Integration (Days 8-14)
- **Day 8**: HelpDesk base (Mariam)
- **Days 9-14**: HelpDesk functions (Sequential: Omar → Khaled → Nour → Heba → Mariam → Nour W)
- **Days 9-10**: main.cpp additions (Omar, Khaled)

### Week 3: Testing & Algorithms (Days 15-21)
- **Days 15-17**: Algorithms (Mariam)
- **Days 18-21**: Testing (Nour W leads, all participate)

### Week 4: Report & Final (Days 22-28)
- **Days 22-24**: Report writing (all write their sections)
- **Days 25-28**: Review, screenshots, submission prep

---

## 10. SUCCESS METRICS

**Project succeeds if**:
- ✅ **ZERO unresolved Git conflicts**
- ✅ All functions implemented by assigned owners
- ✅ All handoffs completed on time
- ✅ Code compiles without errors
- ✅ All tests pass
- ✅ Report completed

**Ownership system succeeds if**:
- ✅ No ownership disputes
- ✅ No accidental overwrites
- ✅ Clear responsibility for each bug
- ✅ Smooth handoffs
- ✅ Team collaboration is positive

---

## DOCUMENT APPROVAL

**Created By**: Senior Software Architect  
**Approved By**: Project Team (pending)  
**Status**: **DRAFT** - Needs team review and agreement  
**Version**: 1.0  
**Date**: November 22, 2026

---

**ALL TEAM MEMBERS MUST READ AND AGREE TO THIS DOCUMENT BEFORE CODING BEGINS.**

