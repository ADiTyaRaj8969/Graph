"""
Task: Detect Cycle in Directed Graph
Write a function to determine if a given directed graph contains a cycle.
"""
def has_cycle_util(u, adj, visited, recStack):
    visited[u] = recStack[u] = True
    for v in adj[u]:
        if not visited[v]:
            if has_cycle_util(v, adj, visited, recStack):
                return True
        elif recStack[v]:
            return True
    recStack[u] = False
    return False
def has_cycle_directed(V, adj):
    visited = [False]*V
    recStack = [False]*V
    for u in range(V):
        if not visited[u]:
            if has_cycle_util(u, adj, visited, recStack):
                return True
    return False
# Sample Test Case
if __name__ == "__main__":
    V = 4
    adj = [[1], [2], [3], [1]] # cycle
    print("Cycle (Directed):", has_cycle_directed(V, adj))
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
