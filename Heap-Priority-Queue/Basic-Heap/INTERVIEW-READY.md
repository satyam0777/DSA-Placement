# 🔥 HEAP & PRIORITY QUEUE - BASIC CONCEPTS
## Interview-Ready Package for Service-Based Companies

---

## 📚 WHAT IS A HEAP?

### **Simple Definition:**
> **Heap** is a **complete binary tree** where every parent node follows a specific order with its children.

### **Two Types:**

**1. Min Heap:**
- Parent **≤** Children
- **Smallest element** at root
- Used for: K largest, smallest element

**2. Max Heap:**
- Parent **≥** Children  
- **Largest element** at root
- Used for: K smallest, largest element

---

## 🎯 HEAP vs PRIORITY QUEUE

### **Heap (Data Structure):**
```
Complete Binary Tree with heap property
Array representation: parent at i, children at 2i+1, 2i+2
```

### **Priority Queue (ADT - Abstract Data Type):**
```
Queue where elements have priority
Implemented using Heap
Operations: insert, delete, getTop (highest/lowest priority)
```

**In C++:**
```cpp
priority_queue<int> pq;  // This is a MAX HEAP by default!
```

---

## 🔑 KEY INSIGHTS (MUST REMEMBER!)

### **Golden Rule for K problems:**

```
┌─────────────────────────────────────────┐
│  K LARGEST elements?                    │
│  → Use MIN HEAP of size K               │
│  → Keep largest K, remove smallest      │
└─────────────────────────────────────────┘

┌─────────────────────────────────────────┐
│  K SMALLEST elements?                   │
│  → Use MAX HEAP of size K               │
│  → Keep smallest K, remove largest      │
└─────────────────────────────────────────┘
```

**Why?**
- Min heap (size k): Top = smallest of k largest = Kth largest
- Max heap (size k): Top = largest of k smallest = Kth smallest

---

## 💻 C++ STL SYNTAX (MUST MEMORIZE!)

### **1. Max Heap (Default):**
```cpp
#include <queue>
using namespace std;

priority_queue<int> maxHeap;

// Operations
maxHeap.push(10);           // O(log n) - insert
maxHeap.push(20);
maxHeap.push(5);

int top = maxHeap.top();    // O(1) - peek (returns 20)
maxHeap.pop();              // O(log n) - remove top

int size = maxHeap.size();  // O(1)
bool empty = maxHeap.empty(); // O(1)
```

**Output:** 20 (largest element)

---

### **2. Min Heap (Most Used!):**
```cpp
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;

// Operations
minHeap.push(10);           // O(log n)
minHeap.push(20);
minHeap.push(5);

int top = minHeap.top();    // O(1) - returns 5 (smallest)
minHeap.pop();              // O(log n)
```

**Output:** 5 (smallest element)

---

### **3. Custom Comparator (Pairs, Objects):**

**For Pairs (sort by first, then second):**
```cpp
// Min heap of pairs
priority_queue<pair<int,int>, 
               vector<pair<int,int>>, 
               greater<pair<int,int>>> minHeap;

minHeap.push({5, 10});
minHeap.push({3, 20});
minHeap.push({5, 5});

auto top = minHeap.top();  // {3, 20} - smallest first element
```

**For Custom Objects:**
```cpp
struct Point {
    int x, y;
    int distance() { return x*x + y*y; }
};

// Custom comparator
struct Compare {
    bool operator()(Point& a, Point& b) {
        return a.distance() > b.distance(); // Min heap
    }
};

priority_queue<Point, vector<Point>, Compare> pq;
```

---

## 📖 PROBLEM 1: KTH LARGEST ELEMENT IN ARRAY ⭐⭐⭐

**LeetCode 215 | GFG**

### **Problem:**
```
Given an array and integer k, find the kth largest element.

Example:
Input: arr = [3, 2, 1, 5, 6, 4], k = 2
Output: 5
Explanation: 2nd largest element is 5
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Kth Largest Element** problem. I'll use a **min heap of size k**.
> 
> **Approach:** I'll maintain a min heap containing the **k largest elements** seen so far. When heap size exceeds k, I'll remove the smallest element (top of min heap). At the end, the top of the min heap will be the **kth largest** element.
> 
> **Why min heap?** Because we want to keep the k largest elements and easily remove the smallest among them.
> 
> **Time Complexity:** O(n log k) - We process n elements, each heap operation is O(log k)
> **Space Complexity:** O(k) - Heap size is at most k
> 
> This is better than sorting which takes O(n log n)."

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap of size k
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int num : nums) {
            minHeap.push(num);
            
            // Maintain heap size k
            if(minHeap.size() > k) {
                minHeap.pop(); // Remove smallest
            }
        }
        
        // Top is kth largest
        return minHeap.top();
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "Kth Largest: " << sol.findKthLargest(arr1, k1) << endl;
    // Output: 5
    
    // Test Case 2
    vector<int> arr2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "Kth Largest: " << sol.findKthLargest(arr2, k2) << endl;
    // Output: 4
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arr = [3, 2, 1, 5, 6, 4], k = 2

```
Step 1: num = 3
    minHeap: [3]
    size = 1 ≤ k (2), no pop

Step 2: num = 2
    minHeap: [2, 3]
    size = 2 ≤ k (2), no pop

Step 3: num = 1
    minHeap: [1, 3, 2] → [1, 2, 3]
    size = 3 > k (2), pop smallest
    minHeap.pop() → removes 1
    minHeap: [2, 3]

Step 4: num = 5
    minHeap: [2, 3, 5] → [2, 3, 5]
    size = 3 > k (2), pop smallest
    minHeap.pop() → removes 2
    minHeap: [3, 5]

Step 5: num = 6
    minHeap: [3, 5, 6]
    size = 3 > k (2), pop smallest
    minHeap.pop() → removes 3
    minHeap: [5, 6]

Step 6: num = 4
    minHeap: [4, 6, 5] → [4, 5, 6]
    size = 3 > k (2), pop smallest
    minHeap.pop() → removes 4
    minHeap: [5, 6]

Final: minHeap.top() = 5 (2nd largest) ✅
```

**Heap State Visualization:**
```
After processing all elements:
    minHeap: [5, 6]
         5
        /
       6
    
Top (smallest in heap) = 5 = 2nd largest in array
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n log k) | n elements, each push/pop is O(log k) |
| **Space** | O(k) | Heap stores at most k elements |

**Why better than sorting?**
- Sorting: O(n log n) time, O(1) space (in-place)
- Heap: O(n log k) time, O(k) space
- When k << n, heap is much faster!

---

### **🎯 Edge Cases:**

```cpp
// Edge Case 1: k = 1 (largest element)
arr = [5, 2, 8, 1]
k = 1
Output: 8

// Edge Case 2: k = n (smallest element)
arr = [5, 2, 8, 1]
k = 4
Output: 1

// Edge Case 3: All elements same
arr = [5, 5, 5, 5]
k = 2
Output: 5

// Edge Case 4: Negative numbers
arr = [-1, -5, 3, 2]
k = 2
Output: 2

// Handle in code:
if(k > nums.size()) return -1; // Invalid k
```

---

### **🏢 Company Frequency:**
- **TCS:** 60-65%
- **Infosys:** 65-70%
- **Wipro:** 55-60%
- **Cognizant:** 60%

---

## 📖 PROBLEM 2: KTH SMALLEST ELEMENT IN ARRAY ⭐⭐

**GFG | Similar to Kth Largest**

### **Problem:**
```
Given an array and integer k, find the kth smallest element.

Example:
Input: arr = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element is 7 (sorted: 3, 4, 7, ...)
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Kth Smallest Element** problem. I'll use a **max heap of size k**.
> 
> **Approach:** I'll maintain a max heap containing the **k smallest elements** seen so far. When heap size exceeds k, I'll remove the largest element (top of max heap). At the end, the top of the max heap will be the **kth smallest** element.
> 
> **Why max heap?** Because we want to keep the k smallest elements and easily remove the largest among them.
> 
> **Time:** O(n log k), **Space:** O(k)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int>& nums, int k) {
        // Max heap of size k
        priority_queue<int> maxHeap;
        
        for(int num : nums) {
            maxHeap.push(num);
            
            // Maintain heap size k
            if(maxHeap.size() > k) {
                maxHeap.pop(); // Remove largest
            }
        }
        
        // Top is kth smallest
        return maxHeap.top();
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {7, 10, 4, 3, 20, 15};
    int k1 = 3;
    cout << "Kth Smallest: " << sol.kthSmallest(arr1, k1) << endl;
    // Output: 7
    
    // Test Case 2
    vector<int> arr2 = {7, 10, 4, 3, 20, 15};
    int k2 = 4;
    cout << "Kth Smallest: " << sol.kthSmallest(arr2, k2) << endl;
    // Output: 10
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arr = [7, 10, 4, 3, 20, 15], k = 3

```
Step 1: num = 7
    maxHeap: [7]
    size = 1 ≤ k (3), no pop

Step 2: num = 10
    maxHeap: [10, 7]
    size = 2 ≤ k (3), no pop

Step 3: num = 4
    maxHeap: [10, 7, 4]
    size = 3 ≤ k (3), no pop

Step 4: num = 3
    maxHeap: [10, 7, 4, 3]
    size = 4 > k (3), pop largest
    maxHeap.pop() → removes 10
    maxHeap: [7, 4, 3]

Step 5: num = 20
    maxHeap: [20, 7, 4, 3]
    size = 4 > k (3), pop largest
    maxHeap.pop() → removes 20
    maxHeap: [7, 4, 3]

Step 6: num = 15
    maxHeap: [15, 7, 4, 3]
    size = 4 > k (3), pop largest
    maxHeap.pop() → removes 15
    maxHeap: [7, 4, 3]

Final: maxHeap.top() = 7 (3rd smallest) ✅
```

**Sorted array for reference:** [3, 4, 7, 10, 15, 20]
- 1st smallest: 3
- 2nd smallest: 4
- **3rd smallest: 7** ✅

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n log k) | n elements, each heap operation is O(log k) |
| **Space** | O(k) | Heap stores at most k elements |

---

### **🏢 Company Frequency:**
- **TCS:** 55-60%
- **Infosys:** 60-65%
- **Wipro:** 50-55%

---

## 📖 PROBLEM 3: TOP K FREQUENT ELEMENTS ⭐⭐⭐

**LeetCode 347 | Very Popular!**

### **Problem:**
```
Given an array, return the k most frequent elements.

Example:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1, 2]
Explanation: 1 appears 3 times, 2 appears 2 times (top 2 frequent)
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Top K Frequent Elements** problem. I'll use a **two-step approach**: first create a frequency map, then use a **min heap of size k** to find top k frequent.
> 
> **Step 1:** Build frequency map using unordered_map. Time O(n).
> 
> **Step 2:** Iterate through the map and maintain a min heap of size k. The heap stores pairs {frequency, element}. When heap size exceeds k, I pop the element with minimum frequency.
> 
> **Why min heap?** We want to keep k most frequent elements and easily remove the least frequent among them.
> 
> **Time:** O(n log k), **Space:** O(n) for map + O(k) for heap"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Build frequency map
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Min heap of size k
        // Pair: {frequency, element}
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> minHeap;
        
        for(auto& [num, count] : freq) {
            minHeap.push({count, num});
            
            if(minHeap.size() > k) {
                minHeap.pop(); // Remove least frequent
            }
        }
        
        // Step 3: Extract elements from heap
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> res1 = sol.topKFrequent(nums1, k1);
    
    cout << "Top K Frequent: ";
    for(int x : res1) cout << x << " ";
    cout << endl;
    // Output: 1 2 (or 2 1, order doesn't matter)
    
    // Test Case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> res2 = sol.topKFrequent(nums2, k2);
    
    cout << "Top K Frequent: ";
    for(int x : res2) cout << x << " ";
    cout << endl;
    // Output: 1
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** nums = [1, 1, 1, 2, 2, 3], k = 2

```
Step 1: Build Frequency Map
    1 → 3
    2 → 2
    3 → 1

Step 2: Process each {element, frequency}
    
    Process {1, 3}:
        minHeap: [{3, 1}]
        size = 1 ≤ k (2), no pop
    
    Process {2, 2}:
        minHeap: [{2, 2}, {3, 1}]
                    ↑ top (smallest frequency)
        size = 2 ≤ k (2), no pop
    
    Process {3, 1}:
        minHeap: [{1, 3}, {2, 2}, {3, 1}]
        size = 3 > k (2), pop smallest frequency
        minHeap.pop() → removes {1, 3}
        minHeap: [{2, 2}, {3, 1}]

Step 3: Extract from heap
    Pop {3, 1} → add 1 to result
    Pop {2, 2} → add 2 to result
    
Final: result = [1, 2] ✅
```

**Visualization:**
```
Frequency Map:
    1 → 3 times (most frequent)
    2 → 2 times
    3 → 1 time

Min Heap (stores top 2):
    {2, 2}
       /
   {3, 1}

Result: [1, 2]
```

---

### **⏱️ Complexity Analysis:**

| Operation | Complexity | Explanation |
|-----------|------------|-------------|
| **Build freq map** | O(n) | Process all n elements |
| **Heap operations** | O(m log k) | m unique elements, heap size k |
| **Extract result** | O(k log k) | Remove k elements |
| **Total Time** | **O(n log k)** | Dominated by heap operations |
| **Space** | O(n) | Frequency map + heap |

**Where:** n = total elements, m = unique elements, k = top k

---

### **🎯 Edge Cases:**

```cpp
// Edge Case 1: k = number of unique elements
nums = [1, 2, 3]
k = 3
Output: [1, 2, 3] (all elements)

// Edge Case 2: Single element
nums = [1]
k = 1
Output: [1]

// Edge Case 3: All elements same frequency
nums = [1, 2, 3, 4]
k = 2
Output: Any 2 elements

// Handle in code:
if(k >= freq.size()) {
    // Return all unique elements
}
```

---

### **🏢 Company Frequency:**
- **TCS:** 60-65%
- **Infosys:** 70-75% ⭐
- **Wipro:** 55-60%
- **Amazon:** 95% ⭐⭐⭐
- **Microsoft:** 85%

**Note:** Very popular in both service-based and product-based companies!

---

## 📖 PROBLEM 4: K CLOSEST POINTS TO ORIGIN ⭐⭐⭐

**LeetCode 973**

### **Problem:**
```
Given array of points [x, y] and integer k, find k closest points to origin (0, 0).
Distance = √(x² + y²) = x² + y² (no sqrt needed for comparison)

Example:
Input: points = [[1,3], [-2,2], [5,8], [0,1]], k = 2
Output: [[-2,2], [0,1]]
Explanation: 
    [1,3]: distance = 1+9 = 10
    [-2,2]: distance = 4+4 = 8 ✅
    [5,8]: distance = 25+64 = 89
    [0,1]: distance = 0+1 = 1 ✅
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **K Closest Points** problem. I'll use a **max heap of size k** where each element is a pair {distance, point}.
> 
> **Approach:** For each point, I calculate its distance from origin (x²+y², no need for sqrt). I maintain a max heap of size k containing the k closest points. When heap size exceeds k, I remove the farthest point (maximum distance).
> 
> **Why max heap?** Because we want to keep k closest (smallest distances) and easily remove the farthest among them.
> 
> **Time:** O(n log k), **Space:** O(k)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: {distance, {x, y}}
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        
        for(auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x*x + y*y; // No need for sqrt
            
            maxHeap.push({dist, {x, y}});
            
            // Maintain size k
            if(maxHeap.size() > k) {
                maxHeap.pop(); // Remove farthest
            }
        }
        
        // Extract k closest points
        vector<vector<int>> result;
        while(!maxHeap.empty()) {
            auto [dist, point] = maxHeap.top();
            maxHeap.pop();
            result.push_back({point.first, point.second});
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> points1 = {{1,3}, {-2,2}, {5,8}, {0,1}};
    int k1 = 2;
    auto res1 = sol.kClosest(points1, k1);
    
    cout << "K Closest Points: ";
    for(auto& p : res1) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;
    // Output: [0,1] [-2,2]
    
    // Test Case 2
    vector<vector<int>> points2 = {{3,3}, {5,-1}, {-2,4}};
    int k2 = 2;
    auto res2 = sol.kClosest(points2, k2);
    
    cout << "K Closest Points: ";
    for(auto& p : res2) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << endl;
    // Output: [3,3] [-2,4]
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** points = [[1,3], [-2,2], [5,8], [0,1]], k = 2

```
Step 1: Point [1, 3]
    dist = 1² + 3² = 1 + 9 = 10
    maxHeap: [{10, {1,3}}]
    size = 1 ≤ k (2), no pop

Step 2: Point [-2, 2]
    dist = (-2)² + 2² = 4 + 4 = 8
    maxHeap: [{10, {1,3}}, {8, {-2,2}}]
              ↑ top (maximum distance)
    size = 2 ≤ k (2), no pop

Step 3: Point [5, 8]
    dist = 5² + 8² = 25 + 64 = 89
    maxHeap: [{89, {5,8}}, {10, {1,3}}, {8, {-2,2}}]
    size = 3 > k (2), pop maximum
    maxHeap.pop() → removes {89, {5,8}}
    maxHeap: [{10, {1,3}}, {8, {-2,2}}]

Step 4: Point [0, 1]
    dist = 0² + 1² = 0 + 1 = 1
    maxHeap: [{10, {1,3}}, {8, {-2,2}}, {1, {0,1}}]
    size = 3 > k (2), pop maximum
    maxHeap.pop() → removes {10, {1,3}}
    maxHeap: [{8, {-2,2}}, {1, {0,1}}]

Final: Extract points
    Pop {8, {-2,2}} → add [-2,2]
    Pop {1, {0,1}} → add [0,1]
    
Result: [[-2,2], [0,1]] ✅
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n log k) | n points, each heap operation is O(log k) |
| **Space** | O(k) | Heap stores at most k points |

---

### **🏢 Company Frequency:**
- **TCS:** 55-60%
- **Infosys:** 65-70%
- **Wipro:** 50-55%
- **Amazon:** 90%
- **Facebook:** 85%

---

## 📖 PROBLEM 5: MINIMUM COST TO CONNECT ROPES ⭐⭐⭐

**GFG | LeetCode 1167 (Premium)**

### **Problem:**
```
Given n ropes of different lengths, connect them into one rope.
Cost to connect two ropes = sum of their lengths.
Find minimum cost to connect all ropes.

Example:
Input: ropes = [4, 3, 2, 6]
Output: 29
Explanation:
    Connect 2 + 3 = 5, cost = 5
    Connect 4 + 5 = 9, cost = 9
    Connect 6 + 9 = 15, cost = 15
    Total = 5 + 9 + 15 = 29
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Minimum Cost to Connect Ropes** problem. This is a **greedy algorithm** problem where I should **always connect the two smallest ropes** to minimize cost.
> 
> **Approach:** I'll use a **min heap** to always get the two smallest ropes. I connect them, add the cost, and push the new rope back to the heap. I repeat until only one rope remains.
> 
> **Why greedy works?** Smaller ropes should be connected first because they contribute to cost multiple times (they become part of larger ropes).
> 
> **Time:** O(n log n), **Space:** O(n)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int connectRopes(vector<int>& ropes) {
        // Min heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Add all ropes to heap
        for(int rope : ropes) {
            minHeap.push(rope);
        }
        
        int totalCost = 0;
        
        // Connect ropes until one remains
        while(minHeap.size() > 1) {
            // Get two smallest ropes
            int first = minHeap.top(); minHeap.pop();
            int second = minHeap.top(); minHeap.pop();
            
            // Connect them
            int cost = first + second;
            totalCost += cost;
            
            // Push new rope back
            minHeap.push(cost);
        }
        
        return totalCost;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> ropes1 = {4, 3, 2, 6};
    cout << "Minimum Cost: " << sol.connectRopes(ropes1) << endl;
    // Output: 29
    
    // Test Case 2
    vector<int> ropes2 = {1, 2, 3, 4, 5};
    cout << "Minimum Cost: " << sol.connectRopes(ropes2) << endl;
    // Output: 33
    
    // Test Case 3
    vector<int> ropes3 = {5, 4, 2, 8};
    cout << "Minimum Cost: " << sol.connectRopes(ropes3) << endl;
    // Output: 36
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** ropes = [4, 3, 2, 6]

```
Initial: minHeap = [2, 3, 4, 6]

Iteration 1:
    Pop: 2, 3 (two smallest)
    Connect: 2 + 3 = 5
    Cost: 5
    Total Cost: 5
    Push: 5
    minHeap: [4, 5, 6]

Iteration 2:
    Pop: 4, 5 (two smallest)
    Connect: 4 + 5 = 9
    Cost: 9
    Total Cost: 5 + 9 = 14
    Push: 9
    minHeap: [6, 9]

Iteration 3:
    Pop: 6, 9 (two smallest)
    Connect: 6 + 9 = 15
    Cost: 15
    Total Cost: 14 + 15 = 29
    Push: 15
    minHeap: [15] (only one rope, stop)

Final: Total Cost = 29 ✅
```

**Visualization:**
```
Step-by-step connection:
    [4, 3, 2, 6]
         ↓
    [4, (2+3=5), 6]  cost = 5
         ↓
    [(4+5=9), 6]     cost = 9
         ↓
    [9+6=15]         cost = 15
    
Total = 5 + 9 + 15 = 29
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n log n) | n-1 merges, each with 2 pops + 1 push = O(log n) |
| **Space** | O(n) | Min heap stores all n ropes initially |

---

### **💡 Why Greedy Works:**

**Example showing greedy optimality:**

**Ropes:** [2, 3, 4, 6]

**Greedy (always connect smallest):**
```
2+3=5 (cost 5)
4+5=9 (cost 9)
6+9=15 (cost 15)
Total: 29 ✅
```

**Non-greedy (connect larger first):**
```
4+6=10 (cost 10)
2+3=5 (cost 5)
5+10=15 (cost 15)
Total: 30 ❌
```

**Key Insight:** Smaller ropes contribute to cost multiple times (they're part of larger merged ropes), so connect them first to minimize cumulative cost.

---

### **🏢 Company Frequency:**
- **TCS:** 65-70%
- **Infosys:** 70-75% ⭐
- **Wipro:** 60-65%
- **Amazon:** 80%

---

## 📖 PROBLEM 6: SORT NEARLY SORTED (K-SORTED) ARRAY ⭐⭐

**GFG | Important Concept**

### **Problem:**
```
Given a nearly sorted array where each element is at most k positions away 
from its target position, sort the array.

Example:
Input: arr = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]

Explanation: Element at index 0 can be at most at index 0-3 to 0+3 in sorted array.
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Sort K-Sorted Array** problem. Since each element is at most k positions away from its sorted position, I can use a **min heap of size k+1**.
> 
> **Approach:** I maintain a window of k+1 elements in a min heap. The smallest element in this window must be at the current position in sorted order. I keep removing the minimum and adding new elements.
> 
> **Why k+1?** Because an element can be k positions away, so we need k+1 elements to ensure we have the smallest for current position.
> 
> **Time:** O(n log k), **Space:** O(k)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortKSorted(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        
        // Min heap of size k+1
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Add first k+1 elements
        for(int i = 0; i <= k && i < n; i++) {
            minHeap.push(arr[i]);
        }
        
        // Process remaining elements
        int index = k + 1;
        while(!minHeap.empty()) {
            // Smallest element goes to result
            result.push_back(minHeap.top());
            minHeap.pop();
            
            // Add next element if exists
            if(index < n) {
                minHeap.push(arr[index]);
                index++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {6, 5, 3, 2, 8, 10, 9};
    int k1 = 3;
    vector<int> res1 = sol.sortKSorted(arr1, k1);
    
    cout << "Sorted Array: ";
    for(int x : res1) cout << x << " ";
    cout << endl;
    // Output: 2 3 5 6 8 9 10
    
    // Test Case 2
    vector<int> arr2 = {10, 9, 8, 7, 4, 70, 60, 50};
    int k2 = 4;
    vector<int> res2 = sol.sortKSorted(arr2, k2);
    
    cout << "Sorted Array: ";
    for(int x : res2) cout << x << " ";
    cout << endl;
    // Output: 4 7 8 9 10 50 60 70
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arr = [6, 5, 3, 2, 8, 10, 9], k = 3

```
Step 1: Add first k+1 = 4 elements
    minHeap: [2, 3, 5, 6]
    index = 4

Step 2: Extract min, add next
    min = 2 → result: [2]
    Add arr[4] = 8
    minHeap: [3, 5, 6, 8]
    index = 5

Step 3: Extract min, add next
    min = 3 → result: [2, 3]
    Add arr[5] = 10
    minHeap: [5, 6, 8, 10]
    index = 6

Step 4: Extract min, add next
    min = 5 → result: [2, 3, 5]
    Add arr[6] = 9
    minHeap: [6, 8, 9, 10]
    index = 7 (out of bounds)

Step 5: Extract remaining
    min = 6 → result: [2, 3, 5, 6]
    min = 8 → result: [2, 3, 5, 6, 8]
    min = 9 → result: [2, 3, 5, 6, 8, 9]
    min = 10 → result: [2, 3, 5, 6, 8, 9, 10]

Final: [2, 3, 5, 6, 8, 9, 10] ✅
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n log k) | n elements, heap size k+1 |
| **Space** | O(k) | Min heap of size k+1 |

**Better than O(n log n) sorting when k << n!**

---

### **🏢 Company Frequency:**
- **TCS:** 50-55%
- **Infosys:** 60-65%
- **Wipro:** 45-50%

---

## 📖 PROBLEM 7: MERGE K SORTED ARRAYS ⭐⭐

**GFG | Interview Favorite**

### **Problem:**
```
Given k sorted arrays, merge them into one sorted array.

Example:
Input: arrays = [[1, 3, 5], [2, 4, 6], [0, 7, 8]]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8]
```

---

### **💡 Interview Communication Script:**

> "Sir, this is a **Merge K Sorted Arrays** problem. I'll use a **min heap** to efficiently merge.
> 
> **Approach:** I'll create a min heap containing the first element from each array along with its array index and element index. I'll keep extracting the minimum, add it to result, and insert the next element from the same array.
> 
> **Why min heap?** It gives us the smallest element among k arrays in O(log k) time.
> 
> **Time:** O(n*k log k) where n = average array size, **Space:** O(k)"

---

### **📝 Complete C++ Code:**

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // Structure to store element info
    struct Element {
        int value;
        int arrayIndex;
        int elementIndex;
        
        // Comparator for min heap
        bool operator>(const Element& other) const {
            return value > other.value;
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>>& arrays) {
        vector<int> result;
        
        // Min heap
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        
        // Add first element from each array
        for(int i = 0; i < arrays.size(); i++) {
            if(!arrays[i].empty()) {
                minHeap.push({arrays[i][0], i, 0});
            }
        }
        
        // Extract min and add next from same array
        while(!minHeap.empty()) {
            Element curr = minHeap.top();
            minHeap.pop();
            
            result.push_back(curr.value);
            
            // Add next element from same array
            int nextIndex = curr.elementIndex + 1;
            if(nextIndex < arrays[curr.arrayIndex].size()) {
                minHeap.push({
                    arrays[curr.arrayIndex][nextIndex],
                    curr.arrayIndex,
                    nextIndex
                });
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<vector<int>> arrays1 = {{1, 3, 5}, {2, 4, 6}, {0, 7, 8}};
    vector<int> res1 = sol.mergeKArrays(arrays1);
    
    cout << "Merged Array: ";
    for(int x : res1) cout << x << " ";
    cout << endl;
    // Output: 0 1 2 3 4 5 6 7 8
    
    // Test Case 2
    vector<vector<int>> arrays2 = {{1, 2}, {3, 4}, {5, 6}};
    vector<int> res2 = sol.mergeKArrays(arrays2);
    
    cout << "Merged Array: ";
    for(int x : res2) cout << x << " ";
    cout << endl;
    // Output: 1 2 3 4 5 6
    
    return 0;
}
```

---

### **🔍 Dry Run:**

**Input:** arrays = [[1,3,5], [2,4,6], [0,7,8]]

```
Step 1: Initialize heap with first elements
    minHeap: [{0, arr=2, idx=0}, {1, arr=0, idx=0}, {2, arr=1, idx=0}]

Step 2: Extract 0
    result: [0]
    Add next from array 2: 7
    minHeap: [{1, arr=0, idx=0}, {2, arr=1, idx=0}, {7, arr=2, idx=1}]

Step 3: Extract 1
    result: [0, 1]
    Add next from array 0: 3
    minHeap: [{2, arr=1, idx=0}, {3, arr=0, idx=1}, {7, arr=2, idx=1}]

Step 4: Extract 2
    result: [0, 1, 2]
    Add next from array 1: 4
    minHeap: [{3, arr=0, idx=1}, {4, arr=1, idx=1}, {7, arr=2, idx=1}]

Step 5: Extract 3
    result: [0, 1, 2, 3]
    Add next from array 0: 5
    minHeap: [{4, arr=1, idx=1}, {5, arr=0, idx=2}, {7, arr=2, idx=1}]

Continue similarly...

Final: [0, 1, 2, 3, 4, 5, 6, 7, 8] ✅
```

---

### **⏱️ Complexity Analysis:**

| Aspect | Complexity | Explanation |
|--------|------------|-------------|
| **Time** | O(n*k log k) | n*k total elements, heap operations O(log k) |
| **Space** | O(k) | Heap stores at most k elements |

**Where:** k = number of arrays, n = average array size

---

### **🏢 Company Frequency:**
- **TCS:** 55-60%
- **Infosys:** 65-70%
- **Wipro:** 50-55%
- **Amazon:** 85%

---

## 🎯 SUMMARY - BASIC HEAP CONCEPTS

### **Key Takeaways:**

1. **Heap Types:**
   - Min Heap: Parent ≤ Children (smallest at top)
   - Max Heap: Parent ≥ Children (largest at top)

2. **Golden Rule:**
   - K Largest → Min Heap (size k)
   - K Smallest → Max Heap (size k)

3. **C++ STL:**
   ```cpp
   // Max heap (default)
   priority_queue<int> maxHeap;
   
   // Min heap
   priority_queue<int, vector<int>, greater<int>> minHeap;
   ```

4. **Common Patterns:**
   - Top K problems → Heap of size k
   - Merge K sorted → Min heap with tracking
   - K-sorted array → Min heap window
   - Greedy merging → Min heap (connect ropes)

5. **Time Complexity:**
   - Insert/Delete: O(log n)
   - Get top: O(1)
   - K problems: O(n log k)

---

### **Problems Covered:**

1. ✅ Kth Largest Element (Min heap size k)
2. ✅ Kth Smallest Element (Max heap size k)
3. ✅ Top K Frequent (Frequency map + min heap)
4. ✅ K Closest Points (Max heap with distances)
5. ✅ Connect Ropes (Min heap greedy)
6. ✅ Sort K-Sorted Array (Min heap window)
7. ✅ Merge K Sorted Arrays (Min heap with tracking)

---

### **Company-Wise Focus:**

**TCS:**
- Kth Largest/Smallest
- Connect Ropes
- Basic heap operations

**Infosys:**
- Top K Frequent ⭐⭐⭐
- Connect Ropes ⭐⭐⭐
- K Closest Points
- Merge K Arrays

**Wipro:**
- Kth Largest
- Sort K-Sorted
- Basic concepts

---

## 💪 NEXT STEPS

You've completed **Basic Heap Concepts**! 🎉

**Next:** `Heap-Patterns/INTERVIEW-READY.md` for:
- Running Median from Stream
- Smallest Range in K Lists
- Reorganize String
- Task Scheduler
- And more advanced patterns!

---

**All the best, Satyam!** 🌟  
**Heap is powerful and easy with STL!** 💯

Remember: **K Largest → Min Heap, K Smallest → Max Heap** 🎯
