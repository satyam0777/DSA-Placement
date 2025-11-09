#  KADANE'S ALGORITHM - MUSCLE MEMORY EDITION

---

##  3-SECOND RECOGNITION

**Ask 3 Questions:**
1. Looking for **MAXIMUM SUM**? ✅
2. Must be **CONTIGUOUS** subarray? ✅
3. Array has **NEGATIVE** numbers? ✅

**If all 3 YES → KADANE'S ALGORITHM! 🎯**

---

## 🔥 MAGIC KEYWORDS

| See This | Think Kadane's |
|----------|---------------|
| "Maximum subarray sum" | ✅ CLASSIC |
| "Largest sum contiguous" | ✅ KADANE'S |
| "Max sum any subarray" | ✅ KADANE'S |
| "Contiguous elements" | ✅ (if max sum) |
| "At least one element" | ✅ KADANE'S |

---

## 📝 GENERIC TEMPLATE (Write 5x!)

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
int kadanes(vector<int>& arr) {
    // Step 1: Initialize with first element
    int max_ending_here = arr[0];  // Local max (ending at current)
    int max_so_far = arr[0];       // Global max (best seen)
    
    // Step 2: Process remaining elements
    for (int i = 1; i < arr.size(); i++) {
        // Step 3: KEY DECISION - Extend or Start Fresh?
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
                              ↑              ↑
                        Start new      Extend previous
        
        // Step 4: Update global maximum
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    // Step 5: Return best sum
    return max_so_far;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 🔄 ALTERNATIVE TEMPLATE (Reset if Negative!)

```cpp
// "If sum goes negative, RESET!" Approach
int kadanes(vector<int>& arr) {
    int sum = 0;              // Current running sum
    int ans = INT_MIN;        // Best answer
    
    for (int i = 0; i < arr.size(); i++) {
        
        if (sum >= 0) {
            sum = sum + arr[i];    // Positive? Keep adding
        } else {
            sum = arr[i];          // Negative? Start fresh
        }
        
        ans = max(ans, sum);
    }
    
    return ans;
}
```

**Time:** O(n) | **Space:** O(1)

**When to use:** If if-else feels more natural than max()!

**Key Logic:** "If my sum went negative, DISCARD and restart!"

---

## 🎯 WHICH VERSION TO USE?

| Standard Version | Alternative Version |
|-----------------|---------------------|
| `max(arr[i], sum + arr[i])` | `if (sum >= 0)` |
| Max-based thinking | If-else logic |
| "Pick larger option" | "Reset if negative" |
| ✅ Both give same result! | ✅ Use what feels natural! |

---

## 🎯 THE BIG IDEA

```
At each position, ask:
"Should I ADD this to my previous sum,
 OR should I START FRESH from here?"

Pick whichever gives LARGER result!

max_ending_here: Runner carrying weight
    → If weight too heavy (negative), DROP IT!
    
max_so_far: Judge watching
    → Records BEST performance seen!
```

---

## 💪 MANTRA (Say 10x!)

**"Extend or Start Fresh - whichever is LARGER!"**

**"max_ending_here = Current decision"**

**"max_so_far = Best result remembered"**

---

## 🎨 5 PROBLEM PATTERNS

### **Pattern 1: BASIC KADANE'S** ⭐⭐⭐⭐⭐

**Problem:** Maximum subarray sum

**Key:** Extend or start fresh at each step

**Template:**
```cpp
int maxSum = arr[0], curSum = arr[0];
for (int i = 1; i < n; i++) {
    curSum = max(arr[i], curSum + arr[i]);
    maxSum = max(maxSum, curSum);
}
return maxSum;
```

**Example:** `[-2,1,-3,4,-1,2,1,-5,4]` → `6`

---

### **Pattern 2: WITH INDICES** ⭐⭐⭐⭐⭐

**Problem:** Return start and end indices

**Key:** Track `temp_start` when starting fresh

**Additional Tracking:**
```cpp
int start = 0, end = 0, temp_start = 0;

if (arr[i] > curSum + arr[i]) {
    temp_start = i;  // Starting fresh
}

if (curSum > maxSum) {
    start = temp_start;
    end = i;
}
```

---

### **Pattern 3: CIRCULAR SUBARRAY** ⭐⭐⭐⭐

**Problem:** Array is circular (can wrap around)

**Key:** Max = max(normal_max, total - min_subarray)

**Template:**
```cpp
int normalMax = kadanes(arr);  // Regular
int minSubarray = kadanes_min(arr);  // Minimum
int total = sum(arr);

if (normalMax < 0) return normalMax;  // All negative
return max(normalMax, total - minSubarray);
```

**Example:** `[5,-3,5]` → `10` (circular `[5,5]`)

---

### **Pattern 4: PRODUCT SUBARRAY** ⭐⭐⭐⭐

**Problem:** Maximum product (not sum!)

**Key:** Track BOTH max and min (negative × negative = positive!)

**Template:**
```cpp
int maxProd = arr[0], minProd = arr[0];

for (int i = 1; i < n; i++) {
    if (arr[i] < 0) swap(maxProd, minProd);  // Sign flip!
    
    maxProd = max(arr[i], maxProd * arr[i]);
    minProd = min(arr[i], minProd * arr[i]);
}
```

**Example:** `[2,3,-2,4]` → `6` (product `[2,3]`)

---

### **Pattern 5: AFTER ONE DELETION** ⭐⭐⭐⭐

**Problem:** Can delete at most one element

**Key:** Two states - with/without deletion

**Template:**
```cpp
int without_del = arr[0];  // No deletion used
int with_del = 0;          // One deletion used

for (int i = 1; i < n; i++) {
    new_with = max(without_del, with_del + arr[i]);
    new_without = max(arr[i], without_del + arr[i]);
    
    without_del = new_without;
    with_del = new_with;
}

return max(without_del, with_del);
```

**Example:** `[1,-2,0,3]` → `4` (delete `-2`)

---

## 📊 DECISION TREE

```
START: See "maximum sum contiguous"
    ↓
Q: Just basic max sum?
    ↓
YES → PATTERN 1: Basic Kadane's

Q: Need indices too?
    ↓
YES → PATTERN 2: Track start/end

Q: Circular array?
    ↓
YES → PATTERN 3: Total - Min

Q: Product instead of sum?
    ↓
YES → PATTERN 4: Track max & min

Q: Can delete one element?
    ↓
YES → PATTERN 5: Two states DP
```

---

## 🎓 DRY RUN EXAMPLE

**Array:** `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`

```
Position | arr[i] | Decision        | max_ending | max_so_far
─────────┼────────┼─────────────────┼────────────┼───────────
0        | -2     | Start           | -2         | -2
1        | 1      | Start fresh! ✨ | 1          | 1
2        | -3     | Extend          | -2         | 1
3        | 4      | Start fresh! ✨ | 4          | 4
4        | -1     | Extend          | 3          | 4
5        | 2      | Extend          | 5          | 5
6        | 1      | Extend          | 6          | 6 ✅ BEST!
7        | -5     | Extend          | 1          | 6
8        | 4      | Extend          | 5          | 6

Final Answer: 6
Subarray: [4, -1, 2, 1] (indices 3 to 6)
```

**Key Observations:**
- Started fresh at i=1 (dropped -2)
- Started fresh at i=3 (dropped negative sum)
- Extended from i=3 to i=6 (built maximum)
- Maintained best = 6 even when sum decreased

---

## ⏱️ COMPLEXITY CHEAT SHEET

| Pattern | Time | Space | Key Idea |
|---------|------|-------|----------|
| Basic | O(n) | O(1) | Extend or start |
| With Indices | O(n) | O(1) | Track positions |
| Circular | O(n) | O(1) | Total - min |
| Product | O(n) | O(1) | Track max & min |
| After Deletion | O(n) | O(1) | Two DP states |

---

## 🎯 TOP 5 PROBLEMS (Target Times)

1. **Maximum Subarray** - 5 min ⭐⭐⭐⭐⭐
2. **Maximum Circular** - 8 min ⭐⭐⭐⭐
3. **Maximum Product** - 10 min ⭐⭐⭐⭐
4. **With Indices** - 6 min ⭐⭐⭐⭐⭐
5. **After Deletion** - 12 min ⭐⭐⭐⭐

---

## 🎤 INTERVIEW SCRIPT

**Recognition:**
> "Sir, I see we need maximum sum of contiguous subarray. This is classic Kadane's algorithm - O(n) time, O(1) space!"

**Approach:**
> "At each position, I decide: extend previous subarray OR start fresh. I pick whichever gives larger sum. I track local max (ending here) and global max (best seen)."

**Complexity:**
> "Time O(n) - single pass. Space O(1) - only two variables!"

---

## 💪 MUSCLE MEMORY DRILLS

### **Drill 1: Write Template Blind (5 min)**

Close this file. Write basic Kadane's from memory.  
**Repeat 5 times until automatic!**

---

### **Drill 2: Pattern Recognition (3 sec each)**

```
1. "Find max sum contiguous subarray"
   → BASIC KADANE'S ✅

2. "Max sum, array is circular"
   → CIRCULAR (Total - Min) ✅

3. "Max product of subarray"
   → PRODUCT (Track max & min) ✅

4. "Max sum, can delete one element"
   → AFTER DELETION (Two states) ✅
```

---

### **Drill 3: Dry Run Practice (10 min)**

Pick any array. Trace by hand:
```
arr = [your_array]

Step 1: Initialize
Step 2: For each element, decide extend or start
Step 3: Track max_ending_here and max_so_far
Step 4: Verify final answer
```

---

## 💡 MEMORY HOOKS

### **Hook 1: The Runner 🏃**

**max_ending_here** = Runner carrying backpack
- If backpack too heavy (negative sum) → DROP IT!
- If manageable → KEEP CARRYING

**max_so_far** = Referee watching
- Records BEST performance
- Doesn't care about current struggle

---

### **Hook 2: The Decision Point 🤔**

At each step, you're at a fork:
- **Left path:** Continue with current journey (extend)
- **Right path:** Start fresh journey from here (restart)

Pick path with HIGHER reward!

---

### **Hook 3: The Accumulator 💰**

Think of collecting money:
- If your wallet (sum) goes negative, RESET!
- Start fresh with current coin
- Always remember RICHEST moment!

---

## ✅ PRE-INTERVIEW CHECKLIST (15 min before)

**Concepts:**
- [ ] Can recognize Kadane's in 3 seconds
- [ ] Know 5 pattern variations
- [ ] Understand why it's O(n)

**Template:**
- [ ] Write basic Kadane's from memory (2 min)
- [ ] Explain "extend or start fresh" logic

**Dry Run:**
- [ ] Can trace `[-2,1,-3,4,-1,2,1,-5,4]` by hand
- [ ] Identify where we start fresh vs extend

**Mental:**
- [ ] Confident, templates automatic! 💪

---

## 🔥 GOLDEN RULES

1. **"Extend or Start - pick LARGER!"**
2. **"max_ending_here = local decision"**
3. **"max_so_far = global champion"**
4. **"Circular? Think: Total - Minimum"**
5. **"Product? Track BOTH max and min!"**

---

## 🚀 5-DAY MASTERY PATH

| Day | Focus | Goal |
|-----|-------|------|
| 1 | Basic Kadane's | Write template 5x, solve 3 problems |
| 2 | With Indices | Add tracking, solve 2 problems |
| 3 | Circular | Learn total-min trick, 2 problems |
| 4 | Product | Master max/min tracking, 2 problems |
| 5 | All Patterns | Mixed practice, 5 problems in 40 min |

---

## 🎯 ONE-PAGE PRINTABLE SUMMARY

```
╔══════════════════════════════════════════════════════════╗
║           KADANE'S ALGORITHM - CHEAT SHEET              ║
╚══════════════════════════════════════════════════════════╝

📌 RECOGNITION (3 questions):
   Q1: Maximum SUM? ✅
   Q2: CONTIGUOUS subarray? ✅
   Q3: Has NEGATIVES? ✅
   If all YES → KADANE'S!

📌 GENERIC TEMPLATE:
   
   int maxSum = arr[0], curSum = arr[0];
   
   for (int i = 1; i < n; i++) {
       curSum = max(arr[i], curSum + arr[i]);
                    ↑           ↑
                Start new   Extend old
       
       maxSum = max(maxSum, curSum);
   }
   
   return maxSum;
   
   Mantra: "Extend or Start - pick LARGER!"
   Time: O(n) | Space: O(1)

📌 5 PATTERNS:

   1. BASIC: Just max sum
      → Standard template
   
   2. WITH INDICES: Return start/end
      → Track temp_start
   
   3. CIRCULAR: Array wraps around
      → max(normal, total - min_subarray)
   
   4. PRODUCT: Max product not sum
      → Track max AND min (negative flip!)
   
   5. AFTER DELETION: Can delete one
      → Two states: with_del, without_del

📌 DRY RUN [-2,1,-3,4,-1,2,1,-5,4]:
   
   i=0: cur=-2, max=-2
   i=1: cur=1 (start!), max=1
   i=2: cur=-2 (extend), max=1
   i=3: cur=4 (start!), max=4
   i=4-6: cur=6 (extend!), max=6 ✅
   Answer: 6

📌 COMPLEXITY:
   All patterns: O(n) time, O(1) space

📌 DECISION TREE:
   Max sum + contiguous? → KADANE'S
   Circular? → Total - min
   Product? → Track max & min
   Delete one? → Two DP states

📌 MANTRAS:
   • "Extend or Start - pick larger!"
   • "Local decision, global champion"
   • "Negative pulls down? Drop it!"

📌 TARGET TIMES:
   Basic - 5 min | Circular - 8 min
   Product - 10 min | Deletion - 12 min

╔══════════════════════════════════════════════════════════╗
║  "At each step: Extend OR Start Fresh - pick LARGER!" 🔥║
╚══════════════════════════════════════════════════════════╝
```

---

**🎯 You got this! Kadane's is muscle memory now! 💪**

**All the best! 🚀**

---

*Print this page. Review daily. Master in 5 days!*
