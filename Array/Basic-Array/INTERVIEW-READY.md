#  BASIC ARRAY - INTERVIEW READY PACKAGE


---

## WHAT IS THIS?

This is your **complete interview preparation guide** for **Basic Array** questions asked in service-based companies (TCS, Wipro, Infosys, Cognizant, Capgemini, Accenture).

---

##  TABLE OF CONTENTS

1. [Quick Pattern Recognition](#pattern-recognition)
2. [Top 10 Must-Know Problems](#top-10-problems)
3. [Interview Communication Scripts](#communication-scripts)
4. [Templates to Memorize](#templates)
5. [Company-Wise Questions](#company-questions)
6. [Last Minute Checklist](#checklist)

---

<a name="pattern-recognition"></a>

### When Interviewer Asks Basic Array Questions:

| **Problem Type** | **Keywords** | **Template to Use** |
|------------------|-------------|-------------------|
| **Find Max/Min** | "largest", "smallest", "maximum", "minimum" | Single Pass |
| **Linear Search** | "find element", "search", "exists" | Sequential Scan |
| **Reverse Array** | "reverse", "backwards" | Two Pointer Swap |
| **Sum/Average** | "total", "sum", "average" | Accumulator |
| **Sorting** | "arrange", "order", "sort" | Bubble/Selection Sort |
| **Binary Search** | "sorted array", "find in sorted" | Binary Search Template |
| **Copy Array** | "copy", "duplicate", "clone" | Element-wise Copy |
| **Rotate Array** | "rotate", "shift", "circular" | Reversal Method |

---

<a name="top-10-problems"></a>
##  TOP 10 MUST-KNOW PROBLEMS

### **Problem 1: Find Maximum and Minimum**

**What Interviewer Asks:**
> "Given an array, find the largest and smallest element."

**How to Think (Tell this to interviewer):**
```
Step 1: "I'll initialize max and min with first element"
Step 2: "Then I'll traverse the array once"
Step 3: "For each element, I'll update max if current > max"
Step 4: "Similarly update min if current < min"
Step 5: "This gives O(n) time, O(1) space"
```

**Template:**
```cpp
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(int arr[], int n) {
    int minVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
```

**What to Say:**
> "Sir, I'll use a single pass approach. Initialize max with first element, then compare each element and update max. Time complexity O(n), space O(1). Very efficient for this problem."

**Dry Run (Always show this):**
```
Array: [3, 7, 2, 9, 1]

i=0: max = 3
i=1: 7 > 3, max = 7
i=2: 2 < 7, max = 7
i=3: 9 > 7, max = 9
i=4: 1 < 9, max = 9

Final: max = 9
```

**Edge Cases (Mention these):**
- Single element array → return that element
- All elements same → max = min = that element
- Negative numbers → works same way

---

### **Problem 2: Linear Search**

**What Interviewer Asks:**
> "Find if an element exists in array. If yes, return index, else -1."

**How to Think:**
```
Step 1: "I'll traverse array from start"
Step 2: "Compare each element with target"
Step 3: "If found, return index immediately"
Step 4: "If loop completes, return -1 (not found)"
```

**Template:**
```cpp
int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;  // Found
        }
    }
    return -1;  // Not found
}
```

**What to Say:**
> "Sir, since array is not sorted, binary search won't work. I'll use linear search - check each element sequentially. Best case O(1) if found at start, worst case O(n) if at end or not present."

**Follow-up Question:**
> **Interviewer:** "What if array is sorted?"

**Your Answer:**
> "Sir, if sorted, I can use binary search which is O(log n), much faster than O(n)."

---

### **Problem 3: Reverse an Array**

**What Interviewer Asks:**
> "Reverse the array in-place."

**How to Think:**
```
Step 1: "I'll use two pointers - left at start, right at end"
Step 2: "Swap elements at left and right"
Step 3: "Move left forward, right backward"
Step 4: "Stop when left >= right"
```

**Template:**
```cpp
void reverseArray(int arr[], int n) {
    int left = 0, right = n - 1;
    while(left < right) {
        // Swap
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
}
```

**What to Say:**
> "Sir, I'll use two-pointer technique. Swap first and last elements, then move pointers inward. This is in-place with O(n) time and O(1) space."

**Dry Run:**
```
Array: [1, 2, 3, 4, 5]

left=0, right=4: swap 1 and 5 → [5, 2, 3, 4, 1]
left=1, right=3: swap 2 and 4 → [5, 4, 3, 2, 1]
left=2, right=2: stop

Final: [5, 4, 3, 2, 1]
```

---

### **Problem 4: Sum and Average**

**What Interviewer Asks:**
> "Find sum and average of array elements."

**Template:**
```cpp
int findSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double findAverage(int arr[], int n) {
    int sum = findSum(arr, n);
    return (double)sum / n;
}
```

**What to Say:**
> "Sir, I'll traverse array once and accumulate sum. For average, divide sum by n. Important to cast to double to avoid integer division."

**Edge Cases:**
- Empty array → handle n=0 case
- Integer overflow → use `long long` for large arrays
- Division by zero → check n != 0

---

### **Problem 5: Copy Array (Value vs Reference)**

**What Interviewer Asks:**
> "Copy array to another array."

**CRITICAL CONCEPT (This confuses many!):**

**Value Copy (Element-wise):**
```cpp
void copyArray(int source[], int dest[], int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}
// Changes in dest won't affect source
```

**Reference Copy (Pointer):**
```cpp
int* arr1 = new int[5]{1, 2, 3, 4, 5};
int* arr2 = arr1;  // Both point to same memory!
arr2[0] = 100;     // This changes arr1[0] too!
```

**What to Say:**
> "Sir, in C++, we cannot directly assign arrays. For value copy, I'll copy element by element. For reference, I'll use pointers, but need to be careful as both point to same memory."

**Interview Dialogue:**
> **Interviewer:** "What's the difference between value and reference copy?"

**Your Answer:**
> "Sir, value copy creates a new independent array - changes in one don't affect other. Reference copy makes both variables point to same memory - changes in one affect the other. For value copy, I use element-wise copying. For reference, I use pointers."

---

### **Problem 6: Bubble Sort**

**What Interviewer Asks:**
> "Sort the array in ascending order."

**Template:**
```cpp
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

**What to Say:**
> "Sir, I'll use bubble sort. In each pass, largest element bubbles to the end. After n-1 passes, array is sorted. Time complexity O(n²), space O(1)."

**Dry Run (Important to show):**
```
Array: [5, 2, 8, 1]

Pass 1: [2, 5, 1, 8]  (8 bubbled to end)
Pass 2: [2, 1, 5, 8]  (5 in position)
Pass 3: [1, 2, 5, 8]  (sorted)
```

**Follow-up:**
> **Interviewer:** "Can you optimize?"

**Your Answer:**
> "Sir, yes! If no swaps in a pass, array is sorted - we can break early."

```cpp
void optimizedBubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break;  // Already sorted
    }
}
```

---

### **Problem 7: Binary Search (Sorted Array)**

**What Interviewer Asks:**
> "Find element in sorted array."

**Template:**
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) {
            return mid;  // Found
        }
        else if(arr[mid] < target) {
            left = mid + 1;  // Search right half
        }
        else {
            right = mid - 1;  // Search left half
        }
    }
    return -1;  // Not found
}
```

**What to Say:**
> "Sir, since array is sorted, I'll use binary search. Divide search space in half each time. Time complexity O(log n), much better than linear O(n)."

**Dry Run:**
```
Array: [1, 3, 5, 7, 9], target = 7

left=0, right=4, mid=2: arr[2]=5 < 7, go right
left=3, right=4, mid=3: arr[3]=7 = target, found!

Return: 3
```

---

### **Problem 8: Count Even/Odd Elements**

**What Interviewer Asks:**
> "Count number of even and odd elements."

**Template:**
```cpp
void countEvenOdd(int arr[], int n) {
    int evenCount = 0, oddCount = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    cout << "Even: " << evenCount << endl;
    cout << "Odd: " << oddCount << endl;
}
```

**What to Say:**
> "Sir, I'll traverse array once. Check each element with modulo 2. If remainder 0, it's even, else odd. O(n) time, O(1) space."

---

### **Problem 9: Remove Duplicates from Sorted Array**

**What Interviewer Asks:**
> "Remove duplicates in-place from sorted array and return new length."

**Template:**
```cpp
int removeDuplicates(int arr[], int n) {
    if(n == 0) return 0;
    
    int j = 0;  // Index for unique elements
    
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    
    return j + 1;  // New length
}
```

**What to Say:**
> "Sir, I'll use two-pointer technique. j points to last unique element. Compare each element with arr[j]. If different, it's new unique element - increment j and place it there. O(n) time, O(1) space."

**Dry Run:**
```
Array: [1, 1, 2, 2, 3]

i=1: arr[1]=1 == arr[0], skip
i=2: arr[2]=2 != arr[0], j=1, arr[1]=2 → [1,2,2,2,3]
i=3: arr[3]=2 == arr[1], skip
i=4: arr[4]=3 != arr[1], j=2, arr[2]=3 → [1,2,3,2,3]

New length: 3
Result: [1, 2, 3]
```

---

### **Problem 10: Rotate Array by K Positions**

**What Interviewer Asks:**
> "Rotate array to right by k positions."

**Template (Reversal Method):**
```cpp
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int arr[], int n, int k) {
    k = k % n;  // Handle k > n
    
    // Step 1: Reverse entire array
    reverse(arr, 0, n - 1);
    
    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);
    
    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);
}
```

**What to Say:**
> "Sir, I'll use reversal method - 3 reversals. First reverse entire array, then reverse first k elements, then reverse remaining. This is O(n) time, O(1) space, very efficient."

**Dry Run:**
```
Array: [1, 2, 3, 4, 5], k = 2

Step 1: Reverse all → [5, 4, 3, 2, 1]
Step 2: Reverse first 2 → [4, 5, 3, 2, 1]
Step 3: Reverse last 3 → [4, 5, 1, 2, 3]

Final: [4, 5, 1, 2, 3]
```

---

<a name="communication-scripts"></a>
## 🗣️ INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Problem Understanding**

**When interviewer gives problem, say this:**

> "Thank you sir. Let me confirm my understanding:
> 1. Input: Array of integers, size n
> 2. Output: [state what to return]
> 3. Constraints: [ask about array size, element range]
> 4. Edge cases: [ask about empty array, single element, duplicates]
> 
> Is my understanding correct?"

**Why this works:** Shows you think before coding!

---

### **Script 2: Approach Explanation**

**Before writing code, say this:**

> "Sir, I can think of two approaches:
> 
> **Brute Force:** [explain simple approach]
> - Time: O(n²)
> - Space: O(1)
> 
> **Optimized:** [explain better approach]
> - Time: O(n)
> - Space: O(1)
> 
> I'll go with the optimized approach. Is that okay?"

**Why this works:** Shows you know multiple solutions!

---

### **Script 3: While Coding**

**While writing code, keep talking:**

> "I'll initialize variables here..."
> "Now I'll loop through the array..."
> "Here I'm checking the condition..."
> "Need to handle this edge case..."

**Why this works:** Interviewer sees your thinking process!

---

### **Script 4: After Coding**

**After writing code, say this:**

> "Let me do a dry run with an example:
> [Show dry run step by step]
> 
> Time Complexity: O(n) because single pass
> Space Complexity: O(1) because only few variables
> 
> Edge cases handled:
> - Empty array: [explain]
> - Single element: [explain]
> - All same elements: [explain]
> 
> Would you like me to optimize further or test with more examples?"

**Why this works:** Shows completeness and professionalism!

---

<a name="templates"></a>
## 📝 TEMPLATES TO MEMORIZE

### **Template 1: Array Traversal**
```cpp
for(int i = 0; i < n; i++) {
    // Process arr[i]
}
```

### **Template 2: Two Pointer**
```cpp
int left = 0, right = n - 1;
while(left < right) {
    // Process
    left++;
    right--;
}
```

### **Template 3: Finding Max/Min**
```cpp
int result = arr[0];
for(int i = 1; i < n; i++) {
    result = max(result, arr[i]);  // or min
}
```

### **Template 4: Accumulator Pattern**
```cpp
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i];
}
```

### **Template 5: Binary Search**
```cpp
int left = 0, right = n - 1;
while(left <= right) {
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1;
```

### **Template 6: Bubble Sort**
```cpp
for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
        }
    }
}
```

---

<a name="company-questions"></a>
##  COMPANY-WISE QUESTIONS

### **TCS (Most Common)**
1. Find max and min 
2. Reverse array 
3. Linear search 
4. Sum of array elements 
5. Rotate array 

**TCS Pattern:** Very basic, focuses on logic clarity

---

### **Wipro**
1. Binary search ⭐⭐⭐⭐⭐
2. Bubble sort ⭐⭐⭐⭐
3. Remove duplicates ⭐⭐⭐⭐
4. Count even/odd ⭐⭐⭐
5. Array copy concepts ⭐⭐⭐

**Wipro Pattern:** Asks conceptual questions about pointers

---

### **Infosys**
1. Find second largest ⭐⭐⭐⭐⭐
2. Reverse array ⭐⭐⭐⭐⭐
3. Linear search ⭐⭐⭐⭐
4. Sum and average ⭐⭐⭐⭐
5. Simple sorting ⭐⭐⭐

**Infosys Pattern:** Very basic, communication matters most

---

### **Cognizant**
1. Binary search ⭐⭐⭐⭐
2. Rotate array ⭐⭐⭐⭐
3. Remove duplicates ⭐⭐⭐⭐
4. Sorting ⭐⭐⭐
5. Pointer concepts ⭐⭐⭐

**Cognizant Pattern:** Medium difficulty, clear explanation needed

---

### **Capgemini**
1. Max/Min finding ⭐⭐⭐⭐⭐
2. Reverse array ⭐⭐⭐⭐
3. Search algorithms ⭐⭐⭐⭐
4. Basic sorting ⭐⭐⭐
5. Array traversal ⭐⭐⭐

**Capgemini Pattern:** Tests fundamentals thoroughly

---

### **Accenture**
1. Linear search ⭐⭐⭐⭐⭐
2. Sum of elements ⭐⭐⭐⭐⭐
3. Find max/min ⭐⭐⭐⭐
4. Reverse array ⭐⭐⭐⭐
5. Count elements ⭐⭐⭐

**Accenture Pattern:** Easiest among all, communication crucial

---

<a name="checklist"></a>
##  LAST MINUTE CHECKLIST (1 Hour Before Interview)

### **☑️ Memorize These:**
- [ ] Max/Min finding template
- [ ] Linear search template
- [ ] Binary search template
- [ ] Reverse array (two pointer)
- [ ] Bubble sort logic
- [ ] Rotate array (reversal method)

### **☑️ Remember to Say:**
- [ ] "Let me confirm my understanding..."
- [ ] "I can think of two approaches..."
- [ ] "Let me do a dry run..."
- [ ] "Time complexity is O(n)..."
- [ ] "Edge cases are..."

### **☑️ Common Mistakes to Avoid:**
- [ ] Don't start coding immediately
- [ ] Don't forget to ask about constraints
- [ ] Don't skip dry run
- [ ] Don't forget edge cases
- [ ] Don't be silent while coding

### **☑️ Edge Cases to Mention:**
- [ ] Empty array (n = 0)
- [ ] Single element (n = 1)
- [ ] All elements same
- [ ] Already sorted
- [ ] Negative numbers

---

## 🎯 FINAL TIPS

### **For Service-Based Companies:**

**Communication (40%)** > **Pattern Recognition (30%)** > **Code Quality (20%)** > **Optimization (10%)**

### **Golden Rules:**
1. **Always explain before coding**
2. **Do dry run after coding**
3. **Mention time/space complexity**
4. **Handle edge cases**
5. **Be confident but humble**

### **Common Interview Flow:**
```
Problem Given
    ↓
Clarify & Confirm (1 min)
    ↓
Think of Approaches (2 min)
    ↓
Explain Best Approach (2 min)
    ↓
Write Code (5 min)
    ↓
Dry Run (2 min)
    ↓
Discuss Complexity (1 min)
    ↓
Handle Follow-ups
```

---

##  CONFIDENCE BOOSTERS

**Remember:**
- ✅ Basic arrays are in 80% of interviews
- ✅ These 10 problems cover 90% of basic questions
- ✅ Pattern recognition > memorization
- ✅ Communication > perfect code
- ✅ You know the concepts, now you know the strategy!


---

## 🎉 YOU'RE READY!

**You have:**
- ✅ 10 essential problems with solutions
- ✅ Communication scripts
- ✅ Templates to memorize
- ✅ Company-specific insights
- ✅ Complete strategy


---

*Remember: Basic arrays are your foundation. Master these, and everything else becomes easier!*

**All the best** 
