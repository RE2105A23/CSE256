/*
Given the pointer to the head node of a doubly linked list, reverse the order of the
nodes in place. That is, change the next and prev pointers of the nodes so that the
direction of the list is reversed. Return a reference to the head node of the reversed list.
Note: The head node might be NULL to indicate that the list is empty.

Input Format

The first line contains an integer t, the number of test cases.
Each test case is of the following format:
• The first line contains an integer n, the number of elements in the linked list.
• The next n lines contain an integer each denoting an element of the linked list.

Constraints

0

Output Format

Return a reference to the head of your reversed list. The provided code will print the
reverse array as a one line of space-separated integers for each test case.

Sample Input 0

2
4
1 
2 
3 
4
3
6 
7
8
Sample Output 0

4 3 2 1
8 7 6
Explanation 0

There are 2 test cases n=4 element of two way linked list are 1 2 3 4 n=3 element of two way linked list are 6 7 8 So, first output is 4 3 2 1 and second output is 8 7 6
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure for Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Function to reverse the doubly linked list
Node* reverse(Node* head) {
    Node* temp = NULL;  
    Node* current = head;

    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;              
        current = current->prev;
    }

    // Before changing head, check for the cases like empty
    // list and list with only one node
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Node* head = NULL;
        Node* tail = NULL;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            Node* newNode = new Node(val);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        head = reverse(head);
        printList(head);
    }
    
    return 0;
}
