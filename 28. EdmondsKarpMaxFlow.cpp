/*
Task: Maximum Flow (Edmonds-Karp Algorithm)
Implement the Edmonds-Karp algorithm to find the maximum flow from a source to a sink in a flow
network.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent)
{
    int V = rGraph.size();
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    parent[s] = -2;
    while (!q.empty())
    {
        int u = q.front().first, flow = q.front().second;
        q.pop();
        for (int v = 0; v < V; ++v)
        {
            if (parent[v] == -1 && rGraph[u][v] > 0)
            {
                parent[v] = u;
                int new_flow = min(flow, rGraph[u][v]);
                if (v == t)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}
int edmondsKarp(vector<vector<int>>& graph, int s, int t)
{
    int V = graph.size(), flow = 0;
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V);
    int new_flow;
    while (new_flow = bfs(rGraph, s, t, parent))
    {
        flow += new_flow;
        int v = t;
        while (v != s)
        {
            int u = parent[v];
            rGraph[u][v] -= new_flow;
            rGraph[v][u] += new_flow;
            v = u;
        }
    }
    return flow;
}
// Sample Test Case
int main()
{
    vector<vector<int>> graph = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0},
                                 {0, 0, 9, 0, 0, 20},  {0, 0, 0, 7, 0, 4},   {0, 0, 0, 0, 0, 0}};
    cout << "Max Flow: " << edmondsKarp(graph, 0, 5) << endl;
    return 0;
}
/*
Time Complexity: O(VE^2)
Space Complexity: O(V^2)
*/
