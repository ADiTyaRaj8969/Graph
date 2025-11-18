"""
Task: Bipartite Graph Check
Determine if a graph can be colored with two colors such that no two adjacent vertices have the same color.
Application of BFS/DFS.
"""
from collections import deque
def is_bipartite(V, adj):
    color = [-1]*V
    for i in range(V):
        if color[i] == -1:
            q = deque([i])
            color[i] = 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if color[v] == -1:
                        color[v] = 1 - color[u]
                        q.append(v)
                    elif color[v] == color[u]:
                        return False
    return True
# Sample Test Case
if __name__ == "__main__":
    V = 4
    adj = [[1,3],[0,2],[1,3],[0,2]]
    print("Is Bipartite:", is_bipartite(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
