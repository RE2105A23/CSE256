/*
Ajay got an interesting problem in DSA. He has to create a BST from n space seprated unique integer inputs. Futher, He need to print Post-Order Traversal of that tree. first input in n will be considered as root

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

7 9 8 11 14 12 10
*/

#include <iostream>
#include <vector>
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
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert elements into the BST
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for Post-Order Traversal
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Node* root = createNode(arr[0]);
    for (int i = 1; i < n; ++i) {
        insertNode(root, arr[i]);
    }

    postOrder(root);
    cout << endl;

    return 0;
}
