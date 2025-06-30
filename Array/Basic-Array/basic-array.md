
# Arrays in C++: 

---

## 1. What is an Array?

An **array** is a collection of elements of the same data type stored in contiguous memory locations.

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

