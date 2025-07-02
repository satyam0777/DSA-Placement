# C++ Concepts and Problem-Solving for Placement Interviews

---

## 1. Input/Output and Data Types

- Use `cin`, `cout` for fast input/output.
- Know basic data types: `int`, `long long`, `float`, `double`, `char`, `string`, `bool`.
- Use `vector`, `array`, `pair`, and STL containers for flexible data storage.

**Example:**
```cpp
int n;
cin >> n;
vector<int> arr(n);
for(int &x : arr) cin >> x;
```

---

## 2. Functions and Scope

- Write reusable functions.
- Pass by value, reference (`&`), and const reference (`const &`).
- Understand variable scope and lifetime.

**Example:**
```cpp
void printVector(const vector<int>& v) {
    for(int x : v) cout << x << " ";
}
```

---

## 3. Arrays and Vectors

- Use arrays for fixed size, `vector` for dynamic size.
- Know how to resize, access, and traverse.

**Example:**
```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
```

---

## 4. Strings

- Use `string` for text manipulation.
- Common methods: `size()`, `substr()`, `find()`, `push_back()`, `pop_back()`, `reverse()`.

**Example:**
```cpp
string s = "hello";
reverse(s.begin(), s.end());
```

---

## 5. STL Containers

- `vector`, `array`, `deque`, `stack`, `queue`, `priority_queue`, `set`, `unordered_set`, `map`, `unordered_map`.
- Know when to use each (see earlier notes).

---

## 6. Sorting and Searching

- Use `sort(v.begin(), v.end())` for sorting.
- Use `binary_search`, `lower_bound`, `upper_bound` for searching in sorted containers.

**Example:**
```cpp
sort(v.begin(), v.end());
if(binary_search(v.begin(), v.end(), 5)) { /* found */ }
```

---

## 7. Pairs and Tuples

- Store related data together.
- Use `make_pair`, `tie`, and structured bindings (C++17+).

**Example:**
```cpp
pair<int, string> p = {1, "abc"};
auto [num, str] = p;
```

---

## 8. Hashing and Frequency

- Use `unordered_map` for counting and fast lookup.
- Use `unordered_set` for unique elements.

---

## 9. Algorithms

- Use STL algorithms: `sort`, `reverse`, `find`, `count`, `accumulate`, `max_element`, `min_element`, etc.

**Example:**
```cpp
int sum = accumulate(v.begin(), v.end(), 0);
int mx = *max_element(v.begin(), v.end());
```

---

## 10. Problem-Solving Patterns

- **Two Pointer:** Sorted arrays, pair/triplet problems.
- **Sliding Window:** Subarray/substring with property.
- **Prefix Sum:** Range sum queries, subarray sum.
- **Hashing:** Frequency, existence, grouping.
- **Stack/Queue:** Next greater/smaller, balanced parentheses.
- **Binary Search:** Search in sorted, optimization problems.
- **Recursion/Backtracking:** Combinatorial, tree/graph traversal.
- **Dynamic Programming:** Optimal substructure, overlapping subproblems.

---

## 11. Practice Problems (with C++)

- Reverse an array/string.
- Find the maximum/minimum in an array.
- Check if a string is a palindrome.
- Find the frequency of elements.
- Find the pair with a given sum.
- Implement stack/queue using STL.
- Find the longest subarray with sum k.
- Sort a vector of pairs by second element.
- Find the intersection/union of two arrays.
- Implement binary search.



---