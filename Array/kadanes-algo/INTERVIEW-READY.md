#  KADANE'S ALGORITHM - INTERVIEW READY PACKAGE


---

##  TABLE OF CONTENTS

1. [One-Line Recognition](#recognition)
2. [The Magic Template](#template)
3. [Top 8 Kadane's Variations](#variations)
4. [Interview Communication](#communication)
5. [Company-Wise Frequency](#companies)
6. [Common Mistakes to Avoid](#mistakes)

---

<a name="recognition"></a>
##  ONE-LINE RECOGNITION

### **When to Use Kadane's?**

**If problem has these keywords → Use Kadane's:**
- "Maximum **subarray** sum"
- "Largest sum of **contiguous** elements"
- "**Continuous** elements with max sum"
- "Maximum sum in **consecutive** elements"

**Key Word:** **CONTIGUOUS / CONTINUOUS / CONSECUTIVE**

---

<a name="template"></a>
##  THE MAGIC TEMPLATE

### **Memorize This - Works in 90% Cases!**

```cpp
int maxSubarraySum(vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
```

### **What to Say in Interview:**

> "Sir, this is Kadane's Algorithm. I maintain two variables:
> - `maxSoFar`: Maximum sum found so far (our answer)
> - `maxEndingHere`: Maximum sum ending at current position
> 
> At each element, I decide: either extend previous subarray or start fresh from current element.
> 
> Time: O(n), Space: O(1). Very efficient!"

---

<a name="variations"></a>
##  TOP 8 KADANE'S VARIATIONS

### **Problem 1: Classic Maximum Subarray Sum**

**What Interviewer Asks:**
> "Find the maximum sum of any contiguous subarray."

**Template:**
```cpp
int maxSubarraySum(vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
```

**Dry Run (Show this!):**
```
Array: [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: maxEndingHere = -2, maxSoFar = -2
i=1: max(1, -2+1=-1) = 1, maxSoFar = 1
i=2: max(-3, 1-3=-2) = -2, maxSoFar = 1
i=3: max(4, -2+4=2) = 4, maxSoFar = 4
i=4: max(-1, 4-1=3) = 3, maxSoFar = 4
i=5: max(2, 3+2=5) = 5, maxSoFar = 5
i=6: max(1, 5+1=6) = 6, maxSoFar = 6
i=7: max(-5, 6-5=1) = 1, maxSoFar = 6
i=8: max(4, 1+4=5) = 5, maxSoFar = 6

Answer: 6 (subarray [4,-1,2,1])
```

**What to Say:**
> "Sir, at each position I'm asking: should I extend the previous subarray or start fresh? If previous sum is positive, extend. If negative, better to start from current element."

---

### **Problem 2: Print the Subarray (Most Asked!)**

**What Interviewer Asks:**
> "Not just sum, print which subarray has maximum sum."

**Template:**
```cpp
void printMaxSubarray(vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    int start = 0, end = 0, tempStart = 0;
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > maxEndingHere + arr[i]) {
            maxEndingHere = arr[i];
            tempStart = i;  // New start
        } else {
            maxEndingHere = maxEndingHere + arr[i];
        }
        
        if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = tempStart;
            end = i;
        }
    }
    
    cout << "Max sum: " << maxSoFar << endl;
    cout << "Subarray: ";
    for(int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
}
```

**What to Say:**
> "Sir, I'll track start and end indices. When I start a new subarray, update tempStart. When maxSoFar updates, that's our answer subarray."

---

### **Problem 3: All Elements Negative (Tricky!)**

**What Interviewer Asks:**
> "What if all elements are negative?"

**Your Answer:**
> "Sir, Kadane's handles it automatically! It will return the least negative number (maximum among negatives)."

**Example:**
```
Array: [-5, -2, -9, -1, -3]

maxSoFar will be -1 (the maximum element)
```

**Code remains same!** No special handling needed.

---

### **Problem 4: Minimum Subarray Sum**

**What Interviewer Asks:**
> "Find minimum sum instead of maximum."

**Template (Just flip the logic!):**
```cpp
int minSubarraySum(vector<int>& arr) {
    int minSoFar = arr[0];
    int minEndingHere = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        minEndingHere = min(arr[i], minEndingHere + arr[i]);
        minSoFar = min(minSoFar, minEndingHere);
    }
    
    return minSoFar;
}
```

**What to Say:**
> "Sir, exact same logic as Kadane's, just flip max to min!"

---

### **Problem 5: Maximum Subarray Product (Advanced)**

**What Interviewer Asks:**
> "Find maximum product instead of sum."

**Template (Need to track both max and min!):**
```cpp
int maxProduct(vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxHere = arr[0];
    int minHere = arr[0];  // For negatives
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < 0) {
            swap(maxHere, minHere);  // Negative flips max/min
        }
        
        maxHere = max(arr[i], maxHere * arr[i]);
        minHere = min(arr[i], minHere * arr[i]);
        
        maxSoFar = max(maxSoFar, maxHere);
    }
    
    return maxSoFar;
}
```

**What to Say:**
> "Sir, product is trickier because negative × negative = positive. So I track both max and min. When negative number comes, I swap them."

---

### **Problem 6: Circular Array Maximum Sum**

**What Interviewer Asks:**
> "Array is circular - last element connects to first."

**Template (Smart approach!):**
```cpp
int maxCircularSum(vector<int>& arr) {
    // Case 1: Max subarray is in middle (normal Kadane's)
    int normalMax = kadane(arr);
    
    // Case 2: Max subarray wraps around
    int totalSum = 0;
    for(int i = 0; i < arr.size(); i++) {
        totalSum += arr[i];
        arr[i] = -arr[i];  // Invert
    }
    
    int invertedMax = kadane(arr);
    int circularMax = totalSum + invertedMax;  // Same as total - min
    
    // Edge case: All negative
    if(circularMax == 0) return normalMax;
    
    return max(normalMax, circularMax);
}
```

**What to Say:**
> "Sir, two cases: either max subarray is in middle (normal Kadane's), or it wraps around. For wrapping case, max wrap = total - min subarray. So I find min subarray and subtract from total."

---

### **Problem 7: Maximum Sum with At Least K Elements**

**What Interviewer Asks:**
> "Find maximum sum subarray with at least k elements."

**Template:**
```cpp
int maxSumAtLeastK(vector<int>& arr, int k) {
    int n = arr.size();
    
    // First, find max sum of exactly k elements
    int currentSum = 0;
    for(int i = 0; i < k; i++) {
        currentSum += arr[i];
    }
    int maxSum = currentSum;
    
    // Now use Kadane's to extend beyond k
    int kadaneSum = 0;
    for(int i = k; i < n; i++) {
        currentSum += arr[i];
        kadaneSum = max(kadaneSum + arr[i - k], arr[i - k]);
        currentSum = max(currentSum, kadaneSum + currentSum - kadaneSum);
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}
```

**What to Say:**
> "Sir, I first find sum of exactly k elements, then use Kadane's logic to decide whether to extend beyond k."

---

### **Problem 8: Maximum Sum Non-Adjacent Elements**

**What Interviewer Asks:**
> "Find maximum sum but can't pick adjacent elements."

**Template (This is DP, not pure Kadane's):**
```cpp
int maxNonAdjacentSum(vector<int>& arr) {
    int include = arr[0];
    int exclude = 0;
    
    for(int i = 1; i < arr.size(); i++) {
        int newInclude = exclude + arr[i];
        exclude = max(include, exclude);
        include = newInclude;
    }
    
    return max(include, exclude);
}
```

**What to Say:**
> "Sir, this is variation of house robber problem. At each element, I decide: include current (then can't include previous) or exclude current."

---

<a name="communication"></a>
##  INTERVIEW COMMUNICATION SCRIPTS

### **Script 1: Recognizing Kadane's**

**When you see "maximum subarray sum", immediately say:**

> "Sir, this is a classic Kadane's Algorithm problem. I recognize it because:
> 1. We need maximum sum
> 2. Elements must be contiguous
> 3. Can have negative numbers
> 
> Kadane's solves this in O(n) time, O(1) space - optimal solution!"

---

### **Script 2: Explaining the Logic**

**Before coding, say:**

> "Sir, the key insight is: at each position, I ask two questions:
> 1. Should I extend the previous subarray? (if it adds value)
> 2. Or start fresh from current element? (if previous sum is dragging down)
> 
> I keep track of maximum seen so far, that's our answer."

---

### **Script 3: Handling Edge Cases**

**Always mention:**

> "Sir, edge cases for Kadane's:
> 1. All negative numbers → returns least negative
> 2. Single element → returns that element
> 3. All positive → returns sum of all elements
> 
> Standard Kadane's handles all these automatically!"

---

### **Script 4: Dry Run**

**After coding, ALWAYS do dry run:**

> "Sir, let me trace with example [-2, 1, -3, 4, -1, 2, 1]:
> 
> Start with -2...
> Next, max(1, -2+1) = 1, so start fresh from 1...
> Next, max(-3, 1-3) = -2, but 1 is still max...
> Continue...
> 
> Final answer: 6 from subarray [4, -1, 2, 1]"

---

<a name="companies"></a>
##  COMPANY-WISE FREQUENCY

### **TCS** ⭐⭐⭐⭐⭐
- Classic maximum subarray sum
- Print the subarray
- All negative numbers case
- **Frequency:** Very High (appears in 40% of array rounds)

---

### **Wipro** ⭐⭐⭐⭐
- Maximum subarray sum
- Minimum subarray sum
- Explanation of logic
- **Frequency:** High (30% of array rounds)

---

### **Infosys** ⭐⭐⭐⭐⭐
- Basic Kadane's only
- Clear explanation needed
- Dry run is must
- **Frequency:** Very High (50% of array rounds!)

---

### **Cognizant** ⭐⭐⭐⭐
- Maximum subarray sum
- Print subarray
- Circular array (rare)
- **Frequency:** Medium-High (35% of rounds)

---

### **Capgemini** ⭐⭐⭐
- Basic Kadane's
- Conceptual questions
- **Frequency:** Medium (25% of rounds)

---

### **Accenture** ⭐⭐⭐⭐⭐
- Very basic Kadane's
- Focus on explanation
- **Frequency:** Very High (45% of rounds)

---

<a name="mistakes"></a>
##  COMMON MISTAKES TO AVOID

### **Mistake 1: Starting with 0**
```cpp
// WRONG ❌
int maxEndingHere = 0;  // Starting with 0

// CORRECT ✅
int maxEndingHere = arr[0];  // Start with first element
```

**Why:** If all elements negative, 0 would be wrong answer!

---

### **Mistake 2: Not Handling Single Element**
```cpp
// Make sure loop starts from i=1
for(int i = 1; i < arr.size(); i++) {
    // ...
}
```

**Why:** We initialize with arr[0], so start loop from 1!

---

### **Mistake 3: Forgetting to Update maxSoFar**
```cpp
// WRONG ❌
for(int i = 1; i < arr.size(); i++) {
    maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
    // Forgot to update maxSoFar!
}

// CORRECT ✅
for(int i = 1; i < arr.size(); i++) {
    maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
    maxSoFar = max(maxSoFar, maxEndingHere);  // Update!
}
```

---

### **Mistake 4: Confusing Subarray with Subsequence**

**Subarray:** Elements must be consecutive ✅ (Kadane's)
**Subsequence:** Elements can skip ❌ (Not Kadane's)

**Example:**
```
Array: [1, -2, 3, -1, 2]

Subarray: [3, -1, 2] ✅
Subsequence: [1, 3, 2] ❌ (skipped -2 and -1)
```

---

##  QUICK REVISION TEMPLATE

### **Copy-Paste Ready Code:**

```cpp
// CLASSIC KADANE'S (Memorize this!)
int maxSubarraySum(vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for(int i = 1; i < arr.size(); i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

// WITH SUBARRAY INDICES
pair<int, pair<int,int>> maxSubarrayWithIndices(vector<int>& arr) {
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    int start = 0, end = 0, tempStart = 0;
    
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > maxEndingHere + arr[i]) {
            maxEndingHere = arr[i];
            tempStart = i;
        } else {
            maxEndingHere = maxEndingHere + arr[i];
        }
        
        if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = tempStart;
            end = i;
        }
    }
    
    return {maxSoFar, {start, end}};
}
```


---


##  FINAL TIPS

### **For Service-Based Companies:**

1. **TCS/Infosys/Accenture:** Focus on BASIC Kadane's + explanation
2. **Wipro/Cognizant:** Practice "print subarray" version too
3. **Capgemini:** Know why it works, not just the code

### **Golden Rule:**
> "Kadane's is about making ONE decision at EACH element: extend or restart?"

### **If You Remember Nothing Else:**
```cpp
maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
maxSoFar = max(maxSoFar, maxEndingHere);
```


---

*Remember: Kadane's is not just an algorithm - it's a way of thinking!*

**All the best** 
