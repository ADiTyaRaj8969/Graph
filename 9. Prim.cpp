/*
Task: Prim's Algorithm
Find the Minimum Spanning Tree (MST) for a weighted, undirected graph.
*/
#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int, int>>>& adj)
{
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    key[0] = 0;
    int total = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u])
            continue;
        inMST[u] = true;
        total += key[u];
        for (auto& edge : adj[u])
        {
            int v = edge.first, w = edge.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    return total;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}, {2, 7}};
    cout << "Prim's MST: " << primMST(V, adj) << endl;
    return 0;
}
/*
Time Complexity: O((V+E)logV)
Space Complexity: O(V)
*/
