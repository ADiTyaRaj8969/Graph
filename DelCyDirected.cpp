#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}
bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0); 
    queue<int> q; 
    int visited = 0; 
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u]) {
            inDegree[v]++;
        }
    }
    for (int u = 0; u < V; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;
        for (auto v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return visited != V; 
}
int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);
    if (isCyclic(V, adj)) {
        cout << "Contains cycle" << endl;
    } else {
        cout << "No Cycle" << endl;
    }
    return 0;
}
