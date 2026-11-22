# 🔄 دليل تسلسل العمل - تجنب Git Conflicts

## 🚨 المشكلة

**بعض الملفات فيها أكتر من شخص بيشتغل عليها:**
- Stack.cpp → عمر + خالد
- Queue.cpp → عمر + خالد
- LinkedList.cpp → نور + هبه
- BST.cpp → نور + هبه + مريم
- HelpDesk.cpp → الكل

**لو كلكم شغلتوا في نفس الوقت = Git Conflicts! ⚠️**

---

## ✅ الحل البسيط: اشتغلوا بالترتيب!

### المبدأ:
1. **الشخص الأول** يشتغل ويخلص جزئه
2. يعمل **commit & push**
3. **الشخص الثاني** يعمل **pull** ويكمل جزئه
4. يعمل **commit & push**
5. وهكذا...

---

## 📅 التسلسل المقترح (4 أسابيع)

### **Week 1: Individual Structures (Days 1-7)**

#### **Day 1-2: Stack.cpp**
```
✅ عمر → اشتغل على Functions 1-5
   - Constructor, push, pop, peek, isEmpty
   - Test them!
   - git add Stack.cpp
   - git commit -m "Stack: Added first 5 functions by Omar"
   - git push

⏸️ خالد → انتظر حتى عمر يخلص

✅ خالد → اعمل pull واشتغل على Functions 6-10
   - git pull
   - Destructor, isFull, size, display, clear
   - Test them!
   - git add Stack.cpp
   - git commit -m "Stack: Added remaining 5 functions by Khaled"
   - git push
```

#### **Day 2-3: Queue.cpp**
```
✅ عمر → Functions 1-5
   - Constructor, enqueue, front, isEmpty, size
   - git commit & push

✅ خالد → Functions 6-11
   - git pull first!
   - Destructor, dequeue, isFull, display, clear, getHighestPriority
   - git commit & push
```

#### **Day 3-5: LinkedList.cpp**
```
✅ نور → Functions 1-7
   - Constructor, insert, search, display, isEmpty, getCount, assignRequest
   - git commit & push

✅ هبه → Functions 8-14
   - git pull first!
   - Destructor, delete, update, unassign, setAvailability, findAvailable, clear
   - git commit & push
```

#### **Day 5-7: BST.cpp** (الأطول!)
```
✅ نور → Functions 1-7
   - Constructor, insert, insertHelper, search, searchHelper, isEmpty, getCount
   - git commit & push

✅ هبه → Functions 8-14
   - git pull first!
   - Destructor, delete, deleteHelper, findMinNode, findMin, findMax, clear
   - git commit & push

✅ مريم → Functions 15-21
   - git pull first!
   - inorder, inorderHelper, preorder, preorderHelper, updateStatus, updateResolvedTime, clearHelper
   - git commit & push
```

---

### **Week 2: Integration (Days 8-14)**

#### **Day 8-10: HelpDesk.cpp - Phase 1**
```
✅ مريم → Start with structure
   - Constructor, Destructor
   - Helper functions (getTimestamp, getNextId)
   - git commit & push

✅ عمر → Add his integration functions
   - git pull first!
   - createRequest(), escalateRequest()
   - git commit & push

✅ خالد → Add his functions
   - git pull first!
   - processNextRequest(), resolveRequest()
   - git commit & push

✅ نور → Add his function
   - git pull first!
   - addAgent(), searchRequestById()
   - git commit & push

✅ هبه → Add her functions
   - git pull first!
   - removeAgent(), assignAgentToRequest()
   - git commit & push

✅ مريم → Add remaining
   - git pull first!
   - displayStatistics(), algorithms
   - git commit & push
```

#### **Day 11-12: main.cpp**
```
✅ نور و → Main structure & menus
   - main(), menus, validation
   - git commit & push

✅ عمر → Add handleRequestManagement()
   - git pull first!
   - git commit & push

✅ خالد → Add handleSearchOperations()
   - git pull first!
   - git commit & push
```

#### **Day 13-14: View Functions**
```
✅ نور و → Implement all view functions
   - viewRequest(), viewAllRequests(), viewAllAgents()
   - git commit & push
```

---

### **Week 3: Algorithms & Testing (Days 15-21)**

#### **Day 15-17: Algorithms**
```
✅ مريم → Implement algorithms
   - sortRequestsByPriority()
   - linearSearchAgent()
   - git commit & push
```

#### **Day 18-21: Testing**
```
✅ نور و → Write test suite in main.cpp
   - runTests() function
   - Test all structures
   - git commit & push

✅ All → Run tests and fix bugs
   - Each person tests their part
   - Fix any issues
   - Commit fixes separately
```

---

### **Week 4: Report & Final (Days 22-28)**

#### **Day 22-24: Report**
- Each person writes their section
- No code conflicts!

#### **Day 25-28: Final touches**
- Review & screenshots
- Final testing
- Submission prep

---

## 📋 Quick Reference: ترتيب الشغل

### الترتيب الصحيح:

1. **Stack.cpp:** عمر → خالد
2. **Queue.cpp:** عمر → خالد
3. **LinkedList.cpp:** نور → هبه
4. **BST.cpp:** نور → هبه → مريم
5. **HelpDesk.cpp:** مريم → عمر → خالد → نور → هبه → مريم
6. **main.cpp:** نور و → عمر → خالد

---

## 🚫 تجنب هذه الأخطاء!

### ❌ خطأ شائع:
```bash
# عمر و خالد يشتغلوا على Stack.cpp في نفس الوقت
# Result: Conflict! 💥
```

### ✅ الطريقة الصحيحة:
```bash
# عمر يشتغل ويخلص
git add Stack.cpp
git commit -m "Stack: Omar's part done"
git push

# خالد ينتظر ثم:
git pull
# يشتغل على جزئه
git add Stack.cpp
git commit -m "Stack: Khaled's part done"
git push
```

---

## 💡 نصائح مهمة:

### 1️⃣ التواصل
- اتكلموا مع بعض قبل ما تشتغلوا
- استخدموا WhatsApp group
- "أنا بشتغل على Stack.cpp دلوقتي"

### 2️⃣ Pull قبل كل حاجة
```bash
git pull    # دايماً قبل ما تبدأ تشتغل!
```

### 3️⃣ Commit بعد كل جزء
```bash
# لما تخلص جزئك:
git add your_file.cpp
git commit -m "Clear message"
git push
```

### 4️⃣ Test قبل Commit
- اختبر الـ functions بتاعتك
- متعملش commit لكود مش شغال

### 5️⃣ Clear messages
```bash
# ✅ Good
git commit -m "Stack: Added push, pop, peek functions"

# ❌ Bad
git commit -m "updated"
```

---

## 🔧 لو حصل Conflict

### الخطوات:
```bash
# 1. Pull التغييرات
git pull

# 2. لو فيه conflict:
# Git هيقولك في conflict في file X

# 3. افتح الملف وشوف:
<<<<<<< HEAD
Your code
=======
Their code
>>>>>>> branch-name

# 4. اختار الكود الصح أو ادمجهم
# 5. امسح الـ <<<< و ==== و >>>>

# 6. Commit التعديل
git add conflicted_file.cpp
git commit -m "Fixed conflict in file X"
git push
```

---

## 📞 محتاج مساعدة؟

### لو حصلت مشكلة:
1. **اتكلم مع مريم** (Integration Leader)
2. **اسأل في الـ group**
3. **اقرأ GIT_INSTRUCTIONS.md**

---

## ✅ Checklist

قبل ما تبدأ تشتغل على ملف:
- [ ] اتأكدت إن اللي قبلي خلص؟
- [ ] عملت `git pull`?
- [ ] الكود عندي محدث؟

قبل ما تعمل commit:
- [ ] اختبرت الـ functions؟
- [ ] الكود بيشتغل؟
- [ ] مفيش syntax errors?
- [ ] كتبت commit message واضح؟

---

## 🎯 الهدف

**Zero Conflicts! 🎉**

لو اتبعتوا الترتيب ده، مش هيكون فيه أي مشاكل Git.

**Work smart, not hard! 💪**

---

**Remember: التواصل + الترتيب = نجاح المشروع! 🚀**
