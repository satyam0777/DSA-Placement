# Binary Search - Practice Problems with Complete Solutions

---

##  How to Use This File

1. **Read the problem**
2. **Try to solve it yourself first** (15-20 mins)
3. **Check the "Thinking Process"** section
4. **See the solution**
5. **Code it yourself without looking**

---

## Problem 1: Classic Binary Search ⭐⭐⭐⭐⭐

### **Question:**
Given a sorted array of n integers and a target value, return the index if target is found. If not, return -1.

**Input:** arr = [1, 3, 5, 7, 9, 11], target = 7  
**Output:** 3

---

### **Thinking Process (What to say in interview):**

1. **Understand:** "Array is sorted, need to find index or return -1"
2. **Brute Force:** "I can do linear search O(n)"
3. **Optimize:** "Since sorted, binary search O(log n)"
4. **Approach:** "Two pointers, compare mid with target, update pointers"

---

### **Solution:**

```cpp
int search(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) 
            return mid;
        else if(arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 2: First and Last Position ⭐⭐⭐⭐⭐

### **Question:**
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value. If target is not found, return [-1, -1].

**Input:** arr = [5, 7, 7, 8, 8, 10], target = 8  
**Output:** [3, 4]

---

### **Thinking Process:**

1. **Understand:** "Need first AND last occurrence"
2. **Approach:** "Two binary searches - one for first, one for last"
3. **Key Insight:** 
   - For first: after finding, search LEFT (high = mid - 1)
   - For last: after finding, search RIGHT (low = mid + 1)

---

### **Solution:**

```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1; // Continue searching left
        }
        else if(arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return ans;
}

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1; // Continue searching right
        }
        else if(arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return ans;
}

vector<int> searchRange(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if(first == -1) return {-1, -1};
    
    int last = lastOccurrence(arr, target);
    return {first, last};
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 3: Search in Rotated Sorted Array ⭐⭐⭐⭐⭐

### **Question:**
A sorted array is rotated at some unknown pivot. Given this array and a target, return the index of target or -1.

**Input:** arr = [4, 5, 6, 7, 0, 1, 2], target = 0  
**Output:** 4

---

### **Thinking Process:**

1. **Understand:** "Array was sorted, then rotated. Example: [1,2,3,4,5] → [4,5,1,2,3]"
2. **Key Insight:** "One half will ALWAYS be sorted"
3. **Strategy:**
   - Find which half is sorted (compare arr[low] with arr[mid])
   - Check if target is in the sorted half's range
   - If yes, search there. If no, search other half

---

### **Dry Run:**
```
arr = [4, 5, 6, 7, 0, 1, 2], target = 0

Iteration 1:
low=0, high=6, mid=3
arr[mid]=7, arr[low]=4
arr[low] <= arr[mid] → left half [4,5,6,7] is sorted
Is target(0) in [4,7]? NO
So search right half: low = 4

Iteration 2:
low=4, high=6, mid=5
arr[mid]=1, arr[low]=0
arr[low] <= arr[mid]? NO → right half [1,2] is sorted
Is target(0) in [1,2]? NO
So search left half: high = 4

Iteration 3:
low=4, high=4, mid=4
arr[mid]=0 == target
Return 4
```

---

### **Solution:**

```cpp
int search(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) 
            return mid;
        
        // Check which half is sorted
        if(arr[low] <= arr[mid]) { // Left half is sorted
            // Check if target is in this sorted range
            if(target >= arr[low] && target < arr[mid])
                high = mid - 1; // Search in left
            else
                low = mid + 1; // Search in right
        }
        else { // Right half is sorted
            // Check if target is in this sorted range
            if(target > arr[mid] && target <= arr[high])
                low = mid + 1; // Search in right
            else
                high = mid - 1; // Search in left
        }
    }
    return -1;
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 4: Find Peak Element ⭐⭐⭐⭐

### **Question:**
A peak element is an element that is strictly greater than its neighbors. Find any peak element's index.

**Input:** arr = [1, 2, 3, 1]  
**Output:** 2 (arr[2] = 3 is a peak)

**Input:** arr = [1, 2, 1, 3, 5, 6, 4]  
**Output:** 5 (arr[5] = 6 is a peak, but arr[1] = 2 is also valid)

---

### **Thinking Process:**

1. **Understand:** "Peak means arr[i] > arr[i-1] AND arr[i] > arr[i+1]"
2. **Key Insight:** 
   - If arr[mid] > arr[mid+1], peak is on LEFT (or mid itself)
   - If arr[mid] < arr[mid+1], peak is on RIGHT
3. **Why it works:** "We're always moving towards the increasing slope"

---

### **Solution:**

```cpp
int findPeakElement(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] > arr[mid + 1]) {
            // Peak is on left side or mid itself
            high = mid;
        } else {
            // Peak is on right side
            low = mid + 1;
        }
    }
    return low; // low == high at this point
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 5: Square Root (Floor Value) ⭐⭐⭐⭐⭐

### **Question:**
Given a non-negative integer x, compute and return the square root of x (floor value). You cannot use built-in sqrt().

**Input:** x = 8  
**Output:** 2 (sqrt(8) = 2.828..., floor = 2)

**Input:** x = 4  
**Output:** 2

---

### **Thinking Process:**

1. **Understand:** "Find largest integer whose square ≤ x"
2. **Approach:** "Binary search on answer! Search space is [1, x]"
3. **Condition:** "If mid*mid ≤ x, store ans and try larger (low = mid+1)"
4. **Edge Case:** "x = 0 → return 0"

---

### **Dry Run:**
```
x = 8

low=1, high=8, mid=4
4*4=16 > 8 → too large, high=3

low=1, high=3, mid=2
2*2=4 ≤ 8 → possible answer, ans=2, low=3

low=3, high=3, mid=3
3*3=9 > 8 → too large, high=2

low > high, return ans=2
```

---

### **Solution:**

```cpp
int mySqrt(int x) {
    if(x == 0 || x == 1) return x;
    
    int low = 1, high = x;
    int ans = 1;
    
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;
        
        if(square == x) 
            return mid;
        else if(square < x) {
            ans = mid; // Store potential answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
```

**Time:** O(log n), **Space:** O(1)

**Interview Tip:** Use `long long` for mid*mid to avoid overflow!

---

## Problem 6: Count Occurrences in Sorted Array ⭐⭐⭐⭐

### **Question:**
Given a sorted array with possible duplicates, count the number of occurrences of a target element.

**Input:** arr = [1, 1, 2, 2, 2, 2, 3], target = 2  
**Output:** 4

---

### **Thinking Process:**

1. **Formula:** count = last_index - first_index + 1
2. **Approach:** "Find first and last occurrence using binary search"
3. **Edge Case:** "If not found, return 0"

---

### **Solution:**

```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if(first == -1) return 0;
    
    int last = lastOccurrence(arr, target);
    return last - first + 1;
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 7: Find Minimum in Rotated Sorted Array ⭐⭐⭐⭐

### **Question:**
Suppose an array sorted in ascending order is rotated. Find the minimum element.

**Input:** arr = [4, 5, 6, 7, 0, 1, 2]  
**Output:** 0

**Input:** arr = [3, 4, 5, 1, 2]  
**Output:** 1

---

### **Thinking Process:**

1. **Observation:** "Minimum is always in the unsorted half"
2. **Key Insight:** 
   - If arr[mid] > arr[high] → min is in RIGHT half
   - If arr[mid] < arr[high] → min is in LEFT half (or mid itself)

---

### **Solution:**

```cpp
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] > arr[high]) {
            // Minimum is in right half
            low = mid + 1;
        } else {
            // Minimum is in left half or mid
            high = mid;
        }
    }
    return arr[low];
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 8: Search Insert Position ⭐⭐⭐⭐

### **Question:**
Given a sorted array and a target value, return the index if found. If not, return the index where it would be if it were inserted in order.

**Input:** arr = [1, 3, 5, 6], target = 5  
**Output:** 2

**Input:** arr = [1, 3, 5, 6], target = 2  
**Output:** 1 (would be inserted at index 1)

---

### **Thinking Process:**

1. **This is Lower Bound!** "Smallest index where arr[i] >= target"
2. **Approach:** "Modified binary search"

---

### **Solution:**

```cpp
int searchInsert(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size(); // If target is greater than all elements
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] >= target) {
            ans = mid;
            high = mid - 1; // Try to find smaller index
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

**Time:** O(log n), **Space:** O(1)

---

## Problem 9: Capacity To Ship Packages Within D Days ⭐⭐⭐⭐⭐

### **Question:**
A conveyor belt has packages that must be shipped within D days. Each package has a weight. The ship can carry a maximum weight capacity. Find the minimum capacity needed to ship all packages within D days.

**Input:** weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], D = 5  
**Output:** 15

---

### **Thinking Process:**

1. **Pattern Recognition:** "Find MINIMUM capacity that satisfies condition → BS on Answer!"
2. **Search Space:** 
   - Minimum capacity = max(weights) (can't be less than heaviest package)
   - Maximum capacity = sum(weights) (ship everything in 1 day)
3. **Condition Check:** "Can we ship with this capacity in D days?"
4. **Update:** "If yes, try smaller capacity. If no, need larger capacity"

---

### **Helper Function:**

```cpp
bool canShip(vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1;
    int currentLoad = 0;
    
    for(int weight : weights) {
        if(currentLoad + weight > capacity) {
            // Need new day
            daysNeeded++;
            currentLoad = weight;
        } else {
            currentLoad += weight;
        }
    }
    return daysNeeded <= days;
}
```

---

### **Solution:**

```cpp
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(canShip(weights, days, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller capacity
        } else {
            low = mid + 1; // Need larger capacity
        }
    }
    return ans;
}
```

**Time:** O(n * log(sum - max)), **Space:** O(1)

---

## Problem 10: Find Floor and Ceil ⭐⭐⭐

### **Question:**
Given a sorted array and a target, find:
- **Floor:** Largest element ≤ target
- **Ceil:** Smallest element ≥ target

**Input:** arr = [1, 2, 8, 10, 11, 12, 19], target = 5  
**Output:** Floor = 2, Ceil = 8

---

### **Thinking Process:**

1. **Floor:** "Largest element ≤ target → search right when arr[mid] ≤ target"
2. **Ceil:** "Smallest element ≥ target → search left when arr[mid] ≥ target"

---

### **Solution:**

```cpp
int findFloor(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1; // Try to find larger floor
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1; // Try to find smaller ceil
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> findFloorAndCeil(vector<int>& arr, int target) {
    return {findFloor(arr, target), findCeil(arr, target)};
}
```

**Time:** O(log n), **Space:** O(1)

---

## 🎯 Quick Revision Checklist

Before your interview, make sure you can:

- [ ] Write classic binary search in 1 minute
- [ ] Explain when to use binary search
- [ ] Code first/last occurrence without looking
- [ ] Solve rotated array problem
- [ ] Understand BS on Answer pattern
- [ ] Handle edge cases (empty array, single element, not found)
- [ ] Avoid infinite loops (always update low/high properly)
- [ ] Use `low + (high - low) / 2` to avoid overflow

---

## 📚 Practice Schedule (1 Week Plan)

**Day 1-2:** Problems 1, 2, 5 (Basic patterns)  
**Day 3-4:** Problems 3, 4, 6 (Medium patterns)  
**Day 5-6:** Problems 7, 8, 9 (Advanced patterns)  
**Day 7:** Solve all 10 problems again without looking at solutions

---
**If you have still doubt watch Striver and Aditya Verma Playlist they explain much more in depth explaination**

---

**Remember:** In interviews, explaining your thought process is MORE important than getting the perfect solution immediately. Show them how you think!

Good luck! 
