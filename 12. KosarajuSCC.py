"""
Task: Find Strongly Connected Components (SCCs) using Kosaraju's Algorithm
Implement Kosaraju's algorithm to find all SCCs in a directed graph.
"""
def dfs1(u, adj, visited, order):
    visited[u] = True
    for v in adj[u]:
        if not visited[v]:
            dfs1(v, adj, visited, order)
    order.append(u)
def dfs2(u, rev, visited, comp):
    visited[u] = True
    comp.append(u)
    for v in rev[u]:
        if not visited[v]:
            dfs2(v, rev, visited, comp)
def kosaraju_scc(V, adj):
    visited = [False]*V
    order = []
    for u in range(V):
        if not visited[u]:
            dfs1(u, adj, visited, order)
    rev = [[] for _ in range(V)]
    for u in range(V):
        for v in adj[u]:
            rev[v].append(u)
    visited = [False]*V
    sccs = []
    for u in reversed(order):
        if not visited[u]:
            comp = []
            dfs2(u, rev, visited, comp)
            sccs.append(comp)
    return sccs
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[2,3], [0], [1], [4], []]
    print("SCCs:", kosaraju_scc(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
