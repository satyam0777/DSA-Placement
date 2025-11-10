# Array - Interview Preparation Guide (Service-Based Companies <10 LPA)

---

## 🎯 What Service-Based Companies Actually Ask

**Reality Check:**
- TCS, Wipro, Infosys, Cognizant, Capgemini, Accenture, HCL, Tech Mahindra
- Arrays are THE MOST asked topic (70% of coding rounds!)
- They focus on **pattern recognition** more than complex algorithms
- Communication + Clean Code > Perfect Optimization

---

## 🗣️ HOW TO TALK THROUGH ARRAY PROBLEMS IN INTERVIEW

### **Opening Statement (First 30 seconds)**

**When you see an array problem, say this:**

> "Let me understand the problem. I have an array of [size/elements]. 
> The task is to [explain what you need to find/do].
> My first thought is [brute force approach]. This would be O(n²) or O(n).
> But I can optimize this using [pattern name] to O(n) or O(n log n)."

**Example:**
> "I need to find the maximum sum of a contiguous subarray. 
> Brute force would be checking all subarrays O(n²). 
> But since we need contiguous elements and maximum sum, 
> I can use Kadane's Algorithm for O(n) time."

---

## 💭 STEP-BY-STEP THINKING PROCESS (Say this out loud!)

### **Step 1: Pattern Recognition (20 seconds)**
```
Ask yourself:
✓ Is the array sorted? → Two Pointer / Binary Search
✓ Need to find subarray/substring? → Sliding Window / Prefix Sum
✓ Need to count/find frequency? → Hashing
✓ Need maximum/minimum sum? → Kadane's / Greedy
✓ Need pairs/triplets? → Two Pointer / Hashing
✓ Need to track previous elements? → Stack / Array
```

### **Step 2: Identify the Core Pattern**
```
Say: "This problem follows the [PATTERN NAME] pattern because..."

Patterns:
1. Two Pointer → Sorted array, pairs, reverse, partition
2. Sliding Window → Fixed/variable size subarray, at most k
3. Hashing/Frequency → Count, duplicates, existence
4. Kadane's Algorithm → Maximum subarray sum
5. Prefix Sum → Range queries, subarray sum
6. Greedy/Sorting → Optimization problems
```

### **Step 3: Explain Your Approach (45 seconds)**
```
Say: "Here's my approach in 3 steps..."

Template:
"First, I'll [initialize variables/data structures].
Then, I'll [traverse/process the array].
For each element, I'll [your logic].
Finally, I'll return [the answer]."
```

### **Step 4: Complexity Analysis (15 seconds)**
```
Say: "Let me analyze the complexity..."

"Time complexity: O(n) because I traverse once.
Space complexity: O(1) if using only variables, 
or O(n) if using extra array/hashmap."
```

### **Step 5: Edge Cases (20 seconds)**
```
Say: "Let me verify edge cases..."
- Empty array → return default value
- Single element → check if it satisfies condition
- All elements same → handle properly
- Negative numbers → consider impact
```

---

## 📚 MUST-KNOW PATTERNS FOR SERVICE-BASED COMPANIES

## **PATTERN 1: Two Pointer Technique** ⭐⭐⭐⭐⭐

### **When to Use:**
- Array is sorted or can be sorted
- Find pairs/triplets with sum/difference
- Remove duplicates, reverse, partition

### **Template 1: Opposite Direction (Pair Sum)**
```cpp
// Find pair with given sum in sorted array
bool hasPairSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while(left < right) {
        int sum = arr[left] + arr[right];
        
        if(sum == target) 
            return true;
        else if(sum < target) 
            left++;
        else 
            right--;
    }
    return false;
}
```

**What to say:**
> "I'll use two pointers - one at start, one at end. 
> If sum is less than target, I'll move left pointer right to increase sum.
> If sum is greater, I'll move right pointer left to decrease sum.
> This works because the array is sorted."

---

### **Template 2: Same Direction (Remove Duplicates)**
```cpp
// Remove duplicates from sorted array in-place
int removeDuplicates(vector<int>& arr) {
    if(arr.empty()) return 0;
    
    int j = 0; // Slow pointer
    for(int i = 1; i < arr.size(); i++) { // Fast pointer
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}
```

**What to say:**
> "I'll use two pointers moving in same direction - slow (j) and fast (i).
> Fast pointer explores all elements. Slow pointer tracks unique elements.
> When we find a new unique element, we move it to slow pointer's position."

---

## **PATTERN 2: Sliding Window** ⭐⭐⭐⭐⭐

### **When to Use:**
- Find max/min/sum of subarray of size k
- Longest/shortest subarray with condition
- Keywords: "window", "contiguous", "at most k"

### **Template 1: Fixed Size Window**
```cpp
// Maximum sum of subarray of size k
int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if(n < k) return -1;
    
    // Calculate first window
    int windowSum = 0;
    for(int i = 0; i < k; i++)
        windowSum += arr[i];
    
    int maxSum = windowSum;
    
    // Slide the window
    for(int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // Add new, remove old
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

**What to say:**
> "I'll use sliding window. First, I calculate sum of first k elements.
> Then I slide the window - add next element, remove first element.
> This avoids recalculating sum each time, giving O(n) instead of O(n*k)."

---

### **Template 2: Variable Size Window**
```cpp
// Longest substring with at most K distinct characters
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;
    
    for(int right = 0; right < s.size(); right++) {
        // Expand window
        freq[s[right]]++;
        
        // Shrink window if condition violated
        while(freq.size() > k) {
            freq[s[left]]--;
            if(freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}
```

**What to say:**
> "I'll use variable size sliding window with a hashmap.
> Right pointer expands the window, adding characters.
> When we exceed k distinct characters, left pointer shrinks the window.
> I track maximum window size throughout."

---

## **PATTERN 3: Kadane's Algorithm** ⭐⭐⭐⭐⭐

### **When to Use:**
- Find maximum sum of contiguous subarray
- Keywords: "maximum sum", "contiguous", "subarray"

### **Template:**
```cpp
// Maximum subarray sum
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        // Either extend current subarray or start new
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
```

**What to say:**
> "I'll use Kadane's Algorithm. For each position, I decide:
> Either extend the previous subarray (add current element),
> Or start a new subarray from current element.
> I keep track of maximum sum found so far. This is O(n) time, O(1) space."

---

### **Variation: Print the Subarray**
```cpp
// Maximum subarray sum with indices
vector<int> maxSubArrayWithIndices(vector<int>& nums) {
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    int start = 0, end = 0, tempStart = 0;
    
    for(int i = 1; i < nums.size(); i++) {
        if(maxEndingHere + nums[i] < nums[i]) {
            maxEndingHere = nums[i];
            tempStart = i;
        } else {
            maxEndingHere += nums[i];
        }
        
        if(maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
            start = tempStart;
            end = i;
        }
    }
    
    return {maxSoFar, start, end};
}
```

---

## **PATTERN 4: Hashing / Frequency Count** ⭐⭐⭐⭐⭐

### **When to Use:**
- Count occurrences, find duplicates
- Check if element exists
- Find pairs, anagrams, intersection
- Keywords: "frequency", "count", "exists", "duplicate"

### **Template 1: Frequency Counting**
```cpp
// Find element that appears more than n/2 times
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    
    for(int num : nums) {
        freq[num]++;
        if(freq[num] > n/2)
            return num;
    }
    
    return -1;
}
```

**What to say:**
> "I'll use a hashmap to count frequency of each element.
> As I traverse, I check if any element exceeds n/2 occurrences.
> Time: O(n), Space: O(n) for the hashmap."

---

### **Template 2: Two Sum Problem**
```cpp
// Find indices of two numbers that add up to target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        if(seen.count(complement)) {
            return {seen[complement], i};
        }
        
        seen[nums[i]] = i;
    }
    
    return {};
}
```

**What to say:**
> "For each element, I check if its complement (target - element) exists in hashmap.
> If yes, I found the pair. If no, I add current element to hashmap.
> This reduces O(n²) brute force to O(n) using extra space."

---

### **Template 3: Check for Duplicates**
```cpp
// Check if array contains duplicates
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for(int num : nums) {
        if(seen.count(num))
            return true;
        seen.insert(num);
    }
    
    return false;
}
```

---

## **PATTERN 5: Prefix Sum** ⭐⭐⭐⭐

### **When to Use:**
- Multiple range sum queries
- Subarray sum equals k
- Keywords: "range sum", "subarray sum", "cumulative"

### **Template 1: Basic Prefix Sum**
```cpp
// Build prefix sum array for range queries
vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    
    return prefix;
}

// Query sum from L to R
int rangeSum(vector<int>& prefix, int L, int R) {
    if(L == 0) return prefix[R];
    return prefix[R] - prefix[L-1];
}
```

**What to say:**
> "I'll build a prefix sum array where prefix[i] = sum of elements from 0 to i.
> Then any range sum from L to R is prefix[R] - prefix[L-1].
> Preprocessing: O(n), Each query: O(1)."

---

### **Template 2: Subarray Sum Equals K**
```cpp
// Count subarrays with sum equal to k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // Empty subarray
    
    int sum = 0, count = 0;
    
    for(int num : nums) {
        sum += num;
        
        // Check if (sum - k) exists
        if(prefixCount.count(sum - k)) {
            count += prefixCount[sum - k];
        }
        
        prefixCount[sum]++;
    }
    
    return count;
}
```

**What to say:**
> "I use prefix sum with hashmap. If current sum is S and we've seen (S-k) before,
> then there exists a subarray with sum k between those positions.
> I count all such occurrences using the hashmap."

---

## **PATTERN 6: Sorting & Greedy** ⭐⭐⭐⭐

### **When to Use:**
- Optimization problems
- Interval problems
- Merge/combine operations

### **Template: Meeting Rooms**
```cpp
// Check if person can attend all meetings
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < intervals[i-1][1]) {
            return false; // Overlap found
        }
    }
    
    return true;
}
```

**What to say:**
> "I'll sort intervals by start time. Then check if any meeting starts 
> before the previous one ends. If yes, there's an overlap.
> Time: O(n log n) for sorting."

---

## 🎓 TOP 15 PROBLEMS FOR SERVICE-BASED INTERVIEWS

### **1. Two Sum** ⭐⭐⭐⭐⭐
- **Pattern:** Hashing
- **Difficulty:** Easy
- **Asked by:** Everyone (TCS, Wipro, Infosys, all!)

### **2. Maximum Subarray (Kadane's)** ⭐⭐⭐⭐⭐
- **Pattern:** Kadane's Algorithm
- **Difficulty:** Medium
- **Asked by:** TCS, Cognizant, Capgemini

### **3. Best Time to Buy and Sell Stock** ⭐⭐⭐⭐⭐
- **Pattern:** Single pass / Kadane's variation
- **Difficulty:** Easy
- **Asked by:** Wipro, Infosys, TCS

```cpp
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for(int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}
```

### **4. Contains Duplicate** ⭐⭐⭐⭐⭐
- **Pattern:** Hashing
- **Difficulty:** Easy
- **Asked by:** All companies

### **5. Remove Duplicates from Sorted Array** ⭐⭐⭐⭐⭐
- **Pattern:** Two Pointer
- **Difficulty:** Easy
- **Asked by:** TCS, Wipro, Capgemini

### **6. Move Zeros** ⭐⭐⭐⭐
- **Pattern:** Two Pointer
- **Difficulty:** Easy

```cpp
void moveZeroes(vector<int>& nums) {
    int j = 0; // Position for non-zero
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
```

### **7. Find Missing Number** ⭐⭐⭐⭐⭐
- **Pattern:** Math / XOR
- **Difficulty:** Easy
- **Asked by:** Infosys, TCS

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for(int num : nums) actualSum += num;
    return expectedSum - actualSum;
}
```

### **8. Rotate Array** ⭐⭐⭐⭐
- **Pattern:** Reversal
- **Difficulty:** Medium

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
```

### **9. Subarray Sum Equals K** ⭐⭐⭐⭐⭐
- **Pattern:** Prefix Sum + Hashing
- **Difficulty:** Medium
- **Asked by:** Cognizant, TCS Digital

### **10. Product of Array Except Self** ⭐⭐⭐⭐
- **Pattern:** Prefix/Suffix Product
- **Difficulty:** Medium

### **11. Maximum Sum Subarray of Size K** ⭐⭐⭐⭐⭐
- **Pattern:** Sliding Window
- **Difficulty:** Easy
- **Asked by:** Wipro, Capgemini

### **12. Longest Substring Without Repeating Characters** ⭐⭐⭐⭐
- **Pattern:** Sliding Window
- **Difficulty:** Medium
- **Asked by:** TCS, Cognizant

### **13. Merge Sorted Arrays** ⭐⭐⭐⭐
- **Pattern:** Two Pointer
- **Difficulty:** Easy

### **14. Sort Colors (Dutch National Flag)** ⭐⭐⭐⭐
- **Pattern:** Three Pointer
- **Difficulty:** Medium

```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++; mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
```

### **15. Leaders in Array** ⭐⭐⭐⭐
- **Pattern:** Traverse from right
- **Difficulty:** Easy
- **Asked by:** TCS, Infosys

```cpp
vector<int> leaders(vector<int>& arr) {
    vector<int> result;
    int maxFromRight = arr[arr.size()-1];
    result.push_back(maxFromRight);
    
    for(int i = arr.size()-2; i >= 0; i--) {
        if(arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            result.push_back(maxFromRight);
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

---

## 🚨 COMMON MISTAKES & HOW TO AVOID

### **Mistake 1: Not Checking Array Bounds**
```cpp
// ❌ WRONG - Can cause index out of bounds
for(int i = 0; i <= arr.size(); i++)

// ✅ CORRECT
for(int i = 0; i < arr.size(); i++)
```

### **Mistake 2: Forgetting Edge Cases**
```cpp
// Always check:
if(arr.empty()) return defaultValue;
if(arr.size() == 1) // handle single element
```

### **Mistake 3: Integer Overflow**
```cpp
// ❌ WRONG - Can overflow
int sum = arr[i] + arr[j];

// ✅ CORRECT for large numbers
long long sum = (long long)arr[i] + arr[j];
```

### **Mistake 4: Modifying While Iterating**
```cpp
// ❌ Be careful when modifying array while iterating
// ✅ Use two pointer or create new array if needed
```

---

## 💡 INTERVIEW TIPS & TRICKS

### **1. Always Mention Time & Space Complexity**
```
"The time complexity is O(n) because I traverse the array once.
Space complexity is O(1) as I'm using only a few variables."
```

### **2. Draw It Out**
- Draw the array on paper/whiteboard
- Show how pointers move
- Demonstrate window sliding

### **3. Start with Brute Force**
```
"The brute force would be O(n²) using nested loops.
But I can optimize using [pattern] to O(n)."
```

### **4. Handle Edge Cases Proactively**
```
"Let me check edge cases:
- Empty array
- Single element
- All elements same
- Array already sorted/rotated"
```

### **5. Use Meaningful Variable Names**
```cpp
// ❌ AVOID
int i, j, k, x, y, z;

// ✅ BETTER
int left, right, windowSum, maxProfit;
```

---

## 📝 INTERVIEW CHEAT SHEET (Memorize This!)

| Problem Type | Pattern | Key Indicator | Time |
|--------------|---------|---------------|------|
| Pair sum (sorted) | Two Pointer | "pair", "sorted" | O(n) |
| Pair sum (unsorted) | Hashing | "pair", "unsorted" | O(n) |
| Max subarray sum | Kadane's | "maximum sum", "contiguous" | O(n) |
| Fixed window | Sliding Window | "size k", "window" | O(n) |
| Variable window | Sliding Window | "at most k", "longest" | O(n) |
| Range sum | Prefix Sum | "multiple queries", "sum L to R" | O(1) per query |
| Subarray sum = k | Prefix + Hash | "subarray sum equals" | O(n) |
| Frequency/count | Hashing | "count", "frequency", "exists" | O(n) |
| Remove duplicates | Two Pointer | "sorted", "duplicates" | O(n) |
| Intervals/meetings | Sorting | "intervals", "meetings" | O(n log n) |

---


## 🗣️ SAMPLE INTERVIEW DIALOGUE

**Interviewer:** "Find the maximum sum of any contiguous subarray."

**You:** 
> "Okay, so I need to find maximum sum of a contiguous subarray. 
> Let me clarify - the array can have negative numbers? Yes.
> And we need at least one element? Yes.
>
> The brute force would be to check all possible subarrays - that's O(n²).
> But this is a classic maximum subarray problem, so I can use Kadane's Algorithm 
> for O(n) time and O(1) space.
>
> Here's my approach: I'll maintain two variables - maxSoFar and maxEndingHere.
> For each element, I decide: either extend the current subarray by adding this element,
> or start a new subarray from this element. I take whichever gives maximum.
>
> Let me dry run: arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
> - Start: maxSoFar = -2, maxEndingHere = -2
> - At 1: max(1, -2+1) = 1, update maxSoFar = 1
> - At -3: max(-3, 1-3) = -2
> - At 4: max(4, -2+4) = 4, update maxSoFar = 4
> - Continue...
> - Final answer: 6 (subarray [4,-1,2,1])
>
> Now I'll code this..."

**[Write clean code]**

**You:**
> "Edge cases: single element works, all negative returns max (least negative).
> Time: O(n), Space: O(1). Done!"

---

**Remember:** Arrays are the foundation. Master these patterns and you'll crack 70% of interview problems!

**Good luck with your placement! 🚀**
