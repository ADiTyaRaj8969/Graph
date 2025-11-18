"""
Task: Dijkstra's Algorithm
Find the shortest path from a source node to all other nodes in a weighted graph with non-negative edge weights.
"""
import heapq
def dijkstra(V, adj, src):
    dist = [float('inf')]*V
    dist[src] = 0
    heap = [(0, src)]
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]: continue
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(heap, (dist[v], v))
    return dist
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[(1,2),(2,4)], [(2,1),(3,7)], [(4,3)], [(4,1)], []]
    print("Dijkstra:", dijkstra(V, adj, 0))
"""
Time Complexity: O((V+E)logV)
Space Complexity: O(V)
"""
