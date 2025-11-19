"""
Task: Find Articulation Points
A vertex in an undirected graph is an articulation point if removing it (and its edges) increases the number of connected components. Find all articulation points.
"""
def dfs(u, parent, adj, disc, low, time, ap):
    disc[u] = low[u] = time[0] = time[0]+1
    children = 0
    for v in adj[u]:
        if v == parent:
            continue
        if not disc[v]:
            children += 1
            dfs(v, u, adj, disc, low, time, ap)
            low[u] = min(low[u], low[v])
            if parent != -1 and low[v] >= disc[u]:
                ap[u] = True
        else:
            low[u] = min(low[u], disc[v])
    if parent == -1 and children > 1:
        ap[u] = True
def find_articulation_points(V, adj):
    disc = [0]*V
    low = [0]*V
    ap = [False]*V
    time = [0]
    for u in range(V):
        if not disc[u]:
            dfs(u, -1, adj, disc, low, time, ap)
    return [i for i, v in enumerate(ap) if v]
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1,2],[0,2],[0,1,3,4],[2,4],[2,3]]
    print("Articulation Points:", find_articulation_points(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
