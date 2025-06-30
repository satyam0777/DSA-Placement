
# Kadane's Algorithm: Maximum Subarray Sum

---

## 1. Concept

**Kadane's Algorithm** is an efficient way to find the maximum sum of a contiguous subarray in a given array (can contain negative numbers).  
It works in O(n) time and O(1) space.

---

## 2. Identification of Problem

**When to use Kadane's Algorithm?**
- The problem asks for the maximum sum of a contiguous subarray.
- The array may contain negative numbers.
- Example keywords: "maximum subarray sum", "largest sum of contiguous elements", "subarray with maximum sum".

**Typical Problem Statement:**  
Given an array of integers, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

---

## 3. Approaches

### a. Brute Force (Not Efficient)

- Try all possible subarrays and calculate their sums.
- Time Complexity: O(n^2) or O(n^3).

### b. Kadane's Algorithm (Efficient)

- Maintain two variables:
  - `max_so_far`: The maximum sum found so far.
  - `max_ending_here`: The maximum sum of subarray ending at current index.
- For each element, decide:
  - Either extend the previous subarray (`max_ending_here + arr[i]`)
  - Or start a new subarray from current element (`arr[i]`)
- Update `max_so_far` if `max_ending_here` is greater.

---

## 4. Code

```cpp
int maxSubArray(vector<int>& nums) {
    int max_so_far = nums[0];
    int max_ending_here = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        max_ending_here = max(nums[i], max_ending_here + nums[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
```

---

## 5. Example

**Input:**  
`arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

**Step-by-step:**  
- Start with -2.
- Next, max(-2+1, 1) = 1
- Next, max(1-3, -3) = -2
- Next, max(-2+4, 4) = 4
- Continue...

**Output:**  
`6` (subarray `[4, -1, 2, 1]`)

---

## 6. Variations

- **Print the subarray:** Track start and end indices when updating `max_so_far`.
- **All negative numbers:** Kadane's works, returns the largest (least negative) number.

---

## 7. When to Use

- Any problem asking for "maximum sum of contiguous subarray".
- Can be adapted for 2D arrays (Maximum Sum Rectangle in 2D matrix).

---

**Summary:**  
Kadane's Algorithm is the go-to approach for maximum subarray sum problems due to its linear time complexity and