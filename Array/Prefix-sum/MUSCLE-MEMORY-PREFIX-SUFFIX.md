#  PREFIX & SUFFIX SUM - MUSCLE MEMORY EDITION


---

## 📋 3-SECOND RECOGNITION

**Ask 3 Questions:**
1. **Multiple range queries?** ✅
2. **Static array** (no updates)? ✅
3. **Need O(1) per query?** ✅

**If all 3 YES → PREFIX SUM! 🎯**

**Special Cases:**
- Count subarrays → PREFIX + HASHMAP
- Left = Right → PREFIX + SUFFIX
- 2D Matrix → 2D PREFIX SUM

---

## 🔥 MAGIC KEYWORDS

| See This | Think This |
|----------|-----------|
| "Range sum query" | ✅ PREFIX SUM |
| "Subarray with sum K" | ✅ PREFIX + HASHMAP |
| "Count subarrays where..." | ✅ PREFIX + HASHMAP |
| "Equilibrium index" | ✅ PREFIX + SUFFIX |
| "Left sum = Right sum" | ✅ PREFIX + SUFFIX |
| "Product except self" | ✅ PREFIX × SUFFIX |
| "Submatrix sum" | ✅ 2D PREFIX SUM |
| "Multiple queries [l, r]" | ✅ PREFIX SUM |

---

## 📝 TEMPLATE 1: BASIC PREFIX SUM (Write 5x!)

```cpp
// BUILD PREFIX ARRAY
vector<int> prefix(n);
prefix[0] = arr[0];
for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}

// QUERY SUM [l, r]
int rangeSum(int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
```

**Formula:** `sum(l, r) = prefix[r] - prefix[l-1]`  
**Time:** Build O(n), Query O(1) | **Space:** O(n)

---

## 📝 TEMPLATE 2: SUFFIX SUM

```cpp
// BUILD SUFFIX ARRAY (backward!)
vector<int> suffix(n);
suffix[n-1] = arr[n-1];
for (int i = n-2; i >= 0; i--) {
    suffix[i] = suffix[i+1] + arr[i];
}

// QUERY SUM [i, n-1]
int suffixSum(int i) {
    return suffix[i];
}
```

**Time:** Build O(n), Query O(1) | **Space:** O(n)

---

## 📝 TEMPLATE 3: SUBARRAY COUNT (PREFIX + HASHMAP)

```cpp
// Count subarrays with sum = K
int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;  // IMPORTANT! Empty subarray
    
    int sum = 0, count = 0;
    
    for (int x : arr) {
        sum += x;
        
        // Check if (sum - k) exists
        if (mp.count(sum - k)) {
            count += mp[sum - k];
        }
        
        mp[sum]++;  // Store frequency
    }
    
    return count;
}
```

**Key:** If `prefix[j] - prefix[i] = k`, then `prefix[i] = prefix[j] - k`  
**Time:** O(n) | **Space:** O(n)

---

## 📝 TEMPLATE 4: EQUILIBRIUM INDEX

```cpp
// Find index where left sum = right sum
int equilibriumIndex(vector<int>& arr) {
    int total = 0;
    for (int x : arr) total += x;
    
    int leftSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        int rightSum = total - leftSum - arr[i];
        
        if (leftSum == rightSum) return i;
        
        leftSum += arr[i];
    }
    
    return -1;
}
```

**Key:** `rightSum = total - leftSum - arr[i]`  
**Time:** O(n) | **Space:** O(1)

---

## 📝 TEMPLATE 5: 2D PREFIX SUM

```cpp
// BUILD 2D PREFIX
vector<vector<int>> prefix(n, vector<int>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        prefix[i][j] = matrix[i][j]
                     + (i > 0 ? prefix[i-1][j] : 0)     // top
                     + (j > 0 ? prefix[i][j-1] : 0)     // left
                     - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0);  // overlap
    }
}

// QUERY (x1,y1) to (x2,y2)
int querySum(int x1, int y1, int x2, int y2) {
    int result = prefix[x2][y2];
    if (x1 > 0) result -= prefix[x1-1][y2];      // subtract top
    if (y1 > 0) result -= prefix[x2][y1-1];      // subtract left
    if (x1 > 0 && y1 > 0) result += prefix[x1-1][y1-1];  // add overlap
    return result;
}
```

**Time:** Build O(n×m), Query O(1) | **Space:** O(n×m)

---

## 💪 MANTRA (Say 10x!)

**"Precompute ONCE, Query INSTANTLY!"**

**"prefix[r] - prefix[l-1] = sum of [l, r]"**

**"For subarray count: prefix + hashmap!"**

**"Equilibrium: left = total - left - current"**

---

## 🎨 DRY RUN EXAMPLE

**Array:** `[1, 3, 5, 7, 9]`

### **Build Prefix:**
```
i=0: prefix[0] = 1
i=1: prefix[1] = 1 + 3 = 4
i=2: prefix[2] = 4 + 5 = 9
i=3: prefix[3] = 9 + 7 = 16
i=4: prefix[4] = 16 + 9 = 25

prefix = [1, 4, 9, 16, 25]
```

### **Query sum[1, 3]:**
```
l=1, r=3
sum = prefix[3] - prefix[0]
    = 16 - 1
    = 15 ✅

Verify: arr[1] + arr[2] + arr[3] = 3 + 5 + 7 = 15 ✅
```

---

## 🎯 5 PROBLEM PATTERNS

### **Pattern 1: RANGE SUM QUERY** ⭐⭐⭐⭐⭐

**Problem:** Answer Q queries for sum [l, r]

**Key:** Build prefix, query O(1)

```cpp
int sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l-1];
```

---

### **Pattern 2: SUBARRAY SUM = K** ⭐⭐⭐⭐⭐

**Problem:** Count subarrays with sum K

**Key:** Prefix + HashMap

```cpp
if (mp.count(sum - k)) count += mp[sum - k];
mp[sum]++;
```

---

### **Pattern 3: EQUILIBRIUM INDEX** ⭐⭐⭐⭐

**Problem:** Find where left sum = right sum

**Key:** Total sum trick

```cpp
rightSum = total - leftSum - arr[i];
if (leftSum == rightSum) return i;
```

---

### **Pattern 4: PRODUCT EXCEPT SELF** ⭐⭐⭐⭐⭐

**Problem:** Product of all except current (no division!)

**Key:** Prefix × Suffix products

```cpp
// Forward pass: prefix products
// Backward pass: multiply with suffix products
```

---

### **Pattern 5: 2D MATRIX QUERY** ⭐⭐⭐⭐

**Problem:** Sum of submatrix

**Key:** 2D prefix sum

```cpp
sum = prefix[x2][y2] - prefix[x1-1][y2] 
    - prefix[x2][y1-1] + prefix[x1-1][y1-1];
```

---

## 📊 DECISION TREE

```
START: Range/subarray problem
    ↓
Q: Multiple sum queries [l, r]?
    ↓
YES → BASIC PREFIX SUM

Q: Count subarrays with sum K?
    ↓
YES → PREFIX + HASHMAP

Q: Left sum = Right sum?
    ↓
YES → EQUILIBRIUM (PREFIX + SUFFIX)

Q: Product except self?
    ↓
YES → PREFIX × SUFFIX PRODUCTS

Q: 2D matrix queries?
    ↓
YES → 2D PREFIX SUM
```

---

## ⏱️ COMPLEXITY CHEAT SHEET

| Pattern | Build | Query | Space |
|---------|-------|-------|-------|
| Basic Prefix | O(n) | O(1) | O(n) |
| Suffix Sum | O(n) | O(1) | O(n) |
| Prefix + HashMap | O(n) | - | O(n) |
| Equilibrium | O(n) | - | O(1) |
| 2D Prefix | O(n×m) | O(1) | O(n×m) |

---

## 🎤 INTERVIEW SCRIPT

**Recognition:**
> "Sir, I see we need [multiple range queries / count subarrays]. This is classic prefix sum - O(n) preprocessing, O(1) queries!"

**Approach:**
> "I'll build a prefix sum array storing cumulative sums. For range [l, r], I use formula: prefix[r] - prefix[l-1]. This avoids repeated computation!"

**Complexity:**
> "Time: O(n) preprocessing + O(q) for q queries. Space: O(n). Much better than O(n×q) brute force!"


---

### **Drill 2: Pattern Recognition (3 sec each)**

```
1. "Find sum [l, r] for Q queries"
   → BASIC PREFIX ✅

2. "Count subarrays sum = K"
   → PREFIX + HASHMAP ✅

3. "Left sum = Right sum"
   → EQUILIBRIUM ✅

4. "Product except self (no division)"
   → PREFIX × SUFFIX ✅

5. "Submatrix sum queries"
   → 2D PREFIX ✅
```

---



## 🔥 GOLDEN RULES

1. **"Precompute ONCE, Query O(1)!"**
2. **"sum[l,r] = prefix[r] - prefix[l-1]"**
3. **"Subarray count? Add hashmap!"**
4. **"Watch l=0 edge case!"**
5. **"2D? Add surrounding, subtract overlap"**



---


## 🎯 ONE-PAGE PRINTABLE

```
╔══════════════════════════════════════════════════════════╗
║        PREFIX & SUFFIX SUM - CHEAT SHEET                ║
╚══════════════════════════════════════════════════════════╝

📌 RECOGNITION:
   Multiple queries? Static array? → PREFIX SUM!
   Count subarrays? → PREFIX + HASHMAP!

📌 BASIC TEMPLATE:
   
   prefix[0] = arr[0];
   for (i = 1; i < n; i++)
       prefix[i] = prefix[i-1] + arr[i];
   
   sum(l, r) = prefix[r] - prefix[l-1]
                           (watch l=0!)

📌 HASHMAP TEMPLATE (Subarray Count):
   
   map[0] = 1;
   sum = 0, count = 0;
   
   for (x : arr) {
       sum += x;
       count += map[sum - k];
       map[sum]++;
   }

📌 5 PATTERNS:
   1. Range Query → Basic prefix
   2. Subarray = K → Prefix + hashmap
   3. Equilibrium → Prefix + suffix
   4. Product Except → Prefix × suffix
   5. 2D Matrix → 2D prefix

📌 COMPLEXITY:
   Build: O(n), Query: O(1), Space: O(n)

📌 KEY FORMULAS:
   • sum(l,r) = prefix[r] - prefix[l-1]
   • count += map[sum - k]
   • rightSum = total - leftSum - arr[i]

📌 COMMON MISTAKES:
   ❌ Forget l=0 edge case
   ❌ Wrong formula for range
   ❌ Not init map[0]=1 for subarray
   ❌ Integer overflow

📌 MANTRAS:
   • "Precompute ONCE, Query INSTANTLY!"
   • "Subtract to get range!"
   • "Hashmap tracks what we've seen!"

╔══════════════════════════════════════════════════════════╗
║  "prefix[r] - prefix[l-1] = Magic Range Sum!" 🔥        ║
╚══════════════════════════════════════════════════════════╝
```

---

**🎯 You got this! Prefix Sum is muscle memory now! 💪**

**All the best! 🚀**

---

