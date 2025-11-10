# 🎯 BINARY SEARCH - COMPLETE GUIDE (ADITYA VERMA METHOD)

*Master Binary Search with Generic Templates & Pattern Recognition*

---

## 📋 TABLE OF CONTENTS

1. [Introduction - The Big Picture](#introduction)
2. [3-Second Recognition](#recognition)
3. [Aditya Verma's 3 Core Patterns](#patterns)
4. [Generic Templates](#templates)
5. [5 Complete Problems with 5-Step Method](#problems)
6. [Dry Run Examples](#dryrun)
7. [Interview Communication](#communication)

---

<a name="introduction"></a>
## 🌟 INTRODUCTION - THE BIG PICTURE

### **What is Binary Search?**

Binary Search is a **"divide and conquer"** algorithm that finds elements in **O(log n)** time by repeatedly dividing the search space in half.

**Real-World Analogy:** 📚
> Imagine finding a word in a dictionary. You don't start from page 1!
> - Open middle page
> - Word before/after? Go left half or right half
> - Repeat until found!
> 
> **That's Binary Search!**

---

### **Why Binary Search is Powerful:**

```
Linear Search (Brute Force):
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] → Find 9
Check: 1, 2, 3, 4, 5, 6, 7, 8, 9 ✓
Time: O(n) = 9 comparisons

Binary Search:
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] → Find 9
Check middle: 5 (too small, go right)
Check middle: 8 (too small, go right)
Check middle: 9 ✓
Time: O(log n) = 3 comparisons

Speedup: 9/3 = 3x faster (for n=10)
For n=1000: 1000/10 = 100x faster!
For n=1,000,000: 1,000,000/20 = 50,000x faster!
```

---

### **The Core Principle:**

```
╔════════════════════════════════════════════════╗
║                                                ║
║  "In SORTED space, eliminate HALF              ║
║   at each step using MID comparison!"          ║
║                                                ║
╚════════════════════════════════════════════════╝
```

---

<a name="recognition"></a>
## ⚡ 3-SECOND RECOGNITION

### **Is it Binary Search? Ask 3 Questions:**

```
┌─────────────────────────────────────────┐
│  1. Is array SORTED/MONOTONIC?   [YES]  │
│  2. Looking for TARGET/BOUNDARY?  [YES] │
│  3. Can eliminate HALF each step? [YES] │
│                                         │
│  ALL YES? → BINARY SEARCH!              │
└─────────────────────────────────────────┘
```

---

### **🔑 MAGIC KEYWORDS:**

| **See This Keyword** | **Pattern** | **Template** |
|---------------------|-------------|--------------|
| "Sorted array", "Find element" | Classic BS | Standard template |
| "First occurrence", "Lower bound" | Boundary (Left) | `high = mid - 1` on match |
| "Last occurrence", "Upper bound" | Boundary (Right) | `low = mid + 1` on match |
| "Minimum capacity", "Maximum pages" | BS on Answer | Define search space |
| "Rotated sorted array" | Modified BS | Find sorted half |
| "Peak element" | Modified BS | Compare neighbors |
| "Square root", "Nth root" | BS on Answer | Check mid² vs target |

---

### **Visual Pattern Recognition:**

```
Problem Type          →  Pattern           →  Key Idea
═══════════════════════════════════════════════════════
"Find x in sorted"    →  Classic BS        →  Standard
"First x"             →  Boundary (Left)   →  Keep going left
"Last x"              →  Boundary (Right)  →  Keep going right
"Minimum that works"  →  BS on Answer      →  Check condition
"Rotated array"       →  Modified BS       →  Find sorted part
```

---

<a name="patterns"></a>
## 🎨 ADITYA VERMA'S 3 CORE PATTERNS

### **Pattern Recognition Framework:**

```
                    BINARY SEARCH
                         |
        ┌────────────────┼────────────────┐
        |                |                |
    Pattern 1        Pattern 2        Pattern 3
    Classic BS       Boundary BS      BS on Answer
        |                |                |
   Find element    First/Last occ.   Min/Max value
   Yes/No search   Lower/Upper bound  that satisfies
                                      a condition
```

---

### **PATTERN 1: CLASSIC BINARY SEARCH** 📍

**Use When:**
- "Find element in sorted array"
- "Does element exist?"
- "Return index if found"

**Key Characteristic:** Looking for **EXACT MATCH**

**Template Structure:**
```cpp
while (low <= high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) return mid;  // Found!
    else if (arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}
return -1;  // Not found
```

**Example Problems:**
- Search in sorted array
- Binary search in infinite array
- Search in rotated sorted array (variation)

---

### **PATTERN 2: BOUNDARY BINARY SEARCH** 🎯

**Use When:**
- "Find FIRST occurrence"
- "Find LAST occurrence"
- "Lower bound" (smallest index with arr[i] >= target)
- "Upper bound" (smallest index with arr[i] > target)
- "Floor" (largest element ≤ target)
- "Ceiling" (smallest element ≥ target)

**Key Characteristic:** Looking for **BOUNDARY/EDGE**

#### **Sub-Pattern 2A: FIRST Occurrence (Go LEFT)**

```cpp
int ans = -1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        ans = mid;
        high = mid - 1;  // 🔥 Keep searching LEFT
    }
    else if (arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}
return ans;
```

**Mantra:** *"Found it? Great! But check if there's one BEFORE (left)"*

#### **Sub-Pattern 2B: LAST Occurrence (Go RIGHT)**

```cpp
int ans = -1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        ans = mid;
        low = mid + 1;  // 🔥 Keep searching RIGHT
    }
    else if (arr[mid] < target) low = mid + 1;
    else high = mid - 1;
}
return ans;
```

**Mantra:** *"Found it? Great! But check if there's one AFTER (right)"*

**Example Problems:**
- First and last position of element
- Count occurrences (last - first + 1)
- Find floor and ceiling
- Lower bound and upper bound

---

### **PATTERN 3: BINARY SEARCH ON ANSWER** 💡

**Use When:**
- "Find MINIMUM capacity/pages/time that works"
- "Find MAXIMUM distance/weight that satisfies condition"
- "Search space is RANGE of values" (not array indices)
- Keywords: "minimum", "maximum", "allocate", "distribute"

**Key Characteristic:** Search space is **ANSWER RANGE**, not array!

**Template Structure:**
```cpp
// Step 1: Define search space (low to high)
int low = minimum_possible_answer;
int high = maximum_possible_answer;
int result = -1;

// Step 2: Binary search on answer
while (low <= high) {
    int mid = low + (high - low) / 2;
    
    // Step 3: Check if 'mid' is a valid answer
    if (isValid(mid)) {
        result = mid;
        // For minimum: search left
        // For maximum: search right
        high = mid - 1;  // or low = mid + 1
    } else {
        low = mid + 1;   // or high = mid - 1
    }
}

return result;

// Helper function to check validity
bool isValid(int mid) {
    // Check if 'mid' satisfies problem condition
    // Return true/false
}
```

**Mantra:** *"Answer is BETWEEN low and high. Check if mid WORKS!"*

**Example Problems:**
- Allocate minimum pages
- Painter's partition
- Aggressive cows
- Capacity to ship packages
- Koko eating bananas
- Square root / Nth root

---

### **How to Choose Pattern?**

```
╔══════════════════════════════════════════════════╗
║  DECISION TREE                                   ║
╠══════════════════════════════════════════════════╣
║                                                  ║
║  Binary Search Problem?                          ║
║         |                                        ║
║         v                                        ║
║  Is array given and sorted?                      ║
║    ├─ YES → Looking for exact element?           ║
║    │         ├─ YES → PATTERN 1 (Classic)        ║
║    │         └─ NO → First/Last?                 ║
║    │                  └─ YES → PATTERN 2         ║
║    │                                             ║
║    └─ NO → Finding min/max value?                ║
║              └─ YES → PATTERN 3 (BS on Answer)   ║
║                                                  ║
╚══════════════════════════════════════════════════╝
```

---

<a name="templates"></a>
## 📝 GENERIC TEMPLATES (MEMORIZE THESE!)

### **Template 1: CLASSIC BINARY SEARCH**

```cpp
// ========================================
// PATTERN 1: CLASSIC BINARY SEARCH
// Use when: Find element in sorted array
// ========================================

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow
        
        if (arr[mid] == target) {
            return mid;  // Found! Return index
        }
        else if (arr[mid] < target) {
            low = mid + 1;  // Search right half
        }
        else {
            high = mid - 1;  // Search left half
        }
    }
    
    return -1;  // Not found
}

// Time: O(log n) | Space: O(1)
```

**Mantra:** *"Equal found, Less go right, More go left"*

---

### **Template 2A: FIRST OCCURRENCE (LOWER BOUND)**

```cpp
// ========================================
// PATTERN 2A: FIRST OCCURRENCE
// Use when: Find first occurrence, lower bound
// ========================================

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;  // Store result
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;          // Store current position
            high = mid - 1;     // 🔥 Keep searching LEFT
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return ans;  // First occurrence or -1
}

// Time: O(log n) | Space: O(1)
```

**Mantra:** *"Found? Save it! But check LEFT for earlier one!"*

---

### **Template 2B: LAST OCCURRENCE (UPPER BOUND)**

```cpp
// ========================================
// PATTERN 2B: LAST OCCURRENCE
// Use when: Find last occurrence, upper bound
// ========================================

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;  // Store result
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;          // Store current position
            low = mid + 1;      // 🔥 Keep searching RIGHT
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return ans;  // Last occurrence or -1
}

// Time: O(log n) | Space: O(1)
```

**Mantra:** *"Found? Save it! But check RIGHT for later one!"*

---

### **Template 3: BINARY SEARCH ON ANSWER**

```cpp
// ========================================
// PATTERN 3: BINARY SEARCH ON ANSWER
// Use when: Find min/max value satisfying condition
// ========================================

// Helper function: Check if 'mid' is valid answer
bool isValid(vector<int>& arr, int mid, int k) {
    // Check if 'mid' satisfies the problem condition
    // Example: Can we allocate with capacity 'mid'?
    
    int count = 1;  // Example counter
    int sum = 0;    // Example accumulator
    
    for (int x : arr) {
        if (sum + x > mid) {
            count++;
            sum = x;
            if (count > k) return false;
        } else {
            sum += x;
        }
    }
    
    return true;
}

int binarySearchOnAnswer(vector<int>& arr, int k) {
    // Step 1: Define search space
    int low = *max_element(arr.begin(), arr.end());  // Minimum possible
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible
    int result = -1;
    
    // Step 2: Binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Step 3: Check if 'mid' works
        if (isValid(arr, mid, k)) {
            result = mid;
            high = mid - 1;  // Try smaller (for minimum)
            // low = mid + 1;  // Try larger (for maximum)
        } else {
            low = mid + 1;   // Need larger value
            // high = mid - 1;  // Need smaller value
        }
    }
    
    return result;
}

// Time: O(n log(sum)) | Space: O(1)
// where sum = range of search space
```

**Mantra:** *"Define range, check if mid works, adjust accordingly!"*

---

## 🔥 THE GOLDEN FORMULAS

### **Formula 1: Mid Calculation (Avoid Overflow)**
```cpp
// ❌ WRONG (can overflow):
int mid = (low + high) / 2;

// ✅ CORRECT:
int mid = low + (high - low) / 2;

// Why? If low=2^30 and high=2^30, low+high overflows!
// But high-low fits in int, then add to low = safe!
```

---

### **Formula 2: Count Occurrences**
```cpp
// If target appears multiple times:
int first = firstOccurrence(arr, target);
int last = lastOccurrence(arr, target);

if (first == -1) return 0;  // Not found

int count = last - first + 1;
```

---

### **Formula 3: Floor and Ceiling**
```cpp
// Floor = Largest element ≤ target
int floor(vector<int>& arr, int target) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;  // Try larger
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// Ceiling = Smallest element ≥ target
int ceiling(vector<int>& arr, int target) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;  // Try smaller
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

---

<a name="problems"></a>
## 🎯 5 COMPLETE PROBLEMS (ADITYA VERMA'S 5-STEP METHOD)

### **Problem 1: Classic Binary Search** ⭐⭐⭐⭐⭐

#### **STEP 1: Problem Statement + Input/Output**

**Problem:**  
Given a **sorted array** of integers and a **target** value, return the **index** of the target if found, otherwise return **-1**.

**Input:**
```
arr = [1, 3, 5, 7, 9, 11, 13]
target = 7
```

**Output:**
```
3
```

**Explanation:** 7 is at index 3

---

#### **STEP 2: Identification (When to Use?)**

**Ask yourself:**
1. Is array sorted? → ✅ YES
2. Looking for exact element? → ✅ YES
3. Need single position? → ✅ YES

**Pattern:** Classic Binary Search (Pattern 1)

**Real-World Connection:** 📖
> Like finding a word in dictionary! Open middle, check if before/after, repeat.

---

#### **STEP 3: Abstract/Approach (Think Before Coding)**

**Approach:**
```
1. Start with entire array (low=0, high=n-1)
2. Find middle element
3. Three cases:
   - arr[mid] == target → Found! Return mid
   - arr[mid] < target → Target must be in RIGHT half
   - arr[mid] > target → Target must be in LEFT half
4. Repeat until found or low > high
```

**Why it works:**
- Array is sorted, so we can eliminate half at each step
- If mid < target, ALL elements before mid are also < target
- If mid > target, ALL elements after mid are also > target

---

#### **STEP 4: Dry Run (Complete Trace)**

**Input:** arr = [1, 3, 5, 7, 9, 11, 13], target = 7

```
Initial: low=0, high=6

Iteration 1:
-----------
low=0, high=6
mid = 0 + (6-0)/2 = 3
arr[3] = 7
7 == 7? YES! ✅
Return 3

Total comparisons: 1
```

**Another example:** target = 11

```
Iteration 1:
-----------
low=0, high=6
mid = 3
arr[3] = 7
7 < 11? YES → Search right
low = mid + 1 = 4

Iteration 2:
-----------
low=4, high=6
mid = 4 + (6-4)/2 = 5
arr[5] = 11
11 == 11? YES! ✅
Return 5

Total comparisons: 2
```

---

#### **STEP 5: Code (With Comments)**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// PATTERN 1: CLASSIC BINARY SEARCH
int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    // Loop until search space is valid
    while (low <= high) {
        // Calculate mid (avoid overflow)
        int mid = low + (high - low) / 2;
        
        // Case 1: Found target
        if (arr[mid] == target) {
            return mid;
        }
        
        // Case 2: Target in right half
        else if (arr[mid] < target) {
            low = mid + 1;  // Eliminate left half
        }
        
        // Case 3: Target in left half
        else {
            high = mid - 1;  // Eliminate right half
        }
    }
    
    // Target not found
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
```

**Interview Explanation:**
> "Sir, since array is sorted, I'll use binary search. Start with entire array, find middle, compare with target. If match, return. If target is larger, search right half. If smaller, search left half. Repeat until found or search space exhausted. Time O(log n), Space O(1)."

---

### **Problem 2: First and Last Occurrence** ⭐⭐⭐⭐⭐

#### **STEP 1: Problem Statement + Input/Output**

**Problem:**  
Given a **sorted array** with **duplicates** and a **target**, find the **first** and **last** occurrence of the target.

**Input:**
```
arr = [1, 2, 2, 2, 3, 4, 5]
target = 2
```

**Output:**
```
[1, 3]
```

**Explanation:** 2 appears from index 1 to 3

---

#### **STEP 2: Identification**

**Ask yourself:**
1. Array sorted? → ✅ YES
2. Has duplicates? → ✅ YES
3. Need BOUNDARY positions? → ✅ YES

**Pattern:** Boundary Binary Search (Pattern 2)

**Real-World Connection:** 📅
> Like finding first and last day you were sick in a month! Check dates, find start and end.

---

#### **STEP 3: Approach**

**Approach:**
```
1. First Occurrence:
   - Do binary search
   - When found, DON'T stop!
   - Keep searching LEFT (high = mid - 1)
   - Store every occurrence found

2. Last Occurrence:
   - Do binary search
   - When found, DON'T stop!
   - Keep searching RIGHT (low = mid + 1)
   - Store every occurrence found
```

**Key Insight:**  
Normal BS stops when found. Boundary BS keeps searching for better answer!

---

#### **STEP 4: Dry Run**

**Input:** arr = [1, 2, 2, 2, 3, 4, 5], target = 2

**Finding FIRST occurrence:**
```
Iteration 1:
-----------
low=0, high=6
mid = 3
arr[3] = 2
Found 2! Store ans=3
But check LEFT: high = 3-1 = 2

Iteration 2:
-----------
low=0, high=2
mid = 1
arr[1] = 2
Found 2 again! Update ans=1
Check LEFT: high = 1-1 = 0

Iteration 3:
-----------
low=0, high=0
mid = 0
arr[0] = 1
1 < 2? YES → low = 1

low > high, STOP
First occurrence = 1 ✅
```

**Finding LAST occurrence:**
```
Iteration 1:
-----------
low=0, high=6
mid = 3
arr[3] = 2
Found 2! Store ans=3
But check RIGHT: low = 3+1 = 4

Iteration 2:
-----------
low=4, high=6
mid = 5
arr[5] = 4
4 > 2? YES → high = 4

Iteration 3:
-----------
low=4, high=4
mid = 4
arr[4] = 3
3 > 2? YES → high = 3

low > high, STOP
Last occurrence = 3 ✅
```

---

#### **STEP 5: Code**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// PATTERN 2A: FIRST OCCURRENCE
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;          // Store this position
            high = mid - 1;     // Keep searching LEFT
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return ans;
}

// PATTERN 2B: LAST OCCURRENCE
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;          // Store this position
            low = mid + 1;      // Keep searching RIGHT
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return ans;
}

vector<int> firstAndLast(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);
    
    return {first, last};
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;
    
    vector<int> result = firstAndLast(arr, target);
    
    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;
    
    // Count occurrences
    if (result[0] != -1) {
        int count = result[1] - result[0] + 1;
        cout << "Total occurrences: " << count << endl;
    }
    
    return 0;
}

// Time: O(log n) for each search = O(log n)
// Space: O(1)
```

**Interview Explanation:**
> "Sir, this is boundary binary search. For first occurrence, when I find target, I don't stop - I keep searching left to find if there's an earlier one. Similarly for last, I search right. Both are O(log n). To count occurrences, I use formula: last - first + 1."

---

### **Problem 3: Binary Search on Answer - Allocate Minimum Pages** ⭐⭐⭐⭐⭐

#### **STEP 1: Problem Statement**

**Problem:**  
Given an array representing **pages in books** and **number of students**, allocate books such that:
1. Each student gets at least one book
2. Books are allocated in **contiguous** manner
3. **Minimize** the maximum pages allocated to any student

**Input:**
```
books = [12, 34, 67, 90]
students = 2
```

**Output:**
```
113
```

**Explanation:**  
Allocation: [12, 34, 67] to student 1 (113 pages), [90] to student 2 (90 pages)  
Maximum = 113 (minimum possible maximum)

---

#### **STEP 2: Identification**

**Ask yourself:**
1. Array given but NOT searching in it? → ✅ YES
2. Finding MIN/MAX VALUE that works? → ✅ YES
3. Can check if value is valid? → ✅ YES

**Pattern:** Binary Search on Answer (Pattern 3)

**Real-World Connection:** 🎒
> Like distributing workload among team members! Find minimum maximum load.

---

#### **STEP 3: Approach**

**Approach:**
```
1. Search space = [max element, sum of all elements]
   Why? Minimum possible = largest book
        Maximum possible = all books to one student

2. For each 'mid' value, check:
   "Can we allocate books such that no student gets > mid pages?"

3. If yes:
   - This mid works!
   - Try smaller (search left): high = mid - 1

4. If no:
   - Need more capacity
   - Search right: low = mid + 1
```

**Helper Function (isValid):**
```
Given capacity 'mid', can we allocate?
- Start with student 1, sum = 0
- For each book:
  - If sum + book <= mid: Give to current student
  - Else: Need new student, give to them
- If students needed <= k: Valid!
```

---

#### **STEP 4: Dry Run**

**Input:** books = [12, 34, 67, 90], students = 2

```
Search space:
low = max(books) = 90
high = sum(books) = 203

Iteration 1:
-----------
mid = 90 + (203-90)/2 = 146

Check if 146 works:
Student 1: 12 + 34 + 67 = 113 ≤ 146 ✓
           113 + 90 = 203 > 146 ✗ Need new student
Student 2: 90 ≤ 146 ✓
Total students = 2 ≤ 2 ✓
Valid! Store result = 146
Try smaller: high = 145

Iteration 2:
-----------
low=90, high=145
mid = 117

Check if 117 works:
Student 1: 12 + 34 + 67 = 113 ≤ 117 ✓
           113 + 90 = 203 > 117 ✗
Student 2: 90 ≤ 117 ✓
Valid! Update result = 117
Try smaller: high = 116

Iteration 3:
-----------
low=90, high=116
mid = 103

Check if 103 works:
Student 1: 12 + 34 = 46 ≤ 103 ✓
           46 + 67 = 113 > 103 ✗
Student 2: 67 ≤ 103 ✓
           67 + 90 = 157 > 103 ✗
Student 3: 90 ≤ 103 ✓
Total students = 3 > 2 ✗
Invalid! Need more capacity
low = 104

... continues ...

Final answer: 113
```

---

#### **STEP 5: Code**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// PATTERN 3: BINARY SEARCH ON ANSWER

// Helper: Check if we can allocate with max capacity 'mid'
bool isValid(vector<int>& books, int students, int mid) {
    int studentCount = 1;  // Start with first student
    int pagesSum = 0;
    
    for (int pages : books) {
        // If single book > mid, impossible
        if (pages > mid) return false;
        
        // If adding this book exceeds mid
        if (pagesSum + pages > mid) {
            // Need new student
            studentCount++;
            pagesSum = pages;
            
            // If more students needed than available
            if (studentCount > students) {
                return false;
            }
        } else {
            // Add to current student
            pagesSum += pages;
        }
    }
    
    return true;  // Successfully allocated
}

int allocateMinimumPages(vector<int>& books, int students) {
    int n = books.size();
    
    // Edge case: More students than books
    if (students > n) return -1;
    
    // Define search space
    int low = *max_element(books.begin(), books.end());  // Min possible
    int high = accumulate(books.begin(), books.end(), 0); // Max possible
    int result = -1;
    
    // Binary search on answer
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if 'mid' is valid capacity
        if (isValid(books, students, mid)) {
            result = mid;       // Store this answer
            high = mid - 1;     // Try smaller
        } else {
            low = mid + 1;      // Need larger capacity
        }
    }
    
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    
    int result = allocateMinimumPages(books, students);
    
    cout << "Minimum maximum pages: " << result << endl;
    
    return 0;
}

// Time: O(n * log(sum - max))
// Space: O(1)
```

**Interview Explanation:**
> "Sir, this is binary search on answer. I'm not searching in array - I'm searching for the ANSWER itself! Answer lies between max element (minimum possible) and sum (maximum possible). For each mid, I check: can I allocate with this capacity? If yes, try smaller. If no, need larger. The isValid function checks allocation by simulating distribution. Time is O(n log sum)."

---

### **Problem 4: Search in Rotated Sorted Array** ⭐⭐⭐⭐⭐

#### **STEP 1: Problem Statement**

**Problem:**  
Array was sorted, then **rotated** at some pivot. Find target element.

**Input:**
```
arr = [4, 5, 6, 7, 0, 1, 2]
target = 0
```

**Output:**
```
4
```

**Explanation:** 0 is at index 4

**Original sorted:** [0, 1, 2, 4, 5, 6, 7]  
**After rotation:** [4, 5, 6, 7, 0, 1, 2]

---

#### **STEP 2: Identification**

**Ask yourself:**
1. Array was sorted? → ✅ YES
2. Now rotated? → ✅ YES
3. Still has sorted portions? → ✅ YES

**Pattern:** Modified Binary Search (Variation of Pattern 1)

**Real-World Connection:** 🔄
> Like a clock! Numbers 1-12 in order, but start from random position.

---

#### **STEP 3: Approach**

**Key Insight:**  
After rotation, ONE HALF is always sorted!

**Approach:**
```
1. Find middle element
2. Check which half is sorted:
   - If left half sorted (arr[low] <= arr[mid]):
     - Check if target in this range
     - Yes? Search left
     - No? Search right
   
   - If right half sorted:
     - Check if target in this range
     - Yes? Search right
     - No? Search left

3. Repeat until found
```

---

#### **STEP 4: Dry Run**

**Input:** arr = [4, 5, 6, 7, 0, 1, 2], target = 0

```
Iteration 1:
-----------
low=0, high=6
mid = 3
arr[mid] = 7
arr[low]=4 <= arr[mid]=7? YES → Left half [4,5,6,7] is sorted

Is target 0 in [4,7]? NO
So search RIGHT half
low = mid + 1 = 4

Iteration 2:
-----------
low=4, high=6
mid = 5
arr[mid] = 1
arr[low]=0 <= arr[mid]=1? YES → Left half [0,1] is sorted

Is target 0 in [0,1]? YES
Search LEFT half
high = mid - 1 = 4

Iteration 3:
-----------
low=4, high=4
mid = 4
arr[mid] = 0
0 == 0? YES! ✅
Return 4
```

---

#### **STEP 5: Code**

```cpp
#include <iostream>
#include <vector>
using namespace std;

// MODIFIED BINARY SEARCH: Rotated Array
int searchRotated(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Found target
        if (arr[mid] == target) {
            return mid;
        }
        
        // Determine which half is sorted
        
        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if target is in this sorted range
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;  // Search left
            } else {
                low = mid + 1;   // Search right
            }
        }
        // Right half is sorted
        else {
            // Check if target is in this sorted range
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;   // Search right
            } else {
                high = mid - 1;  // Search left
            }
        }
    }
    
    return -1;  // Not found
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    int result = searchRotated(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

// Time: O(log n)
// Space: O(1)
```

**Interview Explanation:**
> "Sir, rotated array has one half always sorted. I find middle, check which half is sorted, then check if target is in that sorted range. If yes, search there. If no, search other half. Still O(log n) because we eliminate half at each step."

---

### **Problem 5: Square Root (Floor Value)** ⭐⭐⭐⭐⭐

#### **STEP 1: Problem Statement**

**Problem:**  
Find square root of a number **without using sqrt()** function. Return **floor** value.

**Input:**
```
n = 28
```

**Output:**
```
5
```

**Explanation:** √28 = 5.29..., floor = 5

---

#### **STEP 2: Identification**

**Ask yourself:**
1. Looking for value (not searching in array)? → ✅ YES
2. Answer is between 0 and n? → ✅ YES
3. Can check if value works? → ✅ YES

**Pattern:** Binary Search on Answer (Pattern 3)

**Real-World Connection:** 📏
> Like measuring square tiles needed! Try sizes, check if area fits.

---

#### **STEP 3: Approach**

**Approach:**
```
1. Search space = [0, n]
2. For each 'mid', check:
   - mid * mid == n? Found exact root!
   - mid * mid < n? mid could be answer, try larger
   - mid * mid > n? mid too large, try smaller

3. Keep tracking largest mid where mid² ≤ n
```

**Why it works:**  
If mid² ≤ n and (mid+1)² > n, then mid is floor of √n

---

#### **STEP 4: Dry Run**

**Input:** n = 28

```
Search space: low=0, high=28

Iteration 1:
-----------
mid = 14
14² = 196 > 28? YES
Too large! high = 13

Iteration 2:
-----------
low=0, high=13
mid = 6
6² = 36 > 28? YES
Too large! high = 5

Iteration 3:
-----------
low=0, high=5
mid = 2
2² = 4 < 28? YES
Could be answer! Store ans=2
Try larger: low = 3

Iteration 4:
-----------
low=3, high=5
mid = 4
4² = 16 < 28? YES
Better answer! Update ans=4
Try larger: low = 5

Iteration 5:
-----------
low=5, high=5
mid = 5
5² = 25 < 28? YES
Even better! Update ans=5
Try larger: low = 6

low > high, STOP
Answer: 5 ✅
```

---

#### **STEP 5: Code**

```cpp
#include <iostream>
using namespace std;

// PATTERN 3: BINARY SEARCH ON ANSWER
int mySqrt(int n) {
    // Edge cases
    if (n == 0 || n == 1) return n;
    
    int low = 1, high = n;
    int ans = 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is perfect square root
        if ((long long)mid * mid == n) {
            return mid;  // Exact root found
        }
        
        // mid² < n: mid could be answer (floor)
        else if ((long long)mid * mid < n) {
            ans = mid;      // Store this as potential answer
            low = mid + 1;  // Try larger
        }
        
        // mid² > n: mid too large
        else {
            high = mid - 1;  // Try smaller
        }
    }
    
    return ans;  // Floor value
}

int main() {
    int n = 28;
    
    int result = mySqrt(n);
    
    cout << "Square root (floor) of " << n << " = " << result << endl;
    cout << "Verification: " << result << "² = " << result * result << endl;
    cout << "Next square: " << (result + 1) << "² = " << (result + 1) * (result + 1) << endl;
    
    return 0;
}

// Time: O(log n)
// Space: O(1)
```

**Interview Explanation:**
> "Sir, this is binary search on answer. Answer is between 0 and n. For each mid, I check if mid² equals, less than, or greater than n. If less, mid could be floor value, so I store it and try larger. If greater, try smaller. I use long long to avoid overflow. Time O(log n)."

---

## 🎤 INTERVIEW COMMUNICATION SCRIPTS

### **Opening Statement (First 10 Seconds)**

**You Say:**
> "Sir, I notice [array is sorted / we're finding min-max value / rotated array].  
> This is [Pattern 1/2/3] binary search problem.  
> I'll use [classic BS / boundary BS / BS on answer] approach.  
> Time complexity will be O(log n)."

---

### **Pattern Recognition Script**

**For Classic BS:**
> "Sir, array is sorted and we need to find exact element. I'll use standard binary search template - compare with mid, go left or right."

**For Boundary BS:**
> "Sir, we need [first/last] occurrence. I'll modify binary search - when found, I won't stop but keep searching [left/right] to find better answer."

**For BS on Answer:**
> "Sir, we're not searching in array but finding min/max value. I'll define search space from [low to high], then binary search on that range, checking if each mid value works using helper function."

---

### **Mid-Coding Script**

**While writing code, say:**
```
"Declaring low and high pointers..."
"While loop with condition low <= high..."
"Calculating mid avoiding overflow..."
"Comparing arr[mid] with target..."
"If match [found/store and continue searching]..."
"Update pointers accordingly..."
```

---

### **Dry Run Script**

**Always say:**
> "Sir, let me trace with example:  
> Initially low=__, high=__  
> Mid=__, arr[mid]=__, compare with target...  
> [Explain decision]  
> Update pointers to low=__, high=__  
> Repeat... Found at iteration __"

---

## ❌ COMMON MISTAKES & FIXES

### **Mistake 1: Integer Overflow**
```cpp
// ❌ WRONG:
int mid = (low + high) / 2;  // Overflows if low+high > INT_MAX

// ✅ CORRECT:
int mid = low + (high - low) / 2;
```

---

### **Mistake 2: Infinite Loop**
```cpp
// ❌ WRONG:
while (low < high) {  // Can cause infinite loop
    int mid = (low + high) / 2;
    if (arr[mid] < target) low = mid;  // mid can equal low
    else high = mid;
}

// ✅ CORRECT:
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < target) low = mid + 1;  // Always move
    else high = mid - 1;
}
```

---

### **Mistake 3: Not Handling Duplicates**
```cpp
// For first occurrence:
if (arr[mid] == target) {
    return mid;  // ❌ WRONG: Stops too early
}

// ✅ CORRECT:
if (arr[mid] == target) {
    ans = mid;
    high = mid - 1;  // Keep searching left
}
```

---

### **Mistake 4: Wrong Boundary Update**
```cpp
// ❌ WRONG:
if (isValid(mid)) {
    result = mid;
    low = mid;  // Can cause infinite loop
}

// ✅ CORRECT:
if (isValid(mid)) {
    result = mid;
    high = mid - 1;  // Move boundary
}
```
---