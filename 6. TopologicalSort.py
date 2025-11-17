"""
Task: Topological Sort of a Directed Acyclic Graph (DAG)
Find a linear ordering of vertices such that for every directed edge u->v, u comes before v in the ordering.
"""
from collections import deque
def topological_sort(V, adj):
    in_degree = [0]*V
    for u in range(V):
        for v in adj[u]:
            in_degree[v] += 1
    q = deque([i for i in range(V) if in_degree[i] == 0])
    order = []
    while q:
        u = q.popleft()
        order.append(u)
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)
    return order
# Sample Test Case
if __name__ == "__main__":
    V = 6
    adj = [[], [], [3], [1], [0,1], [2,0]]
    print("Topological Sort:", topological_sort(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
