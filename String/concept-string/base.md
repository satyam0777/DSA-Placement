# String Mastery for Placements & Interviews (C++)

---

##  Table of Contents

1. Introduction
2. Properties of Strings
3. Common Operations
4. Important Interview Concepts
5. Must-Know Problems with Logic
6. Advanced Topics
7. String Problem Sheet
8. Tips to Crack String Interviews

---

## 📌 Introduction

A **string** is a sequence of characters. In C++, we use the `std::string` class from the STL.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "hello";
    cout << s;
    return 0;
}
```

---

##  Properties of Strings

| Property       | Description                          | Code Example             |
|----------------|--------------------------------------|--------------------------|
| Indexable      | Access with index                    | `s[0] // 'h'`            |
| Iterable       | Loop through characters              | `for(char c : s)`        |
| Length         | Get size                             | `s.length()` or `s.size()` |
| Mutable        | Characters can be changed            | `s[0] = 'H'`             |

---

##  Common Operations

###  Reverse a String
```cpp
reverse(s.begin(), s.end());
```

###  Substring
```cpp
string sub = s.substr(start, length);
```

###  Search in String
```cpp
int pos = s.find("abc"); // returns index or string::npos
```

###  Convert to char array or back 
```cpp
char ch = s[0]; // char from string
string s(1, ch); // string from char
```

---

##  Important Interview Concepts

### 1. Palindrome
```cpp
bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}
```

### 2. Anagram
```cpp
bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    vector<int> freq(26, 0);
    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;
    for (int f : freq) if (f != 0) return false;
    return true;
}
```

### 3. Longest Common Subsequence (LCS)
```cpp
int LCS(string a, string b) {
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
```

### 4. Longest Substring Without Repeating Characters
```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (lastIndex[s[i]] > start)
            start = lastIndex[s[i]];
        lastIndex[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}
```

---

##  Must-Know Problems with Logic

| Problem                             | Technique             | Platform       |
|-------------------------------------|------------------------|----------------|
| Reverse Words in a String           | Split & Reverse        | LeetCode #151  |
| Valid Palindrome                    | Two Pointer            | LeetCode #125  |
| Longest Substring w/o Repeat Char   | Sliding Window         | LeetCode #3    |
| Group Anagrams                      | HashMap + Sorting      | LeetCode #49   |
| Longest Palindromic Substring       | DP / Expand Center     | LeetCode #5    |
| String Compression                  | Two Pointer            | LeetCode #443  |

---

##  Advanced Topics

| Topic                   | Use Case                        |
|------------------------|----------------------------------|
| KMP Algorithm           | Pattern Matching (StrStr)       |
| Rabin-Karp Algorithm    | Efficient Pattern Matching      |
| Trie (Prefix Tree)      | Auto-suggestions, Word Search   |
| Manacher’s Algorithm    | Longest Palindromic Substring   |

---

