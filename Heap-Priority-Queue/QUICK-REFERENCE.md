# ⚡ HEAP & PRIORITY QUEUE - QUICK REFERENCE
## Last-Minute Revision | One-Page Cheat Sheet

---

## 🎯 GOLDEN RULE (MUST MEMORIZE!)

```
┌────────────────────────────────────────────┐
│  K LARGEST elements?                       │
│  → MIN HEAP of size K                      │
│  → Keep largest K, remove smallest (top)   │
│  → Top = Kth largest                       │
└────────────────────────────────────────────┘

┌────────────────────────────────────────────┐
│  K SMALLEST elements?                      │
│  → MAX HEAP of size K                      │
│  → Keep smallest K, remove largest (top)   │
│  → Top = Kth smallest                      │
└────────────────────────────────────────────┘
```

---

## 💻 C++ STL SYNTAX (COPY-PASTE READY)

### **1. Max Heap (Default):**
```cpp
#include <queue>
#include <vector>
using namespace std;

// Max heap
priority_queue<int> maxHeap;

maxHeap.push(10);           // O(log n)
int top = maxHeap.top();    // O(1) - largest
maxHeap.pop();              // O(log n)
bool empty = maxHeap.empty(); // O(1)
int size = maxHeap.size();  // O(1)
```

### **2. Min Heap (Most Used!):**
```cpp
// Min heap
priority_queue<int, vector<int>, greater<int>> minHeap;

minHeap.push(10);           // O(log n)
int top = minHeap.top();    // O(1) - smallest
minHeap.pop();              // O(log n)
```

### **3. Min Heap of Pairs:**
```cpp
// Min heap of pairs {priority, value}
priority_queue<pair<int,int>, 
               vector<pair<int,int>>, 
               greater<pair<int,int>>> minHeap;

minHeap.push({5, 100});
auto [priority, value] = minHeap.top();
```

### **4. Max Heap of Pairs:**
```cpp
// Max heap (default for pairs)
priority_queue<pair<int,int>> maxHeap;

maxHeap.push({5, 100});
auto [priority, value] = maxHeap.top();
```

---

## 🔥 TOP 6 MUST-KNOW TEMPLATES

### **Template 1: Kth Largest Element ⭐⭐⭐**
```cpp
int findKthLargest(vector<int>& nums, int k) {
    // MIN HEAP of size k for K LARGEST
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int num : nums) {
        minHeap.push(num);
        
        if(minHeap.size() > k) {
            minHeap.pop(); // Remove smallest
        }
    }
    
    return minHeap.top(); // Kth largest
}
```
**Key:** Min heap size k, top = Kth largest  
**Time:** O(n log k), **Space:** O(k)

---

### **Template 2: Kth Smallest Element ⭐⭐**
```cpp
int findKthSmallest(vector<int>& nums, int k) {
    // MAX HEAP of size k for K SMALLEST
    priority_queue<int> maxHeap;
    
    for(int num : nums) {
        maxHeap.push(num);
        
        if(maxHeap.size() > k) {
            maxHeap.pop(); // Remove largest
        }
    }
    
    return maxHeap.top(); // Kth smallest
}
```
**Key:** Max heap size k, top = Kth smallest  
**Time:** O(n log k), **Space:** O(k)

---

### **Template 3: Top K Frequent Elements ⭐⭐⭐**
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Frequency map
    unordered_map<int, int> freq;
    for(int num : nums) freq[num]++;
    
    // Step 2: Min heap of size k - {frequency, value}
    priority_queue<pair<int,int>, 
                   vector<pair<int,int>>, 
                   greater<pair<int,int>>> minHeap;
    
    for(auto& [num, count] : freq) {
        minHeap.push({count, num});
        
        if(minHeap.size() > k) {
            minHeap.pop(); // Remove least frequent
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
**Key:** Frequency map + min heap size k  
**Time:** O(n log k), **Space:** O(n)

---

### **Template 4: Find Median from Stream ⭐⭐⭐**
```cpp
class MedianFinder {
    priority_queue<int> maxHeap; // Smaller half (left)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Larger half (right)
    
public:
    void addNum(int num) {
        // Add to max heap (left)
        maxHeap.push(num);
        
        // Balance: move largest from left to right
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Re-balance if right is larger
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top(); // Odd count
        }
        return (maxHeap.top() + minHeap.top()) / 2.0; // Even count
    }
};
```
**Key:** Two heaps (max for left, min for right), balance sizes  
**Time:** O(log n) add, O(1) find, **Space:** O(n)

---

### **Template 5: Connect Ropes Minimum Cost ⭐⭐⭐**
```cpp
int connectRopes(vector<int>& ropes) {
    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int rope : ropes) {
        minHeap.push(rope);
    }
    
    int totalCost = 0;
    
    while(minHeap.size() > 1) {
        // Get two smallest
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        
        // Connect and add cost
        int cost = first + second;
        totalCost += cost;
        
        // Push back
        minHeap.push(cost);
    }
    
    return totalCost;
}
```
**Key:** Greedy - always connect two smallest  
**Time:** O(n log n), **Space:** O(n)

---

### **Template 6: Merge K Sorted Arrays ⭐⭐**
```cpp
struct Element {
    int value, arrayIndex, elementIndex;
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    
    // Add first element from each array
    for(int i = 0; i < arrays.size(); i++) {
        if(!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }
    
    vector<int> result;
    
    while(!minHeap.empty()) {
        Element curr = minHeap.top();
        minHeap.pop();
        
        result.push_back(curr.value);
        
        // Add next from same array
        int nextIdx = curr.elementIndex + 1;
        if(nextIdx < arrays[curr.arrayIndex].size()) {
            minHeap.push({
                arrays[curr.arrayIndex][nextIdx],
                curr.arrayIndex,
                nextIdx
            });
        }
    }
    
    return result;
}
```
**Key:** Min heap with tracking {value, arrayIdx, elemIdx}  
**Time:** O(nk log k), **Space:** O(k)

---

## 🎯 PATTERN DECISION TREE

```
HEAP PROBLEM IDENTIFICATION:

"Kth largest" or "K largest elements"?
    → MIN HEAP of size K
    → Remove smallest when size > k
    → Top = Kth largest
    → Time: O(n log k)

"Kth smallest" or "K smallest elements"?
    → MAX HEAP of size K
    → Remove largest when size > k
    → Top = Kth smallest
    → Time: O(n log k)

"Median" or "running median"?
    → TWO HEAPS (max + min)
    → Max heap for smaller half
    → Min heap for larger half
    → Balance sizes
    → Time: O(log n) add, O(1) find

"Top K frequent"?
    → FREQUENCY MAP + MIN HEAP size K
    → Count frequencies
    → Heap of {frequency, element}
    → Time: O(n log k)

"Reorganize" or "rearrange with no adjacent"?
    → FREQUENCY + MAX HEAP
    → Greedy: always use most frequent
    → Cooldown previous character
    → Time: O(n)

"Schedule" with cooldown?
    → FREQUENCY + HEAP + CYCLES
    → Process in cycles of size n+1
    → Time: O(n)

"Merge K sorted arrays/lists"?
    → MIN HEAP with tracking
    → Track {value, listIndex, elementIndex}
    → Time: O(nk log k)

"Minimum cost to merge/connect"?
    → GREEDY + MIN HEAP
    → Always merge two smallest
    → Accumulate cost
    → Time: O(n log n)
```

---

## 📊 COMPLEXITY TABLE

| Problem | Time | Space | Heap Type |
|---------|------|-------|-----------|
| Kth Largest | O(n log k) | O(k) | Min heap size k |
| Kth Smallest | O(n log k) | O(k) | Max heap size k |
| Top K Frequent | O(n log k) | O(n) | Freq map + min heap |
| Median Stream | O(log n) add | O(n) | Two heaps |
| Connect Ropes | O(n log n) | O(n) | Min heap greedy |
| Merge K Arrays | O(nk log k) | O(k) | Min heap tracking |
| K Closest Points | O(n log k) | O(k) | Max heap distances |
| Reorganize String | O(n) | O(1) | Freq + max heap |
| Task Scheduler | O(n) | O(1) | Freq + cycles |
| Sort K-Sorted | O(n log k) | O(k) | Min heap window |

---

## 💡 COMMUNICATION SCRIPTS

### **Kth Largest:**
> "Sir, this is a **Kth Largest Element** problem. I'll use a **min heap of size k**.
> 
> For each element, I add to heap and if size exceeds k, I remove the smallest (top). At the end, the top of min heap will be the **kth largest** because it's the smallest among the k largest elements.
> 
> **Time:** O(n log k), **Space:** O(k).
> 
> This is better than sorting which takes O(n log n)."

### **Kth Smallest:**
> "Sir, this is a **Kth Smallest Element** problem. I'll use a **max heap of size k**.
> 
> For each element, I add to heap and if size exceeds k, I remove the largest (top). At the end, the top of max heap will be the **kth smallest** because it's the largest among the k smallest elements.
> 
> **Time:** O(n log k), **Space:** O(k)."

### **Top K Frequent:**
> "Sir, this is a **Top K Frequent Elements** problem. I'll use a **two-step approach**.
> 
> **Step 1:** Build frequency map using unordered_map (O(n)).
> 
> **Step 2:** Use a **min heap of size k** with pairs {frequency, element}. When heap size exceeds k, I pop the element with minimum frequency. At the end, heap contains top k frequent elements.
> 
> **Time:** O(n log k), **Space:** O(n) for map + O(k) for heap."

### **Median from Stream:**
> "Sir, this is a **Find Median from Stream** problem. I'll use **two heaps** approach.
> 
> **Max heap** stores smaller half (left side), **min heap** stores larger half (right side). I maintain sizes such that max heap has equal or one more element than min heap.
> 
> When adding: First add to max heap, then move max heap's top to min heap, then rebalance if needed.
> 
> Median: If sizes equal, average of two tops. Otherwise, top of max heap.
> 
> **Time:** O(log n) for addNum, O(1) for findMedian."

### **Connect Ropes:**
> "Sir, this is a **Minimum Cost to Connect Ropes** problem. This is a **greedy algorithm** with **min heap**.
> 
> I should **always connect the two smallest ropes** to minimize cost. I use min heap to get smallest ropes efficiently. After connecting, I add the new rope back to heap. I repeat until one rope remains.
> 
> **Why greedy works?** Smaller ropes contribute to cost multiple times (they become part of larger ropes), so connect them first.
> 
> **Time:** O(n log n), **Space:** O(n)."

---

## 🏢 COMPANY TOP 3

### **TCS (Focus: Basics)**
1. ⭐⭐⭐ Connect Ropes (65%)
2. ⭐⭐⭐ Kth Largest (60%)
3. ⭐⭐ Top K Frequent (60%)

**Interview Tip:** TCS loves K problems and greedy. Explain golden rule clearly.

### **Infosys (Focus: All Patterns)**
1. ⭐⭐⭐ Connect Ropes (70%)
2. ⭐⭐⭐ Top K Frequent (70%)
3. ⭐⭐ K Closest Points (65%)
4. ⭐⭐ Kth Largest (65%)
5. ⭐⭐ Median from Stream (60%)

**Interview Tip:** Infosys tests depth. Know multiple approaches, optimize.

### **Wipro (Focus: Fundamentals)**
1. ⭐⭐⭐ Connect Ropes (60%)
2. ⭐⭐ Kth Largest (55%)
3. ⭐⭐ Top K Frequent (55%)

**Interview Tip:** Wipro values clarity. Explain why min/max heap.

---

## ⚠️ COMMON EDGE CASES

### **K Problems:**
```cpp
// ✅ Check if k valid
if(k > nums.size() || k <= 0) return -1;

// ✅ k = 1 (largest/smallest)
if(k == 1) // Special handling

// ✅ k = n (smallest/largest of all)
if(k == nums.size()) // Return appropriate element

// ✅ All elements same
nums = [5, 5, 5, 5], k = 2 → return 5
```

### **Heap Operations:**
```cpp
// ✅ Always check empty before top/pop
if(!pq.empty()) {
    int val = pq.top();
    pq.pop();
}

// ✅ Maintain heap size for K problems
if(minHeap.size() > k) {
    minHeap.pop();
}
```

### **Median:**
```cpp
// ✅ Single element
addNum(5) → median = 5

// ✅ Two elements
addNum(1), addNum(2) → median = 1.5

// ✅ Negative numbers
Works fine with any integers
```

### **Merge K Arrays:**
```cpp
// ✅ Empty array in input
Skip empty arrays when initializing heap

// ✅ Single array
if(arrays.size() == 1) return arrays[0];
```

---

## 🎯 INTERVIEW DAY CHECKLIST

### **30 Minutes Before:**
- [ ] Read this QUICK-REFERENCE.md
- [ ] Memorize golden rule
- [ ] Practice Kth Largest (5 min)
- [ ] Review C++ STL syntax
- [ ] Pattern decision tree
- [ ] Calm breathing

### **During Interview - 5 Steps:**

**1. Identify Pattern (30 sec):**
```
- "Kth largest/smallest" → Heap size k
- "Median" → Two heaps
- "Top K frequent" → Freq map + heap
- "Reorganize" → Greedy + heap
- "Merge K" → Min heap tracking
- "Minimum cost" → Greedy + min heap
```

**2. Choose Heap Type (20 sec):**
```
- K largest → MIN heap
- K smallest → MAX heap
- Median → MAX + MIN heaps
- Greedy → MIN heap (usually)
```

**3. Explain Approach (2 min):**
```
- "Sir, this is a [pattern] problem"
- "I'll use [heap type] because..."
- Mention time/space complexity
- Draw heap states if helpful
```

**4. Code (5-7 min):**
```
- Use C++ STL priority_queue
- Handle edge cases (empty, k > n)
- Clean, commented code
```

**5. Dry Run (2 min):**
```
- Walk through small example
- Show heap states
- Verify correctness
```

---

## 🌟 KEY REMINDERS

### **Golden Rule:**
```
K LARGEST → MIN HEAP (size k)
K SMALLEST → MAX HEAP (size k)
MEDIAN → TWO HEAPS (max + min)
```

### **C++ STL Quick Syntax:**
```cpp
// Max heap
priority_queue<int> maxHeap;

// Min heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Operations
pq.push(x);    // O(log n)
pq.top();      // O(1)
pq.pop();      // O(log n)
pq.size();     // O(1)
pq.empty();    // O(1)
```

### **Pattern Recognition:**
```
"Kth" → Heap size k
"Median" → Two heaps
"Frequent" → Freq map + heap
"Reorganize" → Greedy + heap
"Merge K" → Min heap tracking
"Minimum cost" → Greedy + min heap
```

### **Common Mistakes:**
```
❌ Max heap for K largest (wrong!)
✅ Min heap for K largest (correct!)

❌ Forgetting to check empty
✅ Always check pq.empty()

❌ Not maintaining heap size k
✅ Pop when size > k
```

---

## 🚀 FINAL TIPS

### **If you have 30 minutes:**
1. Kth Largest (10 min)
2. Top K Frequent (15 min)
3. Connect Ropes (5 min)

### **If you have 1 hour:**
Add:
4. Median from Stream (20 min)
5. Merge K Arrays (10 min)

### **If you have 2 hours:**
Practice all 6 templates!

---

## 💪 SUCCESS FORMULA

```
Heap Mastery = Golden Rule + Templates + Communication

Golden Rule:
    K LARGEST → MIN HEAP
    K SMALLEST → MAX HEAP
    MEDIAN → TWO HEAPS

Templates:
    6 core templates memorized
    Copy-paste ready
    Handle edge cases

Communication:
    "Sir, this is a [pattern] problem"
    "I'll use [heap] because..."
    Draw states
    Complexity analysis
```

---

## 🎯 YOU'RE READY!

**Coverage:**
- ✅ Binary Search
- ✅ Arrays
- ✅ Strings
- ✅ Linked Lists
- ✅ Stack
- ✅ Queue
- ✅ **Heap & Priority Queue (NEW!)**

## **95-98% PLACEMENT READY!** 🚀

---

**Remember:**
- **K Largest → Min Heap (size k)**
- **K Smallest → Max Heap (size k)**
- **Median → Two Heaps (max + min)**

**All the best, Satyam!** 🌟  
**Go crush that interview!** 💯

---

_Last-minute tip: Heap problems are pattern-based. Identify pattern → Use template → Code fast!_
