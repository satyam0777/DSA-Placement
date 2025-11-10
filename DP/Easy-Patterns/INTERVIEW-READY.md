# 🎯 EASY DP PATTERNS - INTERVIEW READY
## Day 1: 4 Essential Easy Problems

---

## 📊 EASY DP FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 80%+ if Easy DP)
```

**Overall Frequency:** TCS 85%, Infosys 80%, Wipro 85%

**Why Easy DP?** Foundation for all medium/hard DP

---

## 🔥 PATTERN 1: FIBONACCI ⭐⭐⭐

### **Frequency:**
- TCS: 85% | Infosys: 75% | Wipro: 80%

### **Problem:**
Find nth fibonacci number

### **Without DP (Exponential):**

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
// fib(40) = several seconds (2^40 calls)
```

### **WITH DP - MEMOIZATION:**

```cpp
int fib(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];  // Already calculated
    
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

// Call:
vector<int> memo(n+1, -1);
return fib(n, memo);
```

### **WITH DP - TABULATION (Better):**

```cpp
int fib(int n) {
    if (n <= 1) return n;
    
    vector<int> dp(n+1);
    dp[0] = 0, dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
```

**Time:** O(n) | **Space:** O(n)

### **SPACE OPTIMIZED:**

```cpp
int fib(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

**Time:** O(n) | **Space:** O(1) ⭐

### **Interview Script:**

> "Sir, fib without DP recalculates same values multiple times.
>
> I'll use tabulation:
> - dp[i] = fibonacci(i)
> - dp[i] = dp[i-1] + dp[i-2]
> - Time: O(n), Space: O(1) if optimized"

---

## 🔥 PATTERN 2: CLIMBING STAIRS ⭐⭐⭐

### **Frequency:**
- TCS: 75% | Infosys: 85% | Wipro: 80%

### **Problem:**
You're at step 0. Reach step n. Each move: +1 or +2 steps. Count ways.

### **Example:**
```
n = 3
Paths:
1. Step 1 → Step 2 → Step 3
2. Step 1 → Step 3
3. Step 2 → Step 3

Answer: 3 ways

Notice: This is Fibonacci!
ways(3) = ways(2) + ways(1)
        = 2 + 1 = 3 ✓
```

### **Code:**

```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    
    vector<int> dp(n+1);
    dp[0] = 1;  // 1 way to stay at step 0
    dp[1] = 1;  // 1 way to reach step 1
    dp[2] = 2;  // 2 ways to reach step 2
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];  // From i-1 or i-2
    }
    
    return dp[n];
}
```

### **Space Optimized:**

```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    
    int prev2 = 1, prev1 = 2;
    
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

**Time:** O(n) | **Space:** O(1)

### **Dry Run:**

```
n = 4
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = dp[2] + dp[1] = 2 + 1 = 3
dp[4] = dp[3] + dp[2] = 3 + 2 = 5

Answer: 5 ways ✓
```

---

## 🔥 PATTERN 3: COIN CHANGE ⭐⭐⭐

### **Frequency:**
- TCS: 80% | Infosys: 85% | Wipro: 75%

### **Problem:**
Given coins and amount, find MINIMUM number of coins to make amount

### **Example:**
```
coins = [1, 2, 5]
amount = 5

Combinations:
- 5×(1 coin) = 5 coins
- 1×(2) + 3×(1) = 4 coins
- 1×(5) = 1 coin ← Minimum!

Answer: 1 coin
```

### **Code:**

```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // 0 coins needed for amount 0
    
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

### **Key Insight:**

```
dp[i] = minimum coins for amount i

For each amount i:
  For each coin:
    if coin can be used:
      dp[i] = min(dp[i], dp[i-coin] + 1)

Why? To make amount i, I can:
- Use a coin, then make remaining amount i-coin
- So: coins(i) = coins(i-coin) + 1
```

### **Dry Run:**

```
coins = [1, 2, 5], amount = 5

dp[0] = 0

i=1: coin 1 → dp[1] = dp[0] + 1 = 1
i=2: coin 1 → dp[2] = dp[1] + 1 = 2
     coin 2 → dp[2] = min(2, dp[0] + 1) = 1
i=3: coin 1 → dp[3] = dp[2] + 1 = 2
     coin 2 → dp[3] = min(2, dp[1] + 1) = 2
i=4: coin 1 → dp[4] = dp[3] + 1 = 3
     coin 2 → dp[4] = min(3, dp[2] + 1) = 2
i=5: coin 1 → dp[5] = dp[4] + 1 = 3
     coin 2 → dp[5] = min(3, dp[3] + 1) = 3
     coin 5 → dp[5] = min(3, dp[0] + 1) = 1 ✓

Answer: 1 ✓
```

**Time:** O(amount × coins) | **Space:** O(amount)

---

## 🔥 PATTERN 4: HOUSE ROBBER ⭐⭐⭐

### **Frequency:**
- TCS: 70% | Infosys: 75% | Wipro: 70%

### **Problem:**
Rob houses in line. Can't rob adjacent houses. Maximize total money.

### **Example:**
```
houses = [1, 2, 3, 1]

Options:
- Rob house 0, 2: 1 + 3 = 4 ← Maximum
- Rob house 0, 3: 1 + 1 = 2
- Rob house 1, 3: 2 + 1 = 3
- Rob house 1: 2
- Rob house 2: 3

Answer: 4 (rob houses 0 and 2)
```

### **Code:**

```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        // Rob current house + best from i-2
        // OR skip current house + best from i-1
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }
    
    return dp[n-1];
}
```

### **Key Insight:**

```
dp[i] = maximum money robbing houses 0..i

For each house i:
  Option 1: Rob house i → money[i] + dp[i-2]
  Option 2: Skip house i → dp[i-1]
  
dp[i] = max(option1, option2)
```

### **Space Optimized:**

```cpp
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int prev2 = 0, prev1 = 0;
    
    for (int money : nums) {
        int curr = max(money + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}
```

**Time:** O(n) | **Space:** O(1)

### **Dry Run:**

```
houses = [1, 2, 3, 1]

dp[0] = 1
dp[1] = max(1, 2) = 2
dp[2] = max(3 + 1, 2) = max(4, 2) = 4
dp[3] = max(1 + 2, 4) = max(3, 4) = 4

Answer: 4 ✓
```

---

## 📊 EASY DP COMPARISON TABLE

| Pattern | Time | Space | Type | When |
|---------|------|-------|------|------|
| **Fibonacci** | O(n) | O(1) | Top-down variant | Building intuition |
| **Climbing Stairs** | O(n) | O(1) | Classic DP | Easy question |
| **Coin Change** | O(n×m) | O(n) | Multi-coin variant | Very common |
| **House Robber** | O(n) | O(1) | Choose/Skip variant | Common variant |

---

## 🎯 COMPANY-WISE FOCUS

### **TCS (Easy DP 85%):**
1. Fibonacci (85%)
2. Climbing Stairs (75%)
3. Coin Change (80%)
4. House Robber (70%)

### **Infosys (Easy DP 80%):**
1. Climbing Stairs (85%)
2. Coin Change (85%)
3. House Robber (75%)
4. Fibonacci (75%)

### **Wipro (Easy DP 85%):**
1. Coin Change (75%)
2. Climbing Stairs (80%)
3. Fibonacci (80%)
4. House Robber (70%)

---

## ⚠️ CRITICAL MISTAKES

```cpp
❌ WRONG: Using INT_MAX without checking
dp[i] = min(dp[i], dp[i-coin] + 1);  // Can overflow!

✅ RIGHT: Check bounds
if (dp[i - coin] != INT_MAX) {
    dp[i] = min(dp[i], dp[i - coin] + 1);
}
```

```cpp
❌ WRONG: Forgetting base case
for (int i = 1; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];  // dp[0] never initialized
}

✅ RIGHT: Initialize base
dp[0] = 0; dp[1] = 1;  // or appropriate values
for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
}
```

---

## ✅ FINAL CHECKLIST

```
Fibonacci:
☐ Can code tabulation
☐ Know space optimization
☐ Understand why DP needed

Climbing Stairs:
☐ Can solve in O(n) time, O(1) space
☐ Understand recurrence

Coin Change:
☐ Can initialize correctly (INT_MAX)
☐ Can handle edge cases (no solution)
☐ Understand inner loop logic

House Robber:
☐ Understand choose/skip decision
☐ Can optimize space
☐ Know recurrence relation
```

---

## 🎓 INTERVIEW TIPS

**Before coding:**
1. "This problem has overlapping subproblems"
2. "I'll use DP with state dp[i] = ..."
3. "Base case is ... because ..."

**While coding:**
1. Initialize carefully
2. Handle edge cases (empty input, n=0, n=1)
3. Bounds checking (especially with INT_MAX)

---

**You're Easy DP Ready!** 🚀

**Time:** 3 hours (30 min each, code 2-3 times)

**Next:** Medium DP Patterns

**All the best!** 💪
