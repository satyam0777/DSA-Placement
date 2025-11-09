# 🎯 HASHING & FREQUENCY - COMPLETE PROBLEMS (5-STEP METHOD)


---

## 📋 TABLE OF CONTENTS

1. [Problem 1: Two Sum](#problem1)
2. [Problem 2: Group Anagrams](#problem2)
3. [Problem 3: Longest Consecutive Sequence](#problem3)
4. [Problem 4: Top K Frequent Elements](#problem4)
5. [Problem 5: Subarray Sum Equals K](#problem5)
6. [Quick Reference Sheet](#reference)

---

<a name="problem1"></a>
## 🎯 PROBLEM 1: TWO SUM

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an array of integers and a target sum, find two numbers that add up to the target. Return their indices.

**Input:**
```
arr = [2, 7, 11, 15]
target = 9
```

**Output:**
```
[0, 1]
```

**Explanation:**  
arr[0] + arr[1] = 2 + 7 = 9

**Constraints:**
- Each input has exactly one solution
- Cannot use same element twice
- 2 ≤ n ≤ 10^4

---

### **2️⃣ IDENTIFICATION**

**How do you know it's HASHING?**

✅ **Sign 1:** Need to find pair with given sum  
✅ **Sign 2:** Array is unsorted  
✅ **Sign 3:** Need better than O(n²)

**Magic Keywords:**
- "Two numbers that add up to..."
- "Find pair with sum..."
- "Unsorted array"

**Why NOT Two Pointer?**
- Two pointer needs sorted array
- Sorting would take O(n log n)
- Hashing is O(n) - better!

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Brute Force:
────────────────────────────────────
for i = 0 to n:
    for j = i+1 to n:
        if arr[i] + arr[j] == target:
            return [i, j]

Time: O(n²) ❌

Optimal (Hashing):
────────────────────────────────────
Key Insight: If arr[i] + arr[j] = target
           Then arr[j] = target - arr[i]

Strategy:
1. Use HashMap to store seen numbers with indices
2. For each number, check if (target - current) exists
3. If yes, found the pair!
4. If no, store current number and continue

Time: O(n) ✅
Space: O(n)
```

---

### **4️⃣ DRY RUN**

**Array:** `[2, 7, 11, 15]`, **target = 9**

```
Initialize:
───────────
seen = {}  (empty map)

i=0: arr[0]=2
───────────
complement = 9 - 2 = 7
Is 7 in seen? NO
seen[2] = 0 → seen = {2→0}

i=1: arr[1]=7
───────────
complement = 9 - 7 = 2
Is 2 in seen? YES! ✅
seen[2] = 0
Return: [0, 1]

Answer: [0, 1] (indices of 2 and 7)
```

**Visualization:**
```
Step 1: See 2, store {2→0}
Step 2: See 7, need 2, FOUND in map!
        Index of 2 is 0, current index is 1
        Return [0, 1] ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> seen;  // value → index
        
        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];
            
            // Check if complement exists
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            
            // Store current number with its index
            seen[arr[i]] = i;
        }
        
        return {};  // No solution found
    }
};
```

**Complexity:**
- **Time:** O(n) - single pass
- **Space:** O(n) - hashmap storage

---

<a name="problem2"></a>
## 🎯 PROBLEM 2: GROUP ANAGRAMS

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an array of strings, group the anagrams together. Anagrams are words with same characters in different order.

**Input:**
```
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
```

**Output:**
```
[
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
]
```

**Explanation:**  
- "eat", "tea", "ate" are anagrams (same letters)
- "tan", "nat" are anagrams
- "bat" is alone

---

### **2️⃣ IDENTIFICATION**

**How do you know it's HASHING?**

✅ **Sign 1:** Need to group similar elements  
✅ **Sign 2:** Anagrams have same character frequency  
✅ **Sign 3:** Need to use string as key

**Magic Keywords:**
- "Group anagrams"
- "Same characters"
- "Group together"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Key Insight:
────────────────────────────────────
All anagrams have the SAME sorted form!
"eat" sorted → "aet"
"tea" sorted → "aet"
"ate" sorted → "aet"

Strategy:
────────────────────────────────────
1. Use HashMap with sorted string as KEY
2. For each word:
   - Sort it to get key
   - Add original word to that key's group
3. Return all groups

Time: O(n × k log k) where k = max string length
Space: O(n × k)
```

---

### **4️⃣ DRY RUN**

**Input:** `["eat", "tea", "tan", "ate", "nat", "bat"]`

```
Initialize:
───────────
groups = {}

Process "eat":
───────────
sorted = "aet"
groups["aet"] = ["eat"]
groups = {"aet" → ["eat"]}

Process "tea":
───────────
sorted = "aet"
groups["aet"] = ["eat", "tea"]
groups = {"aet" → ["eat", "tea"]}

Process "tan":
───────────
sorted = "ant"
groups["ant"] = ["tan"]
groups = {"aet" → ["eat", "tea"], "ant" → ["tan"]}

Process "ate":
───────────
sorted = "aet"
groups["aet"] = ["eat", "tea", "ate"]

Process "nat":
───────────
sorted = "ant"
groups["ant"] = ["tan", "nat"]

Process "bat":
───────────
sorted = "abt"
groups["abt"] = ["bat"]

Final:
groups = {
  "aet" → ["eat", "tea", "ate"],
  "ant" → ["tan", "nat"],
  "abt" → ["bat"]
}

Extract all groups → Answer ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string& s : strs) {
            // Sort string to get key
            string key = s;
            sort(key.begin(), key.end());
            
            // Add original string to this key's group
            groups[key].push_back(s);
        }
        
        // Extract all groups
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
```

**Complexity:**
- **Time:** O(n × k log k) - n strings, each sorted (k log k)
- **Space:** O(n × k) - storing all strings

**Alternative (Frequency as Key):**
```cpp
string getKey(string& s) {
    int count[26] = {0};
    for (char c : s) count[c - 'a']++;
    
    string key = "";
    for (int i = 0; i < 26; i++) {
        key += to_string(count[i]) + "#";
    }
    return key;
}
// Time: O(n × k) - better!
```

---

<a name="problem3"></a>
## 🎯 PROBLEM 3: LONGEST CONSECUTIVE SEQUENCE

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an unsorted array, find the length of the longest consecutive elements sequence.

**Input:**
```
arr = [100, 4, 200, 1, 3, 2]
```

**Output:**
```
4
```

**Explanation:**  
Longest consecutive sequence: [1, 2, 3, 4]  
Length = 4

**Constraints:**
- Must be O(n) time
- Array is unsorted

---

### **2️⃣ IDENTIFICATION**

**How do you know it's HASHING?**

✅ **Sign 1:** Need O(n) solution for unsorted array  
✅ **Sign 2:** Need fast existence checks (O(1))  
✅ **Sign 3:** Building sequences requires lookup

**Magic Keywords:**
- "Consecutive sequence"
- "Unsorted array"
- "O(n) time"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Brute Force:
────────────────────────────────────
For each number, check if num+1, num+2... exist
Time: O(n²) ❌

Optimal (Hashing):
────────────────────────────────────
Key Insight:
Only start counting from BEGINNING of sequence!
How to know if it's beginning? Check if (num-1) exists

Strategy:
────────────────────────────────────
1. Store all numbers in HashSet (O(1) lookup)
2. For each number:
   - If (num-1) exists, skip (not start of sequence)
   - If (num-1) doesn't exist, it's START!
   - Count consecutive: num, num+1, num+2...
3. Track maximum length

Time: O(n) ✅ (each number visited at most twice)
Space: O(n)
```

---

### **4️⃣ DRY RUN**

**Array:** `[100, 4, 200, 1, 3, 2]`

```
Step 1: Build Set
─────────────────
set = {100, 4, 200, 1, 3, 2}

Step 2: Find Sequences
─────────────────────────

Check 100:
  99 in set? NO → Start of sequence!
  Count: 100 → 101? NO
  Length: 1
  maxLen = 1

Check 4:
  3 in set? YES → Not start, skip

Check 200:
  199 in set? NO → Start of sequence!
  Count: 200 → 201? NO
  Length: 1
  maxLen = 1

Check 1:
  0 in set? NO → Start of sequence!
  Count: 1 → 2? YES → 3? YES → 4? YES → 5? NO
  Length: 4 ✅
  maxLen = 4

Check 3:
  2 in set? YES → Not start, skip

Check 2:
  1 in set? YES → Not start, skip

Final Answer: 4
```

**Why O(n)?**
```
Each number checked for "is start?" → O(n)
Each number counted in sequence only once → O(n)
Total: O(n) ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxLen = 0;
        
        for (int num : numSet) {
            // Check if it's start of sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentLen = 1;
                
                // Count consecutive numbers
                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentLen++;
                }
                
                maxLen = max(maxLen, currentLen);
            }
        }
        
        return maxLen;
    }
};
```

**Complexity:**
- **Time:** O(n) - each element visited at most twice
- **Space:** O(n) - hashset storage

---

<a name="problem4"></a>
## 🎯 PROBLEM 4: TOP K FREQUENT ELEMENTS

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Given an array and integer k, return the k most frequent elements.

**Input:**
```
arr = [1, 1, 1, 2, 2, 3]
k = 2
```

**Output:**
```
[1, 2]
```

**Explanation:**  
- 1 appears 3 times (most)
- 2 appears 2 times (second most)
- 3 appears 1 time

Return top 2: [1, 2]

---

### **2️⃣ IDENTIFICATION**

**How do you know it's HASHING?**

✅ **Sign 1:** Need frequency counting  
✅ **Sign 2:** Find most frequent elements  
✅ **Sign 3:** Need O(n) solution

**Magic Keywords:**
- "Most frequent"
- "Top K"
- "Count occurrences"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Strategy (Bucket Sort):
────────────────────────────────────
1. Count frequencies using HashMap
2. Use Bucket Sort by frequency
   - Create buckets[0...n]
   - buckets[i] = list of elements with frequency i
3. Collect from highest frequency bucket

Time: O(n) ✅
Space: O(n)

Alternative: Heap - O(n log k)
```

---

### **4️⃣ DRY RUN**

**Array:** `[1, 1, 1, 2, 2, 3]`, **k = 2**

```
Step 1: Count Frequencies
──────────────────────────
freq = {1→3, 2→2, 3→1}

Step 2: Build Buckets (by frequency)
─────────────────────────────────────
buckets[0] = []
buckets[1] = [3]      (3 appears 1 time)
buckets[2] = [2]      (2 appears 2 times)
buckets[3] = [1]      (1 appears 3 times)
buckets[4] = []
buckets[5] = []
buckets[6] = []

Step 3: Collect Top K from High Frequency
──────────────────────────────────────────
Start from buckets[6] down to buckets[0]

buckets[3]: [1] → result = [1] (k=2, need 1 more)
buckets[2]: [2] → result = [1, 2] (k=2, done!)

Answer: [1, 2] ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        // Step 2: Bucket sort by frequency
        vector<vector<int>> buckets(n + 1);
        for (auto& pair : freq) {
            int element = pair.first;
            int frequency = pair.second;
            buckets[frequency].push_back(element);
        }
        
        // Step 3: Collect top k from highest frequency
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};
```

**Complexity:**
- **Time:** O(n) - count + bucket + collect
- **Space:** O(n) - freq map + buckets

**Alternative (Heap):**
```cpp
// Using priority_queue: O(n log k)
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
// Keep size k, smallest frequency at top
```

---

<a name="problem5"></a>
## 🎯 PROBLEM 5: SUBARRAY SUM EQUALS K

### **1️⃣ PROBLEM STATEMENT + INPUT/OUTPUT**

**Problem:**  
Count the number of continuous subarrays whose sum equals k.

**Input:**
```
arr = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3]
k = 3
```

**Output:**
```
8
```

**Explanation:**  
8 different subarrays sum to 3

---

### **2️⃣ IDENTIFICATION**

**How do you know it's PREFIX SUM + HASHING?**

✅ **Sign 1:** Count subarrays with sum property  
✅ **Sign 2:** Need O(n) solution  
✅ **Sign 3:** Prefix sum optimization

**Magic Keywords:**
- "Subarray with sum K"
- "Count subarrays"
- "Continuous subarray"

---

### **3️⃣ ABSTRACT/APPROACH**

**Think Before Coding:**

```
Key Insight:
────────────────────────────────────
If prefix[j] - prefix[i] = k
Then subarray [i+1...j] has sum k

Rearrange:
prefix[i] = prefix[j] - k

Strategy:
────────────────────────────────────
1. Use HashMap to store prefix sum frequencies
2. Initialize: map[0] = 1 (empty subarray)
3. For each element:
   - Calculate running prefix sum
   - Check if (currentSum - k) exists in map
   - If yes, add its frequency to count
   - Store current prefix sum

Time: O(n) ✅
Space: O(n)
```

---

### **4️⃣ DRY RUN**

**Array:** `[1, 2, 3]`, **k = 3**

```
Initialize:
───────────
map = {0: 1}  (empty subarray)
sum = 0
count = 0

i=0: arr[0]=1
───────────
sum = 0 + 1 = 1
Check: sum - k = 1 - 3 = -2
       -2 in map? NO
map[1]++ → map = {0: 1, 1: 1}
count = 0

i=1: arr[1]=2
───────────
sum = 1 + 2 = 3
Check: sum - k = 3 - 3 = 0
       0 in map? YES! count += map[0] = 1
map[3]++ → map = {0: 1, 1: 1, 3: 1}
count = 1  (subarray [1,2])

i=2: arr[2]=3
───────────
sum = 3 + 3 = 6
Check: sum - k = 6 - 3 = 3
       3 in map? YES! count += map[3] = 1
map[6]++ → map = {0: 1, 1: 1, 3: 1, 6: 1}
count = 2  (subarray [3])

Final: 2 subarrays ✅
```

---

### **5️⃣ CODE**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  // Empty subarray
        
        int prefixSum = 0;
        int count = 0;
        
        for (int num : arr) {
            prefixSum += num;
            
            // Check if (prefixSum - k) exists
            if (prefixCount.count(prefixSum - k)) {
                count += prefixCount[prefixSum - k];
            }
            
            // Store current prefix sum
            prefixCount[prefixSum]++;
        }
        
        return count;
    }
};
```

**Complexity:**
- **Time:** O(n) - single pass
- **Space:** O(n) - hashmap

---

<a name="reference"></a>
## 📋 QUICK REFERENCE SHEET

### **Pattern Recognition:**

| Problem Type | Pattern | Time |
|-------------|---------|------|
| Find pair with sum | HashMap (complement) | O(n) |
| Group similar items | HashMap (key = signature) | O(n×k) |
| Count frequencies | HashMap (element → count) | O(n) |
| Existence check | HashSet | O(n) |
| Longest sequence | HashSet + smart iteration | O(n) |
| Top K frequent | HashMap + Bucket Sort | O(n) |
| Subarray sum K | Prefix Sum + HashMap | O(n) |

---

### **Generic Templates:**

**1. Two Sum:**
```cpp
map<int, int> seen;
if (seen.count(target - x)) return {seen[target-x], i};
seen[x] = i;
```

**2. Frequency:**
```cpp
map<int, int> freq;
for (x : arr) freq[x]++;
```

**3. Duplicates:**
```cpp
set<int> seen;
if (seen.count(x)) return true;
seen.insert(x);
```

**4. Anagram:**
```cpp
string key = s; sort(key.begin(), key.end());
groups[key].push_back(s);
```

---

**🎯 Master these 5 problems - they cover 80% of hashing interviews!**
