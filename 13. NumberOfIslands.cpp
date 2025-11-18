/*
Task: Number of Islands
Given a 2D grid map of '1's (land) and '0's (water), count the number of islands.
Application of BFS/DFS.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1')
        return;
    grid[i][j] = '2';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}
int numIslands(vector<vector<char>>& grid)
{
    if (grid.empty())
        return 0;
    int m = grid.size(), n = grid[0].size(), count = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j);
            }
    return count;
}
// Sample Test Case
int main()
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}
/*
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/
