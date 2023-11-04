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

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

void inorderSecondElement(Node* root, int& count) {
    if (!root || count >= 2) {
        return;
    }

    inorderSecondElement(root->left, count);
    count++;
    if (count == 2) {
        cout << root->data << endl;
        return;
    }
    inorderSecondElement(root->right, count);
}

int main() {
    int N;
    cin >> N;

    if (N <= 2 || N > 10) {
        cout << "Invalid Size" << endl;
        return 0;
    }

    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insertBST(root, val);
    }

    int count = 0;
    inorderSecondElement(root, count);

    return 0;
}
