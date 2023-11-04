/*
Implement a function to print all the internal nodes of a binary search tree in ascending order.

Input Format

First line reads the number of nodes N and second line reads the N elements of the tree

Example:

5

20 30 10 15 25

Constraints

N > 0

Output Format

Prints all the internal nodes of the Tree in ascending order

Example:

10 20 30

Sample Input 0

5
10 20 5 15 30
Sample Output 0

10 20
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform in-order traversal and collect internal nodes
void inorderInternalNodes(Node* root, std::vector<int>& internalNodes) {
    if (root != nullptr) {
        inorderInternalNodes(root->left, internalNodes);
        if (root->left != nullptr || root->right != nullptr) {
            internalNodes.push_back(root->data);
        }
        inorderInternalNodes(root->right, internalNodes);
    }
}

int main() {
    int N;
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Constraints not met: N > 0" << std::endl;
        return 0;
    }

    Node* root = nullptr;
    for (int i = 0; i < N; ++i) {
        int data;
        std::cin >> data;
        root = insert(root, data);
    }

    std::vector<int> internalNodes;
    inorderInternalNodes(root, internalNodes);

    for (const int& node : internalNodes) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
