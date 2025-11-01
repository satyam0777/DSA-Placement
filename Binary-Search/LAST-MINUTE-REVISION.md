# Binary Search - Last Minute Revision (1 Hour Before Interview)

---

##  5-MINUTE QUICK RECALL

### **When to Use Binary Search?**
1. Array is **sorted** ✓
2. Need to find element/position in **O(log n)** ✓
3. "Find minimum/maximum that satisfies condition" ✓
4. Can define a **monotonic** search space ✓

### **3 Core Patterns:**
1. **Classic BS** → Find element
2. **First/Last Occurrence** → Find boundary
3. **BS on Answer** → Find optimal value (not searching in array)

---

##  MUST-KNOW TEMPLATES (Copy-Paste Ready)

### **Template 1: Classic Binary Search**
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

---

### **Template 2: First Occurrence**
```cpp
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            ans = mid;
            high = mid - 1; // ← KEY: Continue left
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
```

---

### **Template 3: Last Occurrence**
```cpp
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1; // ← KEY: Continue right
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
```

---

### **Template 4: Binary Search on Answer**
***watch Striver's - TakeUForword for this**
```cpp
bool canSolveWithValue(int value) {
    // Check if this value satisfies the condition
    // Return true/false
}

int binarySearchOnAnswer() {
    int low = MIN_POSSIBLE, high = MAX_POSSIBLE;
    int ans = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(canSolveWithValue(mid)) {
            ans = mid;
            high = mid - 1; // Try smaller (for minimum)
            // OR low = mid + 1; // Try larger (for maximum)
        } else {
            low = mid + 1; // Need larger value
        }
    }
    return ans;
}
```

---

##  INTERVIEW OPENING SCRIPT (Memorize!)

**When you see the problem:**

> "Let me understand the problem first. [Clarify input/output/edge cases]
> 
> The brute force approach would be [mention O(n) solution].
> 
> However, I notice that [array is sorted / search space is monotonic / we can define a condition]. This suggests we can use binary search to optimize to O(log n).
> 
> Here's my approach: [Explain in 3-4 sentences]
> 
> Let me verify with a quick example... [Dry run]
> 
> Now I'll code this..."

---

##  INSTANT PATTERN RECOGNITION

| Problem Asks | Pattern | Key Point |
|--------------|---------|-----------|
| "Find element in sorted array" | Classic BS | Standard template |
| "Find **first** occurrence" | Modified BS | After match: `high = mid - 1` |
| "Find **last** occurrence" | Modified BS | After match: `low = mid + 1` |
| "Count occurrences" | First + Last | `count = last - first + 1` |
| "Rotated sorted array" | Modified BS | Find sorted half |
| "Peak element" | Modified BS | Compare mid with mid+1 |
| "Find **minimum** that satisfies" | BS on Answer | Search space = [min, max] |
| "Sqrt / Nth root" | BS on Answer | Search space = [1, x] |
| "Capacity / Allocation" | BS on Answer | Use helper to check |

---

## 🚨 AVOID THESE MISTAKES

### **Mistake #1: Infinite Loop**
```cpp
// ❌ WRONG - Can cause infinite loop
while(low <= high) {
    if(condition) low = mid;  // ← DANGER!
}

// ✅ CORRECT - Always +1 or -1
while(low <= high) {
    if(condition) low = mid + 1;  // ← SAFE
}
```

### **Mistake #2: Integer Overflow**
```cpp
// ❌ WRONG
int mid = (low + high) / 2;  // Can overflow if low+high > INT_MAX

// ✅ CORRECT
int mid = low + (high - low) / 2;
```

### **Mistake #3: Wrong Condition**
```cpp
// For FIRST: high = mid - 1 (search left)
// For LAST: low = mid + 1 (search right)
// Don't mix them!
```

### **Mistake #4: Forgetting Edge Cases**
```cpp
// Always check:
if(arr.empty()) return -1;
if(arr.size() == 1) // handle single element
```

---

## 🎓 TOP 5 INTERVIEW PROBLEMS (MUST PRACTICE)

### **1. Search in Sorted Array**
- Pattern: Classic BS
- Time: O(log n)
- **Asked by:** All companies

### **2. First and Last Position**
- Pattern: First/Last Occurrence
- Time: O(log n)
- **Asked by:** TCS, Wipro, Infosys

### **3. Search in Rotated Sorted Array**
- Pattern: Modified BS
- Key: Find sorted half
- **Asked by:** TCS, Cognizant, Capgemini

### **4. Square Root (without sqrt())**
- Pattern: BS on Answer
- Search space: [1, x]
- **Asked by:** Wipro, Infosys

### **5. Peak Element**
- Pattern: Modified BS
- Compare mid with mid+1
- **Asked by:** Infosys, Capgemini

---

## 📝 CODE SNIPPETS (Quick Copy)

### **Rotated Sorted Array**
```cpp
int search(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        
        if(arr[low] <= arr[mid]) { // Left sorted
            if(target >= arr[low] && target < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else { // Right sorted
            if(target > arr[mid] && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
```

### **Square Root**
```cpp
int mySqrt(int x) {
    if(x == 0) return 0;
    int low = 1, high = x, ans = 1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long sq = mid * mid;
        if(sq == x) return mid;
        else if(sq < x) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }
    return ans;
}
```

### **Peak Element**
```cpp
int findPeakElement(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] > arr[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
```

---

## 💬 COMMUNICATION TIPS

### **What to Say:**
✅ "I notice the array is sorted, so binary search would be optimal"  
✅ "Let me dry run this with an example"  
✅ "The time complexity is O(log n) and space is O(1)"  
✅ "I should handle edge cases like empty array"  

### **What NOT to Say:**
❌ *Silently starts coding*  
❌ "I'm not sure if this will work"  
❌ "Binary search is confusing"  

### **If You're Stuck:**
1. Say: "Let me think about the brute force first..."
2. Then: "Since it's sorted, I can optimize with binary search"
3. Draw on paper: Show low, mid, high pointers
4. Explain: "I'll check the mid element and decide which half to search"

---

## 🎯 CONFIDENCE BOOSTERS

### **Things You KNOW:**
✓ Binary search works on sorted data  
✓ It reduces search space by half each time  
✓ Time complexity is O(log n)  
✓ Three main patterns: Classic, First/Last, BS on Answer  
✓ Always update low/high to avoid infinite loops  

### **Things That Are OKAY:**
✓ Taking 1-2 minutes to think before coding  
✓ Asking clarifying questions  
✓ Explaining your thought process  
✓ Dry running on paper  
✓ Mentioning edge cases before coding  

---

## 🔥 LAST 5 MINUTES BEFORE INTERVIEW

1. **Take 3 deep breaths** 🧘
2. **Read classic BS template once** 👀
3. **Remember:** Communication > Perfect code
4. **Smile and be confident** 😊
5. **You've got this!** 💪

---

## ⚡ EMERGENCY CHEAT SHEET

```cpp
// FIRST occurrence → high = mid - 1 after match
// LAST occurrence → low = mid + 1 after match
// mid = low + (high - low) / 2
// while(low <= high) for most cases
// while(low < high) for peak element
// BS on Answer: define canSolve(mid) function
```

---

## 🎤 SAMPLE INTERVIEW Q&A

**Q: "Why binary search?"**  
**A:** "Because the array is sorted, we can eliminate half the search space in each step, giving us O(log n) instead of O(n)."

**Q: "What if duplicates exist?"**  
**A:** "For first/last occurrence, I'll continue searching even after finding the target to get the exact boundary."

**Q: "Why low + (high - low) / 2?"**  
**A:** "To prevent integer overflow that could occur with (low + high) / 2 for large values."

**Q: "What's your approach for rotated array?"**  
**A:** "One half is always sorted. I'll identify which half is sorted, check if target is in that range, and search accordingly."

---

## 📊 COMPLEXITY QUICK REFERENCE

| Operation | Time | Space |
|-----------|------|-------|
| Classic BS | O(log n) | O(1) |
| First/Last | O(log n) | O(1) |
| BS on Answer | O(n log k)* | O(1) |
| Rotated Array | O(log n) | O(1) |

*k = range of answer, n = size for checking condition

---

## 🏆 FINAL CHECKLIST

**Before You Start Coding:**
- [ ] Understood the problem completely
- [ ] Identified the BS pattern
- [ ] Explained approach to interviewer
- [ ] Did a quick mental dry run

**While Coding:**
- [ ] Using `low + (high - low) / 2`
- [ ] Updating low/high correctly
- [ ] Handling edge cases
- [ ] Writing clean, readable code

**After Coding:**
- [ ] Dry run with example
- [ ] Check edge cases (empty, single element, not found)
- [ ] Mention time/space complexity
- [ ] Ask if they want to see any optimizations

---

## 🎯 YOU'RE READY!


**One Last Thing:**
> "Even if you don't get the optimal solution immediately, 
> showing your problem-solving approach and communication 
> is what gets you the offer in service-based companies."

---

**Good luck! You've prepared well. Trust yourself. **

---

## BOOKMARK THIS PAGE
**Check Company-wise problem**
Keep this open in another tab during your interview prep!
