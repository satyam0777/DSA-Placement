#  HASHING & FREQUENCY - INTERVIEW READY PACKAGE


---

##  TABLE OF CONTENTS

1. [One-Line Recognition](#recognition)
2. [Map vs Set - When to Use What](#types)
3. [Top 10 Hashing Problems](#problems)
4. [Interview Scripts](#communication)
5. [Company Questions](#companies)

---

<a name="recognition"></a>
##  ONE-LINE RECOGNITION

### **When to Use Hashing?**

**If you see THESE keywords → Use Hashing:**
- "**Frequency**" / "**Count**"
- "**Duplicate**" / "**Unique**"
- "**Find if exists**"
- "**Most frequent**" / "**Least frequent**"
- "**Anagram**"
- "**Intersection**" / "**Union**"
- "**First non-repeating**"
- "In **O(1)** time" (lookup)

**Key Signal:** Counting, checking existence, or finding duplicates

---

<a name="types"></a>
##  MAP vs SET - WHEN TO USE WHAT?

### **Use `unordered_set<T>` When:**
- ✅ Just need to **check existence** (true/false)
- ✅ Find **duplicates**
- ✅ **Unique** elements
- ✅ **Membership** test

**Example:** Contains Duplicate, Two Sum (seen before?)

```cpp
unordered_set<int> seen;
if(seen.count(x)) {
    // x exists!
}
seen.insert(x);
```

---

### **Use `unordered_map<K, V>` When:**
- ✅ Need to **count frequency**
- ✅ Store **key-value** pairs
- ✅ Track **index** or **position**
- ✅ **Most/Least frequent** element

**Example:** Character frequency, Anagram, Majority Element

```cpp
unordered_map<int, int> freq;
freq[x]++;  // Count frequency

for(auto& p : freq) {
    cout << p.first << ": " << p.second;
}
```

---

##  THE GOLDEN RULE

```
Need COUNT/FREQUENCY → unordered_map
Need EXISTENCE CHECK → unordered_set
```

---

<a name="problems"></a>
##  TOP 10 HASHING PROBLEMS

### **Problem 1: Two Sum (Unsorted Array)** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find indices of two numbers that add up to target."

**Template:**
```cpp
vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> seen;  // value → index
    
    for(int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        
        if(seen.count(complement)) {
            return {seen[complement], i};
        }
        
        seen[arr[i]] = i;
    }
    
    return {};  // Not found
}
```

**What to Say:**
> "Sir, I'll use hashmap to store seen numbers with their indices. For each number, check if (target - current) exists in map. If yes, found the pair! Time O(n), Space O(n)."

**Dry Run:**
```
Array: [2, 7, 11, 15], target = 9

i=0: arr[0]=2, complement=9-2=7, not in map, seen={2:0}
i=1: arr[1]=7, complement=9-7=2, FOUND in map! ✅
Return: [0, 1]
```

**Why Hashing Over Two Pointer?**
> **Interviewer:** "Why not two pointer?"

**Your Answer:**
> "Sir, two pointer needs sorted array. Here array is unsorted. Sorting would take O(n log n) but hashing is O(n) - more efficient!"

---

### **Problem 2: Contains Duplicate** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Return true if any value appears at least twice."

**Template:**
```cpp
bool containsDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    
    for(int num : arr) {
        if(seen.count(num)) {
            return true;  // Duplicate found
        }
        seen.insert(num);
    }
    
    return false;  // No duplicates
}
```

**What to Say:**
> "Sir, I'll use set to track seen numbers. For each number, check if already in set. If yes, it's duplicate. Time O(n), Space O(n)."

---

### **Problem 3: Valid Anagram** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Check if two strings are anagrams (same characters, different order)."

**Template (Method 1 - Two Maps):**
```cpp
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    
    unordered_map<char, int> freq1, freq2;
    
    for(char c : s) freq1[c]++;
    for(char c : t) freq2[c]++;
    
    return freq1 == freq2;  // Compare maps
}
```

**Template (Method 2 - Single Map):**
```cpp
bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    
    unordered_map<char, int> freq;
    
    for(char c : s) freq[c]++;
    for(char c : t) freq[c]--;
    
    for(auto& p : freq) {
        if(p.second != 0) return false;
    }
    
    return true;
}
```

**What to Say:**
> "Sir, I'll count character frequencies in both strings. If frequencies match, they're anagrams. Can use two maps or single map (increment for s, decrement for t). Time O(n), Space O(26) = O(1)."

---

### **Problem 4: First Unique Character** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find first non-repeating character in string."

**Template:**
```cpp
int firstUniqChar(string s) {
    unordered_map<char, int> freq;
    
    // Count frequencies
    for(char c : s) {
        freq[c]++;
    }
    
    // Find first with frequency 1
    for(int i = 0; i < s.size(); i++) {
        if(freq[s[i]] == 1) {
            return i;
        }
    }
    
    return -1;  // All repeating
}
```

**What to Say:**
> "Sir, two-pass solution. First pass counts all character frequencies. Second pass finds first character with frequency 1. Time O(n), Space O(26) = O(1)."

---

### **Problem 5: Group Anagrams** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Group strings that are anagrams together."

**Template:**
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    
    for(string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());  // Sorted string as key
        groups[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for(auto& p : groups) {
        result.push_back(p.second);
    }
    
    return result;
}
```

**What to Say:**
> "Sir, I'll use sorted string as key. All anagrams have same sorted form. Store original strings under their sorted key. Time O(n * k log k) where k is max string length, Space O(n*k)."

**Alternative (Frequency as Key):**
```cpp
string getKey(string& s) {
    int count[26] = {0};
    for(char c : s) count[c - 'a']++;
    
    string key = "";
    for(int i = 0; i < 26; i++) {
        key += to_string(count[i]) + "#";
    }
    return key;
}
```

---

### **Problem 6: Majority Element (>n/2 times)** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find element appearing more than n/2 times."

**Template (Hashing):**
```cpp
int majorityElement(vector<int>& arr) {
    unordered_map<int, int> freq;
    int n = arr.size();
    
    for(int num : arr) {
        freq[num]++;
        if(freq[num] > n/2) {
            return num;  // Found!
        }
    }
    
    return -1;  // Not found
}
```

**What to Say:**
> "Sir, I'll count frequencies using hashmap. When any element's count exceeds n/2, that's our answer. Time O(n), Space O(n)."

**Follow-up:**
> **Interviewer:** "Can you do in O(1) space?"

**Your Answer:**
> "Yes sir! Boyer-Moore Voting Algorithm. I maintain a candidate and count. When count becomes 0, change candidate."

```cpp
int majorityElement(vector<int>& arr) {
    int candidate = 0, count = 0;
    
    for(int num : arr) {
        if(count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    
    return candidate;  // Guaranteed to exist
}
```

---

### **Problem 7: Longest Consecutive Sequence** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find length of longest consecutive elements sequence (unsorted array)."

**Template:**
```cpp
int longestConsecutive(vector<int>& arr) {
    unordered_set<int> numSet(arr.begin(), arr.end());
    int maxLen = 0;
    
    for(int num : numSet) {
        // Check if it's start of sequence
        if(!numSet.count(num - 1)) {
            int currentNum = num;
            int currentLen = 1;
            
            // Count consecutive numbers
            while(numSet.count(currentNum + 1)) {
                currentNum++;
                currentLen++;
            }
            
            maxLen = max(maxLen, currentLen);
        }
    }
    
    return maxLen;
}
```

**What to Say:**
> "Sir, I'll use set for O(1) lookup. For each number, check if it's start of sequence (num-1 doesn't exist). If yes, count how many consecutive numbers exist. Time O(n), Space O(n)."

**Dry Run:**
```
Array: [100, 4, 200, 1, 3, 2]
Set: {100, 4, 200, 1, 3, 2}

Check 100: 99 doesn't exist, start! 100→101 (not exist), len=1
Check 4: 3 exists, not start, skip
Check 200: 199 doesn't exist, start! 200→201 (not exist), len=1
Check 1: 0 doesn't exist, start! 1→2→3→4→5 (not exist), len=4 ✅
Check 3: 2 exists, not start, skip
Check 2: 1 exists, not start, skip

Answer: 4 (sequence: 1,2,3,4)
```

---

### **Problem 8: Intersection of Two Arrays** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find common elements in two arrays."

**Template (Unique elements):**
```cpp
vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> result;
    
    for(int num : arr2) {
        if(set1.count(num)) {
            result.insert(num);
        }
    }
    
    return vector<int>(result.begin(), result.end());
}
```

**Template (With duplicates):**
```cpp
vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    
    for(int num : arr1) freq[num]++;
    
    vector<int> result;
    for(int num : arr2) {
        if(freq[num] > 0) {
            result.push_back(num);
            freq[num]--;
        }
    }
    
    return result;
}
```

**What to Say:**
> "Sir, for unique intersection, use set. For intersection with duplicates, use map to track frequencies. Time O(m+n), Space O(min(m,n))."

---

### **Problem 9: Top K Frequent Elements** ⭐⭐⭐⭐

**What Interviewer Asks:**
> "Find k most frequent elements."

**Template:**
```cpp
vector<int> topKFrequent(vector<int>& arr, int k) {
    // Count frequencies
    unordered_map<int, int> freq;
    for(int num : arr) freq[num]++;
    
    // Use bucket sort by frequency
    vector<vector<int>> buckets(arr.size() + 1);
    for(auto& p : freq) {
        buckets[p.second].push_back(p.first);
    }
    
    // Collect top k
    vector<int> result;
    for(int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
        for(int num : buckets[i]) {
            result.push_back(num);
            if(result.size() == k) break;
        }
    }
    
    return result;
}
```

**What to Say:**
> "Sir, first count frequencies using map. Then use bucket sort - index represents frequency. Collect from highest frequency bucket. Time O(n), Space O(n)."

**Alternative (Heap):**
```cpp
// Using priority queue: O(n log k)
```

---

### **Problem 10: Subarray Sum Equals K** ⭐⭐⭐⭐⭐

**What Interviewer Asks:**
> "Count subarrays with sum equal to k."

**Template (Prefix Sum + Hashing):**
```cpp
int subarraySum(vector<int>& arr, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    
    int prefixSum = 0, count = 0;
    
    for(int num : arr) {
        prefixSum += num;
        
        // Check if (prefixSum - k) exists
        if(prefixCount.count(prefixSum - k)) {
            count += prefixCount[prefixSum - k];
        }
        
        prefixCount[prefixSum]++;
    }
    
    return count;
}
```

**What to Say:**
> "Sir, this combines prefix sum with hashing. I track how many times each prefix sum appeared. If (currentPrefix - k) exists, those many subarrays sum to k. Time O(n), Space O(n)."

---

<a name="communication"></a>
## 🗣️ INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Recognition**

> "Sir, I recognize hashing pattern because:
> 1. Need to count/check frequency/existence
> 2. Need O(1) lookup
> 3. Looking for duplicates/unique elements
> 
> Hashing is perfect for this - O(n) time!"

---

### **Script 2: Map vs Set Choice**

> "Sir, I'll use:
> - **unordered_set** if just checking existence
> - **unordered_map** if counting frequency
> 
> In this problem, [explain choice and why]"

---

### **Script 3: Time Complexity**

> "Sir, hashing operations (insert, search, delete):
> - Average case: O(1)
> - Worst case: O(n) (rare, all collisions)
> - For this problem: O(n) total time with O(n) space"

---

### **Script 4: Space Optimization**

> **If asked:** "Can you optimize space?"

**Your Answer:**
> "Sir, hashing needs O(n) space in worst case. For specific problems like majority element, can use Boyer-Moore for O(1) space. But generally, hashing trades space for time."

---

<a name="companies"></a>
##  COMPANY-WISE FREQUENCY

### **TCS** ⭐⭐⭐⭐⭐
1. Two Sum
2. Contains Duplicate
3. Valid Anagram
4. First Unique Character
5. Frequency counting
- **Frequency:** 50% of interviews! (VERY HIGH)

---

### **Wipro** ⭐⭐⭐⭐⭐
1. Majority Element
2. Group Anagrams
3. Intersection of Arrays
4. Top K Frequent
5. Longest Consecutive
- **Frequency:** 45%

---

### **Infosys** ⭐⭐⭐⭐⭐
1. Contains Duplicate (most common!)
2. Two Sum
3. Valid Anagram
4. First Unique Character
5. Simple frequency
- **Frequency:** 55% (HIGHEST!)

---

### **Cognizant** ⭐⭐⭐⭐
1. Two Sum
2. Subarray Sum K
3. Longest Consecutive
4. Group Anagrams
5. Majority Element
- **Frequency:** 40%

---

### **Capgemini** ⭐⭐⭐⭐
1. Frequency counting
2. Contains Duplicate
3. Two Sum
4. Anagram check
5. Intersection
- **Frequency:** 35%

---

### **Accenture** ⭐⭐⭐⭐⭐
1. Contains Duplicate
2. Two Sum (basic)
3. Frequency count
4. First unique
5. Simple hashing
- **Frequency:** 45%

---

##  QUICK TEMPLATES

### **Template 1: Frequency Counting**
```cpp
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;

// Find max frequency
int maxFreq = 0, element = -1;
for(auto& p : freq) {
    if(p.second > maxFreq) {
        maxFreq = p.second;
        element = p.first;
    }
}
```

### **Template 2: Check Existence**
```cpp
unordered_set<int> seen;
for(int x : arr) {
    if(seen.count(x)) {
        // Duplicate found
    }
    seen.insert(x);
}
```

### **Template 3: Two Sum Pattern**
```cpp
unordered_map<int, int> seen;
for(int i = 0; i < n; i++) {
    int complement = target - arr[i];
    if(seen.count(complement)) {
        // Found pair
    }
    seen[arr[i]] = i;
}
```

### **Template 4: Anagram Check**
```cpp
unordered_map<char, int> freq;
for(char c : s1) freq[c]++;
for(char c : s2) freq[c]--;

bool isAnagram = true;
for(auto& p : freq) {
    if(p.second != 0) isAnagram = false;
}
```

---

## ❌ COMMON MISTAKES

### **Mistake 1: Confusing map and set**
```cpp
// WRONG ❌ - Using map when set is enough
unordered_map<int, bool> seen;  // Wastes space

// CORRECT ✅
unordered_set<int> seen;  // Perfect
```

---

### **Mistake 2: Not Checking Before Access**
```cpp
// WRONG ❌
if(map[key] > 0) {  // Creates entry if not exists!
}

// CORRECT ✅
if(map.count(key) && map[key] > 0) {
}
```

---

### **Mistake 3: Forgetting Empty Check**
```cpp
// Always check:
if(arr.empty()) return ...;
```

---

##  CONFIDENCE BOOSTERS

**Hashing:**
- ✅ Appears in 40-55% of service-based interviews (HIGHEST!)
- ✅ Very intuitive and easy to code
- ✅ O(1) average lookup - super efficient
- ✅ Just TWO data structures: map and set
- ✅ Solves SO many problems!

---

## FINAL TIPS

### **Quick Decision Tree:**
```
Need to COUNT? → unordered_map
Need to CHECK EXISTS? → unordered_set
Need KEY-VALUE? → unordered_map
Need UNIQUE ONLY? → unordered_set
```

### **Golden Patterns:**
```
Frequency → map[x]++
Duplicate → if(set.count(x))
Two Sum → if(map.count(target - x))
Anagram → compare frequency maps
```





---

*Remember: Hashing is the MOST ASKED pattern - master this, you're 50% ready!*

**All the best** 
