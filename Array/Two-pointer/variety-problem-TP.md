
# Two-Pointer Technique: Variations, Problems, and Step-by-Step Thinking

---

## 1. Reverse an Array or String In-Place

**Concept:**  
Swap elements from both ends moving towards the center.

**Step-by-Step Thinking:**
1. Place one pointer at the start (`left`), one at the end (`right`).
2. Swap the elements at `left` and `right`.
3. Move `left` forward and `right` backward.
4. Repeat until `left >= right`.

**Code:**
```cpp
void reverseArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while(left < right) {
        swap(arr[left], arr[right]);
        left++; right--;
    }
}
```

---

## 2. Move Zeros to End

**Concept:**  
Move all zeros to the end while maintaining the order of non-zero elements.

**Step-by-Step Thinking:**
1. Use two pointers: `i` for traversing, `j` for the position to place the next non-zero.
2. Traverse the array with `i`.
3. If `arr[i]` is non-zero, swap it with `arr[j]` and increment `j`.
4. All zeros will be pushed to the end.

**Code:**
```cpp
void moveZeroes(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
```

---

## 3. Container With Most Water (Leetcode 11)

**Concept:**  
Find two lines that together with the x-axis form a container, such that the container contains the most water.

**Step-by-Step Thinking:**
1. Place `left` at the start, `right` at the end.
2. Calculate area: `min(height[left], height[right]) * (right - left)`.
3. Move the pointer pointing to the shorter line inward (to try for a taller line).
4. Repeat until `left < right`.

**Code:**
```cpp
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, ans = 0;
    while(left < right) {
        ans = max(ans, min(height[left], height[right]) * (right - left));
        if(height[left] < height[right]) left++;
        else right--;
    }
    return ans;
}
```

---

## 4. Three Sum Problem

**Concept:**  
Find all unique triplets in the array which gives the sum of zero.

**Step-by-Step Thinking:**
1. Sort the array.
2. Fix one element (`i`), then use two pointers (`left`, `right`) for the rest.
3. For each fixed `i`, move `left` and `right` to find pairs such that `nums[i] + nums[left] + nums[right] == 0`.
4. Skip duplicates for both `i`, `left`, and `right`.

**Code:**
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i+1, right = nums.size()-1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                res.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if(sum < 0) left++;
            else right--;
        }
    }
    return res;
}
```

---

## 5. Remove Duplicates from Sorted Array II (At Most Twice)

**Concept:**  
Allow each element to appear at most twice.

**Step-by-Step Thinking:**
1. Use a pointer `j` to track the position for the next unique or allowed duplicate.
2. Traverse with `i`. If `nums[i]` is not equal to `nums[j-2]`, copy it to `nums[j]` and increment `j`.
3. This ensures at most two occurrences of each element.

**Code:**
```cpp
int removeDuplicates(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(j < 2 || nums[i] != nums[j-2]) {
            nums[j++] = nums[i];
        }
    }
    return j;
}
```

---

## 6. Partition Array by Parity

**Concept:**  
Rearrange array so that all even numbers come before odd numbers.

**Step-by-Step Thinking:**
1. Place `left` at the start, `right` at the end.
2. If `arr[left]` is even, move `left` forward.
3. If `arr[right]` is odd, move `right` backward.
4. If `arr[left]` is odd and `arr[right]` is even, swap and move both pointers.

**Code:**
```cpp
void partitionByParity(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        if(nums[left] % 2 == 0) left++;
        else if(nums[right] % 2 == 1) right--;
        else swap(nums[left++], nums[right--]);
    }
}
```

---

## 7. Trapping Rain Water

**Concept:**  
Calculate how much water can be trapped after raining.

**Step-by-Step Thinking:**
1. Use two pointers, `left` and `right`, at both ends.
2. Track `leftMax` and `rightMax` (highest bars seen so far from each side).
3. At each step, move the pointer with the lower height inward.
4. Water trapped at each position is `leftMax - height[left]` or `rightMax - height[right]`.

**Code:**
```cpp
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1, leftMax = 0, rightMax = 0, ans = 0;
    while(left < right) {
        if(height[left] < height[right]) {
            leftMax = max(leftMax, height[left]);
            ans += leftMax - height[left];
            left++;
        } else {
            rightMax = max(rightMax, height[right]);
            ans += rightMax - height[right];
            right--;
        }
    }
    return ans;
}
```

---

**Summary:**  
For each problem, break it down into:
- How to initialize the pointers.
- What condition to check at each step.
- When and how to move each pointer.
- What to do (swap, count, update answer) at each step.


---