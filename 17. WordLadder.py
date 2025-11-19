"""
Task: Word Ladder
Given two words and a dictionary, find the length of the shortest transformation sequence from the start word to the end word, such that only one letter can be changed at a time, and each transformed word must exist in the dictionary.
Application of BFS on an implicit graph.
"""
from collections import deque
def ladder_length(beginWord, endWord, wordList):
    wordSet = set(wordList)
    if endWord not in wordSet:
        return 0
    q = deque([(beginWord, 1)])
    while q:
        word, length = q.popleft()
        if word == endWord:
            return length
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                if next_word in wordSet:
                    q.append((next_word, length+1))
                    wordSet.remove(next_word)
    return 0
# Sample Test Case
if __name__ == "__main__":
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    print("Word Ladder Length:", ladder_length(beginWord, endWord, wordList))
"""
Time Complexity: O(N*L^2) where N = number of words, L = length of each word
Space Complexity: O(N*L)
"""
