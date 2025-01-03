#include<bits/stdc++.h>
using namespace std;
int rowDir[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int colDir[] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool isValid(int x, int y, int N, vector<vector<bool>>& visited) {
    return x >= 1 && y >= 1 && x <= N && y <= N && !visited[x][y];
}
int minStepsToReachTarget(int N, vector<int>& knightPos, vector<int>& targetPos) {
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    queue<pair<int, int>> q;
    q.push({knightPos[0], knightPos[1]});
    visited[knightPos[0]][knightPos[1]] = true;
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto[x, y] = q.front();
            q.pop();
            if (x == targetPos[0] && y == targetPos[1]) {
                return steps;
            }
            for (int j = 0; j < 8; j++) {
                int newX = x + rowDir[j];
                int newY = y + colDir[j];
                if (isValid(newX, newY, N, visited)) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        steps++;
    }
    return -1;
}
int main() {
    int N = 6;
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1}; 
    int result = minStepsToReachTarget(N, knightPos, targetPos);
    cout << result << endl;

    return 0;
}
