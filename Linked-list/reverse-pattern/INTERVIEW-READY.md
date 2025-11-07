# REVERSE PATTERN - LINKED LIST PROBLEMS
## Complete Interview Package

**Pattern Recognition:** When you see "**reverse**", "**palindrome**", "**reorder**", "**k-groups**" - Think REVERSE!

---

## 📌 CORE CONCEPT

**Reverse = Change direction of next pointers**

**Three Pointer Technique:**
```cpp
Node *prev = NULL, *curr = head, *next = NULL;
while(curr) {
    next = curr->next;     // Save next
    curr->next = prev;     // Reverse
    prev = curr;           // Move prev
    curr = next;           // Move curr
}
return prev;  // New head
```

---

## 🎯 PROBLEM 1: REVERSE ENTIRE LINKED LIST (ITERATIVE)
**⭐⭐⭐⭐⭐ MOST IMPORTANT!**

**Problem:**
Reverse the complete linked list.

**Example:**
```
Input: 1→2→3→4→5
Output: 5→4→3→2→1
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
    head->next->next->next->next = new Node(5);
    
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
Original: 1 → 2 → 3 → 4 → 5 → NULL

Initial: prev = NULL, curr = 1, next = NULL

Step 1: next = 2, curr->next = NULL
        prev = 1, curr = 2
        NULL ← 1    2 → 3 → 4 → 5

Step 2: next = 3, curr->next = 1
        prev = 2, curr = 3
        NULL ← 1 ← 2    3 → 4 → 5

Step 3: next = 4, curr->next = 2
        prev = 3, curr = 4
        NULL ← 1 ← 2 ← 3    4 → 5

Step 4: next = 5, curr->next = 3
        prev = 4, curr = 5
        NULL ← 1 ← 2 ← 3 ← 4    5

Step 5: next = NULL, curr->next = 4
        prev = 5, curr = NULL

Return prev = 5
Result: 5 → 4 → 3 → 2 → 1 → NULL
```

### 💬 COMMUNICATION SCRIPT
> "Sir, classic three-pointer iterative approach. I maintain prev, curr, and next pointers. In each iteration, I reverse current node's link to point to previous, then move all pointers forward. Time O(n), space O(1)."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 2: REVERSE LINKED LIST (RECURSIVE)
**⭐⭐⭐⭐⭐**

**Problem:**
Reverse list using recursion.

### ✅ SOLUTION

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* reverseRecursive(Node* head) {
    // Base case: empty or single node
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive call
    Node* newHead = reverseRecursive(head->next);
    
    // Reverse the link
    head->next->next = head;
    head->next = NULL;
    
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
    
    cout << "Original: ";
    printList(head);
    
    head = reverseRecursive(head);
    
    cout << "Reversed: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Original: 1 → 2 → 3 → 4 → NULL

reverseRecursive(1):
  reverseRecursive(2):
    reverseRecursive(3):
      reverseRecursive(4):
        reverseRecursive(NULL):
          return NULL
        return 4
      4->next->next = 3
      3->next = NULL
      return 4
    3->next->next = 2
    2->next = NULL
    return 4
  2->next->next = 1
  1->next = NULL
  return 4

Result: 4 → 3 → 2 → 1 → NULL
```

### 💬 COMMUNICATION SCRIPT
> "Sir, recursive approach. Base case: if head is NULL or single node, return head. Otherwise, recursively reverse rest of list, then make next node point back to current. Set current's next to NULL. Return new head from recursion."
>
> **Time:** O(n), **Space:** O(n) for recursion stack

---

## 🎯 PROBLEM 3: REVERSE LINKED LIST IN K-GROUPS
**⭐⭐⭐⭐⭐ LEETCODE 25!**

**Problem:**
Reverse nodes in groups of K.

**Example:**
```
Input: 1→2→3→4→5, k = 2
Output: 2→1→4→3→5

Input: 1→2→3→4→5, k = 3
Output: 3→2→1→4→5
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

Node* reverseKGroup(Node* head, int k) {
    // Check if k nodes exist
    Node* temp = head;
    for(int i = 0; i < k; i++) {
        if(!temp) return head;  // Less than k nodes remaining
        temp = temp->next;
    }
    
    // Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    
    while(curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Recursively reverse remaining groups
    if(next != NULL) {
        head->next = reverseKGroup(next, k);
    }
    
    return prev;  // New head of this group
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
    
    head = reverseKGroup(head, 2);
    
    cout << "Reversed in groups of 2: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Input: 1 → 2 → 3 → 4 → 5, k = 2

Step 1: Check if 2 nodes exist → Yes
Step 2: Reverse first 2 nodes
  1 ← 2    3 → 4 → 5
  prev = 2, curr = 3

Step 3: Recursively call on remaining (3 → 4 → 5)
  Check if 2 nodes exist → Yes
  Reverse: 3 ← 4    5
  prev = 4, curr = 5
  
Step 4: Recursively call on (5)
  Check if 2 nodes exist → No
  Return 5 as is

Step 5: Connect groups
  1->next = 4
  3->next = 5

Result: 2 → 1 → 4 → 3 → 5
```

### 💬 COMMUNICATION SCRIPT
> "Sir, recursive approach with group reversal. First check if k nodes exist. If yes, reverse those k nodes, then recursively reverse remaining groups. Connect current group's tail to next group's head. If less than k nodes remain, leave them as is."
>
> **Time:** O(n), **Space:** O(n/k) for recursion

---

## 🎯 PROBLEM 4: PALINDROME LINKED LIST
**⭐⭐⭐⭐⭐**

**Problem:**
Check if linked list is palindrome.

**Example:**
```
Input: 1→2→2→1
Output: true

Input: 1→2→3
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

Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

bool isPalindrome(Node* head) {
    if(!head || !head->next) return true;
    
    // Find middle
    Node* mid = findMiddle(head);
    
    // Reverse second half
    Node* secondHalf = reverse(mid);
    
    // Compare both halves
    Node* firstHalf = head;
    Node* secondHalfCopy = secondHalf;  // To restore later
    
    while(secondHalf) {
        if(firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    // Optional: Restore list
    reverse(secondHalfCopy);
    
    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    
    if(isPalindrome(head)) {
        cout << "List is palindrome!" << endl;
    } else {
        cout << "List is NOT palindrome!" << endl;
    }
    
    return 0;
}
```

### 📊 DRY RUN
```
List: 1 → 2 → 2 → 1

Step 1: Find middle
  slow-fast → mid = 2 (second 2)

Step 2: Reverse second half
  2 → 1 becomes 1 → 2

Step 3: Compare
  First half: 1 → 2
  Second half: 1 → 2
  Match! Palindrome

Return true
```

### 💬 COMMUNICATION SCRIPT
> "Sir, three-step approach. First find middle using slow-fast pointers. Then reverse second half. Finally compare first half and reversed second half. If all match, it's palindrome. Optionally restore list by reversing second half again."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 5: REORDER LIST
**⭐⭐⭐⭐⭐ LEETCODE 143!**

**Problem:**
Reorder list as L0→Ln→L1→Ln-1→L2→Ln-2...

**Example:**
```
Input: 1→2→3→4→5
Output: 1→5→2→4→3
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

Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

void reorderList(Node* head) {
    if(!head || !head->next) return;
    
    // Find middle
    Node* mid = findMiddle(head);
    
    // Reverse second half
    Node* secondHalf = reverse(mid);
    
    // Merge alternately
    Node* firstHalf = head;
    
    while(secondHalf->next) {
        Node* temp1 = firstHalf->next;
        Node* temp2 = secondHalf->next;
        
        firstHalf->next = secondHalf;
        secondHalf->next = temp1;
        
        firstHalf = temp1;
        secondHalf = temp2;
    }
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
    
    reorderList(head);
    
    cout << "Reordered: ";
    printList(head);
    
    return 0;
}
```

### 📊 DRY RUN
```
Original: 1 → 2 → 3 → 4 → 5

Step 1: Find middle = 3

Step 2: Reverse second half
  3 → 4 → 5 becomes 5 → 4 → 3

Step 3: Merge alternately
  First: 1 → 2 → 3
  Second: 5 → 4 → 3
  
  Merge:
  1 → 5 → 2 → 4 → 3

Result: 1 → 5 → 2 → 4 → 3
```

### 💬 COMMUNICATION SCRIPT
> "Sir, three-step solution. Find middle, reverse second half, then merge both halves alternately. Take one from first, one from second, repeat. This creates the required reordering pattern."
>
> **Time:** O(n), **Space:** O(1)

---

## 🎯 PROBLEM 6: REVERSE BETWEEN M AND N
**⭐⭐⭐⭐ LEETCODE 92!**

**Problem:**
Reverse nodes from position m to n (1-indexed).

**Example:**
```
Input: 1→2→3→4→5, m=2, n=4
Output: 1→4→3→2→5
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

Node* reverseBetween(Node* head, int m, int n) {
    if(!head || m == n) return head;
    
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* prev = dummy;
    
    // Move to node before m
    for(int i = 1; i < m; i++) {
        prev = prev->next;
    }
    
    // Reverse from m to n
    Node* curr = prev->next;
    for(int i = 0; i < n - m; i++) {
        Node* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    
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
    
    head = reverseBetween(head, 2, 4);
    
    cout << "Reversed between 2 and 4: ";
    printList(head);
    
    return 0;
}
```

### 💬 COMMUNICATION SCRIPT
> "Sir, use dummy node to handle edge cases. Move to (m-1)th node. Then reverse the portion from m to n by repeatedly moving next node to front. This avoids complex pointer management."
>
> **Time:** O(n), **Space:** O(1)

---

## 📊 COMPANY-WISE FREQUENCY

| Problem | TCS | Infosys | Wipro | Cognizant | Accenture |
|---------|-----|---------|-------|-----------|-----------|
| Reverse List (Iterative) | 95% ⭐⭐⭐⭐⭐ | 90% ⭐⭐⭐⭐⭐ | 90% ⭐⭐⭐⭐⭐ | 85% ⭐⭐⭐⭐⭐ | 80% ⭐⭐⭐⭐⭐ |
| Reverse (Recursive) | 60% ⭐⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ |
| Reverse K-Groups | 55% ⭐⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ |
| Palindrome List | 80% ⭐⭐⭐⭐⭐ | 75% ⭐⭐⭐⭐⭐ | 70% ⭐⭐⭐⭐⭐ | 65% ⭐⭐⭐⭐ | 60% ⭐⭐⭐⭐ |
| Reorder List | 50% ⭐⭐⭐⭐ | 45% ⭐⭐⭐ | 55% ⭐⭐⭐⭐ | 40% ⭐⭐⭐ | 35% ⭐⭐⭐ |
| Reverse Between | 45% ⭐⭐⭐ | 40% ⭐⭐⭐ | 50% ⭐⭐⭐⭐ | 35% ⭐⭐⭐ | 30% ⭐⭐ |

---

## 🎯 QUICK REVISION TEMPLATES

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

### Reverse (Recursive)
```cpp
Node* reverse(Node* head) {
    if(!head || !head->next) return head;
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
```

### Palindrome Check
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

---

## 💡 PATTERN IDENTIFICATION

**When you see:**
- "**Reverse** entire list" → Three pointers
- "**Palindrome**" → Find middle + Reverse second half
- "**Reorder**" → Find middle + Reverse + Merge
- "**K-groups**" → Reverse in chunks + Recursion
- "**Reverse between**" → Dummy node + Partial reverse

**Key insight:**
> Reverse is foundation for many complex LL problems
> Master iterative and recursive versions

---

**Master these 6 problems → Handle 90% reverse-based LL questions!** 🚀
