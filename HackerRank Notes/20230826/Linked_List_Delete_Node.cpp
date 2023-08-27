//
// Created by SRI VISHNU JSB on 2023/08/26
//
/*
Write a program to delete the node from given position in the linked list and return the reference to the head node. If the head is at position 0 and it's intial value is null. The list may be empty after you delete the node. In that case, print "SLL is Empty". If position of linked list is not valid them print a message of "Invalid Position"

Use the following structure to implement it. struct node SLLNode { int data; SLLNode* next; };

Input Format

The first line of input contains the number of elements in the linked list.
The second line of input contains an space separeted node data values.
The Third line contains the position of the node(position number starts from 0) to delete.
Sample Input 1
8
2 6 5 1 7 4 15 9
3
Sample Output 1
2 6 5 7 4 15 9

Explanation
The original list is 2->6->5->1->7->4->15->9.
After deleting the node at position 3, the list is 2->6->5->7->4->15->9.

Sample Input 2
1
2
0
Sample Output 2
SLL is Empty

Sample Input 3
1
2
3
Sample Output 3
Invalid Position

Constraints

0<=n<=1000, where n is number of elements in the linked list the data part of node also must be in between 0 to 1000.

Output Format

The first line of input contains the number of elements in the linked list.
The second line of input contains an space separeted node data values.
The Third line contains the position of the node(position number starts from 0) to delete.
Sample Input 1
8
2 6 5 1 7 4 15 9
3
Sample Output 1
2 6 5 7 4 15 9

Explanation
The original list is 2->6->5->1->7->4->15->9.
After deleting the node at position 3, the list is 2->6->5->7->4->15->9.

Sample Input 2
1
2
0
Sample Output 2
SLL is Empty

Sample Input 3
1
2
3
Sample Output 3
Invalid Position

Sample Input 0

8
2 6 5 1 7 4 15 9
3
Sample Output 0

2 6 5 7 4 15 9
Explanation 0

There are 8 elements in the Linked list, we want to delete the node aat position 3(index possition starts from 0). so at position 3 element 1 is there. 1 is deleted from the linked list and the output becomes 2 6 5 7 4 15 9
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

SLLNode* deleteNodeAtPosition(SLLNode* head, int position) {
    if (!head) {
        std::cout << "SLL is Empty" << std::endl;
        return nullptr;
    }

    if (position == 0) {
        SLLNode* newHead = head->next;
        delete head;
        return newHead;
    }

    SLLNode* current = head;
    SLLNode* previous = nullptr;
    int currentPosition = 0;

    while (current && currentPosition != position) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (!current) {
        std::cout << "Invalid Position" << std::endl;
        exit(0);
    }

    previous->next = current->next;
    delete current;
    return head;
}

void printLinkedList(SLLNode* head) {
    SLLNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n;
    std::cin >> n;

    SLLNode* head = nullptr;
    SLLNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (!head) {
            head = new SLLNode(val);
            tail = head;
        } else {
            tail->next = new SLLNode(val);
            tail = tail->next;
        }
    }

    int position;
    std::cin >> position;

    head = deleteNodeAtPosition(head, position);

    if (!head) {
        std::cout << "SLL is Empty" << std::endl;
    } else {
        printLinkedList(head);
    }

    return 0;
}
