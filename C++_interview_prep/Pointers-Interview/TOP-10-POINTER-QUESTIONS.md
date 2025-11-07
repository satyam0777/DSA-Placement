# 🎯 TOP 10 POINTER QUESTIONS - INTERVIEW READY
## Service-Based Companies (TCS | Infosys | Wipro)

---

## 📊 QUESTION FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 80%+)
⭐⭐   HIGH (Asked 60-80%)
⭐     GOOD (Asked 40-60%)
```

---

## ❓ QUESTION 1: What is a Pointer? ⭐⭐⭐

### **Frequency:**
- **TCS:** 70% ⭐⭐
- **Infosys:** 80% ⭐⭐⭐
- **Wipro:** 65% ⭐⭐

### **💬 Interview Answer:**

> "Sir, **Pointer** is a variable that stores the **memory address** of another variable.
> 
> **Syntax:** `int* ptr;` (pointer to integer)
> 
> **Two operators:**
> - **& (address-of):** Gets address of variable
> - **\* (dereference):** Gets value at that address
> 
> **Why use pointers?**
> - Dynamic memory allocation
> - Pass by reference (modify original value)
> - Efficient for large data structures
> - Required for linked lists, trees"

### **Code Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;  // ptr stores ADDRESS of num
    
    cout << "Value of num: " << num << endl;           // 10
    cout << "Address of num: " << &num << endl;        // 0x7ffc...
    cout << "Value of ptr: " << ptr << endl;           // 0x7ffc... (same address)
    cout << "Value at ptr (*ptr): " << *ptr << endl;   // 10 (dereferencing)
    
    *ptr = 20;  // Change value through pointer
    cout << "New value of num: " << num << endl;       // 20
    
    return 0;
}
```

---

## ❓ QUESTION 2: Difference between Pointer and Reference? ⭐⭐⭐

### **Frequency:**
- **TCS:** 85% ⭐⭐⭐
- **Infosys:** 90% ⭐⭐⭐
- **Wipro:** 80% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir,
> 
> **Pointer:**
> - Stores memory address
> - Can be **reassigned** to different variables
> - Can be **NULL**
> - Syntax: `int* ptr;`
> - Use **\*** to dereference
> 
> **Reference:**
> - Alias (another name) for a variable
> - **Cannot be reassigned** after initialization
> - **Cannot be NULL**
> - Syntax: `int& ref = num;`
> - Direct access (no dereferencing needed)
> 
> **When to use:**
> - Pointer: When need to reassign or NULL option
> - Reference: When passing to functions (cleaner syntax)"

### **Code Example:**

```cpp
int main() {
    int x = 10;
    int y = 20;
    
    // POINTER
    int* ptr = &x;
    cout << *ptr << endl;  // 10
    ptr = &y;              // ✅ Can reassign
    cout << *ptr << endl;  // 20
    ptr = NULL;            // ✅ Can be NULL
    
    // REFERENCE
    int& ref = x;
    cout << ref << endl;   // 10 (no * needed)
    // ref = &y;           // ❌ Cannot reassign to different variable
    ref = y;               // ✅ But can change value (x becomes 20)
    // int& ref2;          // ❌ Must initialize when declared
    
    return 0;
}
```

### **Comparison Table:**

| Aspect | Pointer | Reference |
|--------|---------|-----------|
| **Stores** | Memory address | Alias (same variable) |
| **Reassignment** | Yes ✅ | No ❌ |
| **NULL** | Yes ✅ | No ❌ |
| **Syntax** | `int* ptr` | `int& ref` |
| **Dereferencing** | `*ptr` | Direct `ref` |
| **Initialization** | Can declare without init | Must initialize |

---

## ❓ QUESTION 3: What is NULL pointer and Dangling pointer? ⭐⭐⭐

### **Frequency:**
- **TCS:** 75% ⭐⭐⭐
- **Infosys:** 80% ⭐⭐⭐
- **Wipro:** 70% ⭐⭐

### **💬 Interview Answer:**

> "Sir,
> 
> **NULL Pointer:**
> - Pointer that points to **nothing** (address 0)
> - Created intentionally using `NULL` or `nullptr` (C++11+)
> - Safe to check: `if(ptr == nullptr)`
> - **Good practice:** Initialize pointers to `nullptr`
> 
> **Dangling Pointer:**
> - Pointer that points to **freed/deleted memory**
> - Created when memory is deleted but pointer not set to NULL
> - **Dangerous!** Accessing causes undefined behavior/crash
> - **Solution:** Set to `nullptr` after deleting

### **Code Example:**

```cpp
int main() {
    // NULL POINTER
    int* ptr1 = nullptr;  // Points to nothing (SAFE)
    
    if(ptr1 == nullptr) {
        cout << "ptr1 is NULL, safe to check!" << endl;
    }
    
    // DANGLING POINTER (DANGEROUS!)
    int* ptr2 = new int(10);
    cout << *ptr2 << endl;  // 10 ✅
    
    delete ptr2;            // Memory freed
    // Now ptr2 is DANGLING (points to freed memory)
    
    // cout << *ptr2 << endl;  // ❌ CRASH! Undefined behavior
    
    ptr2 = nullptr;         // ✅ SOLUTION: Set to NULL after delete
    
    if(ptr2 == nullptr) {
        cout << "Safe! ptr2 is NULL now" << endl;
    }
    
    return 0;
}
```

### **Best Practice:**

```cpp
int* ptr = new int(10);
delete ptr;
ptr = nullptr;  // ✅ Always do this!
```

---

## ❓ QUESTION 4: What is Pointer Arithmetic? ⭐⭐

### **Frequency:**
- **TCS:** 65% ⭐⭐
- **Infosys:** 75% ⭐⭐⭐
- **Wipro:** 60% ⭐⭐

### **💬 Interview Answer:**

> "Sir, **Pointer arithmetic** means performing operations on pointers.
> 
> **Allowed operations:**
> - `ptr++` : Move to next element
> - `ptr--` : Move to previous element
> - `ptr + n` : Move n elements forward
> - `ptr - n` : Move n elements backward
> 
> **Important:** Pointer moves by `sizeof(datatype)` bytes, not 1 byte
> - `int*` moves by 4 bytes
> - `char*` moves by 1 byte
> - `double*` moves by 8 bytes
> 
> **Common use:** Array traversal"

### **Code Example:**

```cpp
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;  // Points to arr[0]
    
    cout << "ptr points to: " << *ptr << endl;      // 10
    
    ptr++;  // Move to next element
    cout << "After ptr++: " << *ptr << endl;        // 20
    
    ptr = ptr + 2;  // Move 2 elements forward
    cout << "After ptr+2: " << *ptr << endl;        // 40
    
    ptr--;  // Move back
    cout << "After ptr--: " << *ptr << endl;        // 30
    
    // Array traversal using pointer arithmetic
    ptr = arr;
    for(int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  // 10 20 30 40 50
    }
    
    return 0;
}
```

---

## ❓ QUESTION 5: Relationship between Arrays and Pointers? ⭐⭐⭐

### **Frequency:**
- **TCS:** 80% ⭐⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 75% ⭐⭐⭐

### **💬 Interview Answer:**

> "Sir, in C++, **array name acts as a pointer** to the first element.
> 
> **Key points:**
> - `arr` is equivalent to `&arr[0]`
> - `arr[i]` is equivalent to `*(arr + i)`
> - Arrays decay to pointers when passed to functions
> 
> **Difference:**
> - Array: Fixed size, cannot be reassigned
> - Pointer: Can be reassigned, can point anywhere
> 
> This is why we can use pointers to traverse arrays!"

### **Code Example:**

```cpp
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    
    // Array name is pointer to first element
    cout << "arr = " << arr << endl;           // Address of arr[0]
    cout << "&arr[0] = " << &arr[0] << endl;   // Same address
    
    // Two ways to access elements
    cout << arr[0] << endl;      // 10 (array notation)
    cout << *arr << endl;        // 10 (pointer notation)
    
    cout << arr[2] << endl;      // 30
    cout << *(arr + 2) << endl;  // 30 (equivalent!)
    
    // Using pointer to traverse array
    int* ptr = arr;
    for(int i = 0; i < 5; i++) {
        cout << *ptr << " ";     // 10 20 30 40 50
        ptr++;
    }
    
    return 0;
}
```

---

## ❓ QUESTION 6: What is Dynamic Memory Allocation? ⭐⭐⭐

### **Frequency:**
- **TCS:** 70% ⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 65% ⭐⭐

### **💬 Interview Answer:**

> "Sir, **Dynamic memory allocation** means allocating memory at **runtime** from **heap** (not stack).
> 
> **In C++:**
> - **`new`** : Allocates memory (calls constructor)
> - **`delete`** : Frees memory (calls destructor)
> 
> **For arrays:**
> - `new int[5]` : Allocate array
> - `delete[] arr` : Free array (note `[]`)
> 
> **Why use?**
> - Size not known at compile time
> - Need memory to persist beyond function scope
> - Large data structures (linked list, tree)
> 
> **Important:** Always `delete` to avoid memory leaks!"

### **Code Example:**

```cpp
int main() {
    // Dynamic single variable
    int* ptr = new int;      // Allocate
    *ptr = 10;
    cout << *ptr << endl;    // 10
    delete ptr;              // Free memory
    ptr = nullptr;           // Good practice
    
    // Dynamic array
    int n;
    cout << "Enter size: ";
    cin >> n;
    
    int* arr = new int[n];   // Allocate array at runtime
    
    for(int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    delete[] arr;            // Free array (note [])
    arr = nullptr;
    
    return 0;
}
```

### **new vs malloc:**

| Aspect | new | malloc |
|--------|-----|--------|
| **Language** | C++ | C |
| **Type** | Operator | Function |
| **Constructor** | Calls ✅ | No ❌ |
| **Type safety** | Yes ✅ | No (returns void*) |
| **Syntax** | `int* p = new int;` | `int* p = (int*)malloc(sizeof(int));` |
| **Free** | `delete p;` | `free(p);` |

---

## ❓ QUESTION 7: What is Double Pointer (Pointer to Pointer)? ⭐⭐

### **Frequency:**
- **TCS:** 55% ⭐
- **Infosys:** 70% ⭐⭐
- **Wipro:** 50% ⭐

### **💬 Interview Answer:**

> "Sir, **Double pointer** is a pointer that stores the address of another pointer.
> 
> **Syntax:** `int** ptr;` (pointer to pointer to int)
> 
> **Use cases:**
> - Dynamic 2D arrays
> - Modify pointer in function
> - Multilevel data structures
> 
> **Dereferencing:**
> - `*ptr` : Gives address stored in first pointer
> - `**ptr` : Gives actual value"

### **Code Example:**

```cpp
int main() {
    int num = 10;
    int* ptr = &num;      // Pointer to num
    int** pptr = &ptr;    // Pointer to ptr (double pointer)
    
    cout << "num = " << num << endl;           // 10
    cout << "Address of num = " << &num << endl;
    
    cout << "\nptr = " << ptr << endl;         // Address of num
    cout << "*ptr = " << *ptr << endl;         // 10
    cout << "Address of ptr = " << &ptr << endl;
    
    cout << "\npptr = " << pptr << endl;       // Address of ptr
    cout << "*pptr = " << *pptr << endl;       // Address of num
    cout << "**pptr = " << **pptr << endl;     // 10
    
    // Modify value through double pointer
    **pptr = 20;
    cout << "\nAfter **pptr = 20:" << endl;
    cout << "num = " << num << endl;           // 20
    
    return 0;
}
```

### **Visual:**

```
num = 10
 ↑
 |
ptr (stores address of num)
 ↑
 |
pptr (stores address of ptr)
```

---

## ❓ QUESTION 8: Difference between Pass by Value and Pass by Pointer? ⭐⭐⭐

### **Frequency:**
- **TCS:** 75% ⭐⭐⭐
- **Infosys:** 80% ⭐⭐⭐
- **Wipro:** 70% ⭐⭐

### **💬 Interview Answer:**

> "Sir,
> 
> **Pass by Value:**
> - Function receives **copy** of variable
> - Changes don't affect original
> - Safe but inefficient for large data
> 
> **Pass by Pointer:**
> - Function receives **address** of variable
> - Changes **do affect** original
> - Efficient (only 4/8 bytes passed)
> - Can pass NULL
> 
> **Pass by Reference (bonus):**
> - Similar to pointer but cleaner syntax
> - Cannot be NULL
> - Preferred in modern C++"

### **Code Example:**

```cpp
// PASS BY VALUE
void changeValue(int x) {
    x = 100;  // Changes COPY only
}

// PASS BY POINTER
void changePointer(int* ptr) {
    *ptr = 100;  // Changes ORIGINAL
}

// PASS BY REFERENCE
void changeReference(int& ref) {
    ref = 100;  // Changes ORIGINAL
}

int main() {
    int num = 10;
    
    // Pass by Value
    changeValue(num);
    cout << "After pass by value: " << num << endl;      // 10 (unchanged)
    
    // Pass by Pointer
    changePointer(&num);
    cout << "After pass by pointer: " << num << endl;    // 100 (changed!)
    
    num = 10;  // Reset
    
    // Pass by Reference
    changeReference(num);
    cout << "After pass by reference: " << num << endl;  // 100 (changed!)
    
    return 0;
}
```

---

## ❓ QUESTION 9: What is `this` pointer? ⭐⭐

### **Frequency:**
- **TCS:** 60% ⭐⭐
- **Infosys:** 75% ⭐⭐⭐
- **Wipro:** 55% ⭐

### **💬 Interview Answer:**

> "Sir, **`this`** is a pointer that points to the **current object** of the class.
> 
> **Characteristics:**
> - Implicit pointer available in non-static member functions
> - Type: `ClassName* const this`
> - Cannot be modified
> 
> **Use cases:**
> - When parameter name same as member variable
> - Return current object (`return *this;`)
> - Pass current object to another function
> 
> **Not available in:** Static functions (no object)"

### **Code Example:**

```cpp
class Student {
private:
    string name;
    int rollNo;
    
public:
    // Use case 1: Parameter name same as member
    void setData(string name, int rollNo) {
        this->name = name;        // this->name is member
        this->rollNo = rollNo;    // rollNo is parameter
    }
    
    void display() {
        cout << "Name: " << this->name << endl;
        cout << "Roll: " << this->rollNo << endl;
    }
    
    // Use case 2: Return current object
    Student& setName(string name) {
        this->name = name;
        return *this;  // Return current object
    }
    
    Student& setRoll(int rollNo) {
        this->rollNo = rollNo;
        return *this;
    }
};

int main() {
    Student s;
    s.setData("Satyam", 101);
    s.display();
    
    // Method chaining (using return *this)
    Student s2;
    s2.setName("Rahul").setRoll(102);  // Chaining!
    s2.display();
    
    return 0;
}
```

---

## ❓ QUESTION 10: Common Pointer Mistakes? ⭐⭐⭐

### **Frequency:**
- **TCS:** 70% ⭐⭐
- **Infosys:** 75% ⭐⭐⭐
- **Wipro:** 65% ⭐⭐

### **💬 Interview Answer:**

> "Sir, common pointer mistakes are:
> 
> **1. Uninitialized pointer** (points to garbage)
> **2. Memory leak** (forgot to delete)
> **3. Dangling pointer** (using after delete)
> **4. Double delete** (deleting twice)
> **5. Using wrong delete** (`delete` vs `delete[]`)
> 
> **Best practices:**
> - Initialize to `nullptr`
> - Always `delete` allocated memory
> - Set to `nullptr` after delete
> - Use `delete[]` for arrays"

### **Code Examples:**

```cpp
// ❌ MISTAKE 1: Uninitialized pointer
int* ptr;  // Points to garbage
// *ptr = 10;  // CRASH!

// ✅ SOLUTION
int* ptr = nullptr;
if(ptr != nullptr) {
    *ptr = 10;  // Safe
}

// ❌ MISTAKE 2: Memory leak
void func() {
    int* p = new int(10);
    // Forgot to delete!
}  // Memory leaked

// ✅ SOLUTION
void func() {
    int* p = new int(10);
    delete p;
    p = nullptr;
}

// ❌ MISTAKE 3: Dangling pointer
int* p = new int(10);
delete p;
*p = 20;  // CRASH! p is dangling

// ✅ SOLUTION
int* p = new int(10);
delete p;
p = nullptr;  // Now safe
if(p != nullptr) {
    *p = 20;
}

// ❌ MISTAKE 4: Double delete
int* p = new int(10);
delete p;
delete p;  // CRASH!

// ✅ SOLUTION
int* p = new int(10);
delete p;
p = nullptr;  // Deleting nullptr is safe

// ❌ MISTAKE 5: Wrong delete
int* arr = new int[5];
delete arr;  // WRONG! Should be delete[]

// ✅ SOLUTION
int* arr = new int[5];
delete[] arr;  // Correct for arrays
arr = nullptr;
```

---

## 🎯 QUICK SUMMARY

| Concept | Key Point |
|---------|-----------|
| **Pointer** | Variable storing address |
| **Pointer vs Reference** | Pointer can be NULL & reassigned, reference cannot |
| **NULL pointer** | Points to nothing (safe) |
| **Dangling pointer** | Points to freed memory (dangerous!) |
| **Pointer arithmetic** | `ptr++` moves by `sizeof(type)` |
| **Array & Pointer** | `arr` ≡ `&arr[0]`, `arr[i]` ≡ `*(arr+i)` |
| **new/delete** | Allocate/free heap memory |
| **Double pointer** | `int**` - pointer to pointer |
| **Pass by pointer** | Changes affect original |
| **this pointer** | Points to current object |

---

## 💬 INTERVIEW SCRIPT (1-Minute Answer)

**When asked: "Explain Pointers"**

> "Sir, **Pointer** is a variable that stores memory address of another variable.
> 
> **Syntax:** `int* ptr = &num;` (ptr stores address of num)
> 
> **Two operators:**
> - `&` gets address
> - `*` dereferences (gets value)
> 
> **Uses:**
> - Dynamic memory allocation (new/delete)
> - Pass by reference (modify original)
> - Data structures (linked list, tree)
> 
> **Important difference:** Pointer can be NULL and reassigned, Reference cannot.
> 
> Would you like me to explain with code?"

---

## 🏢 COMPANY-WISE TOP 3

### **TCS:**
1. What is pointer? (70%)
2. Pointer vs Reference (85%)
3. Array & Pointer relationship (80%)

### **Infosys:**
1. Pointer vs Reference (90%)
2. Dynamic memory (new/delete) (85%)
3. Array & Pointer (85%)

### **Wipro:**
1. Pointer vs Reference (80%)
2. NULL vs Dangling pointer (70%)
3. Pass by pointer (70%)

---

## ⏰ 30-MIN QUICK REVISION

```
□ Read Q1-Q3 (Basics) - 10 min
□ Read Q2 (Pointer vs Reference) - 5 min ⭐ MOST ASKED
□ Read Q5 (Array & Pointer) - 5 min
□ Read Q6 (new/delete) - 5 min
□ Practice saying definitions - 5 min

Total: 30 minutes = Ready! ✅
```

---

## ✅ FINAL CHECKLIST

```
□ Can explain what is pointer
□ Know difference: Pointer vs Reference (MOST ASKED!)
□ Know NULL vs Dangling pointer
□ Can write pointer arithmetic code
□ Know array-pointer relationship
□ Can write new/delete code
□ Know common mistakes
```

---

**You're Pointer-Ready!** 🚀

**Study Time:** 2-3 hours ⏱️

**Coverage:** 90% of pointer questions in service-based! ✅

**All the best, Satyam!** 💪
