
##  C++ STL (Standard Template Library) for Arrays and Problem Solving

The **STL** is a powerful library in C++ that provides ready-to-use classes and functions for data structures and algorithms. Mastering STL is crucial for efficient problem solving and placements.

---

### a. Why Use STL?

- **Saves time:** No need to implement common data structures from scratch.
- **Efficient:** STL containers and algorithms are optimized.
- **Readable:** Code is cleaner and easier to debug.

---

### b. Common STL Containers

#### 1. `vector` (Dynamic Array)

- **Resizable array** (like Python list).
- Random access, fast insertion/removal at end.

```cpp
#include <vector>
using namespace std;

vector<int> v;           // Empty vector
vector<int> v2(5, 10);   // {10, 10, 10, 10, 10}
v.push_back(1);          // Add element at end
v.pop_back();            // Remove last element
cout << v[0];            // Access element
v.size();                // Number of elements
v.clear();               // Remove all elements

// Traversal
for(int x : v) cout << x << " ";
```

---

#### 2. `array` (Fixed-size Array, C++11+)

- Safer and more functional than built-in arrays.

```cpp
#include <array>
array<int, 5> arr = {1, 2, 3, 4, 5};
arr[2] = 10;
arr.size(); // 5
```

---

#### 3. `deque` (Double-ended Queue)

- Fast insertion/removal at both ends.

```cpp
#include <deque>
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

---

#### 4. `stack` and `queue`

- **Stack:** LIFO (Last-In-First-Out)
- **Queue:** FIFO (First-In-First-Out)

```cpp
#include <stack>
stack<int> s;
s.push(1); s.pop(); s.top();

#include <queue>
queue<int> q;
q.push(1); q.pop(); q.front();
```

---

#### 5. `set` and `unordered_set`

- **set:** Sorted, unique elements.
- **unordered_set:** Unique elements, not sorted, faster average operations.

```cpp
#include <set>
set<int> s;
s.insert(3); s.insert(1);
s.erase(3);
if(s.count(1)) { /* found */ }

#include <unordered_set>
unordered_set<int> us;
```

---

#### 6. `map` and `unordered_map`

- **map:** Key-value pairs, sorted by key.
- **unordered_map:** Key-value pairs, not sorted, faster average operations.

```cpp
#include <map>
map<string, int> m;
m["apple"] = 2;
cout << m["apple"];

#include <unordered_map>
unordered_map<string, int> um;
```

---

### c. Useful STL Algorithms

```cpp
#include <algorithm>
vector<int> v = {4, 2, 1, 3};
sort(v.begin(), v.end());         // Sort ascending
reverse(v.begin(), v.end());      // Reverse
int idx = find(v.begin(), v.end(), 3) - v.begin(); // Find element
int cnt = count(v.begin(), v.end(), 2);            // Count occurrences
```

---

### d. Tips for Placement

- Use `vector` for dynamic arrays.
- Use `set`/`unordered_set` for unique elements.
- Use `map`/`unordered_map` for key-value lookups.
- Use STL algorithms (`sort`, `find`, `count`, etc.) to save time.
- Know how to traverse and modify STL containers.

---

### e. Example: Remove Duplicates from Array

```cpp
vector<int> v = {1, 2, 2, 3, 4, 4};
set<int> s(v.begin(), v.end());
vector<int> unique(s.begin(), s.end());
```

---

### f. Example: Frequency Count

```cpp
vector<int> v = {1, 2, 2, 3, 4, 4};
unordered_map<int, int> freq;
for(int x : v) freq[x]++;
for(auto p : freq) cout << p.first << " " << p.second << endl;
```

---

### g. Example: Sorting a Vector of Pairs

```cpp
vector<pair<int, int>> vp = {{2, 3}, {1, 5}, {2, 2}};
sort(vp.begin(), vp.end()); // Sorts by first, then second
```

---

### h. Practice Problems

1. Find the most frequent element in an array using STL.
2. Remove all duplicates from an array.
3. Sort an array in descending order.
4. Find the intersection of two arrays.

---

## i. Use Cases of STL Containers (Like Aditya Verma's Approach - DSA OG)

Understanding when to use which STL container is crucial for problem solving. Here are common use cases and typical problems for each:

---

### 1. `map` (Key-Value, Sorted by Key)

**Use Cases:**
- Frequency counting (e.g., count occurrences of elements)
- Storing and retrieving values by key (e.g., word count, index mapping)
- Problems where you need ordered keys (e.g., next greater/smaller element)

**Example Problems:**
- Find the first non-repeating character in a string
- Group anagrams together
- Store prefix sums and their indices

---

### 2. `unordered_map` (Key-Value, Unordered, Faster Average)

**Use Cases:**
- Fast lookups and insertions (O(1) average)
- Frequency counting when order doesn't matter
- Hashing for quick existence checks

**Example Problems:**
- Two Sum (find if two numbers sum to target)
- Longest subarray with given sum
- Detect duplicates in an array

---

### 3. `set` (Unique, Sorted Elements)

**Use Cases:**
- Store unique elements in sorted order
- Remove duplicates and keep order
- Find next greater/smaller element (using `lower_bound`, `upper_bound`)
- Range queries

**Example Problems:**
- Find the kth smallest/largest element
- Remove duplicates from array
- Find floor/ceil of a number in a set

---

### 4. `unordered_set` (Unique, Unordered Elements)

**Use Cases:**
- Fast existence checks for unique elements
- Remove duplicates (order doesn't matter)
- Hashing for quick lookups

**Example Problems:**
- Check if array contains duplicates
- Find intersection of two arrays
- Longest consecutive sequence

---

### 5. `stack` (LIFO)

**Use Cases:**
- Problems with "previous/next greater/smaller" elements
- Balanced parentheses/bracket matching
- Undo operations
- Reverse data

**Example Problems:**
- Next Greater Element
- Valid Parentheses
- Evaluate Reverse Polish Notation
- Stock Span Problem

---

### 6. `queue` (FIFO)

**Use Cases:**
- Level order traversal in trees/graphs (BFS)
- Sliding window problems
- Scheduling tasks

**Example Problems:**
- Print level order traversal of a binary tree
- First negative integer in every window of size k
- Rotten oranges (minimum time to rot all oranges)

---

### 7. `priority_queue` (Heap)

**Use Cases:**
- Always get min/max element efficiently
- Kth largest/smallest element
- Merge k sorted arrays

**Example Problems:**
- Find K largest elements
- Median in a stream
- Merge k sorted lists

---

**Tip:**  
When solving a problem, ask:
- Do I need fast lookups? → `unordered_map`/`unordered_set`
- Do I need order? → `map`/`set`
- Do I need LIFO/FIFO? → `stack`/`queue`
- Do I need to always access min/max?

---