# 🎯 PREFIX & SUFFIX SUM - QUICK REFERENCE SHEET

---

## 📋 PATTERN RECOGNITION

### **3-Second Recognition:**

Ask these questions:
1. **Multiple range queries?** → PREFIX SUM
2. **Count subarrays with sum K?** → PREFIX + HASHMAP
3. **Left sum = Right sum?** → PREFIX + SUFFIX
4. **Product except self?** → PREFIX × SUFFIX
5. **2D matrix queries?** → 2D PREFIX SUM

---

## 🎯 GENERIC TEMPLATES

### **Template 1: Basic Prefix Sum**

```cpp
// Build prefix array
vector<int> prefix(n);
prefix[0] = arr[0];
for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}

// Query sum [l, r]
int sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l-1];
```

---

### **Template 2: Suffix Sum**

```cpp
// Build suffix array
vector<int> suffix(n);
suffix[n-1] = arr[n-1];
for (int i = n-2; i >= 0; i--) {
    suffix[i] = suffix[i+1] + arr[i];
}

// Query sum [i, n-1]
int sum = suffix[i];
```

---

### **Template 3: Subarray Count (Prefix + HashMap)**

```cpp
unordered_map<int, int> mp;
mp[0] = 1;
int sum = 0, count = 0;

for (int x : arr) {
    sum += x;
    if (mp.count(sum - k)) count += mp[sum - k];
    mp[sum]++;
}
```

---

### **Template 4: Equilibrium Index**

```cpp
int total = accumulate(arr.begin(), arr.end(), 0);
int leftSum = 0;

for (int i = 0; i < n; i++) {
    int rightSum = total - leftSum - arr[i];
    if (leftSum == rightSum) return i;
    leftSum += arr[i];
}
```

---

### **Template 5: 2D Prefix Sum**

```cpp
// Build 2D prefix
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        prefix[i][j] = matrix[i][j]
                     + (i > 0 ? prefix[i-1][j] : 0)
                     + (j > 0 ? prefix[i][j-1] : 0)
                     - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0);
    }
}

// Query (x1,y1) to (x2,y2)
int result = prefix[x2][y2];
if (x1 > 0) result -= prefix[x1-1][y2];
if (y1 > 0) result -= prefix[x2][y1-1];
if (x1 > 0 && y1 > 0) result += prefix[x1-1][y1-1];
```

---

## 📊 COMPLEXITY TABLE

| Pattern | Time (Build) | Time (Query) | Space |
|---------|-------------|--------------|-------|
| **Basic Prefix** | O(n) | O(1) | O(n) |
| **Suffix Sum** | O(n) | O(1) | O(n) |
| **Prefix + HashMap** | O(n) | - | O(n) |
| **Equilibrium** | O(n) | - | O(1) |
| **2D Prefix** | O(n×m) | O(1) | O(n×m) |
| **Product Except Self** | O(n) | - | O(1) |

---

## 🎯 TOP 5 PROBLEMS (Target Times)

1. **Range Sum Query** - 5 min ⭐⭐⭐⭐⭐
   - Multiple queries [l, r]
   - Build prefix, query O(1)

2. **Subarray Sum Equals K** - 8 min ⭐⭐⭐⭐⭐
   - Count subarrays with sum K
   - Prefix + HashMap

3. **Equilibrium Index** - 6 min ⭐⭐⭐⭐
   - Left sum = Right sum
   - Total sum trick

4. **Product Except Self** - 10 min ⭐⭐⭐⭐⭐
   - Cannot use division
   - Prefix × Suffix products

5. **2D Matrix Range Sum** - 12 min ⭐⭐⭐⭐
   - Submatrix queries
   - 2D prefix sum

---

## 🔑 KEY FORMULAS

### **1D Range Sum:**
```
sum(l, r) = prefix[r] - prefix[l-1]
```

### **Subarray Count:**
```
If prefix[j] - prefix[i] = k
Then count += frequency[prefix[j] - k]
```

### **Equilibrium:**
```
leftSum = rightSum
where rightSum = total - leftSum - arr[i]
```

### **2D Range Sum:**
```
sum = prefix[x2][y2]
    - prefix[x1-1][y2]
    - prefix[x2][y1-1]
    + prefix[x1-1][y1-1]
```

---

## 🎤 INTERVIEW SCRIPT

**Recognition:**
> "Sir, I see we need [range queries / count subarrays]. This is a classic prefix sum problem with O(n) preprocessing and O(1) queries!"

**Approach:**
> "I'll build a prefix sum array where prefix[i] stores the cumulative sum from start to index i. Then for any range [l, r], I can get the sum using prefix[r] - prefix[l-1]. This avoids recomputing sums repeatedly."

**Edge Cases:**
> "I need to handle when l=0 separately since there's no prefix[l-1]. Also, I'll watch for integer overflow with large sums."

**Complexity:**
> "Time: O(n) for preprocessing + O(q) for queries. Space: O(n) for prefix array. Much better than O(n×q) brute force!"

---

## 💪 MUSCLE MEMORY DRILLS

### **Drill 1: Write Templates Blind (5 min)**

Close this file. Write from memory:
1. Basic prefix sum build
2. Range query formula
3. Subarray count with hashmap

**Repeat 5 times until automatic!**

---

### **Drill 2: Pattern Recognition (3 sec each)**

```
1. "Find sum of subarray [l, r] for Q queries"
   → BASIC PREFIX SUM ✅

2. "Count subarrays with sum K"
   → PREFIX + HASHMAP ✅

3. "Find index where left sum = right sum"
   → EQUILIBRIUM (PREFIX + SUFFIX) ✅

4. "Product of all elements except current"
   → PREFIX × SUFFIX PRODUCTS ✅

5. "Sum of submatrix in 2D array"
   → 2D PREFIX SUM ✅
```

---

### **Drill 3: Dry Run Practice (10 min)**

Pick array: `[1, 3, 5, 7, 9]`

1. Build prefix sum by hand
2. Query sum[1, 3] using formula
3. Verify your answer

**Do this with 3 different arrays!**

---

## 🎓 COMMON MISTAKES & FIXES

| Mistake ❌ | Correct ✅ |
|-----------|----------|
| Forget l=0 edge case | Check if l=0, use prefix[r] directly |
| Wrong formula for range | Use prefix[r] - prefix[l-1] |
| Not initializing map[0]=1 | For subarray count, start with map[0]=1 |
| Overflow with large sums | Use `long long` for prefix sums |
| Wrong 2D formula | Remember to add back overlap: +prefix[x1-1][y1-1] |

---

## 🎯 DECISION TREE

```
START: Need to process array ranges/subarrays
    ↓
Q: Multiple range sum queries?
    ↓
YES → Build PREFIX SUM array

Q: Count subarrays with sum K?
    ↓
YES → PREFIX SUM + HASHMAP

Q: Left sum = Right sum?
    ↓
YES → EQUILIBRIUM INDEX (prefix + suffix)

Q: Product except self?
    ↓
YES → PREFIX × SUFFIX PRODUCTS

Q: 2D matrix queries?
    ↓
YES → 2D PREFIX SUM

Q: Range with condition (not just sum)?
    ↓
YES → Consider SLIDING WINDOW instead
```

---



## 💡 MEMORY HOOKS

### **Hook 1: The Accumulator 💰**
- Walking through array collecting coins
- Prefix = Total collected so far
- To get sum [l, r]: Subtract what you had before l

### **Hook 2: The Scissors ✂️**
- Prefix[r] = Sum from 0 to r
- Cut off prefix[l-1] = Sum from 0 to l-1
- What remains = Sum from l to r!

### **Hook 3: The Balance Scale ⚖️**
- Equilibrium = Left weight = Right weight
- Prefix measures left side
- Suffix measures right side
- Find the balance point!

### **Hook 4: The Product Factory 🏭**
- Left factory produces left products (prefix)
- Right factory produces right products (suffix)
- Combine both to get product except self!

---

## 🔥 GOLDEN RULES

1. **"Precompute ONCE, Query INSTANTLY!"**
2. **"prefix[r] - prefix[l-1] = sum of [l, r]"**
3. **"For subarray count: Use prefix + hashmap"**
4. **"Equilibrium: leftSum = total - leftSum - arr[i]"**
5. **"2D: Add surrounding, subtract overlap"**

---

## 📊 WHY PREFIX SUM WORKS?

```
Original Question:
"What's the sum of elements from index 3 to 7?"

Brute Force:
sum = arr[3] + arr[4] + arr[5] + arr[6] + arr[7]
Time: O(n) per query ❌

Prefix Sum Insight:
prefix[7] = arr[0] + arr[1] + ... + arr[7]
prefix[2] = arr[0] + arr[1] + arr[2]

Subtract:
prefix[7] - prefix[2] = arr[3] + arr[4] + ... + arr[7] ✅

Time: O(1) per query! 🚀

Why it's O(1)?
────────────────────────────────────
Just subtract two numbers!
No loop needed for each query!
That's the magic! ✨
```

---

**🎯 You got this! Prefix Sum is muscle memory now! 💪**
