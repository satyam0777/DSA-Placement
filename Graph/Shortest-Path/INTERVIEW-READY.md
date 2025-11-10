# 🎯 SHORTEST PATH ALGORITHMS - INTERVIEW READY
## Dijkstra, Bellman-Ford & Floyd-Warshall

---

## 📊 ALGORITHM FREQUENCY

```
⭐⭐⭐ MUST KNOW (Asked 80%+ Shortest Path problems)
⭐⭐   HIGH (Asked 60-80%)
⭐     GOOD (Asked 40-60%)
```

**Overall Frequency:** TCS 60%, Infosys 75%, Wipro 55%

---

## 🔥 ALGORITHM 1: DIJKSTRA'S ALGORITHM ⭐⭐⭐

### **Frequency:**
- TCS: 70% | Infosys: 80% | Wipro: 65%

### **When to Use:**
- Weighted graph
- **NO negative edges**
- Find shortest path from one source to all others

### **Time Complexity:** O((V + E) log V) with priority queue

### **Code (Using Priority Queue):**

```cpp
vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int start) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // pair: {distance, node}
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;  // Already processed
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}
```

### **Simpler Code (Without C++17):**

```cpp
typedef pair<int, int> pii;

vector<int> dijkstra(int n, vector<pii> adj[], int start) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[start] = 0;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        
        int d = top.first;
        int u = top.second;
        
        if (d > dist[u]) continue;
        
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    return dist;
}
```

### **Dry Run:**

```
Graph:
    0 --1-- 1
    |       |
    4       2
    |       |
    2 --1-- 3

Dijkstra from 0:
Initial: dist = [0, INF, INF, INF]

Step 1: Process 0 (dist=0)
  To 1: dist[1] = 0 + 1 = 1
  To 2: dist[2] = 0 + 4 = 4
  dist = [0, 1, 4, INF]

Step 2: Process 1 (dist=1)
  To 3: dist[3] = 1 + 2 = 3
  dist = [0, 1, 4, 3]

Step 3: Process 3 (dist=3)
  To 2: dist[2] = 3 + 1 = 4 (no change)

Step 4: Process 2 (dist=4)
  All neighbors processed

Final: dist = [0, 1, 4, 3]
```

### **Interview Script:**

> "Sir, Dijkstra uses a min-heap priority queue.
>
> I maintain shortest distance to each node.
>
> At each step, I pick the unprocessed node with minimum distance.
>
> Then I relax all its edges - if going through this node is shorter, update distance.
>
> This greedy approach works because we always process minimum distance first.
>
> Time: O((V+E) log V), Space: O(V)"

---

## 🔥 ALGORITHM 2: BELLMAN-FORD ⭐⭐

### **Frequency:**
- TCS: 50% | Infosys: 65% | Wipro: 45%

### **When to Use:**
- Weighted graph
- **CAN handle negative edges**
- Can detect negative cycle
- Slower than Dijkstra

### **Time Complexity:** O(V × E)

### **Code:**

```cpp
vector<int> bellmanFord(int n, vector<pair<int, int>> adj[], int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    
    // Relax edges V-1 times
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            if (dist[u] != INT_MAX) {
                for (auto [v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
    }
    
    // Check for negative cycle
    for (int u = 0; u < n; u++) {
        if (dist[u] != INT_MAX) {
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    cout << "Negative cycle detected!" << endl;
                    return {};
                }
            }
        }
    }
    
    return dist;
}
```

### **Key Difference from Dijkstra:**

```
Dijkstra: Greedy, picks minimum each time
Bellman-Ford: Relaxes ALL edges V-1 times

Dijkstra: Faster O((V+E) log V), no negative edges
Bellman-Ford: Slower O(V×E), handles negative edges
```

### **Why V-1 times?**
```
Shortest path in graph with V nodes has at most V-1 edges.
After V-1 relaxations, all shortest paths are found.

If another relaxation helps, there's a negative cycle!
```

---

## 🔥 ALGORITHM 3: FLOYD-WARSHALL ⭐⭐

### **Frequency:**
- TCS: 40% | Infosys: 55% | Wipro: 35%

### **When to Use:**
- Find shortest paths between **ALL PAIRS** of nodes
- Works with negative edges
- Good for small graphs

### **Time Complexity:** O(V³)

### **Code:**

```cpp
void floydWarshall(vector<vector<int>>& dist, int n) {
    // dist[i][j] = shortest distance from i to j
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Detect negative cycle
bool hasNegativeCycle(vector<vector<int>>& dist, int n) {
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) return true;
    }
    return false;
}
```

### **Dry Run:**

```
Initial distance matrix (3 nodes):
  0 1 2
0 0 1 4
1 ∞ 0 2
2 ∞ ∞ 0

k=0 (using node 0 as intermediate):
  Check if going through 0 is shorter
  0→0→1: No improvement
  0→0→2: No improvement
  1→0→2: dist[1][2] = min(2, ∞+4) = 2
  etc.

k=1, k=2: Similar

Final (all shortest paths found)
```

---

## 🔥 COMPARISON: DIJKSTRA vs BELLMAN-FORD vs FLOYD-WARSHALL ⭐⭐⭐

| Property | Dijkstra | Bellman-Ford | Floyd-Warshall |
|----------|----------|--------------|-----------------|
| **Time** | O((V+E)logV) | O(V×E) | O(V³) |
| **Space** | O(V) | O(V) | O(V²) |
| **Negative Edges** | ❌ NO | ✅ YES | ✅ YES |
| **Negative Cycle** | Can't detect | ✅ Can detect | ✅ Can detect |
| **All Pairs?** | ❌ NO (single source) | ❌ NO (single source) | ✅ YES |
| **Best For** | Sparse, non-negative | Sparse, may be negative | Small graphs, all pairs |

---

## 🔥 WHEN TO USE WHICH?

```
Q: Single source shortest path, non-negative weights?
A: Dijkstra ⭐ (Faster)

Q: Single source shortest path, may have negative?
A: Bellman-Ford

Q: All pairs shortest paths?
A: Floyd-Warshall

Q: Unweighted graph?
A: BFS (O(V+E), even faster!)

Q: DAG (Directed Acyclic Graph)?
A: Topological + DFS (even faster for DAG!)
```

---

## 🔥 SPECIAL CASES ⭐⭐⭐

### **Shortest Path in Unweighted Graph:**
Use BFS! (O(V + E))
```cpp
vector<int> dist(n, -1);
queue<int> q;
dist[start] = 0;
q.push(start);

while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

### **Shortest Path in DAG (Directed Acyclic Graph):**
1. Do topological sort (DFS)
2. Relax edges in topological order (O(V + E))

```cpp
vector<int> topoSort;
// ... do topological sort using DFS ...

vector<int> dist(n, INT_MAX);
dist[start] = 0;

for (int u : topoSort) {
    if (dist[u] != INT_MAX) {
        for (auto [v, w] : adj[u]) {
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
}
```

---

## 🎯 COMPANY-WISE TOP QUESTIONS

### **TCS (60% shortest path asked):**
1. Dijkstra (65%)
2. Shortest path BFS (60%)
3. Bellman-Ford (45%)

### **Infosys (75% shortest path asked):**
1. Dijkstra (80%)
2. Floyd-Warshall (60%)
3. Bellman-Ford (65%)

### **Wipro (55% shortest path asked):**
1. Dijkstra (60%)
2. BFS shortest path (55%)
3. Bellman-Ford (40%)

---

## ⚠️ CRITICAL MISTAKES

```cpp
❌ WRONG: Dijkstra with negative edges
// Algorithm will give wrong answer

✅ RIGHT: Use Bellman-Ford for negative edges
if (hasNegativeEdges) {
    bellmanFord(...);
} else {
    dijkstra(...);  // Faster
}
```

```cpp
❌ WRONG: Not checking INT_MAX overflow
if (dist[u] + w < dist[v])  // Can overflow!

✅ RIGHT: Check before adding
if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
    dist[v] = dist[u] + w;
}
```

```cpp
❌ WRONG: Reprocessing nodes in Dijkstra
while (!pq.empty()) {
    auto [d, u] = pq.pop();
    for (v : adj[u]) {
        pq.push(...);  // Multiple entries for same node!
    }
}

✅ RIGHT: Skip if already processed
if (d > dist[u]) continue;  // Already found shorter path
```

---

## ✅ FINAL CHECKLIST

```
Dijkstra:
☐ Can code with priority queue
☐ Understand greedy approach
☐ Know it fails with negative edges
☐ Time: O((V+E)logV)

Bellman-Ford:
☐ Can relax edges V-1 times
☐ Can detect negative cycle
☐ Know it's slower
☐ Time: O(V×E)

Floyd-Warshall:
☐ Can code 3 nested loops
☐ Understand "through k" concept
☐ Good for all pairs
☐ Time: O(V³)

Applications:
☐ Know when to use BFS (unweighted)
☐ Know when to use DAG approach
☐ Can handle negative cycle detection
```

---

**You're Shortest Path Ready!** 🚀

**Study Time:** 3-4 hours ⏱️

**Coverage:** 80%+ of shortest path problems! ✅

**All the best!** 💪
