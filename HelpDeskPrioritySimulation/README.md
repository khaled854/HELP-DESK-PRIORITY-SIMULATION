# CS212 Data Structures Project
## Help-Desk Priority Simulation (Project #89)

**Course:** CS212 - Data Structures  
**Semester:** Fall 2026–2027  
**University:** MISR University for Science & Technology  
**College:** College of Information Technology

---

## Project Overview

This is a **six-member team project** implementing a Help-Desk Priority Simulation system as specified in the official CS212 Course Project Guidelines (Project Idea #89, Page 9).

The system manages help-desk service requests, agent assignments, priority-based dispatching, and escalation tracking using **manually implemented** data structures in C++.

---

## Official Requirements Compliance

This project strictly follows the mandatory technical specification (PDF Pages 2-3, Requirements R1-R10):

### Four Required Data Structures

1. **Stack** - Recent escalations (LIFO)
2. **Queue** - Priority service requests (FIFO with priority levels)
3. **Linked List** - Agent records
4. **Binary Search Tree (BST)** - Request lookup by unique ID

### Additional Requirements

- ✅ C++ implementation with manual data structure code
- ✅ NO use of std::stack, std::queue, std::list, std::map, or ready-made trees
- ✅ Menu-driven console application
- ✅ Insert, delete, search, update, display operations
- ✅ Course searching/sorting algorithm (Merge Sort)
- ✅ Input validation and error handling
- ✅ Empty, boundary, and duplicate ID handling
- ✅ Real integration between structures
- ✅ Big-O complexity analysis
- ✅ Comprehensive testing and documentation

---

## Team Structure

**Six-Member Team with Fair Responsibility Distribution:**

| Member | Primary Responsibility | Main Files Owned |
|--------|----------------------|------------------|
| **Member 1** | Stack & Escalation Module | EscalationStack.h/cpp, EscalationService.h/cpp |
| **Member 2** | Priority Queue & Dispatcher | PriorityRequestQueue.h/cpp, RequestDispatcher.h/cpp |
| **Member 3** | Agent Linked List | AgentLinkedList.h/cpp, AgentService.h/cpp |
| **Member 4** | Request BST & Index | RequestBST.h/cpp, RequestIndexService.h/cpp |
| **Member 5** | Request Services & Integration | RequestService.h/cpp, HelpDeskCoordinator.h/cpp |
| **Member 6** | App Controller, Validation & Algorithms | HelpDeskApp.h/cpp, MenuController.h/cpp, InputValidator.h/cpp, RequestSort.h/cpp, main.cpp |

**See `docs/TEAM_ASSIGNMENT.md` for detailed responsibilities.**

---

## Project Status

🚧 **ARCHITECTURE PHASE COMPLETE**  
📝 **IMPLEMENTATION PHASE READY TO START**

All empty source files, API contracts, documentation, and team assignments are ready. Each team member can now begin implementation of their assigned module.

---

## Directory Structure

```
HelpDeskPrioritySimulation/
├── README.md                    ← You are here
├── CMakeLists.txt              ← Build configuration (to be completed)
├── .gitignore
│
├── docs/                        ← Complete architecture documentation
│   ├── ARCHITECTURE.md
│   ├── PROJECT_SCOPE.md
│   ├── TEAM_ASSIGNMENT.md
│   ├── FILE_OWNERSHIP.md
│   ├── API_CONTRACTS.md
│   ├── NAMING_CONVENTIONS.md
│   ├── INTEGRATION_PLAN.md
│   ├── VALIDATION_RULES.md
│   ├── TESTING_PLAN.md
│   ├── COMPLEXITY_ANALYSIS.md
│   ├── DISCUSSION_PREPARATION.md
│   ├── PROJECT_ROADMAP.md
│   └── REQUIREMENT_TRACEABILITY.md
│
├── src/                         ← All source code (EMPTY - ready for implementation)
│   ├── main.cpp                 ← Application entry point
│   ├── app/                     ← Application controller
│   ├── models/                  ← Shared domain models
│   ├── data_structures/         ← Manual implementations
│   │   ├── stack/
│   │   ├── queue/
│   │   ├── linked_list/
│   │   └── bst/
│   ├── services/                ← Business logic
│   ├── algorithms/              ← Merge Sort
│   └── utils/                   ← Validation & constants
│
├── tests/                       ← Test suites
│   ├── unit/
│   ├── integration/
│   └── test_cases/
│
├── Report/                      ← Final project report
├── Screenshots/                 ← Execution evidence
└── Sample_Data/                 ← Test data
```

---

## How to Build and Run

### Prerequisites

- C++ compiler (g++, clang++, or MSVC)
- C++11 or later standard
- Windows/Linux/macOS command line or IDE

### Compilation (Manual)

```bash
# Navigate to project root
cd HelpDeskPrioritySimulation

# Compile all source files
g++ -std=c++11 -o HelpDeskApp.exe src/main.cpp src/app/*.cpp src/models/*.cpp src/data_structures/*/*.cpp src/services/*.cpp src/algorithms/*.cpp src/utils/*.cpp

# Run the application
./HelpDeskApp.exe
```

### Compilation (CMake - to be configured)

```bash
mkdir build
cd build
cmake ..
make
./HelpDeskApp
```

**Note:** Detailed compilation instructions will be added by Member 6 after implementation.

---

## Quick Start Guide for Team Members

### Step 1: Clone and Setup
```bash
git clone <repository-url>
cd HelpDeskPrioritySimulation
```

### Step 2: Read Documentation
1. **Start with:** `docs/ARCHITECTURE.md`
2. **Read your assignment:** `docs/TEAM_ASSIGNMENT.md`
3. **Check API contracts:** `docs/API_CONTRACTS.md`
4. **Review file ownership:** `docs/FILE_OWNERSHIP.md`

### Step 3: Create Your Feature Branch
```bash
git checkout -b feature/<your-module-name>
# Example: git checkout -b feature/stack-escalation
```

### Step 4: Implement Your Module
- Find your assigned files in `src/`
- Follow API contracts exactly
- Implement your functions
- Handle all edge cases
- Add inline comments

### Step 5: Write Tests
- Create test files in `tests/unit/<your-module>/`
- Test normal, empty, boundary, and invalid cases
- Document test results

### Step 6: Commit and Push
```bash
git add <your-files>
git commit -m "Implement <module-name>: <description>"
git push origin feature/<your-module-name>
```

### Step 7: Create Pull Request
- Request review from integration coordinator (Member 5)
- Address review comments
- Merge after approval

---

## Key Application Features

### Service Request Management
- Create new help-desk requests with unique IDs
- Assign priority levels (HIGH, MEDIUM, LOW)
- Track request status (OPEN, WAITING, ASSIGNED, IN_PROGRESS, RESOLVED, CLOSED)
- Search requests by ID using BST
- Update request information

### Priority-Based Dispatching
- Three independent FIFO queues by priority
- Dispatcher selects next request from highest-priority non-empty queue
- Fair FIFO ordering within same priority level

### Agent Management
- Maintain agent profiles using Linked List
- Track agent availability and specialization
- Assign requests to available agents
- Update agent status

### Escalation Tracking
- Record escalation events in LIFO Stack
- Display recent escalation history
- Track priority changes with reasons

### Reporting and Analytics
- Sort requests using Merge Sort algorithm
- Display statistics by priority and status
- Generate summary reports

---

## Data Structure Roles (Official Compliance)

| Structure | Official Role (PDF Page 9) | Implementation Module | Owner |
|-----------|---------------------------|----------------------|-------|
| **Stack** | Recent escalations | EscalationStack | Member 1 |
| **Queue** | Priority service requests | PriorityRequestQueue | Member 2 |
| **Linked List** | Agent records | AgentLinkedList | Member 3 |
| **BST** | Request lookup by ID | RequestBST | Member 4 |

---

## Testing Requirements

All team members must test their modules. See `docs/TESTING_PLAN.md`.

### Test Categories (PDF Page 11)
- ✅ Normal operation
- ✅ Empty structure
- ✅ Boundary and single item
- ✅ Invalid data
- ✅ Integration across structures
- ✅ Algorithm and complexity verification

---

## Documentation Requirements

### Project Report (10 Sections - PDF Page 10)
1. Cover Page
2. Problem Definition
3. Project Objectives
4. Data Structures Used
5. System Features
6. Implementation Explanation
7. Testing
8. Complexity Analysis
9. Team Contributions
10. Conclusion

**Report template available in `Report/REPORT_OUTLINE.md`**

---

## Submission Instructions (PDF Pages 3-4)

### Team Submission
1. Upload complete project to **GitHub** or **OneDrive**
2. Verify shared link opens without access requests
3. Include: source code, report (PDF/DOCX), README, screenshots, test evidence

### Individual Submission (EVERY STUDENT)
Each of the 6 members must:
1. Create individual `.txt` file with:
   - Your full name
   - Your university ID
   - Team title/number
   - Project URL (same link for all members)
2. Upload YOUR OWN `.txt` file to eLearning CS212 assignment
3. Verify submission before deadline

**Template available in official PDF Page 4.**

---

## Live Demonstration Preparation

All team members must be ready to:
- ✅ Compile and run the project
- ✅ Demonstrate all four data structures
- ✅ Explain Stack operations (push, pop, peek, LIFO)
- ✅ Explain Queue operations (enqueue, dequeue, front, FIFO)
- ✅ Explain Linked List operations (insert, delete, search, traversal)
- ✅ Explain BST operations (insert, delete, search, traversals, deletion cases)
- ✅ Explain Merge Sort algorithm and complexity
- ✅ Show integration and synchronization
- ✅ Handle instructor questions about any module

**See `docs/DISCUSSION_PREPARATION.md` for 30+ practice questions.**

---

## Assessment Rubric (30 Marks Total - PDF Page 11)

| Component | Marks |
|-----------|-------|
| Problem Definition & Objectives | 4 |
| Data Structure Selection & Justification | 10 |
| Data Structures Implementation | 5 |
| Integration & Functional Requirements | 3 |
| Code Quality & Error Handling | 3 |
| Project Documentation | 5 |
| **Total** | **30** |

Individual marks may vary based on contribution and discussion performance.

---

## Important Rules

### Academic Integrity
- All code must be team's original work
- Acknowledge any external resources or AI assistance
- Every member must understand and explain all submitted code

### No Cross-Section Teams
- All 6 members MUST be registered in the SAME CS212 practical section
- Cross-section teams are strictly prohibited

### Manual Implementation Required
- Do NOT use: `std::stack`, `std::queue`, `std::list`, `std::map`
- Do NOT use ready-made tree libraries
- Implement all assessed structures manually

---

## Getting Help

### Internal Resources
1. Check `docs/` directory first
2. Review API contracts and architecture
3. Ask your module dependencies (see FILE_OWNERSHIP.md)
4. Contact integration coordinator (Member 5)

### External Resources
- Official PDF: CS212 Course Project Guidelines
- Course eLearning page
- Instructor office hours
- Team meetings

---

## Project Milestones

See `docs/PROJECT_ROADMAP.md` for detailed timeline.

1. ✅ Architecture Phase (COMPLETE)
2. 🔄 Implementation Phase (READY TO START)
3. ⏳ Integration Phase
4. ⏳ Testing Phase
5. ⏳ Documentation Phase
6. ⏳ Submission & Demonstration

---

## Contact and Collaboration

### Team Communication
- GitHub Issues for bugs and tasks
- Pull Requests for code review
- Regular team meetings (schedule TBD)

### Version Control
- Main branch: stable releases only
- Develop branch: integration
- Feature branches: individual work
- See `docs/GITHUB_WORKFLOW.md`

---

## License and Acknowledgments

**Academic Project - MISR University**  
CS212 Data Structures - Fall 2026-2027

This project fulfills the requirements specified in the official CS212 Course Project Guidelines document.

---

**Last Updated:** November 9, 2026  
**Project Status:** Architecture Complete - Implementation Ready  
**Next Steps:** Each member begins implementing their assigned module

For questions, refer to documentation in `docs/` or contact team coordinator.
