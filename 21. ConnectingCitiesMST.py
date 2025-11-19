"""
Task: Connecting Cities with Minimum Cost
There are n cities and a list of connections, where each connection has a cost. Find the minimum cost to connect all cities.
Application of MST (Prim's or Kruskal's Algorithm).
"""
class DSU:
    def __init__(self, n):
        self.parent = list(range(n+1))
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def unite(self, x, y):
        self.parent[self.find(x)] = self.find(y)
def min_cost_to_connect_cities(n, connections):
    connections.sort(key=lambda e: e[2])
    dsu = DSU(n)
    total = 0
    count = 0
    for u, v, w in connections:
        if dsu.find(u) != dsu.find(v):
            dsu.unite(u, v)
            total += w
            count += 1
    return total if count == n-1 else -1
# Sample Test Case
if __name__ == "__main__":
    n = 4
    connections = [(1,2,3),(2,3,4),(3,4,5),(1,4,1)]
    print("Min Cost to Connect Cities:", min_cost_to_connect_cities(n, connections))
"""
Time Complexity: O(ElogE)
Space Complexity: O(V)
"""
