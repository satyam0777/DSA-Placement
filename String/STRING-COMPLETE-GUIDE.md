# 🎯 STRING MASTERY - COMPLETE GUIDE (Aditya Verma's Way)
*Comprehensive String Problem Solving using Pattern Recognition*

---

## 📋 TABLE OF CONTENTS

1. [Introduction & Big Picture](#introduction)
2. [3-Second Recognition System](#recognition)
3. [Aditya Verma's 7 Core Patterns for Strings](#patterns)
4. [Generic Templates (Ready to Copy)](#templates)
5. [Golden Formulas & Key Insights](#formulas)
6. [5 Complete Problems (5-Step Method)](#problems)
7. [Interview Communication Scripts](#scripts)
8. [Common Mistakes & Fixes](#mistakes)
9. [Real-World Analogies](#analogies)

---

<a name="introduction"></a>
## 🎬 INTRODUCTION & BIG PICTURE

### Why Strings Feel Hard?

**Common misconception:** "Strings are a new data structure!"

**Reality:** Strings are just **character arrays** with fancy helper functions!

```cpp
// These are essentially the same:
string s = "hello";
char arr[] = {'h', 'e', 'l', 'l', 'o', '\0'};
```

### Key Insight
If you master array patterns (sliding window, hashing, two-pointer, stack, etc.), you can solve 90% of string problems!

### Real-World Analogy 📖

**String problems = Text editing operations**

Think like a text editor:
- **Search & Replace** → Sliding Window / Hashing
- **Find Matching Brackets** → Stack
- **Spell Check** → Hashing / Frequency
- **Palindrome Checker** → Two Pointer
- **Compress Text** → Greedy / DP

---

<a name="recognition"></a>
## 🔥 3-SECOND RECOGNITION SYSTEM

### The Quick Decision Framework

```
┌─────────────────────────────────────────────────┐
│  WHAT AM I LOOKING FOR?                         │
├─────────────────────────────────────────────────┤
│                                                 │
│  Q1: Is it about FREQUENCY?                     │
│      └─ YES → HASHING                           │
│      └─ NO → Go to Q2                           │
│                                                 │
│  Q2: Is it about SUBSTRING/SUBSEQUENCE?         │
│      └─ YES → SLIDING WINDOW or DP              │
│      └─ NO → Go to Q3                           │
│                                                 │
│  Q3: Is it about MATCHING/BALANCE?              │
│      └─ YES → STACK or TWO POINTER              │
│      └─ NO → Go to Q4                           │
│                                                 │
│  Q4: Is it about SYMMETRY?                      │
│      └─ YES → TWO POINTER                       │
│      └─ NO → Go to Q5                           │
│                                                 │
│  Q5: Is it about BEST CHOICE?                   │
│      └─ YES → GREEDY or PRIORITY QUEUE          │
│      └─ NO → DP/OTHER PATTERNS                  │
│                                                 │
└─────────────────────────────────────────────────┘
```

---

<a name="patterns"></a>
## 🎨 ADITYA VERMA'S 7 CORE PATTERNS FOR STRINGS

### Pattern 1: HASHING (Frequency Map) 📊

**When:** Anagrams, unique characters, character counts, frequency-based problems

**Key Keywords:** "anagram", "frequency", "unique", "count", "appear", "group"

**Mental Model:** Store character frequencies in a map/array

**Problems:**
- Valid Anagram
- First Unique Character
- Group Anagrams
- Character Frequency Analysis

**Template:**
```cpp
unordered_map<char, int> freq;
for(char c : s) {
    freq[c]++;
}
// Check conditions based on freq map
```

---

### Pattern 2: SLIDING WINDOW (Fixed/Variable) 🪟

**When:** Substring problems, "longest/shortest", window constraints

**Key Keywords:** "substring", "longest", "shortest", "all characters", "window", "contain"

**Mental Model:** Expand and contract a window across the string

**Problems:**
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- All Anagrams in a String
- Max Consecutive Ones

**Real-World:** Text editor searching for valid word in range

**Two Types:**
1. **Fixed Size Window:** Window size is fixed
2. **Variable Size Window:** Expand/shrink based on conditions

---

### Pattern 3: TWO POINTER 👈👉

**When:** Palindromes, reverse, comparing from ends, symmetry

**Key Keywords:** "palindrome", "reverse", "valid", "symmetry", "both ends"

**Mental Model:** Start from both ends, move inward

**Problems:**
- Check Palindrome
- Valid Palindrome (with spaces/punctuation)
- Reverse String
- Palindrome II (after deleting one character)

**Template:**
```cpp
int left = 0, right = s.length() - 1;
while(left < right) {
    // Compare or process
    left++;
    right--;
}
```

---

### Pattern 4: STACK 📚

**When:** Matching, parentheses, removing duplicates, decode

**Key Keywords:** "valid", "remove adjacent", "decode", "match", "brackets", "duplicates"

**Mental Model:** Use stack for LIFO (Last In First Out) matching

**Problems:**
- Valid Parentheses
- Remove Adjacent Duplicates
- Decode String
- Valid Parentheses String

**Key Insight:** Stack is for **undo/matching operations**

---

### Pattern 5: GREEDY / PRIORITY QUEUE ⭐

**When:** Lexicographically smallest/largest, best choice at each step

**Key Keywords:** "lexicographically", "best", "reorganize", "rearrange", "adjacent"

**Mental Model:** Always pick the best available option now

**Problems:**
- Reorganize String (no adjacent duplicates)
- Lexicographically Smallest String
- Remove K Digits

**Use Case:** When local best choices lead to global best

---

### Pattern 6: RECURSION / BACKTRACKING 🔄

**When:** Generate patterns, permutations, combinations

**Key Keywords:** "generate", "all", "permutation", "combination", "backtrack"

**Problems:**
- Generate Parentheses
- Permutations
- Word Search
- Regular Expression Matching

---

### Pattern 7: DYNAMIC PROGRAMMING 🔷

**When:** Optimal substructure, overlapping subproblems

**Key Keywords:** "edit distance", "longest common", "count ways", "minimum operations"

**Problems:**
- Edit Distance (Levenshtein)
- Longest Common Subsequence
- Regular Expression Matching (advanced)
- Distinct Subsequences

---

## 🚀 Pattern Mapping Table

| Pattern | Problem Type | Time | Space | Example |
|---------|-------------|------|-------|---------|
| **Hashing** | Frequency, Anagrams | O(n) | O(1) | Valid Anagram |
| **Sliding Window** | Substring, Window | O(n) | O(min(n,k)) | Longest Substring |
| **Two Pointer** | Palindrome, Symmetry | O(n) | O(1) | Valid Palindrome |
| **Stack** | Matching, Matching | O(n) | O(n) | Valid Parentheses |
| **Greedy/PQ** | Best Choice | O(n log n) | O(n) | Reorganize String |
| **Recursion** | Generation | O(exponential) | O(h) | Generate Parentheses |
| **DP** | Optimal | O(n²) or more | O(n²) | Edit Distance |

---

<a name="templates"></a>
## 📝 GENERIC TEMPLATES (Ready to Copy)

### Template 1: HASHING (Frequency Map) 🗺️

```cpp
// ═══════════════════════════════════════════
// PATTERN 1: HASHING - FREQUENCY MAP
// Use: Count characters, validate anagrams
// Time: O(n) | Space: O(1) for fixed charset
// ═══════════════════════════════════════════

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    // Method 1: Using unordered_map
    unordered_map<char, int> freq;
    
    for (char c : s) freq[c]++;
    for (char c : t) freq[c]--;
    
    for (auto& p : freq) {
        if (p.second != 0) return false;
    }
    return true;
    
    // Method 2: Using array (faster for a-z)
    // int count[26] = {0};
    // for(char c : s) count[c - 'a']++;
    // for(char c : t) count[c - 'a']--;
    // for(int c : count) if(c != 0) return false;
    // return true;
}

// MANTRA: "Count and compare frequencies!"
```

**Real-World:** 📚 Checking if two books have same words!

---

### Template 2: SLIDING WINDOW (Fixed Size) 🪟

```cpp
// ═══════════════════════════════════════════════════════════
// PATTERN 2A: SLIDING WINDOW - FIXED SIZE
// Use: Window of fixed size k, find best value
// Time: O(n) | Space: O(1)
// ═══════════════════════════════════════════════════════════

// Example: Max vowels in substring of size k
int maxVowels(string s, int k) {
    int i = 0, j = 0, count = 0, maxCount = 0;
    
    while (j < s.length()) {
        if (isVowel(s[j])) count++;           // Add j
        
        if (j - i + 1 < k) {
            j++;                              // Not ready (window not full)
        }
        else if (j - i + 1 == k) {
            maxCount = max(maxCount, count);  // Answer
            if (isVowel(s[i])) count--;       // Remove i
            i++; j++;                         // Slide both
        }
    }
    
    return maxCount;
}

// MANTRA: "Add j, check size, answer, slide both"
```

**Real-World:** 🪟 Fixed window sliding across text!

---

### Template 2B: SLIDING WINDOW (Variable - 3 Conditions) 🪟

```cpp
// ═══════════════════════════════════════════════════════════
// PATTERN 2B: SLIDING WINDOW - VARIABLE SIZE (3 CONDITIONS)
// Use: Expand/shrink based on conditions
// Time: O(n) | Space: O(charset)
// ═══════════════════════════════════════════════════════════

// Example: Longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int i = 0, j = 0, maxLen = 0;
    
    while (j < s.length()) {
        char c = s[j];
        
        // Check if character already in window
        if (lastSeen.count(c) && lastSeen[c] >= i) {
            // Character found in current window
            i = lastSeen[c] + 1;              // Shrink: move i ahead
        }
        
        // Add current character
        lastSeen[c] = j;
        
        // Update answer
        maxLen = max(maxLen, j - i + 1);
        
        j++;                                  // Always expand
    }
    
    return maxLen;
}

// MANTRA: "Add j, while duplicate shrink i, update max, move j"
```

**Real-World:** 🔍 Finding longest valid word in text!

---

### Template 3: TWO POINTER 👈👉

```cpp
// ═══════════════════════════════════════════
// PATTERN 3: TWO POINTER
// Use: Check palindromes, reverse operations
// Time: O(n) | Space: O(1)
// ═══════════════════════════════════════════

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        
        // Skip non-alphanumeric from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Compare (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

// MANTRA: "Start from both ends, move inward!"
```

**Real-World:** 📖 Checking palindromic sentences!

---

### Template 4: STACK (Matching) 📚

```cpp
// ═══════════════════════════════════════════
// PATTERN 4: STACK - MATCHING/REMOVAL
// Use: Valid parentheses, remove adjacent duplicates
// Time: O(n) | Space: O(n)
// ═══════════════════════════════════════════

// Use Case 1: Valid Parentheses
bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            // Closing bracket
            if (st.empty()) return false;
            
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
            st.pop();
        }
    }
    
    return st.empty();
}

// Use Case 2: Remove Adjacent Duplicates
string removeDuplicates(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // Remove adjacent duplicate
        } else {
            st.push(c);  // Add character
        }
    }
    
    // Convert stack to string
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// MANTRA: "Stack for LIFO matching and removal!"
```

**Real-World:** ✏️ Text editor undo/redo, bracket matching!

---

### Template 5: SLIDING WINDOW (Fixed Size) 🪟

```cpp
// ═══════════════════════════════════════════
// PATTERN 2B: SLIDING WINDOW (FIXED SIZE)
// Use: Find substring of exact size k
// Time: O(n) | Space: O(1)
// ═══════════════════════════════════════════

int maxVowels(string s, int k) {
    // Sliding window of size k
    int vowels = 0;
    
    // Build first window
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) vowels++;
    }
    
    int maxVowel = vowels;
    
    // Slide the window
    for (int i = k; i < s.length(); i++) {
        // Remove left element
        if (isVowel(s[i - k])) vowels--;
        
        // Add right element
        if (isVowel(s[i])) vowels++;
        
        maxVowel = max(maxVowel, vowels);
    }
    
    return maxVowel;
}

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || 
           c == 'o' || c == 'u';
}

// MANTRA: "Fixed window: remove left, add right!"
```

---

### Template 6: PRIORITY QUEUE (Greedy) ⭐

```cpp
// ═══════════════════════════════════════════
// PATTERN 5: GREEDY / PRIORITY QUEUE
// Use: Reorganize string with constraints
// Time: O(n log n) | Space: O(n)
// ═══════════════════════════════════════════

string reorganizeString(string s) {
    // Count frequency
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    // Max heap: (frequency, character)
    priority_queue<pair<int, char>> maxHeap;
    for (auto& p : freq) {
        maxHeap.push({p.second, p.first});
    }
    
    string result = "";
    pair<int, char> prev = {0, '#'};
    
    while (!maxHeap.empty()) {
        auto [count, ch] = maxHeap.top();
        maxHeap.pop();
        
        result += ch;
        
        // Push previous character back if count > 0
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        
        // Update previous
        prev = {count - 1, ch};
    }
    
    // Check if valid (no adjacent same)
    return result.length() == s.length() ? result : "";
}

// MANTRA: "Always pick most frequent unused character!"
```

**Real-World:** 🎯 Task scheduling, load balancing!

---

<a name="formulas"></a>
## 🔑 GOLDEN FORMULAS & KEY INSIGHTS

### Formula 1: Window Calculation
```
Window Length = right - left + 1
```

### Formula 2: Frequency Comparison
```
Anagram Check: All frequencies match after processing
```

### Formula 3: Palindrome Check
```
s[i] should equal s[n-1-i] for all i < n/2
```

### Formula 4: Valid Brackets
```
Every closing bracket must match the most recent opening bracket
Stack approach: push opening, pop on closing
```

### Formula 5: Adjacent Check
```
Stack top == current → Remove (adjacent duplicates)
Stack top != current → Add (different characters)
```

---

<a name="problems"></a>
## 🎯 5 COMPLETE PROBLEMS (5-STEP METHOD)

---

### PROBLEM 1: Valid Anagram

**Step 1: Problem Statement**

```
Given two strings s and t, return true if t is an anagram of s.

Example:
  Input: s = "anagram", t = "nagaram"
  Output: true
  
  Input: s = "rat", t = "car"
  Output: false

Constraints: 1 ≤ s.length, t.length ≤ 5 × 10^4
```

**Step 2: Identification (Pattern Recognition - 3 Sec) 🔥**

```
Q1: Is it about FREQUENCY? ✅ YES
    → Use HASHING

This is a HASHING problem!
Time: O(n) | Space: O(1) [fixed charset]
```

**Step 3: Approach (Think Before Coding)**

```
Approach:
1. Check if lengths are equal (if not, can't be anagrams)
2. Count character frequencies in s using map/array
3. Decrement frequencies for characters in t
4. If all frequencies are 0, they're anagrams
5. Otherwise, not anagrams

Why This Works:
- Anagrams have exact same character counts
- If we count s and subtract t, result should be all zeros

Example Trace:
s = "anagram", t = "nagaram"

Step 1: freq['a']+=1 → freq['a']=1
Step 2: freq['n']+=1 → freq['n']=1
...after s: a:3, n:1, g:1, r:1, m:1

Then decrement with t:
freq['n']-- → freq['n']=0
freq['a']-- → freq['a']=2
...
All become 0? → true (Anagram!)
```

**Step 4: Dry Run (Complete Trace)**

```
s = "ab", t = "ba"

Initialization:
  freq = {}

Processing s:
  i=0: c='a' → freq['a']=1    {a:1}
  i=1: c='b' → freq['b']=1    {a:1, b:1}

Processing t:
  i=0: c='b' → freq['b']--    {a:1, b:0}
  i=1: c='a' → freq['a']--    {a:0, b:0}

Final check:
  All values = 0? → true ✅
  Return: true
```

**Step 5: Code (With Comments)**

```cpp
bool isAnagram(string s, string t) {
    // Check length first (quick optimization)
    if (s.length() != t.length()) {
        return false;
    }
    
    // Count frequencies in s
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    // Decrement frequencies with t
    for (char c : t) {
        freq[c]--;
    }
    
    // Check if all frequencies are 0
    for (auto& p : freq) {
        if (p.second != 0) {
            return false;  // Not an anagram
        }
    }
    
    return true;  // All frequencies matched
}

// Time: O(n) - iterate through both strings once
// Space: O(1) - at most 26 lowercase letters
```

---

### PROBLEM 2: Longest Substring Without Repeating Characters

**Step 1: Problem Statement**

```
Given a string s, find the length of the longest substring 
without repeating characters.

Example:
  Input: s = "abcabcbb"
  Output: 3 (Explanation: "abc")
  
  Input: s = "bbbbb"
  Output: 1 (Explanation: "b")
  
  Input: s = "pwwkew"
  Output: 3 (Explanation: "wke")

Constraints: 0 ≤ s.length ≤ 5 × 10^4
```

**Step 2: Identification (Pattern Recognition - 3 Sec) 🔥**

```
Q1: Is it about FREQUENCY? ❌ NO
Q2: Is it about SUBSTRING? ✅ YES
Q3: Is it about constraints? ✅ YES (no repeating)
    → Use SLIDING WINDOW

This is a SLIDING WINDOW (Variable Size) problem!
Time: O(n) | Space: O(min(n, charset))
```

**Step 3: Approach (Think Before Coding)**

```
Approach:
1. Use two pointers: left (window start), right (window end)
2. Use a map to track last seen index of each character
3. Expand right pointer one by one
4. If character already seen within current window:
   - Move left pointer to skip duplicate
5. Track maximum window length seen so far

Why Variable Window?
- Window size depends on character distribution
- Shrink only when duplicate found
- Expand whenever possible

Example:
s = "abcabcbb"
Need to find longest substring with unique chars

Window progression:
[a] → length 1
[ab] → length 2
[abc] → length 3
[abca] → duplicate 'a'! Move left to skip first 'a'
[bca] → length 3
[bcab] → duplicate 'b'! Move left to skip first 'b'
[cab] → length 3
[cabc] → duplicate 'c'! Move left
...

Maximum seen: 3
```

**Step 4: Dry Run (Complete Trace)**

```
s = "au"

Initialization:
  left = 0, maxLen = 0
  lastSeen = {} (empty map)

Iteration:
  right=0: c='a'
    lastSeen['a'] not found
    lastSeen['a']=0    → {a:0}
    maxLen = max(0, 0-0+1) = 1

  right=1: c='u'
    lastSeen['u'] not found
    lastSeen['u']=1    → {a:0, u:1}
    maxLen = max(1, 1-0+1) = 2

Return: 2
```

**Step 5: Code (With Comments)**

```cpp
int lengthOfLongestSubstring(string s) {
    // Map to store last seen index of each character
    unordered_map<char, int> lastSeen;
    int maxLen = 0;
    int left = 0;
    
    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        
        // If character seen after left pointer (within window)
        if (lastSeen.count(c) && lastSeen[c] >= left) {
            // Move left pointer to skip duplicate
            left = lastSeen[c] + 1;
        }
        
        // Update last seen index of current character
        lastSeen[c] = right;
        
        // Update maximum length
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

// Time: O(n) - each character visited twice at most
// Space: O(min(n, charset)) - map can have at most 26 chars
```

---

### PROBLEM 3: Valid Palindrome

**Step 1: Problem Statement**

```
Given a string s, determine if it is a palindrome, considering 
only alphanumeric characters and ignoring cases.

Example:
  Input: s = "A man, a plan, a canal: Panama"
  Output: true
  
  Input: s = "race a car"
  Output: false
  
  Input: s = " "
  Output: true

Constraints: 1 ≤ s.length ≤ 10^5
```

**Step 2: Identification (Pattern Recognition - 3 Sec) 🔥**

```
Q1: FREQUENCY? ❌ NO
Q2: SUBSTRING? ❌ NO
Q3: MATCHING? ❌ NO
Q4: SYMMETRY? ✅ YES
    → Use TWO POINTER

This is a TWO POINTER problem!
Time: O(n) | Space: O(1)
```

**Step 3: Approach (Think Before Coding)**

```
Approach:
1. Use two pointers: left at start, right at end
2. Skip non-alphanumeric characters
3. Compare characters (case-insensitive)
4. If mismatch → not palindrome
5. If all match → palindrome

Key Point: Only consider alphanumeric characters
Ignore spaces, punctuation, case differences

Example:
s = "A man, a plan, a canal: Panama"
After removing non-alphanumeric and lowercase:
"amanaplanacanalpanama"

Compare from both ends:
[a]______________________[a] ✅
 _[m]_________________[m]_ ✅
  _[a]_______________[a]_ ✅
   _[n]_____________[n]_ ✅
    _[a]___________[a]_ ✅
...continues...
All match → Palindrome!
```

**Step 4: Dry Run (Complete Trace)**

```
s = ".,a"

left=0, right=2

Iteration 1:
  left=0: s[0]='.' (not alphanumeric) → left++
  left=1: s[1]=',' (not alphanumeric) → left++
  left=2: s[2]='a' (alphanumeric)
  
  right=2: s[2]='a' (alphanumeric)
  
  Compare: tolower('a') vs tolower('a') ✅ MATCH
  
  left++, right--
  Now left=3, right=1 → left NOT < right → exit loop

Return: true (Palindrome!)
```

**Step 5: Code (With Comments)**

```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        
        // Skip non-alphanumeric from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;  // Mismatch → not palindrome
        }
        
        left++;
        right--;
    }
    
    return true;  // All characters matched → palindrome
}

// Time: O(n) - each character visited once
// Space: O(1) - only two pointers
```

---

### PROBLEM 4: Valid Parentheses

**Step 1: Problem Statement**

```
Given a string s containing just the characters '(', ')', '{', '}', 
'[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by same type
2. Open brackets must be closed in correct order

Example:
  Input: s = "()"
  Output: true
  
  Input: s = "([{}])"
  Output: true
  
  Input: s = "([)]"
  Output: false (wrong order)

Constraints: 1 ≤ s.length ≤ 10^4
```

**Step 2: Identification (Pattern Recognition - 3 Sec) 🔥**

```
Q1: FREQUENCY? ❌ NO
Q2: SUBSTRING? ❌ NO
Q3: MATCHING/BALANCE? ✅ YES
    → Use STACK

This is a STACK problem!
Time: O(n) | Space: O(n)
```

**Step 3: Approach (Think Before Coding)**

```
Approach:
1. Use stack to track opening brackets
2. For each character:
   - Opening bracket → push to stack
   - Closing bracket → check if matches stack top
     If matches: pop and continue
     If doesn't match: return false
3. After loop: stack should be empty
4. If empty → valid, else → invalid

Why Stack?
- LIFO property ensures most recent opening bracket
- Closing bracket must match most recent opening
- Stack naturally handles nesting

Example:
s = "([{}])"

Step 1: '(' → push to stack     stack: ['(']
Step 2: '[' → push to stack     stack: ['(', '[']
Step 3: '{' → push to stack     stack: ['(', '[', '{']
Step 4: '}' → top='{' ✅ match  stack: ['(', '[']
Step 5: ']' → top='[' ✅ match  stack: ['(']
Step 6: ')' → top='(' ✅ match  stack: []

Stack empty? YES → Valid! ✅
```

**Step 4: Dry Run (Complete Trace)**

```
s = "([)]"

Initialization:
  stack = [] (empty)

Iteration:
  i=0: '(' → push        stack: ['(']
  i=1: '[' → push        stack: ['(', '[']
  i=2: ')' → closing
    top = '['
    Does ')' match '['? ❌ NO
    Return false ❌

String is invalid!
```

**Step 5: Code (With Comments)**

```cpp
bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // Opening bracket → push to stack
            st.push(c);
        } else {
            // Closing bracket → check match with top
            if (st.empty()) {
                return false;  // No opening bracket to match
            }
            
            char top = st.top();
            
            // Check if closing matches opening
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;  // Mismatch
            }
            
            st.pop();  // Matched → remove from stack
        }
    }
    
    // Stack should be empty (all brackets matched)
    return st.empty();
}

// Time: O(n) - each character processed once
// Space: O(n) - stack can have up to n/2 elements
```

---

### PROBLEM 5: Remove Adjacent Duplicates in String

**Step 1: Problem Statement**

```
You are given a string s consisting of lowercase English letters. 
A duplicate removal consists of choosing two adjacent, equal letters 
and removing them.

Repeat the process until no two adjacent equal letters exist.

Return the final string after all removals.

Example:
  Input: s = "abbaca"
  Output: "ca"
  Explanation:
    "abbaca" → "ca" (remove "bb")
    Then "ca" (no adjacent duplicates)

Constraints: 1 ≤ s.length ≤ 10^5
```

**Step 2: Identification (Pattern Recognition - 3 Sec) 🔥**

```
Q1: FREQUENCY? ❌ NO
Q2: SUBSTRING? ❌ NO
Q3: MATCHING/REMOVAL? ✅ YES
Q4: ADJACENT SAME? ✅ YES
    → Use STACK

This is a STACK problem (Removal/Undo)!
Time: O(n) | Space: O(n)
```

**Step 3: Approach (Think Before Coding)**

```
Approach:
1. Use stack to build result
2. For each character:
   - If stack not empty AND top == current char
     → Pop (remove adjacent duplicate)
   - Else
     → Push (add character to stack)
3. Convert stack to string and return

Why Stack?
- Natural fit for "undo" operations
- LIFO ensures we check most recent character
- Same character pops immediately

Example:
s = "abbaca"

a: stack=[] → push 'a'           stack: [a]
b: stack=[a], top≠'b' → push 'b' stack: [a,b]
b: stack=[a,b], top='b' → pop    stack: [a]
a: stack=[a], top='a' → pop      stack: []
c: stack=[] → push 'c'           stack: [c]
a: stack=[c], top≠'a' → push 'a' stack: [c,a]

Result: "ca" ✅
```

**Step 4: Dry Run (Complete Trace)**

```
s = "ab"

Initialization:
  stack = []

Iteration:
  i=0: c='a'
    stack.empty()? YES
    Push 'a'                       stack: [a]
    
  i=1: c='b'
    stack.empty()? NO
    stack.top()='a', c='b'
    'a' ≠ 'b'? YES
    Push 'b'                       stack: [a,b]

Convert to string:
  Pop 'b' → "b"
  Pop 'a' → "ba"
  Reverse → "ab"

Return: "ab"
```

**Step 5: Code (With Comments)**

```cpp
string removeDuplicates(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            // Adjacent duplicate found → remove
            st.pop();
        } else {
            // Different character or stack empty → add
            st.push(c);
        }
    }
    
    // Convert stack to string
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    // Stack gives reverse order, so reverse back
    reverse(result.begin(), result.end());
    
    return result;
}

// Time: O(n) - each character pushed/popped once
// Space: O(n) - stack can contain n elements
```

---

<a name="scripts"></a>
## 🎤 INTERVIEW COMMUNICATION SCRIPTS

### Script 1: Recognition (First 15 Seconds)

**You Say:**

> "Sir, I see this problem is about **[character frequency/substring search/palindrome check/bracket matching]**.
> 
> This maps to **[hashing/sliding window/two pointer/stack]** pattern.
> 
> I'll use **[map/window pointers/two pointers/stack]** approach.
> 
> Time O(**X**), Space O(**Y**)."

---

### Script 2: HASHING Problems

> "Sir, this is a hashing problem. I need to count character frequencies.
> I'll use an unordered_map to store counts:
> - First pass through string s: increment frequencies
> - Second pass through string t: decrement frequencies
> - Check if all frequencies are zero
> If yes, they're anagrams. Time O(n), Space O(1) for fixed charset."

---

### Script 3: SLIDING WINDOW Problems

> "Sir, this is a sliding window problem with variable constraints.
> I'll maintain a window using two pointers - left and right:
> - Expand right pointer to include characters
> - When constraint violated, shrink from left
> - Track maximum/minimum window seen
> Key is: expand greedily, shrink only when necessary.
> Time O(n), Space O(charset size)."

---

### Script 4: TWO POINTER Problems

> "Sir, this is a two-pointer approach for symmetry checking.
> I'll start with pointers at both ends:
> - Compare characters from both directions
> - Skip non-alphanumeric if needed
> - Move inward until pointers meet
> If all characters match, it's palindrome.
> Time O(n), Space O(1)."

---

### Script 5: STACK Problems

> "Sir, this is a stack problem for bracket matching/removal.
> Stack's LIFO property helps here:
> - Opening brackets: push to stack
> - Closing brackets: check if matches top
> - Adjacent duplicates: if current equals top, pop
> This ensures we handle nesting and matching correctly.
> Time O(n), Space O(n)."

---

<a name="mistakes"></a>
## ❌ COMMON MISTAKES & FIXES

### Mistake 1: Forgetting to Check Empty String ❌

**Wrong:**
```cpp
int maxLen = s[0] - 'a';  // Crash if s is empty!
```

**Correct:**
```cpp
if (s.empty()) return 0;
int maxLen = s[0] - 'a';
```

---

### Mistake 2: Not Reversing Stack Result ❌

**Wrong:**
```cpp
string result = "";
while (!st.empty()) {
    result += st.top();
    st.pop();
}
return result;  // Reversed order!
```

**Correct:**
```cpp
string result = "";
while (!st.empty()) {
    result += st.top();
    st.pop();
}
reverse(result.begin(), result.end());
return result;
```

---

### Mistake 3: Wrong Window Shrinking Logic ❌

**Wrong:**
```cpp
// Forgets to update left when duplicate found
if (lastSeen.count(c)) {
    // Just count, don't move left!
}
```

**Correct:**
```cpp
if (lastSeen.count(c) && lastSeen[c] >= left) {
    left = lastSeen[c] + 1;  // Move left to skip duplicate
}
```

---

### Mistake 4: Case Sensitivity in Palindrome ❌

**Wrong:**
```cpp
if (s[left] != s[right]) {  // 'A' != 'a' !
    return false;
}
```

**Correct:**
```cpp
if (tolower(s[left]) != tolower(s[right])) {
    return false;
}
```

---

### Mistake 5: Stack Not Empty Check ❌

**Wrong:**
```cpp
char top = st.top();  // Crash if empty!
```

**Correct:**
```cpp
if (st.empty()) return false;
char top = st.top();
```

---

<a name="analogies"></a>
## 🌍 REAL-WORLD ANALOGIES

### Analogy 1: HASHING = Library Card System 📚

When checking if two lists have same books:
- Library A: Counter each book type
- Library B: Subtract same book types
- If all counts are zero → Same collections!

**String:** Character frequency matching = **Anagrams**

---

### Analogy 2: SLIDING WINDOW = Train Window 🚂

Watching scenery through a moving train window:
- Expand window (train moves forward) to see new scenery
- Shrink window (train slows down) when seeing same scenery repeatedly
- Track best view seen

**String:** Longest substring without repeating = **Best view achieved**

---

### Analogy 3: TWO POINTER = Mirror Checking 🪞

Checking if your face is symmetrical:
- Compare left cheek with right cheek
- Compare left eye with right eye
- Compare from both ends moving inward

**String:** Palindrome check = **Perfect symmetry**

---

### Analogy 4: STACK = Undo/Redo in Text Editor ✏️

When typing in text editor:
- Each keystroke pushed to undo stack
- Press Ctrl+Z: pop from stack (undo)
- Consecutive same keystrokes: one Ctrl+Z removes both

**String:** Remove adjacent duplicates = **Auto-undo same characters**

---

### Analogy 5: STACK = Plate Stacking 🍽️

Stacking plates in cafeteria:
- Last plate stacked = first plate used (LIFO)
- Matching pair: if top plate matches incoming plate, both used
- Mismatched: stack them separately

**String:** Bracket matching = **Matching pairs, LIFO removal**

---

## 🎯 TOP INTERVIEW PROBLEMS

| # | Problem | Pattern | LeetCode | Difficulty |
|---|---------|---------|----------|------------|
| 1 | Valid Anagram | Hashing | 242 | Easy |
| 2 | Longest Substring Without Repeat | Sliding Window | 3 | Medium |
| 3 | Valid Palindrome | Two Pointer | 125 | Easy |
| 4 | Valid Parentheses | Stack | 20 | Easy |
| 5 | Remove Adjacent Duplicates | Stack | 1047 | Easy |
| 6 | Group Anagrams | Hashing | 49 | Medium |
| 7 | Min Window Substring | Sliding Window | 76 | Hard |
| 8 | First Unique Character | Hashing | 387 | Easy |
| 9 | Reorganize String | Greedy/PQ | 767 | Medium |
| 10 | Edit Distance | DP | 72 | Medium |

---

## 💡 KEY INSIGHTS TO REMEMBER

```
1. Strings = Character Arrays
   Use all array techniques!

2. 7 Patterns Cover 95% of String Problems
   HASHING → Frequency
   SLIDING WINDOW → Substring
   TWO POINTER → Symmetry
   STACK → Matching
   GREEDY/PQ → Best Choice
   RECURSION → Generation
   DP → Optimal

3. Communication > Perfect Code
   Explain pattern first!

4. Real-World Analogies Help Memory
   Text editor, libraries, mirrors, etc.

5. Practice Templates Until Muscle Memory
   Write blind, recognize patterns instantly

6. Always Handle Edge Cases
   Empty string, single char, all same
```

---

## 🚀 YOUR NEXT STEPS

1. **Read through all 7 patterns** - 30 minutes
2. **Memorize 5 templates** - Write them 10 times
3. **Solve 5 problems** - Use 5-step method
4. **Do 8 more problems** - From top problems list
5. **Practice communication** - Say solutions out loud
6. **Speed drills** - Recognize patterns in 3 seconds

---

**🎯 You got this! Strings are just arrays with style!** ✨

*Master these patterns, and string problems become your superpower!*
