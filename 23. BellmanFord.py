"""
Task: Bellman-Ford Algorithm
Find the shortest path from a source node to all other nodes in a weighted graph that may contain negative edge weights.
"""
def bellman_ford(V, edges, src):
    dist = [float('inf')]*V
    dist[src] = 0
    for _ in range(V-1):
        for u, v, w in edges:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    return dist
# Sample Test Case
if __name__ == "__main__":
    V = 5
    edges = [(0,1,-1),(0,2,4),(1,2,3),(1,3,2),(1,4,2),(3,2,5),(3,1,1),(4,3,-3)]
    print("Bellman-Ford:", bellman_ford(V, edges, 0))
"""
Time Complexity: O(VE)
Space Complexity: O(V)
"""
