# Copy Concepts in C++: Shallow Copy, Deep Copy, and Related Ideas

---

## 1. Shallow Copy

- **Definition:**  
  A shallow copy copies the reference (address) to the original data, not the actual data itself.
- **Effect:**  
  Both variables point to the same memory. Changing one affects the other.
- **When it happens:**  
  - Assigning pointers: `int* p1 = p2;`
  - Default copy of objects with pointer members (unless a custom copy constructor is defined).

**Example:**
```cpp
int arr[3] = {1, 2, 3};
int* p1 = arr;
int* p2 = p1; // shallow copy
p2[0] = 10;   // arr[0] and p1[0] also become 10
```

---

## 2. Deep Copy

- **Definition:**  
  A deep copy creates a new copy of the actual data, not just the reference.
- **Effect:**  
  The original and the copy are independent. Changing one does not affect the other.
- **When to use:**  
  - When you want two independent objects/arrays.
  - Required for classes with pointer members (define a custom copy constructor and assignment operator).

**Example:**
```cpp
int arr1[3] = {1, 2, 3};
int arr2[3];
for(int i = 0; i < 3; i++) arr2[i] = arr1[i]; // deep copy
arr2[0] = 10; // arr1[0] is still 1
```

---

## 3. Copy Constructor and Assignment Operator in Classes

- **Default copy constructor:**  
  Performs shallow copy (copies member values, including pointers).
- **Custom copy constructor:**  
  Needed for deep copy (allocate new memory and copy data).

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
    ~MyArray() { delete[] data; }
};
```

---

## 4. Other Types of Copy

- **Memberwise Copy:**  
  Default behavior for structs/classes without pointers—copies each member.
- **Move Semantics (C++11+):**  
  Transfers ownership of resources (efficient for temporary objects).
  ```cpp
  vector<int> v1 = {1,2,3};
  vector<int> v2 = std::move(v1); // v1 is now empty, v2 has the data
  ```

---

## 5. Summary Table

| Copy Type      | What is Copied?         | Effect on Data         | Use Case                        |
|----------------|------------------------|-----------------------|----------------------------------|
| Shallow Copy   | Reference/Pointer      | Shared data           | Pointers, default object copy    |
| Deep Copy      | Actual Data            | Independent data      | Arrays, custom classes           |
| Move           | Ownership of Resource  | Source is emptied     | Temporary/large objects (C++11+) |

---

**Tip:**  
- Use deep copy when you need independent objects.
- For classes with dynamic memory, always define a custom copy constructor and assignment operator (Rule of Three/Five).
- Use move semantics for efficiency with large/temporary objects.

---