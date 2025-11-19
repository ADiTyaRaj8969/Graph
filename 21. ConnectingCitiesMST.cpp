/*
Task: Connecting Cities with Minimum Cost
There are n cities and a list of connections, where each connection has a cost. Find the minimum
cost to connect all cities. Application of MST (Prim's or Kruskal's Algorithm).
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};
struct DSU
{
    vector<int> parent;
    DSU(int n) : parent(n)
    {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int x, int y) { parent[find(x)] = find(y); }
};
int minCostToConnectCities(int n, vector<Edge>& connections)
{
    sort(connections.begin(), connections.end());
    DSU dsu(n + 1);
    int total = 0, count = 0;
    for (auto& e : connections)
    {
        if (dsu.find(e.u) != dsu.find(e.v))
        {
            dsu.unite(e.u, e.v);
            total += e.w;
            count++;
        }
    }
    return count == n - 1 ? total : -1;
}
// Sample Test Case
int main()
{
    int n = 4;
    vector<Edge> connections = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {1, 4, 1}};
    cout << "Min Cost to Connect Cities: " << minCostToConnectCities(n, connections) << endl;
    return 0;
}
/*
Time Complexity: O(ElogE)
Space Complexity: O(V)
*/
