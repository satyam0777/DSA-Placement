# 🎯 TREE TRAVERSALS - QUICK REFERENCE

## ⚡ 4 MUST-KNOW TRAVERSALS

### 1️⃣ PREORDER (Root → Left → Right)
```cpp
// Recursive
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Iterative
void preorderIter(Node* root) {
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        cout << curr->data << " ";
        if (curr->right) st.push(curr->right);  // Right first (reversed)
        if (curr->left) st.push(curr->left);
    }
}
```
**Use:** Copy tree, serialize, detect cycles
**Company:** TCS 75%, Infosys 85%, Wipro 70%

---

### 2️⃣ INORDER (Left → Root → Right)
```cpp
// Recursive
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Iterative (Morris/Stack)
void inorderIter(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr || !st.empty()) {
        while (curr) { st.push(curr); curr = curr->left; }
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
```
**Use:** BST gives SORTED ⭐, validate BST, convert to DLL
**Company:** TCS 80%, Infosys 90%, Wipro 75%

---

### 3️⃣ POSTORDER (Left → Right → Root)
```cpp
// Recursive
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Iterative (2 Stacks)
void postorderIter(Node* root) {
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* curr = st1.top(); st1.pop();
        st2.push(curr);
        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}
```
**Use:** Delete tree (process children first), level-wise operations
**Company:** TCS 65%, Infosys 75%, Wipro 65%

---

### 4️⃣ LEVEL ORDER (BFS)
```cpp
// Recursive with queue
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();  // ⭐ KEY: Size before loop
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
}

// Level-by-level output
void levelOrderByLevel(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front(); q.pop();
            level.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        // Process level
    }
}
```
**Use:** Tree by levels, tree views, check complete
**Company:** TCS 70%, Infosys 85%, Wipro 75%

---

## 🎯 COMPARISON QUICK TABLE

| Traversal | Order | Use Case | Space |
|-----------|-------|----------|-------|
| **Preorder** | R-L-R | Copy tree | O(h) |
| **Inorder** | L-R-R | BST sorted | O(h) |
| **Postorder** | L-R-R | Delete | O(h) |
| **Level** | Level by level | Views | O(w) |

---

## 💡 INTERVIEW SCRIPTS

### Q: "Explain Preorder Traversal"

> "Sir, preorder means Root-Left-Right.
>
> I process root first, then left subtree, then right subtree.
>
> Use case: Copying a tree because you process node before children.
>
> Time: O(n), Space: O(h) for recursion or stack."

### Q: "Difference between Inorder and Preorder?"

> "Sir, main difference:
>
> **Inorder:** Left-Root-Right
> - For BST, gives sorted order ⭐
> - Used to validate BST
>
> **Preorder:** Root-Left-Right  
> - Root processed first
> - Used to copy tree
>
> Both are O(n) time, O(h) space."

### Q: "Why Level Order uses BFS not DFS?"

> "Sir, level order naturally means processing level by level.
>
> BFS (queue) naturally processes level-by-level.
>
> DFS (stack) would process depth-first, losing level structure.
>
> That's why we use queue for level order."

---

## ⚠️ COMMON MISTAKES

```cpp
❌ WRONG: Recursive without base case
void preorder(Node* root) {
    cout << root->data << " ";  // CRASH if nullptr!
    preorder(root->left);
}

✅ RIGHT: Check nullptr first
void preorder(Node* root) {
    if (!root) return;  // BASE CASE
    cout << root->data << " ";
    preorder(root->left);
}
```

```cpp
❌ WRONG: Preorder iterative pushes left first
st.push(root->left);
st.push(root->right);  // Wrong order!

✅ RIGHT: Push right first (reversed)
st.push(root->right);
st.push(root->left);  // Right on top of stack
```

```cpp
❌ WRONG: Forgetting to capture level size in level order
while (!q.empty()) {
    Node* curr = q.front(); q.pop();
    // Size changes as we push!
}

✅ RIGHT: Capture size BEFORE processing
while (!q.empty()) {
    int sz = q.size();  // Capture first
    for (int i = 0; i < sz; i++) {
        // Now process exactly 'sz' nodes
    }
}
```

---

## 📋 COMPANY-WISE FOCUS

### TCS (All 4 Important)
```
Preorder: 75% ⭐⭐
Inorder: 80% ⭐⭐⭐
Postorder: 65% ⭐⭐
Level Order: 70% ⭐⭐
```
**Focus:** Must know all 4

### Infosys (Depth Focus)
```
Preorder: 85% ⭐⭐⭐
Inorder: 90% ⭐⭐⭐
Postorder: 75% ⭐⭐⭐
Level Order: 85% ⭐⭐⭐
```
**Focus:** Heavy on Inorder and Postorder

### Wipro (Balanced)
```
Preorder: 70% ⭐⭐
Inorder: 75% ⭐⭐⭐
Postorder: 65% ⭐⭐
Level Order: 75% ⭐⭐⭐
```
**Focus:** Inorder + Level Order critical

---

## 🔥 MEMORY AIDS

### Order Pattern
```
Pre    = Root  FIRST (Pre-process)
In     = Root  MIDDLE (In-between)
Post   = Root  LAST (Post-process)
Level  = Queue (BFS)
```

### Stack Push Order (Preorder)
```
      ROOT
     /    \
    L      R

Push: R first, then L
Stack: [L, R] → Pop R first

Why? Stack is LIFO (Last In First Out)
```

### Level Order Key
```
❌ while (!q.empty()) {
     push children
     pop current
   }

✅ while (!q.empty()) {
     sz = q.size()  ← CAPTURE BEFORE
     for (sz times) {
       pop current
       push children
     }
   }
```

---

## ✅ FINAL CHECKLIST

```
Recursive Traversals:
☐ Preorder - can code blind
☐ Inorder - can code blind
☐ Postorder - can code blind
☐ All have same structure: if(!root) return

Iterative Traversals:
☐ Preorder iterative with stack
☐ Inorder iterative with stack
☐ Postorder iterative with 2 stacks
☐ Level order with queue

Knowledge:
☐ Know use cases for each
☐ Know company frequencies
☐ Understand why order matters
☐ Can explain to interviewer
☐ Can handle edge cases (single node, empty)
```

---

## 🎯 STUDY TIPS

1. **Always code recursive first** - simpler logic
2. **Iterative uses stack/queue** - maintain state manually
3. **Level order = BFS, others = DFS**
4. **Inorder of BST = SORTED** - Remember this!
5. **Print output at different stages:**
   - Preorder: Before recursing
   - Inorder: Between recursions
   - Postorder: After recursing

---

## 💪 IN INTERVIEW

**Before coding:**
- "I'll start with recursive version"
- "Then I can code iterative if needed"

**While coding:**
1. Write base case first (`if (!root) return;`)
2. Process node (print/store)
3. Recurse left and right
4. Explain as you code

**For iterative:**
1. Initialize stack/queue with root
2. Process while not empty
3. Explain push order (important for preorder!)

---

**Master these 4 and you've mastered 60% of Tree problems!** 🌳✅

**Time to memorize:** 30 minutes
**Time to master:** 2-3 hours

**Go code some traversals!** 💪
