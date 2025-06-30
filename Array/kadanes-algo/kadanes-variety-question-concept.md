
# Variations and Advanced Questions on Kadane's Algorithm

---

## 1. Maximum Subarray Sum with Indices

**Concept:**  
Find not just the sum, but also the starting and ending indices of the maximum sum subarray.

**Approach:**  
Track start, end, and a temporary start index while running Kadane's.

**Code:**
```cpp
int maxSubArray(vector<int>& nums, int &start, int &end) {
    int max_so_far = nums[0], max_ending_here = nums[0];
    start = end = 0;
    int s = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > max_ending_here + nums[i]) {
            max_ending_here = nums[i];
            s = i;
        } else {
            max_ending_here += nums[i];
        }
        if(max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
    }
    return max_so_far;
}
```

---

## 2. Maximum Sum Circular Subarray

**Concept:**  
The subarray can wrap around the end of the array.

**Approach:**  
- Find max subarray sum using Kadane's (non-circular).
- Find min subarray sum using Kadane's (invert sign).
- The answer is `max(normal_max, total_sum - min_subarray_sum)` (if not all negative).

**Code:**
```cpp
int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, max_sum = nums[0], cur_max = 0, min_sum = nums[0], cur_min = 0;
    for(int x : nums) {
        cur_max = max(x, cur_max + x);
        max_sum = max(max_sum, cur_max);
        cur_min = min(x, cur_min + x);
        min_sum = min(min_sum, cur_min);
        total += x;
    }
    if(max_sum < 0) return max_sum; // all negative
    return max(max_sum, total - min_sum);
}
```

---

## 3. Maximum Product Subarray

**Concept:**  
Find the contiguous subarray with the largest product.

**Approach:**  
Track both max and min products at each step (because negative * negative = positive).

**Code:**
```cpp
int maxProduct(vector<int>& nums) {
    int max_prod = nums[0], min_prod = nums[0], ans = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < 0) swap(max_prod, min_prod);
        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);
        ans = max(ans, max_prod);
    }
    return ans;
}
```

---

## 4. Maximum Sum Submatrix (2D Kadane)

**Concept:**  
Find the maximum sum rectangle in a 2D matrix.

**Approach:**  
- Fix left and right columns, compress rows into 1D, and apply Kadane's.

---

## 5. Longest Subarray with Sum at Most K

**Concept:**  
Find the longest subarray whose sum is less than or equal to K.

**Approach:**  
Use prefix sums and a sliding window or map.

---

## 6. Maximum Sum Subarray of Size K

**Concept:**  
Find the maximum sum of any subarray of size exactly K.

**Approach:**  
Use sliding window (not Kadane's, but related).

---

## 7. Maximum Alternating Subarray Sum

**Concept:**  
Find the maximum sum of a subarray where you alternate adding and subtracting elements.

---

## 8. Maximum Subarray Sum After One Deletion

**Concept:**  
Find the maximum sum subarray where you can delete at most one element.

**Approach:**  
Use two DP arrays: one for max sum ending at i, one for max sum starting at i.

---

**Summary:**  
Kadane's Algorithm is the base for many advanced subarray problems. Always check if the problem can be reduced to a variation of Kadane's!

---