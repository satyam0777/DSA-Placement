#  Linked List + Other Concepts: Combined Pattern-Based Problem Solving

This guide explains how **Linked List concepts combine with other DSA concepts** in interviews, using pattern triggers to recognize the right approach.

Each section includes:
-  Core Linked List Pattern
-  Connected Concept (e.g., Stack, Recursion, Binary Search, Graph)
-  Thinking Process
-  Problem Examples

---

## 1️ Reverse LL + Recursion

###  Use Case:
- Reverse a linked list using recursion instead of loop.
- Use call stack to unwind links in reverse order.

###  Thinking Trigger:
> "Reverse karna hai, but without loop?"

###  Example:
```cpp
Node* reverse(Node* head) {
  if (!head || !head->next) return head;
  Node* rest = reverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}
```

###  Connected Concept:
- Recursion, call stack, post-order thinking

---

## 2️ Detect Cycle + Hashing (Map/Set)

###  Use Case:
- Use `unordered_set` to track visited nodes

###  Thinking Trigger:
> "Mujhe node repeat check karna hai?"

###  Example:
```cpp
bool hasCycle(Node* head) {
  unordered_set<Node*> seen;
  while (head) {
    if (seen.count(head)) return true;
    seen.insert(head);
    head = head->next;
  }
  return false;
}
```

###  Connected Concept:
- HashSet for uniqueness

---

## 3️ Kth Node + Two Pointer Technique

###  Use Case:
- Find `kth from end`, `middle`, `nth node` using fast-slow pointer

###  Thinking Trigger:
> "Do pointer se speed difference ka fayda uthana hai?"

###  Example:
Remove Nth node from end:
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode *fast = head, *slow = head;
  for (int i = 0; i < n; i++) fast = fast->next;
  if (!fast) return head->next;
  while (fast->next) fast = fast->next, slow = slow->next;
  slow->next = slow->next->next;
  return head;
}
```

###  Connected Concept:
- Sliding window-like logic

---

## 4️ Palindrome LL + Stack

###  Use Case:
- Push first half into stack, compare with second half

###  Thinking Trigger:
> "Compare front and back, mirror logic"

###  Example:
```cpp
bool isPalindrome(Node* head) {
  stack<int> st;
  Node* slow = head, *fast = head;
  while (fast && fast->next) {
    st.push(slow->val);
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast) slow = slow->next; // odd length
  while (slow) {
    if (st.top() != slow->val) return false;
    st.pop(); slow = slow->next;
  }
  return true;
}
```

###  Connected Concept:
- Stack, LIFO behavior

---

## 5️ Merge Sort on Linked List

###  Use Case:
- Sort a linked list in O(n log n)

###  Thinking Trigger:
> "Array sort nahi karna, LL ka merge sort lagana hai"

###  Example:
```cpp
Node* mergeSort(Node* head) {
  if (!head || !head->next) return head;
  Node* mid = getMid(head);
  Node* left = mergeSort(head);
  Node* right = mergeSort(mid);
  return merge(left, right);
}
```

###  Connected Concept:
- Merge Sort, Divide & Conquer

---

## 6️ Graph + LL (Adjacency List)

###  Use Case:
- Each vertex points to a list (LL of neighbors)

###  Thinking Trigger:
> "Graph ka representation LL se ho raha hai"

###  Example:
```cpp
vector<list<int>> adj(n); // C++ STL
adj[0].push_back(1);
adj[1].push_back(2);
```

###  Connected Concept:
- Graph Traversal + Linked List

---

## 7️ LRU Cache (DLL + HashMap)

###  Use Case:
- Most used interview design question
- Combination of DLL (for O(1) remove/add) + hashmap (for lookup)

###  Thinking Trigger:
> "O(1) access + O(1) remove + O(1) insert"

###  Example Sketch:
```cpp
unordered_map<int, Node*> cache;
class LRUCache {
  DLL dll;
  get(key): move node to front
  put(key, val): insert at front + remove least recent if full
};
```


