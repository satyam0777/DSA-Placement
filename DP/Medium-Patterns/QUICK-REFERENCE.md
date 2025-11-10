# ⚡ DP MEDIUM PATTERNS - QUICK REFERENCE
## Copy-Paste Ready Code Snippets

---

## 🔥 0/1 KNAPSACK - Space Optimized

```cpp
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int w = capacity; w >= weights[i]; w--) {  // REVERSE loop!
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    return dp[capacity];
}
```

**Time:** O(n × capacity) | **Space:** O(capacity)

**Why reverse?** Prevents using same item twice

---

## 🔥 LONGEST INCREASING SUBSEQUENCE

```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
```

**Time:** O(n²) | **Space:** O(n)

---

## 🔥 LONGEST COMMON SUBSEQUENCE

```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
```

**Time:** O(m × n) | **Space:** O(m × n)

---

## 🔥 EDIT DISTANCE

```cpp
int editDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];
}
```

**Time:** O(m × n) | **Space:** O(m × n)

---

## 📋 INTERVIEW SCRIPT

**Interviewer:** "Solve 0/1 Knapsack"

**Your Answer:**
1. "This is the classic knapsack problem - medium DP pattern"
2. "For-each item, decide: include or exclude"
3. "State: dp[w] = max value with capacity w"
4. "Recurrence: dp[w] = max(dp[w], value + dp[w-weight])"
5. "Key: Loop capacity BACKWARDS to prevent item reuse"
6. "Why? Forward loop would use updated dp[w-weight] (same item)"
7. "Space: O(capacity), Time: O(n × capacity)"
8. [Write code with example]

---

## ⚡ QUICK PATTERN IDENTIFICATION

| Pattern | Signature | Recurrence |
|---------|-----------|-----------|
| **Knapsack** | Weight+Value, "include or exclude" | `dp[w] = max(include, exclude)` |
| **LIS** | "Increasing subsequence" | `if arr[j] < arr[i]: dp[i] = max(dp[j]+1)` |
| **LCS** | "Common subsequence" | `if match: dp[i][j] = dp[i-1][j-1]+1` |
| **Edit** | "Min operations transform" | `min(delete, insert, replace)` |

---

## ✅ MEDIUM DP CHECKLIST

- [ ] 0/1 Knapsack: Reverse loop?
- [ ] LIS: Check all j < i?
- [ ] LCS: Handle mismatch with max?
- [ ] Edit Distance: All 3 operations covered?
- [ ] All: Base cases initialized correctly?

