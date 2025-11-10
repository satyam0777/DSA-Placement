# 🎯 STRINGS - MASTER CHEAT SHEET


---

## 📋 TABLE OF CONTENTS

1. [Pattern Recognition Table](#recognition)
2. [When to Use Which Pattern - Decision Tree](#decision-tree)
3. [All Templates Quick Reference](#templates)
4. [Complexity Reference](#complexity)
5. [Interview Scripts](#interview)
6. [One-Page Printable Summary](#printable)

---

<a name="recognition"></a>
## 🔥 PATTERN RECOGNITION TABLE

**Use this to decide which pattern in 3 seconds!**

| **Keywords in Problem** | **Pattern** | **Time** | **Key Action** |
|------------------------|-------------|----------|----------------|
| "Anagram" / "frequency" / "count" | HASHING | O(n) | Count chars in map |
| "First unique" / "character frequency" | HASHING | O(n) | Map + first non-repeat |
| "Group anagrams" | HASHING + SORTING | O(nk log k) | Sort as key |
| "Longest substring" / "no repeat" | SLIDING WINDOW | O(n) | Track last seen |
| "Min window" / "contain all chars" | SLIDING WINDOW | O(n) | Expand/shrink window |
| "All anagrams" / "permutation substring" | SLIDING WINDOW | O(n) | Fixed window match |
| "Palindrome" / "check symmetry" | TWO POINTER | O(n) | Compare both ends |
| "Valid palindrome" / "alphanumeric" | TWO POINTER | O(n) | Skip non-alphanum |
| "Reverse string" / "both directions" | TWO POINTER | O(n) | Swap from ends |
| "Valid parentheses" / "brackets" | STACK | O(n) | Push/pop matching |
| "Remove adjacent duplicates" | STACK | O(n) | Pop if top==current |
| "Decode string" / "nested braces" | STACK | O(n) | Two stacks approach |
| "Lexicographically smallest/largest" | GREEDY/PQ | O(n log n) | Priority heap |
| "Reorganize string" / "no adjacent same" | GREEDY/PQ | O(n log n) | Max heap frequent |
| "Edit distance" / "minimum operations" | DP | O(nm) | Overlapping subproblems |
| "Longest common subsequence" | DP | O(nm) | DP table |
| "Regular expression" / "pattern match" | DP/Recursion | O(nm) | Dynamic programming |
| "Generate parentheses" / "all combinations" | RECURSION | O(exponential) | Backtrack all |
| "Word search" / "path finding" | RECURSION | O(exponential) | DFS/Backtrack |
| "Permutations" / "generate all" | RECURSION | O(n!) | Swap & recursion |

---

<a name="decision-tree"></a>
## 🌳 MASTER DECISION TREE - "WHICH PATTERN WHEN?"

```
                    STRING PROBLEM?
                          |
        ┌─────────────────┼─────────────────┐
        |                 |                 |
   Character-based?  Substring-based?  Structure-based?
        |                 |                 |
    Frequency?        Window?            Matching?
     /    \            /    \             /    \
   YES    NO         YES    NO          YES    NO
    |      |          |      |            |      |
HASHING  Other    SLIDING   Other      STACK  Other
         |        WINDOW      |
      Sorting    Variable?   Recursion?
        |         /    \        |
      GREEDY/     F    V       YES
       HASHING    I    A       |
                  X    R    RECURSION
                  E    I
                  D    A
                  |    B
              Both    L
              size    E
```

---

### **Detailed Decision Logic:**

```
╔═══════════════════════════════════════════════════════╗
║  STEP 1: What are you looking for?                    ║
║    ├─ Character count/frequency? → HASHING            ║
║    ├─ Substring with constraints? → SLIDING WINDOW    ║
║    ├─ Symmetry/Palindrome? → TWO POINTER              ║
║    ├─ Matching/Brackets? → STACK                      ║
║    ├─ Best/Lexicographical? → GREEDY/PQ               ║
║    ├─ Generate all? → RECURSION                       ║
║    └─ Optimal value? → DP                             ║
╠═══════════════════════════════════════════════════════╣
║  STEP 2: Is there a constraint?                       ║
║    ├─ Window size? FIXED or VARIABLE?                 ║
║    ├─ All characters? Check entire string             ║
║    ├─ Adjacent check? Use current & previous          ║
║    └─ Nested structure? Stack needed                  ║
╠═══════════════════════════════════════════════════════╣
║  STEP 3: What type of substring?                      ║
║    ├─ Exact match? HASHING or exact search            ║
║    ├─ Best window? SLIDING WINDOW                     ║
║    ├─ All positions? Maybe DP or multiple passes      ║
║    └─ Pattern based? SLIDING WINDOW or DP             ║
╠═══════════════════════════════════════════════════════╣
║  STEP 4: Remember 7 patterns cover 95%!               ║
║    ├─ HASHING → Frequency                             ║
║    ├─ SLIDING WINDOW → Substring                      ║
║    ├─ TWO POINTER → Symmetry                          ║
║    ├─ STACK → Matching                                ║
║    ├─ GREEDY/PQ → Best Choice                         ║
║    ├─ RECURSION → Generate                            ║
║    └─ DP → Optimal                                    ║
╚═══════════════════════════════════════════════════════╝
```

---

<a name="templates"></a>
## 📝 ALL TEMPLATES QUICK REFERENCE

### **Template 1: HASHING (Frequency Map)** 🗺️

```cpp
// ═══════════════════════════════════════════
// PATTERN 1: HASHING
// Use: Anagrams, unique chars, frequency
// Time: O(n) | Space: O(1) fixed charset
// ═══════════════════════════════════════════

// Method 1: Using unordered_map
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : t) freq[c]--;
    for (auto& p : freq) if (p.second != 0) return false;
    return true;
}

// Method 2: Using array (faster)
bool isAnagramArray(string s, string t) {
    if (s.length() != t.length()) return false;
    int count[26] = {0};
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;
    for (int c : count) if (c != 0) return false;
    return true;
}
```

**Mantra:** *"Count and compare!"*

---

### **Template 2: SLIDING WINDOW (Variable Size)** 🪟

```cpp
// ═══════════════════════════════════════════
// PATTERN 2: SLIDING WINDOW (VARIABLE)
// Use: Longest substring, min window
// Time: O(n) | Space: O(min(n, charset))
// ═══════════════════════════════════════════

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int maxLen = 0, left = 0;
    
    for (int right = 0; right < s.length(); right++) {
        if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left) {
            left = lastSeen[s[right]] + 1;  // Shrink!
        }
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

**Mantra:** *"Expand right, shrink left when invalid!"*

---

### **Template 2: SLIDING WINDOW (Fixed Size)** 🪟

```cpp
// ═══════════════════════════════════════════════════════════
// PATTERN 2A: SLIDING WINDOW - FIXED SIZE
// Use: Window of fixed size k, find best value
// Time: O(n) | Space: O(1)
// ═══════════════════════════════════════════════════════════

int i = 0, j = 0;
while (j < n) {
    // Add s[j] to window
    
    if (j - i + 1 < k) {
        j++;                    // Not ready (window not full)
    }
    else if (j - i + 1 == k) {
        // Answer/Update result
        // Remove s[i]
        i++; j++;               // Slide both
    }
}

// MANTRA: "Add j, check size, answer, slide both"
```

---

### **Template 3: SLIDING WINDOW (Variable - All Patterns)** 🪟

```cpp
// ═══════════════════════════════════════════════════════════
// PATTERN 2B: SLIDING WINDOW - SIMPLIFIED (Most Common)
// Use: Most common pattern for all substring problems
// Time: O(n) | Space: O(charset)
// ═══════════════════════════════════════════════════════════

int i = 0, j = 0, maxLen = 0;
while (j < n) {
    // Add s[j] to window
    
    while (condition_invalid) {  // Shrink while bad
        // Remove s[i]
        i++;
    }
    
    maxLen = max(maxLen, j - i + 1);  // Update answer
    j++;
}

// MANTRA: "Add j, while bad shrink i, update max, move j"
```

---

### **Template 4: TWO POINTER** 👈👉

```cpp
// ═══════════════════════════════════════════
// PATTERN 3: TWO POINTER
// Use: Palindrome, symmetry, both ends
// Time: O(n) | Space: O(1)
// ═══════════════════════════════════════════

bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        // Skip non-alphanumeric
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        
        // Compare case-insensitive
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

**Mantra:** *"Compare from both ends, move inward!"*

---

### **Template 5: STACK (Matching)** 📚

```cpp
// ═══════════════════════════════════════════
// PATTERN 4A: STACK - MATCHING
// Use: Valid parentheses, bracket matching
// Time: O(n) | Space: O(n)
// ═══════════════════════════════════════════

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
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
```

**Mantra:** *"Push opening, pop when matching close!"*

---

### **Template 6: STACK (Removal)** 📚

```cpp
// ═══════════════════════════════════════════
// PATTERN 4B: STACK - REMOVAL/UNDO
// Use: Remove adjacent duplicates, decode
// Time: O(n) | Space: O(n)
// ═══════════════════════════════════════════

string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();  // Remove adjacent duplicate
        } else {
            st.push(c);  // Add character
        }
    }
    
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
```

**Mantra:** *"Stack for LIFO matching and removal!"*

---

### **Template 7: PRIORITY QUEUE (Greedy)** ⭐

```cpp
// ═══════════════════════════════════════════
// PATTERN 5: GREEDY / PRIORITY QUEUE
// Use: Reorganize, best choice at each step
// Time: O(n log n) | Space: O(n)
// ═══════════════════════════════════════════

string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
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
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        prev = {count - 1, ch};
    }
    
    return result.length() == s.length() ? result : "";
}
```

**Mantra:** *"Always pick most frequent unused!"*

---

<a name="complexity"></a>
## 📊 COMPLEXITY REFERENCE TABLE

| **Pattern** | **Time** | **Space** | **When to Use** |
|-------------|----------|-----------|-----------------|
| **HASHING** | O(n) | O(1) | Frequency, anagrams, unique |
| **SLIDING WINDOW (Variable)** | O(n) | O(min(n, k)) | Longest substring |
| **SLIDING WINDOW (Fixed)** | O(n) | O(1) | Fixed size constraints |
| **TWO POINTER** | O(n) | O(1) | Palindrome, symmetry |
| **STACK (Matching)** | O(n) | O(n) | Valid parentheses |
| **STACK (Removal)** | O(n) | O(n) | Remove adjacent |
| **GREEDY/PQ** | O(n log n) | O(n) | Best choice, reorganize |
| **RECURSION** | O(exponential) | O(h) | Generate, backtrack |
| **DP** | O(nm) or more | O(nm) | Optimal, overlapping |

---

## 🔑 MAGIC KEYWORDS → PATTERN MAPPING

| **Keyword** | **Pattern** | **Key Action** |
|-----------|-----------|----------------|
| "anagram" | HASHING | freq[c]++ then compare |
| "unique" | HASHING | freq[c] == 1 |
| "frequency" | HASHING | Count in map |
| "longest substring" | SLIDING WINDOW | Expand/shrink |
| "min window" | SLIDING WINDOW | Expand till all, shrink |
| "shortest" | SLIDING WINDOW | Track minimum |
| "palindrome" | TWO POINTER | Compare both ends |
| "reverse" | TWO POINTER | Swap from ends |
| "symmetry" | TWO POINTER | Check from center |
| "valid brackets" | STACK | Push/pop matching |
| "parentheses" | STACK | Match pairs |
| "adjacent duplicates" | STACK | Pop if equal |
| "decode string" | STACK | Two stacks |
| "remove" | STACK | Pop on condition |
| "lexicographical" | GREEDY/PQ | Best at each step |
| "reorganize" | GREEDY/PQ | Most frequent heap |
| "adjacent same" | GREEDY/PQ | Max heap greedy |
| "edit distance" | DP | Overlapping subproblems |
| "generate" | RECURSION | Backtrack all |
| "permutation" | RECURSION | Swap and recurse |

---

<a name="interview"></a>
## 🎤 INTERVIEW SCRIPTS FOR ALL PATTERNS

### **Script 1: Pattern Recognition (First 10 Seconds)**

**You Say:**

> "Sir, I see this is a **[frequency/substring/palindrome/matching]** problem.
> 
> This maps to **[hashing/sliding window/two pointer/stack]** pattern.
> 
> I'll use **[map/pointers/stack/PQ]** approach.
> 
> Time **O(X)**, Space **O(Y)**."

---

### **Script 2: HASHING Problems**

> "Sir, this is a hashing problem with character frequencies. I'll count occurrences using an unordered_map or array. Then I'll compare frequencies. If all match, the condition is satisfied. Time O(n) because each character is processed once. Space O(1) for fixed charset (26 lowercase letters)."

---

### **Script 3: SLIDING WINDOW Problems**

> "Sir, this is a sliding window problem. I need a window that expands and contracts based on constraints. I'll use two pointers - left and right. Expand right to include characters. When the window violates constraints, shrink from left. Track the best window seen. Time O(n) because each character is visited at most twice. Space O(charset)."

---

### **Script 4: TWO POINTER Problems**

> "Sir, this is a two-pointer approach for symmetry/palindrome checking. I start with pointers at both ends. I skip non-alphanumeric characters if needed. I compare characters case-insensitively. If all match, it's a palindrome. Time O(n) with single pass. Space O(1) using only pointers."

---

### **Script 5: STACK Problems**

> "Sir, this is a stack problem. Stack's LIFO property helps with matching and removal. For matching: push opening brackets, pop when closing matches. For removal: pop when current equals top, else push. Stack ensures we handle nesting correctly. Time O(n), Space O(n)."

---

### **Script 6: GREEDY/PQ Problems**

> "Sir, this is a greedy problem with priority queue. At each step, I pick the best available option - the most frequent character. I use a max-heap to always access the most frequent. I ensure constraints are met by careful placement. Time O(n log n) for heap operations."

---

<a name="printable"></a>
## 📋 ONE-PAGE PRINTABLE SUMMARY

```
╔══════════════════════════════════════════════════════════════════════╗
║        STRINGS - COMPLETE CHEAT SHEET                                ║
║                  ALL PATTERNS IN ONE PAGE                            ║
╚══════════════════════════════════════════════════════════════════════╝

┌──────────────────────────────────────────────────────────────────────┐
│ 1️⃣  PATTERN RECOGNITION (3 SECONDS!)                                │
├──────────────────────────────────────────────────────────────────────┤
│ Q1: Character frequency/count? ✅ → HASHING                          │
│ Q2: Substring with constraints? ✅ → SLIDING WINDOW                  │
│ Q3: Symmetry/palindrome? ✅ → TWO POINTER                            │
│ Q4: Matching/brackets? ✅ → STACK                                    │
│ Q5: Best/lexicographical? ✅ → GREEDY/PQ                            │
│ Q6: Generate all? ✅ → RECURSION                                     │
│ Q7: Optimal value? ✅ → DP                                           │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 2️⃣  KEYWORDS → PATTERN                                               │
├──────────────────────────────────────────────────────────────────────┤
│ "anagram" → HASHING                                                  │
│ "longest substring" → SLIDING WINDOW                                 │
│ "palindrome" → TWO POINTER                                           │
│ "valid brackets" → STACK                                             │
│ "lexicographically" → GREEDY/PQ                                     │
│ "edit distance" → DP                                                 │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 3️⃣  THE 7 GOLDEN TEMPLATES                                           │
├──────────────────────────────────────────────────────────────────────┤
│                                                                      │
│ 1. HASHING:                                                         │
│    for(c:s) freq[c]++; for(c:t) freq[c]--;                         │
│    if all zero → true                                               │
│                                                                      │
│ 2. SLIDING WINDOW (Variable):                                       │
│    if(lastSeen[c] >= left) left = lastSeen[c] + 1;                │
│    maxLen = max(maxLen, right - left + 1);                          │
│                                                                      │
│ 3. SLIDING WINDOW (Fixed):                                          │
│    Build window, then: remove s[i-k], add s[i]                     │
│                                                                      │
│ 4. TWO POINTER:                                                     │
│    left=0, right=n-1; while(left<right)                            │
│    Compare, adjust pointers                                        │
│                                                                      │
│ 5. STACK (Matching):                                                │
│    Push opening, pop on matching close                             │
│    Final: stack.empty()? true                                      │
│                                                                      │
│ 6. STACK (Removal):                                                 │
│    if(top==current) pop; else push                                 │
│    Reverse result before return                                    │
│                                                                      │
│ 7. PRIORITY QUEUE:                                                  │
│    maxHeap.push({freq, char})                                      │
│    Always pick most frequent first                                 │
│                                                                      │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 4️⃣  GOLDEN FORMULAS                                                  │
├──────────────────────────────────────────────────────────────────────┤
│ • Window length = right - left + 1                                   │
│ • Anagram = all frequencies 0                                       │
│ • Palindrome = s[i] == s[n-1-i]                                    │
│ • Stack LIFO = most recent on top                                   │
│ • Always skip left/right as needed before comparing                │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 5️⃣  COMPLEXITY                                                        │
├──────────────────────────────────────────────────────────────────────┤
│ HASHING: O(n) time, O(1) space                                       │
│ SLIDING WINDOW: O(n) time, O(charset) space                          │
│ TWO POINTER: O(n) time, O(1) space                                   │
│ STACK: O(n) time, O(n) space                                         │
│ GREEDY/PQ: O(n log n) time, O(n) space                              │
│ DP: O(nm) or more, O(nm) or more space                              │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 6️⃣  DECISION TREE                                                     │
├──────────────────────────────────────────────────────────────────────┤
│                                                                      │
│                   String Problem                                    │
│                           |                                         │
│          ┌────────────────┼────────────────┐                       │
│          |                |                |                       │
│     Frequency?      Substring?       Matching?                    │
│          |                |                |                       │
│        YES              YES              YES                       │
│         |                |                |                       │
│    HASHING       SLIDING WINDOW         STACK                     │
│                                                                   │
│     No? Check if Symmetry/Palindrome → TWO POINTER               │
│     No? Check if Best Choice → GREEDY/PQ                        │
│     No? Check if Optimal → DP                                    │
│     No? Check if Generate → RECURSION                           │
│                                                                   │
└──────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 7️⃣  COMMON MISTAKES (AVOID!)                                         │
├──────────────────────────────────────────────────────────────────────┤
│ ❌ Not checking empty string                                         │
│ ✅ if(s.empty()) return;                                            │
│                                                                      │
│ ❌ Forgetting to reverse stack result                               │
│ ✅ reverse(result.begin(), result.end());                           │
│                                                                      │
│ ❌ Wrong window update logic                                        │
│ ✅ Check if char seen AND within current window                    │
│                                                                      │
│ ❌ Case sensitivity in palindrome                                   │
│ ✅ Use tolower() for comparison                                    │
│                                                                      │
│ ❌ Stack overflow without empty check                               │
│ ✅ Always check if(st.empty()) before st.top()                    │
│                                                                      │
│ ❌ Skipping non-alphanumeric in palindrome                         │
│ ✅ while(left < right && !isalnum(s[left])) left++;               │
│                                                                      │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 8️⃣  TOP 10 PROBLEMS (Master These!)                                  │
├──────────────────────────────────────────────────────────────────────┤
│ 1. Valid Anagram          - HASHING        - 3 min  ⭐⭐⭐⭐⭐    │
│ 2. Longest Substring      - SLIDING WINDOW - 5 min  ⭐⭐⭐⭐⭐    │
│ 3. Valid Palindrome       - TWO POINTER    - 4 min  ⭐⭐⭐⭐⭐    │
│ 4. Valid Parentheses      - STACK          - 3 min  ⭐⭐⭐⭐⭐    │
│ 5. Remove Duplicates      - STACK          - 4 min  ⭐⭐⭐⭐⭐    │
│ 6. Group Anagrams         - HASHING        - 8 min  ⭐⭐⭐⭐      │
│ 7. Min Window Substring   - SLIDING WINDOW - 10 min ⭐⭐⭐⭐⭐    │
│ 8. Reorganize String      - GREEDY/PQ      - 7 min  ⭐⭐⭐⭐      │
│ 9. First Unique Character - HASHING        - 5 min  ⭐⭐⭐⭐      │
│ 10. Edit Distance         - DP             - 12 min ⭐⭐⭐⭐      │
│                                                                      │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 9️⃣  MANTRAS (RECITE DAILY!)                                          │
├──────────────────────────────────────────────────────────────────────┤
│ 1. "Strings = Character Arrays!"                                    │
│ 2. "7 Patterns = 95% of Problems!"                                 │
│ 3. "Frequency? → HASHING!"                                         │
│ 4. "Substring? → SLIDING WINDOW!"                                  │
│ 5. "Symmetry? → TWO POINTER!"                                      │
│ 6. "Matching? → STACK!"                                            │
│ 7. "Best Choice? → GREEDY/PQ!"                                    │
│ 8. "Expand greedily, shrink when invalid!"                         │
│ 9. "Communication > Perfect Code!"                                 │
│ 10. "You got this! 💪"                                             │
│                                                                      │
└──────────────────────────────────────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────────┐
│ 🔟  REAL-WORLD EXAMPLES                                              │
├──────────────────────────────────────────────────────────────────────┤
│ HASHING:        📚 Library book system                               │
│ SLIDING WINDOW: 🚂 Train viewing scenery                             │
│ TWO POINTER:    🪞 Mirror symmetry checking                          │
│ STACK:          🍽️ Plate stacking (LIFO)                            │
│ GREEDY/PQ:      ⭐ Pick best player available                        │
│                                                                      │
└──────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════╗
║  PRINT THIS → REVISE DAILY → ACE INTERVIEWS! 🚀                     ║
╚══════════════════════════════════════════════════════════════════════╝
```


---

## 🎯 CORE PRINCIPLE

```
╔════════════════════════════════════════════════════╗
║                                                    ║
║   "Read problem → Recognize pattern (3 seconds)    ║
║    → Write template from muscle memory             ║
║    → Fill in logic → Test with example → Done!"    ║
║                                                    ║
║   7 patterns solve 95% of string problems!         ║
║                                                    ║
╚════════════════════════════════════════════════════╝
```

---


