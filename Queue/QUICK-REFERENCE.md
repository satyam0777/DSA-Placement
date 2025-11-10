# ⚡ QUEUE - QUICK REFERENCE GUIDE
## Last-Minute Revision | One-Page Cheat Sheet

---

## 🎯 TOP 8 MUST-KNOW TEMPLATES

### **1. Implement Queue using Array**
```cpp
class Queue {
    int* arr;
    int front, rear, capacity;
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = rear = -1;
    }
    
    void enqueue(int x) {
        if(rear == capacity - 1) return; // Full
        if(front == -1) front = 0;
        arr[++rear] = x;
    }
    
    void dequeue() {
        if(front == -1 || front > rear) return; // Empty
        front++;
    }
    
    int getFront() {
        return (front == -1) ? -1 : arr[front];
    }
};
```
**Key:** front/rear pointers, check empty/full

---

### **2. Circular Queue ⭐⭐⭐**
```cpp
class CircularQueue {
    int* arr;
    int front, rear, capacity;
public:
    CircularQueue(int k) {
        capacity = k;
        arr = new int[capacity];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        // Check full: (rear+1)%capacity == front
        if((rear + 1) % capacity == front) return false;
        
        if(front == -1) front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1) return false;
        
        if(front == rear) {
            front = rear = -1; // Last element
        } else {
            front = (front + 1) % capacity;
        }
        return true;
    }
};
```
**Key:** Modulo `(rear+1)%capacity`, full when `(rear+1)%capacity == front`

---

### **3. Queue using Stack ⭐⭐⭐ (MUST!)**
```cpp
class QueueUsingStack {
    stack<int> s1, s2; // s1 for enqueue, s2 for dequeue
public:
    void enqueue(int x) {
        s1.push(x); // O(1)
    }
    
    int dequeue() {
        if(s2.empty()) {
            // Transfer from s1 to s2
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        if(s2.empty()) return -1; // Queue empty
        
        int front = s2.top();
        s2.pop();
        return front; // Amortized O(1)
    }
};
```
**Key:** s1 enqueue O(1), s2 dequeue amortized O(1), transfer when s2 empty

---

### **4. Sliding Window Maximum (Deque) ⭐⭐⭐**
```cpp
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq; // Stores indices in decreasing order
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        // Remove outside window
        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements from back
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result after first window
        if(i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}
```
**Key:** Deque stores indices, maintain decreasing order, remove outside/smaller

---

### **5. First Negative in Every Window ⭐⭐⭐**
```cpp
vector<int> firstNegativeWindow(vector<int>& arr, int k) {
    queue<int> q; // Stores indices of negative numbers
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        // Add negative to queue
        if(arr[i] < 0) q.push(i);
        
        // Remove outside window
        while(!q.empty() && q.front() <= i - k) {
            q.pop();
        }
        
        // Add result
        if(i >= k - 1) {
            if(!q.empty()) {
                result.push_back(arr[q.front()]);
            } else {
                result.push_back(0); // No negative
            }
        }
    }
    
    return result;
}
```
**Key:** Queue stores negative indices, remove outside window

---

### **6. First Non-Repeating Character (Stream) ⭐⭐⭐**
```cpp
string firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};
    string result = "";
    
    for(char ch : s) {
        // Update frequency
        freq[ch - 'a']++;
        q.push(ch);
        
        // Remove repeating from front
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        // First non-repeating or #
        if(!q.empty()) {
            result += q.front();
        } else {
            result += '#';
        }
    }
    
    return result;
}
```
**Key:** Queue + freq[26] array, remove freq>1 from front

---

### **7. Rotten Oranges (BFS) ⭐⭐⭐**
```cpp
int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int rows = grid.size(), cols = grid[0].size();
    int fresh = 0, time = 0;
    
    // Add all initial rotten oranges
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) q.push({i, j});
            if(grid[i][j] == 1) fresh++;
        }
    }
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // BFS
    while(!q.empty() && fresh > 0) {
        int size = q.size();
        
        for(int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();
            
            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols 
                   && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
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
**Key:** Multi-source BFS, queue all rotten, process level by level

---

### **8. Top K Frequent Elements (Heap) ⭐⭐⭐**
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;
    
    // Min heap of size k: {count, value}
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
                   greater<pair<int,int>>> minHeap;
    
    for(auto [num, count] : freq) {
        minHeap.push({count, num});
        if(minHeap.size() > k) {
            minHeap.pop(); // Remove smallest count
        }
    }
    
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    
    return result;
}
```
**Key:** Frequency map + min heap size k, pop when size > k

---

## 🎯 PATTERN DECISION TREE

```
QUEUE PROBLEM IDENTIFICATION:

"Sliding window" + "maximum/minimum"?
    → Deque (monotonic decreasing/increasing)
    → Template: Remove outside, remove smaller, add current
    → Time: O(n), Space: O(k)

"Every window of size k"?
    → Queue with window tracking
    → Template: Add to queue, remove outside window
    → Time: O(n), Space: O(k)

"Spread/propagate/level-wise"?
    → BFS with Queue
    → Template: Queue start nodes, process level by level
    → Time: O(V+E), Space: O(V)

"K largest/smallest/frequent/closest"?
    → Heap (Priority Queue)
    → K largest → Min heap size k
    → K smallest → Max heap size k
    → Time: O(n log k), Space: O(k)

"Minimum cost to merge/connect"?
    → Greedy + Min Heap
    → Template: Pop 2 smallest, merge, push back
    → Time: O(n log n)

"First non-repeating/unique in stream"?
    → Queue + Frequency Array
    → Template: Queue for order, freq for count
    → Time: O(n), Space: O(26)
```

---

## 📊 TIME COMPLEXITY TABLE

| Pattern | Time | Space | Example |
|---------|------|-------|---------|
| Basic Queue Operations | O(1) | O(1) | Enqueue, Dequeue, Front |
| Circular Queue | O(1) | O(n) | (rear+1)%capacity |
| Queue using Stack | O(1) amortized | O(n) | Two stacks |
| Stack using Queue | Push O(n), Pop O(1) | O(n) | Queue rotation |
| Reverse Queue | O(n) | O(n) | Stack/recursion |
| Generate Binary | O(n) | O(n) | Pattern generation |
| First Non-Repeating | O(n) | O(1) | Queue + freq[26] |
| Sliding Window (Deque) | O(n) | O(k) | Monotonic deque |
| First Negative Window | O(n) | O(k) | Queue indices |
| BFS (Grid) | O(rows×cols) | O(rows×cols) | Multi-source |
| Top K Frequent | O(n log k) | O(k) | Min heap size k |
| Kth Largest | O(n log k) | O(k) | Min heap |
| Connect Ropes | O(n log n) | O(n) | Min heap greedy |

---

## 💡 COMMUNICATION SCRIPTS

### **Queue using Stack:**
> "Sir, this is a Queue using Stack problem. I'll use **two stacks**: `s1` for enqueue and `s2` for dequeue. When enqueue, I push to `s1` which is **O(1)**. When dequeue, if `s2` is empty, I transfer all elements from `s1` to `s2`, reversing the order. This gives us **amortized O(1)** because each element is moved at most once. Time O(1) amortized, Space O(n)."

### **Circular Queue:**
> "Sir, this is a Circular Queue problem. I'll use **modulo arithmetic** `(rear+1) % capacity` to wrap around. The queue is **full** when `(rear+1) % capacity == front`. This allows us to **reuse space** after dequeue. All operations are **O(1)**. Space O(n)."

### **Sliding Window Maximum:**
> "Sir, this is a Sliding Window Maximum problem. I'll use a **deque** to maintain a **monotonic decreasing** order of indices. For each element, I first **remove indices outside the window** from the front, then **remove smaller elements** from the back, then add the current index. The front always has the maximum. Time **O(n)** because each element is added/removed once. Space O(k)."

### **First Negative Window:**
> "Sir, this is a First Negative in Window problem. I'll use a **queue** to store **indices of negative numbers**. For each window, I **remove indices outside the window** from the front, then check if queue is empty. If not empty, the front gives the first negative. Time **O(n)**, Space O(k)."

### **Rotten Oranges:**
> "Sir, this is a Rotten Oranges BFS problem. I'll use **multi-source BFS**. First, I add all **initial rotten oranges** to the queue and count fresh oranges. Then I process **level by level**, each level representing one minute. For each rotten orange, I check **4 directions** and rot adjacent fresh oranges. Time **O(rows × cols)**, Space O(rows × cols)."

### **Top K Frequent:**
> "Sir, this is a Top K Frequent Elements problem. I'll use a **frequency map** to count occurrences, then a **min heap of size k** to find top k. I maintain heap size k by **popping the smallest count** when size exceeds k. At the end, the heap contains top k frequent elements. Time **O(n log k)**, Space O(k)."

---

## 🏢 COMPANY TOP 3

### **TCS (Focus: Basics + Window)**
1. ⭐⭐⭐ Queue using Stack (75%)
2. ⭐⭐⭐ First Negative in Window (75%)
3. ⭐⭐ Implement Queue / Circular Queue (70%)

### **Infosys (Focus: Patterns + Heap)**
1. ⭐⭐⭐ Queue using Stack (80%)
2. ⭐⭐⭐ Circular Queue (75%)
3. ⭐⭐⭐ First Non-Repeating (75%)
4. ⭐⭐ Sliding Window Maximum (70%)
5. ⭐⭐ Top K Frequent (70%)

### **Wipro (Focus: Balanced)**
1. ⭐⭐⭐ Queue using Stack (70%)
2. ⭐⭐ Implement Queue (70%)
3. ⭐⭐ Circular Queue (65%)

---

## ⚠️ COMMON EDGE CASES

### **Queue Operations:**
```cpp
// ✅ Always check empty before front/dequeue
if(!q.empty()) {
    int front = q.front();
    q.pop();
}

// ✅ Check full before enqueue (array-based)
if(rear != capacity - 1) {
    enqueue(x);
}
```

### **Circular Queue:**
```cpp
// ✅ Full condition
if((rear + 1) % capacity == front) {
    // Queue is full
}

// ✅ Last element dequeue
if(front == rear) {
    front = rear = -1; // Reset
}
```

### **Sliding Window:**
```cpp
// ✅ Window size > array size
if(k > arr.size()) {
    // Handle: return max of entire array
}

// ✅ Remove indices outside window
while(!dq.empty() && dq.front() <= i - k) {
    dq.pop_front();
}
```

### **BFS:**
```cpp
// ✅ Disconnected graph
visited[start] = true; // Mark before adding to queue

// ✅ Boundary check
if(nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
    // Valid cell
}
```

### **Heap (K Problems):**
```cpp
// ✅ k > array size
k = min(k, (int)arr.size());

// ✅ Maintain heap size k
if(minHeap.size() > k) {
    minHeap.pop();
}
```

---

## 🎯 INTERVIEW DAY CHECKLIST

### **30 Minutes Before:**
- [ ] Read this QUICK-REFERENCE.md
- [ ] Practice queue using stack (2 stacks method)
- [ ] Practice first negative window (queue + window)
- [ ] Memorize deque sliding window template
- [ ] Review BFS template
- [ ] Calm breathing, stay confident

### **During Interview:**

**Step 1: Identify Pattern (30 seconds)**
```
- "Sliding window max/min" → Deque
- "Every window" → Queue
- "Spread/propagate" → BFS
- "K elements" → Heap
```

**Step 2: Explain Approach (2 minutes)**
```
1. "Sir, this is a [pattern] problem"
2. "I'll use [queue/deque/heap] because [reason]"
3. "Algorithm: [step by step]"
4. "Time O(n), Space O(k)"
5. Draw queue/deque/heap states
```

**Step 3: Code (5-7 minutes)**
```
- Use template from this sheet
- Handle edge cases
- Comment key steps
```

**Step 4: Dry Run (2 minutes)**
```
- Show queue/deque/heap states
- Verify correctness
```

---

## 🌟 C++ STL SYNTAX

### **Queue:**
```cpp
#include <queue>

queue<int> q;
q.push(10);              // Enqueue O(1)
q.pop();                 // Dequeue O(1)
int front = q.front();   // Front element O(1)
int back = q.back();     // Back element O(1)
bool empty = q.empty();  // Check empty O(1)
int size = q.size();     // Size O(1)
```

### **Deque (Double-Ended Queue):**
```cpp
#include <deque>

deque<int> dq;
dq.push_back(10);        // Add to back O(1)
dq.push_front(20);       // Add to front O(1)
dq.pop_back();           // Remove from back O(1)
dq.pop_front();          // Remove from front O(1)
int front = dq.front();  // Front element O(1)
int back = dq.back();    // Back element O(1)
bool empty = dq.empty(); // Check empty O(1)
```

### **Priority Queue (Heap):**
```cpp
#include <queue>

// Max heap (default)
priority_queue<int> maxHeap;
maxHeap.push(10);         // O(log n)
int max = maxHeap.top();  // O(1)
maxHeap.pop();            // O(log n)

// Min heap
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);         // O(log n)
int min = minHeap.top();  // O(1)
minHeap.pop();            // O(log n)

// Custom comparator (e.g., pairs)
priority_queue<pair<int,int>, vector<pair<int,int>>, 
               greater<pair<int,int>>> pq;
```

---

## 🔥 PATTERN TEMPLATES (COPY-PASTE READY)

### **Deque Sliding Window Template:**
```cpp
vector<int> slidingWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    
    for(int i = 0; i < arr.size(); i++) {
        // Remove outside window
        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller/larger based on max/min
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}
```

### **BFS Template:**
```cpp
void bfs(int start) {
    queue<int> q;
    vector<bool> visited(n, false);
    
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        // Process current node
        
        for(int neighbor : adj[curr]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

### **K Largest Template (Min Heap):**
```cpp
vector<int> kLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int num : arr) {
        minHeap.push(num);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return result;
}
```

---

## 💪 FINAL REMINDERS

### **Pattern Recognition:**
```
Window + Max/Min? → Deque
Every Window? → Queue
Spread? → BFS
K elements? → Heap
Merge/Connect? → Min Heap
Non-repeating? → Queue + Freq
```

### **Edge Cases:**
```
✅ Empty queue check
✅ Full queue check (array-based)
✅ Window size > array size
✅ k > array size
✅ BFS visited tracking
✅ Boundary checks (grid)
```

### **Communication:**
```
1. Pattern name
2. Why this approach
3. Step by step
4. Time & Space
5. Draw states
6. Handle edge cases
```

---

## 🎯 MUST PRACTICE BEFORE INTERVIEW

**If you have 30 minutes:**
1. Queue using Stack (Two stacks method)
2. First Negative in Window (Queue + window)
3. Sliding Window Maximum (Deque)

**If you have 1 hour:**
Add:
4. Circular Queue (Modulo)
5. First Non-Repeating (Queue + freq)
6. Top K Frequent (Heap)

**If you have 2 hours:**
Add all 8 templates above!

---

## 🌟 SUCCESS FORMULA

```
Queue Mastery = Pattern Recognition + Template + Communication

Pattern Recognition:
    - Identify in 30 seconds
    - Keywords: window, spread, K, merge

Template:
    - 8 core templates memorized
    - Copy-paste ready
    - Handle edge cases

Communication:
    - "Sir, this is a [pattern] problem"
    - Explain step by step
    - Draw states
    - Complexity analysis
```

---

## 🚀 YOU'RE READY!

**Coverage:**
- ✅ Binary Search
- ✅ Arrays
- ✅ Strings
- ✅ Linked Lists
- ✅ Stack
- ✅ **Queue (NEW!)**

## **92-95% PLACEMENT READY!** 🎯

---

**Remember:**
- Queue = FIFO (First In First Out)
- Deque = Both ends access
- Heap = Priority selection
- BFS = Level-wise processing

**All the best, Satyam!** 🌟  
**Go crush that interview!** 💯

---

_Last-minute tip: Stay calm, identify pattern, use template, communicate clearly!_
