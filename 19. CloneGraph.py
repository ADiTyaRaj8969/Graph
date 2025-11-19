"""
Task: Clone Graph
Given a reference to a node in a connected undirected graph, return a deep copy (clone) of the graph.
"""
class Node:
    def __init__(self, val):
        self.val = val
        self.neighbors = []
def clone_graph(node, mp=None):
    if not node:
        return None
    if mp is None:
        mp = {}
    if node in mp:
        return mp[node]
    clone = Node(node.val)
    mp[node] = clone
    for n in node.neighbors:
        clone.neighbors.append(clone_graph(n, mp))
    return clone
# Sample Test Case
if __name__ == "__main__":
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n1.neighbors = [n2, n4]
    n2.neighbors = [n1, n3]
    n3.neighbors = [n2, n4]
    n4.neighbors = [n1, n3]
    clone = clone_graph(n1)
    print("Cloned Node Val:", clone.val)
"""
Time Complexity: O(V+E)
Space Complexity: O(V)
"""
