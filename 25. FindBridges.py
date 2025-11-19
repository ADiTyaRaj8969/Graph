"""
Task: Find Bridges in a Graph
An edge in an undirected graph is a bridge if removing it increases the number of connected components. Find all bridges in a given graph.
"""
def dfs(u, parent, adj, disc, low, time, bridges):
    disc[u] = low[u] = time[0] = time[0]+1
    for v in adj[u]:
        if v == parent:
            continue
        if not disc[v]:
            dfs(v, u, adj, disc, low, time, bridges)
            low[u] = min(low[u], low[v])
            if low[v] > disc[u]:
                bridges.append((u,v))
        else:
            low[u] = min(low[u], disc[v])
def find_bridges(V, adj):
    disc = [0]*V
    low = [0]*V
    bridges = []
    time = [0]
    for u in range(V):
        if not disc[u]:
            dfs(u, -1, adj, disc, low, time, bridges)
    return bridges
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1,2],[0,2],[0,1,3,4],[2,4],[2,3]]
    print("Bridges:", find_bridges(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
