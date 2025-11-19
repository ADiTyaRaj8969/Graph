"""
Task: Detect Negative Weight Cycle
Use the Bellman-Ford algorithm to detect if a graph contains a cycle where the sum of the edge weights is negative.
"""
def has_negative_cycle(V, edges):
    dist = [0]*V
    for i in range(V):
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                if i == V-1:
                    return True
    return False
# Sample Test Case
if __name__ == "__main__":
    V = 4
    edges = [(0,1,1),(1,2,-1),(2,3,-1),(3,0,-1)]
    print("Has Negative Cycle:", has_negative_cycle(V, edges))
"""
Time Complexity: O(VE)
Space Complexity: O(V)
"""
