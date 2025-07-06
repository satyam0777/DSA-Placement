##  Linked List Pattern Tree 

---

### 🔹 Parent Pattern: Reverse a Linked List

####  Core Idea:
Rewire `.next` pointers to reverse the list in-place.

---

###  Reverse-Based Child Patterns (All at One Place)

Here are all the important patterns derived from the Reverse Linked List parent pattern — grouped and explained so you can **instantly connect** when they appear in coding interviews.

---

### 1️⃣ Palindrome Linked List

> ✅ Reverse second half and compare with first half.

**Use Case:** Check if linked list reads same forward and backward.

 **Pattern Flow:**
- Find middle (slow-fast)
- Reverse second half
- Compare halves
- ✅ Restore (optional, clean)

✅ Often used in interviews to test multi-step reasoning.

---

### 2️⃣ Reverse in K-Groups

> ✅ Reverse every k nodes of the list. Example:  
> `1→2→3→4→5, k=2 → 2→1→4→3→5`

**Use Case:** Reverse nodes in chunks of k.

 **Pattern Flow:**
- Traverse k nodes
- Reverse k group using iterative logic
- Use dummy node and `prevTail`, `currHead`, `nextGroup`

✅ Asked frequently in medium/hard problems.

---

### 3️⃣ Reverse Second Half

> ✅ Just reverse second half starting from mid (helper for reorder/palindrome).

**Use Case:** Used as a step in problems like reorder, check palindrome, zigzag, etc.

 **Pattern Flow:**
- Find mid
- Reverse from mid onward

✅ Simplest sub-pattern. Use when only tail needs reversing.

---

### 4️⃣ Reverse a Sublist (m to n)

> ✅ Reverse a portion of the list between positions m and n.

**Use Case:** Reverse part of a list. Very common.

 **Pattern Flow:**
- Traverse till `m`
- Reverse till `n`
- Reconnect m-1 to n and m to n+1

✅ Needs careful pointer handling.

---

### 5️⃣ Reorder List (L0→Ln→L1→Ln−1→...)

> ✅ Rearrange list into specific first-last alternating order.

**Use Case:** Modify list in-place for pattern rearrangement.

 **Pattern Flow:**
- Find mid
- Reverse second half
- Merge two halves alternately

✅ Combines reverse + merge alternating.

---

### 6️⃣ Merge Two Halves Alternately

> ✅ Merge reversed half with first half in zig-zag order.

**Use Case:** Used in reorder or alternating list tasks.

**Pattern Flow:**
- Interleave one node from each half

✅ Helper logic — enhances main pattern like reorder.

---

### 7️⃣ Restore List After Modification

> ✅ After temporary modification (like palindrome check), restore list.

**Use Case:** Interviewers test clean thinking.

 **Pattern Flow:**
- Reverse back the changed portion
- Reconnect appropriately

✅ Optional but professional step in interviews.

---

This cheat-sheet block lets you **recognize and apply reverse-based problems instantly.**

Want to expand this with:
- `Reverse Alternate Nodes`
- `Reverse Even/Odd Indexed Nodes`
- `Recursion-based Reverse`
