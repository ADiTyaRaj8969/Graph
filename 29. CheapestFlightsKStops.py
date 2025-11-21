"""
Task: Cheapest Flights Within K Stops
Find the cheapest price for a flight route from a source to a destination with at most k stops. (A variation of Bellman-Ford or Dijkstra's).
"""
from collections import deque
def find_cheapest_price(n, flights, src, dst, K):
    adj = [[] for _ in range(n)]
    for u, v, w in flights:
        adj[u].append((v, w))
    dist = [float('inf')]*n
    dist[src] = 0
    q = deque([(src, 0)])
    stops = 0
    while q and stops <= K:
        sz = len(q)
        temp = dist[:]
        for _ in range(sz):
            u, cost = q.popleft()
            for v, w in adj[u]:
                if cost + w < temp[v]:
                    temp[v] = cost + w
                    q.append((v, temp[v]))
        dist = temp
        stops += 1
    return -1 if dist[dst] == float('inf') else dist[dst]
# Sample Test Case
if __name__ == "__main__":
    n, src, dst, K = 4, 0, 3, 1
    flights = [(0,1,100),(1,2,100),(2,3,100),(0,2,500)]
    print("Cheapest Price:", find_cheapest_price(n, flights, src, dst, K))
"""
Time Complexity: O(K*E)
Space Complexity: O(V)
"""
