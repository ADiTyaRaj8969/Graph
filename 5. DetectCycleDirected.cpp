/*
Task: Detect Cycle in Directed Graph
Write a function to determine if a given directed graph contains a cycle.
*/
#include <iostream>
#include <vector>
using namespace std;

bool hasCycleUtil(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack)
{
    visited[u] = recStack[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v] && hasCycleUtil(v, adj, visited, recStack))
            return true;
        else if (recStack[v])
            return true;
    }
    recStack[u] = false;
    return false;
}
bool hasCycleDirected(int V, vector<vector<int>>& adj)
{
    vector<bool> visited(V, false), recStack(V, false);
    for (int u = 0; u < V; ++u)
    {
        if (!visited[u])
        {
            if (hasCycleUtil(u, adj, visited, recStack))
                return true;
        }
    }
    return false;
}
// Sample Test Case
int main()
{
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {1};  // cycle
    cout << "Cycle (Directed): " << (hasCycleDirected(V, adj) ? "Yes" : "No") << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
