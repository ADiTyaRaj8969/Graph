/*
Task: Eulerian Path/Circuit
Given a graph, determine if an Eulerian path or circuit exists. An Eulerian path visits every edge
exactly once.
*/
#include <iostream>
#include <vector>
using namespace std;

string eulerianPathCircuit(int V, vector<vector<int>>& adj)
{
    int odd = 0;
    for (int u = 0; u < V; ++u)
        if (adj[u].size() % 2 != 0)
            odd++;
    if (odd == 0)
        return "Eulerian Circuit";
    if (odd == 2)
        return "Eulerian Path";
    return "None";
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {2, 3}};
    cout << "Eulerian: " << eulerianPathCircuit(V, adj) << endl;
    return 0;
}
/*
Time Complexity: O(V)
Space Complexity: O(1)
*/
