# Binary Search - Interview Preparation Guide (Service-Based Companies <10 LPA)

---

## 🎯 What Service-Based Companies Actually Ask

**Reality Check:**
- TCS, Wipro, Infosys, Cognizant, Capgemini, Accenture, HCL, Tech Mahindra
- They focus on **basic to medium** level problems
- They want to see **your thinking process** more than the perfect solution
- Communication > Perfect Code

---

## 🗣️ HOW TO TALK THROUGH BINARY SEARCH IN INTERVIEW

### **Opening Statement (First 30 seconds)**

**When you see the problem, say this:**

> "Let me analyze this problem. I can see that [explain what you observe]. 
> The first approach that comes to mind is [brute force]. 
> This would take O(n) time. But since [mention sorted/monotonic property], 
> I think we can optimize this using binary search to O(log n)."

**Example:**
> "I need to find an element in a sorted array. The brute force would be linear search O(n). 
> But since the array is sorted, I can use binary search which will give me O(log n) time complexity."

---

## 💭 STEP-BY-STEP THINKING PROCESS (Say this out loud!)

### **Step 1: Problem Understanding (30-45 seconds)**
```
Say: "Let me clarify the problem..."
- What is the input? (array size, sorted?, duplicates?)
- What is the output? (index, value, boolean, count?)
- Any edge cases? (empty array, single element, target not found?)

Example: "So I need to find the target element. The array is sorted. 
If found, return index, else return -1. Got it!"
```

### **Step 2: Identify Binary Search Pattern (20 seconds)**
```
Say: "I need to identify which binary search pattern this is..."

Ask yourself:
✓ Is array sorted? → Classic BS
✓ Find first/last occurrence? → Modified BS with answer variable
✓ Find minimum/maximum that satisfies condition? → BS on Answer
✓ Rotated array? → Modified BS with rotation handling
```

### **Step 3: Explain Your Approach (45 seconds)**
```
Say: "Here's my approach..."

Template:
"I'll use two pointers, low and high, starting at 0 and n-1.
In each iteration, I'll calculate mid and check [your condition].
If [condition], I'll update [low/high/answer].
I'll continue until low crosses high.
Finally, I'll return [answer/index/-1]."
```

### **Step 4: Dry Run (1 minute)**
```
Say: "Let me dry run with an example..."

Example: arr = [1, 3, 5, 7, 9], target = 5
- Initial: low=0, high=4
- Iteration 1: mid=2, arr[2]=5, found! return 2

Show this on paper/whiteboard!
```

### **Step 5: Code (2-3 minutes)**
```
Say: "Now I'll write the code..."
(Use templates below)
```

### **Step 6: Edge Cases & Optimization (30 seconds)**
```
Say: "Let me verify edge cases..."
- Empty array → return -1
- Single element → check if it matches
- Target not present → return -1
- All elements same → handle properly

"The time complexity is O(log n) and space is O(1)."
```

---

## 📚 MUST-KNOW PATTERNS FOR SERVICE-BASED COMPANIES

### **Pattern 1: Classic Binary Search**

**When to use:** Find element in sorted array

**Template:**
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2; // Prevent overflow
        
        if(arr[mid] == target) 
            return mid;
        else if(arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1; // Not found
}
```

**Interview Question Example:**
"Given a sorted array, find if target exists."

**What to say:**
> "This is a classic binary search. I'll maintain low and high pointers, 
> calculate mid, and compare with target. If equal, return index. 
> If target is greater, search right half by moving low. 
> Else search left half by moving high."

---

### **Pattern 2: First Occurrence / Lower Bound**

**When to use:** Find first position where element appears or could be inserted

**Template:**
```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            ans = mid;           // Store potential answer
            high = mid - 1;      // Continue searching left
        }
        else if(arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return ans;
}
```

**What to say:**
> "Even after finding the element, I won't stop. I'll store the index in 'ans' 
> and continue searching in the left half to find the first occurrence."

---

### **Pattern 3: Last Occurrence / Upper Bound**

**Template:**
```cpp
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) {
            ans = mid;           // Store potential answer
            low = mid + 1;       // Continue searching right
        }
        else if(arr[mid] < target) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return ans;
}
```

**What to say:**
> "Similar to first occurrence, but here I search in the right half 
> after finding the element to get the last occurrence."

---

### **Pattern 4: Count Occurrences**

**Interview Trick:** First + Last occurrence

```cpp
int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if(first == -1) return 0;
    
    int last = lastOccurrence(arr, target);
    return last - first + 1;
}
```

**What to say:**
> "I can find count by: count = last_index - first_index + 1. 
> I'll use binary search twice to find both positions."

---

### **Pattern 5: Search in Rotated Sorted Array**

**Very Common in Interviews!**

**Template:**
```cpp
int searchRotated(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == target) return mid;
        
        // Check which half is sorted
        if(arr[low] <= arr[mid]) { // Left half is sorted
            if(target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else { // Right half is sorted
            if(target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
```

**What to say:**
> "In a rotated sorted array, one half will always be sorted. 
> I'll identify which half is sorted by comparing arr[low] with arr[mid]. 
> Then I'll check if target lies in that sorted range. 
> If yes, search there, else search the other half."

---

### **Pattern 6: Peak Element**

**Template:**
```cpp
int findPeakElement(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] > arr[mid + 1])
            high = mid; // Peak is on left or mid itself
        else
            low = mid + 1; // Peak is on right
    }
    return low; // or high, both are same
}
```

**What to say:**
> "A peak is an element greater than its neighbors. 
> If arr[mid] > arr[mid+1], peak is on left side (or mid itself). 
> Otherwise, peak is on right side. I'll keep narrowing until low == high."

---

### **Pattern 7: Binary Search on Answer (IMPORTANT!)**

**When to use:** "Find minimum/maximum value that satisfies a condition"

**Example Problem:** Find minimum capacity to ship packages in D days

**Template:**
```cpp
bool canShipWithCapacity(vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1, currentLoad = 0;
    
    for(int weight : weights) {
        if(currentLoad + weight > capacity) {
            daysNeeded++;
            currentLoad = weight;
        } else {
            currentLoad += weight;
        }
    }
    return daysNeeded <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(canShipWithCapacity(weights, days, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller capacity
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

**What to say:**
> "This is 'Binary Search on Answer' pattern. I'm not searching in an array, 
> but searching for the optimal capacity value. 
> My search space is from [max element] to [sum of all elements].
> For each mid capacity, I'll check if I can ship within D days using a helper function.
> If yes, I'll try smaller capacity (move high). If no, I need larger capacity (move low)."

---

## 🎓 TOP 10 PROBLEMS FOR SERVICE-BASED INTERVIEWS

### **1. Search in Sorted Array** ⭐⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** Classic BS
- **Question:** Find target in sorted array

### **2. First and Last Position** ⭐⭐⭐⭐⭐
- **Difficulty:** Medium
- **Pattern:** First/Last Occurrence
- **Question:** Find first and last position of target in sorted array

### **3. Search in Rotated Sorted Array** ⭐⭐⭐⭐⭐
- **Difficulty:** Medium
- **Pattern:** Modified BS
- **Asked by:** TCS, Wipro, Cognizant

### **4. Find Peak Element** ⭐⭐⭐⭐
- **Difficulty:** Medium
- **Pattern:** Peak finding
- **Asked by:** Infosys, Capgemini

### **5. Square Root (floor value)** ⭐⭐⭐⭐⭐
- **Difficulty:** Easy-Medium
- **Pattern:** BS on Answer
- **Question:** Find floor of sqrt(x) without using sqrt()

```cpp
int mySqrt(int x) {
    if(x == 0) return 0;
    int low = 1, high = x, ans = 1;
    
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;
        
        if(sq == x) return mid;
        else if(sq < x) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
```

### **6. Find Minimum in Rotated Sorted Array** ⭐⭐⭐⭐
- **Difficulty:** Medium
- **Pattern:** Modified BS

```cpp
int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }
    return arr[low];
}
```

### **7. Search Insert Position** ⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** Lower Bound
- **Question:** Find index where target should be inserted

### **8. Count of an Element in Sorted Array** ⭐⭐⭐⭐
- **Difficulty:** Easy
- **Pattern:** First + Last Occurrence

### **9. Find Floor and Ceil** ⭐⭐⭐
- **Difficulty:** Medium
- **Pattern:** Modified BS
- **Floor:** Largest element ≤ target
- **Ceil:** Smallest element ≥ target

### **10. Aggressive Cows / Book Allocation** ⭐⭐⭐
- **Difficulty:** Hard (but appears in some companies)
- **Pattern:** BS on Answer
- **Common variant:** Painter's partition, split array

---

## 🚨 COMMON MISTAKES & HOW TO AVOID

### **Mistake 1: Infinite Loop**
```cpp
// ❌ WRONG
while(low <= high) {
    if(condition) low = mid;  // Can cause infinite loop
}

// ✅ CORRECT
while(low <= high) {
    if(condition) low = mid + 1;  // Always change pointer
}
```

### **Mistake 2: Integer Overflow**
```cpp
// ❌ WRONG
int mid = (low + high) / 2;  // Can overflow

// ✅ CORRECT
int mid = low + (high - low) / 2;
```

### **Mistake 3: Wrong Condition for First/Last**
```cpp
// For FIRST occurrence: high = mid - 1
// For LAST occurrence: low = mid + 1
// Don't mix them up!
```

---

## 💡 INTERVIEW TIPS & TRICKS

### **1. Always Communicate**
```
❌ Don't: Silently write code
✅ Do: "I'm using binary search because the array is sorted..."
```

### **2. Draw on Paper**
```
Show the interviewer:
- Array with indices
- low, mid, high pointers
- How they move in each iteration
```

### **3. Handle Edge Cases First**
```cpp
// Say this out loud:
"Let me handle edge cases first..."

if(arr.empty()) return -1;
if(arr.size() == 1) return arr[0] == target ? 0 : -1;
```

### **4. Dry Run = Bonus Points**
```
"Let me verify with an example:
arr = [1, 3, 5, 7, 9], target = 5
Step 1: low=0, high=4, mid=2, arr[2]=5 ✓"
```

### **5. Mention Complexity**
```
"The time complexity is O(log n) because we're halving the search space.
Space complexity is O(1) as we're using only a few variables."
```

### **6. If Stuck, Start with Brute Force**
```
"The brute force would be to check each element O(n).
But since it's sorted, I can optimize using binary search O(log n)."
```

---

## 📝 INTERVIEW CHEAT SHEET (Memorize This!)

| Problem Type | Key Indicator | Update Strategy |
|--------------|---------------|-----------------|
| Classic Search | "Find element" | Standard low/high update |
| First Occurrence | "Find first", "lower bound" | After match: high = mid - 1 |
| Last Occurrence | "Find last", "upper bound" | After match: low = mid + 1 |
| BS on Answer | "Find minimum/maximum that satisfies" | Check condition, update accordingly |
| Rotated Array | "Rotated sorted array" | Find sorted half, check range |
| Peak Element | "Greater than neighbors" | Compare mid with mid+1 |

---

## 🎯 FINAL PREP CHECKLIST

**Before Interview:**
- [ ] Practice these 10 problems 3 times each
- [ ] Be able to write classic BS in 1 minute
- [ ] Memorize first/last occurrence templates
- [ ] Practice explaining out loud
- [ ] Review common mistakes

**During Interview:**
- [ ] Clarify problem (input/output/edge cases)
- [ ] Identify BS pattern
- [ ] Explain approach before coding
- [ ] Dry run with example
- [ ] Mention time/space complexity
- [ ] Handle edge cases

---

## 🗣️ SAMPLE INTERVIEW DIALOGUE

**Interviewer:** "Find the first occurrence of target in a sorted array with duplicates."

**You:** 
> "Okay, so I need to find the FIRST occurrence. Let me clarify - the array is sorted and may have duplicates. I need to return the index of the first occurrence, or -1 if not found. Correct?"

**Interviewer:** "Yes."

**You:** 
> "Great. The brute force would be linear search O(n). But since the array is sorted, I can use binary search to get O(log n). 
>
> Here's my approach: I'll use the standard binary search template, but with a modification. When I find the target at mid, instead of returning immediately, I'll store this index in an 'ans' variable and continue searching in the LEFT half by setting high = mid - 1. This ensures I find the leftmost occurrence.
>
> Let me dry run with an example: arr = [1, 2, 2, 2, 3], target = 2
> - Initially: low=0, high=4
> - Iteration 1: mid=2, arr[2]=2, found! Store ans=2, search left: high=1
> - Iteration 2: mid=0, arr[0]=1 < 2, search right: low=1
> - Iteration 3: mid=1, arr[1]=2, found! Update ans=1, search left: high=0
> - low > high, return ans=1 ✓
>
> Now I'll code this..."

**[Write code]**

**You:** 
> "Let me check edge cases: empty array returns -1, single element works correctly, target not found returns -1. The time complexity is O(log n) and space is O(1). Does this look good?"

---

**Remember:** Service-based companies value **communication, logical thinking, and clarity** over perfect optimal solutions. Show your thought process, stay calm, and explain each step!

---

**Good luck with your placement! 🚀**
