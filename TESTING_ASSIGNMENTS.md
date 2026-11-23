# 🧪 توزيع التيستينج - Who Tests Who
## CS212 - Help Desk Priority Simulation

**الفكرة الأساسية:** كل واحد يختبر شغل اللي بعده

---

## 👥 مين هيعمل تيست لمين؟

### النظام الدائري (Circular Testing):

```
عمر → خالد → نور → هبه → مريم → نور وائل → عمر
 ↑                                              ↓
 ←←←←←←←←←← كل واحد يختبر اللي بعده ←←←←←←←←←←←
```

---

## 📋 التفاصيل الكاملة

### 1️⃣ **خالد** يختبر شغل **عمر**

**اللي هيتم اختباره:**
- Stack Functions (5 functions): Constructor, push, pop, peek, isEmpty
- Queue Functions (5 functions): Constructor, enqueue, front, isEmpty, size
- HelpDesk Integration (3 functions): createRequest, escalateRequest, viewEscalations

**عدد Test Cases:** 11-13 test  
**الوقت المتوقع:** 2-3 ساعات

---

### 2️⃣ **نور محمد** يختبر شغل **خالد**

**اللي هيتم اختباره:**
- Stack Functions (5 functions): Destructor, isFull, size, display, clear
- Queue Functions (6 functions): Destructor, dequeue, isFull, display, clear, getHighestPriority
- HelpDesk Integration (2 functions): processNextRequest, resolveRequest

**عدد Test Cases:** 11-13 test  
**الوقت المتوقع:** 2-3 ساعات

---

### 3️⃣ **هبه** تختبر شغل **نور محمد**

**اللي هيتم اختباره:**
- LinkedList Functions (7 functions): Constructor, insertAgent, searchAgent, displayAgents, isEmpty, getCount, assignRequest
- BST Functions (7 functions): Constructor, insert, insertHelper, search, searchHelper, isEmpty, getCount
- Main Menu (1 function): handleAgentManagement

**عدد Test Cases:** 13-15 test  
**الوقت المتوقع:** 2-3 ساعات

---

### 4️⃣ **مريم** تختبر شغل **هبه**

**اللي هيتم اختباره:**
- LinkedList Functions (7 functions): Destructor, deleteAgent, updateAgent, unassignRequest, setAvailability, findAvailableAgent, clear
- BST Functions (8 functions): Destructor, deleteRequest, deleteHelper, findMinNode, findMin, findMax, clearHelper, clear

**عدد Test Cases:** 13-15 test  
**الوقت المتوقع:** 3-4 ساعات

**ملاحظة:** أصعب تيستينج (BST delete + destructors)

---

### 5️⃣ **نور وائل** يختبر شغل **مريم**

**اللي هيتم اختباره:**
- HelpDesk Functions (13 functions): Constructor, Destructor, getCurrentTimestamp, getNextRequestId, displayStatistics, sortRequestsByPriority, linearSearchAgent, addAgent, removeAgent, viewPendingRequests, searchRequestById, assignAgentToRequest, processEscalation
- الـ Algorithms (Sorting + Linear Search)

**عدد Test Cases:** 11-13 test  
**الوقت المتوقع:** 2-3 ساعات

**ملاحظة:** اختبار الـ Algorithms مهم جداً

---

### 6️⃣ **عمر** يختبر شغل **نور وائل**

**اللي هيتم اختباره:**
- BST Functions (6 functions): inorderTraversal, inorderHelper, preorderTraversal, preorderHelper, updateStatus, updateResolvedTime
- Main Functions (7 functions): main, displayMainMenu, clearInputBuffer, getValidatedIntInput, getValidatedStringInput, handleViewOperations, runTests
- HelpDesk Views (3 functions): viewRequest, viewAllRequests, viewAllAgents

**عدد Test Cases:** 14-16 test  
**الوقت المتوقع:** 2-3 ساعات

---

## 📊 ملخص التوزيع

| المختبِر (Tester) | اللي بيختبره | عدد Functions | عدد Tests | الوقت |
|-------------------|--------------|---------------|-----------|-------|
| **خالد** | عمر | 14 | 11-13 | 2-3h |
| **نور محمد** | خالد | 14 | 11-13 | 2-3h |
| **هبه** | نور | 15 | 13-15 | 2-3h |
| **مريم** | هبه | 15 | 13-15 | 3-4h |
| **نور وائل** | مريم | 13 | 11-13 | 2-3h |
| **عمر** | نور وائل | 16 | 14-16 | 2-3h |

**إجمالي**: **87 functions** = **87 test cases**  
**متوسط عدد Tests لكل شخص:** ~14.5 tests  
**متوسط الوقت:** 2-3 ساعات  
**النتيجة:** ⚖️ **متوازن تماماً!**

---

## ✅ ليه التوزيع ده أفضل؟

### **الطريقة القديمة** ❌:
- نور وائل: يختبر كل حاجة (25+ tests)
- الباقي: كل واحد يختبر شغله بس
- **المشكلة:** واحد محمل والباقي مش مهتمين بالتيستينج

### **الطريقة الجديدة** ✅:
- **كل واحد يختبر شغل حد تاني**
- Fresh eyes = اكتشاف bugs أكتر
- Shared responsibility
- Quality أحسن
- Fair workload

---

## 🔄 عملية التيستينج

### **خطوات التنفيذ:**

1. **المبرمج (Developer)**:
   - ينهي الـ functions بتاعته
   - يعمل self-testing بسيط
   - يعمل commit + push
   - يبلغ المختبِر: "الكود جاهز للتيستينج"

2. **المختبِر (Tester)**:
   - يسحب الكود الجديد (pull)
   - يقرأ الـ functions اللي هيختبرها
   - يكتب test cases
   - ينفذ الاختبارات
   - يوثق النتايج في `Tests/test_results.txt`
   - يبلغ المبرمج بالـ bugs

3. **المبرمج (مرة تانية)**:
   - يصلح الـ bugs
   - يعمل commit
   - يبلغ المختبِر: "تم إصلاح المشاكل"

4. **المختبِر (تأكيد)**:
   - يعيد الاختبار
   - يوافق إذا كل شيء تمام

---

## 📝 توثيق نتائج الاختبار

**ملف:** `Tests/test_results.txt`

**الصيغة:**
```
========================================
المختبِر: [اسمك]
يختبر: [اسم المبرمج] - [المكون]
التاريخ: [التاريخ]
========================================

TEST 1: [اسم الاختبار]
الوصف: [ما الذي يتم اختباره]
المدخلات: [البيانات المستخدمة]
النتيجة المتوقعة: [ما المفروض يحصل]
النتيجة الفعلية: [ما اللي حصل فعلاً]
الحالة: نجح / فشل
ملاحظات: [أي ملاحظات]

TEST 2: ...
[استمر لكل الاختبارات]

الملخص:
إجمالي الاختبارات: X
النجاح: Y
الفشل: Z
Bugs المكتشفة: [قائمة]

توقيع المختبِر: [الاسم]
========================================
```

---

## 📅 جدول زمني للتيستينج

### **الأسبوع 1 (أيام 1-7)**: Implementation + Self-Testing
- كل مبرمج يختبر كوده الخاص (اختبار أساسي)
- التأكد من compile بدون errors

### **الأسبوع 2 (أيام 8-14)**: Cross-Testing المرحلة الأولى
- **يوم 8**: خالد يختبر عمر
- **يوم 9**: نور يختبر خالد
- **يوم 10**: هبه تختبر نور
- المبرمجين يصلحوا bugs

### **الأسبوع 3 (أيام 15-21)**: Cross-Testing المرحلة الثانية
- **يوم 15**: مريم تختبر هبه
- **يوم 16**: نور وائل يختبر مريم
- **يوم 17**: عمر يختبر نور وائل
- **أيام 18-21**: Re-testing وإصلاح bugs

### **الأسبوع 4 (أيام 22-28)**: Integration Testing
- **كل الفريق** يختبر التكامل بين المكونات
- Final testing
- إصلاح أي مشاكل أخيرة

---

## ✅ Checklist للمبرمج

- [ ] كل الـ functions بتاعتي خلصت
- [ ] عملت self-testing أساسي
- [ ] الكود يعمل compile بدون errors
- [ ] عملت commit + push
- [ ] بلغت المختبِر إن الكود جاهز
- [ ] استلمت bugs من المختبِر
- [ ] صلحت كل المشاكل
- [ ] المختبِر وافق على الكود

---

## ✅ Checklist للمختبِر

- [ ] سحبت الكود من GitHub
- [ ] فهمت الـ functions اللي هختبرها
- [ ] كتبت test cases
- [ ] نفذت كل الاختبارات
- [ ] وثقت النتايج في test_results.txt
- [ ] أبلغت المبرمج بالـ bugs
- [ ] أعدت الاختبار بعد الإصلاح
- [ ] وافقت نهائياً على الكود

---

## 🎯 الهدف النهائي

**كل واحد في الفريق:**
- ✅ ينفذ شغله
- ✅ يختبر شغل حد تاني
- ✅ يفهم المشروع كامل
- ✅ يتعلم من شغل زمايله

**النتيجة:**
- 🎯 Quality عالي
- 🎯 Bugs أقل
- 🎯 Team collaboration أحسن
- 🎯 Shared responsibility
- 🎯 Fair workload

---

**ملاحظة نهائية:** التيستينج مش مسؤولية شخص واحد - **كلنا مسؤولين!** 💪
