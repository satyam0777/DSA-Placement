## 🎯 SLIDING WINDOW - MUSCLE MEMORY EDITION

> **Goal:** Make templates so automatic, they write themselves in interviews!

---

## 📄 ONE-PAGE PRINTABLE SUMMARY (KEEP IN WALLET!)

```
╔══════════════════════════════════════════════════════════════════════════╗
║                   SLIDING WINDOW COMPLETE CHEAT SHEET                    ║
║                         (ADITYA VERMA METHOD)                            ║
╚══════════════════════════════════════════════════════════════════════════╝

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣  RECOGNITION (3 Questions - 3 Seconds)                               │
├─────────────────────────────────────────────────────────────────────────┤
│  ✅ Array or String?                                                     │
│  ✅ Contiguous elements (subarray/substring)?                           │
│  ✅ Keywords: window, size k, longest, smallest, at most?               │
│                                                                          │
│  ALL YES? → SLIDING WINDOW! 🎯                                          │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 2️⃣  DECISION TREE (Which Template?)                                     │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Is window SIZE given (k)?                                              │
│     ├─ YES → FIXED WINDOW                                               │
│     │         Formula: if (j - i + 1 == k)                              │
│     │                                                                    │
│     └─ NO → VARIABLE WINDOW                                             │
│               Formula: 3 Conditions (< = >)                             │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 3️⃣  THE GOLDEN FORMULA (NEVER FORGET!)                                  │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│              Window Size = j - i + 1                                    │
│              Window Size = j - i + 1                                    │
│              Window Size = j - i + 1                                    │
│                                                                          │
│  (Write this 10 times before interview!)                                │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 4️⃣  FIXED WINDOW TEMPLATE                                               │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  int i = 0, j = 0;                                                      │
│  while (j < n) {                                                        │
│      sum += arr[j];              // Add j                               │
│                                                                          │
│      if (j - i + 1 < k) {                                               │
│          j++;                    // Not ready                           │
│      }                                                                   │
│      else if (j - i + 1 == k) {                                         │
│          maxSum = max(maxSum, sum);  // Answer                          │
│          sum -= arr[i];          // Remove i                            │
│          i++; j++;               // Slide both                          │
│      }                                                                   │
│  }                                                                       │
│                                                                          │
│  Mantra: "Add j, check size, answer, slide both"                       │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 5️⃣  VARIABLE WINDOW - 3 CONDITIONS (Aditya Verma)                       │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  int i = 0, j = 0, sum = 0, maxLen = 0;                                │
│  while (j < n) {                                                        │
│      sum += arr[j];              // Add j                               │
│                                                                          │
│      if (sum < k) {              // 🔵 Less than target                 │
│          j++;                    // Need more, expand                   │
│      }                                                                   │
│      else if (sum == k) {        // 🟢 Equals target                    │
│          maxLen = max(maxLen, j - i + 1);  // Found it!                 │
│          j++;                                                            │
│      }                                                                   │
│      else if (sum > k) {         // 🔴 More than target                 │
│          while (sum > k) {       // Too much, shrink                    │
│              sum -= arr[i];                                              │
│              i++;                                                        │
│          }                                                               │
│          j++;                                                            │
│      }                                                                   │
│  }                                                                       │
│                                                                          │
│  Mantra: "Less expand, Equal answer, More shrink"                      │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 6️⃣  VARIABLE WINDOW - SIMPLIFIED (Most Common)                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  int i = 0, j = 0, maxLen = 0;                                         │
│  while (j < n) {                                                        │
│      // Add arr[j] to window                                            │
│                                                                          │
│      while (condition_invalid) {  // Shrink while bad                   │
│          // Remove arr[i]                                                │
│          i++;                                                            │
│      }                                                                   │
│                                                                          │
│      maxLen = max(maxLen, j - i + 1);  // Update answer                 │
│      j++;                                                                │
│  }                                                                       │
│                                                                          │
│  Mantra: "Add j, while bad shrink i, update max, move j"               │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 7️⃣  TEMPLATE SELECTION GUIDE                                            │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Keywords               →  Template                                     │
│  ═══════════════════════════════════════════════                        │
│  "size k"               →  FIXED                                        │
│  "every window k"       →  FIXED                                        │
│  "first k elements"     →  FIXED                                        │
│                                                                          │
│  "longest sum = k"      →  VARIABLE (3-condition)                       │
│  "largest sum ≤ k"      →  VARIABLE (3-condition)                       │
│                                                                          │
│  "without repeating"    →  VARIABLE (simplified)                        │
│  "at most k distinct"   →  VARIABLE (simplified)                        │
│  "max consecutive"      →  VARIABLE (simplified)                        │
│                                                                          │
│  "smallest substring"   →  VARIABLE (update inside while)               │
│  "minimum window"       →  VARIABLE (update inside while)               │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 8️⃣  TOP 8 PROBLEMS (Master These!)                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  FIXED WINDOW:                                                          │
│  ✅ Maximum Sum Subarray Size K          (5 min)                        │
│  ✅ First Negative in Window K           (7 min)                        │
│  ✅ Count Anagrams                       (10 min)                       │
│                                                                          │
│  VARIABLE WINDOW:                                                       │
│  ✅ Longest Without Repeating            (10 min)                       │
│  ✅ Longest Subarray Sum ≤ K             (8 min)                        │
│  ✅ K Unique Characters                  (12 min)                       │
│  ✅ Max Consecutive 1s (Flip K)          (10 min)                       │
│  ✅ Minimum Window Substring             (15 min)                       │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 9️⃣  INTERVIEW SCRIPT (First 30 Seconds)                                 │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  "Sir, I recognize sliding window because:                             │
│   1. Contiguous elements (subarray/substring) ✓                        │
│   2. Looking for [longest/maximum/smallest] ✓                          │
│   3. This is [fixed/variable] window approach!                         │
│                                                                          │
│   I'll use two pointers i,j starting at 0.                             │
│   Time complexity: O(n), Space: O(1) [or O(k)]"                        │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 🔟 COMMON MISTAKES (Check Before Submitting!)                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  ❌ Forgot to remove arr[i] before sliding                              │
│     ✅ Always: sum -= arr[i]; THEN i++;                                 │
│                                                                          │
│  ❌ Window size: j - i (missing +1)                                     │
│     ✅ Always: j - i + 1                                                │
│                                                                          │
│  ❌ j++ outside if conditions                                           │
│     ✅ j++ should be INSIDE each condition                              │
│                                                                          │
│  ❌ Map: forgot to erase when count = 0                                 │
│     ✅ if (map[x] == 0) map.erase(x);                                   │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣1️⃣  COMPLEXITY EXPLANATION                                              │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Time:  O(n) - Each element visited max twice (once by j, once by i)   │
│  Space: O(1) - Only variables                                          │
│         O(k) - If using map/set/queue                                   │
│                                                                          │
│  Why O(n)? Brute force checks all subarrays = O(n²)                    │
│           Sliding window reuses calculations = O(n) ✓                  │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣2️⃣  MEMORY HOOKS                                                        │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  Fixed Window = 🏠 House Party (exactly k guests, slide door)           │
│  Variable Window = 🪟 Elastic Band (stretch/snap based on condition)    │
│                                                                          │
│  Fixed: "Add check answer slide"                                       │
│  Variable: "Less expand, equal answer, more shrink"                    │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣3️⃣  BEFORE INTERVIEW CHECKLIST                                          │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  □ Write both templates blind (2 min)                                   │
│  □ Solve Max Sum Size K (5 min)                                         │
│  □ Solve Longest Without Repeat (10 min)                                │
│  □ Recite: "Window Size = j - i + 1"                                    │
│  □ Recite: "Less expand, equal answer, more shrink"                    │
│  □ Sleep 8 hours! 😴                                                     │
└─────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────┐
│ 1️⃣4️⃣  SUCCESS MANTRA                                                      │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                          │
│  "i = 0, j = 0, while j < n                                            │
│   Window size = j - i + 1                                               │
│   Template writes itself                                                │
│   I just fill the blanks                                                │
│   I've practiced, I'm ready! 🔥"                                         │
└─────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════╗
║  PRINT THIS PAGE → KEEP IN WALLET → REVISE DAILY → CRACK INTERVIEW! 🚀 ║
╚══════════════════════════════════════════════════════════════════════════╝
```

---

## 📋 TABLE OF CONTENTS

1. [🧠 Muscle Memory Templates](#muscle-memory)
2. [⚡ 3-Second Recognition](#recognition)
3. [🔥 Universal Templates (Aditya Verma Style)](#universal)
4. [💪 Practice Drills](#drills)
5. [🎯 Top 8 Problems](#problems)
6. [🗣️ Interview Scripts](#communication)
7. [🏢 Company Questions](#companies)

---

<a name="muscle-memory"></a>
## 🧠 MUSCLE MEMORY TEMPLATES

### **✋ REMEMBER: Window Size = j - i + 1**

This is your **ANCHOR**. Everything revolves around this formula.

```
Window Size = j - i + 1
Window Size = j - i + 1
Window Size = j - i + 1
```

**Write this 10 times on paper RIGHT NOW!** ✍️

---

### **👉 TYPE 1: FIXED WINDOW (When k is given)**

**Muscle Memory Code (Aditya Verma Style):**

```cpp
int i = 0, j = 0;
int n = arr.size();

while (j < n) {
    // STEP 1: CALCULATION (add arr[j])
    
    if (j - i + 1 < k) {
        j++;  // Window not ready
    }
    else if (j - i + 1 == k) {
        // STEP 2: CALCULATE ANSWER
        
        // STEP 3: SLIDE WINDOW (remove arr[i])
        i++;
        j++;
    }
}
```

**Memory Anchor:** "**i j while, check size, if small j++, if equal answer slide both**"

---

### **👉 TYPE 2: VARIABLE WINDOW (Find longest/smallest)**

**Muscle Memory Code (Aditya Verma Style):**

```cpp
int i = 0, j = 0;
int ans = 0;  // or INT_MAX for minimum

while (j < n) {
    // STEP 1: CALCULATION (add arr[j])
    
    if (condition < target) {
        j++;  // Need more elements
    }
    else if (condition == target) {
        ans = max(ans, j - i + 1);  // Found valid window
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

**Memory Anchor:** "**i j while, three ifs: less expand, equal answer, more shrink**"

---

### **🎯 SIMPLIFIED VARIABLE WINDOW (Most Common)**

```cpp
int i = 0, j = 0;
int maxLen = 0;

while (j < n) {
    // Add arr[j] to window
    
    while (condition_violated) {
        // Remove arr[i]
        i++;
    }
    
    maxLen = max(maxLen, j - i + 1);
    j++;
}
```

**Memory Anchor:** "**Add j, while bad shrink i, update answer, move j**"

---

## 🔄 TEMPLATE REPETITION (DO THIS NOW!)

### **Write Fixed Template 3 Times:**

```cpp
// WRITE 1:
int i = 0, j = 0;
while (j < n) {
    if (j - i + 1 < k) j++;
    else if (j - i + 1 == k) { /* answer, slide */ i++; j++; }
}

// WRITE 2:
int i = 0, j = 0;
while (j < n) {
    if (j - i + 1 < k) j++;
    else if (j - i + 1 == k) { /* answer, slide */ i++; j++; }
}

// WRITE 3:
int i = 0, j = 0;
while (j < n) {
    if (j - i + 1 < k) j++;
    else if (j - i + 1 == k) { /* answer, slide */ i++; j++; }
}
```

### **Write Variable Template 3 Times:**

```cpp
// WRITE 1:
int i = 0, j = 0;
while (j < n) {
    // Add arr[j]
    while (invalid) i++;
    maxLen = max(maxLen, j - i + 1);
    j++;
}

// WRITE 2:
int i = 0, j = 0;
while (j < n) {
    // Add arr[j]
    while (invalid) i++;
    maxLen = max(maxLen, j - i + 1);
    j++;
}

// WRITE 3:
int i = 0, j = 0;
while (j < n) {
    // Add arr[j]
    while (invalid) i++;
    maxLen = max(maxLen, j - i + 1);
    j++;
}
```

**🎯 Goal: Write these WITHOUT looking in 30 seconds!**

---


<a name="recognition"></a>
## ⚡ 3-SECOND RECOGNITION

### **Is it Sliding Window? Ask 3 Questions:**

```
┌─────────────────────────────────────┐
│  1. Array or String?         [YES] │
│  2. Contiguous elements?     [YES] │
│  3. Window/Size/Longest?     [YES] │
│                                     │
│  ALL YES? → SLIDING WINDOW! 🎯     │
└─────────────────────────────────────┘
```

### **Quick Decision Tree:**

```
Window size given (k)?
    ├─ YES → FIXED WINDOW
    │         Template: if (j - i + 1 == k)
    │
    └─ NO → VARIABLE WINDOW
              Template: while (invalid) i++;
```

---

### **🔑 MAGIC KEYWORDS:**

| Keyword | Type | Template |
|---------|------|----------|
| "**size k**" | Fixed | `if (j-i+1 == k)` |
| "**every window**" | Fixed | `if (j-i+1 == k)` |
| "**longest**" | Variable | `while (invalid) i++` |
| "**smallest**" | Variable | `while (valid) i++` |
| "**maximum**" | Variable | `while (invalid) i++` |
| "**at most k**" | Variable | `while (count > k) i++` |

---

<a name="universal"></a>
## 🔥 ADITYA VERMA'S FIXED vs VARIABLE (Crystal Clear!)

### **🎯 THE KEY DIFFERENCE:**

```
┌─────────────────────────────────────────────────────────────┐
│  FIXED WINDOW          vs          VARIABLE WINDOW          │
├─────────────────────────────────────────────────────────────┤
│  Window SIZE is GIVEN            Window SIZE is UNKNOWN     │
│  (k is provided)                 (need to FIND size)        │
│                                                              │
│  Example:                        Example:                   │
│  "size k = 3"                    "longest subarray"         │
│  "every window k"                "smallest window"          │
│  "first k elements"              "maximum length"           │
└─────────────────────────────────────────────────────────────┘
```

---

### **📏 FIXED WINDOW = SIZE IS KNOWN**

**Formula:** `j - i + 1 == k`

**Template:**
```cpp
int i = 0, j = 0;
int n = arr.size();

while (j < n) {
    // CALCULATION: Add arr[j]
    sum += arr[j];
    
    if (j - i + 1 < k) {
        j++;  // Window not ready yet
    }
    else if (j - i + 1 == k) {
        // ANSWER: Window is ready!
        maxSum = max(maxSum, sum);
        
        // SLIDE: Remove arr[i], move both
        sum -= arr[i];
        i++;
        j++;
    }
}
```

**Key Point:** Always check `j - i + 1 == k`

---

### **🎯 VARIABLE WINDOW = SIZE IS UNKNOWN (ADITYA VERMA'S 3 CONDITIONS)**

**The Magic:** Instead of checking size, we check **CONDITION with target**

## 🔥 ADITYA VERMA'S 3 CONDITION FORMULA

```
┌──────────────────────────────────────────────────┐
│  VARIABLE WINDOW - THREE CONDITIONS              │
├──────────────────────────────────────────────────┤
│                                                   │
│  if (condition < target) {                       │
│      j++;  // Need MORE, expand window           │
│  }                                                │
│  else if (condition == target) {                 │
│      ans = max(ans, j - i + 1);  // FOUND IT!    │
│      j++;                                         │
│  }                                                │
│  else if (condition > target) {                  │
│      while (condition > target) {                │
│          // TOO MUCH, shrink window              │
│          i++;                                     │
│      }                                            │
│      j++;                                         │
│  }                                                │
└──────────────────────────────────────────────────┘
```

---

### **📝 EXAMPLE: Largest Subarray with Sum = K**

**Problem:** Find **longest** subarray with sum **exactly equal to k**

**Aditya Verma's Approach:**

```cpp
int longestSubarraySum(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int n = arr.size();
    int sum = 0;
    int maxLen = 0;
    
    while (j < n) {
        // CALCULATION: Add arr[j]
        sum += arr[j];
        
        // 🔥 THREE CONDITIONS:
        
        if (sum < k) {
            // Condition 1: SUM < TARGET
            // Need MORE elements
            j++;
        }
        else if (sum == k) {
            // Condition 2: SUM == TARGET
            // PERFECT! Calculate answer
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (sum > k) {
            // Condition 3: SUM > TARGET
            // TOO MUCH! Shrink from left
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

---

### **🎓 UNDERSTANDING THE 3 CONDITIONS:**

#### **Condition 1: sum < k** → **EXPAND** 🔵
```
Current sum is LESS than target
Need to ADD more elements
Action: j++ (expand right)

Example: sum=3, k=5
[2, 1, ___, ___]  ← Need more!
    i   j
```

#### **Condition 2: sum == k** → **ANSWER!** 🟢
```
Current sum EQUALS target
PERFECT window found!
Action: Calculate answer, then j++

Example: sum=5, k=5
[2, 1, 2]  ← Found it! Length = 3
 i      j
```

#### **Condition 3: sum > k** → **SHRINK** 🔴
```
Current sum is MORE than target
Window too BIG, need to REDUCE
Action: while(sum>k) { i++ } (shrink left)

Example: sum=8, k=5
[2, 1, 2, 3]  ← Too much!
 i         j
Shrink: Remove 2, sum=6, still > 5
Shrink: Remove 1, sum=5, now perfect!
```

---

### **🎯 VISUAL COMPARISON:**

```
FIXED WINDOW                    VARIABLE WINDOW
═══════════════                ════════════════════

Window size = k                 Window size = ???
                               
Check: j-i+1 == k?             Check: sum vs k?

if (j-i+1 < k)                 if (sum < k)
    j++                            j++

else if (j-i+1 == k)           else if (sum == k)
    answer                         answer
    slide both                     j++

                               else if (sum > k)
                                   while(sum > k) i++
                                   j++
```

---

### **💡 KEY INSIGHTS:**

| Aspect | Fixed Window | Variable Window |
|--------|--------------|-----------------|
| **What's Given?** | Size k | Target/Condition |
| **What to Find?** | Answer in window k | Optimal window size |
| **Check Formula** | `j - i + 1 == k` | `condition vs target` |
| **Expand When** | `j - i + 1 < k` | `condition < target` |
| **Answer When** | `j - i + 1 == k` | `condition == target` |
| **Shrink When** | Never (just slide) | `condition > target` |
| **Move Pointers** | Both together | Depends on condition |

---

## 🔥 UNIVERSAL TEMPLATES (Copy These!)

### **Template A: FIXED WINDOW** 

```cpp
// ========================================
// FIXED WINDOW - MASTER TEMPLATE
// Use when: Window size k is GIVEN
// ========================================

int i = 0, j = 0;
int n = arr.size();
// Your variables here (sum, count, etc.)

while (j < n) {
    // CALCULATION: Add arr[j] to window
    sum += arr[j];
    
    if (j - i + 1 < k) {
        j++;  // Window not ready yet
    }
    else if (j - i + 1 == k) {
        // ANSWER: Calculate result
        maxSum = max(maxSum, sum);
        
        // SLIDE: Remove arr[i], move both pointers
        sum -= arr[i];
        i++;
        j++;
    }
}
```

**4-Step Mantra:** "**Add j → Check size → Answer → Slide both**"

---

### **Template B: VARIABLE WINDOW (Aditya Verma's 3-Condition)**

```cpp
// ========================================
// VARIABLE WINDOW - ADITYA VERMA METHOD
// Use when: Find longest/maximum window
// ========================================

int i = 0, j = 0;
int n = arr.size();
int sum = 0;  // or count, or any condition
int maxLen = 0;

while (j < n) {
    // CALCULATION: Add arr[j]
    sum += arr[j];
    
    // 🔥 THREE CONDITIONS:
    
    if (sum < k) {
        // Condition < Target: Need more
        j++;
    }
    else if (sum == k) {
        // Condition == Target: Found answer!
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    else if (sum > k) {
        // Condition > Target: Shrink window
        while (sum > k) {
            sum -= arr[i];
            i++;
        }
        j++;
    }
}

return maxLen;
```

**Mantra:** "**Less expand, Equal answer, More shrink**"

---

### **Template C: VARIABLE WINDOW (Simplified - Most Common)**

```cpp
// ========================================
// VARIABLE WINDOW - SIMPLIFIED
// Use when: Longest/Maximum with constraint
// ========================================

int i = 0, j = 0;
int maxLen = 0;
// Your variables here (map, set, count)

while (j < n) {
    // Add arr[j] to window
    window.insert(arr[j]);
    
    // Shrink while condition violated
    while (condition_invalid) {
        // Remove arr[i]
        window.erase(arr[i]);
        i++;
    }
    
    // Update answer
    maxLen = max(maxLen, j - i + 1);
    j++;
}
```

**Mantra:** "**Add j → While bad shrink → Update answer → Move j**"

---

### **Template D: VARIABLE WINDOW (Minimum/Smallest)**

```cpp
// ========================================
// VARIABLE WINDOW - SMALLEST/MINIMUM
// Use when: Find smallest/minimum window
// ========================================

int i = 0, j = 0;
int minLen = INT_MAX;

while (j < n) {
    // Add arr[j] to window
    sum += arr[j];
    
    // Shrink while condition MET (to minimize)
    while (condition_met) {
        // Update answer BEFORE shrinking
        minLen = min(minLen, j - i + 1);
        
        // Remove arr[i]
        sum -= arr[i];
        i++;
    }
    
    j++;
}
```

**Key Difference:** Update answer WHILE condition is valid (not after)

---

## 📚 WHEN TO USE WHICH TEMPLATE?

### **Use FIXED Window When:**
✅ Problem says "**size k**"  
✅ "**Every window of size k**"  
✅ "**First k elements**"  
✅ "**Exactly k**"

**Examples:**
- Max sum subarray size k
- First negative in window k
- Count anagrams (pattern length = k)
- Maximum of all subarrays size k

---

### **Use VARIABLE Window (3-Condition) When:**
✅ "**Longest** subarray with sum = k"  
✅ "**Largest** subarray with sum ≤ k"  
✅ Find **length** with exact condition

**Examples:**
- Longest subarray with sum = k
- Largest subarray with sum ≤ k
- (Use 3 conditions: < = >)

---

### **Use VARIABLE Window (Simplified) When:**
✅ "**Longest** substring without repeat"  
✅ "**At most** k distinct characters"  
✅ "**Maximum** consecutive 1s after flip"

**Examples:**
- Longest substring without repeating
- At most 2 distinct characters
- Max consecutive 1s (flip k zeros)

---

### **Use VARIABLE Window (Minimum) When:**
✅ "**Smallest** substring containing..."  
✅ "**Minimum** window with..."  
✅ "**Shortest** subarray with sum ≥ target"

**Examples:**
- Minimum window substring
- Shortest subarray sum ≥ k
- (Update answer INSIDE while loop!)

---

---

## 🎯 PRACTICE: 3-CONDITION METHOD

### **Dry Run Example: Largest Subarray Sum = 5**

```
arr = [4, 1, 1, 1, 2, 3, 5], k = 5

Step-by-step with 3 conditions:

i=0, j=0: arr[0]=4, sum=4
          sum < k (4 < 5) → j++ ✅

i=0, j=1: arr[1]=1, sum=5
          sum == k (5 == 5) → maxLen=2, j++ ✅

i=0, j=2: arr[2]=1, sum=6
          sum > k (6 > 5) → SHRINK!
          while(6 > 5) { sum -= arr[0]=4, i++ }
          Now: i=1, sum=2, j++ ✅

i=1, j=3: arr[3]=1, sum=3
          sum < k (3 < 5) → j++ ✅

i=1, j=4: arr[4]=2, sum=5
          sum == k (5 == 5) → maxLen=max(2,4)=4, j++ ✅

i=1, j=5: arr[5]=3, sum=8
          sum > k (8 > 5) → SHRINK!
          while(8 > 5) { sum -= arr[1]=1, i++ }  sum=7
          while(7 > 5) { sum -= arr[2]=1, i++ }  sum=6
          while(6 > 5) { sum -= arr[3]=1, i++ }  sum=5
          Now: i=4, sum=5, j++ ✅

i=4, j=6: arr[6]=5, sum=10
          sum > k (10 > 5) → SHRINK!
          while(10 > 5) { sum -= arr[4]=2, i++ }  sum=8
          while(8 > 5) { sum -= arr[5]=3, i++ }  sum=5
          Now: i=6, sum=5, j++ ✅

Answer: maxLen = 4 (subarray [1,1,1,2])
```

---

### **🔥 MUSCLE MEMORY DRILL: 3 Conditions**

**Say this 10 times LOUD:**

```
"sum LESS than k? → j plus plus
 sum EQUALS k? → answer, j plus plus
 sum MORE than k? → while loop shrink i, then j plus plus"
```

**Write this 5 times:**

```cpp
// WRITE 1:
if (sum < k) j++;
else if (sum == k) { ans = max(ans, j-i+1); j++; }
else if (sum > k) { while(sum>k) i++; j++; }

// WRITE 2:


// WRITE 3:


// WRITE 4:


// WRITE 5:

```

---

### **📊 DECISION FLOWCHART:**

```
         Add arr[j] to sum
                |
                v
         Compare sum with k
                |
        ┌───────┼───────┐
        |       |       |
     sum<k   sum==k   sum>k
        |       |       |
        v       v       v
       j++   answer!   while(sum>k)
              j++       remove arr[i]
                        i++
                        j++
```

---

<a name="drills"></a>
## 💪 MUSCLE MEMORY DRILLS

### **🏋️ DRILL 1: Template Writing (2 minutes)**

**Set timer for 2 minutes. Write BOTH templates WITHOUT looking:**

```cpp
// FIXED WINDOW:






// VARIABLE WINDOW:






```

**Goal:** Write complete templates in 2 minutes.

---

### **🏋️ DRILL 2: Recognition Speed (30 seconds)**

**Identify type in 3 seconds each:**

| Problem | Type | Answer |
|---------|------|--------|
| "Max sum of size k" | ? | Fixed (k given) |
| "Longest substring without repeat" | ? | Variable (longest) |
| "First negative in window k" | ? | Fixed (k given) |
| "Smallest sum ≥ target" | ? | Variable (smallest) |
| "At most 2 distinct" | ? | Variable (at most) |

---

### **🏋️ DRILL 3: Code Skeleton (1 minute)**

**Problem:** "Find longest substring with k unique characters"

**Write skeleton in 1 minute:**

```cpp
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int i = 0, j = 0;
    // What data structure? _____________
    
    while (j < n) {
        // Add s[j]: _____________
        
        // Shrink condition: _____________
        while (___________) {
            // Remove s[i]: _____________
            i++;
        }
        
        // Update answer: _____________
        j++;
    }
    
    return ____________;
}
```

**Answers:**
- Data structure: `unordered_map<char, int>`
- Add: `window[s[j]]++`
- Condition: `window.size() > k`
- Remove: `window[s[i]]--; if(window[s[i]]==0) erase`
- Answer: `maxLen = max(maxLen, j-i+1)`
- Return: `maxLen`

---

### **🏋️ DRILL 4: Window Size Formula (CRITICAL!)**

**Fill in blanks (do this 10 times!):**

```
1. Window Size = ___ - ___ + ___
2. Window Size = ___ - ___ + ___
3. Window Size = ___ - ___ + ___
4. Window Size = ___ - ___ + ___
5. Window Size = ___ - ___ + ___
6. Window Size = ___ - ___ + ___
7. Window Size = ___ - ___ + ___
8. Window Size = ___ - ___ + ___
9. Window Size = ___ - ___ + ___
10. Window Size = ___ - ___ + ___
```

**Answer:** `j - i + 1` (EVERY TIME!)

---

### **🏋️ DRILL 5: Common Mistakes (Spot the Error)**

**Error 1:**
```cpp
// WRONG!
if (j - i + 1 == k) {
    maxSum = max(maxSum, sum);
    i++; j++;  // ❌ Forgot to remove arr[i]!
}
```

**Fixed:**
```cpp
if (j - i + 1 == k) {
    maxSum = max(maxSum, sum);
    sum -= arr[i];  // ✅ Remove arr[i] first!
    i++; j++;
}
```

---

**Error 2:**
```cpp
// WRONG!
int windowSize = j - i;  // ❌ Missing +1!
```

**Fixed:**
```cpp
int windowSize = j - i + 1;  // ✅ Always +1!
```

---

**Error 3:**
```cpp
// WRONG!
while (j < n) {
    sum += arr[j];
    if (j - i + 1 < k) {
        // empty
    }
}
j++;  // ❌ j++ should be INSIDE conditions!
```

**Fixed:**
```cpp
while (j < n) {
    sum += arr[j];
    if (j - i + 1 < k) {
        j++;  // ✅ Move j inside!
    }
    else if (j - i + 1 == k) {
        // answer
        i++; j++;
    }
}
```

---

<a name="problems"></a>
## 🎯 TOP 8 PROBLEMS (With Muscle Memory Code)

### **Problem 1: Maximum Sum Subarray of Size K** ⭐⭐⭐⭐⭐

**Type:** FIXED WINDOW | **Frequency:** 95% companies ask this!

**Muscle Memory Code (Write This Blind!):**
```cpp
int maxSumSubarray(vector<int>& arr, int k) {
    int i = 0, j = 0, n = arr.size();
    int sum = 0, maxSum = INT_MIN;
    
    while (j < n) {
        sum += arr[j];  // Add j
        
        if (j - i + 1 < k) {
            j++;  // Not ready
        }
        else if (j - i + 1 == k) {
            maxSum = max(maxSum, sum);  // Answer
            sum -= arr[i];  // Slide
            i++; j++;
        }
    }
    
    return maxSum;
}
```

**Interview Script:**
> "Sir, fixed window of size k. I'll use Aditya Verma's template: add j, check size, calculate answer, slide both. Time O(n), Space O(1)."

**Memory Hook:** "**Sum add, size check, max update, sum remove, both move**"

---

### **Problem 2: Longest Substring Without Repeating** ⭐⭐⭐⭐⭐

**Type:** VARIABLE WINDOW | **Frequency:** 90% companies

**Muscle Memory Code:**
```cpp
int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, n = s.size();
    int maxLen = 0;
    unordered_set<char> window;
    
    while (j < n) {
        // Shrink while duplicate
        while (window.count(s[j])) {
            window.erase(s[i]);
            i++;
        }
        
        window.insert(s[j]);  // Add j
        maxLen = max(maxLen, j - i + 1);  // Update
        j++;
    }
    
    return maxLen;
}
```

**Interview Script:**
> "Sir, variable window. Set tracks current window. When duplicate found, shrink from left until removed. Track max length. O(n) time."

**Memory Hook:** "**While duplicate shrink, add j, update max, move j**"

---

### **Problem 3: First Negative in Every Window K** ⭐⭐⭐⭐

**Type:** FIXED WINDOW | **Frequency:** 70% service companies

**Muscle Memory Code:**
```cpp
vector<int> firstNegative(vector<int>& arr, int k) {
    int i = 0, j = 0, n = arr.size();
    vector<int> result;
    queue<int> negatives;  // Stores negative numbers
    
    while (j < n) {
        // Add if negative
        if (arr[j] < 0) negatives.push(arr[j]);
        
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Answer
            result.push_back(negatives.empty() ? 0 : negatives.front());
            
            // Slide: remove arr[i] if it's in queue
            if (!negatives.empty() && negatives.front() == arr[i]) {
                negatives.pop();
            }
            i++; j++;
        }
    }
    
    return result;
}
```

**Memory Hook:** "**Queue tracks negatives, check size, answer front, slide queue**"

---

### **Problem 4: Longest Subarray Sum ≤ K** ⭐⭐⭐⭐

**Type:** VARIABLE WINDOW | **Frequency:** 80% companies

**Muscle Memory Code:**
```cpp
int longestSubarray(vector<int>& arr, int k) {
    int i = 0, j = 0, n = arr.size();
    int sum = 0, maxLen = 0;
    
    while (j < n) {
        sum += arr[j];  // Add j
        
        // Shrink while sum > k
        while (sum > k) {
            sum -= arr[i];
            i++;
        }
        
        maxLen = max(maxLen, j - i + 1);  // Update
        j++;
    }
    
    return maxLen;
}
```

**Memory Hook:** "**Add j, while sum big shrink, max update, move j**"

---

### **Problem 5: Count Anagrams in String** ⭐⭐⭐⭐

**Type:** FIXED WINDOW | **Frequency:** 65% companies

**Muscle Memory Code:**
```cpp
int countAnagrams(string s, string pattern) {
    int i = 0, j = 0, n = s.size(), k = pattern.size();
    int count = 0;
    unordered_map<char, int> patternMap, windowMap;
    
    for (char c : pattern) patternMap[c]++;
    
    while (j < n) {
        windowMap[s[j]]++;  // Add j
        
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            // Check if anagram
            if (windowMap == patternMap) count++;
            
            // Slide
            windowMap[s[i]]--;
            if (windowMap[s[i]] == 0) windowMap.erase(s[i]);
            i++; j++;
        }
    }
    
    return count;
}
```

**Memory Hook:** "**Map add j, size check, compare maps, map remove i, slide**"

---

### **Problem 6: Longest K Unique Characters** ⭐⭐⭐⭐

**Type:** VARIABLE WINDOW | **Frequency:** 75% companies

**Muscle Memory Code:**
```cpp
int longestKUnique(string s, int k) {
    int i = 0, j = 0, n = s.size();
    int maxLen = 0;
    unordered_map<char, int> window;
    
    while (j < n) {
        window[s[j]]++;  // Add j
        
        // Shrink if too many unique
        while (window.size() > k) {
            window[s[i]]--;
            if (window[s[i]] == 0) window.erase(s[i]);
            i++;
        }
        
        // Update only if exactly k unique
        if (window.size() == k) {
            maxLen = max(maxLen, j - i + 1);
        }
        j++;
    }
    
    return maxLen;
}
```

**Memory Hook:** "**Map add j, while big shrink map, if equal k update, move j**"

---

### **Problem 7: Minimum Window Substring** ⭐⭐⭐⭐

**Type:** VARIABLE WINDOW (MINIMUM) | **Frequency:** 60% product companies

**Muscle Memory Code:**
```cpp
string minWindow(string s, string t) {
    int i = 0, j = 0, n = s.size();
    int minLen = INT_MAX, start = 0;
    
    unordered_map<char, int> required, window;
    for (char c : t) required[c]++;
    
    int formed = 0, needToForm = required.size();
    
    while (j < n) {
        // Add j
        window[s[j]]++;
        if (required.count(s[j]) && window[s[j]] == required[s[j]]) {
            formed++;
        }
        
        // Shrink WHILE valid (to minimize)
        while (formed == needToForm) {
            // Update answer FIRST
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }
            
            // Then shrink
            window[s[i]]--;
            if (required.count(s[i]) && window[s[i]] < required[s[i]]) {
                formed--;
            }
            i++;
        }
        
        j++;
    }
    
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

**Memory Hook:** "**Add j, while valid FIRST answer THEN shrink, move j**"

---

### **Problem 8: Max Consecutive Ones (Flip K Zeros)** ⭐⭐⭐⭐⭐

**Type:** VARIABLE WINDOW | **Frequency:** 85% companies

**Muscle Memory Code:**
```cpp
int longestOnes(vector<int>& arr, int k) {
    int i = 0, j = 0, n = arr.size();
    int zeros = 0, maxLen = 0;
    
    while (j < n) {
        if (arr[j] == 0) zeros++;  // Add j
        
        // Shrink while too many zeros
        while (zeros > k) {
            if (arr[i] == 0) zeros--;
            i++;
        }
        
        maxLen = max(maxLen, j - i + 1);  // Update
        j++;
    }
    
    return maxLen;
}
```

**Memory Hook:** "**Count zeros, while zeros big shrink, max update, move j**"

---

## 🧠 MEMORY PALACE TECHNIQUE

### **Fixed Window = 🏠 House with K Rooms**

```
Imagine a house with EXACTLY k rooms:
- j enters from right (guest arrives)
- i leaves from left (guest leaves)
- Only when k guests present, count the party!
- Then 1 leaves left, 1 enters right (slide)
```

**Code Becomes:**
```cpp
while (j < n) {
    house.add(arr[j]);  // Guest arrives
    
    if (rooms < k) {
        j++;  // Wait for more guests
    }
    else if (rooms == k) {
        countParty();  // Party time!
        house.remove(arr[i]);  // One leaves
        i++; j++;  // Slide
    }
}
```

---

### **Variable Window = 🪟 Elastic Window**

```
Imagine a rubber band:
- j stretches right (expand)
- When condition breaks, i snaps left (shrink)
- Measure length at each valid state
```

**Code Becomes:**
```cpp
while (j < n) {
    band.stretch(arr[j]);  // Expand
    
    while (band.broken()) {
        band.snap(arr[i]);  // Shrink
        i++;
    }
    
    maxLength = measure(band);  // Measure
    j++;
}
```

---

<a name="communication"></a>
## 🗣️ INTERVIEW COMMUNICATION (EXACTLY What to Say!)

### **Script 1: Problem Recognition (First 10 Seconds)**

**You Say:**
> "Sir, I observe three things:  
> 1️⃣ We're dealing with **contiguous** elements (subarray/substring)  
> 2️⃣ There's a **window/size/longest/smallest** requirement  
> 3️⃣ This is a **sliding window** problem!  
>   
> *[PAUSE - Let them nod]*  
>   
> Window size is **[given/not given]**, so I'll use **[fixed/variable]** window approach."

**Confidence Level:** 🔥🔥🔥

---

### **Script 2: Template Explanation (Next 15 Seconds)**

**For FIXED Window:**
> "Sir, my approach:  
> ✅ Use two pointers **i** and **j** starting at 0  
> ✅ Expand **j** until window size equals **k**  
> ✅ Calculate answer, then slide both pointers  
> ✅ Time complexity **O(n)**, Space **O(1)** [or O(k) if using data structure]"

**For VARIABLE Window:**
> "Sir, my approach:  
> ✅ Use two pointers **i** and **j** starting at 0  
> ✅ Expand **j** to add elements  
> ✅ Shrink **i** while condition is violated  
> ✅ Track **maximum/minimum** at each step  
> ✅ Time complexity **O(n)**, Space **O(1)** [or O(k) if using map/set]"

---

### **Script 3: While Writing Code (Keep Talking!)**

**Say Out Loud:**
```
"Declaring i equals 0, j equals 0..."
[Write: int i = 0, j = 0;]

"While j is less than n..."
[Write: while (j < n) {]

"First, I'll add arr[j] to my calculation..."
[Write: sum += arr[j];]

"Now checking window size using formula j minus i plus 1..."
[Write: if (j - i + 1 < k)]

"If window not ready, just move j..."
[Write: j++;]

"Else if window size equals k..."
[Write: else if (j - i + 1 == k) {]

"Calculate my answer..."
[Write: maxSum = max(maxSum, sum);]

"Before sliding, remove arr[i]'s contribution..."
[Write: sum -= arr[i];]

"Finally slide both pointers..."
[Write: i++; j++;}]
```

**Why This Works:** Interviewer sees your thought process! 🧠

---

### **Script 4: Dry Run (Show One Example)**

**Always Say:**
> "Sir, let me quickly trace with a small example to verify..."

**Then Speak While Writing:**
```
arr = [2, 3, 1, 4], k = 2

"Initially i=0, j=0, sum=0"
[Write: i=0, j=0, sum=0]

"Add arr[0]=2, sum=2, size=1, not ready, j++"
[Write: j=1, sum=2]

"Add arr[1]=3, sum=5, size=2, answer! max=5"
[Write: max=5]

"Slide: remove arr[0]=2, sum=3, i=1, j=2"
[Write: i=1, j=2, sum=3]

"And so on... Final answer is 5"
```

**Time This Takes:** 30-45 seconds MAX

---

### **Script 5: Edge Cases (Show You Care!)**

**Always Mention:**
> "Sir, let me handle edge cases:  
> ✅ If array is empty: return 0  
> ✅ If k > n: return -1 or invalid  
> ✅ If all elements same: algorithm still works  
> *[Write quick if check]*"

```cpp
if (n == 0 || k > n) return -1;  // Edge cases
```

---

### **Script 6: Complexity Analysis (Last 10 Seconds)**

**You Say:**
> "Sir, complexity analysis:  
> **Time Complexity:** O(n) - each element visited at most twice (once by j, once by i)  
> **Space Complexity:** O(1) [or O(k) if using map/set/queue]  
>   
> This is optimal because we MUST visit each element at least once."

**Interviewer's Reaction:** 😊 Impressed!

---

## 🎭 ROLE-PLAY SCENARIOS

### **Scenario A: Interviewer Asks "Why Sliding Window?"**

**❌ WEAK Answer:**
> "Because it's efficient..."

**✅ STRONG Answer:**
> "Sir, brute force would check all subarrays - O(n²) or O(n³).  
> Sliding window optimizes by:  
> 1. Reusing calculations from previous window  
> 2. Not recalculating from scratch  
> 3. Each element processed maximum twice  
> Result: O(n²) → O(n), massive improvement!"

---

### **Scenario B: Interviewer Asks "What If K Changes?"**

**❌ WEAK Answer:**
> "Then... uh... we need to adjust..."

**✅ STRONG Answer:**
> "Sir, excellent question! If k is not fixed:  
> - We switch from **fixed** to **variable** window template  
> - Instead of `if (j-i+1 == k)`, we use condition-based shrinking  
> - For example: 'sum ≤ target' or 'at most k distinct'  
> *[Show variable template]*"

---

### **Scenario C: "Can You Optimize Space?"**

**❌ WEAK Answer:**
> "No, we need the map..."

**✅ STRONG Answer:**
> "Sir, depends on problem:  
> - If just counting/summing: O(1) space ✅  
> - If tracking which elements: Need O(k) map/set ❌ can't avoid  
> - **Trade-off:** Space for correctness  
> *[If only lowercase letters: use int[26] array instead of map!]*"

---

### **Script 7: If You Get Stuck (VERY IMPORTANT!)**

**Never Say:** "I don't know..."

**Always Say:**
> "Sir, let me think aloud:  
> 1. Problem needs contiguous elements ✓  
> 2. Need to optimize from brute force ✓  
> 3. Let me start with basic template...  
> *[Write: int i=0, j=0; while(j<n)...]*  
> Now, what should I track? [Think]  
> Ah! I need to [your realization]"

**Thinking out loud = Partial credit!** 🎯

---

## 💡 MEMORY HOOKS (Say These in Your Head!)

### **FIXED Window Hook:**
```
🏠 "House Party Template"
- j arrives (guest comes)
- Check if k guests (party ready?)
- Celebrate (calculate answer)
- i leaves, j arrives (slide both)
```

### **VARIABLE Window Hook:**
```
🪟 "Elastic Band Template"
- j stretches (expand)
- While broken, i snaps (shrink)
- Measure length (update answer)
- j continues (keep going)
```

### **Window Size Hook:**
```
📏 "The +1 Rule"
Window Size = j - i + 1
Why +1? Because indices start at 0!
[i=0, j=2] → 3 elements (0,1,2)
```

### **Shrink Condition Hook:**
```
🎯 "Red Light Green Light"
GREEN (valid): Update answer, move j
RED (invalid): Shrink i until GREEN again
```

---

## 🔥 RAPID FIRE RESPONSES

| Interviewer Question | Your Instant Response |
|---------------------|----------------------|
| "What's window size?" | "j - i + 1, sir" |
| "Why O(n)?" | "Each element visited max twice, sir" |
| "Fixed or variable?" | "[Check if k given] → Fixed/Variable, sir" |
| "Why not nested loop?" | "Reuse previous calculations, O(n²) → O(n), sir" |
| "What if negative numbers?" | "Same template works, sir! Prefix sum concept" |
| "Space complexity?" | "O(1) for basic, O(k) if map/set needed, sir" |
| "Can you code faster?" | "Yes sir, template is muscle memory!" |

---

<a name="companies"></a>
## 🏢 COMPANY-WISE PATTERNS

### **TCS (Tata Consultancy Services)** ⭐⭐⭐⭐
**Difficulty:** Easy to Medium  
**Most Asked:**
1. Maximum Sum Subarray Size K (80% rounds)
2. First Negative in Window (60%)
3. Longest Substring Without Repeat (50%)

**Interview Style:** Explain approach clearly, basic code

---

### **Wipro** ⭐⭐⭐⭐⭐
**Difficulty:** Easy to Medium  
**Most Asked:**
1. All basic sliding window (70% rounds)
2. Count Anagrams (55%)
3. At most K distinct (45%)

**Interview Style:** Focus on communication, dry run important

---

### **Infosys** ⭐⭐⭐
**Difficulty:** Easy  
**Most Asked:**
1. Maximum Sum Size K (90% rounds)
2. Very basic variations (50%)

**Interview Style:** Clear explanation > perfect code

---

### **Cognizant** ⭐⭐⭐⭐
**Difficulty:** Medium  
**Most Asked:**
1. K Unique Characters (65%)
2. Minimum Window Substring (40%)
3. Longest Without Repeat (55%)

**Interview Style:** Optimization discussion expected

---

### **Capgemini** ⭐⭐⭐
**Difficulty:** Easy  
**Most Asked:**
1. Fixed window problems (75%)
2. Basic sum/count problems (60%)

**Interview Style:** Simple, direct coding

---

### **Accenture** ⭐⭐⭐
**Difficulty:** Easy  
**Most Asked:**
1. Maximum/Minimum in window (70%)
2. Simple substring problems (50%)

**Interview Style:** Talk through approach, basic implementation

---

## 📊 DIFFICULTY BREAKDOWN

| Company | Fixed Window | Variable Window | Advanced |
|---------|--------------|-----------------|----------|
| **TCS** | 60% | 35% | 5% |
| **Wipro** | 50% | 45% | 5% |
| **Infosys** | 80% | 20% | 0% |
| **Cognizant** | 40% | 55% | 5% |
| **Capgemini** | 75% | 25% | 0% |
| **Accenture** | 70% | 30% | 0% |

**Key Insight:** Master Fixed Window (80% coverage) + Basic Variable (20% coverage) = SUCCESS! 🎯

---

## ⏱️ TIME TARGETS (Practice These!)

| Problem | Target Time | Your Time |
|---------|-------------|-----------|
| Max Sum Size K | 5 minutes | _____ |
| First Negative Window | 7 minutes | _____ |
| Longest Without Repeat | 10 minutes | _____ |
| Count Anagrams | 10 minutes | _____ |
| K Unique Characters | 12 minutes | _____ |
| Longest Sum ≤ K | 8 minutes | _____ |
| Max Consecutive 1s | 10 minutes | _____ |
| Min Window Substring | 15 minutes | _____ |

**Interview Reality:** 20-25 minutes including discussion + dry run

---

## 📝 FINAL REVISION CHECKLIST

### **Before Interview (Day Before):**
- [ ] Write both templates blind (2 min)
- [ ] Solve Max Sum Size K (5 min)
- [ ] Solve Longest Without Repeat (10 min)
- [ ] Read all interview scripts
- [ ] Sleep 8 hours! 😴

### **Morning of Interview:**
- [ ] Write templates 3 times on paper
- [ ] Recite window size formula: j - i + 1
- [ ] Read memory hooks
- [ ] Practice saying "Sir, this is sliding window because..."

### **In Waiting Room:**
- [ ] Deep breaths
- [ ] Visualize writing template
- [ ] Recall: "i=0, j=0, while(j<n)..."

### **During Interview:**
- [ ] Recognize pattern (10 sec)
- [ ] Explain approach (20 sec)
- [ ] Write template skeleton (30 sec)
- [ ] Fill in logic (5 min)
- [ ] Dry run (2 min)
- [ ] Mention complexity (10 sec)

---

## 🎯 THE ULTIMATE CHEAT SHEET

### **ONE TEMPLATE TO RULE THEM ALL:**

```cpp
// =======================================
// UNIVERSAL SLIDING WINDOW TEMPLATE
// =======================================

int i = 0, j = 0;
// Declare your tracking variables

while (j < n) {
    // ✅ STEP 1: Add arr[j] to window
    
    // ✅ STEP 2: Shrink if needed
    while (condition_invalid) {
        // Remove arr[i]
        i++;
    }
    
    // ✅ STEP 3: Update answer
    ans = update(ans, j - i + 1);
    
    // ✅ STEP 4: Move j
    j++;
}
```

**Adapt For:**
- **Fixed Window:** Change Step 2 to `if (j-i+1 == k)`
- **Maximum:** Use `max(ans, j-i+1)`
- **Minimum:** Use `min(ans, j-i+1)` and update INSIDE while loop
- **Count:** Increment counter when condition met

---

## 🚀 YOUR 7-DAY MASTERY PLAN

### **Day 1-2: FIXED WINDOW**
- Morning: Write template 10 times
- Afternoon: Problem 1 (Max Sum) - 5 solves
- Evening: Problems 3 & 5 (First Negative, Anagrams) - 3 solves each

**Goal:** Template becomes automatic

---

### **Day 3-4: VARIABLE WINDOW**
- Morning: Write variable template 10 times
- Afternoon: Problem 2 (Longest Without Repeat) - 5 solves
- Evening: Problems 4 & 6 (Sum ≤ K, K Unique) - 3 solves each

**Goal:** Understand shrink logic

---

### **Day 5: MIXED PRACTICE**
- Morning: 2 fixed + 2 variable (15 min each)
- Afternoon: Time yourself on all 8 problems
- Evening: Review mistakes, fix weak spots

**Goal:** Speed + Accuracy

---

### **Day 6: INTERVIEW SIMULATION**
- Morning: Practice interview scripts out loud
- Afternoon: Solve 3 random problems explaining to mirror
- Evening: Review communication tips

**Goal:** Confident communication

---

### **Day 7: LIGHT REVIEW**
- Morning: Write both templates blind
- Afternoon: Read all memory hooks
- Evening: Relax, trust your prep! 😊

**Goal:** Fresh mind for interview

---

## 🎓 FINAL WISDOM

### **The Truth About Sliding Window:**

**You Need:**
1. ✅ Two pointers (i, j)
2. ✅ Window size formula (j - i + 1)
3. ✅ When to shrink (condition-based)
4. ✅ What to track (sum/count/max)

**That's IT!** Every problem is just variation of template! 🔥

---

### **Confidence Boosters:**

**Remember:**
- 📝 Template is same for 90% problems
- 🧠 Formula never changes: j - i + 1
- ⚡ O(n) beats O(n²) always
- 🗣️ Communication > Perfect code
- 💪 You've practiced, you're ready!

---

### **Last Words Before Interview:**

```
Take deep breath.
You know the template.
i = 0, j = 0, while (j < n)
Window size = j - i + 1
Shrink when invalid.
Update answer.
You've got this! 🚀
```

---

## 🏆 SUCCESS MANTRAS

**Repeat 10 Times:**

1. "**Window Size = j - i + 1**"
2. "**Add j, shrink i, update answer, move j**"
3. "**Fixed = size given, Variable = size find**"
4. "**Template writes itself, I just fill blanks**"
5. "**O(n) because each element visited max twice**"

---

## 📞 EMERGENCY HELP

**If You Blank Out Mid-Interview:**

1. **Take 5-second pause** - "Sir, let me think..."
2. **Write skeleton:**
   ```cpp
   int i = 0, j = 0;
   while (j < n) {
       // Add j
       // Check condition
       // Update answer
       j++;
   }
   ```
3. **Think:** What am I tracking? (sum/count/max)
4. **Fill in** the blanks
5. **Continue confidently!**

**Your brain KNOWS this. Trust your practice!** 🧠✨

---

**YOU ARE READY! GO CRACK THAT INTERVIEW! 🔥🎯🚀**

---

**All the best!** 💪😊 
