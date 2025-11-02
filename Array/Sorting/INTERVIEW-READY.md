#  SORTING - INTERVIEW READY
## Complete Guide for Service-Based Companies

---

##  WHY SORTING IS CRITICAL?

```
✅ 85-95% array problems need sorting!
✅ Foundation for Binary Search
✅ Two Pointer technique requires sorted array
✅ Optimize many O(n²) → O(n log n)
✅ Asked in 90% service-based interviews
```

---

##  SORTING IN C++ STL (YOU MUST KNOW!)

### **Basic Sort - O(n log n)**

```cpp
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 8, 1, 9};
    
    // Sort in ascending order
    sort(arr.begin(), arr.end());
    // arr = {1, 2, 5, 8, 9}
    
    // Sort in descending order
    sort(arr.begin(), arr.end(), greater<int>());
    // arr = {9, 8, 5, 2, 1}
    
    return 0;
}
```

**Time Complexity:** O(n log n) - IntroSort (Quick + Heap + Insertion)  
**Space Complexity:** O(log n)

---

##  PATTERN 1: SORT ARRAY (BASIC)

### **Problem:** Sort array in ascending/descending order

### ** Interview Communication:**

> "Sir, I'll use C++ STL `sort()` function which uses **IntroSort** algorithm.
> 
> **Approach:**
> - Time Complexity: O(n log n)
> - Space Complexity: O(log n)
> - For descending, pass `greater<int>()` comparator"

### **Code:**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ascending order
vector<int> sortAscending(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

// Descending order
vector<int> sortDescending(vector<int>& arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 9, 3};
    
    sortAscending(arr);
    for(int x : arr) cout << x << " ";  // 1 2 3 5 8 9
    cout << endl;
    
    sortDescending(arr);
    for(int x : arr) cout << x << " ";  // 9 8 5 3 2 1
    
    return 0;
}
```

**Company Frequency:**
- TCS: 95% ⭐⭐⭐
- Infosys: 98% ⭐⭐⭐
- Wipro: 90% ⭐⭐⭐

---

##  PATTERN 2: SORT WITH CUSTOM COMPARATOR

### **Problem:** Sort based on custom criteria

### **Use Cases:**
1. Sort by absolute value
2. Sort by frequency
3. Sort pairs by second element
4. Sort strings by length

---

### **Example 1: Sort by Absolute Value**

```cpp
// Custom comparator
bool compareAbs(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    vector<int> arr = {-5, 2, -8, 1, 9, -3};
    
    sort(arr.begin(), arr.end(), compareAbs);
    // arr = {1, 2, -3, -5, -8, 9}
    
    return 0;
}
```

---

### **Example 2: Sort Pairs by Second Element**

```cpp
// Sort pairs by second element
bool comparePair(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main() {
    vector<pair<int,int>> arr = {{1,5}, {2,3}, {3,8}, {4,1}};
    
    sort(arr.begin(), arr.end(), comparePair);
    // arr = {{4,1}, {2,3}, {1,5}, {3,8}}
    
    for(auto p : arr) {
        cout << "{" << p.first << "," << p.second << "} ";
    }
    
    return 0;
}
```

---

### **Example 3: Using Lambda (Modern C++)**

```cpp
int main() {
    vector<int> arr = {-5, 2, -8, 1, 9, -3};
    
    // Lambda comparator (inline)
    sort(arr.begin(), arr.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    
    return 0;
}
```

**Company Frequency:**
- TCS: 75% ⭐⭐
- Infosys: 95% ⭐⭐⭐
- Wipro: 70% ⭐⭐

---

##  PATTERN 3: SORT 0s, 1s, 2s (DUTCH NATIONAL FLAG) 

### **Problem:** Sort array containing only 0s, 1s, and 2s

**This is VERY FAMOUS in interviews!** 

### ** Interview Communication:**

> "Sir, I'll use **Dutch National Flag algorithm** with 3 pointers.
> 
> **Approach:**
> - `low` pointer: marks end of 0s
> - `mid` pointer: current element
> - `high` pointer: marks start of 2s
> 
> **Rules:**
> - If arr[mid] == 0 → swap with low, increment both
> - If arr[mid] == 1 → just increment mid
> - If arr[mid] == 2 → swap with high, decrement high
> 
> **Time Complexity:** O(n) - Single pass
> **Space Complexity:** O(1)"

### **Code:**

```cpp
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {  // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
            // Don't increment mid (need to check swapped element)
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0};
    
    sort012(arr);
    
    for(int x : arr) cout << x << " ";  // 0 0 0 1 1 1 2 2
    
    return 0;
}
```

### **Dry Run:**

```
arr = {0, 1, 2, 0, 1, 2, 1, 0}
       ↑           ↑
      low         high
       mid

Step 1: arr[0] = 0
→ swap(arr[0], arr[0]), low++, mid++
arr = {0, 1, 2, 0, 1, 2, 1, 0}
          ↑        ↑
         low      high
         mid

Step 2: arr[1] = 1
→ mid++
arr = {0, 1, 2, 0, 1, 2, 1, 0}
          ↑        ↑
         low      high
            mid

Step 3: arr[2] = 2
→ swap(arr[2], arr[7]), high--
arr = {0, 1, 0, 0, 1, 2, 1, 2}
          ↑     ↑
         low   high
            mid

... continue until mid > high
```

**Company Frequency:**
- TCS: 85% ⭐⭐⭐
- Infosys: 95% ⭐⭐⭐
- Wipro: 80% ⭐⭐⭐

---

##  PATTERN 4: SORT BY FREQUENCY

### **Problem:** Sort array by frequency (most frequent first)

### ** Interview Communication:**

> "Sir, I'll use **unordered_map** to count frequencies, then **custom comparator** to sort.
> 
> **Approach:**
> 1. Count frequency using map
> 2. Create pairs (element, frequency)
> 3. Sort by frequency (descending)
> 4. If frequency same, sort by value (ascending)
> 
> **Time Complexity:** O(n log n)
> **Space Complexity:** O(n)"

### **Code:**

```cpp
vector<int> sortByFrequency(vector<int>& arr) {
    // Step 1: Count frequency
    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    
    // Step 2: Custom comparator
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (freq[a] != freq[b]) {
            return freq[a] > freq[b];  // Higher frequency first
        }
        return a < b;  // If same frequency, smaller value first
    });
    
    return arr;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 3, 1, 2};
    
    sortByFrequency(arr);
    
    for(int x : arr) cout << x << " ";
    // 2 2 2 1 1 3 3 4 (2 appears 3 times, 1 and 3 appear 2 times, 4 appears 1 time)
    
    return 0;
}
```

**Company Frequency:**
- TCS: 70% ⭐⭐
- Infosys: 85% ⭐⭐⭐
- Wipro: 65% ⭐⭐

---

## PATTERN 5: MERGE TWO SORTED ARRAYS

### **Problem:** Merge two sorted arrays into one sorted array

### ** Interview Communication:**

> "Sir, I'll use **Two Pointer approach**.
> 
> **Approach:**
> - Pointer i for arr1, pointer j for arr2
> - Compare arr1[i] and arr2[j]
> - Add smaller element to result
> - Move respective pointer
> - Add remaining elements
> 
> **Time Complexity:** O(n + m)
> **Space Complexity:** O(n + m)"

### **Code:**

```cpp
vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    vector<int> result;
    
    int i = 0, j = 0;
    
    // Merge while both have elements
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }
    
    // Add remaining elements from arr1
    while (i < n) {
        result.push_back(arr1[i]);
        i++;
    }
    
    // Add remaining elements from arr2
    while (j < m) {
        result.push_back(arr2[j]);
        j++;
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    
    vector<int> result = mergeSortedArrays(arr1, arr2);
    
    for(int x : result) cout << x << " ";  // 1 2 3 4 5 6 7 8
    
    return 0;
}
```

**Company Frequency:**
- TCS: 80% ⭐⭐⭐
- Infosys: 90% ⭐⭐⭐
- Wipro: 75% ⭐⭐⭐

---

##  PATTERN 6: SORT STRING CHARACTERS

### **Problem:** Sort characters in a string

### **Code:**

```cpp
string sortString(string s) {
    sort(s.begin(), s.end());
    return s;
}

int main() {
    string s = "programming";
    
    sort(s.begin(), s.end());
    cout << s;  // aggimmnoprr
    
    return 0;
}
```

**Use Cases:**
- Anagram detection (sort both strings, compare)
- Check if strings are permutations

```cpp
// Check if two strings are anagrams
bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}
```

**Company Frequency:**
- TCS: 75% ⭐⭐⭐
- Infosys: 80% ⭐⭐⭐
- Wipro: 70% ⭐⭐

---

##  PATTERN 7: KTH LARGEST/SMALLEST ELEMENT (Using Sorting)

### **Problem:** Find Kth largest/smallest element

### ** Interview Communication:**

> "Sir, there are 3 approaches:
> 
> **Approach 1: Sort (Simple)**
> - Sort array
> - Return arr[k-1] for kth smallest
> - Return arr[n-k] for kth largest
> - Time: O(n log n), Space: O(1)
> 
> **Approach 2: Min-Heap (Better)**
> - Use priority_queue (covered in Heap section)
> - Time: O(n log k), Space: O(k)
> 
> I'll implement sorting approach for simplicity."

### **Code:**

```cpp
// Kth Smallest
int kthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

// Kth Largest
int kthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    return arr[n - k];
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    
    cout << "3rd smallest: " << kthSmallest(arr, 3) << endl;  // 7
    cout << "2nd largest: " << kthLargest(arr, 2) << endl;    // 15
    
    return 0;
}
```

**Company Frequency:**
- TCS: 85% ⭐⭐⭐
- Infosys: 95% ⭐⭐⭐
- Wipro: 80% ⭐⭐⭐

---

##  PATTERN 8: SORT ARRAY OF STRINGS

### **Problem:** Sort array of strings

### **By Default (Lexicographic Order):**

```cpp
int main() {
    vector<string> arr = {"apple", "banana", "cherry", "date"};
    
    sort(arr.begin(), arr.end());
    
    for(string s : arr) cout << s << " ";
    // apple banana cherry date
    
    return 0;
}
```

### **By Length:**

```cpp
bool compareByLength(string a, string b) {
    return a.length() < b.length();
}

int main() {
    vector<string> arr = {"apple", "hi", "banana", "a"};
    
    sort(arr.begin(), arr.end(), compareByLength);
    
    for(string s : arr) cout << s << " ";
    // a hi apple banana
    
    return 0;
}
```

### **By Length, then Lexicographic:**

```cpp
bool customCompare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;  // If same length, lexicographic
}
```

**Company Frequency:**
- TCS: 70% ⭐⭐
- Infosys: 80% ⭐⭐⭐
- Wipro: 65% ⭐⭐

---

##  PATTERN 9: WAVE SORT

### **Problem:** Sort array in wave form (arr[0] >= arr[1] <= arr[2] >= arr[3]...)

### ** Interview Communication:**

> "Sir, I'll use **sorting + swapping alternate elements**.
> 
> **Approach:**
> 1. Sort the array
> 2. Swap adjacent pairs (i with i+1) for all even i
> 
> **Time Complexity:** O(n log n)
> **Space Complexity:** O(1)"

### **Code:**

```cpp
void waveSort(vector<int>& arr) {
    // Step 1: Sort
    sort(arr.begin(), arr.end());
    
    // Step 2: Swap adjacent pairs
    for (int i = 0; i < arr.size() - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    vector<int> arr = {10, 5, 6, 3, 2, 20, 100, 80};
    
    waveSort(arr);
    
    for(int x : arr) cout << x << " ";
    // 3 2 6 5 20 10 100 80
    // Pattern: 3 >= 2 <= 6 >= 5 <= 20 >= 10 <= 100 >= 80
    
    return 0;
}
```

**Company Frequency:**
- TCS: 55% ⭐
- Infosys: 70% ⭐⭐
- Wipro: 50% ⭐

---

##  PATTERN 10: MINIMUM DIFFERENCE PAIR (After Sorting)

### **Problem:** Find pair with minimum absolute difference

### ** Interview Communication:**

> "Sir, I'll **sort the array first**, then minimum difference will be between **adjacent elements**.
> 
> **Why?** After sorting, closest elements are next to each other!
> 
> **Time Complexity:** O(n log n)
> **Space Complexity:** O(1)"

### **Code:**

```cpp
pair<int,int> minDifferencePair(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    
    int minDiff = INT_MAX;
    int idx = 0;
    
    for (int i = 0; i < arr.size() - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
            idx = i;
        }
    }
    
    return {arr[idx], arr[idx + 1]};
}

int main() {
    vector<int> arr = {10, 3, 20, 12, 15};
    
    auto result = minDifferencePair(arr);
    cout << "Pair with min difference: " << result.first << ", " << result.second;
    // 10, 12 (difference = 2)
    
    return 0;
}
```

**Company Frequency:**
- TCS: 65% ⭐⭐
- Infosys: 75% ⭐⭐
- Wipro: 60% ⭐⭐

---

##  SORTING ALGORITHMS (THEORY - FOR INTERVIEWS)

### **You DON'T need to code these! Just know the theory!**

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space | Stable? |
|-----------|-------------|------------|--------------|-------|---------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | Yes |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | No |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | Yes |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

### **When to Use What?**

```
Small array (n < 10): Insertion Sort
Need stable sort: Merge Sort
Space constraint: Heap Sort or Quick Sort
General purpose: STL sort() (IntroSort - Quick + Heap + Insertion)
```

---

##  INTERVIEW COMMUNICATION TEMPLATE

### **When asked: "How would you sort this array?"**

> "Sir, I'll use **C++ STL `sort()` function**.
> 
> **Why?**
> - Optimized implementation (IntroSort)
> - Time Complexity: O(n log n)
> - Space Complexity: O(log n)
> - Reliable and efficient
> 
> **Code:**
> ```cpp
> sort(arr.begin(), arr.end());
> ```
> 
> If you need descending order:
> ```cpp
> sort(arr.begin(), arr.end(), greater<int>());
> ```
> 
> Would you like me to implement a specific sorting algorithm instead?"

---

##  KEY TAKEAWAYS

```
✅ ALWAYS use sort() from STL in interviews (unless asked for specific algorithm)
✅ sort() uses IntroSort: Quick Sort + Heap Sort + Insertion Sort
✅ Time: O(n log n), Space: O(log n)
✅ For custom criteria, use lambda or comparator function
✅ Dutch National Flag (0s, 1s, 2s) - VERY FAMOUS! ⭐⭐⭐
✅ Sorting enables Binary Search, Two Pointer
✅ Many problems become easier after sorting
```

---

##  COMPANY-WISE TOP PROBLEMS

### **TCS:**
1. Sort array (95%)
2. Sort 0s, 1s, 2s (85%)
3. Merge sorted arrays (80%)

### **Infosys:**
1. Sort with custom comparator (95%)
2. Sort 0s, 1s, 2s (95%)
3. Kth largest element (95%)

### **Wipro:**
1. Sort array (90%)
2. Merge sorted arrays (75%)
3. Anagram using sort (70%)

---

## ✅ FINAL CHECKLIST

```
□ Can use sort() for ascending/descending
□ Know custom comparator (lambda)
□ Can solve 0s, 1s, 2s (Dutch National Flag) ⭐
□ Can merge two sorted arrays
□ Know sorting theory (algorithms comparison)
□ Can sort strings, pairs, vectors
□ Understand stable vs unstable sort
```

---


**All the best** 
