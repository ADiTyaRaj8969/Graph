/*
Task: Detect Cycle in Undirected Graph
Write a function to determine if a given undirected graph contains a cycle.
*/
#include <iostream>
#include <vector>
using namespace std;

bool hasCycleUtil(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            if (hasCycleUtil(v, u, adj, visited))
                return true;
        }
        else if (v != parent)
        {
            return true;
        }
    }
    return false;
}
bool hasCycleUndirected(int V, vector<vector<int>>& adj)
{
    vector<bool> visited(V, false);
    for (int u = 0; u < V; ++u)
    {
        if (!visited[u])
        {
            if (hasCycleUtil(u, -1, adj, visited))
                return true;
        }
    }
    return false;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    cout << "Cycle (Undirected): " << (hasCycleUndirected(V, adj) ? "Yes" : "No") << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
