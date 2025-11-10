# 🎯 TREE PATTERNS - QUICK REFERENCE

## ⚡ TOP 5 MUST CODE IN INTERVIEW

### 1️⃣ HEIGHT OF TREE
```cpp
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```
**Use:** Base for Diameter, Balanced, etc.

---

### 2️⃣ DIAMETER OF TREE
```cpp
int diameter(Node* root, int& maxDia) {
    if (!root) return 0;
    int lh = diameter(root->left, maxDia);
    int rh = diameter(root->right, maxDia);
    maxDia = max(maxDia, lh + rh);
    return 1 + max(lh, rh);
}
```
**Key:** Track max at each node = `left_height + right_height`

---

### 3️⃣ IS BALANCED
```cpp
bool isBalanced(Node* root) {
    if (!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
```
**Condition:** |left_height - right_height| ≤ 1 for ALL nodes

---

### 4️⃣ LCA (LOWEST COMMON ANCESTOR)
```cpp
Node* LCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data == n1 || root->data == n2) return root;
    
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    
    if (left && right) return root;
    return left ? left : right;
}
```
**Logic:** If both found in different subtrees → current is LCA

---

### 5️⃣ PATH SUM CHECK
```cpp
bool hasPathSum(Node* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->data == targetSum;
    return hasPathSum(root->left, targetSum - root->data) ||
           hasPathSum(root->right, targetSum - root->data);
}
```
**Key:** Reduce sum as you go down

---

## 🔥 NEXT 5 TO PRACTICE

| Pattern | Code Template | Company |
|---------|--------------|---------|
| **Mirror Tree** | `swap(left, right)` for each node | All |
| **Symmetric** | `isMirror(left->left, right->right)` | Infosys, Wipro |
| **Max Path Sum** | Track max, consider path through node | Infosys |
| **Flatten to LL** | `root->right = prev; root->left = null` | TCS, Infosys |
| **Zigzag Level Order** | Alternate direction each level | TCS, Wipro |

---

## 💡 INTERVIEW COMMUNICATION SCRIPTS

### Pattern Question: "How will you find diameter?"

> "Sir, I'll use postorder traversal. At each node, diameter could be:
> 1. Diameter in left subtree
> 2. Diameter in right subtree  
> 3. Path through this node (left_height + right_height)
>
> I'll track the maximum found. Time: O(n), Space: O(h)"

### Pattern Question: "Is tree balanced?"

> "Sir, I'll check for every node:
> |height(left) - height(right)| ≤ 1
>
> If this is violated at ANY node, tree is not balanced.
> Time: O(n), Space: O(h)"

### Pattern Question: "Find LCA of two nodes?"

> "Sir, I'll traverse the tree. If I find either node, I return it.
> 
> When both are found in different subtrees, the current node is LCA.
> 
> This works because LCA is the first common point from root."

---

## ⚠️ COMMON MISTAKES

```cpp
❌ Not handling nullptr
int height(Node* root) {
    return 1 + max(...);  // CRASH if root is null
}

✅ Handle nullptr first
int height(Node* root) {
    if (!root) return 0;  // BASE CASE
    return 1 + max(...);
}
```

```cpp
❌ Backtracking error in path printing
void print(Node* root, vector<int>& path) {
    path.push_back(root->data);
    // ... process ...
    // FORGOT to pop!
}

✅ Pop after recursion
void print(Node* root, vector<int>& path) {
    path.push_back(root->data);
    // ... process ...
    path.pop_back();  // ✓ MUST pop
}
```

---

## 📋 PATTERN CHECKLIST

Before interview, verify:

```
Traversals (Covered Separately):
☐ Can do all 4 traversals (preorder, inorder, postorder, level)

Patterns (This Section):
☐ Height - recursive, simple
☐ Diameter - track max at each node
☐ Balanced - check height difference ≤ 1
☐ LCA - find common node
☐ Path Sum - reduce target sum going down
☐ Mirror - swap children
☐ Symmetric - check if mirror of self
☐ Max Path Sum - handle negative values wisely
☐ Flatten - convert to linked list structure
☐ Zigzag - alternate direction per level

BST (Separate Section):
☐ Validate - use min/max bounds
☐ Insert - find correct position
☐ Delete - handle all 3 cases
☐ Kth Smallest - inorder traversal
☐ LCA in BST - use BST property
```

---

## 🎯 STUDY ORDER

**Day 1:** Traversals (4 traversals) - **ESSENTIAL**
**Day 2:** Height, Diameter, Balanced - **FOUNDATION**
**Day 3:** LCA, Path Sum - **CLASSIC PATTERNS**
**Day 4:** Mirror, Symmetric, Max Path - **MEDIUM**
**Day 5:** Flatten, Zigzag, Others - **ADVANCED**
**Day 6:** BST Operations - **DISTINCT TOPIC**

---

## ⏱️ TIME ESTIMATES

| Topic | Time | Difficulty |
|-------|------|-----------|
| Traversals | 3-4 hrs | ⭐ |
| Basic Patterns | 2-3 hrs | ⭐ |
| Intermediate | 2-3 hrs | ⭐⭐ |
| Advanced | 2-3 hrs | ⭐⭐ |
| BST | 3-4 hrs | ⭐⭐ |

**Total:** 12-17 hours for complete mastery ✅

---

## 🚀 LAST MINUTE TIPS

**In Interview:**
1. **Always state base case first** (nullptr handling)
2. **Explain approach verbally before coding**
3. **Mention time/space complexity**
4. **Handle edge cases** (single node, empty tree)
5. **Test with dry run** before submitting

---

**Practice these patterns and you'll ace any Tree question!** 🌳💪
