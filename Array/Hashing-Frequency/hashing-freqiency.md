
# Hashing and Frequency Counting

---

## 1. Concept

**Hashing** is a technique to map data (like numbers, strings) to a fixed-size table (hash table) for fast lookup, insertion, and deletion.  
**Frequency counting** uses hashing to count occurrences of elements efficiently.

- In C++, `unordered_map` and `unordered_set` are commonly used for hashing.
- Time complexity for lookup, insert, and delete is O(1) on average.

---

## 2. Identification of Problem

**When to use Hashing/Frequency Counting?**
- The problem asks for checking existence, counting, or frequency of elements.
- You need to find duplicates, count occurrences, or check if two arrays/strings are anagrams.
- Example keywords: "frequency", "count", "find if exists", "number of occurrences", "most frequent", "anagram", "intersection".

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