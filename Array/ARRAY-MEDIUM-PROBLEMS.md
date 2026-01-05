#  ARRAY - MEDIUM PROBLEMS GUIDE

---

## 🎬 PROBLEM 1: CONTAINER WITH MOST WATER

### Step 1: Problem Statement
```
Given n non-negative integers a1, a2, ..., an where each represents a point 
at coordinate (i, ai). Find two lines that together with the x-axis form a 
container such that the container holds the most water.

You may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The vertical lines are at indices 1 and 8. 
Area = min(8, 7) * (8 - 1) = 7 * 7 = 49

Example 2:
Input: height = [1,1]
Output: 1
```

### Step 2: Pattern Identification (3 seconds)
"Find best pair" + "Two pointers" + "Opposite direction" 
→ **TWO-POINTER OPPOSITE PATTERN**

**Magic Keywords:** two values, pair, maximize area, distance

### Step 3: Approach

```
Intuition:
The area is limited by the shorter line. If we move the longer line's pointer,
the area will only decrease (width ↓, height ≤). So we must move the shorter 
line's pointer, hoping to find a taller line that might increase area.

Algorithm:
1. Initialize left = 0, right = n-1
2. Calculate area = min(height[left], height[right]) * (right - left)
3. Track max area
4. Move pointer with smaller height (inward)
5. Repeat until left < right

Why move the smaller one?
- Width will definitely decrease (right - left ↓)
- If we move larger line, height can only stay same or decrease
- If we move smaller line, we might find taller line (height ↑)

Complexity: Time O(n), Space O(1)
```

### Step 4: Dry Run

```
height = [1,8,6,2,5,4,8,3,7]
indices:  0 1 2 3 4 5 6 7 8

Iteration 1:
  left = 0 (h=1), right = 8 (h=7)
  area = min(1,7) * (8-0) = 1 * 8 = 8
  max_area = 8
  height[left]=1 < height[right]=7, so move left++

Iteration 2:
  left = 1 (h=8), right = 8 (h=7)
  area = min(8,7) * (8-1) = 7 * 7 = 49
  max_area = 49
  height[left]=8 > height[right]=7, so move right--

Iteration 3:
  left = 1 (h=8), right = 7 (h=3)
  area = min(8,3) * (7-1) = 3 * 6 = 18
  max_area = 49 (unchanged)
  height[left]=8 > height[right]=3, so move right--

Iteration 4:
  left = 1 (h=8), right = 6 (h=8)
  area = min(8,8) * (6-1) = 8 * 5 = 40
  max_area = 49 (unchanged)
  height[left]=8 == height[right]=8, move either (let's move right--)

Continue until left >= right...

Final Answer: 49 ✓
```

### Step 5: Complete Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            // Calculate current area
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);
            
            // Move pointer with smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};

// Time Complexity: O(n) - single pass
// Space Complexity: O(1) - only pointers
// Interview Plus: "Sir, two-pointer O(1) space solution, no sorting needed"
```

**Interview Communication:**
> "Sir, I'll use two pointers starting from both ends. The area is limited by the shorter line. Since width decreases, I must move the shorter pointer to find a taller line. I'll track the maximum area throughout. Single pass O(n) time, O(1) space."

---

## 🎬 PROBLEM 2: MERGE INTERVALS

### Step 1: Problem Statement
```
Given array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of non-overlapping intervals that 
cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6]

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping
```

### Step 2: Pattern Identification (3 seconds)
"Overlapping" + "Merge" + "Scheduling" 
→ **SORTING + GREEDY PATTERN**

**Magic Keywords:** merge, overlapping, combine, scheduling

### Step 3: Approach

```
Key Insight:
If we sort by start time, overlapping intervals will be adjacent.
Then we can greedily merge consecutive overlapping intervals.

Two intervals [a,b] and [c,d] overlap if:
- a <= c and b >= c (assuming first interval starts before second)

Algorithm:
1. Sort intervals by start time
2. Initialize: result = [], current = intervals[0]
3. For each interval:
   - If it overlaps with current: extend current's end
   - Else: add current to result, make it new current
4. Don't forget to add last interval

Complexity: Time O(n log n), Space O(n)
```

### Step 4: Dry Run

```
intervals = [[1,3],[2,6],[8,10],[15,18]]

Step 1: Sort by start time (already sorted)
[[1,3],[2,6],[8,10],[15,18]]

Step 2: Process
result = []
current = [1,3]

Process [2,6]:
  Does [2,6] overlap with [1,3]?
  2 <= 3? YES, overlap!
  current = [1, max(3,6)] = [1,6]

Process [8,10]:
  Does [8,10] overlap with [1,6]?
  8 <= 6? NO, no overlap!
  Add [1,6] to result
  current = [8,10]

Process [15,18]:
  Does [15,18] overlap with [8,10]?
  15 <= 10? NO, no overlap!
  Add [8,10] to result
  current = [15,18]

Don't forget last interval:
  Add [15,18] to result

Final Result: [[1,6],[8,10],[15,18]] ✓
```

### Step 5: Complete Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort by start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]); // Add first interval
        
        for (int i = 1; i < intervals.size(); i++) {
            int lastEnd = result.back()[1];      // End of last merged interval
            int currStart = intervals[i][0];     // Start of current interval
            int currEnd = intervals[i][1];       // End of current interval
            
            if (currStart <= lastEnd) {
                // Overlapping - extend
                result.back()[1] = max(lastEnd, currEnd);
            } else {
                // Non-overlapping - add new
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};

// Time Complexity: O(n log n) - dominated by sorting
// Space Complexity: O(n) - output array
// Interview Plus: "Sir, sort and greedy merge. O(n log n) optimal for this problem"
```

**Interview Communication:**
> "Sir, I'll sort intervals by start time. Then greedily merge overlapping ones. If current interval's start is within last merged interval's end, we extend the end. Otherwise, we start a new interval. Time O(n log n) for sorting, space O(n)."

---

## 🎬 PROBLEM 3: TRAPPING RAIN WATER

### Step 1: Problem Statement
```
Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: 
The above elevation map (black section) is represented by array 
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water can be trapped.

Visual:
      |
    | | |
  | | | |
| | | | | | | |
Height: 0 1 0 2 1 0 1 3 2 1 2 1
Water:  0 0 1 0 1 2 1 0 1 2 1 2
```

### Step 2: Pattern Identification (3 seconds)
"Water trap" + "Between bars" + "Maximum on sides"
→ **TWO-POINTER or PREFIX-SUFFIX PATTERN**

**Magic Keywords:** trap, container, boundaries, max heights

### Step 3: Approach (Two-Pointer Method)

```
Key Insight:
Water at position i = min(max_left, max_right) - height[i]

- max_left[i] = maximum height to the left of i
- max_right[i] = maximum height to the right of i
- Water trapped = min(max_left, max_right) - height[i]

Two-Pointer Optimization:
If we track max_left and max_right as we go, we don't need extra arrays.
Move pointer with smaller height (because water is limited by smaller boundary).

Algorithm:
1. left = 0, right = n-1
2. max_left = 0, max_right = 0
3. total_water = 0
4. While left < right:
   - If height[left] < height[right]:
     - Update max_left
     - Add water at left: max_left - height[left]
     - Move left++
   - Else:
     - Update max_right
     - Add water at right: max_right - height[right]
     - Move right--

Complexity: Time O(n), Space O(1)
```

### Step 4: Dry Run

```
height = [0,1,0,2,1,0,1,3,2,1,2,1]
indices:  0 1 2 3 4 5 6 7 8 9 10 11

Initial:
left=0, right=11, max_left=0, max_right=0, water=0

Iteration 1: height[0]=0, height[11]=1
  height[0]=0 < height[11]=1
  max_left = max(0, 0) = 0
  water += 0 - 0 = 0
  left=1

Iteration 2: height[1]=1, height[11]=1
  height[1]=1 == height[11]=1 (go to else)
  max_right = max(0, 1) = 1
  water += 1 - 1 = 0
  right=10

Iteration 3: height[1]=1, height[10]=2
  height[1]=1 < height[10]=2
  max_left = max(0, 1) = 1
  water += 1 - 1 = 0
  left=2

Iteration 4: height[2]=0, height[10]=2
  height[2]=0 < height[10]=2
  max_left = max(1, 0) = 1
  water += 1 - 0 = 1 ✓ (water trapped at index 2)
  left=3

Iteration 5: height[3]=2, height[10]=2
  height[3]=2 == height[10]=2
  max_right = max(1, 2) = 2
  water += 2 - 2 = 0
  right=9

Iteration 6: height[3]=2, height[9]=1
  height[3]=2 > height[9]=1
  max_right = max(2, 1) = 2
  water += 2 - 1 = 1 ✓ (water trapped at index 9)
  right=8

Continue this process...

Final Result: 6 units of water ✓
```

### Step 5: Complete Code

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    water += max_left - height[left];
                }
                left++;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    water += max_right - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
};

// Time Complexity: O(n) - single pass
// Space Complexity: O(1) - only variables
// Interview Plus: "Sir, two-pointer O(1) space optimal solution"
```

**Interview Communication:**
> "Sir, water trapped at position i depends on maximum heights on both sides. Water = min(max_left, max_right) - height[i]. Using two pointers, I track maximums as I move inward. Move the pointer with smaller height because water is limited by the smaller boundary. O(n) time, O(1) space."

---

## 🎬 PROBLEM 4: 3SUM

### Step 1: Problem Statement
```
Given integer array nums of length n, return all unique triplets that sum to 0.
Solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = [0]
Output: []

Example 3:
Input: nums = [0,0,0,0]
Output: [[0,0,0]]
```

### Step 2: Pattern Identification (3 seconds)
"Find triplets" + "Sum to target" + "Unique" 
→ **TWO-POINTER + SORTING + DEDUPLICATION**

**Magic Keywords:** three numbers, triplets, unique, avoid duplicates

### Step 3: Approach

```
Challenge: Find UNIQUE triplets efficiently

Naive Approach: Brute force O(n³) → WRONG for interviews

Optimal Approach:
1. Sort array
2. For each element, reduce problem to 2Sum
3. Use two pointers for 2Sum
4. Handle duplicates carefully

Algorithm:
1. Sort array
2. For i from 0 to n-3:
   - If nums[i] > 0, break (can't sum to 0 with positive numbers)
   - If nums[i] == nums[i-1], continue (skip duplicate)
   - Find two numbers that sum to -nums[i]
   - Use two pointers: left = i+1, right = n-1
   - Adjust pointers based on sum

Deduplication:
- Skip duplicate elements at current position
- Skip duplicate elements at left pointer
- Skip duplicate elements at right pointer

Complexity: Time O(n²), Space O(1)
```

### Step 4: Dry Run

```
nums = [-1,0,1,2,-1,-4]

Step 1: Sort
[-4,-1,-1,0,1,2]
indices: 0  1  2 3 4 5

Step 2: For each i, find 2Sum of -nums[i]

i=0, nums[0]=-4, target=-(-4)=4
  Need two numbers that sum to 4
  left=1, right=5
  sum = -1 + 2 = 1 < 4, left++
  sum = 0 + 2 = 2 < 4, left++
  sum = 1 + 2 = 3 < 4, left++
  left > right, break
  No triplets found

i=1, nums[1]=-1, target=1
  Need two numbers that sum to 1
  left=2, right=5
  sum = -1 + 2 = 1 == 1 ✓
  Add [-1,-1,2]
  Skip duplicate at left: i=2, nums[2]=-1, skip
  left=3, right=5
  sum = 0 + 2 = 2 > 1, right--
  sum = 0 + 1 = 1 == 1 ✓
  Add [-1,0,1]
  left=4, right=4, stop

i=2, nums[2]=-1, skip (duplicate of i=1)

i=3, nums[3]=0 > 0 for 2Sum? Actually continue anyway...
  Actually let's check: need sum = 0
  left=4, right=5
  sum = 1 + 2 = 3 > 0, right--
  sum = 1 + 1 = 2... wait, indices
  Actually left=4, right=5, but after previous iteration...
  
Let me recalculate i=3:
i=3, nums[3]=0, target=0
  left=4, right=5
  sum = 1 + 2 = 3 > 0, right--
  left=4, right=4, left >= right, stop

Final Result: [[-1,-1,2], [-1,0,1]] ✓
```

### Step 5: Complete Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // Optimization: if nums[i] > 0, no solution
            if (nums[i] > 0) break;
            
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Two pointer approach for 2Sum
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates at left
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Skip duplicates at right
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

// Time Complexity: O(n²) - outer loop O(n), inner 2Sum O(n)
// Space Complexity: O(1) - only pointers
// Interview Plus: "Sir, two-pointer approach with careful deduplication"
```

**Interview Communication:**
> "Sir, I'll sort the array first. For each element, I reduce the problem to 2Sum. Use two pointers to find pairs that sum to -nums[i]. The key is careful deduplication - skip duplicates at each position. Time O(n²), space O(1)."

---

## 🎬 PROBLEM 5: ROTATE SORTED ARRAY II (WITH DUPLICATES)

### Step 1: Problem Statement
```
Suppose an array sorted in ascending order is rotated at some pivot unknown 
to you beforehand. You are given a target value to search for. If found in the 
array return its index, otherwise return -1. The array may contain duplicates.

Example 1:
Input: nums = [1,0,1,1,1], target = 0
Output: 1

Example 2:
Input: nums = [1,3], target = 3
Output: 1

Example 3:
Input: nums = [1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1], target = 2
Output: 13
```

### Step 2: Pattern Identification (3 seconds)
"Rotated sorted array" + "Duplicates" + "Search"
→ **MODIFIED BINARY SEARCH + DUPLICATE HANDLING**

**Magic Keywords:** rotated, pivot, duplicate, find element

### Step 3: Approach

```
Challenge: Duplicates make it hard to know which half is sorted!

Key Issue:
When arr[mid] == arr[left] == arr[right], we can't determine which half is sorted.

Algorithm:
1. Binary search as usual
2. If nums[mid] == nums[left] == nums[right]:
   - We can't determine sorted half
   - Shrink left and right: left++, right--
3. Else:
   - One half is definitely sorted
   - Determine which half has target
   - Move pointers accordingly

Complexity: Time O(n) worst (when all duplicates), O(log n) average
```

### Step 4: Dry Run

```
nums = [1,0,1,1,1], target = 0

Initial: low=0, high=4

Iteration 1:
  mid = 0 + (4-0)/2 = 2
  nums[2] = 1
  
  Check if duplicates confuse us:
  nums[low]=1, nums[mid]=1, nums[high]=1
  All equal! We can't know which half is sorted
  left++, right--
  left=1, right=3

Iteration 2:
  mid = 1 + (3-1)/2 = 2
  nums[2] = 1
  
  nums[1]=0, nums[2]=1, nums[3]=1
  Not all equal
  
  Is right half sorted? nums[mid]=1, nums[high]=1
  Check if target is in right sorted half: 1 <= 0 <= 1? NO
  So target might be in left half
  high = mid - 1 = 1

Iteration 3:
  left=1, high=1, mid=1
  nums[1] = 0 == target ✓
  
  Return 1 ✓
```

### Step 5: Complete Code

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            
            // Determine which half is sorted
            if (nums[left] <= nums[mid]) {
                // Left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    // Target is in left sorted half
                    right = mid - 1;
                } else {
                    // Target is in right half
                    left = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    // Target is in right sorted half
                    left = mid + 1;
                } else {
                    // Target is in left half
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};

// Time Complexity: O(n) worst case (all duplicates), O(log n) average
// Space Complexity: O(1)
// Interview Plus: "Sir, modified BS with duplicate handling for worst case"
```

**Interview Communication:**
> "Sir, this is modified binary search with duplicate handling. When left, mid, and right values are equal, we can't determine which half is sorted, so we shrink both pointers. Otherwise, we identify the sorted half and determine if target is in it. Time O(log n) average, O(n) worst case with duplicates."

---

## 📚 SUMMARY TABLE

| Problem | Pattern | Key Technique | Time | Space |
|---------|---------|---------------|------|-------|
| Container | Two-Pointer | Move smaller pointer | O(n) | O(1) |
| Merge Intervals | Sort+Greedy | Greedy merging | O(n log n) | O(n) |
| Trapping Water | Two-Pointer | Track max heights | O(n) | O(1) |
| 3Sum | Two-Pointer+Sort | Reduce to 2Sum | O(n²) | O(1) |
| Rotate+Duplicate | Modified BS | Handle duplicates | O(log n)* | O(1) |

---

## ✅ PRACTICE CHECKLIST

```
After mastering these 5 problems, you should be able to:

□ Identify two-pointer problems instantly
□ Recognize when to sort vs when not to sort
□ Handle duplicates in sorted arrays
□ Write O(1) space solutions
□ Communicate approach clearly
□ Solve each problem in <15 minutes
□ Do dry run without looking at code
□ Handle all edge cases
□ Optimize without hints
□ Code correctly first attempt
```

---

**Ready to master Medium Array problems?** 💪

Next: Binary Search Medium Problems

