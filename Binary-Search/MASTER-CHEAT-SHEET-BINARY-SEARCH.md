#  BINARY SEARCH - MASTER CHEAT SHEET
*Complete Summary for Daily Revision & Interview Prep*

---

## 📋 TABLE OF CONTENTS

1. [Pattern Recognition Table](#recognition)
2. [When to Use Which Pattern - Decision Tree](#decision-tree)
3. [All Templates Quick Reference](#templates)
4. [Complexity Reference](#complexity)
5. [Interview Scripts](#interview)
6. [One-Page Printable Summary](#printable)

---

<a name="recognition"></a>
## 🔥 PATTERN RECOGNITION TABLE

**Use this to decide which pattern in 3 seconds!**

| **Keywords in Problem** | **Pattern** | **Time** | **Key Action** |
|------------------------|-------------|----------|----------------|
| "Sorted array" + "Find element" | Classic BS | O(log n) | Return when found |
| "First occurrence" / "Lower bound" | Boundary BS (Left) | O(log n) | `high = mid - 1` on match |
| "Last occurrence" / "Upper bound" | Boundary BS (Right) | O(log n) | `low = mid + 1` on match |
| "Floor" (largest ≤ target) | Boundary BS | O(log n) | Store and go right |
| "Ceiling" (smallest ≥ target) | Boundary BS | O(log n) | Store and go left |
| "Count occurrences" | Boundary BS (Both) | O(log n) | `last - first + 1` |
| "Minimum capacity" / "Allocate" | BS on Answer | O(n log R) | Define range, check valid |
| "Maximum distance" / "Distribute" | BS on Answer | O(n log R) | Define range, check valid |
| "Rotated sorted array" | Modified BS | O(log n) | Find sorted half |
| "Peak element" | Modified BS | O(log n) | Compare neighbors |
| "Square root" / "Nth root" | BS on Answer | O(log n) | Check mid² vs n |
| "Search infinite array" | Classic BS | O(log n) | Find bounds first |
| "Search 2D matrix" | Classic BS | O(log(m×n)) | Treat as 1D array |

---

<a name="decision-tree"></a>
## 🌳 MASTER DECISION TREE - "WHICH PATTERN WHEN?"

```
                    BINARY SEARCH PROBLEM?
                             |
        ┌────────────────────┼────────────────────┐
        |                    |                    |
   Is array given?      Finding value?      Special case?
        |                    |                    |
        v                    v                    v
    Sorted array?       Range defined?        Rotated?
     /      \            /      \                 |
   YES      NO         YES      NO                v
    |        |          |        |           Modified BS
    v        v          v        v          (Find sorted half)
Exact match? |    Min/Max value? |
 /      \    |     /      \      |
YES     NO   |   YES      NO     |
 |      |    |    |       |      |
 v      v    v    v       v      v
Classic Boundary Other  BS on  Other  Other
  BS     BS           Answer        patterns
         /  \
      Left Right
     (First)(Last)
```

---

### **Detailed Decision Logic:**

```
╔════════════════════════════════════════════════════════╗
║  STEP 1: Is array SORTED/MONOTONIC?                    ║
║    └─ YES → Go to Step 2                               ║
║    └─ NO → Can't use BS (or sort first)                ║
╠════════════════════════════════════════════════════════╣
║  STEP 2: What are you looking for?                     ║
║    ├─ Exact element → Classic BS                       ║
║    ├─ First/Last occurrence → Boundary BS              ║
║    ├─ Floor/Ceiling → Boundary BS                      ║
║    └─ Count → Boundary BS (last - first + 1)           ║
╠════════════════════════════════════════════════════════╣
║  STEP 3: Is array rotated?                             ║
║    └─ YES → Modified BS (Find sorted half)             ║
╠════════════════════════════════════════════════════════╣
║  STEP 4: Searching for MIN/MAX value?                  ║
║    └─ YES → BS on Answer                               ║
╚════════════════════════════════════════════════════════╝
```

---

<a name="templates"></a>
## 📝 ALL TEMPLATES QUICK REFERENCE

### **Template 1: CLASSIC BINARY SEARCH** 📍

```cpp
// ═══════════════════════════════════════════
// PATTERN 1: CLASSIC BINARY SEARCH
// Use: Find element in sorted array
// Time: O(log n) | Space: O(1)
// ═══════════════════════════════════════════

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow!
        
        if (arr[mid] == target) {
            return mid;              // Found!
        }
        else if (arr[mid] < target) {
            low = mid + 1;           // Search right
        }
        else {
            high = mid - 1;          // Search left
        }
    }
    
    return -1;  // Not found
}
```

**Mantra:** *"Equal found, Less right, More left"*

**Real-World:** 📖 Finding word in dictionary!

---

### **Template 2A: FIRST OCCURRENCE (LOWER BOUND)** 🎯

```cpp
// ═══════════════════════════════════════════
// PATTERN 2A: FIRST OCCURRENCE
// Use: Find first occurrence, lower bound
// Time: O(log n) | Space: O(1)
// ═══════════════════════════════════════════

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;  // Store result
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;              // Store position
            high = mid - 1;         // 🔥 Keep searching LEFT!
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
```

**Mantra:** *"Found? Save it! But check LEFT for earlier!"*

**Real-World:** 📅 Finding first sick day in calendar!

---

### **Template 2B: LAST OCCURRENCE (UPPER BOUND)** 🎯

```cpp
// ═══════════════════════════════════════════
// PATTERN 2B: LAST OCCURRENCE
// Use: Find last occurrence, upper bound
// Time: O(log n) | Space: O(1)
// ═══════════════════════════════════════════

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;  // Store result
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            ans = mid;              // Store position
            low = mid + 1;          // 🔥 Keep searching RIGHT!
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
```

**Mantra:** *"Found? Save it! But check RIGHT for later!"*

**Real-World:** 📅 Finding last sick day in calendar!

---

### **Template 2C: COUNT OCCURRENCES** 📊

```cpp
// ═══════════════════════════════════════════
// COUNT OCCURRENCES
// Use: Count how many times element appears
// Time: O(log n) | Space: O(1)
// ═══════════════════════════════════════════

int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    
    if (first == -1) return 0;  // Not found
    
    int last = lastOccurrence(arr, target);
    
    return last - first + 1;  // Formula!
}
```

**Formula:** `count = last - first + 1`

---

### **Template 2D: FLOOR AND CEILING** 📏

```cpp
// ═══════════════════════════════════════════
// FLOOR: Largest element ≤ target
// ═══════════════════════════════════════════

int floor(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] <= target) {
            ans = arr[mid];     // Store as potential answer
            low = mid + 1;      // Try larger
        } else {
            high = mid - 1;
        }
    }
    
    return ans;
}

// ═══════════════════════════════════════════
// CEILING: Smallest element ≥ target
// ═══════════════════════════════════════════

int ceiling(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] >= target) {
            ans = arr[mid];     // Store as potential answer
            high = mid - 1;     // Try smaller
        } else {
            low = mid + 1;
        }
    }
    
    return ans;
}
```

---

### **Template 3: BINARY SEARCH ON ANSWER** 💡

```cpp
// ═══════════════════════════════════════════
// PATTERN 3: BINARY SEARCH ON ANSWER
// Use: Find min/max value satisfying condition
// Time: O(n log R) | Space: O(1)
// R = range of search space
// ═══════════════════════════════════════════

// Helper function: Check if 'mid' is valid
bool isValid(vector<int>& arr, int mid, int k) {
    // Check if 'mid' satisfies problem condition
    // Example: Can allocate with capacity 'mid'?
    
    int count = 1;
    int sum = 0;
    
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

// Main function
int binarySearchOnAnswer(vector<int>& arr, int k) {
    // Step 1: Define search space (answer range)
    int low = *max_element(arr.begin(), arr.end());  // Minimum possible
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible
    int result = -1;
    
    // Step 2: Binary search on this range
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Step 3: Check if 'mid' is valid answer
        if (isValid(arr, mid, k)) {
            result = mid;
            high = mid - 1;  // Try smaller (for minimum)
            // low = mid + 1;  // Try larger (for maximum)
        } else {
            low = mid + 1;   // Need larger value
        }
    }
    
    return result;
}
```

**Mantra:** *"Define range, check if mid works, adjust accordingly!"*

**Real-World:** 🎒 Distributing workload - find minimum maximum load!

---

### **Template 4: SEARCH IN ROTATED SORTED ARRAY** 🔄

```cpp
// ═══════════════════════════════════════════
// MODIFIED BINARY SEARCH: Rotated Array
// Use: Array was sorted, then rotated
// Time: O(log n) | Space: O(1)
// ═══════════════════════════════════════════

int searchRotated(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Found!
        }
        
        // Determine which half is sorted
        
        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if target in this sorted range
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;  // Search left
            } else {
                low = mid + 1;   // Search right
            }
        }
        // Right half is sorted
        else {
            // Check if target in this sorted range
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;   // Search right
            } else {
                high = mid - 1;  // Search left
            }
        }
    }
    
    return -1;  // Not found
}
```

**Key Insight:** After rotation, ONE half is always sorted!

**Real-World:** 🔄 Clock with numbers - rotated but still ordered!

---

### **Template 5: SQUARE ROOT (FLOOR)** √

```cpp
// ═══════════════════════════════════════════
// SQUARE ROOT (WITHOUT sqrt())
// Use: Find floor(√n)
// Time: O(log n) | Space: O(1)
// ═══════════════════════════════════════════

int mySqrt(int n) {
    if (n == 0 || n == 1) return n;
    
    int low = 1, high = n;
    int ans = 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Use long long to avoid overflow
        if ((long long)mid * mid == n) {
            return mid;  // Perfect square
        }
        else if ((long long)mid * mid < n) {
            ans = mid;      // Store as potential answer
            low = mid + 1;  // Try larger
        }
        else {
            high = mid - 1;  // Try smaller
        }
    }
    
    return ans;  // Floor value
}
```

**Real-World:** 📏 Finding square tile size that fits!

---

<a name="complexity"></a>
## 📊 COMPLEXITY REFERENCE TABLE

| **Pattern** | **Time** | **Space** | **When to Use** |
|-------------|----------|-----------|-----------------|
| **Classic Binary Search** | O(log n) | O(1) | Find element in sorted array |
| **First Occurrence** | O(log n) | O(1) | Find boundary (left) |
| **Last Occurrence** | O(log n) | O(1) | Find boundary (right) |
| **Count Occurrences** | O(log n) | O(1) | last - first + 1 |
| **Floor/Ceiling** | O(log n) | O(1) | Largest ≤ target / Smallest ≥ target |
| **BS on Answer** | O(n log R) | O(1) | Find min/max value (R = range) |
| **Rotated Array** | O(log n) | O(1) | Modified sorted array |
| **Square Root** | O(log n) | O(1) | Find √n without sqrt() |
| **2D Matrix Search** | O(log(m×n)) | O(1) | Treat as 1D array |

*n = array size, R = answer range*

---

## 🔑 MAGIC KEYWORDS → PATTERN MAPPING

| **See This Keyword** | **Think This Pattern** | **Key Action** |
|---------------------|----------------------|----------------|
| "Sorted array" + "Find" | Classic BS | Standard template |
| "First occurrence" | Boundary BS (Left) | `high = mid - 1` on match |
| "Last occurrence" | Boundary BS (Right) | `low = mid + 1` on match |
| "Lower bound" | Boundary BS (Left) | First ≥ target |
| "Upper bound" | Boundary BS (Right) | First > target |
| "Floor" | Boundary BS | Largest ≤ target |
| "Ceiling" | Boundary BS | Smallest ≥ target |
| "Count occurrences" | Boundary BS (Both) | last - first + 1 |
| "Minimum capacity" | BS on Answer | Define range [max, sum] |
| "Maximum distance" | BS on Answer | Define range, check valid |
| "Allocate books/pages" | BS on Answer | Minimize maximum |
| "Painter's partition" | BS on Answer | Minimize maximum |
| "Aggressive cows" | BS on Answer | Maximize minimum |
| "Rotated sorted array" | Modified BS | Find sorted half |
| "Peak element" | Modified BS | Compare neighbors |
| "Square root without sqrt" | BS on Answer | mid² vs n |
| "Kth root" | BS on Answer | mid^k vs n |
| "Infinite sorted array" | Classic BS | Find bounds first |
| "Search 2D matrix" | Classic BS | Treat as 1D |

---

<a name="interview"></a>
## 🎤 INTERVIEW SCRIPTS FOR ALL PATTERNS

### **Script 1: Pattern Recognition (First 10 Seconds)**

**You Say:**
> "Sir, I notice [sorted array / finding min-max value / rotated array].  
> This is [Pattern 1/2/3] binary search.  
> I'll use [classic / boundary / BS on answer] approach.  
> Time complexity O(log n), Space O(1)."

---

### **Script 2: Classic BS**

> "Sir, array is sorted and we need to find exact element. I'll use standard binary search:
> - Start with entire array (low=0, high=n-1)
> - Find middle element
> - Compare with target: equal→return, less→search right, more→search left
> - Eliminate half at each step
> - Time O(log n) because we divide by 2 each time"

---

### **Script 3: Boundary BS**

> "Sir, we need [first/last] occurrence. I'll modify binary search:
> - When I find target, I DON'T stop
> - I keep searching [left/right] to find better boundary
> - Store every occurrence found
> - For first: `high = mid - 1` to search left
> - For last: `low = mid + 1` to search right
> - Still O(log n) time"

---

### **Script 4: BS on Answer**

> "Sir, this is binary search on answer - I'm not searching in array but searching for the ANSWER itself:
> - Answer lies between [minimum possible] and [maximum possible]
> - For each mid value, I check: does this work? using helper function
> - If works: store it, try [smaller for minimum / larger for maximum]
> - If doesn't work: adjust range
> - Time O(n log R) where R is answer range"

---

### **Script 5: Rotated Array**

> "Sir, rotated sorted array has one half always sorted:
> - Find middle
> - Check which half is sorted (compare arr[low] with arr[mid])
> - Check if target is in that sorted range
> - If yes: search there. If no: search other half
> - Still O(log n) because we eliminate half each time"

---

### **Script 6: While Coding (Keep Talking!)**

**Say out loud:**
```
"Declaring low equals 0, high equals n minus 1..."
[Write: int low = 0, high = n - 1;]

"While low less than or equal high..."
[Write: while (low <= high) {}]

"Calculate mid avoiding overflow..."
[Write: int mid = low + (high - low) / 2;]

"Compare arr[mid] with target..."
[Write: if (arr[mid] == target)]

"If equal, [return/store and continue searching]..."
[Write appropriate logic]

"Update pointers..."
[Write: low = mid + 1 or high = mid - 1]
```

---

## 💡 COMMON PROBLEM PATTERNS

### **Problem Type → Solution Approach:**

**1. "Find element in sorted array"**
- Keywords: "sorted", "find", "exists"
- **Pattern:** Classic BS
- **Template:** Standard

**2. "Find first and last position"**
- Keywords: "first", "last", "position", "duplicates"
- **Pattern:** Boundary BS (Both)
- **Template:** First + Last

**3. "Count occurrences of element"**
- Keywords: "count", "how many", "occurrences"
- **Pattern:** Boundary BS (Both)
- **Formula:** `last - first + 1`

**4. "Allocate minimum pages/books"**
- Keywords: "allocate", "minimum", "maximum pages"
- **Pattern:** BS on Answer
- **Range:** [max element, sum]
- **Goal:** Minimize maximum

**5. "Aggressive cows (maximize minimum distance)"**
- Keywords: "maximize", "minimum distance", "place"
- **Pattern:** BS on Answer
- **Range:** [0, max position]
- **Goal:** Maximize minimum

**6. "Search in rotated sorted array"**
- Keywords: "rotated", "sorted"
- **Pattern:** Modified BS
- **Key:** Find sorted half

**7. "Find square root without sqrt()"**
- Keywords: "square root", "without sqrt"
- **Pattern:** BS on Answer
- **Range:** [0, n]
- **Check:** mid² vs n

---

<a name="printable"></a>
## 📋 ONE-PAGE PRINTABLE SUMMARY

```
╔══════════════════════════════════════════════════════════════════════╗
║        BINARY SEARCH - COMPLETE CHEAT SHEET                          ║
║                  ALL PATTERNS IN ONE PAGE                            ║
╚══════════════════════════════════════════════════════════════════════╝

┌──────────────────────────────────────────────────────────────────────┐
│ 1️⃣  PATTERN RECOGNITION (3 SECONDS!)                                │
├──────────────────────────────────────────────────────────────────────┤
│ Q1: Sorted/Monotonic? ✅                                             │
│ Q2: Target/Boundary? ✅                                              │
│ Q3: Eliminate half? ✅                                               │
│ ALL YES → BINARY SEARCH!                                            │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 2️⃣  KEYWORDS → PATTERN                                               │
├──────────────────────────────────────────────────────────────────────┤
│ "Find element"           → Classic BS                                │
│ "First/Last"             → Boundary BS (Go LEFT/RIGHT)              │
│ "Floor/Ceiling"          → Boundary BS                               │
│ "Count occurrences"      → Boundary BS (last - first + 1)           │
│ "Min/Max capacity"       → BS on Answer                              │
│ "Allocate/Distribute"    → BS on Answer                              │
│ "Rotated array"          → Modified BS (Find sorted half)           │
│ "Square root"            → BS on Answer                              │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 3️⃣  THE 3 GOLDEN TEMPLATES                                           │
├──────────────────────────────────────────────────────────────────────┤
│                                                                      │
│ TEMPLATE 1: CLASSIC BINARY SEARCH                                   │
│   int low=0, high=n-1;                                              │
│   while(low <= high) {                                              │
│     mid = low + (high - low) / 2;                                   │
│     if(arr[mid] == target) return mid;                              │
│     else if(arr[mid] < target) low = mid + 1;                       │
│     else high = mid - 1;                                            │
│   }                                                                  │
│   Mantra: "Equal found, Less right, More left"                     │
│                                                                      │
│ TEMPLATE 2A: FIRST OCCURRENCE (Go LEFT)                            │
│   int ans = -1;                                                     │
│   while(low <= high) {                                              │
│     mid = low + (high - low) / 2;                                   │
│     if(arr[mid] == target) {                                        │
│       ans = mid;                                                    │
│       high = mid - 1;  // Keep searching LEFT                      │
│     } else if(arr[mid] < target) low = mid + 1;                    │
│       else high = mid - 1;                                          │
│   }                                                                  │
│   Mantra: "Found? Save! Check LEFT!"                               │
│                                                                      │
│ TEMPLATE 2B: LAST OCCURRENCE (Go RIGHT)                            │
│   int ans = -1;                                                     │
│   while(low <= high) {                                              │
│     mid = low + (high - low) / 2;                                   │
│     if(arr[mid] == target) {                                        │
│       ans = mid;                                                    │
│       low = mid + 1;  // Keep searching RIGHT                      │
│     } else if(arr[mid] < target) low = mid + 1;                    │
│       else high = mid - 1;                                          │
│   }                                                                  │
│   Mantra: "Found? Save! Check RIGHT!"                              │
│                                                                      │
│ TEMPLATE 3: BS ON ANSWER                                            │
│   int low = min_possible, high = max_possible;                     │
│   int result = -1;                                                  │
│   while(low <= high) {                                              │
│     mid = low + (high - low) / 2;                                   │
│     if(isValid(mid)) {                                              │
│       result = mid;                                                 │
│       high = mid - 1; // For minimum, try smaller                  │
│     } else low = mid + 1;                                           │
│   }                                                                  │
│   Mantra: "Define range, check valid, adjust!"                     │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 4️⃣  GOLDEN FORMULAS                                                  │
├──────────────────────────────────────────────────────────────────────┤
│ • mid = low + (high - low) / 2  (avoid overflow!)                  │
│ • count = last - first + 1                                          │
│ • Always: while(low <= high)                                        │
│ • Always: low = mid + 1 or high = mid - 1 (move!)                  │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 5️⃣  COMPLEXITY                                                        │
├──────────────────────────────────────────────────────────────────────┤
│ All patterns: O(log n) time, O(1) space                            │
│ BS on Answer: O(n log R) where R = answer range                    │
│                                                                      │
│ Why O(log n)? Divide by 2 each step:                               │
│   n → n/2 → n/4 → n/8 → ... → 1                                   │
│   Steps = log₂(n)                                                   │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 6️⃣  DECISION TREE                                                     │
├──────────────────────────────────────────────────────────────────────┤
│                                                                      │
│                   Binary Search Problem                             │
│                           |                                          │
│          ┌────────────────┼────────────────┐                       │
│          |                |                |                       │
│     Sorted array?    Finding value?    Special?                    │
│          |                |                |                       │
│     Exact match?      Min/Max?        Rotated?                     │
│       /    \            /    \            |                        │
│    YES     NO         YES    NO           v                        │
│     |      |           |     |        Modified BS                  │
│  Classic  First/Last  BS on  Other   (Find sorted half)           │
│    BS    Boundary    Answer                                        │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 7️⃣  COMMON MISTAKES (AVOID!)                                         │
├──────────────────────────────────────────────────────────────────────┤
│ ❌ mid = (low + high) / 2  → ✅ low + (high - low) / 2             │
│ ❌ while(low < high)       → ✅ while(low <= high)                 │
│ ❌ Stop when found         → ✅ Keep searching (for boundary)       │
│ ❌ low = mid               → ✅ low = mid + 1 (always move!)        │
│ ❌ Forget to store ans     → ✅ ans = mid before continuing         │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 8️⃣  TOP PROBLEMS (Master These!)                                     │
├──────────────────────────────────────────────────────────────────────┤
│ 1. Classic Binary Search           - 3 min  ⭐⭐⭐⭐⭐              │
│ 2. First & Last Position            - 7 min  ⭐⭐⭐⭐⭐              │
│ 3. Search Rotated Array             - 8 min  ⭐⭐⭐⭐⭐              │
│ 4. Square Root (Floor)              - 5 min  ⭐⭐⭐⭐⭐              │
│ 5. Allocate Minimum Pages           - 12 min ⭐⭐⭐⭐⭐              │
│ 6. Count Occurrences                - 8 min  ⭐⭐⭐⭐                │
│ 7. Find Peak Element                - 6 min  ⭐⭐⭐⭐                │
│ 8. Floor and Ceiling                - 10 min ⭐⭐⭐⭐                │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 9️⃣  MANTRAS (RECITE DAILY!)                                          │
├──────────────────────────────────────────────────────────────────────┤
│ 1. "mid = low + (high - low) / 2" (avoid overflow!)                │
│ 2. "Equal found, Less right, More left"                            │
│ 3. "Found? Save! Go LEFT for first!"                               │
│ 4. "Found? Save! Go RIGHT for last!"                               │
│ 5. "Define range, check valid, adjust!"                            │
│ 6. "Eliminate HALF at each step!"                                  │
│ 7. "Sorted = BS possible!"                                         │
│ 8. "One half always sorted in rotated!"                            │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 🔟 REAL-WORLD EXAMPLES                                               │
├──────────────────────────────────────────────────────────────────────┤
│ Classic BS:        📖 Finding word in dictionary                    │
│ Boundary BS:       📅 First/last sick day in month                 │
│ BS on Answer:      🎒 Distributing workload fairly                 │
│ Rotated Array:     🔄 Clock starting from random hour              │
│ Square Root:       📏 Finding tile size that fits                  │
└──────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════╗
║  PRINT THIS → REVISE DAILY → ACE INTERVIEWS! 🚀                     ║
╚══════════════════════════════════════════════════════════════════════╝
```




---

## 🎯 CORE PRINCIPLE

```
╔════════════════════════════════════════════════════╗
║                                                    ║
║   "Read problem → Recognize pattern (3 seconds)    ║
║    → Write template from muscle memory           n ║
║    → Fill in the blanks → Done!"                   ║
║                                                    ║
║   95% of binary search problems solved with        ║
║   these 3 core patterns!                           ║
║                                                    ║
╚════════════════════════════════════════════════════╝
```

---

##  MOBILE-FRIENDLY QUICK REFERENCE

**Save this to your phone:**

```
BS CLASSIC: while(low<=high), compare, return/adjust
BS FIRST: ans=mid, high=mid-1 on match
BS LAST: ans=mid, low=mid+1 on match
BS ANSWER: low=min, high=max, check isValid(mid)
ROTATED: find sorted half, check range
SQRT: mid² vs n, store if less
COUNT: last - first + 1
ALWAYS: mid = low + (high-low)/2
```

---

**🎯 You got this! Binary Search is muscle memory now! 💪**


---

