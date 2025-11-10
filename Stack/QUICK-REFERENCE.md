# ⚡ STACK - QUICK REFERENCE SHEET
## Last-Minute Revision (Print This!)

---

## 🎯 PATTERN DECISION TREE

```
┌─ "matching", "balanced", "valid" → BALANCED PARENTHESES
│
├─ "next greater" → NGR/NGL (Monotonic, pop <=)
│
├─ "next smaller" → NSR/NSL (Monotonic, pop >=)
│
├─ "consecutive days/span" → STOCK SPAN (NGL + indices)
│
├─ "min/max in O(1)" → AUXILIARY STACK
│
├─ "reverse" → BASIC LIFO PROPERTY
│
└─ "rectangle", "histogram" → NSL + NSR COMBINATION
```

---

## 📝 TOP 8 MUST-KNOW TEMPLATES

### 1. BALANCED PARENTHESES
```cpp
bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top(); st.pop();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) return false;
        }
    }
    return st.empty();
}
```

### 2. MIN STACK
```cpp
stack<int> s, minS;
void push(int x) {
    s.push(x);
    if(minS.empty() || x <= minS.top()) minS.push(x);
}
void pop() {
    if(s.top() == minS.top()) minS.pop();
    s.pop();
}
int getMin() { return minS.top(); }
```

### 3. NEXT GREATER TO RIGHT (NGR)
```cpp
vector<int> NGR(vector<int>& arr) {
    vector<int> v;
    stack<int> s;
    for(int i = n-1; i >= 0; i--) {  // Right to left
        while(!s.empty() && s.top() <= arr[i]) s.pop();
        v.push_back(s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());  // Must reverse!
    return v;
}
```

### 4. NEXT GREATER TO LEFT (NGL)
```cpp
vector<int> NGL(vector<int>& arr) {
    vector<int> v;
    stack<int> s;
    for(int i = 0; i < n; i++) {  // Left to right
        while(!s.empty() && s.top() <= arr[i]) s.pop();
        v.push_back(s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    return v;  // No reverse!
}
```

### 5. NEXT SMALLER TO RIGHT (NSR)
```cpp
vector<int> NSR(vector<int>& arr) {
    vector<int> v;
    stack<int> s;
    for(int i = n-1; i >= 0; i--) {  // Right to left
        while(!s.empty() && s.top() >= arr[i]) s.pop();  // Pop >=
        v.push_back(s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());  // Must reverse!
    return v;
}
```

### 6. NEXT SMALLER TO LEFT (NSL)
```cpp
vector<int> NSL(vector<int>& arr) {
    vector<int> v;
    stack<int> s;
    for(int i = 0; i < n; i++) {  // Left to right
        while(!s.empty() && s.top() >= arr[i]) s.pop();  // Pop >=
        v.push_back(s.empty() ? -1 : s.top());
        s.push(arr[i]);
    }
    return v;  // No reverse!
}
```

### 7. STOCK SPAN (NGL with Indices)
```cpp
vector<int> stockSpan(vector<int>& prices) {
    vector<int> span;
    stack<int> s;  // Store INDICES
    for(int i = 0; i < n; i++) {
        while(!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        span.push_back(s.empty() ? i+1 : i - s.top());
        s.push(i);
    }
    return span;
}
```

### 8. LARGEST RECTANGLE IN HISTOGRAM
```cpp
int largestRectangle(vector<int>& heights) {
    // Step 1: Find NSL indices
    vector<int> left = NSL_indices(heights);
    
    // Step 2: Find NSR indices
    vector<int> right = NSR_indices(heights);
    
    // Step 3: Calculate max area
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}
```

---

## 🔥 ADITYA VERMA'S 4 FUNDAMENTAL PATTERNS

| Pattern | Direction | Pop When | Reverse? | Use Case |
|---------|-----------|----------|----------|----------|
| **NGR** | ← (n-1→0) | <= | YES | Daily temps, next warmer |
| **NGL** | → (0→n-1) | <= | NO | Stock span base |
| **NSR** | ← (n-1→0) | >= | YES | Histogram right bound |
| **NSL** | → (0→n-1) | >= | NO | Histogram left bound |

**Memory Trick:**
- **RIGHT side** → go **RIGHT to LEFT** → **REVERSE** result
- **LEFT side** → go **LEFT to RIGHT** → **NO REVERSE**
- **GREATER** → pop **smaller/equal** (<=)
- **SMALLER** → pop **greater/equal** (>=)

---

## 💬 COMMUNICATION SCRIPTS

### When you see BALANCED PARENTHESES:
> "Sir, stack-based matching approach. For opening bracket, push to stack. For closing, check if top matches - if yes pop, else invalid. At end, stack should be empty. Time O(n), space O(n)."

### When you see NEXT GREATER:
> "Sir, monotonic stack approach. Traverse right to left, maintain decreasing stack. Pop smaller elements until greater found - that's the answer. Each element pushed/popped once, so Time O(n), space O(n)."

### When you see STOCK SPAN:
> "Sir, this is Next Greater Left variation! Stack stores indices. For each day, pop while price <= current. Span = current index - stack top (or i+1 if empty). Time O(n), space O(n)."

### When you see MIN STACK:
> "Sir, auxiliary stack technique. Maintain two stacks - main for all elements, min for tracking minimums. Push to min only if element <= current min. Pop from min only if equal to main top. All operations O(1)."

### When you see HISTOGRAM:
> "Sir, combination of NSL and NSR! For each bar, find nearest smaller on left and right - these define boundaries. Width = right - left - 1, area = height * width. Track maximum. Time O(n), space O(n)."

---

## 📊 COMPANY-WISE TOP 3

### TCS (Focus: Basics + Stock Span)
1. **Balanced Parentheses** - 85%
2. **Stock Span** - 85%
3. **Next Greater Element** - 80%

### Infosys (Focus: Min Stack + Patterns)
1. **Next Greater Element** - 85%
2. **Min Stack** - 80%
3. **Stock Span** - 80%

### Wipro (Focus: Balanced Mix)
1. **Balanced Parentheses** - 75%
2. **Stock Span** - 75%
3. **Next Greater Element** - 75%

### Cognizant / Accenture
1. **Balanced Parentheses** - 70-75%
2. **Implement Stack** - 65-70%
3. **Min Stack** - 60-65%

---

## ⏰ TIME COMPLEXITIES (MEMORIZE!)

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Push | O(1) | O(1) | Direct operation |
| Pop | O(1) | O(1) | Direct operation |
| Top/Peek | O(1) | O(1) | Direct access |
| Balanced Parentheses | O(n) | O(n) | Single pass |
| Min Stack (all ops) | O(1) | O(n) | Auxiliary stack |
| NGR/NGL/NSR/NSL | O(n) | O(n) | Each element once |
| Stock Span | O(n) | O(n) | Index stack |
| Largest Histogram | O(n) | O(n) | NSL + NSR |
| Sort Stack | O(n²) | O(n) | Nested operations |

---

## 🔧 C++ STACK STL - QUICK SYNTAX

```cpp
#include <stack>

// Declaration
stack<int> s;

// Operations
s.push(10);         // Add element
s.pop();            // Remove top (no return value!)
int top = s.top();  // Get top element
bool empty = s.empty();  // Check if empty
int size = s.size();     // Get size

// Common pattern: process all elements
while(!s.empty()) {
    int val = s.top();
    s.pop();
    // Process val
}
```

---

## 🚨 COMMON EDGE CASES

```cpp
// ALWAYS CHECK:

// 1. Empty stack
if(s.empty()) { /* handle */ }

// 2. Empty input
if(arr.size() == 0) return result;

// 3. Single element
if(n == 1) return {-1};

// 4. All same elements
// Test: [5, 5, 5, 5]

// 5. Increasing sequence
// Test: [1, 2, 3, 4]

// 6. Decreasing sequence
// Test: [4, 3, 2, 1]

// 7. Null pointers (for custom implementation)
if(!s.empty()) { ... }
```

---

## 💡 COMMON PATTERNS AT A GLANCE

### Pattern 1: Basic Stack Ops
```cpp
stack<int> s;
s.push(x);
s.pop();
int top = s.top();
```

### Pattern 2: Matching Pairs
```cpp
if(opening) s.push(c);
else {
    if(s.empty() || !matches) return false;
    s.pop();
}
return s.empty();
```

### Pattern 3: Monotonic Stack (Generic)
```cpp
for(int i = START; CONDITION; UPDATE) {
    while(!s.empty() && COMPARE) s.pop();
    result = s.empty() ? DEFAULT : s.top();
    s.push(arr[i]);
}
if(REVERSE_NEEDED) reverse(result);
```

### Pattern 4: Auxiliary Stack
```cpp
stack<int> main, aux;
// Maintain both in sync
// aux tracks min/max/sum/etc.
```

### Pattern 5: Recursion with Stack
```cpp
void solve(stack<int>& s) {
    if(s.empty()) return;  // Base
    int temp = s.top(); s.pop();
    solve(s);  // Recurse
    // Process temp
    s.push(temp);
}
```

---

## 🎯 PATTERN RECOGNITION KEYWORDS

| Keywords | Pattern | Template |
|----------|---------|----------|
| "balanced", "valid", "matching" | Balanced Parentheses | Push open, pop close |
| "next greater", "warmer" | NGR/NGL | Monotonic, pop <= |
| "next smaller" | NSR/NSL | Monotonic, pop >= |
| "span", "consecutive days" | Stock Span | NGL + indices |
| "minimum in O(1)" | Min Stack | Auxiliary stack |
| "reverse" | LIFO | Push all, pop all |
| "histogram", "rectangle" | Histogram | NSL + NSR |
| "undo", "backtrack" | History Stack | Push states |

---

## 🔥 INTERVIEW DAY CHECKLIST

**30 minutes before:**
- [ ] Stack operations memorized (push, pop, top, empty)
- [ ] Balanced parentheses logic clear
- [ ] NGR template ready
- [ ] Stock span approach understood
- [ ] Edge cases ready (empty, single element)

**In interview:**
- [ ] Draw diagram showing stack states
- [ ] Explain why stack (LIFO, matching, tracking)
- [ ] Mention time/space complexity
- [ ] Handle edge cases explicitly
- [ ] Do dry run with example
- [ ] Stay calm!

---

## 🌟 THE 4-PATTERN MANTRA

```
Problem mentions:
    Next GREATER → Pop SMALLER (<=)
    Next SMALLER → Pop GREATER (>=)
    To RIGHT → Go RIGHT to LEFT + REVERSE
    To LEFT → Go LEFT to RIGHT + NO REVERSE
```

**Example Decision:**
- "Next **Greater** to **Right**" → Pop <=, ← traverse, reverse ✅
- "Next **Smaller** to **Left**" → Pop >=, → traverse, no reverse ✅

---

## 💪 FINAL TIPS

1. **Always check empty** before top() or pop()
2. **Draw stack states** during interview
3. **NGR = Right to Left + Reverse** (remember this!)
4. **Stock Span = NGL + indices** (direct pattern)
5. **Min Stack = Auxiliary stack** (two stacks trick)
6. **Histogram = NSL + NSR** (combination)
7. **Communicate clearly** - explain LIFO, pattern, complexity

---

## 🎓 QUICK PROBLEM SOLVER

**See "balanced" or "valid"?**
→ Balanced Parentheses pattern

**See "next greater"?**
→ Monotonic stack, pop <=, check direction for reverse

**See "span" or "consecutive"?**
→ Stock Span = NGL with indices

**See "min/max in O(1)"?**
→ Auxiliary stack

**See "histogram" or "rectangle"?**
→ NSL + NSR combination

**See "reverse"?**
→ Basic LIFO property

---

## 🚀 YOU GOT THIS!

**Remember:**
- **Matching?** → Balanced Parentheses
- **Greater?** → Pop <=
- **Smaller?** → Pop >=
- **Right?** → ← + reverse
- **Left?** → → + no reverse
- **Span?** → Indices!

**Stack mastery = Pattern recognition!**

**All the best, Satyam!** 🌟  
**Interview crush करोगे!** 💯

---

**Print this sheet and keep it handy!** 📄✅
