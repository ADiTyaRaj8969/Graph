/*
Task: Find Strongly Connected Components (SCCs) using Kosaraju's Algorithm
Implement Kosaraju's algorithm to find all SCCs in a directed graph.
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs1(v, adj, visited, order);
    order.push_back(u);
}
void dfs2(int u, vector<vector<int>>& rev, vector<bool>& visited, vector<int>& comp)
{
    visited[u] = true;
    comp.push_back(u);
    for (int v : rev[u])
        if (!visited[v])
            dfs2(v, rev, visited, comp);
}
vector<vector<int>> kosarajuSCC(int V, vector<vector<int>>& adj)
{
    vector<bool> visited(V, false);
    vector<int> order;
    for (int u = 0; u < V; ++u)
        if (!visited[u])
            dfs1(u, adj, visited, order);
    vector<vector<int>> rev(V);
    for (int u = 0; u < V; ++u)
        for (int v : adj[u]) rev[v].push_back(u);
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    for (int i = V - 1; i >= 0; --i)
    {
        int u = order[i];
        if (!visited[u])
        {
            vector<int> comp;
            dfs2(u, rev, visited, comp);
            sccs.push_back(comp);
        }
    }
    return sccs;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {2, 3};
    adj[1] = {0};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {};
    auto sccs = kosarajuSCC(V, adj);
    cout << "SCCs: ";
    for (auto& comp : sccs)
    {
        cout << "{";
        for (int v : comp) cout << v << " ";
        cout << "} ";
    }
    cout << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
