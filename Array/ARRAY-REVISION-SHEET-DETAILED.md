# 📖 ARRAY PATTERNS - COMPREHENSIVE REVISION SHEET
## Complete Guide with Intuitions, Templates & Flow Structures
### **For Printing & Detailed Study**

---

## 📑 TABLE OF CONTENTS
1. [Pattern 1: Single Pass Linear Scan](#pattern-1)
2. [Pattern 2: Two Pointer Technique](#pattern-2)
3. [Pattern 3: Sliding Window](#pattern-3)
4. [Pattern 4: Prefix/Suffix Sum](#pattern-4)
5. [Pattern 5: Hashing](#pattern-5)
6. [Pattern 6: Sorting & Searching](#pattern-6)
7. [Pattern 7: Kadane's Algorithm](#pattern-7)
8. [Master Pattern Recognition Flowchart](#flowchart)
9. [Quick Problem Reference](#reference)

---

---

# PATTERN 1: SINGLE PASS LINEAR SCAN
<a name="pattern-1"></a>

## 🎯 WHAT IS IT?

**Definition:** Traverse array once from start to end, maintaining some state/accumulator, performing some operation on each element.

**Core Concept:**
- One loop: `for(int i = 0; i < n; i++)`
- Process each element independently
- Accumulate or track result

---

## 💡 INTUITION & ABSTRACT THINKING

### **Real-World Analogy:**
```
You're walking through a market with a list of items to count.
- As you walk, you count how many expensive items you see
- You don't look back, don't reorder items
- Just one pass, count as you go

Array Problem: Count how many elements > 5
- Same idea: one pass, count when condition met
```

### **Why This Pattern Works:**
```
Problem: Find maximum element
Brute Force Thinking: Check first against all others (O(n²))
Smart Thinking: Keep track of max as we go (O(n))

✓ Key Insight: We DON'T need to compare every pair
✓ We just need to track the best so far
```

---

## 📋 GENERIC TEMPLATE

```cpp
// ═══════════════════════════════════════════════════════════
// TEMPLATE: SINGLE PASS LINEAR SCAN
// ═══════════════════════════════════════════════════════════

dataType result = initial_value;  // Initialize accumulator

for(int i = 0; i < n; i++) {
    // Process current element
    if(condition_met(arr[i])) {
        // Update result
        result = update_operation(result, arr[i]);
    }
}

return result;

// TIME: O(n) - one pass
// SPACE: O(1) - only few variables
```

---

## 🌊 FLOW STRUCTURE (Step-by-Step)

```
                    START
                      ↓
          Initialize result/accumulator
                      ↓
          ┌─────────────────────┐
          │   i = 0 to n-1      │
          └─────────────────────┘
                      ↓
          ┌─────────────────────┐
          │  Check condition    │
          │  on arr[i]          │
          └─────────────────────┘
                    YES/NO
                   /      \
                YES        NO
                 ↓          ↓
          Update result   Continue
                 ↓          ↓
                 └───→ Next i
                      ↓
              ┌─────────────────┐
              │ i reached n-1?  │
              └─────────────────┘
                    YES
                      ↓
              RETURN result
```

---

## 📚 PROBLEMS USING THIS PATTERN

### **Problem 1.1: Find Maximum Element**

**Problem Statement:**
```
Input: arr = [3, 7, 2, 9, 1]
Output: 9
```

**Intuition Breakdown:**
```
Question: How do we know 9 is max without comparing with all?
Answer: Keep track of max as we go!

As we see each element:
- 3: Is this the max so far? Yes → max = 3
- 7: Is this bigger than 3? Yes → max = 7
- 2: Is this bigger than 7? No → max = 7
- 9: Is this bigger than 7? Yes → max = 9
- 1: Is this bigger than 9? No → max = 9

Final max = 9
```

**Abstraction:**
```
Abstract Problem: Find the best element (where "best" = largest)

Generic Solution Pattern:
1. Track best_so_far = first element
2. For each subsequent element:
   - If better than best_so_far → update best_so_far
   - Otherwise → keep best_so_far
3. Return best_so_far
```

**Generic Template (Specialized):**
```cpp
int findMax(int arr[], int n) {
    int max_so_far = arr[0];        // Initialize with first
    
    for(int i = 1; i < n; i++) {    // Start from second
        if(arr[i] > max_so_far) {   // Check if better
            max_so_far = arr[i];    // Update
        }
    }
    
    return max_so_far;              // Return best found
}
```

**Detailed Dry Run:**
```
Array: [3, 7, 2, 9, 1]

INITIALIZATION:
max_so_far = 3 (arr[0])

LOOP ITERATIONS:
i=1: arr[1]=7
     Is 7 > 3? YES
     max_so_far = 7

i=2: arr[2]=2
     Is 2 > 7? NO
     max_so_far = 7 (unchanged)

i=3: arr[3]=9
     Is 9 > 7? YES
     max_so_far = 9

i=4: arr[4]=1
     Is 1 > 9? NO
     max_so_far = 9 (unchanged)

RETURN: 9
```

**Complexity Analysis:**
```
Time: O(n)  - Single pass through array
Space: O(1) - Only one variable (max_so_far)

Why O(n)?
- We visit each element exactly once
- Each visit is O(1) operation
- Total: n × O(1) = O(n)
```

**Edge Cases to Handle:**
```
□ Empty array (n=0): Return error or handle specially
□ Single element (n=1): Return that element
□ All negative: Still works, returns largest negative
□ All same: Returns that value
□ Very large numbers: Use long long to avoid overflow
```

**Interview Dialogue:**
```
You: "Sir, I need to find maximum element. 
      I'll traverse array once, maintaining max_so_far.
      For each element, if it's larger than max_so_far, 
      I'll update max_so_far. O(n) time, O(1) space."

Interviewer: "Good. What about edge cases?"

You: "Empty array - I should check n > 0 first.
      Single element - returns that element naturally.
      All negative - still works, returns largest negative.
      Integer overflow - I can use long long if needed."

Interviewer: "Perfect, code it up."
```

---

### **Problem 1.2: Find Sum of All Elements**

**Problem Statement:**
```
Input: arr = [1, 2, 3, 4, 5]
Output: 15
```

**Intuition:**
```
Running Total Concept:
- Start with sum = 0
- Add each element to sum as we go
- Final sum = answer

Visual:
sum = 0
sum = 0 + 1 = 1
sum = 1 + 2 = 3
sum = 3 + 3 = 6
sum = 6 + 4 = 10
sum = 10 + 5 = 15
```

**Template:**
```cpp
int findSum(int arr[], int n) {
    int sum = 0;                // Initialize accumulator
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];          // Add current element
    }
    
    return sum;
}
```

**Complexity:** O(n) time, O(1) space

---

### **Problem 1.3: Count Elements Meeting Condition**

**Problem Statement:**
```
Input: arr = [1, 2, 3, 4, 5, 6], target = "even"
Output: 3 (elements 2, 4, 6 are even)
```

**Template:**
```cpp
int countEven(int arr[], int n) {
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {   // Condition: even
            count++;
        }
    }
    
    return count;
}
```

---

### **Problem 1.4: Linear Search**

**Problem Statement:**
```
Input: arr = [3, 7, 2, 9, 1], target = 7
Output: 1 (index of 7)
```

**Intuition:**
```
Need to find element? Check each one sequentially!

Is arr[0] == 7? No
Is arr[1] == 7? Yes → Found! Return 1

If we reach end without finding: Return -1
```

**Template:**
```cpp
int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;           // Found at index i
        }
    }
    return -1;                  // Not found
}
```

**Complexity:**
- Best Case: O(1) - found at first element
- Worst Case: O(n) - found at last or not present
- Average Case: O(n)

---

## 🔑 KEY INSIGHTS FOR THIS PATTERN

```
✓ Use when: You need to process every element once
✓ Don't use: When you need multiple passes or complex conditions
✓ Best for: Finding max/min, sum, count, first occurrence
✓ Time: Always O(n)
✓ Space: Usually O(1)
✓ Memory efficient: ✅ Excellent
✓ Interview friendly: ✅ Shows clean thinking
```

---

---

# PATTERN 2: TWO POINTER TECHNIQUE
<a name="pattern-2"></a>

## 🎯 WHAT IS IT?

**Definition:** Use two pointers moving in same or opposite directions to solve problems efficiently.

**Core Concept:**
- Pointer 1 starts at start
- Pointer 2 starts at end (or start too)
- Move based on conditions
- Reduces from O(n²) to O(n)

---

## 💡 INTUITION & ABSTRACT THINKING

### **Real-World Analogy:**
```
Two-Pointer = Two People Walking from Opposite Ends

Scenario: Two friends meeting on a straight road
- Friend A starts from left, walks right
- Friend B starts from right, walks left
- They meet somewhere in middle

Array Problem: Find two elements that sum to target
- Pointer1 at start (smallest)
- Pointer2 at end (largest)
- If sum < target: move Pointer1 right (need bigger number)
- If sum > target: move Pointer2 left (need smaller number)
- If sum == target: Found!
```

### **Why This Works (The Math):**
```
Observation: Array is SORTED

For Two Sum = Target (sorted array):
[1, 3, 5, 7, 9], target = 12

Pointer1=0 (1), Pointer2=4 (9): sum=10 < 12 → move Pointer1 right
Pointer1=1 (3), Pointer2=4 (9): sum=12 = 12 → FOUND!

Why this is efficient:
- We NEVER go back
- Each pointer moves only forward (or backward)
- Total movement: 2n at most = O(n)
- Without two pointer: O(n²) comparing all pairs
```

---

## 📋 GENERIC TEMPLATE

```cpp
// ═══════════════════════════════════════════════════════════
// TEMPLATE: TWO POINTER OPPOSITE DIRECTION
// ═══════════════════════════════════════════════════════════

int left = 0, right = n - 1;

while(left < right) {
    int current_sum = arr[left] + arr[right];
    
    if(current_sum == target) {
        return {left, right};           // Found!
    }
    else if(current_sum < target) {
        left++;                         // Need larger number
    }
    else {
        right--;                        // Need smaller number
    }
}

return {-1, -1};                        // Not found

// TIME: O(n) - each pointer moves at most n times
// SPACE: O(1) - only two pointers
```

---

## 🌊 FLOW STRUCTURE

```
        START (sorted array)
             ↓
    left = 0, right = n-1
             ↓
    ┌─────────────────────┐
    │  left < right?      │
    └─────────────────────┘
        NO (pointers crossed)
         ↓
    NOT FOUND, return -1
    
        YES
         ↓
    ┌─────────────────────┐
    │ Calculate current   │
    │ sum or property     │
    └─────────────────────┘
         ↓
    ┌──────────────────────────────┐
    │ Check condition              │
    │ (sum, product, etc)          │
    └──────────────────────────────┘
         ↓
    ┌─────────────────────────────────┐
    │  Which branch?                  │
    │  Less / Equal / Greater         │
    └─────────────────────────────────┘
     /            |           \
   LESS        EQUAL       GREATER
    ↓            ↓             ↓
  left++   RETURN answer   right--
    ↓            ↓             ↓
    └────→ Loop back ←───→ Loop back
```

---

## 📚 PROBLEMS USING THIS PATTERN

### **Problem 2.1: Two Sum (in Sorted Array)**

**Problem Statement:**
```
Input: arr = [1, 3, 5, 7, 9], target = 12
Output: [1, 4] (indices of 3 and 9, which sum to 12)
```

**Intuition Breakdown:**
```
Step 1: Recognize it's sorted
  → Two pointer can work

Step 2: Why two pointer?
  → Instead of checking all pairs (O(n²))
  → We use information about sorting
  → Small numbers on left, large on right

Step 3: Logic
  If sum too small: need bigger number → move left pointer right
  If sum too large: need smaller number → move right pointer left
  If sum equals: we found it!

Step 4: Why it's efficient
  - We never look at same pair twice
  - We never go backward
  - Maximum movement: left goes 0→n, right goes n→0
  - Total: 2n = O(n)
```

**Generic Template (Specialized for this problem):**
```cpp
pair<int, int> twoSum(int arr[], int n, int target) {
    int left = 0, right = n - 1;            // Start from ends
    
    while(left < right) {                   // While not crossed
        int sum = arr[left] + arr[right];   // Calculate sum
        
        if(sum == target) {
            return {left, right};           // Found!
        }
        else if(sum < target) {
            left++;                         // Need bigger
        }
        else {
            right--;                        // Need smaller
        }
    }
    
    return {-1, -1};                        // Not found
}
```

**Detailed Dry Run:**
```
Array: [1, 3, 5, 7, 9], target = 12

Visualization:
Pointers:  L           R
Array:   [1, 3, 5, 7, 9]

ITERATION 1:
left=0, right=4
sum = 1 + 9 = 10
Is 10 == 12? No
Is 10 < 12? Yes
→ Need bigger number
→ Move left++ (1 → 3)

Pointers:     L        R
Array:   [1, 3, 5, 7, 9]

ITERATION 2:
left=1, right=4
sum = 3 + 9 = 12
Is 12 == 12? YES!
→ FOUND! Return {1, 4}
```

**Complexity Analysis:**
```
Time: O(n)
- Worst case: left starts at 0, right starts at n-1
- They meet in middle
- Total: 0 + (n-1) = n-1 = O(n)

Space: O(1)
- Only left and right pointers

Compare to brute force O(n²):
Array: [1, 3, 5, 7, 9], target = 12
Brute force: Check all pairs
- (1,3): sum=4
- (1,5): sum=6
- (1,7): sum=8
- (1,9): sum=10
- (3,5): sum=8
- (3,7): sum=10
- (3,9): sum=12 ← Found (9 comparisons)

Two pointer:
- (1,9): sum=10
- (3,9): sum=12 ← Found (2 comparisons)
```

---

### **Problem 2.2: Reverse Array In-Place**

**Problem Statement:**
```
Input: arr = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
```

**Intuition:**
```
What does reverse mean?
- First becomes last
- Second becomes second-last
- And so on...

Two pointer approach:
- Put first at start, last at end
- Swap them
- Move towards center
- Stop when pointers meet
```

**Template:**
```cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;        // Start from both ends
    
    while(left < right) {               // While not crossed
        // Swap
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;                         // Move inward
        right--;
    }
}
```

**Detailed Dry Run:**
```
Array: [1, 2, 3, 4, 5]

ITERATION 1:
left=0, right=4
arr[0]=1, arr[4]=5
Swap: [5, 2, 3, 4, 1]
left++, right--

ITERATION 2:
left=1, right=3
arr[1]=2, arr[3]=4
Swap: [5, 4, 3, 2, 1]
left++, right--

ITERATION 3:
left=2, right=2
left < right? NO
Stop

Result: [5, 4, 3, 2, 1]
```

**Complexity:** O(n) time, O(1) space (in-place!)

---

### **Problem 2.3: Container With Most Water** (More Complex)

**Problem Statement:**
```
Given n vertical lines, find two that form a container 
holding maximum water.

Input: height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
Output: 49

Visual:
  |     |
  | |   |
  | | | | |
  | | | | |
  ---------
Heights: 1, 8, 6, 2, 5, 4, 8, 3, 7

Container between indices 1 and 8:
Width = 8 - 1 = 7
Height = min(8, 7) = 7
Area = 7 × 7 = 49
```

**Intuition:**
```
Area formula: width × min_height

Key insight: If we move pointer from LONGER line inward,
width definitely decreases. Even if we find taller line,
width loss might not be compensated. But moving from SHORTER
line might find taller line, potentially increasing area.

Strategy: Always move the shorter line's pointer
```

**Template:**
```cpp
int maxArea(int height[]) {
    int left = 0, right = n - 1;
    int max_area = 0;
    
    while(left < right) {
        int current_height = min(height[left], height[right]);
        int width = right - left;
        int area = current_height * width;
        
        max_area = max(max_area, area);
        
        if(height[left] < height[right]) {
            left++;                     // Move shorter
        } else {
            right--;                    // Move shorter
        }
    }
    
    return max_area;
}
```

---

## 🔑 KEY INSIGHTS FOR THIS PATTERN

```
✓ Use when: Array is sorted, need pairs, need to skip unnecessary comparisons
✓ Variants: 
  - Opposite direction (start and end)
  - Same direction (fast/slow pointer)
  - Same position different speeds
✓ Best for: Two Sum, Reverse, Container, Triplets
✓ Time: O(n) - usually much better than brute force
✓ Space: O(1) - no extra space
✓ Interview friendly: ✅ Shows optimization skill
```

---

---

# PATTERN 3: SLIDING WINDOW
<a name="pattern-3"></a>

## 🎯 WHAT IS IT?

**Definition:** Maintain a window of elements and slide it across the array to solve problems efficiently.

**Two Types:**
1. **Fixed Window:** Size known in advance
2. **Variable Window:** Size changes based on conditions

---

## 💡 INTUITION & ABSTRACT THINKING

### **Real-World Analogy:**
```
Sliding Window = Moving Glass Pane Over Array

Scenario: You have a glass pane of width 3. Slide it over a row of blocks.
What you see inside the pane at each position is your "window".

Block row:    [1,  2,  3,  4,  5]
Window size:   |___|

Position 1:   [1,  2,  3]      sum=6
Position 2:        [2,  3,  4]  sum=9
Position 3:             [3,  4,  5] sum=12

Problem: Find maximum sum in any window of size 3
Answer: 12 (window [3,4,5])

Why sliding window is efficient:
- Don't recalculate sum from scratch each time
- Remove element going out, add element coming in
- Instead of O(n*k): becomes O(n)
```

---

## 📋 GENERIC TEMPLATE - FIXED WINDOW

```cpp
// ═══════════════════════════════════════════════════════════
// TEMPLATE: SLIDING WINDOW - FIXED SIZE
// ═══════════════════════════════════════════════════════════

int windowSum = 0;
int maxSum = 0;

// Step 1: Build initial window
for(int i = 0; i < k; i++) {
    windowSum += arr[i];
}
maxSum = windowSum;

// Step 2: Slide window
for(int i = k; i < n; i++) {
    windowSum = windowSum - arr[i-k] + arr[i];  // Remove left, add right
    maxSum = max(maxSum, windowSum);
}

return maxSum;

// TIME: O(n) - one pass for building + one pass for sliding = 2 passes
// SPACE: O(1) - only few variables
```

---

## 🌊 FLOW STRUCTURE - FIXED WINDOW

```
              START
                ↓
    Initialize window (first k elements)
                ↓
    Calculate initial sum/property
                ↓
    max_result = current window result
                ↓
    ┌──────────────────────────┐
    │  i = k to n              │
    └──────────────────────────┘
                ↓
    ┌──────────────────────────┐
    │  Slide window:           │
    │  Remove arr[i-k]         │
    │  Add arr[i]              │
    └──────────────────────────┘
                ↓
    ┌──────────────────────────┐
    │  Update result if better │
    └──────────────────────────┘
                ↓
    ┌──────────────────────────┐
    │  i == n?                 │
    └──────────────────────────┘
              YES
                ↓
          RETURN max_result
```

---

## 📚 PROBLEMS USING FIXED WINDOW

### **Problem 3.1: Maximum Sum of Subarray of Size K**

**Problem Statement:**
```
Input: arr = [1, 4, 2, 10, 2, 3, 1, 0, 20], k = 4
Output: 24 (subarray [10, 2, 3, 1, 0, 20] actually [2, 10, 2, 3] = 17, [10, 2, 3, 1] = 16, [2, 3, 1, 0] = 6, [3, 1, 0, 20] = 24)
```

**Detailed Step-by-Step:**

```
Array: [1, 4, 2, 10, 2, 3, 1, 0, 20], k = 4

STEP 1: Build initial window (first 4 elements)
Window: [1, 4, 2, 10]
Sum: 1 + 4 + 2 + 10 = 17
max_sum = 17

Visualization:
Window: |_[1, 4, 2, 10]_|
Index:   0  1  2   3

STEP 2: Slide to next position
Remove arr[0]=1, Add arr[4]=2
Window: [4, 2, 10, 2]
Sum: 17 - 1 + 2 = 18
max_sum = max(17, 18) = 18

Visualization:
Window:    |_[4, 2, 10, 2]_|
Index:      1  2   3   4

STEP 3: Slide to next position
Remove arr[1]=4, Add arr[5]=3
Window: [2, 10, 2, 3]
Sum: 18 - 4 + 3 = 17
max_sum = max(18, 17) = 18

Visualization:
Window:       |_[2, 10, 2, 3]_|
Index:         2   3   4  5

STEP 4: Slide to next position
Remove arr[2]=2, Add arr[6]=1
Window: [10, 2, 3, 1]
Sum: 17 - 2 + 1 = 16
max_sum = max(18, 16) = 18

STEP 5: Slide to next position
Remove arr[3]=10, Add arr[7]=0
Window: [2, 3, 1, 0]
Sum: 16 - 10 + 0 = 6
max_sum = max(18, 6) = 18

STEP 6: Slide to next position
Remove arr[4]=2, Add arr[8]=20
Window: [3, 1, 0, 20]
Sum: 6 - 2 + 20 = 24
max_sum = max(18, 24) = 24

FINAL ANSWER: 24
```

**Template:**
```cpp
int maxSumSubarray(int arr[], int n, int k) {
    // Step 1: Build initial window
    int windowSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    
    // Step 2: Slide window
    for(int i = k; i < n; i++) {
        windowSum = windowSum - arr[i-k] + arr[i];  // Key insight!
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

**Complexity:**
```
Time: O(n)
- Building window: O(k)
- Sliding: O(n-k)
- Total: O(k + n - k) = O(n)

Space: O(1)

Compare to brute force O(n*k):
For each of n positions, calculate sum of k elements = n*k operations
With sliding: only 2 operations per slide (remove + add) = n operations
```

---

## 📋 GENERIC TEMPLATE - VARIABLE WINDOW

```cpp
// ═══════════════════════════════════════════════════════════
// TEMPLATE: SLIDING WINDOW - VARIABLE SIZE
// ═══════════════════════════════════════════════════════════

int left = 0, right = 0;
int result = 0;

for(right = 0; right < n; right++) {
    // Add element at right pointer to window
    add_to_window(arr[right]);
    
    // Shrink window while condition is violated
    while(condition_violated()) {
        remove_from_window(arr[left]);
        left++;
    }
    
    // Update result with current valid window
    result = max(result, calculate_result());
}

return result;

// TIME: O(n) - each element visited twice (added and removed once)
// SPACE: O(1) or O(k) depending on what we track in window
```

---

## 🌊 FLOW STRUCTURE - VARIABLE WINDOW

```
              START
                ↓
    left = 0, right = 0
    result = 0
                ↓
    ┌──────────────────────────┐
    │  for right = 0 to n      │
    └──────────────────────────┘
                ↓
    ┌──────────────────────────┐
    │  Add arr[right] to       │
    │  window, expand window   │
    └──────────────────────────┘
                ↓
    ┌──────────────────────────┐
    │  While window is         │
    │  INVALID/VIOLATES        │
    │  condition:              │
    └──────────────────────────┘
                ↓
          YES: Remove arr[left]
               left++
               Loop back
                ↓
               NO
                ↓
    ┌──────────────────────────┐
    │  Window now VALID        │
    │  Update result           │
    │  Continue to next right  │
    └──────────────────────────┘
                ↓
    ┌──────────────────────────┐
    │  right == n?             │
    └──────────────────────────┘
              YES
                ↓
          RETURN result
```

---

## 📚 PROBLEMS USING VARIABLE WINDOW

### **Problem 3.2: Longest Substring Without Repeating Characters**

**Problem Statement:**
```
Input: s = "abcabcbb"
Output: 3 (substring "abc")

Input: s = "au"
Output: 2 ("au")

Input: s = "dvdf"
Output: 3 ("vdf")
```

**Intuition:**
```
Question: How to handle repeating characters?
Answer: When we see a repeat, shrink window from left until repeat is gone

Example: s = "abcabcbb"

Positions: a b c a b c b b
Index:     0 1 2 3 4 5 6 7

Expand window:
- Add 'a' at 0: window = "a", seen = {a}
- Add 'b' at 1: window = "ab", seen = {a,b}
- Add 'c' at 2: window = "abc", seen = {a,b,c}, length = 3
- Add 'a' at 3: REPEAT! 'a' already seen at index 0
  - Shrink: remove 'a' at 0: window = "bc", seen = {b,c}
  - Now add 'a': window = "bca", seen = {a,b,c}, length = 3
- Add 'b' at 4: REPEAT! 'b' already seen in window
  - Shrink: remove 'b' at 1: window = "ca", seen = {a,c}
  - Now add 'b': window = "cab", seen = {a,b,c}, length = 3
- And so on...

Maximum length seen: 3
```

**Detailed Step-by-Step:**

```
String: a b c a b c b b
Index:  0 1 2 3 4 5 6 7

STEP 1: left=0, right=0
Add 'a': seen = {'a'}, window = "a", maxLen = 1

STEP 2: left=0, right=1
Add 'b': seen = {'a','b'}, window = "ab", maxLen = 2

STEP 3: left=0, right=2
Add 'c': seen = {'a','b','c'}, window = "abc", maxLen = 3

STEP 4: left=0, right=3
Add 'a': REPEAT! 'a' last seen at index 0
SHRINK: left = 0+1 = 1
Seen now: {'b','c','a'}, window = "bca", maxLen = 3

STEP 5: left=1, right=4
Add 'b': REPEAT! 'b' last seen at index 1
SHRINK: left = 1+1 = 2
Seen now: {'c','a','b'}, window = "cab", maxLen = 3

STEP 6: left=2, right=5
Add 'c': REPEAT! 'c' last seen at index 2
SHRINK: left = 2+1 = 3
Seen now: {'a','b','c'}, window = "abc", maxLen = 3

STEP 7: left=3, right=6
Add 'b': REPEAT! 'b' last seen at index 4
SHRINK: left = 4 (remove 'a' and 'b')
Actually, last occurrence of 'b' is at 4, so left = 5
Seen now: {'c','b'}, window = "cb", but we need to add 'b'
Seen now: {'c','b'}, window = "cbb"... wait let me recalculate

Actually better approach: use lastSeen map
When we see repeat, move left to lastSeen[char] + 1
```

**Template:**
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;  // char -> last index seen
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.length(); right++) {
        char current = s[right];
        
        // If character was seen and is in current window
        if(lastSeen.count(current) && lastSeen[current] >= left) {
            // Shrink window: move left to position after last occurrence
            left = lastSeen[current] + 1;
        }
        
        // Update last seen position
        lastSeen[current] = right;
        
        // Update max length
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**Complexity:**
```
Time: O(n)
- Each character visited once in right pointer
- Each character removed at most once (by left pointer)
- Total: 2n = O(n)

Space: O(min(n, 26)) or O(1) if only lowercase English
- At most 26 characters to track
```

---

## 🔑 KEY INSIGHTS FOR THIS PATTERN

```
✓ Fixed Window: Use when window size is known and fixed
✓ Variable Window: Use when window size changes based on conditions
✓ Key Optimization: Don't recalculate from scratch, update incrementally
✓ Time Improvement: From O(n*k) to O(n)
✓ Best for: Max/min sum in window, longest substring, all subarrays
✓ Watch out: Off-by-one errors, index management
```

---

(Continuing with remaining patterns in separate sections...)

---

# PATTERN 4: PREFIX/SUFFIX SUM
<a name="pattern-4"></a>

## 🎯 WHAT IS IT?

**Definition:** Precompute cumulative sums to answer range queries in O(1) time.

**Concept:**
```
prefix[i] = sum of elements from index 0 to i
Example: arr = [1, 2, 3, 4, 5]
prefix = [1, 3, 6, 10, 15]
         (1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5)
```

---

## 💡 INTUITION

### **Real-World Analogy:**
```
Bank Account Cumulative Balance

Day 1: Deposit 100  → Balance = 100
Day 2: Deposit 200  → Balance = 300
Day 3: Withdraw 50  → Balance = 250
Day 4: Deposit 150  → Balance = 400
Day 5: Deposit 100  → Balance = 500

If asked: "How much did you earn from Day 2 to Day 4?"
Answer: Balance[Day 4] - Balance[Day 1] = 400 - 100 = 300

This is prefix sum principle!
```

---

## 📋 GENERIC TEMPLATE

```cpp
// ═══════════════════════════════════════════════════════════
// BUILD PREFIX ARRAY (O(n))
// ═══════════════════════════════════════════════════════════

vector<int> prefix(n);
prefix[0] = arr[0];

for(int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i];
}

// ═══════════════════════════════════════════════════════════
// QUERY RANGE SUM (O(1))
// ═══════════════════════════════════════════════════════════

int rangeSum(int l, int r) {
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}

// TIME: Build O(n), Query O(1)
// SPACE: O(n) for prefix array
```

---

## 📚 PROBLEMS USING THIS PATTERN

### **Problem 4.1: Range Sum Queries**

**Problem Statement:**
```
Array: [1, 3, 5, 7, 9]
Query 1: Sum from index 1 to 3 → 3 + 5 + 7 = 15
Query 2: Sum from index 0 to 4 → 1 + 3 + 5 + 7 + 9 = 25
Query 3: Sum from index 2 to 4 → 5 + 7 + 9 = 21
```

**Solution with Prefix Array:**

```cpp
// Build prefix array once
arr = [1, 3, 5, 7, 9]
prefix = [1, 4, 9, 16, 25]

// Answer queries instantly
rangeSum(1, 3) = prefix[3] - prefix[0] = 16 - 1 = 15 ✓
rangeSum(0, 4) = prefix[4] = 25 ✓
rangeSum(2, 4) = prefix[4] - prefix[1] = 25 - 4 = 21 ✓
```

---

(I'll continue with remaining patterns...)

Let me create the file now to ensure you have a complete, printable resource:
