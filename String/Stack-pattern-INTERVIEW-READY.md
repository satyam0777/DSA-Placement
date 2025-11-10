#  STACK - STRING PROBLEMS

**Pattern Recognition:** When you see "**remove adjacent**", "**valid parentheses**", "**decode**", "**next greater**" - Think STACK!

---

##  CORE CONCEPT

**Stack = Last In First Out (LIFO)**

**Perfect for:**
- Matching pairs (parentheses, duplicates)
- Reversing operations
- Processing nested structures

**Template:**
```cpp
stack<char> st;

for(char c : s) {
    if(/* matching condition with st.top() */) {
        st.pop();  // Remove match
    } else {
        st.push(c);  // Add to stack
    }
}
```

---

##  PROBLEM 1: REMOVE ALL ADJACENT DUPLICATES
**⭐⭐⭐⭐⭐ MOST ASKED!**

**Problem:**
Remove all adjacent duplicate characters repeatedly.

**Example:**
```
Input: s = "abbaca"
Output: "ca"
Explanation: "bb" removed → "aaca" → "aa" removed → "ca"
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    
    for(char c : s) {
        if(!st.empty() && st.top() == c) {
            st.pop();  // Remove duplicate
        } else {
            st.push(c);  // Add to stack
        }
    }
    
    // Build result from stack
    string result = "";
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    cout << "After removing duplicates: " << removeDuplicates(s) << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "abbaca"

Step 1: c = 'a'
  Stack: ['a']
  
Step 2: c = 'b'
  Stack: ['a', 'b']
  
Step 3: c = 'b'
  Top = 'b', same as current!
  Pop 'b'
  Stack: ['a']
  
Step 4: c = 'a'
  Top = 'a', same as current!
  Pop 'a'
  Stack: []
  
Step 5: c = 'c'
  Stack: ['c']
  
Step 6: c = 'a'
  Stack: ['c', 'a']
  
Reverse: "ca"
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this is stack pattern for matching adjacent elements. I'll iterate through string, if current character matches stack top, I'll pop (remove the pair). Otherwise push current character. Finally reverse to get correct order."
>
> **Time Complexity:** "Sir, O(n) - single pass through string"
>
> **Space Complexity:** "Sir, O(n) for stack in worst case"

---

## 🎯 PROBLEM 2: VALID PARENTHESES
**⭐⭐⭐⭐⭐ CLASSIC STACK PROBLEM!**

**Problem:**
Check if string has valid parentheses: (), {}, []

**Example:**
```
Input: s = "{[()]}"
Output: true

Input: s = "{[(])}"
Output: false
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    
    for(char c : s) {
        // Opening brackets - push
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // Closing brackets - check match
        else {
            if(st.empty()) return false;
            
            char top = st.top();
            
            if((c == ')' && top == '(') ||
               (c == '}' && top == '{') ||
               (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    
    return st.empty();  // All matched
}

int main() {
    string s;
    cout << "Enter string with parentheses: ";
    cin >> s;
    
    if(isValid(s)) {
        cout << "Valid parentheses!" << endl;
    } else {
        cout << "Invalid parentheses!" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "{[()]}"

Step 1: c = '{'
  Opening bracket
  Stack: ['{']
  
Step 2: c = '['
  Opening bracket
  Stack: ['{', '[']
  
Step 3: c = '('
  Opening bracket
  Stack: ['{', '[', '(']
  
Step 4: c = ')'
  Closing bracket
  Top = '(' → Match! Pop
  Stack: ['{', '[']
  
Step 5: c = ']'
  Closing bracket
  Top = '[' → Match! Pop
  Stack: ['{']
  
Step 6: c = '}'
  Closing bracket
  Top = '{' → Match! Pop
  Stack: []
  
Stack empty → Valid!
```

### 💬 COMMUNICATION SCRIPT
> "Sir, classic stack problem for bracket matching. For opening brackets, I push to stack. For closing brackets, I check if they match with stack top. If match, pop; if not, return false. Finally check if stack is empty - all brackets matched."
>
> **Time:** O(n), **Space:** O(n)

---

## 🎯 PROBLEM 3: REMOVE K ADJACENT DUPLICATES
**⭐⭐⭐⭐**

**Problem:**
Remove K consecutive equal characters repeatedly.

**Example:**
```
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: "eee" removed → "deedbbcccbdaa"
             "ccc" removed → "deedbbdaa"
             "ddd" removed (spanning) → "ebaa"
             "bb" not 3, so stays
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;  // {character, count}
    
    for(char c : s) {
        if(!st.empty() && st.top().first == c) {
            // Same character, increment count
            st.top().second++;
            
            // If count reaches k, remove
            if(st.top().second == k) {
                st.pop();
            }
        } else {
            // New character
            st.push({c, 1});
        }
    }
    
    // Build result
    string result = "";
    while(!st.empty()) {
        auto [ch, count] = st.top();
        st.pop();
        result.append(count, ch);  // Append ch 'count' times
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    
    cout << "After removing " << k << " duplicates: " 
         << removeDuplicates(s, k) << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "abbbaaca", k = 3

Step 1-3: a, b, b, b
  Stack: [{'a',1}, {'b',3}]
  Count of 'b' = 3 → Remove!
  Stack: [{'a',1}]
  
Step 4: a
  Stack: [{'a',2}]
  
Step 5: a
  Stack: [{'a',3}]
  Count = 3 → Remove!
  Stack: []
  
Step 6-7: c, a
  Stack: [{'c',1}, {'a',1}]
  
Result: "ca"
```

### 💬 COMMUNICATION SCRIPT
> "Sir, extension of adjacent duplicates. I'll use stack of pairs - character and its count. When count reaches K, I remove that character. This handles K consecutive duplicates."
>
> **Time:** O(n), **Space:** O(n)

---

## 🎯 PROBLEM 4: DECODE STRING
**⭐⭐⭐⭐⭐**

**Problem:**
Decode encoded string. Format: k[encoded_string]

**Example:**
```
Input: s = "3[a2[c]]"
Output: "accaccacc"
Explanation: 2[c] = "cc", a2[c] = "acc", 3[acc] = "accaccacc"
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString = "";
    int k = 0;
    
    for(char c : s) {
        if(isdigit(c)) {
            // Build number (could be multi-digit)
            k = k * 10 + (c - '0');
        }
        else if(c == '[') {
            // Push current state
            countStack.push(k);
            stringStack.push(currentString);
            
            // Reset
            currentString = "";
            k = 0;
        }
        else if(c == ']') {
            // Decode
            string temp = currentString;
            currentString = stringStack.top();
            stringStack.pop();
            
            int count = countStack.top();
            countStack.pop();
            
            // Repeat temp 'count' times
            for(int i = 0; i < count; i++) {
                currentString += temp;
            }
        }
        else {
            // Regular character
            currentString += c;
        }
    }
    
    return currentString;
}

int main() {
    string s;
    cout << "Enter encoded string: ";
    cin >> s;
    
    cout << "Decoded: " << decodeString(s) << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "3[a2[c]]"

Step 1: '3'
  k = 3
  
Step 2: '['
  countStack: [3]
  stringStack: [""]
  currentString = "", k = 0
  
Step 3: 'a'
  currentString = "a"
  
Step 4: '2'
  k = 2
  
Step 5: '['
  countStack: [3, 2]
  stringStack: ["", "a"]
  currentString = "", k = 0
  
Step 6: 'c'
  currentString = "c"
  
Step 7: ']'
  Pop: count = 2, prevString = "a"
  currentString = "a" + "cc" = "acc"
  countStack: [3]
  stringStack: [""]
  
Step 8: ']'
  Pop: count = 3, prevString = ""
  currentString = "" + "accaccacc" = "accaccacc"
  
Result: "accaccacc"
```

### 💬 COMMUNICATION SCRIPT
> "Sir, nested decoding problem using two stacks - one for counts, one for strings. When I see opening bracket, I save current state. When I see closing bracket, I decode by repeating string count times and append to previous string."
>
> **Time:** O(maxK * n) where maxK is maximum count, **Space:** O(n)

---

## 🎯 PROBLEM 5: BASIC CALCULATOR II
**⭐⭐⭐⭐**

**Problem:**
Evaluate string expression with +, -, *, /

**Example:**
```
Input: s = "3+2*2"
Output: 7

Input: s = " 3/2 "
Output: 1
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int num = 0;
    char op = '+';  // Previous operator
    
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if(isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        
        // Process when operator or end of string
        if((!isdigit(c) && c != ' ') || i == s.length() - 1) {
            if(op == '+') {
                st.push(num);
            }
            else if(op == '-') {
                st.push(-num);
            }
            else if(op == '*') {
                int top = st.top();
                st.pop();
                st.push(top * num);
            }
            else if(op == '/') {
                int top = st.top();
                st.pop();
                st.push(top / num);
            }
            
            op = c;
            num = 0;
        }
    }
    
    // Sum all in stack
    int result = 0;
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    return result;
}

int main() {
    string s;
    cout << "Enter expression: ";
    getline(cin, s);
    
    cout << "Result: " << calculate(s) << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "3+2*2"

Step 1-2: num = 3, op = '+'
  Stack: [3]
  op = '+', num = 0
  
Step 3-4: num = 2, op = '*'
  Stack: [3, 2]
  op = '*', num = 0
  
Step 5: num = 2, end of string
  op = '*', so multiply: 2 * 2 = 4
  Stack: [3, 4]
  
Sum stack: 3 + 4 = 7
```

### 💬 COMMUNICATION SCRIPT
> "Sir, expression evaluation using stack. For + and -, I push numbers directly. For * and /, I immediately calculate with previous number in stack. Finally sum all numbers in stack."
>
> **Time:** O(n), **Space:** O(n)

---

## 🎯 PROBLEM 6: SIMPLIFY PATH
**⭐⭐⭐⭐**

**Problem:**
Simplify Unix file path.

**Example:**
```
Input: "/home//foo/"
Output: "/home/foo"

Input: "/a/./b/../../c/"
Output: "/c"
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    stack<string> st;
    stringstream ss(path);
    string dir;
    
    while(getline(ss, dir, '/')) {
        if(dir == "" || dir == ".") {
            continue;  // Ignore
        }
        else if(dir == "..") {
            if(!st.empty()) {
                st.pop();  // Go back one directory
            }
        }
        else {
            st.push(dir);  // Valid directory
        }
    }
    
    // Build result
    string result = "";
    while(!st.empty()) {
        result = "/" + st.top() + result;
        st.pop();
    }
    
    return result.empty() ? "/" : result;
}

int main() {
    string path;
    cout << "Enter path: ";
    cin >> path;
    
    cout << "Simplified: " << simplifyPath(path) << endl;
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, path simplification using stack. I'll split by '/', ignore empty and '.', pop for '..', and push valid directories. Finally build canonical path."

---

## 📊 COMPANY-WISE FREQUENCY

| Problem | TCS | Infosys | Wipro | Cognizant | Accenture |
|---------|-----|---------|-------|-----------|-----------|
| Remove Duplicates | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ |
| Valid Parentheses | 90% ⭐⭐⭐⭐⭐ | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ |
| Remove K Duplicates | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ |
| Decode String | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ |
| Basic Calculator | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ | 45% ⭐⭐⭐⭐ | 30% ⭐⭐ | 25% ⭐⭐ |
| Simplify Path | 35% ⭐⭐⭐ | 30% ⭐⭐⭐ | 40% ⭐⭐⭐ | 25% ⭐⭐ | 20% ⭐⭐ |

---

## 🎯 QUICK REVISION TEMPLATE

```cpp
// SIMPLE MATCHING (Remove Duplicates)
string removeAdjacentDuplicates(string s) {
    stack<char> st;
    for(char c : s) {
        if(!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    // Build result (reverse order)
    string result = "";
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

// BRACKET MATCHING
bool isValidParentheses(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            if((c == ')' && top == '(') ||
               (c == '}' && top == '{') ||
               (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

// NESTED DECODING
string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string current = "";
    int k = 0;
    
    for(char c : s) {
        if(isdigit(c)) k = k * 10 + (c - '0');
        else if(c == '[') {
            countStack.push(k);
            stringStack.push(current);
            current = "";
            k = 0;
        }
        else if(c == ']') {
            string temp = current;
            current = stringStack.top();
            stringStack.pop();
            int count = countStack.top();
            countStack.pop();
            for(int i = 0; i < count; i++) current += temp;
        }
        else current += c;
    }
    return current;
}
```

---

## 💡 PATTERN IDENTIFICATION

**When you see:**
- "**Remove adjacent** duplicates" → Simple stack with matching
- "**Valid parentheses**" → Stack for bracket matching
- "**Decode** k[string]" → Two stacks (count + string)
- "**Calculator**" → Stack for operator precedence
- "**Simplify** path" → Stack for directory navigation

**Your response:** "Sir, stack pattern. I'll use LIFO property to..."

---

**Master these 6 problems → Handle 95% stack string questions!** 🚀
