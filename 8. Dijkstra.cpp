/*
Task: Dijkstra's Algorithm
Find the shortest path from a source node to all other nodes in a weighted graph with non-negative
edge weights.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto& edge : adj[u])
        {
            int v = edge.first, w = edge.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{2, 1}, {3, 7}};
    adj[2] = {{4, 3}};
    adj[3] = {{4, 1}};
    adj[4] = {};
    vector<int> dist = dijkstra(V, adj, 0);
    cout << "Dijkstra: ";
    for (int d : dist) cout << d << " ";
    cout << endl;
    return 0;
}
/*
Time Complexity: O((V+E)logV)
Space Complexity: O(V)
*/
