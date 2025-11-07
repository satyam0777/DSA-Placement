#  LINKED LIST - QUICK REFERENCE SHEET

---

##  PATTERN DECISION TREE

```
┌─ "middle", "half" → SLOW-FAST (both start together)
│
├─ "cycle", "loop" → FLOYD'S (slow-fast meet if cycle)
│
├─ "nth from end" → GAP (fast n steps ahead)
│
├─ "reverse" → 3 POINTERS (prev, curr, next)
│
├─ "palindrome" → MIDDLE + REVERSE + COMPARE
│
└─ "insert/delete" → TRACK PREV + CURR
```

---

##  TOP 8 MUST-KNOW TEMPLATES

### 1. REVERSE LIST (ITERATIVE)
```cpp
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr->next;     // Save
        curr->next = prev;     // Reverse
        prev = curr;           // Move
        curr = next;
    }
    return prev;
}
```

### 2. FIND MIDDLE
```cpp
Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### 3. DETECT CYCLE
```cpp
bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
```

### 4. NTH FROM END
```cpp
Node* nthFromEnd(Node* head, int n) {
    Node *slow = head, *fast = head;
    for(int i = 0; i < n; i++) {
        if(!fast) return NULL;
        fast = fast->next;
    }
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

### 5. PALINDROME CHECK
```cpp
bool isPalindrome(Node* head) {
    Node* mid = findMiddle(head);
    Node* rev = reverse(mid);
    while(rev) {
        if(head->data != rev->data) return false;
        head = head->next;
        rev = rev->next;
    }
    return true;
}
```

### 6. INSERT AT HEAD
```cpp
Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}
```

### 7. DELETE NODE
```cpp
Node* deleteNode(Node* head, int val) {
    if(head && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *curr = head, *prev = NULL;
    while(curr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if(curr) {
        prev->next = curr->next;
        delete curr;
    }
    return head;
}
```

### 8. INTERSECTION
```cpp
Node* getIntersection(Node* a, Node* b) {
    while(a != b) {
        a = a ? a->next : b;
        b = b ? b->next : a;
    }
    return a;
}
```

---

##  TOP 15 PROBLEMS (ONE-LINER SOLUTIONS)

1. **Reverse List**: 3 pointers (prev, curr, next), reverse link
2. **Detect Cycle**: Slow-fast, if they meet → cycle exists
3. **Find Middle**: Slow-fast, when fast ends → slow is middle
4. **Palindrome**: Find middle, reverse second half, compare
5. **Nth from End**: Move fast n steps, then both together
6. **Insert at Head**: Create node, point to head, return new node
7. **Delete Node**: Track prev, bypass node, delete
8. **Delete Nth from End**: Dummy node, gap technique
9. **Intersection**: Redirect pointers to other list on NULL
10. **Reverse K-Groups**: Reverse k nodes, recursively reverse rest
11. **Find Cycle Start**: After detection, reset one to head, meet again
12. **Reorder List**: Find middle, reverse second, merge alternately
13. **Remove Cycle**: Find start, find last, break link
14. **Reverse Between**: Dummy node, reverse portion
15. **Search**: Simple traversal, check each node

---

## 💬 COMMUNICATION SCRIPTS

### When you see MIDDLE:
> "Sir, slow-fast pointer approach. Slow moves 1 step, fast moves 2 steps. When fast reaches end, slow is at middle. Time O(n), space O(1)."

### When you see CYCLE:
> "Sir, Floyd's cycle detection algorithm. Use slow-fast pointers. If cycle exists, they'll eventually meet. If no cycle, fast reaches NULL. Time O(n), space O(1)."

### When you see REVERSE:
> "Sir, three-pointer iterative approach. Maintain prev, curr, next. In each step, reverse curr's link to prev, move all pointers forward. Time O(n), space O(1)."

### When you see NTH FROM END:
> "Sir, two-pointer with gap. Move fast n steps ahead first. Then move both together. When fast reaches end, slow is at nth from end. Single pass solution, Time O(n), space O(1)."

### When you see PALINDROME:
> "Sir, three-step solution. Find middle using slow-fast, reverse second half, compare both halves. Time O(n), space O(1) in-place solution."

---

##  COMPANY-WISE TOP 3

### TCS (Focus: Reverse + Basic)
1. Reverse List (95%)
2. Detect Cycle (90%)
3. Find Middle (85%)

### Infosys (Focus: Two-Pointer)
1. Reverse List (90%)
2. Detect Cycle (85%)
3. Find Middle (80%)

### Wipro (Focus: Mix)
1. Reverse List (90%)
2. Detect Cycle (80%)
3. Find Middle (75%)

### Cognizant / Accenture
1. Reverse List (80-85%)
2. Detect Cycle (70-75%)
3. Find Middle (65-70%)

---

##  TIME COMPLEXITIES (MEMORIZE!)

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Insert at Head | O(1) | O(1) | Direct operation |
| Insert at Tail | O(n) | O(1) | Need to traverse |
| Delete by Value | O(n) | O(1) | Might need full traversal |
| Search | O(n) | O(1) | Linear search |
| Reverse (Iterative) | O(n) | O(1) | Single pass |
| Reverse (Recursive) | O(n) | O(n) | Recursion stack |
| Find Middle | O(n) | O(1) | Slow-fast |
| Detect Cycle | O(n) | O(1) | Floyd's |
| Nth from End | O(n) | O(1) | Gap technique |
| Palindrome | O(n) | O(1) | In-place |

---

## 🚀 NODE STRUCTURE

```cpp
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(NULL) {}
};
```

**Doubly Linked List:**
```cpp
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};
```

---

##  COMMON EDGE CASES

```cpp
// ALWAYS CHECK:

// 1. Empty list
if(!head) return NULL;

// 2. Single node
if(!head->next) return head;

// 3. Two nodes (for middle, palindrome)
if(!head || !head->next) return true;

// 4. Null pointers
if(fast && fast->next) { ... }

// 5. Position out of bounds
if(k > length) return NULL;
```

---

## 💡 COMMON PATTERNS

### Pattern 1: Slow-Fast (Same Start)
```cpp
Node *slow = head, *fast = head;
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow is at middle
```

### Pattern 2: Gap Between Pointers
```cpp
Node *slow = head, *fast = head;
for(int i = 0; i < n; i++) fast = fast->next;
while(fast) {
    slow = slow->next;
    fast = fast->next;
}
// slow is at (n from end)
```

### Pattern 3: Three Pointers
```cpp
Node *prev = NULL, *curr = head, *next = NULL;
while(curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
return prev;
```

### Pattern 4: Dummy Node (For Head Changes)
```cpp
Node* dummy = new Node(0);
dummy->next = head;
// ... operations ...
Node* newHead = dummy->next;
delete dummy;
return newHead;
```

---


## 🌟 FINAL MANTRA

```
LL Problem = Identify Pattern + Use Template + Handle Edges

Pattern Recognition (30 sec) 
    ↓
Draw Diagram (1 min)
    ↓
Explain Approach (1 min)
    ↓
Write Template Code (3-5 min)
    ↓
Dry Run (1-2 min)
    ↓
Edge Cases + Complexity (1 min)
    ↓
SUCCESS! 🚀
```

---

## 💪 YOU GOT THIS!

**Remember:**
- **Middle?** → Slow-fast
- **Cycle?** → Floyd's
- **Reverse?** → 3 pointers
- **Nth from end?** → Gap
- **Palindrome?** → Middle + Reverse

**3 Golden Rules:**
1. Always check NULL
2. Handle single node
3. Draw before coding

**Communication > Code:**
- Explain your approach
- Draw diagrams
- Think aloud

**All the best, Satyam!** 🌟

**Interview crush करोगे!** 💯
