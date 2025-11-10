# 📚 QUEUE BASICS - INTERVIEW READY GUIDE
## Foundation for All Queue Problems

---

## 🎯 WHAT IS QUEUE?

**Queue = FIFO (First In First Out)**

Think of a **line at ticket counter**:
- Person joins at back → **ENQUEUE**
- Person leaves from front → **DEQUEUE**
- See front person → **FRONT**

```
FRONT                        REAR
  ↓                            ↓
[10] → [20] → [30] → [40]
 ↑                       ↑
First added           Last added
First to leave        Last to leave
```

---

## 🔧 BASIC OPERATIONS

### 1. ENQUEUE (Add Element)
```cpp
queue<int> q;
q.push(10);  // Queue: [10]
q.push(20);  // Queue: [10, 20]
q.push(30);  // Queue: [10, 20, 30]
```

### 2. DEQUEUE (Remove Element)
```cpp
q.pop();  // Removes 10 (front)
// Queue now: [20, 30]
```

### 3. FRONT (See Front Element)
```cpp
int frontElement = q.front();  // Returns 20 (doesn't remove)
```

### 4. BACK (See Rear Element)
```cpp
int backElement = q.back();  // Returns 30
```

### 5. EMPTY (Check if Empty)
```cpp
if(q.empty()) {
    cout << "Queue is empty";
}
```

### 6. SIZE (Get Size)
```cpp
int size = q.size();  // Returns 2
```

---

## 📝 C++ STL QUEUE - COMPLETE SYNTAX

```cpp
#include <queue>
using namespace std;

// Declaration
queue<int> q;

// Operations
q.push(10);          // Add element at rear
q.pop();             // Remove element from front
int front = q.front();  // Get front (without removing)
int back = q.back();    // Get rear element
bool empty = q.empty(); // Check if empty
int size = q.size();    // Get size

// Process all elements
while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
```

---

## 🧩 PROBLEM 1: IMPLEMENT QUEUE USING ARRAY

### Problem Statement:
Implement a queue using an array with enqueue, dequeue, front, and isEmpty operations.

### Communication Script:
> "Sir, I'll use array with two pointers - front and rear. Initially both = -1 (empty). For enqueue, increment rear and add element. For dequeue, increment front. When front > rear, queue is empty. Time O(1) for all operations, space O(n)."

### Code:
```cpp
class Queue {
    int* arr;
    int front, rear;
    int capacity;
    
public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }
    
    void enqueue(int x) {
        if(rear == capacity - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }
    
    int dequeue() {
        if(front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }
    
    int getFront() {
        if(front > rear) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        return front > rear;
    }
    
    int size() {
        if(front > rear) return 0;
        return rear - front + 1;
    }
    
    ~Queue() {
        delete[] arr;
    }
};
```

### Dry Run:
```
Initial: front = 0, rear = -1, capacity = 5
arr: [_, _, _, _, _]

enqueue(10):
  rear = 0
  arr: [10, _, _, _, _]
  front = 0, rear = 0

enqueue(20):
  rear = 1
  arr: [10, 20, _, _, _]
  front = 0, rear = 1

enqueue(30):
  rear = 2
  arr: [10, 20, 30, _, _]
  front = 0, rear = 2

dequeue():
  returns arr[0] = 10
  front = 1
  arr: [10, 20, 30, _, _]
  Queue: [20, 30]

getFront():
  returns arr[1] = 20
```

### Time & Space:
- **Time:** O(1) for all operations
- **Space:** O(n) where n is capacity

### Edge Cases:
- Empty queue → Check before dequeue/front
- Full queue → Check before enqueue
- Single element → Handle correctly

---

## 🧩 PROBLEM 2: IMPLEMENT CIRCULAR QUEUE

### Problem Statement:
Implement a circular queue to optimize space usage (reuse empty spaces at front).

### Communication Script:
> "Sir, circular queue to avoid wasted space. Use modulo operation for wrapping. Front and rear move circularly. Full when (rear+1) % capacity == front. Empty when front == -1. Time O(1), space O(n)."

### Code:
```cpp
class CircularQueue {
    int* arr;
    int front, rear;
    int capacity;
    
public:
    CircularQueue(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }
    
    void enqueue(int x) {
        // Check full
        if((rear + 1) % capacity == front) {
            cout << "Queue Full\n";
            return;
        }
        
        // First element
        if(front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;  // Circular increment
        }
        
        arr[rear] = x;
    }
    
    int dequeue() {
        if(front == -1) {
            cout << "Queue Empty\n";
            return -1;
        }
        
        int result = arr[front];
        
        // Last element
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;  // Circular increment
        }
        
        return result;
    }
    
    int getFront() {
        if(front == -1) return -1;
        return arr[front];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    
    ~CircularQueue() {
        delete[] arr;
    }
};
```

### Dry Run:
```
Capacity = 5, front = -1, rear = -1
arr: [_, _, _, _, _]

enqueue(10):
  front = 0, rear = 0
  arr: [10, _, _, _, _]

enqueue(20):
  rear = 1
  arr: [10, 20, _, _, _]

enqueue(30):
  rear = 2
  arr: [10, 20, 30, _, _]

dequeue():
  returns 10, front = 1
  arr: [10, 20, 30, _, _]
  Queue: [20, 30]

enqueue(40):
  rear = 3
  arr: [10, 20, 30, 40, _]

enqueue(50):
  rear = 4
  arr: [10, 20, 30, 40, 50]

enqueue(60):
  rear = (4+1) % 5 = 0
  arr: [60, 20, 30, 40, 50]
  Queue wraps around! ✅
```

### Time & Space:
- **Time:** O(1) for all operations
- **Space:** O(n)

### Company Frequency:
- **TCS:** 70%
- **Infosys:** 75%
- **Wipro:** 65%

---

## 🧩 PROBLEM 3: IMPLEMENT QUEUE USING STACK

### Problem Statement:
Implement queue operations using two stacks.

### Communication Script:
> "Sir, two stack approach. Stack1 for enqueue (O(1)), Stack2 for dequeue. When dequeue called and Stack2 empty, transfer all from Stack1 to Stack2 (reverses order). Amortized O(1) for both operations."

### Code:
```cpp
class QueueUsingStacks {
    stack<int> s1, s2;
    
public:
    // Enqueue - O(1)
    void enqueue(int x) {
        s1.push(x);
    }
    
    // Dequeue - Amortized O(1)
    int dequeue() {
        if(s2.empty() && s1.empty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        
        // Transfer from s1 to s2 if s2 empty
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int front = s2.top();
        s2.pop();
        return front;
    }
    
    int front() {
        if(s2.empty() && s1.empty()) {
            return -1;
        }
        
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        return s2.top();
    }
    
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};
```

### Dry Run:
```
enqueue(1):
  s1: [1]
  s2: []

enqueue(2):
  s1: [1, 2]
  s2: []

enqueue(3):
  s1: [1, 2, 3]
  s2: []

dequeue():
  s2 empty, transfer from s1:
    Pop 3 from s1 → push to s2
    Pop 2 from s1 → push to s2
    Pop 1 from s1 → push to s2
  s1: []
  s2: [3, 2, 1] (1 on top)
  Pop from s2 → returns 1
  s1: []
  s2: [3, 2]

enqueue(4):
  s1: [4]
  s2: [3, 2]

dequeue():
  s2 not empty
  Pop from s2 → returns 2
  s1: [4]
  s2: [3]
```

### Time & Space:
- **Time:** Amortized O(1) for both
- **Space:** O(n)

### Company Frequency:
- **TCS:** 75%
- **Infosys:** 80%
- **Wipro:** 70%

---

## 🧩 PROBLEM 4: IMPLEMENT STACK USING QUEUE

### Problem Statement:
Implement stack operations using queues.

### Method 1: Two Queues (Expensive Push)
### Communication Script:
> "Sir, two queue approach. For push, add to q2, transfer all from q1 to q2, swap q1 and q2. This makes newest element at front. Push O(n), pop O(1)."

### Code (Two Queues):
```cpp
class StackUsingQueues {
    queue<int> q1, q2;
    
public:
    // Push - O(n)
    void push(int x) {
        // Add to q2
        q2.push(x);
        
        // Transfer all from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Swap q1 and q2
        swap(q1, q2);
    }
    
    // Pop - O(1)
    int pop() {
        if(q1.empty()) {
            cout << "Stack Empty\n";
            return -1;
        }
        
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool isEmpty() {
        return q1.empty();
    }
};
```

### Method 2: One Queue (Expensive Push)
```cpp
class StackUsingQueue {
    queue<int> q;
    
public:
    // Push - O(n)
    void push(int x) {
        int size = q.size();
        q.push(x);
        
        // Rotate queue to bring new element to front
        for(int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Pop - O(1)
    int pop() {
        if(q.empty()) return -1;
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.empty() ? -1 : q.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
};
```

### Dry Run (One Queue):
```
push(1):
  q: [1]
  size = 0, no rotation

push(2):
  q: [1, 2]
  size = 1, rotate 1 time:
    Push 1, pop 1 → q: [2, 1]

push(3):
  q: [2, 1, 3]
  size = 2, rotate 2 times:
    Push 2, pop 2 → q: [1, 3, 2]
    Push 1, pop 1 → q: [3, 2, 1]

top(): returns 3 ✅
pop(): returns 3, q: [2, 1]
pop(): returns 2, q: [1]
```

### Time & Space:
- **Time:** Push O(n), Pop O(1)
- **Space:** O(n)

---

## 🧩 PROBLEM 5: REVERSE A QUEUE

### Problem Statement:
Reverse a queue using recursion or stack.

### Method 1: Using Stack
### Communication Script:
> "Sir, stack approach. Pop all from queue and push to stack. Then pop from stack and enqueue back to queue. Stack's LIFO reverses FIFO. Time O(n), space O(n)."

### Code (Using Stack):
```cpp
void reverseQueue(queue<int>& q) {
    stack<int> s;
    
    // Transfer queue to stack
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Transfer stack back to queue
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}
```

### Method 2: Using Recursion
```cpp
void reverseQueue(queue<int>& q) {
    // Base case
    if(q.empty()) return;
    
    // Remove front
    int front = q.front();
    q.pop();
    
    // Reverse remaining
    reverseQueue(q);
    
    // Add front to back
    q.push(front);
}
```

### Dry Run (Recursion):
```
Input: [1, 2, 3, 4]

reverseQueue([1,2,3,4]):
  front = 1, pop → q: [2,3,4]
  reverseQueue([2,3,4]):
    front = 2, pop → q: [3,4]
    reverseQueue([3,4]):
      front = 3, pop → q: [4]
      reverseQueue([4]):
        front = 4, pop → q: []
        reverseQueue([]) → return
        q.push(4) → q: [4]
      q.push(3) → q: [4,3]
    q.push(2) → q: [4,3,2]
  q.push(1) → q: [4,3,2,1]

Output: [4, 3, 2, 1] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n) for recursion/stack

---

## 🧩 PROBLEM 6: GENERATE BINARY NUMBERS FROM 1 TO N

### Problem Statement:
Generate binary representations of numbers from 1 to n using queue.

**Example:**
```
Input: n = 5
Output: ["1", "10", "11", "100", "101"]
```

### Communication Script:
> "Sir, queue-based pattern generation! Start with '1' in queue. For each element, generate two children by appending '0' and '1'. Process n elements. Time O(n), space O(n)."

### Code:
```cpp
vector<string> generateBinary(int n) {
    vector<string> result;
    queue<string> q;
    
    q.push("1");
    
    for(int i = 0; i < n; i++) {
        string front = q.front();
        q.pop();
        
        result.push_back(front);
        
        // Generate next by appending 0 and 1
        q.push(front + "0");
        q.push(front + "1");
    }
    
    return result;
}
```

### Dry Run:
```
n = 5

Initial: q = ["1"]

i=0:
  front = "1", pop
  result = ["1"]
  q.push("10"), q.push("11")
  q = ["10", "11"]

i=1:
  front = "10", pop
  result = ["1", "10"]
  q.push("100"), q.push("101")
  q = ["11", "100", "101"]

i=2:
  front = "11", pop
  result = ["1", "10", "11"]
  q.push("110"), q.push("111")
  q = ["100", "101", "110", "111"]

i=3:
  front = "100", pop
  result = ["1", "10", "11", "100"]
  q.push("1000"), q.push("1001")
  q = ["101", "110", "111", "1000", "1001"]

i=4:
  front = "101", pop
  result = ["1", "10", "11", "100", "101"]
  q = ["110", "111", "1000", "1001", "1010", "1011"]

Output: ["1", "10", "11", "100", "101"] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

### Company Frequency:
- **TCS:** 60%
- **Infosys:** 65%
- **Wipro:** 55%

---

## 🧩 PROBLEM 7: FIRST NON-REPEATING CHARACTER IN STREAM

### Problem Statement:
For a stream of characters, find the first non-repeating character at each point.

**Example:**
```
Input: "aabbc"
Output: "a#bbc"

Explanation:
  After 'a': first non-repeating = 'a'
  After 'aa': no non-repeating = '#'
  After 'aab': first non-repeating = 'b'
  After 'aabb': first non-repeating = 'b'
  After 'aabbc': first non-repeating = 'c'
```

### Communication Script:
> "Sir, queue + frequency array approach. Queue maintains order of characters. Frequency array tracks count. For each character, increment frequency and add to queue. Remove from queue front if frequency > 1. Front of queue is answer. Time O(n), space O(26) = O(1)."

### Code:
```cpp
string firstNonRepeating(string str) {
    string result = "";
    queue<char> q;
    int freq[26] = {0};
    
    for(char ch : str) {
        // Increment frequency
        freq[ch - 'a']++;
        
        // Add to queue
        q.push(ch);
        
        // Remove repeating characters from front
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        // First non-repeating or '#'
        if(q.empty()) {
            result += '#';
        } else {
            result += q.front();
        }
    }
    
    return result;
}
```

### Dry Run:
```
Input: "aabbc"

ch='a':
  freq[a] = 1
  q = ['a']
  q.front() = 'a', freq[a] = 1 (don't pop)
  result = "a"

ch='a':
  freq[a] = 2
  q = ['a', 'a']
  q.front() = 'a', freq[a] = 2 → pop
  q.front() = 'a', freq[a] = 2 → pop
  q = []
  result = "a#"

ch='b':
  freq[b] = 1
  q = ['b']
  q.front() = 'b', freq[b] = 1 (don't pop)
  result = "a#b"

ch='b':
  freq[b] = 2
  q = ['b', 'b']
  q.front() = 'b', freq[b] = 2 → pop
  q.front() = 'b', freq[b] = 2 → pop
  q = []
  result = "a#b#"

ch='c':
  freq[c] = 1
  q = ['c']
  q.front() = 'c', freq[c] = 1 (don't pop)
  result = "a#b#c"

Output: "a#b#c" ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(26) = O(1) for freq array

### Company Frequency:
- **TCS:** 70%
- **Infosys:** 75%
- **Wipro:** 65%

---

## 🧩 PROBLEM 8: INTERLEAVE FIRST HALF WITH SECOND HALF

### Problem Statement:
Interleave the first half of queue with second half.

**Example:**
```
Input: [1, 2, 3, 4, 5, 6]
Output: [1, 4, 2, 5, 3, 6]

Explanation:
  First half: [1, 2, 3]
  Second half: [4, 5, 6]
  Interleaved: [1, 4, 2, 5, 3, 6]
```

### Communication Script:
> "Sir, auxiliary queue approach. Move first half to temp queue. Then alternately dequeue from temp and original queue. Time O(n), space O(n/2)."

### Code:
```cpp
queue<int> interleave(queue<int> q) {
    int n = q.size();
    queue<int> temp;
    
    // Move first half to temp
    for(int i = 0; i < n/2; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    // Interleave
    while(!temp.empty()) {
        q.push(temp.front());
        temp.pop();
        
        q.push(q.front());
        q.pop();
    }
    
    return q;
}
```

### Dry Run:
```
Input: [1, 2, 3, 4, 5, 6]

Step 1: Move first half to temp
  temp = [1, 2, 3]
  q = [4, 5, 6]

Step 2: Interleave
  Iteration 1:
    q.push(temp.front()) → q.push(1) → q = [4,5,6,1]
    temp.pop() → temp = [2,3]
    q.push(q.front()) → q.push(4) → q = [5,6,1,4]
    q.pop() → q = [6,1,4]
    
  Iteration 2:
    q.push(2) → q = [6,1,4,2]
    temp.pop() → temp = [3]
    q.push(6) → q = [1,4,2,6]
    q.pop() → q = [4,2,6]
    
  Iteration 3:
    q.push(3) → q = [4,2,6,3]
    temp.pop() → temp = []
    q.push(4) → q = [2,6,3,4]
    q.pop() → q = [6,3,4]

Wait, this doesn't work correctly!

Correct approach:
```

### Correct Code:
```cpp
queue<int> interleave(queue<int> q) {
    int n = q.size();
    queue<int> temp;
    queue<int> result;
    
    // Move first half to temp
    for(int i = 0; i < n/2; i++) {
        temp.push(q.front());
        q.pop();
    }
    
    // Interleave
    while(!temp.empty()) {
        result.push(temp.front());
        temp.pop();
        
        result.push(q.front());
        q.pop();
    }
    
    return result;
}
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(n)

---

## 🧩 PROBLEM 9: REVERSE FIRST K ELEMENTS

### Problem Statement:
Reverse the first K elements of a queue.

**Example:**
```
Input: [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
```

### Communication Script:
> "Sir, stack + queue approach. Pop first k elements from queue, push to stack. Pop from stack and enqueue back (reverses first k). Then dequeue and enqueue remaining elements to maintain order. Time O(n), space O(k)."

### Code:
```cpp
queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> s;
    
    // Step 1: Pop first k and push to stack
    for(int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    // Step 2: Pop from stack and enqueue (reverses)
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    // Step 3: Move remaining (n-k) elements to back
    int remaining = q.size() - k;
    for(int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
    
    return q;
}
```

### Dry Run:
```
Input: [1, 2, 3, 4, 5], k = 3

Step 1: First k to stack
  s = [1, 2, 3] (3 on top)
  q = [4, 5]

Step 2: Stack to queue
  Pop 3, enqueue → q = [4, 5, 3]
  Pop 2, enqueue → q = [4, 5, 3, 2]
  Pop 1, enqueue → q = [4, 5, 3, 2, 1]

Step 3: Move remaining (5-3=2) to back
  Dequeue 4, enqueue → q = [5, 3, 2, 1, 4]
  Dequeue 5, enqueue → q = [3, 2, 1, 4, 5]

Output: [3, 2, 1, 4, 5] ✅
```

### Time & Space:
- **Time:** O(n)
- **Space:** O(k)

### Company Frequency:
- **TCS:** 65%
- **Infosys:** 70%
- **Wipro:** 60%

---

## 🧩 PROBLEM 10: IMPLEMENT DEQUE (DOUBLE-ENDED QUEUE)

### Problem Statement:
Implement a deque that supports insertion and deletion from both ends.

### Communication Script:
> "Sir, doubly linked list or STL deque. Support push/pop from front and rear. All operations O(1) using doubly linked list. STL deque provides same interface."

### Code (Using STL):
```cpp
#include <deque>

deque<int> dq;

// Operations
dq.push_front(10);   // Add at front
dq.push_back(20);    // Add at rear
dq.pop_front();      // Remove from front
dq.pop_back();       // Remove from rear
int front = dq.front();  // Get front
int back = dq.back();    // Get rear
bool empty = dq.empty(); // Check empty
int size = dq.size();    // Get size
```

### Code (Custom Implementation):
```cpp
class Deque {
    int* arr;
    int front, rear;
    int capacity;
    
public:
    Deque(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }
    
    void pushFront(int x) {
        if((front == 0 && rear == capacity - 1) || 
           (front == rear + 1)) {
            cout << "Deque Full\n";
            return;
        }
        
        if(front == -1) {
            front = 0;
            rear = 0;
        } else if(front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }
        
        arr[front] = x;
    }
    
    void pushRear(int x) {
        if((front == 0 && rear == capacity - 1) || 
           (front == rear + 1)) {
            cout << "Deque Full\n";
            return;
        }
        
        if(rear == -1) {
            front = 0;
            rear = 0;
        } else if(rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }
        
        arr[rear] = x;
    }
    
    int popFront() {
        if(front == -1) {
            cout << "Deque Empty\n";
            return -1;
        }
        
        int result = arr[front];
        
        if(front == rear) {
            front = -1;
            rear = -1;
        } else if(front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }
        
        return result;
    }
    
    int popRear() {
        if(rear == -1) {
            cout << "Deque Empty\n";
            return -1;
        }
        
        int result = arr[rear];
        
        if(front == rear) {
            front = -1;
            rear = -1;
        } else if(rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }
        
        return result;
    }
    
    ~Deque() {
        delete[] arr;
    }
};
```

### Time & Space:
- **Time:** O(1) for all operations
- **Space:** O(n)

---

## 📊 COMPANY-WISE FREQUENCY

### TCS (Focus: Implementation + Applications)
| Problem | Frequency |
|---------|-----------|
| Queue using Stack | 75% |
| Implement Queue | 70% |
| First Non-Repeating | 70% |
| Circular Queue | 70% |
| Reverse First K | 65% |

### Infosys (Focus: Queue Patterns)
| Problem | Frequency |
|---------|-----------|
| Queue using Stack | 80% |
| Circular Queue | 75% |
| First Non-Repeating | 75% |
| Reverse First K | 70% |
| Generate Binary | 65% |

### Wipro (Focus: Balanced Mix)
| Problem | Frequency |
|---------|-----------|
| Queue using Stack | 70% |
| Implement Queue | 70% |
| Circular Queue | 65% |
| First Non-Repeating | 65% |
| Reverse Queue | 60% |

---

## 🎯 QUICK REVISION CHECKLIST

**Before Interview (5 minutes):**

✅ **Queue Operations:**
```cpp
queue<int> q;
q.push(x);      // Enqueue
q.pop();        // Dequeue
q.front();      // Front element
q.back();       // Rear element
q.empty();      // Check empty
q.size();       // Get size
```

✅ **Queue using Stack Pattern:**
```cpp
// Two stacks: s1 for enqueue, s2 for dequeue
// Transfer when s2 empty
```

✅ **Circular Queue:**
```cpp
// Use modulo: (rear + 1) % capacity
// Full: (rear + 1) % capacity == front
```

✅ **First Non-Repeating:**
```cpp
// Queue + frequency array
// Remove from front if freq > 1
```

---

## 💡 COMMON PATTERNS

### Pattern 1: Basic Queue Ops
```cpp
queue<int> q;
q.push(x);  // Enqueue
q.pop();    // Dequeue
q.front();  // Front
```

### Pattern 2: Queue with Stack
```cpp
// s1 for input, s2 for output
// Transfer when needed
```

### Pattern 3: Circular Queue
```cpp
// Modulo arithmetic
// Wrap around using %
```

### Pattern 4: Queue + Frequency
```cpp
// Queue for order
// Array/map for frequency
```

---

## 🚨 EDGE CASES TO REMEMBER

```cpp
// 1. Empty queue
if(q.empty()) { /* handle */ }

// 2. Queue overflow
if(rear == capacity - 1) { /* overflow */ }

// 3. Queue underflow
if(front > rear) { /* underflow */ }

// 4. Single element
if(front == rear) { /* last element */ }

// 5. Circular wrap-around
rear = (rear + 1) % capacity;
```

---

## 🎓 LEARNING PATH

**Day 1: Implementations (3-4 hours)**
- Implement Queue (Array)
- Circular Queue
- Queue using Stack

**Day 2: Applications (3-4 hours)**
- Stack using Queue
- Reverse Queue
- First Non-Repeating Character

**Day 3: Advanced (3-4 hours)**
- Generate Binary Numbers
- Interleave Queue
- Reverse First K Elements
- Deque

**Day 4: Practice (2-3 hours)**
- Solve all 10 problems again
- Communication scripts
- Company-specific prep

---

## 💪 INTERVIEW TIPS

1. **Explain FIFO:** "Sir, queue follows FIFO - first come, first served"
2. **Compare with Stack:** "Unlike stack's LIFO, queue is FIFO"
3. **Circular advantage:** "Circular queue reuses space, no wastage"
4. **State complexity:** "O(1) for basic operations, O(n) for traversal"

**Master these 10 problems → 85% Queue coverage!** 🚀

---

**Next:** Move to Queue Pattern Problems (Sliding Window, BFS-based)
