# 🔍 Advanced & Miscellaneous String Concepts (Not Covered in Pattern-Based Guide)

> This document contains **important string concepts** and edge cases that were **not covered in the 8-pattern-based string guide** 

---

## Table of Contents

1. [String Interning](#1-string-interning)
2. [String Matching Algorithms](#2-string-matching-algorithms)
3. [Character Encoding](#3-character-encoding)
4. [Mutable vs Immutable Strings](#4-mutable-vs-immutable-strings)
5. [String vs Char Array](#5-string-vs-char-array)
6. [Trie (Prefix Tree) Basics](#6-trie-prefix-tree-basics)
7. [Manacher’s Algorithm (Longest Palindromic Substring)](#7-manachers-algorithm-longest-palindromic-substring)
8. [String Compression and Encoding](#8-string-compression-and-encoding)
9. [Common STL Functions for Strings](#9-common-stl-functions-for-strings)

---

## 1. String Interning

###  What is it?
String interning is a technique where identical strings are stored only once in memory to save space and allow faster comparisons. It maintains a **pool of strings**.

###  Why important?
- Saves memory
- Speeds up string comparison using reference equality

###  Real World Use:
- Python: `sys.intern()`
- Java: `String.intern()`
- Not used much in C++ as `std::string` does not use interning by default

###  When to Think About It:
- Problems involving lots of duplicate string instances
- Implementing custom memory-optimized data storage

---

## 2.  String Matching Algorithms

### A. Naive Matching:
Compare every substring of text `T` with pattern `P`. O(n*m)

### B.  KMP (Knuth-Morris-Pratt):
- Avoid redundant comparisons using a prefix table.
**learn Tushar roy sir youtube**
- Build `lps[]` (Longest Prefix Suffix)
- Use it to skip matching from the start

```cpp
void computeLPS(string pat, vector<int>& lps) {
    int len = 0;
    for (int i = 1; i < pat.length(); ) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
}
```

### C.  Rabin-Karp:
- Uses rolling hash to compare substrings
- Fast average case for multiple pattern matches

➡️ Use KMP when pattern is fixed.  
➡️ Use Rabin-Karp when matching multiple patterns.

---

## 3.  Character Encoding

### What is it?
A system that maps characters to binary values.

### Common Encodings:
- ASCII (0–127): Basic Latin characters
- Extended ASCII (0–255): Adds symbols, accents
- Unicode (UTF-8, UTF-16): Supports every language

###  In C++:
- `std::string` = sequence of bytes
- `char` = 1 byte (ASCII)
- For Unicode, use libraries (e.g., ICU, `wstring` for wide chars)

###  When to Think About It:
- Problems involving emojis, multi-language strings
- Character counts mismatch due to encoding

---

## 4.  Mutable vs Immutable Strings

### In Java/Python:
- `String` is **immutable**: once created, cannot change
- `StringBuilder`, `StringBuffer` used for changes

### In C++:
- `std::string` is **mutable**:
```cpp
string s = "hello";
s[0] = 'H';
```

### Why Important?
- Immutable strings are **thread-safe**
- Mutable strings are **efficient for edits** (no need to create new string)

**Use `string` for light edits**  
**Use `char[]` or `stringstream` for heavy edits**

---

## 5.  String vs Char Array

| Feature          | `string` (C++)        | `char[]` (C-style)         |
|------------------|------------------------|----------------------------|
| Null-terminated? | No                     | Yes                        |
| Easy to use?     | Yes (has methods)      | No (manual memory, loops)  |
| Mutable?         | Yes                    | Yes                        |
| Functions        | `.substr`, `.find()`   | Manual logic               |

### When to Use Which?
- Use `string` for almost everything
- Use `char[]` only if working with legacy C functions or performance-critical space

### Conversion:
```cpp
string s = "hello";
const char* c = s.c_str();
```

---

## 6.  Trie (Prefix Tree) Basics

### What is Trie?
- A tree where each node represents a character
- Children of node = next characters
- Root to leaf = complete string

### Structure:
```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
};
```

### Uses:
- Word dictionary
- Prefix search
- Autocomplete engines (Google Search, IDEs)

### Problem Examples:
- Implement Trie (LeetCode 208)
- Search Suggestions System (LeetCode 1268)

 - Build when you need fast prefix search or insertions

---

## 7.  Manacher’s Algorithm

### Problem:
Find longest palindromic substring in **O(n)** time

### Why Not Expand Center (Brute Force)?
- That’s O(n²)
- Repeats a lot of comparisons

### Idea:
- Transform string: insert `#` between characters
- Use center + mirror symmetry + dynamic expansion

```cpp
// Core idea only, implementation needs proper transformation
```

 **Use only if:**
- Asked to solve **palindromic substring** in O(n)
- Usually in advanced interviews (Google, Meta)

---

## 8.  String Compression and Encoding

### A. Run-Length Encoding
Compress repeated characters:
```cpp
string compress(string s) {
    string result = "";
    for (int i = 0; i < s.length(); ) {
        char c = s[i];
        int count = 0;
        while (i < s.length() && s[i] == c) {
            count++, i++;
        }
        result += c + to_string(count);
    }
    return result;
}
```

### B. Base64 Encoding
Encodes binary data as ASCII text.

 Useful for:
- Image upload
- JWT tokens
- Emails

- Use libraries like `OpenSSL`, or online tools.

---

## 9.  Common STL Functions for Strings (C++)

| Function                | Description                          | Example                    |
|-------------------------|--------------------------------------|----------------------------|
| `s.length()`            | Returns length of string             | `s.length()`               |
| `s.substr(i, len)`      | Get substring from index `i`         | `s.substr(1, 3)`           |
| `s.find("ab")`         | Returns index of substring           | `s.find("lo")`            |
| `s.erase(i, len)`       | Removes part of string               | `s.erase(1, 2)`            |
| `s.insert(i, "abc")`   | Insert string at index `i`           | `s.insert(2, "xy")`       |
| `s.replace(i, len, x)`  | Replace substring                    | `s.replace(1, 2, "zz")`   |
| `reverse(...)`          | Reverses characters                  | `reverse(s.begin(), s.end())` |
| `toupper(s[i])`         | Uppercase conversion (include `<cctype>`) | `toupper(s[0])`     |



---



