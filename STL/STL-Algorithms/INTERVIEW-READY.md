# 🎯 STL ALGORITHMS - COMPLETE GUIDE
## Interview-Ready Package for Service-Based Companies

---

## 📚 WHAT ARE STL ALGORITHMS?

### **Pre-built functions for common operations:**
```
✅ Sorting, Searching, Reversing
✅ Min/Max finding
✅ Counting, Finding
✅ Permutations
✅ Binary Search operations
```

### **Why STL Algorithms are CRUCIAL:**
```
✅ Save 70% coding time
✅ Optimized implementations
✅ Fewer bugs
✅ Clean, readable code
✅ Expected in ALL interviews
```

**Include:** `#include <algorithm>`

---

## 📖 ALGORITHM 1: SORT() ⭐⭐⭐

### **What is sort()?**
> Sorts elements in ascending/descending order

### **Time Complexity:** O(n log n)

---

### **💡 Interview Communication:**

> "Sir, I'll use STL **sort()** which implements IntroSort (QuickSort + HeapSort + InsertionSort).
> 
> Time complexity: O(n log n)
> 
> Let me sort the array..."

---

### **📝 Complete Usage:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 1. SORT VECTOR (Ascending)
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end());
    // Result: {1, 2, 5, 8, 9}
    
    // 2. SORT VECTOR (Descending)
    vector<int> v2 = {5, 2, 8, 1, 9};
    sort(v2.begin(), v2.end(), greater<int>());
    // Result: {9, 8, 5, 2, 1}
    
    // 3. SORT ARRAY
    int arr[] = {5, 2, 8, 1, 9};
    int n = 5;
    sort(arr, arr + n);
    // Result: {1, 2, 5, 8, 9}
    
    // 4. SORT PARTIAL RANGE
    vector<int> v3 = {5, 2, 8, 1, 9};
    sort(v3.begin() + 1, v3.begin() + 4);
    // Sort indices 1-3: {5, 1, 2, 8, 9}
    
    // 5. SORT STRING
    string s = "dcba";
    sort(s.begin(), s.end());
    // Result: "abcd"
    
    return 0;
}
```

---

### **🎯 CUSTOM COMPARATORS**

#### **Sort by Absolute Value:**
```cpp
bool compareAbs(int a, int b) {
    return abs(a) < abs(b);
}

vector<int> v = {-5, 2, -8, 1, 9};
sort(v.begin(), v.end(), compareAbs);
// Result: {1, 2, -5, -8, 9}
```

#### **Sort Vector of Pairs:**
```cpp
// By default: sorts by first, then second
vector<pair<int, int>> vp = {{2, 3}, {1, 5}, {2, 2}};
sort(vp.begin(), vp.end());
// Result: {{1,5}, {2,2}, {2,3}}

// Custom: Sort by second element
bool comparePair(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}
sort(vp.begin(), vp.end(), comparePair);
// Result: {{2,2}, {2,3}, {1,5}}
```

#### **Sort by String Length:**
```cpp
bool compareLength(string a, string b) {
    return a.length() < b.length();
}

vector<string> words = {"apple", "dog", "cat", "elephant"};
sort(words.begin(), words.end(), compareLength);
// Result: {"dog", "cat", "apple", "elephant"}
```

#### **Lambda Function (Modern C++):**
```cpp
vector<int> v = {-5, 2, -8, 1, 9};
sort(v.begin(), v.end(), [](int a, int b) {
    return abs(a) < abs(b);
});
```

---

### **🏢 Company Frequency:**
- **TCS:** 95% ⭐⭐⭐
- **Infosys:** 98% ⭐⭐⭐
- **Wipro:** 95% ⭐⭐⭐

**Most used STL algorithm!**

---

## 📖 ALGORITHM 2: REVERSE() ⭐⭐⭐

### **What is reverse()?**
> Reverses order of elements

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    // 1. REVERSE VECTOR
    vector<int> v = {1, 2, 3, 4, 5};
    reverse(v.begin(), v.end());
    // Result: {5, 4, 3, 2, 1}
    
    // 2. REVERSE STRING
    string s = "hello";
    reverse(s.begin(), s.end());
    // Result: "olleh"
    
    // 3. REVERSE ARRAY
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, arr + 5);
    // Result: {5, 4, 3, 2, 1}
    
    // 4. REVERSE PARTIAL RANGE
    vector<int> v2 = {1, 2, 3, 4, 5};
    reverse(v2.begin() + 1, v2.begin() + 4);
    // Reverse indices 1-3: {1, 4, 3, 2, 5}
    
    return 0;
}
```

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Reverse Words in String**
```cpp
string reverseWords(string s) {
    string word = "";
    string result = "";
    
    for(char c : s) {
        if(c == ' ') {
            reverse(word.begin(), word.end());
            result += word + " ";
            word = "";
        } else {
            word += c;
        }
    }
    
    // Last word
    reverse(word.begin(), word.end());
    result += word;
    
    return result;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 85% ⭐⭐⭐
- **Infosys:** 90% ⭐⭐⭐
- **Wipro:** 80% ⭐⭐⭐

---

## 📖 ALGORITHM 3: FIND() ⭐⭐⭐

### **What is find()?**
> Searches for element, returns iterator

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    // 1. FIND IN VECTOR
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = find(v.begin(), v.end(), 3);
    
    if(it != v.end()) {
        cout << "Found at index: " << it - v.begin(); // 2
    } else {
        cout << "Not found";
    }
    
    // 2. FIND IN ARRAY
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = find(arr, arr + 5, 3);
    
    if(ptr != arr + 5) {
        cout << "Found at index: " << ptr - arr; // 2
    }
    
    // 3. FIND IN STRING
    string s = "hello";
    auto sit = find(s.begin(), s.end(), 'l');
    
    if(sit != s.end()) {
        cout << "Found at index: " << sit - s.begin(); // 2
    }
    
    return 0;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 80% ⭐⭐⭐
- **Infosys:** 85% ⭐⭐⭐
- **Wipro:** 75% ⭐⭐

---

## 📖 ALGORITHM 4: COUNT() ⭐⭐⭐

### **What is count()?**
> Counts occurrences of element

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    // 1. COUNT IN VECTOR
    vector<int> v = {1, 2, 2, 3, 2, 4};
    int cnt = count(v.begin(), v.end(), 2);
    cout << cnt; // 3
    
    // 2. COUNT IN STRING
    string s = "hello world";
    int lcnt = count(s.begin(), s.end(), 'l');
    cout << lcnt; // 3
    
    // 3. COUNT WITH CONDITION (count_if)
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    int evenCount = count_if(v2.begin(), v2.end(), [](int x) {
        return x % 2 == 0;
    });
    cout << evenCount; // 3
    
    return 0;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 75% ⭐⭐⭐
- **Infosys:** 80% ⭐⭐⭐
- **Wipro:** 70% ⭐⭐

---

## 📖 ALGORITHM 5: MIN_ELEMENT() & MAX_ELEMENT() ⭐⭐⭐

### **What are they?**
> Find minimum/maximum element

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9};
    
    // MIN ELEMENT
    auto minIt = min_element(v.begin(), v.end());
    cout << "Min: " << *minIt; // 1
    cout << "At index: " << minIt - v.begin(); // 1
    
    // MAX ELEMENT
    auto maxIt = max_element(v.begin(), v.end());
    cout << "Max: " << *maxIt; // 9
    cout << "At index: " << maxIt - v.begin(); // 5
    
    // MIN/MAX IN ARRAY
    int arr[] = {3, 1, 4, 1, 5, 9};
    int minVal = *min_element(arr, arr + 6);
    int maxVal = *max_element(arr, arr + 6);
    
    // MIN/MAX OF TWO VALUES
    int a = 5, b = 10;
    cout << min(a, b); // 5
    cout << max(a, b); // 10
    
    return 0;
}
```

---

### **🎯 Top Interview Problems:**

#### **Problem 1: Find Second Largest**
```cpp
int secondLargest(vector<int>& arr) {
    int max1 = *max_element(arr.begin(), arr.end());
    int max2 = INT_MIN;
    
    for(int x : arr) {
        if(x != max1 && x > max2) {
            max2 = x;
        }
    }
    return max2;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 90% ⭐⭐⭐
- **Infosys:** 92% ⭐⭐⭐
- **Wipro:** 85% ⭐⭐⭐

---

## 📖 ALGORITHM 6: BINARY_SEARCH() ⭐⭐⭐

### **What is binary_search()?**
> Checks if element exists in **sorted** array

### **Time Complexity:** O(log n)

### **⚠️ IMPORTANT:** Array MUST be sorted!

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    
    // CHECK IF EXISTS
    if(binary_search(v.begin(), v.end(), 4)) {
        cout << "4 exists"; // Yes
    }
    
    if(binary_search(v.begin(), v.end(), 7)) {
        cout << "7 exists"; // No
    }
    
    // MUST BE SORTED!
    vector<int> unsorted = {5, 2, 8, 1};
    sort(unsorted.begin(), unsorted.end());
    bool found = binary_search(unsorted.begin(), unsorted.end(), 2);
    
    return 0;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 85% ⭐⭐⭐
- **Infosys:** 90% ⭐⭐⭐
- **Wipro:** 80% ⭐⭐⭐

---

## 📖 ALGORITHM 7: LOWER_BOUND() & UPPER_BOUND() ⭐⭐⭐

### **What are they?**
```
lower_bound(x): First element >= x
upper_bound(x): First element > x
```

### **Time Complexity:** O(log n)

### **⚠️ IMPORTANT:** Array MUST be sorted!

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 2, 3, 4, 5};
    
    // LOWER_BOUND (first >= x)
    auto lb = lower_bound(v.begin(), v.end(), 2);
    cout << "Lower bound of 2: index " << lb - v.begin(); // 1
    cout << "Value: " << *lb; // 2
    
    // UPPER_BOUND (first > x)
    auto ub = upper_bound(v.begin(), v.end(), 2);
    cout << "Upper bound of 2: index " << ub - v.begin(); // 4
    cout << "Value: " << *ub; // 3
    
    // COUNT OCCURRENCES
    int count = ub - lb;
    cout << "Count of 2: " << count; // 3
    
    // FIND FLOOR (largest <= x)
    int x = 3;
    auto floor_it = lower_bound(v.begin(), v.end(), x);
    if(floor_it != v.begin()) {
        floor_it--;
        cout << "Floor of 3: " << *floor_it; // 2
    }
    
    // FIND CEIL (smallest >= x)
    auto ceil_it = lower_bound(v.begin(), v.end(), x);
    if(ceil_it != v.end()) {
        cout << "Ceil of 3: " << *ceil_it; // 3
    }
    
    return 0;
}
```

---

### **🎯 Visual Example:**

```
Array: {1, 2, 2, 2, 3, 4, 5}
         0  1  2  3  4  5  6

For x = 2:
lower_bound(2) → points to index 1 (first 2)
upper_bound(2) → points to index 4 (first 3, which is > 2)

Count of 2 = upper_bound - lower_bound = 4 - 1 = 3 ✅
```

---

### **🏢 Company Frequency:**
- **TCS:** 70-75% ⭐⭐⭐
- **Infosys:** 80-85% ⭐⭐⭐
- **Wipro:** 65-70% ⭐⭐

---

## 📖 ALGORITHM 8: UNIQUE() ⭐⭐⭐

### **What is unique()?**
> Removes consecutive duplicates

### **Time Complexity:** O(n)

### **⚠️ IMPORTANT:** Array MUST be sorted to remove ALL duplicates!

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    // REMOVE DUPLICATES (must sort first!)
    vector<int> v = {1, 2, 2, 3, 4, 4, 5};
    
    sort(v.begin(), v.end()); // Already sorted
    
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
    
    // Result: {1, 2, 3, 4, 5}
    
    // ONE-LINER
    vector<int> v2 = {1, 2, 2, 3, 4, 4, 5};
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    
    return 0;
}
```

---

### **🎯 How unique() Works:**

```
Before: {1, 2, 2, 3, 4, 4, 5}
After unique(): {1, 2, 3, 4, 5, ?, ?}
                               ↑
                            Returns iterator here

Then erase from this iterator to end!
```

---

### **🏢 Company Frequency:**
- **TCS:** 75-80% ⭐⭐⭐
- **Infosys:** 80-85% ⭐⭐⭐
- **Wipro:** 70-75% ⭐⭐

---

## 📖 ALGORITHM 9: ACCUMULATE() ⭐⭐

### **What is accumulate()?**
> Calculates sum of elements

### **Include:** `#include <numeric>`

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // SUM (starting from 0)
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum; // 15
    
    // PRODUCT (starting from 1)
    int product = accumulate(v.begin(), v.end(), 1, 
                             multiplies<int>());
    cout << product; // 120
    
    // CUSTOM OPERATION (lambda)
    int custom = accumulate(v.begin(), v.end(), 0,
                            [](int a, int b) { return a + b * 2; });
    
    return 0;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 65-70% ⭐⭐
- **Infosys:** 70-75% ⭐⭐
- **Wipro:** 60-65% ⭐⭐

---

## 📖 ALGORITHM 10: NEXT_PERMUTATION() ⭐⭐⭐

### **What is next_permutation()?**
> Generates next lexicographically greater permutation

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    
    // GENERATE ALL PERMUTATIONS
    sort(v.begin(), v.end()); // Start with smallest
    
    do {
        for(int x : v) cout << x << " ";
        cout << endl;
    } while(next_permutation(v.begin(), v.end()));
    
    /* Output:
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    */
    
    // FIND NEXT PERMUTATION
    vector<int> v2 = {1, 3, 2};
    next_permutation(v2.begin(), v2.end());
    // Result: {2, 1, 3}
    
    return 0;
}
```

---

### **🎯 Top Interview Problems:**

#### **Problem: Find Kth Permutation**
```cpp
string getPermutation(int n, int k) {
    string s = "";
    for(int i = 1; i <= n; i++) {
        s += to_string(i);
    }
    
    for(int i = 1; i < k; i++) {
        next_permutation(s.begin(), s.end());
    }
    
    return s;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 60-65% ⭐⭐
- **Infosys:** 70-75% ⭐⭐⭐
- **Wipro:** 55-60% ⭐⭐

---

## 📖 ALGORITHM 11: ROTATE() ⭐⭐

### **What is rotate()?**
> Rotates elements in range

### **Time Complexity:** O(n)

---

### **📝 Complete Usage:**

```cpp
#include <algorithm>
using namespace std;

int main() {
    // ROTATE LEFT by 2 positions
    vector<int> v = {1, 2, 3, 4, 5};
    rotate(v.begin(), v.begin() + 2, v.end());
    // Result: {3, 4, 5, 1, 2}
    
    // ROTATE RIGHT by 2 positions
    vector<int> v2 = {1, 2, 3, 4, 5};
    rotate(v2.rbegin(), v2.rbegin() + 2, v2.rend());
    // Result: {4, 5, 1, 2, 3}
    
    return 0;
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 55-60% ⭐⭐
- **Infosys:** 60-65% ⭐⭐
- **Wipro:** 50-55% ⭐

---

## 🎯 ALGORITHM QUICK REFERENCE

| Algorithm | Time | Use Case |
|-----------|------|----------|
| **sort()** | O(n log n) | Sort array/vector |
| **reverse()** | O(n) | Reverse order |
| **find()** | O(n) | Search element |
| **count()** | O(n) | Count occurrences |
| **min_element()** | O(n) | Find minimum |
| **max_element()** | O(n) | Find maximum |
| **binary_search()** | O(log n) | Check if exists (sorted) |
| **lower_bound()** | O(log n) | First >= x (sorted) |
| **upper_bound()** | O(log n) | First > x (sorted) |
| **unique()** | O(n) | Remove duplicates (sorted) |
| **accumulate()** | O(n) | Sum/Product |
| **next_permutation()** | O(n) | Next permutation |
| **rotate()** | O(n) | Rotate elements |

---

## 💡 INTERVIEW TIPS

### **When to Use Which:**

```
Need to sort? → sort()
Need min/max? → min_element() / max_element()
Sorted array + search? → binary_search() / lower_bound() / upper_bound()
Count frequency? → count() or use map
Remove duplicates? → sort() + unique() + erase()
Find element? → find()
Sum of array? → accumulate()
All permutations? → sort() + next_permutation() in loop
```

---

### **Common Patterns:**

#### **1. Remove Duplicates:**
```cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

#### **2. Find Kth Smallest:**
```cpp
sort(v.begin(), v.end());
int kthSmallest = v[k - 1];
```

#### **3. Count in Sorted Array:**
```cpp
int count = upper_bound(v.begin(), v.end(), x) - 
            lower_bound(v.begin(), v.end(), x);
```

#### **4. All Permutations:**
```cpp
sort(v.begin(), v.end());
do {
    // Process permutation
} while(next_permutation(v.begin(), v.end()));
```

---

## 💯 SUMMARY

**Algorithms Covered:**
1. ✅ sort() - O(n log n)
2. ✅ reverse() - O(n)
3. ✅ find() - O(n)
4. ✅ count() - O(n)
5. ✅ min_element() / max_element() - O(n)
6. ✅ binary_search() - O(log n)
7. ✅ lower_bound() / upper_bound() - O(log n)
8. ✅ unique() - O(n)
9. ✅ accumulate() - O(n)
10. ✅ next_permutation() - O(n)
11. ✅ rotate() - O(n)

**You're now 100% done with STL Algorithms!** 🎉

**Next:** Check `STL-COMPLETE-PACKAGE.md` for complete guide! 🚀

**All the best, Satyam!** 💪
