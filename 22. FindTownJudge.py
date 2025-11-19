"""
Task: Find the Town Judge
In a town, there is a town judge. The judge trusts nobody, everybody trusts the judge, and there is exactly one person who satisfies these properties. Find the judge.
Graph problem solvable by calculating in-degrees and out-degrees.
"""
def find_judge(n, trust):
    in_deg = [0]*(n+1)
    out_deg = [0]*(n+1)
    for a, b in trust:
        out_deg[a] += 1
        in_deg[b] += 1
    for i in range(1, n+1):
        if in_deg[i] == n-1 and out_deg[i] == 0:
            return i
    return -1
# Sample Test Case
if __name__ == "__main__":
    n = 3
    trust = [(1,3),(2,3)]
    print("Town Judge:", find_judge(n, trust))
"""
Time Complexity: O(T)
Space Complexity: O(N)
"""
