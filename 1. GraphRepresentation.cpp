/*
Task: Implement Graph Representation using both Adjacency List and Adjacency Matrix.
Includes: BFS, DFS (recursive & iterative), cycle detection (undirected & directed), topological
sort, connected components, Dijkstra, Prim, Kruskal, Floyd-Warshall, SCC (Kosaraju), and more. Each
function includes a sample test case at the bottom.
*/
#include <bits/stdc++.h>
using namespace std;

// Graph Representation (Adjacency List & Matrix)
class Graph
{
   public:
    int V;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;
    Graph(int V) : V(V), adjList(V), adjMatrix(V, vector<int>(V, 0)) {}
    void addEdge(int u, int v, int w = 1, bool directed = false)
    {
        adjList[u].push_back(v);
        adjMatrix[u][v] = w;
        if (!directed)
        {
            adjList[v].push_back(u);
            adjMatrix[v][u] = w;
        }
    }
};

// BFS Traversal
void BFS(const Graph& g, int src)
{
    vector<bool> visited(g.V, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    cout << "BFS: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : g.adjList[u])
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

// DFS Traversal (Recursive)
void DFSUtil(const Graph& g, int u, vector<bool>& visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : g.adjList[u])
    {
        if (!visited[v])
            DFSUtil(g, v, visited);
    }
}
void DFS(const Graph& g, int src)
{
    vector<bool> visited(g.V, false);
    cout << "DFS (Recursive): ";
    DFSUtil(g, src, visited);
    cout << endl;
}
// DFS Traversal (Iterative)
void DFSIterative(const Graph& g, int src)
{
    vector<bool> visited(g.V, false);
    stack<int> st;
    st.push(src);
    cout << "DFS (Iterative): ";
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            visited[u] = true;
            cout << u << " ";
            for (auto it = g.adjList[u].rbegin(); it != g.adjList[u].rend(); ++it)
            {
                if (!visited[*it])
                    st.push(*it);
            }
        }
    }
    cout << endl;
}

// Detect Cycle in Undirected Graph (DFS)
bool hasCycleUndirectedUtil(const Graph& g, int u, int parent, vector<bool>& visited)
{
    visited[u] = true;
    for (int v : g.adjList[u])
    {
        if (!visited[v])
        {
            if (hasCycleUndirectedUtil(g, v, u, visited))
                return true;
        }
        else if (v != parent)
        {
            return true;
        }
    }
    return false;
}
bool hasCycleUndirected(const Graph& g)
{
    vector<bool> visited(g.V, false);
    for (int u = 0; u < g.V; ++u)
    {
        if (!visited[u])
        {
            if (hasCycleUndirectedUtil(g, u, -1, visited))
                return true;
        }
    }
    return false;
}

// Detect Cycle in Directed Graph (DFS)
bool hasCycleDirectedUtil(const Graph& g, int u, vector<bool>& visited, vector<bool>& recStack)
{
    visited[u] = recStack[u] = true;
    for (int v : g.adjList[u])
    {
        if (!visited[v] && hasCycleDirectedUtil(g, v, visited, recStack))
            return true;
        else if (recStack[v])
            return true;
    }
    recStack[u] = false;
    return false;
}
bool hasCycleDirected(const Graph& g)
{
    vector<bool> visited(g.V, false), recStack(g.V, false);
    for (int u = 0; u < g.V; ++u)
    {
        if (!visited[u])
        {
            if (hasCycleDirectedUtil(g, u, visited, recStack))
                return true;
        }
    }
    return false;
}

// Topological Sort (Kahn's Algorithm)
vector<int> topologicalSort(const Graph& g)
{
    vector<int> inDegree(g.V, 0);
    for (int u = 0; u < g.V; ++u)
        for (int v : g.adjList[u]) inDegree[v]++;
    queue<int> q;
    for (int i = 0; i < g.V; ++i)
        if (inDegree[i] == 0)
            q.push(i);
    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g.adjList[u])
        {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }
    return order;
}

// Number of Connected Components
int countConnectedComponents(const Graph& g)
{
    vector<bool> visited(g.V, false);
    int count = 0;
    for (int u = 0; u < g.V; ++u)
    {
        if (!visited[u])
        {
            count++;
            DFSUtil(g, u, visited);
        }
    }
    return count;
}

// Dijkstra's Algorithm
vector<int> dijkstra(const Graph& g, int src)
{
    vector<int> dist(g.V, INT_MAX);
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty())
    {
        int u = s.begin()->second;
        s.erase(s.begin());
        for (int v = 0; v < g.V; ++v)
        {
            if (g.adjMatrix[u][v] && dist[v] > dist[u] + g.adjMatrix[u][v])
            {
                s.erase({dist[v], v});
                dist[v] = dist[u] + g.adjMatrix[u][v];
                s.insert({dist[v], v});
            }
        }
    }
    return dist;
}

// Prim's Algorithm
int primMST(const Graph& g)
{
    vector<int> key(g.V, INT_MAX), parent(g.V, -1);
    vector<bool> inMST(g.V, false);
    key[0] = 0;
    for (int count = 0; count < g.V - 1; ++count)
    {
        int u = -1;
        for (int v = 0; v < g.V; ++v)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;
        inMST[u] = true;
        for (int v = 0; v < g.V; ++v)
            if (g.adjMatrix[u][v] && !inMST[v] && g.adjMatrix[u][v] < key[v])
            {
                key[v] = g.adjMatrix[u][v];
                parent[v] = u;
            }
    }
    int total = 0;
    for (int v = 1; v < g.V; ++v) total += g.adjMatrix[v][parent[v]];
    return total;
}

// Kruskal's Algorithm (DSU)
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
struct Edge
{
    int u, v, w;
};
bool cmp(const Edge& a, const Edge& b)
{
    return a.w < b.w;
}
int kruskalMST(int V, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), cmp);
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

// Floyd-Warshall Algorithm
vector<vector<int>> floydWarshall(const Graph& g)
{
    vector<vector<int>> dist = g.adjMatrix;
    for (int i = 0; i < g.V; ++i)
        for (int j = 0; j < g.V; ++j)
            if (i != j && dist[i][j] == 0)
                dist[i][j] = INT_MAX / 2;
    for (int k = 0; k < g.V; ++k)
        for (int i = 0; i < g.V; ++i)
            for (int j = 0; j < g.V; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return dist;
}

// Kosaraju's Algorithm for SCC
void dfsKosaraju(const Graph& g, int u, vector<bool>& visited, vector<int>& order)
{
    visited[u] = true;
    for (int v : g.adjList[u])
        if (!visited[v])
            dfsKosaraju(g, v, visited, order);
    order.push_back(u);
}
void dfsReverse(const vector<vector<int>>& rev, int u, vector<bool>& visited, vector<int>& comp)
{
    visited[u] = true;
    comp.push_back(u);
    for (int v : rev[u])
        if (!visited[v])
            dfsReverse(rev, v, visited, comp);
}
vector<vector<int>> kosarajuSCC(const Graph& g)
{
    vector<bool> visited(g.V, false);
    vector<int> order;
    for (int u = 0; u < g.V; ++u)
        if (!visited[u])
            dfsKosaraju(g, u, visited, order);
    vector<vector<int>> rev(g.V);
    for (int u = 0; u < g.V; ++u)
        for (int v : g.adjList[u]) rev[v].push_back(u);
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    for (int i = g.V - 1; i >= 0; --i)
    {
        int u = order[i];
        if (!visited[u])
        {
            vector<int> comp;
            dfsReverse(rev, u, visited, comp);
            sccs.push_back(comp);
        }
    }
    return sccs;
}

// Sample Test Case
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    BFS(g, 0);
    DFS(g, 0);
    DFSIterative(g, 0);
    cout << "Cycle (Undirected): " << (hasCycleUndirected(g) ? "Yes" : "No") << endl;
    cout << "Cycle (Directed): " << (hasCycleDirected(g) ? "Yes" : "No") << endl;
    vector<int> topo = topologicalSort(g);
    cout << "Topological Sort: ";
    for (int v : topo) cout << v << " ";
    cout << endl;
    cout << "Connected Components: " << countConnectedComponents(g) << endl;
    vector<int> dist = dijkstra(g, 0);
    cout << "Dijkstra: ";
    for (int d : dist) cout << d << " ";
    cout << endl;
    cout << "Prim's MST: " << primMST(g) << endl;
    vector<Edge> edges = {{0, 1, 1}, {0, 2, 1}, {1, 3, 1}, {1, 4, 1}};
    cout << "Kruskal's MST: " << kruskalMST(5, edges) << endl;
    auto fw = floydWarshall(g);
    cout << "Floyd-Warshall: ";
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j) cout << fw[i][j] << " ";
        cout << endl;
    }
    auto sccs = kosarajuSCC(g);
    cout << "SCCs: ";
    for (auto& comp : sccs)
    {
        for (int v : comp) cout << v << " ";
        cout << ", ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity (TC) and Space Complexity (SC):
- Graph Representation: TC = O(1) per edge insert, SC = O(V+E) for list, O(V^2) for matrix
- BFS/DFS: TC = O(V+E), SC = O(V)
- Cycle Detection: TC = O(V+E), SC = O(V)
- Topological Sort: TC = O(V+E), SC = O(V)
- Connected Components: TC = O(V+E), SC = O(V)
- Dijkstra: TC = O((V+E)logV), SC = O(V)
- Prim: TC = O(V^2), SC = O(V)
- Kruskal: TC = O(ElogE), SC = O(V)
- Floyd-Warshall: TC = O(V^3), SC = O(V^2)
- Kosaraju's SCC: TC = O(V+E), SC = O(V)
*/
