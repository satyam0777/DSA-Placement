# 🎯 PREFIX SUM & SUFFIX SUM - COMPLETE SERIES (ADITYA VERMA METHOD)

> **"Answer range queries in O(1) - The preprocessing powerhouse!"**

---

## 📖 TABLE OF CONTENTS

1. [🎬 Video 1: Introduction - What is Prefix/Suffix Sum?](#video1)
2. [🔍 Video 2: Identification - When to Use?](#video2)
3. [🎨 Video 3: The Core Concept - Why It Works](#video3)
4. [📝 Video 4: Generic Templates (Muscle Memory)](#video4)
5. [🎯 Video 5: Problem 1 - Range Sum Query](#problem1)
6. [🎯 Video 6: Problem 2 - Subarray Sum Equals K](#problem2)
7. [🎯 Video 7: Problem 3 - Equilibrium Index](#problem3)
8. [🎯 Video 8: Problem 4 - 2D Matrix Range Sum](#problem4)
9. [🎯 Video 9: Problem 5 - Product of Array Except Self](#problem5)
10. [📋 Quick Reference Sheet](#reference)
11. [🎓 7-Day Learning Path](#learning)

---

<a name="video1"></a>
## 🎬 VIDEO 1: INTRODUCTION - WHAT IS PREFIX/SUFFIX SUM?

### **What is Prefix Sum?**

A **prefix sum** array stores cumulative sums from the start of the array.

```
Original: [2, 4, 1, 3, 5]
Prefix:   [2, 6, 7, 10, 15]
           ↑  ↑  ↑   ↑   ↑
           2  2+4 6+1 7+3 10+5

prefix[i] = sum of arr[0...i]
```

**Formula:**  
`prefix[i] = arr[0] + arr[1] + ... + arr[i]`

---

### **What is Suffix Sum?**

A **suffix sum** array stores cumulative sums from the end of the array.

```
Original: [2, 4, 1, 3, 5]
Suffix:   [15, 13, 9, 8, 5]
           ↑   ↑   ↑  ↑  ↑
         2+13  4+9 1+8 3+5  5

suffix[i] = sum of arr[i...n-1]
```

**Formula:**  
`suffix[i] = arr[i] + arr[i+1] + ... + arr[n-1]`

---

### **Why Use Prefix/Suffix Sum?**

**Time Complexity Reduction:**
```
Problem: Find sum of subarray [l, r]

Brute Force: Loop from l to r → O(n) per query
With Prefix Sum: prefix[r] - prefix[l-1] → O(1) per query!

For Q queries:
Brute Force: O(Q × n) ❌
Prefix Sum: O(n) preprocessing + O(Q) queries ✅
```

---

### **The Big Idea:**

> **"Precompute cumulative sums ONCE, then answer ANY range query in O(1)!"**

```
Key Insight:
─────────────────────────────────────────
sum(l, r) = prefix[r] - prefix[l-1]

Why? Because:
prefix[r] = sum(0, r)
prefix[l-1] = sum(0, l-1)
Difference = sum(l, r) ✅
─────────────────────────────────────────
```

---

<a name="video2"></a>
## 🔍 VIDEO 2: IDENTIFICATION - WHEN TO USE PREFIX/SUFFIX SUM?

### **🎯 3 Signs to Recognize Prefix Sum:**

1. **Multiple Range Queries** - Many queries asking for sum/count in range [l, r]
2. **Static Array** - Array doesn't change between queries
3. **Subarray Sum Problems** - Finding subarrays with specific sum properties

---

### **🔑 Magic Keywords:**

| Keyword in Problem | Think This |
|-------------------|------------|
| "Range sum query" | ✅ PREFIX SUM |
| "Subarray with sum K" | ✅ PREFIX + HASHMAP |
| "Count subarrays where..." | ✅ PREFIX + HASHMAP |
| "Equilibrium index" | ✅ PREFIX + SUFFIX |
| "Product except self" | ✅ PREFIX × SUFFIX |
| "Left sum = Right sum" | ✅ PREFIX + SUFFIX |
| "Multiple queries [l, r]" | ✅ PREFIX SUM |

---

### **❓ Questions to Ask Yourself:**

1. **Are there multiple queries?** → Preprocessing helps!
2. **Is the array static (no updates)?** → Prefix sum perfect!
3. **Do I need cumulative information?** → Prefix/suffix sum!
4. **Am I counting subarrays?** → Prefix sum + hashmap!

---

### **🎨 Pattern vs Other Techniques:**

| Pattern | When to Use | Key Difference |
|---------|------------|----------------|
| **Prefix Sum** | Multiple range queries, static array | O(1) query after O(n) preprocessing |
| **Sliding Window** | Find subarray with constraint, variable size | Two pointers, no preprocessing |
| **Kadane's** | Maximum sum subarray | Dynamic programming approach |
| **Two Pointer** | Two elements with property | Process from both ends |

---

<a name="video3"></a>
## 🎨 VIDEO 3: THE CORE CONCEPT - WHY IT WORKS

### **The Intuition:**

Think of **prefix sum** as a **RUNNING TOTAL** while walking through array:

```
Array: [2, 4, 1, 3, 5]

Walking forward (Prefix):
─────────────────────────
Step 0: Total = 2
Step 1: Total = 2+4 = 6
Step 2: Total = 6+1 = 7
Step 3: Total = 7+3 = 10
Step 4: Total = 10+5 = 15

Walking backward (Suffix):
─────────────────────────
Step 4: Total = 5
Step 3: Total = 3+5 = 8
Step 2: Total = 1+8 = 9
Step 1: Total = 4+9 = 13
Step 0: Total = 2+13 = 15
```

---

### **Visual Representation:**

```
Finding sum of arr[2...4] (elements: 1, 3, 5)

Prefix Array: [2, 6, 7, 10, 15]
                     ↑       ↑
                   l-1=1    r=4

sum = prefix[4] - prefix[1]
    = 15 - 6
    = 9 ✅

Verification: 1 + 3 + 5 = 9 ✅
```

---

### **🔑 Key Formula Explained:**

```cpp
sum(l, r) = prefix[r] - prefix[l-1]

Why?
────────────────────────────────────────
prefix[r] contains: arr[0] + arr[1] + ... + arr[r]
prefix[l-1] contains: arr[0] + arr[1] + ... + arr[l-1]

Subtract them:
prefix[r] - prefix[l-1] = arr[l] + arr[l+1] + ... + arr[r]

This is EXACTLY what we want! ✅

Edge Case: If l = 0, then use prefix[r] directly
(no need to subtract anything)
```

---

<a name="video4"></a>
## 📝 VIDEO 4: GENERIC TEMPLATES (MUSCLE MEMORY)

### **✍️ TEMPLATE 1: BASIC PREFIX SUM**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    
    // Step 1: Initialize first element
    prefix[0] = arr[0];
    
    // Step 2: Build prefix array
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    return prefix;
}

// Query: Sum of range [l, r]
int rangeSum(vector<int>& prefix, int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
```

**Time:** Build O(n), Query O(1) | **Space:** O(n)

---

### **✍️ TEMPLATE 2: SUFFIX SUM**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
vector<int> buildSuffixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> suffix(n);
    
    // Step 1: Initialize last element
    suffix[n-1] = arr[n-1];
    
    // Step 2: Build suffix array (backward)
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] + arr[i];
    }
    
    return suffix;
}

// Query: Sum from index i to end
int suffixSum(vector<int>& suffix, int i) {
    return suffix[i];
}
```

**Time:** Build O(n), Query O(1) | **Space:** O(n)

---

### **✍️ TEMPLATE 3: PREFIX SUM + HASHMAP (Subarray Count)**

```cpp
// For counting subarrays with sum = K
int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> mp;  // prefix_sum → frequency
    mp[0] = 1;  // Empty subarray has sum 0
    
    int sum = 0;    // Running prefix sum
    int count = 0;  // Answer
    
    for (int x : arr) {
        sum += x;
        
        // Check if (sum - k) exists
        if (mp.count(sum - k)) {
            count += mp[sum - k];
        }
        
        // Store current prefix sum
        mp[sum]++;
    }
    
    return count;
}
```

**Time:** O(n) | **Space:** O(n)

---

### **✍️ TEMPLATE 4: 2D PREFIX SUM (Matrix)**

```cpp
// Build 2D prefix sum matrix
vector<vector<int>> build2DPrefix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prefix(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i][j] = matrix[i][j]
                         + (i > 0 ? prefix[i-1][j] : 0)
                         + (j > 0 ? prefix[i][j-1] : 0)
                         - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0);
        }
    }
    
    return prefix;
}

// Query: Sum of submatrix (x1,y1) to (x2,y2)
int matrixRangeSum(vector<vector<int>>& prefix, int x1, int y1, int x2, int y2) {
    int result = prefix[x2][y2];
    if (x1 > 0) result -= prefix[x1-1][y2];
    if (y1 > 0) result -= prefix[x2][y1-1];
    if (x1 > 0 && y1 > 0) result += prefix[x1-1][y1-1];
    return result;
}
```

**Time:** Build O(n×m), Query O(1) | **Space:** O(n×m)

---

### **🔥 Mantras (Say 10 times!):**

**"Precompute ONCE, Query INSTANTLY!"**

**"prefix[r] - prefix[l-1] = sum of range [l, r]"**

**"Prefix forward, Suffix backward!"**

**"For subarray count: Use prefix + hashmap!"**

---

### **💡 Memory Hooks:**

**Hook 1: The Accumulator 💰**
- **Prefix Sum** = Wallet growing as you collect coins
- Each step, add current coin to wallet
- At any point, know total collected so far!

**Hook 2: The Subtraction Trick ✂️**
- Want sum [l, r]? Think SCISSORS!
- Cut off the part [0, l-1] from [0, r]
- What remains is [l, r]!

**Hook 3: The Bookkeeper 📚**
- Prefix = Running balance from START
- Suffix = Running balance from END
- Meet in middle = Equilibrium!

---

<a name="problem1"></a>
## 🎯 VIDEO 5: PROBLEM 1 - RANGE SUM QUERY

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an array of `n` integers and `q` queries, each query asks for the sum of elements from index `l` to `r` (0-based). Answer all queries efficiently.

**Input:**
```
arr = [1, 3, 5, 7, 9]
queries = [[0, 2], [1, 3], [2, 4]]
```

**Output:**
```
9   (sum of arr[0...2] = 1+3+5)
15  (sum of arr[1...3] = 3+5+7)
21  (sum of arr[2...4] = 5+7+9)
```

**Constraints:**
- 1 ≤ n ≤ 10^5
- 1 ≤ q ≤ 10^5
- No array updates between queries

---

### **2️⃣ IDENTIFICATION**

**How do you know it's PREFIX SUM?**

✅ **Sign 1:** Multiple range sum queries  
✅ **Sign 2:** Static array (no updates)  
✅ **Sign 3:** Need O(1) per query

**Magic Keywords:**
- "Range sum query"
- "Multiple queries"
- "Sum from l to r"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Brute Force:
────────────────────────────────────
For each query [l, r]:
    sum = 0
    for i = l to r:
        sum += arr[i]
    return sum

Time: O(Q × n) - TOO SLOW! ❌

Optimal Approach (Prefix Sum):
────────────────────────────────────
Step 1: Build prefix sum array - O(n)
Step 2: For each query [l, r]:
        - If l = 0: return prefix[r]
        - Else: return prefix[r] - prefix[l-1]
        
Time: O(n + Q) ✅
Space: O(n)
```

**Strategy:**
1. Precompute prefix sum array ONCE
2. Use formula: `sum(l, r) = prefix[r] - prefix[l-1]`
3. Handle edge case when l = 0

---

### **4️⃣ DRY RUN**

**Array:** `[1, 3, 5, 7, 9]`

**Step 1: Build Prefix Sum**
```
i=0: prefix[0] = arr[0] = 1
i=1: prefix[1] = prefix[0] + arr[1] = 1 + 3 = 4
i=2: prefix[2] = prefix[1] + arr[2] = 4 + 5 = 9
i=3: prefix[3] = prefix[2] + arr[3] = 9 + 7 = 16
i=4: prefix[4] = prefix[3] + arr[4] = 16 + 9 = 25

prefix = [1, 4, 9, 16, 25]
```

**Step 2: Answer Queries**

**Query 1: [l=0, r=2]**
```
l = 0, so return prefix[2] = 9 ✅
```

**Query 2: [l=1, r=3]**
```
sum = prefix[3] - prefix[0]
    = 16 - 1
    = 15 ✅
```

**Query 3: [l=2, r=4]**
```
sum = prefix[4] - prefix[1]
    = 25 - 4
    = 21 ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    vector<int> rangeSum(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        // Build prefix sum array
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        
        // Answer queries
        vector<int> result;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            
            if (l == 0) {
                result.push_back(prefix[r]);
            } else {
                result.push_back(prefix[r] - prefix[l-1]);
            }
        }
        
        return result;
    }
};
```

**Complexity:**
- **Time:** O(n + q) - n for building prefix, q for queries
- **Space:** O(n) - prefix array

---

<a name="problem2"></a>
## 🎯 VIDEO 6: PROBLEM 2 - SUBARRAY SUM EQUALS K

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an array and an integer `k`, find the total number of continuous subarrays whose sum equals `k`.

**Input:**
```
arr = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3]
k = 3
```

**Output:**
```
8
```

**Explanation:**  
Subarrays with sum 3:
- [1, 2]
- [3]
- [3, -3, 1, 1, 1]
- [1, 1, 1]
- [-3, 1, 1, 1, 4, 2, -3]
- [2, -3, 1, 1, 1, 4, 2, -3]
- [4, 2, -3]
- (and one more)

---

### **2️⃣ IDENTIFICATION**

**How do you know it's PREFIX SUM + HASHMAP?**

✅ **Sign 1:** Count subarrays with specific sum  
✅ **Sign 2:** Need to track cumulative sums  
✅ **Sign 3:** Array can have negatives

**Magic Keywords:**
- "Subarray with sum K"
- "Count subarrays where sum equals..."
- "Continuous subarray"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Key Insight:
────────────────────────────────────
If prefix[j] - prefix[i] = k
Then subarray [i+1...j] has sum k!

Rearrange:
prefix[i] = prefix[j] - k

So at each position j:
- Calculate prefix[j]
- Check if (prefix[j] - k) exists in hashmap
- If yes, add its frequency to count!
────────────────────────────────────
```

**Strategy:**
1. Use hashmap to store prefix sum frequencies
2. Initialize: `map[0] = 1` (empty subarray)
3. For each element:
   - Add to running sum
   - Check if `(sum - k)` exists in map
   - Add current sum to map

---

### **4️⃣ DRY RUN**

**Array:** `[1, 2, 3]`, **k = 3**

```
Initialize:
───────────
map = {0: 1}  // Empty subarray
sum = 0
count = 0

i=0: arr[0]=1
───────────
sum = 0 + 1 = 1
Check: sum - k = 1 - 3 = -2
       -2 in map? NO
map[1]++ → map = {0: 1, 1: 1}
count = 0

i=1: arr[1]=2
───────────
sum = 1 + 2 = 3
Check: sum - k = 3 - 3 = 0
       0 in map? YES! count += map[0] = 1
map[3]++ → map = {0: 1, 1: 1, 3: 1}
count = 1  (subarray [1, 2])

i=2: arr[2]=3
───────────
sum = 3 + 3 = 6
Check: sum - k = 6 - 3 = 3
       3 in map? YES! count += map[3] = 1
map[6]++ → map = {0: 1, 1: 1, 3: 1, 6: 1}
count = 2  (subarray [3])

Final: 2 subarrays with sum 3 ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;  // prefix_sum → frequency
        mp[0] = 1;  // Empty subarray
        
        int sum = 0;
        int count = 0;
        
        for (int x : arr) {
            sum += x;
            
            // Check if (sum - k) exists
            if (mp.count(sum - k)) {
                count += mp[sum - k];
            }
            
            // Store current prefix sum
            mp[sum]++;
        }
        
        return count;
    }
};
```

**Complexity:**
- **Time:** O(n) - single pass
- **Space:** O(n) - hashmap

---

<a name="problem3"></a>
## 🎯 VIDEO 7: PROBLEM 3 - EQUILIBRIUM INDEX

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Find an index where the sum of elements to the left equals the sum of elements to the right.

**Input:**
```
arr = [1, 3, 5, 2, 2]
```

**Output:**
```
2
```

**Explanation:**  
At index 2 (element 5):
- Left sum = 1 + 3 = 4
- Right sum = 2 + 2 = 4
- Both equal! ✅

---

### **2️⃣ IDENTIFICATION**

**How do you know it's PREFIX + SUFFIX?**

✅ **Sign 1:** Compare left side vs right side  
✅ **Sign 2:** Need cumulative sums from both directions  
✅ **Sign 3:** Looking for balance point

**Magic Keywords:**
- "Equilibrium index"
- "Left sum = Right sum"
- "Partition array"
- "Balance point"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
At index i:
───────────────────────────────────
Left sum = sum(0...i-1)
Right sum = sum(i+1...n-1)

We need: Left sum = Right sum

Using total:
───────────────────────────────────
Total = sum of entire array
Left sum = prefix sum up to i-1
Right sum = Total - prefix sum up to i

Check: Left sum = Right sum
```

**Strategy:**
1. Calculate total sum
2. Iterate with running left sum
3. At each index:
   - Right sum = total - left sum - arr[i]
   - Check if left sum = right sum
   - Update left sum

---

### **4️⃣ DRY RUN**

**Array:** `[1, 3, 5, 2, 2]`

```
Total sum = 1 + 3 + 5 + 2 + 2 = 13

i=0: arr[0]=1
───────────
left = 0
right = 13 - 0 - 1 = 12
left ≠ right
left = 0 + 1 = 1

i=1: arr[1]=3
───────────
left = 1
right = 13 - 1 - 3 = 9
left ≠ right
left = 1 + 3 = 4

i=2: arr[2]=5
───────────
left = 4
right = 13 - 4 - 5 = 4
left = right! ✅ Return index 2

Answer: 2
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    int equilibriumIndex(vector<int>& arr) {
        int n = arr.size();
        
        // Calculate total sum
        int total = 0;
        for (int x : arr) total += x;
        
        // Find equilibrium index
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            // Right sum = total - leftSum - arr[i]
            int rightSum = total - leftSum - arr[i];
            
            if (leftSum == rightSum) {
                return i;
            }
            
            leftSum += arr[i];
        }
        
        return -1;  // No equilibrium found
    }
};
```

**Complexity:**
- **Time:** O(n) - two passes
- **Space:** O(1) - only variables

---

<a name="problem4"></a>
## 🎯 VIDEO 8: PROBLEM 4 - 2D MATRIX RANGE SUM

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given a 2D matrix and multiple queries, each query asks for the sum of elements in a submatrix defined by top-left `(x1, y1)` and bottom-right `(x2, y2)`.

**Input:**
```
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
query = (1, 1) to (2, 2)
```

**Output:**
```
28
```

**Explanation:**  
Submatrix: [[5, 6], [8, 9]]  
Sum = 5 + 6 + 8 + 9 = 28

---

### **2️⃣ IDENTIFICATION**

**How do you know it's 2D PREFIX SUM?**

✅ **Sign 1:** Matrix/2D array  
✅ **Sign 2:** Multiple submatrix sum queries  
✅ **Sign 3:** Need O(1) per query

**Magic Keywords:**
- "Submatrix sum"
- "2D range query"
- "Matrix rectangle sum"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
2D Prefix Sum Formula:
─────────────────────────────────────────────
prefix[i][j] = sum of all elements from (0,0) to (i,j)

Building prefix[i][j]:
prefix[i][j] = matrix[i][j]
             + prefix[i-1][j]     (add top)
             + prefix[i][j-1]     (add left)
             - prefix[i-1][j-1]   (subtract overlap)

Query sum from (x1,y1) to (x2,y2):
result = prefix[x2][y2]
       - prefix[x1-1][y2]          (subtract top)
       - prefix[x2][y1-1]          (subtract left)
       + prefix[x1-1][y1-1]        (add back overlap)
─────────────────────────────────────────────
```

---

### **4️⃣ DRY RUN**

**Matrix:**
```
[1, 2, 3]
[4, 5, 6]
[7, 8, 9]
```

**Build 2D Prefix:**
```
prefix[0][0] = 1
prefix[0][1] = 1 + 2 = 3
prefix[0][2] = 3 + 3 = 6

prefix[1][0] = 1 + 4 = 5
prefix[1][1] = 1 + 2 + 4 + 5 = 12
prefix[1][2] = 1 + 2 + 3 + 4 + 5 + 6 = 21

prefix[2][0] = 1 + 4 + 7 = 12
prefix[2][1] = 1 + 2 + 4 + 5 + 7 + 8 = 27
prefix[2][2] = 1 + 2 + ... + 9 = 45

Prefix Matrix:
[1,  3,  6]
[5, 12, 21]
[12, 27, 45]
```

**Query: (1,1) to (2,2)**
```
result = prefix[2][2]
       - prefix[0][2]
       - prefix[2][0]
       + prefix[0][0]
       
     = 45 - 6 - 12 + 1
     = 28 ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    vector<vector<int>> buildPrefix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = matrix[i][j];
                if (i > 0) prefix[i][j] += prefix[i-1][j];
                if (j > 0) prefix[i][j] += prefix[i][j-1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        
        return prefix;
    }
    
    int querySum(vector<vector<int>>& prefix, int x1, int y1, int x2, int y2) {
        int result = prefix[x2][y2];
        if (x1 > 0) result -= prefix[x1-1][y2];
        if (y1 > 0) result -= prefix[x2][y1-1];
        if (x1 > 0 && y1 > 0) result += prefix[x1-1][y1-1];
        return result;
    }
};
```

**Complexity:**
- **Time:** Build O(n×m), Query O(1)
- **Space:** O(n×m)

---

<a name="problem5"></a>
## 🎯 VIDEO 9: PROBLEM 5 - PRODUCT OF ARRAY EXCEPT SELF

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an array, return an array where each element at index `i` is the product of all elements except `arr[i]`. **Cannot use division!**

**Input:**
```
arr = [1, 2, 3, 4]
```

**Output:**
```
[24, 12, 8, 6]
```

**Explanation:**
- result[0] = 2 × 3 × 4 = 24
- result[1] = 1 × 3 × 4 = 12
- result[2] = 1 × 2 × 4 = 8
- result[3] = 1 × 2 × 3 = 6

---

### **2️⃣ IDENTIFICATION**

**How do you know it's PREFIX × SUFFIX?**

✅ **Sign 1:** Product of all EXCEPT current  
✅ **Sign 2:** Cannot use division  
✅ **Sign 3:** Need left product × right product

**Magic Keywords:**
- "Product except self"
- "Cannot use division"
- "Product of all other elements"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
At index i, we need:
───────────────────────────────────
result[i] = (product of left elements) × (product of right elements)
         = prefix[i-1] × suffix[i+1]

Strategy:
───────────────────────────────────
1. Build prefix product array (left to right)
2. Build suffix product array (right to left)
3. result[i] = prefix[i-1] × suffix[i+1]

Optimization: Can do in O(1) space using result array!
```

---

### **4️⃣ DRY RUN**

**Array:** `[1, 2, 3, 4]`

**Step 1: Build Prefix Products**
```
prefix[0] = 1
prefix[1] = 1 × 2 = 2
prefix[2] = 2 × 3 = 6
prefix[3] = 6 × 4 = 24

prefix = [1, 2, 6, 24]
```

**Step 2: Build Suffix Products**
```
suffix[3] = 4
suffix[2] = 3 × 4 = 12
suffix[1] = 2 × 12 = 24
suffix[0] = 1 × 24 = 24

suffix = [24, 24, 12, 4]
```

**Step 3: Calculate Result**
```
result[0] = 1 (left) × 24 (suffix[1]) = 24
result[1] = 1 (prefix[0]) × 12 (suffix[2]) = 12
result[2] = 2 (prefix[1]) × 4 (suffix[3]) = 8
result[3] = 6 (prefix[2]) × 1 (right) = 6

result = [24, 12, 8, 6] ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 1);
        
        // Build prefix products in result array
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= arr[i];
        }
        
        // Multiply with suffix products
        int suffix = 1;
        for (int i = n-1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= arr[i];
        }
        
        return result;
    }
};
```

**Complexity:**
- **Time:** O(n) - two passes
- **Space:** O(1) - excluding output array

---

### Why Use Prefix Sum?

- To answer sum queries for any subarray in O(1) time after O(n) preprocessing.
- Useful in range sum, subarray sum, and frequency problems.

---

### How to Build Prefix Sum Array

```cpp
vector<int> arr = {2, 4, 1, 3, 5};
vector<int> prefix(arr.size());
prefix[0] = arr[0];
for(int i = 1; i < arr.size(); i++) {
    prefix[i] = prefix[i-1] + arr[i];
}
```

---

### How to Use Prefix Sum

**Find sum of subarray [l, r]:**

```cpp
int sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
```

---

### Example Problem 1: Range Sum Query

**Problem:** Given an array and multiple queries of the form [l, r], find the sum of elements from l to r for each query.

**Solution:**  
- Build prefix sum array.
- For each query, use the formula above.

---

### Example Problem 2: Count Subarrays with Given Sum

**Problem:** Find the number of subarrays with sum equal to k.

**Solution:**  
- Use prefix sum and unordered_map to store frequencies.

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;
    for(int x : nums) {
        sum += x;
        if(mp.count(sum - k)) count += mp[sum - k];
        mp[sum]++;
    }
    return count;
}
```

---

## 2. What is Suffix Sum?

A **suffix sum** array is an array where each element at index `i` is the sum of all elements from index `i` to the end of the original array.

**Formula:**  
`suffix[i] = arr[i] + arr[i+1] + ... + arr[n-1]`

---

### How to Build Suffix Sum Array

```cpp
vector<int> arr = {2, 4, 1, 3, 5};
vector<int> suffix(arr.size());
suffix[arr.size()-1] = arr[arr.size()-1];
for(int i = arr.size()-2; i >= 0; i--) {
    suffix[i] = suffix[i+1] + arr[i];
}
```

---

### When to Use Suffix Sum?

- When you need to answer queries about the sum from index `i` to the end.
- Useful in problems involving right-side cumulative sums, or when combining prefix and suffix logic.

---

### Example Problem 3: Suffix Sum Application

**Problem:** Given an array, for each index, print the sum of elements to its right.

**Solution:**

```cpp
vector<int> arr = {2, 4, 1, 3, 5};
vector<int> suffix(arr.size());
suffix[arr.size()-1] = arr[arr.size()-1];
for(int i = arr.size()-2; i >= 0; i--) {
    suffix[i] = suffix[i+1] + arr[i];
}
// For each i, sum to the right is suffix[i+1] (if i+1 < n)
```

---

## 3. When to Use Prefix/Suffix Sums?

- **Prefix Sum:**  
  - Range sum queries (many queries, static array)
  - Subarray sum problems
  - Cumulative frequency/count problems

- **Suffix Sum:**  
  - Right-side cumulative queries
  - Problems where you need to know the sum of elements after a given index

---

## 4. Practice Problems

1. **Range Sum Query:**  
   Given an array and Q queries [l, r], return the sum for each query.

2. **Equilibrium Index:**  
   Find an index where the sum of elements to the left equals the sum to the right.

3. **Count Subarrays with Given Sum:**  
   Find the number of subarrays with sum k.

4. **Partition Array:**  
   Find if there exists a point where prefix sum equals suffix sum.

---

## 5. Tips

- Always preprocess prefix/suffix sums if you have multiple range queries.
- Use unordered_map with prefix sums for subarray sum problems.
- For large arrays, use `long long` to avoid overflow.

---

**Summary:**  
Prefix and suffix sums are powerful tools for optimizing range queries and subarray problems. Recognize patterns in problems where cumulative sums can reduce time complexity from O(n*q) to O(n+q).

---

<a name="reference"></a>
##  QUICK REFERENCE SHEET - See PREFIX-SUFFIX-COMPLETE.md

<a name="learning"></a>
##  7-DAY LEARNING PATH - See PREFIX-SUFFIX-COMPLETE.md

---

** ALL CONTENT COMPLETE! Check these files:**

1. **Prefix-suffix.md** - Main concept file with all 5 problems (this file)
2. **PREFIX-SUFFIX-COMPLETE.md** - Quick reference, templates, learning path
3. **MUSCLE-MEMORY-PREFIX-SUFFIX.md** - One-page printable summary

**All the best! **
