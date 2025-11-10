# Array - Practice Problems with Complete Solutions

---

## 🎯 How to Use This File

1. **Read the problem**
2. **Try to solve it yourself first** (15-20 mins)
3. **Check the "Thinking Process"** section
4. **See the solution**
5. **Code it yourself without looking**
6. **Repeat 3 times for each problem**

---

## Problem 1: Two Sum ⭐⭐⭐⭐⭐

### **Question:**
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution.

**Input:** nums = [2, 7, 11, 15], target = 9  
**Output:** [0, 1]  
**Explanation:** nums[0] + nums[1] = 2 + 7 = 9

---

### **Thinking Process:**

1. **Understand:** "Find two indices whose values sum to target"
2. **Brute Force:** "Check all pairs O(n²) using nested loops"
3. **Optimize:** "Use hashmap to store complements O(n)"
4. **Pattern:** "This is a HASHING problem"

---

### **Approach:**
> "For each element, I'll check if its complement (target - element) exists in the hashmap.
> If found, return both indices. If not, add current element to hashmap.
> This way I only traverse once."

---

### **Solution:**

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // value -> index
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists
        if(seen.count(complement)) {
            return {seen[complement], i};
        }
        
        // Store current element
        seen[nums[i]] = i;
    }
    
    return {}; // No solution found
}
```

**Time:** O(n), **Space:** O(n)

**Interview Tip:** Mention that you're using hashmap to trade space for time!

---

## Problem 2: Maximum Subarray (Kadane's Algorithm) ⭐⭐⭐⭐⭐

### **Question:**
Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]  
**Output:** 6  
**Explanation:** [4,-1,2,1] has the largest sum = 6

---

### **Thinking Process:**

1. **Understand:** "Need maximum sum of contiguous elements"
2. **Brute Force:** "Check all subarrays O(n²)"
3. **Optimize:** "Use Kadane's Algorithm O(n)"
4. **Pattern:** "Classic KADANE'S ALGORITHM problem"

---

### **Dry Run:**
```
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

maxSoFar = -2, maxEndingHere = -2

i=1: maxEndingHere = max(1, -2+1) = 1, maxSoFar = 1
i=2: maxEndingHere = max(-3, 1-3) = -2, maxSoFar = 1
i=3: maxEndingHere = max(4, -2+4) = 4, maxSoFar = 4
i=4: maxEndingHere = max(-1, 4-1) = 3, maxSoFar = 4
i=5: maxEndingHere = max(2, 3+2) = 5, maxSoFar = 5
i=6: maxEndingHere = max(1, 5+1) = 6, maxSoFar = 6
i=7: maxEndingHere = max(-5, 6-5) = 1, maxSoFar = 6
i=8: maxEndingHere = max(4, 1+4) = 5, maxSoFar = 6

Answer: 6
```

---

### **Solution:**

```cpp
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        // Either extend current subarray or start new
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        
        // Update global maximum
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I use Kadane's Algorithm. For each position, I decide: extend previous subarray 
> or start fresh. I track the maximum sum throughout."

---

## Problem 3: Best Time to Buy and Sell Stock ⭐⭐⭐⭐⭐

### **Question:**
You are given an array `prices` where `prices[i]` is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit. If you cannot achieve any profit, return 0.

**Input:** prices = [7,1,5,3,6,4]  
**Output:** 5  
**Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5

---

### **Thinking Process:**

1. **Understand:** "Buy low, sell high. Find maximum profit"
2. **Key Insight:** "Track minimum price seen so far"
3. **Pattern:** "Single pass / Kadane's variation"

---

### **Solution:**

```cpp
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for(int price : prices) {
        // Update minimum price seen so far
        minPrice = min(minPrice, price);
        
        // Calculate profit if we sell today
        int profit = price - minPrice;
        
        // Update maximum profit
        maxProfit = max(maxProfit, profit);
    }
    
    return maxProfit;
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I track the minimum price seen so far. For each day, I calculate profit 
> if I sell today (price - minPrice). I keep track of maximum profit."

---

## Problem 4: Contains Duplicate ⭐⭐⭐⭐⭐

### **Question:**
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Input:** nums = [1,2,3,1]  
**Output:** true

---

### **Thinking Process:**

1. **Pattern:** "HASHING - check existence"
2. **Approach:** "Use set to track seen elements"

---

### **Solution:**

```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for(int num : nums) {
        if(seen.count(num)) {
            return true; // Duplicate found
        }
        seen.insert(num);
    }
    
    return false;
}
```

**Time:** O(n), **Space:** O(n)

**Alternative O(1) space but O(n log n) time:**
```cpp
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i-1]) return true;
    }
    return false;
}
```

---

## Problem 5: Remove Duplicates from Sorted Array ⭐⭐⭐⭐⭐

### **Question:**
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. Return the number of unique elements.

**Input:** nums = [1,1,2]  
**Output:** 2, nums = [1,2,_]

---

### **Thinking Process:**

1. **Pattern:** "TWO POINTER - same direction"
2. **Key:** "Slow pointer for unique, fast pointer for exploration"

---

### **Dry Run:**
```
nums = [0,0,1,1,1,2,2,3,3,4]

j=0 (slow), i=1 (fast)

i=1: nums[1]=0 == nums[0]=0, skip
i=2: nums[2]=1 != nums[0]=0, j++, nums[1]=1
i=3: nums[3]=1 == nums[1]=1, skip
i=4: nums[4]=1 == nums[1]=1, skip
i=5: nums[5]=2 != nums[1]=1, j++, nums[2]=2
i=6: nums[6]=2 == nums[2]=2, skip
i=7: nums[7]=3 != nums[2]=2, j++, nums[3]=3
i=8: nums[8]=3 == nums[3]=3, skip
i=9: nums[9]=4 != nums[3]=3, j++, nums[4]=4

Result: [0,1,2,3,4,...], length = 5
```

---

### **Solution:**

```cpp
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    
    int j = 0; // Slow pointer - position for unique elements
    
    for(int i = 1; i < nums.size(); i++) { // Fast pointer
        if(nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }
    
    return j + 1; // Length of unique elements
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I use two pointers. Slow pointer (j) tracks position for unique elements.
> Fast pointer (i) explores the array. When I find a new unique element,
> I place it at j+1 position."

---

## Problem 6: Move Zeroes ⭐⭐⭐⭐

### **Question:**
Given an integer array nums, move all 0's to the end while maintaining the relative order of the non-zero elements. Must be done in-place.

**Input:** nums = [0,1,0,3,12]  
**Output:** [1,3,12,0,0]

---

### **Thinking Process:**

1. **Pattern:** "TWO POINTER - same direction"
2. **Key:** "j tracks position for non-zero elements"

---

### **Solution:**

```cpp
void moveZeroes(vector<int>& nums) {
    int j = 0; // Position for next non-zero
    
    // Move all non-zero elements to front
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I use two pointers. j tracks position for non-zero elements.
> When I find a non-zero, I swap it with position j and increment j.
> This maintains relative order and moves zeros to end."

---

## Problem 7: Find Missing Number ⭐⭐⭐⭐⭐

### **Question:**
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

**Input:** nums = [3,0,1]  
**Output:** 2  
**Explanation:** n = 3, range is [0,1,2,3], missing number is 2

---

### **Thinking Process:**

1. **Pattern:** "MATH - Sum formula"
2. **Key:** "Expected sum - Actual sum = Missing number"

---

### **Solution 1: Using Sum**

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of 0 to n
    int actualSum = 0;
    
    for(int num : nums) {
        actualSum += num;
    }
    
    return expectedSum - actualSum;
}
```

**Time:** O(n), **Space:** O(1)

---

### **Solution 2: Using XOR (More elegant!)**

```cpp
int missingNumber(vector<int>& nums) {
    int xorAll = 0;
    
    // XOR all numbers from 0 to n
    for(int i = 0; i <= nums.size(); i++) {
        xorAll ^= i;
    }
    
    // XOR with all array elements
    for(int num : nums) {
        xorAll ^= num;
    }
    
    return xorAll; // Remaining is the missing number
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I can use sum formula: expected sum - actual sum = missing number.
> Or XOR approach: XOR of all numbers 0 to n, then XOR with array elements.
> Duplicate XORs cancel out, leaving only the missing number."

---

## Problem 8: Rotate Array ⭐⭐⭐⭐

### **Question:**
Given an array, rotate the array to the right by k steps.

**Input:** nums = [1,2,3,4,5,6,7], k = 3  
**Output:** [5,6,7,1,2,3,4]

---

### **Thinking Process:**

1. **Pattern:** "REVERSAL technique"
2. **Key:** "Reverse whole, then reverse parts"

---

### **Dry Run:**
```
nums = [1,2,3,4,5,6,7], k = 3

Step 1: Reverse entire array
[7,6,5,4,3,2,1]

Step 2: Reverse first k elements
[5,6,7,4,3,2,1]

Step 3: Reverse remaining elements
[5,6,7,1,2,3,4] ✓
```

---

### **Solution:**

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle k > n
    
    // Reverse entire array
    reverse(nums.begin(), nums.end());
    
    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);
    
    // Reverse remaining elements
    reverse(nums.begin() + k, nums.end());
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I use the reversal technique. First reverse entire array, 
> then reverse first k elements, then reverse rest.
> This achieves rotation in-place with O(1) extra space."

---

## Problem 9: Subarray Sum Equals K ⭐⭐⭐⭐⭐

### **Question:**
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

**Input:** nums = [1,1,1], k = 2  
**Output:** 2

---

### **Thinking Process:**

1. **Pattern:** "PREFIX SUM + HASHING"
2. **Key:** "If current sum is S and we've seen (S-k), there's a subarray with sum k"

---

### **Solution:**

```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // Empty subarray has sum 0
    
    int sum = 0, count = 0;
    
    for(int num : nums) {
        sum += num;
        
        // Check if (sum - k) exists
        if(prefixCount.count(sum - k)) {
            count += prefixCount[sum - k];
        }
        
        // Add current sum to map
        prefixCount[sum]++;
    }
    
    return count;
}
```

**Time:** O(n), **Space:** O(n)

**What to say:**
> "I use prefix sum with hashmap. At each position, if current sum is S
> and we've previously seen sum (S-k), it means there's a subarray between
> those positions with sum k. I count all such occurrences."

---

## Problem 10: Maximum Sum Subarray of Size K ⭐⭐⭐⭐⭐

### **Question:**
Given an array and integer k, find the maximum sum of any contiguous subarray of size k.

**Input:** arr = [2,1,5,1,3,2], k = 3  
**Output:** 9  
**Explanation:** Subarray [5,1,3] has maximum sum = 9

---

### **Thinking Process:**

1. **Pattern:** "SLIDING WINDOW - Fixed size"
2. **Key:** "Add next, remove first, track maximum"

---

### **Dry Run:**
```
arr = [2,1,5,1,3,2], k = 3

First window: [2,1,5], sum = 8
Slide: Remove 2, add 1 → [1,5,1], sum = 7
Slide: Remove 1, add 3 → [5,1,3], sum = 9 ← max
Slide: Remove 5, add 2 → [1,3,2], sum = 6

Answer: 9
```

---

### **Solution:**

```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if(n < k) return -1;
    
    // Calculate sum of first window
    int windowSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    
    // Slide the window
    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // Add new, remove old
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I use sliding window. First calculate sum of first k elements.
> Then slide window: add next element, remove first element of previous window.
> This avoids recalculating sum, giving O(n) instead of O(n*k)."

---

## Problem 11: Longest Substring Without Repeating Characters ⭐⭐⭐⭐

### **Question:**
Given a string s, find the length of the longest substring without repeating characters.

**Input:** s = "abcabcbb"  
**Output:** 3  
**Explanation:** "abc" is the longest without repeating

---

### **Thinking Process:**

1. **Pattern:** "SLIDING WINDOW - Variable size + HASHING"
2. **Key:** "Expand window, shrink when duplicate found"

---

### **Solution:**

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.size(); right++) {
        // Shrink window while duplicate exists
        while(window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        
        // Add current character
        window.insert(s[right]);
        
        // Update maximum length
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**Time:** O(n), **Space:** O(min(n, charset size))

**What to say:**
> "I use variable sliding window with a set. Right pointer expands window.
> When duplicate found, left pointer shrinks window until duplicate removed.
> I track maximum window size throughout."

---

## Problem 12: Sort Colors (Dutch National Flag) ⭐⭐⭐⭐

### **Question:**
Given an array nums with n objects colored red, white, or blue (represented by 0, 1, 2), sort them in-place.

**Input:** nums = [2,0,2,1,1,0]  
**Output:** [0,0,1,1,2,2]

---

### **Thinking Process:**

1. **Pattern:** "THREE POINTER"
2. **Key:** "0s to left, 2s to right, 1s in middle"

---

### **Solution:**

```cpp
void sortColors(vector<int>& nums) {
    int low = 0;      // Everything before low is 0
    int mid = 0;      // Current element being processed
    int high = nums.size() - 1; // Everything after high is 2
    
    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
            // Don't increment mid, need to check swapped element
        }
    }
}
```

**Time:** O(n), **Space:** O(1)

**What to say:**
> "I use three pointers - low, mid, high. 
> 0s go to left (low), 2s go to right (high), 1s stay in middle.
> Process each element once, achieving O(n) time with O(1) space."

---

## Problem 13: Leaders in Array ⭐⭐⭐⭐

### **Question:**
An element is a leader if it is greater than all the elements to its right side. The rightmost element is always a leader.

**Input:** arr = [16,17,4,3,5,2]  
**Output:** [17,5,2]

---

### **Thinking Process:**

1. **Pattern:** "TRAVERSE FROM RIGHT"
2. **Key:** "Track maximum from right, compare"

---

### **Solution:**

```cpp
vector<int> leaders(vector<int>& arr) {
    vector<int> result;
    int n = arr.size();
    
    int maxFromRight = arr[n-1];
    result.push_back(maxFromRight);
    
    // Traverse from right to left
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            result.push_back(maxFromRight);
        }
    }
    
    // Reverse to get left-to-right order
    reverse(result.begin(), result.end());
    return result;
}
```

**Time:** O(n), **Space:** O(k) where k is number of leaders

**What to say:**
> "I traverse from right to left, tracking maximum element seen so far.
> Any element greater than max from right is a leader.
> Then reverse result to get left-to-right order."

---

## Problem 14: Product of Array Except Self ⭐⭐⭐⭐

### **Question:**
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all elements except nums[i]. You must write an algorithm that runs in O(n) time and without using the division operation.

**Input:** nums = [1,2,3,4]  
**Output:** [24,12,8,6]

---

### **Thinking Process:**

1. **Pattern:** "PREFIX and SUFFIX PRODUCT"
2. **Key:** "Product at i = prefix[i-1] * suffix[i+1]"

---

### **Solution:**

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    // Calculate prefix products
    int prefix = 1;
    for(int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    
    // Calculate suffix products and combine
    int suffix = 1;
    for(int i = n-1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
    
    return result;
}
```

**Time:** O(n), **Space:** O(1) excluding output array

**What to say:**
> "I use prefix and suffix products. First pass calculates prefix product
> for each position. Second pass multiplies with suffix product.
> Result at i = prefix[i-1] * suffix[i+1], which is product of all except i."

---

## Problem 15: Merge Sorted Arrays ⭐⭐⭐⭐

### **Question:**
Given two sorted arrays, merge them into one sorted array.

**Input:** nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3  
**Output:** [1,2,2,3,5,6]

---

### **Solution:**

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;      // Last element of nums1
    int j = n - 1;      // Last element of nums2
    int k = m + n - 1;  // Last position in merged array
    
    // Merge from right to left
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    
    // Copy remaining from nums2
    while(j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
```

**Time:** O(m+n), **Space:** O(1)

**What to say:**
> "I merge from right to left using three pointers.
> Compare elements from end of both arrays, place larger at end of nums1.
> This avoids overwriting elements and uses O(1) extra space."

---

Good luck! 💪
