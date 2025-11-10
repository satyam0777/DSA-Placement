#  STRING BASICS - INTERVIEW READY PACKAGE

---

##  TABLE OF CONTENTS

1. [Quick Recognition](#recognition)
2. [Top 10 Basic String Problems](#problems)
3. [Interview Communication](#communication)
4. [Company-Wise Questions](#companies)
5. [Common Mistakes](#mistakes)

---

<a name="recognition"></a>
##  QUICK RECOGNITION

### **Strings = Character Arrays + Helper Functions**

**Key Insight:**
```cpp
string s = "hello";  // Same as char s[] = {'h','e','l','l','o'}

// All array techniques work:
s[0]              // Indexing
for(char c : s)   // Iteration
s.length()        // Size
```

---

##  ESSENTIAL STRING OPERATIONS

### **Template 1: String Input/Output**
```cpp
string s;
getline(cin, s);  // For strings with spaces
cin >> s;         // For single word

cout << s << endl;
```

### **Template 2: Character Operations**
```cpp
char c = 'a';
toupper(c);  // 'A'
tolower(c);  // 'a'
isalpha(c);  // true if letter
isdigit(c);  // true if 0-9
isalnum(c);  // true if letter or digit
```

### **Template 3: String Manipulation**
```cpp
string s = "hello";

// Substring
s.substr(start, length);  // s.substr(1, 3) = "ell"

// Find
int pos = s.find("ll");   // Returns 2 (or string::npos if not found)

// Insert/Erase
s.insert(2, "XX");        // "heXXllo"
s.erase(2, 2);            // "helo"

// Reverse
reverse(s.begin(), s.end());  // "olleh"
```

---

<a name="problems"></a>
##  TOP 10 BASIC STRING PROBLEMS

### **Problem 1: Reverse a String** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Reverse the given string in-place."

**Template:**
```cpp
void reverseString(string& s) {
    int left = 0, right = s.length() - 1;
    
    while(left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// Or use STL:
reverse(s.begin(), s.end());
```

**What to Say:**
> "Sir, I'll use two-pointer technique from both ends, swap and move inward. Time O(n), Space O(1) since it's in-place."

**Dry Run:**
```
String: "hello"

left=0, right=4: swap 'h' and 'o' → "oellh"
left=1, right=3: swap 'e' and 'l' → "olleh"
left=2, right=2: stop

Result: "olleh"
```

---

### **Problem 2: Check Palindrome** ⭐⭐⭐⭐⭐

**Template:**
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}
```

**What to Say:**
> "Sir, palindrome reads same forward and backward. I'll check characters from both ends using two pointers. Time O(n), Space O(1)."

**Dry Run:**
```
String: "racecar"

left=0, right=6: 'r' == 'r' ✓
left=1, right=5: 'a' == 'a' ✓
left=2, right=4: 'c' == 'c' ✓
left=3, right=3: stop

Result: true (palindrome)
```

---

### **Problem 3: Valid Palindrome (Alphanumeric Only)** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Check palindrome, considering only alphanumeric characters and ignoring cases."

**Template:**
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    
    while(left < right) {
        // Skip non-alphanumeric from left
        while(left < right && !isalnum(s[left])) left++;
        
        // Skip non-alphanumeric from right
        while(left < right && !isalnum(s[right])) right--;
        
        // Compare (case-insensitive)
        if(tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
```

**What to Say:**
> "Sir, I'll skip non-alphanumeric characters and compare case-insensitively using tolower(). Two pointers for comparison. Time O(n), Space O(1)."

**Example:**
```
Input: "A man, a plan, a canal: Panama"
→ "amanaplanacanalpanama" (after filtering)
→ Is palindrome? YES ✓
```

---

### **Problem 4: Reverse Words in String** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Reverse the order of words. Input: 'hello world' → Output: 'world hello'"

**Template:**
```cpp
string reverseWords(string s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    
    // Extract words
    while(ss >> word) {
        words.push_back(word);
    }
    
    // Reverse order
    reverse(words.begin(), words.end());
    
    // Join with space
    string result = "";
    for(int i = 0; i < words.size(); i++) {
        result += words[i];
        if(i < words.size() - 1) result += " ";
    }
    
    return result;
}
```

**What to Say:**
> "Sir, I'll split string into words using stringstream, reverse the word array, then join back. Time O(n), Space O(n) for storing words."

---

### **Problem 5: Count Vowels and Consonants** ⭐⭐⭐⭐⭐

**Template:**
```cpp
void countVowelsConsonants(string s) {
    int vowels = 0, consonants = 0;
    
    for(char c : s) {
        c = tolower(c);
        
        if(isalpha(c)) {
            if(c == 'a' || c == 'e' || c == 'i' || 
               c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
}
```

**What to Say:**
> "Sir, I'll traverse string once, check each character if it's vowel or consonant. Time O(n), Space O(1)."

---

### **Problem 6: Remove All Spaces** ⭐⭐⭐⭐

**Template:**
```cpp
string removeSpaces(string s) {
    string result = "";
    
    for(char c : s) {
        if(c != ' ') {
            result += c;
        }
    }
    
    return result;
}

// In-place version:
void removeSpacesInPlace(string& s) {
    int j = 0;  // Write pointer
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') {
            s[j++] = s[i];
        }
    }
    
    s.resize(j);  // Truncate
}
```

**What to Say:**
> "Sir, I'll filter out spaces. Can use new string O(n) space, or in-place with two pointers O(1) space."

---

### **Problem 7: String to Integer (atoi)** ⭐⭐⭐⭐⭐

**Template:**
```cpp
int myAtoi(string s) {
    int i = 0, n = s.length();
    
    // Skip leading spaces
    while(i < n && s[i] == ' ') i++;
    
    // Check sign
    int sign = 1;
    if(i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert digits
    long result = 0;
    while(i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        // Check overflow
        if(result * sign > INT_MAX) return INT_MAX;
        if(result * sign < INT_MIN) return INT_MIN;
        
        i++;
    }
    
    return result * sign;
}
```

**What to Say:**
> "Sir, I'll handle: leading spaces, sign, digit conversion, overflow. Process character by character. Time O(n), Space O(1)."

---

### **Problem 8: Check Anagram (Basic)** ⭐⭐⭐⭐⭐

**Template (Sorting Method):**
```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s == t;
}
```

**Template (Frequency Method - Better):**
```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    
    vector<int> freq(26, 0);
    
    for(char c : s) freq[c - 'a']++;
    for(char c : t) freq[c - 'a']--;
    
    for(int f : freq) {
        if(f != 0) return false;
    }
    
    return true;
}
```

**What to Say:**
> "Sir, two approaches: Sort both and compare O(n log n), or use frequency array O(n) which is better. For lowercase letters, array of size 26 is sufficient."

---

### **Problem 9: Longest Common Prefix** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find longest common prefix among array of strings."

**Template:**
```cpp
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    
    string prefix = strs[0];
    
    for(int i = 1; i < strs.size(); i++) {
        // Shrink prefix until it matches start of current string
        while(strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if(prefix.empty()) return "";
        }
    }
    
    return prefix;
}
```

**What to Say:**
> "Sir, I'll take first string as prefix, then compare with each string. Keep shrinking prefix until it matches. Time O(n*m) where m is average string length."

**Dry Run:**
```
strs = ["flower", "flow", "flight"]

prefix = "flower"
Compare with "flow": shrink to "flow" ✓
Compare with "flight": shrink to "fl" ✓

Result: "fl"
```

---

### **Problem 10: Count and Say** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Generate count-and-say sequence."
```
1 → "1"
2 → "11" (one 1)
3 → "21" (two 1s)
4 → "1211" (one 2, one 1)
```

**Template:**
```cpp
string countAndSay(int n) {
    if(n == 1) return "1";
    
    string prev = countAndSay(n - 1);
    string result = "";
    
    int i = 0;
    while(i < prev.length()) {
        char digit = prev[i];
        int count = 0;
        
        // Count consecutive same digits
        while(i < prev.length() && prev[i] == digit) {
            count++;
            i++;
        }
        
        result += to_string(count) + digit;
    }
    
    return result;
}
```

**What to Say:**
> "Sir, I'll build recursively. For each group of consecutive digits, count them and append count + digit. Time O(n * length), Space O(1) excluding recursion."

---

<a name="communication"></a>
##  INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: String = Character Array**

> "Sir, I recognize that strings in C++ are character arrays with helper functions. So I can apply array techniques like two-pointer, iteration, indexing."

---

### **Script 2: Explaining Palindrome**

> "Sir, palindrome means it reads same forward and backward. I'll use two pointers from both ends and compare. Time O(n), Space O(1)."

---

### **Script 3: String Manipulation**

> "Sir, for string manipulation, I have these options:
> 1. Create new string: O(n) space
> 2. In-place with two pointers: O(1) space
> 
> I'll use [choice] because [reason]."

---

<a name="companies"></a>
##  COMPANY-WISE FREQUENCY

### **TCS** ⭐⭐⭐⭐⭐
- Reverse String
- Palindrome Check
- Count Vowels/Consonants
- Remove Spaces
- **Frequency:** 60% of string interviews!

### **Infosys** ⭐⭐⭐⭐⭐
- Palindrome (most common!)
- Reverse Words
- Anagram Check
- String to Integer
- **Frequency:** 65% (VERY HIGH!)

### **Wipro** ⭐⭐⭐⭐
- Valid Palindrome
- Longest Common Prefix
- Reverse String
- Anagram
- **Frequency:** 50%

### **Cognizant** ⭐⭐⭐⭐
- Reverse Words
- Palindrome
- String manipulation
- **Frequency:** 45%

### **Accenture** ⭐⭐⭐⭐⭐
- Very basic operations
- Reverse, Palindrome
- Count characters
- **Frequency:** 55%

---

<a name="mistakes"></a>
## ❌ COMMON MISTAKES

### **Mistake 1: Forgetting null terminator in C-style**
```cpp
// C++ strings don't need it, but char arrays do:
char s[] = "hello";  // Automatically adds '\0'
```

### **Mistake 2: String comparison**
```cpp
// WRONG ❌
if(s1 = s2)  // Assignment, not comparison!

// CORRECT ✅
if(s1 == s2)  // Comparison
```

### **Mistake 3: Index out of bounds**
```cpp
// Always check:
if(i < s.length() && s[i] == 'a') {
    // Safe
}
```

---

## ✅ QUICK TEMPLATES

### **Template 1: Two Pointer (Reverse/Palindrome)**
```cpp
int left = 0, right = s.length() - 1;
while(left < right) {
    // Process
    left++;
    right--;
}
```

### **Template 2: Character Check**
```cpp
if(isalpha(c))  // Letter?
if(isdigit(c))  // Digit?
if(isalnum(c))  // Letter or digit?
char lower = tolower(c);
char upper = toupper(c);
```

### **Template 3: String Building**
```cpp
string result = "";
for(char c : s) {
    if(condition) {
        result += c;
    }
}
```

---

##  FINAL TIPS

**For Service-Based Companies:**
- Master reverse and palindrome (appear in 70%)
- Practice explaining character-by-character
- Know difference between string and char[]
- Handle spaces and special characters

**Golden Rule:**
> "Strings are arrays. All array techniques apply!"

---


**All the best** 
