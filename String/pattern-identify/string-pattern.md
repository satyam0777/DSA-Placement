#  String Patterns for Placements (Inspired by Aditya Verma sir)

---

##  Table of Contents

1. [Introduction: Strings are Arrays](#1-introduction-strings-are-arrays)
2. [Mapping Array Patterns to Strings](#2-mapping-array-patterns-to-strings)
3. [Pattern-Based Explanations with Deep Dive](#3-pattern-based-explanations-with-deep-dive)
4. [Key Problems for Each Pattern](#4-key-problems-for-each-pattern)
5. [Summary Table: Pattern → Problem Type](#5-summary-table-pattern--problem-type)
6. [Conclusion: No Fear from Strings](#6-conclusion-no-fear-from-strings)

---

## 1.  Introduction: Strings are Arrays

I fear strings because I'm think it’s a new data type. But it's just a **character array** with some helper functions.

In C++, a string is a dynamic array of characters:
```cpp
string s = "hello"; // equivalent to char s[] = {'h','e','l','l','o'};
```

You can use all array techniques like:
- Indexing: `s[0]`
- Loops: `for (char c : s)`
- STL: `s.length()`, `s.find()`, `s.substr()`

---

## 2.  Mapping Array Patterns to Strings

Let’s match Aditya Verma’s **8 array patterns** to **string problems**:

| # | Array Pattern               | String Use Case Example                        | Key Logic                   |
|---|-----------------------------|-----------------------------------------------|-----------------------------|
| 1 | Stack                      | Remove Adjacent Duplicates                    | Push/pop char               |
| 2 | Sliding Window             | Longest Substring Without Repeat             | Shrink/grow window          |
| 3 | Two Pointer                | Palindrome Check, Reverse Words              | Move inwards                |
| 4 | Prefix Sum                 | Count Balanced Strings (R = L)               | Prefix counters             |
| 5 | Hashing / Frequency Map    | Anagrams, Unique Chars                        | Char count in map           |
| 6 | Sorting                    | Group Anagrams                                | Sort string or freq sort    |
| 7 | Greedy                     | Reorganize String, Lexico Smallest           | Choose best character       |
| 8 | Binary Search on Answer   | Smallest Substring That Meets Condition      | Length is monotonic         |

---

## 3.  Pattern-Based Explanations with Deep Dive

### Pattern 1: Stack → "Remove Adjacent Duplicates"

**Problem:** Given `s = "abbaca"`, return string after removing adjacent duplicates → "ca"

```cpp
string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
```

 **Key Concept:** Stack stores characters only when not repeated.

---

### Pattern 2: Sliding Window → "Longest Substring Without Repeating Characters"

**Problem:** Find max length of substring with all unique characters.

```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> index(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (index[s[i]] > start)
            start = index[s[i]];
        index[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}
```

 **Key Concept:** Use a moving window and track last seen index of characters.

---

### Pattern 3: Two Pointer → "Valid Palindrome"

```cpp
bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}
```

 **Key Concept:** Check symmetry from both ends.

---

### Pattern 4: Prefix Sum → "Balanced Strings"

**Problem:** Count substrings with equal L and R

```cpp
int balancedStringSplit(string s) {
    int count = 0, balance = 0;
    for (char c : s) {
        balance += (c == 'L') ? 1 : -1;
        if (balance == 0) count++;
    }
    return count;
}
```

 **Key Concept:** Prefix sum balances at 0 = one balanced substring

---

### Pattern 5: HashMap → "Check Anagram"

```cpp
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;
    for (int i : count) if (i != 0) return false;
    return true;
}
```

 **Key Concept:** Frequency map using array for a-z

---

### Pattern 6: Sorting → "Group Anagrams"

```cpp
unordered_map<string, vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    return map;
}
```

 **Key Concept:** Sorted version is the unique identifier for anagram group

---

### Pattern 7: Greedy → "Reorganize String"

**Problem:** Rearrange so no two adjacent chars are same

```cpp
string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto [c, f] : freq) pq.push({f, c});

    string result = "";
    pair<int, char> prev = {0, '#'};

    while (!pq.empty()) {
        auto [f, c] = pq.top(); pq.pop();
        result += c;
        if (prev.first > 0) pq.push(prev);
        prev = {f - 1, c};
    }
    return result.length() == s.length() ? result : "";
}
```

 **Key Concept:** Always use the most frequent char not recently used.

---

### Pattern 8: Binary Search on Answer → "Minimum Window Length"

**Problem:** Find min length substring with all chars of T

- Not directly binary search, but similar logic is used when substring length is monotonic.

---

## 4.  Key Problems for Each Pattern

| Pattern | LeetCode Problem                                 |
|---------|--------------------------------------------------|
| Stack   | Remove Adjacent Duplicates (1047)                |
| Sliding Window | Longest Substring Without Repeat (3)    |
| Two Pointer | Valid Palindrome (125)                       |
| Prefix Sum | Balanced String Split (1221)                 |
| Hashing | Group Anagrams (49), Valid Anagram (242)        |
| Sorting | Group Anagrams                                  |
| Greedy | Reorganize String (767)                          |
| Binary Search | Smallest Substring With Condition         |

---

## 5.  Summary Table: Pattern → Problem Type

| Pattern        | Think About…                     |
|----------------|----------------------------------|
| Stack          | Repeating/undo characters        |
| Sliding Window | Substring constraints            |
| Two Pointer    | Symmetry, movement from both ends|
| Prefix Sum     | Counting / balancing conditions  |
| Hashing        | Frequency, uniqueness            |
| Sorting        | Comparing character sets         |
| Greedy         | Lexicographical / frequency based|
| Binary Search  | Smallest length satisfying rule  |

---

## 6.  Conclusion: No Fear from Strings

> You already know 80% of string problems if you know arrays , sliding window and binary and other concept.



