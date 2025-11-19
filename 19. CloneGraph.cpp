/*
Task: Clone Graph
Given a reference to a node in a connected undirected graph, return a deep copy (clone) of the
graph.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};
Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& mp)
{
    if (!node)
        return nullptr;
    if (mp.count(node))
        return mp[node];
    Node* clone = new Node(node->val);
    mp[node] = clone;
    for (auto n : node->neighbors) clone->neighbors.push_back(cloneGraph(n, mp));
    return clone;
}
Node* cloneGraph(Node* node)
{
    unordered_map<Node*, Node*> mp;
    return cloneGraph(node, mp);
}
// Sample Test Case
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};
    Node* clone = cloneGraph(n1);
    cout << "Cloned Node Val: " << clone->val << endl;
    return 0;
}
/*
Time Complexity: O(V+E)
Space Complexity: O(V)
*/
