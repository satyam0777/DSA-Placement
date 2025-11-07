# PREFIX SUM - INTERVIEW READY PACKAGE

---


##  TABLE OF CONTENTS

1. [One-Line Recognition](#recognition)
2. [The Core Concept](#concept)
3. [Top 8 Problems](#problems)
4. [Interview Scripts](#communication)
5. [Company Questions](#companies)

---

<a name="recognition"></a>
##  ONE-LINE RECOGNITION

### **When to Use Prefix Sum?**

**If you see THESE keywords → Prefix Sum:**
- "**Range sum** query"
- "**Subarray sum** equals k"
- "**Multiple queries** for sum"
- "Sum of elements from **index i to j**"
- "**Equilibrium** point"
- "**Partition** array"

**Key Signal:** Multiple range queries OR subarray sum with target

---

<a name="concept"></a>
##  THE CORE CONCEPT

### **What is Prefix Sum?**

**Prefix sum at index i = Sum of all elements from 0 to i**

```cpp
prefix[i] = arr[0] + arr[1] + ... + arr[i]
```

### **How to Build:**
```cpp
vector<int> prefix(n);
prefix[0] = arr[0];
for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}
```

### **How to Use (Range Sum):**
```cpp
// Sum from index l to r:
int rangeSum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
```

### **Why Prefix Sum?**
- **Without prefix:** Each range query = O(n) → Total O(n*q)
- **With prefix:** Build O(n) + Each query O(1) → Total O(n+q)

**HUGE optimization for multiple queries!**

---

<a name="problems"></a>
##  TOP 8 PREFIX SUM PROBLEMS

### **Problem 1: Range Sum Query (Classic)** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Given array and Q queries [l, r], find sum from index l to r for each query."

**Template:**
```cpp
class RangeSumQuery {
    vector<int> prefix;
public:
    RangeSumQuery(vector<int>& arr) {
        int n = arr.size();
        prefix.resize(n);
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    
    int sumRange(int l, int r) {
        if(l == 0) return prefix[r];
        return prefix[r] - prefix[l-1];
    }
};
```

**What to Say:**
> "Sir, I'll precompute prefix sums in O(n). Then each query becomes O(1) - just subtract prefix[l-1] from prefix[r]. For Q queries, total time O(n+Q) instead of O(n*Q)."

**Dry Run:**
```
Array: [1, 3, 5, 7, 9]
Prefix: [1, 4, 9, 16, 25]

Query [1, 3]: sum(3,5,7)
Answer: prefix[3] - prefix[0] = 16 - 1 = 15 ✅

Query [2, 4]: sum(5,7,9)
Answer: prefix[4] - prefix[1] = 25 - 4 = 21 ✅
```

---

### **Problem 2: Subarray Sum Equals K** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find count of subarrays with sum equal to k."

**Template (Prefix Sum + HashMap):**
```cpp
int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;  // Empty subarray
    
    int prefixSum = 0, count = 0;
    
    for(int num : arr) {
        prefixSum += num;
        
        // Check if (prefixSum - k) exists
        if(prefixCount.count(prefixSum - k)) {
            count += prefixCount[prefixSum - k];
        }
        
        prefixCount[prefixSum]++;
    }
    
    return count;
}
```

**What to Say:**
> "Sir, I'll use prefix sum with hashmap. Key insight: if prefix sum at j is (prefixSum - k), then subarray from that point to current has sum k. I track prefix sum frequencies. Time O(n), Space O(n)."

**Dry Run:**
```
Array: [1, 2, 3], k = 3

i=0: prefixSum=1, check (1-3=-2), not exist, map={0:1, 1:1}, count=0
i=1: prefixSum=3, check (3-3=0), exists! count=1, map={0:1, 1:1, 3:1}
i=2: prefixSum=6, check (6-3=3), exists! count=2, map={0:1, 1:1, 3:1, 6:1}

Answer: 2
Subarrays: [1,2] and [3]
```

**CRITICAL POINT:**
> **Interviewer:** "Why prefixCount[0] = 1?"

**Your Answer:**
> "Sir, this handles case when prefix sum itself equals k. Means entire subarray from start has sum k."

---

### **Problem 3: Equilibrium Index (Pivot Point)** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find index where left sum equals right sum."

**Template:**
```cpp
int equilibriumIndex(vector<int>& arr) {
    int n = arr.size();
    
    // Build prefix sum
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    int totalSum = prefix[n-1];
    
    for(int i = 0; i < n; i++) {
        int leftSum = (i > 0) ? prefix[i-1] : 0;
        int rightSum = totalSum - prefix[i];
        
        if(leftSum == rightSum) {
            return i;  // Found!
        }
    }
    
    return -1;  // Not found
}
```

**What to Say:**
> "Sir, I'll compute total sum using prefix array. For each index, left sum = prefix[i-1], right sum = total - prefix[i]. Check if equal. Time O(n), Space O(n)."

**Dry Run:**
```
Array: [1, 3, 5, 2, 2]
Prefix: [1, 4, 9, 11, 13]
Total: 13

i=0: left=0, right=13-1=12, not equal
i=1: left=1, right=13-4=9, not equal
i=2: left=4, right=13-9=4, EQUAL! ✅

Answer: index 2
```

---

### **Problem 4: Maximum Sum Subarray with At Least Size K** ⭐⭐⭐⭐

**Template:**
```cpp
int maxSumAtLeastK(vector<int>& arr, int k) {
    int n = arr.size();
    
    // Build prefix sum
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    int maxSum = prefix[k-1];  // First k elements
    int minPrefix = 0;
    
    for(int i = k; i < n; i++) {
        // Update minPrefix (for extending left)
        minPrefix = min(minPrefix, prefix[i-k]);
        
        // Max sum ending at i with at least k elements
        maxSum = max(maxSum, prefix[i] - minPrefix);
    }
    
    return maxSum;
}
```

**What to Say:**
> "Sir, I need at least k elements. I'll track minimum prefix before current k-sized window. Maximum sum = prefix[i] - minPrefix ensures at least k elements. Time O(n), Space O(n)."

---

### **Problem 5: Product of Array Except Self** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Return array where each element is product of all others."

**Template (Prefix × Suffix):**
```cpp
vector<int> productExceptSelf(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    
    // Build prefix products
    result[0] = 1;
    for(int i = 1; i < n; i++) {
        result[i] = result[i-1] * arr[i-1];
    }
    
    // Multiply with suffix products
    int suffix = 1;
    for(int i = n-1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= arr[i];
    }
    
    return result;
}
```

**What to Say:**
> "Sir, this uses prefix and suffix products. First pass builds prefix products. Second pass multiplies with suffix products. Result[i] = prefix[i] × suffix[i]. Time O(n), Space O(1) excluding output. No division needed!"

**Dry Run:**
```
Array: [1, 2, 3, 4]

Step 1 (Prefix):
result = [1, 1, 1*2=2, 2*3=6]

Step 2 (Suffix):
suffix = 1
i=3: result[3] = 6*1 = 6, suffix = 4
i=2: result[2] = 2*4 = 8, suffix = 12
i=1: result[1] = 1*12 = 12, suffix = 24
i=0: result[0] = 1*24 = 24, suffix = 24

Result: [24, 12, 8, 6] ✅
```

---

### **Problem 6: Continuous Subarray Sum (Multiple of K)** ⭐⭐⭐⭐

**Template:**
```cpp
bool checkSubarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> remainderIndex;
    remainderIndex[0] = -1;  // For subarray from start
    
    int prefixSum = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        int remainder = prefixSum % k;
        
        if(remainderIndex.count(remainder)) {
            // Check if subarray size >= 2
            if(i - remainderIndex[remainder] >= 2) {
                return true;
            }
        } else {
            remainderIndex[remainder] = i;
        }
    }
    
    return false;
}
```

**What to Say:**
> "Sir, if two prefix sums have same remainder mod k, the subarray between them is divisible by k. I store remainder and its first occurrence index. When same remainder appears again with gap ≥ 2, found answer. Time O(n), Space O(k)."

---

### **Problem 7: Count Number of Nice Subarrays (Odd Numbers)** ⭐⭐⭐⭐

**Template:**
```cpp
int numberOfSubarrays(vector<int>& arr, int k) {
    // Convert: odd=1, even=0, then find subarrays with sum=k
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    
    int prefixSum = 0, count = 0;
    
    for(int num : arr) {
        prefixSum += (num % 2);  // Add 1 if odd, 0 if even
        
        if(prefixCount.count(prefixSum - k)) {
            count += prefixCount[prefixSum - k];
        }
        
        prefixCount[prefixSum]++;
    }
    
    return count;
}
```

**What to Say:**
> "Sir, I'll transform problem: treat odd as 1, even as 0. Then it becomes 'subarray sum equals k' which I solve with prefix sum + hashmap. Time O(n), Space O(n)."

---

### **Problem 8: Maximum Size Subarray Sum Equals K** ⭐⭐⭐⭐

**Template:**
```cpp
int maxSubArrayLen(vector<int>& arr, int k) {
    unordered_map<int, int> prefixIndex;  // First occurrence
    prefixIndex[0] = -1;
    
    int prefixSum = 0, maxLen = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        
        // Check if subarray with sum k exists
        if(prefixIndex.count(prefixSum - k)) {
            maxLen = max(maxLen, i - prefixIndex[prefixSum - k]);
        }
        
        // Store first occurrence only
        if(!prefixIndex.count(prefixSum)) {
            prefixIndex[prefixSum] = i;
        }
    }
    
    return maxLen;
}
```

**What to Say:**
> "Sir, similar to count problem but track maximum length. Store first occurrence of each prefix sum to maximize length. Time O(n), Space O(n)."

---

<a name="communication"></a>
##  INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Recognition**

> "Sir, I recognize prefix sum pattern because:
> 1. Multiple range sum queries / Subarray sum problem
> 2. Need efficient solution for queries
> 3. Prefix sum gives O(1) per query after O(n) preprocessing!"

---

### **Script 2: Building Prefix Sum**

> "Sir, first I'll build prefix sum array:
> ```
> prefix[i] = prefix[i-1] + arr[i]
> ```
> This takes O(n) time once, then each query is O(1)."

---

### **Script 3: Using Prefix for Range**

> "Sir, for sum from l to r:
> ```
> sum = prefix[r] - prefix[l-1]
> ```
> Important to handle l=0 case: just prefix[r]."

---

### **Script 4: Prefix + HashMap Pattern**

> "Sir, for subarray sum k, I use prefix sum with hashmap:
> - Track: how many times each prefix sum appeared
> - Logic: if prefix sum - k exists, found subarray
> - Why: difference between two prefix sums = subarray sum"

---

<a name="companies"></a>
##  COMPANY-WISE FREQUENCY

### **TCS** ⭐⭐⭐⭐⭐
- Range sum query (basic)
- Equilibrium index
- Subarray sum k
- **Frequency:** 35% of array interviews

---

### **Wipro** ⭐⭐⭐⭐
- Subarray sum equals k
- Product except self
- Range queries
- **Frequency:** 30%

---

### **Infosys** ⭐⭐⭐⭐⭐
- Very basic prefix sum
- Range sum query
- Equilibrium point
- **Frequency:** 40% (loves this topic!)

---

### **Cognizant** ⭐⭐⭐⭐
- Subarray sum k
- Range queries
- Product array
- **Frequency:** 30%

---

### **Capgemini** ⭐⭐⭐
- Basic range sum
- Equilibrium index
- **Frequency:** 25%

---

### **Accenture** ⭐⭐⭐⭐
- Simple range queries
- Basic prefix concepts
- **Frequency:** 30%

---

##  QUICK TEMPLATES

### **Template 1: Build Prefix Sum**
```cpp
vector<int> prefix(n);
prefix[0] = arr[0];
for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}
```

### **Template 2: Range Sum Query**
```cpp
int rangeSum(int l, int r) {
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
```

### **Template 3: Subarray Sum = K (With HashMap)**
```cpp
unordered_map<int, int> prefixCount;
prefixCount[0] = 1;
int prefixSum = 0, count = 0;

for(int num : arr) {
    prefixSum += num;
    count += prefixCount[prefixSum - k];
    prefixCount[prefixSum]++;
}
```

### **Template 4: Equilibrium Index**
```cpp
int totalSum = accumulate(arr.begin(), arr.end(), 0);
int leftSum = 0;

for(int i = 0; i < n; i++) {
    int rightSum = totalSum - leftSum - arr[i];
    if(leftSum == rightSum) return i;
    leftSum += arr[i];
}
```

---

## ❌ COMMON MISTAKES

### **Mistake 1: Off-by-One in Range Query**
```cpp
// WRONG ❌
sum = prefix[r] - prefix[l];

// CORRECT ✅
sum = (l == 0) ? prefix[r] : prefix[r] - prefix[l-1];
```

---

### **Mistake 2: Forgetting prefixCount[0] = 1**
```cpp
// For subarray sum k, MUST initialize:
prefixCount[0] = 1;  // Handles subarray from start
```

---

### **Mistake 3: Integer Overflow**
```cpp
// For large arrays, use long long:
vector<long long> prefix(n);
```

---



##  FINAL TIPS

### **Pattern Recognition:**
```
Multiple queries? → Prefix Sum
Subarray sum k? → Prefix + HashMap
Range [l,r]? → Prefix Sum
Equilibrium? → Prefix/Suffix Sum
```

### **Golden Formula:**
```
Range Sum [l, r] = prefix[r] - prefix[l-1]

Subarray Sum = k:
if (prefixSum - k) exists → found subarray
```


---

*Remember: Prefix sum turns O(n*Q) into O(n+Q) - that's HUGE!*

**All the best, Satyam!** 🌟
