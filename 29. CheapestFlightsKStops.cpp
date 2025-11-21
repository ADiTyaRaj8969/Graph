/*
Task: Cheapest Flights Within K Stops
Find the cheapest price for a flight route from a source to a destination with at most k stops. (A
variation of Bellman-Ford or Dijkstra's).
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    int stops = 0;
    while (!q.empty() && stops <= K)
    {
        int sz = q.size();
        vector<int> temp = dist;
        while (sz--)
        {
            auto [u, cost] = q.front();
            q.pop();
            for (auto& [v, w] : adj[u])
            {
                if (cost + w < temp[v])
                {
                    temp[v] = cost + w;
                    q.push({v, temp[v]});
                }
            }
        }
        dist = temp;
        stops++;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
// Sample Test Case
int main()
{
    int n = 4, src = 0, dst = 3, K = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 3, 100}, {0, 2, 500}};
    cout << "Cheapest Price: " << findCheapestPrice(n, flights, src, dst, K) << endl;
    return 0;
}
/*
Time Complexity: O(K*E)
Space Complexity: O(V)
*/
