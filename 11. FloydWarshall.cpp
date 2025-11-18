/*
Task: Floyd-Warshall Algorithm
Find the shortest distances between every pair of vertices in a given weighted directed graph
(All-Pairs Shortest Path).
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> floydWarshall(int V, vector<vector<int>>& matrix)
{
    vector<vector<int>> dist = matrix;
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            if (i != j && dist[i][j] == 0)
                dist[i][j] = INT_MAX / 2;
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return dist;
}
// Sample Test Case
int main()
{
    int V = 4;
    vector<vector<int>> matrix = {{0, 5, 0, 10}, {0, 0, 3, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}};
    auto dist = floydWarshall(V, matrix);
    cout << "Floyd-Warshall:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j) cout << dist[i][j] << " ";
        cout << endl;
    }
    return 0;
}
/*
Time Complexity: O(V^3)
Space Complexity: O(V^2)
*/
