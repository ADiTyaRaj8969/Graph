"""
Task: Number of Islands
Given a 2D grid map of '1's (land) and '0's (water), count the number of islands.
Application of BFS/DFS.
"""
def dfs(grid, i, j):
    m, n = len(grid), len(grid[0])
    if i < 0 or j < 0 or i >= m or j >= n or grid[i][j] != '1':
        return
    grid[i][j] = '2'
    dfs(grid, i+1, j)
    dfs(grid, i-1, j)
    dfs(grid, i, j+1)
    dfs(grid, i, j-1)
def num_islands(grid):
    if not grid: return 0
    m, n = len(grid), len(grid[0])
    count = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '1':
                count += 1
                dfs(grid, i, j)
    return count
# Sample Test Case
if __name__ == "__main__":
    grid = [
        ['1','1','0','0','0'],
        ['1','1','0','0','0'],
        ['0','0','1','0','0'],
        ['0','0','0','1','1']
    ]
    print("Number of Islands:", num_islands(grid))
"""
Time Complexity: O(m*n)
Space Complexity: O(m*n)
"""
