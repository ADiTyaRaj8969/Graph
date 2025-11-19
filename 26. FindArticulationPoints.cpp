/*
Task: Find Articulation Points
A vertex in an undirected graph is an articulation point if removing it (and its edges) increases
the number of connected components. Find all articulation points.
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
         int& time, vector<bool>& ap)
{
    disc[u] = low[u] = ++time;
    int children = 0;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        if (!disc[v])
        {
            children++;
            dfs(v, u, adj, disc, low, time, ap);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (parent == -1 && children > 1)
        ap[u] = true;
}
vector<int> findArticulationPoints(int V, vector<vector<int>>& adj)
{
    vector<int> disc(V, 0), low(V, 0);
    vector<bool> ap(V, false);
    int time = 0;
    for (int u = 0; u < V; ++u)
        if (!disc[u])
            dfs(u, -1, adj, disc, low, time, ap);
    vector<int> res;
    for (int i = 0; i < V; ++i)
        if (ap[i])
            res.push_back(i);
    return res;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {2, 3}};
    auto aps = findArticulationPoints(V, adj);
    cout << "Articulation Points: ";
    for (int v : aps) cout << v << " ";
    cout << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
