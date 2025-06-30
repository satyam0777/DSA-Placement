
# Two-Pointer Technique

---

## 1. Concept

The **two-pointer technique** uses two indices (pointers) to traverse a data structure (usually an array or string) in a coordinated way.  
It is often used to reduce time complexity from O(n²) to O(n) for problems involving pairs or subarrays.

---

## 2. Identification of Problem

**When to use Two-Pointer Technique?**
- The problem involves searching for pairs or subarrays with certain properties (sum, difference, etc.).
- The array is sorted or can be sorted.
- You need to find or count all pairs/subarrays that satisfy a condition.
- Example keywords: "pair with sum", "subarray with sum", "remove duplicates", "reverse array", "move zeros", "window", "longest substring".

**Typical Problem Statements:**
- Find if there exists a pair with a given sum in a sorted array.
- Count the number of subarrays with a given sum or property.
- Remove duplicates from a sorted array in-place.
- Find the longest substring without repeating characters.

---

## 3. Approaches

### a. Opposite Ends (Classic Two-Pointer)

- Place one pointer at the start (`left`), one at the end (`right`).
- Move pointers towards each other based on the condition.

**Example:**  
Find if a sorted array has a pair with sum equal to target.

### b. Sliding Window (Both Pointers Move Forward)

- Both pointers start at the beginning.
- The window between pointers represents a subarray or substring.
- Expand or shrink the window to maintain a property (sum, unique elements, etc.).

**Example:**  
Find the length of the longest subarray with sum ≤ k.

---

## 4. Code Examples

### Example 1: Pair with Given Sum in Sorted Array

```cpp
bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        int sum = arr[left] + arr[right];
        if(sum == target) return true;
        else if(sum < target) left++;
        else right--;
    }
    return false;
}
```

---

### Example 2: Remove Duplicates from Sorted Array (In-place)

```cpp
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int j = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1; // New length
}
```

---

### Example 3: Longest Substring Without Repeating Characters (Sliding Window)

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

### Example 4: Find All Subarrays with Sum Equal to K (Positive Integers)

```cpp
int countSubarrays(vector<int>& arr, int k) {
    int left = 0, sum = 0, count = 0;
    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while(sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }
        if(sum == k) count++;
    }
    return count;
}
```

---

## 5. When to Use

- Problems involving pairs or subarrays in sorted arrays.
- Problems where you need to maintain a window with certain properties.
- Problems asking for the longest/shortest subarray/substring with a property.

---

**Summary:**  
The two-pointer technique is a powerful tool for optimizing problems involving pairs, subarrays, or substrings. Recognize patterns where two indices can efficiently scan the data structure to reduce time complexity.

---