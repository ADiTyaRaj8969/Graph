"""
Task: Detect Cycle in Undirected Graph
Write a function to determine if a given undirected graph contains a cycle.
"""
def has_cycle_util(u, parent, adj, visited):
    visited[u] = True
    for v in adj[u]:
        if not visited[v]:
            if has_cycle_util(v, u, adj, visited):
                return True
        elif v != parent:
            return True
    return False
def has_cycle_undirected(V, adj):
    visited = [False]*V
    for u in range(V):
        if not visited[u]:
            if has_cycle_util(u, -1, adj, visited):
                return True
    return False
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1,2], [0,3,4], [0], [1], [1]]
    print("Cycle (Undirected):", has_cycle_undirected(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
