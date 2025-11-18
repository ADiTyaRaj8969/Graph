/*
Task: Bipartite Graph Check
Determine if a graph can be colored with two colors such that no two adjacent vertices have the same
color. Application of BFS/DFS.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj)
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; ++i)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
// Sample Test Case
int main()
{
    int V = 4;
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << "Is Bipartite: " << (isBipartite(V, adj) ? "Yes" : "No") << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
