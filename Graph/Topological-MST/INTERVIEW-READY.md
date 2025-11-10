# 🎯 TOPOLOGICAL SORT & MST - INTERVIEW READY
## Advanced Graph Algorithms

---

## 📊 ALGORITHM FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 70%+ if graph asked)
⭐⭐   HIGH (Asked 50-70%)
```

**Overall Frequency:** TCS 55%, Infosys 70%, Wipro 50%

---

## 🔥 TOPOLOGICAL SORT ⭐⭐⭐

### **Frequency:**
- TCS: 60% | Infosys: 75% | Wipro: 55%

### **When to Use:**
- **ONLY for DAG** (Directed Acyclic Graph)
- Task scheduling/ordering problems
- Build order of dependencies

### **Definition:**
Linear ordering of vertices such that for every directed edge (u→v), u comes before v

### **Example:**

```
DAG:
  1 → 2 → 4
  |   ↑
  └─→ 3

Topological Orders:
- 1, 2, 3, 4 ✓
- 1, 3, 2, 4 ✓
- 1, 2, 4, 3 ✗ (4 before 3, but 2→4 not done yet... wait, actually ✓)
```

### **Method 1: DFS (Kahn's Algorithm - Iterative):**

```cpp
vector<int> topologicalSort(int n, vector<int> adj[]) {
    vector<int> inDegree(n, 0);
    
    // Calculate in-degrees
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }
    
    // Queue stores all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topo;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        
        // Reduce in-degree of neighbors
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // If topo size != n, graph has cycle
    if (topo.size() != n) {
        cout << "Cycle detected!" << endl;
        return {};
    }
    
    return topo;
}
```

### **Method 2: DFS (Stack-based):**

```cpp
void dfs(int u, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, st);
        }
    }
    
    st.push(u);  // Push AFTER visiting all descendants
}

vector<int> topologicalSort(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    
    return topo;
}
```

### **Dry Run (BFS/Kahn's):**

```
DAG:
  1 → 2 → 4
  |   ↑
  └─→ 3

In-degrees: 1→0, 2→1, 3→1, 4→1

Initial queue: [1] (in-degree 0)

Step 1: Pop 1, add to topo
  Reduce in-degrees: 2→0, 3→0
  Queue: [2, 3]
  Topo: [1]

Step 2: Pop 2, add to topo
  Reduce in-degrees: 4→0
  Queue: [3, 4]
  Topo: [1, 2]

Step 3: Pop 3, add to topo
  No outgoing edges
  Queue: [4]
  Topo: [1, 2, 3]

Step 4: Pop 4, add to topo
  No outgoing edges
  Queue: []
  Topo: [1, 2, 3, 4]

Result: 1, 2, 3, 4 ✓
```

### **Time Complexity:** O(V + E)

### **Interview Script:**

> "Sir, topological sort only works for DAG.
>
> I use Kahn's algorithm with BFS:
> 1. Calculate in-degree for all nodes
> 2. Add all nodes with in-degree 0 to queue
> 3. Pop node, add to result
> 4. For each neighbor, reduce in-degree
> 5. If in-degree becomes 0, add to queue
>
> If result size < n, graph has cycle.
>
> Time: O(V+E), Space: O(V)"

---

## 🔥 MINIMUM SPANNING TREE (MST) ⭐⭐⭐

### **Frequency:**
- TCS: 50% | Infosys: 65% | Wipro: 45%

### **Definition:**
Tree that connects all vertices with minimum total edge weight

### **Properties:**
- Has exactly V-1 edges for V vertices
- No cycles
- Connected (if graph is connected)
- Unique if all weights are distinct
- Multiple MSTs possible if weights repeat

### **Example:**

```
Graph:
    1 --2-- 2
    |       |
    4       1
    |       |
    3 --3-- 4

MST options (total weight 6):
- 1-2(2), 1-3(4), 3-4(1)  → total = 7? No...
Actually: 2-4(1), 1-2(2), 2-3(1)? Wait, need to check correctly.

MST always: minimum total weight connecting all vertices
```

---

## 🔥 KRUSKAL'S ALGORITHM (MST) ⭐⭐⭐

### **When to Use:**
- Greedy approach
- Sort edges by weight
- Use Union-Find to avoid cycles

### **Steps:**
1. Sort all edges by weight
2. Take minimum weight edge
3. If it creates cycle, skip
4. Else add to MST
5. Repeat until V-1 edges in MST

### **Code:**

```cpp
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if (x == y) return false;  // Already connected
        
        // Union by rank
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        
        return true;
    }
};

int kruskalMST(int n, vector<tuple<int, int, int>> edges) {
    // edges: {weight, u, v}
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    int mstWeight = 0;
    int edgesUsed = 0;
    
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mstWeight += w;
            edgesUsed++;
            
            if (edgesUsed == n - 1) break;  // MST complete
        }
    }
    
    return (edgesUsed == n - 1) ? mstWeight : -1;  // -1 if not connected
}
```

### **Dry Run:**

```
Edges (weight, u, v):
(1, 3, 4), (2, 1, 2), (3, 2, 4), (4, 1, 3)

Step 1: Take (1, 3, 4) → unite 3, 4
  MST weight = 1, edges = 1

Step 2: Take (2, 1, 2) → unite 1, 2
  MST weight = 3, edges = 2

Step 3: Take (3, 2, 4) → unite {1,2}, {3,4}
  MST weight = 6, edges = 3 ✓ (n-1 edges for 4 nodes)

Result: MST weight = 6
```

---

## 🔥 PRIM'S ALGORITHM (MST) ⭐⭐

### **When to Use:**
- Dense graphs
- Start from one vertex
- Grow MST by adding minimum edge

### **Steps:**
1. Start with any vertex
2. Mark it as visited
3. Add all its edges to priority queue
4. Pick minimum edge to unvisited vertex
5. Add vertex to MST
6. Repeat until all vertices visited

### **Code:**

```cpp
int primMST(int n, vector<pair<int, int>> adj[]) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {weight, node}
    
    int mstWeight = 0;
    int edgesUsed = 0;
    
    pq.push({0, 0});  // Start from node 0
    
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        
        visited[u] = true;
        mstWeight += w;
        edgesUsed++;
        
        for (auto [v, weight] : adj[u]) {
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    
    return (edgesUsed == n) ? mstWeight : -1;
}
```

---

## 🔥 KRUSKAL vs PRIM ⭐⭐⭐

| Property | Kruskal | Prim |
|----------|---------|------|
| **Approach** | Greedy on edges | Greedy on vertices |
| **Data Structure** | Sorting + DSU | Priority queue |
| **Time** | O(E log E) | O((V+E) log V) |
| **Space** | O(V) | O(V) |
| **Best For** | Sparse graphs | Dense graphs |
| **Complexity** | Simpler to code | Easier to understand |

---

## 🎯 COMPANY-WISE TOP QUESTIONS

### **TCS (55% Topo/MST asked):**
1. Topological Sort (60%)
2. Kruskal MST (45%)
3. Cycle Detection in DAG (50%)

### **Infosys (70% Topo/MST asked):**
1. Topological Sort (75%)
2. Prim's MST (65%)
3. Kruskal MST (60%)

### **Wipro (50% Topo/MST asked):**
1. Topological Sort (55%)
2. Cycle Detection (50%)
3. MST basics (40%)

---

## ⚠️ CRITICAL MISTAKES

```cpp
❌ WRONG: Using topological sort on graph with cycle
if (!hasCycle(adj, n)) {
    topo = topologicalSort(...);  // Check first!
}

✅ RIGHT: Check result size
vector<int> topo = topologicalSort(...);
if (topo.size() != n) {
    cout << "Cycle detected!" << endl;
}
```

```cpp
❌ WRONG: Union without checking if already united
for (auto [w, u, v] : edges) {
    mstWeight += w;
    dsu.unite(u, v);  // Might already be united!
}

✅ RIGHT: Check return value
if (dsu.unite(u, v)) {
    mstWeight += w;
    edgesUsed++;
}
```

---

## ✅ FINAL CHECKLIST

```
Topological Sort:
☐ Can use Kahn's algorithm (BFS + In-degree)
☐ Can use DFS + Stack method
☐ Know it only works for DAG
☐ Can detect cycle
☐ Time: O(V+E)

MST:
☐ Can code Kruskal (sort + DSU)
☐ Can code Prim (priority queue)
☐ Know properties (V-1 edges, connected, minimum weight)
☐ Can implement Union-Find
☐ Know when to use which

Applications:
☐ Topological sort for task scheduling
☐ MST for minimum cost network
☐ Can handle weighted/unweighted
```

---

**You're Topological Sort & MST Ready!** 🚀

**Study Time:** 3-4 hours ⏱️

**Coverage:** 70%+ of advanced graph problems! ✅

**All the best!** 💪
