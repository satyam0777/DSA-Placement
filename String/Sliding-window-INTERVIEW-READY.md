#  SLIDING WINDOW - STRING PROBLEMS

**Pattern Recognition:** When you see "**longest**", "**shortest**", "**substring**", "**at most K**" - Think SLIDING WINDOW!

---

##  CORE CONCEPT

**Same as Array Sliding Window, but with characters!**

**Template:**
```cpp
int slidingWindow(string s) {
    unordered_map<char, int> window;
    int left = 0, result = 0;
    
    for(int right = 0; right < s.length(); right++) {
        // Expand: Add s[right] to window
        window[s[right]]++;
        
        // Shrink: While condition violated
        while(/* condition violated */) {
            window[s[left]]--;
            left++;
        }
        
        // Update result
        result = max(result, right - left + 1);
    }
    
    return result;
}
```

---

##  PROBLEM 1: LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS
**⭐⭐⭐⭐⭐ MOST ASKED!**

**Problem:**
Given string, find length of longest substring without repeating characters.

**Example:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: "abc" is longest without repeat
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0;
    int maxLength = 0;
    
    for(int right = 0; right < s.length(); right++) {
        // If duplicate found, shrink from left
        while(window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        
        // Add current character
        window.insert(s[right]);
        
        // Update max length
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    cout << "Longest substring without repeat: " 
         << lengthOfLongestSubstring(s) << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "abcabcbb"

Step 1: right = 0, s[right] = 'a'
  window = {'a'}, maxLength = 1
  
Step 2: right = 1, s[right] = 'b'
  window = {'a', 'b'}, maxLength = 2
  
Step 3: right = 2, s[right] = 'c'
  window = {'a', 'b', 'c'}, maxLength = 3
  
Step 4: right = 3, s[right] = 'a'
  Duplicate! Shrink:
  Remove s[0]='a', left=1
  window = {'b', 'c', 'a'}, maxLength = 3
  
Step 5: right = 4, s[right] = 'b'
  Duplicate! Shrink:
  Remove s[1]='b', left=2
  window = {'c', 'a', 'b'}, maxLength = 3
  
Continue...

Answer: 3
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this is sliding window problem. I'll use unordered_set to track characters in current window. When I find duplicate, I'll shrink window from left by removing characters until duplicate is removed. I'll track maximum window size throughout."
>
> **Time Complexity:** "Sir, O(n) because each character visited at most twice - once by right pointer, once by left pointer."
>
> **Space Complexity:** "Sir, O(min(n, charset)) for the set. At most 26 characters for lowercase, 128 for ASCII."

---

##  PROBLEM 2: LONGEST SUBSTRING WITH AT MOST K DISTINCT CHARACTERS
**⭐⭐⭐⭐⭐**

**Problem:**
Find longest substring with at most K distinct characters.

**Example:**
```
Input: s = "eceba", k = 2
Output: 3
Explanation: "ece" has 2 distinct characters
```

###  SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(k == 0) return 0;
    
    unordered_map<char, int> window;
    int left = 0;
    int maxLength = 0;
    
    for(int right = 0; right < s.length(); right++) {
        // Add character to window
        window[s[right]]++;
        
        // Shrink if more than k distinct characters
        while(window.size() > k) {
            window[s[left]]--;
            if(window[s[left]] == 0) {
                window.erase(s[left]);
            }
            left++;
        }
        
        // Update max length
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    
    cout << "Longest substring with at most " << k 
         << " distinct: " << lengthOfLongestSubstringKDistinct(s, k) << endl;
    
    return 0;
}
```

###  DRY RUN
```
s = "eceba", k = 2

Step 1: right = 0, s[right] = 'e'
  window = {'e':1}, distinct = 1, maxLength = 1
  
Step 2: right = 1, s[right] = 'c'
  window = {'e':1, 'c':1}, distinct = 2, maxLength = 2
  
Step 3: right = 2, s[right] = 'e'
  window = {'e':2, 'c':1}, distinct = 2, maxLength = 3
  
Step 4: right = 3, s[right] = 'b'
  window = {'e':2, 'c':1, 'b':1}, distinct = 3 > k
  Shrink:
  Remove s[0]='e': window = {'e':1, 'c':1, 'b':1}
  Remove s[1]='c': window = {'e':1, 'b':1}, left=2
  maxLength = 3
  
Step 5: right = 4, s[right] = 'a'
  window = {'e':1, 'b':1, 'a':1}, distinct = 3 > k
  Shrink:
  Remove s[2]='e': window = {'b':1, 'a':1}, left=3
  maxLength = 3

Answer: 3 ("ece")
```

### 💬 COMMUNICATION SCRIPT
> "Sir, sliding window with constraint. I'll maintain frequency map of characters in window. When distinct count exceeds K, I'll shrink from left until we have at most K distinct characters. Track maximum window size."
>
> **Time:** O(n), **Space:** O(k) for the map

---

##  PROBLEM 3: MINIMUM WINDOW SUBSTRING
**⭐⭐⭐⭐⭐ HARD BUT IMPORTANT!**

**Problem:**
Find minimum window in S that contains all characters of T.

**Example:**
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
```

###  SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if(s.empty() || t.empty()) return "";
    
    // Frequency map of characters in t
    unordered_map<char, int> required;
    for(char c : t) {
        required[c]++;
    }
    
    // Window frequency map
    unordered_map<char, int> window;
    
    int left = 0, right = 0;
    int formed = 0;  // Characters in window that match required frequency
    int required_size = required.size();
    
    // Result
    int minLen = INT_MAX;
    int minLeft = 0;
    
    while(right < s.length()) {
        // Expand window
        char c = s[right];
        window[c]++;
        
        // Check if this character's frequency matches required
        if(required.count(c) && window[c] == required[c]) {
            formed++;
        }
        
        // Try to shrink window
        while(left <= right && formed == required_size) {
            // Update result
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
            }
            
            // Remove from left
            char leftChar = s[left];
            window[leftChar]--;
            if(required.count(leftChar) && window[leftChar] < required[leftChar]) {
                formed--;
            }
            left++;
        }
        
        right++;
    }
    
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;
    
    string result = minWindow(s, t);
    if(result.empty()) {
        cout << "No valid window found" << endl;
    } else {
        cout << "Minimum window: " << result << endl;
    }
    
    return 0;
}
```

###  DRY RUN
```
s = "ADOBECODEBANC", t = "ABC"
required = {'A':1, 'B':1, 'C':1}

Step 1-5: Expand to "ADOBEC"
  window = {'A':1, 'D':1, 'O':2, 'B':1, 'E':1, 'C':1}
  formed = 3 ✓ Found valid window!
  minLen = 6, minLeft = 0
  
Step 6: Try to shrink
  Remove 'A': formed = 2 (not valid anymore)
  
Step 7-12: Continue expanding...
  At "ADOBECODEBA": formed = 3 again
  minLen = 6 (no improvement)
  
Step 13: Reach "ODEBANC"
  window = {'O':1, 'D':1, 'E':1, 'B':1, 'A':1, 'N':1, 'C':1}
  formed = 3
  Length = 7 > 6, no update
  
Step 14: Continue shrinking to "BANC"
  window = {'B':1, 'A':1, 'N':1, 'C':1}
  formed = 3
  minLen = 4, minLeft = 9

Answer: "BANC"
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this is advanced sliding window problem. I'll maintain two hashmaps - one for required characters from T, one for current window. I'll expand window with right pointer, and when all required characters are present, I'll try to shrink from left to find minimum window. I'll use 'formed' variable to track how many unique characters in window match required frequency."
>
> **Time:** O(|S| + |T|), **Space:** O(|S| + |T|) for hashmaps

---

##  PROBLEM 4: LONGEST REPEATING CHARACTER REPLACEMENT
**⭐⭐⭐⭐**

**Problem:**
You can change at most K characters. Find longest substring with same characters.

**Example:**
```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace one 'A' in middle → "AABBBBA" → "BBBB"
```

###  SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char, int> window;
    int left = 0;
    int maxFreq = 0;  // Frequency of most frequent character
    int maxLength = 0;
    
    for(int right = 0; right < s.length(); right++) {
        window[s[right]]++;
        maxFreq = max(maxFreq, window[s[right]]);
        
        // Window size - most frequent character > k
        // means we need to replace more than k characters
        if((right - left + 1) - maxFreq > k) {
            window[s[left]]--;
            left++;
        }
        
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    
    cout << "Longest repeating with " << k 
         << " changes: " << characterReplacement(s, k) << endl;
    
    return 0;
}
```

###  DRY RUN
```
s = "AABABBA", k = 1

Step 1-3: "AAB"
  window = {'A':2, 'B':1}, maxFreq = 2
  windowSize = 3, replacements needed = 3-2 = 1 ≤ k ✓
  maxLength = 3
  
Step 4: "AABA"
  window = {'A':3, 'B':1}, maxFreq = 3
  windowSize = 4, replacements = 4-3 = 1 ≤ k ✓
  maxLength = 4
  
Step 5: "AABAB"
  window = {'A':3, 'B':2}, maxFreq = 3
  windowSize = 5, replacements = 5-3 = 2 > k ✗
  Shrink: left = 1
  window = {'A':2, 'B':2}
  maxLength = 4
  
Continue...

Answer: 4
```

###  COMMUNICATION SCRIPT
> "Sir, sliding window with K replacements allowed. Key insight: window is valid if (window size - most frequent character count) ≤ K. I'll track frequency of most common character, and shrink when we need more than K replacements."
>
> **Time:** O(n), **Space:** O(1) (at most 26 characters)

---

##  PROBLEM 5: PERMUTATION IN STRING
**⭐⭐⭐⭐**

**Problem:**
Check if s1's permutation is substring of s2.

**Example:**
```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains "ba" which is permutation of "ab"
```

###  SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;
    
    // Frequency maps
    unordered_map<char, int> s1Freq, windowFreq;
    
    for(char c : s1) {
        s1Freq[c]++;
    }
    
    int windowSize = s1.length();
    int left = 0;
    
    for(int right = 0; right < s2.length(); right++) {
        // Add character to window
        windowFreq[s2[right]]++;
        
        // Maintain fixed window size
        if(right - left + 1 > windowSize) {
            windowFreq[s2[left]]--;
            if(windowFreq[s2[left]] == 0) {
                windowFreq.erase(s2[left]);
            }
            left++;
        }
        
        // Check if window matches s1 frequency
        if(windowFreq == s1Freq) {
            return true;
        }
    }
    
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;
    
    if(checkInclusion(s1, s2)) {
        cout << "s2 contains permutation of s1" << endl;
    } else {
        cout << "s2 does NOT contain permutation of s1" << endl;
    }
    
    return 0;
}
```

###  DRY RUN
```
s1 = "ab", s2 = "eidbaooo"
s1Freq = {'a':1, 'b':1}

Window size = 2

Step 1-2: window = "ei"
  windowFreq = {'e':1, 'i':1} ≠ s1Freq
  
Step 3-4: window = "id"
  windowFreq = {'i':1, 'd':1} ≠ s1Freq
  
Step 5-6: window = "db"
  windowFreq = {'d':1, 'b':1} ≠ s1Freq
  
Step 7: window = "ba"
  windowFreq = {'b':1, 'a':1} == s1Freq ✓
  
Return true
```

###  COMMUNICATION SCRIPT
> "Sir, fixed-size sliding window problem. Size equals s1 length. I'll maintain frequency map of current window and compare with s1's frequency. If they match, we found a permutation."
>
> **Time:** O(n), **Space:** O(1) (fixed charset)

---

##  PROBLEM 6: FIND ALL ANAGRAMS IN STRING
**⭐⭐⭐⭐⭐**

**Problem:**
Find all start indices where p's anagram is substring of s.

**Example:**
```
Input: s = "cbaebabacd", p = "abc"
Output: [0, 6]
Explanation: "cba" at index 0, "bac" at index 6
```

###  SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if(s.length() < p.length()) return result;
    
    unordered_map<char, int> pFreq, windowFreq;
    
    for(char c : p) {
        pFreq[c]++;
    }
    
    int windowSize = p.length();
    
    for(int i = 0; i < s.length(); i++) {
        // Add character to window
        windowFreq[s[i]]++;
        
        // Remove character from left if window too large
        if(i >= windowSize) {
            windowFreq[s[i - windowSize]]--;
            if(windowFreq[s[i - windowSize]] == 0) {
                windowFreq.erase(s[i - windowSize]);
            }
        }
        
        // Check if current window is anagram
        if(windowFreq == pFreq) {
            result.push_back(i - windowSize + 1);
        }
    }
    
    return result;
}

int main() {
    string s, p;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter pattern p: ";
    cin >> p;
    
    vector<int> indices = findAnagrams(s, p);
    
    if(indices.empty()) {
        cout << "No anagrams found" << endl;
    } else {
        cout << "Anagram starting indices: ";
        for(int idx : indices) {
            cout << idx << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

###  COMMUNICATION SCRIPT
> "Sir, this is combination of sliding window and frequency comparison. I'll maintain fixed window of size equal to pattern length, and check if window's frequency matches pattern's frequency. Add all matching indices to result."

---

##  COMPANY-WISE FREQUENCY

| Problem | TCS | Infosys | Wipro | Cognizant | Accenture |
|---------|-----|---------|-------|-----------|-----------|
| Longest Substring Without Repeat | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ |
| K Distinct Characters | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ |
| Minimum Window Substring | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ | 45% ⭐⭐⭐⭐ | 30% ⭐⭐⭐ | 25% ⭐⭐ |
| Character Replacement | 30% ⭐⭐⭐ | 25% ⭐⭐ | 35% ⭐⭐⭐ | 20% ⭐⭐ | 20% ⭐⭐ |
| Find Anagrams | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ |

---

##  QUICK REVISION TEMPLATE

```cpp
// SLIDING WINDOW - VARIABLE SIZE
int slidingWindow(string s, int condition) {
    unordered_map<char, int> window;
    int left = 0, result = 0;
    
    for(int right = 0; right < s.length(); right++) {
        window[s[right]]++;
        
        while(/* condition violated */) {
            window[s[left]]--;
            if(window[s[left]] == 0) window.erase(s[left]);
            left++;
        }
        
        result = max(result, right - left + 1);
    }
    return result;
}

// SLIDING WINDOW - FIXED SIZE
vector<int> fixedWindow(string s, string pattern) {
    unordered_map<char, int> required, window;
    for(char c : pattern) required[c]++;
    
    vector<int> result;
    int size = pattern.length();
    
    for(int i = 0; i < s.length(); i++) {
        window[s[i]]++;
        
        if(i >= size) {
            window[s[i - size]]--;
            if(window[s[i - size]] == 0) window.erase(s[i - size]);
        }
        
        if(window == required) {
            result.push_back(i - size + 1);
        }
    }
    return result;
}
```

---

##  PATTERN IDENTIFICATION

**When you see:**
- "**Longest** substring..." → Variable window, maximize
- "**Shortest** substring..." → Variable window, minimize
- "**At most K** distinct..." → Variable window with constraint
- "**Find all** anagrams..." → Fixed window
- "**Permutation** in string..." → Fixed window

**Your response:** "Sir, sliding window technique. I'll use..."

---

**Master these 6 problems → Handle 95% sliding window string questions!** 
