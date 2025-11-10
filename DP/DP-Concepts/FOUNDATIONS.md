# 🎯 DYNAMIC PROGRAMMING CONCEPTS - INTERVIEW READY
## What You MUST Know Before Solving Problems

---

## 📊 DP FREQUENCY IN INTERVIEWS

```
⭐⭐⭐ MUST KNOW (Asked 70%+ if DP topic)
```

**Overall Frequency:** TCS 60%, Infosys 75%, Wipro 55%

---

## 🔥 FUNDAMENTAL 1: WHAT IS DYNAMIC PROGRAMMING? ⭐⭐⭐

### **Definition:**
Solving complex problems by breaking into **overlapping subproblems** and storing results (memoization/tabulation)

### **Key Insight:**
```
WITHOUT DP:
fib(5) = fib(4) + fib(3)
       = (fib(3) + fib(2)) + (fib(2) + fib(1))
       
Same fib(3), fib(2) calculated MULTIPLE times! ❌

WITH DP:
Calculate fib(3) ONCE, store result, reuse! ✅
```

### **Real Example:**

```cpp
// WITHOUT DP (Exponential - SLOW)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);  // Recalculates many times
}
// Time: O(2^n) ← Very slow!
// fib(40) takes seconds

// WITH DP - MEMOIZATION (Fast)
int fib(int n, unordered_map<int, int>& memo) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];  // Already calculated
    
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}
// Time: O(n) ← Linear!
// fib(40) instant

// WITH DP - TABULATION (Iterative, cleaner)
int fib(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n+1);
    dp[0] = 0, dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];  // Build bottom-up
    }
    
    return dp[n];
}
// Time: O(n), Space: O(n)
```

---

## 🔥 FUNDAMENTAL 2: MEMOIZATION vs TABULATION ⭐⭐⭐

### **MEMOIZATION (Top-Down)**

```cpp
map<int, int> memo;  // Store results

int solve(int n) {
    if (base_case) return value;
    if (memo.count(n)) return memo[n];  // Already solved
    
    int result = ... // Use subproblems
    memo[n] = result;
    return result;
}
```

**When to use:**
- Recursive solution is clearer
- Not all subproblems needed
- Medium complexity

**Example:** Tree DP, Coin Change

---

### **TABULATION (Bottom-Up)**

```cpp
vector<int> dp(n+1);

for (int i = 1; i <= n; i++) {
    dp[i] = ... // Use dp[i-1], dp[i-2], etc.
}

return dp[n];
```

**When to use:**
- Iterative approach clearer
- All subproblems needed
- Better space optimization

**Example:** Fibonacci, Knapsack

---

### **Example: Both Approaches Same Problem**

```cpp
// Problem: Minimum coins to make amount n

// MEMOIZATION (Top-Down)
int minCoins(int amount, vector<int>& coins, unordered_map<int, int>& memo) {
    if (amount == 0) return 0;
    if (memo.count(amount)) return memo[amount];
    
    int minCount = INT_MAX;
    for (int coin : coins) {
        if (coin <= amount) {
            int result = minCoins(amount - coin, coins, memo);
            minCount = min(minCount, result + 1);
        }
    }
    
    return memo[amount] = minCount;
}

// TABULATION (Bottom-Up)
int minCoins(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

---

## 🔥 FUNDAMENTAL 3: WHEN TO USE DP? ⭐⭐⭐

### **Check these 2 conditions:**

```
1. OVERLAPPING SUBPROBLEMS
   Can you break problem into same subproblems?
   Example: fib(5) = fib(4) + fib(3)
            fib(4) = fib(3) + fib(2)
            fib(3) appears twice! ✓

2. OPTIMAL SUBSTRUCTURE
   Does optimal solution use optimal solutions of subproblems?
   Example: Shortest path(A→C) = Shortest path(A→B) + Shortest path(B→C) ✓

If both YES → Use DP ✓
```

### **Non-DP Problems (Even if recursive):**

```
Binary Search: Only one branch needed, not overlapping ✗
Merge Sort: Optimal substructure? Yes, but not overlapping ✗
Greedy: Overlapping? Maybe, but greedy choice works ✗
```

---

## 🔥 FUNDAMENTAL 4: DP TABLE STATES ⭐⭐

### **1D DP (Simple)**
```cpp
vector<int> dp(n);
dp[i] = answer for index i
```

**Example:** Fibonacci, Climbing Stairs, House Robber

---

### **2D DP (Common)**
```cpp
vector<vector<int>> dp(n, vector<int>(m));
dp[i][j] = answer for i rows, j columns
```

**Example:** Knapsack, LCS, Edit Distance, Matrix Path

---

### **3D DP (Complex, skip for now)**
```cpp
vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k)));
```

---

## 🔥 FUNDAMENTAL 5: STATE TRANSITION ⭐⭐⭐

### **The KEY to solving DP:**
```
1. Define dp[i] = what does it represent?
2. Find relation = dp[i] = f(dp[i-1], dp[i-2], ...)
3. Base case = what's dp[0], dp[1]?
4. Build solution
```

### **Example 1: Fibonacci**
```cpp
// Define: dp[i] = ith fibonacci number
// Relation: dp[i] = dp[i-1] + dp[i-2]
// Base: dp[0]=0, dp[1]=1
// Build:
vector<int> dp(n+1);
dp[0] = 0; dp[1] = 1;
for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
```

### **Example 2: Coin Change**
```cpp
// Define: dp[i] = minimum coins to make amount i
// Relation: dp[i] = min(dp[i-coin] + 1) for all coins
// Base: dp[0] = 0 (no coins needed for 0)
// Build:
vector<int> dp(amount+1, INT_MAX);
dp[0] = 0;
for (int i = 1; i <= amount; i++) {
    for (int coin : coins) {
        if (coin <= i) {
            dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
}
return dp[amount];
```

### **Example 3: LCS (Longest Common Subsequence)**
```cpp
// Define: dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1]
// Relation: 
//   if text1[i-1] == text2[j-1]: dp[i][j] = dp[i-1][j-1] + 1
//   else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// Base: dp[0][j] = 0, dp[i][0] = 0
// Build: 2D loop
```

---

## 🔥 FUNDAMENTAL 6: SPACE OPTIMIZATION ⭐⭐

### **Many DP only need previous row/column:**

```cpp
// BEFORE (2D, O(n*m) space)
vector<vector<int>> dp(n, vector<int>(m));

// AFTER (1D, O(m) space)
vector<int> prev(m), curr(m);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        curr[j] = ... // Use prev[j], prev[j-1], curr[j-1]
    }
    prev = curr;
}
```

**Not needed for this module** (focus on correctness first)

---

## 🎯 DP PROBLEM TYPES YOU'LL LEARN

### **Easy DP (3 hours) - Day 1:**
1. Fibonacci + Memoization
2. Climbing Stairs
3. Coin Change (minimum coins)
4. House Robber

### **Medium DP (3 hours) - Day 2-3:**
1. 0/1 Knapsack (CLASSIC)
2. Longest Increasing Subsequence (LIS)
3. Longest Common Subsequence (LCS)
4. Edit Distance

---

## ⚠️ COMMON MISTAKES

```cpp
❌ WRONG: Forgetting base case
int dp[n];
dp[0] = dp[0] + ... // Undefined!

✅ RIGHT: Initialize base cases
dp[0] = 0, dp[1] = 1;  // or appropriate values
```

```cpp
❌ WRONG: Wrong recurrence relation
dp[i] = dp[i-1] + dp[i-2] + ...  // Random formula!

✅ RIGHT: Think about what each state means
dp[i] = minimum coins to make i
dp[i] = min(dp[i-coin] + 1) for all coins ✓
```

```cpp
❌ WRONG: Not checking bounds
dp[i] = dp[i-coin] // What if i-coin < 0?

✅ RIGHT: Bounds check
if (coin <= i) {
    dp[i] = min(dp[i], dp[i-coin] + 1);
}
```

---

## ✅ FINAL CHECKLIST

```
Understanding:
☐ Know why DP works (overlapping subproblems)
☐ Know memoization vs tabulation difference
☐ Understand state definition
☐ Understand state transition

Implementation:
☐ Can write base cases correctly
☐ Can write recurrence relation
☐ Can build DP table
☐ Know time/space complexity

Interview:
☐ Can identify DP problems
☐ Can define state clearly
☐ Can explain approach before coding
☐ Can optimize space if needed
```

---

## 🎓 INTERVIEW COMMUNICATION

### Q: "Why use DP here?"

> "Sir, this problem has overlapping subproblems. For example, coin change for amount 5 and 6 both use coin change for amount 3. By storing results, we avoid recalculation.
>
> Without DP: Exponential time
> With DP: Polynomial time
>
> I'll use memoization/tabulation."

---

**You're DP Foundation Ready!** 🚀

**Next:** Easy patterns (Fibonacci, Stairs, Coin Change, House Robber)

**All the best!** 💪
