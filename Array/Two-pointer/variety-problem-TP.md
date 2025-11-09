#  TWO POINTER TECHNIQUE - COMPLETE SERIES


---

## 📋 TABLE OF CONTENTS

1. [🎓 Introduction - What is Two Pointer?](#introduction)
2. [🔍 Identification - How to Recognize?](#identification)
3. [🎯 Types of Two Pointer](#types)
4. [🔥 Generic Templates](#templates)
5. [📝 Problems with 5-Step Method](#problems)
6. [📄 One-Page Printable Summary](#summary)

---

<a name="introduction"></a>
## 🎓 VIDEO 1: INTRODUCTION - WHAT IS TWO POINTER?

### **Why Two Pointer?**

**Problem:** Find pair with sum = target in sorted array

**❌ Brute Force (O(n²)):**
```cpp
for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        if(arr[i] + arr[j] == target) return true;
    }
}
```

**✅ Two Pointer (O(n)):**
```cpp
int left = 0, right = n-1;
while(left < right) {
    int sum = arr[left] + arr[right];
    if(sum == target) return true;
    else if(sum < target) left++;
    else right--;
}
```

**Optimization:** O(n²) → O(n) 🔥

---

### **What is Two Pointer Technique?**

```
┌─────────────────────────────────────────────────────┐
│  TWO POINTER = Using 2 pointers to solve problem   │
│                in SINGLE PASS (O(n))                │
│                                                     │
│  Instead of nested loops (O(n²))                   │
│  Use smart pointer movement (O(n))                 │
└─────────────────────────────────────────────────────┘
```

**Core Idea:**
- Start with 2 pointers (usually `left` and `right`)
- Move them based on **condition**
- Single pass through array
- Much faster than brute force!

---

<a name="identification"></a>
## 🔍 VIDEO 2: IDENTIFICATION - HOW TO RECOGNIZE TWO POINTER?

### **🎯 3 Signs to Identify Two Pointer:**

```
┌──────────────────────────────────────────────────────┐
│  1. ✅ Is it an ARRAY or STRING?                     │
│  2. ✅ Need to find PAIR, TRIPLET, or PARTITION?     │
│  3. ✅ Array is SORTED or needs BOTH ENDS?           │
│                                                       │
│  ALL 3 YES? → TWO POINTER! 🎯                        │
└──────────────────────────────────────────────────────┘
```

### **🔑 Magic Keywords:**

| Keyword | Two Pointer Type |
|---------|------------------|
| "**pair sum**" | Opposite Direction |
| "**sorted array**" | Opposite Direction |
| "**remove duplicates**" | Same Direction |
| "**partition**" | Opposite Direction |
| "**triplet**" | Fixed + Two Pointer |
| "**container/water**" | Opposite Direction |
| "**palindrome**" | Opposite Direction |

---

<a name="types"></a>
## 🎯 VIDEO 3: TYPES OF TWO POINTER

### **Type 1: OPPOSITE DIRECTION** ⬅️➡️

**When:** Array is sorted OR need both ends

```
[1, 2, 3, 4, 5, 6, 7]
 ↑                 ↑
left            right

Move based on condition
```

**Examples:**
- Pair sum in sorted array
- Container with most water
- Trapping rain water
- Reverse array
- Valid palindrome

---

### **Type 2: SAME DIRECTION** ➡️➡️

**When:** Remove/partition elements in-place

```
[0, 1, 0, 3, 12]
 ↑
 i
 ↑
 j

i moves fast, j moves when condition met
```

**Examples:**
- Remove duplicates
- Move zeros to end
- Partition array (even/odd)
- Remove element

---

### **Type 3: FIXED + TWO POINTER** 🎯⬅️➡️

**When:** Need to find triplet or k-sum

```
Fix one element, use two pointer on rest

[1, 2, 3, 4, 5, 6]
 ↑  ↑           ↑
 i  left      right

For each i, apply two pointer on [i+1...n-1]
```

**Examples:**
- 3Sum problem
- 4Sum problem
- Closest triplet sum

---

<a name="templates"></a>
## 🔥 GENERIC TEMPLATES

### **Template A: OPPOSITE DIRECTION (Sorted Array)**

```cpp
// =============================================
// OPPOSITE DIRECTION - MASTER TEMPLATE
// Use when: Sorted array, pair sum, partition
// =============================================

int left = 0, right = n - 1;

while (left < right) {
    // CALCULATION
    int result = calculate(arr[left], arr[right]);
    
    // THREE CONDITIONS
    if (result < target) {
        left++;      // Need bigger value
    }
    else if (result == target) {
        // Found answer!
        return true; // or store result
    }
    else {
        right--;     // Need smaller value
    }
}

return false; // or default answer
```

**Mantra:** "**Less move left, Equal found, More move right**"

---

### **Template B: SAME DIRECTION (In-Place Modification)**

```cpp
// =============================================
// SAME DIRECTION - MASTER TEMPLATE
// Use when: Remove/partition in-place
// =============================================

int i = 0, j = 0;  // or j = -1 depending on problem

while (i < n) {
    // CHECK CONDITION
    if (condition_met(arr[i])) {
        // Place arr[i] at position j
        arr[j] = arr[i];  // or swap(arr[i], arr[j])
        j++;
    }
    i++;
}

return j;  // j is new length or partition point
```

**Mantra:** "**i explores, j collects valid elements**"

---

### **🎯 Understanding `condition_met(arr[i])`**

**What is it?**  
The CHECK that decides if element `arr[i]` should be KEPT/COLLECTED by pointer `j`

**Mental Model:** Think of **`j` as a BASKET** collecting valid elements

```
i explores the entire array (fast pointer - checks everything)
j collects only valid elements (slow pointer - basket)

[3, 0, 1, 0, 2, 0, 4]
 ↑
 j (basket - collecting non-zeros)
 ↑
 i (explorer - checking each element)

i: "Is arr[i]=3 valid (non-zero)?" → YES → Put in basket j
i: "Is arr[i]=0 valid?" → NO → Skip, don't put in basket
i: "Is arr[i]=1 valid?" → YES → Put in basket j
```

**Pattern:**
```cpp
if (condition_met(arr[i])) {
    // YES → Keep this element
    arr[j] = arr[i];  // or swap(arr[i], arr[j])
    j++;              // Move basket forward
}
// NO → Skip, only i moves
i++;  // Explorer always moves
```

---

### **📝 Examples from Real Problems:**

**Problem 1: Remove Duplicates**
```cpp
if (condition_met(arr[i]))
// translates to:
if (arr[i] != arr[j-1])  // Is this element DIFFERENT from last kept?
```
**Meaning:** Keep element if it's NOT a duplicate

---

**Problem 2: Move Zeros to End**
```cpp
if (condition_met(arr[i]))
// translates to:
if (arr[i] != 0)  // Is this element NON-ZERO?
```
**Meaning:** Keep (swap) element if it's NOT zero

---

**Problem 3: Remove Element (Value = val)**
```cpp
if (condition_met(arr[i]))
// translates to:
if (arr[i] != val)  // Is this element NOT equal to val?
```
**Meaning:** Keep element if it's not the target value

---

**Problem 4: Keep Only Even Numbers**
```cpp
if (condition_met(arr[i]))
// translates to:
if (arr[i] % 2 == 0)  // Is this element EVEN?
```
**Meaning:** Keep element if it's even

---

**Problem 5: Keep Only Positive Numbers**
```cpp
if (condition_met(arr[i]))
// translates to:
if (arr[i] > 0)  // Is this element POSITIVE?
```
**Meaning:** Keep element if it's positive

---

### **🔥 Common Conditions Reference:**

| Problem | `condition_met(arr[i])` | Meaning |
|---------|------------------------|---------|
| Remove Duplicates | `arr[i] != arr[j-1]` | Not a duplicate |
| Move Zeros | `arr[i] != 0` | Not zero |
| Remove Element `val` | `arr[i] != val` | Not target value |
| Keep Only Even | `arr[i] % 2 == 0` | Is even |
| Keep Only Odd | `arr[i] % 2 == 1` | Is odd |
| Keep Positive | `arr[i] > 0` | Is positive |
| Keep Negative | `arr[i] < 0` | Is negative |
| Remove Vowels | `!isVowel(arr[i])` | Not a vowel |
| Keep Alphabetic | `isalpha(arr[i])` | Is letter |
| Keep Digits | `isdigit(arr[i])` | Is digit |

---

### **💡 Key Insight:**

**`condition_met` = "Should I KEEP this element in the result?"**

- If **YES** → Place at `arr[j]` (or swap), move `j++`
- If **NO** → Skip it, only move `i++`

**The template stays SAME, only the condition changes!** 🎯

This is why it's called a **GENERIC TEMPLATE** - works for ALL same-direction problems!

---

### **Template C: FIXED + TWO POINTER (K-Sum)**

```cpp
// =============================================
// FIXED + TWO POINTER TEMPLATE
// Use when: 3Sum, 4Sum, k-Sum problems
// =============================================

sort(arr.begin(), arr.end());  // MUST sort first!

for (int i = 0; i < n; i++) {
    // Skip duplicates
    if (i > 0 && arr[i] == arr[i-1]) continue;
    
    // Apply two pointer on remaining array
    int left = i + 1, right = n - 1;
    
    while (left < right) {
        int sum = arr[i] + arr[left] + arr[right];
        
        if (sum < target) {
            left++;
        }
        else if (sum == target) {
            // Store result
            result.push_back({arr[i], arr[left], arr[right]});
            
            // Skip duplicates
            while (left < right && arr[left] == arr[left+1]) left++;
            while (left < right && arr[right] == arr[right-1]) right--;
            
            left++;
            right--;
        }
        else {
            right--;
        }
    }
}
```

**Mantra:** "**Fix i, two pointer on rest, skip duplicates**"

---

<a name="problems"></a>
## 📝 PROBLEMS WITH 5-STEP METHOD

---

## 📝 PROBLEM 1: Two Sum II (Sorted Array)

### **1. PROBLEM STATEMENT**

Find two numbers in **sorted array** such that they add up to target.

**Input:** `arr = [2, 7, 11, 15]`, `target = 9`  
**Output:** `[0, 1]` (indices)  
**Explanation:** arr[0] + arr[1] = 2 + 7 = 9

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Find pair** → Two Pointer hint  
✅ **Sorted array** → Perfect for Two Pointer!

**Type:** OPPOSITE DIRECTION ⬅️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Array is SORTED → Use opposite direction pointers

If sum < target → Need BIGGER value → Move left++
If sum == target → Found answer! → Return
If sum > target → Need SMALLER value → Move right--

Why this works?
- Array sorted, so left has smaller, right has bigger
- Can eliminate half elements in each step
- O(n) instead of O(n²)
```

---

### **4. DRY RUN**

```
arr = [2, 7, 11, 15], target = 9

left=0, right=3:
  arr[0] + arr[3] = 2 + 15 = 17 > 9
  → Move right-- (need smaller)

left=0, right=2:
  arr[0] + arr[2] = 2 + 11 = 13 > 9
  → Move right--

left=0, right=1:
  arr[0] + arr[1] = 2 + 7 = 9 == 9
  → Found! Return [0, 1]

Answer: [0, 1] ✓
```

---

### **5. CODE**

```cpp
vector<int> twoSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum < target) {
            left++;       // Need bigger
        }
        else if (sum == target) {
            return {left, right};  // Found!
        }
        else {
            right--;      // Need smaller
        }
    }
    
    return {-1, -1};  // Not found
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 2: Remove Duplicates from Sorted Array

### **1. PROBLEM STATEMENT**

Remove duplicates **in-place** such that each element appears only once.

**Input:** `arr = [1, 1, 2, 2, 3]`  
**Output:** `3` (new length)  
**Modified Array:** `[1, 2, 3, _, _]`

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Remove/partition in-place** → Two Pointer hint  
✅ **Sorted array** → Same direction works!

**Type:** SAME DIRECTION ➡️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Use two pointers: i (explorer), j (collector)

j tracks position for next unique element
i traverses entire array

If arr[i] != arr[j-1] → New unique element!
  → Place at arr[j], increment j

Why this works?
- Array sorted, duplicates are together
- j builds result in-place
- i explores, j only moves when unique found
```

---

### **4. DRY RUN**

```
arr = [1, 1, 2, 2, 3]

j=1 (arr[0]=1 already in place)

i=1: arr[1]=1 == arr[0]=1 → Skip
i=2: arr[2]=2 != arr[0]=1 → arr[j=1]=2, j=2
i=3: arr[3]=2 == arr[1]=2 → Skip  
i=4: arr[4]=3 != arr[1]=2 → arr[j=2]=3, j=3

Final: [1, 2, 3, 2, 3]
        ↑  ↑  ↑
       j=0 1  2 → length=3 ✓
```

---

### **5. CODE**

```cpp
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    
    int j = 1;  // First element always unique
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[j-1]) {
            arr[j] = arr[i];
            j++;
        }
    }
    
    return j;  // New length
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 3: Move Zeros to End

### **1. PROBLEM STATEMENT**

Move all zeros to end while maintaining relative order of non-zeros.

**Input:** `arr = [0, 1, 0, 3, 12]`  
**Output:** `[1, 3, 12, 0, 0]`

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Partition/rearrange in-place** → Two Pointer!  
✅ **Maintain order** → Same direction

**Type:** SAME DIRECTION ➡️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Use j to track position for next non-zero

If arr[i] != 0 → Swap with arr[j], move j

Why swap instead of assign?
- Maintains relative order
- Automatically pushes zeros to end
- Works in single pass
```

---

### **4. DRY RUN**

```
arr = [0, 1, 0, 3, 12]

j=0 (position for next non-zero)

i=0: arr[0]=0 → Skip (zero)
i=1: arr[1]=1 → Swap(arr[1], arr[0]), j=1
     arr = [1, 0, 0, 3, 12]
i=2: arr[2]=0 → Skip
i=3: arr[3]=3 → Swap(arr[3], arr[1]), j=2
     arr = [1, 3, 0, 0, 12]
i=4: arr[4]=12 → Swap(arr[4], arr[2]), j=3
     arr = [1, 3, 12, 0, 0]

Answer: [1, 3, 12, 0, 0] ✓
```

---

### **5. CODE**

```cpp
void moveZeroes(vector<int>& arr) {
    int j = 0;  // Position for next non-zero
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 4: Container With Most Water

### **1. PROBLEM STATEMENT**

Find two lines that together with x-axis form container with maximum water.

**Input:** `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`  
**Output:** `49`  
**Explanation:** Max area between index 1 (height=8) and index 8 (height=7)

```
Area = min(height[left], height[right]) × (right - left)
```

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Find maximum from both ends** → Two Pointer!  
✅ **Need to check all possible containers** → Opposite direction

**Type:** OPPOSITE DIRECTION ⬅️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Start with widest container (left=0, right=n-1)
Area = min(height[left], height[right]) × width

Key Insight:
- Width decreases as we move pointers
- To get larger area, need TALLER height
- Move pointer with SMALLER height inward
  (because keeping shorter one won't help)

Why move shorter pointer?
- Shorter height limits the area
- Moving taller pointer only decreases width
- Moving shorter pointer might find taller line
```

---

### **4. DRY RUN**

```
height = [1, 8, 6, 2, 5, 4, 8, 3, 7]

left=0, right=8:
  area = min(1, 7) × 8 = 1 × 8 = 8
  height[0]=1 < height[8]=7 → Move left++ (shorter)

left=1, right=8:
  area = min(8, 7) × 7 = 7 × 7 = 49
  maxArea = 49
  height[1]=8 > height[8]=7 → Move right-- (shorter)

left=1, right=7:
  area = min(8, 3) × 6 = 3 × 6 = 18
  height[1]=8 > height[7]=3 → Move right--

left=1, right=6:
  area = min(8, 8) × 5 = 8 × 5 = 40
  height[1]=8 == height[6]=8 → Move either

... continue until left >= right

Answer: 49 ✓
```

---

### **5. CODE**

```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    
    while (left < right) {
        // Calculate current area
        int width = right - left;
        int minHeight = min(height[left], height[right]);
        int area = minHeight * width;
        
        maxArea = max(maxArea, area);
        
        // Move pointer with shorter height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return maxArea;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 5: Three Sum (Find Triplets)

### **1. PROBLEM STATEMENT**

Find all **unique** triplets that sum to zero.

**Input:** `arr = [-1, 0, 1, 2, -1, -4]`  
**Output:** `[[-1, -1, 2], [-1, 0, 1]]`  
**Explanation:** Both triplets sum to 0

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Find triplets** → Fixed + Two Pointer!  
✅ **Need unique triplets** → Skip duplicates

**Type:** FIXED + TWO POINTER 🎯⬅️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
MUST sort array first!

For each element arr[i]:
  - Fix arr[i]
  - Find two elements in arr[i+1...n-1] with sum = -arr[i]
  - Use two pointer on remaining array

Skip duplicates:
  - Skip duplicate i values
  - Skip duplicate left values
  - Skip duplicate right values

Why sort?
- Two pointer works on sorted array
- Easy to skip duplicates
- Can optimize with early termination
```

---

### **4. DRY RUN**

```
arr = [-1, 0, 1, 2, -1, -4]
After sort: [-4, -1, -1, 0, 1, 2]

i=0: arr[0]=-4, target=4
  left=1, right=5: -1+2=1 < 4 → left++
  left=2, right=5: -1+2=1 < 4 → left++
  left=3, right=5: 0+2=2 < 4 → left++
  left=4, right=5: 1+2=3 < 4 → left++
  No triplet found

i=1: arr[1]=-1, target=1
  left=2, right=5: -1+2=1 == 1 ✓
  Found: [-1, -1, 2]
  Skip duplicate left: arr[2]=arr[3]=-1
  left=3, right=4: 0+1=1 == 1 ✓
  Found: [-1, 0, 1]

i=2: arr[2]=-1 == arr[1]=-1 → Skip duplicate i

i=3: arr[3]=0, target=0
  left=4, right=5: 1+2=3 > 0 → right--
  left >= right → Stop

Answer: [[-1, -1, 2], [-1, 0, 1]] ✓
```

---

### **5. CODE**

```cpp
vector<vector<int>> threeSum(vector<int>& arr) {
    sort(arr.begin(), arr.end());  // MUST sort!
    vector<vector<int>> result;
    
    for (int i = 0; i < arr.size(); i++) {
        // Skip duplicate i
        if (i > 0 && arr[i] == arr[i-1]) continue;
        
        // Two pointer on remaining array
        int left = i + 1, right = arr.size() - 1;
        int target = -arr[i];
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            if (sum < target) {
                left++;
            }
            else if (sum == target) {
                // Found triplet!
                result.push_back({arr[i], arr[left], arr[right]});
                
                // Skip duplicate left
                while (left < right && arr[left] == arr[left+1]) {
                    left++;
                }
                // Skip duplicate right
                while (left < right && arr[right] == arr[right-1]) {
                    right--;
                }
                
                left++;
                right--;
            }
            else {
                right--;
            }
        }
    }
    
    return result;
}
```

**Time:** O(n²) | **Space:** O(1)

---

## 📝 PROBLEM 6: Trapping Rain Water

### **1. PROBLEM STATEMENT**

Calculate how much water can be trapped after raining.

**Input:** `height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]`  
**Output:** `6`

```
Water at position i = min(leftMax, rightMax) - height[i]
```

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Need max from both sides** → Two Pointer!  
✅ **Process from both ends** → Opposite direction

**Type:** OPPOSITE DIRECTION ⬅️➡️ (Advanced)

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Water at each position depends on:
  - Highest bar on LEFT (leftMax)
  - Highest bar on RIGHT (rightMax)
  - Water trapped = min(leftMax, rightMax) - height[i]

Two Pointer Optimization:
  - Track leftMax from left side
  - Track rightMax from right side
  - Move pointer with SMALLER max
  - Add water at that position

Why move smaller max pointer?
  - Water limited by smaller of leftMax, rightMax
  - If leftMax < rightMax, left position determined
  - Can safely calculate water at left
```

---

### **4. DRY RUN**

```
height = [0, 1, 0, 2, 1, 0, 1, 3]

left=0, right=7, leftMax=0, rightMax=0, water=0

left=0, right=7:
  height[0]=0 < height[7]=3 → Process left
  leftMax = max(0, 0) = 0
  water += 0 - 0 = 0
  left++

left=1, right=7:
  height[1]=1 < height[7]=3 → Process left
  leftMax = max(0, 1) = 1
  water += 1 - 1 = 0
  left++

left=2, right=7:
  height[2]=0 < height[7]=3 → Process left
  leftMax = max(1, 0) = 1
  water += 1 - 0 = 1 ✓
  left++

left=3, right=7:
  height[3]=2 < height[7]=3 → Process left
  leftMax = max(1, 2) = 2
  water += 2 - 2 = 0
  left++

... continue

Answer: 6 ✓
```

---

### **5. CODE**

```cpp
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            // Process left side
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
            left++;
        } else {
            // Process right side
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
            right--;
        }
    }
    
    return water;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 7: Valid Palindrome

### **1. PROBLEM STATEMENT**

Check if string is palindrome (considering only alphanumeric, ignoring cases).

**Input:** `s = "A man, a plan, a canal: Panama"`  
**Output:** `true`  
**Explanation:** "amanaplanacanalpanama" is palindrome

---

### **2. IDENTIFICATION**

✅ **String problem** → Check  
✅ **Check from both ends** → Two Pointer!  
✅ **Compare opposite positions** → Opposite direction

**Type:** OPPOSITE DIRECTION ⬅️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Use left and right pointers from both ends

Skip non-alphanumeric characters
Compare characters (ignore case)

If mismatch → Not palindrome
If left >= right → Is palindrome
```

---

### **4. DRY RUN**

```
s = "A man"
Process: "Aman"

left=0, right=3:
  s[0]='A', s[3]='n'
  'A' != 'n' → Not palindrome

s = "madam"

left=0, right=4: 'm' == 'm' ✓, left++, right--
left=1, right=3: 'a' == 'a' ✓, left++, right--
left=2, right=2: left >= right → Palindrome ✓
```

---

### **5. CODE**

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Skip non-alphanumeric from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Compare (ignore case)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 📝 PROBLEM 8: Partition Array (Even/Odd)

### **1. PROBLEM STATEMENT**

Rearrange array so all **even** numbers come before **odd** numbers.

**Input:** `arr = [3, 1, 2, 4]`  
**Output:** `[2, 4, 3, 1]` (any order with evens first)

---

### **2. IDENTIFICATION**

✅ **Array problem** → Check  
✅ **Partition in-place** → Two Pointer!  
✅ **Process from both ends** → Opposite direction

**Type:** OPPOSITE DIRECTION ⬅️➡️

---

### **3. ABSTRACT/APPROACH**

**Think Before Coding:**

```
Use left and right pointers

If left is even → Move left++ (already correct)
If right is odd → Move right-- (already correct)
If left is odd AND right is even → Swap them

Continue until left >= right
```

---

### **4. DRY RUN**

```
arr = [3, 1, 2, 4]

left=0, right=3:
  arr[0]=3 is odd, arr[3]=4 is even
  → Swap: [4, 1, 2, 3]
  left++, right--

left=1, right=2:
  arr[1]=1 is odd, arr[2]=2 is even
  → Swap: [4, 2, 1, 3]
  left++, right--

left=2, right=1: left >= right → Stop

Answer: [4, 2, 1, 3] ✓ (evens first)
```

---

### **5. CODE**

```cpp
void partitionByParity(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        // If left is even, move forward
        if (arr[left] % 2 == 0) {
            left++;
        }
        // If right is odd, move backward
        else if (arr[right] % 2 == 1) {
            right--;
        }
        // Both in wrong positions, swap
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
```

**Time:** O(n) | **Space:** O(1)

---

<a name="summary"></a>
## 📄 ONE-PAGE PRINTABLE SUMMARY

```
╔══════════════════════════════════════════════════════════════════════════╗
║                 TWO POINTER TECHNIQUE - COMPLETE CHEAT SHEET             ║
║                                                  
╚══════════════════════════════════════════════════════════════════════════╝

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣  RECOGNITION (3 Questions - 3 Seconds)                               │
├─────────────────────────────────────────────────────────────────────────┤
│  ✅ Is it ARRAY or STRING?                                               │
│  ✅ Need to find PAIR, TRIPLET, or PARTITION?                           │
│  ✅ Array is SORTED or need BOTH ENDS?                                  │
│                                                                          │
│  ALL YES? → TWO POINTER! 🎯                                             │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 2️⃣  TYPES OF TWO POINTER                                                │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Type 1: OPPOSITE DIRECTION ⬅️➡️                                        │
│    [1, 2, 3, 4, 5, 6, 7]                                                 │
│     ↑                 ↑                                                  │
│    left            right                                                 │
│                                                                          │
│    Use when: Sorted array, pair sum, partition                          │
│    Examples: Two sum, container water, palindrome                       │
│                                                                          │
│  Type 2: SAME DIRECTION ➡️➡️                                             │
│    [0, 1, 0, 3, 12]                                                     │
│     ↑  ↑                                                                 │
│     j  i                                                                 │
│                                                                          │
│    Use when: Remove/partition in-place                                  │
│    Examples: Remove duplicates, move zeros                              │
│                                                                          │
│  Type 3: FIXED + TWO POINTER 🎯⬅️➡️                                      │
│    [1, 2, 3, 4, 5, 6]                                                   │
│     ↑  ↑           ↑                                                     │
│     i  left      right                                                   │
│                                                                          │
│    Use when: Find triplet or k-sum                                      │
│    Examples: 3Sum, 4Sum                                                 │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 3️⃣  TEMPLATE A: OPPOSITE DIRECTION                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  int left = 0, right = n - 1;                                           │
│                                                                          │
│  while (left < right) {                                                 │
│      int result = arr[left] + arr[right];  // Calculate                 │
│                                                                          │
│      if (result < target) {                                             │
│          left++;        // Need bigger value                            │
│      }                                                                   │
│      else if (result == target) {                                       │
│          return true;   // Found answer!                                │
│      }                                                                   │
│      else {                                                              │
│          right--;       // Need smaller value                           │
│      }                                                                   │
│  }                                                                       │
│                                                                          │
│  Mantra: "Less move left, Equal found, More move right"                │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 4️⃣  TEMPLATE B: SAME DIRECTION                                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  int i = 0, j = 0;                                                      │
│                                                                          │
│  while (i < n) {                                                        │
│      if (condition_met(arr[i])) {                                       │
│          arr[j] = arr[i];   // or swap(arr[i], arr[j])                 │
│          j++;               // Move j when valid                        │
│      }                                                                   │
│      i++;                   // i always moves                           │
│  }                                                                       │
│                                                                          │
│  return j;  // j is new length or partition point                      │
│                                                                          │
│  Mantra: "i explores, j collects"                                      │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 5️⃣  TEMPLATE C: FIXED + TWO POINTER (3Sum)                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  sort(arr.begin(), arr.end());  // MUST sort first!                    │
│                                                                          │
│  for (int i = 0; i < n; i++) {                                         │
│      if (i > 0 && arr[i] == arr[i-1]) continue;  // Skip dup i         │
│                                                                          │
│      int left = i + 1, right = n - 1;                                  │
│                                                                          │
│      while (left < right) {                                             │
│          int sum = arr[i] + arr[left] + arr[right];                    │
│                                                                          │
│          if (sum < target) left++;                                      │
│          else if (sum == target) {                                      │
│              // Store result                                             │
│              while (left < right && arr[left] == arr[left+1]) left++;  │
│              while (left < right && arr[right] == arr[right-1]) right--;│
│              left++; right--;                                            │
│          }                                                               │
│          else right--;                                                   │
│      }                                                                   │
│  }                                                                       │
│                                                                          │
│  Mantra: "Fix i, two pointer rest, skip duplicates"                    │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 6️⃣  KEYWORD TO TEMPLATE MAPPING                                         │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Keyword                  →  Template                                   │
│  ══════════════════════════════════════════                             │
│  "pair sum"               →  OPPOSITE DIRECTION                         │
│  "sorted array"           →  OPPOSITE DIRECTION                         │
│  "palindrome"             →  OPPOSITE DIRECTION                         │
│  "container/water"        →  OPPOSITE DIRECTION                         │
│                                                                          │
│  "remove duplicates"      →  SAME DIRECTION                             │
│  "move zeros"             →  SAME DIRECTION                             │
│  "partition"              →  SAME/OPPOSITE                              │
│                                                                          │
│  "triplet"                →  FIXED + TWO POINTER                        │
│  "3sum/4sum"              →  FIXED + TWO POINTER                        │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 7️⃣  TOP 8 PROBLEMS (Master These!)                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  OPPOSITE DIRECTION:                                                    │
│  ✅ Two Sum II (Sorted)              (5 min)                            │
│  ✅ Container With Most Water        (7 min)                            │
│  ✅ Trapping Rain Water              (12 min)                           │
│  ✅ Valid Palindrome                 (5 min)                            │
│                                                                          │
│  SAME DIRECTION:                                                        │
│  ✅ Remove Duplicates                (5 min)                            │
│  ✅ Move Zeros to End                (5 min)                            │
│  ✅ Partition Even/Odd               (7 min)                            │
│                                                                          │
│  FIXED + TWO POINTER:                                                   │
│  ✅ Three Sum                         (15 min)                          │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 8️⃣  INTERVIEW SCRIPT (First 30 Seconds)                                 │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  "Sir, I recognize two pointer because:                                │
│   1. [Array/String] with [pair/partition] requirement ✓                │
│   2. Array is [sorted/need both ends] ✓                                │
│   3. This is [opposite/same/fixed+two] direction!                      │
│                                                                          │
│   I'll use [left,right / i,j] pointers.                                │
│   Time complexity: O(n) [or O(n²) for 3sum]"                           │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 9️⃣  DECISION TREE                                                        │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Is array SORTED or need BOTH ENDS?                                    │
│     ├─ YES → OPPOSITE DIRECTION                                         │
│     │         (left=0, right=n-1)                                       │
│     │                                                                    │
│     └─ NO → Is it in-place remove/partition?                           │
│             ├─ YES → SAME DIRECTION                                     │
│             │         (i,j both start from 0)                           │
│             │                                                            │
│             └─ NO → Find triplet/k-sum?                                 │
│                     └─ YES → FIXED + TWO POINTER                        │
│                               (sort, fix i, two pointer)                │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 🔟 COMMON MISTAKES                                                       │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  ❌ Forgot to SORT before 3Sum                                          │
│     ✅ Always: sort(arr.begin(), arr.end())                             │
│                                                                          │
│  ❌ Not skipping duplicates in 3Sum                                     │
│     ✅ if (i > 0 && arr[i] == arr[i-1]) continue                        │
│                                                                          │
│  ❌ Wrong pointer initialization                                        │
│     ✅ Opposite: left=0, right=n-1                                      │
│     ✅ Same: i=0, j=0 (or j=1 for duplicates)                          │
│                                                                          │
│  ❌ Moving both pointers always                                         │
│     ✅ Check condition, move appropriate pointer                        │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣1️⃣  COMPLEXITY                                                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Opposite Direction:  O(n) time, O(1) space                            │
│  Same Direction:      O(n) time, O(1) space                            │
│  Fixed + Two Pointer: O(n²) time, O(1) space                           │
│                       (n for outer loop, n for two pointer)             │
│                                                                          │
│  Why better than brute force?                                           │
│  - Brute force: O(n²) or O(n³)                                         │
│  - Two pointer: O(n) or O(n²)                                          │
│  - Single/Double pass vs nested loops                                   │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣2️⃣  MEMORY HOOKS                                                        │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Opposite = ⬅️➡️ "Squeeze from both ends"                               │
│  Same = ➡️➡️ "Fast explorer, slow collector"                            │
│  Fixed = 🎯 "Anchor one, search with two"                               │
│                                                                          │
│  Sorted + Pair → Opposite direction                                    │
│  Remove/Partition → Same direction                                     │
│  Triplet → Fixed + Two pointer (MUST sort!)                            │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣3️⃣  BEFORE INTERVIEW CHECKLIST                                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  □ Write all 3 templates blind (3 min)                                  │
│  □ Solve Two Sum II (5 min)                                             │
│  □ Solve Move Zeros (5 min)                                             │
│  □ Solve Three Sum (15 min)                                             │
│  □ Recite: "Opposite for sorted, Same for remove, Fixed for triplet"   │
│  □ Know when to SORT (3Sum needs it!)                                   │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣4️⃣  SUCCESS MANTRAS                                                     │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Opposite: "Less move left, Equal found, More move right"              │
│  Same: "i explores, j collects"                                        │
│  Fixed: "Fix i, two pointer rest, skip duplicates"                     │
│                                                                          │
│  "Sorted array → Two pointer works!                                     │
│   3Sum needs sort → Don't forget!                                       │
│   Templates write themselves! 🔥"                                        │
└─────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════╗
║  PRINT THIS PAGE → KEEP IN WALLET → REVISE DAILY → CRACK INTERVIEW! 🚀 ║
╚══════════════════════════════════════════════════════════════════════════╝
```

---

## 🎯 COMPLETE LEARNING PATH

### **Day 1: Understand Concepts**
- Read Introduction + Identification sections
- Understand 3 types of two pointer
- Write templates 3 times each

### **Day 2: Opposite Direction**
- Solve Problems 1, 4, 6, 7
- Focus on: Two Sum, Container Water, Trapping Rain, Palindrome
- Master the mantra: "Less left, Equal found, More right"

### **Day 3: Same Direction**
- Solve Problems 2, 3, 8
- Focus on: Remove Duplicates, Move Zeros, Partition
- Master the mantra: "i explores, j collects"

### **Day 4: Fixed + Two Pointer**
- Solve Problem 5 (Three Sum)
- Practice skipping duplicates
- Master sorting + two pointer combination

### **Day 5: Mixed Practice**
- Solve 2 from each type
- Time yourself (target times in summary)
- Write templates blind

### **Day 6: Speed Practice**
- Solve all 8 problems in one sitting
- Target: Complete in 90 minutes
- Focus on speed + accuracy

### **Day 7: Review + Rest**
- Read printable summary
- Recite all mantras
- Relax before interview! 😊

---

## 🔥 FINAL WISDOM

### **The Secret to Two Pointer:**

```
1. ✅ Identify the TYPE correctly
2. ✅ Choose right template
3. ✅ Move pointers based on CONDITION
4. ✅ Handle edge cases (duplicates, empty)
```

### **Common Pattern:**

```
ALL Two Pointer problems follow:
1. Initialize pointers
2. Loop with condition
3. Calculate/Compare
4. Move appropriate pointer(s)
5. Return result
```

### **You're Ready When:**

- ✅ Can identify type in 5 seconds
- ✅ Can write templates without looking
- ✅ Know when to sort (3Sum!)
- ✅ Understand why each pointer moves

---

**🎯 TWO POINTER MASTERED! NOW GO CRACK THOSE INTERVIEWS! 🚀💪**

---