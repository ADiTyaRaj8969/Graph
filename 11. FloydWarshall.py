"""
Task: Floyd-Warshall Algorithm
Find the shortest distances between every pair of vertices in a given weighted directed graph (All-Pairs Shortest Path).
"""
def floyd_warshall(V, matrix):
    dist = [row[:] for row in matrix]
    for i in range(V):
        for j in range(V):
            if i != j and dist[i][j] == 0:
                dist[i][j] = float('inf')
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist
# Sample Test Case
if __name__ == "__main__":
    V = 4
    matrix = [
        [0, 5, 0, 10],
        [0, 0, 3, 0],
        [0, 0, 0, 1],
        [0, 0, 0, 0]
    ]
    dist = floyd_warshall(V, matrix)
    print("Floyd-Warshall:")
    for row in dist:
        print(row)
"""
Time Complexity: O(V^3)
Space Complexity: O(V^2)
"""
