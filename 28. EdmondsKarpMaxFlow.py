"""
Task: Maximum Flow (Edmonds-Karp Algorithm)
Implement the Edmonds-Karp algorithm to find the maximum flow from a source to a sink in a flow network.
"""
from collections import deque
def bfs(rGraph, s, t, parent):
    V = len(rGraph)
    for i in range(V):
        parent[i] = -1
    q = deque([(s, float('inf'))])
    parent[s] = -2
    while q:
        u, flow = q.popleft()
        for v in range(V):
            if parent[v] == -1 and rGraph[u][v] > 0:
                parent[v] = u
                new_flow = min(flow, rGraph[u][v])
                if v == t:
                    return new_flow
                q.append((v, new_flow))
    return 0
def edmonds_karp(graph, s, t):
    V = len(graph)
    rGraph = [row[:] for row in graph]
    parent = [-1]*V
    flow = 0
    while True:
        new_flow = bfs(rGraph, s, t, parent)
        if not new_flow:
            break
        flow += new_flow
        v = t
        while v != s:
            u = parent[v]
            rGraph[u][v] -= new_flow
            rGraph[v][u] += new_flow
            v = u
    return flow
# Sample Test Case
if __name__ == "__main__":
    graph = [
        [0,16,13,0,0,0],
        [0,0,10,12,0,0],
        [0,4,0,0,14,0],
        [0,0,9,0,0,20],
        [0,0,0,7,0,4],
        [0,0,0,0,0,0]
    ]
    print("Max Flow:", edmonds_karp(graph, 0, 5))
"""
Time Complexity: O(VE^2)
Space Complexity: O(V^2)
"""
