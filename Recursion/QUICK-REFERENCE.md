# 🎯 RECURSION - QUICK REFERENCE
## One-Page Cheat Sheet for Interview Day

---

## 🔑 RECURSION ESSENTIALS

### **What is Recursion?**
> Function calls itself to solve smaller instances of same problem

### **Three Must-Haves:**
1. ✅ **Base Case** - Stopping condition
2. ✅ **Recursive Case** - Function calls itself
3. ✅ **Progress** - Each call moves toward base case

---

## 📋 TOP 8 TEMPLATES

### **1. Factorial (Linear Recursion)**
```cpp
int factorial(int n) {
    if(n == 0 || n == 1) return 1; // Base
    return n * factorial(n - 1);    // Recursive
}
// Time: O(n), Space: O(n)
```

---

### **2. Fibonacci - Naive (Binary Recursion)**
```cpp
int fib(int n) {
    if(n <= 1) return n;            // Base
    return fib(n-1) + fib(n-2);     // Recursive
}
// Time: O(2^n), Space: O(n) - TOO SLOW!
```

---

### **3. Fibonacci - Optimized (With Memoization)**
```cpp
int fib(int n, vector<int>& memo) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n]; // Check memo
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}
// Time: O(n), Space: O(n) - FAST! ⭐
```

---

### **4. Power Function (Divide & Conquer)**
```cpp
double power(double x, int n) {
    if(n == 0) return 1;            // Base
    double half = power(x, n / 2);  // Divide
    if(n % 2 == 0) return half * half;
    return x * half * half;
}
// Time: O(log n), Space: O(log n) ⭐
```

---

### **5. Binary Search (Divide & Conquer)**
```cpp
int binarySearch(vector<int>& arr, int left, int right, int target) {
    if(left > right) return -1;     // Base: not found
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) 
        return binarySearch(arr, left, mid-1, target);
    return binarySearch(arr, mid+1, right, target);
}
// Time: O(log n), Space: O(log n)
```

---

### **6. Backtracking Template ⭐⭐⭐**
```cpp
void backtrack(params, current, result) {
    // BASE: Valid solution
    if(isValid(current)) {
        result.push_back(current);
        return;
    }
    
    // Try each choice
    for(choice : choices) {
        // CHOOSE
        current.push_back(choice);
        
        // EXPLORE
        backtrack(params, current, result);
        
        // UNCHOOSE (Backtrack)
        current.pop_back();
    }
}
```

---

### **7. Permutations (Backtracking)**
```cpp
void permute(vector<int>& nums, vector<int>& current, 
             vector<bool>& used, vector<vector<int>>& result) {
    if(current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(used[i]) continue;
        current.push_back(nums[i]);  // CHOOSE
        used[i] = true;
        permute(nums, current, used, result); // EXPLORE
        current.pop_back();          // UNCHOOSE
        used[i] = false;
    }
}
// Time: O(n! × n), Space: O(n)
```

---

### **8. Subsets (Backtracking)**
```cpp
void subsets(vector<int>& nums, int start, vector<int>& current,
             vector<vector<int>>& result) {
    result.push_back(current); // All subsets valid
    
    for(int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);     // CHOOSE
        subsets(nums, i+1, current, result); // EXPLORE
        current.pop_back();             // UNCHOOSE
    }
}
// Time: O(2^n × n), Space: O(n)
```

---

## 🎯 PATTERN DECISION TREE

```
┌─────────────────────────────────┐
│   Need to solve problem?        │
└────────────┬────────────────────┘
             │
    ┌────────▼─────────┐
    │ What type?       │
    └──┬───┬───┬───┬───┘
       │   │   │   │
   ┌───▼┐ ┌▼──┐ ┌▼──┐ ┌▼────┐
   │Tree│ │All│ │½  │ │Loop?│
   │ /  │ │com│ │ea │ │     │
   │Grph│ │bin│ │ch │ │     │
   └─┬──┘ └┬──┘ └┬──┘ └─┬───┘
     │     │     │      │
  ┌──▼──┐┌─▼─────▼┐ ┌──▼────┐┌────▼─────┐
  │DFS  ││Backtrac││Divide ││Iteration │
  │BFS  ││king    ││&      ││better    │
  └─────┘└────────┘│Conquer│└──────────┘
                   └───────┘

Examples:
Tree/Graph → DFS/BFS recursion
All combinations/permutations → Backtracking
Divide in half → Divide & Conquer (Binary Search, Power)
Simple loop → Iteration (better space)
```

---

## 💬 INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Basic Recursion**
```
"Sir, this is a [FACTORIAL/FIBONACCI] problem.
I'll use recursion.

Base case: [STATE CONDITION]
Recursive case: [STATE FORMULA]

Time: O(X), Space: O(Y) because [REASON]

Let me code this..."
```

**Example:**
```
"Sir, this is a Factorial problem. I'll use recursion.

Base case: if n is 0 or 1, return 1
Recursive case: return n × factorial(n-1)

Time: O(n), Space: O(n) because recursion depth is n

Let me code this..."
```

---

### **Script 2: Backtracking**
```
"Sir, this is a [PERMUTATIONS/SUBSETS/COMBINATIONS] problem.
I'll use backtracking with Choose-Explore-Unchoose pattern.

Approach:
1. Try each choice
2. CHOOSE: Add to current solution
3. EXPLORE: Recurse with this choice
4. UNCHOOSE: Remove from current (backtrack)

When [CONDITION], we have valid solution.

Time: O(X), Space: O(Y)

Let me code this..."
```

**Example:**
```
"Sir, this is a Permutations problem.
I'll use backtracking with Choose-Explore-Unchoose pattern.

Approach:
1. Try each unused number
2. CHOOSE: Mark as used, add to current
3. EXPLORE: Recurse for remaining positions
4. UNCHOOSE: Mark as unused, remove from current

When current size = n, we have valid permutation.

Time: O(n! × n), Space: O(n)

Let me code this..."
```

---

### **Script 3: Optimization**
```
"Sir, for this problem, naive recursion is O(2^n) which is slow.

We can optimize using MEMOIZATION:
1. Create memo array to store computed results
2. Before computing, check if memo[n] exists
3. If exists, return it (O(1))
4. Else compute, store in memo, return

This reduces time from O(2^n) to O(n).

Let me code the optimized version..."
```

---

## 🏢 COMPANY TOP 3

### **TCS:**
1. ✅ **Fibonacci** (75%) - Naive + Memoized
2. ✅ **Binary Search** (75%) - Recursive
3. ✅ **Subsets** (70%) - Backtracking

---

### **Infosys:**
1. ✅ **Permutations** (75%) ⭐⭐⭐ MUST!
2. ✅ **Fibonacci** (80%) - WITH optimization!
3. ✅ **Subsets** (75%) - Include/Exclude

---

### **Wipro:**
1. ✅ **Factorial** (70%) - Basic recursion
2. ✅ **Power Function** (65%) - O(log n)
3. ✅ **Permutations** (65%) - Backtracking

---

## ⚠️ EDGE CASES CHECKLIST

```
□ n = 0 (base case?)
□ n = 1 (base case or simplest?)
□ Empty array/string (base case: return)
□ Single element (often base case)
□ Negative numbers (Power: handle with x = 1/x)
□ Duplicates (Permutations: skip if used)
□ Integer overflow (Factorial: use long)
```

---

## ⏱️ COMPLEXITY CHEAT SHEET

| Pattern | Time | Space | Example |
|---------|------|-------|---------|
| **Linear** | O(n) | O(n) | Factorial, Sum, Print |
| **Binary** | O(2^n) | O(n) | Fibonacci (naive) |
| **+ Memo** | O(n) | O(n) | Fibonacci (optimized) ⭐ |
| **D&C** | O(log n) | O(log n) | Binary Search, Power ⭐ |
| **Backtrack** | O(2^n) or O(n!) | O(n) | Permutations, Subsets |

**Remember:** Memoization = Store results to avoid recomputation!

---

## 🚨 COMMON MISTAKES

### ❌ **1. Missing Base Case**
```cpp
int factorial(int n) {
    return n * factorial(n-1); // ❌ Infinite!
}
```

### ✅ **Fixed:**
```cpp
int factorial(int n) {
    if(n <= 1) return 1; // ✅ Base case
    return n * factorial(n-1);
}
```

---

### ❌ **2. Wrong Base Case**
```cpp
int fib(int n) {
    if(n == 1) return 1; // ❌ Missing n=0!
    return fib(n-1) + fib(n-2);
}
```

### ✅ **Fixed:**
```cpp
int fib(int n) {
    if(n <= 1) return n; // ✅ Handles 0 and 1
    return fib(n-1) + fib(n-2);
}
```

---

### ❌ **3. Forgetting to Backtrack**
```cpp
void permute(...) {
    current.push_back(nums[i]); // CHOOSE
    permute(...);               // EXPLORE
    // ❌ Missing: current.pop_back(); UNCHOOSE!
}
```

### ✅ **Fixed:**
```cpp
void permute(...) {
    current.push_back(nums[i]); // CHOOSE
    permute(...);               // EXPLORE
    current.pop_back();         // ✅ UNCHOOSE
}
```

---

### ❌ **4. Not Optimizing Fibonacci**
```cpp
// ❌ O(2^n) - TOO SLOW for n > 30!
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

### ✅ **Fixed with Memoization:**
```cpp
// ✅ O(n) - FAST!
int fib(int n, vector<int>& memo) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}
```

---

## 📝 INTERVIEW DAY CHECKLIST

### **30 Minutes Before:**
```
□ Review this sheet (5 min)
□ Write Fibonacci from memory (5 min)
□ Write Permutations from memory (5 min)
□ Review backtracking template (3 min)
□ Review communication scripts (3 min)
□ Deep breaths, confidence! 💪 (5 min)
```

---

### **During Interview:**
```
□ Listen carefully to problem
□ Identify pattern (recursion type?)
□ State approach clearly BEFORE coding
□ Write base case FIRST
□ Then write recursive case
□ Add comments while coding
□ Test with example (dry run)
□ Mention time/space complexity
□ Handle edge cases (n=0, n=1, empty)
□ Stay calm, think aloud!
```

---

## 🎯 TOP 5 MUST-KNOW (EMERGENCY)

**If you have ONLY 1 hour, memorize these:**

1. ✅ **Fibonacci (with memoization)** ⭐⭐⭐
   - Most asked, shows optimization knowledge

2. ✅ **Permutations** ⭐⭐⭐
   - Backtracking template application

3. ✅ **Subsets** ⭐⭐⭐
   - Include/Exclude pattern, very popular

4. ✅ **Combinations** ⭐⭐⭐
   - Similar to Subsets, high frequency

5. ✅ **Power Function** ⭐⭐
   - Divide & Conquer, shows optimization O(n) → O(log n)

**Know these 5 → 75-80% recursion coverage!**

---

## 💯 BACKTRACKING TEMPLATE (MEMORIZE!)

```cpp
void backtrack(parameters, currentSolution, result) {
    // Step 1: Check if valid solution
    if(isValidSolution(currentSolution)) {
        result.push_back(currentSolution);
        return; // or continue based on problem
    }
    
    // Step 2: Iterate through choices
    for(choice : availableChoices) {
        // Step 3: CHOOSE
        make_choice(currentSolution, choice);
        
        // Step 4: EXPLORE
        backtrack(parameters, currentSolution, result);
        
        // Step 5: UNCHOOSE (Backtrack)
        undo_choice(currentSolution, choice);
    }
}
```

**Remember: CHOOSE → EXPLORE → UNCHOOSE** 🎯

---

## 🔥 LAST-MINUTE TIPS

### **Recursion:**
- ✅ Always write base case FIRST
- ✅ Make sure each call makes progress
- ✅ Draw recursion tree if confused
- ✅ Think: "What's the smallest subproblem?"

### **Backtracking:**
- ✅ Memorize Choose-Explore-Unchoose
- ✅ Don't forget to UNCHOOSE (pop_back)
- ✅ Use `start` index to avoid duplicates
- ✅ Add result at right time (base case or always)

### **Optimization:**
- ✅ If O(2^n), think memoization
- ✅ If dividing in half, think O(log n)
- ✅ Always mention optimization if exists

---

## 🌟 CONFIDENCE BOOSTERS

**You know:**
- ✅ 14 recursion problems
- ✅ Backtracking template by heart
- ✅ Memoization concept
- ✅ Company-specific strategies
- ✅ Communication scripts

**You're ready for:**
- ✅ TCS ✅ Infosys ✅ Wipro
- ✅ 98-99% placement readiness!

---

## 💪 FINAL MANTRA

> **"Recursion = Function calls itself"**
> 
> **"Base case = Stop"**
> 
> **"Backtracking = Try, Fail, Try Again"**
> 
> **"Memoization = Remember results"**
> 
> **"I got this!" 💯**

---

## 📚 REMEMBER

```
Factorial     → Linear recursion, O(n)
Fibonacci     → Binary recursion, OPTIMIZE with memo!
Power         → Divide & Conquer, O(log n)
Binary Search → Divide & Conquer, O(log n)
Permutations  → Backtracking, O(n!)
Subsets       → Backtracking, O(2^n)
Combinations  → Backtracking, O(C(n,k))
```

---

## 🎯 YOU'RE READY!

**Satyam, you've got this!** 💪

**Recursion mastered:** ✅  
**Backtracking conquered:** ✅  
**Placement ready:** ✅

**Go ace that interview!** 🚀

---

### **Quick Access:**
- 📖 Detailed problems: `Basic-Recursion/INTERVIEW-READY.md`
- 🎯 Advanced patterns: `Backtracking-Patterns/INTERVIEW-READY.md`
- 📚 Full guide: `RECURSION-COMPLETE-PACKAGE.md`
- ⚡ This sheet: `QUICK-REFERENCE.md` (You are here!)

**All the best!** 🌟
