"""
Task: Eulerian Path/Circuit
Given a graph, determine if an Eulerian path or circuit exists. An Eulerian path visits every edge exactly once.
"""
def eulerian_path_circuit(V, adj):
    odd = 0
    for u in range(V):
        if len(adj[u]) % 2 != 0:
            odd += 1
    if odd == 0:
        return "Eulerian Circuit"
    if odd == 2:
        return "Eulerian Path"
    return "None"
# Sample Test Case
if __name__ == "__main__":
    V = 5
    adj = [[1,2],[0,2],[0,1,3,4],[2,4],[2,3]]
    print("Eulerian:", eulerian_path_circuit(V, adj))
"""
Time Complexity: O(V)
Space Complexity: O(1)
"""
