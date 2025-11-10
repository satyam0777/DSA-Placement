# 🔄 RECURSION - BASIC CONCEPTS
## Interview-Ready Package for Service-Based Companies

---

## 📚 WHAT IS RECURSION?

### **Simple Definition:**
> **Recursion** is when a function **calls itself** to solve a smaller version of the same problem.

### **Real-Life Analogy:**
```
Opening nested boxes:
- Open outer box
- If there's a box inside, open it (recursive call)
- Keep opening until you find the gift (base case)
```

---

## 🎯 RECURSION ANATOMY

### **Every Recursive Function Has:**

**1. Base Case (Stopping Condition):**
```cpp
if(n == 0) return 1;  // Stop recursion
```

**2. Recursive Case (Function calls itself):**
```cpp
return n * factorial(n - 1);  // Calls itself with smaller problem
```

**3. Progress Towards Base Case:**
```cpp
n → n-1 → n-2 → ... → 0  // Gets closer to base case
```

---

## 🔑 KEY CONCEPTS

### **1. Call Stack:**
```
factorial(3)
  → factorial(2)
    → factorial(1)
      → factorial(0) → returns 1
    → returns 1 * 1 = 1
  → returns 2 * 1 = 2
→ returns 3 * 2 = 6
```

### **2. Types of Recursion:**

**Head Recursion:**
```cpp
void print(int n) {
    if(n == 0) return;
    print(n - 1);      // Recursive call first
    cout << n << " ";  // Process after
}
// Output: 1 2 3 4 5
```

**Tail Recursion:**
```cpp
void print(int n) {
    if(n == 0) return;
    cout << n << " ";  // Process first
    print(n - 1);      // Recursive call last
}
// Output: 5 4 3 2 1
```

### **3. Recursion Tree:**
```
                fib(4)
              /        \
          fib(3)      fib(2)
         /     \       /    \
     fib(2)  fib(1) fib(1) fib(0)
     /   \
 fib(1) fib(0)
```

---

## 📖 PROBLEM 1: FACTORIAL ⭐⭐

**GFG | Basic Recursion**

### **Problem:**
```
Find factorial of n.
factorial(n) = n * (n-1) * (n-2) * ... * 1

Example:
Input: n = 5
Output: 120
Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Factorial** problem. I'll use **recursion**.
> 
> **Base Case:** If n is 0 or 1, factorial is 1.
> 
> **Recursive Case:** factorial(n) = n * factorial(n-1)
> 
> Each recursive call reduces the problem size by 1, eventually reaching base case.
> 
> **Time:** O(n) - n recursive calls
> **Space:** O(n) - recursion call stack depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
using namespace std;

// Recursive approach
int factorial(int n) {
    // Base case
    if(n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    // Test Case 1
    int n1 = 5;
    cout << "Factorial of " << n1 << " = " << factorial(n1) << endl;
    // Output: 120
    
    // Test Case 2
    int n2 = 0;
    cout << "Factorial of " << n2 << " = " << factorial(n2) << endl;
    // Output: 1
    
    // Test Case 3
    int n3 = 6;
    cout << "Factorial of " << n3 << " = " << factorial(n3) << endl;
    // Output: 720
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** n = 4

```
Call Stack Visualization:

factorial(4)
    → 4 * factorial(3)
        → 3 * factorial(2)
            → 2 * factorial(1)
                → return 1 (base case)
            → return 2 * 1 = 2
        → return 3 * 2 = 6
    → return 4 * 6 = 24

Step-by-step:
1. factorial(4) called
2. n=4, not base case, compute 4 * factorial(3)
3. factorial(3) called
4. n=3, not base case, compute 3 * factorial(2)
5. factorial(2) called
6. n=2, not base case, compute 2 * factorial(1)
7. factorial(1) called
8. n=1, BASE CASE, return 1
9. Back to step 6: return 2 * 1 = 2
10. Back to step 4: return 3 * 2 = 6
11. Back to step 2: return 4 * 6 = 24

Final Answer: 24 ✅
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n) | n recursive calls |
| **Space** | O(n) | Call stack depth n |

---

### **🏢 Company Frequency:**
- **TCS:** 70-75% (Very basic, often asked)
- **Infosys:** 65-70%
- **Wipro:** 70-75%

---

## 📖 PROBLEM 2: FIBONACCI NUMBER ⭐⭐⭐

**LeetCode 509 | GFG | Very Popular**

### **Problem:**
```
Find nth Fibonacci number.
F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2)

Example:
Input: n = 5
Output: 5
Explanation: F(5) = F(4) + F(3) = 3 + 2 = 5
Sequence: 0, 1, 1, 2, 3, 5, 8, 13, ...
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Fibonacci Number** problem. I'll use **recursion**.
> 
> **Base Cases:** 
> - F(0) = 0
> - F(1) = 1
> 
> **Recursive Case:** F(n) = F(n-1) + F(n-2)
> 
> Each call branches into two recursive calls, creating a binary tree of calls.
> 
> **Note:** Pure recursion has exponential time O(2^n) due to repeated calculations. For optimization, we can use memoization (Dynamic Programming).
> 
> **Time:** O(2^n) - exponential (without memoization)
> **Space:** O(n) - recursion depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
using namespace std;

// Pure Recursive approach (Exponential time)
int fibonacci(int n) {
    // Base cases
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Optimized with Memoization (for interview mention)
int fibMemo(int n, int memo[]) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    if(memo[n] != -1) return memo[n]; // Already calculated
    
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

int main() {
    // Test Case 1
    int n1 = 5;
    cout << "Fibonacci(" << n1 << ") = " << fibonacci(n1) << endl;
    // Output: 5
    
    // Test Case 2
    int n2 = 7;
    cout << "Fibonacci(" << n2 << ") = " << fibonacci(n2) << endl;
    // Output: 13
    
    // Test Case 3 - With memoization
    int n3 = 10;
    int memo[100];
    fill(memo, memo + 100, -1);
    cout << "Fibonacci(" << n3 << ") with memo = " << fibMemo(n3, memo) << endl;
    // Output: 55
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** n = 4

```
Recursion Tree:

                    fib(4)
                  /        \
              fib(3)        fib(2)
             /     \         /    \
         fib(2)  fib(1)  fib(1) fib(0)
         /   \      |       |      |
     fib(1) fib(0)  1       1      0
       |      |
       1      0

Call sequence:
1. fib(4)
2.   fib(3)
3.     fib(2)
4.       fib(1) → return 1
5.       fib(0) → return 0
6.     return 1 + 0 = 1
7.     fib(1) → return 1
8.   return 1 + 1 = 2
9.   fib(2)
10.    fib(1) → return 1
11.    fib(0) → return 0
12.  return 1 + 0 = 1
13. return 2 + 1 = 3

Final Answer: 3 ✅

Notice: fib(2) calculated twice, fib(1) calculated 3 times!
This is why pure recursion is slow.
```

---

### **⏱️ Complexity Analysis:**

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| **Pure Recursion** | O(2^n) | O(n) | Exponential, many repeated calls |
| **With Memoization** | O(n) | O(n) | Each fib(i) calculated once |

---

### **🏢 Company Frequency:**
- **TCS:** 75-80% ⭐⭐⭐
- **Infosys:** 80-85% ⭐⭐⭐
- **Wipro:** 70-75%

---

## 📖 PROBLEM 3: PRINT 1 TO N ⭐

**Basic Recursion Pattern**

### **Problem:**
```
Print numbers from 1 to n using recursion.

Example:
Input: n = 5
Output: 1 2 3 4 5
```

---

### **💡 Interview Communication Script:**

> "Sir, I'll print 1 to n using **tail recursion**.
> 
> **Base Case:** If current number > n, stop.
> 
> **Recursive Case:** Print current number, then recursively call with current+1.
> 
> This demonstrates tail recursion where processing happens before recursive call."

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
using namespace std;

// Tail recursion - print then recurse
void printTail(int current, int n) {
    // Base case
    if(current > n) return;
    
    // Print current
    cout << current << " ";
    
    // Recursive call
    printTail(current + 1, n);
}

// Head recursion - recurse then print
void printHead(int n) {
    // Base case
    if(n == 0) return;
    
    // Recursive call first
    printHead(n - 1);
    
    // Print after
    cout << n << " ";
}

int main() {
    int n = 5;
    
    cout << "Tail Recursion (1 to n): ";
    printTail(1, n);
    cout << endl;
    // Output: 1 2 3 4 5
    
    cout << "Head Recursion (1 to n): ";
    printHead(n);
    cout << endl;
    // Output: 1 2 3 4 5
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** n = 4 (Tail Recursion)

```
Call Stack:

printTail(1, 4)
    print 1
    → printTail(2, 4)
        print 2
        → printTail(3, 4)
            print 3
            → printTail(4, 4)
                print 4
                → printTail(5, 4)
                    5 > 4, return (base case)

Output: 1 2 3 4 ✅
```

---

### **⏱️ Complexity:**
- **Time:** O(n)
- **Space:** O(n) - call stack

---

## 📖 PROBLEM 4: SUM OF ARRAY ⭐⭐

**Recursion on Arrays**

### **Problem:**
```
Find sum of all array elements using recursion.

Example:
Input: arr = [1, 2, 3, 4, 5]
Output: 15
```

---

### **💡 Interview Communication Script:**

> "Sir, this is **Sum of Array** using recursion.
> 
> **Base Case:** If index reaches array size, return 0.
> 
> **Recursive Case:** Current element + sum of remaining array.
> 
> sum(arr, i) = arr[i] + sum(arr, i+1)
> 
> **Time:** O(n), **Space:** O(n)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Recursion approach
int arraySum(vector<int>& arr, int index) {
    // Base case
    if(index >= arr.size()) {
        return 0;
    }
    
    // Recursive case: current + sum of rest
    return arr[index] + arraySum(arr, index + 1);
}

// Alternative: from end
int arraySumEnd(vector<int>& arr, int n) {
    // Base case
    if(n == 0) return 0;
    
    // Recursive case
    return arr[n - 1] + arraySumEnd(arr, n - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    cout << "Sum: " << arraySum(arr, 0) << endl;
    // Output: 15
    
    cout << "Sum (from end): " << arraySumEnd(arr, arr.size()) << endl;
    // Output: 15
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arr = [2, 3, 5], index = 0

```
Call Stack:

arraySum([2,3,5], 0)
    → 2 + arraySum([2,3,5], 1)
        → 3 + arraySum([2,3,5], 2)
            → 5 + arraySum([2,3,5], 3)
                → 0 (base case: index >= size)
            → return 5 + 0 = 5
        → return 3 + 5 = 8
    → return 2 + 8 = 10

Final Answer: 10 ✅
```

---

### **🏢 Company Frequency:**
- **TCS:** 65-70%
- **Infosys:** 70-75%
- **Wipro:** 60-65%

---

## 📖 PROBLEM 5: REVERSE A STRING ⭐⭐

**Recursion on Strings**

### **Problem:**
```
Reverse a string using recursion.

Example:
Input: s = "hello"
Output: "olleh"
```

---

### **💡 Interview Communication Script:**

> "Sir, I'll reverse string using **recursion**.
> 
> **Approach:** Swap first and last characters, then recursively reverse the middle portion.
> 
> **Base Case:** If left >= right, string is reversed.
> 
> **Recursive Case:** Swap s[left] and s[right], then recurse with left+1 and right-1.
> 
> **Time:** O(n), **Space:** O(n)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Helper function
void reverseHelper(string& s, int left, int right) {
    // Base case
    if(left >= right) return;
    
    // Swap
    swap(s[left], s[right]);
    
    // Recursive call
    reverseHelper(s, left + 1, right - 1);
}

string reverseString(string s) {
    reverseHelper(s, 0, s.length() - 1);
    return s;
}

// Alternative: build reversed string
string reverseRecursive(string s) {
    // Base case
    if(s.length() == 0) return "";
    
    // Recursive case: last char + reverse of rest
    return s[s.length() - 1] + reverseRecursive(s.substr(0, s.length() - 1));
}

int main() {
    string s1 = "hello";
    cout << "Reversed: " << reverseString(s1) << endl;
    // Output: olleh
    
    string s2 = "recursion";
    cout << "Reversed: " << reverseRecursive(s2) << endl;
    // Output: noisrucer
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** s = "abc", left = 0, right = 2

```
Call Stack:

reverseHelper("abc", 0, 2)
    swap('a', 'c') → "cba"
    → reverseHelper("cba", 1, 1)
        1 >= 1, return (base case)

Final String: "cba" ✅

Visual:
"abc"
  ↓
swap a & c
  ↓
"cba"
  ↓
middle stays same
  ↓
"cba" ✅
```

---

### **⏱️ Complexity:**
- **Time:** O(n)
- **Space:** O(n) - call stack

---

## 📖 PROBLEM 6: POWER FUNCTION (x^n) ⭐⭐⭐

**LeetCode 50 | Important**

### **Problem:**
```
Calculate x raised to power n.

Example:
Input: x = 2, n = 10
Output: 1024

Input: x = 2, n = -2
Output: 0.25
```

---

### **💡 Interview Communication Script:**

> "Sir, this is **Power Function** problem. I'll use **optimized recursion**.
> 
> **Naive Approach:** x^n = x * x^(n-1), Time O(n)
> 
> **Optimized Approach:** Use divide and conquer:
> - If n is even: x^n = (x^(n/2))^2
> - If n is odd: x^n = x * (x^(n/2))^2
> 
> This reduces time to **O(log n)** by halving the problem each time.
> 
> **Handle negative:** x^(-n) = 1 / x^n
> 
> **Time:** O(log n), **Space:** O(log n)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
using namespace std;

// Optimized recursion - O(log n)
double power(double x, long long n) {
    // Base case
    if(n == 0) return 1;
    
    // Handle negative power
    if(n < 0) {
        x = 1 / x;
        n = -n;
    }
    
    // If even: x^n = (x^(n/2))^2
    if(n % 2 == 0) {
        double half = power(x, n / 2);
        return half * half;
    }
    // If odd: x^n = x * (x^(n/2))^2
    else {
        double half = power(x, n / 2);
        return x * half * half;
    }
}

// Naive approach - O(n) - for comparison
double powerNaive(double x, int n) {
    if(n == 0) return 1;
    if(n < 0) return 1 / powerNaive(x, -n);
    
    return x * powerNaive(x, n - 1);
}

int main() {
    // Test Case 1
    cout << "2^10 = " << power(2, 10) << endl;
    // Output: 1024
    
    // Test Case 2
    cout << "2^-2 = " << power(2, -2) << endl;
    // Output: 0.25
    
    // Test Case 3
    cout << "3^5 = " << power(3, 5) << endl;
    // Output: 243
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** x = 2, n = 5

```
Call Stack:

power(2, 5)
    n = 5 (odd)
    → half = power(2, 2)
        n = 2 (even)
        → half = power(2, 1)
            n = 1 (odd)
            → half = power(2, 0)
                → return 1 (base case)
            → return 2 * 1 * 1 = 2
        → return 2 * 2 = 4
    → return 2 * 4 * 4 = 32

Final Answer: 32 ✅

Why O(log n)?
5 → 2 → 1 → 0  (3 calls for n=5)
Instead of 5 calls in naive approach!
```

---

### **⏱️ Complexity Analysis:**

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| **Naive** | O(n) | O(n) | x * x^(n-1) |
| **Optimized** | O(log n) | O(log n) | Divide & conquer |

---

### **🏢 Company Frequency:**
- **TCS:** 60-65%
- **Infosys:** 70-75% ⭐⭐
- **Wipro:** 55-60%

---

## 📖 PROBLEM 7: CHECK IF ARRAY IS SORTED ⭐⭐

**Recursion Pattern**

### **Problem:**
```
Check if array is sorted in ascending order.

Example:
Input: arr = [1, 2, 3, 4, 5]
Output: true

Input: arr = [1, 3, 2, 4]
Output: false
```

---

### **💡 Interview Communication Script:**

> "Sir, I'll check if array is sorted using **recursion**.
> 
> **Base Case:** If we reach last element, array is sorted.
> 
> **Recursive Case:** Check if current element ≤ next element, AND rest of array is sorted.
> 
> **Time:** O(n), **Space:** O(n)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>& arr, int index) {
    // Base case: reached second last element
    if(index >= arr.size() - 1) {
        return true;
    }
    
    // Check current and next, AND rest is sorted
    return (arr[index] <= arr[index + 1]) && isSorted(arr, index + 1);
}

int main() {
    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Is Sorted: " << (isSorted(arr1, 0) ? "Yes" : "No") << endl;
    // Output: Yes
    
    // Test Case 2
    vector<int> arr2 = {1, 3, 2, 4};
    cout << "Is Sorted: " << (isSorted(arr2, 0) ? "Yes" : "No") << endl;
    // Output: No
    
    // Test Case 3
    vector<int> arr3 = {5};
    cout << "Is Sorted: " << (isSorted(arr3, 0) ? "Yes" : "No") << endl;
    // Output: Yes (single element)
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arr = [1, 3, 2], index = 0

```
Call Stack:

isSorted([1,3,2], 0)
    arr[0]=1 <= arr[1]=3? Yes
    → isSorted([1,3,2], 1)
        arr[1]=3 <= arr[2]=2? No
        → return false

Final Answer: false ✅

For sorted array [1, 2, 3]:
isSorted([1,2,3], 0)
    1 <= 2? Yes
    → isSorted([1,2,3], 1)
        2 <= 3? Yes
        → isSorted([1,2,3], 2)
            index=2 >= size-1, return true
        → return true
    → return true
Final: true ✅
```

---

### **🏢 Company Frequency:**
- **TCS:** 60-65%
- **Infosys:** 65-70%
- **Wipro:** 55-60%

---

## 📖 PROBLEM 8: BINARY SEARCH (RECURSIVE) ⭐⭐⭐

**Classic Divide & Conquer**

### **Problem:**
```
Search for target in sorted array using recursive binary search.

Example:
Input: arr = [1, 3, 5, 7, 9], target = 5
Output: 2 (index)
```

---

### **💡 Interview Communication Script:**

> "Sir, this is **Binary Search** implemented using **recursion**.
> 
> **Base Case:** 
> - If left > right, element not found, return -1
> - If mid element equals target, return mid
> 
> **Recursive Case:**
> - If target < arr[mid], search left half
> - If target > arr[mid], search right half
> 
> This is **divide and conquer** approach.
> 
> **Time:** O(log n), **Space:** O(log n) - recursion stack"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
    // Base case: not found
    if(left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    // Found
    if(arr[mid] == target) {
        return mid;
    }
    
    // Search left half
    if(target < arr[mid]) {
        return binarySearch(arr, left, mid - 1, target);
    }
    
    // Search right half
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    
    int result = binarySearch(arr, 0, arr.size() - 1, target);
    
    if(result != -1) {
        cout << "Found at index: " << result << endl;
    } else {
        cout << "Not found" << endl;
    }
    // Output: Found at index: 3
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arr = [1, 3, 5, 7, 9], target = 5

```
Call Stack:

binarySearch([1,3,5,7,9], 0, 4, 5)
    mid = 2, arr[2] = 5
    target = 5
    Found! return 2 ✅

For target = 7:
binarySearch([1,3,5,7,9], 0, 4, 7)
    mid = 2, arr[2] = 5
    7 > 5, search right
    → binarySearch([1,3,5,7,9], 3, 4, 7)
        mid = 3, arr[3] = 7
        Found! return 3 ✅
```

---

### **⏱️ Complexity:**
- **Time:** O(log n)
- **Space:** O(log n) - recursion stack

---

### **🏢 Company Frequency:**
- **TCS:** 70-75%
- **Infosys:** 75-80% ⭐⭐⭐
- **Wipro:** 65-70%

---

## 🎯 SUMMARY - BASIC RECURSION

### **Key Takeaways:**

1. **Recursion Components:**
   - Base case (stopping condition)
   - Recursive case (calls itself)
   - Progress towards base case

2. **Types:**
   - Head Recursion (recurse then process)
   - Tail Recursion (process then recurse)

3. **Common Patterns:**
   - Linear recursion (factorial, sum)
   - Binary recursion (fibonacci, tree)
   - Divide & conquer (binary search, power)

4. **Time/Space:**
   - Time: Usually O(n) or O(2^n)
   - Space: O(recursion depth)

---

### **Problems Covered:**

1. ✅ Factorial (Basic pattern)
2. ✅ Fibonacci (Binary recursion, exponential)
3. ✅ Print 1 to N (Tail/Head recursion)
4. ✅ Sum of Array (Array recursion)
5. ✅ Reverse String (Two pointer recursion)
6. ✅ Power Function (Divide & conquer, O(log n))
7. ✅ Check Sorted (Boolean recursion)
8. ✅ Binary Search (Classic divide & conquer)

---

### **Company-Wise Focus:**

**TCS:**
- Factorial, Fibonacci
- Binary Search recursive
- Basic patterns

**Infosys:**
- Fibonacci ⭐⭐⭐
- Power function ⭐⭐
- Binary Search ⭐⭐⭐
- Optimization important

**Wipro:**
- Basic recursion
- Factorial, Print patterns
- Clear explanation

---

## 💪 NEXT STEPS

You've completed **Basic Recursion**! 🎉

**Next:** `Backtracking-Patterns/INTERVIEW-READY.md` for:
- Permutations ⭐⭐⭐
- Combinations ⭐⭐⭐
- Subsets/Subsequences ⭐⭐⭐
- N-Queens ⭐⭐
- Sudoku Solver ⭐⭐
- And more backtracking patterns!

---

**All the best, Satyam!** 🌟  
**Recursion is the foundation for trees and backtracking!** 💯

**Remember:** Every recursion needs a **base case** to stop! 🎯
