# SORTING - 5 COMPLETE PROBLEMS 🎯
*Following Aditya Verma's 5-Step Methodology with Real-World Examples*

---

# PROBLEM 1: BASIC SORTING (ASCENDING/DESCENDING) 📊

## Real-World Context 🌍
**Scenario**: You're building an e-commerce website. Customers want to sort products by price "Low to High" or "High to Low".

**Example**: Amazon product sorting
```
Unsorted Prices: [$50, $20, $100, $30, $80]
Low→High: [$20, $30, $50, $80, $100]
High→Low: [$100, $80, $50, $30, $20]
```

---

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers, sort it in **ascending** or **descending** order.

### Input:
```
arr = [5, 2, 8, 1, 9, 3]
n = 6
```

### Output (Ascending):
```
arr = [1, 2, 3, 5, 8, 9]
```

### Output (Descending):
```
arr = [9, 8, 5, 3, 2, 1]
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `-10^9 ≤ arr[i] ≤ 10^9`

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Sort", "Arrange", "Order", "Ascending", "Descending"  
✅ **Pattern**: Basic Sorting  
✅ **Approach**: Use STL sort() function  

### Why STL sort()?
- ✅ Optimized (IntroSort = Quick + Heap + Insertion)
- ✅ Guaranteed O(n log n)
- ✅ Simple one-liner
- ✅ Interview-friendly

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
For Ascending:
1. Use sort(arr.begin(), arr.end())
2. Default behavior = ascending order

For Descending:
1. Use sort(arr.begin(), arr.end(), greater<int>())
2. greater<int>() = comparator for descending
```

### The Key Insight:
**"STL sort() = One line solution for most sorting problems!"**

### Time Complexity: O(n log n) - IntroSort
### Space Complexity: O(log n) - Recursion stack

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [5, 2, 8, 1, 9, 3]`

### Ascending Sort:
```
Initial: [5, 2, 8, 1, 9, 3]

sort(arr.begin(), arr.end());

Internally (Quick Sort based):
1. Pick pivot (e.g., 5)
2. Partition: smaller left, larger right
3. Recursively sort left and right

After sorting: [1, 2, 3, 5, 8, 9] ✅

Verification:
arr[0] ≤ arr[1] ≤ arr[2] ≤ ... ≤ arr[n-1]
1 ≤ 2 ≤ 3 ≤ 5 ≤ 8 ≤ 9 ✅
```

### Descending Sort:
```
Initial: [5, 2, 8, 1, 9, 3]

sort(arr.begin(), arr.end(), greater<int>());

After sorting: [9, 8, 5, 3, 2, 1] ✅

Verification:
arr[0] ≥ arr[1] ≥ arr[2] ≥ ... ≥ arr[n-1]
9 ≥ 8 ≥ 5 ≥ 3 ≥ 2 ≥ 1 ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

// Ascending order
vector<int> sortAscending(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

// Descending order
vector<int> sortDescending(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9, 3};
    
    // Ascending
    vector<int> asc = sortAscending(arr);
    cout << "Ascending: ";
    for (int x : asc) cout << x << " ";
    cout << endl;
    // Output: 1 2 3 5 8 9
    
    // Descending
    vector<int> desc = sortDescending(arr);
    cout << "Descending: ";
    for (int x : desc) cout << x << " ";
    cout << endl;
    // Output: 9 8 5 3 2 1
    
    return 0;
}
```

### Real-World Application:
```cpp
// E-commerce: Sort products by price
struct Product {
    string name;
    int price;
};

vector<Product> products = {
    {"Laptop", 50000},
    {"Mouse", 500},
    {"Keyboard", 2000}
};

// Sort by price (Low to High)
sort(products.begin(), products.end(), [](Product a, Product b) {
    return a.price < b.price;
});

// Result: Mouse(500), Keyboard(2000), Laptop(50000)
```

### Key Points:
- ✅ STL sort() = O(n log n)
- ✅ Default = Ascending
- ✅ greater<int>() = Descending
- ✅ Works on vectors, arrays, strings

---
---

# PROBLEM 2: SORT 0s, 1s, 2s (DUTCH NATIONAL FLAG) 🚦

## Real-World Context 🌍
**Scenario**: You're organizing a traffic light system. Sort signals: Red(0), Yellow(1), Green(2) in correct order.

**Example**: Traffic light controller
```
Unsorted: [Red, Green, Yellow, Red, Yellow, Green, Red]
Sorted:   [Red, Red, Red, Yellow, Yellow, Green, Green]
          (All Red → All Yellow → All Green)
```

**Another Example**: Sort colored balls
```
Balls: [Blue, Red, Green, Blue, Red, Green]
After: [Blue, Blue, Red, Red, Green, Green]
```

---

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array containing **only 0s, 1s, and 2s**, sort the array in **O(n) time** and **O(1) space**.

### Input:
```
arr = [0, 1, 2, 0, 1, 2, 1, 0]
n = 8
```

### Output:
```
arr = [0, 0, 0, 1, 1, 1, 2, 2]
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `arr[i] ∈ {0, 1, 2}` only
- **Must be O(n) time** (not O(n log n))
- **Must be O(1) space** (in-place)

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "0s, 1s, 2s", "Three colors", "Dutch Flag"  
✅ **Pattern**: Three-way partitioning  
✅ **Approach**: Dutch National Flag Algorithm (3 pointers)  

### Why NOT Regular sort()?
```
sort() → O(n log n) ❌
Dutch Flag → O(n) ✅ (Better!)
```

### This is VERY FAMOUS in interviews! 🌟
- Asked in 85-95% service company interviews
- Also called "Sort Colors" problem

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### The Dutch National Flag Algorithm:

```
Use 3 Pointers:
1. low → End of 0s region
2. mid → Current element to process
3. high → Start of 2s region

Goal:
[0, 0, 0, ..., 1, 1, 1, ..., 2, 2, 2]
 ↑             ↑             ↑
 0 to low-1    low to high   high+1 to n-1
 (All 0s)      (All 1s)      (All 2s)
```

### Rules:
```
If arr[mid] == 0:
    → Swap with low
    → Move both low++ and mid++
    (0 belongs to left region)

If arr[mid] == 1:
    → Just mid++
    (1 is already in correct region)

If arr[mid] == 2:
    → Swap with high
    → Move high-- only
    (Don't move mid! Need to check swapped element)
```

### The Key Insight:
**"0→Left, 2→Right, 1→Middle stays!"**

### Time Complexity: O(n) - Single pass
### Space Complexity: O(1) - In-place

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [0, 1, 2, 0, 1, 2, 1, 0]`

```
Initial State:
arr = [0, 1, 2, 0, 1, 2, 1, 0]
       ↑                     ↑
      low                   high
      mid

Step 1: arr[mid=0] = 0
→ Swap arr[low] and arr[mid] (both 0)
→ low++, mid++
arr = [0, 1, 2, 0, 1, 2, 1, 0]
          ↑                 ↑
         low               high
         mid

Step 2: arr[mid=1] = 1
→ Just mid++
arr = [0, 1, 2, 0, 1, 2, 1, 0]
          ↑                 ↑
         low               high
             mid

Step 3: arr[mid=2] = 2
→ Swap arr[mid=2] and arr[high=7]
arr = [0, 1, 0, 0, 1, 2, 1, 2]
          ↑             ↑
         low           high
             mid

Step 4: arr[mid=2] = 0 (after swap)
→ Swap arr[low=1] and arr[mid=2]
arr = [0, 0, 1, 0, 1, 2, 1, 2]
             ↑          ↑
            low        high
                mid

Step 5: arr[mid=3] = 0
→ Swap arr[low=2] and arr[mid=3]
arr = [0, 0, 0, 1, 1, 2, 1, 2]
                ↑       ↑
               low     high
                   mid

Step 6: arr[mid=4] = 1
→ Just mid++
arr = [0, 0, 0, 1, 1, 2, 1, 2]
                ↑       ↑
               low     high
                      mid

Step 7: arr[mid=5] = 2
→ Swap arr[mid=5] and arr[high=6]
arr = [0, 0, 0, 1, 1, 1, 2, 2]
                ↑    ↑
               low  high
                    mid

Step 8: mid > high → STOP!

Final: [0, 0, 0, 1, 1, 1, 2, 2] ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0;              // End of 0s
    int mid = 0;              // Current element
    int high = arr.size() - 1; // Start of 2s
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            // 0 belongs to left region
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            // 1 is already in correct place
            mid++;
        }
        else {  // arr[mid] == 2
            // 2 belongs to right region
            swap(arr[mid], arr[high]);
            high--;
            // Don't increment mid! (need to check swapped element)
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0};
    
    cout << "Before: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    sort012(arr);
    
    cout << "After: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    // Output: 0 0 0 1 1 1 2 2
    
    return 0;
}
```

### Real-World Application:
```cpp
// Traffic Light System
enum Signal { RED = 0, YELLOW = 1, GREEN = 2 };

vector<int> signals = {RED, GREEN, YELLOW, RED, YELLOW, GREEN};
sort012(signals);
// Result: [RED, RED, YELLOW, YELLOW, GREEN, GREEN]
// All Red lights → Yellow lights → Green lights ✅

// Hospital Triage System
enum Priority { CRITICAL = 0, URGENT = 1, NORMAL = 2 };

vector<int> patients = {NORMAL, CRITICAL, URGENT, NORMAL, CRITICAL};
sort012(patients);
// Result: [CRITICAL, CRITICAL, URGENT, NORMAL, NORMAL]
// Critical patients treated first! ✅
```

### Key Points:
- ✅ O(n) time, O(1) space
- ✅ Single pass through array
- ✅ Three-way partitioning
- ✅ VERY FAMOUS interview problem!
- ✅ Also called "Sort Colors" on LeetCode

---
---

# PROBLEM 3: CUSTOM COMPARATOR (SORT BY LENGTH) 📏

## Real-World Context 🌍
**Scenario**: You're building a word game app. Sort words by length so players can start with shorter words.

**Example**: Word puzzle game
```
Words: ["apple", "hi", "banana", "a", "cat"]
Sorted by length: ["a", "hi", "cat", "apple", "banana"]
```

**Another Example**: File organizer
```
Files: ["document.pdf", "pic.jpg", "presentation.pptx", "note.txt"]
By size: ["pic.jpg", "note.txt", "document.pdf", "presentation.pptx"]
```

---

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of strings, sort them by their **length** (shortest first). If two strings have the same length, sort them **lexicographically** (alphabetically).

### Input:
```
words = ["apple", "hi", "banana", "a", "cat", "dog"]
```

### Output:
```
words = ["a", "hi", "cat", "dog", "apple", "banana"]
```

### Explanation:
```
"a" → length 1
"hi", "cat", "dog" → length 3 (sorted: "cat" < "dog" < "hi")
"apple" → length 5
"banana" → length 6
```

### Constraints:
- `1 ≤ n ≤ 10^5`
- `1 ≤ word.length() ≤ 100`

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Sort by length", "Custom order", "Special criteria"  
✅ **Pattern**: Custom Comparator  
✅ **Approach**: Lambda function or comparator function  

### When to Use Custom Comparator?
- Sorting by frequency
- Sorting by second element in pairs
- Sorting by length, distance, custom metric
- Multiple sorting criteria

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
1. Use sort() with custom comparator
2. Comparator logic:
   - If lengths different → sort by length
   - If lengths same → sort alphabetically
3. Use lambda function for inline code
```

### The Key Insight:
**"Custom comparator = Your own sorting rules!"**

### Comparator Function:
```cpp
bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();  // Shorter first
    }
    return a < b;  // Same length → alphabetical
}
```

### Time Complexity: O(n log n) - Sorting
### Space Complexity: O(log n) - Recursion stack

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `words = ["apple", "hi", "banana", "a", "cat", "dog"]`

```
Step 1: Compare "apple" and "hi"
Length: 5 vs 2 → "hi" comes first

Step 2: Compare "hi" and "banana"
Length: 2 vs 6 → "hi" comes first

Step 3: Compare "hi" and "a"
Length: 2 vs 1 → "a" comes first

Step 4: Compare "hi" and "cat"
Length: 2 vs 3 → "hi" comes first

Step 5: Compare "hi" and "dog"
Length: 2 vs 3 → "hi" comes first

After internal sorting:
["a", "hi", "cat", "dog", "apple", "banana"]

Verification:
- Length 1: "a"
- Length 2: "hi"
- Length 3: "cat", "dog" (alphabetically: "cat" < "dog")
- Length 5: "apple"
- Length 6: "banana"
✅ Correct!
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

// Method 1: Using comparator function
bool compareByLength(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();  // Shorter first
    }
    return a < b;  // Same length → alphabetical
}

vector<string> sortByLength1(vector<string> words) {
    sort(words.begin(), words.end(), compareByLength);
    return words;
}

// Method 2: Using lambda (Modern C++)
vector<string> sortByLength2(vector<string> words) {
    sort(words.begin(), words.end(), [](string a, string b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        return a < b;
    });
    return words;
}

int main() {
    vector<string> words = {"apple", "hi", "banana", "a", "cat", "dog"};
    
    // Method 1
    vector<string> result1 = sortByLength1(words);
    cout << "Method 1: ";
    for (string s : result1) cout << s << " ";
    cout << endl;
    
    // Method 2
    vector<string> result2 = sortByLength2(words);
    cout << "Method 2: ";
    for (string s : result2) cout << s << " ";
    cout << endl;
    
    // Output: a hi cat dog apple banana
    
    return 0;
}
```

### Real-World Applications:

#### 1. Word Game Sorting
```cpp
// Sort words for a word puzzle game
vector<string> words = {"cat", "elephant", "dog", "hippopotamus"};
sort(words.begin(), words.end(), [](string a, string b) {
    return a.length() < b.length();
});
// Easy → Hard progression
```

#### 2. Sort Products by Name Length (UI Display)
```cpp
vector<string> products = {"Laptop Pro Max", "Mouse", "USB Cable"};
sort(products.begin(), products.end(), [](string a, string b) {
    return a.length() < b.length();
});
// Short names displayed first (better UX)
```

#### 3. Sort by Frequency then Value
```cpp
vector<int> arr = {1, 2, 2, 3, 3, 3};
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;

sort(arr.begin(), arr.end(), [&](int a, int b) {
    if (freq[a] != freq[b]) return freq[a] > freq[b];  // High freq first
    return a < b;  // Tie → smaller value first
});
// Result: [3, 3, 3, 2, 2, 1]
```

### Key Points:
- ✅ Lambda for inline comparators
- ✅ Return `true` if `a` should come before `b`
- ✅ Can use multiple criteria
- ✅ Very flexible!

---
---

# PROBLEM 4: MERGE TWO SORTED ARRAYS 🔀

## Real-World Context 🌍
**Scenario**: You have two sorted contact lists from different phones. Merge them into one sorted list.

**Example**: Merging contact lists
```
Phone 1: ["Alice", "Charlie", "Eve"]
Phone 2: ["Bob", "David", "Frank"]

Merged: ["Alice", "Bob", "Charlie", "David", "Eve", "Frank"]
```

**Another Example**: Merging sorted order lists
```
Online Orders (Morning): [101, 105, 110]
Online Orders (Evening): [102, 108, 115]

All Orders: [101, 102, 105, 108, 110, 115]
```

---

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given two **sorted** arrays `arr1` and `arr2`, merge them into a single **sorted** array.

### Input:
```
arr1 = [1, 3, 5, 7]
arr2 = [2, 4, 6, 8]
```

### Output:
```
merged = [1, 2, 3, 4, 5, 6, 7, 8]
```

### Constraints:
- `0 ≤ n, m ≤ 10^5`
- Both arrays are already sorted
- `-10^9 ≤ arr1[i], arr2[i] ≤ 10^9`

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Merge", "Two sorted arrays", "Combine"  
✅ **Pattern**: Two Pointer Technique  
✅ **Approach**: Compare elements from both arrays, pick smaller  

### Why Two Pointers?
```
❌ Concatenate + Sort → O((n+m) log (n+m))
✅ Two Pointers → O(n+m) (Better!)
```

### This is the MERGE step of Merge Sort!

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process:
```
1. Use two pointers: i for arr1, j for arr2
2. Compare arr1[i] and arr2[j]
3. Add smaller element to result
4. Move the respective pointer
5. After one array exhausted, add remaining elements
```

### The Key Insight:
**"Both sorted → Compare and pick smaller!"**

### Visual:
```
arr1 = [1, 3, 5]  arr2 = [2, 4, 6]
        ↑                  ↑
        i                  j

Compare 1 vs 2 → 1 smaller → result = [1], i++
Compare 3 vs 2 → 2 smaller → result = [1,2], j++
Compare 3 vs 4 → 3 smaller → result = [1,2,3], i++
Compare 5 vs 4 → 4 smaller → result = [1,2,3,4], j++
Compare 5 vs 6 → 5 smaller → result = [1,2,3,4,5], i++
arr1 exhausted → Add remaining [6] → result = [1,2,3,4,5,6]
```

### Time Complexity: O(n + m) - Single pass through both
### Space Complexity: O(n + m) - Result array

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr1 = [1, 3, 5, 7]`, `arr2 = [2, 4, 6, 8]`

```
Initial:
arr1 = [1, 3, 5, 7]  n = 4
arr2 = [2, 4, 6, 8]  m = 4
result = []
i = 0, j = 0

Step 1: Compare arr1[0]=1 vs arr2[0]=2
1 < 2 → result.push(1), i++
result = [1], i=1, j=0

Step 2: Compare arr1[1]=3 vs arr2[0]=2
3 > 2 → result.push(2), j++
result = [1, 2], i=1, j=1

Step 3: Compare arr1[1]=3 vs arr2[1]=4
3 < 4 → result.push(3), i++
result = [1, 2, 3], i=2, j=1

Step 4: Compare arr1[2]=5 vs arr2[1]=4
5 > 4 → result.push(4), j++
result = [1, 2, 3, 4], i=2, j=2

Step 5: Compare arr1[2]=5 vs arr2[2]=6
5 < 6 → result.push(5), i++
result = [1, 2, 3, 4, 5], i=3, j=2

Step 6: Compare arr1[3]=7 vs arr2[2]=6
7 > 6 → result.push(6), j++
result = [1, 2, 3, 4, 5, 6], i=3, j=3

Step 7: Compare arr1[3]=7 vs arr2[3]=8
7 < 8 → result.push(7), i++
result = [1, 2, 3, 4, 5, 6, 7], i=4, j=3

Step 8: i = 4 (arr1 exhausted)
Add remaining arr2[3] = 8
result = [1, 2, 3, 4, 5, 6, 7, 8]

Final: [1, 2, 3, 4, 5, 6, 7, 8] ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;
    
    int i = 0, j = 0;
    
    // Merge while both have elements
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    
    // Add remaining elements from arr1
    while (i < n) {
        result.push_back(arr1[i]);
        i++;
    }
    
    // Add remaining elements from arr2
    while (j < m) {
        result.push_back(arr2[j]);
        j++;
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    
    vector<int> merged = mergeSortedArrays(arr1, arr2);
    
    cout << "Merged: ";
    for (int x : merged) cout << x << " ";
    cout << endl;
    // Output: 1 2 3 4 5 6 7 8
    
    return 0;
}
```

### Real-World Applications:

#### 1. Merge Contact Lists
```cpp
vector<string> phone1 = {"Alice", "Charlie", "Eve"};
vector<string> phone2 = {"Bob", "David", "Frank"};

// Same merge logic works for strings!
vector<string> allContacts = merge(phone1, phone2);
// Result: ["Alice", "Bob", "Charlie", "David", "Eve", "Frank"]
```

#### 2. Merge Order IDs from Different Platforms
```cpp
vector<int> amazonOrders = {101, 105, 110, 115};
vector<int> flipkartOrders = {102, 108, 112, 120};

vector<int> allOrders = merge(amazonOrders, flipkartOrders);
// Process orders chronologically by ID
```

#### 3. Merge Sorted Log Files
```cpp
// Log files from Server 1 and Server 2 (sorted by timestamp)
vector<string> server1Logs = {"10:00 Login", "10:05 Action1"};
vector<string> server2Logs = {"10:02 Request", "10:07 Response"};

// Merge to create unified timeline
```

### Key Points:
- ✅ O(n+m) time - Linear
- ✅ Two pointers technique
- ✅ Works for sorted arrays only
- ✅ This is Merge step in Merge Sort!

---
---

# PROBLEM 5: KTH LARGEST ELEMENT 🏆

## Real-World Context 🌍
**Scenario**: You're building a leaderboard system. Find the 3rd highest scorer without displaying all scores.

**Example**: Gaming leaderboard
```
Scores: [85, 92, 78, 95, 88, 90, 82]
1st Highest: 95
2nd Highest: 92
3rd Highest: 90 ← We want this!
```

**Another Example**: Salary ranking
```
Salaries: [50000, 80000, 60000, 95000, 70000]
Find 2nd highest salary → 80000
```

---

## STEP 1: PROBLEM STATEMENT + INPUT/OUTPUT

### Problem:
Given an array of `n` integers and an integer `k`, find the **kth largest** element.

### Input:
```
arr = [7, 10, 4, 3, 20, 15]
k = 2
```

### Output:
```
15  (2nd largest)
```

### Explanation:
```
Sorted (Descending): [20, 15, 10, 7, 4, 3]
                      ↑   ↑
                     1st 2nd largest

2nd largest = 15
```

### Constraints:
- `1 ≤ k ≤ n ≤ 10^5`
- `-10^9 ≤ arr[i] ≤ 10^9`

---

## STEP 2: IDENTIFICATION

### How to Recognize?
✅ **Keywords**: "Kth largest", "Kth smallest", "Top K", "Rank K"  
✅ **Pattern**: Sorting or Heap  
✅ **Approach**: Sort and access by index  

### Multiple Approaches:

| **Approach** | **Time** | **Space** | **When to Use** |
|--------------|----------|-----------|-----------------|
| **Sort** | O(n log n) | O(1) | Simple, interview-friendly |
| **Min-Heap** | O(n log k) | O(k) | Better for large n, small k |
| **Quick Select** | O(n) avg | O(1) | Advanced, optimal |

**In interviews**: Use **Sort** for simplicity unless asked for optimization!

---

## STEP 3: ABSTRACT/APPROACH (Think Before Coding!)

### Thought Process (Sorting Approach):
```
1. Sort array in descending order
2. Kth largest = arr[k-1]

OR

1. Sort array in ascending order
2. Kth largest = arr[n-k]
```

### The Key Insight:
**"After sorting, Kth largest is at index (k-1) from end!"**

### Why This Works?
```
arr = [7, 10, 4, 3, 20, 15]
Sorted desc: [20, 15, 10, 7, 4, 3]
              ↑   ↑   ↑
             1st 2nd 3rd largest
            [0] [1] [2]

k=2 → arr[k-1] = arr[1] = 15 ✅
```

### Time Complexity: O(n log n) - Sorting
### Space Complexity: O(1) - In-place sort

---

## STEP 4: DRY RUN (Complete Trace)

### Input: `arr = [7, 10, 4, 3, 20, 15]`, `k = 2`

```
Step 1: Sort array in descending order
Original: [7, 10, 4, 3, 20, 15]
Sorted:   [20, 15, 10, 7, 4, 3]

Step 2: Access kth largest
k = 2 (2nd largest)
Index = k - 1 = 2 - 1 = 1
arr[1] = 15

Answer: 15 ✅

Verification:
Largest elements in order:
1st: 20 ✅
2nd: 15 ✅ (Our answer)
3rd: 10
...
```

### Alternative: Ascending Sort
```
Sort ascending: [3, 4, 7, 10, 15, 20]
                                 ↑   ↑
                            2nd  1st largest

k = 2 (2nd largest)
Index from end = n - k = 6 - 2 = 4
arr[4] = 15 ✅
```

---

## STEP 5: CODE

```cpp
#include <bits/stdc++.h>
using namespace std;

// Method 1: Sort Descending
int kthLargest1(vector<int> arr, int k) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k - 1];
}

// Method 2: Sort Ascending
int kthLargest2(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    return arr[n - k];
}

// Method 3: Kth Smallest (Bonus)
int kthSmallest(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 2;
    
    cout << "Kth Largest (Method 1): " << kthLargest1(arr, k) << endl;
    cout << "Kth Largest (Method 2): " << kthLargest2(arr, k) << endl;
    cout << "Kth Smallest: " << kthSmallest(arr, k) << endl;
    
    // Output:
    // Kth Largest (Method 1): 15
    // Kth Largest (Method 2): 15
    // Kth Smallest: 4
    
    return 0;
}
```

### Real-World Applications:

#### 1. Gaming Leaderboard
```cpp
// Find 3rd place winner
vector<int> scores = {85, 92, 78, 95, 88, 90};
int thirdPlace = kthLargest(scores, 3);
// Result: 88 (Bronze medal!)
```

#### 2. Salary Ranking
```cpp
// Find median salary (middle value)
vector<int> salaries = {50000, 80000, 60000, 95000, 70000};
sort(salaries.begin(), salaries.end());
int median = salaries[salaries.size() / 2];
// Median = 70000
```

#### 3. Find Top N Products
```cpp
// Top 5 products by sales
vector<int> sales = {100, 500, 200, 800, 300, 600, 150};
sort(sales.begin(), sales.end(), greater<int>());
vector<int> top5(sales.begin(), sales.begin() + 5);
// Top 5: [800, 600, 500, 300, 200]
```

#### 4. Stock Market - Find Kth Highest Price
```cpp
vector<int> stockPrices = {150, 200, 180, 220, 190};
int secondHighest = kthLargest(stockPrices, 2);
// Result: 200
```

### Advanced: Using Min-Heap (Better for Large Data)
```cpp
int kthLargestHeap(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int x : arr) {
        minHeap.push(x);
        if (minHeap.size() > k) {
            minHeap.pop();  // Remove smallest
        }
    }
    
    return minHeap.top();  // Kth largest
}
// Time: O(n log k) - Better when k << n
// Space: O(k) - Heap of size k
```

### Key Points:
- ✅ Sort approach: Simple and interview-friendly
- ✅ Heap approach: Better for large n, small k
- ✅ Kth largest = arr[k-1] (descending) or arr[n-k] (ascending)
- ✅ Kth smallest = arr[k-1] (ascending)

---
---

# 📋 QUICK REFERENCE SHEET

## Pattern Recognition Table

| **Problem Type** | **Pattern** | **Time** | **Space** | **Real Example** |
|------------------|-------------|----------|-----------|------------------|
| Basic Sort | STL sort() | O(n log n) | O(log n) | E-commerce filters |
| 0s, 1s, 2s | Dutch Flag | O(n) | O(1) | Traffic lights |
| Custom Order | Comparator | O(n log n) | O(log n) | Sort by length |
| Merge Sorted | Two Pointer | O(n+m) | O(n+m) | Merge contacts |
| Kth Largest | Sort + Index | O(n log n) | O(1) | Leaderboard |

---

## Generic Templates Summary

### 1. Basic Sort
```cpp
sort(arr.begin(), arr.end());  // Ascending
sort(arr.begin(), arr.end(), greater<int>());  // Descending
```

### 2. Custom Comparator
```cpp
sort(arr.begin(), arr.end(), [](auto a, auto b) {
    return /* your condition */;
});
```

### 3. Dutch Flag (0s, 1s, 2s)
```cpp
int low=0, mid=0, high=n-1;
while (mid <= high) {
    if (arr[mid]==0) swap(arr[low++], arr[mid++]);
    else if (arr[mid]==1) mid++;
    else swap(arr[mid], arr[high--]);
}
```

### 4. Merge Sorted Arrays
```cpp
while (i < n && j < m) {
    if (a[i] <= b[j]) result.push(a[i++]);
    else result.push(b[j++]);
}
```

### 5. Kth Largest/Smallest
```cpp
sort(arr.begin(), arr.end(), greater<int>());
return arr[k-1];  // Kth largest
```

---

## Interview Tips

1. ✅ **Always use STL sort()** unless asked for specific algorithm
2. ✅ **Dutch Flag (0,1,2)** - VERY FAMOUS, must know!
3. ✅ **Custom comparator** - Use lambda for readability
4. ✅ **Merge sorted** - Two pointer technique
5. ✅ **Kth largest** - Sort is simplest approach

---

