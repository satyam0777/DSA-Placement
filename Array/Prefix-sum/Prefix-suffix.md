
# Prefix Sum and Suffix Sum in DSA

---

## 1. What is Prefix Sum?

A **prefix sum** array is an array where each element at index `i` is the sum of all elements from the start up to index `i` in the original array.

**Formula:**  
`prefix[i] = arr[0] + arr[1] + ... + arr[i]`

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