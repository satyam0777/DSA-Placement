
# Sliding Window: Fixed Size vs Variable Size

---

## 1. Fixed Size Sliding Window

### Concept

- The window size (k) is fixed.
- You process every subarray/substring of length k.
- Works for any type of numbers (positive, negative, zero).

### Identification

- Problem says: "subarray of size k", "substring of length k", "window of size k", "maximum/minimum/sum/average of k consecutive elements".
- Example: "Find the maximum sum of any subarray of size k."

### Implementation

**Step-by-Step:**
1. Calculate the sum (or other property) of the first k elements.
2. Slide the window by adding the next element and removing the first element of the previous window.
3. Update your answer as you go.

**Code:**
```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size(), sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < k; i++) sum += arr[i];
    maxSum = sum;
    for(int i = k; i < n; i++) {
        sum += arr[i] - arr[i-k];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
```

---

## 2. Variable Size Sliding Window

### Concept

- The window size is not fixed; it expands and shrinks based on a condition (like sum, unique elements, etc.).
- **Usually works best when all numbers are positive** (because sum only increases as you add elements, so you can safely shrink from the left).
- If negative numbers are present, the window may not work as expected (sum can decrease even as you expand).

### Identification

- Problem says: "smallest/largest subarray/substring with sum at least/exactly k", "longest substring with at most k distinct characters", "minimum window", etc.
- Example: "Find the minimal length of a contiguous subarray with sum at least S."

### Implementation

**Step-by-Step:**
1. Use two pointers (`left`, `right`) to define the window.
2. Expand the window by moving `right` and adding elements.
3. When the window meets the condition, try to shrink from `left` to optimize (minimize/maximize length, etc.).
4. Update your answer when the window is valid.

**Code (for positive numbers):**
```cpp
int minSubArrayLen(int s, vector<int>& nums) {
    int left = 0, sum = 0, minLen = INT_MAX;
    for(int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while(sum >= s) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}
```

---

## 3. How to Identify Which Type to Use

- **Fixed Size:**  
  - Window size is given or implied.
  - All subarrays/substrings of a certain length.
  - Works for any numbers.

- **Variable Size:**  
  - Condition to be met (sum, unique elements, etc.).
  - Usually positive numbers (for sum-based problems).
  - Window expands and shrinks to find optimal answer.

---

## 4. Key Points

- For **sum-based variable window**, positive numbers are required for the classic sliding window to work.
- If negative numbers are present and you need variable window, consider prefix sums, hash maps, or other techniques.

---

**Summary:**  
- **Fixed size window:** Use for all types of numbers, when window size is given.
- **Variable size window:** Use when you need to find the smallest/largest window meeting a condition, and numbers are positive.

---