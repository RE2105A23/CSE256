/*
find the postorder traversal of the tree , in which preorder and inorder traversals are given.

Input Format

First line must be preorder traversal
second line must be inorder traversal

Constraints

Number of node n in binary tree, 3<=n<=10.
the elements of the node can be either alphabate or a number.

Output Format

postorder traversal

Sample Input 0

1 2 4 5 3 6 7
4 2 5 1 6 3 7
Sample Output 0

4 5 2 6 7 3 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

void findPostOrder(const vector<string>& preorder, const vector<string>& inorder,
                   int inStart, int inEnd, unordered_map<string, int>& inMap,
                   int& preIndex) {
    if (inStart > inEnd) {
        return;
    }
    
    string rootValue = preorder[preIndex];
    int inIndex = inMap[rootValue];
    preIndex++;

    findPostOrder(preorder, inorder, inStart, inIndex - 1, inMap, preIndex);
    findPostOrder(preorder, inorder, inIndex + 1, inEnd, inMap, preIndex);

    cout << rootValue << " ";
}

vector<string> split(const string& input, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(input);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string preorderInput, inorderInput;
    getline(cin, preorderInput);
    getline(cin, inorderInput);

    vector<string> preorder = split(preorderInput, ' ');
    vector<string> inorder = split(inorderInput, ' ');

    int n = inorder.size();
    if (n < 3 || n > 10) {
        cout << "Invalid input. Number of nodes must be between 3 and 10." << endl;
        return 1;
    }

    unordered_map<string, int> inMap;
    for (int i = 0; i < n; ++i) {
        inMap[inorder[i]] = i;
    }

    int preIndex = 0;
    findPostOrder(preorder, inorder, 0, n - 1, inMap, preIndex);
    cout << endl;

    return 0;
}
