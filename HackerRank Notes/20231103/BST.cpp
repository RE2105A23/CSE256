/*
Write a program to create Binary Search tree for the given elements and then find the shortest distance between two elements in Binary Search tree. Elements may exist on same side of the tree or may be opposite side.

Input Format

First line will contain one integer N value representing number of elements.
Second line will contain N space separated integers.
Third line will contain two space separated integers and you have to find distance between these two values in BST.

Constraints

N>5 && N<20

Output Format

One integer value representing distance between two key values.

Sample Input 0

5
5 3 7 4 2
2 5
Sample Output 0

2
*/

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left, *right;
};

Node* new_node(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return new_node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->key > n1 && root->key > n2) return lca(root->left, n1, n2);
    if (root->key < n1 && root->key < n2) return lca(root->right, n1, n2);
    return root;
}

int find_level(Node* node, int val, int level) {
    if (node == NULL) return -1;
    if (node->key == val) return level;
    int l = find_level(node->left, val, level + 1);
    return (l != -1)? l : find_level(node->right, val, level + 1);
}

int find_distance(Node* root, int n1, int n2) {
    Node* lca_node = lca(root, n1, n2);
    int d1 = find_level(lca_node, n1, 0);
    int d2 = find_level(lca_node, n2, 0);
    return d1 + d2;
}

int main() {
    int N, val;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        root = insert(root, val);
    }
    int n1, n2;
    cin >> n1 >> n2;
    cout << find_distance(root, n1, n2) << endl;
    return 0;
}
