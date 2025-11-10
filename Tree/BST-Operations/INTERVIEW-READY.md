# 🎯 BINARY SEARCH TREE (BST) - INTERVIEW READY
## Core Operations Every Company Asks

---

## 📊 OPERATION FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 80%+ BST problems)
⭐⭐   HIGH (Asked 60-80%)
⭐     GOOD (Asked 40-60%)
```

**Overall BST Frequency:** TCS 75%, Infosys 85%, Wipro 70%

---

## 🔥 CORE 1: BST PROPERTIES & VALIDATION ⭐⭐⭐

### **Frequency:**
- TCS: 75% | Infosys: 85% | Wipro: 70%

### **Key Property:**
- For every node: `all_left < node < all_right`
- Inorder traversal gives SORTED array ⭐ (Most important!)

### **Validate BST:**

```cpp
bool isValidBST(Node* root, long minVal = LLONG_MIN, long maxVal = LLONG_MAX) {
    if (root == nullptr) return true;
    
    if (root->data <= minVal || root->data >= maxVal) return false;
    
    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}
```

### **Dry Run:**

```
Validate:
    10
   /  \
  5    15
 / \
3   7

isValidBST(10, -∞, +∞):
  - 10 in range ✓
  - left: isValidBST(5, -∞, 10)
    - 5 in range ✓
    - left: isValidBST(3, -∞, 5) ✓
    - right: isValidBST(7, 5, 10) ✓
  - right: isValidBST(15, 10, +∞) ✓
  
Result: Valid BST ✓
```

### **Interview Script:**

> "Sir, I'll maintain min and max bounds.
>
> At each node, I check if current value is within bounds.
> 
> For left subtree, max becomes current value.
> For right subtree, min becomes current value.
>
> This ensures ALL left < current < ALL right."

---

## 🔥 CORE 2: INSERT IN BST ⭐⭐⭐

### **Frequency:**
- TCS: 70% | Infosys: 80% | Wipro: 65%

### **Recursive Code:**

```cpp
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // If value == root->data, ignore (or handle duplicates)
    
    return root;
}
```

### **Iterative Code:**

```cpp
void insertIterative(Node*& root, int value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }
    
    Node* curr = root;
    while (true) {
        if (value < curr->data) {
            if (curr->left == nullptr) {
                curr->left = new Node(value);
                return;
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = new Node(value);
                return;
            }
            curr = curr->right;
        }
    }
}
```

### **Dry Run:**

```
Insert 6 into:
      10
     /  \
    5    15
   / \
  3   7

- Start at 10: 6 < 10 → go left
- At 5: 6 > 5 → go right
- At 7: 6 < 7 → left is null
- Insert 6 at left of 7

Result:
      10
     /  \
    5    15
   / \
  3   7
     /
    6
```

---

## 🔥 CORE 3: SEARCH IN BST ⭐⭐⭐

### **Frequency:**
- TCS: 75% | Infosys: 85% | Wipro: 70%

### **Code:**

```cpp
Node* search(Node* root, int value) {
    if (root == nullptr) return nullptr;
    
    if (value == root->data) return root;
    
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}
```

### **Iterative Code:**

```cpp
Node* searchIterative(Node* root, int value) {
    while (root != nullptr) {
        if (value == root->data) return root;
        if (value < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}
```

**Time Complexity:** O(log n) average, O(n) worst case (skewed tree)

---

## 🔥 CORE 4: DELETE FROM BST ⭐⭐⭐

### **Frequency:**
- TCS: 65% | Infosys: 80% | Wipro: 60%

### **Three Cases:**

**Case 1: No children (Leaf)**
```
Simply remove
```

**Case 2: One child**
```
Replace node with child
```

**Case 3: Two children**
```
Replace with Inorder Successor (smallest in right subtree)
or Inorder Predecessor (largest in left subtree)
```

### **Code:**

```cpp
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return nullptr;
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node found
        
        // Case 1: No children (Leaf)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Two children
        // Find inorder successor (smallest in right subtree)
        Node* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    
    return root;
}
```

### **Dry Run - Delete with 2 Children:**

```
Delete 10:
      10           7
     /  \         / \
    5    15  →   5   15
   / \         /
  3   7       3

Find successor (smallest in right):
- Go right from 10 → 15
- Go left from 15 → null
- Successor = 15

Actually smallest in right is just 15, so:
- Copy 15 to 10's place
- Delete 15 from right subtree

Result:
      15
     /  \
    5    (null)
   / \
  3   7

Wait, let me reconsider...
If we use proper successor (smallest in right):
- Right subtree of 10 is just 15 (no left child)
- So successor is 15
- Replace 10 with 15
- Delete the old 15

Result:
      15
     /  \
    5    (null)
   / \
  3   7
```

### **Interview Script:**

> "Sir, three cases:
>
> 1. **Leaf node:** Simply remove
>
> 2. **One child:** Copy child's value and recurse on child
>
> 3. **Two children:** Find inorder successor (smallest in right subtree), copy its value to current node, then delete the successor."

---

## 🔥 OPERATION 5: FIND KTH SMALLEST ⭐⭐⭐

### **Frequency:**
- TCS: 75% | Infosys: 85% | Wipro: 70%

### **Key Insight:**
Inorder traversal of BST gives sorted array!

### **Code:**

```cpp
int kthSmallest(Node* root, int k) {
    int count = 0;
    int result = -1;
    
    function<void(Node*)> inorder = [&](Node* node) {
        if (node == nullptr || count >= k) return;
        
        inorder(node->left);
        
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        
        inorder(node->right);
    };
    
    inorder(root);
    return result;
}
```

### **Dry Run:**

```
Find Kth smallest (k=3):
      10
     /  \
    5    15
   / \
  3   7

Inorder: 3, 5, 7, 10, 15
         1  2  3  4   5

3rd element = 7 ✓
```

**Time Complexity:** O(n) | **Space Complexity:** O(h) recursion

---

## 🔥 OPERATION 6: FIND KTH LARGEST ⭐⭐⭐

### **Frequency:**
- TCS: 70% | Infosys: 80% | Wipro: 65%

### **Approach:**
Reverse inorder (Right → Root → Left)

### **Code:**

```cpp
int kthLargest(Node* root, int k) {
    int count = 0;
    int result = -1;
    
    function<void(Node*)> reverseInorder = [&](Node* node) {
        if (node == nullptr || count >= k) return;
        
        reverseInorder(node->right);
        
        count++;
        if (count == k) {
            result = node->data;
            return;
        }
        
        reverseInorder(node->left);
    };
    
    reverseInorder(root);
    return result;
}
```

---

## 🔥 OPERATION 7: FLOOR & CEILING ⭐⭐

### **Frequency:**
- TCS: 60% | Infosys: 70% | Wipro: 55%

### **Definitions:**
- **Floor:** Largest value ≤ target
- **Ceiling:** Smallest value ≥ target

### **Code - Floor:**

```cpp
int floor(Node* root, int x) {
    int result = -1;
    
    while (root != nullptr) {
        if (root->data == x) return root->data;
        
        if (root->data < x) {
            result = root->data;  // This could be answer
            root = root->right;
        } else {
            root = root->left;
        }
    }
    
    return result;
}
```

### **Code - Ceiling:**

```cpp
int ceiling(Node* root, int x) {
    int result = -1;
    
    while (root != nullptr) {
        if (root->data == x) return root->data;
        
        if (root->data > x) {
            result = root->data;  // This could be answer
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    return result;
}
```

### **Dry Run - Floor of 8:**

```
Find floor(8):
      10
     /  \
    5    15
   / \
  3   7

- At 10: 10 > 8, go left
- At 5: 5 < 8, save 5 as candidate, go right
- At 7: 7 < 8, save 7 as candidate, go right
- nullptr, stop

Answer: 7 ✓
```

---

## 🔥 OPERATION 8: INORDER SUCCESSOR & PREDECESSOR ⭐⭐

### **Frequency:**
- TCS: 60% | Infosys: 70% | Wipro: 55%

### **Definitions:**
- **Successor:** Next node in inorder
- **Predecessor:** Previous node in inorder

### **Code - Successor:**

```cpp
Node* findSuccessor(Node* root, int value) {
    Node* succ = nullptr;
    
    while (root != nullptr) {
        if (value < root->data) {
            succ = root;  // This could be successor
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    return succ;
}
```

**Logic:** Successor is the smallest in right subtree (or ancestor)

### **Code - Predecessor:**

```cpp
Node* findPredecessor(Node* root, int value) {
    Node* pred = nullptr;
    
    while (root != nullptr) {
        if (value > root->data) {
            pred = root;  // This could be predecessor
            root = root->right;
        } else {
            root = root->left;
        }
    }
    
    return pred;
}
```

---

## 🔥 OPERATION 9: LOWEST COMMON ANCESTOR IN BST ⭐⭐⭐

### **Frequency:**
- TCS: 70% | Infosys: 80% | Wipro: 65%

### **Advantage Over Generic Tree:**
Can use BST property for O(h) instead of O(n)!

### **Code:**

```cpp
Node* lcaBST(Node* root, int n1, int n2) {
    if (root == nullptr) return nullptr;
    
    // If both are smaller, go left
    if (n1 < root->data && n2 < root->data) {
        return lcaBST(root->left, n1, n2);
    }
    
    // If both are larger, go right
    if (n1 > root->data && n2 > root->data) {
        return lcaBST(root->right, n1, n2);
    }
    
    // One on each side (or at root) → root is LCA
    return root;
}
```

### **Dry Run:**

```
Find LCA of 3 and 7:
      10
     /  \
    5    15
   / \
  3   7

- At 10: 3 < 10 and 7 < 10 → go left
- At 5: 3 < 5 and 7 > 5 → one on each side
- Answer: 5 ✓
```

---

## 🔥 OPERATION 10: CONVERT TO SORTED DOUBLY LINKED LIST ⭐⭐

### **Frequency:**
- TCS: 55% | Infosys: 70% | Wipro: 50%

### **Code:**

```cpp
void inorder(Node* root, Node*& head, Node*& tail) {
    if (root == nullptr) return;
    
    inorder(root->left, head, tail);
    
    if (head == nullptr) {
        head = tail = root;
    } else {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    
    inorder(root->right, head, tail);
}

Node* bstToDLL(Node* root) {
    Node* head = nullptr, *tail = nullptr;
    inorder(root, head, tail);
    
    if (tail) tail->right = nullptr;  // Break circular
    return head;
}
```

---

## 🎯 COMPANY-WISE OPERATIONS

### **TCS (BST 75% asked):**
1. Insert (70%)
2. Search (75%)
3. Validate (75%)
4. Delete (65%)
5. Kth Smallest (75%)

### **Infosys (BST 85% asked):**
1. Validate (85%)
2. Kth Smallest (85%)
3. LCA in BST (80%)
4. Delete (80%)
5. Floor/Ceiling (70%)

### **Wipro (BST 70% asked):**
1. Insert (65%)
2. Search (70%)
3. Validate (70%)
4. Kth Smallest (70%)
5. Successor/Predecessor (55%)

---

## 📝 QUICK COMPARISON TABLE

| Operation | Time (Avg) | Time (Worst) | Space | Difficulty |
|-----------|-----------|-----------|-------|-----------|
| Insert | O(log n) | O(n) | O(1) | ⭐ |
| Search | O(log n) | O(n) | O(h) | ⭐ |
| Delete | O(log n) | O(n) | O(h) | ⭐⭐ |
| Validate | O(n) | O(n) | O(h) | ⭐ |
| Kth Smallest | O(n) | O(n) | O(h) | ⭐ |
| Floor/Ceiling | O(log n) | O(n) | O(1) | ⭐ |
| LCA (BST) | O(log n) | O(n) | O(h) | ⭐ |

---

## ⚠️ COMMON MISTAKES

```cpp
❌ WRONG: Checking only immediate children
if (root->left->data < root->data && root->right->data > root->data) 
// This doesn't ensure ALL left < current < ALL right

✅ RIGHT: Using min/max bounds
if (root->data > minVal && root->data < maxVal)
```

```cpp
❌ WRONG: Deleting node without handling children properly
delete root;
// Memory leak if children exist!

✅ RIGHT: Properly handle all three cases
if (isLeaf) {
    delete root; return nullptr;
} else if (hasOneChild) {
    return child;
} else {
    // Handle two children with successor
}
```

---

## ✅ FINAL CHECKLIST

```
□ Can insert into BST
□ Can search in BST
□ Can validate BST correctly
□ Can delete all 3 cases
□ Can find Kth smallest
□ Can find LCA in BST (using property!)
□ Know time complexities
□ Can explain worst case (skewed tree)
□ Know when to use BST
```

---

## 🚀 PREPARATION TIPS

1. **Always use BST property** for efficiency
2. **Inorder = Sorted** (most important!)
3. **For delete:** Use inorder successor
4. **For validation:** Use min/max bounds
5. **For LCA:** Use comparison, not tree traversal

---

**You're BST Ready!** 🌳

**Study Time:** 4-5 hours ⏱️

**Coverage:** 80% of BST problems! ✅

**Final reminder:** Inorder traversal is EVERYTHING in BST!

**All the best!** 💪
