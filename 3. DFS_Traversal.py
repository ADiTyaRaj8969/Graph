"""
Task: DFS Traversal of a Graph (Recursive and Iterative)
Given a source vertex, perform Depth-First Search traversal (both recursive and iterative).
"""
def dfs_recursive_util(u, adj, visited):
    visited[u] = True
    print(u, end=" ")
    for v in adj[u]:
        if not visited[v]:
            dfs_recursive_util(v, adj, visited)
def dfs_recursive(V, adj, src):
    visited = [False]*V
    print("DFS (Recursive):", end=" ")
    dfs_recursive_util(src, adj, visited)
    print()
def dfs_iterative(V, adj, src):
    visited = [False]*V
    stack = [src]
    print("DFS (Iterative):", end=" ")
    while stack:
        u = stack.pop()
        if not visited[u]:
            visited[u] = True
            print(u, end=" ")
            for v in reversed(adj[u]):
                if not visited[v]:
                    stack.append(v)
    print()
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1,2], [0,3,4], [0], [1], [1]]
    dfs_recursive(V, adj, 0)
    dfs_iterative(V, adj, 0)
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
