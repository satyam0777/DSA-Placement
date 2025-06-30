
# Hashing & Frequency: Problem Varieties and Cross-Concept Usage

---

## 1. Find the First Non-Repeating Character in a String

**Concept:**  
Use a hash map to count character frequencies, then scan to find the first with count 1.

**Code:**
```cpp
unordered_map<char, int> freq;
for(char c : s) freq[c]++;
for(char c : s) {
    if(freq[c] == 1) return c;
}
```

---

## 2. Majority Element (> n/2 times)

**Concept:**  
Count frequencies and check if any element appears more than n/2 times.

**Code:**
```cpp
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;
for(auto& p : freq) {
    if(p.second > arr.size()/2) return p.first;
}
```

---

## 3. Two Sum Problem

**Concept:**  
Use a hash map to check if `target - arr[i]` exists as you iterate.

**Code:**
```cpp
unordered_map<int, int> mp;
for(int i = 0; i < arr.size(); i++) {
    if(mp.count(target - arr[i])) {
        // Pair found: arr[i], target - arr[i]
    }
    mp[arr[i]] = i;
}
```

---

## 4. Longest Consecutive Sequence

**Concept:**  
Use a set for O(1) lookups and build sequences.

**Code:**
```cpp
unordered_set<int> s(arr.begin(), arr.end());
int longest = 0;
for(int x : arr) {
    if(!s.count(x-1)) {
        int y = x;
        while(s.count(y)) y++;
        longest = max(longest, y - x);
    }
}
```

---

## 5. Group Anagrams

**Concept:**  
Use a hash map with sorted string as key.

**Code:**
```cpp
unordered_map<string, vector<string>> groups;
for(string& word : words) {
    string key = word;
    sort(key.begin(), key.end());
    groups[key].push_back(word);
}
```

---

## 6. Subarray Sum Equals K (Prefix Sum + Hashing)

**Concept:**  
Combine prefix sum and hash map to count subarrays with sum k.

**Code:**
```cpp
unordered_map<int, int> mp;
mp[0] = 1;
int sum = 0, count = 0;
for(int x : arr) {
    sum += x;
    if(mp.count(sum - k)) count += mp[sum - k];
    mp[sum]++;
}
```

---

## 7. Sliding Window + Hashing

**Concept:**  
Use a hash map to track frequencies in a window (e.g., longest substring with k distinct characters).

**Code:**
```cpp
unordered_map<char, int> freq;
int left = 0, maxLen = 0;
for(int right = 0; right < s.size(); right++) {
    freq[s[right]]++;
    while(freq.size() > k) {
        freq[s[left]]--;
        if(freq[s[left]] == 0) freq.erase(s[left]);
        left++;
    }
    maxLen = max(maxLen, right - left + 1);
}
```

---

## 8. Hashing in Graphs

**Concept:**  
Use hash maps/sets to store adjacency lists, visited nodes, or edge weights for fast lookup.

---

## 9. Hashing for Frequency in 2D Arrays

**Concept:**  
Count frequency of elements or pairs in a matrix using a hash map.

---

## 10. Hashing for Custom Objects

**Concept:**  
Define custom hash functions for complex keys (like pairs or tuples).

---

**Summary:**  
Hashing and frequency counting are not just for simple lookups—they combine powerfully with prefix sums, sliding windows, and even graph algorithms.  
Whenever you need fast existence checks, counting, or grouping, think of hashing!

---