# 🌳 TREE TRAVERSALS - INTERVIEW READY
## Complete Guide for Service-Based Companies

---

## 🎯 WHY TRAVERSALS ARE CRITICAL?

```
✅ 95%+ tree problems require traversals!
✅ Foundation for all tree algorithms
✅ Asked in 100% of service-based interviews
✅ Master these 4 = Unlock all tree patterns
✅ Can be asked in multiple ways (recursive, iterative)
```

---

## 📊 4 MAIN TRAVERSALS

```
Traversals:
├─ Preorder (Root → Left → Right)
├─ Inorder (Left → Root → Right)
├─ Postorder (Left → Right → Root)
└─ Level Order (BFS - Level by Level)
```

---

## 🌳 TREE STRUCTURE (Review)

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

## 🔥 TRAVERSAL 1: PREORDER (Root → Left → Right) ⭐⭐⭐

### **What is Preorder?**
Visit: **Root FIRST**, then Left subtree, then Right subtree

### **Real-life use:**
- Make copy of tree
- Serialize tree (save to file)
- Delete tree (process node before children)

### **Recursive Code:**

```cpp
void preorder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";           // Process root
    preorder(root->left);                // Go left
    preorder(root->right);               // Go right
}
```

### **Example Dry Run:**

```
       1
      / \
     2   3
    / \
   4   5

Preorder: 1 → 2 → 4 → 5 → 3
```

### **Iterative Code (Using Stack):**

```cpp
vector<int> preorderIterative(Node* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<Node*> st;
    st.push(root);
    
    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();
        
        result.push_back(curr->data);    // Process
        
        // Push right first (so left is processed first)
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    
    return result;
}
```

### **Interview Communication:**

> "Sir, **Preorder traversal** processes the **root first**, then left subtree, then right subtree.
> 
> **Use recursive approach for simplicity:**
> - Base case: if node is null, return
> - Process current node
> - Recurse on left and right children
> 
> **Iterative:** Use stack, push right then left (so left processes first).
> 
> **Time:** O(n), **Space:** O(h) where h is height"

---

## 🔥 TRAVERSAL 2: INORDER (Left → Root → Right) ⭐⭐⭐

### **What is Inorder?**
Visit: Left subtree, then **Root**, then Right subtree

### **Real-life use:**
- **BST gives sorted order!** (MOST IMPORTANT!)
- Check if tree is BST
- Convert to DLL (doubly linked list)

### **Recursive Code:**

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;
    
    inorder(root->left);                // Go left
    cout << root->data << " ";          // Process root
    inorder(root->right);               // Go right
}
```

### **Example Dry Run:**

```
       1
      / \
     2   3
    / \
   4   5

Inorder: 4 → 2 → 5 → 1 → 3
(If BST: sorted order!)
```

### **Iterative Code (Using Stack):**

```cpp
vector<int> inorderIterative(Node* root) {
    vector<int> result;
    stack<Node*> st;
    Node* curr = root;
    
    while (curr != nullptr || !st.empty()) {
        // Go to left subtree
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        
        // Current is null, pop from stack
        curr = st.top();
        st.pop();
        
        result.push_back(curr->data);    // Process
        
        // Visit right subtree
        curr = curr->right;
    }
    
    return result;
}
```

### **Why This Works:**

```
1. Keep going left until null
2. When null, pop and process
3. Go right
4. Repeat

Example for above tree:
- curr=1, push 1, go left (curr=2)
- curr=2, push 2, go left (curr=4)
- curr=4, push 4, go left (curr=null)
- pop 4, print 4, go right (curr=null)
- pop 2, print 2, go right (curr=5)
- curr=5, push 5, go left (curr=null)
- pop 5, print 5, go right (curr=null)
- pop 1, print 1, go right (curr=3)
- ...
```

### **Interview Communication:**

> "Sir, **Inorder traversal** processes: Left subtree → **Root** → Right subtree.
> 
> **Key point:** In a **Binary Search Tree, inorder gives sorted order!**
> 
> **Iterative approach:**
> 1. Go to leftmost node (push all left nodes)
> 2. Pop and process
> 3. Go right
> 4. Repeat
> 
> **Time:** O(n), **Space:** O(h)"

---

## 🔥 TRAVERSAL 3: POSTORDER (Left → Right → Root) ⭐⭐⭐

### **What is Postorder?**
Visit: Left subtree, then Right subtree, then **Root LAST**

### **Real-life use:**
- **Delete tree** (delete children first!)
- Calculate expression tree
- Get postfix expression

### **Recursive Code:**

```cpp
void postorder(Node* root) {
    if (root == nullptr) return;
    
    postorder(root->left);              // Go left
    postorder(root->right);             // Go right
    cout << root->data << " ";          // Process root LAST
}
```

### **Example Dry Run:**

```
       1
      / \
     2   3
    / \
   4   5

Postorder: 4 → 5 → 2 → 3 → 1
(Process children before parent!)
```

### **Iterative Code (Using Two Stacks):**

```cpp
vector<int> postorderIterative(Node* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<Node*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);
        
        // Push left then right (so right is processed before left in st2)
        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    
    // st2 has postorder
    while (!st2.empty()) {
        result.push_back(st2.top()->data);
        st2.pop();
    }
    
    return result;
}
```

### **Interview Communication:**

> "Sir, **Postorder traversal** processes: Left → Right → **Root LAST**.
> 
> **Important use:** When deleting tree (delete children before parent).
> 
> **Recursive is simpler** - just swap positions of process line.
> 
> **Iterative:** Use two stacks approach.
> 
> **Time:** O(n), **Space:** O(h)"

---

## 🔥 TRAVERSAL 4: LEVEL ORDER (BFS) ⭐⭐⭐

### **What is Level Order?**
Visit nodes **level by level** (top to bottom, left to right)

### **Real-life use:**
- Print tree level-wise
- Find level of a node
- Check if tree is complete
- Tree views (top, bottom, left, right)

### **Recursive Code (Not Common):**

```cpp
void levelOrder(Node* root) {
    int h = height(root);
    
    for (int level = 1; level <= h; level++) {
        printLevel(root, level);
    }
}

void printLevel(Node* root, int level) {
    if (root == nullptr) return;
    
    if (level == 1) {
        cout << root->data << " ";
    } else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
```

### **Iterative Code (Using Queue) - BETTER!**

```cpp
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();  // Important! Get size at this level
        vector<int> currentLevel;
        
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();
            
            currentLevel.push_back(curr->data);
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}
```

### **Example Dry Run:**

```
       1
      / \
     2   3
    / \   \
   4   5   6

Level Order: [[1], [2,3], [4,5,6]]

Step-by-step:
- q: [1] → process 1, add children [2,3] → q: [2,3]
- q: [2,3] → process 2, add children [4,5], process 3, add child [6] → q: [4,5,6]
- q: [4,5,6] → process all (no children) → q: []
```

### **Interview Communication:**

> "Sir, **Level order traversal** visits nodes **level by level**.
> 
> **Use BFS with queue:**
> 1. Push root to queue
> 2. While queue not empty:
>    - Get current level size
>    - Process all nodes at current level
>    - Add their children to queue
> 
> **Key point:** Capture level size BEFORE processing (to separate levels).
> 
> **Time:** O(n), **Space:** O(w) where w is max width"

---

## 🎯 COMPARISON TABLE

| Traversal | Order | Use Case | Recursive Easy? |
|-----------|-------|----------|-----------------|
| **Preorder** | Root, Left, Right | Copy tree, serialize | ✅ YES |
| **Inorder** | Left, Root, Right | BST sorted, validate BST | ✅ YES |
| **Postorder** | Left, Right, Root | Delete tree, postfix | ✅ YES |
| **Level Order** | Level by level | Tree views, BFS | ❌ NO (use queue) |

---

## 💡 IMPORTANT NOTES

### **When to use which?**

```
Need sorted order from BST?          → Inorder
Delete/free tree?                   → Postorder
Need to process before children?    → Preorder
Process level by level?             → Level Order
Make copy of tree?                  → Preorder
```

### **Memory Usage:**

```
- Recursive: Uses call stack (implicit)
- Iterative: Uses explicit stack/queue
- Both: Space = O(h) for balanced, O(n) for skewed
```

---

## 🏢 COMPANY-WISE FREQUENCY

### **TCS:**
- Preorder: 75% ⭐⭐
- Inorder: 80% ⭐⭐⭐
- Postorder: 65% ⭐⭐
- Level Order: 70% ⭐⭐

### **Infosys:**
- Preorder: 85% ⭐⭐⭐
- Inorder: 90% ⭐⭐⭐
- Postorder: 75% ⭐⭐⭐
- Level Order: 85% ⭐⭐⭐

### **Wipro:**
- Preorder: 70% ⭐⭐
- Inorder: 75% ⭐⭐⭐
- Postorder: 65% ⭐⭐
- Level Order: 75% ⭐⭐⭐

---

## ✅ FINAL CHECKLIST

```
□ Can write preorder (recursive & iterative)
□ Can write inorder (recursive & iterative)
□ Can write postorder (recursive & iterative)
□ Can write level order (queue-based)
□ Know when to use which traversal
□ Understand level order size trick
□ Can dry run all 4 on paper
```

---

**You're Traversal-Ready!** 🚀

**Study Time:** 4-5 hours ⏱️

**Coverage:** 95% of tree problems start with traversals! ✅

**All the best, Satyam!** 💪
