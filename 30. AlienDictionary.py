"""
Task: Alien Dictionary
Given a list of words from the dictionary sorted lexicographically, find the order of characters in the language. (Application of Topological Sort on a graph built from character dependencies).
"""
from collections import deque, defaultdict
def alien_order(words):
    adj = defaultdict(set)
    in_deg = {}
    for w in words:
        for c in w:
            in_deg[c] = 0
    for i in range(len(words)-1):
        w1, w2 = words[i], words[i+1]
        for j in range(min(len(w1), len(w2))):
            if w1[j] != w2[j]:
                if w2[j] not in adj[w1[j]]:
                    adj[w1[j]].add(w2[j])
                    in_deg[w2[j]] += 1
                break
    q = deque([c for c in in_deg if in_deg[c]==0])
    order = ''
    while q:
        u = q.popleft()
        order += u
        for v in adj[u]:
            in_deg[v] -= 1
            if in_deg[v] == 0:
                q.append(v)
    return order if len(order) == len(in_deg) else ''
# Sample Test Case
if __name__ == "__main__":
    words = ["wrt","wrf","er","ett","rftt"]
    print("Alien Dictionary Order:", alien_order(words))
"""
Time Complexity: O(N*L) where N = number of words, L = average word length
Space Complexity: O(1) (since alphabet size is constant)
"""
