## 2. Functions and Scope in C++

---

### a. Function Basics

- **Definition:** A function is a reusable block of code that performs a specific task.
- **Syntax:**
  ```cpp
  return_type function_name(parameter_list) {
      // function body
      return value; // if not void
  }
  ```
- **Example:**
  ```cpp
  int add(int a, int b) {
      return a + b;
  }
  ```

---

### b. Function Declaration vs. Definition

- **Declaration:** Tells the compiler about the function’s name, return type, and parameters.
  ```cpp
  int add(int, int); // Declaration
  ```
- **Definition:** Provides the actual body of the function.
  ```cpp
  int add(int a, int b) { return a + b; } // Definition
  ```

---

### c. Function Parameters

- **Pass by Value:**  
  The function gets a copy of the argument. Changes inside the function do not affect the original variable.
  ```cpp
  void foo(int x) { x = 10; } // Original variable unchanged
  ```
- **Pass by Reference (`&`):**  
  The function can modify the original variable.
  ```cpp
  void foo(int &x) { x = 10; } // Original variable changed
  ```
- **Pass by Const Reference (`const &`):**  
  The function gets a reference but cannot modify the original variable. Efficient for large objects (like vectors).
  ```cpp
  void printVector(const vector<int>& v) { /* ... */ }
  ```

---

### d. Default Arguments

- You can provide default values for parameters.
  ```cpp
  int add(int a, int b = 5) { return a + b; }
  // add(3) returns 8, add(3, 4) returns 7
  ```

---

### e. Function Overloading

- You can define multiple functions with the same name but different parameter lists.
  ```cpp
  int add(int a, int b) { return a + b; }
  double add(double a, double b) { return a + b; }
  ```

---

### f. Scope

- **Local Scope:**  
  Variables declared inside a function/block are accessible only within that function/block.
  ```cpp
  void foo() {
      int x = 5; // x is local to foo
  }
  ```
- **Global Scope:**  
  Variables declared outside all functions are accessible everywhere in the file (avoid unless necessary).
  ```cpp
  int g = 10;
  void foo() { cout << g; }
  ```
- **Block Scope:**  
  Variables declared inside `{}` are accessible only within those braces.

---

### g. Lifetime

- **Local variables:** Created when the function is called, destroyed when it ends.
- **Static variables:** Retain their value between function calls.
  ```cpp
  void foo() {
      static int cnt = 0;
      cnt++;
      cout << cnt << endl;
  }
  // Each call to foo() will increment cnt, not reset it.
  ```

---

### h. Inline Functions

- Suggests to the compiler to replace the function call with the function code (for small functions).
  ```cpp
  inline int square(int x) { return x * x; }
  ```

---

### i. Lambda Functions (C++11+)

- Anonymous functions, useful for short operations (especially with STL algorithms).
  ```cpp
  auto add = [](int a, int b) { return a + b; };
  cout << add(2, 3); // 5
  ```

---

### j. Recursion

- A function that calls itself.
  ```cpp
  int factorial(int n) {
      if(n == 0) return 1;
      return n * factorial(n-1);
  }
  ```

---

### k. Best Practices

- Use `const &` for large objects to avoid unnecessary copying.
- Keep functions short and focused on a single task.
- Avoid using global variables unless necessary.
- Prefer passing by value for small data types (int, char, double).
- Use meaningful function and parameter names.

---
