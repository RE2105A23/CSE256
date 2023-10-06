/*
Write a program to create the Binary Search Tree of N elements. Number of elements in the BST should be greater than 2 and less than equal to 10. If the number of elements will not be in the range then display the message “Invalid Size” and elements should not be inserted. After insertion your program should display the second element of the inorder traversal.

Input Format

Your program should take the 2 types of inputs. First will represent the number of elements in the BST and second will be the elements of the BST. If the number of elements will not be in the range than display the message “Invalid Size” and element should not be inserted.

Constraints

Size(N) of the BST should be 2 < N <= 10

Output Format

Your program should display the second element of the inorder traversal. But if the size will be invalid then display the mentioned message.

Sample Input 0

3
2
1
3
Sample Output 0

2
Sample Input 1

2
Sample Output 1

Invalid Size
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal
void inorder(Node* root, int &count) {
    if (root == nullptr) return;

    inorder(root->left, count);
    
    // Increment the count and print the second element
    count++;
    if (count == 2) {
        cout << root->data << endl;
        return;
    }

    inorder(root->right, count);
}

int main() {
    Node* root = nullptr;
    int n, count = 0;

    //cout << "Enter the number of elements in the BST: ";
    cin >> n;

    // Validate the size constraint
    if (n <= 2 || n > 10) {
        cout << "Invalid Size" << endl;
        return 0;
    }

    // cout << "Enter the elements of the BST: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    inorder(root, count);

    return 0;
}
