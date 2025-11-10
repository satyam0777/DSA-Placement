# 🎯 STL CONTAINERS - COMPLETE GUIDE
## Interview-Ready Package for Service-Based Companies

---

## 📚 WHAT IS STL?

### **Standard Template Library (STL):**
> Pre-built, optimized data structures and algorithms in C++

### **Why STL is CRUCIAL for Interviews:**
```
✅ 90-95% of problems use STL
✅ Saves 50% coding time
✅ Clean, readable code (impresses interviewers!)
✅ Built-in optimization (faster than manual)
✅ Expected knowledge in ALL companies
```

---

## 🎯 CONTAINER SELECTION FLOWCHART

```
Need to solve problem?
        |
   ┌────▼────┐
   │What do  │
   │you need?│
   └─┬──┬──┬─┘
     │  │  │
  ┌──▼┐┌▼─┐┌▼────┐
  │Dy-││Key││LIFO/│
  │namic││Val││FIFO?│
  │Array│└──┘└─────┘
  └──┬─┘  │    │
     │    │    │
  ┌──▼──┐ │ ┌──▼───┐
  │vector│ │ │stack/│
  └─────┘ │ │queue │
          │ └──────┘
     ┌────▼─────┐
     │Ordered?  │
     └─┬────┬───┘
       │    │
    ┌──▼┐ ┌─▼──────┐
    │map│ │unordered│
    │set│ │_map/set │
    └───┘ └────────┘
```

---

## 📖 CONTAINER 1: VECTOR ⭐⭐⭐

### **What is Vector?**
> Dynamic array that can grow/shrink in size

### **When to Use:**
```
✅ Need dynamic-sized array
✅ Random access to elements (arr[i])
✅ Frequent additions at end
✅ Don't know size beforehand
```

---

### **💡 Interview Communication:**

> "Sir, I'll use **vector** because we need a dynamic array with random access.
> 
> Vector provides O(1) access and O(1) amortized push_back.
> 
> Let me declare it..."

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // DECLARATION
    vector<int> v;              // Empty vector
    vector<int> v2(5);          // Size 5, values = 0
    vector<int> v3(5, 10);      // Size 5, values = 10
    vector<int> v4 = {1,2,3,4}; // Initialize with values
    
    // INSERTION
    v.push_back(10);            // Add at end - O(1)
    v.insert(v.begin(), 5);     // Insert at position - O(n)
    v.insert(v.begin() + 2, 7); // Insert at index 2
    
    // ACCESS
    cout << v[0];               // Index access - O(1)
    cout << v.at(1);            // Bounds-checked access - O(1)
    cout << v.front();          // First element - O(1)
    cout << v.back();           // Last element - O(1)
    
    // MODIFICATION
    v[0] = 20;                  // Direct modification
    v.pop_back();               // Remove last - O(1)
    v.erase(v.begin() + 1);     // Erase at position - O(n)
    v.clear();                  // Remove all - O(n)
    
    // SIZE OPERATIONS
    int size = v.size();        // Number of elements - O(1)
    bool empty = v.empty();     // Check if empty - O(1)
    v.resize(10);               // Change size
    v.reserve(100);             // Reserve capacity
    
    // TRAVERSAL
    // Method 1: Range-based for
    for(int x : v) cout << x << " ";
    
    // Method 2: Iterator
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    
    // Method 3: Index-based
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    // SORTING & SEARCHING
    sort(v.begin(), v.end());           // Sort ascending
    reverse(v.begin(), v.end());        // Reverse
    auto it = find(v.begin(), v.end(), 10); // Find element
    
    return 0;
}
```

---

### **⏱️ Time Complexity:**

| Operation | Time | Explanation |
|-----------|------|-------------|
| **Access v[i]** | O(1) | Direct index |
| **push_back()** | O(1) amortized | May resize occasionally |
| **pop_back()** | O(1) | Remove last |
| **insert(pos)** | O(n) | Shift elements |
| **erase(pos)** | O(n) | Shift elements |
| **find()** | O(n) | Linear search |
| **sort()** | O(n log n) | QuickSort/MergeSort |

**Space:** O(n)

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Find Maximum Element**
```cpp
vector<int> v = {3, 1, 4, 1, 5};
int maxVal = *max_element(v.begin(), v.end()); // 5
cout << maxVal;
```

#### **Problem 2: Remove Duplicates**
```cpp
vector<int> v = {1, 2, 2, 3, 4, 4};
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// Result: {1, 2, 3, 4}
```

#### **Problem 3: Reverse Array**
```cpp
vector<int> v = {1, 2, 3, 4, 5};
reverse(v.begin(), v.end());
// Result: {5, 4, 3, 2, 1}
```

#### **Problem 4: Find Element**
```cpp
vector<int> v = {1, 2, 3, 4, 5};
auto it = find(v.begin(), v.end(), 3);
if(it != v.end()) {
    cout << "Found at index: " << it - v.begin();
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 95% ⭐⭐⭐
- **Infosys:** 98% ⭐⭐⭐
- **Wipro:** 95% ⭐⭐⭐

**Most used STL container in interviews!**

---

## 📖 CONTAINER 2: MAP ⭐⭐⭐

### **What is Map?**
> Key-value pairs stored in **sorted order by key**

### **When to Use:**
```
✅ Need key-value storage
✅ Need sorted keys
✅ Frequency counting with order
✅ Range queries on keys
```

---

### **💡 Interview Communication:**

> "Sir, I'll use **map** for frequency counting because it stores key-value pairs in sorted order.
> 
> Map provides O(log n) insert/find operations.
> 
> Perfect for this problem..."

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    // DECLARATION
    map<int, int> mp;
    map<string, int> wordCount;
    map<char, int> freq;
    
    // INSERTION
    mp[1] = 10;                 // Insert/update - O(log n)
    mp[2] = 20;
    mp.insert({3, 30});         // Alternative insert
    mp.insert(make_pair(4, 40));
    
    // ACCESS
    cout << mp[1];              // Access value - O(log n)
    // Note: mp[key] creates key if doesn't exist!
    
    // SAFE ACCESS
    if(mp.find(5) != mp.end()) {
        cout << mp[5];
    }
    
    // COUNT (check existence)
    if(mp.count(1)) {           // O(log n)
        cout << "Key 1 exists";
    }
    
    // DELETION
    mp.erase(2);                // Erase by key - O(log n)
    mp.clear();                 // Remove all
    
    // SIZE
    int size = mp.size();       // O(1)
    bool empty = mp.empty();    // O(1)
    
    // TRAVERSAL (in sorted order of keys!)
    map<int, int> m = {{3,30}, {1,10}, {2,20}};
    for(auto p : m) {
        cout << p.first << " -> " << p.second << endl;
    }
    // Output: 1->10, 2->20, 3->30 (sorted!)
    
    // Alternative traversal
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " -> " << it->second << endl;
    }
    
    return 0;
}
```

---

### **⏱️ Time Complexity:**

| Operation | Time | Explanation |
|-----------|------|-------------|
| **Insert** | O(log n) | Red-Black Tree |
| **Find** | O(log n) | Binary search |
| **Erase** | O(log n) | Tree rebalance |
| **Access mp[key]** | O(log n) | Find + create if needed |
| **Traversal** | O(n) | In-order traversal |

**Space:** O(n)

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Frequency Count**
```cpp
vector<int> arr = {1, 2, 2, 3, 1, 4};
map<int, int> freq;

for(int x : arr) {
    freq[x]++;
}

// Print frequencies
for(auto p : freq) {
    cout << p.first << " appears " << p.second << " times\n";
}
// Output (sorted by element):
// 1 appears 2 times
// 2 appears 2 times
// 3 appears 1 times
// 4 appears 1 times
```

#### **Problem 2: First Non-Repeating Character**
```cpp
string s = "leetcode";
map<char, int> freq;

for(char c : s) freq[c]++;

for(char c : s) {
    if(freq[c] == 1) {
        cout << "First non-repeating: " << c;
        break;
    }
}
// Output: l
```

#### **Problem 3: Two Sum (with indices)**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mp; // value -> index
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
```

#### **Problem 4: Group Anagrams**
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;
    
    for(string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for(auto p : mp) {
        result.push_back(p.second);
    }
    return result;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 85-90% ⭐⭐⭐
- **Infosys:** 90-95% ⭐⭐⭐
- **Wipro:** 80-85% ⭐⭐⭐

---

## 📖 CONTAINER 3: UNORDERED_MAP ⭐⭐⭐

### **What is Unordered_Map?**
> Key-value pairs stored **without order** (hash table)

### **When to Use:**
```
✅ Need FAST insert/find (O(1) average)
✅ Don't need sorted keys
✅ Frequency counting (order doesn't matter)
✅ Two Sum, Subarray Sum problems
```

### **Map vs Unordered_Map:**
| Feature | map | unordered_map |
|---------|-----|---------------|
| **Order** | Sorted | No order |
| **Time** | O(log n) | O(1) average ⭐ |
| **Implementation** | Red-Black Tree | Hash Table |
| **Use When** | Need order | Need speed |

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // DECLARATION
    unordered_map<int, int> ump;
    unordered_map<string, int> wordCount;
    
    // All operations same as map, but O(1) average!
    ump[1] = 10;                // O(1) average
    ump.insert({2, 20});        // O(1) average
    
    if(ump.find(1) != ump.end()) { // O(1) average
        cout << ump[1];
    }
    
    ump.erase(1);               // O(1) average
    
    // TRAVERSAL (NO SPECIFIC ORDER!)
    for(auto p : ump) {
        cout << p.first << " -> " << p.second << endl;
    }
    
    return 0;
}
```

---

### **⏱️ Time Complexity:**

| Operation | Average | Worst | Explanation |
|-----------|---------|-------|-------------|
| **Insert** | O(1) ⭐ | O(n) | Hash collision |
| **Find** | O(1) ⭐ | O(n) | Hash collision |
| **Erase** | O(1) ⭐ | O(n) | Hash collision |

**Use unordered_map when you need SPEED!**

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Two Sum (Faster!)**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // O(1) lookup!
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
// Time: O(n) instead of O(n log n) with map!
```

#### **Problem 2: Subarray Sum Equals K**
```cpp
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    
    int sum = 0, count = 0;
    for(int num : nums) {
        sum += num;
        if(prefixSum.find(sum - k) != prefixSum.end()) {
            count += prefixSum[sum - k];
        }
        prefixSum[sum]++;
    }
    return count;
}
```

#### **Problem 3: Longest Consecutive Sequence**
```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    
    for(int num : s) {
        if(s.find(num - 1) == s.end()) { // Start of sequence
            int current = num;
            int streak = 1;
            
            while(s.find(current + 1) != s.end()) {
                current++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 80-85% ⭐⭐⭐
- **Infosys:** 85-90% ⭐⭐⭐
- **Wipro:** 75-80% ⭐⭐

---

## 📖 CONTAINER 4: SET ⭐⭐⭐

### **What is Set?**
> Stores **unique elements in sorted order**

### **When to Use:**
```
✅ Need unique elements only
✅ Need sorted order
✅ Remove duplicates
✅ Range queries (lower_bound, upper_bound)
✅ Find kth smallest/largest
```

---

### **💡 Interview Communication:**

> "Sir, I'll use **set** because we need unique elements in sorted order.
> 
> Set automatically maintains sorted order and removes duplicates.
> 
> Perfect for this problem..."

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    // DECLARATION
    set<int> s;
    set<int, greater<int>> descSet; // Descending order
    
    // INSERTION (duplicates ignored!)
    s.insert(3);                    // O(log n)
    s.insert(1);
    s.insert(2);
    s.insert(2);                    // Ignored!
    // s = {1, 2, 3} (sorted, unique)
    
    // DELETION
    s.erase(2);                     // Erase by value - O(log n)
    auto it = s.find(1);
    s.erase(it);                    // Erase by iterator
    
    // FIND
    if(s.find(3) != s.end()) {      // O(log n)
        cout << "3 exists";
    }
    
    // COUNT (0 or 1 for set)
    if(s.count(3)) {                // O(log n)
        cout << "3 exists";
    }
    
    // SIZE
    int size = s.size();            // O(1)
    bool empty = s.empty();
    
    // TRAVERSAL (sorted order!)
    set<int> st = {5, 2, 8, 1};
    for(int x : st) {
        cout << x << " ";           // 1 2 5 8
    }
    
    // RANGE QUERIES
    set<int> s2 = {1, 3, 5, 7, 9};
    
    // lower_bound: First element >= x
    auto lb = s2.lower_bound(5);    // Points to 5
    
    // upper_bound: First element > x
    auto ub = s2.upper_bound(5);    // Points to 7
    
    // Find range
    auto range_start = s2.lower_bound(3);
    auto range_end = s2.upper_bound(7);
    // Elements: 3, 5, 7
    
    return 0;
}
```

---

### **⏱️ Time Complexity:**

| Operation | Time | Explanation |
|-----------|------|-------------|
| **Insert** | O(log n) | Red-Black Tree |
| **Find** | O(log n) | Binary search |
| **Erase** | O(log n) | Tree rebalance |
| **lower_bound** | O(log n) | Binary search |
| **upper_bound** | O(log n) | Binary search |
| **Traversal** | O(n) | In-order |

**Space:** O(n)

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Remove Duplicates**
```cpp
vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
set<int> s(arr.begin(), arr.end());

vector<int> unique(s.begin(), s.end());
// unique = {1, 2, 3, 4, 5}
```

#### **Problem 2: Kth Smallest Element**
```cpp
vector<int> arr = {7, 10, 4, 3, 20, 15};
set<int> s(arr.begin(), arr.end());

int k = 3;
auto it = s.begin();
advance(it, k - 1); // Move iterator k-1 steps
cout << "Kth smallest: " << *it; // 7
```

#### **Problem 3: Floor and Ceil**
```cpp
set<int> s = {1, 3, 5, 7, 9};
int x = 6;

// Floor: Largest element <= x
auto floor_it = s.lower_bound(x);
if(floor_it != s.begin()) {
    floor_it--;
    cout << "Floor: " << *floor_it; // 5
}

// Ceil: Smallest element >= x
auto ceil_it = s.lower_bound(x);
if(ceil_it != s.end()) {
    cout << "Ceil: " << *ceil_it; // 7
}
```

#### **Problem 4: Find Missing Number in Range**
```cpp
vector<int> arr = {1, 3, 5, 6};
set<int> s(arr.begin(), arr.end());

for(int i = 1; i <= 6; i++) {
    if(s.find(i) == s.end()) {
        cout << "Missing: " << i << endl;
    }
}
// Output: Missing: 2, 4
```

---

### **🏢 Company Frequency:**
- **TCS:** 75-80% ⭐⭐⭐
- **Infosys:** 80-85% ⭐⭐⭐
- **Wipro:** 70-75% ⭐⭐

---

## 📖 CONTAINER 5: UNORDERED_SET ⭐⭐⭐

### **What is Unordered_Set?**
> Stores **unique elements without order** (hash table)

### **When to Use:**
```
✅ Need FAST insert/find (O(1) average)
✅ Check existence quickly
✅ Remove duplicates (order doesn't matter)
✅ Don't need sorted order
```

### **Set vs Unordered_Set:**
| Feature | set | unordered_set |
|---------|-----|---------------|
| **Order** | Sorted | No order |
| **Time** | O(log n) | O(1) average ⭐ |
| **Use When** | Need order | Need speed |

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;
    
    // All operations same as set, but O(1) average!
    us.insert(3);               // O(1) average
    us.insert(1);
    us.insert(2);
    
    if(us.find(2) != us.end()) { // O(1) average
        cout << "Found";
    }
    
    us.erase(1);                // O(1) average
    
    // TRAVERSAL (random order!)
    for(int x : us) {
        cout << x << " ";
    }
    
    return 0;
}
```

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Contains Duplicate**
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for(int num : nums) {
        if(seen.find(num) != seen.end()) {
            return true; // Found duplicate
        }
        seen.insert(num);
    }
    return false;
}
// Time: O(n), Space: O(n)
```

#### **Problem 2: Intersection of Two Arrays**
```cpp
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> result;
    
    for(int num : nums2) {
        if(s1.find(num) != s1.end()) {
            result.insert(num);
        }
    }
    
    return vector<int>(result.begin(), result.end());
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 70-75% ⭐⭐
- **Infosys:** 75-80% ⭐⭐⭐
- **Wipro:** 65-70% ⭐⭐

---

## 📖 CONTAINER 6: STACK ⭐⭐⭐

### **What is Stack?**
> **LIFO** - Last In, First Out

### **When to Use:**
```
✅ Next Greater/Smaller Element
✅ Valid Parentheses
✅ Evaluate expressions
✅ Undo operations
✅ Backtracking
```

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    
    // PUSH
    st.push(10);                // O(1)
    st.push(20);
    st.push(30);
    
    // TOP (peek)
    cout << st.top();           // 30 - O(1)
    
    // POP
    st.pop();                   // Remove 30 - O(1)
    
    // SIZE & EMPTY
    int size = st.size();       // O(1)
    bool empty = st.empty();    // O(1)
    
    // PROCESS ALL
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    
    return 0;
}
```

---

### **⏱️ Time Complexity:**

| Operation | Time |
|-----------|------|
| **push()** | O(1) |
| **pop()** | O(1) |
| **top()** | O(1) |
| **empty()** | O(1) |

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Valid Parentheses**
```cpp
bool isValid(string s) {
    stack<char> st;
    
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            
            char top = st.top();
            if((c == ')' && top == '(') ||
               (c == '}' && top == '{') ||
               (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
```

#### **Problem 2: Next Greater Element**
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        
        if(!st.empty()) {
            result[i] = st.top();
        }
        
        st.push(nums[i]);
    }
    return result;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 80-85% ⭐⭐⭐
- **Infosys:** 85-90% ⭐⭐⭐
- **Wipro:** 75-80% ⭐⭐⭐

---

## 📖 CONTAINER 7: QUEUE ⭐⭐⭐

### **What is Queue?**
> **FIFO** - First In, First Out

### **When to Use:**
```
✅ BFS (Level order traversal)
✅ Sliding Window problems
✅ First come, first served
✅ Process in order
```

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    
    // PUSH (add to back)
    q.push(10);                 // O(1)
    q.push(20);
    q.push(30);
    
    // FRONT
    cout << q.front();          // 10 - O(1)
    
    // BACK
    cout << q.back();           // 30 - O(1)
    
    // POP (remove from front)
    q.pop();                    // Remove 10 - O(1)
    
    // SIZE & EMPTY
    int size = q.size();        // O(1)
    bool empty = q.empty();
    
    // PROCESS ALL
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}
```

---

### **🎯 Top Interview Problems:**

#### **Problem 1: First Negative in Window**
```cpp
vector<int> firstNegative(vector<int>& arr, int k) {
    queue<int> q; // Store indices of negatives
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        // Add negative indices
        if(arr[i] < 0) {
            q.push(i);
        }
        
        // Remove out-of-window indices
        while(!q.empty() && q.front() < i - k + 1) {
            q.pop();
        }
        
        // Window complete
        if(i >= k - 1) {
            if(!q.empty()) {
                result.push_back(arr[q.front()]);
            } else {
                result.push_back(0);
            }
        }
    }
    return result;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 75-80% ⭐⭐⭐
- **Infosys:** 80-85% ⭐⭐⭐
- **Wipro:** 70-75% ⭐⭐

---

## 📖 CONTAINER 8: PRIORITY_QUEUE (HEAP) ⭐⭐⭐

### **What is Priority Queue?**
> Always gives **maximum** (or minimum) element in O(1)

### **When to Use:**
```
✅ Find Kth largest/smallest
✅ Merge K sorted arrays
✅ Top K frequent elements
✅ Median in stream
```

---

### **📝 Complete Operations:**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // MAX HEAP (default)
    priority_queue<int> maxHeap;
    
    maxHeap.push(10);           // O(log n)
    maxHeap.push(30);
    maxHeap.push(20);
    
    cout << maxHeap.top();      // 30 (max) - O(1)
    maxHeap.pop();              // Remove 30 - O(log n)
    
    // MIN HEAP
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    
    cout << minHeap.top();      // 10 (min) - O(1)
    
    return 0;
}
```

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Kth Largest Element**
```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int num : nums) {
        minHeap.push(num);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    return minHeap.top();
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 70-75% ⭐⭐⭐
- **Infosys:** 75-80% ⭐⭐⭐
- **Wipro:** 65-70% ⭐⭐

---

## 🎯 CONTAINER SELECTION DECISION TREE

```
PROBLEM → Which Container?

Need dynamic array? → vector
Need key-value + order? → map
Need key-value + speed? → unordered_map
Need unique + order? → set
Need unique + speed? → unordered_set
Need LIFO? → stack
Need FIFO? → queue
Need max/min always? → priority_queue
```

---

## 💯 SUMMARY

**Containers Covered:**
1. ✅ vector (dynamic array)
2. ✅ map (ordered key-value)
3. ✅ unordered_map (fast key-value)
4. ✅ set (ordered unique)
5. ✅ unordered_set (fast unique)
6. ✅ stack (LIFO)
7. ✅ queue (FIFO)
8. ✅ priority_queue (heap)

**You're now 50% done with STL mastery!**

**Next:** Check `STL-Algorithms/INTERVIEW-READY.md` for algorithms! 🚀

**All the best, Satyam!** 💪
