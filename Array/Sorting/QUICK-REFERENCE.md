#  SORTING QUICK REFERENCE
## One-Page Cheat Sheet for Interviews

---

##  ESSENTIAL SORTING CODE (COPY-PASTE READY)

### **1. Basic Sort (Ascending)**
```cpp
sort(arr.begin(), arr.end());
```

### **2. Sort Descending**
```cpp
sort(arr.begin(), arr.end(), greater<int>());
```

### **3. Custom Comparator (Lambda)**
```cpp
// Sort by absolute value
sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b);
});
```

### **4. Sort 0s, 1s, 2s (MOST ASKED!) ⭐⭐⭐**
```cpp
void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++; mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {  // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
```

### **5. Merge Two Sorted Arrays**
```cpp
vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    
    return result;
}
```

### **6. Kth Largest/Smallest**
```cpp
int kthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int kthLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - k];
}
```

---

##  INTERVIEW SCRIPTS

### **When asked: "Sort this array"**

> "Sir, I'll use C++ STL `sort()` function.
> 
> Time Complexity: O(n log n)
> Space Complexity: O(log n)
> 
> Code: `sort(arr.begin(), arr.end());`"

### **When asked: "Sort 0s, 1s, 2s"**

> "Sir, I'll use **Dutch National Flag algorithm** with 3 pointers.
> 
> low (end of 0s), mid (current), high (start of 2s)
> 
> - If arr[mid] == 0 → swap with low, increment both
> - If arr[mid] == 1 → increment mid
> - If arr[mid] == 2 → swap with high, decrement high
> 
> Time: O(n) - Single pass
> Space: O(1)"

---

##  TOP 5 PATTERNS

| Pattern | When to Use | Example |
|---------|-------------|---------|
| **STL sort()** | Any unsorted array | Sort ascending/descending |
| **Dutch Flag** | 3 distinct values (0,1,2) | Sort colors |
| **Merge** | Two sorted arrays | Merge sorted arrays |
| **Custom Comparator** | Special sorting criteria | Sort by frequency, length |
| **After Sorting** | Optimization | Kth largest, Min difference pair |

---

##  SORTING ALGORITHMS (THEORY ONLY)

| Algorithm | Time (Avg) | Space | Stable? | Use Case |
|-----------|------------|-------|---------|----------|
| **Bubble** | O(n²) | O(1) | Yes | Teaching (don't use!) |
| **Selection** | O(n²) | O(1) | No | Teaching (don't use!) |
| **Insertion** | O(n²) | O(1) | Yes | Small/nearly sorted |
| **Merge** | O(n log n) | O(n) | Yes | Need stable sort |
| **Quick** | O(n log n) | O(log n) | No | General purpose |
| **Heap** | O(n log n) | O(1) | No | Memory constraint |

**In interviews:** Just use `sort()` unless asked for specific algorithm!

---

##  COMPANY TOP 3

### **TCS:**
1. Basic sort (95%)
2. Sort 0,1,2 (85%)
3. Merge sorted (80%)

### **Infosys:**
1. Custom comparator (95%)
2. Sort 0,1,2 (95%)
3. Kth largest (95%)

### **Wipro:**
1. Basic sort (90%)
2. Merge sorted (75%)
3. Anagram (sort strings) (70%)

---

##  COMMON MISTAKES

```
❌ Not knowing STL sort() syntax
   ✅ sort(arr.begin(), arr.end());

❌ Implementing bubble sort in interviews
   ✅ Use STL sort() unless asked

❌ Wrong Dutch Flag logic
   ✅ Don't increment mid when swapping with high!

❌ Forgetting greater<int>() for descending
   ✅ sort(arr.begin(), arr.end(), greater<int>());
```

---

##  KEY FACTS

```
✅ sort() uses IntroSort (Quick + Heap + Insertion)
✅ Time: O(n log n), Space: O(log n)
✅ Dutch Flag = 0s, 1s, 2s sorting in O(n)
✅ Sorting enables Binary Search, Two Pointer
✅ Custom comparator uses lambda or function
✅ Stable sort preserves relative order
```

---

##  15-MIN EMERGENCY REVISION

1. **sort() basic** - 3 min
2. **Sort 0,1,2 (Dutch Flag)** - 5 min ⭐ MOST IMPORTANT
3. **Merge sorted arrays** - 4 min
4. **Custom comparator** - 3 min

---

##  CHECKLIST

```
□ Can use sort() ascending/descending
□ Know Dutch National Flag (0,1,2) ⭐
□ Can merge two sorted arrays
□ Can write lambda comparator
□ Know Kth largest using sort
□ Know sorting theory (algorithms table)
```

---


**You're Sorting-Ready!** 
