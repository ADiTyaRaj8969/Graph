"""
Task: Course Schedule
Given a total number of courses and a list of prerequisite pairs, determine if it is possible to finish all courses.
Application of Topological Sort/Cycle Detection.
"""
from collections import deque
def can_finish(numCourses, prerequisites):
    adj = [[] for _ in range(numCourses)]
    in_degree = [0]*numCourses
    for a, b in prerequisites:
        adj[b].append(a)
        in_degree[a] += 1
    q = deque([i for i in range(numCourses) if in_degree[i]==0])
    count = 0
    while q:
        u = q.popleft()
        count += 1
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)
    return count == numCourses
# Sample Test Case
if __name__ == "__main__":
    numCourses = 2
    prerequisites = [(1,0)]
    print("Can Finish All Courses:", can_finish(numCourses, prerequisites))
"""
Time Complexity: O(V+E)
Space Complexity: O(V+E)
"""
