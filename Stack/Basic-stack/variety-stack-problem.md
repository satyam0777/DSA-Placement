# Stack Problem Varieties: Step-by-Step Approach and Thinking

---

## 1. Balanced Parentheses / Bracket Matching

**Problem:**  
Check if a string of brackets is balanced.

**Step-by-Step Thinking:**
1. Traverse the string character by character.
2. If you see an opening bracket, push it onto the stack.
3. If you see a closing bracket:
    - If the stack is empty, it's unbalanced.
    - Pop from the stack and check if it matches the closing bracket.
4. At the end, if the stack is empty, the string is balanced.

**Code:**
```cpp
bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else {
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

---

## 2. Next Greater Element

**Problem:**  
For each element, find the next greater element to its right.

**Step-by-Step Thinking:**
1. Traverse the array from left to right.
2. Use a stack to keep indices of elements for which we haven't found the next greater.
3. For each element:
    - While the stack is not empty and the current element is greater than the element at the top index of the stack:
        - The current element is the next greater for the element at the top index.
        - Pop the index and record the answer.
    - Push the current index onto the stack.
4. For indices left in the stack, the answer is -1.

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

## 3. Stock Span Problem

**Problem:**  
For each day, find how many consecutive days before it had a lower price.

**Step-by-Step Thinking:**
1. Use a stack to keep track of indices of days.
2. For each day:
    - Pop from the stack while the price at the top index is less than or equal to the current price.
    - If the stack is empty, span is i+1.
    - Else, span is i - top of stack.
    - Push the current index onto the stack.

**Code:**
```cpp
vector<int> stockSpan(vector<int>& prices) {
    stack<int> s;
    vector<int> span(prices.size());
    for(int i = 0; i < prices.size(); i++) {
        while(!s.empty() && prices[s.top()] <= prices[i]) s.pop();
        span[i] = s.empty() ? i + 1 : i - s.top();
        s.push(i);
    }
    return span;
}
```

---

## 4. Largest Rectangle in Histogram

**Problem:**  
Find the area of the largest rectangle in a histogram.

**Step-by-Step Thinking:**
1. Use a stack to keep indices of bars.
2. For each bar:
    - While the stack is not empty and the current bar is lower than the bar at the top index:
        - Pop the top index, calculate area with the popped bar as the smallest bar.
        - Width is current index if stack is empty, else current index - stack top - 1.
    - Push the current index onto the stack.
3. After traversing, repeat the process for remaining indices in the stack.

**Code:**
```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0, n = heights.size();
    for(int i = 0; i <= n; i++) {
        int h = (i == n ? 0 : heights[i]);
        while(!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()]; s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}
```

---

## 5. Min Stack (Stack with O(1) Minimum)

**Problem:**  
Design a stack that supports push, pop, top, and retrieving the minimum element in O(1) time.

**Step-by-Step Thinking:**
1. Use two stacks: one for all elements, one for the current minimum.
2. When pushing, also push to min stack if it's empty or new element ≤ min stack top.
3. When popping, pop from min stack if the popped element is the current minimum.

**Code:**
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

---

## Additional Tips for Stack Problem Solving

- **Draw the Stack:**  
  For tricky problems, draw the stack’s state at each step to visualize the process.

- **Trace with Examples:**  
  Manually trace your algorithm with small input examples to understand how the stack evolves.

- **Recognize Monotonic Stack Patterns:**  
  Many "next/previous greater/smaller" problems use a monotonic stack (increasing or decreasing order).

- **Think in Terms of Indices:**  
  For range problems (like histogram, span), often store indices in the stack, not values.

- **Use Stack for Backtracking:**  
  Stack is useful for problems where you need to undo choices (e.g., recursion, DFS, undo operations).

- **Combine with Other Data Structures:**  
  Sometimes, stack is combined with arrays, hash maps, or queues for advanced problems.

- **Practice Edge Cases:**  
  Consider empty input, single element, all increasing/decreasing, and duplicate values.

- **Template Your Code:**  
  Write and reuse templates for common stack problems (e.g., next greater element, balanced parentheses).

- **Understand Stack Overflow:**  
  Be aware of recursion stack limits in recursive solutions.

---

**Remember:**  
Stack problems often require you to think in reverse order, maintain history, or process elements as soon as a certain condition is met.  
Practice a variety of problems to build strong intuition!

---
**Summary:**  
For each stack problem:
- Identify what needs to be tracked (indices, values, min/max, etc.).
- Use the stack to maintain
---

**For Learning these concept in depth watch - Aditya Verma playlist on youtube**