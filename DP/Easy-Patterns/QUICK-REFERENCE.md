# ⚡ DP EASY PATTERNS - QUICK REFERENCE
## Copy-Paste Ready Code Snippets

---

## 🔥 FIBONACCI - Space Optimized

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

**Time:** O(n) | **Space:** O(1)

---

## 🔥 CLIMBING STAIRS - Space Optimized

```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    int prev1 = 1, prev2 = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

**Time:** O(n) | **Space:** O(1)

---

## 🔥 COIN CHANGE - Minimum Coins

```cpp
int coinChange(vector<int>& coins, int amount) {
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

**Time:** O(amount × coins) | **Space:** O(amount)

---

## 🔥 HOUSE ROBBER - Space Optimized

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

---

## 📋 INTERVIEW SCRIPT

**Interviewer:** "Please solve coin change problem."

**Your Answer:**
1. "This is a classic minimum coin problem - DP easy pattern."
2. "State: dp[i] = minimum coins to make amount i"
3. "Base: dp[0] = 0 (zero coins for amount 0)"
4. "Transition: For each amount, try each coin"
5. "If coin fits: dp[amount] = min(dp[amount], dp[amount-coin] + 1)"
6. "Important: Check dp[amount-coin] != INT_MAX to avoid overflow"
7. "Time: O(amount × num_coins), Space: O(amount)"
8. [Write code with dry run example]

---

## ✅ EASY DP CHECKLIST

- [ ] Fibonacci: Write space-optimized version
- [ ] Climbing Stairs: Same recurrence as Fib?
- [ ] Coin Change: Initialize dp[0]=0, others=INT_MAX?
- [ ] House Robber: Choose/skip decision tree clear?
- [ ] All: Can explain time/space complexity?

