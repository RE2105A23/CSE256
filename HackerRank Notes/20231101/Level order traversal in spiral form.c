/*
write the code to print the Level order traversal in spiral form for Binary Tree.

Input Format

First line reads the number of nodes N second line reads the N elements of the tree

Example: 7 1 3 5 7 9 11 13

Constraints

N>0, otherwise print "Tree root is empty"

Output Format

Spiral Order traversal of binary tree: 1 3 5 7 9 11 13
*/

#include <stdio.h>
#include <stdlib.h>

// Define the Tree Node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Define the Stack Node
typedef struct StackNode {
    TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

// Define the Stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new Tree Node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if(newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new Stack
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if(newStack == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newStack->top = NULL;
    return newStack;
}

// Function to check if a stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push a node onto the stack
void push(Stack* stack, TreeNode* treeNode) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    if(newStackNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newStackNode->treeNode = treeNode;
    newStackNode->next = stack->top;
    stack->top = newStackNode;
}

// Function to pop a node from the stack
TreeNode* pop(Stack* stack) {
    if(isEmpty(stack)) {
        fprintf(stderr, "Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    TreeNode* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

// Function to insert nodes into the tree in level order
TreeNode* insertLevelOrder(int arr[], TreeNode* root, int i, int n) {
    if (i < n) {
        TreeNode* temp = createNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to print the level order traversal in spiral form
void printSpiral(TreeNode* root) {
    if (root == NULL) return;

    // Create two stacks to hold the alternate levels
    Stack* stack1 = createStack();
    Stack* stack2 = createStack();

    // Push the root to stack1
    push(stack1, root);

    while (!isEmpty(stack1) || !isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            TreeNode* temp = pop(stack1);
            printf("%d ", temp->data);
            if (temp->left) push(stack2, temp->left);  // Left child is pushed before right
            if (temp->right) push(stack2, temp->right);
        }
        while (!isEmpty(stack2)) {
            TreeNode* temp = pop(stack2);
            printf("%d ", temp->data);
            if (temp->right) push(stack1, temp->right);  // Right child is pushed before left
            if (temp->left) push(stack1, temp->left);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);  // Number of nodes
    if(n <= 0) {
        printf("Tree root is empty\n");
        return 0;
    }

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Reading tree nodes
    }

    TreeNode* root = NULL;
    root = insertLevelOrder(arr, root, 0, n);  // Constructing the tree

    printf("Spiral Order traversal of binary tree: ");
    printSpiral(root);  // Print the spiral order traversal

    return 0;
}
