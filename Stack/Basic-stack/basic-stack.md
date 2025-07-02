# Stack in Data Structures and Algorithms

---

## 1. Concept

A **stack** is a linear data structure that follows the **Last-In-First-Out (LIFO)** principle.  
- The last element added (pushed) is the first one to be removed (popped).
- Think of a stack of plates: you add/remove plates from the top.

---

## 2. Basic Operations

- **push(x):** Add element x to the top.
- **pop():** Remove and return the top element.
- **top()/peek():** Return the top element without removing it.
- **isEmpty():** Check if the stack is empty.
- **size():** Number of elements in the stack.

**C++ STL Example:**
```cpp
#include <stack>
stack<int> s;
s.push(10);
s.push(20);
s.pop();         // Removes 20
int t = s.top(); // t = 10
bool empty = s.empty();
int sz = s.size();
```

---

## 3. Identification of Stack Problems

**When to use a stack?**
- Problems with "previous/next greater/smaller", "balanced parentheses", "undo", "reverse", "backtracking", "evaluate expressions".
- LIFO order is required.
- Need to remember the order of operations or elements.

**Keywords:**  
previous, next, balanced, reverse, undo, evaluate, span, history, backtracking

---

## 4. Common Stack Problem Varieties

### a. Balanced Parentheses / Bracket Matching

- Check if a string of brackets is balanced.
- Use stack to push opening brackets and match with closing ones.

### b. Next Greater/Smaller Element

- For each element, find the next greater/smaller element to the right or left.
- Use stack to keep track of indices or values.

### c. Stock Span Problem

- For each day, find how many consecutive days before it had a lower price.
- Use stack to track indices.

### d. Evaluate Expressions (Postfix/Prefix/Infix)

- Use stack to evaluate mathematical expressions.

### e. Undo Operations / Browser Back

- Use stack to store history for undo/redo or browser navigation.

### f. Min/Max Stack

- Design a stack that can return the minimum/maximum in O(1) time.

### g. Largest Rectangle in Histogram

- Use stack to find the largest rectangle area in a histogram.

### h. Remove K Digits / Monotonic Stack

- Use stack to maintain increasing/decreasing order for greedy removals.

---

## 5. Advanced Stack Concepts

- **Monotonic Stack:**  
  Stack that is always increasing or decreasing, used for range queries (next/previous greater/smaller).
- **Two Stacks for Queue:**  
  Implement a queue using two stacks.
- **Stack with O(1) min/max:**  
  Use an auxiliary stack to track min/max values.

---

## 6. Example: Next Greater Element

**Problem:** For each element, find the next greater element to its right.

**Code:**
```cpp
vector<int> nextGreater(vector<int>& nums) {
    stack<int> s;
    vector<int> res(nums.size(), -1);
    for(int i = 0; i < nums.size(); i++) {
        while(!s.empty() && nums[i] > nums[s.top()]) {
            res[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}
```

---

## 7. How to Identify Stack Problems

- Is there a need to process elements in reverse order?
- Do you need to undo/redo or backtrack?
- Are you matching pairs (like brackets)?
- Are you looking for "next/previous greater/smaller"?
- Is there a need to maintain a history?

---

## 8. Summary Table

| Problem Type                | Stack Use Case/Pattern         |
|-----------------------------|-------------------------------|
| Balanced Parentheses        | Push/pop brackets             |
| Next Greater/Smaller        | Monotonic stack, indices      |
| Stock Span                  | Indices, monotonic stack      |
| Expression Evaluation       | Operands/operators stack      |
| Undo/Redo                   | History stack                 |
| Min/Max Stack               | Auxiliary stack               |
| Largest Rectangle Histogram | Indices, monotonic stack      |

---

**Summary:**  
Stack is a fundamental DSA tool for LIFO problems, matching, and range queries.  
Recognize stack patterns by looking for LIFO, matching, or "next/previous"