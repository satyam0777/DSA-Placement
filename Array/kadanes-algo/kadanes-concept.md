
# 🎯 KADANE'S ALGORITHM - COMPLETE SERIES 

> **"Find maximum subarray sum in O(n) - The DP classic!"**

---

## 📖 TABLE OF CONTENTS

1. [🎬 Video 1: Introduction - What is Kadane's Algorithm?](#video1)
2. [🔍 Video 2: Identification - When to Use Kadane's?](#video2)
3. [🎨 Video 3: The Core Concept - Why It Works](#video3)
4. [📝 Video 4: Generic Template (Muscle Memory)](#video4)
5. [🎯 Video 5: Problem 1 - Maximum Subarray Sum](#problem1)
6. [🎯 Video 6: Problem 2 - Maximum Subarray with Indices](#problem2)
7. [🎯 Video 7: Problem 3 - Maximum Circular Subarray](#problem3)
8. [🎯 Video 8: Problem 4 - Maximum Product Subarray](#problem4)
9. [🎯 Video 9: Problem 5 - Maximum Subarray After One Deletion](#problem5)
10. [📋 Quick Reference Sheet](#reference)
11. [🎓 7-Day Learning Path](#learning)

---

<a name="video1"></a>
## 🎬 VIDEO 1: INTRODUCTION - WHAT IS KADANE'S ALGORITHM?

### **What is Kadane's Algorithm?**

**Kadane's Algorithm** is an efficient way to find the **maximum sum of a contiguous subarray** in O(n) time.

```
Problem: Find maximum sum of any contiguous subarray

Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
                  ↑____________↑
                  [4, -1, 2, 1] = 6 (maximum!)

Brute Force: Check all subarrays → O(n²) or O(n³) ❌
Kadane's Algorithm: Single pass → O(n) ✅
```

### **Why Kadane's Algorithm?**

**Time Complexity Reduction:**
- **Brute Force:** O(n²) - check all pairs (i, j)
- **Kadane's:** O(n) - single pass through array
- **Space:** O(1) - only 2 variables needed!

### **The Big Idea:**

> **"At each position, decide: Should I EXTEND the previous subarray or START a new one?"**

```
At each element arr[i]:
    max_ending_here = max(arr[i], max_ending_here + arr[i])
                          ↑              ↑
                    Start new      Extend previous
```

**Key Insight:**
- If `max_ending_here + arr[i]` becomes negative, it will only pull down future sums
- Better to START FRESH from current element!

---

<a name="video2"></a>
## 🔍 VIDEO 2: IDENTIFICATION - WHEN TO USE KADANE'S?

### **🎯 3 Signs to Recognize Kadane's Pattern:**

**Sign 1:** Problem asks for **MAXIMUM SUM** ✅  
**Sign 2:** Of a **CONTIGUOUS SUBARRAY** (no gaps!) ✅  
**Sign 3:** Array may contain **NEGATIVE numbers** ✅

**If all 3 signs present → KADANE'S ALGORITHM! 🎯**

---

### **🔥 Magic Keywords (Instant Recognition):**

If you see these phrases → Think Kadane's:

| Keyword | Means Kadane's |
|---------|---------------|
| **"Maximum subarray sum"** | ✅ Classic Kadane's |
| **"Largest sum contiguous"** | ✅ Kadane's |
| **"Max sum of any subarray"** | ✅ Kadane's |
| **"Contiguous elements"** | ✅ (if asking for max sum) |
| **"At least one element"** | ✅ (Kadane's handles this) |

---

### **❓ Questions to Ask Yourself:**

```
Q1: Am I looking for MAXIMUM SUM?
Q2: Must elements be CONTIGUOUS (side by side)?
Q3: Can array have NEGATIVE numbers?

If YES to all → Kadane's Algorithm! 🎯
```

---

### **📊 Pattern vs Other Techniques:**

```
╔═══════════════════════╦═══════════════════════════════╗
║ If Problem Says...    ║ Use...                        ║
╠═══════════════════════╬═══════════════════════════════╣
║ Max sum + contiguous  ║ KADANE'S ALGORITHM ✅         ║
║ Sum = k + contiguous  ║ PREFIX SUM / SLIDING WINDOW   ║
║ Max sum + size = k    ║ SLIDING WINDOW (Fixed)        ║
║ Max sum + pick any    ║ GREEDY (not contiguous)       ║
╚═══════════════════════╩═══════════════════════════════╝
```

---

<a name="video3"></a>
## 🎨 VIDEO 3: THE CORE CONCEPT - WHY IT WORKS

### **🧠 The Intuition:**

Imagine you're walking through the array, collecting elements:

```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

At each step, you ask:
"Should I ADD this element to my current sum,
 OR should I START FRESH from here?"

Decision Rule:
- If current_sum + arr[i] > arr[i] → EXTEND
- If current_sum + arr[i] < arr[i] → START FRESH
```

---

### **📐 The Two Variables:**

```cpp
max_ending_here: Maximum sum of subarray ENDING at current position
max_so_far:      Maximum sum found so far (global maximum)
```

**Visual Representation:**

```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Position 0 (-2):
    max_ending_here = -2 (start here)
    max_so_far = -2

Position 1 (1):
    max_ending_here = max(1, -2+1) = 1 (start fresh!)
    max_so_far = max(-2, 1) = 1

Position 2 (-3):
    max_ending_here = max(-3, 1-3) = -2 (extend)
    max_so_far = max(1, -2) = 1

Position 3 (4):
    max_ending_here = max(4, -2+4) = 4 (start fresh!)
    max_so_far = max(1, 4) = 4

Position 4 (-1):
    max_ending_here = max(-1, 4-1) = 3 (extend)
    max_so_far = max(4, 3) = 4

Position 5 (2):
    max_ending_here = max(2, 3+2) = 5 (extend)
    max_so_far = max(4, 5) = 5

Position 6 (1):
    max_ending_here = max(1, 5+1) = 6 (extend)
    max_so_far = max(5, 6) = 6 ✅

Final Answer: 6
Subarray: [4, -1, 2, 1]
```

---

### **🔑 Key Formula:**

```cpp
max_ending_here = max(arr[i], max_ending_here + arr[i])
                      ↑              ↑
                Start new      Extend previous
```

**Why this works:**
- If `max_ending_here + arr[i]` is less than `arr[i]` alone
- It means previous subarray was pulling us down (negative)
- Better to abandon it and start fresh!

---

<a name="video4"></a>
## 📝 VIDEO 4: GENERIC TEMPLATE (MUSCLE MEMORY)

### **✍️ KADANE'S ALGORITHM - GENERIC TEMPLATE**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
int kadanesAlgorithm(vector<int>& arr) {
    // Initialize with first element
    int max_ending_here = arr[0];  // Max sum ending at current position
    int max_so_far = arr[0];       // Global maximum
    
    // Process remaining elements
    for (int i = 1; i < arr.size(); i++) {
        // Key Decision: Extend or Start Fresh?
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        
        // Update global maximum
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}
```

**Time:** O(n) | **Space:** O(1)

---

### **🎯 Template Breakdown:**

```cpp
Step 1: Initialize
────────────────────
int max_ending_here = arr[0];  // Local max
int max_so_far = arr[0];       // Global max

Step 2: Loop through array (from index 1)
────────────────────
for (int i = 1; i < n; i++) {
    
Step 3: KEY DECISION (This is the heart!)
────────────────────
    max_ending_here = max(arr[i], max_ending_here + arr[i]);
                          ↑              ↑
                    Start new      Extend previous
    
Step 4: Update global maximum
────────────────────
    max_so_far = max(max_so_far, max_ending_here);
}

Step 5: Return answer
────────────────────
return max_so_far;
```

---

### **🔥 Mantra (Say 10 times!):**

**"Extend or Start Fresh - whichever is LARGER!"**

**"max_ending_here asks: Should I continue or restart?"**

**"max_so_far remembers: What's the best I've seen?"**

---

### **💡 Memory Hook:**

Think of **max_ending_here** as a **RUNNER** carrying weight:
- If weight (sum) becomes too heavy (negative), DROP IT and start fresh!
- If still manageable, KEEP CARRYING (extend)

Think of **max_so_far** as the **JUDGE** watching:
- Records the BEST performance seen so far
- Doesn't care about current struggle, only BEST result!

---

### **🔄 ALTERNATIVE IMPLEMENTATION (Your Version!):**

```cpp
// "Reset if Negative" Approach - Equally Valid!
int kadanes(vector<int>& arr) {
    int sum = 0;              // Current sum (can go negative)
    int ans = INT_MIN;        // Best answer so far
    
    for (int i = 0; i < arr.size(); i++) {
        
        if (sum >= 0) {
            // Sum is positive/zero → ADD current element
            sum = sum + arr[i];
        } else {
            // Sum went negative → RESET to current element
            sum = arr[i];
        }
        
        // Update best answer
        ans = max(ans, sum);
    }
    
    return ans;
}
```

**Time:** O(n) | **Space:** O(1)

---

### **🎯 How Your Version Works:**

```
Logic: "If my sum went negative, DISCARD it and start fresh!"

Key Difference:
─────────────────────────────────────────────────────────
Standard:  max_ending_here = max(arr[i], sum + arr[i])
Your Way:  if (sum < 0) sum = arr[i]  else  sum += arr[i]
─────────────────────────────────────────────────────────

Both achieve same result - just different thinking!
```

---

### **📊 Comparison: Both Implementations**

| Aspect | Standard Version | Your Version |
|--------|-----------------|--------------|
| **Logic** | "Pick larger: extend or restart" | "If negative, reset; else add" |
| **Variables** | `max_ending_here`, `max_so_far` | `sum`, `ans` |
| **Key Check** | `max(arr[i], sum + arr[i])` | `if (sum >= 0)` |
| **When to Reset** | When `arr[i]` alone is larger | When `sum < 0` |
| **Result** | ✅ Identical | ✅ Identical |
| **Time/Space** | O(n)/O(1) | O(n)/O(1) |

---

### **💭 Which One to Use?**

**Use Standard Version when:**
- You want max-based thinking: "Pick the larger option"
- Interview expects traditional Kadane's
- Building on max_ending_here concept for variations

**Use Your Version when:**
- You prefer if-else logic over max()
- "Reset if negative" is more intuitive to you
- You learned it this way and it's muscle memory!

**Bottom Line:** Both are 100% correct! Stick with what feels natural to YOU! 💪

---

### **🎨 Dry Run: Your Version**

```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: arr[0]=-2
     sum=0 (initial), sum>=0? YES → sum=0+(-2)=-2
     ans=max(INT_MIN, -2) = -2

i=1: arr[1]=1
     sum=-2, sum>=0? NO → sum=1 (RESET!)
     ans=max(-2, 1) = 1

i=2: arr[2]=-3
     sum=1, sum>=0? YES → sum=1+(-3)=-2
     ans=max(1, -2) = 1

i=3: arr[3]=4
     sum=-2, sum>=0? NO → sum=4 (RESET!)
     ans=max(1, 4) = 4

i=4: arr[4]=-1
     sum=4, sum>=0? YES → sum=4+(-1)=3
     ans=max(4, 3) = 4

i=5: arr[5]=2
     sum=3, sum>=0? YES → sum=3+2=5
     ans=max(4, 5) = 5

i=6: arr[6]=1
     sum=5, sum>=0? YES → sum=5+1=6
     ans=max(5, 6) = 6 ✅

Final: 6
```

**Key Observations:**
- Reset at i=1 (sum was -2)
- Reset at i=3 (sum was -2)
- Extended from i=3 to i=6 (sum stayed positive)
- Same result as standard version!

---

<a name="problem1"></a>
## 🎯 VIDEO 5: PROBLEM 1 - MAXIMUM SUBARRAY SUM (CLASSIC)




