#  HASHING & FREQUENCY - MUSCLE MEMORY EDITION

---

##  3-SECOND RECOGNITION

**Ask 3 Questions:**
1. Need to **COUNT/CHECK FREQUENCY**? ✅
2. Need **O(1) LOOKUP**? ✅
3. **EXISTENCE CHECK** or **DUPLICATES**? ✅

**If any YES → HASHING! 🎯**

---

## 🔥 MAGIC KEYWORDS

| See This | Think This |
|----------|-----------|
| "Frequency" / "Count" | ✅ HASHMAP |
| "Duplicate" / "Unique" | ✅ HASHSET |
| "Find if exists" | ✅ HASHSET |
| "Most/Least frequent" | ✅ HASHMAP + max |
| "Anagram" | ✅ HASHMAP (char freq) |
| "Two elements with sum" | ✅ HASHMAP (complement) |
| "Intersection" / "Union" | ✅ HASHSET |
| "First non-repeating" | ✅ HASHMAP + scan |
| "In O(1) time" | ✅ HASHING! |

---

## 📝 THE GOLDEN RULE

```
╔═══════════════════════════════════════════╗
║  Need to COUNT? → unordered_map           ║
║  Need to CHECK EXISTS? → unordered_set    ║
╚═══════════════════════════════════════════╝
```

---

## 📝 TEMPLATE 1: FREQUENCY COUNTING (Write 5x!)

```cpp
// MEMORIZE THIS!
unordered_map<int, int> freq;

// Count all elements
for (int x : arr) {
    freq[x]++;
}

// Find most frequent
int maxFreq = 0, result = -1;
for (auto& p : freq) {
    if (p.second > maxFreq) {
        maxFreq = p.second;
        result = p.first;
    }
}
```

**Time:** O(n) | **Space:** O(n)

---

## 📝 TEMPLATE 2: CHECK DUPLICATES

```cpp
// MEMORIZE THIS!
bool containsDuplicate(vector<int>& arr) {
    unordered_set<int> seen;
    
    for (int x : arr) {
        if (seen.count(x)) {
            return true;  // Found!
        }
        seen.insert(x);
    }
    
    return false;
}
```

**Time:** O(n) | **Space:** O(n)

---

## 📝 TEMPLATE 3: TWO SUM PATTERN

```cpp
// MEMORIZE THIS!
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

**Key:** Store complement, check if current exists!  
**Time:** O(n) | **Space:** O(n)

---

## 📝 TEMPLATE 4: ANAGRAM CHECK

```cpp
// MEMORIZE THIS!
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    
    unordered_map<char, int> freq;
    
    for (char c : s) freq[c]++;
    for (char c : t) freq[c]--;
    
    for (auto& p : freq) {
        if (p.second != 0) return false;
    }
    
    return true;
}
```

**Key:** Increment for s, decrement for t, check all 0!  
**Time:** O(n) | **Space:** O(26) = O(1)

---

## 📝 TEMPLATE 5: INTERSECTION

```cpp
// MEMORIZE THIS!
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
```

**Time:** O(m + n) | **Space:** O(min(m,n))

---

## 💪 MANTRA (Say 10x!)

**"Count frequency? Use MAP!"**

**"Check exists? Use SET!"**

**"Two Sum? Store complement!"**

**"Anagram? Compare frequencies!"**

**"O(1) lookup? Think HASHING!"**

---

## 🎨 5 PROBLEM PATTERNS

### **Pattern 1: TWO SUM** ⭐⭐⭐⭐⭐

**Problem:** Find two numbers that add to target

**Key:** `if (seen.count(target - arr[i]))`

```cpp
map[arr[i]] = i;  // Store with index
if (map.count(target - current)) → Found!
```

---

### **Pattern 2: GROUP ANAGRAMS** ⭐⭐⭐⭐

**Problem:** Group words with same letters

**Key:** Sorted string as key

```cpp
string key = s;
sort(key.begin(), key.end());
groups[key].push_back(s);
```

---

### **Pattern 3: LONGEST CONSECUTIVE** ⭐⭐⭐⭐

**Problem:** Longest sequence in unsorted array

**Key:** Only count from sequence start

```cpp
if (!set.count(num - 1)) {  // Start!
    while (set.count(num + 1)) num++;
}
```

---

### **Pattern 4: TOP K FREQUENT** ⭐⭐⭐⭐

**Problem:** K most frequent elements

**Key:** Bucket sort by frequency

```cpp
// Count frequencies
freq[x]++;

// Bucket sort
buckets[frequency].push_back(element);

// Collect from high to low
```

---

### **Pattern 5: SUBARRAY SUM = K** ⭐⭐⭐⭐⭐

**Problem:** Count subarrays with sum K

**Key:** Prefix sum + HashMap

```cpp
map[0] = 1;  // Important!
sum += x;
count += map[sum - k];
map[sum]++;
```

---

## 📊 DECISION TREE

```
START: Need fast lookup/count?
    ↓
Q: Need to count frequency?
    ↓
YES → HASHMAP (unordered_map<T, int>)

Q: Just check if exists?
    ↓
YES → HASHSET (unordered_set<T>)

Q: Find pair with sum?
    ↓
YES → HASHMAP (store complement)

Q: Group similar items?
    ↓
YES → HASHMAP (key = signature)

Q: Count subarrays?
    ↓
YES → PREFIX SUM + HASHMAP
```

---

## ⏱️ COMPLEXITY CHEAT SHEET

| Pattern | Time | Space | Key Operation |
|---------|------|-------|---------------|
| **Frequency Count** | O(n) | O(n) | map[x]++ |
| **Check Duplicates** | O(n) | O(n) | set.count(x) |
| **Two Sum** | O(n) | O(n) | map[target-x] |
| **Anagram** | O(n) | O(1) | freq compare |
| **Intersection** | O(m+n) | O(min) | set lookup |
| **Longest Consecutive** | O(n) | O(n) | set.count(x-1) |
| **Top K Frequent** | O(n) | O(n) | bucket sort |
| **Subarray Sum K** | O(n) | O(n) | prefix + map |

---

##  TOP 5 PROBLEMS (Target Times)

1. **Two Sum** - 5 min ⭐⭐⭐⭐⭐
2. **Contains Duplicate** - 3 min ⭐⭐⭐⭐⭐
3. **Valid Anagram** - 5 min ⭐⭐⭐⭐⭐
4. **Group Anagrams** - 8 min ⭐⭐⭐⭐
5. **Longest Consecutive** - 10 min ⭐⭐⭐⭐

---

## 🎤 INTERVIEW SCRIPT

**Recognition:**
> "Sir, I see we need to [count frequency / check existence / find pairs]. This is classic hashing - O(n) with O(1) lookup!"

**Choice:**
> "I'll use unordered_map for counting / unordered_set for existence check."

**Complexity:**
> "Time: O(n) single pass. Space: O(n) for hash table. Average O(1) per operation!"

---

## 💪 MUSCLE MEMORY DRILLS

### **Drill 1: Write Templates Blind (5 min)**

Close file. Write from memory:
1. Frequency counting
2. Check duplicates
3. Two sum pattern

**Repeat 5 times!**

---

### **Drill 2: Pattern Recognition (3 sec each)**

```
1. "Find two numbers that add to target"
   → TWO SUM (HashMap complement) ✅

2. "Count how many times each appears"
   → FREQUENCY (HashMap) ✅

3. "Check if array has duplicates"
   → DUPLICATES (HashSet) ✅

4. "Group words with same letters"
   → ANAGRAMS (HashMap with sorted key) ✅

5. "Count subarrays with sum K"
   → PREFIX SUM + HASHMAP ✅
```

---

## 💡 MEMORY HOOKS

### **Hook 1: The Dictionary 📖**
- HashMap = Dictionary
- Word → Definition
- O(1) to look up any word!

### **Hook 2: The Attendance 📝**
- HashSet = Name list
- Present or Absent
- O(1) to check attendance!

### **Hook 3: The Counter 🔢**
- Frequency Map = Tally marks
- Each element gets count
- freq[x]++ = Add tally!

---

## 🔥 GOLDEN RULES

1. **"Count? MAP. Exists? SET."**
2. **"Two Sum? Store complement!"**
3. **"Anagram? Sort or count!"**
4. **"O(1) lookup = Hashing power!"**
5. **"Space for speed trade-off!"**

---


## 🎯 ONE-PAGE PRINTABLE

```
╔══════════════════════════════════════════════════════════╗
║           HASHING & FREQUENCY - CHEAT SHEET             ║
╚══════════════════════════════════════════════════════════╝

📌 RECOGNITION:
   Count/Frequency? Exists? Duplicates? → HASHING!

📌 GOLDEN RULE:
   COUNT → unordered_map
   EXISTS → unordered_set

📌 FREQUENCY TEMPLATE:
   map<int, int> freq;
   for (x : arr) freq[x]++;

📌 TWO SUM TEMPLATE:
   map<int, int> seen;
   if (seen.count(target - x)) → Found!
   seen[x] = i;

📌 DUPLICATE CHECK:
   set<int> seen;
   if (seen.count(x)) → Duplicate!
   seen.insert(x);

📌 ANAGRAM:
   Sort both strings, compare
   OR count frequencies, compare

📌 5 PATTERNS:
   1. Two Sum → Store complement
   2. Group Anagrams → Sorted key
   3. Longest Consecutive → Start check
   4. Top K Frequent → Bucket sort
   5. Subarray Sum K → Prefix + map

📌 COMPLEXITY:
   All: O(n) time, O(n) space
   Average O(1) per operation

📌 COMMON MISTAKES:
   ❌ Using map when set enough
   ❌ Not checking before access
   ❌ Forgetting map[0] = 1 for prefix

📌 MANTRAS:
   • "Count? MAP. Exists? SET."
   • "Two Sum? Store complement!"
   • "O(1) lookup power!"

╔══════════════════════════════════════════════════════════╗
║  "HashMap = O(1) lookup magic!" 🔥                      ║
╚══════════════════════════════════════════════════════════╝
```

---

**🎯 You got this! Hashing is muscle memory now! 💪**

**All the best! 🚀**

---

