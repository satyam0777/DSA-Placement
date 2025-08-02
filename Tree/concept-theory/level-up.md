## 10. Other Important Tree Concepts for Interviews

---

### a. Height and Depth of a Tree

- **Height:** Number of edges from root to deepest leaf.
- **Depth:** Number of edges from root to a given node.

**Code to find height:**
```cpp
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

### b. Size (Total Number of Nodes)

**Code:**
```cpp
int size(Node* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}
```

---

### c. Diameter of a Tree

- **Definition:** The length of the longest path between any two nodes.
- **Pattern:** For each node, diameter is max of:
    - Diameter of left subtree
    - Diameter of right subtree
    - Height of left + height of right

**Efficient Code (returns diameter):**
```cpp
int diameter(Node* root, int& res) {
    if (!root) return 0;
    int lh = diameter(root->left, res);
    int rh = diameter(root->right, res);
    res = max(res, lh + rh);
    return 1 + max(lh, rh);
}
```

---

### d. Check if Tree is Balanced

- **Definition:** For every node, height difference of left and right subtree ≤ 1.

**Code:**
```cpp
bool isBalanced(Node* root) {
    if (!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
```

---

### e. Mirror of a Tree

**Code:**
```cpp
void mirror(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}
```

---

### f. Lowest Common Ancestor (LCA)

- **Definition:** The lowest node that has both given nodes as descendants.

**Code:**
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

---

### g. Path Sum Problems

- **Example:** Check if there is a root-to-leaf path with a given sum.

**Code:**
```cpp
bool hasPathSum(Node* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return sum == root->data;
    return hasPathSum(root->left, sum - root->data) ||
           hasPathSum(root->right, sum - root->data);
}
```

---

### h. Serialize and Deserialize a Tree

- **Serialize:** Convert tree to string/array.
- **Deserialize:** Rebuild tree from string/array.

**Pattern:** Use preorder traversal with markers for nulls.

---

### i. Binary Search Tree (BST) Operations

- **Insert, Delete, Search**
- **Validate BST:** Inorder traversal should be sorted.

**Validate BST Code:**
```cpp
bool isBST(Node* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}
```

---

### j. Morris Traversal (O(1) Space Traversal)

- Advanced: Inorder traversal without stack or recursion.

---

**Summary:**  
These concepts cover most tree interview questions.  
Practice each pattern, understand recursive thinking, and always dry run with small trees for