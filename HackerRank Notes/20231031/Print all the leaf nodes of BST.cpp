/*
Given a binary search tree with N nodes, implement a function print_leaf(node* root) to print all the leaf nodes in descending order.

Input Format

First line reads the number of nodes and second line reads the elements of the tree.

Example:

5

10 5 20 30 15

Constraints

N > 0

Output Format

Prints all the nodes of BST in descending order

Example:

30 15 5

Sample Input 0

5
10 5 20 30 15
Sample Output 0

30 15 5
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to insert nodes into the BST
Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    }
    else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Function to collect leaf nodes
void collectLeafNodes(Node* root, vector<int>& leafNodes) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        leafNodes.push_back(root->data);
    }
    collectLeafNodes(root->left, leafNodes);
    collectLeafNodes(root->right, leafNodes);
}

// Main function
int main() {
    int n;
    //cout << "Enter the number of nodes: ";
    cin >> n;

    Node* root = NULL;

    //cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }

    vector<int> leafNodes;
    collectLeafNodes(root, leafNodes);

    // Sort the leaf nodes in descending order
    sort(leafNodes.rbegin(), leafNodes.rend());

    //cout << "Leaf nodes in descending order: ";
    for (const auto& node : leafNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
