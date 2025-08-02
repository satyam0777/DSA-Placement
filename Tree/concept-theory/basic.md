# Tree Mastery for Placements (C++ + Pattern-Based Learning)

---

## 1. Introduction to Trees

**What is a Tree?**  
A tree is a hierarchical data structure consisting of nodes, with a single node as the root and zero or more child nodes.  
- **Root:** The top node.
- **Leaf:** Node with no children.
- **Parent/Child:** Relationship between nodes.
- **Edge:** Connection between nodes.
- **Height:** Number of edges from root to deepest leaf.

**Types of Trees:**
- **Binary Tree:** Each node has at most 2 children.
- **Full Binary Tree:** Every node has 0 or 2 children.
- **Perfect Binary Tree:** All internal nodes have 2 children, all leaves at same level.
- **Complete Binary Tree:** All levels filled except possibly last, filled left to right.
- **Balanced Binary Tree:** Height is O(log N).
- **Degenerate Tree:** Each parent has only one child (like a linked list).

---

## 2. Binary Tree Representation in C++

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
```

---

## 3. Tree Traversals

### a. Preorder Traversal (Root ➝ Left ➝ Right)

**Pattern:**  
- Visit root, then left subtree, then right subtree.

**Recursive Code:**
```cpp
void preorder(Node* root, vector<int>& ans) {
    if (root == nullptr) return;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
```

**Iterative Code:**
```cpp
vector<int> iterativePreorder(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        ans.push_back(curr->data);
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return ans;
}
```

---

### b. Inorder Traversal (Left ➝ Root ➝ Right)

**Pattern:**  
- Visit left subtree, root, then right subtree.
- In BST, gives sorted order.

**Iterative Code:**
```cpp
vector<int> iterativeInorder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;
    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        ans.push_back(curr->data);
        curr = curr->right;
    }
    return ans;
}
```

---

### c. Postorder Traversal (Left ➝ Right ➝ Root)

**Pattern:**  
- Visit left subtree, right subtree, then root.
- Used for deleting/freeing trees.

**Recursive Code:**
```cpp
void postorder(Node* root, vector<int>& ans) {
    if (!root) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}
```

---

## 4. Level Order Traversal (Breadth-First Search)

**Pattern:**  
- Visit nodes level by level using a queue.

**Code:**
```cpp
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
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
        ans.push_back(level);
    }
    return ans;
}
```

---

## 5. Pattern Recognition for Tree Problems

- **Traversal-based:** Use preorder/inorder/postorder/level order.
- **Recursive:** Most tree problems are naturally recursive.
- **Divide and conquer:** Solve for left and right, combine at root.
- **Use of stack/queue:** For iterative traversals and BFS.

---

## 6. Common Interview Patterns

- **Count/Check/Find:**  
  - Count leaf nodes, height, diameter, etc.
  - Check if tree is balanced, symmetric, etc.
  - Find LCA, kth ancestor, path sum, etc.
- **Modify/Transform:**  
  - Mirror tree, flatten tree, convert to DLL, etc.
- **BST-specific:**  
  - Insert, delete, search, validate BST, find kth smallest/largest.

---

## 7. Example: Count Nodes with One Child

**Code:**
```cpp
int countOneChild(Node* root) {
    if (!root) return 0;
    int count = 0;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        if ((curr->left && !curr->right) || (!curr->left && curr->right))
            count++;
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return count;
}
```

---

## 8. How to Approach Any Tree Problem

1. **Draw the tree** for small input.
2. **Identify the pattern:** Is it traversal, divide and conquer, or something else?
3. **Think recursively:** What is the base case? What is the current node’s work? What do you need from children?
4. **Write helper functions** if needed (for height, sum, etc.).
5. **Dry run** your code on a small tree.

---

## 9. Practice Patterns

- Preorder, Inorder, Postorder (recursive and iterative)
- Level order (BFS)
- Height/Depth of tree
- Count leaf/one-child/two-child nodes
- Check balanced/symmetric
- Lowest Common Ancestor (LCA)
- Path sum problems
- Serialize/deserialize tree
- BST operations

---

**Summary:**  
Master tree basics, traversals, and common patterns.  
Always break down the problem into smaller subproblems, use recursion, and practice with diagrams and dry runs.  
For in-depth learning, follow Aditya Verma’s tree playlist and solve problems step by step.
