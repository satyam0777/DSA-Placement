# BASIC ARRAY OPERATIONS - COMPLETE SERIES 🎯
*Following Aditya Verma's Methodology*

---

## 📚 TABLE OF CONTENTS

1. [Introduction - What is Array?](#video-1-introduction)
2. [Identification - When to Use?](#video-2-identification)
3. [Core Concepts - Memory & Pointers](#video-3-core-concepts)
4. [Generic Templates](#video-4-generic-templates)
5. [Problem 1: Find Min/Max](#problem-1-find-minmax)
6. [Problem 2: Reverse Array](#problem-2-reverse-array)
7. [Problem 3: Linear Search](#problem-3-linear-search)
8. [Problem 4: Remove Duplicates](#problem-4-remove-duplicates)
9. [Problem 5: Rotate Array](#problem-5-rotate-array)
10. [Quick Reference Sheet](#quick-reference)
11. [7-Day Learning Path](#learning-path)

---

# VIDEO 1: INTRODUCTION 🎬

## What is an Array?

An **array** is a collection of elements of:
- **Same data type** stored in **contiguous memory locations**
- **Fixed size** after declaration
- **Zero-based indexing** (0 to n-1)

### Why Use Arrays?
✅ Store multiple values in single variable  
✅ Direct access using index O(1)  
✅ Sequential memory = cache-friendly  
✅ Foundation for all data structures  

### The Big Idea
```
Array = Contiguous Memory Block
        ↓
    Fast Access
        ↓
    Index = Base_Address + (index × size)
```

### Visual Representation
```
arr[5] = {10, 20, 30, 40, 50}

Memory:  [10][20][30][40][50]
Index:    0   1   2   3   4
Address: 100 104 108 112 116  (if int = 4 bytes)
```

---

# VIDEO 2: IDENTIFICATION 🔍

## How to Recognize Array Problems?

### 3 Magic Signs:
1. **Fixed Collection** - "Given n elements..."
2. **Index-Based Access** - "Find at position i..."
3. **Sequential Operations** - "Traverse/Scan all elements..."

### Magic Keywords (Array Problems):

| **Keyword** | **Pattern** | **Example** |
|------------|------------|-------------|
| "Find", "Search" | Linear/Binary Search | Find element x |
| "Maximum", "Minimum" | Single Pass Scan | Find largest |
| "Reverse" | Two Pointer | Reverse array |
| "Rotate" | Rotation Logic | Rotate by k |
| "Sort" | Sorting | Sort array |
| "Duplicates" | Hashing/Set | Remove duplicates |
| "Subarray" | Sliding Window | Max sum subarray |
| "Prefix/Suffix" | Prefix Sum | Range queries |

### Pattern vs Other Techniques:

| **Array** | **Hashing** | **Two Pointer** |
|-----------|-------------|-----------------|
| Sequential scan | O(1) lookup | Left-right scan |
| Index-based | Key-value pairs | Sorted typically |
| In-place ops | Extra space | In-place |

---

# VIDEO 3: CORE CONCEPTS 💡

## A. Declaration and Initialization

## A. Declaration and Initialization

```cpp
// Method 1: Declaration only
int arr[5];  // Uninitialized (garbage values)

// Method 2: Declaration + Initialization
int arr2[5] = {1, 2, 3, 4, 5};

// Method 3: Partial initialization (rest = 0)
int arr3[5] = {1, 2};  // {1, 2, 0, 0, 0}

// Method 4: Size inferred from initializer
int arr4[] = {10, 20, 30};  // size = 3

// Method 5: Dynamic size (C++ only)
int n = 5;
int arr5[n];  // Variable length array (VLA)
```

---

## B. Array and Pointers - The Golden Connection

### The Golden Rule:
```
╔═══════════════════════════════════════════╗
║  Array Name = Pointer to First Element    ║
║  arr ≡ &arr[0]                            ║
╚═══════════════════════════════════════════╝
```

### Pointer Arithmetic
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr;  // p points to arr[0]

cout << *p;         // 10 (arr[0])
cout << *(p + 1);   // 20 (arr[1])
cout << *(p + 2);   // 30 (arr[2])

// Equivalent notations:
arr[i]  ≡  *(arr + i)  ≡  *(p + i)  ≡  p[i]
```

### Address Calculation
```
Address of arr[i] = Base_Address + (i × sizeof(element))
```

---

## C. Array vs Pointer - The Difference

| **Array Name** | **Pointer Variable** |
|----------------|----------------------|
| `int arr[5];` | `int* p = arr;` |
| Constant pointer | Variable pointer |
| Cannot reassign `arr` | Can reassign `p` |
| `sizeof(arr) = 20` | `sizeof(p) = 8` (64-bit) |
| Fixed size | Points anywhere |

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int* p = arr;

// arr = something;  ❌ ERROR! Cannot change arr
p = something;       // ✅ OK! Can change p
```

---

## D. Passing Arrays to Functions

### Key Insight: Arrays Always Passed by Reference!

```cpp
void modify(int arr[], int n) {
    arr[0] = 999;  // This WILL change original array
}

// Why? Because arr[] decays to int* (pointer)
// Function receives address, not copy!
```

### To Prevent Modification - Use `const`
```cpp
void printArray(const int arr[], int n) {
    // arr[0] = 10;  ❌ ERROR! Cannot modify
    cout << arr[0];  // ✅ OK! Can read
}
```

---

## E. Memory Layout Concept

```
Stack Memory (Local Arrays):
int arr[5] = {1, 2, 3, 4, 5};
[1][2][3][4][5] ← Automatic cleanup

Heap Memory (Dynamic Arrays):
int* arr = new int[5];
[1][2][3][4][5] ← Must delete[] manually
```

---

# VIDEO 4: GENERIC TEMPLATES 📝

## Template 1: Basic Traversal
```cpp
// Forward traversal
void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// Reverse traversal
void reverseTraverse(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

// Mantra: "0 to n-1, forward. n-1 to 0, backward."
```

---

## Template 2: Find Min/Max (Single Pass)
```cpp
int findMax(int arr[], int n) {
    int maxVal = arr[0];  // Start from first element
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// Mantra: "Assume first is best, then challenge it!"
```

---

## Template 3: Linear Search
```cpp
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}

// Mantra: "Scan left to right, return when found, -1 if not."
```

---

## Template 4: Reverse Array (Two Pointer)
```cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// Mantra: "Two pointers, swap and move inward!"
```

---

## Template 5: Rotate Array by K Positions
```cpp
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int k) {
    k = k % n;  // Handle k > n
    reverse(arr, 0, n - 1);        // Reverse entire
    reverse(arr, 0, k - 1);        // Reverse first k
    reverse(arr, k, n - 1);        // Reverse rest
}

// Mantra: "Reverse whole, reverse parts!"
```

---

## Template 6: Remove Duplicates (Using Set)
```cpp
int removeDuplicates(int arr[], int n) {
    unordered_set<int> seen;
    int writeIndex = 0;
    
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[writeIndex++] = arr[i];
        }
    }
    return writeIndex;  // New size
}

// Mantra: "Seen it? Skip it. New? Write it!"
```

---

## 💪 MEMORY HOOKS & MANTRAS

### Say 10x Before Coding:
1. **"Array = Contiguous Memory Block"**
2. **"Index starts at 0, ends at n-1"**
3. **"arr ≡ &arr[0] (pointer to first)"**
4. **"Always pass by reference in functions!"**
5. **"Two pointers for reversal, swap and move!"**

### Memory Hooks:
- 🎬 **Cinema Seats** → Array (Row of seats, seat numbers = indices)
- 📦 **Storage Boxes** → Contiguous memory (Box 0, Box 1, Box 2...)
- 🚂 **Train Coaches** → Sequential access (Coach[0], Coach[1]...)

---

## 2. Declaring and Initializing Arrays

```cpp
int arr[5]; // Declaration
int arr2[5] = {1, 2, 3, 4, 5}; // Declaration + Initialization
```

---

## 3. Key Points

- Indexing starts from 0.
- Fixed size after declaration.
- All elements must be of the same data type.

---

## 4. Input and Output

```cpp
int n;
cin >> n;
int arr[n];
for(int i = 0; i < n; i++) cin >> arr[i];
for(int i = 0; i < n; i++) cout << arr[i] << " ";
```

---

## 5. Array Traversal

Loop through all elements using a `for` loop.

---

## 6. Updating Elements

```cpp
arr[2] = 100; // Updates the 3rd element
```

---

## 7. Common Array Problems

### a. Find Maximum and Minimum

```cpp
int max = arr[0], min = arr[0];
for(int i = 1; i < n; i++) {
    if(arr[i] > max) max = arr[i];
    if(arr[i] < min) min = arr[i];
}
```

---

### b. Linear Search

```cpp
int key, found = -1;
cin >> key;
for(int i = 0; i < n; i++) {
    if(arr[i] == key) {
        found = i;
        break;
    }
}
if(found != -1) cout << "Found at index " << found;
else cout << "Not found";
```

---

### c. Reverse an Array

```cpp
for(int i = 0; i < n/2; i++) {
    int temp = arr[i];
    arr[i] = arr[n-1-i];
    arr[n-1-i] = temp;
}
```

---

### d. Sum and Average

```cpp
int sum = 0;
for(int i = 0; i < n; i++) sum += arr[i];
double avg = (double)sum / n;
```

---

### e. Copying Arrays

```cpp
int b[n];
for(int i = 0; i < n; i++) b[i] = arr[i];
```

---

### f. Sorting (Bubble Sort Example)

```cpp
for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
        if(arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
```

---

### g. Binary Search (Array must be sorted)

```cpp
int left = 0, right = n-1, key;
cin >> key;
while(left <= right) {
    int mid = left + (right - left) / 2;
    if(arr[mid] == key) {
        cout << "Found at index " << mid;
        break;
    } else if(arr[mid] < key) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

---

## 8. Multidimensional Arrays

```cpp
int mat[3][4]; // 3 rows, 4 columns
```

---

## 9. Passing Arrays to Functions

```cpp
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
```

---

## 10. Practice Problems

- Find the second largest element in an array.
- Count the number of even and odd elements.
- Remove duplicates from a sorted array.
- Rotate array by k positions.

---


## 11. Copying Arrays: Value Copy vs Reference

### a. Value Copy

When you copy arrays element by element, you create a new array with the same values but a different memory location.

```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
for(int i = 0; i < 5; i++) {
    arr2[i] = arr1[i];
}
// arr2 is a separate copy; changing arr2 does not affect arr1
```

### b. Reference (Pointer) Copy

In C++, you cannot directly assign one array to another (e.g., `arr2 = arr1;` is invalid). However, you can use pointers to refer to the same array.

```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int* ptr = arr1; // ptr points to the first element of arr1
ptr[0] = 100;    // This will change arr1[0] to 100
```

---

## 12. Array Addresses and Pointers

- The name of the array (`arr`) acts as a pointer to its first element.
- You can use pointers to traverse arrays.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr; // or int* p = &arr[0];

cout << *p << endl;     // 10
cout << *(p + 1) << endl; // 20

// Traversing using pointers
for(int i = 0; i < 5; i++) {
    cout << *(p + i) << " ";
}
```

---

## 13. Difference Between Array Name and Pointer

- `arr` is a constant pointer to the first element; you cannot change `arr` to point elsewhere.
- A pointer variable (`int* p`) can point to any integer variable or array.

---

## 14. Passing Arrays to Functions (Pointer Behavior)

When you pass an array to a function, you are actually passing a pointer to its first element. Changes made inside the function affect the original array.

```cpp
void modify(int arr[], int n) {
    arr[0] = 999; // This will change the original array's first element
}
```

---


## 11. Copying Arrays: Value Copy vs Reference

### a. Value Copy (Element-wise Copy)

When you copy arrays element by element, you create a new array with the same values but a different memory location.

```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5];
for(int i = 0; i < 5; i++) {
    arr2[i] = arr1[i];
}
// arr2 is a separate copy; changing arr2 does not affect arr1
```

### b. Reference (Pointer) Copy

You cannot directly assign one array to another (`arr2 = arr1;` is invalid). But you can use pointers to refer to the same array.

```cpp
int arr1[5] = {1, 2, 3, 4, 5};
int* ptr = arr1; // ptr points to arr1's first element
ptr[0] = 100;    // This will change arr1[0] to 100
```

---

## 12. Array Addresses and Pointers

- The name of the array (`arr`) acts as a pointer to its first element.
- You can use pointers to traverse arrays.

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr; // or int* p = &arr[0];

cout << *p << endl;        // 10
cout << *(p + 1) << endl;  // 20

// Traversing using pointers
for(int i = 0; i < 5; i++) {
    cout << *(p + i) << " ";
}
```

---

## 13. Passing Arrays to Functions

When you pass an array to a function, you are actually passing a pointer to its first element. Changes made inside the function affect the original array.

```cpp
void modify(int arr[], int n) {
    arr[0] = 999; // This will change the original array's first element
}

int main() {
    int arr[3] = {1, 2, 3};
    modify(arr, 3);
    // arr[0] is now 999
}
```

---

## 14. Difference Between Array Name and Pointer

- `arr` is a constant pointer to the first element; you cannot change `arr` to point elsewhere.
- A pointer variable (`int* p`) can point to any integer variable or array.

---

## 15. Returning Arrays from Functions

You cannot return a local array from a function (it will be destroyed), but you can return a pointer to a dynamically allocated array.

```cpp
int* createArray(int n) {
    int* arr = new int[n]; // dynamic allocation
    for(int i = 0; i < n; i++) arr[i] = i;
    return arr;
}
```
*Remember to `delete[]` the array after use to avoid memory leaks.*

---

## 16. Const Arrays and Function Parameters

If you don't want a function to modify the array, use `const`:

```cpp
void printArray(const int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
```

---

## 11. Advanced Concepts & Conceptual Problems

### a. Array and Pointer Basics

- What is the difference between `int arr[5]` and `int* ptr = arr;`?
- How does pointer arithmetic work with arrays?  
  *(e.g., What does `*(arr + 2)` give you?)*

---

### b. Passing Arrays to Functions

**Problem:**  
Write a function that takes an array and its size, and sets all even-indexed elements to zero.  
*How does the function affect the original array? Why?*

```cpp
void setEvenZero(int arr[], int n) {
    for(int i = 0; i < n; i += 2) arr[i] = 0;
}
```

---

### c. Pointer Manipulation

**Problem:**  
Given an array, use a pointer to reverse the array in-place (without using array indexing).

```cpp
void reverseWithPointers(int* arr, int n) {
    int* left = arr;
    int* right = arr + n - 1;
    while(left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
```

---

### d. Returning Arrays from Functions

**Problem:**  
Write a function that returns a pointer to a dynamically allocated array containing the squares of the first `n` natural numbers.

```cpp
int* getSquares(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) arr[i] = (i+1)*(i+1);
    return arr;
}
```
*Remember to `delete[]` the array after use.*

---

### e. Array Addressing

**Problem:**  
Given `int arr[5] = {10, 20, 30, 40, 50};`, what is the output of:
- `cout << arr;`
- `cout << &arr[0];`
- `cout << *(arr + 2);`
- `cout << *(2 + arr);`

---

### f. Const Correctness

**Problem:**  
Write a function that prints an array but does not allow modification of its elements.

```cpp
void printArray(const int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
```

---

### g. Function Pointer as Array Argument

**Problem:**  
Write a function that takes a pointer to an array and its size, and increments each element by 1.

```cpp
void increment(int* arr, int n) {
    for(int i = 0; i < n; i++) arr[i]++;
}
```

---

### h. Multi-dimensional Array and Function

**Problem:**  
Write a function to print a 2D array using pointer notation.

```cpp
void print2D(int arr[][3], int rows) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < 3; j++)
            cout << *(*(arr + i) + j) << " ";
}
```

---

## 12. Practice: Company-Style Conceptual Questions

1. **Pointer Output:**  
   What will be the output of the following code?
   ```cpp
   int arr[3] = {1, 2, 3};
   int* p = arr;
   cout << *(p + 1);
   ```

2. **Function Modification:**  
   If you pass an array to a function and modify it, does the original array change? Why?

3. **Dynamic Allocation:**  
   Write a function that takes an integer `n` and returns a pointer to an array of size `n` initialized to zero.

4. **Address Comparison:**  
   What is the difference between `arr` and `&arr`?

5. **Array Decay:**  
   What happens when you pass an array to a function? Does it decay to a pointer? What are the implications?

---

---

# PROBLEM 1: FIND MINIMUM AND MAXIMUM 📊

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers, find the **minimum** and **maximum** elements.

### Input:
```
arr = [3, 5, 1, 8, 2, 9, 4]
n = 7
```

### Output:
```
Minimum: 1
Maximum: 9
```

---

## STEP 2: IDENTIFICATION

✅ **Keywords**: "Find", "Minimum", "Maximum"  
✅ **Pattern**: Single pass scan  
✅ **Approach**: Compare each element with current min/max  

---

## STEP 3: ABSTRACT/APPROACH

```
1. Assume first element is both min and max
2. For each remaining element:
   - If smaller than min → update min
   - If larger than max → update max
3. Return min and max
```

**Key Insight**: "We only need ONE pass!"

**Time**: O(n) | **Space**: O(1)

---

## STEP 4: DRY RUN

```
arr = [3, 5, 1, 8, 2, 9, 4]

Init: min=3, max=3

i=1: 5 → max=5
i=2: 1 → min=1
i=3: 8 → max=8
i=4: 2 → no change
i=5: 9 → max=9
i=6: 4 → no change

Final: min=1, max=9 ✅
```

---

## STEP 5: CODE

```cpp
pair<int, int> findMinMax(int arr[], int n) {
    int minVal = arr[0];
    int maxVal = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    
    return {minVal, maxVal};
}
```

---

# PROBLEM 2: REVERSE AN ARRAY 🔄

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Reverse the array **in-place** without extra space.

### Input:
```
arr = [1, 2, 3, 4, 5]
```

### Output:
```
arr = [5, 4, 3, 2, 1]
```

---

## STEP 2: IDENTIFICATION

✅ **Keywords**: "Reverse", "In-place"  
✅ **Pattern**: Two Pointer Technique  
✅ **Approach**: Swap from both ends moving inward  

---

## STEP 3: ABSTRACT/APPROACH

```
1. left = 0, right = n-1
2. While left < right:
   - Swap arr[left] and arr[right]
   - left++, right--
3. Stop when pointers meet
```

**Key Insight**: "Swap and move inward from both ends!"

**Time**: O(n) | **Space**: O(1)

---

## STEP 4: DRY RUN

```
arr = [1, 2, 3, 4, 5]

Step 1: Swap arr[0]↔arr[4] → [5,2,3,4,1] → left=1, right=3
Step 2: Swap arr[1]↔arr[3] → [5,4,3,2,1] → left=2, right=2
Stop! (left=right)

Final: [5, 4, 3, 2, 1] ✅
```

---

## STEP 5: CODE

```cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
```

---

# PROBLEM 3: LINEAR SEARCH 🔍

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Find the **index** of first occurrence of `key`. Return `-1` if not found.

### Input:
```
arr = [10, 20, 30, 40, 50, 30]
key = 30
```

### Output:
```
Index: 2
```

---

## STEP 2: IDENTIFICATION

✅ **Keywords**: "Find", "Search", "Index"  
✅ **Pattern**: Linear Search (Sequential)  
✅ **Approach**: Check each element one by one  

---

## STEP 3: ABSTRACT/APPROACH

```
1. For each element from 0 to n-1:
   - If arr[i] == key → return i
2. If loop completes → return -1
```

**Key Insight**: "Scan left to right, return when found!"

**Time**: O(n) | **Space**: O(1)

---

## STEP 4: DRY RUN

```
arr = [10, 20, 30, 40, 50, 30], key = 30

i=0: 10≠30
i=1: 20≠30
i=2: 30=30 → Return 2 ✅
(Don't check i=5 because found first!)
```

---

## STEP 5: CODE

```cpp
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Found!
        }
    }
    return -1;  // Not found
}
```

---

# PROBLEM 4: REMOVE DUPLICATES 🗑️

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Remove duplicates while **preserving order**. Return new size.

### Input:
```
arr = [10, 20, 30, 20, 40, 10, 50]
```

### Output:
```
arr = [10, 20, 30, 40, 50, _, _]
New size = 5
```

---

## STEP 2: IDENTIFICATION

✅ **Keywords**: "Remove duplicates", "Preserve order"  
✅ **Pattern**: HashSet + Write Index  
✅ **Approach**: Track seen, write only unique  

---

## STEP 3: ABSTRACT/APPROACH

```
1. Create HashSet to track seen elements
2. writeIndex = 0
3. For each element:
   - If NOT in set:
     * Add to set
     * Write to arr[writeIndex++]
   - If in set: Skip
4. Return writeIndex
```

**Key Insight**: "Seen it? Skip. New? Write!"

**Time**: O(n) | **Space**: O(n)

---

## STEP 4: DRY RUN

```
arr = [10, 20, 30, 20, 40, 10]
seen = {}, writeIdx = 0

10 → Write[0]=10, seen={10}, w=1
20 → Write[1]=20, seen={10,20}, w=2
30 → Write[2]=30, seen={10,20,30}, w=3
20 → Skip! (already in set)
40 → Write[3]=40, seen={10,20,30,40}, w=4
10 → Skip! (already in set)

Result: [10,20,30,40,_,_]
Size = 4 ✅
```

---

## STEP 5: CODE

```cpp
int removeDuplicates(int arr[], int n) {
    unordered_set<int> seen;
    int writeIndex = 0;
    
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[writeIndex++] = arr[i];
        }
    }
    
    return writeIndex;
}
```

---

# PROBLEM 5: ROTATE ARRAY BY K 🔄

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Rotate array to the **right** by `k` positions in-place.

### Input:
```
arr = [1, 2, 3, 4, 5, 6, 7]
k = 3
```

### Output:
```
arr = [5, 6, 7, 1, 2, 3, 4]
```

---

## STEP 2: IDENTIFICATION

✅ **Keywords**: "Rotate", "Shift", "Circular"  
✅ **Pattern**: Triple Reversal  
✅ **Approach**: Reverse whole, then parts  

---

## STEP 3: ABSTRACT/APPROACH

**The Magic Formula:**
```
1. Reverse entire array [0...n-1]
2. Reverse first k [0...k-1]
3. Reverse remaining [k...n-1]
```

**Key Insight**: "Reverse whole, reverse parts!"

**Time**: O(n) | **Space**: O(1)

---

## STEP 4: DRY RUN

```
arr = [1, 2, 3, 4, 5, 6, 7], k = 3

Step 1: Reverse all [0..6]
  [7, 6, 5, 4, 3, 2, 1]

Step 2: Reverse first k=3 [0..2]
  [5, 6, 7, 4, 3, 2, 1]

Step 3: Reverse rest [3..6]
  [5, 6, 7, 1, 2, 3, 4] ✅
```

---

## STEP 5: CODE

```cpp
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start++], arr[end--]);
    }
}

void rotateRight(int arr[], int n, int k) {
    k = k % n;  // Handle k > n
    
    reverse(arr, 0, n - 1);    // Reverse all
    reverse(arr, 0, k - 1);    // Reverse first k
    reverse(arr, k, n - 1);    // Reverse rest
}
```

---

# 📋 QUICK REFERENCE SHEET

## Pattern Recognition

| **Problem** | **Pattern** | **Time** | **Space** | **Key** |
|-------------|-------------|----------|-----------|---------|
| Min/Max | Single Pass | O(n) | O(1) | Compare with best |
| Reverse | Two Pointer | O(n) | O(1) | Swap both ends |
| Search | Sequential | O(n) | O(1) | Check each |
| Remove Dup | HashSet | O(n) | O(n) | Seen? Skip. |
| Rotate | Triple Reversal | O(n) | O(1) | Reverse all, parts |

---

## Decision Tree

```
Array Problem?
    ↓
Find Min/Max? → Single pass scan
Reverse? → Two pointer swap
Search? → Linear (unsorted) / Binary (sorted)
Remove Dup? → HashSet tracking
Rotate? → Triple reversal
```

---

## Interview Tips

1. ✅ **Clarify**: Sorted? Extra space? In-place?
2. ✅ **Think first**: Identify pattern before coding
3. ✅ **Dry run**: Show 2-3 steps with example
4. ✅ **Complexity**: State time/space clearly
5. ✅ **Edge cases**: n=0, n=1, k>n

---

# 🗓️ 7-DAY LEARNING PATH

**Day 1**: Array basics, memory, pointers  
**Day 2**: Min/Max, Traversal (Template 1)  
**Day 3**: Reverse, Two Pointer (Template 2)  
**Day 4**: Linear Search, Binary Search (Template 3)  
**Day 5**: Remove Duplicates, HashSet (Template 4)  
**Day 6**: Rotate Array, Triple Reversal (Template 5)  
**Day 7**: All problems + Mock interview

---

**🎯 Master these 5 patterns → 80% of basic array problems solved!**

---