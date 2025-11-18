/*
Task: Rotting Oranges
In a grid, each cell can be a fresh orange (1), a rotten orange (2), or empty (0). Every minute, any
fresh orange adjacent to a rotten one becomes rotten. Find the minimum time required until no fresh
oranges are left. Application of Multi-Source BFS.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0, time = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                fresh++;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty() && fresh)
    {
        int sz = q.size();
        while (sz--)
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto& d : dirs)
            {
                int ni = i + d.first, nj = j + d.second;
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 1)
                {
                    grid[ni][nj] = 2;
                    fresh--;
                    q.push({ni, nj});
                }
            }
        }
        time++;
    }
    return fresh == 0 ? time : -1;
}
// Sample Test Case
int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Min Time to Rot All Oranges: " << orangesRotting(grid) << endl;
    return 0;
}
/*
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/
