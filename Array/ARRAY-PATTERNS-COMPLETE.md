# 📖 ARRAY PATTERNS - COMPLETE REVISION SHEET
## Detailed Guide with ALL Patterns, Intuitions, Templates & Flow Structures
### **PRINT-READY VERSION - For Deep Study & Interview Prep**

---

## 📑 QUICK NAVIGATION
1. **Pattern 1:** Single Pass Linear Scan
2. **Pattern 2:** Two Pointer Technique  
3. **Pattern 3:** Sliding Window
4. **Pattern 4:** Prefix/Suffix Sum
5. **Pattern 5:** Hashing
6. **Pattern 6:** Sorting & Binary Search
7. **Pattern 7:** Kadane's Algorithm
8. **Master Pattern Recognition Flowchart**
9. **Interview Scripts & Dialogues**
10. **Quick Problem Reference**

---

---

# 🎯 PATTERN 1: SINGLE PASS LINEAR SCAN
## Time: O(n) | Space: O(1)

### **WHAT IS IT?**
Traverse array once, maintain state/accumulator, process each element independently.

### **REAL-WORLD INTUITION**
```
Walking through market counting items:
- You walk once (don't go back)
- Count expensive items as you see them
- One pass, done

Array Problem: Find max element?
- Walk through array once
- Track maximum seen so far
- When done, you have answer
```

### **WHY IT WORKS**
```
Key Insight: We don't need to compare every element with every other

Problem: Find max in [3, 7, 2, 9, 1]
Inefficient: Compare 3 with all others, then 7 with all others...
Efficient: Track max = 3. See 7? It's bigger, max = 7. See 2? Nope...

Don't need all comparisons, just track the best!
```

### **GENERIC TEMPLATE**
```cpp
dataType result = initial_value;

for(int i = 0; i < n; i++) {
    if(condition_met(arr[i])) {
        result = update_operation(result, arr[i]);
    }
}

return result;
```

### **FLOW STRUCTURE**
```
INITIALIZE result/accumulator
        ↓
LOOP: for i = 0 to n-1
        ↓
CHECK condition on arr[i]
        ↓ (if met)
UPDATE result
        ↓
CONTINUE to next element
        ↓ (loop ends)
RETURN result
```

---

## 📊 PROBLEM 1.1: Find Maximum Element

**Problem:** `[3, 7, 2, 9, 1]` → Output: `9`

**Deep Intuition:**
```
How do we know 9 is max without comparing ALL pairs?

Running Comparison Principle:
- 3: Is this max so far? YES → max = 3
- 7: Is this bigger than max(3)? YES → max = 7
- 2: Is this bigger than max(7)? NO → max stays 7
- 9: Is this bigger than max(7)? YES → max = 9
- 1: Is this bigger than max(9)? NO → max stays 9

ANSWER: 9

Key: We only needed 4 comparisons, not 10 pair comparisons!
```

**Generic Template:**
```cpp
int findMax(int arr[], int n) {
    int max_so_far = arr[0];        // Initialize with first
    
    for(int i = 1; i < n; i++) {    // Start from second
        if(arr[i] > max_so_far) {   // Is this better?
            max_so_far = arr[i];    // Update
        }
    }
    
    return max_so_far;              // Return best found
}
```

**Detailed Dry Run:**
```
Array: [3, 7, 2, 9, 1]

Step 0: max_so_far = 3 (arr[0])

Step 1: i=1, arr[1]=7
        Is 7 > 3? YES
        → max_so_far = 7

Step 2: i=2, arr[2]=2
        Is 2 > 7? NO
        → max_so_far = 7 (no change)

Step 3: i=3, arr[3]=9
        Is 9 > 7? YES
        → max_so_far = 9

Step 4: i=4, arr[4]=1
        Is 1 > 9? NO
        → max_so_far = 9 (no change)

RETURN: 9 ✓
```

**Complexity:**
- **Time:** O(n) — One pass, n comparisons
- **Space:** O(1) — Only max_so_far variable

**Edge Cases:**
- Empty array: Handle n==0
- Single element: Returns that element
- All negative: Still works (returns largest negative)
- Duplicates: Works fine

---

## 📊 PROBLEM 1.2: Count Elements Meeting Condition

**Problem:** `[1, 2, 3, 4, 5, 6]` → Count even numbers → Output: `3`

**Template:**
```cpp
int countEven(int arr[], int n) {
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {       // Even condition
            count++;
        }
    }
    
    return count;
}
```

**Dry Run:**
```
[1, 2, 3, 4, 5, 6]

1: Is 1 even? NO, count = 0
2: Is 2 even? YES, count = 1
3: Is 3 even? NO, count = 1
4: Is 4 even? YES, count = 2
5: Is 5 even? NO, count = 2
6: Is 6 even? YES, count = 3

RETURN: 3 ✓
```

---

## 📊 PROBLEM 1.3: Linear Search (First Occurrence)

**Problem:** `[3, 7, 2, 9, 1]`, target=7 → Output: `1` (index)

**Intuition:**
```
Need to find element sequentially?

Check arr[0] == 7? No
Check arr[1] == 7? Yes! Return 1

If reach end without finding: Return -1
```

**Template:**
```cpp
int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;               // Found!
        }
    }
    return -1;                      // Not found
}
```

**Complexity:**
- Best: O(1) — Found at first position
- Worst: O(n) — Found at last or not present
- Average: O(n)

---

---

# 🎯 PATTERN 2: TWO POINTER TECHNIQUE
## Time: O(n) | Space: O(1)

### **WHAT IS IT?**
Use two pointers moving toward each other (or in same direction) to solve problems efficiently.

### **REAL-WORLD INTUITION**
```
Two Friends Meeting:
- Friend A starts from left, walks right
- Friend B starts from right, walks left
- They meet somewhere in middle

Array Problem (sorted):
Find two numbers that sum to target?
- left pointer at start (small numbers)
- right pointer at end (large numbers)
- If sum < target: move left right (need bigger)
- If sum > target: move right left (need smaller)
- If sum == target: FOUND!
```

### **WHY IT WORKS**
```
Key: Array is SORTED = Information we can use

For sorted array [1, 3, 5, 7, 9], target = 12:

Without sorting:
- Check all pairs: (1,3), (1,5), ... O(n²)

With sorting (already given):
- left=0 (1), right=4 (9): sum=10 < 12 → left++
- left=1 (3), right=4 (9): sum=12 == 12 → FOUND!

We never look at same pair twice!
Each pointer moves only forward/backward.
Total movement: 2n = O(n)
```

### **GENERIC TEMPLATE - OPPOSITE ENDS**
```cpp
int left = 0, right = n - 1;

while(left < right) {
    int current = arr[left] + arr[right];
    
    if(current == target) {
        return {left, right};       // Found!
    }
    else if(current < target) {
        left++;                     // Need larger
    }
    else {
        right--;                    // Need smaller
    }
}

return {-1, -1};                    // Not found
```

### **FLOW STRUCTURE**
```
INITIALIZE: left = 0, right = n-1
        ↓
WHILE left < right (haven't crossed):
        ↓
CALCULATE: current sum/property
        ↓
CHECK condition (less/equal/greater)
        ↓
BRANCH:
├─ LESS: left++ (need bigger value)
├─ EQUAL: RETURN solution
└─ GREATER: right-- (need smaller value)
        ↓
REPEAT while loop
        ↓ (when left >= right)
NOT FOUND
```

---

## 📊 PROBLEM 2.1: Two Sum (Sorted Array)

**Problem:** `[1, 3, 5, 7, 9]`, target=12 → Output: `[1, 4]` (indices 3 and 9)

**Deep Intuition:**
```
Why two pointer works here:

1. Array is sorted: Small numbers left, large numbers right
2. If sum too small: We need LARGER number
   - We can't get larger from left side (more small numbers)
   - So move left pointer right
3. If sum too large: We need SMALLER number
   - We can't get smaller from right side (more large numbers)
   - So move right pointer left
4. This eliminates many possibilities without checking

Visual:
left           right
 ↓              ↓
[1, 3, 5, 7, 9]

1+9=10, too small, left→
   [3, 5, 7, 9]

3+9=12, equal, FOUND!
```

**Solution:**
```cpp
pair<int, int> twoSum(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(sum == target) {
            return {left, right};
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    
    return {-1, -1};
}
```

**Detailed Dry Run:**
```
Array: [1, 3, 5, 7, 9], target = 12

Initialize: left=0, right=4

Iteration 1:
  left=0 (value 1), right=4 (value 9)
  sum = 1 + 9 = 10
  Is 10 == 12? NO
  Is 10 < 12? YES → left++

Iteration 2:
  left=1 (value 3), right=4 (value 9)
  sum = 3 + 9 = 12
  Is 12 == 12? YES!
  RETURN {1, 4} ✓

Elements at indices 1 and 4 are 3 and 9.
3 + 9 = 12 ✓
```

**Complexity:**
- **Time:** O(n) — Each pointer visits each element once
- **Space:** O(1) — Only two pointers

**vs Brute Force O(n²):**
```
Brute Force for [1, 3, 5, 7, 9]:
Check: (1,3), (1,5), (1,7), (1,9) = 4 checks
       (3,5), (3,7), (3,9) = 3 checks
       (5,7), (5,9) = 2 checks
       (7,9) = 1 check
Total: 10 comparisons

Two Pointer:
(1,9) → (3,9) = 2 checks
Much better for large arrays!
```

---

## 📊 PROBLEM 2.2: Reverse Array In-Place

**Problem:** `[1, 2, 3, 4, 5]` → Output: `[5, 4, 3, 2, 1]`

**Intuition:** Swap elements from ends moving inward.

**Solution:**
```cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while(left < right) {
        // Swap
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
}
```

**Detailed Dry Run:**
```
Array: [1, 2, 3, 4, 5]

Iteration 1: left=0, right=4
  Swap arr[0] and arr[4]: [5, 2, 3, 4, 1]
  left++, right--

Iteration 2: left=1, right=3
  Swap arr[1] and arr[3]: [5, 4, 3, 2, 1]
  left++, right--

Iteration 3: left=2, right=2
  left < right? NO (2 is not < 2)
  Stop

Result: [5, 4, 3, 2, 1] ✓
```

**Complexity:**
- **Time:** O(n) — n/2 swaps
- **Space:** O(1) — In-place, no extra array

---

## 📊 PROBLEM 2.3: Container With Most Water

**Problem:** `[1, 8, 6, 2, 5, 4, 8, 3, 7]`
```
Heights represent container walls.
Find two walls that can hold maximum water.

Area = width × min_height

Visual:
     |     |
     | |   |
     | | | | |
     | | | | |
   ----------

Between index 1 (height 8) and index 8 (height 7):
Width = 8 - 1 = 7
Height = min(8, 7) = 7
Area = 7 × 7 = 49 ← Answer
```

**Intuition:**
```
Area = width × min_height

Key Insight:
If we move pointer from LONGER line inward:
- Width decreases
- Maximum possible height stays same (limited by longer line)
- Area can only decrease

If we move pointer from SHORTER line inward:
- Width decreases
- But we might find TALLER line
- Area might increase!

Strategy: Always move the SHORTER pointer inward.
```

**Solution:**
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while(left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        int area = h * w;
        
        maxWater = max(maxWater, area);
        
        if(height[left] < height[right]) {
            left++;                 // Move shorter
        } else {
            right--;                // Move shorter
        }
    }
    
    return maxWater;
}
```

**Detailed Dry Run:**
```
Array: [1, 8, 6, 2, 5, 4, 8, 3, 7]
Index:  0  1  2  3  4  5  6  7  8

Iteration 1:
  left=0 (height 1), right=8 (height 7)
  width = 8 - 0 = 8
  height = min(1, 7) = 1
  area = 1 × 8 = 8
  maxWater = 8
  1 < 7? YES → left++

Iteration 2:
  left=1 (height 8), right=8 (height 7)
  width = 8 - 1 = 7
  height = min(8, 7) = 7
  area = 7 × 7 = 49
  maxWater = 49
  8 < 7? NO → right--

[Continue for remaining iterations...]

Maximum: 49 ✓
```

---

---

# 🎯 PATTERN 3: SLIDING WINDOW
## Time: O(n) | Space: O(1) or O(k)

### **WHAT IS IT?**
Maintain a window and slide it across array. Two types:
- **Fixed Window:** Size known (k)
- **Variable Window:** Size changes based on conditions

### **REAL-WORLD INTUITION**
```
Glass Pane Moving Over Blocks:

Block row: [1, 2, 3, 4, 5]
Pane size: 3

Position 1: [1, 2, 3] → Sum = 6
Position 2:    [2, 3, 4] → Sum = 9
Position 3:       [3, 4, 5] → Sum = 12

Problem: Find max sum in any window?
Answer: 12

Without sliding window:
- Recalculate sum for each position: O(n × k)
- [1+2+3], [2+3+4], [3+4+5]...

With sliding window:
- Calculate first: 1+2+3 = 6
- Remove 1, add 4: 6 - 1 + 4 = 9
- Remove 2, add 5: 9 - 2 + 5 = 12
- Only additions/subtractions: O(n)
```

### **GENERIC TEMPLATE - FIXED WINDOW**
```cpp
int windowSum = 0;
int maxSum = 0;

// Build initial window
for(int i = 0; i < k; i++) {
    windowSum += arr[i];
}
maxSum = windowSum;

// Slide window
for(int i = k; i < n; i++) {
    windowSum = windowSum - arr[i-k] + arr[i];
    maxSum = max(maxSum, windowSum);
}

return maxSum;
```

---

## 📊 PROBLEM 3.1: Maximum Sum of k-size Subarray

**Problem:** `[1, 4, 2, 10, 2, 3, 1, 0, 20]`, k=4 → Max sum in any window of 4?

**Detailed Dry Run:**
```
Array: [1, 4, 2, 10, 2, 3, 1, 0, 20]

STEP 1: Build first window (indices 0-3)
Window: [1, 4, 2, 10]
Sum: 1 + 4 + 2 + 10 = 17
maxSum = 17

STEP 2: Slide to indices 1-4
Remove arr[0]=1, Add arr[4]=2
windowSum = 17 - 1 + 2 = 18
maxSum = 18

STEP 3: Slide to indices 2-5
Remove arr[1]=4, Add arr[5]=3
windowSum = 18 - 4 + 3 = 17
maxSum = 18 (unchanged)

STEP 4: Slide to indices 3-6
Remove arr[2]=2, Add arr[6]=1
windowSum = 17 - 2 + 1 = 16
maxSum = 18 (unchanged)

STEP 5: Slide to indices 4-7
Remove arr[3]=10, Add arr[7]=0
windowSum = 16 - 10 + 0 = 6
maxSum = 18 (unchanged)

STEP 6: Slide to indices 5-8
Remove arr[4]=2, Add arr[8]=20
windowSum = 6 - 2 + 20 = 24
maxSum = 24

FINAL: maxSum = 24 ✓ (subarray [3, 1, 0, 20])
```

**Solution:**
```cpp
int maxSumSubarray(int arr[], int n, int k) {
    int windowSum = 0;
    
    // Build first window
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    
    // Slide window
    for(int i = k; i < n; i++) {
        windowSum = windowSum - arr[i-k] + arr[i];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

**Complexity:**
- **Time:** O(n) vs O(n×k) brute force
- **Space:** O(1)

---

### **GENERIC TEMPLATE - VARIABLE WINDOW**
```cpp
int left = 0, right = 0;
int result = 0;
unordered_map<char, int> seen;  // Track window contents

for(right = 0; right < n; right++) {
    // Add new element to window
    seen[arr[right]]++;
    
    // Shrink while invalid
    while(condition_violated(seen)) {
        seen[arr[left]]--;
        if(seen[arr[left]] == 0) {
            seen.erase(arr[left]);
        }
        left++;
    }
    
    // Update result with current window
    result = max(result, right - left + 1);
}

return result;
```

---

## 📊 PROBLEM 3.2: Longest Substring Without Repeating Characters

**Problem:** `"abcabcbb"` → Output: `3` (substring "abc")

**Deep Intuition:**
```
How to handle repeating characters?
When we see a character we've seen before (in current window):
- Shrink window from left until the repeated character is removed

Example: "abcabcbb"

Expand:
- Add 'a': window="a", seen={'a'}
- Add 'b': window="ab", seen={'a','b'}
- Add 'c': window="abc", seen={'a','b','c'}, length=3

- Add 'a' (REPEAT!): 
  'a' is already in window
  Shrink: remove 'a' at index 0
  window="bc", seen={'b','c'}
  Now add 'a': window="bca", seen={'a','b','c'}, length=3

Continue...

Maximum length seen: 3
```

**Solution:**
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;  // char → last index
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.length(); right++) {
        char current = s[right];
        
        // If character was seen in current window
        if(lastSeen.count(current) && lastSeen[current] >= left) {
            // Shrink: move left to after last occurrence
            left = lastSeen[current] + 1;
        }
        
        // Update last position
        lastSeen[current] = right;
        
        // Update max length
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**Detailed Dry Run:**
```
String: a b c a b c b b
Index:  0 1 2 3 4 5 6 7

Step 1: right=0, char='a'
  lastSeen['a'] = 0
  window length = 0 - 0 + 1 = 1
  maxLen = 1

Step 2: right=1, char='b'
  lastSeen['b'] = 1
  window length = 1 - 0 + 1 = 2
  maxLen = 2

Step 3: right=2, char='c'
  lastSeen['c'] = 2
  window length = 2 - 0 + 1 = 3
  maxLen = 3

Step 4: right=3, char='a' (REPEAT!)
  'a' in lastSeen and lastSeen['a']=0 >= left(0)
  SHRINK: left = 0 + 1 = 1
  lastSeen['a'] = 3
  window length = 3 - 1 + 1 = 3
  maxLen = 3

Step 5: right=4, char='b' (REPEAT!)
  'b' in lastSeen and lastSeen['b']=1 >= left(1)
  SHRINK: left = 1 + 1 = 2
  lastSeen['b'] = 4
  window length = 4 - 2 + 1 = 3
  maxLen = 3

...continue similarly...

FINAL: maxLen = 3 ✓
```

**Complexity:**
- **Time:** O(n) — Each character visited once by right, once by left
- **Space:** O(min(n, alphabet_size)) — For character map

---

---

# 🎯 PATTERN 4: PREFIX/SUFFIX SUM  
## Build: O(n) | Query: O(1) | Space: O(n)

### **WHAT IS IT?**
Precompute cumulative sums to answer range queries instantly.

### **INTUITION**
```
prefix[i] = sum of all elements from index 0 to i

Array: [1, 2, 3, 4, 5]
prefix: [1, 3, 6, 10, 15]
         1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5

To find sum from index L to R:
sum(L to R) = prefix[R] - prefix[L-1]

Why?
prefix[R] = sum(0 to R)
prefix[L-1] = sum(0 to L-1)
Difference = sum(L to R)
```

### **FORMULA**
```
Range Sum Query(L, R):
- If L == 0: answer = prefix[R]
- Otherwise: answer = prefix[R] - prefix[L-1]
```

---

## 📊 PROBLEM 4.1: Range Sum Queries

**Problem:** Multiple queries on same array
```
Array: [1, 3, 5, 7, 9]
Query 1: Sum(1, 3) → 3 + 5 + 7 = 15
Query 2: Sum(0, 4) → 1 + 3 + 5 + 7 + 9 = 25
Query 3: Sum(2, 4) → 5 + 7 + 9 = 21
```

**Solution:**
```cpp
class RangeSum {
private:
    vector<int> prefix;
    
public:
    RangeSum(vector<int>& arr) {
        int n = arr.size();
        prefix.resize(n);
        
        // BUILD: O(n)
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    
    // QUERY: O(1)
    int rangeSum(int l, int r) {
        if(l == 0) return prefix[r];
        return prefix[r] - prefix[l-1];
    }
};
```

**Detailed Dry Run:**
```
Array: [1, 3, 5, 7, 9]

BUILD prefix:
prefix[0] = 1
prefix[1] = 1 + 3 = 4
prefix[2] = 4 + 5 = 9
prefix[3] = 9 + 7 = 16
prefix[4] = 16 + 9 = 25

prefix = [1, 4, 9, 16, 25]

QUERIES:

Query(1, 3):
  l=1, r=3
  Not 0, so: prefix[3] - prefix[0]
  = 16 - 1 = 15 ✓

Query(0, 4):
  l=0, r=4
  Is l==0? YES: return prefix[4]
  = 25 ✓

Query(2, 4):
  l=2, r=4
  Not 0, so: prefix[4] - prefix[1]
  = 25 - 4 = 21 ✓
```

**Complexity:**
- **Build:** O(n)
- **Each Query:** O(1)
- **Total for m queries:** O(n + m)

**vs Brute Force:**
- **Brute:** O(n × m) — Recalculate for each query
- **Prefix:** O(n + m) — Build once, query fast

For 1000 queries on 10,000 element array:
- Brute: 10,000,000 operations
- Prefix: 11,000 operations

---

## 📊 PROBLEM 4.2: Pivot Index

**Problem:** Find index where left sum = right sum
```
Array: [1, 7, 3, 6, 5, 6]
At index 3:
  Left sum: 1 + 7 + 3 = 11
  Right sum: 5 + 6 = 11
  FOUND! Answer: 3
```

**Solution:**
```cpp
int pivotIndex(vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;
    
    // Calculate total
    for(int num : arr) {
        totalSum += num;
    }
    
    int leftSum = 0;
    
    for(int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - arr[i];
        
        if(leftSum == rightSum) {
            return i;
        }
        
        leftSum += arr[i];
    }
    
    return -1;  // Not found
}
```

---

---

# 🎯 PATTERN 5: HASHING
## Time: O(n) avg | Space: O(k)

### **WHAT IS IT?**
Use HashMap/HashSet for O(1) lookups instead of O(n) searches.

### **INTUITION**
```
Library without index:
- Need to find book by author? Check every shelf = O(n)

Library with index:
- Author → Book IDs map
- Look up → Instant O(1)

Array without hashing:
- Does element X exist? Search through all = O(n)

Array with hashing:
- Add all to map during first pass = O(n)
- Check if exists? Instant O(1)
```

---

## 📊 PROBLEM 5.1: Find Duplicates

**Problem:** `[1, 2, 3, 1, 2, 4]` → Find elements appearing > 1 time

**Solution:**
```cpp
vector<int> findDuplicates(vector<int>& arr) {
    unordered_map<int, int> freq;
    vector<int> result;
    
    // Count frequencies
    for(int num : arr) {
        freq[num]++;
    }
    
    // Find duplicates
    for(auto& p : freq) {
        if(p.second > 1) {
            result.push_back(p.first);
        }
    }
    
    return result;  // [1, 2]
}
```

---

## 📊 PROBLEM 5.2: Two Sum (Unsorted Array)

**Problem:** `[2, 7, 11, 15]`, target=9 → Output: indices `[0, 1]`

**Solution:**
```cpp
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> seen;  // value → index
    
    for(int i = 0; i < arr.size(); i++) {
        int need = target - arr[i];
        
        if(seen.count(need)) {
            return {seen[need], i};
        }
        
        seen[arr[i]] = i;
    }
    
    return {-1, -1};
}
```

**Dry Run:**
```
[2, 7, 11, 15], target = 9

i=0, arr[0]=2:
  need = 9 - 2 = 7
  Is 7 in seen? NO
  Add 2: seen = {2→0}

i=1, arr[1]=7:
  need = 9 - 7 = 2
  Is 2 in seen? YES at index 0!
  RETURN {0, 1} ✓

2 + 7 = 9 ✓
```

---

---

# 🎯 PATTERN 6: SORTING & BINARY SEARCH  
## Sort: O(n log n) | Search: O(log n)

### **QUICK TEMPLATES**

**Sorting:**
```cpp
sort(arr.begin(), arr.end());  // Ascending
sort(arr.rbegin(), arr.rend()); // Descending
```

**Binary Search:**
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    return -1;  // Not found
}
```

---

---

# 🎯 PATTERN 7: KADANE'S ALGORITHM
## Time: O(n) | Space: O(1)

### **WHAT IS IT?**
Find maximum sum subarray efficiently.

### **INTUITION**
```
At each position, decide:
1. Start fresh new subarray from current element
2. Extend previous subarray

Choose whichever gives larger sum!

max_ending_here = max(arr[i], max_ending_here + arr[i])
```

---

## 📊 PROBLEM 7.1: Maximum Sum Subarray

**Problem:** `[-2, 1, -3, 4, -1, 2, 1, -5, 4]` → Max sum subarray?

**Solution:**
```cpp
int maxSubarraySum(int arr[], int n) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];
    
    for(int i = 1; i < n; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
```

**Detailed Dry Run:**
```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: maxEndingHere=-2, maxSoFar=-2

i=1: (1)
  maxEndingHere = max(1, -2+1) = max(1, -1) = 1
  maxSoFar = max(-2, 1) = 1

i=2: (-3)
  maxEndingHere = max(-3, 1-3) = max(-3, -2) = -2
  maxSoFar = max(1, -2) = 1

i=3: (4)
  maxEndingHere = max(4, -2+4) = max(4, 2) = 4
  maxSoFar = max(1, 4) = 4

i=4: (-1)
  maxEndingHere = max(-1, 4-1) = max(-1, 3) = 3
  maxSoFar = max(4, 3) = 4

i=5: (2)
  maxEndingHere = max(2, 3+2) = max(2, 5) = 5
  maxSoFar = max(4, 5) = 5

i=6: (1)
  maxEndingHere = max(1, 5+1) = max(1, 6) = 6
  maxSoFar = max(5, 6) = 6

i=7: (-5)
  maxEndingHere = max(-5, 6-5) = max(-5, 1) = 1
  maxSoFar = max(6, 1) = 6

i=8: (4)
  maxEndingHere = max(4, 1+4) = max(4, 5) = 5
  maxSoFar = max(6, 5) = 6

ANSWER: 6 ✓ (subarray [4, -1, 2, 1])
```

---

---

# 📋 QUICK REFERENCE TABLE

| Pattern | When to Use | Time | Space | Key insight |
|---------|-----------|------|-------|------------|
| **Linear Scan** | Find max/min, count, sum | O(n) | O(1) | Track best so far |
| **Two Pointer** | Sorted array, pairs | O(n) | O(1) | Move from ends |
| **Sliding Window** | Contiguous subarrays | O(n) | O(1)/O(k) | Expand/shrink window |
| **Prefix Sum** | Range queries | Build O(n), Query O(1) | O(n) | Cumulative information |
| **Hashing** | Duplicates, existence | O(n) avg | O(k) | Fast lookup |
| **Sorting+BS** | Search in sorted | O(n log n)+O(log n) | O(1) | Divide and conquer |
| **Kadane's** | Max subarray sum | O(n) | O(1) | DP on the fly |

---

# 🗣️ INTERVIEW SCRIPTS

## **How to Explain:**

```
Interviewer: "Can you solve this?"

You: "Sure! Let me think...
     [READ PROBLEM CAREFULLY - 30 seconds]
     
     I recognize this is a [PATTERN NAME] problem
     because [WHY].
     
     High-level approach:
     1. [Step 1 with intuition]
     2. [Step 2 with intuition]
     3. [Step 3 with intuition]
     
     Time Complexity: O([time]) because [reason]
     Space Complexity: O([space]) because [reason]
     
     Edge cases I'll handle:
     - [Case 1]: [How]
     - [Case 2]: [How]
     
     Should I code it?"
```

## **When Stuck:**

```
"Let me think about this step by step.
 
 First, let me verify I understand the problem...
 
 For this type of problem, I've seen these approaches work:
 - Approach 1: [Time/Space]
 - Approach 2: [Time/Space]
 - Approach 3: [Time/Space]
 
 I think [BEST APPROACH] is optimal because...
 
 Can I code this?"
```

---

**PRINT-READY | COMPLETE REVISION SHEET**
**Study: 1-2 hours per pattern | Practice: 3-4 problems per pattern**
**Master these 7 patterns → 80% of array problems solved!**
