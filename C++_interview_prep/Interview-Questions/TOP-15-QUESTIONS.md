# TOP 15 C++ & OOPs INTERVIEW QUESTIONS

---

##  QUESTION 1: What is OOP? Explain its advantages ⭐⭐⭐

### **Frequency:**
- **TCS:** 100% ⭐⭐⭐
- **Infosys:** 100% ⭐⭐⭐
- **Wipro:** 100% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, **Object-Oriented Programming (OOP)** is a programming paradigm that uses **objects** and **classes** to organize code.
> 
> **Key Concepts:**
> - **Class:** Blueprint (template)
> - **Object:** Instance of a class
> 
> **Advantages:**
> 1. **Code Reusability** (inheritance, don't repeat code)
> 2. **Modularity** (organized in classes, easy to understand)
> 3. **Security** (data hiding through encapsulation)
> 4. **Flexibility** (polymorphism allows same interface, different implementations)
> 5. **Easy Maintenance** (changes in one place affect all)
> 
> **Example:** Instead of writing separate code for each car, we create a `Car` class and create multiple objects (Toyota, Honda, BMW) from it."

### **Code Example:**

```cpp
class Car {
public:
    string brand;
    int speed;
    
    void display() {
        cout << brand << " runs at " << speed << " km/h" << endl;
    }
};

int main() {
    Car car1;  // Object 1
    car1.brand = "Toyota";
    car1.speed = 120;
    
    Car car2;  // Object 2
    car2.brand = "Honda";
    car2.speed = 110;
    
    car1.display();  // Toyota runs at 120 km/h
    car2.display();  // Honda runs at 110 km/h
    
    return 0;
}
```

---

## ❓ QUESTION 2: What are the 4 pillars of OOP? ⭐⭐⭐

### **Frequency:**
- **TCS:** 95% ⭐⭐⭐
- **Infosys:** 98% ⭐⭐⭐
- **Wipro:** 92% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, the 4 pillars of OOP are:
> 
> **1. Encapsulation** - Bundling data and methods together and hiding data using access specifiers (private, public, protected). Example: Bank account with private balance.
> 
> **2. Inheritance** - One class acquiring properties from another class for code reusability. Example: Vehicle → Car.
> 
> **3. Polymorphism** - Same function name with different behaviors. Types: Compile-time (overloading) and Run-time (overriding).
> 
> **4. Abstraction** - Hiding complex implementation, showing only essential features using abstract classes with pure virtual functions.
> 
> **Memory Trick:** **EIPA** - Encapsulation, Inheritance, Polymorphism, Abstraction"

---

## ❓ QUESTION 3: Difference between Class and Object? ⭐⭐⭐

### **Frequency:**
- **TCS:** 95% ⭐⭐⭐
- **Infosys:** 92% ⭐⭐⭐
- **Wipro:** 90% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir,
> 
> **Class:**
> - Blueprint or template
> - Logical entity (doesn't occupy memory until object is created)
> - Defined once
> - Example: Car blueprint
> 
> **Object:**
> - Instance of a class
> - Physical entity (occupies memory)
> - Can create multiple objects from one class
> - Example: Toyota, Honda (specific cars from Car blueprint)
> 
> **Analogy:** Class = Building Blueprint, Object = Actual Building"

### **Code Example:**

```cpp
// CLASS (Blueprint)
class Student {
public:
    string name;
    int rollNo;
    
    void display() {
        cout << name << " - " << rollNo << endl;
    }
};

int main() {
    // OBJECTS (Instances)
    Student s1;  // Object 1
    s1.name = "Satyam";
    s1.rollNo = 101;
    
    Student s2;  // Object 2
    s2.name = "Rahul";
    s2.rollNo = 102;
    
    s1.display();  // Satyam - 101
    s2.display();  // Rahul - 102
    
    return 0;
}
```

---

## ❓ QUESTION 4: What is Encapsulation? Explain with example ⭐⭐⭐

### **Frequency:**
- **TCS:** 90% ⭐⭐⭐
- **Infosys:** 95% ⭐⭐⭐
- **Wipro:** 88% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, **Encapsulation** means bundling data (variables) and methods (functions) together in a class and hiding internal details using **access specifiers**.
> 
> **Three Access Specifiers:**
> - **private:** Accessible only inside class
> - **public:** Accessible everywhere
> - **protected:** Accessible in class and inherited classes
> 
> **Benefits:**
> - Data hiding (security)
> - Controlled access (getters/setters)
> - Validation (check data before setting)
> 
> **Example:** Bank account - balance is private, can only access through deposit/withdraw methods"

### **Code Example:**

```cpp
class BankAccount {
private:
    double balance;  // HIDDEN (private)
    
public:
    // Constructor
    BankAccount(double initial) {
        balance = initial;
    }
    
    // Controlled access methods
    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
        }
    }
    
    void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }
    
    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc(1000);
    
    // Can't directly access: acc.balance = 10000; ❌
    
    acc.deposit(500);        // ✅
    acc.withdraw(200);       // ✅
    cout << acc.getBalance(); // 1300
    
    return 0;
}
```

---

## ❓ QUESTION 5: What is Inheritance? Types of Inheritance? ⭐⭐⭐

### **Frequency:**
- **TCS:** 92% ⭐⭐⭐
- **Infosys:** 95% ⭐⭐⭐
- **Wipro:** 90% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, **Inheritance** is when one class (child/derived) acquires properties and methods from another class (parent/base).
> 
> **Benefits:**
> - Code reusability
> - Reduces redundancy
> - Easier maintenance
> 
> **5 Types:**
> 
> **1. Single:** A → B (one parent, one child)
> 
> **2. Multilevel:** A → B → C (chain of inheritance)
> 
> **3. Hierarchical:** A → B, A → C (one parent, multiple children)
> 
> **4. Multiple:** A, B → C (multiple parents, one child) - using virtual base classes to avoid diamond problem
> 
> **5. Hybrid:** Combination of above types"

### **Code Example (Single Inheritance):**

```cpp
// BASE CLASS (Parent)
class Vehicle {
protected:
    string brand;
    int speed;
    
public:
    void setBrand(string b) { brand = b; }
    void setSpeed(int s) { speed = s; }
    
    void display() {
        cout << "Brand: " << brand << ", Speed: " << speed << endl;
    }
};

// DERIVED CLASS (Child)
class Car : public Vehicle {
private:
    int doors;
    
public:
    void setDoors(int d) { doors = d; }
    
    void displayCar() {
        display();  // Inherited method
        cout << "Doors: " << doors << endl;
    }
};

int main() {
    Car c;
    c.setBrand("Toyota");  // Inherited
    c.setSpeed(120);       // Inherited
    c.setDoors(4);         // Own method
    
    c.displayCar();
    return 0;
}
```

---

## ❓ QUESTION 6: What is Polymorphism? Types? ⭐⭐⭐

### **Frequency:**
- **TCS:** 85% ⭐⭐⭐
- **Infosys:** 95% ⭐⭐⭐
- **Wipro:** 80% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, **Polymorphism** means 'many forms'. Same function name can behave differently based on context.
> 
> **Two Types:**
> 
> **1. Compile-time Polymorphism (Static Binding):**
> - Function Overloading (same name, different parameters)
> - Operator Overloading (redefine operators like +, -, <<)
> - Decided at **compile time**
> 
> **2. Run-time Polymorphism (Dynamic Binding):**
> - Function Overriding (using virtual functions)
> - Decided at **run time**
> - Requires inheritance + virtual keyword
> 
> **Benefit:** Code flexibility, one interface multiple implementations"

### **Code Example (Compile-time - Function Overloading):**

```cpp
class Calculator {
public:
    // Same name, different parameters
    int add(int a, int b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculator c;
    cout << c.add(5, 10) << endl;        // 15 (int, int)
    cout << c.add(5, 10, 15) << endl;    // 30 (int, int, int)
    cout << c.add(5.5, 10.5) << endl;    // 16 (double, double)
    return 0;
}
```

### **Code Example (Run-time - Function Overriding):**

```cpp
class Animal {
public:
    virtual void sound() {  // virtual keyword
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // override
        cout << "Dog barks: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows: Meow!" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    
    a1->sound();  // Dog barks: Woof!
    a2->sound();  // Cat meows: Meow!
    
    delete a1;
    delete a2;
    return 0;
}
```

---

## ❓ QUESTION 7: What is Virtual Function? ⭐⭐⭐

### **Frequency:**
- **TCS:** 75% ⭐⭐
- **Infosys:** 92% ⭐⭐⭐
- **Wipro:** 70% ⭐⭐

### **💬 Interview Answer:**

> "Sir, **Virtual function** is a function in base class declared using `virtual` keyword that can be **overridden** in derived class.
> 
> **Purpose:** Achieve run-time polymorphism (dynamic binding)
> 
> **Key Points:**
> - Use `virtual` in base class
> - Use `override` in derived class (optional but recommended)
> - Function selection happens at **run time** based on object type
> - Requires pointer/reference to base class
> 
> **Pure Virtual Function:** `virtual void func() = 0;`
> - Makes class abstract (can't create objects)
> - Must be overridden in derived class"

### **Code Example:**

```cpp
class Shape {
public:
    virtual double area() {  // Virtual function
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
    double l, w;
public:
    Rectangle(double length, double width) : l(length), w(width) {}
    
    double area() override {
        return l * w;
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

## ❓ QUESTION 8: Difference between Encapsulation and Abstraction? ⭐⭐⭐

### **Frequency:**
- **TCS:** 70% ⭐⭐
- **Infosys:** 90% ⭐⭐⭐
- **Wipro:** 65% ⭐⭐

### **💬 Interview Answer:**

> "Sir, both are different concepts:
> 
> **Encapsulation:**
> - **Data hiding** (wrapping data and methods together)
> - Achieved using **access specifiers** (private, public, protected)
> - **How:** Use getters/setters for controlled access
> - **Focus:** Hiding data members
> - **Example:** Bank account - balance is private
> 
> **Abstraction:**
> - **Implementation hiding** (hide complex logic)
> - Achieved using **abstract classes** and **interfaces**
> - **How:** Use pure virtual functions `virtual func() = 0;`
> - **Focus:** Hiding implementation details
> - **Example:** Car - you know accelerate(), don't know how engine works internally
> 
> **Simple:** Encapsulation = WHAT to hide (data), Abstraction = HOW to hide (implementation)"

### **Comparison Table:**

| Aspect | Encapsulation | Abstraction |
|--------|---------------|-------------|
| **Definition** | Data hiding | Implementation hiding |
| **Achieved by** | Access specifiers | Abstract classes/interfaces |
| **Focus** | Bundling data + methods | Showing essential features |
| **Example** | Private variables | Virtual functions |
| **Level** | Data level | Design level |

---

## ❓ QUESTION 9: What is Constructor? Types of Constructors? ⭐⭐⭐

### **Frequency:**
- **TCS:** 88% ⭐⭐⭐
- **Infosys:** 95% ⭐⭐⭐
- **Wipro:** 85% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, **Constructor** is a special member function with **same name as class** that is **automatically called** when object is created.
> 
> **Purpose:** Initialize object
> 
> **Characteristics:**
> - Same name as class
> - No return type (not even void)
> - Called automatically
> - Can be overloaded
> 
> **3 Types:**
> 
> **1. Default Constructor:** No parameters
> 
> **2. Parameterized Constructor:** Takes parameters
> 
> **3. Copy Constructor:** Creates object by copying another object"

### **Code Example:**

```cpp
class Student {
private:
    string name;
    int rollNo;
    
public:
    // 1. DEFAULT CONSTRUCTOR
    Student() {
        name = "Unknown";
        rollNo = 0;
        cout << "Default constructor called" << endl;
    }
    
    // 2. PARAMETERIZED CONSTRUCTOR
    Student(string n, int r) {
        name = n;
        rollNo = r;
        cout << "Parameterized constructor called" << endl;
    }
    
    // 3. COPY CONSTRUCTOR
    Student(const Student &s) {
        name = s.name;
        rollNo = s.rollNo;
        cout << "Copy constructor called" << endl;
    }
    
    void display() {
        cout << "Name: " << name << ", Roll: " << rollNo << endl;
    }
};

int main() {
    Student s1;                    // Default
    Student s2("Satyam", 101);     // Parameterized
    Student s3 = s2;               // Copy
    
    s1.display();  // Unknown, 0
    s2.display();  // Satyam, 101
    s3.display();  // Satyam, 101
    
    return 0;
}
```

---

## ❓ QUESTION 10: What is Destructor? ⭐⭐

### **Frequency:**
- **TCS:** 75% ⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 70% ⭐⭐

### **💬 Interview Answer:**

> "Sir, **Destructor** is a special member function that is **automatically called** when object is **destroyed** (goes out of scope or deleted).
> 
> **Purpose:** Clean up resources (free memory, close files, etc.)
> 
> **Characteristics:**
> - Same name as class with **~ (tilde)** prefix
> - No return type, no parameters
> - Only **one destructor** per class (can't be overloaded)
> - Called automatically
> - Called in **reverse order** of construction
> 
> **Use case:** When using dynamic memory allocation (new/delete)"

### **Code Example:**

```cpp
class Demo {
private:
    int* data;
    
public:
    // Constructor
    Demo(int val) {
        data = new int;  // Dynamic allocation
        *data = val;
        cout << "Constructor called, value = " << *data << endl;
    }
    
    // Destructor
    ~Demo() {
        cout << "Destructor called, value = " << *data << endl;
        delete data;  // Free memory
    }
    
    void display() {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    Demo d1(10);
    d1.display();
    
    Demo d2(20);
    d2.display();
    
    // Destructors called automatically when objects go out of scope
    // Order: d2 destroyed first, then d1 (reverse order)
    
    return 0;
}

/* Output:
Constructor called, value = 10
Value: 10
Constructor called, value = 20
Value: 20
Destructor called, value = 20
Destructor called, value = 10
*/
```

---

## ❓ QUESTION 11: Difference between Structure and Class? ⭐⭐

### **Frequency:**
- **TCS:** 70% ⭐⭐
- **Infosys:** 75% ⭐⭐
- **Wipro:** 65% ⭐⭐

### **💬 Interview Answer:**

> "Sir, in C++, both are almost same except:
> 
> **Structure:**
> - Members are **public by default**
> - Used for **data grouping**
> - Syntax: `struct Student { ... };`
> - Traditionally used for simple data (no methods)
> 
> **Class:**
> - Members are **private by default**
> - Used for **data + behavior** (OOP)
> - Syntax: `class Student { ... };`
> - Used for complex objects with encapsulation
> 
> **Main Difference:** Default access specifier
> 
> **In Practice:** Use `struct` for plain data, `class` for OOP with methods and encapsulation"

### **Code Example:**

```cpp
// STRUCTURE - public by default
struct Point {
    int x;  // public by default
    int y;  // public by default
};

// CLASS - private by default
class Rectangle {
    int length;  // private by default
    int width;   // private by default
    
public:
    void setDimensions(int l, int w) {
        length = l;
        width = w;
    }
    
    int area() {
        return length * width;
    }
};

int main() {
    Point p;
    p.x = 10;  // ✅ Direct access (public)
    p.y = 20;  // ✅
    
    Rectangle r;
    // r.length = 5;  // ❌ ERROR (private)
    r.setDimensions(5, 10);  // ✅ Use method
    
    return 0;
}
```

---

## ❓ QUESTION 12: What is Friend Function? ⭐⭐

### **Frequency:**
- **TCS:** 60% ⭐
- **Infosys:** 75% ⭐⭐
- **Wipro:** 55% ⭐

### **💬 Interview Answer:**

> "Sir, **Friend function** is a function that is **not a member** of a class but can **access private and protected members** of that class.
> 
> **Declared using:** `friend` keyword inside class
> 
> **Key Points:**
> - Not a member function (no `this` pointer)
> - Can access private/protected members
> - Called like normal function (not with object)
> - Breaks encapsulation (use carefully!)
> 
> **Use case:** When you need external function to access private data (e.g., operator overloading for <<, >>)"

### **Code Example:**

```cpp
class Box {
private:
    int length;
    
public:
    Box(int l) : length(l) {}
    
    // Declare friend function
    friend void printLength(Box b);
};

// Friend function definition (outside class)
void printLength(Box b) {
    // Can access private member!
    cout << "Length: " << b.length << endl;
}

int main() {
    Box b(10);
    
    // Call friend function (like normal function)
    printLength(b);  // Length: 10
    
    return 0;
}
```

---

## ❓ QUESTION 13: Difference between Public, Private, Protected? ⭐⭐⭐

### **Frequency:**
- **TCS:** 80% ⭐⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 75% ⭐⭐

### **💬 Interview Answer:**

> "Sir, these are **access specifiers** that control visibility of class members:
> 
> **1. Public:**
> - Accessible **everywhere**
> - Inside class, outside class, in derived classes
> - Use for methods (interface)
> 
> **2. Private:**
> - Accessible **only inside the same class**
> - Not accessible in derived classes
> - Use for data members (data hiding)
> 
> **3. Protected:**
> - Accessible in **same class and derived classes**
> - Not accessible outside classes
> - Use when want derived class to access but not outside
> 
> **Summary:** public > protected > private (decreasing accessibility)"

### **Code Example:**

```cpp
class Parent {
public:
    int pub = 1;     // Accessible everywhere
    
protected:
    int prot = 2;    // Accessible in this class and child classes
    
private:
    int priv = 3;    // Accessible only in this class
    
    void display() {
        cout << pub << " " << prot << " " << priv << endl;  // ✅ All accessible
    }
};

class Child : public Parent {
public:
    void show() {
        cout << pub << endl;   // ✅ Public accessible
        cout << prot << endl;  // ✅ Protected accessible
        // cout << priv << endl;  // ❌ Private NOT accessible
    }
};

int main() {
    Parent p;
    cout << p.pub << endl;   // ✅ Public accessible
    // cout << p.prot << endl;  // ❌ Protected NOT accessible
    // cout << p.priv << endl;  // ❌ Private NOT accessible
    
    return 0;
}
```

---

## ❓ QUESTION 14: What is Abstract Class? ⭐⭐

### **Frequency:**
- **TCS:** 65% ⭐⭐
- **Infosys:** 80% ⭐⭐⭐
- **Wipro:** 60% ⭐

### **💬 Interview Answer:**

> "Sir, **Abstract class** is a class that has **at least one pure virtual function**.
> 
> **Pure Virtual Function:** `virtual void func() = 0;`
> 
> **Key Points:**
> - **Cannot create object** of abstract class
> - Used as **base class** for other classes
> - Derived classes **must override** pure virtual functions
> - Used to achieve **abstraction** (hide implementation)
> 
> **Purpose:** Define interface that derived classes must implement
> 
> **Interface:** Abstract class with **only pure virtual functions** (no data members)"

### **Code Example:**

```cpp
// ABSTRACT CLASS
class Shape {
public:
    // Pure virtual function
    virtual double area() = 0;
    virtual void display() = 0;
    
    virtual ~Shape() {}  // Virtual destructor
};

// CONCRETE CLASS 1
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    // Must override pure virtual functions
    double area() override {
        return 3.14 * radius * radius;
    }
    
    void display() override {
        cout << "Circle area: " << area() << endl;
    }
};

// CONCRETE CLASS 2
class Rectangle : public Shape {
private:
    double l, w;
    
public:
    Rectangle(double length, double width) : l(length), w(width) {}
    
    double area() override {
        return l * w;
    }
    
    void display() override {
        cout << "Rectangle area: " << area() << endl;
    }
};

int main() {
    // Shape s;  // ❌ ERROR! Can't create object of abstract class
    
    Shape* s1 = new Circle(5);      // ✅ Pointer to abstract class
    Shape* s2 = new Rectangle(4, 6); // ✅
    
    s1->display();  // Circle area: 78.5
    s2->display();  // Rectangle area: 24
    
    delete s1;
    delete s2;
    
    return 0;
}
```

---

## ❓ QUESTION 15: Difference between Compile-time and Run-time Polymorphism? ⭐⭐

### **Frequency:**
- **TCS:** 70% ⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 65% ⭐⭐

### **💬 Interview Answer:**

> "Sir,
> 
> **Compile-time Polymorphism (Static Binding):**
> - Achieved by **function overloading** and **operator overloading**
> - Function call resolved at **compile time**
> - **Faster** (no overhead)
> - Also called **Early Binding**
> - Example: Multiple `add()` functions with different parameters
> 
> **Run-time Polymorphism (Dynamic Binding):**
> - Achieved by **function overriding** (virtual functions)
> - Function call resolved at **run time**
> - **Slower** (vtable lookup overhead)
> - Also called **Late Binding**
> - Requires inheritance + virtual keyword
> - Example: Animal → Dog, Cat with `sound()` overridden"

### **Comparison Table:**

| Aspect | Compile-time | Run-time |
|--------|--------------|----------|
| **Achieved by** | Overloading | Overriding (virtual) |
| **Binding** | Early (compile time) | Late (run time) |
| **Speed** | Faster | Slower |
| **Flexibility** | Less | More |
| **Keyword** | None | `virtual` |
| **Example** | `add(int, int)`, `add(double, double)` | `Animal::sound()`, `Dog::sound()` |

### **Code Example:**

```cpp
// COMPILE-TIME POLYMORPHISM
class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};

// RUN-TIME POLYMORPHISM
class Animal {
public:
    virtual void sound() { cout << "Animal sound" << endl; }
};

class Dog : public Animal {
public:
    void sound() override { cout << "Bark" << endl; }
};

int main() {
    // Compile-time
    Math m;
    cout << m.add(5, 10) << endl;      // Decided at compile time
    cout << m.add(5.5, 10.5) << endl;  // Decided at compile time
    
    // Run-time
    Animal* a = new Dog();
    a->sound();  // Decided at run time (Bark)
    
    delete a;
    return 0;
}
```

---

## 🎯 BONUS QUESTIONS (GOOD TO KNOW)

### **Q16: What is `this` pointer?**
> Pointer that points to current object. Used to refer to current object's members.

### **Q17: What is Static member?**
> Shared by all objects of class. Only one copy exists. Access using `ClassName::member`.

### **Q18: What is Operator Overloading?**
> Redefining operators (+, -, <<, etc.) for user-defined types.

### **Q19: Difference between new/delete and malloc/free?**
> `new/delete` are operators (call constructor/destructor), `malloc/free` are functions (don't call constructors).

### **Q20: What is Diamond Problem in Multiple Inheritance?**
> Ambiguity when class inherits from two classes that have common base. Solved using **virtual inheritance**.

---

## 💯 INTERVIEW DAY PREPARATION

### **30 Minutes Before Interview:**

```
□ Read all 15 questions once
□ Practice saying "4 Pillars" out loud
□ Memorize EIPA (Encapsulation, Inheritance, Polymorphism, Abstraction)
□ Review access specifiers (public, private, protected)
□ Review constructor types (default, parameterized, copy)
□ Practice virtual function example in mind
```

---

## 💬 INTERVIEW COMMUNICATION TIPS

1. **Start with definition** → Then example → Then code
2. **Use "Sir" or "Ma'am"** (respectful)
3. **Draw diagrams** if allowed (inheritance tree, class diagram)
4. **Ask "Should I explain with code?"** before writing
5. **Be confident** - you've prepared well!

---

## 🏢 COMPANY-WISE FOCUS

### **TCS (Focus on clarity):**
- All 4 pillars (Q1-Q6)
- Constructor/Destructor (Q9-Q10)
- Access specifiers (Q13)

### **Infosys (Focus on depth):**
- Virtual functions (Q7)
- Encapsulation vs Abstraction (Q8)
- Abstract class (Q14)
- Polymorphism types (Q6, Q15)

### **Wipro (Focus on basics):**
- OOP advantages (Q1)
- Class vs Object (Q3)
- Inheritance (Q5)
- Constructor (Q9)

---

## ✅ FINAL CHECKLIST

```
□ Can answer all 15 questions confidently
□ Can write code for each concept
□ Know real-life examples for all pillars
□ Memorized 4 pillars (EIPA)
□ Understand difference questions (Q8, Q11, Q13, Q15)
□ Can explain virtual functions (Q7)
```

---

**You're Interview Ready!** 🚀

**Next:** Check `CPP-OOPs-QUICK-REFERENCE.md` for last-minute revision! ⚡

**All the best, Satyam!** 💪 **You've got this!** ✨
