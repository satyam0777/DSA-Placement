# Other Important C++ Concepts for Interviews (Except OOPs)

---

## 1. Const Correctness

- Use `const` to prevent modification of variables, function parameters, and member functions.
- Improves code safety and clarity.

**Example:**
```cpp
void printVec(const vector<int>& v) { /* cannot modify v */ }
const int x = 10; // x cannot be changed
```

---

## 2. Namespaces

- Avoids name conflicts in large projects or when using libraries.
- Standard library is in the `std` namespace.

**Example:**
```cpp
namespace myspace {
    int x = 5;
}
cout << myspace::x;
```

---

## 3. Macros and Preprocessor Directives

- Use `#define` for constants or simple functions.
- Use `#include` to include libraries.

**Example:**
```cpp
#define PI 3.14159
#include <iostream>
```

---

## 4. Inline Functions

- Suggests to the compiler to replace the function call with the function code (for small, frequently called functions).

**Example:**
```cpp
inline int square(int x) { return x * x; }
```

---

## 5. Lambda Functions (C++11+)

- Anonymous functions, useful with STL algorithms.

**Example:**
```cpp
auto add = [](int a, int b) { return a + b; };
cout << add(2, 3); // 5
```

---

## 6. Enumerations (`enum`)

- User-defined type for a set of named integral constants.

**Example:**
```cpp
enum Color { RED, GREEN, BLUE };
Color c = RED;
```

---

## 7. Type Aliases (`typedef`, `using`)

- Create shorter names for types.

**Example:**
```cpp
typedef long long ll;
using vi = vector<int>;
```

---

## 8. Exception Handling

- Use `try`, `catch`, and `throw` to handle runtime errors gracefully.

**Example:**
```cpp
try {
    throw 10;
} catch(int e) {
    cout << "Exception: " << e << endl;
}
```

---

## 9. File I/O

- Read from and write to files using `ifstream` and `ofstream`.

**Example:**
```cpp
#include <fstream>
ifstream fin("input.txt");
ofstream fout("output.txt");
int x; fin >> x; fout << x;
```

---

## 10. Smart Pointers (C++11+)

- Automatic memory management: `unique_ptr`, `shared_ptr`, `weak_ptr`.

**Example:**
```cpp
#include <memory>
unique_ptr<int> p = make_unique<int>(10);
```

---

## 11. Bit Manipulation

- Efficient operations using bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`).

**Example:**
```cpp
int x = 5; // 0101
int y = x << 1; // 1010 (10)
```

---

## 12. Templates (Generic Programming)

- Write functions/classes that work with any data type.

**Example:**
```cpp
template<typename T>
T add(T a, T b) { return a + b; }
```

---

## 13. Memory Management

- Use `new` and `delete` for dynamic memory.
- Avoid memory leaks by freeing memory.

**Example:**
```cpp
int* arr = new int[5];
delete[] arr;
```

---
---

## 6. In-Depth: Copy Concepts in C++

### a. Memberwise Copy

- **What happens:**  
  For structs/classes without pointers or dynamic memory, the default copy constructor and assignment operator copy each member variable one by one.
- **Safe when:**  
  All members are value types (int, double, etc.) or STL containers (which manage their own memory).
- **Pitfall:**  
  If your class has raw pointers, memberwise copy will copy the pointer address, not the data it points to (leads to shallow copy issues).

**Example:**
```cpp
struct Point {
    int x, y;
};
Point p1 = {1, 2};
Point p2 = p1; // memberwise copy, p2.x = 1, p2.y = 2
```

---

### b. Deep Copy in Classes

- **Why needed:**  
  If your class allocates memory dynamically (e.g., with `new`), you must define a custom copy constructor and assignment operator to copy the data, not just the pointer.
- **Rule of Three/Five:**  
  If you define a custom destructor, copy constructor, or copy assignment operator, you likely need all three (and in C++11+, move constructor and move assignment too).

**Example:**
```cpp
class MyArray {
    int* data;
    int size;
public:
    MyArray(int n) : size(n) { data = new int[n]; }
    // Deep copy constructor
    MyArray(const MyArray& other) : size(other.size) {
        data = new int[size];
        for(int i = 0; i < size; i++) data[i] = other.data[i];
    }
    // Deep copy assignment operator
    MyArray& operator=(const MyArray& other) {
        if(this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for(int i = 0; i < size; i++) data[i] = other.data[i];
        }
        return *this;
    }
    ~MyArray() { delete[] data; }
};
```

---

### c. Move Semantics (C++11+)

- **Purpose:**  
  Avoid unnecessary deep copies for temporary or large objects by "moving" resources instead of copying.
- **How:**  
  Transfers ownership of resources (like dynamic memory) from one object to another, leaving the source in a valid but unspecified state.
- **Syntax:**  
  Use `std::move()` to cast an object to an rvalue reference.

**Example:**
```cpp
vector<int> v1 = {1,2,3};
vector<int> v2 = std::move(v1); // v2 now owns the data, v1 is empty
```

**Custom Move Constructor Example:**
```cpp
class MyArray {
    int* data;
    int size;
public:
    // Move constructor
    MyArray(MyArray&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    // Move assignment operator
    MyArray& operator=(MyArray&& other) noexcept {
        if(this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
    // ... (rest as before)
};
```

---

### d. Copy Elision and Return Value Optimization (RVO)

- **What is it:**  
  Modern C++ compilers often optimize away unnecessary copies when returning objects from functions (RVO).
- **Effect:**  
  You may not see copy/move constructors called when returning local objects.

**Example:**
```cpp
MyArray createArray(int n) {
    MyArray arr(n);
    // ... fill arr ...
    return arr; // RVO may eliminate copy/move
}
```

---

### e. Pitfalls and Best Practices

- **Dangling pointers:**  
  If two objects share the same pointer (shallow copy), deleting one will make the other's pointer invalid.
- **Double free:**  
  If two objects try to delete the same pointer (from shallow copy), program will crash.
- **Always:**  
  - Use STL containers (vector, string, etc.) when possible—they handle deep copy and move semantics for you.
  - For classes with raw pointers, implement the Rule of Three/Five.
  - Use `std::move` for efficiency with large/temporary objects.

---

### f. Summary Table (Expanded)

| Copy Type      | What is Copied?         | Effect on Data         | Use Case                        | Pitfall                        |
|----------------|------------------------|-----------------------|----------------------------------|--------------------------------|
| Shallow Copy   | Reference/Pointer      | Shared data           | Pointers, default object copy    | Dangling pointers, double free |
| Deep Copy      | Actual Data            | Independent data      | Arrays, custom classes           | Slower for large data          |
| Move           | Ownership of Resource  | Source is emptied     | Temporary/large objects (C++11+) | Source object is empty         |
| Memberwise     | Each member variable   | Value-by-value copy   | Structs/classes w/o pointers     | Shallow for pointer members    |


---