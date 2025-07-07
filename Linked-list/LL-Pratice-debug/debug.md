#  Linked List Practice Problems by Pattern (With Dry Runs)

This file provides **practice questions** grouped by Linked List patterns.  
Each question includes:
-  Thinking Steps
-  Hints
-  Dry-run walkthroughs 

---

##  1. Reverse Linked List Pattern

### ✅Problem 1: Reverse a Linked List
**Input:** `1 -> 2 -> 3 -> 4 -> NULL`
**LeetCode 206 / Amazon / Microsoft**

###  Idea:
Use 3 pointers — `prev`, `curr`, `next`

###  Step-by-step:
1. `prev = NULL`, `curr = head`
2. Jab tak `curr != NULL`, tab tak:
   - `next = curr->next`
   - `curr->next = prev`
   - `prev = curr`
   - `curr = next`
3. Return `prev`

###  Dry Run:
```
Initial:
curr = 1
prev = NULL

Loop:
1 -> 2 -> 3 -> 4 -> NULL
Step 1: next = 2, curr->next = NULL, prev = 1, curr = 2
Step 2: next = 3, curr->next = 1, prev = 2, curr = 3
...
Final: 4 -> 3 -> 2 -> 1 -> NULL
```

---

##  2. Cycle Detection Pattern

###  Problem 2: Detect a cycle in LL
**LeetCode 141 / Flipkart / Accenture**

###  Idea:
Use Floyd's Cycle detection (slow-fast pointer)

###  Thinking:
- Slow ek step chalega, fast do(2)
- Agar kahin mil gaye → cycle hai

###  Dry Run:
```
1 -> 2 -> 3 -> 4 -> 2 (back to 2)
slow = 1, fast = 1
Loop:
slow = 2, fast = 3
slow = 3, fast = 2
slow = 4, fast = 4 (same = cycle)
```

---

##  3. Intersection Point Pattern

###  Problem 3: Find Intersection of Two LLs
**LeetCode 160 / Google / Adobe**

###  Idea:
Align both lists based on length

###  Steps:
1. Find length of both LLs
2. Move longer list’s pointer ahead by diff
3. Traverse both together until `a == b`

###  Dry Run:
```
A: 1 -> 2 -> 3 -> 4 -> 5
B:       9 -> 4 -> 5
length A = 5, B = 3
Move A ahead 2 times → then both same speed
Match found at 4
```

---

##  4. Middle Element Pattern

###  Problem 4: Find middle of LL
**LeetCode 876 / TCS / Wipro**

###  Idea:
Slow-fast pointer

###  Steps:
- Slow moves 1, fast moves 2
- Jab fast NULL ya last node ho → slow = middle

###  Dry Run:
```
1 -> 2 -> 3 -> 4 -> 5
slow = 1, fast = 1
slow = 2, fast = 3
slow = 3, fast = 5
Answer = 3
```

---

##  5. Palindrome Pattern

###  Problem 5: Check if LL is Palindrome
**LeetCode 234 / Amazon / Adobe**

###  Idea:
- Find middle
- Reverse second half
- Compare both halves

###  Steps:
1. middle nikalo
2. second half reverse karo
3. dono ko compare karo

###  Dry Run:
```
1 -> 2 -> 2 -> 1
middle = 2
Second half = 1 -> 2
Compare:
1 vs 1, 2 vs 2 → palindrome
```

---

##  6. Clone with Random Pointer

###  Problem 6: Clone LL with random pointer
**LeetCode 138 / Amazon / Facebook**

###  Idea:
1. Interleave clone nodes
2. Fix random pointers
3. Separate the lists

###  Steps:
- original->next = clone
- clone->random = original->random->next

###  Dry Run:
```
A: 1 -> 2 -> 3 (random points randomly)
Make clone nodes: 1->1'->2->2'->3->3'
Fix random:
clone->random = original->random->next
Split: 1->2->3, 1'->2'->3'
```

---

##  7. Merge / Flatten / Sort Pattern

###  Problem 7: Merge two sorted LLs
**LeetCode 21 / Oracle / Microsoft**

###  Idea:
Use dummy node + tail pointer

###  Steps:
- Compare current nodes
- Append smaller one to tail
- Advance the pointer

###  Dry Run:
```
L1: 1 -> 3 -> 5
L2: 2 -> 4 -> 6
Result: 1->2->3->4->5->6
```

---

##  8. kth Node Pattern

###  Problem 8: Find kth node from end
**LeetCode 19 / Flipkart / Infosys**

###  Idea:
Use two pointers, k distance apart

###  Steps:
1. fast = k steps ahead
2. slow & fast move together
3. when fast == NULL → slow at kth from end

###  Dry Run:
```
k = 2
1 -> 2 -> 3 -> 4 -> 5
fast = 1→2
Now slow & fast move
Result = 4
```

---

