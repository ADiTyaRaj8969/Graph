"""
Task: Rotting Oranges
In a grid, each cell can be a fresh orange (1), a rotten orange (2), or empty (0). Every minute, any fresh orange adjacent to a rotten one becomes rotten. Find the minimum time required until no fresh oranges are left.
Application of Multi-Source BFS.
"""
from collections import deque
def oranges_rotting(grid):
    m, n = len(grid), len(grid[0])
    q = deque()
    fresh = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 2:
                q.append((i,j))
            elif grid[i][j] == 1:
                fresh += 1
    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    time = 0
    while q and fresh:
        for _ in range(len(q)):
            i,j = q.popleft()
            for di,dj in dirs:
                ni, nj = i+di, j+dj
                if 0<=ni<m and 0<=nj<n and grid[ni][nj]==1:
                    grid[ni][nj]=2
                    fresh -= 1
                    q.append((ni,nj))
        time += 1
    return time if fresh==0 else -1
# Sample Test Case
if __name__ == "__main__":
    grid = [
        [2,1,1],
        [1,1,0],
        [0,1,1]
    ]
    print("Min Time to Rot All Oranges:", oranges_rotting(grid))
"""
Time Complexity: O(m*n)
Space Complexity: O(m*n)
"""
