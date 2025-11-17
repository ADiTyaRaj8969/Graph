"""
Task: Implement Graph Representation using both Adjacency List and Adjacency Matrix.
Includes: BFS, DFS (recursive & iterative), cycle detection (undirected & directed), topological sort, connected components, Dijkstra, Prim, Kruskal, Floyd-Warshall, SCC (Kosaraju), and more.
Each function includes a sample test case at the bottom.
"""

from collections import deque, defaultdict
import heapq

class Graph:
    def __init__(self, V):
        self.V = V
        self.adjList = [[] for _ in range(V)]
        self.adjMatrix = [[0]*V for _ in range(V)]
    def add_edge(self, u, v, w=1, directed=False):
        self.adjList[u].append(v)
        self.adjMatrix[u][v] = w
        if not directed:
            self.adjList[v].append(u)
            self.adjMatrix[v][u] = w

# BFS Traversal
def bfs(g, src):
    visited = [False]*g.V
    q = deque([src])
    visited[src] = True
    print("BFS:", end=" ")
    while q:
        u = q.popleft()
        print(u, end=" ")
        for v in g.adjList[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)
    print()

# DFS Traversal (Recursive)
def dfs_util(g, u, visited):
    visited[u] = True
    print(u, end=" ")
    for v in g.adjList[u]:
        if not visited[v]:
            dfs_util(g, v, visited)
def dfs(g, src):
    visited = [False]*g.V
    print("DFS (Recursive):", end=" ")
    dfs_util(g, src, visited)
    print()
# DFS Traversal (Iterative)
def dfs_iterative(g, src):
    visited = [False]*g.V
    stack = [src]
    print("DFS (Iterative):", end=" ")
    while stack:
        u = stack.pop()
        if not visited[u]:
            visited[u] = True
            print(u, end=" ")
            for v in reversed(g.adjList[u]):
                if not visited[v]:
                    stack.append(v)
    print()

# Detect Cycle in Undirected Graph (DFS)
def has_cycle_undirected_util(g, u, parent, visited):
    visited[u] = True
    for v in g.adjList[u]:
        if not visited[v]:
            if has_cycle_undirected_util(g, v, u, visited):
                return True
        elif v != parent:
            return True
    return False
def has_cycle_undirected(g):
    visited = [False]*g.V
    for u in range(g.V):
        if not visited[u]:
            if has_cycle_undirected_util(g, u, -1, visited):
                return True
    return False

# Detect Cycle in Directed Graph (DFS)
def has_cycle_directed_util(g, u, visited, recStack):
    visited[u] = recStack[u] = True
    for v in g.adjList[u]:
        if not visited[v]:
            if has_cycle_directed_util(g, v, visited, recStack):
                return True
        elif recStack[v]:
            return True
    recStack[u] = False
    return False
def has_cycle_directed(g):
    visited = [False]*g.V
    recStack = [False]*g.V
    for u in range(g.V):
        if not visited[u]:
            if has_cycle_directed_util(g, u, visited, recStack):
                return True
    return False

# Topological Sort (Kahn's Algorithm)
def topological_sort(g):
    in_degree = [0]*g.V
    for u in range(g.V):
        for v in g.adjList[u]:
            in_degree[v] += 1
    q = deque([i for i in range(g.V) if in_degree[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in g.adjList[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)
    return order

# Number of Connected Components
def count_connected_components(g):
    visited = [False]*g.V
    count = 0
    def dfs_cc(u):
        visited[u] = True
        for v in g.adjList[u]:
            if not visited[v]:
                dfs_cc(v)
    for u in range(g.V):
        if not visited[u]:
            count += 1
            dfs_cc(u)
    return count

# Dijkstra's Algorithm
def dijkstra(g, src):
    dist = [float('inf')]*g.V
    dist[src] = 0
    heap = [(0, src)]
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]: continue
        for v in range(g.V):
            if g.adjMatrix[u][v] and dist[v] > dist[u] + g.adjMatrix[u][v]:
                dist[v] = dist[u] + g.adjMatrix[u][v]
                heapq.heappush(heap, (dist[v], v))
    return dist

# Prim's Algorithm
def prim_mst(g):
    key = [float('inf')]*g.V
    parent = [-1]*g.V
    in_mst = [False]*g.V
    key[0] = 0
    for _ in range(g.V-1):
        u = min((k, v) for v, k in enumerate(key) if not in_mst[v])[1]
        in_mst[u] = True
        for v in range(g.V):
            if g.adjMatrix[u][v] and not in_mst[v] and g.adjMatrix[u][v] < key[v]:
                key[v] = g.adjMatrix[u][v]
                parent[v] = u
    return sum(key)

# Kruskal's Algorithm (DSU)
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0]*n
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def unite(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr: return
        if self.rank[xr] < self.rank[yr]:
            self.parent[xr] = yr
        elif self.rank[xr] > self.rank[yr]:
            self.parent[yr] = xr
        else:
            self.parent[yr] = xr
            self.rank[xr] += 1
class Edge:
    def __init__(self, u, v, w):
        self.u, self.v, self.w = u, v, w
def kruskal_mst(V, edges):
    edges.sort(key=lambda e: e.w)
    dsu = DSU(V)
    total = 0
    for e in edges:
        if dsu.find(e.u) != dsu.find(e.v):
            dsu.unite(e.u, e.v)
            total += e.w
    return total

# Floyd-Warshall Algorithm
def floyd_warshall(g):
    dist = [row[:] for row in g.adjMatrix]
    for i in range(g.V):
        for j in range(g.V):
            if i != j and dist[i][j] == 0:
                dist[i][j] = float('inf')
    for k in range(g.V):
        for i in range(g.V):
            for j in range(g.V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

# Kosaraju's Algorithm for SCC
def dfs_kosaraju(g, u, visited, order):
    visited[u] = True
    for v in g.adjList[u]:
        if not visited[v]:
            dfs_kosaraju(g, v, visited, order)
    order.append(u)
def dfs_reverse(rev, u, visited, comp):
    visited[u] = True
    comp.append(u)
    for v in rev[u]:
        if not visited[v]:
            dfs_reverse(rev, v, visited, comp)
def kosaraju_scc(g):
    visited = [False]*g.V
    order = []
    for u in range(g.V):
        if not visited[u]:
            dfs_kosaraju(g, u, visited, order)
    rev = [[] for _ in range(g.V)]
    for u in range(g.V):
        for v in g.adjList[u]:
            rev[v].append(u)
    visited = [False]*g.V
    sccs = []
    for u in reversed(order):
        if not visited[u]:
            comp = []
            dfs_reverse(rev, u, visited, comp)
            sccs.append(comp)
    return sccs

# Sample Test Case
if __name__ == "__main__":
    g = Graph(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    bfs(g, 0)
    dfs(g, 0)
    dfs_iterative(g, 0)
    print("Cycle (Undirected):", has_cycle_undirected(g))
    print("Cycle (Directed):", has_cycle_directed(g))
    print("Topological Sort:", topological_sort(g))
    print("Connected Components:", count_connected_components(g))
    print("Dijkstra:", dijkstra(g, 0))
    print("Prim's MST:", prim_mst(g))
    edges = [Edge(0,1,1), Edge(0,2,1), Edge(1,3,1), Edge(1,4,1)]
    print("Kruskal's MST:", kruskal_mst(5, edges))
    fw = floyd_warshall(g)
    print("Floyd-Warshall:")
    for row in fw:
        print(row)
    sccs = kosaraju_scc(g)
    print("SCCs:", sccs)

"""
Time Complexity (TC) and Space Complexity (SC):
- Graph Representation: TC = O(1) per edge insert, SC = O(V+E) for list, O(V^2) for matrix
- BFS/DFS: TC = O(V+E), SC = O(V)
- Cycle Detection: TC = O(V+E), SC = O(V)
- Topological Sort: TC = O(V+E), SC = O(V)
- Connected Components: TC = O(V+E), SC = O(V)
- Dijkstra: TC = O((V+E)logV), SC = O(V)
- Prim: TC = O(V^2), SC = O(V)
- Kruskal: TC = O(ElogE), SC = O(V)
- Floyd-Warshall: TC = O(V^3), SC = O(V^2)
- Kosaraju's SCC: TC = O(V+E), SC = O(V)
"""
