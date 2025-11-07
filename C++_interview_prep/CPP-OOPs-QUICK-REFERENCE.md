# ⚡ C++ & OOPs QUICK REFERENCE - ONE PAGE
## Last-Minute Revision for Interview Day

---

## 🎯 4 PILLARS OF OOP (MEMORIZE!)

```
┌─────────────────────────────────┐
│  EIPA = 4 Pillars              │
└────────────┬────────────────────┘
             │
    ┌────────▼─────────┐
    │  E I P A         │
    └─┬──┬──┬──┬───────┘
      │  │  │  │
   Enc Inh Poly Abs
```

| Pillar | What | How | Example |
|--------|------|-----|---------|
| **E**ncapsulation | Data hiding | `private`, getters/setters | Bank account (private balance) |
| **I**nheritance | Code reuse | `: public` | Vehicle → Car |
| **P**olymorphism | Many forms | Overloading / `virtual` | `add(int, int)`, `add(double, double)` |
| **A**bstraction | Hide complexity | `virtual func() = 0` | Payment methods (interface) |

---

## 💬 1-MINUTE PITCH (Say this confidently!)

> "Sir, OOP has **4 pillars - EIPA**:
> 
> 1. **Encapsulation** - Hiding data using private, accessing via getters/setters
> 2. **Inheritance** - Reusing code, parent to child
> 3. **Polymorphism** - Same name, different behavior (overloading & overriding)
> 4. **Abstraction** - Hiding implementation using abstract classes
> 
> Shall I explain any with code?"

---

## 🔥 TOP 10 MUST-KNOW QUESTIONS

| # | Question | Frequency | Quick Answer |
|---|----------|-----------|--------------|
| 1 | What is OOP? | 100% ⭐⭐⭐ | Objects + Classes, advantages: reusability, security, modularity |
| 2 | 4 Pillars? | 95% ⭐⭐⭐ | **EIPA** - Encapsulation, Inheritance, Polymorphism, Abstraction |
| 3 | Class vs Object? | 95% ⭐⭐⭐ | Class = Blueprint, Object = Instance (building analogy) |
| 4 | Encapsulation? | 90% ⭐⭐⭐ | Data + methods bundled, data hidden (private) |
| 5 | Inheritance types? | 92% ⭐⭐⭐ | 5 types: Single, Multilevel, Hierarchical, Multiple, Hybrid |
| 6 | Polymorphism types? | 85% ⭐⭐⭐ | Compile-time (overloading) + Run-time (virtual overriding) |
| 7 | Virtual function? | 80% ⭐⭐⭐ | `virtual void func()` - allows overriding, run-time binding |
| 8 | Encap vs Abstraction? | 80% ⭐⭐⭐ | Encap = data hiding, Abstraction = implementation hiding |
| 9 | Constructor types? | 88% ⭐⭐⭐ | 3 types: Default, Parameterized, Copy |
| 10 | Access specifiers? | 80% ⭐⭐⭐ | public (everywhere), private (class only), protected (class + child) |

---

## 📝 CODE TEMPLATES (Copy-Paste Ready)

### **Template 1: Encapsulation**
```cpp
class BankAccount {
private:
    double balance;  // HIDDEN
public:
    void deposit(double amt) { balance += amt; }
    double getBalance() { return balance; }
};
```

### **Template 2: Inheritance**
```cpp
class Vehicle {
protected:
    string brand;
public:
    void setBrand(string b) { brand = b; }
};

class Car : public Vehicle {  // Inherits
private:
    int doors;
public:
    void setDoors(int d) { doors = d; }
};
```

### **Template 3: Polymorphism (Overloading)**
```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};
```

### **Template 4: Polymorphism (Overriding)**
```cpp
class Animal {
public:
    virtual void sound() { cout << "Animal sound"; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Woof!"; }
};

// Usage: Animal* a = new Dog(); a->sound();  // Woof!
```

### **Template 5: Abstract Class**
```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double rad) : r(rad) {}
    double area() override { return 3.14 * r * r; }
};
```

### **Template 6: Constructor**
```cpp
class Student {
    string name;
    int roll;
public:
    Student() { name = "Unknown"; roll = 0; }  // Default
    Student(string n, int r) : name(n), roll(r) {}  // Parameterized
    Student(const Student &s) : name(s.name), roll(s.roll) {}  // Copy
};
```

---

## 🎓 KEY DEFINITIONS

### **OOP:**
Object-Oriented Programming using objects and classes

### **Class:**
Blueprint/template (doesn't occupy memory)

### **Object:**
Instance of class (occupies memory)

### **Encapsulation:**
Wrapping data + methods, hiding data (private)

### **Inheritance:**
Child class acquires parent's properties (code reuse)

### **Polymorphism:**
Same name, different forms (overloading/overriding)

### **Abstraction:**
Hide complex implementation, show essential (abstract classes)

### **Virtual Function:**
`virtual void func()` - can be overridden in child class

### **Pure Virtual Function:**
`virtual void func() = 0` - makes class abstract

### **Constructor:**
Special function, same name as class, initializes object

### **Destructor:**
`~ClassName()` - called when object destroyed, cleanup

### **Friend Function:**
Non-member function accessing private members

---

## 🔑 KEYWORD CHEAT SHEET

| Keyword | Purpose | Example |
|---------|---------|---------|
| `class` | Define class | `class Car { ... };` |
| `public:` | Accessible everywhere | `public: int x;` |
| `private:` | Accessible in class only | `private: int balance;` |
| `protected:` | Accessible in class + child | `protected: int data;` |
| `virtual` | Can be overridden | `virtual void func()` |
| `override` | Overrides parent function | `void func() override` |
| `= 0` | Pure virtual (abstract) | `virtual void f() = 0;` |
| `: public` | Public inheritance | `class Car : public Vehicle` |
| `friend` | Grant access to private | `friend void display(Box b);` |
| `this` | Pointer to current object | `this->x = x;` |
| `new` | Allocate memory | `int* p = new int;` |
| `delete` | Free memory | `delete p;` |

---

## 🏢 COMPANY-WISE TOP 3

### **TCS (Clarity + Basics):**
1. 4 Pillars of OOP (95%)
2. Class vs Object (95%)
3. Constructor types (88%)

### **Infosys (Depth + Advanced):**
1. Virtual functions (92%)
2. Encapsulation vs Abstraction (90%)
3. Polymorphism types (95%)

### **Wipro (Fundamentals):**
1. OOP advantages (100%)
2. Inheritance types (90%)
3. Access specifiers (80%)

---

## ⚠️ COMMON MISTAKES TO AVOID

```
❌ Saying "Constructor returns void"
   ✅ Constructor has NO return type

❌ "Encapsulation and Abstraction are same"
   ✅ Different! Encapsulation = data hiding, Abstraction = implementation hiding

❌ Forgetting `virtual` keyword for overriding
   ✅ Base class needs `virtual`, child uses `override`

❌ "Can create object of abstract class"
   ✅ CANNOT create object if has pure virtual function

❌ "Destructor can be overloaded"
   ✅ Only ONE destructor per class

❌ "Private members accessible in child class"
   ✅ Only protected and public are accessible in child
```

---

## ⏰ INTERVIEW DAY CHECKLIST (30 MIN BEFORE)

```
□ Read 4 Pillars (EIPA) - 5 min
□ Memorize Top 10 questions - 10 min
□ Practice saying definitions out loud - 5 min
□ Review code templates - 5 min
□ Write "EIPA" on paper from memory - 2 min
□ Deep breath, relax - 3 min ✨
```

---

## 💡 INTERVIEW COMMUNICATION STRATEGY

### **When asked ANY OOPs question:**

**Step 1:** Definition (20 seconds)
> "Sir, [concept] means [definition in simple words]"

**Step 2:** Benefits/Types (20 seconds)
> "It provides [benefits] / There are [X] types"

**Step 3:** Example (20 seconds)
> "For example, [real-life analogy]"

**Step 4:** Code (optional, ask first!)
> "Shall I explain with code?"

**Total:** 1 minute clear answer! ✅

---

## 🎯 EMERGENCY 15-MIN REVISION

If you have ONLY 15 minutes before interview:

1. **4 Pillars (EIPA)** - 5 min
   - Encapsulation = data hiding
   - Inheritance = code reuse
   - Polymorphism = many forms
   - Abstraction = implementation hiding

2. **Top 5 Questions** - 7 min
   - What is OOP?
   - 4 Pillars?
   - Class vs Object?
   - Encapsulation example?
   - Inheritance types?

3. **Quick Code Practice** - 3 min
   - Write simple class from memory
   - Write simple inheritance from memory

**You're ready!** 🚀

---

## 🔥 CONFIDENCE BOOSTERS

```
✅ You know 4 Pillars (EIPA)
✅ You can code encapsulation
✅ You understand inheritance
✅ You know virtual functions
✅ You've practiced 15 questions
✅ You're INTERVIEW READY! 💪
```

---

## 📊 QUICK COMPARISON TABLES

### **Table 1: Polymorphism Types**
| Aspect | Compile-time | Run-time |
|--------|--------------|----------|
| Method | Overloading | Overriding |
| Keyword | None | `virtual` |
| Binding | Early | Late |
| Speed | Faster | Slower |

### **Table 2: Access Specifiers**
| Specifier | Inside Class | Outside Class | In Child Class |
|-----------|--------------|---------------|----------------|
| public | ✅ | ✅ | ✅ |
| protected | ✅ | ❌ | ✅ |
| private | ✅ | ❌ | ❌ |

### **Table 3: Constructor vs Destructor**
| Aspect | Constructor | Destructor |
|--------|-------------|------------|
| Name | Same as class | ~ClassName |
| Return type | None | None |
| Parameters | Can have | Cannot have |
| Overloading | Yes (multiple) | No (only one) |
| When called | Object creation | Object destruction |

---

## 🎬 FINAL WORDS

> **You've prepared 180+ DSA problems**  
> **You've mastered 9 DSA topics**  
> **You've learned complete STL**  
> **You now know C++ & OOPs**  
> 
> **You're 100% READY for service-based companies!** ✨
> 
> **Go crack that interview, Satyam!** 🚀💪
> 
> **Remember:** Confidence + Clarity = Selection ✅

---

**Keep this file open during last 30 minutes before interview!** 📖

**Print this page if possible!** 🖨️

**You've got this!** 💯
