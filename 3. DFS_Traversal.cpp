/*
Task: DFS Traversal of a Graph (Recursive and Iterative)
Given a source vertex, perform Depth-First Search traversal (both recursive and iterative).
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_recursive_util(int u, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs_recursive_util(v, adj, visited);
    }
}
void dfs_recursive(int V, vector<vector<int>>& adj, int src)
{
    vector<bool> visited(V, false);
    cout << "DFS (Recursive): ";
    dfs_recursive_util(src, adj, visited);
    cout << endl;
}
void dfs_iterative(int V, vector<vector<int>>& adj, int src)
{
    vector<bool> visited(V, false);
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
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it)
            {
                if (!visited[*it])
                    st.push(*it);
            }
        }
    }
    cout << endl;
}
// Sample Test Case
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    dfs_recursive(V, adj, 0);
    dfs_iterative(V, adj, 0);
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
