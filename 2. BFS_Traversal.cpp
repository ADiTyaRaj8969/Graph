/*
Task: BFS Traversal of a Graph
Given a source vertex, perform Breadth-First Search traversal.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int V, vector<vector<int>>& adj, int src)
{
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    cout << "BFS: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
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
    bfs(V, adj, 0);
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
