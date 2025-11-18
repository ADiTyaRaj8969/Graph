"""
Task: Prim's Algorithm
Find the Minimum Spanning Tree (MST) for a weighted, undirected graph.
"""
import heapq
def prim_mst(V, adj):
    key = [float('inf')]*V
    in_mst = [False]*V
    key[0] = 0
    total = 0
    heap = [(0, 0)]
    while heap:
        k, u = heapq.heappop(heap)
        if in_mst[u]: continue
        in_mst[u] = True
        total += k
        for v, w in adj[u]:
            if not in_mst[v] and w < key[v]:
                key[v] = w
                heapq.heappush(heap, (key[v], v))
    return total
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[(1,2),(3,6)], [(0,2),(2,3),(3,8),(4,5)], [(1,3),(4,7)], [(0,6),(1,8)], [(1,5),(2,7)]]
    print("Prim's MST:", prim_mst(V, adj))
"""
Time Complexity: O((V+E)logV)
Space Complexity: O(V)
"""
