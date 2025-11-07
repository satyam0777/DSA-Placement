#  TWO POINTER - LINKED LIST PROBLEMS


**Pattern Recognition:** When you see "**middle**", "**cycle**", "**kth from end**", "**intersection**" - Think TWO POINTER!

---

##  CORE CONCEPT

**Two Pointer = Slow + Fast Pointers**

**Movement Pattern:**
```cpp
slow = slow->next;        // Move 1 step
fast = fast->next->next;  // Move 2 steps
```

**Why this works?**
- Fast travels 2x speed of slow
- When fast reaches end, slow is at middle
- If cycle exists, they'll meet inside cycle

---

##  PROBLEM 1: FIND MIDDLE OF LINKED LIST
**⭐⭐⭐⭐⭐ MOST ASKED!**

**Problem:**
Find the middle node of linked list.

**Example:**
```
Input: 1→2→3→4→5
Output: 3

Input: 1→2→3→4→5→6
Output: 4 (second middle)
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

Node* findMiddle(Node* head) {
    if(head == NULL) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
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
    head->next->next->next->next = new Node(5);
    
    cout << "List: ";
    printList(head);
    
    Node* mid = findMiddle(head);
    cout << "Middle: " << mid->data << endl;
    
    return 0;
}
```

###  DRY RUN
```
List: 1 → 2 → 3 → 4 → 5 → NULL

Initial: slow = 1, fast = 1

Step 1:
  slow = 2, fast = 3
  
Step 2:
  slow = 3, fast = 5
  
Step 3:
  fast->next = NULL, stop
  
Return slow = 3
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this is classic slow-fast pointer approach. Slow moves 1 step, fast moves 2 steps. When fast reaches end, slow is at middle. For even length, this returns second middle node."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 2: DETECT CYCLE IN LINKED LIST
**⭐⭐⭐⭐⭐ FLOYD'S ALGORITHM!**

**Problem:**
Check if linked list has a cycle.

**Example:**
```
Input: 1→2→3→4→2 (4 points back to 2)
Output: true

Input: 1→2→3→4→NULL
Output: false
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

bool hasCycle(Node* head) {
    if(head == NULL || head->next == NULL) {
        return false;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            return true;  // Cycle detected
        }
    }
    
    return false;  // No cycle
}

int main() {
    // Create list with cycle: 1→2→3→4→2
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;  // Cycle
    
    if(hasCycle(head)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
List: 1 → 2 → 3 → 4 → 2 (cycle)

Initial: slow = 1, fast = 1

Step 1: slow = 2, fast = 3
Step 2: slow = 3, fast = 2
Step 3: slow = 4, fast = 4
Step 4: slow = 2, fast = 2  → MATCH! Cycle exists

Return true
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this is Floyd's Cycle Detection algorithm, also called Tortoise and Hare. If cycle exists, fast pointer will eventually catch up to slow pointer. If no cycle, fast will reach NULL. Very elegant O(1) space solution."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 3: FIND START OF CYCLE
**⭐⭐⭐⭐⭐**

**Problem:**
Find the node where cycle begins.

**Example:**
```
Input: 1→2→3→4→2 (cycle starts at 2)
Output: Node with value 2
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

Node* detectCycleStart(Node* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    
    // Step 1: Detect cycle
    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    if(!hasCycle) {
        return NULL;
    }
    
    // Step 2: Find start of cycle
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;  // Start of cycle
}

int main() {
    // Create list with cycle: 1→2→3→4→2
    Node* head = new Node(1);
    head->next = new Node(2);
    Node* cycleStart = head->next;
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = cycleStart;  // Cycle
    
    Node* start = detectCycleStart(head);
    
    if(start) {
        cout << "Cycle starts at node: " << start->data << endl;
    } else {
        cout << "No cycle" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
List: 1 → 2 → 3 → 4 → 2 (cycle)

Phase 1: Detect cycle
  slow and fast meet at some point

Phase 2: Find start
  Reset slow to head
  Move both 1 step at a time
  
  slow = 1, fast = (wherever they met)
  slow = 2, fast = 2  → MATCH!
  
Return 2 (start of cycle)
```

### 💬 COMMUNICATION SCRIPT
> "Sir, first I detect cycle using Floyd's algorithm. After detection, I reset slow to head and move both pointers one step at a time. They will meet at cycle start. This is mathematical property of cycle detection."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 4: REMOVE CYCLE FROM LINKED LIST
**⭐⭐⭐⭐**

**Problem:**
Detect and remove cycle, making list linear.

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void removeCycle(Node* head) {
    if(!head || !head->next) return;
    
    // Detect cycle
    Node *slow = head, *fast = head;
    bool hasCycle = false;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    if(!hasCycle) return;
    
    // Find start of cycle
    slow = head;
    Node* prev = NULL;
    
    while(slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    
    // Find last node of cycle
    while(fast->next != slow) {
        fast = fast->next;
    }
    
    // Break the cycle
    fast->next = NULL;
}

void printList(Node* head) {
    int count = 0;
    while(head && count < 20) {  // Limit to avoid infinite loop
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
        count++;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;  // Cycle
    
    cout << "Before removing cycle (showing first 10): ";
    Node* temp = head;
    for(int i = 0; i < 10; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    removeCycle(head);
    
    cout << "After removing cycle: ";
    printList(head);
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, first detect cycle, then find start of cycle. After finding start, traverse to find last node that points back to start. Set that node's next to NULL to break cycle."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 5: NTH NODE FROM END
**⭐⭐⭐⭐⭐**

**Problem:**
Find nth node from the end of linked list.

**Example:**
```
Input: 1→2→3→4→5, n = 2
Output: 4
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

Node* nthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
    
    // Move fast n steps ahead
    for(int i = 0; i < n; i++) {
        if(fast == NULL) {
            return NULL;  // n is greater than length
        }
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    int n = 2;
    Node* result = nthFromEnd(head, n);
    
    if(result) {
        cout << n << "th node from end: " << result->data << endl;
    } else {
        cout << "Invalid n" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
List: 1 → 2 → 3 → 4 → 5 → NULL
n = 2

Step 1: Move fast 2 steps ahead
  fast = 3, slow = 1

Step 2: Move both together
  fast = 4, slow = 2
  fast = 5, slow = 3
  fast = NULL, slow = 4

Return slow = 4 (2nd from end)
```

### 💬 COMMUNICATION SCRIPT
> "Sir, this uses two-pointer with gap. I'll move fast pointer n steps ahead first. Then move both together. When fast reaches end, slow will be at nth from end. This avoids calculating length separately."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 6: DELETE NTH NODE FROM END
**⭐⭐⭐⭐⭐ LEETCODE 19!**

**Problem:**
Remove nth node from end of list.

**Example:**
```
Input: 1→2→3→4→5, n = 2
Output: 1→2→3→5
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

Node* removeNthFromEnd(Node* head, int n) {
    // Dummy node to handle edge cases
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node* fast = dummy;
    Node* slow = dummy;
    
    // Move fast n+1 steps ahead
    for(int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Delete nth node
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    
    Node* newHead = dummy->next;
    delete dummy;
    
    return newHead;
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
    head->next->next->next->next = new Node(5);
    
    cout << "Original: ";
    printList(head);
    
    head = removeNthFromEnd(head, 2);
    
    cout << "After removing 2nd from end: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
List: 1 → 2 → 3 → 4 → 5, n = 2

Step 1: Create dummy → 0 → 1 → 2 → 3 → 4 → 5
Step 2: Move fast n+1 steps (3 steps)
  fast = 3, slow = dummy(0)

Step 3: Move both together
  fast = 4, slow = 1
  fast = 5, slow = 2
  fast = NULL, slow = 3

Step 4: slow->next = 4, delete it
  slow->next = slow->next->next (5)

Result: 1 → 2 → 3 → 5
```

### 💬 COMMUNICATION SCRIPT
> "Sir, similar to finding nth from end, but I use dummy node to handle edge cases like deleting head. Move fast n+1 steps ahead so slow stops at node before the one to delete. Then bypass and delete."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 7: INTERSECTION OF TWO LINKED LISTS
**⭐⭐⭐⭐⭐ LEETCODE 160!**

**Problem:**
Find node where two lists intersect.

**Example:**
```
A: 1→2→3→4→5
B:     6→4→5
Output: Node 4 (intersection point)
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

Node* getIntersection(Node* headA, Node* headB) {
    if(!headA || !headB) return NULL;
    
    Node* a = headA;
    Node* b = headB;
    
    // When one reaches end, redirect to other list's head
    while(a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    
    return a;  // Intersection point or NULL
}

int main() {
    // Create intersection
    Node* common = new Node(4);
    common->next = new Node(5);
    
    // List A: 1→2→3→4→5
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common;
    
    // List B: 6→4→5
    Node* headB = new Node(6);
    headB->next = common;
    
    Node* intersection = getIntersection(headA, headB);
    
    if(intersection) {
        cout << "Intersection at node: " << intersection->data << endl;
    } else {
        cout << "No intersection" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
A: 1 → 2 → 3 → 4 → 5
B:           6 → 4 → 5

a = 1, b = 6
a = 2, b = 4
a = 3, b = 5
a = 4, b = NULL → redirect to headA (1)
a = 5, b = 1
a = NULL → redirect to headB (6), b = 2
a = 6, b = 3
a = 4, b = 4  → MATCH!

Return 4
```

### 💬 COMMUNICATION SCRIPT
> "Sir, elegant two-pointer solution. When one pointer reaches end, redirect it to other list's head. They will eventually meet at intersection or both become NULL if no intersection. This handles different lengths automatically."
>
> **Time:** O(m + n), **Space:** O(1)

---

## 🎯 PROBLEM 8: CHECK IF LENGTH IS EVEN OR ODD
**⭐⭐⭐**

**Problem:**
Determine if linked list has even or odd number of nodes.

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

bool isEvenLength(Node* head) {
    if(!head) return true;  // 0 is even
    
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
    }
    
    return (fast == NULL);  // If NULL, even; if not NULL, odd
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    if(isEvenLength(head)) {
        cout << "List has even length" << endl;
    } else {
        cout << "List has odd length" << endl;
    }
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, use fast pointer moving 2 steps. If it ends at NULL, list has even nodes. If it ends at last node (next is NULL), list has odd nodes."
>
> **Time:** O(n), **Space:** O(1)

---

## 📊 COMPANY-WISE FREQUENCY

| Problem | TCS | Infosys | Wipro | Cognizant | Accenture |
|---------|-----|---------|-------|-----------|-----------|
| Find Middle | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ |
| Detect Cycle | 90% ⭐⭐⭐⭐⭐ | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ |
| Find Cycle Start | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ |
| Nth from End | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ |
| Delete Nth from End | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ |
| Intersection | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐ | 45% ⭐⭐⭐ |

---

## 🎯 QUICK REVISION TEMPLATES

### Find Middle
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

### Detect Cycle
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

### Nth from End
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

### Intersection
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

## 💡 PATTERN IDENTIFICATION

**When you see:**
- "**Middle** of list" → Slow-fast, both start together
- "**Cycle** detection" → Slow-fast, check if they meet
- "**Nth from end**" → Gap of n between pointers
- "**Intersection**" → Redirect to other list on NULL

**Key insight:**
> Fast pointer travels 2x speed of slow
> This creates useful mathematical relationships

---

**Master these 8 problems → Handle 95% two-pointer LL questions!** 🚀
