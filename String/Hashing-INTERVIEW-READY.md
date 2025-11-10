#  HASHING - STRING PROBLEMS
## Complete Interview Package

**Pattern Recognition:** When you see "**anagram**", "**frequency**", "**unique**", "**count**", "**group**" - Think HASHING!

---

##  CORE CONCEPT

**Hashing = Fast Lookup with Map/Set**

**Perfect for:**
- Character frequency counting
- Anagram detection
- Finding unique/duplicate elements
- Grouping similar strings

**Template:**
```cpp
unordered_map<char, int> freq;  // Character → Count

// Count frequency
for(char c : s) {
    freq[c]++;
}

// Check frequency
if(freq[target] > 0) {
    // target exists
}
```

---

## 🎯 PROBLEM 1: VALID ANAGRAM
**⭐⭐⭐⭐⭐ MOST ASKED!**

**Problem:**
Check if two strings are anagrams (same characters, different order).

**Example:**
```
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
```

### ✅ SOLUTION - METHOD 1 (Frequency Map)

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, int> freq;
    
    // Count characters in s
    for(char c : s) {
        freq[c]++;
    }
    
    // Decrease for characters in t
    for(char c : t) {
        freq[c]--;
    }
    
    // Check if all frequencies are 0
    for(auto& p : freq) {
        if(p.second != 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;
    
    if(isAnagram(s, t)) {
        cout << "Anagrams!" << endl;
    } else {
        cout << "Not anagrams!" << endl;
    }
    
    return 0;
}
```

### ✅ SOLUTION - METHOD 2 (Sorting)

```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s == t;
}
```

### 📊 DRY RUN
```
s = "anagram", t = "nagaram"

Method 1 (Hashing):
Step 1: Count s
  freq = {'a':3, 'n':1, 'g':1, 'r':1, 'm':1}
  
Step 2: Decrease for t
  freq = {'a':0, 'n':0, 'g':0, 'r':0, 'm':0}
  
Step 3: All zeros → Anagram!

Method 2 (Sorting):
  s sorted = "aaagnmr"
  t sorted = "aaagnmr"
  Equal → Anagram!
```

### 💬 COMMUNICATION SCRIPT
> "Sir, two approaches - hashing or sorting. With hashing, I count character frequencies and check if both strings have same frequencies. Time O(n), space O(1) for 26 characters. With sorting, I sort both and compare. Time O(n log n), space O(1). Hashing is faster."
>
> **Hashing:** Time O(n), Space O(1)
> **Sorting:** Time O(n log n), Space O(1)

---

## 🎯 PROBLEM 2: FIRST UNIQUE CHARACTER
**⭐⭐⭐⭐⭐**

**Problem:**
Find first non-repeating character's index.

**Example:**
```
Input: s = "leetcode"
Output: 0 (first 'l' appears once)

Input: s = "loveleetcode"
Output: 2 (first 'v' appears once)
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> freq;
    
    // Count all characters
    for(char c : s) {
        freq[c]++;
    }
    
    // Find first with count 1
    for(int i = 0; i < s.length(); i++) {
        if(freq[s[i]] == 1) {
            return i;
        }
    }
    
    return -1;  // No unique character
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    int index = firstUniqChar(s);
    
    if(index == -1) {
        cout << "No unique character found" << endl;
    } else {
        cout << "First unique character at index " << index 
             << ": '" << s[index] << "'" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "leetcode"

Step 1: Count frequencies
  freq = {'l':1, 'e':3, 't':1, 'c':1, 'o':1, 'd':1}
  
Step 2: Find first with freq 1
  i=0: s[0]='l', freq['l']=1 ✓
  
Return 0
```

### 💬 COMMUNICATION SCRIPT
> "Sir, two-pass hashing solution. First pass counts all character frequencies. Second pass finds first character with frequency 1. Simple and efficient O(n) solution."
>
> **Time:** O(n), **Space:** O(1) (at most 26 characters)

---

## 🎯 PROBLEM 3: GROUP ANAGRAMS
**⭐⭐⭐⭐⭐ VERY IMPORTANT!**

**Problem:**
Group strings that are anagrams of each other.

**Example:**
```
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    
    for(string& s : strs) {
        // Sort string to use as key
        string key = s;
        sort(key.begin(), key.end());
        
        // Group by sorted key
        groups[key].push_back(s);
    }
    
    // Extract all groups
    vector<vector<string>> result;
    for(auto& p : groups) {
        result.push_back(p.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = groupAnagrams(strs);
    
    cout << "Grouped anagrams:" << endl;
    for(auto& group : result) {
        cout << "[ ";
        for(string& s : group) {
            cout << s << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

Step 1: "eat" → sorted key = "aet"
  groups = {"aet": ["eat"]}
  
Step 2: "tea" → sorted key = "aet"
  groups = {"aet": ["eat", "tea"]}
  
Step 3: "tan" → sorted key = "ant"
  groups = {"aet": ["eat", "tea"], "ant": ["tan"]}
  
Step 4: "ate" → sorted key = "aet"
  groups = {"aet": ["eat", "tea", "ate"], "ant": ["tan"]}
  
Step 5: "nat" → sorted key = "ant"
  groups = {"aet": ["eat", "tea", "ate"], "ant": ["tan", "nat"]}
  
Step 6: "bat" → sorted key = "abt"
  groups = {"aet": ["eat", "tea", "ate"], "ant": ["tan", "nat"], "abt": ["bat"]}
  
Result: [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
```

### 💬 COMMUNICATION SCRIPT
> "Sir, hashing with sorted key approach. Anagrams will have same sorted form. I'll use sorted string as key in hashmap, group all anagrams together. Finally extract all groups."
>
> **Time:** O(n * k log k) where n = number of strings, k = max string length
> **Space:** O(n * k)

---

## 🎯 PROBLEM 4: LONGEST SUBSTRING WITH AT MOST K DISTINCT
**⭐⭐⭐⭐** (Already covered in Sliding Window, but uses hashing!)

**Problem:**
Find longest substring with at most K distinct characters.

### ✅ SOLUTION

```cpp
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> window;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.length(); right++) {
        window[s[right]]++;
        
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

### 💬 COMMUNICATION SCRIPT
> "Sir, combination of sliding window and hashing. Use hashmap to track character frequencies in window, check size for distinct count."

---

## 🎯 PROBLEM 5: RANSOM NOTE
**⭐⭐⭐⭐⭐**

**Problem:**
Check if ransomNote can be constructed from magazine characters.

**Example:**
```
Input: ransomNote = "aa", magazine = "aab"
Output: true

Input: ransomNote = "aa", magazine = "ab"
Output: false
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> available;
    
    // Count available characters
    for(char c : magazine) {
        available[c]++;
    }
    
    // Check if we can construct ransom note
    for(char c : ransomNote) {
        if(available[c] == 0) {
            return false;
        }
        available[c]--;
    }
    
    return true;
}

int main() {
    string ransomNote, magazine;
    cout << "Enter ransom note: ";
    cin >> ransomNote;
    cout << "Enter magazine: ";
    cin >> magazine;
    
    if(canConstruct(ransomNote, magazine)) {
        cout << "Can construct!" << endl;
    } else {
        cout << "Cannot construct!" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
ransomNote = "aa", magazine = "aab"

Step 1: Count magazine
  available = {'a':2, 'b':1}
  
Step 2: Check ransom note
  c='a': available['a']=2 → 1
  c='a': available['a']=1 → 0
  
All characters available → true
```

### 💬 COMMUNICATION SCRIPT
> "Sir, frequency matching problem. Count available characters in magazine, then check if we have enough for ransom note."
>
> **Time:** O(m + n), **Space:** O(1) (26 characters max)

---

## 🎯 PROBLEM 6: LONGEST PALINDROME
**⭐⭐⭐⭐**

**Problem:**
Find length of longest palindrome that can be built.

**Example:**
```
Input: s = "abccccdd"
Output: 7
Explanation: "dccaccd" (or "dccbccd")
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> freq;
    
    // Count frequencies
    for(char c : s) {
        freq[c]++;
    }
    
    int length = 0;
    bool hasOdd = false;
    
    for(auto& p : freq) {
        if(p.second % 2 == 0) {
            // Even frequency - use all
            length += p.second;
        } else {
            // Odd frequency - use even part
            length += p.second - 1;
            hasOdd = true;
        }
    }
    
    // If any odd frequency, we can put one in middle
    if(hasOdd) {
        length++;
    }
    
    return length;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    cout << "Longest palindrome length: " << longestPalindrome(s) << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "abccccdd"

Step 1: Count frequencies
  freq = {'a':1, 'b':1, 'c':4, 'd':2}
  
Step 2: Process frequencies
  'a': odd (1) → use 0, hasOdd = true
  'b': odd (1) → use 0, hasOdd stays true
  'c': even (4) → use 4
  'd': even (2) → use 2
  
  length = 0 + 0 + 4 + 2 = 6
  
Step 3: Add one odd in middle
  length = 6 + 1 = 7
  
Result: 7
```

### 💬 COMMUNICATION SCRIPT
> "Sir, palindrome construction using frequency counting. For even frequencies, use all characters. For odd frequencies, use (count-1). Finally add 1 if any odd frequency exists - that character goes in middle."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 7: ISOMORPHIC STRINGS
**⭐⭐⭐⭐**

**Problem:**
Check if two strings are isomorphic (one-to-one character mapping).

**Example:**
```
Input: s = "egg", t = "add"
Output: true (e→a, g→d)

Input: s = "foo", t = "bar"
Output: false (o can't map to both a and r)
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;
    
    unordered_map<char, char> mapST;  // s → t mapping
    unordered_map<char, char> mapTS;  // t → s mapping
    
    for(int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];
        
        // Check s → t mapping
        if(mapST.count(c1)) {
            if(mapST[c1] != c2) return false;
        } else {
            mapST[c1] = c2;
        }
        
        // Check t → s mapping
        if(mapTS.count(c2)) {
            if(mapTS[c2] != c1) return false;
        } else {
            mapTS[c2] = c1;
        }
    }
    
    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;
    
    if(isIsomorphic(s, t)) {
        cout << "Isomorphic!" << endl;
    } else {
        cout << "Not isomorphic!" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
s = "egg", t = "add"

Step 1: i=0, c1='e', c2='a'
  mapST = {'e':'a'}
  mapTS = {'a':'e'}
  
Step 2: i=1, c1='g', c2='d'
  mapST = {'e':'a', 'g':'d'}
  mapTS = {'a':'e', 'd':'g'}
  
Step 3: i=2, c1='g', c2='d'
  Check: mapST['g'] = 'd' ✓
  Check: mapTS['d'] = 'g' ✓
  
Return true
```

### 💬 COMMUNICATION SCRIPT
> "Sir, two-way mapping problem. I need both s→t and t→s mappings to ensure one-to-one correspondence. Check consistency at each step."
>
> **Time:** O(n), **Space:** O(1) (26 characters max)

---

## 🎯 PROBLEM 8: WORD PATTERN
**⭐⭐⭐⭐**

**Problem:**
Check if string follows pattern. Similar to isomorphic but with words.

**Example:**
```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    
    // Extract words
    while(ss >> word) {
        words.push_back(word);
    }
    
    if(pattern.length() != words.size()) return false;
    
    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;
    
    for(int i = 0; i < pattern.length(); i++) {
        char c = pattern[i];
        string w = words[i];
        
        // Check char → word
        if(charToWord.count(c)) {
            if(charToWord[c] != w) return false;
        } else {
            charToWord[c] = w;
        }
        
        // Check word → char
        if(wordToChar.count(w)) {
            if(wordToChar[w] != c) return false;
        } else {
            wordToChar[w] = c;
        }
    }
    
    return true;
}

int main() {
    string pattern, s;
    cout << "Enter pattern: ";
    cin >> pattern;
    cin.ignore();
    cout << "Enter string: ";
    getline(cin, s);
    
    if(wordPattern(pattern, s)) {
        cout << "Follows pattern!" << endl;
    } else {
        cout << "Does NOT follow pattern!" << endl;
    }
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, extension of isomorphic strings. Instead of char-to-char, I map char-to-word. Use two hashmaps for bidirectional mapping. Parse words using stringstream."

---

## 📊 COMPANY-WISE FREQUENCY

| Problem | TCS | Infosys | Wipro | Cognizant | Accenture |
|---------|-----|---------|-------|-----------|-----------|
| Valid Anagram | 90% ⭐⭐⭐⭐⭐ | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ |
| First Unique Character | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ |
| Group Anagrams | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ |
| Ransom Note | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ |
| Longest Palindrome | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ | 30% ⭐⭐⭐ |
| Isomorphic Strings | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ |
| Word Pattern | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ | 30% ⭐⭐⭐ | 25% ⭐⭐ | 20% ⭐⭐ |

---

## 🎯 QUICK REVISION TEMPLATE

```cpp
// FREQUENCY COUNTING
unordered_map<char, int> getFrequency(string s) {
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;
    return freq;
}

// ANAGRAM CHECK
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

// GROUP ANAGRAMS
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

// FIRST UNIQUE
int firstUniqChar(string s) {
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;
    for(int i = 0; i < s.length(); i++) {
        if(freq[s[i]] == 1) return i;
    }
    return -1;
}
```

---

## 💡 PATTERN IDENTIFICATION

**When you see:**
- "**Anagram**" → Frequency map comparison
- "**First unique**" → Frequency map + linear scan
- "**Group** similar strings" → Sorted string as key
- "**Construct** from available" → Frequency availability check
- "**Longest palindrome**" → Even/odd frequency logic
- "**Isomorphic** / Pattern" → Bidirectional mapping

**Your response:** "Sir, hashing for frequency/mapping. I'll use unordered_map to..."

---

**Master these 8 problems → Handle 95% hashing string questions!** 🚀
