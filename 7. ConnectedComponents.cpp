/*
Task: Number of Connected Components in an Undirected Graph
Count the number of separate, disconnected subgraphs.
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}
int countConnectedComponents(int V, vector<vector<int>>& adj)
{
    vector<bool> visited(V, false);
    int count = 0;
    for (int u = 0; u < V; ++u)
    {
        if (!visited[u])
        {
            count++;
            dfs(u, adj, visited);
        }
    }
    return count;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {0};
    adj[2] = {3};
    adj[3] = {2};
    // adj[4] is empty (disconnected)
    cout << "Connected Components: " << countConnectedComponents(V, adj) << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
