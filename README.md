# Help Desk Priority Simulation
## CS212 - Data Structures Project

**Project ID:** 89  
**Team Members:** 6 students  
**Semester:** Fall 2026-2027

---

## Team Members

1. **عمر محمد** - Team Member 1
2. **خالد طه** - Team Member 2  
3. **نور محمد** - Team Member 3
4. **هبه رجب** - Team Member 4
5. **مريم علاء** - Team Member 5
6. **نور وائل** - Team Member 6

---

## Project Description

Help-Desk Priority Simulation system that manages IT support tickets using multiple data structures:

- **Stack**: Recent escalations (LIFO)
- **Queue**: Priority service requests (FIFO by urgency)
- **Linked List**: Agent records
- **BST**: Request lookup by ID

---

## Project Structure

```
HELP-DESK-PRIORITY-SIMULATION/
├── README.md
├── Source_Code/
│   ├── main.cpp
│   ├── Stack.h
│   ├── Stack.cpp
│   ├── Queue.h
│   ├── Queue.cpp
│   ├── LinkedList.h
│   ├── LinkedList.cpp
│   ├── BST.h
│   ├── BST.cpp
│   ├── HelpDesk.h
│   └── HelpDesk.cpp
├── Report/
│   └── project_report.pdf
├── Screenshots/
└── Tests/
    └── test_cases.txt
```

---

## How to Compile and Run

### Windows (MinGW/g++)
```bash
cd Source_Code
g++ -o HelpDesk main.cpp Stack.cpp Queue.cpp LinkedList.cpp BST.cpp HelpDesk.cpp
HelpDesk.exe
```

### Linux/Mac
```bash
cd Source_Code
g++ -o HelpDesk main.cpp Stack.cpp Queue.cpp LinkedList.cpp BST.cpp HelpDesk.cpp
./HelpDesk
```

---

## Task Distribution (Fair & Balanced)

> 📖 **للتفاصيل الكاملة، اقرأ:** `BALANCED_DISTRIBUTION.md`

**كل عضو: 15-16 functions من structures مختلفة - متوازن 100%!**

### عمر محمد (Member 1) - 15 functions
- **Stack Part 1:** 5 functions (Constructor, push, pop, peek, isEmpty)
- **Queue Part 1:** 5 functions (Constructor, enqueue, front, isEmpty, size)
- **Integration:** 5 functions (createRequest, escalateRequest, views, menu)
- **Time:** 12-14 hours | **Difficulty:** ⭐⭐⭐

### خالد طه (Member 2) - 15 functions
- **Stack Part 2:** 5 functions (Destructor, isFull, size, display, clear)
- **Queue Part 2:** 6 functions (Destructor, dequeue, isFull, display, clear, getHighestPriority)
- **Integration:** 4 functions (processNext, resolve, processEscalation, menu)
- **Time:** 13-15 hours | **Difficulty:** ⭐⭐⭐

### نور محمد (Member 3) - 16 functions
- **LinkedList Part 1:** 7 functions (Constructor, insert, search, display, isEmpty, getCount, assignRequest)
- **BST Part 1:** 7 functions (Constructor, insert/Helper, search/Helper, isEmpty, getCount)
- **Integration:** 2 functions (addAgent, searchRequestById)
- **Time:** 13-15 hours | **Difficulty:** ⭐⭐⭐

### هبه رجب (Member 4) - 16 functions
- **LinkedList Part 2:** 7 functions (Destructor, delete, update, unassign, setAvailability, findAvailable, clear)
- **BST Part 2:** 7 functions (delete/Helper, findMin/MinNode, inorder/Helper, preorder/Helper)
- **Integration:** 2 functions (removeAgent, viewAllRequests)
- **Time:** 14-16 hours | **Difficulty:** ⭐⭐⭐⭐

### مريم علاء (Member 5) - 15 functions
- **BST Part 3:** 7 functions (Destructor, findMax, updateStatus, updateResolvedTime, clear/Helper)
- **Algorithms:** 2 functions (sortByPriority, linearSearchAgent)
- **Integration:** 6 functions (viewRequest, viewAgents, statistics, assign, getTimestamp, getNextId)
- **Time:** 14-16 hours | **Difficulty:** ⭐⭐⭐⭐

### نور وائل (Member 6) - 16 functions
- **UI:** 6 functions (main, displayMenu, 4 handler submenus)
- **Testing:** 1 comprehensive function (runTests with 8 test suites)
- **Validation:** 2 functions (getValidatedInt, getValidatedString)
- **Integration:** 7 view functions (distributed across all structures)
- **Time:** 13-15 hours | **Difficulty:** ⭐⭐⭐

**Average:** 15.5 functions, 13-15 hours per member | **Difference:** ±4h max

---

## Required Features

1. ✅ Stack for escalations
2. ✅ Queue for priority requests
3. ✅ Linked List for agents
4. ✅ BST for request lookup
5. ✅ Searching/Sorting algorithm
6. ✅ Menu-driven interface
7. ✅ Input validation
8. ✅ Error handling

---

## Git Workflow

1. Clone the repository:
```bash
git clone https://github.com/khaled854/HELP-DESK-PRIORITY-SIMULATION.git
```

2. Create your branch:
```bash
git checkout -b your-name
```

3. Make changes to your assigned files only

4. Commit and push:
```bash
git add .
git commit -m "Description of changes"
git push origin your-name
```

5. Create Pull Request on GitHub

---

## Important Notes

- Do NOT modify files assigned to other team members
- Test your code before committing
- Follow C++ coding standards
- Add comments to explain your code
- Update this README if needed

---

## Project Deadline

As announced on eLearning

---

## License

Academic Project - MISR University for Science & Technology
