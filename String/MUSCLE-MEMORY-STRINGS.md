# 🧠 STRINGS - MUSCLE MEMORY EDITION (One-Page Printable)
*All Patterns, Templates & Mantras for Daily Revision*

---

## 📋 3-SECOND RECOGNITION CHECKLIST

| See This Keyword | Pattern | Key Action |
|------------------|---------|-----------|
| "anagram", "frequency", "count" | HASHING | Map frequencies |
| "longest", "shortest", "substring" | SLIDING WINDOW | Expand/shrink |
| "palindrome", "reverse", "both ends" | TWO POINTER | Start ends, move in |
| "valid", "match", "remove", "adjacent" | STACK | LIFO matching |
| "lexicographically", "best", "reorganize" | GREEDY/PQ | Always pick best |
| "generate", "all combinations" | RECURSION | Backtrack all |
| "edit", "distance", "common", "optimal" | DP | Overlapping subproblems |

---

## 🎯 THE 7 GOLDEN TEMPLATES

### TEMPLATE 1: HASHING (Frequency Map) 🗺️

```cpp
unordered_map<char, int> freq;
for(char c : s) freq[c]++;      // Count s
for(char c : t) freq[c]--;      // Subtract t
for(auto& p : freq) {
    if(p.second != 0) return false;
}
return true;
// Mantra: "Count and compare!"
```

**Use:** Anagrams, unique chars, frequency validation

---

### TEMPLATE 2: SLIDING WINDOW (Fixed Size) 🪟

```cpp
int i = 0, j = 0;
while (j < n) {
    // Add s[j] to window
    
    if (j - i + 1 < k) {
        j++;                    // Not ready
    }
    else if (j - i + 1 == k) {
        // Answer
        // Remove s[i]
        i++; j++;               // Slide both
    }
}
// Mantra: "Add j, check size, answer, slide both"
```

**Use:** Fixed window of size k, max/min value

---

### TEMPLATE 3: SLIDING WINDOW (Variable - 3 Conditions) 🪟

```cpp
int i = 0, j = 0;
while (j < n) {
    // Add s[j]
    
    if (condition_valid) {      // 🟢 Valid
        // Update answer
        j++;                    // Expand
    }
    else {                      // 🔴 Invalid
        while (condition_invalid) {  // Shrink
            // Remove s[i]
            i++;
        }
        j++;
    }
}
// Mantra: "Add j, while invalid shrink i, update max, move j"
```

**Use:** Variable window with flexibility

---

### TEMPLATE 4: SLIDING WINDOW (Simplified) 🪟

```cpp
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
// Mantra: "Add j, while bad shrink i, update max, move j"
```

**Use:** Most common - longest substring problems

---

### TEMPLATE 5: TWO POINTER 👈👉

```cpp
int left = 0, right = s.length() - 1;
while(left < right) {
    while(left < right && !isalnum(s[left])) left++;
    while(left < right && !isalnum(s[right])) right--;
    if(tolower(s[left]) != tolower(s[right])) return false;
    left++; right--;
}
return true;
// Mantra: "Start from ends, move inward!"
```

**Use:** Palindrome checks, reverse operations, symmetry

---

### TEMPLATE 6: STACK (Matching) 📚

```cpp
stack<char> st;
for(char c : s) {
    if(isOpening(c)) {
        st.push(c);
    } else {
        if(st.empty() || !matches(st.top(), c)) return false;
        st.pop();
    }
}
return st.empty();
// Mantra: "Push opening, pop on matching close!"
```

**Use:** Valid parentheses, bracket matching

---

### TEMPLATE 7: STACK (Removal) 📚

```cpp
stack<char> st;
for(char c : s) {
    if(!st.empty() && st.top() == c) {
        st.pop();  // Remove adjacent duplicate
    } else {
        st.push(c);  // Add character
    }
}
string result = "";
while(!st.empty()) {
    result += st.top();
    st.pop();
}
reverse(result.begin(), result.end());
return result;
// Mantra: "Stack for undo/removal!"
```

**Use:** Remove adjacent duplicates, decode string

---

### TEMPLATE 8: PRIORITY QUEUE (Greedy) ⭐

```cpp
unordered_map<char, int> freq;
for(char c : s) freq[c]++;
priority_queue<pair<int, char>> maxHeap;
for(auto& p : freq) maxHeap.push({p.second, p.first});

string result = "";
pair<int, char> prev = {0, '#'};
while(!maxHeap.empty()) {
    auto [count, ch] = maxHeap.top(); maxHeap.pop();
    result += ch;
    if(prev.first > 0) maxHeap.push(prev);
    prev = {count - 1, ch};
}
return result.length() == s.length() ? result : "";
// Mantra: "Always pick most frequent!"
```

**Use:** Reorganize string, task scheduling

---

## ⚡ PATTERN DECISION TREE

```
String Problem?
    |
    ├─ Frequency/Count? ──→ HASHING 🗺️
    |
    ├─ Substring/Window? ──→ SLIDING WINDOW 🪟
    |
    ├─ Matching/Balance? ──→ STACK 📚
    |
    ├─ Symmetry/Reverse? ──→ TWO POINTER 👈👉
    |
    ├─ Best Choice? ──→ GREEDY/PQ ⭐
    |
    ├─ Generate All? ──→ RECURSION 🔄
    |
    └─ Optimal Value? ──→ DP 🔷
```

---

## 🧭 PATTERN COMPARISON TABLE

| Pattern | When | Time | Space | Key Operation |
|---------|------|------|-------|---------------|
| HASHING | Frequency | O(n) | O(1) | Map counts |
| SLIDING WINDOW | Substring | O(n) | O(k) | Expand/shrink |
| TWO POINTER | Symmetry | O(n) | O(1) | Compare ends |
| STACK | Matching | O(n) | O(n) | LIFO match |
| GREEDY/PQ | Best | O(n log n) | O(n) | Max heap |

---

## 📊 TOP 10 MUST-KNOW PROBLEMS

| # | Problem | Pattern | Time | Space |
|---|---------|---------|------|-------|
| 1 | Valid Anagram | HASHING | O(n) | O(1) |
| 2 | Longest Substring | SLIDING WINDOW | O(n) | O(k) |
| 3 | Valid Palindrome | TWO POINTER | O(n) | O(1) |
| 4 | Valid Parentheses | STACK | O(n) | O(n) |
| 5 | Remove Duplicates | STACK | O(n) | O(n) |
| 6 | Group Anagrams | HASHING | O(nk) | O(nk) |
| 7 | Min Window Substring | SLIDING WINDOW | O(n) | O(k) |
| 8 | Reorganize String | GREEDY/PQ | O(n log n) | O(n) |
| 9 | First Unique Char | HASHING | O(n) | O(1) |
| 10 | Edit Distance | DP | O(nm) | O(nm) |

---

## 🎤 COMMUNICATION SCRIPTS (One-Liners)

**Anagram:** "Count frequencies with map, subtract and check if all zero."

**Longest Substring:** "Sliding window with last seen index, shrink on duplicate."

**Palindrome:** "Two pointers from ends, compare case-insensitive."

**Valid Parentheses:** "Stack push opening, pop on closing if matches."

**Remove Duplicates:** "Stack pop if top equals current, else push."

**Group Anagrams:** "Sort string as key, group anagrams by key."

**Min Window:** "Sliding window expand until all chars found, shrink to minimize."

**Reorganize:** "Count frequency, use max heap, pick most frequent."

---

## 💪 CORE MANTRAS (Recite 10x Daily!)

```
1. "Strings are character arrays!"
2. "Seven patterns cover 95% of problems!"
3. "Frequency? Hashing!"
4. "Substring? Sliding window!"
5. "Symmetry? Two pointer!"
6. "Matching? Stack!"
7. "Best choice? Greedy/PQ!"
8. "Expand greedily, shrink when needed!"
9. "Communication matters most!"
10. "You got this! 💪"
```

---

## 🧠 MEMORY HOOKS (Visualize These!)

**HASHING = 📚 Library**
Count books by type, check if both libraries same

**SLIDING WINDOW = 🚂 Train**
Window moves, expands to see new, shrinks when seeing same

**TWO POINTER = 🪞 Mirror**
Compare face reflection left-right from center

**STACK = 🍽️ Plate Stack**
Last plate stacked, first one used (LIFO)

**GREEDY = ⭐ Star Player**
Always pick best player available now

---

## ❌ COMMON MISTAKES (Avoid These!)

```
❌ Forgetting empty check
✅ if(s.empty()) return 0;

❌ Not reversing stack result
✅ reverse(result.begin(), result.end());

❌ Wrong window shrinking logic
✅ if(lastSeen.count(c) && lastSeen[c] >= left)
     left = lastSeen[c] + 1;

❌ Case sensitivity in palindrome
✅ if(tolower(s[left]) != tolower(s[right]))

❌ Stack not empty check before pop
✅ if(st.empty()) return false;
✅ char top = st.top();

❌ Forgetting to skip non-alphanumeric
✅ while(left < right && !isalnum(s[left])) left++;
```

---

## ⚙️ STL COMMANDS CHEAT SHEET

```cpp
// Frequency
unordered_map<char, int> freq;
freq[c]++;
freq.count(c);

// Sliding Window
left, right pointers
s.length()

// Case Conversion
tolower(c), toupper(c)

// Alphanumeric Check
isalnum(c), isalpha(c), isdigit(c)

// String Operations
s.substr(i, len)
s.find(ch)
reverse(s.begin(), s.end())

// Stacks
stack<char> st;
st.push(c);
st.pop();
st.top();
st.empty();

// Priority Queue
priority_queue<pair<int, char>> maxHeap;
maxHeap.push({count, ch});
maxHeap.top();
maxHeap.pop();
```

---

## 📄 ONE-PAGE WALLET CARD

```
╔════════════════════════════════════════════╗
║  STRING PROBLEMS - QUICK REFERENCE         ║
╠════════════════════════════════════════════╣
║                                            ║
║  PATTERN RECOGNITION (3 sec)               ║
║  ├─ Frequency? → HASHING 🗺️               ║
║  ├─ Substring? → SLIDING WINDOW 🪟        ║
║  ├─ Symmetry? → TWO POINTER 👈👉          ║
║  ├─ Matching? → STACK 📚                  ║
║  └─ Best? → GREEDY/PQ ⭐                  ║
║                                            ║
║  TOP 5 TEMPLATES                           ║
║  1. freq[c]++ then check              ║
║  2. left=0, right loop with shrink    ║
║  3. left=0, right=n-1, compare        ║
║  4. stack push/pop match logic         ║
║  5. priority_queue max heap            ║
║                                            ║
║  GOLDEN FORMULAS                          ║
║  • Window = right - left + 1          ║
║  • Stack LIFO = most recent           ║
║  • Anagram = all freq = 0             ║
║                                            ║
║  MANTRAS (Say 10x!)                       ║
║  1. Strings = Arrays!                 ║
║  2. 7 patterns = 95% problems!        ║
║  3. Expand greedy, shrink when bad!   ║
║  4. Communication > Code!             ║
║  5. You got this! 💪                  ║
║                                            ║
╚════════════════════════════════════════════╝
```

---

## 🎯 7-DAY REVISION PLAN

**Day 1: HASHING**
- Morning: Write template blind 5x
- Afternoon: Solve valid anagram, first unique char
- Evening: Recite "Count and compare!" 10x

**Day 2: SLIDING WINDOW**
- Morning: Write both templates
- Afternoon: Solve longest substring, min window
- Evening: Recite "Expand, shrink!" 10x

**Day 3: TWO POINTER**
- Morning: Write template
- Afternoon: Solve palindrome variations
- Evening: Visualize mirror analogy

**Day 4: STACK**
- Morning: Write matching & removal templates
- Afternoon: Solve parentheses, remove duplicates
- Evening: Think plate stacking

**Day 5: GREEDY/PQ**
- Morning: Write PQ template
- Afternoon: Solve reorganize string
- Evening: Practice "always pick best!"

**Day 6: MIXED PRACTICE**
- Morning: All templates blind (10 min)
- Afternoon: 10 problems mixed
- Evening: Communication scripts

**Day 7: LIGHT REVIEW**
- Morning: Read this cheat sheet
- Afternoon: Pattern recognition drills
- Evening: Relax! Ready! 😊

---

## 💪 DAILY DRILL (15 Minutes)

**Every Morning:**

```
Step 1: Template Writing (5 min)
  □ Write HASHING template
  □ Write SLIDING WINDOW template
  □ Write TWO POINTER template
  
Step 2: Mantra Recitation (3 min)
  □ Say all 10 mantras once
  
Step 3: Pattern Recognition (5 min)
  □ See 8 problems, name pattern in 3 sec each
  
Step 4: Speed Check (2 min)
  □ Can you write templates blind? YES/NO
```

---

## 🎬 INTERVIEW DAY CHECKLIST

**15 Minutes Before:**

- [ ] Read this wallet card
- [ ] Write all 7 templates blind
- [ ] Say 10 mantras once
- [ ] Deep breath - You got this! 💪

**During Interview:**

```
1. Listen carefully (30 sec)
2. Recognize pattern (10 sec) ← 3 questions!
3. Say: "Sir, this is [pattern]..."
4. Explain approach (1 min)
5. Write template (3 min)
6. Fill in logic (2 min)
7. Dry run (1 min)
8. Complexity (30 sec)
```

**If You Blank Out:**

```
1. Breathe - "Let me think..."
2. Ask clarifying question
3. Write skeleton code
4. Think pattern first
5. Fill in template
6. Test with example
```

---

## 🔥 FINAL POWER TIPS

```
✨ Remember:
  • Pattern recognition = 50% of problem
  • Template code = 30% of problem
  • Communication = 20% of problem

✨ Practice:
  • Write blind until automatic
  • Solve same problem 3 ways
  • Explain out loud
  • Time yourself

✨ Interview:
  • Show thinking process
  • Communicate continuously
  • Ask clarifying questions
  • Optimize only after working solution

✨ Confidence:
  • You know these patterns!
  • You've practiced templates!
  • You're ready! 💪
```

---

## 🎯 SUCCESS FORMULA

```
┌──────────────────────────────────────┐
│  Pattern Recognition (30 sec)        │
│           ↓                          │
│  Template Code (5 min)               │
│           ↓                          │
│  Dry Run & Test (2 min)              │
│           ↓                          │
│  Complexity Analysis (30 sec)        │
│           ↓                          │
│  ✅ SUCCESS!                         │
└──────────────────────────────────────┘
```

---

## 🚀 FINAL SUCCESS MANTRA

**Recite this 10x before interview:**

```
"I know string patterns inside out!
I can recognize in 3 seconds!
I have templates in muscle memory!
I communicate my thinking clearly!
I'm confident and ready!
I will crush this interview! 💪"
```

---

**Print this → Carry in wallet → Revise daily → ACE INTERVIEWS! 🎉**

*Strings are just arrays with style. You got this!* ✨
