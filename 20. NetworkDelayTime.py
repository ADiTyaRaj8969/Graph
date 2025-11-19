"""
Task: Network Delay Time
Given a network of n nodes, and a list of travel times as directed edges. If a signal is sent from a source node, find how long it will take for all nodes to receive the signal.
Application of Dijkstra's Algorithm.
"""
import heapq
def network_delay_time(times, n, k):
    adj = [[] for _ in range(n+1)]
    for u,v,w in times:
        adj[u].append((v,w))
    dist = [float('inf')] * (n+1)
    dist[k] = 0
    heap = [(0, k)]
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]: continue
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(heap, (dist[v], v))
    ans = 0
    for i in range(1, n+1):
        if dist[i] == float('inf'):
            return -1
        ans = max(ans, dist[i])
    return ans
# Sample Test Case
if __name__ == "__main__":
    times = [[2,1,1],[2,3,1],[3,4,1]]
    n, k = 4, 2
    print("Network Delay Time:", network_delay_time(times, n, k))
"""
Time Complexity: O((V+E)logV)
Space Complexity: O(V+E)
"""
