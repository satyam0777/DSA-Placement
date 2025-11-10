#  STRING PATTERNS - COMPLETE INTERVIEW PACKAGE


---

##  THE 8 CORE PATTERNS

### **Pattern Mapping: Array → String**

| Pattern | Array Example | String Example |
|---------|---------------|----------------|
| **Two Pointer** | Two Sum, Remove Duplicates | Palindrome, Reverse |
| **Sliding Window** | Max Sum Subarray | Longest Substring |
| **Hashing** | Frequency Count | Anagram, First Unique |
| **Stack** | Next Greater Element | Remove Adjacent Duplicates |
| **Prefix Sum** | Range Query | Balanced Strings |
| **Sorting** | Sort Array | Group Anagrams |
| **Greedy** | Activity Selection | Reorganize String |
| **Binary Search** | Search in Array | (Advanced patterns) |

---

##  PATTERN 1: TWO POINTER

### **When to Use:**
- **Palindrome** problems
- **Reverse** operations
- Comparing from **both ends**

### **Top 3 Problems:**

**1. Valid Palindrome**
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while(left < right) {
        // Skip non-alphanumeric
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right--;
        
        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
```

**2. Reverse Vowels**
```cpp
string reverseVowels(string s) {
    int left = 0, right = s.length() - 1;
    string vowels = "aeiouAEIOU";
    
    while(left < right) {
        while(left < right && vowels.find(s[left]) == string::npos) left++;
        while(left < right && vowels.find(s[right]) == string::npos) right--;
        
        swap(s[left++], s[right--]);
    }
    return s;
}
```

**3. Two Sum (String Version)**
```cpp
// Find if two characters at different positions match target
bool twoCharSum(string s, char target) {
    int left = 0, right = s.length() - 1;
    
    while(left < right) {
        if(s[left] + s[right] == target) return true;
        else if(s[left] + s[right] < target) left++;
        else right--;
    }
    return false;
}
```

**Communication Script:**
> "Sir, this is two-pointer pattern. I'll use pointers from both ends, move inward based on condition. Same as array two-pointer but with characters."

---

##  PATTERN 2: SLIDING WINDOW

### **When to Use:**
- **Longest/Shortest** substring
- **At most K** distinct characters
- **Substring** with condition

### **Top 3 Problems:**

**1. Longest Substring Without Repeating Characters** ⭐⭐⭐⭐⭐
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.length(); right++) {
        // Shrink while duplicate
        while(window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        
        window.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**2. Longest Substring with At Most K Distinct Characters**
```cpp
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> window;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.length(); right++) {
        window[s[right]]++;
        
        // Shrink if more than k distinct
        while(window.size() > k) {
            window[s[left]]--;
            if(window[s[left]] == 0) {
                window.erase(s[left]);
            }
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**3. Minimum Window Substring** ⭐⭐⭐⭐⭐
```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> required, window;
    
    for(char c : t) required[c]++;
    
    int left = 0, formed = 0;
    int minLen = INT_MAX, minLeft = 0;
    
    for(int right = 0; right < s.length(); right++) {
        char c = s[right];
        window[c]++;
        
        if(required.count(c) && window[c] == required[c]) {
            formed++;
        }
        
        // Try to shrink
        while(formed == required.size()) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            char leftChar = s[left];
            window[leftChar]--;
            if(required.count(leftChar) && window[leftChar] < required[leftChar]) {
                formed--;
            }
            left++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}
```

**Communication Script:**
> "Sir, sliding window pattern. Expand right to include characters, shrink left when condition violated. Track maximum/minimum window size."

---

##  PATTERN 3: HASHING (FREQUENCY MAP)

### **When to Use:**
- **Anagram** problems
- **Character frequency**
- **First unique** character
- **Group** by property

### **Top 5 Problems:**

**1. Valid Anagram** ⭐⭐⭐⭐⭐
```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    
    unordered_map<char, int> freq;
    
    for(char c : s) freq[c]++;
    for(char c : t) freq[c]--;
    
    for(auto& p : freq) {
        if(p.second != 0) return false;
    }
    
    return true;
}
```

**2. First Unique Character** ⭐⭐⭐⭐⭐
```cpp
int firstUniqChar(string s) {
    unordered_map<char, int> freq;
    
    // Count frequencies
    for(char c : s) freq[c]++;
    
    // Find first with freq 1
    for(int i = 0; i < s.length(); i++) {
        if(freq[s[i]] == 1) return i;
    }
    
    return -1;
}
```

**3. Group Anagrams** ⭐⭐⭐⭐⭐
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    
    for(string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for(auto& p : groups) {
        result.push_back(p.second);
    }
    
    return result;
}
```

**4. Longest Palindrome** (can be formed)
```cpp
int longestPalindrome(string s) {
    unordered_map<char, int> freq;
    
    for(char c : s) freq[c]++;
    
    int length = 0;
    bool hasOdd = false;
    
    for(auto& p : freq) {
        if(p.second % 2 == 0) {
            length += p.second;
        } else {
            length += p.second - 1;  // Use even part
            hasOdd = true;
        }
    }
    
    return hasOdd ? length + 1 : length;
}
```

**5. Ransom Note**
```cpp
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> available;
    
    for(char c : magazine) available[c]++;
    
    for(char c : ransomNote) {
        if(available[c] == 0) return false;
        available[c]--;
    }
    
    return true;
}
```

**Communication Script:**
> "Sir, hashing pattern for frequency counting. Use unordered_map to count characters. Same as array hashing but with char keys."

---

##  PATTERN 4: STACK

### **When to Use:**
- **Remove adjacent** duplicates
- **Valid parentheses**
- **Decode** strings
- **Reverse** with constraints

### **Top 3 Problems:**

**1. Remove All Adjacent Duplicates** ⭐⭐⭐⭐⭐
```cpp
string removeDuplicates(string s) {
    stack<char> st;
    
    for(char c : s) {
        if(!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    
    string result = "";
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

**2. Valid Parentheses** ⭐⭐⭐⭐⭐
```cpp
bool isValid(string s) {
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
```

**3. Decode String** (e.g., "3[a2[c]]" → "accaccacc")
```cpp
string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string current = "";
    int k = 0;
    
    for(char c : s) {
        if(isdigit(c)) {
            k = k * 10 + (c - '0');
        } else if(c == '[') {
            countStack.push(k);
            stringStack.push(current);
            current = "";
            k = 0;
        } else if(c == ']') {
            string temp = current;
            current = stringStack.top();
            stringStack.pop();
            
            int count = countStack.top();
            countStack.pop();
            
            for(int i = 0; i < count; i++) {
                current += temp;
            }
        } else {
            current += c;
        }
    }
    
    return current;
}
```

**Communication Script:**
> "Sir, stack pattern for matching/removing. Push characters, pop when condition met. Same as array stack problems."

---

##  PATTERN 5: PREFIX SUM (BALANCE/COUNT)

### **When to Use:**
- **Balanced** strings (equal L and R)
- **Count** substrings
- **Cumulative** properties

### **Top 2 Problems:**

**1. Split Balanced Strings** ⭐⭐⭐⭐
```cpp
int balancedStringSplit(string s) {
    int balance = 0, count = 0;
    
    for(char c : s) {
        balance += (c == 'L') ? 1 : -1;
        
        if(balance == 0) {
            count++;
        }
    }
    
    return count;
}
```

**2. Score of Parentheses**
```cpp
int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);
    
    for(char c : s) {
        if(c == '(') {
            st.push(0);
        } else {
            int val = st.top();
            st.pop();
            int top = st.top();
            st.pop();
            st.push(top + max(2 * val, 1));
        }
    }
    
    return st.top();
}
```

**Communication Script:**
> "Sir, prefix sum pattern. Track cumulative balance/count. When balance reaches target, found valid substring."

---

##  PATTERN 6: SORTING

### **When to Use:**
- **Group** similar strings
- **Compare** character sets
- **Anagram** detection (alternative to hashing)

### **Key Template:**
```cpp
// Sort string to use as key
string getKey(string s) {
    sort(s.begin(), s.end());
    return s;
}

// Group by sorted key
unordered_map<string, vector<string>> groups;
for(string s : strs) {
    groups[getKey(s)].push_back(s);
}
```

---

##  PATTERN 7: GREEDY

### **When to Use:**
- **Reorganize** string (no adjacent same)
- **Lexicographically** smallest/largest
- **Remove K** characters

### **Top 2 Problems:**

**1. Reorganize String** ⭐⭐⭐⭐
```cpp
string reorganizeString(string s) {
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;
    
    priority_queue<pair<int, char>> pq;
    for(auto& p : freq) pq.push({p.second, p.first});
    
    string result = "";
    pair<int, char> prev = {0, '#'};
    
    while(!pq.empty()) {
        auto [f, c] = pq.top();
        pq.pop();
        
        result += c;
        
        if(prev.first > 0) pq.push(prev);
        
        prev = {f - 1, c};
    }
    
    return result.length() == s.length() ? result : "";
}
```

**2. Remove K Digits**
```cpp
string removeKdigits(string num, int k) {
    string result = "";
    
    for(char c : num) {
        while(!result.empty() && result.back() > c && k > 0) {
            result.pop_back();
            k--;
        }
        result += c;
    }
    
    // Remove remaining k digits from end
    while(k > 0) {
        result.pop_back();
        k--;
    }
    
    // Remove leading zeros
    int i = 0;
    while(i < result.length() && result[i] == '0') i++;
    
    return i == result.length() ? "0" : result.substr(i);
}
```

---

##  PATTERN 8: ADVANCED (KMP, TRIE)

### **When to Use (Rare in Service-Based):**
- **Pattern matching** (KMP)
- **Autocomplete** (Trie)
- **Longest common prefix** (Trie)

**Usually NOT asked in TCS/Infosys/Wipro!**

---

##  PATTERN FREQUENCY IN INTERVIEWS

| Pattern | Service-Based | Example Problem |
|---------|---------------|-----------------|
| **Hashing** | 40% ⭐⭐⭐⭐⭐ | Anagram, First Unique |
| **Two Pointer** | 30% ⭐⭐⭐⭐⭐ | Palindrome, Reverse |
| **Sliding Window** | 25% ⭐⭐⭐⭐ | Longest Substring |
| **Stack** | 20% ⭐⭐⭐⭐ | Valid Parentheses |
| **Sorting** | 15% ⭐⭐⭐ | Group Anagrams |
| **Greedy** | 10% ⭐⭐⭐ | Reorganize String |
| **Prefix Sum** | 5% ⭐⭐ | Balanced Strings |
| **Advanced** | <5% ⭐ | KMP, Trie |

---

##  QUICK DECISION TREE

```
Palindrome / Reverse? → TWO POINTER
Longest / Shortest substring? → SLIDING WINDOW
Frequency / Anagram? → HASHING
Remove adjacent / Parentheses? → STACK
Group similar strings? → SORTING
No adjacent same? → GREEDY
Pattern matching? → KMP (rare)
```

---

##  MASTER THESE 15 PROBLEMS

1. Valid Palindrome (Two Pointer)
2. Longest Substring Without Repeat (Sliding Window)
3. Valid Anagram (Hashing)
4. First Unique Character (Hashing)
5. Group Anagrams (Hashing + Sorting)
6. Remove Duplicates (Stack)
7. Valid Parentheses (Stack)
8. Minimum Window Substring (Sliding Window)
9. Longest Palindromic Substring (Two Pointer/DP)
10. Reverse Words (Two Pointer)
11. String to Integer (atoi) (Basic)
12. Reorganize String (Greedy)
13. Decode String (Stack)
14. Longest Common Prefix (Basic)
15. Implement strStr() (Basic/KMP)

**Master these 15 → Crack 90% of string interviews!**

---

##  FINAL TIPS

**The Secret:**
> **You already know all patterns from Arrays!**
> **Just apply them to character arrays!**

**Success Formula:**
```
String Problem = Recognize Pattern + Apply Array Technique
```

**Priority:**
1. Hashing (40%) - MUST master
2. Two Pointer (30%) - MUST master
3. Sliding Window (25%) - Important
4. Stack (20%) - Important
5. Others - Good to know

---


**All the best** 
