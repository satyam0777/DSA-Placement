# Binary Search: Concept, Identification, and Application

---

## 1. Concept

**Binary Search** is an efficient algorithm to find an element in a **sorted** array or to answer questions about the position of elements.  
It works by repeatedly dividing the search interval in half.

- **Time Complexity:** O(log n)
- **Requirement:** The array (or search space) must be sorted or monotonic (always increasing or decreasing).

---

## 2. How Binary Search Works

1. Set two pointers: `low` (start) and `high` (end).
2. Find the middle index: `mid = low + (high - low) / 2`.
3. Compare the target with `arr[mid]`:
   - If equal, return `mid`.
   - If target < arr[mid], search the left half (`high = mid - 1`).
   - If target > arr[mid], search the right half (`low = mid + 1`).
4. Repeat until `low > high`.

---

## 3. When and Where to Apply Binary Search

### a. Identification

- The array or search space is **sorted** or **monotonic**.
- The problem asks for:
  - Existence of an element.
  - First/last occurrence of an element.
  - Lower/upper bound (smallest/largest index with a property).
  - "Find minimum/maximum value that satisfies a condition."
- The brute force solution is O(n), but you want O(log n).

### b. Typical Problem Statements

- Search for a value in a sorted array.
- Find the first/last occurrence of a value.
- Find the smallest/largest value that meets a condition (e.g., minimum capacity, maximum length).
- Search in rotated sorted arrays.
- Find square root, kth smallest/largest, peak element, etc.

---

## 4. Binary Search Template (Classic)

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}
```

---

## 5. Binary Search for First/Last Occurrence

**First Occurrence:**
```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1; // search left
        } else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
```

---

## 6. Binary Search on Answer (Search Space)

- Sometimes, the array is not given, but you need to find the minimum/maximum value that satisfies a condition.
- **Example:** "Find the minimum capacity to ship packages in D days."
- **Approach:**  
  - Define `low` and `high` as the possible range of answers.
  - For each `mid`, check if it satisfies the condition (using a helper function).
  - Adjust `low` and `high` accordingly.

---

## 7. How to Think and Apply

1. **Is the array/search space sorted or monotonic?**
2. **Can you define a condition that splits the search space?**
3. **Can you check the condition in O(1) or O(n)?**
4. **If yes, try binary search!**

---

## 8. Common Binary Search Mistakes

- Not updating `low` and `high` correctly (infinite loop).
- Off-by-one errors (be careful with `mid`, `low`, `high`).
- Not handling duplicates for first/last occurrence.
- Applying binary search to unsorted data.

---

## 9. Summary Table

| Use Case                        | How to Apply Binary Search                |
|----------------------------------|-------------------------------------------|
| Find element in sorted array     | Classic binary search                     |
| First/last occurrence            | Binary search with answer tracking        |
| Lower/upper bound                | Binary search for smallest/largest index  |
| Search on answer                 | Binary search on value range, not array   |
| Rotated sorted array             | Modified binary search                    |

---

**Summary:**  
Binary search is a must-know technique for sorted/monotonic problems and "search on answer" scenarios.  
Always check if the problem can be reduced to a sorted search space or a monotonic condition!

---
**For learning more in depth and identify the problem , watch Aditya Verma playlist on youtube**