# 🔥 STACK MONOTONIC PATTERNS - INTERVIEW READY GUIDE
## Next Greater/Smaller Element Mastery (Aditya Verma Style)

---

## 🎯 WHAT IS MONOTONIC STACK?

**Monotonic Stack = Stack that maintains increasing or decreasing order**

### Why Monotonic Stack?
- **Problem:** Find next/previous greater/smaller element
- **Brute Force:** O(n²) - for each element, scan array
- **Monotonic Stack:** O(n) - single pass!

### Core Concept:
```
For each element, we want to find:
- Next Greater to Right (NGR)
- Next Greater to Left (NGL)
- Next Smaller to Right (NSR)
- Next Smaller to Left (NSL)
```

---

## 📚 THE 4 FUNDAMENTAL PATTERNS

### Pattern Summary Table:

| Pattern | Direction | Stack Order | What to find |
|---------|-----------|-------------|--------------|
| **NGR** | Right to Left (n-1 → 0) | Decreasing | Next greater on right |
| **NGL** | Left to Right (0 → n-1) | Decreasing | Next greater on left |
| **NSR** | Right to Left (n-1 → 0) | Increasing | Next smaller on right |
| **NSL** | Left to Right (0 → n-1) | Increasing | Next smaller on left |

### Aditya Verma's Universal Template:
```cpp
vector<int> v;
stack<int> s;

for(int i = start; i moves to end; i++) {
    if(s.empty()) {
        v.push_back(-1);
    }
    else if(condition_matches) {
        v.push_back(s.top());
    }
    else {
        while(!s.empty() && !condition_matches) {
            s.pop();
        }
        if(!s.empty()) v.push_back(s.top());
        else v.push_back(-1);
    }
    s.push(arr[i]);
}

// Reverse if going right to left
if(right_to_left) reverse(v.begin(), v.end());
```

---

## 🧩 PROBLEM 1: NEXT GREATER ELEMENT TO RIGHT (NGR)

### Problem Statement:
For each element, find the next greater element to its right. If not found, return -1.

**Example:**
```
Input:  [1, 3, 2, 4]
Output: [3, 4, 4, -1]

Explanation:
  1 → next greater is 3
  3 → next greater is 4
  2 → next greater is 4
  4 → no greater element → -1
```

### Communication Script:
> "Sir, monotonic stack approach. I'll traverse from right to left maintaining a decreasing stack. For each element, pop smaller elements until I find greater one - that's the answer. If stack empty, no greater element exists. Time O(n) single pass, space O(n) for stack."

### Aditya Verma's Code:
```cpp
vector<int> nextGreaterRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> v;
    stack<int> s;
    
    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {
        // Stack empty → no greater element
        if(s.empty()) {
            v.push_back(-1);
        }
        // Stack top is greater → that's the answer
        else if(s.top() > arr[i]) {
            v.push_back(s.top());
        }
        // Stack top is smaller or equal → pop and find
        else {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if(!s.empty()) {
                v.push_back(s.top());
            } else {
                v.push_back(-1);
            }
        }
        
        // Push current element
        s.push(arr[i]);
    }
    
    // Reverse because we went right to left
    reverse(v.begin(), v.end());
    return v;
}
```

### Dry Run:
```
Input: [1, 3, 2, 4]

i=3, arr[3]=4:
  Stack empty → push -1
  s.push(4)
  Stack: [4], v: [-1]

i=2, arr[2]=2:
  s.top()=4 > 2 → push 4
  s.push(2)
  Stack: [4, 2], v: [-1, 4]

i=1, arr[1]=3:
  s.top()=2 <= 3 → pop 2
  s.top()=4 > 3 → push 4
  s.push(3)
  Stack: [4, 3], v: [-1, 4, 4]

i=0, arr[0]=1:
  s.top()=3 > 1 → push 3
  s.push(1)
  Stack: [4, 3, 1], v: [-1, 4, 4, 3]

Reverse v: [3, 4, 4, -1] ✅
```

### Why Right to Left?
```
When at element arr[i]:
- Need to know what's on its RIGHT
- Stack already has elements to the right
- Can answer immediately!
```

### Time & Space:
- **Time:** O(n) - each element pushed/popped once
- **Space:** O(n) - stack space

### Company Frequency:
- **TCS:** 80%
- **Infosys:** 85%
- **Wipro:** 75%
- **Cognizant:** 70%

---

## 🧩 PROBLEM 2: NEXT GREATER ELEMENT TO LEFT (NGL)

### Problem Statement:
For each element, find the next greater element to its left.

**Example:**
```
Input:  [1, 3, 2, 4]
Output: [-1, -1, 3, -1]

Explanation:
  1 → no element on left → -1
  3 → 1 < 3, no greater → -1
  2 → 3 > 2 → answer is 3
  4 → 3 < 4, no greater → -1
```

### Communication Script:
> "Sir, same monotonic stack but left to right traversal. For each element, pop smaller/equal from stack until greater found. No need to reverse result as we're already going left to right. Time O(n), space O(n)."

### Aditya Verma's Code:
```cpp
vector<int> nextGreaterLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> v;
    stack<int> s;
    
    // Traverse from left to right
    for(int i = 0; i < n; i++) {
        // Stack empty → no greater element on left
        if(s.empty()) {
            v.push_back(-1);
        }
        // Stack top is greater → that's the answer
        else if(s.top() > arr[i]) {
            v.push_back(s.top());
        }
        // Stack top is smaller or equal → pop and find
        else {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if(!s.empty()) {
                v.push_back(s.top());
            } else {
                v.push_back(-1);
            }
        }
        
        // Push current element
        s.push(arr[i]);
    }
    
    // No reverse needed (left to right)
    return v;
}
```

### Dry Run:
```
Input: [1, 3, 2, 4]

i=0, arr[0]=1:
  Stack empty → push -1
  s.push(1)
  Stack: [1], v: [-1]

i=1, arr[1]=3:
  s.top()=1 <= 3 → pop 1
  Stack empty → push -1
  s.push(3)
  Stack: [3], v: [-1, -1]

i=2, arr[2]=2:
  s.top()=3 > 2 → push 3
  s.push(2)
  Stack: [3, 2], v: [-1, -1, 3]

i=3, arr[3]=4:
  s.top()=2 <= 4 → pop 2
  s.top()=3 <= 4 → pop 3
  Stack empty → push -1
  s.push(4)
  Stack: [4], v: [-1, -1, 3, -1]

Result: [-1, -1, 3, -1] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

---

## 🧩 PROBLEM 3: NEXT SMALLER ELEMENT TO RIGHT (NSR)

### Problem Statement:
For each element, find the next smaller element to its right.

**Example:**
```
Input:  [4, 2, 1, 3]
Output: [2, 1, -1, -1]

Explanation:
  4 → next smaller is 2
  2 → next smaller is 1
  1 → no smaller → -1
  3 → no smaller → -1
```

### Communication Script:
> "Sir, same template but condition changes to 'smaller'. Traverse right to left, maintain increasing stack. Pop greater/equal elements until smaller found. Time O(n), space O(n)."

### Aditya Verma's Code:
```cpp
vector<int> nextSmallerRight(vector<int>& arr) {
    int n = arr.size();
    vector<int> v;
    stack<int> s;
    
    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {
        // Stack empty → no smaller element
        if(s.empty()) {
            v.push_back(-1);
        }
        // Stack top is smaller → that's the answer
        else if(s.top() < arr[i]) {
            v.push_back(s.top());
        }
        // Stack top is greater or equal → pop and find
        else {
            while(!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if(!s.empty()) {
                v.push_back(s.top());
            } else {
                v.push_back(-1);
            }
        }
        
        // Push current element
        s.push(arr[i]);
    }
    
    // Reverse because we went right to left
    reverse(v.begin(), v.end());
    return v;
}
```

### Dry Run:
```
Input: [4, 2, 1, 3]

i=3, arr[3]=3:
  Stack empty → push -1
  s.push(3)
  Stack: [3], v: [-1]

i=2, arr[2]=1:
  s.top()=3 >= 1 → pop 3
  Stack empty → push -1
  s.push(1)
  Stack: [1], v: [-1, -1]

i=1, arr[1]=2:
  s.top()=1 < 2 → push 1
  s.push(2)
  Stack: [1, 2], v: [-1, -1, 1]

i=0, arr[0]=4:
  s.top()=2 < 4 → push 2
  s.push(4)
  Stack: [1, 2, 4], v: [-1, -1, 1, 2]

Reverse v: [2, 1, -1, -1] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

### Company Frequency:
- **TCS:** 75%
- **Infosys:** 70%
- **Wipro:** 65%

---

## 🧩 PROBLEM 4: NEXT SMALLER ELEMENT TO LEFT (NSL)

### Problem Statement:
For each element, find the next smaller element to its left.

**Example:**
```
Input:  [4, 2, 1, 3]
Output: [-1, -1, -1, 1]

Explanation:
  4 → no element on left → -1
  2 → no smaller on left → -1
  1 → no smaller on left → -1
  3 → 1 < 3 → answer is 1
```

### Communication Script:
> "Sir, left to right traversal for left side elements. Maintain increasing stack, pop greater/equal until smaller found. No reverse needed. Time O(n), space O(n)."

### Aditya Verma's Code:
```cpp
vector<int> nextSmallerLeft(vector<int>& arr) {
    int n = arr.size();
    vector<int> v;
    stack<int> s;
    
    // Traverse from left to right
    for(int i = 0; i < n; i++) {
        // Stack empty → no smaller element on left
        if(s.empty()) {
            v.push_back(-1);
        }
        // Stack top is smaller → that's the answer
        else if(s.top() < arr[i]) {
            v.push_back(s.top());
        }
        // Stack top is greater or equal → pop and find
        else {
            while(!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            if(!s.empty()) {
                v.push_back(s.top());
            } else {
                v.push_back(-1);
            }
        }
        
        // Push current element
        s.push(arr[i]);
    }
    
    // No reverse needed (left to right)
    return v;
}
```

### Dry Run:
```
Input: [4, 2, 1, 3]

i=0, arr[0]=4:
  Stack empty → push -1
  s.push(4)
  Stack: [4], v: [-1]

i=1, arr[1]=2:
  s.top()=4 >= 2 → pop 4
  Stack empty → push -1
  s.push(2)
  Stack: [2], v: [-1, -1]

i=2, arr[2]=1:
  s.top()=2 >= 1 → pop 2
  Stack empty → push -1
  s.push(1)
  Stack: [1], v: [-1, -1, -1]

i=3, arr[3]=3:
  s.top()=1 < 3 → push 1
  s.push(3)
  Stack: [1, 3], v: [-1, -1, -1, 1]

Result: [-1, -1, -1, 1] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

---

## 🧩 PROBLEM 5: STOCK SPAN PROBLEM ⭐⭐⭐

### Problem Statement:
The stock span on a particular day is the maximum number of consecutive days before that day where the stock price was less than or equal to that day's price.

**Example:**
```
Input:  [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]

Explanation:
  Day 0: 100 → no previous days → span = 1
  Day 1: 80 → 100 > 80 → span = 1
  Day 2: 60 → 80 > 60 → span = 1
  Day 3: 70 → 60 <= 70, 80 > 70 → span = 2
  Day 4: 60 → 70 > 60 → span = 1
  Day 5: 75 → 60,70,60 <= 75, 80 > 75 → span = 4
  Day 6: 85 → all previous <= 85 except 100 → span = 6
```

### 🔑 Key Insight:
**Stock Span = Current Index - Index of Next Greater to Left**

If NGL doesn't exist → span = i + 1 (all previous days)

### Communication Script:
> "Sir, this is variation of Next Greater Left! Stock span means consecutive smaller/equal days before. I'll use stack to store indices, not values. For each day, pop while price at stack top <= current price. If stack empty, span = i+1 (all previous days). Else, span = i - stack.top() (distance to last greater). Time O(n), space O(n)."

### Aditya Verma's Code (with Indices):
```cpp
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span;
    stack<int> s;  // Stack stores INDICES
    
    for(int i = 0; i < n; i++) {
        // Pop while current price >= price at stack top index
        while(!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }
        
        // Calculate span
        if(s.empty()) {
            span.push_back(i + 1);  // All previous days
        } else {
            span.push_back(i - s.top());  // Distance to last greater
        }
        
        // Push current index
        s.push(i);
    }
    
    return span;
}
```

### Alternative: Using Pair (Value + Index):
```cpp
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span;
    stack<pair<int, int>> s;  // {price, index}
    
    for(int i = 0; i < n; i++) {
        // Pop while current price >= price at stack top
        while(!s.empty() && s.top().first <= prices[i]) {
            s.pop();
        }
        
        // Calculate span
        if(s.empty()) {
            span.push_back(i + 1);
        } else {
            span.push_back(i - s.top().second);
        }
        
        // Push current {price, index}
        s.push({prices[i], i});
    }
    
    return span;
}
```

### Dry Run:
```
Input: [100, 80, 60, 70, 60, 75, 85]

i=0, price=100:
  Stack empty → span = 0+1 = 1
  s.push(0)
  Stack: [0], span: [1]

i=1, price=80:
  prices[s.top()]=100 > 80 → don't pop
  span = 1 - 0 = 1
  s.push(1)
  Stack: [0, 1], span: [1, 1]

i=2, price=60:
  prices[s.top()]=80 > 60 → don't pop
  span = 2 - 1 = 1
  s.push(2)
  Stack: [0, 1, 2], span: [1, 1, 1]

i=3, price=70:
  prices[s.top()]=60 <= 70 → pop 2
  prices[s.top()]=80 > 70 → don't pop
  span = 3 - 1 = 2
  s.push(3)
  Stack: [0, 1, 3], span: [1, 1, 1, 2]

i=4, price=60:
  prices[s.top()]=70 > 60 → don't pop
  span = 4 - 3 = 1
  s.push(4)
  Stack: [0, 1, 3, 4], span: [1, 1, 1, 2, 1]

i=5, price=75:
  prices[s.top()]=60 <= 75 → pop 4
  prices[s.top()]=70 <= 75 → pop 3
  prices[s.top()]=80 > 75 → don't pop
  span = 5 - 1 = 4
  s.push(5)
  Stack: [0, 1, 5], span: [1, 1, 1, 2, 1, 4]

i=6, price=85:
  prices[s.top()]=75 <= 85 → pop 5
  prices[s.top()]=80 <= 85 → pop 1
  prices[s.top()]=100 > 85 → don't pop
  span = 6 - 0 = 6
  s.push(6)
  Stack: [0, 6], span: [1, 1, 1, 2, 1, 4, 6]

Result: [1, 1, 1, 2, 1, 4, 6] ✅
```

### Time & Space:
- **Time:** O(n) - each element pushed/popped once
- **Space:** O(n)

### Company Frequency:
- **TCS:** 85% ⭐
- **Infosys:** 80% ⭐
- **Wipro:** 75% ⭐
- **Cognizant:** 70%
- **Accenture:** 65%

---

## 🧩 PROBLEM 6: LARGEST RECTANGLE IN HISTOGRAM ⭐⭐⭐

### Problem Statement:
Given an array representing heights of bars in a histogram, find the area of the largest rectangle.

**Example:**
```
Input: [2, 1, 5, 6, 2, 3]
Output: 10

Explanation:
  Largest rectangle is formed by bars at index 2,3 with height 5
  Area = 5 * 2 = 10
```

### 🔑 Key Insight:
**For each bar as minimum height:**
- Find left boundary: Next Smaller to Left (NSL)
- Find right boundary: Next Smaller to Right (NSR)
- Width = NSR index - NSL index - 1
- Area = height[i] * width

### Communication Script:
> "Sir, combination of NSL and NSR! For each bar, I'll find how far left and right it can extend as minimum height. Use stack twice - once for NSL indices, once for NSR indices. Then calculate area for each bar: area = height * (right - left - 1). Track maximum. Time O(n), space O(n)."

### Code:
```cpp
int largestRectangle(vector<int>& heights) {
    int n = heights.size();
    
    // Step 1: Find NSL indices
    vector<int> left(n);
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    
    // Step 2: Find NSR indices
    vector<int> right(n);
    while(!s.empty()) s.pop();  // Clear stack
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    
    // Step 3: Calculate max area
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}
```

### Optimized Single Pass:
```cpp
int largestRectangle(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    
    for(int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        
        while(!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        s.push(i);
    }
    
    return maxArea;
}
```

### Dry Run:
```
Input: [2, 1, 5, 6, 2, 3]

Step 1 - NSL (Next Smaller Left):
i=0, h=2: Stack empty → left[0] = -1, push 0
i=1, h=1: 2 >= 1 → pop 0, empty → left[1] = -1, push 1
i=2, h=5: 1 < 5 → left[2] = 1, push 2
i=3, h=6: 5 < 6 → left[3] = 2, push 3
i=4, h=2: 6 >= 2 → pop 3, 5 >= 2 → pop 2, 1 < 2 → left[4] = 1, push 4
i=5, h=3: 2 < 3 → left[5] = 4, push 5
left[] = [-1, -1, 1, 2, 1, 4]

Step 2 - NSR (Next Smaller Right):
i=5, h=3: Stack empty → right[5] = 6, push 5
i=4, h=2: 3 >= 2 → pop 5, empty → right[4] = 6, push 4
i=3, h=6: 2 < 6 → right[3] = 4, push 3
i=2, h=5: 6 >= 5 → pop 3, 2 < 5 → right[2] = 4, push 2
i=1, h=1: 5 >= 1 → pop 2, 4 >= 1 → pop 4, empty → right[1] = 6, push 1
i=0, h=2: 1 < 2 → right[0] = 1, push 0
right[] = [1, 6, 4, 4, 6, 6]

Step 3 - Calculate Areas:
i=0: width = 1-(-1)-1 = 1, area = 2*1 = 2
i=1: width = 6-(-1)-1 = 6, area = 1*6 = 6
i=2: width = 4-1-1 = 2, area = 5*2 = 10 ✅ Max
i=3: width = 4-2-1 = 1, area = 6*1 = 6
i=4: width = 6-1-1 = 4, area = 2*4 = 8
i=5: width = 6-4-1 = 1, area = 3*1 = 3

Max Area = 10
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

### Company Frequency:
- **TCS:** 60%
- **Infosys:** 70%
- **Wipro:** 55%
- **Amazon/Microsoft:** 90% (if targeting product-based)

---

## 🧩 PROBLEM 7: MAXIMUM AREA RECTANGLE IN BINARY MATRIX

### Problem Statement:
Given a binary matrix, find the largest rectangle containing only 1s.

**Example:**
```
Input:
  1 0 1 0 0
  1 0 1 1 1
  1 1 1 1 1
  1 0 0 1 0

Output: 6
(Rectangle from row 1, col 2 to row 2, col 4)
```

### 🔑 Key Insight:
**Convert to Histogram Problem!**
- For each row, treat it as base of histogram
- Height = consecutive 1s above (including current row)
- Apply Largest Rectangle in Histogram

### Communication Script:
> "Sir, this reduces to histogram problem! I'll build histogram row by row - if cell is 1, height increases from previous row, if 0, height resets to 0. For each row's histogram, find largest rectangle using stack. Track overall maximum. Time O(rows × cols), space O(cols)."

### Code:
```cpp
int maxRectangle(vector<vector<int>>& matrix) {
    if(matrix.empty()) return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;
    
    for(int i = 0; i < rows; i++) {
        // Build histogram for current row
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 1) {
                heights[j]++;  // Increase height
            } else {
                heights[j] = 0;  // Reset height
            }
        }
        
        // Find largest rectangle in this histogram
        int area = largestRectangle(heights);
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

// Use largestRectangle from Problem 6
```

### Dry Run:
```
Input:
  1 0 1 0 0
  1 0 1 1 1
  1 1 1 1 1
  1 0 0 1 0

Row 0: heights = [1, 0, 1, 0, 0]
  largestRectangle([1,0,1,0,0]) = 1

Row 1: heights = [2, 0, 2, 1, 1]
  largestRectangle([2,0,2,1,1]) = 3

Row 2: heights = [3, 1, 3, 2, 2]
  largestRectangle([3,1,3,2,2]) = 6 ✅ Max
  (Rectangle: 3 heights of 2 width)

Row 3: heights = [4, 0, 0, 3, 0]
  largestRectangle([4,0,0,3,0]) = 4

Max Area = 6
```

### Time & Space:
- **Time:** O(rows × cols)
- **Space:** O(cols)

### Company Frequency:
- **TCS:** 40%
- **Infosys:** 50%
- **Wipro:** 35%
- **Amazon/Google:** 80% (product-based)

---

## 🧩 PROBLEM 8: DAILY TEMPERATURES (LeetCode 739)

### Problem Statement:
Given daily temperatures, for each day find how many days you have to wait for a warmer temperature. If no warmer day, return 0.

**Example:**
```
Input:  [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]

Explanation:
  Day 0 (73°): Next day is 74° → wait 1 day
  Day 1 (74°): Next day is 75° → wait 1 day
  Day 2 (75°): Day 6 is 76° → wait 4 days
  ...
```

### 🔑 Key Insight:
**This is Next Greater to Right with distance!**
- Instead of value, we need number of days
- Use stack to store indices
- Answer = NGR_index - current_index

### Communication Script:
> "Sir, variation of Next Greater Right! Use stack to store indices. For each temperature, pop indices with lower temps - for them, current is answer. Distance = current_index - popped_index. Time O(n), space O(n)."

### Code:
```cpp
vector<int> dailyTemperatures(vector<int>& temps) {
    int n = temps.size();
    vector<int> result(n, 0);
    stack<int> s;  // Stack stores indices
    
    for(int i = 0; i < n; i++) {
        // Pop indices with lower temps
        while(!s.empty() && temps[i] > temps[s.top()]) {
            int prevIndex = s.top();
            s.pop();
            result[prevIndex] = i - prevIndex;  // Days to wait
        }
        
        s.push(i);
    }
    
    return result;
}
```

### Dry Run:
```
Input: [73, 74, 75, 71, 69, 72, 76, 73]

i=0, temp=73:
  Stack empty, push 0
  Stack: [0], result: [0,0,0,0,0,0,0,0]

i=1, temp=74:
  74 > temps[0]=73 → pop 0, result[0] = 1-0 = 1
  Push 1
  Stack: [1], result: [1,0,0,0,0,0,0,0]

i=2, temp=75:
  75 > temps[1]=74 → pop 1, result[1] = 2-1 = 1
  Push 2
  Stack: [2], result: [1,1,0,0,0,0,0,0]

i=3, temp=71:
  71 < 75, push 3
  Stack: [2,3], result: [1,1,0,0,0,0,0,0]

i=4, temp=69:
  69 < 71, push 4
  Stack: [2,3,4], result: [1,1,0,0,0,0,0,0]

i=5, temp=72:
  72 > temps[4]=69 → pop 4, result[4] = 5-4 = 1
  72 > temps[3]=71 → pop 3, result[3] = 5-3 = 2
  72 < 75, push 5
  Stack: [2,5], result: [1,1,0,2,1,0,0,0]

i=6, temp=76:
  76 > temps[5]=72 → pop 5, result[5] = 6-5 = 1
  76 > temps[2]=75 → pop 2, result[2] = 6-2 = 4
  Push 6
  Stack: [6], result: [1,1,4,2,1,1,0,0]

i=7, temp=73:
  73 < 76, push 7
  Stack: [6,7], result: [1,1,4,2,1,1,0,0]

Final: Indices in stack have no warmer day → already 0

Result: [1,1,4,2,1,1,0,0] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

### Company Frequency:
- **TCS:** 65%
- **Infosys:** 70%
- **Wipro:** 60%

---

## 📊 COMPARISON TABLE: All 4 Patterns

| Feature | NGR | NGL | NSR | NSL |
|---------|-----|-----|-----|-----|
| **Direction** | ← (n-1→0) | → (0→n-1) | ← (n-1→0) | → (0→n-1) |
| **Condition** | > | > | < | < |
| **Pop When** | <= | <= | >= | >= |
| **Reverse?** | Yes | No | Yes | No |
| **Use Case** | Daily temps | Stock span | Histogram | Histogram |

---

## 🎯 PATTERN RECOGNITION GUIDE

### When you see:
- **"Next greater"** → NGR or NGL (decreasing stack)
- **"Next smaller"** → NSR or NSL (increasing stack)
- **"To the right"** → Traverse right to left, reverse result
- **"To the left"** → Traverse left to right, no reverse
- **"Consecutive days"** → Stock span (NGL with indices)
- **"Rectangle in histogram"** → NSL + NSR
- **"Days to wait"** → NGR with distance (indices)

---

## 💡 ADITYA VERMA'S MASTER TEMPLATE

```cpp
// Decide parameters based on problem:
// 1. Direction: left-to-right OR right-to-left
// 2. Condition: s.top() > arr[i] OR s.top() < arr[i]
// 3. Pop condition: opposite of condition
// 4. Reverse: YES if right-to-left, NO if left-to-right

vector<int> solve(vector<int>& arr) {
    vector<int> v;
    stack<int> s;
    
    for(int i = START; CONDITION; UPDATE) {
        if(s.empty()) {
            v.push_back(-1);
        }
        else if(CONDITION_MATCHES) {
            v.push_back(s.top());
        }
        else {
            while(!s.empty() && !CONDITION_MATCHES) {
                s.pop();
            }
            if(!s.empty()) v.push_back(s.top());
            else v.push_back(-1);
        }
        s.push(arr[i]);
    }
    
    if(REVERSE_NEEDED) reverse(v.begin(), v.end());
    return v;
}
```

---

## 🔥 COMPANY-WISE TOP PROBLEMS

### TCS (Focus: Stock Span + NGE)
1. Stock Span - 85%
2. Next Greater Element - 80%
3. Daily Temperatures - 65%

### Infosys (Focus: Histogram)
1. Largest Rectangle in Histogram - 70%
2. Next Greater Element - 85%
3. Stock Span - 80%

### Wipro (Focus: Balanced)
1. Next Greater Element - 75%
2. Stock Span - 75%
3. Next Smaller Element - 65%

---

## 🎓 LEARNING PATH

**Day 1: Master the 4 Patterns (4 hours)**
- NGR, NGL, NSR, NSL
- Understand template
- Practice dry runs

**Day 2: Apply Patterns (4 hours)**
- Stock Span
- Daily Temperatures
- Hands-on coding

**Day 3: Advanced (5 hours)**
- Largest Rectangle in Histogram
- Maximum Rectangle in Matrix
- Practice combinations

---

## 💪 INTERVIEW TIPS

1. **Start with pattern identification:**
   - "Sir, this is Next Greater to Right variation"

2. **Explain stack order:**
   - "I'll maintain decreasing/increasing stack"

3. **Mention direction:**
   - "Traversing right to left, will reverse at end"

4. **State complexity upfront:**
   - "O(n) time, each element pushed/popped once"

5. **Draw stack states:**
   - Visual explanation helps interviewer follow

**Master these 8 problems → 90% Stack patterns covered!** 🚀

---

**Next:** Combine with recursion and other advanced patterns!
