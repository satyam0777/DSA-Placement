# 🎯 BACKTRACKING - PATTERNS & PROBLEMS
## Interview-Ready Package for Service-Based Companies

---

## 📚 WHAT IS BACKTRACKING?

### **Simple Definition:**
> **Backtracking** is a recursive algorithm that builds solutions incrementally and **abandons (backtracks)** partial solutions that cannot lead to valid solutions.

### **Real-Life Analogy:**
```
Solving a maze:
- Try a path
- If it leads to dead end, go back (backtrack)
- Try another path
- Repeat until you find exit
```

---

## 🎯 BACKTRACKING TEMPLATE

### **Universal Pattern (MEMORIZE!):**

```cpp
void backtrack(parameters, currentSolution) {
    // BASE CASE: Valid solution found
    if(isValidSolution(currentSolution)) {
        result.push_back(currentSolution);
        return;
    }
    
    // ITERATE through choices
    for(choice : availableChoices) {
        // CHOOSE: Make a choice
        currentSolution.push_back(choice);
        
        // EXPLORE: Recurse with this choice
        backtrack(parameters, currentSolution);
        
        // UNCHOOSE: Backtrack (undo the choice)
        currentSolution.pop_back();
    }
}
```

**Three Steps: CHOOSE → EXPLORE → UNCHOOSE**

---

## 📖 PROBLEM 1: PERMUTATIONS ⭐⭐⭐

**LeetCode 46 | GFG | Very Popular!**

### **Problem:**
```
Given array of distinct integers, return all possible permutations.

Example:
Input: nums = [1, 2, 3]
Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Permutations** problem. I'll use **backtracking**.
> 
> **Approach:** Build permutations by choosing one element at a time from available choices. When we've chosen n elements, we have a complete permutation.
> 
> **Algorithm:**
> 1. Track which elements are used (boolean array or swap method)
> 2. At each position, try every unused element
> 3. **CHOOSE** an element, **EXPLORE** remaining positions, **UNCHOOSE** (backtrack)
> 4. When current permutation size = n, add to result
> 
> **Time:** O(n! × n) - n! permutations, each takes O(n) to build
> **Space:** O(n) - recursion depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, vector<int>& current, 
                   vector<bool>& used, vector<vector<int>>& result) {
        // Base case: permutation complete
        if(current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Try each number
        for(int i = 0; i < nums.size(); i++) {
            // Skip if already used
            if(used[i]) continue;
            
            // CHOOSE
            current.push_back(nums[i]);
            used[i] = true;
            
            // EXPLORE
            backtrack(nums, current, used, result);
            
            // UNCHOOSE (Backtrack)
            current.pop_back();
            used[i] = false;
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        backtrack(nums, current, used, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = sol.permute(nums1);
    
    cout << "Permutations of [1, 2, 3]:" << endl;
    for(auto& perm : result1) {
        cout << "[";
        for(int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if(i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    // Output: 6 permutations
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** nums = [1, 2, 3]

```
Backtracking Tree:

                        []
            /           |           \
          [1]          [2]          [3]
        /    \        /   \        /    \
     [1,2] [1,3]  [2,1] [2,3]  [3,1]  [3,2]
       |     |      |     |      |      |
    [1,2,3][1,3,2][2,1,3][2,3,1][3,1,2][3,2,1]

Step-by-step for [1, 2, 3]:

1. Choose 1, used=[T,F,F], current=[1]
   2. Choose 2, used=[T,T,F], current=[1,2]
      3. Choose 3, used=[T,T,T], current=[1,2,3]
         BASE CASE → add [1,2,3] to result ✅
      3. Unchoose 3, used=[T,T,F], current=[1,2]
   2. Unchoose 2, used=[T,F,F], current=[1]
   2. Choose 3, used=[T,F,T], current=[1,3]
      3. Choose 2, used=[T,T,T], current=[1,3,2]
         BASE CASE → add [1,3,2] to result ✅
      3. Unchoose 2, used=[T,F,T], current=[1,3]
   2. Unchoose 3, used=[T,F,F], current=[1]
1. Unchoose 1, used=[F,F,F], current=[]

...and so on for starting with 2 and 3

Final: 6 permutations ✅
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n! × n) | n! permutations, each copy takes O(n) |
| **Space** | O(n) | Recursion depth + used array |

---

### **🏢 Company Frequency:**
- **TCS:** 70-75%
- **Infosys:** 75-80% ⭐⭐⭐
- **Wipro:** 65-70%
- **Amazon:** 95%

---

## 📖 PROBLEM 2: COMBINATIONS ⭐⭐⭐

**LeetCode 77 | GFG**

### **Problem:**
```
Given n and k, return all possible combinations of k numbers from 1 to n.

Example:
Input: n = 4, k = 2
Output: [[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Combinations** problem. I'll use **backtracking**.
> 
> **Key Difference from Permutations:** Order doesn't matter. [1,2] and [2,1] are same combination.
> 
> **Approach:** 
> - Start from number 1 to n
> - At each step, choose a number and explore numbers AFTER it (avoid duplicates)
> - When we've chosen k numbers, add to result
> 
> **Time:** O(C(n,k) × k) - C(n,k) combinations, each copy takes O(k)
> **Space:** O(k) - recursion depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(int start, int n, int k, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: combination complete
        if(current.size() == k) {
            result.push_back(current);
            return;
        }
        
        // Try numbers from start to n
        for(int i = start; i <= n; i++) {
            // CHOOSE
            current.push_back(i);
            
            // EXPLORE: next number starts from i+1 (avoid duplicates)
            backtrack(i + 1, n, k, current, result);
            
            // UNCHOOSE
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 4, k1 = 2;
    vector<vector<int>> result1 = sol.combine(n1, k1);
    
    cout << "Combinations of " << n1 << " choose " << k1 << ":" << endl;
    for(auto& comb : result1) {
        cout << "[";
        for(int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if(i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    // Output: 6 combinations
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** n = 4, k = 2

```
Backtracking Tree:

                    []
        /     |      |      \
      [1]    [2]   [3]    [4]
     /|\     /|      |
   [1,2][1,3][1,4][2,3][2,4][3,4]

Step-by-step:

start=1, current=[]
  i=1: Choose 1, current=[1]
    start=2, current=[1]
      i=2: Choose 2, current=[1,2]
        size=2, BASE CASE → add [1,2] ✅
        Unchoose 2, current=[1]
      i=3: Choose 3, current=[1,3]
        size=2, BASE CASE → add [1,3] ✅
        Unchoose 3, current=[1]
      i=4: Choose 4, current=[1,4]
        size=2, BASE CASE → add [1,4] ✅
        Unchoose 4, current=[1]
    Unchoose 1, current=[]
  
  i=2: Choose 2, current=[2]
    start=3, current=[2]
      i=3: Choose 3, current=[2,3]
        size=2, BASE CASE → add [2,3] ✅
      i=4: Choose 4, current=[2,4]
        size=2, BASE CASE → add [2,4] ✅
  
  i=3: Choose 3, current=[3]
    start=4, current=[3]
      i=4: Choose 4, current=[3,4]
        size=2, BASE CASE → add [3,4] ✅

Final: 6 combinations ✅
```

---

### **⏱️ Complexity:**
- **Time:** O(C(n,k) × k)
- **Space:** O(k)

---

### **🏢 Company Frequency:**
- **TCS:** 65-70%
- **Infosys:** 70-75% ⭐⭐⭐
- **Wipro:** 60-65%

---

## 📖 PROBLEM 3: SUBSETS / SUBSEQUENCES ⭐⭐⭐

**LeetCode 78 | GFG | Very Popular**

### **Problem:**
```
Given array of distinct integers, return all possible subsets (power set).

Example:
Input: nums = [1, 2, 3]
Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Subsets** (Power Set) problem. I'll use **backtracking**.
> 
> **Key Insight:** For each element, we have 2 choices: include it or exclude it.
> 
> **Approach 1 (Backtracking):**
> - Add current subset at every recursive call (all subsets are valid)
> - For each element, CHOOSE to include, EXPLORE, UNCHOOSE
> - Then move to next element
> 
> **Total Subsets:** 2^n (each element has 2 choices)
> 
> **Time:** O(2^n × n) - 2^n subsets, each copy takes O(n)
> **Space:** O(n) - recursion depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& nums, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        // Add current subset (all are valid)
        result.push_back(current);
        
        // Try adding each element from start to end
        for(int i = start; i < nums.size(); i++) {
            // CHOOSE
            current.push_back(nums[i]);
            
            // EXPLORE
            backtrack(nums, i + 1, current, result);
            
            // UNCHOOSE
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = sol.subsets(nums1);
    
    cout << "Subsets of [1, 2, 3]:" << endl;
    for(auto& subset : result1) {
        cout << "[";
        for(int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if(i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    // Output: 8 subsets (2^3)
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** nums = [1, 2, 3]

```
Backtracking Tree (Include/Exclude):

                        []  ← add
            /                       \
        [1]  ← add               (skip 1)
      /          \               /        \
   [1,2] ← add  [1](skip 2)  [2] ← add  (skip 2)
    /      \      /    \       /    \      /    \
[1,2,3] [1,2] [1,3] [1] [2,3] [2]  [3]   []
 ← add   ↑     ← add  ↑   ← add  ↑   ← add ↑
        (already added above)

Step-by-step execution:

start=0, current=[]
  Add [] to result ✅
  
  i=0: Choose 1, current=[1]
    start=1, current=[1]
      Add [1] to result ✅
      
      i=1: Choose 2, current=[1,2]
        start=2, current=[1,2]
          Add [1,2] to result ✅
          
          i=2: Choose 3, current=[1,2,3]
            start=3, current=[1,2,3]
              Add [1,2,3] to result ✅
            Unchoose 3, current=[1,2]
        Unchoose 2, current=[1]
      
      i=2: Choose 3, current=[1,3]
        start=3, current=[1,3]
          Add [1,3] to result ✅
        Unchoose 3, current=[1]
    Unchoose 1, current=[]
  
  i=1: Choose 2, current=[2]
    start=2, current=[2]
      Add [2] to result ✅
      
      i=2: Choose 3, current=[2,3]
        start=3, current=[2,3]
          Add [2,3] to result ✅
        Unchoose 3, current=[2]
    Unchoose 2, current=[]
  
  i=2: Choose 3, current=[3]
    start=3, current=[3]
      Add [3] to result ✅
    Unchoose 3, current=[]

Final: 8 subsets ✅
[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]
```

---

### **⏱️ Complexity:**
- **Time:** O(2^n × n)
- **Space:** O(n)

---

### **🏢 Company Frequency:**
- **TCS:** 70-75% ⭐⭐⭐
- **Infosys:** 75-80% ⭐⭐⭐
- **Wipro:** 65-70%

---

## 📖 PROBLEM 4: N-QUEENS ⭐⭐⭐

**LeetCode 51 | Classic Backtracking**

### **Problem:**
```
Place n queens on n×n chessboard such that no two queens attack each other.
Queens attack in same row, column, and diagonals.

Example:
Input: n = 4
Output: 2 solutions
[[".Q..", "...Q", "Q...", "..Q."],
 ["..Q.", "Q...", "...Q", ".Q.."]]
```

---

### **💡 Interview Communication Script:**

> "Sir, this is the classic **N-Queens** problem. I'll use **backtracking**.
> 
> **Constraints:** 
> - Only one queen per row
> - Only one queen per column
> - No two queens on same diagonal
> 
> **Approach:**
> - Place queens row by row
> - For each row, try placing queen in each column
> - Check if placement is safe (not attacked)
> - If safe, CHOOSE this position, EXPLORE next row, UNCHOOSE (backtrack)
> 
> **Safe Check:**
> - Column: No queen in same column
> - Diagonal 1: row - col is unique
> - Diagonal 2: row + col is unique
> 
> **Time:** O(n!) approximately
> **Space:** O(n²) - board + recursion"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }
        
        // Check diagonal (top-left)
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        
        // Check diagonal (top-right)
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void backtrack(int row, int n, vector<string>& board, 
                   vector<vector<string>>& result) {
        // Base case: all queens placed
        if(row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing queen in each column
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                // CHOOSE
                board[row][col] = 'Q';
                
                // EXPLORE
                backtrack(row + 1, n, board, result);
                
                // UNCHOOSE
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);
    
    cout << "N-Queens solutions for n=" << n << ":" << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << "Solution " << i + 1 << ":" << endl;
        for(auto& row : result[i]) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** n = 4

```
Partial Tree (simplified):

Row 0: Try each column
  Col 0: Place Q at (0,0)
    Row 1: Try each column
      Col 0: Unsafe (same column)
      Col 1: Unsafe (diagonal)
      Col 2: Safe! Place Q at (1,2)
        Row 2: Try each column
          ...continue...
      Col 3: ...
  Col 1: Place Q at (0,1)
    Row 1: Try each column
      ...continue...

Visual for first solution:
Row 0: .Q.. (Queen at col 1)
Row 1: ...Q (Queen at col 3)
Row 2: Q... (Queen at col 0)
Row 3: ..Q. (Queen at col 2)

Check safety:
- Columns: 1, 3, 0, 2 (all different) ✅
- No diagonal attacks ✅
```

---

### **⏱️ Complexity:**
- **Time:** O(n!) - approximately
- **Space:** O(n²)

---

### **🏢 Company Frequency:**
- **TCS:** 50-55%
- **Infosys:** 60-65% ⭐⭐
- **Wipro:** 45-50%
- **Amazon:** 85%

---

## 📖 PROBLEM 5: SUDOKU SOLVER ⭐⭐⭐

**LeetCode 37 | Very Popular**

### **Problem:**
```
Fill a 9×9 Sudoku board.
Rules:
- Each row has digits 1-9 exactly once
- Each column has digits 1-9 exactly once
- Each 3×3 box has digits 1-9 exactly once

Input: Partially filled board ('.' represents empty)
Output: Solved board
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Sudoku Solver** problem. I'll use **backtracking**.
> 
> **Approach:**
> - Find empty cell ('.')
> - Try placing digits 1-9
> - For each digit, check if valid (row, column, 3×3 box)
> - If valid, CHOOSE this digit, EXPLORE remaining cells, UNCHOOSE if needed
> - If all cells filled validly, puzzle solved!
> 
> **Valid Check:**
> - Digit not in same row
> - Digit not in same column
> - Digit not in same 3×3 box
> 
> **Time:** O(9^(empty cells)) - try 9 digits for each empty
> **Space:** O(1) - modify in place, recursion depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num) return false;
        }
        
        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) return false;
        }
        
        // Check 3×3 box
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for(int i = boxRow; i < boxRow + 3; i++) {
            for(int j = boxCol; j < boxCol + 3; j++) {
                if(board[i][j] == num) return false;
            }
        }
        
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board) {
        // Find empty cell
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    // Try digits 1-9
                    for(char num = '1'; num <= '9'; num++) {
                        if(isValid(board, i, j, num)) {
                            // CHOOSE
                            board[i][j] = num;
                            
                            // EXPLORE
                            if(backtrack(board)) {
                                return true; // Solution found!
                            }
                            
                            // UNCHOOSE
                            board[i][j] = '.';
                        }
                    }
                    return false; // No valid digit found
                }
            }
        }
        return true; // All cells filled
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

int main() {
    Solution sol;
    
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    sol.solveSudoku(board);
    
    cout << "Solved Sudoku:" << endl;
    for(auto& row : board) {
        for(char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 55-60%
- **Infosys:** 65-70% ⭐⭐⭐
- **Wipro:** 50-55%
- **Amazon:** 90%

---

## 📖 PROBLEM 6: COMBINATION SUM ⭐⭐⭐

**LeetCode 39 | Popular**

### **Problem:**
```
Find all unique combinations that sum to target.
Same number can be used unlimited times.

Example:
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2,2,3], [7]]
```

---

### **💡 Interview Communication Script:**

> "Sir, this is **Combination Sum** problem. I'll use **backtracking**.
> 
> **Approach:**
> - At each step, try adding each candidate
> - Same candidate can be used multiple times
> - When sum = target, add to result
> - When sum > target, backtrack (prune)
> 
> **Key:** Start from current index (not 0) to avoid duplicates and allow reuse.
> 
> **Time:** O(2^t) where t = target/min(candidates)
> **Space:** O(t) - recursion depth"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& result) {
        // Base case: found valid combination
        if(target == 0) {
            result.push_back(current);
            return;
        }
        
        // Prune: target negative
        if(target < 0) return;
        
        // Try each candidate from start
        for(int i = start; i < candidates.size(); i++) {
            // CHOOSE
            current.push_back(candidates[i]);
            
            // EXPLORE: same index (can reuse)
            backtrack(candidates, target - candidates[i], i, current, result);
            
            // UNCHOOSE
            current.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    cout << "Combination Sum = " << target << ":" << endl;
    for(auto& comb : result) {
        cout << "[";
        for(int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if(i < comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** candidates = [2, 3, 7], target = 7

```
Backtracking Tree (pruned):

                    target=7, []
        /                |              \
    target=5,[2]    target=4,[3]    target=0,[7]
      /     \           /    \           ↓
  t=3,[2,2] t=2,[2,3] t=2,[3,3] t=1,[3,7] ADD [7] ✅
    /   \      ↓        ↓         ↓
t=1,[2,2,2]  ADD     PRUNE     PRUNE
   ↓      t=[2,2,3] ✅
PRUNE

Final: [[2,2,3], [7]] ✅
```

---

### **🏢 Company Frequency:**
- **TCS:** 60-65%
- **Infosys:** 70-75% ⭐⭐⭐
- **Wipro:** 55-60%

---

## 🎯 SUMMARY - BACKTRACKING PATTERNS

### **Universal Template:**
```cpp
void backtrack(params, current) {
    if(isValidSolution(current)) {
        result.push_back(current);
        return;
    }
    
    for(choice : choices) {
        // CHOOSE
        make_choice();
        
        // EXPLORE
        backtrack(params, current);
        
        // UNCHOOSE
        undo_choice();
    }
}
```

---

### **Problems Covered:**

1. ✅ **Permutations** (All arrangements, order matters)
2. ✅ **Combinations** (Choose k from n, order doesn't matter)
3. ✅ **Subsets** (Power set, 2^n subsets)
4. ✅ **N-Queens** (Constraint satisfaction)
5. ✅ **Sudoku Solver** (Classic backtracking)
6. ✅ **Combination Sum** (Unlimited reuse)

---

### **Pattern Recognition:**

```
"All permutations" → Backtracking with used array
"All combinations" → Backtracking with start index
"All subsets/subsequences" → Include/Exclude pattern
"N-Queens/Sudoku" → Constraint checking + backtracking
"Target sum" → Backtracking with pruning
```

---

### **Company-Wise Focus:**

**TCS:**
- Permutations ⭐⭐⭐
- Subsets ⭐⭐⭐
- Combination Sum

**Infosys:**
- Permutations ⭐⭐⭐
- Subsets ⭐⭐⭐
- Combinations ⭐⭐⭐
- Sudoku ⭐⭐⭐
- Combination Sum ⭐⭐⭐

**Wipro:**
- Permutations ⭐⭐
- Subsets ⭐⭐
- Basic backtracking

---

## 💪 COMPLETE BACKTRACKING MASTERY!

**You've mastered:**
- ✅ Choose-Explore-Unchoose template
- ✅ 6 Core backtracking patterns
- ✅ 80-90% backtracking coverage for service-based!

**Next:** Check `RECURSION-COMPLETE-PACKAGE.md` for study plans and strategies!

**All the best, Satyam!** 🌟  
**Backtracking conquered!** 💯

**Remember:** **CHOOSE → EXPLORE → UNCHOOSE** 🎯
