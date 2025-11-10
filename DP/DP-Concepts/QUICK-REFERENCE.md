# ⚡ DP CONCEPTS - QUICK REFERENCE
## Just Before Interview: Memory Jogger

---

## 🎯 WHEN TO USE DP?

```
✅ Use DP if:
1. Problem has overlapping subproblems (recalculate same state)
2. Optimal substructure (solution built from optimal solutions)

❌ Skip DP if:
- Can't find overlapping subproblems (greedy/direct logic works)
- Too many states (exponential memory)
```

---

## 🔄 MEMOIZATION TEMPLATE

```cpp
map<State, Answer> memo;

function<ReturnType(State)> solve = [&](State state) {
    if (memo.find(state) != memo.end()) {
        return memo[state];  // Already calculated
    }
    
    if (base_case) {
        return memo[state] = base_answer;
    }
    
    ReturnType ans = ...;  // Try all choices
    // ...calculations...
    
    return memo[state] = ans;
};

return solve(initial_state);
```

**Approach:** Recursive top-down with caching

---

## 📊 TABULATION TEMPLATE

```cpp
vector<datatype> dp(n);  // 1D

// For 2D: vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

// Initialize base cases
dp[0] = base_value;

// Fill table bottom-up
for (int i = 1; i < n; i++) {
    dp[i] = ...calculate from previous states...
}

return dp[n-1];
```

**Approach:** Iterative bottom-up, build solution

---

## 🔑 KEY DIFFERENCES

| Aspect | Memoization | Tabulation |
|--------|------------|-----------|
| **Approach** | Top-down | Bottom-up |
| **How** | Recursive + cache | Iterative |
| **When to use** | Think recursively | Think iteratively |
| **Complexity** | Same time, extra space for recursion | Same time, less overhead |
| **Easier for** | Natural recursion problems | Easier to optimize space |

---

## 📈 STATE TRANSITION FORMULA

```
Step 1: DEFINE THE STATE
  dp[i] = answer for input size i
  dp[i][j] = answer for 2D problem at (i,j)
  
Step 2: FIND THE RELATION
  What states lead to current state?
  Example: dp[i] = dp[i-1] + dp[i-2]  (Fibonacci)
  
Step 3: IDENTIFY BASE CASES
  What's the minimum input?
  Example: dp[0] = 1, dp[1] = 1
  
Step 4: BUILD THE SOLUTION
  Iterative: for loop from base to target
  Recursive: memoize and recurse
```

---

## 💾 SPACE OPTIMIZATION TRICK

### **Before:**
```cpp
vector<vector<int>> dp(n, vector<int>(m));  // O(n×m) space
```

### **After (2 prev rows):**
```cpp
vector<int> prev(m), curr(m);
// Use only 2 rows instead of n rows
```

### **After (Most Optimized):**
```cpp
vector<int> dp(m);
// Use single row, if you can loop in right order
```

---

## ⚠️ COMMON MISTAKES

```cpp
❌ Forget to initialize dp table
❌ Base case wrong or missing
❌ Recurrence relation off by one
❌ Integer overflow (use long long or INT_MAX checks)
❌ Not handling edge cases (empty input, n=1, etc.)
❌ Knapsack: Forward loop instead of reverse
❌ Coin change: Not checking if state is reachable
```

---

## 🎓 DP PROBLEMS BY DIFFICULTY

### **Easy (1D DP):**
- Fibonacci
- Climbing Stairs
- Coin Change
- House Robber

### **Medium (2D DP, Multi-choice):**
- 0/1 Knapsack
- LCS
- LIS
- Edit Distance
- Matrix Chain Multiplication

### **Hard (3D DP, Complex Logic):**
- Wildcard Matching
- Regular Expression Matching
- Maximum Rectangle in Histogram
- **[Skip these for placement - not priority]**

---

## ✅ FINAL CHECKLIST BEFORE INTERVIEW

- [ ] Read problem: Is it DP? (overlapping subproblems?)
- [ ] Define state: What does dp[i] represent?
- [ ] Write relation: How to reach dp[i]?
- [ ] Base cases: What are minimum inputs?
- [ ] Code memoization OR tabulation
- [ ] Verify with dry run (trace by hand)
- [ ] Check time/space complexity
- [ ] Handle edge cases (n=0, n=1, empty, overflow)
- [ ] Optimize space if needed

---

## 🚀 YOU'RE DP READY!

**Master these patterns and you're ready for ANY DP question in interviews!**

