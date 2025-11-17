"""
Task: Number of Connected Components in an Undirected Graph
Count the number of separate, disconnected subgraphs.
"""
def dfs(u, adj, visited):
    visited[u] = True
    for v in adj[u]:
        if not visited[v]:
            dfs(v, adj, visited)
def count_connected_components(V, adj):
    visited = [False]*V
    count = 0
    for u in range(V):
        if not visited[u]:
            count += 1
            dfs(u, adj, visited)
    return count
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1], [0], [3], [2], []]
    print("Connected Components:", count_connected_components(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
