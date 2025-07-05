#  8 Key String Problems Based on Array Patterns (with Full Thinking Process)

> This guide contains **8 handpicked string problems**, each related to one of the **8 core array patterns** (I already do these 8 concept and i try to co-relate , as same Aditya Verma sir). For each, we’ll include:
-  Problem Statement
-  Thought Process
-  Pattern Mapping
-  Step-by-step Explanation
-  Final Code (in C++)

---

## 1.  Pattern: Stack – Problem: Remove All Adjacent Duplicates in String

###  Problem:
Given a string `s`, repeatedly remove adjacent duplicates.

###  Thought Process:
- Use a **stack** to keep track of characters.
- If top of stack equals current character, pop it.
- Else, push the current character.

###  Pattern:
Stack → Just like **Next Greater Element** but with character logic.

###  Code:
```cpp
string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
```

---

## 2.  Pattern: Sliding Window – Problem: Longest Substring Without Repeating Characters

###  Problem:
Given a string `s`, find the length of the longest substring without repeating characters.

###  Thought Process:
- Keep two pointers `left` and `right`.
- Expand `right`, and if a char repeats, shrink from `left`.
- Use map to store last seen index.

###  Pattern:
Sliding window like **max sum subarray of size K**, but variable window.

###  Code:
```cpp
int lengthOfLongestSubstring(string s) {
    vector<int> index(256, -1);
    int maxLen = 0, left = -1;
    for (int right = 0; right < s.length(); right++) {
        if (index[s[right]] > left) {
            left = index[s[right]];
        }
        index[s[right]] = right;
        maxLen = max(maxLen, right - left);
    }
    return maxLen;
}
```

---

## 3.  Pattern: Two Pointer – Problem: Valid Palindrome

###  Problem:
Check if string is a palindrome (reads same forward and backward).

###  Thought Process:
- Use `left = 0`, `right = n - 1`.
- Compare chars from both sides.

### ⚙️ Pattern:
Same as **sorted pair sum**, you move pointers inward.

###  Code:
```cpp
bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}
```

---

## 4.  Pattern: Prefix Sum – Problem: Balanced String Split

###  Problem:
Split the string into maximum balanced substrings (equal L and R).

###  Thought Process:
- Track balance: +1 for L, -1 for R.
- When balance == 0 → one split

###  Pattern:
Like prefix sum reaching target.

###  Code:
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

---

## 5.  Pattern: Hashing – Problem: Group Anagrams

###  Problem:
Group strings that are anagrams of each other.

###  Thought Process:
- Sort string to create unique key.
- Use hashmap to group by key.

###  Pattern:
Same as hashing frequencies in array (like count subarray sum).

###  Code:
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

---

## 6.  Pattern: Sorting – Problem: Check Anagram

###  Problem:
Check if two strings are anagrams.

###  Thought Process:
- Sort both strings.
- Compare if they are equal.

###  Pattern:
Direct sort and compare — like sorting arrays before comparing.

###  Code:
```cpp
bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
```

---

## 7.  Pattern: Greedy – Problem: Reorganize String

###  Problem:
Rearrange string so no two same characters are adjacent.

###  Thought Process:
- Count frequency.
- Always place most frequent unused character.
- Use max-heap (priority queue).

###  Pattern:
Greedy like activity selection – always take best option.

###  Code:
```cpp
string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    priority_queue<pair<int, char>> pq;
    for (auto [c, f] : freq) pq.push({f, c});

    string res = "";
    pair<int, char> prev = {0, '#'};
    while (!pq.empty()) {
        auto [f, c] = pq.top(); pq.pop();
        res += c;
        if (prev.first > 0) pq.push(prev);
        prev = {f - 1, c};
    }
    return res.size() == s.size() ? res : "";
}
```

---

## 8.  Pattern: Binary Search on Answer – Problem: Minimum Window Substring

###  Problem:
Find the smallest substring of `s` that contains all characters of `t`.

###  Thought Process:
- Expand window till all characters matched.
- Then contract from left to minimize.
- Binary search style: is this length valid?

###  Pattern:
Binary search on size + sliding window.

###  Code (sliding window):
```cpp
string minWindow(string s, string t) {
    vector<int> map(128, 0);
    for (char c : t) map[c]++;
    int count = t.size(), l = 0, r = 0, minLen = INT_MAX, start = 0;
    while (r < s.size()) {
        if (map[s[r++]]-- > 0) count--;
        while (count == 0) {
            if (r - l < minLen) minLen = r - l, start = l;
            if (++map[s[l++]] > 0) count++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

---

