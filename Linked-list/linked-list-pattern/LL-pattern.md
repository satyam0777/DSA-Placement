#  Linked List Pattern Recognition + Thinking Steps .

---

##  1. Reverse Linked List Pattern

###  Common Problems:
- Reverse entire list
- Reverse between positions `m` and `n`
- Reverse in k-groups

###  Thinking Steps:
1. Can I use 3 pointers (prev, curr, next)?
2. Can I break problem into smaller sub-list reversals?
3. Do I need dummy node to handle head edge case?
4. If recursive — identify base case and self call on smaller list

### Pattern Trigger:
> "Reverse order, group or partial reversal mentioned?"

---

##  2. Cycle Detection Pattern

###  Common Problems:
- Detect if cycle exists
- Find start of the cycle
- Length of cycle

###  Thinking Steps:
1. Try slow-fast pointer (Floyd’s Cycle detection)
2. If they meet → cycle exists
3. To find starting node: put one pointer to head, then move both
4. To find length: measure steps after meeting until meet again

### Pattern Trigger:
> "Does list loop forever or need detection of repetition?"

---

##  3. Intersection Pattern

###  Common Problems:
- Find intersection of two LLs
- Merge sorted lists (partial intersection)

###  Thinking Steps:
1. Use length difference to align pointers
2. Traverse together to check reference equality
3. Don’t compare values, compare addresses

### Pattern Trigger:
> "Are two lists merging at a node?"

---

##  4. Middle of Linked List Pattern

###  Common Problems:
- Find middle node
- Split list into two halves
- Apply slow-fast technique

###  Thinking Steps:
1. Initialize both slow and fast at head
2. Move fast by 2 and slow by 1
3. Stop when fast == NULL or fast->next == NULL

### Pattern Trigger:
> "Middle element or divide problem in halves"

---

##  5. Palindrome Pattern

###  Common Problems:
- Is list a palindrome?
- Compare first and second half

###  Thinking Steps:
1. Find middle using slow-fast
2. Reverse second half
3. Compare values from both sides
4. Optional: restore original list

### Pattern Trigger:
> "Check symmetry, mirror, same forward/backward"

---

##  6. Clone with Random Pointer Pattern

### 🔍 Common Problems:
- Clone LL with next and random pointers

###  Thinking Steps:
1. Interleave cloned nodes beside originals
2. Assign random of clone = original->random->next
3. Detach clone list from original

### Pattern Trigger:
> "Clone list with complex pointer references"

---

## 7. Merge / Sort / Flatten Pattern

###  Common Problems:
- Merge two sorted lists
- Flatten multilevel linked list
- Sort list in O(n log n)

###  Thinking Steps:
1. Divide using slow-fast (for merge sort)
2. Use recursion to merge sorted sublists
3. Handle next/child/prev pointers carefully

### Pattern Trigger:
> "Combine or flatten multiple linked chains"

---

##  8. k-th Element / Node Pattern

###  Common Problems:
- Find kth from start or end
- Remove nth from end

###  Thinking Steps:
1. Use two pointers spaced k apart
2. When fast hits end, slow is at correct position
3. Handle `head` carefully for edge cases

### Pattern Trigger:
> "kth, nth, last or from-end mentioned"

---

##  9. Manipulation Pattern (Insert/Delete)

###  Common Problems:
- Insert at kth position
- Delete node without head

###  Thinking Steps:
1. Track previous + current nodes
2. For head insert/delete — use dummy node
3. To delete without head, copy next value and bypass next

### Pattern Trigger:
> "Insert/delete/move single node or perform surgery on list"

---

