/*
Task: Word Ladder
Given two words and a dictionary, find the length of the shortest transformation sequence from the
start word to the end word, such that only one letter can be changed at a time, and each transformed
word must exist in the dictionary. Application of BFS on an implicit graph.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
        return 0;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty())
    {
        auto [word, len] = q.front();
        q.pop();
        if (word == endWord)
            return len;
        for (int i = 0; i < word.size(); ++i)
        {
            string next = word;
            for (char c = 'a'; c <= 'z'; ++c)
            {
                next[i] = c;
                if (dict.count(next))
                {
                    q.push({next, len + 1});
                    dict.erase(next);
                }
            }
        }
    }
    return 0;
}
// Sample Test Case
int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << "Word Ladder Length: " << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
/*
Time Complexity: O(N*L^2) where N = number of words, L = length of each word
Space Complexity: O(N*L)
*/
