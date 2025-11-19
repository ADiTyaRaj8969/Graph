"""
Task: Snakes and Ladders
Given a snakes and ladders board, find the minimum number of dice throws required to reach the final square.
Application of BFS.
"""
from collections import deque
def snakes_and_ladders(board):
    n = len(board)
    visited = [False]*n
    q = deque([(0,0)])
    visited[0] = True
    while q:
        pos, moves = q.popleft()
        if pos == n-1:
            return moves
        for dice in range(1,7):
            next_pos = pos + dice
            if next_pos < n and not visited[next_pos]:
                visited[next_pos] = True
                dest = board[next_pos] if board[next_pos] != -1 else next_pos
                q.append((dest, moves+1))
    return -1
# Sample Test Case
if __name__ == "__main__":
    board = [-1]*100
    board[2]=15; board[5]=7; board[9]=27; board[17]=4; board[20]=6; board[25]=35; board[32]=30; board[34]=12
    print("Min Dice Throws:", snakes_and_ladders(board))
"""
Time Complexity: O(N)
Space Complexity: O(N)
"""
