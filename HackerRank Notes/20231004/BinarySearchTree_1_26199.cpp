/*
a) Use binary tree data structure and apply insert operation on binary search tree.
b) Apply pre-order traversing to display the content of the tree.

Input Format

First line contains number of nodes in the binary search tree.
Second line contains the node values separeted by space.
Sample Input
7
15 12 20 8 14 16 18

Constraints

1<=number of nodes<=20

Output Format

Output is space separated preorder traversing of binary search tree.
If the tree is empty then it should display "Empty BST"
If the binary search tree contains more than 20 nodes then display "Out of the limit" message and don't read the node values
If first line of input is negative number then display "Invalid number" message and don't read the node values

Sample Input
7
15 12 20 8 14 16 18
Sample Output
15 12 8 14 20 16 18

Sample Input 0

7
15 12 20 8 14 16 18
Sample Output 0

15 12 8 14 20 16 18

*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for pre-order traversal
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int n;
    //cout << "Enter the number of nodes: ";
    cin >> n;

    // Validate the number of nodes
    if (n < 0) {
        cout << "Invalid number" << endl;
        return 1;
    }
    if (n == 0) {
        cout << "Empty BST" << endl;
        return 0;
    }
    if (n > 20) {
        cout << "Out of the limit" << endl;
        return 1;
    }

    cin.ignore();
    string line;
    //cout << "Enter the node values separated by space: ";
    getline(cin, line);
    stringstream ss(line);

    Node* root = NULL;
    int data;
    while (ss >> data) {
        root = insertNode(root, data);
    }

    // Perform pre-order traversal
    //cout << "Pre-order traversal: ";
    preOrder(root);
    cout << endl;

    return 0;
}
