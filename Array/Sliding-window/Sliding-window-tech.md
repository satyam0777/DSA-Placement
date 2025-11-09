
# 🪟 SLIDING WINDOW - ADITYA VERMA COMPLETE SERIES
## Following Exact YouTube Playlist Order

---

## 📚 ADITYA VERMA'S TEACHING METHOD

**Every Problem Follows 5 Steps:**
```
1. PROBLEM STATEMENT + INPUT/OUTPUT
2. IDENTIFICATION (How to know it's sliding window?)
3. ABSTRACT/APPROACH (Think before coding)
4. DRY RUN (Trace by hand first)
5. CODE (Write after understanding)
```

---


---

## 📚 QUICK REFERENCE GUIDE

### **Template Comparison**

| Aspect | Fixed Window | Variable Window |
|--------|--------------|-----------------|
| **Window Size** | Given (k) | Need to find |
| **Keywords** | "size k", "every window" | "longest", "minimum", "maximum" |
| **Template** | `if(j-i+1 == k)` | 3 conditions (< = >) |
| **Problems** | Max sum, First negative, Anagrams | Subarray sum, K unique, Min window |

---

### **Fixed Window Template (Copy-Paste Ready)**

```cpp
int i = 0, j = 0;
int n = arr.size();

while (j < n) {
    // CALCULATION (add arr[j])
    
    if (j - i + 1 < k) {
        j++;
    }
    else if (j - i + 1 == k) {
        // CALCULATE ANSWER
        
        // SLIDE WINDOW (remove arr[i])
        i++;
        j++;
    }
}
```

---

### **Variable Window Template (Copy-Paste Ready)**

```cpp
int i = 0, j = 0;
int ans = 0; // or INT_MAX for minimum

while (j < n) {
    // CALCULATION (add arr[j])
    
    if (condition < target) {
        j++;
    }
    else if (condition == target) {
        ans = max(ans, j - i + 1);
        j++;
    }
    else if (condition > target) {
        while (condition > target) {
            // Remove arr[i]
            i++;
        }
        j++;
    }
}
```

---

## ⚠️ COMMON MISTAKES

### **Mistake 1: Forgetting to Remove arr[i]**
```cpp
// WRONG ❌
windowSum += arr[j];
if (j - i + 1 == k) {
    maxSum = max(maxSum, windowSum);
    i++; j++; // Forgot to remove arr[i]!
}

// CORRECT ✅
windowSum += arr[j];
if (j - i + 1 == k) {
    maxSum = max(maxSum, windowSum);
    windowSum -= arr[i]; // Remove arr[i] before sliding
    i++; j++;
}
```

---

### **Mistake 2: Wrong j++ Placement**
```cpp
// WRONG ❌
if (j - i + 1 < k) {
    // Nothing here
}
j++; // This runs for both conditions!

// CORRECT ✅
if (j - i + 1 < k) {
    j++;
}
else if (j - i + 1 == k) {
    // ...
    i++; j++;
}
```

---

### **Mistake 3: Window Size Calculation**
```cpp
// WRONG ❌
windowSize = j - i; // Missing +1

// CORRECT ✅
windowSize = j - i + 1; // Always +1
```

---

### **Mistake 4: Map Deletion**
```cpp
// WRONG ❌
charMap[s[i]]--;
// Forgot to erase if count becomes 0

// CORRECT ✅
charMap[s[i]]--;
if (charMap[s[i]] == 0) {
    charMap.erase(s[i]);
}
```

---

## 🎯 PATTERN RECOGNITION GUIDE

### **How to Identify Sliding Window?**

**Ask 3 Questions:**
1. ✅ Is it **Array** or **String**?
2. ✅ Do we need **contiguous** elements (subarray/substring)?
3. ✅ Are there keywords: **window, k size, longest, shortest, maximum, minimum**?

**If all 3 YES → Sliding Window!**

---

### **Fixed vs Variable Decision Tree**

```
Is window size given?
    ├─ YES → Fixed Window
    │   └─ Use: if(j-i+1 == k)
    │
    └─ NO → Variable Window
        └─ Looking for: longest/shortest/max/min?
            ├─ YES → Variable Window
            └─ Use: 3 conditions (< = >)
```

---

### **Data Structure Choice**

| Problem Type | Data Structure |
|--------------|----------------|
| Basic sum/count | Variable only |
| Need max in window | Deque |
| Track frequency | unordered_map |
| Track negative numbers | queue |
| Just sum | Variable (int sum) |

---

## 🏆 INTERVIEW TIPS

### **1. Talk Through Template**
```
"I'll use sliding window with i,j pointers.
First, I'll check window size formula: j - i + 1
Then I'll expand until window is ready..."
```

---

### **2. Mention Time Complexity**
"Sliding window gives O(n) instead of O(n²) brute force"

---

### **3. Handle Edge Cases**
- Empty array: `if (n == 0) return 0;`
- k > n: `if (k > n) return -1;`
- No valid window: Track with flag or INT_MAX

---

### **4. Start with Template**
Always write template skeleton first:
```cpp
int i = 0, j = 0;
while (j < n) {
    // Then fill in
}
```

---

### **5. Dry Run Small Example**
Always trace with 3-4 elements:
```
arr = [1, 2, 3], k = 2
i=0,j=0: ...
i=0,j=1: ...
i=1,j=2: ...
```

---

## 📊 ADITYA VERMA'S COMPLETE SERIES SUMMARY

### **Videos 1-6: Fixed Window**
1. Introduction - What is sliding window
2. Identification - 3 signs to recognize
3. Maximum Sum Subarray (basic template)
4. First Negative in Window (queue)
5. Count Anagrams (frequency map)
6. Maximum of All Subarrays (deque)

### **Videos 7-13: Variable Window**
7-9. Largest Subarray Sum K (variable intro)
10. Longest K Unique Characters
11. Longest Without Repeating
12. Pick Toys (Fruit Baskets)
13. Minimum Window Substring

---

## ✅ FINAL CHECKLIST

**Before Interview:**
- [ ] Memorize both templates (fixed + variable)
- [ ] Practice window size formula: `j - i + 1`
- [ ] Know when to use map vs queue vs deque
- [ ] Can dry run on paper in 2-3 minutes
- [ ] Remember to remove arr[i] before sliding

**During Interview:**
- [ ] Ask: "Is window size given?"
- [ ] Write template skeleton first
- [ ] Talk through approach before coding
- [ ] Dry run with small example
- [ ] Mention O(n) complexity

---

## 🎓 STUDY STRATEGY

**Day 1-2:** Fixed Window
- Master template
- Practice Problems 3-6
- Focus on calculation + slide steps

**Day 3-4:** Variable Window
- Understand 3 conditions
- Practice Problems 7-13
- Focus on shrink logic

**Day 5:** Mixed Practice
- Do 2 fixed + 2 variable
- Time yourself (15 min each)
- No looking at notes

---

**🔥 You now have COMPLETE Aditya Verma series! Practice each problem until template becomes automatic. In interview, template writes itself! 🚀**

### **Video 1: Sliding Window Introduction**

**What is Sliding Window?**
- Technique to solve array/string problems efficiently
- Instead of O(n²) nested loops → O(n) single pass
- Maintain a "window" that slides over data

**Key Concept:**
```
Brute Force (O(n²)):
for i in range(n):
    for j in range(i, i+k):  # Check every subarray
        calculate()

Sliding Window (O(n)):
Calculate for first window
Then slide: Add new element, Remove old element
```

**Why It Works:**
- Reuses previous calculations
- No need to recalculate from scratch

---

### **Video 2: IDENTIFICATION - How to Recognize Sliding Window?**

**3 Clear Signs:**

**1. Array or String problem** ✅

**2. Subarray or Substring** ✅
   - Must be **CONTIGUOUS** (continuous elements)
   - NOT subsequence (can skip elements)

**3. Keywords in Problem:**
   - "Window of size K"
   - "Maximum/Minimum of size K"
   - "Longest substring with..."
   - "Smallest subarray with..."
   - "First/Last K elements"

**Problem Statement Patterns:**
```
✅ "Maximum sum of subarray of size K"
✅ "Longest substring with K unique characters"
✅ "First negative in every window of size K"
✅ "Smallest window containing all characters"

❌ "All subarrays" (not contiguous window)
❌ "Subsequence" (can skip elements)
```

---

### **TYPES OF SLIDING WINDOW:**

#### **Type 1: FIXED SIZE WINDOW**
- Window size (K) is given
- Example: "subarray of size K", "window of size K"

#### **Type 2: VARIABLE SIZE WINDOW**
- Window size is NOT given
- Need to find: longest, shortest, maximum, minimum
- Example: "longest substring with...", "smallest subarray with..."

---

## 🔧 FIXED SIZE WINDOW TEMPLATE (Aditya Verma)

```cpp
// UNIVERSAL TEMPLATE FOR FIXED WINDOW
int i = 0, j = 0;
int n = arr.size();

while (j < n) {
    // Step 1: CALCULATION (Process arr[j])
    
    // Step 2: CHECK WINDOW SIZE
    if (j - i + 1 < k) {
        j++; // Window not ready, just expand
    }
    else if (j - i + 1 == k) {
        // Window size reached!
        
        // Step 3: CALCULATE ANSWER
        
        // Step 4: SLIDE WINDOW
        // Remove arr[i] contribution
        i++;
        j++;
    }
}
```

**Key Formula:** `Window Size = j - i + 1`

---

## 📝 PROBLEM 3: Maximum Sum Subarray of Size K

### **1. Problem Statement**
Given an array and integer K, find maximum sum of any subarray of size K.

**Input:** `arr[] = {2, 5, 1, 8, 2, 9, 1}`, `k = 3`  
**Output:** `19`  
**Explanation:** Subarray `{8, 2, 9}` has sum 19 (maximum)

---

### **2. Identification**
✅ Array problem  
✅ Subarray (contiguous)  
✅ "of size K" → Fixed window  
✅ "Maximum sum" → Sliding window  

**Pattern:** Fixed Size Window

---

### **3. Abstract/Approach**

**Brute Force (O(n²)):**
```cpp
for i = 0 to n-k:
    sum = 0
    for j = i to i+k-1:
        sum += arr[j]
    maxSum = max(maxSum, sum)
```

**Sliding Window (O(n)):**
```
1. Calculate sum of first window (0 to k-1)
2. Slide: Add next element, Remove first element
3. Track maximum at each step
```

**Why Better?**
- Reuses previous sum
- No recalculation needed

---

### **4. Dry Run**

```
arr = [2, 5, 1, 8, 2, 9, 1], k = 3

i=0, j=0: arr[0]=2, windowSum=2, size=1 (<3) → j++
i=0, j=1: arr[1]=5, windowSum=7, size=2 (<3) → j++
i=0, j=2: arr[2]=1, windowSum=8, size=3 (==3) 
          → maxSum=8, remove arr[0]=2, windowSum=6, i++, j++
          
i=1, j=3: arr[3]=8, windowSum=14, size=3
          → maxSum=14, remove arr[1]=5, windowSum=9, i++, j++
          
i=2, j=4: arr[4]=2, windowSum=11, size=3
          → maxSum=14, remove arr[2]=1, windowSum=10, i++, j++
          
i=3, j=5: arr[5]=9, windowSum=19, size=3
          → maxSum=19, remove arr[3]=8, windowSum=11, i++, j++
          
i=4, j=6: arr[6]=1, windowSum=12, size=3
          → maxSum=19, done

Answer: 19 ✓
```

---

### **5. Code**

```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int n = arr.size();
    int maxSum = INT_MIN;
    int windowSum = 0;
    
    while (j < n) {
        // Step 1: Calculation
        windowSum += arr[j];
        
        // Step 2: Check window size
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Step 3: Calculate answer
            maxSum = max(maxSum, windowSum);
            
            // Step 4: Slide window
            windowSum -= arr[i];
            i++;
            j++;
        }
    }
    
    return maxSum;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 4: First Negative Number in Every Window of Size K

### **1. Problem Statement**
Given an array with negatives, find first negative number in every window of size K. If no negative, output 0.

**Input:** `arr[] = {12, -1, -7, 8, -15, 30, 16, 28}`, `k = 3`  
**Output:** `{-1, -1, -7, -15, -15, 0}`

**Explanation:**
```
Window [12, -1, -7] → First negative: -1
Window [-1, -7, 8] → First negative: -1
Window [-7, 8, -15] → First negative: -7
Window [8, -15, 30] → First negative: -15
Window [-15, 30, 16] → First negative: -15
Window [30, 16, 28] → First negative: 0 (none)
```

---

### **2. Identification**
✅ Array problem  
✅ "Every window of size K" → Fixed window  
✅ "First" element with condition → Sliding window + Queue  

---

### **3. Abstract/Approach**

**Key Insight:** Use queue to store negative numbers in current window

**Steps:**
1. If arr[j] is negative, add to queue
2. When window size = k:
   - First element in queue = answer
   - If queue empty, answer = 0
3. Before sliding: If arr[i] was in queue, remove it

---

### **4. Dry Run**

```
arr = [12, -1, -7, 8, -15], k = 3
queue = []

j=0: arr[0]=12 (positive), queue=[], size=1 → j++
j=1: arr[1]=-1 (negative), queue=[-1], size=2 → j++
j=2: arr[2]=-7 (negative), queue=[-1,-7], size=3
     → answer=-1 (queue.front()), 
     → remove arr[0]=12 (not in queue), i++, j++
     
j=3: arr[3]=8 (positive), queue=[-1,-7], size=3
     → answer=-1,
     → remove arr[1]=-1 (in queue), queue=[-7], i++, j++
     
j=4: arr[4]=-15 (negative), queue=[-7,-15], size=3
     → answer=-7,
     → remove arr[2]=-7, queue=[-15], i++, j++

Output: [-1, -1, -7] ✓
```

---

### **5. Code**

```cpp
vector<int> firstNegative(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int n = arr.size();
    vector<int> result;
    queue<int> negatives; // Store negative numbers
    
    while (j < n) {
        // Step 1: Calculation
        if (arr[j] < 0) {
            negatives.push(arr[j]);
        }
        
        // Step 2: Check window size
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Step 3: Calculate answer
            if (negatives.empty()) {
                result.push_back(0);
            } else {
                result.push_back(negatives.front());
            }
            
            // Step 4: Slide window
            if (arr[i] < 0) {
                negatives.pop();
            }
            i++;
            j++;
        }
    }
    
    return result;
}
```

**Time:** O(n) | **Space:** O(k) for queue

---

## 📝 PROBLEM 5: Count Occurrences of Anagrams

### **1. Problem Statement**
Given text and pattern, count occurrences of anagrams of pattern in text.

**Input:** `text = "forxxorfxdofr"`, `pattern = "for"`  
**Output:** `3`  
**Explanation:** Anagrams of "for": "for", "orf", "ofr" found at positions 0, 3, 10

---

### **2. Identification**
✅ String problem  
✅ "Window of pattern length" → Fixed window (k = pattern.length)  
✅ Anagram check → Use frequency map  

---

### **3. Abstract/Approach**

**Key Insight:** 
- Anagram means same characters with same frequency
- Use map to track character counts
- When all counts = 0, found anagram

**Steps:**
1. Create frequency map of pattern
2. Track count of distinct characters
3. When window = k:
   - If all characters matched (count = 0), increment answer
4. Slide: Restore frequency of arr[i]

---

### **4. Dry Run**

```
text = "aabaabaa", pattern = "aaba", k = 4
patternMap = {a: 3, b: 1}, distinctChars = 2

j=0: text[0]='a', map[a]=2, distinctChars=2, size=1 → j++
j=1: text[1]='a', map[a]=1, distinctChars=2, size=2 → j++
j=2: text[2]='b', map[b]=0, distinctChars=1, size=3 → j++
j=3: text[3]='a', map[a]=0, distinctChars=0, size=4
     → count++ (found anagram!)
     → restore text[0]='a', map[a]=1, distinctChars=1, i++, j++
     
j=4: text[4]='a', map[a]=0, distinctChars=0, size=4
     → count++ (found anagram!)
     → restore text[1]='a', map[a]=1, distinctChars=1, i++, j++

Output: 2 anagrams found ✓
```

---

### **5. Code**

```cpp
int countAnagrams(string text, string pattern) {
    int i = 0, j = 0;
    int k = pattern.size();
    int n = text.size();
    int count = 0;
    
    // Frequency map of pattern
    unordered_map<char, int> patternMap;
    for (char c : pattern) {
        patternMap[c]++;
    }
    
    int distinctChars = patternMap.size();
    
    while (j < n) {
        // Step 1: Calculation
        if (patternMap.find(text[j]) != patternMap.end()) {
            patternMap[text[j]]--;
            if (patternMap[text[j]] == 0) {
                distinctChars--;
            }
        }
        
        // Step 2: Check window size
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Step 3: Calculate answer
            if (distinctChars == 0) {
                count++; // Found anagram!
            }
            
            // Step 4: Slide window
            if (patternMap.find(text[i]) != patternMap.end()) {
                patternMap[text[i]]++;
                if (patternMap[text[i]] == 1) {
                    distinctChars++;
                }
            }
            i++;
            j++;
        }
    }
    
    return count;
}
```

**Time:** O(n) | **Space:** O(k) for map

---

## 📝 PROBLEM 6: Maximum of All Subarrays of Size K

### **1. Problem Statement**
Given array and K, find maximum element in every window of size K.

**Input:** `arr[] = {1, 3, -1, -3, 5, 3, 6, 7}`, `k = 3`  
**Output:** `{3, 3, 5, 5, 6, 7}`

**Explanation:**
```
Window [1, 3, -1] → Max: 3
Window [3, -1, -3] → Max: 3
Window [-1, -3, 5] → Max: 5
Window [-3, 5, 3] → Max: 5
Window [5, 3, 6] → Max: 6
Window [3, 6, 7] → Max: 7
```

---

### **2. Identification**
✅ "Every window of size K" → Fixed window  
✅ "Maximum" → Need max tracking  
✅ Use **Deque** (double-ended queue) for O(n) solution

---

### **3. Abstract/Approach**

**Key Insight:** Use deque to store indices of useful elements

**Deque maintains:**
- Decreasing order of elements
- Front always has maximum of current window
- Remove elements outside window
- Remove smaller elements (not useful)

---

### **4. Dry Run**

```
arr = [1, 3, -1, -3], k = 3
deque = [] (stores indices)

j=0: arr[0]=1, deque=[0], size=1 → j++
j=1: arr[1]=3 > arr[0]=1, remove 0, deque=[1], size=2 → j++
j=2: arr[2]=-1 < arr[1]=3, deque=[1,2], size=3
     → max=arr[deque.front()]=arr[1]=3
     
j=3: arr[3]=-3 < arr[2]=-1, deque=[1,2,3]
     → remove index 1 (out of window i=1), deque=[2,3]
     → max=arr[2]=-1... wait, need to check

Actually: deque=[1,2,3] after adding
But index 1 is still in window [1,2,3], so keep it
max=arr[1]=3 ✓
```

---

### **5. Code**

```cpp
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int n = arr.size();
    vector<int> result;
    deque<int> dq; // Stores indices
    
    while (j < n) {
        // Step 1: Calculation
        // Remove smaller elements (not useful)
        while (!dq.empty() && arr[dq.back()] < arr[j]) {
            dq.pop_back();
        }
        dq.push_back(j);
        
        // Step 2: Check window size
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Step 3: Calculate answer
            result.push_back(arr[dq.front()]);
            
            // Step 4: Slide window
            // Remove elements outside window
            if (dq.front() == i) {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    
    return result;
}
```

**Time:** O(n) | **Space:** O(k)

---

## 🔄 VARIABLE SIZE WINDOW

### **Video 7-8-9: Variable Size Introduction**

**Difference from Fixed:**
- Window size is NOT given
- Need to find: **longest**, **shortest**, **maximum**, **minimum**
- Window expands and shrinks based on condition

**Keywords:**
- "Longest substring with..."
- "Largest subarray with sum..."
- "Smallest window containing..."

---

## 🔧 VARIABLE SIZE WINDOW TEMPLATE

```cpp
// UNIVERSAL TEMPLATE FOR VARIABLE WINDOW
int i = 0, j = 0;
int ans = 0; // or INT_MAX for minimum

while (j < n) {
    // Step 1: CALCULATION (add arr[j])
    
    // Step 2: CHECK CONDITION
    if (condition < target) {
        // Condition not met, expand
        j++;
    }
    else if (condition == target) {
        // Condition met! Calculate answer
        ans = max(ans, j - i + 1);
        j++;
    }
    else if (condition > target) {
        // Condition exceeded, shrink window
        while (condition > target) {
            // Remove arr[i] from calculation
            i++;
        }
        j++;
    }
}
```

---

## 📝 PROBLEM 7-8: Largest Subarray of Sum K (Variable Window)

### **1. Problem Statement**
Given array of **positive integers** and sum K, find length of longest subarray with sum = K.

**Input:** `arr[] = {4, 1, 1, 1, 2, 3, 5}`, `k = 5`  
**Output:** `4`  
**Explanation:** Subarray `[1, 1, 1, 2]` has sum 5 and length 4

---

### **2. Identification**
✅ Array problem  
✅ Subarray (contiguous)  
✅ "Largest/Longest" → Variable window  
✅ Sum condition → Track running sum

---

### **3. Abstract/Approach**

**3 Conditions:**
1. **sum < k:** Expand window (j++)
2. **sum == k:** Found answer! Calculate length, expand
3. **sum > k:** Shrink window (i++) until sum <= k

---

### **4. Dry Run**

```
arr = [4, 1, 1, 1, 2], k = 5

i=0, j=0: sum=4 (<5) → j++
i=0, j=1: sum=5 (==5) → maxLen=2, j++
i=0, j=2: sum=6 (>5) → shrink: sum=2, i=1, then j++
i=1, j=3: sum=3 (<5) → j++
i=1, j=4: sum=5 (==5) → maxLen=4 ✓

Answer: 4
```

---

### **5. Code**

```cpp
int longestSubarraySum(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int n = arr.size();
    int maxLen = 0;
    int sum = 0;
    
    while (j < n) {
        // Step 1: Calculation
        sum += arr[j];
        
        // Step 2: Check condition
        if (sum < k) {
            j++;
        }
        else if (sum == k) {
            // Found valid subarray
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (sum > k) {
            // Shrink window
            while (sum > k) {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    
    return maxLen;
}
```

**Time:** O(n) | **Space:** O(1)

**Note:** Only works for **positive integers**

---

## 📝 PROBLEM 10: Longest Substring With K Unique Characters

### **1. Problem Statement**
Given string, find length of longest substring with exactly K unique characters.

**Input:** `s = "aabacbebebe"`, `k = 3`  
**Output:** `7`  
**Explanation:** "cbebebe" has 3 unique chars (c, b, e) and length 7

---

### **2. Identification**
✅ String problem  
✅ "Longest substring" → Variable window  
✅ "K unique" → Track unique characters with map

---

### **3. Abstract/Approach**

**Use map to track character frequency**

**3 Conditions:**
1. **unique < k:** Need more, expand (j++)
2. **unique == k:** Valid! Calculate answer, expand
3. **unique > k:** Too many, shrink (i++) until unique == k

---

### **4. Dry Run**

```
s = "aabac", k = 2
map = {}, unique = map.size()

j=0: s[0]='a', map={a:1}, unique=1 (<2) → j++
j=1: s[1]='a', map={a:2}, unique=1 (<2) → j++
j=2: s[2]='b', map={a:2,b:1}, unique=2 (==2) → maxLen=3, j++
j=3: s[3]='a', map={a:3,b:1}, unique=2 (==2) → maxLen=4, j++
j=4: s[4]='c', map={a:3,b:1,c:1}, unique=3 (>2)
     → shrink: remove s[0]='a', map={a:2,b:1,c:1}, still 3
     → shrink: remove s[1]='a', map={a:1,b:1,c:1}, still 3
     → shrink: remove s[2]='b', map={a:1,c:1}, unique=2
     → j++

Answer: 4
```

---

### **5. Code**

```cpp
int longestKUniqueChars(string s, int k) {
    int i = 0, j = 0;
    int n = s.size();
    int maxLen = 0;
    unordered_map<char, int> charMap;
    
    while (j < n) {
        // Step 1: Calculation
        charMap[s[j]]++;
        
        // Step 2: Check condition
        if (charMap.size() < k) {
            j++;
        }
        else if (charMap.size() == k) {
            // Valid window
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (charMap.size() > k) {
            // Too many unique chars
            while (charMap.size() > k) {
                charMap[s[i]]--;
                if (charMap[s[i]] == 0) {
                    charMap.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    
    return maxLen;
}
```

**Time:** O(n) | **Space:** O(k)

---

## 📝 PROBLEM 11: Longest Substring Without Repeating Characters

### **1. Problem Statement**
Find length of longest substring with all unique characters (no repeats).

**Input:** `s = "abcabcbb"`  
**Output:** `3`  
**Explanation:** "abc" is longest with length 3

---

### **2. Identification**
✅ "Longest substring" → Variable window  
✅ "Without repeating" → All characters must be unique  
✅ Use map to track frequency

---

### **3. Abstract/Approach**

**This is like K unique problem with K = all characters in window**

**Conditions:**
- **No duplicates:** Calculate answer, expand
- **Has duplicates:** Shrink until no duplicates

---

### **4. Code**

```cpp
int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0;
    int n = s.size();
    int maxLen = 0;
    unordered_map<char, int> charMap;
    
    while (j < n) {
        // Step 1: Calculation
        charMap[s[j]]++;
        
        // Step 2: Check condition
        if (charMap.size() == j - i + 1) {
            // All unique (map size = window size)
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else {
            // Has duplicates (map size < window size)
            while (charMap.size() < j - i + 1) {
                charMap[s[i]]--;
                if (charMap[s[i]] == 0) {
                    charMap.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    
    return maxLen;
}
```

**Time:** O(n) | **Space:** O(min(n, charset))

---

## 📝 PROBLEM 12: Pick Toys (Fruit Into Baskets)

### **1. Problem Statement**
Pick maximum fruits of at most 2 types (only 2 baskets).

**Input:** `fruits = "abcbbcaaac"` (a, b, c are fruit types)  
**Output:** `5`  
**Explanation:** "bbcaa" or "caaac" has 2 types and length 5

---

### **2. Identification**
✅ "At most 2 types" → Variable window with k=2  
✅ Same as "Longest substring with K=2 unique characters"

---

### **3. Code**

```cpp
int totalFruit(string fruits) {
    int i = 0, j = 0;
    int n = fruits.size();
    int maxLen = 0;
    unordered_map<char, int> basket;
    
    while (j < n) {
        basket[fruits[j]]++;
        
        if (basket.size() <= 2) {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else {
            while (basket.size() > 2) {
                basket[fruits[i]]--;
                if (basket[fruits[i]] == 0) {
                    basket.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
    }
    
    return maxLen;
}
```

---

## 📝 PROBLEM 13: Minimum Window Substring

### **1. Problem Statement**
Find smallest substring in S that contains all characters of T.

**Input:** `s = "ADOBECODEBANC"`, `t = "ABC"`  
**Output:** `"BANC"`

---

### **2. Identification**
✅ "Minimum/Smallest window" → Variable window  
✅ "Contains all" → Track character frequency  
✅ Need to find MINIMUM (not maximum)

---

### **3. Abstract/Approach**

**Different from previous:** Looking for **MINIMUM** length

**Steps:**
1. Create frequency map of T
2. Expand window until all characters found
3. Shrink window to minimize length
4. Track minimum length window

---

### **4. Code**

```cpp
string minWindow(string s, string t) {
    int i = 0, j = 0;
    int n = s.size();
    int minLen = INT_MAX;
    int start = 0;
    
    unordered_map<char, int> tMap, windowMap;
    for (char c : t) tMap[c]++;
    
    int required = tMap.size();
    int formed = 0;
    
    while (j < n) {
        // Add character
        char c = s[j];
        windowMap[c]++;
        
        if (tMap.count(c) && windowMap[c] == tMap[c]) {
            formed++;
        }
        
        // Shrink window while valid
        while (i <= j && formed == required) {
            // Update result
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }
            
            // Remove from left
            char leftChar = s[i];
            windowMap[leftChar]--;
            if (tMap.count(leftChar) && windowMap[leftChar] < tMap[leftChar]) {
                formed--;
            }
            i++;
        }
        
        j++;
    }
    
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

**Time:** O(n) | **Space:** O(m) where m = unique chars in t

---

### **Variable Size Template:**

```cpp
int slidingWindowVariable(vector<int>& arr, int condition) {
    int i = 0, j = 0;
    int n = arr.size();
    int ans = 0;
    
    while (j < n) {
        // 1. Calculation
        // ... update variables with arr[j]
        
        // 2. Check condition
        if (current < condition) {
            // Expand window
            j++;
        }
        else if (current == condition) {
            // Calculate answer, then expand
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (current > condition) {
            // Shrink window until condition satisfied
            while (current > condition) {
                // Remove arr[i] from calculation
                i++;
            }
            j++;
        }
    }
    
    return ans;
}
```

### **Problem 4: Longest Substring with K Unique Characters** ⭐⭐⭐

```cpp
int longestKUniqueChars(string s, int k) {
    int i = 0, j = 0;
    int n = s.size();
    int maxLen = 0;
    unordered_map<char, int> charMap;
    
    while (j < n) {
        // 1. Calculation
        charMap[s[j]]++;
        
        // 2. Check condition
        if (charMap.size() < k) {
            j++; // Need more unique chars
        }
        else if (charMap.size() == k) {
            // Found valid window
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (charMap.size() > k) {
            // Too many unique chars, shrink
            while (charMap.size() > k) {
                charMap[s[i]]--;
                if (charMap[s[i]] == 0) {
                    charMap.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    
    return maxLen;
}
```

---

## 6. Pattern Recognition

### **Fixed Size Window Pattern:**
```
Keywords: "of size k", "exactly k", "window of size k"
Template: if (j - i + 1 == k) then calculate
```

### **Variable Size Window Pattern:**
```
Keywords: "longest", "maximum", "at most k", "at least k"
Template: Expand/shrink based on condition
```

---

## 7. Common Mistakes to Avoid

```cpp
❌ WRONG: Forgetting to remove arr[i] before sliding
if (j - i + 1 == k) {
    ans = max(ans, windowSum);
    i++; j++; // BUG: Didn't remove arr[i] from windowSum!
}

✅ RIGHT: Always remove arr[i] contribution
if (j - i + 1 == k) {
    ans = max(ans, windowSum);
    windowSum -= arr[i]; // Remove before sliding
    i++; j++;
}
```

```cpp
❌ WRONG: Incrementing j outside the while loop
while (j < n) {
    if (j - i + 1 < k) {
        // Missing j++ here!
    }
}
j++; // BUG: j++ should be inside conditions

✅ RIGHT: j++ inside each condition
while (j < n) {
    if (j - i + 1 < k) {
        j++; // Correct
    }
    else if (j - i + 1 == k) {
        // ...
        j++; // Correct
    }
}
```

---

## 8. Template Variations

### **Variation 1: Maximum/Minimum of Window**
```cpp
int maxSum = INT_MIN; // For maximum
int minSum = INT_MAX; // For minimum
```

### **Variation 2: Count Problems**
```cpp
int count = 0;
if (condition_satisfied) {
    count++;
}
```

### **Variation 3: Using Data Structures**
```cpp
queue<int> q;        // For first/last element tracking
deque<int> dq;       // For max/min in window
map<char, int> mp;   // For frequency/unique elements
```

---

## 9. Quick Reference

### **Fixed Size Window (4 Steps):**
```
1. CALCULATION:    Process arr[j]
2. CHECK SIZE:     if (j - i + 1 < k) → j++
3. ANSWER:         if (j - i + 1 == k) → calculate answer
4. SLIDE:          Remove arr[i], then i++, j++
```

### **Variable Size Window (3 Conditions):**
```
1. LESS THAN:      if (current < target) → j++
2. EQUAL:          if (current == target) → ans, j++
3. GREATER:        if (current > target) → while loop to shrink i
```

---

## 10. Interview Tips

✅ **Before Coding:**
1. Identify: Fixed or Variable window?
2. What to calculate? (sum, count, max, min)
3. What data structure needed? (queue, map, set)

✅ **While Coding:**
1. Always initialize i = 0, j = 0
2. Remember to remove arr[i] before sliding
3. j++ in EVERY condition path

✅ **Testing:**
1. Test with k = 1 (edge case)
2. Test with k = n (full array)
3. Check boundary conditions

---

## ✅ Summary

**Aditya Verma's Template = Universal Solution**

```cpp
FIXED WINDOW:
int i = 0, j = 0;
while (j < n) {
    // Calculation
    if (j - i + 1 < k) j++;
    else if (j - i + 1 == k) {
        // Answer
        // Slide
        i++; j++;
    }
}

VARIABLE WINDOW:
int i = 0, j = 0;
while (j < n) {
    // Calculation
    if (condition < target) j++;
    else if (condition == target) { ans; j++; }
    else if (condition > target) { while(...) i++; j++; }
}
```

**Master these 2 templates and you can solve ANY sliding window problem! 🚀**

---