# Help Desk Priority Simulation
## CS212 - Data Structures Project

**Project ID:** 89  
**Team Members:** 6 students  
**Semester:** Fall 2026-2027  
**Status:** ✅ **SKELETON COMPLETE - READY FOR IMPLEMENTATION**

---

## 🚀 PROJECT STATUS

**✅ Skeleton Status**: Complete and compiles successfully  
**✅ Distribution**: Fair and balanced across all 6 members  
**✅ Testing**: Shared by ALL members (no one overloaded)  
**📋 Implementation**: Empty function bodies with TODO placeholders  
**🎯 Next Step**: Team members begin implementing their assigned functions

---

## Team Members

1. **عمر محمد (Omar Mohamed)** - Team Member 1
2. **خالد طه (Khaled Taha)** - Team Member 2  
3. **نور محمد (Nour Mohamed)** - Team Member 3
4. **هبه رجب (Heba Ragab)** - Team Member 4
5. **مريم علاء (Mariam Alaa)** - Team Member 5
6. **نور وائل (Nour Wael)** - Team Member 6

---

## Project Description

Help-Desk Priority Simulation system that manages IT support tickets using multiple data structures:

- **Stack**: Recent escalations (LIFO)
- **Queue**: Priority service requests (FIFO by urgency)
- **Linked List**: Agent records
- **BST**: Request lookup by ID

---

## 📂 Project Structure

```
HELP-DESK-PRIORITY-SIMULATION/
├── README.md
├── Source_Code/
│   ├── main.cpp                (Menu + UI + Validation)
│   ├── Stack.h / Stack.cpp     (Escalation stack)
│   ├── Queue.h / Queue.cpp     (Priority queue)
│   ├── LinkedList.h / LinkedList.cpp  (Agent management)
│   ├── BST.h / BST.cpp         (Request lookup tree)
│   └── HelpDesk.h / HelpDesk.cpp      (Integration layer)
├── Documentation/
│   ├── START_HERE.md           (👈 READ THIS FIRST!)
│   ├── NEW_FAIR_DISTRIBUTION.md (Complete task allocation)
│   ├── FUNCTION_OWNERSHIP_TABLE.md (Detailed function ownership)
│   ├── PROJECT_AUDIT.md
│   └── INTERFACE_CONTRACT.md
├── Report/
│   └── REPORT_TEMPLATE.md
├── Screenshots/
└── Tests/
    └── test_cases.txt
```

---

## 🎯 Fair Task Distribution (NEW)

**Total Functions**: 87 functions  
**Average per member**: 14.5 functions  
**Time per member**: 14-19 hours (perfectly balanced)

### Quick Overview

| Member | Functions | Difficulty | Total Hours |
|--------|-----------|------------|-------------|
| **Omar Mohamed** | 14 | ⭐⭐⭐ Medium | 13-16h |
| **Khaled Taha** | 14 | ⭐⭐⭐ Medium | 14-17h |
| **Nour Mohamed** | 15 | ⭐⭐⭐ Medium | 14-17h |
| **Heba Ragab** | 15 | ⭐⭐⭐⭐ Hard | 15-18h |
| **Mariam Alaa** | 13 | ⭐⭐⭐⭐ Hard | 15-18h |
| **Nour Wael** | 16 | ⭐⭐⭐⭐ Med-Hard | 15-18h |

**📖 For complete details, see:** `Documentation/NEW_FAIR_DISTRIBUTION.md`

---

## 🆕 MAJOR CHANGE: Nour Wael Gets Meaningful Work!

**Previous (UNFAIR)**: Nour Wael was assigned ONLY testing (23-25h total)

**NEW (FAIR)**: Nour Wael now implements:
- ✅ 7 BST functions (traversals, updates, recursive algorithms)
- ✅ 6 main.cpp functions (UI + validation)
- ✅ 3 HelpDesk view functions
- ✅ Total: 16 functions + shared testing = **15-18h** (balanced!)

**Testing is now SHARED by ALL 6 members** - no one overloaded!

---

## How to Compile and Run

### Windows (MinGW/g++)
```bash
cd Source_Code
g++ -std=c++11 -o HelpDesk main.cpp Stack.cpp Queue.cpp LinkedList.cpp BST.cpp HelpDesk.cpp
HelpDesk.exe
```

### Linux/Mac
```bash
cd Source_Code
g++ -std=c++11 -o HelpDesk main.cpp Stack.cpp Queue.cpp LinkedList.cpp BST.cpp HelpDesk.cpp
./HelpDesk
```

**Note**: Currently, all functions have empty bodies (skeleton only). Executable will run but functions need implementation.

---

## Required Features

1. ✅ Stack for escalations (10 functions)
2. ✅ Queue for priority requests (11 functions)
3. ✅ Linked List for agents (14 functions)
4. ✅ BST for request lookup (21 functions - 8 private + 13 public)
5. ✅ HelpDesk integration (21 functions)
6. ✅ Menu system (10 functions in main.cpp)
7. ✅ Searching/Sorting algorithm (Mariam)
8. ✅ Input validation (Nour Wael)
9. ✅ Error handling (All members)

**All PDF requirements (R1-R10) are covered!**

---

## 📋 Implementation Status

### ✅ Complete (Skeleton):
- All header files (.h)
- All class declarations
- All function signatures
- All data structures defined
- Compiles successfully

### 🔨 To Be Implemented:
- Function bodies (each member implements their assigned functions)
- Algorithms (sorting + searching)
- Testing (shared by all 6 members)

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

3. **IMPORTANT**: Only edit your assigned functions (see FUNCTION_OWNERSHIP_TABLE.md)

4. Commit and push:
```bash
git add .
git commit -m "Implemented [your functions]"
git push origin your-name
```

5. Create Pull Request on GitHub

---

## Important Notes

- ✅ **Skeleton is complete** - all functions declared
- 🔨 **Function bodies are empty** - marked with TODO placeholders
- 📖 **Read Documentation/START_HERE.md** before coding
- 👥 **Testing is SHARED** - everyone implements AND tests
- ⚠️ **Do NOT modify** files assigned to other members
- 📝 **Follow** the FUNCTION_OWNERSHIP_TABLE.md
- ✅ **Compile before committing** to verify no errors

---

## Project Deadline

As announced on eLearning

---

## Documentation

**Start Here**:
1. Read `Documentation/START_HERE.md` (project overview)
2. Read `Documentation/NEW_FAIR_DISTRIBUTION.md` (your assignments)
3. Read `Documentation/FUNCTION_OWNERSHIP_TABLE.md` (detailed function list)
4. Read `Documentation/INTERFACE_CONTRACT.md` (function signatures)
5. Begin implementing YOUR assigned functions

**All documentation updated with new fair distribution!**

---

## License

Academic Project - MISR University for Science & Technology

---

## Contact

For questions about task distribution or collaboration:
- Check Documentation/ folder first
- Contact team coordinator (Mariam Alaa for integration questions)
- Use GitHub Issues for bugs

**Ready to code! 💪**
