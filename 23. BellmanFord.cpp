/*
Task: Bellman-Ford Algorithm
Find the shortest path from a source node to all other nodes in a weighted graph that may contain
negative edge weights.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 1; i < V; ++i)
    {
        for (auto& e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    return dist;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
                                 {1, 4, 2},  {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    vector<int> dist = bellmanFord(V, edges, 0);
    cout << "Bellman-Ford: ";
    for (int d : dist) cout << d << " ";
    cout << endl;
    return 0;
}
/*
Time Complexity: O(VE)
Space Complexity: O(V)
*/
