/*
Task: Detect Negative Weight Cycle
Use the Bellman-Ford algorithm to detect if a graph contains a cycle where the sum of the edge
weights is negative.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool hasNegativeCycle(int V, vector<vector<int>>& edges)
{
    vector<int> dist(V, 0);
    for (int i = 1; i <= V; ++i)
    {
        for (auto& e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                if (i == V)
                    return true;
            }
        }
    }
    return false;
}
// Sample Test Case
int main()
{
    int V = 4;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, -1}, {2, 3, -1}, {3, 0, -1}};
    cout << "Has Negative Cycle: " << (hasNegativeCycle(V, edges) ? "Yes" : "No") << endl;
    return 0;
}
/*
Time Complexity: O(VE)
Space Complexity: O(V)
*/
