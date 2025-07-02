## Pass by Reference vs Pass by Value in C++

---

### Pass by Value

- **How it works:**  
  The function receives a **copy** of the argument.
- **Effect:**  
  Changes made to the parameter inside the function **do not affect** the original variable.
- **Usage:**  
  Safe for small data types (int, char, double) when you don't want to modify the original.

**Example:**
```cpp
void foo(int x) {
    x = 10; // Only changes local copy
}
int main() {
    int a = 5;
    foo(a);
    // a is still 5
}
```

---

### Pass by Reference

- **How it works:**  
  The function receives a **reference** (alias) to the original variable.
- **Effect:**  
  Changes made to the parameter **do affect** the original variable.
- **Usage:**  
  Useful when you want the function to modify the argument, or to avoid copying large objects (like vectors).

**Example:**
```cpp
void foo(int &x) {
    x = 10; // Changes the original variable
}
int main() {
    int a = 5;
    foo(a);
    // a is now 10
}
```

---

### Key Differences

| Aspect             | Pass by Value                | Pass by Reference           |
|--------------------|-----------------------------|-----------------------------|
| What is passed     | Copy of the variable        | Reference to original       |
| Effect on original | No change                   | Can change original         |
| Memory             | May use more (copies data)  | More efficient for big data |
| Syntax             | `void foo(int x)`           | `void foo(int &x)`          |

---

**Tip:**  
- Use **pass by reference** (`&`) when you want to modify the argument or avoid copying large data.
- Use **pass by value** for small data types or when you want to protect the original value.

---