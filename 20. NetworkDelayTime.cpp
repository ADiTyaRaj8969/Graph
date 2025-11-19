/*
Task: Network Delay Time
Given a network of n nodes, and a list of travel times as directed edges. If a signal is sent from a
source node, find how long it will take for all nodes to receive the signal. Application of
Dijkstra's Algorithm.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto& t : times) adj[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
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
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (dist[i] == INT_MAX)
            return -1;
        else
            ans = max(ans, dist[i]);
    return ans;
}
// Sample Test Case
int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << "Network Delay Time: " << networkDelayTime(times, n, k) << endl;
    return 0;
}
/*
Time Complexity: O((V+E)logV)
Space Complexity: O(V+E)
*/
