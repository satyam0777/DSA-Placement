#  🎯 TWO POINTER TECHNIQUE - INTERVIEW READY PACKAGE (MUSCLE MEMORY EDITION)

> **"Two pointers, one solution - eliminate brute force in O(n)!"**

---

##  📖 TABLE OF CONTENTS

1. [🔍 Pattern Recognition (30 seconds)](#recognition)
2. [🎨 Three Types of Two Pointer](#types)
3. [📝 Templates (Muscle Memory)](#templates)
4. [💪 Muscle Memory Drills](#drills)
5. [🎯 Top 10 Problems with Solutions](#problems)
6. [🎤 Interview Communication Scripts](#communication)
7. [🏢 Company-Wise Questions](#companies)
8. [❌ Common Mistakes](#mistakes)
9. [📋 One-Page Printable Summary](#summary)

---

<a name="recognition"></a>
##  🔍 PATTERN RECOGNITION (Master in 30 seconds)


<a name="recognition"></a>
##  🔍 PATTERN RECOGNITION (Master in 30 seconds)

### **🎯 3-Second Recognition Test:**

**Ask yourself these 3 questions:**
1. Is array **SORTED** or can be sorted? ✅
2. Problem about **PAIRS** or **IN-PLACE** modification? ✅
3. Need **O(1) space** solution? ✅

**If 2+ answers YES → TWO POINTER PATTERN! 🎯**

---

### **🔥 Magic Keywords (Instant Recognition):**

**See these words → Think Two Pointer:**

```
╔══════════════════╦═════════════════════════════════════╗
║    KEYWORD       ║         TYPE TO USE                 ║
╠══════════════════╬═════════════════════════════════════╣
║ "Sorted array"   ║ → Opposite Direction ⬅️➡️          ║
║ "Pair with sum"  ║ → Opposite Direction ⬅️➡️          ║
║ "Remove dup..."  ║ → Same Direction ➡️➡️              ║
║ "Move zeros"     ║ → Same Direction ➡️➡️              ║
║ "Reverse"        ║ → Opposite Direction ⬅️➡️          ║
║ "Palindrome"     ║ → Opposite Direction ⬅️➡️          ║
║ "In-place"       ║ → Same Direction ➡️➡️              ║
║ "Three sum"      ║ → Fixed + Two Pointer 🎯           ║
║ "Triplets"       ║ → Fixed + Two Pointer 🎯           ║
╚══════════════════╩═════════════════════════════════════╝
```

---

### **📊 Visual Decision Tree:**

```
START: See Problem
    ↓
Q: Is array SORTED?
    ↓
YES → Q: Looking for PAIRS?
       ↓
     YES → OPPOSITE DIRECTION ⬅️➡️
       ↓
     NO → Q: In-place modification?
            ↓
          YES → SAME DIRECTION ➡️➡️

Q: Looking for TRIPLETS (3Sum)?
    ↓
YES → FIXED + TWO POINTER 🎯
```

---

##  💡 KEY INSIGHT (Read This 5 Times!)

**Why Two Pointer Works:**

```
Brute Force (Nested Loops):
for i in array:
    for j in array:
        check pair[i,j]
Time: O(n²) ❌ SLOW!

Two Pointer (Smart Elimination):
left = 0, right = n-1
while left < right:
    if found: return
    eliminate half by moving one pointer
Time: O(n) ✅ FAST!
```

**Key Concept:**
> **"Two pointers ELIMINATE possibilities, not check everything!"**

If `arr[left] + arr[right] < target` in sorted array:
- ALL pairs with `arr[left]` will be too small ❌
- Eliminate entire `arr[left]` position → `left++`
- This is why O(n) not O(n²)! ✨

---

<a name="types"></a>
##  🎨 THREE TYPES OF TWO POINTER (Memorize This!)


<a name="types"></a>
##  🎨 THREE TYPES OF TWO POINTER (Memorize This!)

### **📊 Visual Comparison:**

```
TYPE 1: OPPOSITE DIRECTION ⬅️➡️
╔════════════════════════════════════════╗
║ [1, 2, 3, 4, 5, 6, 7]                 ║
║  ↑                 ↑                   ║
║ left              right                ║
║  →                ←                    ║
║      Meet in middle                    ║
╚════════════════════════════════════════╝
Use for: Sorted arrays, Pairs, Reverse

TYPE 2: SAME DIRECTION ➡️➡️
╔════════════════════════════════════════╗
║ [1, 2, 3, 4, 5, 6, 7]                 ║
║  ↑                                     ║
║ slow (collects valid)                  ║
║  ↑                                     ║
║ fast (explores all)                    ║
║   → →                                  ║
║    Both move forward (different speed) ║
╚════════════════════════════════════════╝
Use for: Remove/Modify in-place

TYPE 3: FIXED + TWO POINTER 🎯
╔════════════════════════════════════════╗
║ [1, 2, 3, 4, 5, 6, 7]                 ║
║  ↑  ↑           ↑                      ║
║  i  left       right                   ║
║ Fix i, apply two pointer on rest       ║
╚════════════════════════════════════════╝
Use for: Triplets (3Sum, 4Sum)
```

---

### **TYPE 1: OPPOSITE DIRECTION** ⬅️➡️

**When to Use:**
- Array is **SORTED** ✅
- Looking for **PAIRS** that satisfy condition ✅
- **REVERSE** operations ✅
- **PALINDROME** check ✅

**How it Works:**
```cpp
Start: left = 0, right = n-1
Move: Towards each other based on condition
Stop: When left >= right
```

**Examples:**
- Two Sum (sorted array)
- Container With Most Water
- Trapping Rain Water
- Valid Palindrome
- Reverse Array

**Mantra:** 🎯 *"Less move left, Equal found, More move right"*

---

### **TYPE 2: SAME DIRECTION** ➡️➡️

**When to Use:**
- Need to **REMOVE** elements in-place ✅
- Need to **PARTITION** array ✅
- **MOVE** elements around (like zeros to end) ✅

**How it Works:**
```cpp
Both start at beginning: slow = 0, fast = 0
fast: Explores entire array (checks everything)
slow: Collects valid elements (basket)
Think: "fast explores, slow collects"
```

**Examples:**
- Remove Duplicates
- Move Zeros to End
- Remove Element
- Partition Array (even/odd)

**Mantra:** 🎯 *"fast explores, slow collects valid elements"*

---

### **TYPE 3: FIXED + TWO POINTER** 🎯

**When to Use:**
- Looking for **TRIPLETS** (three elements) ✅
- **3Sum**, **4Sum** problems ✅
- Fix one element, find pair in rest ✅

**How it Works:**
```cpp
Step 1: MUST sort array first!
Step 2: Fix first element with loop: for(int i = 0...)
Step 3: Apply two-pointer on rest: left = i+1, right = n-1
Step 4: Skip duplicates to avoid repeated results
```

**Examples:**
- Three Sum
- Four Sum
- Closest Three Sum

**Mantra:** 🎯 *"Sort → Fix → Two Pointer → Skip Duplicates"*

---

<a name="templates"></a>
## 📝 TEMPLATES (MUSCLE MEMORY - Write 5 Times Each!)

### **✍️ TEMPLATE A: OPPOSITE DIRECTION** ⬅️➡️

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
int left = 0, right = n - 1;

while (left < right) {  // NOT <=
    int result = arr[left] + arr[right];
    
    if (result == target) {
        // Found answer!
        return true;  // or store result
    }
    else if (result < target) {
        left++;   // Need larger value
    }
    else {
        right--;  // Need smaller value
    }
}

return false;  // Not found
```

**Use for:** Two Sum, Reverse, Palindrome, Container Water  
**Time:** O(n) | **Space:** O(1)

**Mantra:** *"Less → left++, Equal → found, More → right--"*

---

### **✍️ TEMPLATE B: SAME DIRECTION** ➡️➡️

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
int slow = 0;  // Position for next valid element

for (int fast = 0; fast < n; fast++) {
    if (condition_met(arr[fast])) {  // Should I KEEP this?
        arr[slow] = arr[fast];  // or swap(arr[slow], arr[fast])
        slow++;
    }
}

return slow;  // New length or last valid position
```

**Use for:** Remove Duplicates, Move Zeros, Remove Element  
**Time:** O(n) | **Space:** O(1)

**Mantra:** *"fast explores ALL, slow collects VALID"*

---

### **✍️ TEMPLATE C: FIXED + TWO POINTER** 🎯

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
sort(arr.begin(), arr.end());  // MUST SORT FIRST!
vector<vector<int>> result;

for (int i = 0; i < n - 2; i++) {
    // Skip duplicates for first element
    if (i > 0 && arr[i] == arr[i-1]) continue;
    
    // Apply Template A on rest
    int left = i + 1, right = n - 1;
    int target = -arr[i];  // or other calculation
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            result.push_back({arr[i], arr[left], arr[right]});
            
            // Skip duplicates
            while (left < right && arr[left] == arr[left+1]) left++;
            while (left < right && arr[right] == arr[right-1]) right--;
            
            left++;
            right--;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
}

return result;
```

**Use for:** Three Sum, Four Sum, Triplet problems  
**Time:** O(n²) | **Space:** O(1) excluding result

**Mantra:** *"Sort first! Fix i, pointer rest, skip dups"*

---

<a name="drills"></a>
## 💪 MUSCLE MEMORY DRILLS (Do These NOW!)

### **🔥 Drill 1: Write Templates Blind (15 minutes)**

**Instructions:**
1. Close this file
2. Open blank paper/editor
3. Write all 3 templates from memory
4. Check accuracy
5. **Repeat 5 times until 100% accurate!**

**Target Time:**
- Template A (Opposite): 2 minutes
- Template B (Same): 2 minutes
- Template C (Fixed): 3 minutes
- **Total: 7 minutes for all 3! 🎯**

---

### **🔥 Drill 2: Instant Recognition (10 minutes)**

**Read problem → Identify type in 3 seconds:**

```
1. "Find pair with sum k in sorted array"
   Your answer: _________________ (3 seconds)
   Correct: OPPOSITE DIRECTION ⬅️➡️

2. "Remove duplicates from sorted array in-place"
   Your answer: _________________ (3 seconds)
   Correct: SAME DIRECTION ➡️➡️

3. "Find all triplets that sum to zero"
   Your answer: _________________ (3 seconds)
   Correct: FIXED + TWO POINTER 🎯

4. "Check if string is valid palindrome"
   Your answer: _________________ (3 seconds)
   Correct: OPPOSITE DIRECTION ⬅️➡️

5. "Move all zeros to end maintaining order"
   Your answer: _________________ (3 seconds)
   Correct: SAME DIRECTION ➡️➡️
```

**Do 20 problems until instant recognition! 🚀**

---

### **🔥 Drill 3: Mantra Recitation (5 minutes)**

**Recite out loud 10 times:**

1. **Opposite:** "Less move left, Equal found, More move right" 🎯
2. **Same:** "fast explores ALL, slow collects VALID" 🎯
3. **Fixed:** "Sort → Fix → Two Pointer → Skip Duplicates" 🎯

**Until you can say them in your sleep! 😴**

---

<a name="problems"></a>
##  🎯 TOP 10 TWO POINTER PROBLEMS (Interview-Ready Solutions)

### **Problem 1: Two Sum in Sorted Array** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find if there exists a pair with sum equal to target in sorted array."

**How to Think:**
```
Step 1: "Array is sorted - hint for two pointer!"
Step 2: "One pointer at start, one at end"
Step 3: "If sum too small, move left forward"
Step 4: "If sum too large, move right backward"
Step 5: "If equal, found the pair!"
```

**Template:**
```cpp
bool twoSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(sum == target) {
            return true;  // Found!
        }
        else if(sum < target) {
            left++;  // Need larger sum
        }
        else {
            right--;  // Need smaller sum
        }
    }
    
    return false;  // No such pair
}
```

**What to Say:**
> "Sir, since array is sorted, I'll use two pointers. Start from both ends. If sum is less than target, move left forward to get larger number. If more, move right backward. Time O(n), Space O(1)."

**Dry Run:**
```
Array: [1, 3, 5, 7, 9], target = 10

left=0, right=4: 1+9=10 ✅ Found!

Array: [1, 2, 3, 4], target = 10

left=0, right=3: 1+4=5 < 10, left++
left=1, right=3: 2+4=6 < 10, left++
left=2, right=3: 3+4=7 < 10, left++
left=3, right=3: stop

Answer: false
```

**Follow-up:**
> **Interviewer:** "What if array is not sorted?"

**Your Answer:**
> "Sir, then I'd use hashing (unordered_set). Check if (target - current) exists in set. Same O(n) time but O(n) space."

---

### **Problem 2: Remove Duplicates from Sorted Array** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Remove duplicates in-place and return new length."

**How to Think:**
```
Step 1: "Need to modify in-place - two pointer pattern!"
Step 2: "Slow pointer tracks unique elements"
Step 3: "Fast pointer explores array"
Step 4: "If arr[fast] != arr[slow], it's new unique - place it"
```

**Template:**
```cpp
int removeDuplicates(vector<int>& arr) {
    if(arr.empty()) return 0;
    
    int slow = 0;  // Last unique position
    
    for(int fast = 1; fast < arr.size(); fast++) {
        if(arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    
    return slow + 1;  // New length
}
```

**What to Say:**
> "Sir, I'll use two pointers - slow and fast. Slow tracks last unique element position. Fast explores the array. When fast finds a new unique element, I place it at slow+1. Time O(n), Space O(1)."

**Dry Run:**
```
Array: [1, 1, 2, 2, 3, 4, 4]

Initial: slow=0, arr[0]=1

fast=1: arr[1]=1 == arr[0], skip
fast=2: arr[2]=2 != arr[0], slow=1, arr[1]=2 → [1,2,2,2,3,4,4]
fast=3: arr[3]=2 == arr[1], skip
fast=4: arr[4]=3 != arr[1], slow=2, arr[2]=3 → [1,2,3,2,3,4,4]
fast=5: arr[5]=4 != arr[2], slow=3, arr[3]=4 → [1,2,3,4,3,4,4]
fast=6: arr[6]=4 == arr[3], skip

New length: 4
Result: [1, 2, 3, 4]
```

---

### **Problem 3: Move Zeros to End** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Move all zeros to end while maintaining order of non-zeros."

**Template:**
```cpp
void moveZeros(vector<int>& arr) {
    int slow = 0;  // Position for next non-zero
    
    for(int fast = 0; fast < arr.size(); fast++) {
        if(arr[fast] != 0) {
            swap(arr[slow], arr[fast]);
            slow++;
        }
    }
}
```

**What to Say:**
> "Sir, I'll use two pointers. Slow tracks position for next non-zero. Fast finds non-zero elements. When found, swap with slow position. This maintains order and moves zeros to end. Time O(n), Space O(1)."

**Dry Run:**
```
Array: [0, 1, 0, 3, 12]

fast=0: arr[0]=0, skip
fast=1: arr[1]=1≠0, swap(arr[0],arr[1]), slow=1 → [1,0,0,3,12]
fast=2: arr[2]=0, skip
fast=3: arr[3]=3≠0, swap(arr[1],arr[3]), slow=2 → [1,3,0,0,12]
fast=4: arr[4]=12≠0, swap(arr[2],arr[4]), slow=3 → [1,3,12,0,0]

Final: [1, 3, 12, 0, 0]
```

---

### **Problem 4: Reverse Array/String** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Reverse array in-place."

**Template:**
```cpp
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    
    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
```

**What to Say:**
> "Sir, classic two pointer from opposite ends. Swap elements and move pointers inward. Very simple and efficient. Time O(n), Space O(1)."

---

### **Problem 5: Container With Most Water** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Given heights, find two lines that form container with maximum water."

**How to Think:**
```
Step 1: "Start with widest container (left=0, right=n-1)"
Step 2: "Area = min(height[left], height[right]) × width"
Step 3: "Move pointer with smaller height (bottleneck)"
Step 4: "Track maximum area"
```

**Template:**
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while(left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        int area = h * width;
        
        maxWater = max(maxWater, area);
        
        // Move pointer with smaller height
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxWater;
}
```

**What to Say:**
> "Sir, I start with widest container. Area depends on shorter height. So I move the pointer with smaller height, hoping to find a taller line. This greedy approach finds maximum. Time O(n)."

---

### **Problem 6: Sort Colors (Dutch National Flag)** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Array has only 0s, 1s, 2s. Sort in-place."

**Template (Three Pointer!):**
```cpp
void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {  // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
```

**What to Say:**
> "Sir, I'll use Dutch National Flag algorithm with three pointers. Low for 0s boundary, high for 2s boundary, mid to explore. When see 0, swap with low. When see 2, swap with high. When see 1, just move mid. Time O(n), Space O(1)."

---

### **Problem 7: Three Sum = 0** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find all triplets that sum to zero."

**Template:**
```cpp
vector<vector<int>> threeSum(vector<int>& arr) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());  // Sort first!
    
    for(int i = 0; i < arr.size() - 2; i++) {
        // Skip duplicates
        if(i > 0 && arr[i] == arr[i-1]) continue;
        
        // Two pointer for remaining two elements
        int left = i + 1, right = arr.size() - 1;
        int target = -arr[i];
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            
            if(sum == target) {
                result.push_back({arr[i], arr[left], arr[right]});
                
                // Skip duplicates
                while(left < right && arr[left] == arr[left+1]) left++;
                while(left < right && arr[right] == arr[right-1]) right--;
                
                left++;
                right--;
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    return result;
}
```

**What to Say:**
> "Sir, I'll fix first element, then use two pointer for remaining two. Sort array first. For each i, find two elements that sum to -arr[i]. Skip duplicates to avoid repeated triplets. Time O(n²)."

---

### **Problem 8: Valid Palindrome** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Check if string is palindrome (ignore non-alphanumeric)."

**Template:**
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    
    while(left < right) {
        // Skip non-alphanumeric
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right--;
        
        // Compare
        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
```

**What to Say:**
> "Sir, two pointers from both ends. Skip non-alphanumeric characters. Compare characters (case-insensitive). If mismatch, not palindrome. Time O(n), Space O(1)."

---

### **Problem 9: Merge Two Sorted Arrays** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Merge two sorted arrays into first array (has enough space)."

**Template:**
```cpp
void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
    int i = m - 1;      // Last element of arr1
    int j = n - 1;      // Last element of arr2
    int k = m + n - 1;  // Last position
    
    // Merge from end
    while(i >= 0 && j >= 0) {
        if(arr1[i] > arr2[j]) {
            arr1[k] = arr1[i];
            i--;
        } else {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
    
    // Copy remaining from arr2 (if any)
    while(j >= 0) {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}
```

**What to Say:**
> "Sir, I'll merge from end to avoid overwriting. Three pointers: i for arr1's last element, j for arr2's last, k for final position. Compare and place larger element at k. Time O(m+n), Space O(1)."

---

### **Problem 10: Squares of Sorted Array** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Array is sorted (can have negatives). Return squares in sorted order."

**Template:**
```cpp
vector<int> sortedSquares(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    
    int left = 0, right = n - 1;
    int pos = n - 1;  // Fill from end
    
    while(left <= right) {
        int leftSq = arr[left] * arr[left];
        int rightSq = arr[right] * arr[right];
        
        if(leftSq > rightSq) {
            result[pos] = leftSq;
            left++;
        } else {
            result[pos] = rightSq;
            right--;
        }
        pos--;
    }
    
    return result;
}
```

**What to Say:**
> "Sir, largest square will be at either end (most negative or most positive). I'll use two pointers from both ends, compare squares, place larger one at end of result. Fill result from right to left. Time O(n), Space O(n)."

---

<a name="communication"></a>
##  INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Recognizing Two Pointer**

**When you see problem, immediately say:**

> "Sir, I notice:
> 1. Array is sorted / Need in-place modification
> 2. Looking for pairs / Need to remove duplicates
> 3. This suggests two pointer technique!
> 
> Two pointer reduces time from O(n²) to O(n) - very efficient!"

---

### **Script 2: Choosing Pointer Type**

**Before coding, say:**

> "Sir, I'll use [OPPOSITE / SAME] direction pointers because:
> 
> **Opposite (left and right):** For sorted arrays, finding pairs
> **Same (slow and fast):** For in-place modifications
> 
> In this problem, [explain which and why]"

---

### **Script 3: Explaining Movement Logic**

**Always explain WHY pointers move:**

> "Sir, I move left pointer when [condition]
> I move right pointer when [condition]
> This ensures we don't miss any valid combination"

---

### **Script 4: Dry Run**

**After coding, ALWAYS trace:**

> "Sir, let me trace with example:
> Initially left=0, right=4...
> At each step, I check [condition]...
> Move pointer based on [logic]...
> Final answer: [result]"

---

<a name="companies"></a>
##  COMPANY-WISE QUESTIONS

### **TCS** ⭐⭐⭐⭐⭐
1. Two Sum (sorted array)
2. Remove Duplicates
3. Move Zeros
4. Reverse Array
5. Merge Sorted Arrays

**Frequency:** 45% of array interviews

---

### **Wipro** ⭐⭐⭐⭐
1. Two Sum variations
2. Remove Duplicates
3. Valid Palindrome
4. Sort Colors
5. Container With Most Water

**Frequency:** 35% of array interviews

---

### **Infosys** ⭐⭐⭐⭐⭐
1. Reverse Array (very common!)
2. Two Sum
3. Move Zeros
4. Remove Duplicates
5. Palindrome Check

**Frequency:** 50% of array interviews

---

### **Cognizant** ⭐⭐⭐⭐
1. Two Sum
2. Three Sum
3. Remove Duplicates
4. Sort Colors
5. Merge Arrays

**Frequency:** 40% of array interviews

---

### **Capgemini** ⭐⭐⭐
1. Reverse Array
2. Two Sum
3. Remove Duplicates
4. Move Zeros
5. Palindrome

**Frequency:** 30% of array interviews

---

### **Accenture** ⭐⭐⭐⭐⭐
1. Reverse Array
2. Two Sum (basic)
3. Move Zeros
4. Remove Duplicates
5. Palindrome Check

**Frequency:** 40% of array interviews

---

<a name="mistakes"></a>
## ❌ COMMON MISTAKES TO AVOID

### **Mistake 1: Wrong While Condition**
```cpp
// WRONG ❌
while(left <= right)  // For opposite direction with swaps

// CORRECT ✅
while(left < right)   // For opposite direction with swaps
```

**Why:** When left == right, we'd swap element with itself!

---

### **Mistake 2: Not Checking Array Sorted**
```cpp
// Always ask interviewer!
"Sir, is the array sorted?"

// If not sorted for two-sum:
// Use hashing instead of two pointer
```

---

### **Mistake 3: Forgetting to Handle Edge Cases**
```cpp
// Always check:
if(arr.empty()) return [appropriate value];
if(arr.size() == 1) return [handle single element];
```

---

### **Mistake 4: Moving Wrong Pointer**
```cpp
// In two-sum:
if(sum < target) left++;   // ✅ Need larger sum
if(sum > target) right--;  // ✅ Need smaller sum

// NOT the reverse!
```

---

## 📝 QUICK TEMPLATES

### **Template 1: Opposite Direction**
```cpp
int left = 0, right = n - 1;
while(left < right) {
    if(condition_met) {
        // Process
        left++; right--;
    } else if(need_increase) {
        left++;
    } else {
        right--;
    }
}
```

### **Template 2: Same Direction (Remove/Modify)**
```cpp
int slow = 0;
for(int fast = 0; fast < n; fast++) {
    if(should_keep) {
        arr[slow] = arr[fast];
        slow++;
    }
}
return slow;  // New length
```

### **Template 3: Three Pointer (Sort 0,1,2)**
```cpp
int low = 0, mid = 0, high = n - 1;
while(mid <= high) {
    if(arr[mid] == 0) { swap(arr[low++], arr[mid++]); }
    else if(arr[mid] == 1) { mid++; }
    else { swap(arr[mid], arr[high--]); }
}
```

---

##  LAST MINUTE CHECKLIST

### **1 Hour Before Interview:**

**☑️ Memorize:**
- [ ] Opposite direction pattern (two sum)
- [ ] Same direction pattern (remove duplicates)
- [ ] When to use which type

**☑️ Practice Saying:**
- [ ] "I'll use two pointers because..."
- [ ] "Move left when... move right when..."
- [ ] "Time O(n), Space O(1)"

**☑️ Remember:**
- [ ] Check if array is sorted
- [ ] Handle edge cases (empty, single element)
- [ ] Explain pointer movement logic
- [ ] Always do dry run


##  FINAL TIPS

### **Recognition Checklist:**
```
Sorted array? → Opposite direction
Pairs/Sum problems? → Opposite direction
Remove/Modify in-place? → Same direction
Reverse/Palindrome? → Opposite direction
```

### **Golden Rule:**
> "Two pointers work when you can eliminate possibilities from one direction based on current comparison!"


---

*Remember: Two pointer is about smart elimination, not brute force!*

**All the best** 
