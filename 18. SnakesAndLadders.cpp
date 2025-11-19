/*
Task: Snakes and Ladders
Given a snakes and ladders board, find the minimum number of dice throws required to reach the final
square. Application of BFS.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int snakesAndLadders(vector<int>& board)
{
    int n = board.size();
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0] = true;
    while (!q.empty())
    {
        auto [pos, moves] = q.front();
        q.pop();
        if (pos == n - 1)
            return moves;
        for (int dice = 1; dice <= 6; ++dice)
        {
            int next = pos + dice;
            if (next < n && !visited[next])
            {
                visited[next] = true;
                int dest = board[next] == -1 ? next : board[next];
                q.push({dest, moves + 1});
            }
        }
    }
    return -1;
}
// Sample Test Case
int main()
{
    vector<int> board = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                         -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // Example: board[2]=15 means from 2 go to 15
    board[2] = 15;
    board[5] = 7;
    board[9] = 27;
    board[17] = 4;
    board[20] = 6;
    board[25] = 35;
    board[32] = 30;
    board[34] = 12;
    cout << "Min Dice Throws: " << snakesAndLadders(board) << endl;
    return 0;
}
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
