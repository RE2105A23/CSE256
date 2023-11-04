/*
Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

NOTE:

There are no self-loops in the graph. There are no multiple edges between two nodes. The graph may or may not be connected. Nodes are numbered from 1 to A. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

Input Format

The first argument given is an integer A representing the number of nodes in the graph.
The second argument is M, i.e. number of edges.
The third argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Constraints

2 <= A <= 105

1 <= M <= min(200000,A(A-1))

1 <= B[i][0], B[i][1] <= A

Output Format

Return 1 if path exists between node 1 to node A else return 0.

Sample Input 0

5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 0

0
Explanation 0

first line: A = 5 is number of vertices second line: M= number of edges.
Rest lines are edges in the form of paired vertices.
B = [ [1, 2] [4, 1] [2, 4] [3, 4] [5, 2] [1, 3] ] The given graph doens't contain any path from node 1 to node 5 so we will return 0.

Sample Input 1

5
4
1 2
2 3
3 4
4 5
Sample Output 1

1
Explanation 1

A = 5
M = 4
B = [ [1, 2] [2, 3] [3, 4] [4, 5] ]
Path from node1 to node 5 is ( 1 -> 2 -> 3 -> 4 -> 5 ) so we will return 1.
Output 2:
1
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list
vector<bool> visited; // Visited array to keep track of visited nodes

bool dfs(int node, int target) {
    if (node == target) return true; // Target node reached
    visited[node] = true; // Mark current node as visited
    
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (dfs(neighbour, target)) return true; // Recur for all connected nodes
        }
    }
    return false; // Target node not reachable from current node
}

int main() {
    int A, M;
    cin >> A >> M;
    
    adj.resize(A + 1);
    visited.resize(A + 1, false);
    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed graph
    }
    
    if (dfs(1, A)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
