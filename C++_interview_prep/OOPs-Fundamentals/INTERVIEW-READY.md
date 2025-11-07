# 🎯 OOPs FUNDAMENTALS - INTERVIEW READY
## Complete Guide for Service-Based Companies

---

## 📚 WHAT IS OOP?

### **Object-Oriented Programming (OOP):**
> A programming paradigm that uses **objects** and **classes** to organize code

### **Why OOP?**
```
✅ Code Reusability (write once, use many times)
✅ Modularity (organized in classes)
✅ Easy Maintenance (changes in one place)
✅ Real-world modeling (car, student, bank account)
✅ Security (data hiding)
```

---

## 🎯 THE 4 PILLARS OF OOP

```
┌─────────────────────────────────────┐
│   OOP = 4 PILLARS (MEMORIZE!)       │
└────────────┬────────────────────────┘
             │
    ┌────────▼─────────┐
    │  4 Pillars       │
    └──┬───┬───┬───┬───┘
       │   │   │   │
   ┌───▼┐ ┌▼──┐ ┌▼──────┐ ┌▼─────────┐
   │Enc-│ │Inh-│ │Poly-  │ │Abstra-   │
   │apsu│ │erit│ │morphi │ │ction     │
   │lati│ │ance│ │sm     │ │          │
   │on  │ │    │ │       │ │          │
   └────┘ └────┘ └───────┘ └──────────┘
   Hide   Reuse   Many     Hide
   Data   Code    Forms    Complex
```

---

## 📖 PILLAR 1: ENCAPSULATION ⭐⭐⭐

### **What is Encapsulation?**
> **Wrapping data (variables) and methods (functions) together** and **hiding** internal details

### **Real-Life Example:**
```
Medicine Capsule 🔴
├─ Medicine inside (data) - HIDDEN
└─ Outer coating (public interface) - VISIBLE

You don't see what's inside, you just take it!
```

---

### **💡 Interview Communication:**

> "Sir, **Encapsulation** means bundling data and methods together in a class and hiding internal details using **access specifiers** (private, public, protected).
> 
> **Benefits:**
> - Data hiding (security)
> - Controlled access through getters/setters
> - Easy to maintain
> 
> Let me show an example..."

---

### **📝 Code Example 1: Bank Account**

```cpp
#include <iostream>
using namespace std;

class BankAccount {
private:
    // Data is HIDDEN (encapsulated)
    string accountNumber;
    double balance;
    
public:
    // Constructor
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }
    
    // Public methods to ACCESS private data (Controlled Access)
    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
    }
    
    void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    
    // Getter (controlled read access)
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc("123456", 1000.0);
    
    // Can't directly access balance (it's private!)
    // acc.balance = 10000; // ❌ ERROR!
    
    // Must use public methods (controlled access)
    acc.deposit(500);        // ✅
    acc.withdraw(200);       // ✅
    cout << "Balance: " << acc.getBalance(); // ✅
    
    return 0;
}
```

**Output:**
```
Deposited: 500
Withdrawn: 200
Balance: 1300
```

---

### **📝 Code Example 2: Student Class**

```cpp
class Student {
private:
    string name;
    int rollNo;
    float marks;
    
public:
    // Setter methods (controlled write access)
    void setName(string n) {
        name = n;
    }
    
    void setRollNo(int r) {
        if(r > 0) {  // Validation!
            rollNo = r;
        }
    }
    
    void setMarks(float m) {
        if(m >= 0 && m <= 100) {  // Validation!
            marks = m;
        }
    }
    
    // Getter methods (controlled read access)
    string getName() { return name; }
    int getRollNo() { return rollNo; }
    float getMarks() { return marks; }
    
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;
    s.setName("Satyam");
    s.setRollNo(101);
    s.setMarks(95.5);
    
    s.display();
    
    return 0;
}
```

---

### **🎯 Key Points:**
- ✅ Data members are **private**
- ✅ Methods are **public**
- ✅ Use **getters/setters** for controlled access
- ✅ Can add **validation** in setters
- ✅ **Data hiding** = Security

---

### **🏢 Company Frequency:**
- **TCS:** 90% ⭐⭐⭐
- **Infosys:** 95% ⭐⭐⭐
- **Wipro:** 88% ⭐⭐⭐

---

## 📖 PILLAR 2: INHERITANCE ⭐⭐⭐

### **What is Inheritance?**
> **One class acquiring properties** (data members & methods) **of another class**

### **Real-Life Example:**
```
Parent 👨‍👩‍👦
├─ Eye color, height, surname
│
Child inherits these properties!
└─> Child 👶
    ├─ Eye color (inherited)
    ├─ Height genes (inherited)
    ├─ Surname (inherited)
    └─ Own hobbies (new)
```

---

### **💡 Interview Communication:**

> "Sir, **Inheritance** allows a class (child/derived) to inherit properties and methods from another class (parent/base).
> 
> **Benefits:**
> - Code reusability
> - Reduces redundancy
> - Easier maintenance
> 
> **Types:** Single, Multiple, Multilevel, Hierarchical, Hybrid
> 
> Let me show an example..."

---

### **📝 Code Example 1: Vehicle → Car**

```cpp
#include <iostream>
using namespace std;

// BASE CLASS (Parent)
class Vehicle {
protected:  // Accessible to child classes
    string brand;
    int speed;
    
public:
    void setBrand(string b) {
        brand = b;
    }
    
    void setSpeed(int s) {
        speed = s;
    }
    
    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

// DERIVED CLASS (Child) - inherits from Vehicle
class Car : public Vehicle {
private:
    int numberOfDoors;
    
public:
    void setDoors(int d) {
        numberOfDoors = d;
    }
    
    void displayCar() {
        displayVehicle();  // Using inherited method!
        cout << "Doors: " << numberOfDoors << endl;
    }
};

int main() {
    Car myCar;
    
    // Using inherited methods
    myCar.setBrand("Toyota");
    myCar.setSpeed(120);
    
    // Using own method
    myCar.setDoors(4);
    
    myCar.displayCar();
    
    return 0;
}
```

**Output:**
```
Brand: Toyota
Speed: 120 km/h
Doors: 4
```

---

### **📝 Code Example 2: Person → Student**

```cpp
// BASE CLASS
class Person {
protected:
    string name;
    int age;
    
public:
    void setPersonDetails(string n, int a) {
        name = n;
        age = a;
    }
    
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// DERIVED CLASS
class Student : public Person {
private:
    int rollNo;
    float marks;
    
public:
    void setStudentDetails(int r, float m) {
        rollNo = r;
        marks = m;
    }
    
    void displayStudent() {
        displayPerson();  // Inherited method
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;
    s.setPersonDetails("Satyam", 22);  // Inherited
    s.setStudentDetails(101, 95.5);    // Own
    
    s.displayStudent();
    
    return 0;
}
```

---

### **🎯 Types of Inheritance:**

```
1. SINGLE: A → B
   One child, one parent

2. MULTILEVEL: A → B → C
   Child becomes parent

3. HIERARCHICAL: A → B, A → C
   One parent, multiple children

4. MULTIPLE: A, B → C
   Multiple parents, one child

5. HYBRID: Combination
```

---

### **🏢 Company Frequency:**
- **TCS:** 92% ⭐⭐⭐
- **Infosys:** 95% ⭐⭐⭐
- **Wipro:** 90% ⭐⭐⭐

---

## 📖 PILLAR 3: POLYMORPHISM ⭐⭐⭐

### **What is Polymorphism?**
> **"Many forms"** - Same name, different behaviors

### **Real-Life Example:**
```
Person 👤
├─ As Student → studies
├─ As Employee → works
└─ As Parent → cares for kids

Same person, different roles (behaviors)!
```

---

### **💡 Interview Communication:**

> "Sir, **Polymorphism** means 'many forms'. Same function name can behave differently.
> 
> **Two Types:**
> 1. **Compile-time** (Function Overloading, Operator Overloading)
> 2. **Run-time** (Function Overriding with virtual functions)
> 
> **Benefit:** Code flexibility and extensibility
> 
> Let me show examples..."

---

### **Type 1: Compile-Time Polymorphism (Function Overloading)**

### **📝 Code Example 1: Calculator**

```cpp
#include <iostream>
using namespace std;

class Calculator {
public:
    // SAME NAME, DIFFERENT PARAMETERS
    
    // Add 2 integers
    int add(int a, int b) {
        return a + b;
    }
    
    // Add 3 integers
    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    // Add 2 doubles
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    
    cout << calc.add(5, 10) << endl;        // Calls int add(int, int)
    cout << calc.add(5, 10, 15) << endl;    // Calls int add(int, int, int)
    cout << calc.add(5.5, 10.5) << endl;    // Calls double add(double, double)
    
    return 0;
}
```

**Output:**
```
15
30
16
```

---

### **Type 2: Run-Time Polymorphism (Function Overriding)**

### **📝 Code Example 2: Animal Sounds**

```cpp
#include <iostream>
using namespace std;

// BASE CLASS
class Animal {
public:
    // Virtual function (allows overriding)
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
};

// DERIVED CLASS 1
class Dog : public Animal {
public:
    // Override base class method
    void makeSound() override {
        cout << "Dog barks: Woof Woof!" << endl;
    }
};

// DERIVED CLASS 2
class Cat : public Animal {
public:
    // Override base class method
    void makeSound() override {
        cout << "Cat meows: Meow Meow!" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    animal1->makeSound();  // Dog barks: Woof Woof!
    animal2->makeSound();  // Cat meows: Meow Meow!
    
    delete animal1;
    delete animal2;
    
    return 0;
}
```

**Output:**
```
Dog barks: Woof Woof!
Cat meows: Meow Meow!
```

---

### **📝 Code Example 3: Shapes (Area Calculation)**

```cpp
class Shape {
public:
    virtual double area() {
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    double area() override {
        return length * width;
    }
};

int main() {
    Shape* s1 = new Circle(5);
    Shape* s2 = new Rectangle(4, 6);
    
    cout << "Circle area: " << s1->area() << endl;      // 78.5
    cout << "Rectangle area: " << s2->area() << endl;   // 24
    
    delete s1;
    delete s2;
    
    return 0;
}
```

---

### **🎯 Key Points:**
- ✅ **Compile-time:** Function/Operator Overloading
- ✅ **Run-time:** Virtual functions + Overriding
- ✅ Use `virtual` keyword in base class
- ✅ Use `override` keyword in derived class (optional but recommended)

---

### **🏢 Company Frequency:**
- **TCS:** 85% ⭐⭐⭐
- **Infosys:** 92% ⭐⭐⭐
- **Wipro:** 80% ⭐⭐⭐

---

## 📖 PILLAR 4: ABSTRACTION ⭐⭐⭐

### **What is Abstraction?**
> **Hiding complex implementation**, showing only **essential features**

### **Real-Life Example:**
```
TV Remote 📺
├─ Buttons: ON/OFF, Volume +/-, Channel
│  (What you see - SIMPLE)
│
└─ Internal circuits, signals, processing
   (What's hidden - COMPLEX)

You just press buttons, don't need to know HOW it works!
```

---

### **💡 Interview Communication:**

> "Sir, **Abstraction** means hiding complex implementation details and showing only necessary features.
> 
> **Achieved by:**
> - Abstract classes (with pure virtual functions)
> - Interfaces
> 
> **Difference from Encapsulation:**
> - Encapsulation = Data hiding (using access specifiers)
> - Abstraction = Implementation hiding (using abstract classes)
> 
> Let me show an example..."

---

### **📝 Code Example 1: Abstract Class**

```cpp
#include <iostream>
using namespace std;

// ABSTRACT CLASS (has pure virtual function)
class PaymentMethod {
public:
    // Pure virtual function (= 0)
    virtual void processPayment(double amount) = 0;
    
    virtual void generateReceipt() = 0;
    
    virtual ~PaymentMethod() {}  // Virtual destructor
};

// CONCRETE CLASS 1
class CreditCard : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of Rs." << amount << endl;
        cout << "Connecting to bank..." << endl;
        cout << "Payment successful!" << endl;
    }
    
    void generateReceipt() override {
        cout << "Credit Card receipt generated" << endl;
    }
};

// CONCRETE CLASS 2
class UPI : public PaymentMethod {
public:
    void processPayment(double amount) override {
        cout << "Processing UPI payment of Rs." << amount << endl;
        cout << "Sending UPI request..." << endl;
        cout << "Payment successful!" << endl;
    }
    
    void generateReceipt() override {
        cout << "UPI receipt generated" << endl;
    }
};

int main() {
    // Can't create object of abstract class
    // PaymentMethod* p = new PaymentMethod(); // ❌ ERROR!
    
    // But can use pointer to abstract class
    PaymentMethod* payment1 = new CreditCard();
    PaymentMethod* payment2 = new UPI();
    
    payment1->processPayment(1000);
    payment1->generateReceipt();
    
    cout << endl;
    
    payment2->processPayment(500);
    payment2->generateReceipt();
    
    delete payment1;
    delete payment2;
    
    return 0;
}
```

**Output:**
```
Processing credit card payment of Rs.1000
Connecting to bank...
Payment successful!
Credit Card receipt generated

Processing UPI payment of Rs.500
Sending UPI request...
Payment successful!
UPI receipt generated
```

---

### **📝 Code Example 2: Database Interface**

```cpp
// ABSTRACT CLASS (Interface)
class Database {
public:
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void executeQuery(string query) = 0;
    virtual ~Database() {}
};

// CONCRETE CLASS 1
class MySQL : public Database {
public:
    void connect() override {
        cout << "Connecting to MySQL database..." << endl;
    }
    
    void disconnect() override {
        cout << "Disconnecting from MySQL..." << endl;
    }
    
    void executeQuery(string query) override {
        cout << "Executing MySQL query: " << query << endl;
    }
};

// CONCRETE CLASS 2
class MongoDB : public Database {
public:
    void connect() override {
        cout << "Connecting to MongoDB..." << endl;
    }
    
    void disconnect() override {
        cout << "Disconnecting from MongoDB..." << endl;
    }
    
    void executeQuery(string query) override {
        cout << "Executing MongoDB query: " << query << endl;
    }
};

int main() {
    Database* db = new MySQL();
    
    db->connect();
    db->executeQuery("SELECT * FROM users");
    db->disconnect();
    
    delete db;
    
    return 0;
}
```

---

### **🎯 Key Points:**
- ✅ **Abstract Class:** Has at least one pure virtual function
- ✅ **Pure Virtual Function:** `virtual void func() = 0;`
- ✅ **Can't create object** of abstract class
- ✅ **Must override** pure virtual functions in derived class
- ✅ **Interface:** Abstract class with ONLY pure virtual functions

---

### **🏢 Company Frequency:**
- **TCS:** 75% ⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 70% ⭐⭐

---

## 🎯 SUMMARY - 4 PILLARS

| Pillar | Definition | Example | Keyword |
|--------|------------|---------|---------|
| **Encapsulation** | Data + Methods bundled, data hidden | Bank Account (private balance) | `private`, `public`, getters/setters |
| **Inheritance** | Child class inherits from parent | Vehicle → Car | `: public` |
| **Polymorphism** | Same name, different forms | Overloading, Overriding | `virtual`, `override` |
| **Abstraction** | Hide complex implementation | Payment methods (different ways) | `virtual func() = 0` |

---

## 💬 INTERVIEW SCRIPT

### **When asked: "Explain OOP Pillars"**

> "Sir, OOP has **4 main pillars:**
> 
> **1. Encapsulation** - Bundling data and methods together and hiding data using access specifiers. Example: Bank account with private balance.
> 
> **2. Inheritance** - One class acquiring properties of another class for code reusability. Example: Vehicle class inherited by Car class.
> 
> **3. Polymorphism** - Same function name with different behaviors. Two types: Compile-time (overloading) and Run-time (overriding with virtual functions).
> 
> **4. Abstraction** - Hiding complex implementation, showing only essential features using abstract classes and pure virtual functions.
> 
> Would you like me to explain any of these in detail with code examples?"

---

## 🏢 COMPANY-WISE FOCUS

### **TCS:**
- Focus on **definitions** and **real-life examples**
- All 4 pillars (equal importance)
- Simple code examples

### **Infosys:**
- Focus on **virtual functions** (polymorphism)
- **Abstract classes** (abstraction)
- **Difference** questions (encapsulation vs abstraction)

### **Wipro:**
- Focus on **basic concepts**
- **Inheritance types**
- **Simple examples**

---

## 💯 FINAL CHECKLIST

```
□ Can explain all 4 pillars in 2 minutes
□ Know difference: Encapsulation vs Abstraction
□ Can write code for each pillar
□ Know real-life examples for each
□ Understand virtual functions
□ Know inheritance types
□ Can explain polymorphism types
```

---

**You've mastered OOPs Fundamentals!** ✅

**Next:** Check `Interview-Questions/TOP-15-QUESTIONS.md` for specific questions! 🚀

**All the best, Satyam!** 💪
