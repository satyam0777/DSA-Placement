#  STRING - QUICK REFERENCE SHEET
## Last-Minute Revision (Print This!)

---

##  PATTERN DECISION TREE

```
┌─ "anagram", "frequency", "unique" → HASHING
│
├─ "longest", "shortest", "substring" → SLIDING WINDOW
│
├─ "adjacent", "parentheses", "decode" → STACK
│
├─ "palindrome", "reverse" → TWO POINTER / BASIC
│
└─ "group", "pattern", "mapping" → HASHING + SORTING
```

---

##  TOP 5 MUST-KNOW TEMPLATES

### 1. HASHING - Valid Anagram
```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;
    for(char c : t) freq[c]--;
    for(auto& p : freq) {
        if(p.second != 0) return false;
    }
    return true;
}
```

### 2. SLIDING WINDOW - Longest Substring
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0, maxLen = 0;
    for(int right = 0; right < s.length(); right++) {
        while(window.count(s[right])) {
            window.erase(s[left++]);
        }
        window.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

### 3. STACK - Remove Duplicates
```cpp
string removeDuplicates(string s) {
    stack<char> st;
    for(char c : s) {
        if(!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    string result = "";
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
```

### 4. TWO POINTER - Palindrome
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right--;
        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

### 5. BASIC - Reverse String
```cpp
void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while(left < right) {
        swap(s[left++], s[right--]);
    }
}
```

---

##  TOP 15 PROBLEMS (ONE-LINER SOLUTIONS)

1. **Valid Anagram**: Frequency map, compare counts
2. **First Unique Character**: Count freq, find first with freq=1
3. **Check Palindrome**: Two pointers, compare from both ends
4. **Longest Substring**: Sliding window with set, shrink on duplicate
5. **Valid Parentheses**: Stack, match opening-closing pairs
6. **Reverse String**: Two pointers, swap from ends
7. **Group Anagrams**: Sorted string as key, group in map
8. **Remove Duplicates**: Stack, pop if top equals current
9. **Reverse Words**: Split → reverse array → join
10. **Find Anagrams**: Fixed window, compare frequency maps
11. **String to Integer**: Handle spaces, sign, digits, overflow
12. **Longest Palindrome**: Count even freq, add one odd in middle
13. **Minimum Window**: Expand till all chars found, shrink to minimize
14. **Decode String**: Two stacks (count + string), nested decoding
15. **Longest Common Prefix**: Shrinking method, check char by char

---

## 💬 COMMUNICATION SCRIPTS

### When you see ANAGRAM:
> "Sir, this is anagram problem using hashing. I'll count character frequencies using unordered_map. For s, I'll increment frequencies, for t I'll decrement. If all frequencies are zero, they're anagrams. Time O(n), space O(1) for fixed charset."

### When you see LONGEST SUBSTRING:
> "Sir, this is sliding window problem. I'll maintain a window with unique characters using unordered_set. Expand right pointer, when duplicate found, shrink from left. Track maximum window size. Time O(n), space O(min(n, charset))."

### When you see PARENTHESES:
> "Sir, this is stack problem for bracket matching. For opening brackets, I'll push to stack. For closing brackets, I'll check if they match stack top. If match, pop; if not, return false. Finally check if stack empty. Time O(n), space O(n)."

### When you see PALINDROME:
> "Sir, this is two-pointer approach. I'll use pointers from both ends, skip non-alphanumeric, compare characters in lowercase. If any mismatch, not palindrome. Time O(n), space O(1)."

---

##  COMPANY-WISE TOP 3

### TCS (Focus: Hashing + Basics)
1. Valid Anagram (90%)
2. Valid Parentheses (90%)
3. First Unique Character (85%)

### Infosys (Focus: Hashing + Sliding Window)
1. Valid Anagram (85%)
2. Valid Parentheses (85%)
3. Longest Substring Without Repeat (80%)

### Wipro (Focus: Balanced)
1. Valid Parentheses (80%)
2. Valid Anagram (80%)
3. Check Palindrome (75%)

### Cognizant / Accenture
1. Valid Anagram (70-75%)
2. Valid Parentheses (70-75%)
3. Check Palindrome (70%)

---

##  TIME COMPLEXITIES (MEMORIZE!)

| Operation | Time | Space |
|-----------|------|-------|
| Hashing - Anagram | O(n) | O(1) |
| Hashing - First Unique | O(n) | O(1) |
| Sliding Window - Longest Substring | O(n) | O(min(n,26)) |
| Stack - Valid Parentheses | O(n) | O(n) |
| Two Pointer - Palindrome | O(n) | O(1) |
| Sorting - Group Anagrams | O(n*k log k) | O(n*k) |

---

##  COMMON PATTERNS

### Pattern 1: Frequency Counting
```cpp
unordered_map<char, int> freq;
for(char c : s) freq[c]++;
```

### Pattern 2: Sliding Window (Variable)
```cpp
int left = 0, result = 0;
for(int right = 0; right < n; right++) {
    // Expand
    window.add(s[right]);
    
    // Shrink if needed
    while(condition_violated) {
        window.remove(s[left++]);
    }
    
    // Update result
    result = max(result, right - left + 1);
}
```

### Pattern 3: Stack Matching
```cpp
stack<char> st;
for(char c : s) {
    if(matches_top(c)) {
        st.pop();
    } else {
        st.push(c);
    }
}
```

### Pattern 4: Two Pointer
```cpp
int left = 0, right = n - 1;
while(left < right) {
    if(condition) {
        // Move based on condition
    }
    left++; right--;
}
```

---

##  STRING STL CHEATSHEET

```cpp
// Basic Operations
string s = "hello";
s.length() / s.size()        // 5
s[0]                         // 'h'
s.substr(start, length)      // substring
s.find(char/string)          // index or string::npos
s.append(str) / s += str     // concatenate

// Character Operations
isalnum(c)    // alphanumeric?
isalpha(c)    // alphabet?
isdigit(c)    // digit?
tolower(c)    // to lowercase
toupper(c)    // to uppercase

// Conversions
stoi(str)     // string to int
to_string(n)  // int to string

// Iteration
for(char c : s) { }
for(int i = 0; i < s.length(); i++) { }

// Sorting
sort(s.begin(), s.end());
reverse(s.begin(), s.end());

// Splitting (using stringstream)
stringstream ss(s);
string word;
while(ss >> word) { }
while(getline(ss, word, delimiter)) { }
```

---

##  COMMON MISTAKES TO AVOID

1. **Not checking empty string**: Always check `if(s.empty())`
2. **Integer overflow in atoi**: Use `long` or check limits
3. **Forgetting to reverse stack result**: Stack gives reverse order
4. **Not handling spaces in stringstream**: Use `>>` for space-separated, `getline` for custom delimiter
5. **Case sensitivity in palindrome**: Use `tolower()`
6. **Out of bounds access**: Check `i < s.length()` before `s[i]`

---

##  FINAL MANTRA

```
String Problem = Recognize Pattern + Use Template + Communicate Well

Pattern Recognition (30 sec) 
    ↓
Explain Approach (1 min)
    ↓
Write Template Code (3-5 min)
    ↓
Dry Run (1-2 min)
    ↓
Complexity Analysis (30 sec)
    ↓
SUCCESS! 
```

---

### YOU GOT THIS!

**Remember:**
- Strings are just character arrays
- All array patterns work here
- Communication matters more than perfect code
- Stay calm, think pattern first
- Use templates, don't reinvent

**All the best** 

