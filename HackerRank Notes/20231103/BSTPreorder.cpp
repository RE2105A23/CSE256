/*
Write a program to create the Binary Search Tree of N elements. Number of elements in the BST should be greater than 2 and less than equal to 10. If the number of elements will not be in the range then display the message “Invalid Size” and elements should not be inserted. After insertion your program should display the second element of the Preorder traversal.

Input Format

Your program should take the 2 types of inputs. First will represent the number of elements in the BST and second will be the elements of the BST. If the number of elements will not be in the range than display the message “Invalid Size” and element should not be inserted.

Constraints

Size (N) of the BST should be 2 < N <= 10

Output Format

Your program should display the second element of the Preorder traversal. But if the size will be invalid then display the mentioned message.

Sample Input 0

3
2
1
3
Sample Output 0

1
Sample Input 1

2
Sample Output 1

Invalid Size
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

void preorder(Node* root, int& count) {
    if (root == NULL || count > 2) return;
    count++;
    if (count == 2) {
        cout << root->key << endl;
        return;
    }
    preorder(root->left, count);
    preorder(root->right, count);
}

int main() {
    int N;
    cin >> N;
    if (N <= 2 || N > 10) {
        cout << "Invalid Size" << endl;
        return 0;
    }
    Node* root = NULL;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    int count = 0;
    preorder(root, count);
    return 0;
}
