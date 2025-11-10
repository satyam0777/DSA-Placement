# 🔥 QUEUE PATTERNS - INTERVIEW READY GUIDE
## Sliding Window + BFS + Advanced Queue Problems

---

## 🎯 QUEUE PATTERN CATEGORIES

### 1. Sliding Window with Queue/Deque
- Maximum/Minimum in sliding window
- First negative in window
- Sum of min and max in window

### 2. BFS (Breadth-First Search)
- Level order traversal
- Shortest path problems
- Connected components

### 3. Priority Queue (Min/Max Heap)
- K largest/smallest elements
- Merge K sorted arrays
- Top K frequent elements

### 4. Monotonic Queue/Deque
- Next greater/smaller in window
- Longest subarray with constraints

---

## 🧩 PROBLEM 1: SLIDING WINDOW MAXIMUM ⭐⭐⭐

### Problem Statement (LeetCode 239):
Find the maximum element in each sliding window of size k.

**Example:**
```
Input: arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]

Explanation:
  Window [1,  3, -1] → max = 3
  Window [3, -1, -3] → max = 3
  Window [-1, -3, 5] → max = 5
  Window [-3, 5,  3] → max = 5
  Window [5,  3,  6] → max = 6
  Window [3,  6,  7] → max = 7
```

### Communication Script:
> "Sir, deque-based monotonic queue approach. Maintain decreasing order in deque by storing indices. For each element, remove indices outside window from front, remove smaller elements from back (they can't be max), add current. Front has maximum index. Time O(n), space O(k)."

### Code:
```cpp
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq;  // Stores indices in decreasing order of values
    
    for(int i = 0; i < arr.size(); i++) {
        // Remove indices outside window
        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements from back
        // (they can't be max in current or future windows)
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add current index
        dq.push_back(i);
        
        // Add to result after first window
        if(i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}
```

### Dry Run:
```
arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

i=0, arr[0]=1:
  dq empty, add 0
  dq = [0]
  i < k-1, don't add to result

i=1, arr[1]=3:
  arr[dq.back()]=arr[0]=1 <= 3 → pop 0
  dq = [], add 1
  dq = [1]

i=2, arr[2]=-1:
  arr[dq.back()]=arr[1]=3 > -1 → don't pop
  dq = [1, 2]
  i >= k-1, add arr[dq.front()] = arr[1] = 3
  result = [3]

i=3, arr[3]=-3:
  arr[dq.back()]=arr[2]=-1 > -3 → don't pop
  dq = [1, 2, 3]
  result = [3, arr[1]] = [3, 3]

i=4, arr[4]=5:
  dq.front()=1 <= 4-3=1 → pop front
  dq = [2, 3]
  arr[2]=-1 <= 5 → pop
  arr[3]=-3 <= 5 → pop
  dq = [], add 4
  dq = [4]
  result = [3, 3, 5]

i=5, arr[5]=3:
  arr[4]=5 > 3 → don't pop
  dq = [4, 5]
  result = [3, 3, 5, 5]

i=6, arr[6]=6:
  arr[5]=3 <= 6 → pop
  arr[4]=5 <= 6 → pop
  dq = [], add 6
  dq = [6]
  result = [3, 3, 5, 5, 6]

i=7, arr[7]=7:
  arr[6]=6 <= 7 → pop
  dq = [], add 7
  dq = [7]
  result = [3, 3, 5, 5, 6, 7]

Output: [3, 3, 5, 5, 6, 7] ✅
```

### Time & Space:
- **Time:** O(n) - each element added/removed once
- **Space:** O(k) - deque size

### Company Frequency:
- **TCS:** 60%
- **Infosys:** 70%
- **Wipro:** 55%
- **Amazon/Microsoft:** 95% (product-based)

---

## 🧩 PROBLEM 2: FIRST NEGATIVE IN EVERY WINDOW OF SIZE K

### Problem Statement:
Find the first negative number in every window of size k. If no negative, return 0.

**Example:**
```
Input: arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output: [-1, -1, -7, -15, -15, 0]

Explanation:
  Window [12, -1, -7] → first negative = -1
  Window [-1, -7,  8] → first negative = -1
  Window [-7,  8,-15] → first negative = -7
  Window [8, -15, 30] → first negative = -15
  Window [-15, 30, 16] → first negative = -15
  Window [30, 16, 28] → first negative = 0
```

### Communication Script:
> "Sir, simple queue approach. Queue stores negative numbers. For each window, remove elements outside window from front, add current if negative, front is answer. Time O(n), space O(k)."

### Code:
```cpp
vector<int> firstNegative(vector<int>& arr, int k) {
    vector<int> result;
    queue<int> q;  // Stores indices of negative numbers
    
    for(int i = 0; i < arr.size(); i++) {
        // Add current if negative
        if(arr[i] < 0) {
            q.push(i);
        }
        
        // Remove indices outside window
        while(!q.empty() && q.front() <= i - k) {
            q.pop();
        }
        
        // Add to result after first window
        if(i >= k - 1) {
            if(q.empty()) {
                result.push_back(0);
            } else {
                result.push_back(arr[q.front()]);
            }
        }
    }
    
    return result;
}
```

### Dry Run:
```
arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3

i=0, arr[0]=12: not negative, q = []
i=1, arr[1]=-1: negative, q = [1]
i=2, arr[2]=-7: negative, q = [1,2], result = [arr[1]] = [-1]
i=3, arr[3]=8: not negative, q = [1,2], result = [-1, arr[1]] = [-1,-1]
i=4, arr[4]=-15: 
  negative, q = [1,2,4]
  q.front()=1 <= 4-3=1 → pop
  q = [2,4]
  result = [-1, -1, arr[2]] = [-1,-1,-7]
i=5, arr[5]=30:
  not negative, q = [2,4]
  q.front()=2 <= 5-3=2 → pop
  q = [4]
  result = [-1,-1,-7, arr[4]] = [-1,-1,-7,-15]
i=6, arr[6]=16:
  not negative, q = [4]
  q.front()=4 > 6-3=3 → don't pop
  result = [-1,-1,-7,-15, arr[4]] = [-1,-1,-7,-15,-15]
i=7, arr[7]=28:
  not negative, q = [4]
  q.front()=4 <= 7-3=4 → pop
  q = []
  result = [-1,-1,-7,-15,-15, 0]

Output: [-1, -1, -7, -15, -15, 0] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(k)

### Company Frequency:
- **TCS:** 75%
- **Infosys:** 70%
- **Wipro:** 65%

---

## 🧩 PROBLEM 3: SUM OF MINIMUM AND MAXIMUM IN WINDOW

### Problem Statement:
Find sum of minimum and maximum elements in all windows of size k.

**Example:**
```
Input: arr = [2, 5, -1, 7, -3, -1, -2], k = 4
Output: 18

Explanation:
  Window [2, 5, -1, 7]   → min=-1, max=7  → sum = 6
  Window [5, -1, 7, -3]  → min=-3, max=7  → sum = 4
  Window [-1, 7, -3, -1] → min=-3, max=7  → sum = 4
  Window [7, -3, -1, -2] → min=-3, max=7  → sum = 4
  Total = 6 + 4 + 4 + 4 = 18
```

### Communication Script:
> "Sir, two deques approach - one for minimum (increasing), one for maximum (decreasing). Similar to sliding window maximum but maintain both. Time O(n), space O(k)."

### Code:
```cpp
int sumMinMax(vector<int>& arr, int k) {
    deque<int> minDq, maxDq;  // Store indices
    int sum = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        // Remove indices outside window
        while(!minDq.empty() && minDq.front() <= i - k) {
            minDq.pop_front();
        }
        while(!maxDq.empty() && maxDq.front() <= i - k) {
            maxDq.pop_front();
        }
        
        // Maintain increasing deque for minimum
        while(!minDq.empty() && arr[minDq.back()] >= arr[i]) {
            minDq.pop_back();
        }
        
        // Maintain decreasing deque for maximum
        while(!maxDq.empty() && arr[maxDq.back()] <= arr[i]) {
            maxDq.pop_back();
        }
        
        minDq.push_back(i);
        maxDq.push_back(i);
        
        // Add to sum after first window
        if(i >= k - 1) {
            int minVal = arr[minDq.front()];
            int maxVal = arr[maxDq.front()];
            sum += minVal + maxVal;
        }
    }
    
    return sum;
}
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(k)

---

## 🧩 PROBLEM 4: ROTTEN ORANGES (BFS) ⭐⭐⭐

### Problem Statement (LeetCode 994):
In a grid, 0=empty, 1=fresh orange, 2=rotten orange. Every minute, rotten oranges rot adjacent fresh oranges. Find minimum time to rot all oranges, or -1 if impossible.

**Example:**
```
Input:
  2 1 1
  1 1 0
  0 1 1

Output: 4

Explanation:
  Time 0: 2 1 1      Time 1: 2 2 1      Time 2: 2 2 2
          1 1 0              2 1 0              2 2 0
          0 1 1              0 1 1              0 2 1

  Time 3: 2 2 2      Time 4: 2 2 2
          2 2 0              2 2 0
          0 2 1              0 2 2
```

### Communication Script:
> "Sir, multi-source BFS! Add all initial rotten oranges to queue with time 0. Process level by level, rot adjacent fresh oranges. Track time and fresh count. If fresh > 0 at end, return -1. Time O(rows×cols), space O(rows×cols)."

### Code:
```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    int time = 0;
    
    // Add all rotten oranges to queue
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            } else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    
    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // BFS
    while(!q.empty() && fresh > 0) {
        int size = q.size();
        
        for(int i = 0; i < size; i++) {
            auto [x, y] = q.front();
            q.pop();
            
            // Check all 4 directions
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                // Check bounds and if fresh
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols 
                   && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;  // Rot it
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        
        time++;
    }
    
    return fresh == 0 ? time : -1;
}
```

### Dry Run:
```
Input:
  2 1 1
  1 1 0
  0 1 1

Initial: q = [(0,0)], fresh = 6

Time 0 → 1:
  Process (0,0):
    Check (1,0): fresh, rot → grid[1][0]=2, q.push((1,0))
    Check (0,1): fresh, rot → grid[1][1]=2, q.push((0,1))
  q = [(1,0), (0,1)], fresh = 4, time = 1

Time 1 → 2:
  Process (1,0):
    Check (1,1): fresh, rot → grid[1][1]=2, q.push((1,1))
  Process (0,1):
    Check (0,2): fresh, rot → grid[0][2]=2, q.push((0,2))
  q = [(1,1), (0,2)], fresh = 2, time = 2

... continues until all fresh = 0

Final time = 4
```

### Time & Space:
- **Time:** O(rows × cols)
- **Space:** O(rows × cols)

### Company Frequency:
- **TCS:** 50%
- **Infosys:** 60%
- **Wipro:** 45%
- **Amazon/Google:** 90% (product-based)

---

## 🧩 PROBLEM 5: K CLOSEST POINTS TO ORIGIN (Priority Queue)

### Problem Statement (LeetCode 973):
Find K closest points to origin (0, 0). Distance = sqrt(x² + y²).

**Example:**
```
Input: points = [[1,3], [-2,2], [5,8], [0,1]], K = 2
Output: [[0,1], [-2,2]]

Explanation:
  Distance [1,3] = sqrt(10) ≈ 3.16
  Distance [-2,2] = sqrt(8) ≈ 2.83
  Distance [5,8] = sqrt(89) ≈ 9.43
  Distance [0,1] = sqrt(1) = 1
  
  Closest 2: [0,1] and [-2,2]
```

### Communication Script:
> "Sir, max heap approach with size K. For each point, calculate distance, add to heap. If heap size > K, remove maximum. At end, heap has K closest. Time O(n log k), space O(k)."

### Code:
```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // Max heap: {distance, index}
    priority_queue<pair<int, int>> maxHeap;
    
    for(int i = 0; i < points.size(); i++) {
        int dist = points[i][0] * points[i][0] + 
                   points[i][1] * points[i][1];
        
        maxHeap.push({dist, i});
        
        // Keep only K closest
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    // Extract result
    vector<vector<int>> result;
    while(!maxHeap.empty()) {
        int idx = maxHeap.top().second;
        maxHeap.pop();
        result.push_back(points[idx]);
    }
    
    return result;
}
```

### Time & Space:
- **Time:** O(n log k)
- **Space:** O(k)

### Company Frequency:
- **TCS:** 55%
- **Infosys:** 65%
- **Wipro:** 50%

---

## 🧩 PROBLEM 6: TOP K FREQUENT ELEMENTS ⭐⭐

### Problem Statement (LeetCode 347):
Find K most frequent elements in an array.

**Example:**
```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1, 2]

Explanation:
  1 appears 3 times
  2 appears 2 times
  3 appears 1 time
  
  Top 2 frequent: [1, 2]
```

### Communication Script:
> "Sir, frequency map + min heap approach. Build frequency map, use min heap of size K. For each element, add to heap with frequency. If size > K, remove minimum. Time O(n log k), space O(n)."

### Code:
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Build frequency map
    unordered_map<int, int> freq;
    for(int num : nums) {
        freq[num]++;
    }
    
    // Step 2: Min heap {frequency, value}
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> minHeap;
    
    for(auto& [num, count] : freq) {
        minHeap.push({count, num});
        
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Step 3: Extract result
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}
```

### Dry Run:
```
Input: [1,1,1,2,2,3], k = 2

Step 1: Frequency map
  freq = {1: 3, 2: 2, 3: 1}

Step 2: Process with min heap
  Process (1, 3):
    minHeap = [(3, 1)]
  
  Process (2, 2):
    minHeap = [(2, 2), (3, 1)]
  
  Process (3, 1):
    minHeap = [(1, 3), (2, 2), (3, 1)]
    size > k → pop (1, 3)
    minHeap = [(2, 2), (3, 1)]

Step 3: Extract
  result = [2, 1]

Output: [2, 1] (or [1, 2] - order doesn't matter)
```

### Time & Space:
- **Time:** O(n log k)
- **Space:** O(n) for frequency map

### Company Frequency:
- **TCS:** 60%
- **Infosys:** 70%
- **Wipro:** 55%
- **Amazon/Facebook:** 95% (product-based)

---

## 🧩 PROBLEM 7: K-TH LARGEST ELEMENT (Quick Select/Heap)

### Problem Statement (LeetCode 215):
Find the kth largest element in an unsorted array.

**Example:**
```
Input: [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Explanation:
  Sorted: [1, 2, 3, 4, 5, 6]
  2nd largest = 5
```

### Method 1: Min Heap (Simple)
### Communication Script:
> "Sir, min heap of size k. Add elements, maintain size k by removing minimum. At end, top is kth largest. Time O(n log k), space O(k)."

### Code:
```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int num : nums) {
        minHeap.push(num);
        
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}
```

### Method 2: Max Heap (Alternative)
```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxHeap(nums.begin(), nums.end());
    
    for(int i = 0; i < k - 1; i++) {
        maxHeap.pop();
    }
    
    return maxHeap.top();
}
```

### Time & Space:
- **Min Heap:** O(n log k), Space O(k)
- **Max Heap:** O(n + k log n), Space O(n)

---

## 🧩 PROBLEM 8: CONNECT ROPES WITH MINIMUM COST

### Problem Statement:
Connect n ropes with minimum cost. Cost of connecting two ropes = sum of their lengths.

**Example:**
```
Input: ropes = [4, 3, 2, 6]
Output: 29

Explanation:
  Connect 2 and 3 → cost = 5, ropes = [4, 5, 6]
  Connect 4 and 5 → cost = 9, ropes = [6, 9]
  Connect 6 and 9 → cost = 15, ropes = [15]
  Total cost = 5 + 9 + 15 = 29
```

### Communication Script:
> "Sir, greedy + min heap! Always connect two smallest ropes to minimize cost. Use min heap to get smallest efficiently. Time O(n log n), space O(n)."

### Code:
```cpp
int connectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // Add all ropes to heap
    for(int rope : ropes) {
        minHeap.push(rope);
    }
    
    int totalCost = 0;
    
    while(minHeap.size() > 1) {
        // Get two smallest
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        
        // Connect them
        int cost = first + second;
        totalCost += cost;
        
        // Add back to heap
        minHeap.push(cost);
    }
    
    return totalCost;
}
```

### Dry Run:
```
Input: [4, 3, 2, 6]

Initial heap: [2, 3, 4, 6]

Step 1:
  Pop 2, pop 3
  cost = 5, totalCost = 5
  Push 5
  heap = [4, 5, 6]

Step 2:
  Pop 4, pop 5
  cost = 9, totalCost = 14
  Push 9
  heap = [6, 9]

Step 3:
  Pop 6, pop 9
  cost = 15, totalCost = 29
  Push 15
  heap = [15]

Size = 1, stop
Total cost = 29 ✅
```

### Time & Space:
- **Time:** O(n log n)
- **Space:** O(n)

### Company Frequency:
- **TCS:** 65%
- **Infosys:** 70%
- **Wipro:** 60%

---

## 📊 PATTERN COMPARISON TABLE

| Pattern | Data Structure | Time | When to Use |
|---------|---------------|------|-------------|
| **Sliding Window Max** | Deque | O(n) | Window maximum/minimum |
| **First Negative** | Queue | O(n) | Window-based search |
| **Rotten Oranges** | Queue (BFS) | O(m×n) | Multi-source spread |
| **K Closest** | Max Heap | O(n log k) | K smallest/largest |
| **Top K Frequent** | Min Heap | O(n log k) | K most frequent |
| **Connect Ropes** | Min Heap | O(n log n) | Greedy merging |

---

## 🎯 PATTERN RECOGNITION GUIDE

### When you see:
- **"Sliding window" + "maximum/minimum"** → Deque (monotonic)
- **"Every window"** → Queue or Deque with window tracking
- **"Spread/propagate"** → BFS with queue
- **"K largest/smallest"** → Heap (size K)
- **"Top K frequent"** → Frequency map + Heap
- **"Minimum cost to connect"** → Min heap (greedy)

---

## 💡 COMPANY-WISE TOP PROBLEMS

### TCS (Focus: Basics + Applications)
1. First Negative in Window - 75%
2. Queue using Stack - 75%
3. Connect Ropes - 65%

### Infosys (Focus: Heap + BFS)
1. Sliding Window Maximum - 70%
2. Top K Frequent - 70%
3. Rotten Oranges - 60%

### Wipro (Focus: Balanced)
1. First Negative in Window - 65%
2. K Closest Points - 50%
3. Connect Ropes - 60%

---

## 🔥 QUICK TEMPLATES

### Sliding Window Maximum Template:
```cpp
deque<int> dq;  // Indices
for(int i = 0; i < n; i++) {
    // Remove outside window
    while(!dq.empty() && dq.front() <= i - k) 
        dq.pop_front();
    
    // Remove smaller from back
    while(!dq.empty() && arr[dq.back()] <= arr[i]) 
        dq.pop_back();
    
    dq.push_back(i);
    
    if(i >= k-1) 
        result.push_back(arr[dq.front()]);
}
```

### BFS Template:
```cpp
queue<Node> q;
q.push(start);
visited[start] = true;

while(!q.empty()) {
    Node curr = q.front();
    q.pop();
    
    // Process curr
    
    for(Node neighbor : curr.neighbors) {
        if(!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}
```

### K Largest/Smallest Template:
```cpp
// K largest → use min heap
priority_queue<int, vector<int>, greater<int>> minHeap;

for(int num : nums) {
    minHeap.push(num);
    if(minHeap.size() > k) 
        minHeap.pop();
}

return minHeap.top();
```

---

## 🎓 LEARNING PATH

**Day 1: Sliding Window (4 hours)**
- Sliding Window Maximum
- First Negative in Window
- Sum of Min/Max in Window

**Day 2: BFS Problems (4 hours)**
- Rotten Oranges
- Level Order Traversal
- Shortest Path

**Day 3: Heap Problems (4 hours)**
- K Closest Points
- Top K Frequent
- Kth Largest Element
- Connect Ropes

**Day 4: Practice (3 hours)**
- Mixed problems
- Company-specific prep

---

## 💪 INTERVIEW TIPS

1. **Identify pattern quickly:** Window → Deque, Spread → BFS, K elements → Heap
2. **Draw diagrams:** Show queue/deque states, BFS levels, heap structure
3. **Explain complexity:** Deque O(n), BFS O(V+E), Heap O(n log k)
4. **Handle edge cases:** Empty window, no path in BFS, k > n in heap

**Master these 8 patterns → 90% Queue problems covered!** 🚀

---

**You've now mastered Queue basics + patterns!** 🎉
