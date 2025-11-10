# 🎯 BST OPERATIONS - QUICK REFERENCE

## ⚡ TOP 5 MUST CODE

### 1️⃣ VALIDATE BST
```cpp
bool isValidBST(Node* root, long minVal = LLONG_MIN, long maxVal = LLONG_MAX) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}
```
**Key:** Use min/max bounds, not just immediate children

---

### 2️⃣ INSERT INTO BST
```cpp
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}
```
**Logic:** Left if smaller, right if larger

---

### 3️⃣ SEARCH IN BST
```cpp
Node* search(Node* root, int value) {
    if (!root) return nullptr;
    if (value == root->data) return root;
    return value < root->data ? search(root->left, value) : search(root->right, value);
}
```
**Time:** O(log n) average, O(n) worst (skewed)

---

### 4️⃣ DELETE FROM BST
```cpp
Node* deleteNode(Node* root, int value) {
    if (!root) return nullptr;
    
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        // Node found - 3 cases:
        if (!root->left && !root->right) return nullptr;  // Case 1: Leaf
        if (!root->left) return root->right;  // Case 2: Right only
        if (!root->right) return root->left;  // Case 2: Left only
        
        // Case 3: Two children - find inorder successor
        Node* temp = root->right;
        while (temp->left) temp = temp->left;  // Smallest in right
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
```
**Tricky Part:** Two children case - use inorder successor

---

### 5️⃣ KTH SMALLEST
```cpp
int kthSmallest(Node* root, int k) {
    int count = 0, result = -1;
    function<void(Node*)> inorder = [&](Node* node) {
        if (!node || count >= k) return;
        inorder(node->left);
        if (++count == k) result = node->data;
        inorder(node->right);
    };
    inorder(root);
    return result;
}
```
**Magic:** Inorder of BST = Sorted array ⭐

---

## 🔥 NEXT 5

| Operation | Template | Company |
|-----------|----------|---------|
| **Kth Largest** | Reverse inorder (R-Root-L) | Infosys |
| **Floor** | Go left when > target | Infosys |
| **Ceiling** | Go right when < target | TCS |
| **Successor** | Smallest in right subtree | Wipro |
| **LCA in BST** | Use BST property (O(log n)) | All |

---

## 💡 INTERVIEW SCRIPTS

### Q: "How will you validate BST?"

> "Sir, I use the bounds approach. I track min and max values.
> 
> At each node, I check if current value is within [min, max].
> - For left subtree, max becomes current value
> - For right subtree, min becomes current value
> 
> This ensures ALL left < current < ALL right.
> Time: O(n), Space: O(h)"

### Q: "Delete a node with two children?"

> "Sir, I find the inorder successor (smallest node in right subtree).
> 
> I copy the successor's value to current node.
> 
> Then I delete the successor from right subtree.
> 
> This maintains BST property."

### Q: "Find Kth smallest efficiently?"

> "Sir, inorder traversal of BST gives sorted array!
> 
> I do inorder and count. When count reaches k, I have answer.
> 
> Time: O(n) worst, but O(k) if k is small.
> Space: O(h) for recursion."

---

## ⚠️ CRITICAL MISTAKES

```cpp
❌ WRONG: Checking only immediate children for validation
bool isValidBST(Node* root) {
    if (root->left && root->left->data > root->data) return false;
    // This misses violations in subtrees!
}

✅ RIGHT: Use min/max bounds
bool isValidBST(Node* root, long minVal, long maxVal) {
    if (root->data <= minVal || root->data >= maxVal) return false;
    // Correct bounds checking
}
```

```cpp
❌ WRONG: Not finding inorder successor correctly
Node* temp = root->right;
// Don't find successor, just take right child
root->data = temp->data;

✅ RIGHT: Find SMALLEST in right subtree
Node* temp = root->right;
while (temp->left) temp = temp->left;  // Go left until null
root->data = temp->data;
```

```cpp
❌ WRONG: Using < instead of <= for validation
if (root->data < minVal || root->data > maxVal) // Allows duplicates!

✅ RIGHT: Use <= and >= for uniqueness
if (root->data <= minVal || root->data >= maxVal) // No duplicates
```

---

## 📋 COMPANY-WISE CHECKLIST

### TCS (75% BST)
```
☐ Insert
☐ Search
☐ Validate
☐ Delete
☐ Kth Smallest
☐ Inorder = Sorted (KEY!)
```

### Infosys (85% BST)
```
☐ Everything from TCS
☐ Kth Largest (reverse inorder)
☐ Floor/Ceiling
☐ LCA in BST (using property)
☐ Successor/Predecessor
```

### Wipro (70% BST)
```
☐ Insert/Search
☐ Validate
☐ Delete (all 3 cases)
☐ Kth Smallest
☐ Successor/Predecessor
```

---

## 🎯 DELETION CASES MEMORY AID

```
       NODE_TO_DELETE

Case 1: ◯ (no children)     → DELETE
           
Case 2: ◯                   → REPLACE WITH CHILD
         └─◯
         
Case 3: ◯                   → REPLACE WITH SUCCESSOR
         ├─◯                  (smallest in right subtree)
         └─◯

Successor location:
        ◯─────────────────┐
                          ◯ (right child)
                          └─◯ (go left until null) ← SUCCESSOR
                            └─◯
```

---

## ⏱️ TIME COMPLEXITIES

| Operation | Average | Worst | Why Worst? |
|-----------|---------|-------|-----------|
| Insert | O(log n) | O(n) | Skewed tree |
| Search | O(log n) | O(n) | Skewed tree |
| Delete | O(log n) | O(n) | Skewed tree |
| Validate | O(n) | O(n) | Always visit all |
| Kth Smallest | O(n) | O(n) | Full traversal |

**Skewed tree = All nodes on one side (like linked list)**

---

## 🚀 INTERVIEW DAY TIPS

**Before coding:**
1. Clarify: Duplicates allowed?
2. Mention: "I'll use BST property for efficiency"
3. Explain approach: "I'll do inorder..." or "I'll use bounds..."

**While coding:**
1. Handle nullptr first (base case)
2. Write comparison logic clearly
3. Test on paper with dry run

**Common edge cases:**
- Single node tree
- Empty tree
- All nodes on left (skewed left)
- All nodes on right (skewed right)
- Duplicates present

---

## 📊 PATTERN DIFFICULTY

```
Easy (Can code blind):
  ├─ Insert
  ├─ Search
  ├─ Validate
  └─ Kth Smallest

Medium (Need thought):
  ├─ Delete (especially 2 children)
  ├─ Floor/Ceiling
  └─ Successor/Predecessor

Hard (Rare, study if time):
  ├─ Balanced BST
  ├─ AVL Trees
  └─ Red-Black Trees
```

---

## 💪 FINAL CHECKLIST

```
Core (MUST):
☐ Can validate BST with bounds
☐ Can insert new node
☐ Can search for node
☐ Can delete all 3 cases
☐ Understand inorder = sorted

Important:
☐ Can find Kth smallest
☐ Can find inorder successor
☐ Know why worst case is O(n)
☐ Can explain skewed tree

Nice to have:
☐ Floor/Ceiling
☐ Kth largest
☐ LCA in BST (optimized)
```

---

**Practice these 5 and you'll handle 85% BST questions!** 🌳✅
