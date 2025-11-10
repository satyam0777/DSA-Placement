# 📚 STACK BASICS - INTERVIEW READY GUIDE
## Foundation for All Stack Problems

---

## 🎯 WHAT IS STACK?

**Stack = LIFO (Last In First Out)**

Think of a **stack of plates**:
- Add plate on top → **PUSH**
- Remove plate from top → **POP**
- See top plate → **PEEK/TOP**

```
     TOP
      ↓
    [30]  ← Last added, first to remove
    [20]
    [10]  ← First added, last to remove
   ------
```

---

## 🔧 BASIC OPERATIONS

### 1. PUSH (Add Element)
```cpp
stack<int> s;
s.push(10);  // Stack: [10]
s.push(20);  // Stack: [10, 20]
s.push(30);  // Stack: [10, 20, 30] (30 on top)
```

### 2. POP (Remove Element)
```cpp
s.pop();  // Removes 30
// Stack now: [10, 20]
```

### 3. TOP/PEEK (See Top Element)
```cpp
int topElement = s.top();  // Returns 20 (doesn't remove)
```

### 4. EMPTY (Check if Empty)
```cpp
if(s.empty()) {
    cout << "Stack is empty";
}
```

### 5. SIZE (Get Size)
```cpp
int size = s.size();  // Returns 2
```

---

## 📝 C++ STL STACK - COMPLETE SYNTAX

```cpp
#include <stack>
using namespace std;

// Declaration
stack<int> s;

// Operations
s.push(10);         // Add element
s.pop();            // Remove top
int top = s.top();  // Get top (without removing)
bool empty = s.empty();  // Check if empty
int size = s.size();     // Get size

// Iteration (need to pop all elements)
while(!s.empty()) {
    cout << s.top() << " ";
    s.pop();
}
```

---

## 🧩 PROBLEM 1: IMPLEMENT STACK USING ARRAY

### Problem Statement:
Implement a stack using an array with push, pop, top, and isEmpty operations.

### Communication Script:
> "Sir, I'll use an array and a top pointer. Initially top = -1 (empty). For push, increment top and add element. For pop, return element at top and decrement. Time O(1) for all operations, space O(n) where n is max size."

### Code:
```cpp
class Stack {
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    
    void push(int x) {
        if(top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    
    int pop() {
        if(top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if(top == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    int size() {
        return top + 1;
    }
    
    ~Stack() {
        delete[] arr;
    }
};
```

### Dry Run:
```
Initial: top = -1, capacity = 5
arr: [_, _, _, _, _]

push(10):
  top = 0
  arr: [10, _, _, _, _]

push(20):
  top = 1
  arr: [10, 20, _, _, _]

push(30):
  top = 2
  arr: [10, 20, 30, _, _]

pop():
  returns 30, top = 1
  arr: [10, 20, 30, _, _] (30 still there but top moved)

peek():
  returns 20 (top = 1)
```

### Time & Space:
- **Time:** O(1) for all operations
- **Space:** O(n) where n is capacity

### Edge Cases:
- Empty stack → Check before pop/peek
- Full stack → Check before push
- Single element → Handle correctly

---

## 🧩 PROBLEM 2: BALANCED PARENTHESES

### Problem Statement:
Given a string containing '(', ')', '{', '}', '[', ']', check if it's balanced.

### Examples:
```
Input: "()"       → Output: true
Input: "()[]{}"   → Output: true
Input: "(]"       → Output: false
Input: "([)]"     → Output: false
Input: "{[]}"     → Output: true
```

### Communication Script:
> "Sir, stack approach. For opening bracket, push to stack. For closing, check if stack top matches - if yes pop and continue, else return false. At end, stack should be empty for balanced. Time O(n), space O(n)."

### Code:
```cpp
bool isValid(string s) {
    stack<char> st;
    
    for(char c : s) {
        // If opening bracket, push
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // If closing bracket
        else {
            // Stack empty means no matching opening
            if(st.empty()) return false;
            
            char top = st.top();
            st.pop();
            
            // Check if matching
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    // Stack should be empty for balanced
    return st.empty();
}
```

### Dry Run:
```
Input: "{[()]}"

i=0, c='{': Opening → push '{'
Stack: ['{']

i=1, c='[': Opening → push '['
Stack: ['{', '[']

i=2, c='(': Opening → push '('
Stack: ['{', '[', '(']

i=3, c=')': Closing
  top = '(', matches ')'
  Pop '('
Stack: ['{', '[']

i=4, c=']': Closing
  top = '[', matches ']'
  Pop '['
Stack: ['{']

i=5, c='}': Closing
  top = '{', matches '}'
  Pop '{'
Stack: []

Stack empty → return true
```

### Time & Space:
- **Time:** O(n) - single pass
- **Space:** O(n) - worst case all opening brackets

### Edge Cases:
- Empty string → true
- Only opening brackets → false
- Only closing brackets → false
- Nested brackets → handle correctly

### Company Frequency:
- **TCS:** 85%
- **Infosys:** 80%
- **Wipro:** 75%
- **Cognizant:** 70%

---

## 🧩 PROBLEM 3: REVERSE STRING USING STACK

### Problem Statement:
Reverse a string using stack.

### Communication Script:
> "Sir, LIFO property of stack naturally reverses. Push all characters to stack, then pop one by one. Time O(n), space O(n) for stack."

### Code:
```cpp
string reverseString(string s) {
    stack<char> st;
    
    // Push all characters
    for(char c : s) {
        st.push(c);
    }
    
    // Pop and build reversed string
    string result = "";
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}
```

### Dry Run:
```
Input: "hello"

Push phase:
  h → Stack: [h]
  e → Stack: [h, e]
  l → Stack: [h, e, l]
  l → Stack: [h, e, l, l]
  o → Stack: [h, e, l, l, o]

Pop phase:
  Pop 'o' → result = "o"
  Pop 'l' → result = "ol"
  Pop 'l' → result = "oll"
  Pop 'e' → result = "olle"
  Pop 'h' → result = "olleh"

Output: "olleh"
```

### Time & Space:
- **Time:** O(n) - push n + pop n
- **Space:** O(n) - stack space

---

## 🧩 PROBLEM 4: DELETE MIDDLE ELEMENT OF STACK

### Problem Statement:
Delete the middle element of a stack.

### Communication Script:
> "Sir, recursive approach. Find middle position (size/2 + 1). Recursively pop elements, skip middle, push back rest. Time O(n), space O(n) for recursion."

### Code:
```cpp
void deleteMidUtil(stack<int>& s, int mid, int curr) {
    // Base case: reached middle
    if(curr == mid) {
        s.pop();
        return;
    }
    
    // Store top and remove
    int temp = s.top();
    s.pop();
    
    // Recursive call
    deleteMidUtil(s, mid, curr + 1);
    
    // Push back after recursion
    s.push(temp);
}

void deleteMiddle(stack<int>& s) {
    int size = s.size();
    if(size == 0) return;
    
    int mid = size / 2 + 1;  // 1-indexed middle
    deleteMidUtil(s, mid, 1);
}
```

### Dry Run:
```
Input Stack: [1, 2, 3, 4, 5] (5 on top)
Size = 5, Mid = 3 (1-indexed)

Call deleteMidUtil(s, 3, 1):
  curr=1, temp=5, pop → Stack: [1,2,3,4]
  Call deleteMidUtil(s, 3, 2):
    curr=2, temp=4, pop → Stack: [1,2,3]
    Call deleteMidUtil(s, 3, 3):
      curr=3 == mid → pop → Stack: [1,2]
      return
    push 4 → Stack: [1,2,4]
    return
  push 5 → Stack: [1,2,4,5]
  return

Output Stack: [1, 2, 4, 5] (3 deleted)
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n) - recursion stack

---

## 🧩 PROBLEM 5: SORT A STACK

### Problem Statement:
Sort a stack in ascending order (smallest on top).

### Communication Script:
> "Sir, recursive approach. Pop all elements, insert each in sorted position while backtracking. Time O(n²), space O(n) for recursion."

### Code:
```cpp
void sortedInsert(stack<int>& s, int element) {
    // Base case: stack empty or element greater than top
    if(s.empty() || element > s.top()) {
        s.push(element);
        return;
    }
    
    // Remove top and recurse
    int temp = s.top();
    s.pop();
    sortedInsert(s, element);
    
    // Put back temp
    s.push(temp);
}

void sortStack(stack<int>& s) {
    // Base case
    if(s.empty()) return;
    
    // Remove top
    int temp = s.top();
    s.pop();
    
    // Sort remaining
    sortStack(s);
    
    // Insert temp in sorted position
    sortedInsert(s, temp);
}
```

### Dry Run:
```
Input: [30, -5, 18, 14] (14 on top)

sortStack([30, -5, 18, 14]):
  temp = 14, pop → Stack: [30, -5, 18]
  sortStack([30, -5, 18]):
    temp = 18, pop → Stack: [30, -5]
    sortStack([30, -5]):
      temp = -5, pop → Stack: [30]
      sortStack([30]):
        temp = 30, pop → Stack: []
        sortStack([]) → return
        sortedInsert([], 30) → Stack: [30]
      sortedInsert([30], -5):
        30 > -5, so pop 30, recurse
        sortedInsert([], -5) → Stack: [-5]
        push 30 → Stack: [-5, 30]
    sortedInsert([-5, 30], 18):
      30 > 18, pop 30
      sortedInsert([-5], 18):
        18 > -5, push 18 → Stack: [-5, 18]
      push 30 → Stack: [-5, 18, 30]
  sortedInsert([-5, 18, 30], 14):
    30 > 14, pop 30
    sortedInsert([-5, 18], 14):
      18 > 14, pop 18
      sortedInsert([-5], 14):
        14 > -5, push 14 → Stack: [-5, 14]
      push 18 → Stack: [-5, 14, 18]
    push 30 → Stack: [-5, 14, 18, 30]

Output: [-5, 14, 18, 30] (sorted, smallest on top)
```

### Time & Space:
- **Time:** O(n²) - n recursive calls, each with O(n) insertion
- **Space:** O(n) - recursion stack

---

## 🧩 PROBLEM 6: MIN STACK (Get Minimum in O(1))

### Problem Statement:
Design a stack that supports push, pop, top, and retrieving minimum in O(1) time.

### Communication Script:
> "Sir, auxiliary stack approach. Maintain two stacks - main stack for all elements, min stack for tracking minimums. When pushing, also push to min stack if new element ≤ current min. When popping, pop from min stack if element equals current min. All operations O(1)."

### Code:
```cpp
class MinStack {
    stack<int> s;      // Main stack
    stack<int> minS;   // Min stack
    
public:
    void push(int x) {
        s.push(x);
        // Push to min stack if empty or x is new minimum
        if(minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        
        // If popping minimum, pop from min stack too
        if(s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
```

### Dry Run:
```
push(-2):
  s: [-2]
  minS: [-2] (empty, so push)

push(0):
  s: [-2, 0]
  minS: [-2] (0 > -2, don't push)

push(-3):
  s: [-2, 0, -3]
  minS: [-2, -3] (-3 <= -2, push)

getMin(): returns -3

pop():
  s.top() = -3, minS.top() = -3 (equal)
  Pop from both
  s: [-2, 0]
  minS: [-2]

getMin(): returns -2

top(): returns 0
```

### Time & Space:
- **Time:** O(1) for all operations
- **Space:** O(n) - two stacks

### Company Frequency:
- **TCS:** 75%
- **Infosys:** 80%
- **Wipro:** 70%

---

## 🧩 PROBLEM 7: IMPLEMENT TWO STACKS IN ONE ARRAY

### Problem Statement:
Implement two stacks in a single array efficiently.

### Communication Script:
> "Sir, start one stack from left (index 0), other from right (index n-1). For stack1, top1 starts at -1 and grows right. For stack2, top2 starts at n and grows left. Overflow when top1 + 1 == top2. Space efficient O(n) solution."

### Code:
```cpp
class TwoStacks {
    int* arr;
    int size;
    int top1, top2;
    
public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;        // Stack1 starts from left
        top2 = size;      // Stack2 starts from right
    }
    
    void push1(int x) {
        // Check overflow
        if(top1 + 1 == top2) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top1] = x;
    }
    
    void push2(int x) {
        // Check overflow
        if(top1 + 1 == top2) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[--top2] = x;
    }
    
    int pop1() {
        if(top1 == -1) {
            cout << "Stack1 Underflow\n";
            return -1;
        }
        return arr[top1--];
    }
    
    int pop2() {
        if(top2 == size) {
            cout << "Stack2 Underflow\n";
            return -1;
        }
        return arr[top2++];
    }
};
```

### Dry Run:
```
Array size = 5
arr: [_, _, _, _, _]
top1 = -1, top2 = 5

push1(5):
  top1 = 0
  arr: [5, _, _, _, _]

push2(10):
  top2 = 4
  arr: [5, _, _, _, 10]

push1(11):
  top1 = 1
  arr: [5, 11, _, _, 10]

push2(15):
  top2 = 3
  arr: [5, 11, _, 15, 10]

push1(7):
  top1 = 2
  arr: [5, 11, 7, 15, 10]

push1(40):
  top1 + 1 = 3, top2 = 3 → Overflow!

pop1():
  returns 7, top1 = 1
  arr: [5, 11, 7, 15, 10]
```

### Time & Space:
- **Time:** O(1) for all operations
- **Space:** O(n) - single array

---

## 🧩 PROBLEM 8: IMPLEMENT QUEUE USING STACK

### Problem Statement:
Implement queue operations (enqueue, dequeue) using stacks.

### Communication Script:
> "Sir, two stack approach. For enqueue, push to stack1 (O(1)). For dequeue, if stack2 empty, pop all from stack1 and push to stack2 (reverses order), then pop from stack2. Amortized O(1) for both operations."

### Code:
```cpp
class QueueUsingStacks {
    stack<int> s1, s2;
    
public:
    // Enqueue - O(1)
    void enqueue(int x) {
        s1.push(x);
    }
    
    // Dequeue - Amortized O(1)
    int dequeue() {
        // If both empty
        if(s2.empty() && s1.empty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        
        // If s2 empty, transfer from s1
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int front() {
        if(s2.empty() && s1.empty()) {
            return -1;
        }
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }
};
```

### Dry Run:
```
enqueue(1):
  s1: [1]
  s2: []

enqueue(2):
  s1: [1, 2]
  s2: []

dequeue():
  s2 empty, transfer from s1:
    Pop 2 from s1 → push to s2
    Pop 1 from s1 → push to s2
  s1: []
  s2: [2, 1] (1 on top)
  Pop from s2 → returns 1
  s1: []
  s2: [2]

enqueue(3):
  s1: [3]
  s2: [2]

dequeue():
  s2 not empty
  Pop from s2 → returns 2
  s1: [3]
  s2: []

dequeue():
  s2 empty, transfer from s1:
    Pop 3 from s1 → push to s2
  s1: []
  s2: [3]
  Pop from s2 → returns 3
```

### Time & Space:
- **Time:** Amortized O(1) for both enqueue and dequeue
- **Space:** O(n) - two stacks

---

## 🧩 PROBLEM 9: EVALUATE POSTFIX EXPRESSION

### Problem Statement:
Evaluate a postfix expression using stack.

**Example:**
```
Input: "231*+9-"
Output: -4
Explanation: ((2 + (3 * 1)) - 9) = -4
```

### Communication Script:
> "Sir, scan postfix left to right. If operand, push to stack. If operator, pop two operands, apply operator, push result. At end, stack has final answer. Time O(n), space O(n)."

### Code:
```cpp
int evaluatePostfix(string exp) {
    stack<int> s;
    
    for(char c : exp) {
        // If operand, push
        if(isdigit(c)) {
            s.push(c - '0');
        }
        // If operator
        else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            
            switch(c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
            }
        }
    }
    
    return s.top();
}
```

### Dry Run:
```
Input: "231*+9-"

i=0, c='2': digit → push 2
Stack: [2]

i=1, c='3': digit → push 3
Stack: [2, 3]

i=2, c='1': digit → push 1
Stack: [2, 3, 1]

i=3, c='*': operator
  op2 = 1, op1 = 3
  3 * 1 = 3 → push 3
Stack: [2, 3]

i=4, c='+': operator
  op2 = 3, op1 = 2
  2 + 3 = 5 → push 5
Stack: [5]

i=5, c='9': digit → push 9
Stack: [5, 9]

i=6, c='-': operator
  op2 = 9, op1 = 5
  5 - 9 = -4 → push -4
Stack: [-4]

Result: -4
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

### Company Frequency:
- **TCS:** 60%
- **Infosys:** 65%
- **Wipro:** 55%

---

## 🧩 PROBLEM 10: VALID SUBSTRING WITH BALANCED PARENTHESES

### Problem Statement:
Find the length of the longest valid (well-formed) parentheses substring.

**Example:**
```
Input: "(()"
Output: 2
Explanation: "()" is longest valid

Input: ")()())"
Output: 4
Explanation: "()()" is longest valid
```

### Communication Script:
> "Sir, stack with indices approach. Push -1 initially as base. For '(', push index. For ')', pop. If stack empty after pop, push current index (new base). Else, length = current_index - stack_top. Track maximum. Time O(n), space O(n)."

### Code:
```cpp
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  // Base for valid substring
    int maxLen = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else {  // s[i] == ')'
            st.pop();
            
            if(st.empty()) {
                // No matching '(', this ')' is new base
                st.push(i);
            }
            else {
                // Valid substring found
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    
    return maxLen;
}
```

### Dry Run:
```
Input: ")()())"

i=0, s[0]=')':
  Pop -1
  Stack empty → push 0
Stack: [0]
maxLen = 0

i=1, s[1]='(':
  Push 1
Stack: [0, 1]

i=2, s[2]=')':
  Pop 1
  Stack not empty: maxLen = max(0, 2-0) = 2
Stack: [0]
maxLen = 2

i=3, s[3]='(':
  Push 3
Stack: [0, 3]

i=4, s[4]=')':
  Pop 3
  Stack not empty: maxLen = max(2, 4-0) = 4
Stack: [0]
maxLen = 4

i=5, s[5]=')':
  Pop 0
  Stack empty → push 5
Stack: [5]
maxLen = 4

Result: 4 (substring "()()")
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

---

## 📊 COMPANY-WISE FREQUENCY

### TCS (Focus: Basics + Parentheses)
| Problem | Frequency |
|---------|-----------|
| Balanced Parentheses | 85% |
| Implement Stack | 75% |
| Min Stack | 75% |
| Reverse String | 70% |
| Sort Stack | 60% |

### Infosys (Focus: Min Stack + Queue)
| Problem | Frequency |
|---------|-----------|
| Min Stack | 80% |
| Balanced Parentheses | 80% |
| Queue using Stack | 75% |
| Evaluate Postfix | 65% |
| Two Stacks in Array | 60% |

### Wipro (Focus: Balanced Mix)
| Problem | Frequency |
|---------|-----------|
| Balanced Parentheses | 75% |
| Min Stack | 70% |
| Implement Stack | 70% |
| Sort Stack | 65% |
| Delete Middle | 55% |

### Cognizant / Accenture
| Problem | Frequency |
|---------|-----------|
| Balanced Parentheses | 70-75% |
| Implement Stack | 65-70% |
| Reverse String | 60-65% |
| Min Stack | 60-65% |

---

## 🎯 QUICK REVISION CHECKLIST

**Before Interview (5 minutes):**

✅ **Stack Operations:**
```cpp
stack<int> s;
s.push(x);      // Add
s.pop();        // Remove
s.top();        // See top
s.empty();      // Check empty
s.size();       // Get size
```

✅ **Balanced Parentheses Pattern:**
```cpp
// Opening → push
// Closing → check top and pop
// End → stack should be empty
```

✅ **Min Stack Pattern:**
```cpp
// Two stacks: main + min
// Push: to min if x <= minS.top()
// Pop: from min if s.top() == minS.top()
```

✅ **Recursion with Stack:**
```cpp
// Pop, recurse, process, push back
// Base case when empty
```

---

## 💡 COMMON PATTERNS

### Pattern 1: Basic Stack Operations
**When to use:** Direct stack manipulation problems
**Template:**
```cpp
stack<int> s;
// Push, pop, top operations
```

### Pattern 2: Stack with Recursion
**When to use:** Delete middle, sort stack, reverse
**Template:**
```cpp
void solve(stack<int>& s) {
    if(s.empty()) return;  // Base case
    int temp = s.top(); s.pop();
    solve(s);  // Recurse
    // Process temp after recursion
    s.push(temp);
}
```

### Pattern 3: Auxiliary Stack
**When to use:** Min/Max stack, tracking additional info
**Template:**
```cpp
stack<int> main, aux;
// Maintain both in sync
```

### Pattern 4: Stack for Matching
**When to use:** Parentheses, tags, pairs
**Template:**
```cpp
// Opening → push
// Closing → pop and check match
// End → stack empty?
```

---

## 🚨 EDGE CASES TO REMEMBER

```cpp
// 1. Empty stack
if(s.empty()) { /* handle */ }

// 2. Stack overflow (array-based)
if(top == capacity - 1) { /* overflow */ }

// 3. Stack underflow
if(top == -1) { /* underflow */ }

// 4. Single element
if(s.size() == 1) { /* special case */ }

// 5. All same elements
// Test with [5, 5, 5, 5]

// 6. Already sorted
// Test with sorted input
```

---

## 🎓 LEARNING PATH

**Day 1-2: Basics (4-5 hours)**
- Stack implementation (Problem 1)
- Balanced parentheses (Problem 2)
- Reverse string (Problem 3)

**Day 3-4: Intermediate (5-6 hours)**
- Delete middle (Problem 4)
- Sort stack (Problem 5)
- Min stack (Problem 6)

**Day 5-6: Advanced (4-5 hours)**
- Two stacks in array (Problem 7)
- Queue using stack (Problem 8)
- Evaluate postfix (Problem 9)
- Valid parentheses substring (Problem 10)

**Day 7: Practice (3-4 hours)**
- Solve 5-7 problems hands-on
- Practice communication scripts
- Revision of all patterns

---

## 💪 INTERVIEW COMMUNICATION TIPS

### When Explaining Approach:
1. **Mention LIFO:** "Sir, stack follows LIFO, so..."
2. **Explain why stack:** "We need to track in reverse order, so stack is perfect"
3. **State complexity first:** "This will be O(n) time, O(n) space approach"
4. **Draw diagram:** Always show stack state visually

### Sample Communication:
> "Sir, for balanced parentheses, I'll use stack approach. When I see opening bracket, I'll push to stack. For closing bracket, I'll check if top matches - if yes, pop and continue. If stack doesn't match or is empty, return false. At end, stack should be empty for balanced string. This is O(n) time for single pass, O(n) space for stack in worst case when all opening brackets."

---

## 🔥 FINAL TIPS

1. **Always check empty** before top() or pop()
2. **LIFO is key** - last added is first removed
3. **Recursion uses stack** - remember call stack
4. **Draw the stack** - visualize helps immensely
5. **Practice without STL** - understand array implementation
6. **Communicate clearly** - explain LIFO property

**Master these 10 problems → 80% Stack basics covered!** 🚀

---

**Next:** Move to Stack Pattern Problems (Next Greater, Stock Span, etc.)
