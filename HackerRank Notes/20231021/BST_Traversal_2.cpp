

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* firstLargest = NULL;
Node* secondLargest = NULL;

void findSecondLargest(Node* root) {
    if (root == NULL || secondLargest != NULL)
        return;
    
    findSecondLargest(root->right);
    
    if (firstLargest == NULL) {
        firstLargest = root;
    } else if (secondLargest == NULL) {
        secondLargest = root;
        return;
    }
    
    findSecondLargest(root->left);
}

string findLocation(Node* root, Node* target) {
    if (root == NULL) return "";
    
    if (root->right == target) return "Right of " + to_string(root->data);
    if (root->left == target) return "Left of " + to_string(root->data);
    
    string left = findLocation(root->left, target);
    if (left != "") return left;
    
    return findLocation(root->right, target);
}

int main() {
    int n, val;
    cin >> n;

    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val);
    }

    findSecondLargest(root);
    
    if (secondLargest != NULL) {
        cout << findLocation(root, secondLargest) << endl;
    } else {
        cout << "No second largest element found" << endl;
    }
    
    return 0;
}
