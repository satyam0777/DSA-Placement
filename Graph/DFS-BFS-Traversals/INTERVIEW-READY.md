# 🎯 DFS & BFS TRAVERSALS - INTERVIEW READY
## Foundation for All Graph Algorithms

---

## 📊 TRAVERSAL FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 95%+ Graph problems)
```

**Overall Frequency:** TCS 80%, Infosys 90%, Wipro 75%

**Key Fact:** DFS + BFS = Foundation of 70%+ graph interview questions!

---

## 🔥 DFS (DEPTH FIRST SEARCH) ⭐⭐⭐

### **Frequency:**
- TCS: 85% | Infosys: 90% | Wipro: 75%

### **What is DFS?**
Go deep into one branch before backtracking

### **DFS Recursive (MOST COMMON):**

```cpp
void dfs(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";  // Process node
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);  // Recurse
        }
    }
}

// Main
vector<bool> visited(n, false);
for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        dfs(i, adj, visited);
    }
}
```

### **Dry Run:**

```
Graph:
    0 - 1 - 2
    |       |
    3 - 4 - 5

DFS from 0:
Visit 0 → Visit 1 → Visit 2 → Visit 5
        ↓
       Visit 3 → Visit 4
        
Order: 0, 1, 2, 5, 3, 4 (depends on order in adj list)
```

### **DFS Iterative (Using Stack):**

```cpp
void dfsIterative(int start, vector<int> adj[]) {
    stack<int> st;
    vector<bool> visited(n, false);
    
    st.push(start);
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";
            
            // Push neighbors (in reverse order for same order as recursive)
            for (int i = adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (!visited[v]) {
                    st.push(v);
                }
            }
        }
    }
}
```

### **DFS Applications:**
- Detect cycle
- Find connected components
- Topological sort
- Find bridges/articulation points
- Check if graph is bipartite
- Path finding

### **Time Complexity:** O(V + E)
**Space Complexity:** O(V) for recursion/stack

### **Interview Script:**

> "Sir, DFS means going as deep as possible before backtracking.
>
> I use recursion - mark node as visited, then recurse on all unvisited neighbors.
>
> When I hit a dead end, I backtrack and explore other branches.
>
> Time: O(V+E), Space: O(V) for visited array."

---

## 🔥 BFS (BREADTH FIRST SEARCH) ⭐⭐⭐

### **Frequency:**
- TCS: 75% | Infosys: 85% | Wipro: 70%

### **What is BFS?**
Explore level by level, all neighbors before going deeper

### **BFS Using Queue (ONLY WAY):**

```cpp
void bfs(int start, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        cout << u << " ";  // Process node
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;  // Mark before adding to queue
                q.push(v);
            }
        }
    }
}

// For multiple components
void bfsAll(vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i, adj, visited);  // Modified BFS
        }
    }
}

// Modified BFS for multiple components
void bfs(int start, vector<int> adj[], vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

### **Dry Run:**

```
Same Graph:
    0 - 1 - 2
    |       |
    3 - 4 - 5

BFS from 0:
Level 0: Visit 0
Level 1: Visit 1, 3
Level 2: Visit 2, 4
Level 3: Visit 5

Order: 0, 1, 3, 2, 4, 5 (level by level)
```

### **Key Difference from DFS:**

```
DFS: 0, 1, 2, 5, 3, 4  (Go deep)
BFS: 0, 1, 3, 2, 4, 5  (Level by level)
```

### **BFS Applications:**
- Shortest path in unweighted graph ⭐
- Level order traversal
- Finding connected components
- Check if graph is bipartite
- Closest node/neighbor search
- Social network problems

### **Time Complexity:** O(V + E)
**Space Complexity:** O(V) for queue and visited

### **Interview Script:**

> "Sir, BFS explores level by level using a queue.
>
> I push the start node, then while queue is not empty:
> - Pop a node
> - Process it
> - Push all unvisited neighbors
>
> This gives level-order traversal.
>
> Perfect for finding shortest path in unweighted graphs!
>
> Time: O(V+E), Space: O(V)."

---

## 🔥 DFS vs BFS COMPARISON ⭐⭐⭐

| Property | DFS | BFS |
|----------|-----|-----|
| **Data Structure** | Stack (Recursion) | Queue |
| **Order** | Deep (Preorder-like) | Level by level |
| **Time** | O(V+E) | O(V+E) |
| **Space** | O(V) recursion | O(V) queue |
| **When to Use** | Cycle, topological, connectivity | Shortest path, levels |
| **Shortest Path** | ❌ NO | ✅ YES (unweighted) |
| **Memory** | Can be more ⚠️ | Typically O(V) |
| **Backtracking** | ✅ Natural | ❌ Explicit |

---

## 🔥 PROBLEM 1: DETECT CYCLE (DFS) ⭐⭐⭐

### **Undirected Graph:**

```cpp
bool hasCycleUndirected(int u, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycleUndirected(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;  // Back edge = cycle
        }
    }
    
    return false;
}

// Main
vector<bool> visited(n, false);
for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        if (hasCycleUndirected(i, -1, adj, visited)) {
            cout << "Cycle exists!" << endl;
            return;
        }
    }
}
```

**Dry Run:**
```
0 - 1
|   |
2 - 3

DFS(0, -1): visited[0]=true
  DFS(1, 0): visited[1]=true
    DFS(3, 1): visited[3]=true
      Neighbor 2: DFS(2, 3)
        visited[2]=true
          Neighbor 0: visited[0]=true AND 0!=parent(3)
          Return true! → CYCLE FOUND
```

### **Directed Graph (Using Colors):**

```cpp
bool hasCycleDirected(int u, vector<int> color, vector<int> adj[]) {
    color[u] = 1;  // Gray (currently visiting)
    
    for (int v : adj[u]) {
        if (color[v] == 1) {
            return true;  // Back edge (gray to gray) = cycle
        }
        if (color[v] == 0 && hasCycleDirected(v, color, adj)) {
            return true;
        }
    }
    
    color[u] = 2;  // Black (completely visited)
    return false;
}

// Color scheme: 0=white (unvisited), 1=gray (visiting), 2=black (visited)
```

---

## 🔥 PROBLEM 2: CONNECTED COMPONENTS ⭐⭐⭐

### **Count Connected Components:**

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
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
```

**Example:**
```
0 - 1    3 - 4
|        
2        5

Components: 3
- Component 1: {0, 1, 2}
- Component 2: {3, 4}
- Component 3: {5}
```

---

## 🔥 PROBLEM 3: SHORTEST PATH (UNWEIGHTED) ⭐⭐⭐

### **BFS for Shortest Path:**

```cpp
vector<int> shortestPath(int n, vector<int> adj[], int start) {
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {  // Unvisited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist;
}

// Usage
vector<int> dist = shortestPath(n, adj, 0);
// dist[i] = shortest distance from 0 to i
```

**Example:**
```
0 - 1 - 2 - 3

Shortest paths from 0:
dist[0] = 0
dist[1] = 1
dist[2] = 2
dist[3] = 3
```

---

## 🔥 PROBLEM 4: BIPARTITE CHECK ⭐⭐⭐

### **Using BFS:**

```cpp
bool isBipartite(int n, vector<int> adj[]) {
    vector<int> color(n, -1);  // -1 = uncolored, 0/1 = colors
    
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;  // Same color = not bipartite
                    }
                }
            }
        }
    }
    
    return true;
}
```

**Dry Run:**
```
0 - 1 - 2

Color 0 as 0
  Neighbor 1 → Color as 1
    Neighbor 2 → Color as 0
      Neighbors: None new

Result: Bipartite! ✓
```

---

## 🎯 COMPANY-WISE TOP QUESTIONS

### **TCS:**
1. DFS Implementation (80%)
2. Cycle Detection (75%)
3. Connected Components (70%)
4. BFS Implementation (70%)

### **Infosys:**
1. BFS for Shortest Path (85%)
2. DFS (90%)
3. Cycle Detection (85%)
4. Bipartite Check (75%)

### **Wipro:**
1. DFS/BFS (both important) (75%)
2. Cycle Detection (60%)
3. Connected Components (65%)

---

## ⚠️ CRITICAL MISTAKES

```cpp
❌ WRONG: DFS without marking visited
void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);  // Infinite recursion!
    }
}

✅ RIGHT: Mark visited first
void dfs(int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, visited);
    }
}
```

```cpp
❌ WRONG: BFS without marking visited before adding to queue
for (int v : adj[u]) {
    if (dist[v] == -1) {
        q.push(v);
        dist[v] = dist[u] + 1;  // Too late!
    }
}

✅ RIGHT: Mark before adding
for (int v : adj[u]) {
    if (dist[v] == -1) {
        dist[v] = dist[u] + 1;  // Mark immediately
        q.push(v);
    }
}
```

---

## ✅ FINAL CHECKLIST

```
DFS:
☐ Can code recursive DFS
☐ Can code iterative DFS
☐ Can detect cycle
☐ Know time/space complexity

BFS:
☐ Can code BFS with queue
☐ Can find shortest path
☐ Can check bipartite
☐ Can handle multiple components

Applications:
☐ Can solve cycle detection
☐ Can count components
☐ Can find shortest path
☐ Can check bipartite
```

---

**You're DFS & BFS Ready!** 🚀

**Study Time:** 4-5 hours ⏱️

**Coverage:** 95%+ of traversal problems! ✅

**All the best!** 💪
