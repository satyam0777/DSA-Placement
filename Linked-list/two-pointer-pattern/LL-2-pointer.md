##  Two-Pointer Based Linked List Patterns 

---

###  **Parent Concept**: Two-Pointer Technique

* **Core Idea:** Use two pointers (typically `slow` and `fast`) to solve problems in a single traversal with minimal space.
* **Common Movement:**

  * `slow = slow->next`
  * `fast = fast->next->next`

---

##  Patterns Derived from Two-Pointer Logic

### 1️⃣ Detect Loop in a Linked List  

* **Concept:** If there's a cycle, `slow` and `fast` will eventually meet.
* **Logic:**

  ```cpp
  while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true; // loop exists
  }
  return false;
  ```
* **Pattern Role:** Detects presence of a cycle
* **Time:** O(n), **Space:** O(1)

---

### 2️⃣ Find Starting Point of Loop  

* **Concept:** After detection, reset `slow` to head and move both one step until they meet again.
* **Logic:**

  ```cpp
  // After detection
  slow = head;
  while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
  }
  return slow; // starting node of loop
  ```
* **Pattern Role:** Pinpoints entry node of the loop

---

### 3️⃣ Intersection of Two Linked Lists  

* **Concept:** Use pointer sync trick. When one pointer reaches end, redirect to other list.
* **Logic:**

  ```cpp
  while (a != b) {
      a = a ? a->next : headB;
      b = b ? b->next : headA;
  }
  return a; // or b
  ```
* **Pattern Role:** Detect shared node by reference (not value)
* **Time:** O(m+n), **Space:** O(1)

---

### 4️⃣ Find If Length is Even or Odd 

* **Concept:** Use `fast` pointer. If it ends on `NULL`, even. If on `fast->next == NULL`, odd.
* **Logic:**

  ```cpp
  while (fast && fast->next) {
      fast = fast->next->next;
  }
  return (fast == NULL); // true = even, false = odd
  ```
* **Pattern Role:** Detect length parity

---

### 5️⃣ Palindrome Linked List (Reverse-Based + Two Pointer) 

* **Concept:** Use two-pointer to find mid, reverse second half, compare halves

* **Logic Flow:**

  * Find mid via `slow/fast`
  * Reverse second half
  * Compare first and reversed second
  * Optional: Restore the list

* **Pattern Role:** Combines reverse + two-pointer

* **Key Use:** Real interview pattern (multi-step reasoning)

---

## ✅ Summary Table

| # | Problem                   | Parent Pattern   | Concept/Use                     |
| - | ------------------------- | ---------------- | ------------------------------- |
| 1 | Detect Loop               | Two Pointer      | Fast meets slow in cycle        |
| 2 | Find Start of Loop        | Two Pointer      | Reset slow, meet again          |
| 3 | Intersection of Two Lists | Two Pointer      | Sync walk via pointer switching |
| 4 | Even or Odd Length        | Two Pointer      | Check final position of fast    |
| 5 | Palindrome Linked List    | Reverse + TwoPtr | Reverse half + compare          |

---


