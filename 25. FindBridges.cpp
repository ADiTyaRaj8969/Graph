/*
Task: Find Bridges in a Graph
An edge in an undirected graph is a bridge if removing it increases the number of connected
components. Find all bridges in a given graph.
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
         int& time, vector<pair<int, int>>& bridges)
{
    disc[u] = low[u] = ++time;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        if (!disc[v])
        {
            dfs(v, u, adj, disc, low, time, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                bridges.push_back({u, v});
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}
vector<pair<int, int>> findBridges(int V, vector<vector<int>>& adj)
{
    vector<int> disc(V, 0), low(V, 0);
    vector<pair<int, int>> bridges;
    int time = 0;
    for (int u = 0; u < V; ++u)
        if (!disc[u])
            dfs(u, -1, adj, disc, low, time, bridges);
    return bridges;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {2, 3}};
    auto bridges = findBridges(V, adj);
    cout << "Bridges: ";
    for (auto& b : bridges) cout << "(" << b.first << "," << b.second << ") ";
    cout << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
