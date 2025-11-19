/*
Task: Course Schedule
Given a total number of courses and a list of prerequisite pairs, determine if it is possible to
finish all courses. Application of Topological Sort/Cycle Detection.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto& p : prerequisites)
    {
        adj[p.second].push_back(p.first);
        inDegree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
        if (inDegree[i] == 0)
            q.push(i);
    int count = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;
        for (int v : adj[u])
        {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }
    return count == numCourses;
}
// Sample Test Case
int main()
{
    int numCourses = 2;
    vector<pair<int, int>> prerequisites = {{1, 0}};
    cout << "Can Finish All Courses: " << (canFinish(numCourses, prerequisites) ? "Yes" : "No")
         << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V+E)
*/
