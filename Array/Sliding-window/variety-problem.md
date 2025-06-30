
# Sliding Window Technique: Problem Varieties, Approach, and Step-by-Step Thinking

---

## 1. Maximum Sum Subarray of Size K (Fixed Window)

**Problem:**  
Find the maximum sum of any contiguous subarray of size k.

**How to Think:**
- Fixed window size: sum the first k elements.
- Slide the window by removing the first element and adding the next element.
- Track the maximum sum.

**Step-by-Step:**
1. Calculate sum of first k elements.
2. For each next element, add it and subtract the element that just left the window.
3. Update max if needed.

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

## 2. Longest Substring Without Repeating Characters (Variable Window)

**Problem:**  
Find the length of the longest substring with all unique characters.

**How to Think:**
- Use a set or map to track unique characters.
- Expand window by moving right pointer.
- If duplicate found, shrink window from left until unique.

**Step-by-Step:**
1. Initialize left and right pointers at 0.
2. Move right, add characters to set.
3. If duplicate, remove from left until unique.
4. Track max window length.

**Code:**
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

## 3. Smallest Subarray With Sum At Least S

**Problem:**  
Find the minimal length of a contiguous subarray with sum ≥ S.

**How to Think:**
- Expand window to increase sum.
- When sum ≥ S, try to shrink window from left to minimize length.

**Step-by-Step:**
1. Initialize left, sum, minLen.
2. Expand right, add to sum.
3. While sum ≥ S, update minLen and shrink from left.

**Code:**
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

## 4. Longest Substring With At Most K Distinct Characters

**Problem:**  
Find the length of the longest substring with at most K distinct characters.

**How to Think:**
- Use a map to count character frequencies.
- Expand right, add to map.
- If map size > K, shrink from left.

**Step-by-Step:**
1. Initialize left, right, map, maxLen.
2. Expand right, add/update map.
3. While map size > K, shrink from left and update map.
4. Track maxLen.

**Code:**
```cpp
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;
    for(int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        while(freq.size() > k) {
            freq[s[left]]--;
            if(freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

---

## 5. Maximum Number of Vowels in a Substring of Given Length

**Problem:**  
Given a string and integer k, return the maximum number of vowels in any substring of length k.

**How to Think:**
- Fixed window size.
- Count vowels in first window, then slide and update count.

**Step-by-Step:**
1. Count vowels in first k characters.
2. Slide window: add right char, remove left char if vowel.
3. Track max count.

**Code:**
```cpp
bool isVowel(char c) {
    return string("aeiou").find(c) != string::npos;
}
int maxVowels(string s, int k) {
    int count = 0, maxCount = 0;
    for(int i = 0; i < k; i++) if(isVowel(s[i])) count++;
    maxCount = count;
    for(int i = k; i < s.size(); i++) {
        if(isVowel(s[i])) count++;
        if(isVowel(s[i-k])) count--;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
```

---

## 6. Fruit Into Baskets (Longest Subarray with At Most 2 Distinct Elements)

**Problem:**  
Given an array, find the length of the longest subarray with at most 2 distinct numbers.

**How to Think:**
- Use a map to count fruit types.
- Expand right, add to map.
- If map size > 2, shrink from left.

**Step-by-Step:**
1. Initialize left, right, map, maxLen.
2. Expand right, add/update map.
3. While map size > 2, shrink from left and update map.
4. Track maxLen.

---

## 7. Binary Subarrays With Sum

**Problem:**  
Given a binary array and integer S, return the number of subarrays with sum S.

**How to Think:**
- Use prefix sum and hashmap (advanced sliding window).

---

**Summary:**  
For sliding window problems:
- Identify if window size is fixed or variable.
- Use two pointers to expand and shrink the window.
- Use a set/map for unique/distinct/character count constraints.
- Always update your answer when the window is valid.

---