/*
Write a code to identified that the two given trees are identical or not.

Input Format

First line reads the number of nodes N for Tree_1 second line reads the N elements of the tree Example: 5 20 30 10 15 25

Third line reads the number of nodes M for Tree_2
Fourth line reads the M elements of the tree Example: 5 20 30 10 15 25

Constraints

N > 0 M > 0

Output Format

Both trees are identical or Both trees are not identical

Sample Input 0

5
1 2 3 4 5
5
1 3 2 5 4
Sample Output 0

Both trees are not identical
Explanation 0

Enter number of node for Tree_1: 5 Enter 5 node for Tree_1 : 1 2 3 4 5 Enter number of node for Tree_2: 5 Enter 5 node for Tree_2 : 1 3 2 5 4
*/

#include <iostream>
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
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

// Function to check if two trees are identical
bool areIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->data == root2->data) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

// Main function
int main() {
    int n, m;
    //cout << "Enter the number of nodes for Tree_1: ";
    cin >> n;

    Node* root1 = NULL;
    //cout << "Enter the elements for Tree_1: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root1 = insertBST(root1, x);
    }

    //cout << "Enter the number of nodes for Tree_2: ";
    cin >> m;

    Node* root2 = NULL;
    //cout << "Enter the elements for Tree_2: ";
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        root2 = insertBST(root2, x);
    }

    if (areIdentical(root1, root2)) {
        cout << "Both trees are identical" << endl;
    } else {
        cout << "Both trees are not identical" << endl;
    }

    return 0;
}
