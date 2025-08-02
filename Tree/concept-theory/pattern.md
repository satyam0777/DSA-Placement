# Tree Problems: Parent-Child Pattern Approach

---

## What is a Parent Problem?

A **parent problem** is a fundamental or classic problem whose solution pattern can be adapted to solve many related (child) problems.  
Understanding the parent problem helps you quickly recognize and solve its variations.

---

## Example: Traversal as Parent Pattern

### Parent Problem: **Tree Traversal (Preorder, Inorder, Postorder, Level Order)**

- **Pattern:** Visit nodes in a specific order (root, left, right).
- **Approach:** Use recursion or stack/queue for iterative solutions.

#### Child Problems Derived from Traversal

- Print all nodes at a given level (variation of level order).
- Print leaf nodes (variation of preorder/postorder).
- Print boundary nodes (combination of traversals).
- Serialize/deserialize tree (preorder with null markers).
- Mirror tree (postorder traversal, swap children).

---

## Example: Path/Property as Parent Pattern

### Parent Problem: **Root-to-Leaf Path Sum**

- **Pattern:** Recursively check if a path from root to leaf sums to a target.
- **Approach:** Subtract node value from sum, recurse left/right.

#### Child Problems Derived

- Print all root-to-leaf paths (track path vector).
- Find path with maximum sum (track max as you recurse).
- Count paths with a given sum (count all valid paths).
- Path sum in any-to-any node (variation: use postorder and return max path sum).

---

## Example: LCA as Parent Pattern

### Parent Problem: **Lowest Common Ancestor (LCA)**

- **Pattern:** Find the lowest node that is ancestor to both given nodes.
- **Approach:** Recurse left/right, return node if found.

#### Child Problems Derived

- Distance between two nodes (find LCA, then compute distances).
- Kth ancestor of a node (variation: track depth).
- Print all ancestors of a node (variation: print path on recursion stack).

---

## Example: Height/Depth as Parent Pattern

### Parent Problem: **Height of a Tree**

- **Pattern:** Height = 1 + max(left height, right height).
- **Approach:** Postorder recursion.

#### Child Problems Derived

- Check if tree is balanced (compare left/right heights).
- Diameter of tree (combine left/right heights at each node).
- Maximum width of tree (track nodes at each level).

---

## Example: BST as Parent Pattern

### Parent Problem: **BST Properties (Insert, Search, Validate)**

- **Pattern:** Use BST property (left < root < right).
- **Approach:** Recursion or iteration.

#### Child Problems Derived

- Find kth smallest/largest (inorder traversal).
- Find predecessor/successor (track during traversal).
- Convert BST to DLL (inorder traversal, link nodes).

---

## How to Use Parent-Child Pattern in Interviews

1. **Identify the core pattern** (parent problem) in the question.
2. **Recall the standard approach** for the parent problem.
3. **Adapt the approach** to fit the child problem’s requirements (add extra logic, track more info, combine patterns).
4. **Practice tracing** both parent and child problems with small examples.

---

## Summary Table

| Parent Problem         | Child Problems/Patterns Derived From It                |
|----------------------- |-------------------------------------------------------|
| Traversal              | Print leaves, boundary, serialize, mirror, etc.       |
| Path Sum               | All root-to-leaf paths, max path sum, count paths     |
| LCA                    | Distance, kth ancestor, print ancestors               |
| Height/Depth           | Balanced check, diameter, max width                   |
| BST Operations         | Kth smallest/largest, predecessor, DLL conversion     |

---

# In-Depth Approach, Dry Run, and Pseudocode for Advanced Tree Concepts

---

### h. Print All Root-to-Leaf Paths

**Approach:**  
- Use recursion to traverse the tree.
- Maintain a path vector (or array) that stores the current path from root to the current node.
- When you reach a leaf node, print or store the path.

**Pseudocode:**
```
function printPaths(node, path):
    if node is null:
        return
    add node.data to path
    if node.left is null and node.right is null:
        print path
    else:
        printPaths(node.left, path)
        printPaths(node.right, path)
    remove last element from path (backtrack)
```

**Dry Run Example:**  
For tree:  
```
    1
   / \
  2   3
 / \
4   5
```
Paths: 1-2-4, 1-2-5, 1-3

---

### i. Flatten Binary Tree to Linked List

**Approach:**  
- Use preorder traversal.
- Rearrange pointers so that each node's right points to the next node in preorder, and left is null.
- Can be done recursively or iteratively using a stack.

**Pseudocode:**
```
function flatten(root):
    if root is null:
        return
    flatten(root.right)
    flatten(root.left)
    root.right = prev
    root.left = null
    prev = root
```
*(prev is a global/static variable initialized as null)*

**Dry Run:**  
For tree:  
```
    1
   / \
  2   5
 / \   \
3   4   6
```
Flattened: 1 - 2 - 3 - 4 - 5 - 6 (all right pointers)

---

### j. Symmetric Tree

**Approach:**  
- Check if left and right subtrees are mirror images.
- Recursively compare left of left with right of right and right of left with left of right.

**Pseudocode:**
```
function isSymmetric(root):
    return isMirror(root.left, root.right)

function isMirror(left, right):
    if left is null and right is null:
        return true
    if left is null or right is null:
        return false
    return (left.data == right.data) and
           isMirror(left.left, right.right) and
           isMirror(left.right, right.left)
```

**Dry Run:**  
For tree:  
```
    1
   / \
  2   2
 /     \
3       3
```
isSymmetric returns true.

---

### k. Children Sum Property

**Approach:**  
- For every node, check if node.data == sum of left and right child data (if children exist).
- Recursively check for all nodes.

**Pseudocode:**
```
function childrenSum(node):
    if node is null or (node.left is null and node.right is null):
        return true
    sum = 0
    if node.left: sum += node.left.data
    if node.right: sum += node.right.data
    return (node.data == sum) and
           childrenSum(node.left) and
           childrenSum(node.right)
```

**Dry Run:**  
For tree:  
```
    10
   /  \
  8    2
 / \    \
3   5    2
```
All nodes satisfy the property.

---

### l. Threaded Binary Tree (Advanced)

**Approach:**  
- Use unused left/right pointers to point to inorder predecessor/successor.
- Helps in inorder traversal without stack or recursion.

**Pseudocode:**  
(Conceptual, implementation is advanced and rarely asked for code.)

---

### m. AVL Tree, Red-Black Tree, Segment Tree, Trie (Advanced)

- **AVL/Red-Black Tree:** Self-balancing BSTs, maintain height balance after insert/delete.
- **Segment Tree:** Used for range queries and updates on arrays.
- **Trie:** Efficient for prefix-based search (strings).

**Approach:**  
- Learn the basic structure and insertion/search/update logic.
- For segment tree, recursively build and query/update ranges.
- For trie, use a tree of characters for fast prefix queries.

---

### n. Binary Indexed Tree (Fenwick Tree)

**Approach:**  
- Used for prefix sum and update queries.
- Uses bit manipulation for efficient updates and queries.

**Pseudocode:**  
- Update: Add value to index and all its ancestors.
- Query: Sum up to index by moving to parent nodes.

---

### o. Tree Diameter (Longest Path) Between Any Two Nodes

**Approach:**  
- Use postorder traversal.
- For each node, diameter is max of:
    - Diameter of left subtree
    - Diameter of right subtree
    - Height of left + height of right

**Pseudocode:**
```
function diameter(node, res):
    if node is null:
        return 0
    lh = diameter(node.left, res)
    rh = diameter(node.right, res)
    res = max(res, lh + rh)
    return 1 + max(lh, rh)
```

**Dry Run:**  
For tree:  
```
    1
   / \
  2   3
 / \
4   5
```
Diameter is path 4-2-1-3 (length 3).

---

### p. Morris Traversal (O(1) Space Traversal)

**Approach:**  
- Inorder traversal without stack or recursion.
- Temporarily modify the tree to create threads to predecessor nodes.

**Pseudocode:**
```
function morrisInorder(root):
    curr = root
    while curr is not null:
        if curr.left is null:
            visit(curr)
            curr = curr.right
        else:
            pred = curr.left
            while pred.right is not null and pred.right != curr:
                pred = pred.right
            if pred.right is null:
                pred.right = curr
                curr = curr.left
            else:
                pred.right = null
                visit(curr)
                curr = curr.right
```

---

**How to Approach Any Advanced Tree Problem:**

1. **Draw the tree** for a small example.
2. **Write the recursive/iterative pattern** (see above).
3. **Dry run** with your example, track variables and pointers.
4. **Write pseudocode** before coding.
5. **Understand the base case and recursive case.**
6. **Practice edge cases** (empty tree, single node, skewed tree).

---

**Summary:**  
For each advanced tree concept, understand the pattern, write pseudocode, and dry run with small trees.  
This will help you confidently approach and solve any tree problem in interviews.

---
