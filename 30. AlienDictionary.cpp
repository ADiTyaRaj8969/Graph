/*
Task: Alien Dictionary
Given a list of words from the dictionary sorted lexicographically, find the order of characters in
the language. (Application of Topological Sort on a graph built from character dependencies).
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string alienOrder(vector<string>& words)
{
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> inDeg;
    for (auto& w : words)
        for (char c : w) inDeg[c] = 0;
    for (int i = 0; i < words.size() - 1; ++i)
    {
        string w1 = words[i], w2 = words[i + 1];
        int len = min(w1.size(), w2.size());
        for (int j = 0; j < len; ++j)
        {
            if (w1[j] != w2[j])
            {
                if (!adj[w1[j]].count(w2[j]))
                {
                    adj[w1[j]].insert(w2[j]);
                    inDeg[w2[j]]++;
                }
                break;
            }
        }
    }
    queue<char> q;
    for (auto& p : inDeg)
        if (p.second == 0)
            q.push(p.first);
    string order;
    while (!q.empty())
    {
        char u = q.front();
        q.pop();
        order += u;
        for (char v : adj[u])
        {
            if (--inDeg[v] == 0)
                q.push(v);
        }
    }
    return order.size() == inDeg.size() ? order : "";
}
// Sample Test Case
int main()
{
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Alien Dictionary Order: " << alienOrder(words) << endl;
    return 0;
}
/*
Time Complexity: O(N*L) where N = number of words, L = average word length
Space Complexity: O(1) (since alphabet size is constant)
*/
