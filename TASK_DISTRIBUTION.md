# توزيع المهام - Help Desk Priority Simulation

## معلومات المشروع
- **رقم المشروع**: 89
- **اسم المشروع**: Help-Desk Priority Simulation
- **المادة**: CS212 - Data Structures
- **الفصل الدراسي**: Fall 2026-2027
- **عدد الأعضاء**: 6

---

## توزيع الملفات والمسؤوليات (التوزيع العادل)

> **ملحوظة مهمة**: التوزيع الجديد يضمن أن كل عضو يأخذ نفس الكمية والصعوبة تقريباً

### استراتيجية التوزيع الجديدة:
- كل عضو يأخذ **جزء من كل data structure**
- التقسيم بحسب **الوظائف** مش الملفات
- كل واحد عنده **نفس العدد** من الـ functions تقريباً (8-10 functions)
- كل واحد عنده **mix** من السهل والصعب

---

## 📊 التوزيع الجديد

### 👤 Member 1: عمر محمد

**المسؤوليات:**
- **Stack**: Basic operations (4 functions)
- **Queue**: Basic operations (4 functions)
- **Testing**: Stack & Queue tests

**الوظائف المطلوبة (8 functions):**

#### من Stack.cpp:
1. `Stack()` - Constructor (Easy)
2. `push()` - إضافة escalation (Easy)
3. `peek()` - عرض القمة (Easy)
4. `isEmpty()` - فحص فارغ (Easy)

#### من Queue.cpp:
5. `Queue()` - Constructor (Easy)
6. `enqueue()` - إضافة request (Medium)
7. `front()` - عرض الأول (Easy)
8. `isEmpty()` - فحص فارغ (Easy)

**الصعوبة**: ⭐⭐ (Easy-Medium)  
**الوقت المتوقع**: 10-12 ساعة

---

### 👤 Member 2: خالد طه

**المسؤوليات:**
- **Stack**: Advanced operations (4 functions)
- **Queue**: Advanced operations (4 functions)
- **Testing**: Stack & Queue edge cases

**الوظائف المطلوبة (8 functions):**

#### من Stack.cpp:
1. `~Stack()` - Destructor (Easy)
2. `pop()` - إزالة من القمة (Medium)
3. `isFull()` - فحص ممتلئ (Easy)
4. `size()` - عدد العناصر (Easy)

#### من Queue.cpp:
5. `~Queue()` - Destructor (Easy)
6. `dequeue()` - إزالة بأولوية (Hard - أصعب function)
7. `isFull()` - فحص ممتلئ (Easy)
8. `size()` - عدد العناصر (Easy)

**الصعوبة**: ⭐⭐⭐ (Medium)  
**الوقت المتوقع**: 10-12 ساعة

---

### 👤 Member 3: نور محمد

**المسؤوليات:**
- **Stack**: Display & Clear (2 functions)
- **Queue**: Display, Clear & Priority (3 functions)
- **LinkedList**: Basic operations (4 functions)

**الوظائف المطلوبة (9 functions):**

#### من Stack.cpp:
1. `display()` - عرض الكل (Medium)
2. `clear()` - مسح الكل (Easy)

#### من Queue.cpp:
3. `display()` - عرض الكل (Medium)
4. `clear()` - مسح الكل (Easy)
5. `getHighestPriority()` - إيجاد أعلى أولوية (Medium)

#### من LinkedList.cpp:
6. `LinkedList()` - Constructor (Easy)
7. `insertAgent()` - إضافة موظف (Medium)
8. `searchAgent()` - بحث (Medium)
9. `isEmpty()` - فحص فارغ (Easy)

**الصعوبة**: ⭐⭐⭐ (Medium)  
**الوقت المتوقع**: 11-13 ساعة

---

### 👤 Member 4: هبه رجب

**المسؤوليات:**
- **LinkedList**: Advanced operations (5 functions)
- **BST**: Basic operations (4 functions)

**الوظائف المطلوبة (9 functions):**

#### من LinkedList.cpp:
1. `~LinkedList()` - Destructor (Hard - memory management)
2. `deleteAgent()` - حذف موظف (Hard)
3. `displayAgents()` - عرض الكل (Medium)
4. `getCount()` - عدد العناصر (Easy)
5. `clear()` - مسح الكل (Medium)

#### من BST.cpp:
6. `BST()` - Constructor (Easy)
7. `insert()` + `insertHelper()` - إضافة (Medium-Hard)
8. `search()` + `searchHelper()` - بحث (Medium)
9. `isEmpty()` - فحص فارغ (Easy)

**الصعوبة**: ⭐⭐⭐ (Medium-Hard)  
**الوقت المتوقع**: 12-14 ساعة

---

### 👤 Member 5: مريم علاء

**المسؤوليات:**
- **LinkedList**: Update & Agent management (5 functions)
- **BST**: Delete operations (3 functions)
- **Integration**: Helper functions (2 functions)

**الوظائف المطلوبة (10 functions):**

#### من LinkedList.cpp:
1. `updateAgent()` - تحديث (Medium)
2. `assignRequest()` - تخصيص طلب (Medium)
3. `unassignRequest()` - إلغاء تخصيص (Medium)
4. `setAvailability()` - تغيير الحالة (Easy)
5. `findAvailableAgent()` - إيجاد متاح (Medium)

#### من BST.cpp:
6. `~BST()` - Destructor (Medium)
7. `deleteRequest()` + `deleteHelper()` - حذف (Hard - 3 cases)
8. `findMinNode()` - إيجاد الأصغر (Medium)

#### من HelpDesk.cpp:
9. `getCurrentTimestamp()` - وقت (Easy)
10. `getNextRequestId()` - ID جديد (Easy)

**الصعوبة**: ⭐⭐⭐ (Medium-Hard)  
**الوقت المتوقع**: 12-14 ساعة

---

### 👤 Member 6: نور وائل

**المسؤوليات:**
- **BST**: Traversal & Updates (6 functions)
- **Main Menu**: Interface & Validation (4 functions)

**الوظائف المطلوبة (10 functions):**

#### من BST.cpp:
1. `inorderTraversal()` + `inorderHelper()` - عرض مرتب (Medium)
2. `preorderTraversal()` + `preorderHelper()` - عرض preorder (Medium)
3. `findMin()` - أصغر عنصر (Easy)
4. `findMax()` - أكبر عنصر (Easy)
5. `getCount()` - عدد العناصر (Easy)
6. `updateStatus()` - تحديث حالة (Medium)
7. `updateResolvedTime()` - تحديث وقت (Easy)
8. `clear()` + `clearHelper()` - مسح الكل (Medium)

#### من main.cpp:
9. `getValidatedIntInput()` - validation (Medium)
10. `getValidatedStringInput()` - validation (Medium)

**الصعوبة**: ⭐⭐⭐ (Medium)  
**الوقت المتوقع**: 11-13 ساعة

---

## 📊 جدول المقارنة (التوزيع الجديد)

| العضو | عدد Functions | Easy | Medium | Hard | الوقت المتوقع |
|------|--------------|------|--------|------|---------------|
| عمر محمد | 8 | 6 | 2 | 0 | 10-12 ساعة |
| خالد طه | 8 | 5 | 2 | 1 | 10-12 ساعة |
| نور محمد | 9 | 3 | 5 | 0 | 11-13 ساعة |
| هبه رجب | 9 | 2 | 4 | 2 | 12-14 ساعة |
| مريم علاء | 10 | 3 | 5 | 1 | 12-14 ساعة |
| نور وائل | 10 | 5 | 4 | 0 | 11-13 ساعة |

**متوسط**: 9 functions, 11-13 ساعة للفرد ✅

---

## 💡 ملاحظات مهمة:

### التنسيق بين الأعضاء:
- **عمر وخالد**: يكملوا Stack & Queue معاً
- **نور وهبه ومريم**: يكملوا LinkedList معاً
- **هبه ومريم ونور (و)**: يكملوا BST معاً

### Integration (كل الفريق):
**الجميع** سيشاركون في:
- `HelpDesk.h` و `HelpDesk.cpp` (مريم تقود + الكل يساعد)
- `main.cpp` (نور (و) تقود + الكل يساعد)
- Testing (كل واحد يختبر جزئه)

**Main Menu Structure:**
```
1. Request Management
   ├─ Create New Request
   ├─ Process Next Request
   ├─ Escalate Request
   ├─ Resolve Request
   └─ View Request Details

2. Agent Management
   ├─ Add New Agent
   ├─ Remove Agent
   ├─ View All Agents
   └─ Assign Agent to Request

3. View Operations
   ├─ View All Requests (BST Inorder)
   ├─ View Pending Requests (Queue)
   ├─ View Escalations (Stack)
   ├─ View All Agents (Linked List)
   └─ View Specific Request

4. Search Operations
   ├─ Search Request by ID (BST)
   ├─ Search Agent by Name (Linear)
   └─ Sort Requests by Priority

5. Display Statistics

6. Run System Tests

0. Exit
```

**Testing Requirements:**

يجب اختبار كل الحالات التالية:

**Test 1: Stack Operations**
- Push multiple escalations
- Pop and verify LIFO order
- Test peek without removing
- Test isEmpty on empty stack
- Test isFull at capacity
- Display all escalations

**Test 2: Queue Operations**
- Enqueue requests with different priorities
- Verify highest priority is dequeued first
- Test FIFO for same priority
- Test isEmpty on empty queue
- Test isFull at capacity
- Display queue contents

**Test 3: Linked List Operations**
- Insert agents at different positions
- Delete from beginning, middle, end
- Search existing and non-existing agents
- Update agent information
- Test with single node
- Traverse and display all

**Test 4: BST Operations**
- Insert multiple requests
- Search for existing and non-existing IDs
- Delete node with 0 children
- Delete node with 1 child
- Delete node with 2 children
- Inorder traversal (verify sorted)
- Preorder traversal

**Test 5: Integration Tests**
- Create request → appears in Queue and BST
- Process request → removed from Queue, assigned agent in BST
- Escalate request → moved to Stack, status updated in BST
- Resolve request → agent freed, status updated
- Verify data consistency across all structures

**Test 6: Edge Cases**
- Empty structures (Stack, Queue, LinkedList, BST)
- Single element in each structure
- Full capacity (Stack, Queue)
- Invalid inputs (negative IDs, empty strings)
- Duplicate IDs
- Non-existent IDs

**Test 7: Search Algorithms**
- BST Search (O(log n))
- Linear Search (O(n))
- Compare performance with multiple searches

**Test 8: Sorting Algorithm**
- Create 10+ requests with random priorities
- Sort using implemented algorithm
- Verify correct order
- Display Big-O analysis

**Input Validation Requirements:**
- لا تقبل أرقام سالبة
- لا تقبل نصوص فارغة
- تحقق من نطاق الأولوية (1-4)
- تحقق من نطاق القوائم (0-max)
- اعرض رسائل خطأ واضحة
- اطلب إعادة الإدخال عند الخطأ

**User Experience:**
- قوائم واضحة ومنظمة
- رسائل نجاح عند إتمام العمليات
- رسائل خطأ عند الفشل
- امكانية العودة للقائمة الرئيسية
- زر Exit واضح
- Pause بعد كل عملية للقراءة

**Sample Data (Optional):**
يمكنك إضافة بيانات تجريبية في البداية:
```cpp
// Add sample agents
helpDesk.addAgent(101, "Ahmed Ali", "Hardware", "ahmed@email.com", "0123456789");
helpDesk.addAgent(102, "Sara Mohamed", "Software", "sara@email.com", "0123456788");
helpDesk.addAgent(103, "Omar Hassan", "Network", "omar@email.com", "0123456787");

// Create sample requests
helpDesk.createRequest("Customer 1", "Hardware", "Printer not working", 3);
helpDesk.createRequest("Customer 2", "Software", "Application crash", 4);
```

---

## ملاحظات عامة لجميع الأعضاء

### ⚠️ قواعد مهمة:

1. **لا تعدل على ملفات الأعضاء الآخرين** - كل شخص مسؤول عن ملفاته فقط
2. **اختبر كودك قبل الـ commit** - تأكد أن كل شيء يعمل
3. **أضف comments** - اشرح الكود بوضوح
4. **استخدم أسماء متغيرات واضحة** - تجنب i, j, k للمتغيرات المهمة
5. **اتبع نفس الـ coding style** - مسافات، أقواس، تنسيق

### 📝 Coding Standards:

```cpp
// Good variable names
int requestId;
string customerName;
bool isAvailable;

// Good function comments
/*
 * Function: functionName
 * Purpose: What it does
 * Parameters: What it takes
 * Returns: What it gives back
 */

// Proper indentation
if (condition) {
    // code
    if (nested) {
        // more code
    }
}
```

### 🔍 Testing Checklist:

- [ ] الكود يعمل compile بدون errors
- [ ] الكود يعمل compile بدون warnings
- [ ] اختبرت جميع الوظائف
- [ ] اختبرت edge cases (empty, single, full)
- [ ] اختبرت invalid inputs
- [ ] أضفت comments كافية
- [ ] متأكد من Big-O complexity

### 📚 Required Deliverables:

**في الـ Repository:**
1. ✅ Source Code (كل الملفات .h و .cpp)
2. ✅ README.md (تعليمات التشغيل)
3. ✅ Report (PDF أو DOCX)
4. ✅ Screenshots (لقطات شاشة للتشغيل)
5. ✅ Test Cases (نتائج الاختبارات)

**في الـ Report (يجب أن يحتوي على):**
1. Cover Page (أسماء، IDs، Section)
2. Problem Definition
3. Objectives
4. Data Structures Used (شرح لماذا استخدمنا كل واحدة)
5. System Features (القوائم والوظائف)
6. Implementation (شرح + code screenshots)
7. Testing (test cases + results)
8. Complexity Analysis (Big-O لكل عملية)
9. Team Contributions (مين عمل إيه)
10. Conclusion (الخلاصة والتحسينات المستقبلية)

### 🎯 Integration Points:

**يجب التنسيق بين الأعضاء في:**

1. **Member 5 ↔ All**: مريم تحتاج تستخدم كل الـ classes
2. **Member 6 ↔ Member 5**: نور تستدعي functions من HelpDesk
3. **Data consistency**: نفس الـ IDs في كل الـ structures

### 📅 Suggested Timeline:

**Week 1:**
- كل شخص يكمل الـ header file
- يتأكد من الـ function prototypes
- يناقش مع الفريق أي تغييرات

**Week 2:**
- تطبيق الوظائف الأساسية
- الاختبار الفردي لكل data structure

**Week 3:**
- Integration (دمج الـ HelpDesk)
- تطبيق الـ main menu
- الاختبار الشامل

**Week 4:**
- كتابة الـ Report
- أخذ Screenshots
- المراجعة النهائية
- الـ Submission

### 🚀 Git Workflow:

```bash
# 1. Clone the repository
git clone https://github.com/khaled854/HELP-DESK-PRIORITY-SIMULATION.git

# 2. Create your branch
git checkout -b your-name

# 3. Work on your files

# 4. Check status
git status

# 5. Add your files only
git add Stack.h Stack.cpp  # example

# 6. Commit with clear message
git commit -m "Implemented Stack push and pop functions"

# 7. Push to your branch
git push origin your-name

# 8. Create Pull Request on GitHub
```

### ⚡ Quick Start Commands:

**Compile:**
```bash
g++ -o HelpDesk main.cpp Stack.cpp Queue.cpp LinkedList.cpp BST.cpp HelpDesk.cpp
```

**Run:**
```bash
./HelpDesk        # Linux/Mac
HelpDesk.exe      # Windows
```

### 💡 Tips:

1. **اختبر كل function لوحدها** قبل ما تدمجها
2. **استخدم cout** للـ debugging
3. **ارسم على ورق** الـ data structures قبل التطبيق
4. **اسأل الفريق** إذا عندك أي سؤال
5. **ابدأ بالسهل** ثم انتقل للصعب
6. **اكتب TODO comments** للأشياء اللي لسه مش خلصتها

---

## 📞 Communication:

- اتواصلوا مع بعض باستمرار
- اعملوا اجتماع أسبوعي للمتابعة
- شاركوا المشاكل اللي واجهتكم
- ساعدوا بعض في الحل

---

## ✅ Success Criteria:

المشروع يعتبر ناجح لما:
- ✅ كل الـ data structures شغالة صح
- ✅ المشروع يعمل compile بدون errors
- ✅ كل الـ requirements متحققة
- ✅ الاختبارات كلها passed
- ✅ الكود نظيف ومنظم
- ✅ الـ Report كامل ومفصل
- ✅ كل عضو فاهم المشروع كله (مش بس جزئه)

---

## 🎓 Assessment Breakdown (30 marks):

1. Problem Definition & Objectives: **4 marks**
2. Data Structure Selection & Justification: **10 marks**
3. Data Structures Implementation: **5 marks**
4. Integration & Functional Requirements: **3 marks**
5. Code Quality & Error Handling: **3 marks**
6. Project Documentation: **5 marks**
7. **Individual Discussion: 5 marks** ← **مهم جداً! كل واحد لازم يفهم المشروع كله**

---

## Good Luck! 🎉

اشتغلوا بجد، ساعدوا بعض، وان شاء الله مشروع ممتاز! 💪
