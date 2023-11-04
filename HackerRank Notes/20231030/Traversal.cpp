/*
Ashish got an interesting problem in DSA. He has to create a BST from n space seprated unique integer inputs. Futher, He need to print Pre-Order Traversal of that tree. first input in n will be considered as root

Input Format

First line will contain the count of n. Second line will contain the n space seprated unique integer.

Constraints

n>0 & n<20

Output Format

n space seprated unique integer

Sample Input 0

7
10 8 7 12 14 11 9
Sample Output 0

10 8 7 9 12 11 14
*/

#include <iostream>
#include <vector>
using namespace std;

// Define the structure of a tree node
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

// Function to insert a new node in BST
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

// Function for pre-order tree traversal
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    int n;
    cin >> n;

    // Check constraints
    if (n <= 0 || n >= 20) {
        cout << "Invalid input. n should be between 1 and 19." << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* root = nullptr;
    root = insert(root, arr[0]);  // First element as root

    for (int i = 1; i < n; ++i) {
        insert(root, arr[i]);
    }

    preOrder(root);
    cout << endl;

    return 0;
}
