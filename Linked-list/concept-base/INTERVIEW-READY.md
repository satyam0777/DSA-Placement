#  LINKED LIST BASICS - COMPLETE INTERVIEW PACKAGE
## Foundation for All LL Problems

**Master these 10 problems → Handle 80% of basic LL questions!**

---

##  CORE CONCEPTS

**Linked List = Chain of Nodes**

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
```

**Why Linked List?**
- ✅ Dynamic size (no fixed capacity)
- ✅ Easy insertion/deletion at front (O(1))
- ✅ No shifting required like arrays

**When NOT to use?**
- ❌ Need random access (array is O(1), LL is O(n))
- ❌ Memory overhead (extra pointer storage)

---

## 🎯 PROBLEM 1: INSERT AT HEAD
**⭐⭐⭐⭐⭐ MOST BASIC!**

**Problem:**
Insert a new node at the beginning of linked list.

**Example:**
```
Input: head = 1→2→3, val = 0
Output: 0→1→2→3
```

###  SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    cout << "Original: ";
    printList(head);
    
    head = insertAtHead(head, 0);
    
    cout << "After insert: ";
    printList(head);
    
    return 0;
}
```

###  DRY RUN
```
Original: 1 → 2 → 3 → NULL
Insert 0:

Step 1: Create newNode(0)
  newNode = [0 | NULL]

Step 2: newNode->next = head
  newNode = [0 | →1]

Step 3: Return newNode as new head
  Result: 0 → 1 → 2 → 3 → NULL
```

### 💬 COMMUNICATION SCRIPT
> "Sir, inserting at head is O(1) operation. I'll create new node, point its next to current head, and return new node as new head. Very simple and efficient."
>
> **Time:** O(1), **Space:** O(1)

---

##  PROBLEM 2: INSERT AT TAIL
**⭐⭐⭐⭐⭐**

**Problem:**
Insert a new node at the end of linked list.

**Example:**
```
Input: head = 1→2→3, val = 4
Output: 1→2→3→4
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);
    
    // Empty list case
    if(head == NULL) {
        return newNode;
    }
    
    // Traverse to last node
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    // Attach new node
    temp->next = newNode;
    
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    cout << "Original: ";
    printList(head);
    
    head = insertAtTail(head, 4);
    
    cout << "After insert: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Original: 1 → 2 → 3 → NULL
Insert 4:

Step 1: temp = head (1)
Step 2: temp = temp->next (2)
Step 3: temp = temp->next (3)
Step 4: temp->next is NULL, stop
Step 5: temp->next = newNode(4)

Result: 1 → 2 → 3 → 4 → NULL
```

### 💬 COMMUNICATION SCRIPT
> "Sir, to insert at tail, I need to traverse to last node where next is NULL. Then attach new node. Time is O(n) because of traversal. To optimize, we can maintain tail pointer separately."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 3: DELETE NODE BY VALUE
**⭐⭐⭐⭐⭐**

**Problem:**
Delete first occurrence of a value from linked list.

**Example:**
```
Input: head = 1→2→3→2→4, val = 2
Output: 1→3→2→4
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* deleteNode(Node* head, int val) {
    // If head is the node to delete
    if(head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    // Find the node to delete
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    
    // If value not found
    if(curr == NULL) {
        return head;
    }
    
    // Delete the node
    prev->next = curr->next;
    delete curr;
    
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);
    
    cout << "Original: ";
    printList(head);
    
    head = deleteNode(head, 2);
    
    cout << "After delete: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Original: 1 → 2 → 3 → 2 → 4 → NULL
Delete 2:

Step 1: head->data = 1 ≠ 2, continue
Step 2: prev = 1, curr = 2
Step 3: curr->data = 2, found!
Step 4: prev->next = curr->next
        1->next = 3
Step 5: delete curr

Result: 1 → 3 → 2 → 4 → NULL
```

### 💬 COMMUNICATION SCRIPT
> "Sir, I need to track previous node to delete current node. Special case: if head itself needs deletion, handle separately. Otherwise traverse with prev and curr pointers, when found, bypass the node by prev->next = curr->next, then delete."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 4: SEARCH IN LINKED LIST
**⭐⭐⭐⭐⭐**

**Problem:**
Find if a value exists in linked list.

**Example:**
```
Input: head = 1→2→3→4, val = 3
Output: true
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

bool search(Node* head, int val) {
    Node* temp = head;
    
    while(temp != NULL) {
        if(temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    int searchVal = 3;
    
    if(search(head, searchVal)) {
        cout << searchVal << " found in list!" << endl;
    } else {
        cout << searchVal << " not found!" << endl;
    }
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, simple linear search. Traverse list, check each node's data. If match found, return true. If reach NULL, value doesn't exist, return false."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 5: REVERSE LINKED LIST (ITERATIVE)
**⭐⭐⭐⭐⭐ SUPER IMPORTANT!**

**Problem:**
Reverse the entire linked list.

**Example:**
```
Input: 1→2→3→4→NULL
Output: 4→3→2→1→NULL
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr != NULL) {
        next = curr->next;     // Save next
        curr->next = prev;     // Reverse link
        prev = curr;           // Move prev forward
        curr = next;           // Move curr forward
    }
    
    return prev;  // New head
}

void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "Original: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "Reversed: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Original: 1 → 2 → 3 → 4 → NULL

Initial: prev = NULL, curr = 1

Step 1:
  next = 2
  curr->next = NULL
  prev = 1, curr = 2
  State: NULL ← 1   2 → 3 → 4

Step 2:
  next = 3
  curr->next = 1
  prev = 2, curr = 3
  State: NULL ← 1 ← 2   3 → 4

Step 3:
  next = 4
  curr->next = 2
  prev = 3, curr = 4
  State: NULL ← 1 ← 2 ← 3   4

Step 4:
  next = NULL
  curr->next = 3
  prev = 4, curr = NULL
  State: NULL ← 1 ← 2 ← 3 ← 4

Return prev = 4
Result: 4 → 3 → 2 → 1 → NULL
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this is classic three-pointer approach. I'll maintain prev, curr, and next pointers. In each step, I reverse the link from curr to prev, then move all pointers forward. When curr becomes NULL, prev is the new head."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 6: FIND LENGTH OF LINKED LIST
**⭐⭐⭐⭐**

**Problem:**
Count total nodes in linked list.

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "Length of list: " << getLength(head) << endl;
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, simple traversal with counter. Start from head, increment count for each node, return final count."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 7: NTH NODE FROM BEGINNING
**⭐⭐⭐⭐**

**Problem:**
Get value of nth node from start (1-indexed).

**Example:**
```
Input: 1→2→3→4→5, n = 3
Output: 3
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

int getNthNode(Node* head, int n) {
    Node* temp = head;
    int count = 1;
    
    while(temp != NULL) {
        if(count == n) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    
    return -1;  // Not found
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    int n = 3;
    int result = getNthNode(head, n);
    
    if(result != -1) {
        cout << n << "th node value: " << result << endl;
    } else {
        cout << "Position out of bounds!" << endl;
    }
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, traverse list with counter. When counter equals n, return that node's value. If list ends before reaching n, return -1 or error."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 8: DELETE ENTIRE LINKED LIST
**⭐⭐⭐⭐**

**Problem:**
Free all nodes and set head to NULL.

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void deleteList(Node*& head) {
    Node* curr = head;
    Node* next = NULL;
    
    while(curr != NULL) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    
    head = NULL;
}

void printList(Node* head) {
    if(head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    cout << "Before delete: ";
    printList(head);
    
    deleteList(head);
    
    cout << "After delete: ";
    printList(head);
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, traverse list, delete each node one by one. Important to save next pointer before deleting current, otherwise we lose reference. Finally set head to NULL."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 9: INSERT AT POSITION K
**⭐⭐⭐⭐**

**Problem:**
Insert node at kth position (1-indexed).

**Example:**
```
Input: 1→2→4→5, val=3, k=3
Output: 1→2→3→4→5
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insertAtPosition(Node* head, int val, int k) {
    Node* newNode = new Node(val);
    
    // Insert at head
    if(k == 1) {
        newNode->next = head;
        return newNode;
    }
    
    // Traverse to k-1 position
    Node* temp = head;
    for(int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    // Position out of bounds
    if(temp == NULL) {
        delete newNode;
        return head;
    }
    
    // Insert
    newNode->next = temp->next;
    temp->next = newNode;
    
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    
    cout << "Original: ";
    printList(head);
    
    head = insertAtPosition(head, 3, 3);
    
    cout << "After insert: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Original: 1 → 2 → 4 → 5
Insert 3 at position 3:

Step 1: k = 3, so traverse to position 2
  temp = 1
  temp = 2 (stop, this is k-1)

Step 2: newNode(3)->next = temp->next (4)
  newNode = [3 | →4]

Step 3: temp->next = newNode
  2->next = 3

Result: 1 → 2 → 3 → 4 → 5
```

### 💬 COMMUNICATION SCRIPT
> "Sir, to insert at position k, I traverse to (k-1)th node. Then insert new node between (k-1) and k by adjusting next pointers. Handle k=1 case separately as head insertion."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 10: PRINT LINKED LIST IN REVERSE (USING RECURSION)
**⭐⭐⭐⭐**

**Problem:**
Print linked list from end to start without reversing it.

**Example:**
```
Input: 1→2→3→4
Output: 4 3 2 1
```

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void printReverse(Node* head) {
    // Base case
    if(head == NULL) {
        return;
    }
    
    // Recursive call first
    printReverse(head->next);
    
    // Print after recursion returns
    cout << head->data << " ";
}

void printNormal(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    cout << "Normal: ";
    printNormal(head);
    
    cout << "Reverse: ";
    printReverse(head);
    cout << endl;
    
    return 0;
}
```

### 📊 DRY RUN
```
List: 1 → 2 → 3 → 4 → NULL

Call printReverse(1):
  → Call printReverse(2):
    → Call printReverse(3):
      → Call printReverse(4):
        → Call printReverse(NULL): return
        Print 4
      Print 3
    Print 2
  Print 1

Output: 4 3 2 1
```

### 💬 COMMUNICATION SCRIPT
> "Sir, using recursion stack to reverse print. I'll make recursive call first until NULL, then print while returning. This uses call stack like a stack data structure. Space O(n) for recursion stack."
>
> **Time:** O(n), **Space:** O(n) for recursion stack

---

## 📊 COMPANY-WISE FREQUENCY

| Problem | TCS | Infosys | Wipro | Cognizant | Accenture |
|---------|-----|---------|-------|-----------|-----------|
| Insert at Head/Tail | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ |
| Delete Node | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ |
| Reverse List | 90% ⭐⭐⭐⭐⭐ | 85% ⭐⭐⭐⭐⭐ | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ |
| Search in List | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ |
| Find Length | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 55% ⭐⭐⭐ | 50% ⭐⭐⭐ |
| Nth Node | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 50% ⭐⭐⭐ | 45% ⭐⭐⭐ |

---

## 🎯 QUICK REVISION TEMPLATES

### Insert at Head
```cpp
Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}
```

### Insert at Tail
```cpp
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if(!head) return newNode;
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
```

### Delete by Value
```cpp
Node* deleteNode(Node* head, int val) {
    if(head && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head, *prev = NULL;
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

### Reverse (Iterative)
```cpp
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
```

---

## 💡 COMMON PATTERNS IN BASICS

**When you see:**
- "**Insert**" → Track where to insert (head/tail/position)
- "**Delete**" → Need previous pointer (except head)
- "**Reverse**" → Three pointers (prev, curr, next)
- "**Search**" → Simple traversal
- "**Length/Count**" → Traverse with counter

**Always remember:**
- Handle **empty list** (head == NULL)
- Handle **single node** list
- For deletion, **track previous** node
- For head changes, **return new head**

---

**Master these 10 basics → Ready for advanced LL patterns!** 🚀

**All the best, Satyam!** 🌟
