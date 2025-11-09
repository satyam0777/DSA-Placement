#  HASHING & FREQUENCY - COMPLETE SERIES 

---

## 📖 TABLE OF CONTENTS

1. [🎬 Video 1: Introduction - What is Hashing?](#video1)
2. [🔍 Video 2: Identification - When to Use Hashing?](#video2)
3. [🎨 Video 3: The Core Concept - Map vs Set](#video3)
4. [📝 Video 4: Generic Templates (Muscle Memory)](#video4)
5. [🎯 Video 5: Problem 1 - Two Sum](#problem1)
6. [🎯 Video 6: Problem 2 - Group Anagrams](#problem2)
7. [🎯 Video 7: Problem 3 - Longest Consecutive Sequence](#problem3)
8. [🎯 Video 8: Problem 4 - Top K Frequent Elements](#problem4)
9. [🎯 Video 9: Problem 5 - Subarray Sum Equals K](#problem5)
10. [📋 Quick Reference Sheet](#reference)
11. [🎓 7-Day Learning Path](#learning)

---

<a name="video1"></a>
## 🎬 VIDEO 1: INTRODUCTION - WHAT IS HASHING?

### **What is Hashing?**

**Hashing** is a technique to store and retrieve data in **O(1) average time** using a hash function that maps keys to indices.

```
Problem: Find if 42 exists in array [1, 5, 42, 17, 9]

Brute Force: Check each element → O(n)
Array: [1] → [5] → [42] ✅ (found after 3 checks)

With Hashing: Insert all to set, check → O(1)
Set: {1, 5, 42, 17, 9}
Check 42? → INSTANT! ✅
```

**In C++:**
- `unordered_map<K, V>` - stores key-value pairs
- `unordered_set<T>` - stores unique elements

---

### **Why Use Hashing?**

**Time Complexity Comparison:**
```
Operation         | Array | Hashing
─────────────────────────────────────
Search           | O(n)  | O(1) ✅
Insert           | O(1)  | O(1) ✅
Delete           | O(n)  | O(1) ✅
Count Frequency  | O(n²) | O(n) ✅
```

---

### **The Big Idea:**

> **"Trade space for speed - use memory to get O(1) access!"**

```
Key Insight:
─────────────────────────────────────────
Instead of searching linearly (O(n)),
store data in hash table for instant lookup (O(1))!

Hash Function: key → index (in constant time)
─────────────────────────────────────────
```

---

<a name="video2"></a>
## 🔍 VIDEO 2: IDENTIFICATION - WHEN TO USE HASHING?

### **🎯 3 Signs to Recognize Hashing:**

1. **Need O(1) lookup/insert/delete** - Fast access required
2. **Counting/Frequency problems** - Track occurrences
3. **Existence checks** - "Does X exist?" questions

---

### **🔑 Magic Keywords:**

| Keyword in Problem | Think This |
|-------------------|------------|
| "**Frequency**" / "**Count**" | ✅ HASHMAP |
| "**Duplicate**" / "**Unique**" | ✅ HASHSET |
| "**Find if exists**" | ✅ HASHSET |
| "**Most frequent**" | ✅ HASHMAP + frequency |
| "**Anagram**" | ✅ HASHMAP (char count) |
| "**Intersection**" / "**Union**" | ✅ HASHSET |
| "**First non-repeating**" | ✅ HASHMAP + scan |
| "**Two elements with sum**" | ✅ HASHSET/MAP |
| "In O(1) time" | ✅ HASHING! |

---

### **❓ Questions to Ask Yourself:**

1. **Do I need to count something?** → HashMap!
2. **Just checking if exists?** → HashSet!
3. **Need to store pairs?** → HashMap!
4. **Find duplicates?** → HashSet!

---

### **🎨 Pattern vs Other Techniques:**

| Pattern | When to Use | Key Difference |
|---------|------------|----------------|
| **Hashing** | Count, existence, O(1) lookup | Space for speed trade-off |
| **Two Pointer** | Sorted array, find pairs | No extra space, O(n) |
| **Sliding Window** | Subarray with condition | Window maintenance |
| **Prefix Sum** | Range queries | Preprocessing for queries |

---

<a name="video3"></a>
## 🎨 VIDEO 3: THE CORE CONCEPT - MAP vs SET

### **The Golden Rule:**

```
╔═══════════════════════════════════════════╗
║  Need to COUNT? → unordered_map           ║
║  Need to CHECK EXISTS? → unordered_set    ║
╚═══════════════════════════════════════════╝
```

---

### **unordered_set<T> - For Existence Checks**

```cpp
unordered_set<int> seen;

// Insert
seen.insert(5);

// Check existence
if (seen.count(5)) {  // Returns 1 if exists, 0 if not
    cout << "5 exists!";
}

// Delete
seen.erase(5);

// Size
int size = seen.size();
```

**Use When:**
- ✅ Finding duplicates
- ✅ Checking membership
- ✅ Storing unique elements
- ✅ Simple existence checks

**Visual:**
```
Set: {1, 5, 9, 17}
         ↓
Just stores elements (no values)
O(1) to check if element exists
```

---

### **unordered_map<K, V> - For Key-Value Pairs**

```cpp
unordered_map<int, int> freq;

// Count frequency
freq[5]++;  // Increments frequency of 5

// Access
int count = freq[5];  // Get frequency

// Check if key exists
if (freq.count(5)) {
    // Key 5 exists
}

// Iterate
for (auto& pair : freq) {
    cout << pair.first << ": " << pair.second;
}
```

**Use When:**
- ✅ Counting frequencies
- ✅ Storing value with key
- ✅ Tracking indices/positions
- ✅ Most/least frequent element

**Visual:**
```
Map: {5 → 3, 9 → 1, 17 → 2}
      ↓    ↓   ↓    ↓  ↓    ↓
     key value pairs
     
5 appears 3 times
9 appears 1 time
17 appears 2 times
```

---

### **Visual Comparison:**

```
HASHSET (Existence Only):
──────────────────────────
{42, 17, 5, 99}
"Does 42 exist?" → YES ✅
"Does 100 exist?" → NO ❌

HASHMAP (Count/Value):
──────────────────────────
{42→2, 17→1, 5→3, 99→1}
"How many times 42?" → 2
"How many times 5?" → 3
```

---

<a name="video4"></a>
## 📝 VIDEO 4: GENERIC TEMPLATES (MUSCLE MEMORY)

### **✍️ TEMPLATE 1: FREQUENCY COUNTING**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
unordered_map<int, int> countFrequency(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    // Count each element
    for (int x : arr) {
        freq[x]++;
    }
    
    return freq;
}

// Find most frequent element
int mostFrequent(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;
    
    int maxFreq = 0, result = -1;
    for (auto& p : freq) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
            result = p.first;
        }
    }
    
    return result;
}
```

**Time:** O(n) | **Space:** O(n)

---

### **✍️ TEMPLATE 2: CHECK DUPLICATES**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
bool containsDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    
    for (int x : arr) {
        if (seen.count(x)) {
            return true;  // Duplicate found
        }
        seen.insert(x);
    }
    
    return false;  // No duplicates
}
```

**Time:** O(n) | **Space:** O(n)

---

### **✍️ TEMPLATE 3: TWO SUM PATTERN**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> seen;  // value → index
    
    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        
        if (seen.count(complement)) {
            return {seen[complement], i};
        }
        
        seen[arr[i]] = i;
    }
    
    return {};
}
```

**Time:** O(n) | **Space:** O(n)

---

### **✍️ TEMPLATE 4: ANAGRAM CHECK**

```cpp
// MEMORIZE THIS EXACT STRUCTURE!
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    
    unordered_map<char, int> freq;
    
    // Increment for s, decrement for t
    for (char c : s) freq[c]++;
    for (char c : t) freq[c]--;
    
    // Check if all frequencies are 0
    for (auto& p : freq) {
        if (p.second != 0) return false;
    }
    
    return true;
}
```

**Time:** O(n) | **Space:** O(26) = O(1)

---

### **✍️ TEMPLATE 5: INTERSECTION/UNION**

```cpp
// Intersection (unique elements)
vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> result;
    
    for (int x : arr2) {
        if (set1.count(x)) {
            result.insert(x);
        }
    }
    
    return vector<int>(result.begin(), result.end());
}

// Union
vector<int> unionArrays(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> resultSet;
    
    for (int x : arr1) resultSet.insert(x);
    for (int x : arr2) resultSet.insert(x);
    
    return vector<int>(resultSet.begin(), resultSet.end());
}
```

**Time:** O(m + n) | **Space:** O(m + n)

---

### **🔥 Mantras (Say 10 times!):**

**"Count frequency? Use MAP!"**

**"Check exists? Use SET!"**

**"Two Sum? Store complement in map!"**

**"Anagram? Compare frequencies!"**

---

### **💡 Memory Hooks:**

**Hook 1: The Dictionary 📖**
- **HashMap** = Dictionary (word → definition)
- Store key-value pairs
- O(1) to look up any word!

**Hook 2: The Attendance Register 📝**
- **HashSet** = Name list for attendance
- Just mark present/absent
- O(1) to check if someone present!

**Hook 3: The Counter 🔢**
- **Frequency Map** = Tally marks
- Each element gets its own count
- freq[x]++ = Add one tally mark!

---

**Typical Problem Statements:**
- Find the element that appears most frequently.
- Check if two strings are anagrams.
- Find all elements that appear more than n/2 times (majority element).
- Find intersection/union of two arrays.

---

## 3. Approaches

### a. Frequency Counting with Hash Map

- Use `unordered_map` to store element as key and its count as value.

**Example:**  
Count frequency of each element in an array.

**Code:**
```cpp
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;
// freq[x] gives the count of x
```

---

### b. Check for Duplicates

- Use `unordered_set` to check if an element has appeared before.

**Code:**
```cpp
unordered_set<int> seen;
for(int x : arr) {
    if(seen.count(x)) {
        // Duplicate found
    }
    seen.insert(x);
}
```

---

### c. Most Frequent Element

- After counting frequencies, iterate to find the element with the highest count.

**Code:**
```cpp
int maxFreq = 0, ans = -1;
for(auto& p : freq) {
    if(p.second > maxFreq) {
        maxFreq = p.second;
        ans = p.first;
    }
}
```

---

### d. Anagram Check (Strings)

- Count frequency of each character in both strings and compare.

**Code:**
```cpp
unordered_map<char, int> freq1, freq2;
for(char c : s1) freq1[c]++;
for(char c : s2) freq2[c]++;
if(freq1 == freq2) {
    // Strings are anagrams
}
```

---

### e. Intersection of Two Arrays

- Use a set or map to store elements of one array, then check for matches in the other.

**Code:**
```cpp
unordered_set<int> s(arr1.begin(), arr1.end());
vector<int> intersection;
for(int x : arr2) {
    if(s.count(x)) intersection.push_back(x);
}
```

---

## 4. When to Use

- When you need fast existence checks or frequency counts.
- When the problem involves counting, grouping, or matching elements.
- When brute force would be too slow (O(n²)), hashing can reduce to O(n).

---

**Summary:**  
Hashing and frequency counting are essential for efficient problem solving in arrays and strings. Use `unordered_map` for counting and `unordered_set` for existence checks.

---