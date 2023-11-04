/*
Height of a binary search tree is calculated as the number of edges in the longest path. Write a program to calculate the number of edges in the shortest path of the tree.

Input Format

10 elements of type int separated by space

Constraints

10 elements of type int separated by space

Output Format

Length of path from root to closest leaf.

Sample Input 0

6 3 8 1 5 7 9 0 2 4
Sample Output 0

2
*/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

int findShortestPath(Node* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 0;
    }

    return min(findShortestPath(root->left), findShortestPath(root->right)) + 1;
}

int main() {
    Node* root = NULL;
    vector<int> arr(10);
    
    //cout << "Enter 10 integers separated by spaces: ";
    
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; ++i) {
        root = insert(root, arr[i]);
    }

    //cout << "Length of path from root to closest leaf: " << findShortestPath(root) << endl;
    cout << findShortestPath(root) << endl;

    return 0;
}
