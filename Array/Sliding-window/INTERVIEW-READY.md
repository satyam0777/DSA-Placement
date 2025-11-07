## SLIDING WINDOW - INTERVIEW READY PACKAGE


---


##  TABLE OF CONTENTS

1. [One-Line Recognition](#recognition)
2. [Two Types of Windows](#types)
3. [Top 8 Problems](#problems)
4. [Interview Scripts](#communication)
5. [Company Questions](#companies)

---

<a name="recognition"></a>
##  ONE-LINE RECOGNITION

### **When to Use Sliding Window?**

**If you see THESE keywords → Sliding Window:**
- "**Subarray** of size k"
- "**Maximum/Minimum** sum of k elements"
- "**Longest** substring with..."
- "**Smallest** subarray with sum ≥ S"
- "**At most** k distinct characters"
- "**Contiguous** elements"

**Key Words:** CONTIGUOUS + SIZE/CONDITION

---

<a name="types"></a>
##  TWO TYPES OF SLIDING WINDOW

### **Type 1: FIXED SIZE Window**

**When:** "Subarray/substring of **exact size k**"

**Pattern:**
```cpp
int windowSum = 0;

// Build first window
for(int i = 0; i < k; i++) {
    windowSum += arr[i];
}
int result = windowSum;

// Slide window
for(int i = k; i < n; i++) {
    windowSum += arr[i] - arr[i - k];  // Add new, remove old
    result = max(result, windowSum);
}

return result;
```

---

### **Type 2: VARIABLE SIZE Window**

**When:** "Longest/smallest subarray with **condition**"

**Pattern:**
```cpp
int left = 0, maxLen = 0;

for(int right = 0; right < n; right++) {
    // Add arr[right] to window
    
    // Shrink while condition violated
    while(condition_violated) {
        // Remove arr[left]
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
}

return maxLen;
```

---

<a name="problems"></a>
##  TOP 8 SLIDING WINDOW PROBLEMS

### **Problem 1: Maximum Sum Subarray of Size K** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find maximum sum of any subarray of size k."

**Template:**
```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int windowSum = 0;
    
    // First window
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    
    // Slide window
    for(int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

**What to Say:**
> "Sir, fixed size window of k. Build first window, then slide by adding next element and removing first element of previous window. Time O(n), Space O(1)."

**Dry Run:**
```
Array: [2, 1, 5, 1, 3, 2], k = 3

First window [2,1,5]: sum = 8, max = 8
Slide to [1,5,1]: sum = 8-2+1 = 7, max = 8
Slide to [5,1,3]: sum = 7-1+3 = 9, max = 9
Slide to [1,3,2]: sum = 9-5+2 = 6, max = 9

Answer: 9
```

---

### **Problem 2: Longest Substring Without Repeating Characters** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find length of longest substring with no repeating characters."

**Template:**
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.size(); right++) {
        // Shrink while duplicate exists
        while(window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        
        window.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**What to Say:**
> "Sir, variable size window. Use set to track characters in current window. When duplicate found, shrink from left until duplicate removed. Track maximum length. Time O(n), Space O(min(n, 26))."

**Dry Run:**
```
String: "abcabcbb"

right=0: 'a', window={a}, len=1
right=1: 'b', window={a,b}, len=2
right=2: 'c', window={a,b,c}, len=3
right=3: 'a' duplicate! Remove from left:
         Remove 'a', left=1, window={b,c}
         Add 'a', window={b,c,a}, len=3
right=4: 'b' duplicate! Remove until gone:
         Remove 'b', left=2, window={c,a}
         Add 'b', window={c,a,b}, len=3
...

Answer: 3 (substring "abc")
```

---

### **Problem 3: Minimum Window Substring** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find smallest substring containing all characters of pattern."

**Template:**
```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> required, window;
    
    for(char c : t) required[c]++;
    
    int left = 0, formed = 0, minLen = INT_MAX;
    int ansLeft = 0;
    
    for(int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;
        
        if(required.count(c) && window[c] == required[c]) {
            formed++;
        }
        
        // Shrink while valid
        while(formed == required.size()) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                ansLeft = left;
            }
            
            char leftChar = s[left];
            window[leftChar]--;
            if(required.count(leftChar) && window[leftChar] < required[leftChar]) {
                formed--;
            }
            left++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(ansLeft, minLen);
}
```

**What to Say:**
> "Sir, variable window. Expand right to include characters. When all required characters present, try shrinking from left to minimize. Track minimum length window. Time O(m+n), Space O(m+n)."

---

### **Problem 4: Longest Subarray with Sum ≤ K (Positive Numbers)** ⭐⭐⭐⭐

**Template:**
```cpp
int longestSubarray(vector<int>& arr, int k) {
    int left = 0, sum = 0, maxLen = 0;
    
    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        
        // Shrink while sum > k
        while(sum > k) {
            sum -= arr[left];
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**What to Say:**
> "Sir, expand window by adding elements. When sum exceeds k, shrink from left. Track maximum valid window size. Time O(n), Space O(1)."

---

### **Problem 5: Max Consecutive Ones After Flipping K Zeros** ⭐⭐⭐⭐

**Template:**
```cpp
int longestOnes(vector<int>& arr, int k) {
    int left = 0, zeros = 0, maxLen = 0;
    
    for(int right = 0; right < arr.size(); right++) {
        if(arr[right] == 0) zeros++;
        
        // Shrink if too many zeros
        while(zeros > k) {
            if(arr[left] == 0) zeros--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**What to Say:**
> "Sir, window tracks subarray. Count zeros in window. If zeros exceed k, shrink from left. Maximum window size is answer. Time O(n), Space O(1)."

---

### **Problem 6: Fruits Into Baskets (At Most 2 Types)** ⭐⭐⭐⭐

**Template:**
```cpp
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int left = 0, maxFruits = 0;
    
    for(int right = 0; right < fruits.size(); right++) {
        basket[fruits[right]]++;
        
        // Shrink if more than 2 types
        while(basket.size() > 2) {
            basket[fruits[left]]--;
            if(basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }
        
        maxFruits = max(maxFruits, right - left + 1);
    }
    
    return maxFruits;
}
```

**What to Say:**
> "Sir, this is 'longest subarray with at most 2 distinct elements'. Use map to count fruit types in window. When more than 2 types, shrink from left. Time O(n), Space O(1) - max 3 types in map."

---

### **Problem 7: Substring with At Most K Distinct Characters** ⭐⭐⭐⭐

**Template:**
```cpp
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> window;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.size(); right++) {
        window[s[right]]++;
        
        // Shrink if too many distinct
        while(window.size() > k) {
            window[s[left]]--;
            if(window[s[left]] == 0) {
                window.erase(s[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

---

### **Problem 8: Minimum Size Subarray Sum ≥ Target** ⭐⭐⭐⭐⭐

**Template:**
```cpp
int minSubArrayLen(int target, vector<int>& arr) {
    int left = 0, sum = 0, minLen = INT_MAX;
    
    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        
        // Shrink while condition met
        while(sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
}
```

**What to Say:**
> "Sir, expand window until sum ≥ target. Then shrink to minimize while maintaining condition. Track minimum length. Time O(n), Space O(1)."

---

<a name="communication"></a>
##  INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Recognition**

> "Sir, I recognize sliding window pattern because:
> 1. Problem asks for contiguous subarray/substring
> 2. Looking for maximum/minimum/longest/smallest
> 3. This suggests sliding window!
> 
> Fixed size if k given, variable size for condition-based."

---

### **Script 2: Explaining Fixed Window**

> "Sir, for fixed size k:
> 1. Build first window of size k
> 2. Slide by adding next, removing first
> 3. Track optimal answer
> Very efficient - each element processed once!"

---

### **Script 3: Explaining Variable Window**

> "Sir, for variable size:
> 1. Expand right pointer to grow window
> 2. Shrink left pointer when condition violated
> 3. Track maximum/minimum window size
> Both pointers move forward only - O(n)!"

---

<a name="companies"></a>
##  COMPANY-WISE FREQUENCY

### **TCS** ⭐⭐⭐⭐
- Max sum subarray size k
- Longest substring without repeating
- **Frequency:** 30%

### **Wipro** ⭐⭐⭐⭐⭐
- All sliding window basics
- Minimum window substring
- **Frequency:** 35%

### **Infosys** ⭐⭐⭐
- Very basic sliding window
- Max sum size k
- **Frequency:** 20%

### **Cognizant** ⭐⭐⭐⭐
- Medium difficulty
- K distinct characters
- **Frequency:** 30%

### **Capgemini** ⭐⭐⭐
- Basic patterns
- Max sum problems
- **Frequency:** 25%

### **Accenture** ⭐⭐⭐
- Simple fixed windows
- Clear explanation needed
- **Frequency:** 20%

---

##  QUICK REVISION

### **Fixed Window Template:**
```cpp
// Build first window
for(int i = 0; i < k; i++) add(arr[i]);

// Slide window
for(int i = k; i < n; i++) {
    add(arr[i]);
    remove(arr[i-k]);
    update_result();
}
```

### **Variable Window Template:**
```cpp
int left = 0;
for(int right = 0; right < n; right++) {
    add(arr[right]);
    
    while(invalid) {
        remove(arr[left]);
        left++;
    }
    
    update_result(right - left + 1);
}
```

---

##  FINAL TIPS

**Recognition:**
- Contiguous + Optimization → Sliding Window
- Fixed k → Fixed window
- Longest/Smallest → Variable window

**Common Pattern:**
1. Expand to include new element
2. Shrink to maintain validity
3. Track optimal answer

---

**All the best** 
