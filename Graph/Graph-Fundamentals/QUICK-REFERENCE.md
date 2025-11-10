# 🎯 GRAPH FUNDAMENTALS - QUICK REFERENCE

## ⚡ 5 MUST KNOW

### 1️⃣ ADJACENCY LIST (MOST USED)
```cpp
// Unweighted
vector<int> adj[n];
adj[0] = {1, 3};
adj[1] = {0, 2, 3};

// Weighted
vector<pair<int, int>> adj[n];  // {node, weight}
adj[0] = {{1, 5}, {3, 2}};
```
**When:** Sparse graphs, most problems ✅

---

### 2️⃣ GRAPH TYPES
```
Directed → Undirected (add both ways)
Weighted → Keep edge weights
Cyclic ↔ Acyclic (DAG)
Connected ↔ Components
```

**Code Snippets:**
```cpp
// Undirected edge
adj[u].push_back(v);
adj[v].push_back(u);

// Directed edge
adj[u].push_back(v);

// Weighted
adj[u].push_back({v, weight});
```

---

### 3️⃣ CYCLE DETECTION

**Undirected (DFS):**
```cpp
bool hasCycle(int u, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;  // Back edge = cycle
        }
    }
    return false;
}
```

**Directed (Color DFS):**
```cpp
// 0=white, 1=gray, 2=black
bool hasCycle(int u, vector<int>& color, vector<int> adj[]) {
    color[u] = 1;  // Gray
    for (int v : adj[u]) {
        if (color[v] == 1) return true;  // Cycle!
        if (color[v] == 0 && hasCycle(v, color, adj)) return true;
    }
    color[u] = 2;  // Black
    return false;
}
```

---

### 4️⃣ CONNECTED COMPONENTS
```cpp
int countComponents(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }
    return count;
}

void dfs(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, adj, visited);
    }
}
```

---

### 5️⃣ DEGREE CALCULATION
```cpp
// In-degree for directed graph
vector<int> inDegree(n, 0);
for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
        inDegree[v]++;
    }
}

// Degree for undirected = adjacency list size
for (int i = 0; i < n; i++) {
    int degree = adj[i].size();
}
```

---

## 🎯 COMPANY FOCUS

### TCS
- Adjacency list building (70%)
- Graph types (65%)
- Cycle detection (60%)

### Infosys  
- All from TCS
- Connected components (75%)
- In-degree calculation (65%)

### Wipro
- Basics (60%)
- Cycle detection (55%)

---

## 🔥 COMMON MISTAKES

```cpp
❌ WRONG: Adjacency matrix for sparse graph
int adj[n][n];  // O(n²) space for few edges!

✅ RIGHT: Adjacency list for sparse
vector<int> adj[n];  // O(V+E) space
```

```cpp
❌ WRONG: Undirected edge only one way
adj[u].push_back(v);  // Missing reverse!

✅ RIGHT: Both ways
adj[u].push_back(v);
adj[v].push_back(u);
```

```cpp
❌ WRONG: Using < instead of != parent
else if (v < parent) return true;  // Wrong!

✅ RIGHT: Check against parent
else if (v != parent) return true;
```

---

## 📊 QUICK FORMULAS

```
Complete Graph: E = V(V-1)/2 (undirected)
Tree: E = V-1, acyclic, connected
Sum of degrees = 2×E (undirected)
Sum of in-degrees = Sum of out-degrees = E (directed)
```

---

## ✅ CHECKLIST

```
☐ Can build adjacency list
☐ Know directed vs undirected
☐ Can detect cycle (undirected)
☐ Can detect cycle (directed)
☐ Can count components
☐ Can calculate degree
☐ Know time: O(V+E)
```

---

**Master fundamentals, rest follows!** 💪
