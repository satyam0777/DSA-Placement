# 🎯 MEDIUM DP PATTERNS - INTERVIEW READY
## Day 2-3: 4 Important Medium Problems

---

## 📊 MEDIUM DP FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 70%+ if Medium DP)
```

**Overall Frequency:** TCS 65%, Infosys 80%, Wipro 60%

---

## 🔥 PATTERN 1: 0/1 KNAPSACK ⭐⭐⭐

### **Frequency:**
- TCS: 75% | Infosys: 85% | Wipro: 70%

### **THE CLASSIC DP PROBLEM**

### **Problem:**
Given items with weight and value, and capacity. Maximize value without exceeding capacity. Can take each item 0 or 1 time.

### **Example:**
```
weights = [2, 3, 4, 5]
values = [3, 4, 5, 6]
capacity = 8

Options:
- Item 0,1: weight=5, value=7
- Item 0,2: weight=6, value=8
- Item 0,3: weight=7, value=9
- Item 1,2: weight=7, value=9
- Item 2,3: weight=9 (exceeds)
- etc.

Answer: 9 (items 0,3 or 1,2)
```

### **Code (Tabulation):**

```cpp
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
    
    // dp[i][w] = max value using items 0..i-1 with capacity w
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            int itemWeight = weights[i-1];
            int itemValue = values[i-1];
            
            if (itemWeight <= w) {
                // Option 1: Include this item
                int include = itemValue + dp[i-1][w - itemWeight];
                
                // Option 2: Exclude this item
                int exclude = dp[i-1][w];
                
                dp[i][w] = max(include, exclude);
            } else {
                // Can't include, take previous value
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}
```

### **Key Insight:**

```
dp[i][w] = max value with first i items and capacity w

For each item i with weight w_i and value v_i:
  If w_i <= w (item fits):
    Option 1: Take item → value = v_i + dp[i-1][w - w_i]
    Option 2: Skip item → value = dp[i-1][w]
    dp[i][w] = max(option1, option2)
  Else:
    dp[i][w] = dp[i-1][w]
```

### **Dry Run:**

```
weights = [2, 3], values = [3, 4], capacity = 5

     0  1  2  3  4  5
i=0  0  0  0  0  0  0
i=1  0  0  3  3  3  3   (item 0: weight=2, value=3)
i=2  0  0  3  4  4  7   (item 1: weight=3, value=4)

i=1, w=2: weight[0]=2, can include
  include = 3 + dp[0][0] = 3
  exclude = dp[0][2] = 0
  dp[1][2] = 3 ✓

i=2, w=5: weight[1]=3, can include
  include = 4 + dp[1][2] = 4 + 3 = 7
  exclude = dp[1][5] = 3
  dp[2][5] = 7 ✓

Answer: 7 ✓
```

**Time:** O(n × capacity) | **Space:** O(n × capacity)

### **Space Optimized (1D):**

```cpp
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    vector<int> dp(capacity + 1, 0);
    
    for (int i = 0; i < weights.size(); i++) {
        for (int w = capacity; w >= weights[i]; w--) {  // Reverse loop!
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    
    return dp[capacity];
}
```

**Why reverse loop?** Prevents using same item twice

**Time:** O(n × capacity) | **Space:** O(capacity)

---

## 🔥 PATTERN 2: LONGEST INCREASING SUBSEQUENCE (LIS) ⭐⭐⭐

### **Frequency:**
- TCS: 65% | Infosys: 80% | Wipro: 65%

### **Problem:**
Find length of longest subsequence with increasing elements (not necessarily contiguous)

### **Example:**
```
arr = [10, 9, 2, 5, 3, 7, 101, 18]

LIS: [2, 3, 7, 101] or [2, 3, 7, 18] length=4

NOT [10, 9, 2] (not increasing)
NOT [9, 5, 3] (not increasing)
```

### **Code:**

```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);  // Each element is LIS of length 1
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {  // Can extend LIS ending at j
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
```

### **Key Insight:**

```
dp[i] = length of LIS ending at index i

For each position i:
  Look at all previous positions j where j < i
  If nums[j] < nums[i]:
    We can extend LIS ending at j
    dp[i] = max(dp[i], dp[j] + 1)
```

### **Dry Run:**

```
arr = [10, 9, 2, 5, 3, 7]

dp[0] = 1            [10]
dp[1] = 1            [9]
dp[2] = 1            [2]
dp[3] = max(2)       [2, 5]
        (2 < 5, dp[2]+1 = 2)
dp[4] = 1            [3] (2 < 3, but need to check all)
        (2 < 3, dp[2]+1 = 2)
        dp[4] = 2
dp[5] = max(3)       [2, 5, 7] or [2, 3, 7]
        (2 < 7, dp[2]+1 = 2)
        (5 < 7, dp[3]+1 = 3)
        (3 < 7, dp[4]+1 = 3)
        dp[5] = 3

Answer: 3 ✓
```

**Time:** O(n²) | **Space:** O(n)

---

## 🔥 PATTERN 3: LONGEST COMMON SUBSEQUENCE (LCS) ⭐⭐⭐

### **Frequency:**
- TCS: 60% | Infosys: 75% | Wipro: 55%

### **Problem:**
Find length of longest common subsequence between two strings

### **Example:**
```
text1 = "abcde"
text2 = "ace"

Common: "a", "c", "e"
LCS: "ace" length=3

text1 = "abc"
text2 = "abc"
LCS: "abc" length=3

text1 = "abc"
text2 = "def"
LCS: "" length=0
```

### **Code:**

```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1]
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                // Characters match, extend LCS
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // Characters don't match, take better of two
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
```

### **Key Insight:**

```
dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1]

If text1[i-1] == text2[j-1]:
  dp[i][j] = dp[i-1][j-1] + 1  (extend LCS)
Else:
  dp[i][j] = max(dp[i-1][j], dp[i][j-1])  (skip one char)
```

### **Dry Run:**

```
text1 = "abc", text2 = "ac"

        ""  a  c
    ""  0   0  0
    a   0   1  1
    b   0   1  1
    c   0   1  2

dp[1][1]: text1[0]='a', text2[0]='a' → match! dp[0][0]+1 = 1 ✓
dp[1][2]: text1[0]='a', text2[1]='c' → no match. max(dp[0][2], dp[1][1]) = 1 ✓
dp[3][2]: text1[2]='c', text2[1]='c' → match! dp[2][1]+1 = 2 ✓

Answer: 2 ✓
```

**Time:** O(m × n) | **Space:** O(m × n)

---

## 🔥 PATTERN 4: EDIT DISTANCE (Levenshtein) ⭐⭐

### **Frequency:**
- TCS: 50% | Infosys: 70% | Wipro: 45%

### **Problem:**
Minimum edits (insert, delete, replace) to convert one string to another

### **Example:**
```
word1 = "horse", word2 = "ros"

Edits:
1. Replace 'h' with 'r': "rorse"
2. Delete 'o': "rrse"
3. Delete 'o': "rse"
4. Replace 's' with 'o': "roe"
...
Better: Delete 'h': "orse"
        Replace 'r' with 'r': "orse" (no change)
        Delete 'e': "ors"
...

Answer: 3
```

### **Code:**

```cpp
int editDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    // dp[i][j] = min edits to convert word1[0..i-1] to word2[0..j-1]
    
    // Base: convert empty string to word2[0..j-1]
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;  // Insert j characters
    }
    
    // Base: convert word1[0..i-1] to empty string
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;  // Delete i characters
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // No edit needed
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],      // Delete from word1
                    dp[i][j-1],      // Insert to word1
                    dp[i-1][j-1]     // Replace
                });
            }
        }
    }
    
    return dp[m][n];
}
```

### **Key Insight:**

```
dp[i][j] = min edits for word1[0..i-1] → word2[0..j-1]

If word1[i-1] == word2[j-1]:
  dp[i][j] = dp[i-1][j-1]  (no edit)
Else:
  Option 1: Delete from word1 → dp[i-1][j] + 1
  Option 2: Insert to word1 → dp[i][j-1] + 1
  Option 3: Replace → dp[i-1][j-1] + 1
  dp[i][j] = min(option1, option2, option3)
```

**Time:** O(m × n) | **Space:** O(m × n)

---

## 📊 MEDIUM DP COMPARISON

| Pattern | Time | Space | When |
|---------|------|-------|------|
| **0/1 Knapsack** | O(n×C) | O(C) | Weight+Value optimization |
| **LIS** | O(n²) | O(n) | Find increasing pattern |
| **LCS** | O(m×n) | O(m×n) | Find common pattern |
| **Edit Distance** | O(m×n) | O(m×n) | String transformation |

---

## 🎯 COMPANY-WISE FOCUS

### **TCS (65% Medium DP):**
1. 0/1 Knapsack (75%)
2. LIS (60%)
3. Edit Distance (50%)

### **Infosys (80% Medium DP):**
1. 0/1 Knapsack (85%)
2. LCS (75%)
3. LIS (75%)
4. Edit Distance (70%)

### **Wipro (60% Medium DP):**
1. 0/1 Knapsack (65%)
2. LIS (55%)
3. LCS (50%)

---

## ⚠️ CRITICAL MISTAKES

```cpp
❌ WRONG: Not initializing dp table correctly
vector<vector<int>> dp(n, vector<int>(m));  // Might have garbage

✅ RIGHT: Initialize with clear values
vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
```

```cpp
❌ WRONG: Forward loop in knapsack space optimization
for (int w = 1; w <= capacity; w++) {  // Can use item twice!
    dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
}

✅ RIGHT: Reverse loop
for (int w = capacity; w >= weights[i]; w--) {  // Use each item once
    dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
}
```

---

## ✅ FINAL CHECKLIST

```
0/1 Knapsack:
☐ Can write 2D solution
☐ Can optimize to 1D
☐ Know reverse loop reason

LIS:
☐ Can find length
☐ Know O(n²) approach
☐ Understand inner loop logic

LCS:
☐ Can write 2D DP
☐ Know base cases
☐ Understand match/mismatch logic

Edit Distance:
☐ Can handle all 3 operations
☐ Know base cases (empty strings)
☐ Can trace back solution
```

---

**You're Medium DP Ready!** 🚀

**Time:** 3-4 hours (45-60 min each)

**Combined:** Easy (3h) + Medium (4h) = 7 hours total

**All the best!** 💪
