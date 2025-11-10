# 💪 MUSCLE-MEMORY: LINKED LIST EDITION
## One-Page Printable + Daily 15-Minute Drill

---

## ⚡ 3-SECOND RECOGNITION CHECKLIST

```
Q1: "middle" / "split"?              → TWO-POINTER SLOW-FAST
Q2: "cycle" / "loop"?                → FLOYD'S ALGORITHM
Q3: "nth from end" / "kth"?          → GAP TECHNIQUE
Q4: "reverse" / "backward"?          → THREE-POINTER
Q5: "palindrome"?                    → REVERSE + TWO-POINTER
Q6: "intersection" / "merge"?        → POINTER SYNC / DUMMY NODE
Q7: "insert/delete"?                 → TRACK PREV + CURR + DUMMY
```

**Master this in 30 seconds → Identify any LL problem instantly!**

---

## 🎯 7 GOLDEN TEMPLATES (Copy-Paste Ready)

### TEMPLATE 1: FIND MIDDLE (Slow-Fast)
```cpp
Node* findMiddle(Node* head) {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// Mantra: "Slow 1 step, fast 2 steps → slow is middle"
// Time: O(n), Space: O(1)
```

### TEMPLATE 2: DETECT CYCLE (Floyd's)
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
// Mantra: "They meet → cycle, fast reaches NULL → no cycle"
// Time: O(n), Space: O(1)
```

### TEMPLATE 3: REVERSE (Three-Pointer)
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
// Mantra: "Save next, reverse link, move all forward"
// Time: O(n), Space: O(1)
```

### TEMPLATE 4: NTH FROM END (Gap)
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
// Mantra: "Gap n, then move together → nth from end"
// Time: O(n), Space: O(1)
```

### TEMPLATE 5: PALINDROME (Middle + Reverse + Compare)
```cpp
bool isPalindrome(Node* head) {
    if(!head || !head->next) return true;
    
    // Find middle
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node *prev = NULL, *curr = slow;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Compare
    while(prev) {
        if(head->data != prev->data) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
}
// Mantra: "Find mid, reverse second, compare halves"
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
// Mantra: "Dummy handles head deletion, prev->next = curr->next"
// Time: O(n), Space: O(1)
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
// Mantra: "Check k available, reverse group, reconnect, next group"
// Time: O(n), Space: O(1)
```

---

## 🗺️ PATTERN DECISION TREE

```
          START: LL Problem Encountered
                    ↓
        ┌─────────────┴──────────────┐
        │                            │
    "middle"?              Does problem mention
    OR                    "find", "locate", "point"?
    "split"?         ──→  NO: Go to Tree B
    ↓
    YES: SLOW-FAST TWO-POINTER
         (Find Middle, Cycle, Kth)
         
Tree B: "cycle" or "loop"?
    ↓
    YES: FLOYD'S CYCLE DETECTION
         (Detect, Find Start, Length)
    NO: Go to Tree C
    
Tree C: "reverse", "backward", "undo"?
    ↓
    YES: THREE-POINTER REVERSAL
         (Reverse, Reverse K-Groups, Between M-N)
    NO: Go to Tree D
    
Tree D: "palindrome", "mirror", "symmetric"?
    ↓
    YES: REVERSE + TWO-POINTER COMBINED
         (Find Mid → Reverse Second → Compare)
    NO: Go to Tree E
    
Tree E: "insert", "delete", "modify"?
    ↓
    YES: USE DUMMY NODE + TRACK PREV-CURR
         (Head-safe deletion, position insert)
    NO: Go to Tree F
    
Tree F: "intersection", "merge", "combine"?
    ↓
    YES: POINTER SYNC OR MERGE
         (Find intersection, merge sorted)
    NO: Probably basic traversal/search
```

---

## 💡 TOP 10 MUST-KNOW PROBLEMS

1. **Reverse List** → Template 3
2. **Detect Cycle** → Template 2
3. **Find Middle** → Template 1
4. **Palindrome Check** → Template 5
5. **Delete Nth from End** → Template 4
6. **Remove Node** → Template 6
7. **Reverse K-Groups** → Template 7
8. **Find Cycle Start** → Floyd's + Position
9. **Merge Sorted Lists** → Compare + Attach
10. **Intersection of Two** → Pointer Sync

---

## 📢 COMMUNICATION SCRIPTS (Memorize These!)

### When You See "Middle"
> "Sir, slow-fast pointers. Slow moves 1, fast moves 2. When fast ends, slow is middle. O(n) time, O(1) space."

### When You See "Cycle"
> "Sir, Floyd's algorithm. If cycle exists, slow and fast will meet. If no cycle, fast reaches NULL. O(n) time, O(1) space."

### When You See "Reverse"
> "Sir, three-pointer approach: prev, curr, next. Save next, reverse link, move pointers forward. O(n) time, O(1) space."

### When You See "Palindrome"
> "Sir, find middle using slow-fast, reverse second half, compare halves. Three-step O(n) time, O(1) space solution."

### When You See "Nth from End"
> "Sir, gap technique. Create gap of n between pointers, then move both together. When fast ends, slow is at nth from end."

---

## ⚠️ CORE MANTRAS (Recite 10x Daily)

```
1. "NULL check first!" 
   Before ANY pointer operation: if(!curr) return;

2. "Save next pointer!"
   Before: curr->next = prev, always do: next = curr->next

3. "Use dummy for head changes!"
   Deleting head? Use dummy node for O(1) logic

4. "Two pointers save space!"
   Slow-fast, gap, pointer sync → O(1) extra space

5. "Reverse = 3 pointers!"
   prev, curr, next → complete reversal

6. "Compare references, not values!"
   For intersection: a == b (address), not a->data == b->data

7. "Slow-fast meet in cycle!"
   Cycle exists → they meet inside, no cycle → fast exits first

8. "Middle + Reverse = Palindrome!"
   Find fold, flip second, compare → palindrome check

9. "Dummy node = Head safety!"
   Dummy->next = head, always have prev, delete head becomes normal

10. "One pass, no revisit!"
    LL problems should be single/double pass, not O(n²)
```

---

## 🎯 MEMORY HOOKS (Visualize These!)

### Hook 1: Train Cars (Reversal)
```
Before: 🚂→🚃→🚄→🛤  (Cars connected forward)
After:  🛤←🚄←🚃←🚂  (All couplings reversed)

When coupling link from next to prev, all cars flip direction!
```

### Hook 2: Circular Track (Cycle)
```
     ╔═══════╗
     ║       ║
     🏃 🏃 🏃  ← Two runners at different speeds
     ║ ↙   ║
     ╚═════╝
     
If track is circular, they MUST meet!
If track ends, faster one exits first!
```

### Hook 3: Mirror Reflection (Palindrome)
```
Original:    1 → 2 → 3 → 2 → 1
             ↑ ↑       ↑ ↑ ↑
Reflection:  1 2       1 2 1 ← (after reverse)
             ✓ ✓       ✓ ✓ ✓

Mirror check: all positions match → palindrome!
```

### Hook 4: Two Runners Gap (Kth from End)
```
Position:  0   1   2   3   4

Runners:   🏃slow ........ 🏃fast (gap of k=3)
           ↓              ↓
List:      1 → 2 → 3 → 4 → 5

Both move together:
Runners:           🏃slow ... 🏃fast
                   ↓         ↓
List:      1 → 2 → 3 → 4 → 5

When fast ends, slow is at kth from end!
```

### Hook 5: Warehouse Manager (Dummy Node)
```
Before deletion:  dummy → 1 → 2 → 3
                    ↑
                  Manager

Delete head (1):  dummy → 2 → 3
                    ↑
                  Manager still here!

Why dummy works:
- Always have a prev node (manager)
- Deleting head becomes normal node deletion
```

---

## 🏋️ DAILY 15-MINUTE DRILL

### Minute 1-2: Pattern Recognition
```
Read problem: "Remove nth node from end"
Answer: "Gap technique two-pointer?"
        ✓ Correct!
        
Read problem: "Check if linked list is palindrome"
Answer: "Reverse + two-pointer combined?"
        ✓ Correct!
```

### Minute 3-5: Template Recall
```
Write Template 3 (Reverse) from memory:
- Three pointers: prev, curr, next
- Save next, reverse link, move all forward
- Return prev as new head
Time: O(n), Space: O(1)
```

### Minute 6-8: Dry Run
```
List: 1 → 2 → 3
Reverse:
Step 1: prev=NULL, curr=1, next=NULL
Step 2: next=2, 1->next=NULL, prev=1, curr=2
Step 3: next=3, 2->next=1, prev=2, curr=3
Step 4: 3->next=2, prev=3, curr=NULL
Result: 3 → 2 → 1 ✓
```

### Minute 9-12: Edge Case Thinking
```
Template 1 (Find Middle) edge cases:
- Empty list? (handled by condition check)
- Single node? (returns head correctly)
- Two nodes? (returns second node correctly)
- Even nodes? (returns first middle)
- Odd nodes? (returns exact middle)
All ✓
```

### Minute 13-15: Complexity Recitation
```
Template 1: O(n) time, O(1) space
Template 2: O(n) time, O(1) space
Template 3: O(n) time, O(1) space
Template 4: O(n) time, O(1) space
Template 5: O(n) time, O(1) space
Template 6: O(n) time, O(1) space
Template 7: O(n) time, O(1) space

All linked list patterns = O(1) space! (Key insight)
```

---

## 📅 7-DAY REVISION PLAN

### Day 1: Templates 1 & 2 (Two-Pointer Basics)
```
Monday:
- Morning: Memorize Template 1 (Find Middle)
- Noon: Solve 3 middle-finding variations
- Evening: Memorize Template 2 (Floyd's)
- Night: Solve 3 cycle-detection variations
Target: Automatic recall in 10 seconds each
```

### Day 2: Templates 3 & 4 (Reversal & Gap)
```
Tuesday:
- Morning: Memorize Template 3 (Reverse) + dry run
- Noon: Solve 3 reversal variations (partial, kth group, etc.)
- Evening: Memorize Template 4 (Nth from End)
- Night: Solve 3 gap-technique variations
Target: Write both templates without looking
```

### Day 3: Templates 5 & 6 (Combined & Dummy)
```
Wednesday:
- Morning: Memorize Template 5 (Palindrome) - 3 step process
- Noon: Solve 3 palindrome variations + reorder
- Evening: Memorize Template 6 (Delete with Dummy)
- Night: Solve 3 deletion variations
Target: Understand WHY dummy node works
```

### Day 4: Template 7 (K-Groups Advanced)
```
Thursday:
- Morning: Understand Template 7 logic deeply
- Noon: Draw boxes for k-group reversal manually
- Evening: Code Template 7 from memory with notes
- Night: Solve 2 k-group variations
Target: Complex logic mastered, not just memorized
```

### Day 5: Mixed Problems (Combine Patterns)
```
Friday:
- Morning: LeetCode 3-problem marathon (mixed patterns)
- Noon: Implement all 7 templates in single file
- Evening: Create cheat-sheet for YOUR weaknesses
- Night: Solve 2 hard problems
Target: Confident pattern recognition in real problems
```

### Day 6: Interview Simulations
```
Saturday:
- Morning: Record yourself explaining each template
- Noon: Mock interview 1 (45 min, 2 problems)
- Evening: Review mistakes from mock 1
- Night: Mock interview 2 (45 min, harder 2 problems)
Target: Communication + Code speed + Accuracy
```

### Day 7: Final Polish
```
Sunday:
- Morning: Quick review of weak templates
- Noon: Solve company-specific past problems
- Evening: Review common mistakes document
- Night: Rest, confidence check, ready for interview!
Target: Feel 100% prepared for LL questions
```

---

## 📊 COMPLEXITY REFERENCE TABLE

| Pattern | Problem | Time | Space | Notes |
|---------|---------|------|-------|-------|
| Two-Pointer | Find Middle | O(n) | O(1) | Slow-fast |
| Two-Pointer | Detect Cycle | O(n) | O(1) | Floyd's algo |
| Two-Pointer | Nth from End | O(n) | O(1) | Gap technique |
| Reversal | Reverse List | O(n) | O(1) | 3 pointers |
| Reversal | Palindrome | O(n) | O(1) | Mid+Rev+Cmp |
| Combined | Reorder | O(n) | O(1) | Mid+Rev+Merge |
| Dummy Node | Delete | O(n) | O(1) | Safe deletion |
| K-Groups | Reverse K | O(n) | O(1) | Group reversal |

**Key Pattern:** ALL good LL solutions use **O(1) space**! (Pointer tricks, not arrays)

---

## 🎤 INTERVIEW DAY CHECKLIST

```
□ Clarifying Questions Asked?
  - "Can list have cycle?"
  - "What if empty?"
  - "What if single node?"

□ Approach Explained?
  - Drew diagram
  - Explained pattern
  - Mentioned time/space

□ Code Quality?
  - NULL checks before each access
  - Dummy node if head modification
  - Saved next before modifying link

□ Dry Run Done?
  - Traced with actual example
  - Showed pointer movements
  - Verified output

□ Complexity Mentioned?
  - Time complexity stated
  - Space complexity stated
  - Optimality discussed

□ Edge Cases Handled?
  - Empty list
  - Single node
  - Head deletion
  - Boundary conditions

□ Communication Throughout?
  - Explained, didn't just code
  - Asked feedback
  - Stayed confident
```

---

## 🚀 LAST-MINUTE TIPS (5 Minutes Before Interview)

```
1. Breathe. You know this.

2. Read problem carefully. Look for magic keywords:
   - "middle" → slow-fast
   - "cycle" → Floyd's
   - "nth from end" → gap
   - "reverse" → 3 pointers

3. Ask clarifying questions. Shows you think.

4. Explain approach before coding. Saves you time.

5. Use dummy node for ANY head modification. Safe.

6. Draw diagrams. Helps you AND interviewer.

7. NULL check everything. Crashes cost you hard.

8. Save next pointer before modifying link. Critical.

9. Mention O(1) space. Shows deep LL understanding.

10. Smile and be confident. You've mastered this.
```

---

## 🎯 FINAL CHECKLIST: ARE YOU READY?

```
✅ Can you identify patterns in 3 seconds?
✅ Can you write all 7 templates from memory?
✅ Can you do dry runs without looking at code?
✅ Can you explain why dummy node works?
✅ Can you handle all edge cases automatically?
✅ Do you understand time/space complexity deeply?
✅ Can you explain to someone else?
✅ Have you solved 10+ problems each pattern?
✅ Can you code 80% problem in interview time?
✅ Are you confident and calm?
```

**If ALL YES → You're interview-ready! 🚀**

---

## 💪 YOUR MANTRA (Say Before Interview)

```
"I know linked lists.
I know two pointers.
I know reversals.
I know patterns.

I can identify any problem in 3 seconds.
I can code any solution in 5 minutes.
I can explain complex pointer logic simply.

I am confident. I am prepared. I will crush this!"

🚀 NOW GO WIN! 🚀
```

---

**Remember:** Linked List mastery = Pattern Recognition + Templates + Practice

You've got this! 💪

