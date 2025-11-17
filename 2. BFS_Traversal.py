"""
Task: BFS Traversal of a Graph
Given a source vertex, perform Breadth-First Search traversal.
"""
from collections import deque

def bfs(V, adj, src):
    visited = [False]*V
    q = deque([src])
    visited[src] = True
    print("BFS:", end=" ")
    while q:
        u = q.popleft()
        print(u, end=" ")
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)
    print()

# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1,2], [0,3,4], [0], [1], [1]]
    bfs(V, adj, 0)
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
