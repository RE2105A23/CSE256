/*
Check if given Preorder, Inorder and Postorder traversals are of same tree or not

Input Format

The first line must be preorder traversal
The Second line must be Inorder Traversal
The Third Line Must be Post Order Traversal

Constraints

Number of node n in binary tree, 3<=n<=10.
The node Elements can be alphabates or Numericals

Output Format

Output will be either "yes" or "no" .
(if constraints are not following then will display "Invalid input").

Sample Input 0

4 2 5 1 3
1 5 4 2 3
4 1 2 3 5
Sample Output 0

no
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* buildTree(vector<char>& preorder, int& preIndex,
                vector<char>& inorder, int inStart, int inEnd,
                vector<char>& postorder, int& postIndex) {
    if (inStart > inEnd)
        return nullptr;

    Node* root = new Node{preorder[preIndex++], nullptr, nullptr};

    int rootIndex = -1;
    for (int i = inStart; i <= inEnd; ++i) {
        if (inorder[i] == root->data) {
            rootIndex = i;
            break;
        }
    }

    if (rootIndex == -1) return nullptr;  // Invalid traversal
    
    root->left = buildTree(preorder, preIndex, inorder, inStart, rootIndex - 1, postorder, postIndex);
    root->right = buildTree(preorder, preIndex, inorder, rootIndex + 1, inEnd, postorder, postIndex);

    if (root->data != postorder[postIndex]) return nullptr; // Invalid traversal

    postIndex++;

    return root;
}

int main() {
    vector<char> preorder, inorder, postorder;
    string line;

    getline(cin, line);
    stringstream ss1(line);
    char val;
    while (ss1 >> val) {
        preorder.push_back(val);
    }

    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> val) {
        inorder.push_back(val);
    }

    getline(cin, line);
    stringstream ss3(line);
    while (ss3 >> val) {
        postorder.push_back(val);
    }

    int preIndex = 0, postIndex = 0;
    Node* root = buildTree(preorder, preIndex, inorder, 0, inorder.size() - 1, postorder, postIndex);

    if (root && preIndex == preorder.size() && postIndex == postorder.size()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}

