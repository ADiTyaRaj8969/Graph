/*
Task: Kruskal's Algorithm
Find the Minimum Spanning Tree (MST) using the Disjoint Set Union (DSU) data structure.
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};
struct DSU
{
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int xr = find(x), yr = find(y);
        if (xr == yr)
            return;
        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else
        {
            parent[yr] = xr;
            rank[xr]++;
        }
    }
};
int kruskalMST(int V, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int total = 0;
    for (auto& e : edges)
    {
        if (dsu.find(e.u) != dsu.find(e.v))
        {
            dsu.unite(e.u, e.v);
            total += e.w;
        }
    }
    return total;
}
// Sample Test Case
int main()
{
    int V = 4;
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    cout << "Kruskal's MST: " << kruskalMST(V, edges) << endl;
    return 0;
}
/*
Time Complexity: O(ElogE)
Space Complexity: O(V)
*/
