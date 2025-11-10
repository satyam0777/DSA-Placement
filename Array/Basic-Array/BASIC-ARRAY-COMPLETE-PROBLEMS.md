# BASIC ARRAY - 5 COMPLETE PROBLEMS 🎯
*Following Aditya Verma's 5-Step Methodology*

---

# PROBLEM 1: FIND MINIMUM AND MAXIMUM 📊

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers, find the **minimum** and **maximum** elements in the array.

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

### Constraints:
- `1 ≤ n ≤ 10^5`
- `-10^9 ≤ arr[i] ≤ 10^9`

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Find", "Minimum", "Maximum"  
✅ **Pattern**: Single pass scan through array  
✅ **Approach**: Compare each element with current min/max  

### Why This Pattern?
- Need to examine every element once
- No sorting required (would be O(n log n))
- Simple comparison logic

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
1. Assume first element is both min and max
2. For each remaining element:
   - If smaller than min → update min
   - If larger than max → update max
3. Return min and max
```

### The Key Insight:
**"We only need ONE pass through the array!"**

### Time Complexity: O(n) - Single traversal
### Space Complexity: O(1) - Only two variables

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [3, 5, 1, 8, 2, 9, 4]`

```
Initialization:
min = arr[0] = 3
max = arr[0] = 3

i = 1: arr[1] = 5
  5 > 3 (min) → No change to min
  5 > 3 (max) → max = 5
  State: min = 3, max = 5

i = 2: arr[2] = 1
  1 < 3 (min) → min = 1
  1 < 5 (max) → No change to max
  State: min = 1, max = 5

i = 3: arr[3] = 8
  8 > 1 (min) → No change to min
  8 > 5 (max) → max = 8
  State: min = 1, max = 8

i = 4: arr[4] = 2
  2 > 1 (min) → No change to min
  2 < 8 (max) → No change to max
  State: min = 1, max = 8

i = 5: arr[5] = 9
  9 > 1 (min) → No change to min
  9 > 8 (max) → max = 9
  State: min = 1, max = 9

i = 6: arr[6] = 4
  4 > 1 (min) → No change to min
  4 < 9 (max) → No change to max
  State: min = 1, max = 9

Final Answer: min = 1, max = 9 ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinMax(int arr[], int n) {
    // Initialize with first element
    int minVal = arr[0];
    int maxVal = arr[0];
    
    // Traverse remaining elements
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];  // Update minimum
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];  // Update maximum
        }
    }
    
    return {minVal, maxVal};
}

int main() {
    int arr[] = {3, 5, 1, 8, 2, 9, 4};
    int n = 7;
    
    pair<int, int> result = findMinMax(arr, n);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;
    
    return 0;
}
```

### Key Points:
- ✅ Single pass O(n)
- ✅ No extra space O(1)
- ✅ Works with negative numbers
- ✅ Handles single element array

---
---

# PROBLEM 2: REVERSE AN ARRAY 🔄

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers, reverse the array **in-place** (without using extra space).

### Input:
```
arr = [1, 2, 3, 4, 5]
n = 5
```

### Output:
```
arr = [5, 4, 3, 2, 1]
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `-10^9 ≤ arr[i] ≤ 10^9`
- Must modify original array (in-place)

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Reverse", "In-place"  
✅ **Pattern**: Two Pointer Technique  
✅ **Approach**: Swap elements from both ends moving inward  

### Why Two Pointers?
- No need to copy entire array
- Swap first with last, second with second-last, etc.
- O(1) space solution

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
1. Place two pointers:
   - left = 0 (start)
   - right = n - 1 (end)
2. While left < right:
   - Swap arr[left] and arr[right]
   - Move left forward (left++)
   - Move right backward (right--)
3. Stop when pointers meet/cross
```

### The Key Insight:
**"Swap and move inward from both ends!"**

### Visual:
```
[1, 2, 3, 4, 5]
 ↑           ↑
left       right    Swap → [5, 2, 3, 4, 1]
    ↑       ↑
   left   right     Swap → [5, 4, 3, 2, 1]
       ↑
    left=right      Stop!
```

### Time Complexity: O(n) - n/2 swaps
### Space Complexity: O(1) - Only temp variable

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [1, 2, 3, 4, 5]`

```
Initial State:
arr = [1, 2, 3, 4, 5]
left = 0, right = 4

Step 1: left < right? (0 < 4) → YES
  Swap arr[0] and arr[4]
  temp = arr[0] = 1
  arr[0] = arr[4] = 5
  arr[4] = temp = 1
  arr = [5, 2, 3, 4, 1]
  left++, right-- → left = 1, right = 3

Step 2: left < right? (1 < 3) → YES
  Swap arr[1] and arr[3]
  temp = arr[1] = 2
  arr[1] = arr[3] = 4
  arr[3] = temp = 2
  arr = [5, 4, 3, 2, 1]
  left++, right-- → left = 2, right = 2

Step 3: left < right? (2 < 2) → NO (Equal)
  Stop! (Middle element stays in place)

Final Answer: [5, 4, 3, 2, 1] ✅
```

### Edge Case: Even Length Array
```
arr = [1, 2, 3, 4]
left = 0, right = 3

Swap: [4, 2, 3, 1] → left = 1, right = 2
Swap: [4, 3, 2, 1] → left = 2, right = 1
Stop! (left > right)

Result: [4, 3, 2, 1] ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        // Move pointers
        left++;
        right--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    reverseArray(arr, n);
    
    cout << "Reversed: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
```

### Alternative: Using Built-in
```cpp
reverse(arr, arr + n);  // STL reverse
```

### Key Points:
- ✅ In-place reversal O(1) space
- ✅ Works for even and odd length
- ✅ Two pointer pattern
- ✅ No extra array needed

---
---

# PROBLEM 3: LINEAR SEARCH 🔍

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers and a target value `key`, find the **index** of the first occurrence of `key` in the array. Return `-1` if not found.

### Input:
```
arr = [10, 20, 30, 40, 50, 30]
key = 30
```

### Output:
```
Index: 2  (First occurrence of 30)
```

### Input 2:
```
arr = [10, 20, 30, 40, 50]
key = 60
```

### Output 2:
```
Index: -1  (Not found)
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `-10^9 ≤ arr[i], key ≤ 10^9`

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Find", "Search", "Index of"  
✅ **Pattern**: Linear Search (Sequential Scan)  
✅ **Approach**: Check each element one by one  

### When to Use Linear Search?
- Array is **unsorted** (cannot use binary search)
- Need to find **first occurrence**
- Simple and straightforward

### Linear vs Binary Search:
| **Linear Search** | **Binary Search** |
|-------------------|-------------------|
| Unsorted array | Sorted array required |
| O(n) time | O(log n) time |
| Simple | More complex |

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
1. Start from index 0
2. For each element:
   - If arr[i] == key → return i (found!)
3. If loop completes → return -1 (not found)
```

### The Key Insight:
**"Scan left to right, return immediately when found!"**

### Time Complexity: 
- Best Case: O(1) - Element at first position
- Average Case: O(n/2) = O(n)
- Worst Case: O(n) - Element at last or not present

### Space Complexity: O(1) - No extra space

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [10, 20, 30, 40, 50, 30]`, `key = 30`

```
Searching for key = 30

i = 0: arr[0] = 10
  10 == 30? → NO
  Continue...

i = 1: arr[1] = 20
  20 == 30? → NO
  Continue...

i = 2: arr[2] = 30
  30 == 30? → YES! Found!
  Return index 2 ✅

(Note: We don't check arr[5] = 30, 
 because we found first occurrence at index 2)
```

### Dry Run 2: Element Not Found
```
Input: arr = [10, 20, 30, 40, 50], key = 60

i = 0: arr[0] = 10 → 10 != 60
i = 1: arr[1] = 20 → 20 != 60
i = 2: arr[2] = 30 → 30 != 60
i = 3: arr[3] = 40 → 40 != 60
i = 4: arr[4] = 50 → 50 != 60

Loop completed without finding key
Return -1 ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    // Scan array from left to right
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Found! Return index
        }
    }
    return -1;  // Not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 30};
    int n = 6;
    int key = 30;
    
    int result = linearSearch(arr, n, key);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    
    return 0;
}
```

### Variant: Find All Occurrences
```cpp
vector<int> findAllOccurrences(int arr[], int n, int key) {
    vector<int> indices;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            indices.push_back(i);  // Store all indices
        }
    }
    return indices;
}
```

### Variant: Count Occurrences
```cpp
int countOccurrences(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) count++;
    }
    return count;
}
```

### Key Points:
- ✅ Works on unsorted arrays
- ✅ Returns first occurrence
- ✅ O(n) time, O(1) space
- ✅ Simple and intuitive

---
---

# PROBLEM 4: REMOVE DUPLICATES (PRESERVE ORDER) 🗑️

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers, remove all duplicate elements while **preserving the original order** of first occurrences. Return the new size of the array.

### Input:
```
arr = [10, 20, 30, 20, 40, 10, 50]
n = 7
```

### Output:
```
Modified arr = [10, 20, 30, 40, 50, _, _]
New size = 5
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `-10^9 ≤ arr[i] ≤ 10^9`
- Preserve order of first occurrence
- Can modify original array

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Remove duplicates", "Preserve order"  
✅ **Pattern**: Hashing (Set) + Write Index  
✅ **Approach**: Track seen elements, write only unique ones  

### Why Use Set?
- O(1) lookup to check if element seen before
- Maintain order by using write index
- Don't need sorted array

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
1. Create empty HashSet (to track seen elements)
2. Use writeIndex = 0 (where to write next unique element)
3. For each element in array:
   - If NOT in set:
     * Add to set
     * Write to arr[writeIndex]
     * Increment writeIndex
   - If already in set:
     * Skip (it's a duplicate)
4. Return writeIndex (new size)
```

### The Key Insight:
**"Seen it? Skip it. New? Write it!"**

### Visual Example:
```
arr = [10, 20, 30, 20, 40, 10]
seen = {}
writeIndex = 0

10 → Not seen → Write at [0] → seen = {10}
20 → Not seen → Write at [1] → seen = {10, 20}
30 → Not seen → Write at [2] → seen = {10, 20, 30}
20 → Seen! → Skip
40 → Not seen → Write at [3] → seen = {10, 20, 30, 40}
10 → Seen! → Skip

Result: [10, 20, 30, 40, _, _]
New size = 4
```

### Time Complexity: O(n) - Single pass
### Space Complexity: O(n) - HashSet storage

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [10, 20, 30, 20, 40, 10, 50]`

```
Initialization:
seen = {}  (empty set)
writeIndex = 0
arr = [10, 20, 30, 20, 40, 10, 50]

Step 1: i = 0, arr[0] = 10
  Is 10 in seen? → NO
  seen.insert(10) → seen = {10}
  arr[writeIndex] = arr[0] = 10
  writeIndex++ → writeIndex = 1
  arr = [10, 20, 30, 20, 40, 10, 50]
           ↑
      write here next

Step 2: i = 1, arr[1] = 20
  Is 20 in seen? → NO
  seen.insert(20) → seen = {10, 20}
  arr[writeIndex] = arr[1] = 20
  writeIndex++ → writeIndex = 2
  arr = [10, 20, 30, 20, 40, 10, 50]
               ↑
          write here next

Step 3: i = 2, arr[2] = 30
  Is 30 in seen? → NO
  seen.insert(30) → seen = {10, 20, 30}
  arr[writeIndex] = arr[2] = 30
  writeIndex++ → writeIndex = 3
  arr = [10, 20, 30, 20, 40, 10, 50]
                   ↑
              write here next

Step 4: i = 3, arr[3] = 20
  Is 20 in seen? → YES! (Duplicate)
  Skip! (Don't write, don't increment writeIndex)
  arr = [10, 20, 30, 20, 40, 10, 50]
                   ↑
              (same position)

Step 5: i = 4, arr[4] = 40
  Is 40 in seen? → NO
  seen.insert(40) → seen = {10, 20, 30, 40}
  arr[writeIndex] = arr[4] = 40
  writeIndex++ → writeIndex = 4
  arr = [10, 20, 30, 40, 40, 10, 50]
                       ↑
                  write here next

Step 6: i = 5, arr[5] = 10
  Is 10 in seen? → YES! (Duplicate)
  Skip!
  arr = [10, 20, 30, 40, 40, 10, 50]
                       ↑
                  (same position)

Step 7: i = 6, arr[6] = 50
  Is 50 in seen? → NO
  seen.insert(50) → seen = {10, 20, 30, 40, 50}
  arr[writeIndex] = arr[6] = 50
  writeIndex++ → writeIndex = 5
  arr = [10, 20, 30, 40, 50, 10, 50]

Final State:
arr = [10, 20, 30, 40, 50, _, _]
      ↑____________↑ (unique elements)
New size = writeIndex = 5 ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n) {
    unordered_set<int> seen;  // Track seen elements
    int writeIndex = 0;        // Where to write next unique
    
    for (int i = 0; i < n; i++) {
        // If element not seen before
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);        // Mark as seen
            arr[writeIndex] = arr[i];   // Write to array
            writeIndex++;               // Move write position
        }
        // If duplicate, skip (don't write, don't increment)
    }
    
    return writeIndex;  // New size
}

int main() {
    int arr[] = {10, 20, 30, 20, 40, 10, 50};
    int n = 7;
    
    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    int newSize = removeDuplicates(arr, n);
    
    cout << "After removing duplicates: ";
    for (int i = 0; i < newSize; i++) cout << arr[i] << " ";
    cout << endl;
    cout << "New size: " << newSize << endl;
    
    return 0;
}
```

### Alternative: Return New Vector
```cpp
vector<int> removeDuplicatesVector(vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> result;
    
    for (int x : arr) {
        if (seen.find(x) == seen.end()) {
            seen.insert(x);
            result.push_back(x);
        }
    }
    return result;
}
```

### Key Points:
- ✅ Preserves order of first occurrence
- ✅ O(n) time, O(n) space
- ✅ Uses HashSet for O(1) lookup
- ✅ In-place modification possible

---
---

# PROBLEM 5: ROTATE ARRAY BY K POSITIONS 🔄

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers and an integer `k`, rotate the array to the **right** by `k` positions.

### Input:
```
arr = [1, 2, 3, 4, 5, 6, 7]
k = 3
```

### Output:
```
arr = [5, 6, 7, 1, 2, 3, 4]
(Rotated right by 3 positions)
```

### Explanation:
```
Original: [1, 2, 3, 4, 5, 6, 7]
k=1:      [7, 1, 2, 3, 4, 5, 6]
k=2:      [6, 7, 1, 2, 3, 4, 5]
k=3:      [5, 6, 7, 1, 2, 3, 4] ✅
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `0 ≤ k ≤ 10^9`
- `-10^9 ≤ arr[i] ≤ 10^9`
- Must rotate in-place O(1) space

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Rotate", "Shift", "Circular"  
✅ **Pattern**: Triple Reversal Technique  
✅ **Approach**: Reverse whole, then reverse parts  

### Why Triple Reversal?
- ❌ Naive: Use extra array O(n) space
- ❌ One by one: Rotate k times O(n × k) time
- ✅ Triple Reversal: O(n) time, O(1) space!

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### The Magic Formula:
```
To rotate RIGHT by k:
1. Reverse entire array [0...n-1]
2. Reverse first k elements [0...k-1]
3. Reverse remaining elements [k...n-1]
```

### Why This Works?
```
Original: [1, 2, 3, 4, 5, 6, 7]
          └─────────┘ └─────┘
          First n-k   Last k (to move to front)

Step 1: Reverse all
[7, 6, 5, 4, 3, 2, 1]
 └─────┘ └─────────┘
 Last k   First n-k (both reversed individually)

Step 2: Reverse first k=3
[5, 6, 7, 4, 3, 2, 1]
 └─────┘ (now in correct order!)

Step 3: Reverse remaining n-k=4
[5, 6, 7, 1, 2, 3, 4]
          └─────────┘ (now in correct order!)

Final: [5, 6, 7, 1, 2, 3, 4] ✅
```

### The Key Insight:
**"Reverse whole, reverse parts!"**

### Edge Case: k > n
```
If k = 10 and n = 7
k = k % n = 10 % 7 = 3
(Rotating by n is same as no rotation)
```

### Time Complexity: O(n) - 3 passes
### Space Complexity: O(1) - In-place

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`

```
Step 0: Handle k > n
k = 3 % 7 = 3 (no change)

Initial: [1, 2, 3, 4, 5, 6, 7]
         n = 7, k = 3

╔══════════════════════════════════════╗
║ STEP 1: Reverse entire array [0..6] ║
╚══════════════════════════════════════╝

Before: [1, 2, 3, 4, 5, 6, 7]
         ↑                 ↑
        L=0              R=6

Swap arr[0] ↔ arr[6]: [7, 2, 3, 4, 5, 6, 1]
     L++, R-- → L=1, R=5

Swap arr[1] ↔ arr[5]: [7, 6, 3, 4, 5, 2, 1]
     L++, R-- → L=2, R=4

Swap arr[2] ↔ arr[4]: [7, 6, 5, 4, 3, 2, 1]
     L++, R-- → L=3, R=3

Stop! (L >= R)

After Step 1: [7, 6, 5, 4, 3, 2, 1]

╔═══════════════════════════════════════╗
║ STEP 2: Reverse first k=3 [0..2]     ║
╚═══════════════════════════════════════╝

Before: [7, 6, 5, 4, 3, 2, 1]
         ↑     ↑
        L=0  R=2

Swap arr[0] ↔ arr[2]: [5, 6, 7, 4, 3, 2, 1]
     L++, R-- → L=1, R=1

Stop! (L >= R)

After Step 2: [5, 6, 7, 4, 3, 2, 1]
               └─────┘ (correct order!)

╔═══════════════════════════════════════╗
║ STEP 3: Reverse rest [3..6]          ║
╚═══════════════════════════════════════╝

Before: [5, 6, 7, 4, 3, 2, 1]
                  ↑        ↑
                 L=3     R=6

Swap arr[3] ↔ arr[6]: [5, 6, 7, 1, 3, 2, 4]
     L++, R-- → L=4, R=5

Swap arr[4] ↔ arr[5]: [5, 6, 7, 1, 2, 3, 4]
     L++, R-- → L=5, R=4

Stop! (L > R)

Final Answer: [5, 6, 7, 1, 2, 3, 4] ✅
```

### Verification:
```
Original: [1, 2, 3, 4, 5, 6, 7]
Result:   [5, 6, 7, 1, 2, 3, 4]

Last 3 elements (5,6,7) moved to front ✅
First 4 elements (1,2,3,4) moved to end ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

// Helper: Reverse array from start to end
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
    // Handle k > n (e.g., k=10, n=7 → k=3)
    k = k % n;
    
    // Edge case: k=0 means no rotation
    if (k == 0) return;
    
    // Step 1: Reverse entire array [0...n-1]
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse first k elements [0...k-1]
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse remaining elements [k...n-1]
    reverse(arr, k, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 3;
    
    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    rotateRight(arr, n, k);
    
    cout << "After rotating right by " << k << ": ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
```

### For Left Rotation:
```cpp
void rotateLeft(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, k - 1);     // Reverse first k
    reverse(arr, k, n - 1);     // Reverse rest
    reverse(arr, 0, n - 1);     // Reverse all
}
```

### Using STL:
```cpp
// Right rotate by k
rotate(arr, arr + n - k, arr + n);

// Left rotate by k
rotate(arr, arr + k, arr + n);
```

### Key Points:
- ✅ Triple reversal technique
- ✅ O(n) time, O(1) space
- ✅ In-place rotation
- ✅ Works for both left and right rotation

---
---

# 📋 QUICK REFERENCE SHEET

## Pattern Recognition Table

| **Problem Type** | **Pattern** | **Time** | **Space** | **Key Insight** |
|------------------|-------------|----------|-----------|-----------------|
| Find Min/Max | Single Pass Scan | O(n) | O(1) | Compare with best so far |
| Reverse Array | Two Pointer | O(n) | O(1) | Swap from both ends |
| Linear Search | Sequential Scan | O(n) | O(1) | Check each element |
| Remove Duplicates | HashSet + Write Index | O(n) | O(n) | Seen? Skip. New? Write. |
| Rotate Array | Triple Reversal | O(n) | O(1) | Reverse whole, reverse parts |

---

## Generic Templates Summary

### 1. Min/Max Template
```cpp
int maxVal = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) maxVal = arr[i];
}
```

### 2. Two Pointer Template
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process/Swap
    left++; right--;
}
```

### 3. Linear Search Template
```cpp
for (int i = 0; i < n; i++) {
    if (arr[i] == target) return i;
}
return -1;
```

### 4. Remove Duplicates Template
```cpp
unordered_set<int> seen;
int writeIndex = 0;
for (int i = 0; i < n; i++) {
    if (!seen.count(arr[i])) {
        seen.insert(arr[i]);
        arr[writeIndex++] = arr[i];
    }
}
```

### 5. Triple Reversal Template
```cpp
k = k % n;
reverse(arr, 0, n-1);
reverse(arr, 0, k-1);
reverse(arr, k, n-1);
```

---

## Complexity Quick Reference

| **Operation** | **Time** | **Space** | **Notes** |
|---------------|----------|-----------|-----------|
| Access arr[i] | O(1) | - | Direct index |
| Traverse | O(n) | O(1) | Single loop |
| Search (Unsorted) | O(n) | O(1) | Linear scan |
| Search (Sorted) | O(log n) | O(1) | Binary search |
| Insert at end | O(1) | - | If space available |
| Insert at start | O(n) | - | Shift all elements |
| Delete | O(n) | - | Shift elements |
| Reverse | O(n) | O(1) | Two pointer |
| Rotate | O(n) | O(1) | Triple reversal |
| Sort | O(n log n) | O(1) | Quick/Merge sort |

---

## Decision Tree

```
Array Problem?
    ↓
Need Min/Max?
    → Single pass scan
    → Compare with best
    
Need to Search?
    → Sorted? 
        YES → Binary Search O(log n)
        NO → Linear Search O(n)
    
Need to Reverse?
    → Two Pointer
    → Swap and move inward
    
Need to Rotate?
    → Triple Reversal
    → O(1) space
    
Need to Remove Duplicates?
    → HashSet tracking
    → Write only unique
```

---

## Top 5 Interview Tips

1. **Always ask about constraints first!**
   - Is array sorted?
   - Can we use extra space?
   - In-place modification allowed?

2. **Check edge cases:**
   - Empty array (n = 0)
   - Single element (n = 1)
   - k > n for rotation

3. **Optimize space:**
   - Two pointer > Extra array
   - In-place > Creating copy

4. **Use built-ins when appropriate:**
   - `reverse()`, `sort()`, `rotate()` from STL
   - But know how to implement from scratch!

5. **State complexity clearly:**
   - Time: O(?)
   - Space: O(?)

---

