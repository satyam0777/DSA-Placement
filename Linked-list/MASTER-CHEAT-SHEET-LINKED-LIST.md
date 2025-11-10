# 📌 MASTER-CHEAT-SHEET: LINKED LIST
## Complete Summary at One Place

---

## 🎯 PATTERN RECOGNITION TABLE

| Magic Keywords | Pattern | Template | Time | Space | Frequency |
|---|---|---|---|---|---|
| middle, halfway, split | Two-Pointer (Slow-Fast) | Template 1 | O(n) | O(1) | ⭐⭐⭐⭐⭐ |
| cycle, loop, detect | Floyd's Cycle | Template 2 | O(n) | O(1) | ⭐⭐⭐⭐⭐ |
| kth from end, nth | Gap Technique | Template 4 | O(n) | O(1) | ⭐⭐⭐⭐ |
| reverse, backward, undo | 3-Pointer Reversal | Template 3 | O(n) | O(1) | ⭐⭐⭐⭐⭐ |
| palindrome, mirror, symmetric | Reverse + Two-Pointer | Template 5 | O(n) | O(1) | ⭐⭐⭐⭐ |
| insert, delete, modify | Dummy Node + Tracking | Template 6 | O(n) | O(1) | ⭐⭐⭐⭐ |
| reverse groups, k chunks | K-Group Reversal | Template 7 | O(n) | O(1) | ⭐⭐⭐ |
| intersection, common, merge | Pointer Sync | Template 8 | O(n) | O(1) | ⭐⭐⭐ |

---

## 🎪 7 ESSENTIAL TEMPLATES (Quick Reference)

```cpp
// TEMPLATE 1: FIND MIDDLE
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// Mantra: Slow 1, fast 2 → slow at middle

// TEMPLATE 2: DETECT CYCLE
while(fast && fast->next) {
    if(slow == fast) return true;
    slow = slow->next;
    fast = fast->next->next;
}
// Mantra: They meet = cycle, fast NULL = no cycle

// TEMPLATE 3: REVERSE
while(curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
// Mantra: Save next, reverse link, move forward

// TEMPLATE 4: NTH FROM END
for(int i = 0; i < n; i++) fast = fast->next;
while(fast) {
    slow = slow->next;
    fast = fast->next;
}
// Mantra: Gap n, then together → nth from end

// TEMPLATE 5: PALINDROME
// Step 1: Find mid (slow-fast)
// Step 2: Reverse second half
// Step 3: Compare halves
// Mantra: Mid + Rev + Cmp

// TEMPLATE 6: DELETE WITH DUMMY
Node* dummy = new Node(0);
dummy->next = head;
// ... use dummy ...
result = dummy->next;
// Mantra: Dummy handles head deletion

// TEMPLATE 7: REVERSE K-GROUPS
// Check k available, reverse group, reconnect
// Repeat for next group
// Mantra: Check, reverse, reconnect, next
```

---

## 🗺️ MASTER DECISION TREE

```
                    START
                     ↓
        ┌────────────┴────────────┐
        │ Problem Analysis        │
        └────────────┬────────────┘
                     ↓
        ┌─────────────────────────────────┐
        │ Does problem have "middle"?     │
        │ or "split" or "divide"?         │
        └────────┬──────────────┬─────────┘
              YES │              │ NO
                  ↓              ↓
            SLOW-FAST       ┌─────────────────┐
            (Template 1)    │ "cycle" or      │
                            │ "loop"?         │
                            └────┬───────┬────┘
                              YES│       │NO
                                 ↓       ↓
                            FLOYD'S  ┌──────────────┐
                           (Temp 2)  │ "reverse" or │
                                     │ "backward"?  │
                                     └────┬───┬─────┘
                                       YES│   │NO
                                          ↓   ↓
                                       3-PTR ┌──────────────┐
                                      (Temp 3)│"palindrome"? │
                                             │ or "mirror"? │
                                             └────┬───┬─────┘
                                               YES│   │NO
                                                  ↓   ↓
                                            REV+2PT ┌────────────┐
                                           (Temp 5) │ "nth from" │
                                                    │ or "kth"?  │
                                                    └────┬──┬────┘
                                                      YES│  │NO
                                                         ↓  ↓
                                                       GAP  ┌───────┐
                                                     (Temp4)│BASIC │
                                                         │INSERT │
                                                         │DELETE │
                                                         │(Temp6)│
                                                         └───────┘
```

---

## 📚 ALL TEMPLATES QUICK REFERENCE

### TEMPLATE 1: FIND MIDDLE
```cpp
Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Time: O(n), Space: O(1)
// Used in: Middle, Palindrome, Reorder
```

### TEMPLATE 2: DETECT CYCLE (FLOYD'S)
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
// Time: O(n), Space: O(1)
// Used in: Cycle detection, Cycle start
```

### TEMPLATE 3: REVERSE (3-POINTER)
```cpp
Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Time: O(n), Space: O(1)
// Used in: Reverse, Palindrome, Reorder
```

### TEMPLATE 4: NTH FROM END (GAP)
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
// Time: O(n), Space: O(1)
// Used in: Kth from end, Remove nth
```

### TEMPLATE 5: PALINDROME (3-STEP)
```cpp
bool isPalindrome(Node* head) {
    // Step 1: Find middle
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Reverse second half
    Node *prev = NULL, *curr = slow;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Step 3: Compare
    while(prev) {
        if(head->data != prev->data) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
// Time: O(n), Space: O(1)
```

### TEMPLATE 6: DELETE WITH DUMMY
```cpp
Node* deleteNode(Node* head, int val) {
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node *prev = dummy, *curr = head;
    while(curr) {
        if(curr->data == val) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}
// Time: O(n), Space: O(1)
// Used in: Delete, Insert, Modify head
```

### TEMPLATE 7: REVERSE K-GROUPS
```cpp
Node* reverseKGroup(Node* head, int k) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node *prevTail = dummy, *curr = head;
    
    while(curr) {
        // Check k nodes available
        Node* kthNode = curr;
        for(int i = 0; i < k - 1 && kthNode; i++) {
            kthNode = kthNode->next;
        }
        if(!kthNode) break;
        
        // Reverse k group
        Node* nextGroup = kthNode->next;
        Node *prev = NULL, *c = curr;
        for(int i = 0; i < k; i++) {
            Node* next = c->next;
            c->next = prev;
            prev = c;
            c = next;
        }
        
        // Reconnect
        Node* prevGroupTail = curr;
        prevTail->next = kthNode;
        prevGroupTail->next = nextGroup;
        prevTail = prevGroupTail;
        curr = nextGroup;
    }
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}
// Time: O(n), Space: O(1)
// Example: 1→2→3→4→5, k=2 → 2→1→4→3→5
```

### TEMPLATE 8: INTERSECTION (POINTER SYNC)
```cpp
Node* getIntersection(Node* a, Node* b) {
    while(a != b) {
        a = a ? a->next : b;  // Redirect on NULL
        b = b ? b->next : a;
    }
    return a; // Meeting point or NULL
}
// Time: O(m+n), Space: O(1)
// Why it works: Both travel same total distance
```

---

## 🎯 COMPLEXITY REFERENCE

```
ALL LL PATTERNS = O(n) TIME, O(1) SPACE

Key Insight: Pointer tricks (not arrays) → No extra space!

Compare to Arrays:
- Array: O(n) time, O(n) space (copy needed for reverse)
- LL: O(n) time, O(1) space (just rewire pointers)

This is why LL appears in interviews!
```

---

## 🔥 MAGIC KEYWORDS → PATTERN MAPPING

```
"middle" → SLOW-FAST
"find the middle"
"split in half"
"divide list"
→ Algorithm: Both start at head, slow 1 step, fast 2 steps
→ Result: slow at middle when fast ends

"cycle" → FLOYD'S
"loop"
"detect repetition"
"circular"
→ Algorithm: If they meet, cycle exists
→ Result: Two pointers meet or fast exits

"reverse" → 3-POINTER
"backward"
"undo"
"opposite direction"
→ Algorithm: prev-curr-next triplet
→ Result: All links reversed

"palindrome" → REVERSE + 2-POINTER
"mirror"
"symmetric"
"same forward/backward"
→ Algorithm: Find mid, reverse second, compare
→ Result: First == Reversed second = palindrome

"nth from end" → GAP TECHNIQUE
"kth from last"
"k positions from end"
→ Algorithm: Create gap k, move both together
→ Result: slow at kth from end when fast exits

"insert/delete" → DUMMY NODE
"modify"
"remove"
"add at head"
→ Algorithm: Dummy → head, use prev tracking
→ Result: Head deletion becomes safe

"k groups" → K-GROUP REVERSAL
"reverse every k"
"rotate"
→ Algorithm: Check k available, reverse group, reconnect
→ Result: Every k nodes reversed
```

---

## 📊 TOP 15 PROBLEMS QUICK SOLVE GUIDE

| # | Problem | Pattern | Time | Space |
|---|---------|---------|------|-------|
| 1 | Reverse List | 3-Pointer | O(n) | O(1) |
| 2 | Detect Cycle | Floyd's | O(n) | O(1) |
| 3 | Find Middle | Slow-Fast | O(n) | O(1) |
| 4 | Palindrome | Rev+2Ptr | O(n) | O(1) |
| 5 | Nth from End | Gap | O(n) | O(1) |
| 6 | Delete by Value | Dummy | O(n) | O(1) |
| 7 | Insert at Head | Basic | O(1) | O(1) |
| 8 | Remove Nth End | Gap+Dummy | O(n) | O(1) |
| 9 | Intersection | Pointer Sync | O(m+n) | O(1) |
| 10 | Reverse K-Groups | K-Group | O(n) | O(1) |
| 11 | Find Cycle Start | Floyd's+Position | O(n) | O(1) |
| 12 | Merge Sorted | Compare | O(m+n) | O(1) |
| 13 | Reorder List | Rev+2Ptr | O(n) | O(1) |
| 14 | Cycle Length | Floyd's Loop | O(n) | O(1) |
| 15 | Reverse Between M-N | Dummy+Rev | O(n) | O(1) |

---

## 💬 INTERVIEW SCRIPTS (One-Liners)

### When Interviewer Gives "Middle" Problem
> "I'll use slow-fast pointers - both start at head, slow moves 1 step, fast moves 2 steps, when fast reaches end slow is at middle. O(n) time, O(1) space."

### When Interviewer Gives "Cycle" Problem
> "Floyd's cycle detection - if there's a cycle, two pointers at different speeds will eventually meet. If no cycle, fast pointer reaches NULL first. O(n) time, O(1) space."

### When Interviewer Gives "Reverse" Problem
> "Three-pointer approach - maintain prev, curr, next. Save next first (don't lose it), then reverse curr's link, move all three forward. O(n) time, O(1) space."

### When Interviewer Gives "Palindrome" Problem
> "Three-step: find middle with slow-fast, reverse second half in-place, compare both halves. O(n) time, O(1) space, no extra data structures."

### When Interviewer Gives "Kth from End" Problem
> "Gap technique - create gap of k between two pointers, then move both together until fast reaches end. When fast is at end, slow is at kth from end. O(n) time, single pass."

---

## 🎬 ONE-PAGE PRINTABLE WALLET CARD

```
╔════════════════════════════════════════════╗
║    LINKED LIST MASTER - WALLET CARD        ║
║ Fit in your pocket before interview!       ║
╚════════════════════════════════════════════╝

┌─ PATTERN QUICK ID ─────────────────────────┐
│ middle → SLOW-FAST                         │
│ cycle → FLOYD'S                            │
│ reverse → 3-POINTER                        │
│ palindrome → REV+2PTR                      │
│ nth from end → GAP                         │
│ insert/delete → DUMMY                      │
│ k-groups → K-GROUP REV                     │
└────────────────────────────────────────────┘

┌─ ALWAYS REMEMBER ───────────────────────────┐
│ ✓ NULL check everything!                    │
│ ✓ Save next before reversing link!          │
│ ✓ Use dummy for head changes!               │
│ ✓ All solutions = O(1) space!               │
│ ✓ Draw diagrams in interview!               │
└────────────────────────────────────────────┘

┌─ CRITICAL MANTRAS ──────────────────────────┐
│ "Slow 1, fast 2 → slow is middle"          │
│ "They meet = cycle, NULL = no cycle"       │
│ "Save next, reverse, move all forward"     │
│ "Gap n, both together → nth from end"      │
│ "Mid + Rev + Cmp = Palindrome"             │
│ "Dummy handles head deletion safely"       │
└────────────────────────────────────────────┘

┌─ COMMUNICATION ─────────────────────────────┐
│ 1. Explain approach (30 sec)                │
│ 2. Draw diagram (30 sec)                    │
│ 3. State complexity (30 sec)                │
│ 4. Code template (3-5 min)                  │
│ 5. Dry run (1 min)                          │
│ 6. Edge cases (30 sec)                      │
└────────────────────────────────────────────┘
```

---

## 🔍 EDGE CASE CHECKLIST

```
For EVERY LL problem, always handle:

□ Empty list (head == NULL)
  Fix: if(!head) return ...

□ Single node (head->next == NULL)
  Fix: if(!head->next) return head

□ Two nodes (testing single iteration)
  Fix: Test manually with simple example

□ Deleting head node
  Fix: Use dummy node or return new head

□ Infinite loop risk (cycle)
  Fix: Check fast && fast->next in condition

□ Out of bounds access
  Fix: NULL check before every pointer access

□ Memory leaks
  Fix: Every new → delete pair
```

---


Good luck! 🌟

