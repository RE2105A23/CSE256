/*
Ajay got a new problem in his subject. He has given a Circular Singly Linklist in which every node contains a pointer ‘next’ which points to the next node in the list. Last node ‘next’ pointer points to the first node in the linked list. Every node has a ‘data’ part that contains some integer positive. You have to insert an integer Z in the linked list at the given position N.

Note:

Assume all the indexing starts from Zero. N will be always less or equal to the nos. of node in the linked list.
You need to create the circular linklist first and then perform operation.
Input Format

First line will contain N.
Second Line will contain Z.
Third Line will contain total nos. of element in the linklist before the operation.
Fourth line will contain space separated integer that depicts the data part from Linked List
Constraints

N>0 & N<50
Z>0 & Z<100
Output Format

Space separated integer that depicts the data part from Linked List after inserting Z at N.

Sample Input 0

3
10
7
2 5 7 8 9 10 12
Sample Output 0

2 5 7 10 8 9 10 12
Explanation 0

10 is inserted at position 3 in the circular linked list 2 5 7 8 9 10 12 having 7 elements in it
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* temp = createNode(data);
    if (!head) {
        temp->next = temp;
        head = temp;
    } else {
        Node* last = head->next;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp;
        temp->next = head;
    }
    return head;
}

Node* insertAtPos(Node* head, int data, int pos) {
    Node* temp = createNode(data);
    if (pos == 0) {
        temp->next = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp;
        head = temp;
    } else {
        Node* prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        temp->next = prev->next;
        prev->next = temp;
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N, Z, numElements, value;
    cin >> N >> Z >> numElements;

    Node* head = NULL;
    for (int i = 0; i < numElements; i++) {
        cin >> value;
        head = insertEnd(head, value);
    }

    head = insertAtPos(head, Z, N);
    printList(head);
    
    return 0;
}
