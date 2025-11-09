
# 🎯 TWO POINTER TECHNIQUE - COMPLETE MASTERY GUIDE

> **"Two pointers, one solution - eliminate brute force!"**

---

## 📖 TABLE OF CONTENTS

1. [🎬 Introduction - What & Why](#introduction)
2. [🔍 Pattern Recognition - When to Use](#recognition)
3. [🎨 Three Types of Two Pointer](#types)
4. [📝 Generic Templates (Muscle Memory)](#templates)
5. [💡 Detailed Concept & Formula](#concept)
6. [🎯 Problem Examples](#examples)
7. [📋 Quick Reference Sheet](#reference)
8. [🎓 Learning Path](#learning-path)

---

<a name="introduction"></a>
## 🎬 INTRODUCTION - WHAT & WHY

### **What is Two Pointer Technique?**

The **two-pointer technique** uses **TWO indices (pointers)** to traverse a data structure (array/string) in a **coordinated way**.

```
Single Loop: i → → → → → → → (checks each element once)
                O(n)

Nested Loops: i → → → →
              j ↓ ↓ ↓ ↓  (checks all pairs)
                O(n²) ❌ SLOW!

Two Pointers: left → ← right  (smart elimination)
                O(n) ✅ FAST!
```

### **Why Use Two Pointer?**

**Problem:** Find pair with sum = target in sorted array  
**Brute Force:** Check all pairs → O(n²) ❌  
**Two Pointer:** Start from ends, eliminate half each step → O(n) ✅

**Time Complexity Reduction:**
- **From:** O(n²) nested loops ❌
- **To:** O(n) single pass ✅
- **Space:** O(1) - no extra array needed!

### **Key Insight:**

> **"Two pointers work when you can ELIMINATE possibilities from one direction based on current comparison!"**

Example: If `arr[left] + arr[right] < target` in sorted array:
- We know ALL pairs with `arr[left]` will be < target
- So we can ELIMINATE entire left position and move `left++`
- This is why it's O(n) not O(n²)!

---

<a name="recognition"></a>
## 🔍 PATTERN RECOGNITION - WHEN TO USE TWO POINTER

### **🎯 Magic Keywords (Instant Recognition)**

If you see these words in problem → Think Two Pointer:

| Keyword | Meaning | Example |
|---------|---------|---------|
| **"Sorted array"** | Array is pre-sorted | Two Sum in sorted array |
| **"Pair with sum"** | Find two elements | Pair with given sum |
| **"Remove duplicates"** | In-place modification | Remove duplicates from sorted |
| **"Move zeros"** | Rearrange elements | Move zeros to end |
| **"Reverse"** | Flip order | Reverse array/string |
| **"In-place"** | No extra space | Partition array |
| **"Two elements"** | Find pair | Two elements satisfying condition |
| **"Palindrome"** | Check symmetry | Valid palindrome |

### **🔥 3 Signs to Recognize Two Pointer Pattern:**

**Sign 1:** Array is **SORTED** or can be sorted  
**Sign 2:** Problem asks about **PAIRS** or **SUBARRAYS**  
**Sign 3:** Need to work **IN-PLACE** (O(1) space)

**If 2 out of 3 signs present → Use Two Pointer! 🎯**

### **❓ Question to Ask Yourself:**

```
"Can I start from both ends and eliminate possibilities?"
OR
"Can I use slow and fast pointer to modify in-place?"

If YES → Two Pointer Pattern!
```

---

<a name="types"></a>
## 🎨 THREE TYPES OF TWO POINTER

### **📊 Visual Comparison:**

```
TYPE 1: OPPOSITE DIRECTION ⬅️➡️
[1, 2, 3, 4, 5, 6, 7]
 ↑                 ↑
left              right
 →                ←
    Meet in middle

TYPE 2: SAME DIRECTION ➡️➡️
[1, 2, 3, 4, 5, 6, 7]
 ↑
 slow
 ↑
 fast
  → →
    Both move forward (different speeds)

TYPE 3: FIXED + TWO POINTER 🎯
[1, 2, 3, 4, 5, 6, 7]
 ↑  ↑           ↑
 i  left       right
Fix i, apply two pointer on rest
```

---

### **TYPE 1: OPPOSITE DIRECTION** ⬅️➡️

**When to Use:**
- Array is **SORTED**
- Looking for **PAIRS** that satisfy condition
- **REVERSE** operations
- **PALINDROME** check

**How it Works:**
- Start: `left = 0`, `right = n-1`
- Move pointers towards each other
- Stop when `left >= right`

**Examples:**
- Two Sum (sorted array)
- Container With Most Water
- Trapping Rain Water
- Valid Palindrome
- Reverse Array

**Mantra:** *"Less move left, Equal found, More move right"* 🎯

---

### **TYPE 2: SAME DIRECTION** ➡️➡️

**When to Use:**
- Need to **REMOVE** elements in-place
- Need to **PARTITION** array
- **MOVE** elements around (like zeros to end)

**How it Works:**
- Both start at beginning: `slow = 0`, `fast = 0`
- `fast` explores the entire array
- `slow` collects/places valid elements
- Think: **"fast explores, slow collects"**

**Examples:**
- Remove Duplicates
- Move Zeros to End
- Remove Element
- Partition Array (even/odd)

**Mantra:** *"i explores, j collects valid elements"* 🎯

---

### **TYPE 3: FIXED + TWO POINTER** 🎯

**When to Use:**
- Looking for **TRIPLETS** (three elements)
- **3Sum**, **4Sum** problems
- Fix one element, find pair in rest

**How it Works:**
- **MUST** sort array first!
- Fix first element with loop: `for(int i = 0...)`
- Apply two-pointer on rest: `left = i+1`, `right = n-1`
- Skip duplicates to avoid repeated results

**Examples:**
- Three Sum
- Four Sum
- Closest Three Sum

**Mantra:** *"Fix i, two pointer rest, skip duplicates"* 🎯

---

<a name="templates"></a>
## 📝 GENERIC TEMPLATES (MUSCLE MEMORY)

### **✍️ TEMPLATE A: OPPOSITE DIRECTION** ⬅️➡️

```cpp
// Use for: Pair Sum, Reverse, Palindrome, Container Water
int left = 0, right = n - 1;

while (left < right) {
    int result = arr[left] + arr[right];  // or other calculation
    
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

**When:** Sorted array + looking for pairs  
**Time:** O(n) | **Space:** O(1)

**Mantra:** *"Less move left, Equal found, More move right"*

---

### **✍️ TEMPLATE B: SAME DIRECTION** ➡️➡️

```cpp
// Use for: Remove Duplicates, Move Zeros, Remove Element
int slow = 0;  // Position for next valid element

for (int fast = 0; fast < n; fast++) {
    if (condition_met(arr[fast])) {
        arr[slow] = arr[fast];  // or swap(arr[slow], arr[fast])
        slow++;
    }
}

return slow;  // New length or last valid position
```

**When:** In-place removal/modification  
**Time:** O(n) | **Space:** O(1)

**Mantra:** *"fast explores, slow collects"*

---

### **✍️ TEMPLATE C: FIXED + TWO POINTER** 🎯

```cpp
// Use for: Three Sum, Four Sum
sort(arr.begin(), arr.end());  // MUST sort first!
vector<vector<int>> result;

for (int i = 0; i < n - 2; i++) {
    // Skip duplicates for first element
    if (i > 0 && arr[i] == arr[i-1]) continue;
    
    // Two pointer on rest
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

**When:** Finding triplets/quadruplets  
**Time:** O(n²) for 3Sum | **Space:** O(1) excluding result

**Mantra:** *"Sort → Fix → Two Pointer → Skip Duplicates"*

---

<a name="concept"></a>
## 💡 DETAILED CONCEPT & FORMULA

### **🔢 Core Formulas:**

**1. Opposite Direction:**
```
Initial: left = 0, right = n - 1
Condition: while (left < right)
Movement: left++ or right-- based on condition
Elements checked: n times total → O(n)
```

**2. Same Direction:**
```
Initial: slow = 0, fast = 0
Condition: while (fast < n)
Movement: fast++ always, slow++ conditionally
Valid elements collected at arr[0...slow-1]
New length: slow
```

**3. Fixed + Two Pointer:**
```
Outer loop: i = 0 to n-2 (fix element)
Inner two pointer: left = i+1, right = n-1
Time: O(n) × O(n) = O(n²)
```

### **📐 Why Two Pointer is O(n)?**

**Key Insight:**
- Each pointer moves AT MOST n times
- `left` moves: 0 → n-1 (at most n moves)
- `right` moves: n-1 → 0 (at most n moves)
- **Total moves:** left + right ≤ 2n → **O(n)** ✅

**Compare to Brute Force:**
```
Brute Force: Check all pairs
for (i = 0 to n)
    for (j = i+1 to n)
        check pair[i,j]
Total pairs: n × (n-1) / 2 = O(n²) ❌

Two Pointer: Smart elimination
Total moves: n + n = 2n = O(n) ✅
```

---

<a name="examples"></a>
## 🎯 PROBLEM EXAMPLES


<a name="examples"></a>
## 🎯 PROBLEM EXAMPLES

### **Example 1: Two Sum in Sorted Array** (Opposite Direction)

**Problem:** Find if there exists a pair with sum equal to target.

**Step-by-Step Approach:**
```cpp
bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(sum == target) {
            return true;  // Found!
        }
        else if(sum < target) {
            left++;   // Need larger sum
        }
        else {
            right--;  // Need smaller sum
        }
    }
    
    return false;
}
```

**Dry Run:**
```
Array: [1, 3, 5, 7, 9], target = 10

Step 1: left=0, right=4 → sum = 1+9 = 10 ✅ Found!

Array: [1, 2, 3, 4], target = 10

Step 1: left=0, right=3 → sum = 1+4 = 5 < 10, left++
Step 2: left=1, right=3 → sum = 2+4 = 6 < 10, left++
Step 3: left=2, right=3 → sum = 3+4 = 7 < 10, left++
Step 4: left=3, right=3 → Stop (left >= right)
Answer: false
```

**Time:** O(n) | **Space:** O(1)

---

### **Example 2: Remove Duplicates from Sorted Array** (Same Direction)

**Problem:** Remove duplicates in-place and return new length.

**Step-by-Step Approach:**
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

**Dry Run:**
```
Array: [1, 1, 2, 2, 3, 4, 4]

Initial: slow=0 (arr[0]=1)

fast=1: arr[1]=1 == arr[0], skip
fast=2: arr[2]=2 != arr[0], slow=1, arr[1]=2 → [1,2,2,2,3,4,4]
fast=3: arr[3]=2 == arr[1], skip
fast=4: arr[4]=3 != arr[1], slow=2, arr[2]=3 → [1,2,3,2,3,4,4]
fast=5: arr[5]=4 != arr[2], slow=3, arr[3]=4 → [1,2,3,4,3,4,4]
fast=6: arr[6]=4 == arr[3], skip

New length: 4
Result: [1, 2, 3, 4]
```

**Time:** O(n) | **Space:** O(1)

---

### **Example 3: Move Zeros to End** (Same Direction with Swap)

**Problem:** Move all zeros to end while maintaining order of non-zeros.

**Step-by-Step Approach:**
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

**Dry Run:**
```
Array: [0, 1, 0, 3, 12]

fast=0: arr[0]=0, skip (slow=0)
fast=1: arr[1]=1≠0, swap(arr[0],arr[1]) → [1,0,0,3,12], slow=1
fast=2: arr[2]=0, skip (slow=1)
fast=3: arr[3]=3≠0, swap(arr[1],arr[3]) → [1,3,0,0,12], slow=2
fast=4: arr[4]=12≠0, swap(arr[2],arr[4]) → [1,3,12,0,0], slow=3

Final: [1, 3, 12, 0, 0] ✅
```

**Time:** O(n) | **Space:** O(1)

---

### **Example 4: Reverse Array** (Opposite Direction)

**Problem:** Reverse array in-place.

**Step-by-Step Approach:**
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

**Dry Run:**
```
Array: [1, 2, 3, 4, 5]

Step 1: swap(arr[0], arr[4]) → [5, 2, 3, 4, 1]
Step 2: swap(arr[1], arr[3]) → [5, 4, 3, 2, 1]
Step 3: left=2, right=2 → Stop

Final: [5, 4, 3, 2, 1] ✅
```

**Time:** O(n) | **Space:** O(1)

---

### **Example 5: Three Sum = 0** (Fixed + Two Pointer)

**Problem:** Find all triplets that sum to zero.

**Step-by-Step Approach:**
```cpp
vector<vector<int>> threeSum(vector<int>& arr) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());  // MUST sort!
    
    for(int i = 0; i < arr.size() - 2; i++) {
        // Skip duplicates for first element
        if(i > 0 && arr[i] == arr[i-1]) continue;
        
        // Two pointer on rest
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

**Dry Run:**
```
Array: [-1, 0, 1, 2, -1, -4]
After sort: [-4, -1, -1, 0, 1, 2]

i=0 (arr[0]=-4), target=4:
  left=1, right=5: -1+2=1<4, left++
  left=2, right=5: -1+2=1<4, left++
  left=3, right=5: 0+2=2<4, left++
  left=4, right=5: 1+2=3<4, left++
  left=5, right=5: Stop

i=1 (arr[1]=-1), target=1:
  left=2, right=5: -1+2=1✅ Found: [-1,-1,2]
  Skip duplicates: left=3
  left=3, right=4: 0+1=1✅ Found: [-1,0,1]
  left++, right--: left=4, right=3, Stop

i=2: arr[2]==-1 (duplicate), skip

Result: [[-1,-1,2], [-1,0,1]]
```

**Time:** O(n²) | **Space:** O(1) excluding result

---

<a name="reference"></a>
## 📋 QUICK REFERENCE SHEET

### **🔥 Pattern Recognition (30 seconds):**

```
✅ Sorted Array? → Opposite Direction
✅ Pairs/Sum? → Opposite Direction
✅ Remove/Modify In-Place? → Same Direction
✅ Reverse/Palindrome? → Opposite Direction
✅ Triplets (3Sum)? → Fixed + Two Pointer
```

---

### **📝 Three Generic Templates:**

**Template A: Opposite Direction** ⬅️➡️
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (result == target) return true;
    else if (result < target) left++;
    else right--;
}
```

**Template B: Same Direction** ➡️➡️
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (valid(arr[fast])) {
        arr[slow] = arr[fast];
        slow++;
    }
}
return slow;
```

**Template C: Fixed + Two Pointer** 🎯
```cpp
sort(arr);
for (int i = 0; i < n-2; i++) {
    if (i > 0 && arr[i] == arr[i-1]) continue;
    int left = i+1, right = n-1;
    // Apply Template A on rest
}
```

---

### **⏱️ Time Complexity:**

| Type | Complexity | Why |
|------|-----------|-----|
| Opposite Direction | O(n) | Each pointer moves n times max |
| Same Direction | O(n) | Single pass with two pointers |
| Fixed + Two Pointer | O(n²) | Outer loop O(n) × Inner O(n) |

---

### **🎯 Common Mistakes to Avoid:**

❌ `while (left <= right)` for opposite (swap issue)  
✅ `while (left < right)` 

❌ Forget to sort for 3Sum  
✅ Always `sort()` before Fixed + Two Pointer

❌ Not skipping duplicates in 3Sum  
✅ Skip with `if (i>0 && arr[i]==arr[i-1]) continue;`

❌ Wrong pointer movement direction  
✅ Less → left++, More → right--

---

<a name="learning-path"></a>
## 🎓 LEARNING PATH (5-Day Plan)

### **Day 1: Opposite Direction Master** ⬅️➡️
- ✅ Two Sum in Sorted Array
- ✅ Reverse Array/String
- ✅ Valid Palindrome
- **Practice:** 5 problems, write template 3 times

### **Day 2: Same Direction Master** ➡️➡️
- ✅ Remove Duplicates
- ✅ Move Zeros
- ✅ Remove Element
- **Practice:** 5 problems, write template 3 times

### **Day 3: Mixed Practice**
- ✅ Container With Most Water
- ✅ Squares of Sorted Array
- ✅ Merge Sorted Arrays
- **Practice:** 7 problems mixing both types

### **Day 4: Fixed + Two Pointer** 🎯
- ✅ Three Sum
- ✅ Four Sum
- ✅ Closest Three Sum
- **Practice:** 3 3Sum variations

### **Day 5: Speed & Accuracy**
- ⏱️ Solve each problem in 5-7 minutes
- ✅ Write templates from memory
- ✅ Explain approach out loud
- **Target:** 90% accuracy in 7 minutes

---

## 🎯 MUSCLE MEMORY DRILLS

### **Drill 1: Write Templates Blind (2 minutes each)**

**Close your eyes and write:**
1. Opposite Direction template
2. Same Direction template
3. Fixed + Two Pointer template

**Repeat 5 times until automatic!**

---

### **Drill 2: Instant Recognition (30 seconds)**

Read problem → Identify type in 3 seconds:

```
"Find pair with sum k in sorted array"
→ OPPOSITE DIRECTION ✅ (3 seconds)

"Remove duplicates in-place"
→ SAME DIRECTION ✅ (3 seconds)

"Find all triplets summing to zero"
→ FIXED + TWO POINTER ✅ (3 seconds)
```

---

### **Drill 3: Mantra Recitation**

Recite 5 times:

1. **Opposite:** "Less move left, Equal found, More move right"
2. **Same:** "fast explores, slow collects"
3. **Fixed:** "Sort → Fix → Two Pointer → Skip Duplicates"

---

## 💡 MEMORY HOOKS

### **Hook 1: The Dance Floor 🕺💃**

**Opposite Direction** = Two people dancing from opposite ends, meeting in middle  
**Same Direction** = One person exploring, other collecting items following behind

### **Hook 2: The Library Shelf 📚**

**Opposite Direction** = Searching from both ends of shelf  
**Same Direction** = Organizing books, slow pointer is "organized section", fast is "exploring section"

### **Hook 3: The Target Practice 🎯**

**Opposite Direction** = Adjusting aim (too low? aim higher, too high? aim lower)  
**Same/Fixed** = Collecting valid targets while exploring the range

---

## 📊 COMPLEXITY ANALYSIS

### **Why Two Pointer is O(n)?**

```
Proof:
- left moves: 0 → n-1 (at most n moves)
- right moves: n-1 → 0 (at most n moves)
- Total moves: n + n = 2n
- Big O: O(2n) = O(n) ✅

Compare to brute force:
- Nested loops: O(n²)
- Improvement: n² / n = n times faster!
```

---

## ✅ INTERVIEW CHECKLIST

**Before Coding:**
- [ ] Recognize pattern (sorted? pairs? in-place?)
- [ ] Choose correct type (opposite/same/fixed)
- [ ] Explain why two pointer (O(n) advantage)

**While Coding:**
- [ ] Write correct template
- [ ] Handle edge cases (empty, single element)
- [ ] Correct pointer movement logic

**After Coding:**
- [ ] Dry run with example
- [ ] State time/space complexity
- [ ] Mention sorted array requirement (if applicable)

---

## 🎤 INTERVIEW SCRIPT

**Recognition Phase:**
> "Sir, I notice the array is sorted and we're looking for pairs. This suggests two pointer technique, which reduces time from O(n²) to O(n)."

**Choosing Type:**
> "I'll use opposite direction pointers - starting from both ends. When sum is less than target, I move left forward. When more, I move right backward. This eliminates half the possibilities at each step."

**Complexity:**
> "Time complexity is O(n) since each pointer moves at most n times. Space is O(1) as we only use two pointers."

---

## 🔥 FINAL WISDOM

### **Golden Rules:**

1. **"If sorted + pairs → Think Two Pointer first!"**
2. **"Opposite for pairs, Same for in-place, Fixed for triplets"**
3. **"Always explain WHY pointers move (elimination logic)"**
4. **"Dry run to catch off-by-one errors"**
5. **"Two pointer eliminates, not checks everything"**

### **Success Formula:**

```
Recognition (3 sec) + 
Correct Template (2 min) + 
Clean Code (3 min) + 
Dry Run (2 min) = 
7-minute perfect solution ✅
```

---

## 📚 ADDITIONAL PROBLEMS FOR PRACTICE

### **Opposite Direction:** ⬅️➡️
1. Two Sum II (sorted) - LeetCode 167
2. Container With Most Water - LeetCode 11
3. Trapping Rain Water - LeetCode 42
4. Valid Palindrome - LeetCode 125
5. Squares of Sorted Array - LeetCode 977

### **Same Direction:** ➡️➡️
6. Remove Duplicates - LeetCode 26
7. Move Zeros - LeetCode 283
8. Remove Element - LeetCode 27
9. Partition Array (Even/Odd)
10. Dutch National Flag (Sort Colors) - LeetCode 75

### **Fixed + Two Pointer:** 🎯
11. Three Sum - LeetCode 15
12. Three Sum Closest - LeetCode 16
13. Four Sum - LeetCode 18
14. Three Sum Smaller - LeetCode 259

---

## 🎯 ONE-PAGE PRINTABLE SUMMARY

```
╔════════════════════════════════════════════════════════════════╗
║           TWO POINTER TECHNIQUE - CHEAT SHEET                  ║
╚════════════════════════════════════════════════════════════════╝

📌 RECOGNITION (3 Signs):
   ✅ Sorted Array / Can Sort
   ✅ Pairs / Subarrays
   ✅ In-Place (O(1) space)

📌 THREE TYPES:

   TYPE 1: OPPOSITE ⬅️➡️
   When: Sorted + Pairs
   Code: left=0, right=n-1; while(left<right)
   Examples: Two Sum, Palindrome, Reverse

   TYPE 2: SAME ➡️➡️
   When: In-place Remove/Modify
   Code: slow=0; for(fast=0...)
   Examples: Remove Duplicates, Move Zeros

   TYPE 3: FIXED 🎯
   When: Triplets (3Sum)
   Code: sort; for(i) { two-pointer on rest }
   Examples: 3Sum, 4Sum

📌 TEMPLATES:

   A: Opposite
   ────────────
   int left=0, right=n-1;
   while(left < right) {
       if(found) return;
       else if(less) left++;
       else right--;
   }

   B: Same
   ────────────
   int slow=0;
   for(int fast=0; fast<n; fast++) {
       if(valid) arr[slow++] = arr[fast];
   }

   C: Fixed
   ────────────
   sort(arr);
   for(int i=0; i<n-2; i++) {
       skip duplicates;
       left=i+1, right=n-1;
       // Template A
   }

📌 MANTRAS:
   • "Less move left, Equal found, More move right"
   • "fast explores, slow collects"
   • "Sort → Fix → Two Pointer → Skip Duplicates"

📌 COMPLEXITY:
   Opposite/Same: O(n) time, O(1) space
   Fixed: O(n²) time, O(1) space

📌 COMMON MISTAKES:
   ❌ while(left <= right) → ✅ while(left < right)
   ❌ Forget to sort for 3Sum
   ❌ Wrong pointer movement

📌 DECISION TREE:
   Sorted? → YES → Pairs? → YES → Opposite
                        ↓
                        NO → In-place? → YES → Same
   
   Triplets? → YES → Fixed + Two Pointer

📌 TOP 5 PROBLEMS:
   1. Two Sum (sorted) - 5 min
   2. Remove Duplicates - 3 min
   3. Move Zeros - 4 min
   4. Valid Palindrome - 5 min
   5. Three Sum - 10 min

╔════════════════════════════════════════════════════════════════╗
║  "Two pointers eliminate possibilities, not check everything!" ║
╚════════════════════════════════════════════════════════════════╝
```

---

**🎯 Remember:** Two pointer is about **SMART ELIMINATION**, not brute force checking!

**All the best! 🚀**

---
