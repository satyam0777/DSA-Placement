
# Advanced Prefix Sum Problems and Concepts

---

## 1. Range Sum Query (Multiple Queries)

**Problem:**  
Given an array and Q queries of the form [l, r], return the sum of elements from l to r for each query.

**Concept:**  
- Precompute prefix sum array.
- Each query is answered in O(1).

**Code:**
```cpp
vector<int> prefix(n);
prefix[0] = arr[0];
for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

int sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
```

---

## 2. Subarray Sum Equals K

**Problem:**  
Count the number of subarrays whose sum is exactly k.

**Concept:**  
- Use prefix sum and a hashmap to store frequencies of prefix sums.

**Code:**
```cpp
unordered_map<int, int> mp;
mp[0] = 1;
int sum = 0, count = 0;
for(int x : arr) {
    sum += x;
    if(mp.count(sum - k)) count += mp[sum - k];
    mp[sum]++;
}
```

---

## 3. Equilibrium Index

**Problem:**  
Find an index where the sum of elements to the left equals the sum to the right.

**Concept:**  
- Use prefix sum to get left sum, total sum - prefix sum for right sum.

**Code:**
```cpp
int total = accumulate(arr.begin(), arr.end(), 0);
int left = 0;
for(int i = 0; i < n; i++) {
    total -= arr[i];
    if(left == total) return i;
    left += arr[i];
}
return -1;
```

---

## 4. Maximum Subarray Sum (Kadane’s Algorithm)

**Problem:**  
Find the maximum sum of any contiguous subarray.

**Concept:**  
- Not classic prefix sum, but related to cumulative sums.

**Code:**
```cpp
int max_sum = arr[0], curr = arr[0];
for(int i = 1; i < n; i++) {
    curr = max(arr[i], curr + arr[i]);
    max_sum = max(max_sum, curr);
}
```

---

## 5. Number of Subarrays with Sum Divisible by K

**Problem:**  
Count subarrays whose sum is divisible by k.

**Concept:**  
- Use prefix sum and hashmap of mod values.

**Code:**
```cpp
unordered_map<int, int> mp;
mp[0] = 1;
int sum = 0, count = 0;
for(int x : arr) {
    sum += x;
    int mod = ((sum % k) + k) % k;
    count += mp[mod];
    mp[mod]++;
}
```

---

## 6. Binary Array: Count Subarrays with Equal Number of 0s and 1s

**Problem:**  
Given a binary array, count subarrays with equal number of 0s and 1s.

**Concept:**  
- Replace 0 with -1, then use prefix sum and hashmap.

**Code:**
```cpp
unordered_map<int, int> mp;
mp[0] = 1;
int sum = 0, count = 0;
for(int x : arr) {
    sum += (x == 0 ? -1 : 1);
    count += mp[sum];
    mp[sum]++;
}
```

---

## 7. Prefix Sum in 2D Arrays (Matrix)

**Problem:**  
Given a matrix, quickly find the sum of elements in any submatrix.

**Concept:**  
- Precompute 2D prefix sum matrix.

**Code:**
```cpp
vector<vector<int>> prefix(n, vector<int>(m));
for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        prefix[i][j] = arr[i][j] + (i > 0 ? prefix[i-1][j] : 0)
                                    + (j > 0 ? prefix[i][j-1] : 0)
                                    - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0);

// Sum of submatrix (x1, y1) to (x2, y2):
int res = prefix[x2][y2]
        - (x1 > 0 ? prefix[x1-1][y2] : 0)
        - (y1 > 0 ? prefix[x2][y1-1] : 0)
        + (x1 > 0 && y1 > 0 ? prefix[x1-1][y1-1] : 0);
```

---

## 8. When to Use Prefix Sum?

- Multiple range sum queries.
- Counting subarrays with certain properties (sum, mod, etc.).
- Problems involving cumulative frequency/count.
- Efficient submatrix sum queries in 2D arrays.

---

**Tip:**  
If you see repeated sum queries or need to count subarrays with a given sum, prefix sum (and often a hashmap) is likely the best approach!

---
---

## 9. Range Sum Queries: Classic Problems

### Problem 1: Static Range Sum Query

**Statement:**  
Given an array of size `n` and `q` queries, each query asks for the sum of elements from index `l` to `r` (0-based).

**Approach:**  
- Precompute prefix sum array.
- Answer each query in O(1).

**Code:**
```cpp
vector<int> prefix(n);
prefix[0] = arr[0];
for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

for(auto [l, r] : queries) {
    int sum = prefix[r] - (l > 0 ? prefix[l-1] : 0);
    cout << sum << endl;
}
```

---

### Problem 2: Range Update and Range Query (Difference Array)

**Statement:**  
Given an array, perform `q` operations. Each operation adds a value `val` to all elements in range `[l, r]`. After all operations, print the final array.

**Approach:**  
- Use a difference array for efficient range updates.

**Code:**
```cpp
vector<int> diff(n+1, 0);
for(auto [l, r, val] : operations) {
    diff[l] += val;
    if(r+1 < n) diff[r+1] -= val;
}
vector<int> arr(n);
arr[0] = diff[0];
for(int i = 1; i < n; i++) arr[i] = arr[i-1] + diff[i];
```

---

### Problem 3: Range Minimum/Maximum Query (Prefix/ Suffix Min/Max)

**Statement:**  
Given an array, answer queries for the minimum (or maximum) in a range `[l, r]`.

**Approach:**  
- Prefix/suffix min/max arrays can answer some special cases (like min from start to i, or i to end).
- For arbitrary ranges, use Segment Tree (advanced).

**Code for Prefix Min:**
```cpp
vector<int> prefixMin(n);
prefixMin[0] = arr[0];
for(int i = 1; i < n; i++) prefixMin[i] = min(prefixMin[i-1], arr[i]);
```

---

### Problem 4: Range Sum Query in 2D Matrix

**Statement:**  
Given a matrix, answer queries for the sum of elements in a submatrix defined by top-left `(x1, y1)` and bottom-right `(x2, y2)`.

**Approach:**  
- Precompute 2D prefix sum matrix.

**Code:**
```cpp
vector<vector<int>> prefix(n, vector<int>(m));
for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        prefix[i][j] = arr[i][j] + (i > 0 ? prefix[i-1][j] : 0)
                                    + (j > 0 ? prefix[i][j-1] : 0)
                                    - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0);

// Query sum for (x1, y1) to (x2, y2):
int res = prefix[x2][y2]
        - (x1 > 0 ? prefix[x1-1][y2] : 0)
        - (y1 > 0 ? prefix[x2][y1-1] : 0)
        + (x1 > 0 && y1 > 0 ? prefix[x1-1][y1-1] : 0);
```

---

### Problem 5: Range XOR Query

**Statement:**  
Given an array, answer queries for the XOR of elements in range `[l, r]`.

**Approach:**  
- Precompute prefix XOR array.

**Code:**
```cpp
vector<int> prefixXor(n);
prefixXor[0] = arr[0];
for(int i = 1; i < n; i++) prefixXor[i] = prefixXor[i-1] ^ arr[i];

int xorSum = prefixXor[r] ^ (l > 0 ? prefixXor[l-1] : 0);
```

---

**Summary:**  
Prefix sums and their variants (difference array, prefix min/max, prefix XOR) are powerful for answering a wide variety of range queries in O(1) after O(n) preprocessing.

---