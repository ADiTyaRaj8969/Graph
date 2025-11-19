/*
Task: Find the Town Judge
In a town, there is a town judge. The judge trusts nobody, everybody trusts the judge, and there is
exactly one person who satisfies these properties. Find the judge. Graph problem solvable by
calculating in-degrees and out-degrees.
*/
#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust)
{
    vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);
    for (auto& t : trust)
    {
        outDeg[t[0]]++;
        inDeg[t[1]]++;
    }
    for (int i = 1; i <= n; ++i)
        if (inDeg[i] == n - 1 && outDeg[i] == 0)
            return i;
    return -1;
}
// Sample Test Case
int main()
{
    int n = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << "Town Judge: " << findJudge(n, trust) << endl;
    return 0;
}
/*
Time Complexity: O(T)
Space Complexity: O(N)
*/
