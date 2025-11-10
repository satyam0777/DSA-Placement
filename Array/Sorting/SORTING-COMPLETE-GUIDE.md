# SORTING ALGORITHMS - COMPLETE SERIES 🎯
*Following Aditya Verma's Methodology with Real-World Examples*

---

## 📚 TABLE OF CONTENTS

1. [Introduction - What is Sorting?](#video-1-introduction)
2. [Identification - When to Sort?](#video-2-identification)
3. [Core Concepts - Why Sorting Matters?](#video-3-core-concepts)
4. [Generic Templates](#video-4-generic-templates)
5. [Problem 1: Basic Sorting](#problem-1-basic-sorting)
6. [Problem 2: Sort 0s, 1s, 2s (Dutch Flag)](#problem-2-dutch-national-flag)
7. [Problem 3: Custom Comparator](#problem-3-custom-comparator)
8. [Problem 4: Merge Sorted Arrays](#problem-4-merge-sorted-arrays)
9. [Problem 5: Kth Largest Element](#problem-5-kth-largest-element)
10. [Quick Reference Sheet](#quick-reference)
11. [7-Day Learning Path](#learning-path)

---

# VIDEO 1: INTRODUCTION 🎬

## What is Sorting?

**Definition**: Sorting is the process of arranging elements in a **specific order** (ascending or descending).

### Real-World Examples 🌍

#### Example 1: Phone Contacts 📱
```
Unsorted: [Zara, Alice, Bob, Charlie]
Sorted:   [Alice, Bob, Charlie, Zara] ✅
```
**Why?** Easy to find contacts alphabetically!

#### Example 2: E-commerce Products 🛒
```
Products by Price:
Unsorted: [$50, $20, $100, $30, $80]
Sorted:   [$20, $30, $50, $80, $100] ✅
```
**Why?** Customers can filter "Low to High" or "High to Low"!

#### Example 3: Exam Rank List 🎓
```
Students by Marks:
Unsorted: [85, 92, 78, 95, 88]
Sorted:   [95, 92, 88, 85, 78] ✅ (Descending)
```
**Why?** Topper appears first!

#### Example 4: Library Books 📚
```
Sorted by: Author name, Title, ISBN
```
**Why?** Quick search using Binary Search!

#### Example 5: Gmail Inbox 📧
```
Sort by: Date, Sender, Subject, Importance
```
**Why?** Find important emails quickly!

---

### Why Sorting is CRUCIAL? 💡

```
✅ Enables Binary Search (O(log n) instead of O(n))
✅ Two Pointer technique requires sorted array
✅ Makes many problems easier (finding duplicates, closest pair)
✅ Real-world applications everywhere!
✅ Asked in 85-95% of array interviews!
```

### The Big Idea
```
Unsorted Data
      ↓
   SORTING
      ↓
Ordered Data → Fast Search, Pattern Detection, Optimization
```

---

# VIDEO 2: IDENTIFICATION 🔍

## How to Recognize Sorting Problems?

### 3 Magic Signs:
1. **"Sort", "Order", "Arrange"** - Direct keywords
2. **"Closest", "Minimum Difference"** - After sorting, neighbors are closest
3. **"Kth largest/smallest"** - Sort to find Kth element

### Magic Keywords (Sorting Problems):

| **Keyword** | **Pattern** | **Real Example** |
|------------|------------|------------------|
| "Sort array" | Basic sort | Sort student names |
| "Ascending/Descending" | STL sort | Price low→high |
| "0s, 1s, 2s" | Dutch Flag | Sort red, white, blue balls |
| "Merge sorted" | Two pointer | Merge two contact lists |
| "Custom order" | Comparator | Sort by length, frequency |
| "Kth largest" | Sort + index | 3rd highest scorer |
| "Anagram" | Sort strings | "listen" vs "silent" |
| "Closest pair" | Sort + adjacent | Find similar prices |

---

### When Sorting Helps? (Real Interview Scenarios)

#### Scenario 1: "Find if duplicate exists"
```
❌ Without Sorting: O(n²) - Compare all pairs
✅ With Sorting: O(n log n) - Adjacent elements will be equal!

arr = [3, 1, 4, 1, 5]
After sort: [1, 1, 3, 4, 5]
            ↑  ↑ Adjacent duplicates!
```

#### Scenario 2: "Find closest pair"
```
❌ Without Sorting: O(n²) - Check all pairs
✅ With Sorting: O(n log n) - Closest elements become adjacent!

arr = [10, 50, 12, 100]
After sort: [10, 12, 50, 100]
             ↑   ↑ Closest pair (diff=2)
```

#### Scenario 3: "Two sum problem"
```
✅ After Sorting: Use Two Pointer technique!
arr = [2, 7, 11, 15], target = 9
After sort: [2, 7, 11, 15]
             ↑           ↑ Two pointers
```

---

## Pattern vs Other Techniques:

| **Sorting** | **Hashing** | **Two Pointer** |
|-------------|-------------|-----------------|
| O(n log n) | O(n) | O(n) |
| Order matters | Order doesn't matter | Needs sorted |
| Enables binary search | Fast lookup | In-place |
| Example: Rank list | Example: Frequency count | Example: Two sum |

---

# VIDEO 3: CORE CONCEPTS 💡

## A. What Happens During Sorting?

### Visual Example: Sorting [5, 2, 8, 1, 9]

```
Initial:  [5, 2, 8, 1, 9]

After sorting: [1, 2, 5, 8, 9]

Memory stays same, only ORDER changes!
```

### Real-World Analogy:
**Think of sorting like arranging books on a shelf:**
- Books = Array elements
- Shelf = Array
- Arranging by title = Sorting
- Finding a book after arranging = Binary Search (fast!)

---

## B. C++ STL sort() - The Magic Function

### What is sort()?
```cpp
#include <algorithm>

sort(arr.begin(), arr.end());  // Ascending
sort(arr.begin(), arr.end(), greater<int>());  // Descending
```

### Behind the Scenes:
**STL sort() uses IntroSort** = Quick Sort + Heap Sort + Insertion Sort

```
Why hybrid?
- Quick Sort: Fast average O(n log n)
- Heap Sort: When Quick Sort degrades to O(n²)
- Insertion Sort: For small subarrays (< 16 elements)

Result: Guaranteed O(n log n) performance!
```

---

## C. Sorting Algorithms - Real-World Analogies

### 1. Bubble Sort 🫧
**Analogy**: Like bubbles rising to the surface!

**Real Example**: Arranging students by height in a line
- Compare adjacent students
- Shorter one goes left, taller goes right
- Repeat until all sorted

```cpp
// Bubble Sort (Teaching purpose only - Don't use in interviews!)
for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
}
```
**Time**: O(n²) - Too slow!  
**Interview**: ❌ Don't implement, just use sort()

---

### 2. Selection Sort 🔍
**Analogy**: Selecting the best player for each position!

**Real Example**: Picking top 3 students for awards
- Find smallest (1st rank)
- Find next smallest (2nd rank)
- Find next smallest (3rd rank)

```cpp
// Selection Sort (Teaching purpose only)
for (int i = 0; i < n-1; i++) {
    int minIdx = i;
    for (int j = i+1; j < n; j++) {
        if (arr[j] < arr[minIdx]) minIdx = j;
    }
    swap(arr[i], arr[minIdx]);
}
```
**Time**: O(n²) - Too slow!  
**Interview**: ❌ Don't implement, just use sort()

---

### 3. Insertion Sort 🃏
**Analogy**: Sorting playing cards in your hand!

**Real Example**: Arranging cards while playing Rummy
- Pick one card
- Insert it in the correct position among sorted cards
- Repeat

```cpp
// Insertion Sort (Good for small/nearly sorted arrays)
for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
```
**Time**: O(n²) average, O(n) best (already sorted)  
**Use Case**: Small arrays, nearly sorted data  
**Interview**: Know the concept, but use sort()

---

### 4. Merge Sort 🔀
**Analogy**: Divide and Conquer - like merging two queues!

**Real Example**: Merging two sorted contact lists
```
List 1: [Alice, Charlie, Eve]
List 2: [Bob, David, Frank]

Merged: [Alice, Bob, Charlie, David, Eve, Frank]
```

```cpp
// Merge Sort (Stable, Guaranteed O(n log n))
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);
    
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
```
**Time**: O(n log n) - Guaranteed!  
**Space**: O(n) - Extra array needed  
**Interview**: Know the concept, but use sort()

---

### 5. Quick Sort ⚡
**Analogy**: Pivot and partition - like organizing files!

**Real Example**: Sorting files in a folder
- Pick a pivot file (middle one)
- Files smaller than pivot → Left folder
- Files larger than pivot → Right folder
- Repeat for each folder

```cpp
// Quick Sort (Fast average, but O(n²) worst case)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```
**Time**: O(n log n) average, O(n²) worst  
**Space**: O(log n) - Recursion stack  
**Interview**: Know the concept, but use sort()

---

## D. Sorting Algorithms Comparison Table

| **Algorithm** | **Time (Avg)** | **Space** | **Stable?** | **Real-World Use** |
|---------------|----------------|-----------|-------------|---------------------|
| **Bubble** | O(n²) | O(1) | Yes | Teaching only ❌ |
| **Selection** | O(n²) | O(1) | No | Teaching only ❌ |
| **Insertion** | O(n²) | O(1) | Yes | Small/nearly sorted |
| **Merge** | O(n log n) | O(n) | Yes | External sorting, stable needed |
| **Quick** | O(n log n) | O(log n) | No | General purpose (STL uses this!) |
| **Heap** | O(n log n) | O(1) | No | Priority queues |
| **STL sort()** | O(n log n) | O(log n) | No | **USE THIS!** ✅ |

### What is Stable Sorting?

**Definition**: Relative order of equal elements is preserved.

**Example**:
```
Input: [(5, "A"), (3, "B"), (5, "C"), (3, "D")]
       Sort by first element

Stable Sort:   [(3, "B"), (3, "D"), (5, "A"), (5, "C")]
               ↑ B comes before D ✅
               
Unstable Sort: [(3, "D"), (3, "B"), (5, "C"), (5, "A")]
               ↑ Order changed ❌
```

**Real Example**: Sorting students by marks, then by name
- Stable: Same marks → Name order preserved
- Unstable: Same marks → Name order may change

---

## E. The Golden Rule of Interviews

```
╔══════════════════════════════════════════════════════╗
║  ALWAYS USE STL sort() IN INTERVIEWS!                ║
║                                                      ║
║  sort(arr.begin(), arr.end());                      ║
║                                                      ║
║  DON'T implement Bubble/Selection/Insertion         ║
║  UNLESS explicitly asked!                            ║
╚══════════════════════════════════════════════════════╝
```

### Why?
1. ✅ Optimized (IntroSort - hybrid algorithm)
2. ✅ Guaranteed O(n log n)
3. ✅ Well-tested and bug-free
4. ✅ Saves time in interviews
5. ✅ Shows you know standard libraries

---

# VIDEO 4: GENERIC TEMPLATES 📝

## Template 1: Basic Sort (Ascending/Descending)
```cpp
#include <algorithm>
#include <vector>
using namespace std;

// Ascending order
void sortAscending(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

// Descending order
void sortDescending(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
}

// Mantra: "sort() for ascending, greater<>() for descending!"
```

**Real Example**:
```cpp
// E-commerce: Sort products by price
vector<int> prices = {50, 20, 100, 30, 80};
sort(prices.begin(), prices.end());  // Low to High
// prices = [20, 30, 50, 80, 100]
```

---

## Template 2: Custom Comparator (Lambda)
```cpp
// Sort by absolute value
sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b);
});

// Sort pairs by second element
sort(pairs.begin(), pairs.end(), [](auto a, auto b) {
    return a.second < b.second;
});

// Sort strings by length
sort(words.begin(), words.end(), [](string a, string b) {
    return a.length() < b.length();
});

// Mantra: "Lambda for custom criteria!"
```

**Real Example**:
```cpp
// Sort employees by salary, then by name
sort(employees.begin(), employees.end(), [](Employee a, Employee b) {
    if (a.salary != b.salary) return a.salary > b.salary;  // High salary first
    return a.name < b.name;  // Same salary → alphabetical
});
```

---

## Template 3: Dutch National Flag (0s, 1s, 2s)
```cpp
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++; mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {  // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
            // Don't increment mid! (need to check swapped element)
        }
    }
}

// Mantra: "0→left, 2→right, 1→middle!"
```

**Real Example**:
```cpp
// Sort traffic lights: Red(0), Yellow(1), Green(2)
vector<int> lights = {2, 0, 1, 2, 1, 0, 0, 2, 1};
sort012(lights);
// Result: [0, 0, 0, 1, 1, 1, 2, 2, 2]
// All Red→Yellow→Green ✅
```

---

## Template 4: Merge Two Sorted Arrays
```cpp
vector<int> mergeSorted(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    
    return result;
}

// Mantra: "Two pointers, compare and merge!"
```

**Real Example**:
```cpp
// Merge two sorted contact lists
vector<string> list1 = {"Alice", "Charlie", "Eve"};
vector<string> list2 = {"Bob", "David", "Frank"};
// Merged: ["Alice", "Bob", "Charlie", "David", "Eve", "Frank"]
```

---

## Template 5: Kth Largest/Smallest
```cpp
// Kth Smallest (1-indexed)
int kthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

// Kth Largest (1-indexed)
int kthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - k];
}

// Mantra: "Sort first, then index!"
```

**Real Example**:
```cpp
// Find 3rd highest scorer in exam
vector<int> marks = {85, 92, 78, 95, 88, 90};
int third = kthLargest(marks, 3);
// Result: 88 (ranks: 95, 92, 90, 88...)
```

---

## Template 6: Sort by Frequency
```cpp
vector<int> sortByFrequency(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;
    
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (freq[a] != freq[b]) return freq[a] > freq[b];  // High freq first
        return a < b;  // Tie → smaller value first
    });
    
    return arr;
}

// Mantra: "Count frequency, sort by count!"
```

**Real Example**:
```cpp
// Most viewed products first
vector<int> productIDs = {101, 102, 101, 103, 101, 102};
sortByFrequency(productIDs);
// Result: [101, 101, 101, 102, 102, 103]
// Product 101 viewed 3 times → shown first!
```

---

## 💪 MEMORY HOOKS & MANTRAS

### Say 10x Before Coding:
1. **"sort() = O(n log n), guaranteed!"**
2. **"Ascending by default, greater<>() for descending!"**
3. **"Dutch Flag: 0→left, 2→right, 1→stay!"**
4. **"Merge sorted: Two pointers, compare smaller!"**
5. **"Custom order? Use lambda comparator!"**

### Memory Hooks:
- 📱 **Phone Contacts** → Sorted alphabetically (easy search!)
- 🛒 **E-commerce** → Sort by price, rating, reviews
- 🎓 **Rank List** → Sorted by marks (descending)
- 📚 **Library** → Books sorted by author, title
- 🚦 **Traffic Lights** → Red, Yellow, Green (Dutch Flag!)

---

