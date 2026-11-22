# تعليمات استخدام Git و GitHub

## خطوات البداية (مرة واحدة فقط)

### 1. تحميل Git (إذا لم يكن مثبتاً)
- Windows: [Download Git](https://git-scm.com/download/win)
- Mac: `brew install git`
- Linux: `sudo apt-get install git`

### 2. إعداد Git (أول مرة)
```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

### 3. Clone المشروع
```bash
cd Desktop
git clone https://github.com/khaled854/HELP-DESK-PRIORITY-SIMULATION.git
cd HELP-DESK-PRIORITY-SIMULATION
```

---

## طريقة العمل اليومية

### خطوة 1: قبل البدء - اسحب آخر التحديثات
```bash
git pull origin main
```
⚠️ **مهم جداً**: افعل هذا كل مرة قبل ما تبدأ الشغل!

### خطوة 2: شوف حالة الملفات
```bash
git status
```
هيوريك الملفات اللي اتغيرت (أحمر = مش staged، أخضر = staged)

### خطوة 3: أضف ملفاتك فقط
```bash
# أضف ملفاتك بس (مش ملفات الناس التانية!)
git add Stack.h Stack.cpp          # مثال لـ Member 1
git add Queue.h Queue.cpp          # مثال لـ Member 2
git add LinkedList.h LinkedList.cpp # مثال لـ Member 3
# ... وهكذا
```

### خطوة 4: اعمل Commit برسالة واضحة
```bash
git commit -m "وصف واضح للتعديلات"
```

أمثلة على رسائل جيدة:
```bash
git commit -m "Implemented Stack push and pop functions"
git commit -m "Added input validation to Queue enqueue"
git commit -m "Fixed memory leak in LinkedList destructor"
git commit -m "Completed BST delete with 2 children case"
git commit -m "Added main menu interface"
```

### خطوة 5: ارفع التعديلات
```bash
git push origin main
```

---

## حل المشاكل الشائعة

### Problem 1: Merge Conflict
إذا ظهر conflict (تعارض):

```bash
# 1. افتح الملف اللي فيه مشكلة
# 2. ابحث عن:
<<<<<<< HEAD
Your changes
=======
Other person's changes
>>>>>>> branch-name

# 3. احذف العلامات وخلي التعديل الصح
# 4. بعدين:
git add [filename]
git commit -m "Resolved merge conflict"
git push origin main
```

### Problem 2: Forgot to Pull First
```bash
# إذا حاولت تعمل push ولقيت رسالة خطأ:
git pull origin main
# حل أي conflicts لو موجودة
git push origin main
```

### Problem 3: Want to Undo Changes
```bash
# قبل الـ commit:
git checkout -- filename.cpp

# بعد الـ commit (لكن قبل الـ push):
git reset --soft HEAD~1

# ⚠️ لا تستخدم --hard إلا لو متأكد!
```

---

## الأوامر الأساسية - ملخص سريع

| الأمر | الوصف |
|------|-------|
| `git status` | شوف حالة الملفات |
| `git pull` | اسحب آخر التحديثات |
| `git add <file>` | أضف ملف للـ staging |
| `git commit -m "msg"` | احفظ التعديلات |
| `git push` | ارفع على GitHub |
| `git log` | شوف تاريخ الـ commits |
| `git diff` | شوف الفرق قبل الـ add |

---

## قواعد مهمة جداً ⚠️

### ✅ افعل:
1. **Pull قبل Push** دايماً
2. **Commit بشكل متكرر** (كل 30 دقيقة أو ساعة)
3. **اكتب رسائل commit واضحة** (بالإنجليزي أحسن)
4. **أضف ملفاتك فقط** (مش كل الملفات)
5. **Test قبل Push** (تأكد إن الكود بيشتغل)

### ❌ لا تفعل:
1. **لا تعدل على ملفات غيرك** إلا بتنسيق
2. **لا تعمل `git add .`** بدون تفكير (ممكن تضيف ملفات غلط)
3. **لا تعمل push لملفات compiled** (.exe, .o, .obj)
4. **لا تعمل `git push --force`** أبداً!
5. **لا تنسى تعمل pull** قبل ما تبدأ

---

## Workflow النموذجي - مثال عملي

### صباح يوم الشغل:
```bash
# 1. افتح Terminal/Command Prompt
cd Desktop/HELP-DESK-PRIORITY-SIMULATION

# 2. اسحب آخر التحديثات
git pull origin main

# 3. شوف إيه اللي اتغير
git status

# 4. ابدأ الشغل...
# (اشتغل على ملفاتك)
```

### بعد ما تخلص جزء من الشغل:
```bash
# 1. شوف إيه اللي اتغير
git status

# 2. أضف ملفاتك
git add Stack.h Stack.cpp

# 3. اعمل commit
git commit -m "Implemented push, pop, and peek functions"

# 4. ارفع
git push origin main
```

### قبل ما تقفل الجهاز:
```bash
# تأكد إن كل حاجة متحفوظة
git status

# لو فيه تعديلات مش محفوظة:
git add [your-files]
git commit -m "End of day commit - work in progress"
git push origin main
```

---

## شرح البنية (Branch Structure)

### Main Branch (الفرع الرئيسي):
- هو الفرع الأساسي
- كل الناس بتشتغل عليه
- يجب يكون دايماً في حالة جيدة (يعمل compile)

### إذا أردت استخدام Branches (اختياري):
```bash
# إنشاء فرع جديد
git checkout -b omar-stack

# الشغل على الفرع
git add Stack.h Stack.cpp
git commit -m "Completed Stack implementation"

# رفع الفرع
git push origin omar-stack

# العودة للـ main
git checkout main

# دمج الفرع (بعد المراجعة)
git merge omar-stack
```

---

## نصائح للعمل الجماعي

### 1. التواصل
- أخبر الفريق قبل تعديل أي ملف مشترك
- استخدم WhatsApp/Telegram للتنسيق
- اعملوا اجتماع أسبوعي للمتابعة

### 2. تقسيم العمل
- كل شخص مسؤول عن ملفاته فقط
- لو محتاج تعدل في ملف حد تاني، نسّق معاه
- مريم (Member 5) هتحتاج تستخدم كل الـ classes - نسقوا معاها

### 3. التكامل
- اعملوا integration testing بشكل دوري
- تأكدوا إن الملفات بتشتغل مع بعض
- اختبروا بعد كل merge

### 4. المراجعة
- راجعوا commits بعض
- استخدموا GitHub Issues لتتبع المشاكل
- اعملوا code review قبل الـ final submission

---

## GitHub Web Interface

### عرض الملفات:
1. اذهب إلى: https://github.com/khaled854/HELP-DESK-PRIORITY-SIMULATION
2. اضغط على أي ملف لعرضه
3. اضغط "History" لرؤية التغييرات

### عرض Commits:
1. اضغط على "Commits" (جنب الـ branch name)
2. شوف مين عمل إيه ومتى

### Downloading الكود:
1. اضغط "Code" (الزر الأخضر)
2. اختر "Download ZIP"
3. **أو** استخدم `git clone` (أفضل)

---

## إعداد SSH Key (اختياري - لتجنب كتابة Password)

### Windows/Mac/Linux:
```bash
# 1. توليد SSH key
ssh-keygen -t ed25519 -C "your.email@example.com"
# اضغط Enter 3 مرات (default settings)

# 2. نسخ الـ public key
# Windows:
cat ~/.ssh/id_ed25519.pub

# Mac/Linux:
cat ~/.ssh/id_ed25519.pub

# 3. اذهب إلى GitHub → Settings → SSH and GPG keys
# 4. اضغط "New SSH key"
# 5. الصق الـ key وحفظ

# 6. غير الـ remote URL:
git remote set-url origin git@github.com:khaled854/HELP-DESK-PRIORITY-SIMULATION.git
```

---

## موارد إضافية

### تعلم Git:
- [Git Tutorial (العربية)](https://www.youtube.com/results?search_query=git+tutorial+arabic)
- [GitHub Guides](https://guides.github.com/)
- [Git Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf)

### أدوات مفيدة:
- **GitHub Desktop**: برنامج GUI بدل Command Line
- **GitKraken**: Git client متقدم
- **VS Code**: فيه Git integration مدمج

---

## الخلاصة - 5 خطوات بس!

```bash
1. git pull origin main          # اسحب التحديثات
2. [Work on your files]          # اشتغل
3. git add <your-files>          # أضف ملفاتك
4. git commit -m "message"       # احفظ
5. git push origin main          # ارفع
```

**كرر كل يوم!** 🔄

---

## أسئلة شائعة (FAQ)

**Q: هل يجب أن أعمل branch خاص بي؟**
A: لا، يمكنكم الشغل كلكم على main branch (أسهل للمشروع الصغير)

**Q: ماذا لو نسيت أعمل pull قبل push؟**
A: Git سيطلب منك تعمل pull أولاً، افعلها ثم push مرة أخرى

**Q: هل يمكنني حذف commit؟**
A: نعم، لكن فقط إذا لم تعمل push بعد (استخدم git reset)

**Q: ماذا لو رفعت ملف بالغلط؟**
A: يمكنك حذفه وعمل commit جديد بالحذف

**Q: كيف أعرف مين عمل إيه؟**
A: استخدم `git log` أو شوف على GitHub

---

**Good Luck! إذا واجهت مشكلة، اسأل الفريق أو ابحث على Google** 🚀
