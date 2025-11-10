# 🎯 GRAPH FUNDAMENTALS - INTERVIEW READY
## Every Service Company Asks These

---

## 📊 FUNDAMENTAL FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 90%+ Graph problems)
⭐⭐   HIGH (Asked 70-90%)
⭐     GOOD (Asked 50-70%)
```

**Overall Graph Frequency:** TCS 65%, Infosys 80%, Wipro 60%

---

## 🔥 FUNDAMENTAL 1: GRAPH REPRESENTATION ⭐⭐⭐

### **Frequency:**
- TCS: 70% | Infosys: 85% | Wipro: 65%

### **What is a Graph?**
- Nodes/Vertices and Edges
- Can be directed or undirected
- Can be weighted or unweighted
- Can have cycles or be acyclic

### **Representation Method 1: ADJACENCY LIST ⭐⭐⭐ (MOST USED)**

```cpp
// Unweighted Graph
vector<int> adj[n];  // adj[u] = {v1, v2, ...}

// Example: Graph with 4 nodes, 5 edges
// 0-1, 1-2, 2-3, 1-3, 0-3

vector<int> adj[4];
adj[0] = {1, 3};
adj[1] = {0, 2, 3};
adj[2] = {1, 3};
adj[3] = {0, 1, 2};
```

**Advantages:**
- Space: O(V + E)
- Easy to iterate over neighbors
- Best for sparse graphs

```cpp
// Weighted Graph
vector<pair<int, int>> adj[n];  // adj[u] = {(v, weight), ...}

vector<pair<int, int>> adj[4];
adj[0] = {{1, 5}, {3, 2}};
adj[1] = {{0, 5}, {2, 3}, {3, 1}};
adj[2] = {{1, 3}, {3, 4}};
adj[3] = {{0, 2}, {1, 1}, {2, 4}};
```

### **Representation Method 2: ADJACENCY MATRIX**

```cpp
int adj[n][n];  // adj[i][j] = weight (or 0/1 for unweighted)

// Unweighted
int adj[4][4] = {
    {0, 1, 0, 1},  // 0 connects to 1, 3
    {1, 0, 1, 1},  // 1 connects to 0, 2, 3
    {0, 1, 0, 1},  // 2 connects to 1, 3
    {1, 1, 1, 0}   // 3 connects to 0, 1, 2
};

// Weighted
int adj[4][4] = {
    {0, 5, 0, 2},  // 0-1: weight 5, 0-3: weight 2
    {5, 0, 3, 1},
    {0, 3, 0, 4},
    {2, 1, 4, 0}
};
```

**Disadvantages:**
- Space: O(V²) (wasteful for sparse)
- Good for dense graphs

### **Interview Script:**

> "Sir, for most problems I use adjacency list because:
> 
> 1. Space efficient - O(V + E)
> 2. Easy to iterate over neighbors
> 3. Most graphs in interviews are sparse
>
> Adjacency matrix is O(V²) space, useful only for dense graphs."

---

## 🔥 FUNDAMENTAL 2: TYPES OF GRAPHS ⭐⭐⭐

### **1. Directed vs Undirected**

```
Undirected:          Directed:
    1                   1 → 2
   / \                  ↑   ↓
  2   3                 3 ← 4

Edge 1-2 = Edge 2-1   Edge 1→2 ≠ Edge 2→1
```

**Code:**
```cpp
// Undirected: Add edge both ways
adj[u].push_back(v);
adj[v].push_back(u);

// Directed: Add edge one way
adj[u].push_back(v);
```

### **2. Weighted vs Unweighted**

```
Unweighted:          Weighted:
    1                   1 --5-- 2
   /|\                  |  /3  /
  2 3 4                 |/    /4
                        3 --2--
```

### **3. Cyclic vs Acyclic**

```
Cyclic:              Acyclic (DAG):
  1 → 2              1 → 2
  ↑   ↓              ↓   ↓
  4 ← 3              3 → 4

Has cycle!           No cycle (tree-like)
```

### **4. Connected vs Disconnected**

```
Connected:           Disconnected:
    1 - 2            1 - 2    4 - 5
    |   |            |        |
    3 - 4            3        6

All reachable        Multiple components
```

### **Complete Graph:**
```
Every node connects to every other node
K₄ (4 nodes): 6 edges (4*3/2)
Edges = n(n-1)/2
```

### **Bipartite Graph:**
```
Nodes split into 2 groups
No edges within a group, only between

  1 - A
  |   |
  2 - B
  |   |
  3 - C

Alternating pattern
```

---

## 🔥 FUNDAMENTAL 3: GRAPH BUILDING (INPUT) ⭐⭐⭐

### **Common Input Format 1: Edge List**

```cpp
int n, m;  // n = nodes, m = edges
cin >> n >> m;

vector<int> adj[n];

for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    
    // Undirected
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

**Example:**
```
Input:
4 5
0 1
1 2
2 3
1 3
0 3

Graph Built:
adj[0] = {1, 3}
adj[1] = {0, 2, 3}
adj[2] = {1, 3}
adj[3] = {2, 1, 0}
```

### **Common Input Format 2: Weighted Edges**

```cpp
int n, m;
cin >> n >> m;

vector<pair<int, int>> adj[n];  // {node, weight}

for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});  // If undirected
}
```

### **Common Input Format 3: Adjacency Matrix**

```cpp
int adj[n][n];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin >> adj[i][j];
    }
}
```

---

## 🔥 FUNDAMENTAL 4: DEGREE & EDGES ⭐⭐

### **Degree:**
```
In-degree: Number of edges coming IN (directed)
Out-degree: Number of edges going OUT (directed)
Degree: Number of edges connected (undirected)

Example:
    1 → 2
    ↓   ↓
    3 ← 4

Node 2: In-degree = 2, Out-degree = 1
Node 3: In-degree = 1, Out-degree = 1
```

**Count In-degree:**
```cpp
vector<int> inDegree(n, 0);
for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
        inDegree[v]++;
    }
}
```

### **Total Edges:**
```
Sum of all in-degrees = Sum of all out-degrees = Total edges
For undirected: Sum of degrees = 2 * Total edges
```

---

## 🔥 FUNDAMENTAL 5: PATH & CYCLE ⭐⭐⭐

### **Path:**
Sequence of nodes connected by edges, no node repeated

```
1 → 2 → 3 → 4  (Valid path)
1 → 2 → 1 → 3  (Not a path, 1 repeated)
```

### **Cycle:**
Path that starts and ends at same node

```
1 → 2 → 3 → 1  (Cycle!)
```

### **Detect Cycle in Undirected Graph:**

```cpp
bool hasCycle(int u, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;  // Found cycle
        }
    }
    
    return false;
}

// Main
vector<bool> visited(n, false);
for (int i = 0; i < n; i++) {
    if (!visited[i] && hasCycle(i, -1, adj, visited)) {
        cout << "Cycle exists!" << endl;
    }
}
```

### **Detect Cycle in Directed Graph:**

```cpp
// Using DFS with 3 colors: 0=white, 1=gray, 2=black
bool hasCycleDFS(int u, vector<int>& color, vector<int> adj[]) {
    color[u] = 1;  // Gray (visiting)
    
    for (int v : adj[u]) {
        if (color[v] == 1) return true;  // Gray edge = cycle!
        if (color[v] == 0 && hasCycleDFS(v, color, adj)) return true;
    }
    
    color[u] = 2;  // Black (visited)
    return false;
}
```

---

## 🔥 FUNDAMENTAL 6: CONNECTED COMPONENTS ⭐⭐

### **Definition:**
Set of nodes where every node is reachable from every other node

```
Component 1: 1-2-3
Component 2: 4-5

Two separate components
```

### **Count Connected Components:**

```cpp
int countComponents(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);  // Explore one component
            count++;
        }
    }
    
    return count;
}

void dfs(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
```

---

## 🔥 FUNDAMENTAL 7: GRAPH PROPERTIES ⭐⭐

### **Connectivity:**
```
Connected: Can reach any node from any other
Strongly Connected (Directed): Can reach any node from any other in both directions
Weakly Connected: Connected if treated as undirected
```

### **Acyclic:**
```
DAG (Directed Acyclic Graph): Directed graph with no cycles
Used for topological sorting
```

### **Tree vs Graph:**
```
Tree: 
  - Connected, acyclic graph
  - n nodes, n-1 edges
  - One unique path between any two nodes

Graph:
  - Can be disconnected
  - Can have cycles
  - Can have multiple paths
```

---

## 🔥 FUNDAMENTAL 8: ADJACENCY LIST BUILDING - COMPLETE EXAMPLE ⭐⭐⭐

### **Problem:** Build graph from edges

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // n = nodes, m = edges
    
    vector<int> adj[n];  // Adjacency list
    
    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected
    }
    
    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Input:**
```
4 4
0 1
1 2
2 3
3 0
```

**Output:**
```
0: 1 3
1: 0 2
2: 1 3
3: 2 0
```

---

## 🎯 COMPANY-WISE FOCUS

### **TCS (Graph 65% asked):**
- Graph representation (70%)
- Types of graphs (65%)
- Building graphs (75%)
- Cycle detection (60%)

### **Infosys (Graph 80% asked):**
- Everything from TCS
- Connected components (75%)
- Path problems (70%)
- Degree counting (65%)

### **Wipro (Graph 60% asked):**
- Graph representation (60%)
- Cycle detection (55%)
- Basic properties (60%)

---

## ⚠️ COMMON MISTAKES

```cpp
❌ WRONG: Forgetting to mark visited in DFS
void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);  // Infinite loop!
    }
}

✅ RIGHT: Mark visited first
void dfs(int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, visited);
        }
    }
}
```

```cpp
❌ WRONG: Parent check wrong in cycle detection
if (v != parent) return true;  // Catches self-loops only

✅ RIGHT: Check visited
if (!visited[v]) {
    if (hasCycle(...)) return true;
} else if (v != parent) {
    return true;  // Back edge = cycle
}
```

```cpp
❌ WRONG: Not handling disconnected components
for (int i = 0; i < n; i++) {
    dfs(i);  // Might visit same node multiple times!
}

✅ RIGHT: Check visited
for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        dfs(i);
    }
}
```

---

## ✅ FINAL CHECKLIST

```
Representation:
☐ Can build adjacency list from edges
☐ Can build adjacency matrix
☐ Know when to use which
☐ Can handle weighted graphs

Types:
☐ Know directed vs undirected
☐ Know cyclic vs acyclic
☐ Know connected vs disconnected
☐ Know bipartite graphs

Properties:
☐ Can count edges
☐ Can calculate degree
☐ Can detect cycles
☐ Can find connected components

Code:
☐ Can code adjacency list building
☐ Can code basic DFS
☐ Can code cycle detection
☐ Can code component counting
```

---

## 🎓 KNOWLEDGE SUMMARY

| Concept | Formula/Property |
|---------|-----------------|
| **Edges (Complete)** | V(V-1)/2 for undirected, V(V-1) for directed |
| **Degree Sum** | 2 * Edges (undirected), = In-degrees = Out-degrees (directed) |
| **Tree vs Graph** | Tree = connected acyclic, V-1 edges |
| **Path** | Sequence of unique nodes |
| **Cycle** | Path where start = end |
| **Component** | Set of reachable nodes |

---

**You're Graph Fundamentals Ready!** 🚀

**Study Time:** 2-3 hours ⏱️

**Coverage:** 100% of graph basics! ✅

**All the best!** 💪
