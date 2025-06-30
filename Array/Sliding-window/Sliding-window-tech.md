
# Sliding Window Technique

---

## 1. Concept

The **sliding window technique** is used to efficiently solve problems involving subarrays or substrings that are contiguous and of variable or fixed length.  
It helps reduce time complexity from O(n²) (brute force) to O(n) by maintaining a "window" that slides over the data structure.

---

## 2. Identification of Problem

**When to use Sliding Window?**
- The problem asks for the maximum/minimum/sum/average/length of a subarray or substring.
- The subarray/substring must be contiguous.
- The window size may be fixed (e.g., "subarray of size k") or variable (e.g., "longest substring with at most k distinct characters").
- Example keywords: "maximum sum of k elements", "longest substring", "at most k", "exactly k", "minimum window".

**Typical Problem Statements:**
- Find the maximum sum of any subarray of size k.
- Find the length of the longest substring with at most k distinct characters.
- Find the smallest subarray with sum at least S.

---

## 3. Approaches

### a. Fixed Size Sliding Window

- The window size is fixed (e.g., subarray of size k).
- Move the window by adding the next element and removing the first element of the previous window.

**Example:**  
Find the maximum sum of any subarray of size k.

### b. Variable Size Sliding Window

- The window size changes based on a condition (e.g., sum, unique characters).
- Expand the window by moving the right pointer, shrink by moving the left pointer to maintain the condition.

**Example:**  
Find the length of the longest substring with at most k distinct characters.

---

## 4. Code Examples

### Example 1: Maximum Sum Subarray of Size K (Fixed Window)

```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int windowSum = 0, maxSum = INT_MIN;
    for(int i = 0; i < k; i++) windowSum += arr[i];
    maxSum = windowSum;
    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
```

---

### Example 2: Longest Substring Without Repeating Characters (Variable Window)

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int left = 0, maxLen = 0;
    for(int right = 0; right < s.size(); right++) {
        while(seen.count(s[right])) {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

---

### Example 3: Smallest Subarray with Sum at Least S (Variable Window)

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

## 5. When to Use

- When you need to process all subarrays/substrings of a given or variable length efficiently.
- When the problem involves contiguous elements and can be solved by expanding and shrinking a window.

---

**Summary:**  
The sliding window technique is a must-know for optimizing problems involving contiguous subarrays or substrings, especially when brute force is too slow.

---