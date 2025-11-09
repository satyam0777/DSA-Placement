# 🎯 KADANE'S ALGORITHM - ALL PROBLEMS

> **Complete problem solutions following 5-step methodology**

---

## 🎯 PROBLEM 1: MAXIMUM SUBARRAY SUM (CLASSIC)

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:** Given an array of integers, find the contiguous subarray with the largest sum.

**Input:** `arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`  
**Output:** `6`  
**Explanation:** Subarray `[4, -1, 2, 1]` has sum = 6

---

### **2️⃣ IDENTIFICATION**

- ✅ "Maximum sum" → Kadane's
- ✅ "Contiguous subarray" → Kadane's
- ✅ Array has negatives → Kadane's

---

### **3️⃣ ABSTRACT/APPROACH**

At each position: **Extend previous subarray** OR **Start fresh**  
Track: `max_ending_here` (local) and `max_so_far` (global)

---

### **4️⃣ DRY RUN**

```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: max_ending=-2, max_so_far=-2
i=1: max(1, -2+1)=1, max_so_far=1 ✅ (start fresh)
i=2: max(-3, 1-3)=-2, max_so_far=1
i=3: max(4, -2+4)=4, max_so_far=4 ✅ (start fresh)
i=4: max(-1, 4-1)=3, max_so_far=4 (extend)
i=5: max(2, 3+2)=5, max_so_far=5 ✅ (extend)
i=6: max(1, 5+1)=6, max_so_far=6 ✅ (extend)
i=7: max(-5, 6-5)=1, max_so_far=6
i=8: max(4, 1+4)=5, max_so_far=6

Answer: 6
```

---

### **5️⃣ CODE**

```cpp
int maxSubArray(vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 🎯 PROBLEM 2: MAXIMUM SUBARRAY WITH INDICES

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:** Find maximum sum subarray AND return start/end indices.

**Input:** `arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`  
**Output:** `Sum: 6, Start: 3, End: 6`

---

### **2️⃣ IDENTIFICATION**

Same as Problem 1 + need to track indices

---

### **3️⃣ ABSTRACT/APPROACH**

Track `temp_start` when starting fresh  
Update `start` and `end` when finding new maximum

---

### **4️⃣ DRY RUN**

```
i=1: Start fresh → temp_start=1
i=3: Start fresh → temp_start=3
i=6: New max found → start=3, end=6

Final: start=3, end=6, sum=6
```

---

### **5️⃣ CODE**

```cpp
int maxSubArrayWithIndices(vector<int>& arr, int &start, int &end) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    start = 0, end = 0;
    int temp_start = 0;
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_ending_here + arr[i]) {
            max_ending_here = arr[i];
            temp_start = i;
        } else {
            max_ending_here += arr[i];
        }
        
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            start = temp_start;
            end = i;
        }
    }
    
    return max_so_far;
}
```

---

## 🎯 PROBLEM 3: MAXIMUM CIRCULAR SUBARRAY SUM

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:** Find max subarray sum where array is circular (can wrap around).

**Input:** `arr = [5, -3, 5]`  
**Output:** `10` (circular subarray `[5, 5]`)

---

### **2️⃣ IDENTIFICATION**

- ✅ "Maximum sum" → Kadane's
- ✅ "Circular array" → Special case
- ✅ "Can wrap around" → Total - minimum

---

### **3️⃣ ABSTRACT/APPROACH**

Two cases:
1. Max subarray doesn't wrap → Regular Kadane's
2. Max subarray wraps → Total sum - Min subarray

Answer = max(case1, case2)

---

### **4️⃣ DRY RUN**

```
arr = [5, -3, 5]

Max subarray (normal): 7 (entire array)
Min subarray: -3
Total sum: 7
Circular max: 7 - (-3) = 10 ✅

Answer: max(7, 10) = 10
```

---

### **5️⃣ CODE**

```cpp
int maxSubarraySumCircular(vector<int>& arr) {
    int total = 0, max_sum = arr[0], min_sum = arr[0];
    int cur_max = 0, cur_min = 0;
    
    for (int num : arr) {
        cur_max = max(num, cur_max + num);
        max_sum = max(max_sum, cur_max);
        
        cur_min = min(num, cur_min + num);
        min_sum = min(min_sum, cur_min);
        
        total += num;
    }
    
    return (max_sum < 0) ? max_sum : max(max_sum, total - min_sum);
}
```

---

## 🎯 PROBLEM 4: MAXIMUM PRODUCT SUBARRAY

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:** Find contiguous subarray with largest product.

**Input:** `arr = [2, 3, -2, 4]`  
**Output:** `6` (subarray `[2, 3]`)

---

### **2️⃣ IDENTIFICATION**

- ✅ "Maximum product" (not sum)
- ✅ "Contiguous subarray"
- ✅ Negative × Negative = Positive!

---

### **3️⃣ ABSTRACT/APPROACH**

Track both **max_product** and **min_product**  
When seeing negative, swap them (sign flip!)

---

### **4️⃣ DRY RUN**

```
arr = [2, 3, -2, 4]

i=0: max=2, min=2
i=1: max=6, min=3, result=6 ✅
i=2: Swap! max=-2, min=-12
i=3: max=4, min=-48, result=6

Answer: 6
```

---

### **5️⃣ CODE**

```cpp
int maxProduct(vector<int>& arr) {
    int max_prod = arr[0], min_prod = arr[0], result = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < 0) swap(max_prod, min_prod);
        
        max_prod = max(arr[i], max_prod * arr[i]);
        min_prod = min(arr[i], min_prod * arr[i]);
        
        result = max(result, max_prod);
    }
    
    return result;
}
```

---

## 🎯 PROBLEM 5: MAX SUBARRAY AFTER ONE DELETION

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:** Find max sum where you can delete at most one element.

**Input:** `arr = [1, -2, 0, 3]`  
**Output:** `4` (delete -2, get `[1, 0, 3]`)

---

### **2️⃣ IDENTIFICATION**

- ✅ "Maximum sum" + "delete one" → DP variant
- ✅ Two states: with/without deletion

---

### **3️⃣ ABSTRACT/APPROACH**

Two states:
- `without_del[i]`: Max ending at i, no deletion
- `with_del[i]`: Max ending at i, one deletion used

---

### **4️⃣ DRY RUN**

```
arr = [1, -2, 0, 3]

i=0: without=1, with=0
i=1: without=-1, with=1 (delete -2)
i=2: without=0, with=1
i=3: without=3, with=4 ✅ (1 + 3)

Answer: 4
```

---

### **5️⃣ CODE**

```cpp
int maxSubarrayAfterDeletion(vector<int>& arr) {
    int without_del = arr[0], with_del = 0, result = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        int new_with = max(without_del, with_del + arr[i]);
        int new_without = max(arr[i], without_del + arr[i]);
        
        without_del = new_without;
        with_del = new_with;
        result = max({result, without_del, with_del});
    }
    
    return result;
}
```

---

## 📋 QUICK REFERENCE SHEET

### **🔥 Pattern Recognition:**

```
✅ "Maximum sum" + "Contiguous" → KADANE'S
✅ "Circular array" → Total - Min subarray
✅ "Maximum product" → Track max AND min
✅ "Delete one element" → DP with two states
```

---

### **📝 Generic Template:**

```cpp
int kadanes(vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}
```

**Mantra:** *"Extend or Start Fresh - whichever is LARGER!"*

---

### **⏱️ Complexity:**

| Problem | Time | Space |
|---------|------|-------|
| Basic Kadane's | O(n) | O(1) |
| With Indices | O(n) | O(1) |
| Circular | O(n) | O(1) |
| Product | O(n) | O(1) |
| After Deletion | O(n) | O(1) |

---

### **🎯 Top 5 Problems:**

1. **Maximum Subarray** - 5 min ⭐⭐⭐⭐⭐
2. **Circular Subarray** - 8 min ⭐⭐⭐⭐
3. **Product Subarray** - 10 min ⭐⭐⭐⭐
4. **With Indices** - 6 min ⭐⭐⭐⭐⭐
5. **After Deletion** - 12 min ⭐⭐⭐⭐

---

### **💡 Key Insights:**

1. **Basic Kadane's:** Extend or start fresh
2. **Circular:** Max = max(normal, total - min)
3. **Product:** Track both max and min (negative flip!)
4. **Deletion:** Two states (with/without)
5. **Always:** Think DP - current depends on previous!

---

**All the best! 🚀**
