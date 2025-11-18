"""
Task: Kruskal's Algorithm
Find the Minimum Spanning Tree (MST) using the Disjoint Set Union (DSU) data structure.
"""
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
# Sample Test Case
if __name__ == "__main__":
    V = 4
    edges = [Edge(0,1,10), Edge(0,2,6), Edge(0,3,5), Edge(1,3,15), Edge(2,3,4)]
    print("Kruskal's MST:", kruskal_mst(V, edges))
"""
Time Complexity: O(ElogE)
Space Complexity: O(V)
"""
