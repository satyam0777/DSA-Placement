#  MASTER ARRAY PATTERNS - COMPLETE CHEAT SHEET

---

## 📌 TABLE OF CONTENTS
1. [Pattern Recognition Table](#recognition)
2. [When to Use Which Pattern - Decision Tree](#decision-tree)
3. [All Templates Quick Reference](#templates)
4. [Complexity Reference](#complexity)
5. [Interview Scripts for All Patterns](#interview)
6. [One-Page Printable Summary](#printable)

---

<a name="recognition"></a>
## 🔥 PATTERN RECOGNITION TABLE

**Use this to decide which pattern in 3 seconds!**

| **Keywords in Problem** | **Pattern** | **Time** | **Template** |
|------------------------|-------------|----------|--------------|
| "Size k", "Window k", "Every window" | **Sliding Window (Fixed)** | O(n) | `if (j-i+1 == k)` |
| "Longest", "Without repeat", "At most k" | **Sliding Window (Variable)** | O(n) | `while (invalid) i++` |
| "Maximum sum contiguous", "Largest subarray" | **Kadane's Algorithm** | O(n) | `max(arr[i], sum+arr[i])` |
| "Range [l,r]", "Multiple queries", "Subarray sum = k" | **Prefix/Suffix Sum** | O(n) build, O(1) query | `prefix[r] - prefix[l-1]` |
| "Count", "Frequency", "Duplicate", "Two sum" | **Hashing** | O(n) | Map/Set |
| "Find min/max", "Reverse", "Search", "Rotate" | **Basic Array** | O(n) | Single pass/Two pointer |
| "Sort", "0,1,2", "Kth largest", "Merge sorted" | **Sorting** | O(n log n) | `sort()` or Dutch Flag |
| "Sorted array + Pairs", "Move zeros", "3Sum" | **Two Pointer** | O(n) or O(n²) | Opposite/Same/Fixed |

---

<a name="decision-tree"></a>
## 🌳 MASTER DECISION TREE - "WHICH PATTERN WHEN?"

```
                        ARRAY PROBLEM?
                             |
        ┌────────────────────┼─────────────────────┐
        |                    |                     |
    See "window"         See "pairs"         See "frequency"
    or "contiguous"?     or "sorted"?        or "count"?
        |                    |                     |
        v                    v                     v
   SLIDING WINDOW        TWO POINTER           HASHING
        |                    |                     |
    Size k given?        Array sorted?         Need count?
     /      \             /      \               /      \
   YES      NO          YES      NO             YES      NO
    |        |           |        |              |        |
  FIXED   VARIABLE    OPPOSITE   SAME          MAP      SET
         "longest"    "pairs"  "in-place"
         "at most"
         
                    See "maximum sum contiguous"?
                             |
                             v
                      KADANE'S ALGORITHM
                      (Extend or start fresh)
                      
                    See "range query" or "subarray sum"?
                             |
                             v
                      PREFIX/SUFFIX SUM
                      (Build once, query O(1))
                      
                    See "sort", "0,1,2", "Kth largest"?
                             |
                             v
                         SORTING
                      /            \
                  Basic sort    Dutch Flag
                  O(n log n)    O(n), O(1)
                  
                    Simple "find min", "reverse"?
                             |
                             v
                       BASIC ARRAY
                    (Single pass/Two pointer)
```

---

<a name="templates"></a>
## 📝 ALL TEMPLATES QUICK REFERENCE

### **1️⃣ SLIDING WINDOW - FIXED**
```cpp
// USE WHEN: "Size k" given
int i = 0, j = 0;
while (j < n) {
    sum += arr[j];  // Add j
    
    if (j - i + 1 < k) j++;
    else if (j - i + 1 == k) {
        maxSum = max(maxSum, sum);  // Answer
        sum -= arr[i];  // Slide
        i++; j++;
    }
}
```
**Mantra:** *"Add j, check size, answer, slide both"*

---

### **2️⃣ SLIDING WINDOW - VARIABLE**
```cpp
// USE WHEN: "Longest", "At most k distinct"
int i = 0, j = 0, maxLen = 0;
while (j < n) {
    // Add arr[j] to window
    
    while (condition_invalid) {  // Shrink while bad
        // Remove arr[i]
        i++;
    }
    
    maxLen = max(maxLen, j - i + 1);  // Update answer
    j++;
}
```
**Mantra:** *"Add j, while bad shrink i, update max, move j"*

---

### **3️⃣ TWO POINTER - OPPOSITE** ⬅️➡️
```cpp
// USE WHEN: Sorted + Pairs + Target sum
int left = 0, right = n - 1;

while (left < right) {
    int sum = arr[left] + arr[right];
    
    if (sum == target) return true;
    else if (sum < target) left++;   // Need larger
    else right--;                     // Need smaller
}
```
**Mantra:** *"Less left++, Equal found, More right--"*

---

### **4️⃣ TWO POINTER - SAME** ➡️➡️
```cpp
// USE WHEN: Remove duplicates, Move zeros
int slow = 0;

for (int fast = 0; fast < n; fast++) {
    if (condition_met(arr[fast])) {  // Should I keep?
        arr[slow] = arr[fast];
        slow++;
    }
}
return slow;  // New length
```
**Mantra:** *"fast explores ALL, slow collects VALID"*

---

### **5️⃣ KADANE'S ALGORITHM**
```cpp
// USE WHEN: "Maximum sum contiguous subarray"
int maxSum = arr[0], curSum = arr[0];

for (int i = 1; i < n; i++) {
    curSum = max(arr[i], curSum + arr[i]);
            //    ↑           ↑
            // Start new   Extend old
    
    maxSum = max(maxSum, curSum);
}
return maxSum;
```
**Mantra:** *"Extend or Start Fresh - whichever is LARGER!"*

---

### **6️⃣ PREFIX SUM - BASIC**
```cpp
// USE WHEN: Multiple range queries [l, r]
// BUILD:
prefix[0] = arr[0];
for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}

// QUERY sum[l, r]:
int rangeSum = prefix[r] - (l == 0 ? 0 : prefix[l-1]);
```
**Mantra:** *"Precompute ONCE, Query INSTANTLY!"*

---

### **7️⃣ PREFIX SUM + HASHMAP**
```cpp
// USE WHEN: "Count subarrays with sum = k"
unordered_map<int, int> mp;
mp[0] = 1;  // IMPORTANT!

int sum = 0, count = 0;
for (int x : arr) {
    sum += x;
    count += mp[sum - k];  // Check if (sum - k) exists
    mp[sum]++;
}
```
**Mantra:** *"For subarray count: prefix + hashmap!"*

---

### **8️⃣ HASHING - FREQUENCY**
```cpp
// USE WHEN: "Count", "Frequency"
unordered_map<int, int> freq;

for (int x : arr) {
    freq[x]++;
}

// Find most frequent:
int maxFreq = 0;
for (auto& p : freq) {
    maxFreq = max(maxFreq, p.second);
}
```
**Mantra:** *"Count? MAP. Exists? SET."*

---

### **9️⃣ HASHING - TWO SUM**
```cpp
// USE WHEN: "Find two numbers that add to target"
unordered_map<int, int> seen;

for (int i = 0; i < n; i++) {
    int complement = target - arr[i];
    
    if (seen.count(complement)) {
        return {seen[complement], i};
    }
    seen[arr[i]] = i;
}
```
**Mantra:** *"Store complement, check if current exists!"*

---

### **🔟 BASIC ARRAY - MIN/MAX**
```cpp
// USE WHEN: "Find minimum/maximum"
int maxVal = arr[0];

for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) {
        maxVal = arr[i];
    }
}
```
**Mantra:** *"Assume first is best, then challenge!"*

---

### **1️⃣1️⃣ BASIC ARRAY - REVERSE**
```cpp
// USE WHEN: "Reverse array"
int left = 0, right = n - 1;

while (left < right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
}
```
**Mantra:** *"Swap and move inward from both ends!"*

---

### **1️⃣2️⃣ BASIC ARRAY - ROTATE**
```cpp
// USE WHEN: "Rotate array by k"
void reverse(int arr[], int s, int e) {
    while (s < e) swap(arr[s++], arr[e--]);
}

k = k % n;
reverse(arr, 0, n-1);    // Reverse all
reverse(arr, 0, k-1);    // Reverse first k
reverse(arr, k, n-1);    // Reverse rest
```
**Mantra:** *"Reverse whole, reverse parts!"*

---

### **1️⃣3️⃣ SORTING - BASIC**
```cpp
// USE WHEN: "Sort array"
// Ascending:
sort(arr.begin(), arr.end());

// Descending:
sort(arr.begin(), arr.end(), greater<int>());
```
**Mantra:** *"sort() for ascending, greater<>() for descending!"*

---

### **1️⃣4️⃣ SORTING - DUTCH FLAG (0,1,2)** ⭐ MOST FAMOUS
```cpp
// USE WHEN: "Sort 0s, 1s, 2s" or "Three colors"
int low = 0, mid = 0, high = n - 1;

while (mid <= high) {
    if (arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++; mid++;
    }
    else if (arr[mid] == 1) mid++;
    else {  // arr[mid] == 2
        swap(arr[mid], arr[high]);
        high--;  // Don't move mid!
    }
}
```
**Mantra:** *"0→Left, 2→Right, 1→Stay!"*

---

### **1️⃣5️⃣ SORTING - KTH LARGEST**
```cpp
// USE WHEN: "Find Kth largest element"
sort(arr.begin(), arr.end(), greater<int>());
return arr[k - 1];
```
**Mantra:** *"Sort descending, then arr[k-1]!"*

---

<a name="complexity"></a>
## 📊 COMPLEXITY REFERENCE TABLE

| **Pattern** | **Time** | **Space** | **When to Use** |
|-------------|----------|-----------|-----------------|
| **Sliding Window (Fixed)** | O(n) | O(1) or O(k) | Window size k given |
| **Sliding Window (Variable)** | O(n) | O(1) or O(k) | Find longest/smallest |
| **Two Pointer (Opposite)** | O(n) | O(1) | Sorted + pairs |
| **Two Pointer (Same)** | O(n) | O(1) | In-place modify |
| **Two Pointer (Fixed)** | O(n²) | O(1) | 3Sum, triplets |
| **Kadane's Algorithm** | O(n) | O(1) | Max sum contiguous |
| **Prefix Sum (Build)** | O(n) | O(n) | Multiple range queries |
| **Prefix Sum (Query)** | O(1) | - | After build |
| **Prefix + HashMap** | O(n) | O(n) | Subarray count |
| **Hashing (Frequency)** | O(n) | O(n) | Count/frequency |
| **Hashing (Two Sum)** | O(n) | O(n) | Find pairs |
| **Basic Array (Min/Max)** | O(n) | O(1) | Single pass scan |
| **Basic Array (Reverse)** | O(n) | O(1) | Two pointer |
| **Basic Array (Rotate)** | O(n) | O(1) | Triple reversal |
| **Sorting (STL)** | O(n log n) | O(log n) | General sorting |
| **Sorting (Dutch Flag)** | O(n) | O(1) | Only 0,1,2 |
| **Sorting (Merge)** | O(n+m) | O(n+m) | Two sorted arrays |

---

## 🔑 MAGIC KEYWORDS → PATTERN MAPPING

| **See This Keyword** | **Think This Pattern** |
|---------------------|----------------------|
| "Window", "Size k", "Every window" | Sliding Window (Fixed) |
| "Longest", "Without repeat", "At most" | Sliding Window (Variable) |
| "Maximum sum contiguous", "Largest subarray" | Kadane's Algorithm |
| "Range query [l,r]", "Multiple queries" | Prefix Sum |
| "Subarray sum = k", "Count subarrays" | Prefix + HashMap |
| "Count", "Frequency", "How many times" | Hashing (Map) |
| "Duplicate", "Exists", "Find if" | Hashing (Set) |
| "Two numbers add to target" | Hashing (Two Sum) |
| "Sorted array", "Pair with sum" | Two Pointer (Opposite) |
| "Remove duplicates", "Move zeros" | Two Pointer (Same) |
| "Three sum", "Triplets" | Two Pointer (Fixed) |
| "Find min/max", "Reverse", "Search" | Basic Array |
| "Rotate by k", "Remove element" | Basic Array |
| "Sort", "Arrange", "Order" | Sorting (Basic) |
| "0s, 1s, 2s", "Three colors" | Sorting (Dutch Flag) ⭐ |
| "Kth largest", "Kth smallest" | Sorting + Index |
| "Merge sorted arrays" | Sorting (Merge) |
| "Anagram", "Same letters" | Hashing (Frequency) |
| "Intersection", "Union" | Hashing (Set) |
| "First non-repeating" | Hashing (Map + Scan) |
| "Equilibrium index" | Prefix + Suffix |
| "Product except self" | Prefix × Suffix |
| "Circular subarray" | Kadane's (Total - Min) |
| "Maximum product" | Kadane's (Track max & min) |

---

<a name="interview"></a>
## 🎤 INTERVIEW SCRIPTS FOR ALL PATTERNS

### **Script 1: Sliding Window Recognition**
> "Sir, I notice we need [longest/smallest] with [contiguous elements/window size k]. This is **sliding window** - I'll use two pointers i and j. Time O(n), Space O(1) [or O(k) if using data structure]."

### **Script 2: Two Pointer Recognition**
> "Sir, I notice the array is [sorted/needs in-place modification] and we need [pairs/remove elements]. This is **two pointer** technique - reduces O(n²) to O(n)! Time O(n), Space O(1)."

### **Script 3: Kadane's Recognition**
> "Sir, I see we need **maximum sum of contiguous subarray**. This is classic **Kadane's algorithm** - at each position, I decide: extend previous subarray OR start fresh. Pick whichever gives larger sum. Time O(n), Space O(1)!"

### **Script 4: Prefix Sum Recognition**
> "Sir, I see we have [multiple range queries / count subarrays]. This is **prefix sum** - I'll precompute cumulative sums in O(n), then each query is O(1). [If counting] I'll use hashmap to track prefix sums seen."

### **Script 5: Hashing Recognition**
> "Sir, I need to [count frequency / check existence / find pairs]. This is **hashing** - O(n) time with O(1) lookup! I'll use [unordered_map for counting / unordered_set for existence]."

### **Script 6: Basic Array Recognition**
> "Sir, this is [find min/max / reverse / rotate] - basic array operation. I'll use [single pass O(n) / two pointer O(n) / triple reversal O(n)]."

### **Script 7: Sorting Recognition**
> "Sir, I see we need [elements in order / Kth largest / 0,1,2 sort]. I'll use [STL sort() O(n log n) / Dutch Flag O(n)]. [Connect to real-world example like sorting Amazon products or traffic lights]."

---

## 💡 COMMON PROBLEM PATTERNS

### **Pattern Recognition Guide:**

**1. "Find longest substring without repeating characters"**
- Keywords: "longest", "substring" (contiguous), "without repeating"
- **Pattern:** Sliding Window (Variable)
- **Template:** Simplified (Add j, while duplicate shrink i)

**2. "Two sum in sorted array"**
- Keywords: "two", "sum", "sorted"
- **Pattern:** Two Pointer (Opposite)
- **Template:** left=0, right=n-1, compare sum

**3. "Maximum subarray sum"**
- Keywords: "maximum", "subarray" (contiguous), "sum"
- **Pattern:** Kadane's Algorithm
- **Template:** max(arr[i], curSum + arr[i])

**4. "Count subarrays with sum equals k"**
- Keywords: "count", "subarrays", "sum equals"
- **Pattern:** Prefix Sum + HashMap
- **Template:** mp[0]=1, count += mp[sum-k]

**5. "Find duplicates in array"**
- Keywords: "find", "duplicates"
- **Pattern:** Hashing (Set)
- **Template:** seen.count(x) → duplicate

**6. "Sort array of 0s, 1s, 2s"**
- Keywords: "sort", "0s, 1s, 2s"
- **Pattern:** Sorting (Dutch Flag) ⭐
- **Template:** 3 pointers (low, mid, high)

**7. "Remove duplicates in sorted array"**
- Keywords: "remove", "duplicates", "sorted"
- **Pattern:** Two Pointer (Same)
- **Template:** slow collects unique, fast explores

**8. "Maximum sum of window size k"**
- Keywords: "maximum", "sum", "window size k"
- **Pattern:** Sliding Window (Fixed)
- **Template:** if (j-i+1 == k) calculate answer

---

<a name="printable"></a>
## 📋 ONE-PAGE PRINTABLE SUMMARY

```
╔══════════════════════════════════════════════════════════════════════╗
║        MASTER ARRAY PATTERNS - DAILY REVISION CHEAT SHEET           ║
║                     ALL 7 PATTERNS IN ONE PAGE                      ║
╚══════════════════════════════════════════════════════════════════════╝

┌──────────────────────────────────────────────────────────────────────┐
│ 1️⃣  PATTERN RECOGNITION (3 SECONDS!)                                │
├──────────────────────────────────────────────────────────────────────┤
│ "Size k" / "Window"          → SLIDING WINDOW (Fixed)               │
│ "Longest" / "At most"        → SLIDING WINDOW (Variable)            │
│ "Sorted + Pairs"             → TWO POINTER (Opposite)               │
│ "Remove duplicates"          → TWO POINTER (Same)                   │
│ "Maximum sum contiguous"     → KADANE'S ALGORITHM                   │
│ "Range query [l,r]"          → PREFIX SUM                           │
│ "Subarray sum = k"           → PREFIX SUM + HASHMAP                 │
│ "Count" / "Frequency"        → HASHING (Map)                        │
│ "Duplicate" / "Exists"       → HASHING (Set)                        │
│ "Two numbers add to target"  → HASHING (Two Sum)                    │
│ "Find min/max" / "Reverse"   → BASIC ARRAY                          │
│ "Sort" / "0,1,2"             → SORTING (Basic/Dutch Flag)           │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 2️⃣  QUICK TEMPLATES                                                  │
├──────────────────────────────────────────────────────────────────────┤
│                                                                      │
│ SLIDING WINDOW (FIXED):                                             │
│   int i=0, j=0;                                                     │
│   while(j<n) {                                                      │
│     sum += arr[j];                                                  │
│     if(j-i+1==k) { ans=max(ans,sum); sum-=arr[i]; i++; j++; }       │
│   }                                                                 │
│   Mantra: "Add j, check size, answer, slide both"                   │
│                                                                     │
│ SLIDING WINDOW (VARIABLE):                                          │
│   int i=0, j=0, maxLen=0;                                           │
│   while(j<n) {                                                      │
│     // Add j                                                        │
│     while(invalid) i++;                                             │
│     maxLen = max(maxLen, j-i+1);                                    │
│     j++;                                                            │
│   }                                                                 │
│   Mantra: "Add j, while bad shrink, update, move"                   │
│                                                                     │
│ TWO POINTER (OPPOSITE):                                             │
│   int L=0, R=n-1;                                                   │
│   while(L<R) {                                                      │
│     if(arr[L]+arr[R]==target) return true;                          │
│     else if(sum<target) L++;                                        │
│     else R--;                                                       │
│   }                                                                 │
│   Mantra: "Less L++, Equal found, More R--"                         │
│                                                                     │
│ TWO POINTER (SAME):                                                 │
│   int slow=0;                                                       │
│   for(int fast=0; fast<n; fast++) {                                 │
│     if(valid) arr[slow++] = arr[fast];                              │
│   }                                                                 │
│   Mantra: "fast explores, slow collects"                            │
│                                                                     │
│ KADANE'S:                                                           │
│   int maxSum=arr[0], curSum=arr[0];                                 │
│   for(int i=1; i<n; i++) {                                          │
│     curSum = max(arr[i], curSum+arr[i]);                            │
│     maxSum = max(maxSum, curSum);                                   │
│   }                                                                 │
│   Mantra: "Extend or start - pick larger"                          │
│                                                                      │
│ PREFIX SUM:                                                         │
│   prefix[i] = prefix[i-1] + arr[i];                                │
│   sum[l,r] = prefix[r] - prefix[l-1];                              │
│   Mantra: "Precompute once, query instantly"                       │
│                                                                      │
│ PREFIX + HASHMAP (Count):                                           │
│   map[0]=1; sum=0; count=0;                                        │
│   for(x: arr) {                                                     │
│     sum += x;                                                       │
│     count += map[sum-k];                                            │
│     map[sum]++;                                                     │
│   }                                                                  │
│   Mantra: "Check complement, then add current"                     │
│                                                                      │
│ HASHING (Frequency):                                                │
│   map<int,int> freq;                                               │
│   for(x: arr) freq[x]++;                                           │
│   Mantra: "Count? MAP. Exists? SET."                               │
│                                                                      │
│ HASHING (Two Sum):                                                  │
│   map<int,int> seen;                                               │
│   for(i=0; i<n; i++) {                                             │
│     if(seen.count(target-arr[i])) return {seen[target-arr[i]], i};│
│     seen[arr[i]] = i;                                               │
│   }                                                                  │
│   Mantra: "Store complement, check current"                        │
│                                                                      │
│ SORTING (Dutch Flag 0,1,2): ⭐ MOST FAMOUS                           │
│   int low=0, mid=0, high=n-1;                                        │
│   while(mid<=high) {                                                 │
│     if(arr[mid]==0) swap(arr[low++], arr[mid++]);                    │
│     else if(arr[mid]==1) mid++;                                      │
│     else swap(arr[mid], arr[high--]);                                │
│   }                                                                  │
│   Mantra: "0→left, 2→right, 1→stay"                                  │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 3️⃣  COMPLEXITY QUICK REFERENCE                                       │
├──────────────────────────────────────────────────────────────────────┤
│ Sliding Window:      O(n), O(1) or O(k)                            │
│ Two Pointer:         O(n) or O(n²), O(1)                           │
│ Kadane's:            O(n), O(1)                                     │
│ Prefix Sum:          O(n) build + O(1) query, O(n) space           │
│ Hashing:             O(n), O(n)                                     │
│ Basic Array:         O(n), O(1)                                     │
│ Sorting (STL):       O(n log n), O(log n)                          │
│ Dutch Flag:          O(n), O(1) ⭐                                  │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 4️⃣  GOLDEN FORMULAS (NEVER FORGET!)                                  │
├──────────────────────────────────────────────────────────────────────┤
│ • Sliding Window Size = j - i + 1                                   │
│ • Kadane's Decision = max(arr[i], curSum + arr[i])                 │
│ • Prefix Sum Query = prefix[r] - prefix[l-1]                       │
│ • Two Sum = map[target - current]                                   │
│ • Subarray Count = map[sum - k]                                     │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 5️⃣  MANTRAS (RECITE DAILY!)                                          │
├──────────────────────────────────────────────────────────────────────┤
│ SW Fixed:        "Add j, check size, answer, slide both"           │
│ SW Variable:     "Add j, while bad shrink, update, move"           │
│ TP Opposite:     "Less L++, Equal found, More R--"                 │
│ TP Same:         "fast explores, slow collects"                    │
│ Kadane's:        "Extend or start - pick larger"                   │
│ Prefix:          "Precompute once, query instantly"                │
│ Hashing:         "Count? MAP. Exists? SET."                        │
│ Dutch Flag:      "0→left, 2→right, 1→stay" ⭐                      │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 6️⃣  COMMON MISTAKES (AVOID THESE!)                                   │
├──────────────────────────────────────────────────────────────────────┤
│ ❌ Window size: j - i (missing +1)                                  │
│    ✅ Always: j - i + 1                                             │
│                                                                      │
│ ❌ while(left <= right) for Two Pointer                            │
│    ✅ while(left < right)                                           │
│                                                                      │
│ ❌ Forgot sum -= arr[i] before sliding                             │
│    ✅ Always remove arr[i] before i++                               │
│                                                                      │
│ ❌ Map: Forgot to erase when count = 0                             │
│    ✅ if(map[x]==0) map.erase(x);                                  │
│                                                                      │
│ ❌ Prefix query: Forgot l=0 edge case                              │
│    ✅ if(l==0) return prefix[r];                                   │
│                                                                      │
│ ❌ Dutch Flag: mid++ after swapping with high                      │
│    ✅ Only high--, don't move mid!                                 │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 7️⃣  DECISION TREE (Visual)                                           │
├──────────────────────────────────────────────────────────────────────┤
│                                                                      │
│                       Array Problem                                 │
│                            |                                         │
│          ┌─────────────────┼─────────────────┐                     │
│          |                 |                 |                     │
│     "window"          "sorted"           "count"                   │
│          |                 |                 |                     │
│    Size given?       Pairs/In-place?    Need what?                │
│       /    \            /     \           /    \                   │
│    Fixed  Variable  Opposite  Same     Map    Set                 │
│                                                                      │
│    "max sum" → Kadane's    |    "range" → Prefix                  │
│    "0,1,2" → Dutch Flag ⭐  |    "sort" → sort()                   │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 8️⃣  REAL-WORLD EXAMPLES (For Interview Communication!)               │
├──────────────────────────────────────────────────────────────────────┤
│ Sliding Window:      📱 Phone notifications (last k)                │
│ Two Pointer:         📚 Book pages meeting in middle                │
│ Kadane's:            💰 Best time to buy/sell stock                 │
│ Prefix Sum:          📊 Quick salary range calculations             │
│ Hashing:             📖 Dictionary O(1) lookup                      │
│ Dutch Flag:          🚦 Traffic lights (Red→Yellow→Green) ⭐        │
│ Basic Array:         🎬 Cinema seats (index access)                 │
│ Sorting:             🛒 E-commerce price filters                    │
└──────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════╗
║  PRINT THIS → KEEP IN WALLET → REVISE DAILY → ACE INTERVIEWS! 🚀   ║
╚══════════════════════════════════════════════════════════════════════╝
```

---

## 🎯 TOP 20 MUST-KNOW PROBLEMS (Across All Patterns)

| # | **Problem** | **Pattern** | **Time** | **⭐** |
|---|-------------|-------------|----------|--------|
| 1 | Max sum subarray size k | SW Fixed | 5 min | ⭐⭐⭐⭐⭐ |
| 2 | Longest substring without repeat | SW Variable | 10 min | ⭐⭐⭐⭐⭐ |
| 3 | Two sum (sorted array) | TP Opposite | 5 min | ⭐⭐⭐⭐⭐ |
| 4 | Remove duplicates (sorted) | TP Same | 3 min | ⭐⭐⭐⭐⭐ |
| 5 | Maximum subarray sum | Kadane's | 5 min | ⭐⭐⭐⭐⭐ |
| 6 | Range sum query | Prefix Sum | 5 min | ⭐⭐⭐⭐⭐ |
| 7 | Subarray sum equals k | Prefix + HashMap | 8 min | ⭐⭐⭐⭐⭐ |
| 8 | Contains duplicate | Hashing Set | 3 min | ⭐⭐⭐⭐⭐ |
| 9 | Two sum (unsorted) | Hashing Map | 5 min | ⭐⭐⭐⭐⭐ |
| 10 | Find min/max | Basic Array | 3 min | ⭐⭐⭐⭐⭐ |
| 11 | Reverse array | Basic Array | 3 min | ⭐⭐⭐⭐⭐ |
| 12 | Rotate array by k | Basic Array | 7 min | ⭐⭐⭐⭐ |
| 13 | Sort colors (0,1,2) | Dutch Flag | 5 min | ⭐⭐⭐⭐⭐ |
| 14 | Kth largest element | Sorting | 3 min | ⭐⭐⭐⭐ |
| 15 | Merge sorted arrays | Sorting | 5 min | ⭐⭐⭐⭐ |
| 16 | First negative in window k | SW Fixed | 7 min | ⭐⭐⭐⭐ |
| 17 | K unique characters | SW Variable | 12 min | ⭐⭐⭐⭐ |
| 18 | Move zeros | TP Same | 4 min | ⭐⭐⭐⭐ |
| 19 | Valid anagram | Hashing | 5 min | ⭐⭐⭐⭐⭐ |
| 20 | Equilibrium index | Prefix + Suffix | 8 min | ⭐⭐⭐⭐ |

---



---

**Formula Check**
- Window size = j - i + 1
- Kadane's = max(arr[i], sum + arr[i])
- Prefix query = prefix[r] - prefix[l-1]
- Two sum = map[target - current]
- Subarray count = map[sum - k]

---

## 🎤 INTERVIEW DAY CHECKLIST


### **If You Blank Out:**

1. **Pause** - "Sir, let me think..."
2. **Write skeleton:**
   ```cpp
   int i = 0, j = 0;
   while (j < n) {
       // Add
       // Check
       // Update
       j++;
   }
   ```
3. **Think:** What am I tracking?
4. **Fill in** the blanks
5. **Continue confidently!**

---

## 🔥 FINAL SUCCESS MANTRAS

**Recite these 10x before interview:**

```
1. "Window size = j - i + 1"
2. "Extend or start - pick larger"
3. "Precompute once, query instantly"
4. "Count? MAP. Exists? SET."
5. "Less L++, Equal found, More R--"
6. "fast explores, slow collects"
7. "0→left, 2→right, 1→stay"
8. "Template writes itself, I fill blanks"
9. "Pattern recognition → 3 seconds"
10. "I've practiced, I'm ready!" 💪
```
---

##  CORE PRINCIPLE

```
╔════════════════════════════════════════════════════╗
║                                                    ║
║   "Read problem → Recognize pattern in 3 seconds   ║
║    → Write template from muscle memory             ║
║    → Fill in the blanks → Done!"                   ║
║                                                    ║
║   85-95% of array problems solved with             ║
║   these 7 patterns!                                ║
║                                                    ║
╚════════════════════════════════════════════════════╝
```

---



*Last updated: [Current Date] | Practice daily for guaranteed success!* ✨
