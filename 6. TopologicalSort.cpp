/*
Task: Topological Sort of a Directed Acyclic Graph (DAG)
Find a linear ordering of vertices such that for every directed edge u->v, u comes before v in the
ordering.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int V, vector<vector<int>>& adj)
{
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; ++u)
        for (int v : adj[u]) inDegree[v]++;
    queue<int> q;
    for (int i = 0; i < V; ++i)
        if (inDegree[i] == 0)
            q.push(i);
    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
        {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }
    return order;
}
// Sample Test Case
int main()
{
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    vector<int> order = topologicalSort(V, adj);
    cout << "Topological Sort: ";
    for (int v : order) cout << v << " ";
    cout << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
