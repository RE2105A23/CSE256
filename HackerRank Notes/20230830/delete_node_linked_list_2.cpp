/*
Write a program to delete the node from given position in the linked list. The list may be empty after you delete the node. In that case, print "SLL is Empty". If position of linked list is not valid then print a message of "Invalid Position"


Use the following structure to implement it.
struct node SLLNode
{
int data;
SLLNode* next;
};

Input Format

The first line of input contains the number of elements in the linked list.
The second line of input contains an space separeted node data values.
The Third line contains the position of the node(position number starts from 0) to delete.

Constraints

0<=n<=1000, where n is number of elements in the linked list.
the data part of node also must be in between 0 to 1000.

Output Format

It will display the singly linked list after deleting the node from the singly linked list.
The list may be empty after you delete the node. In that case, print "SLL is Empty". If position of linked list is not valid then print a message of "Invalid Position"


Sample Input 0

8
2 6 5 1 7 4 15 9
3
Sample Output 0

2 6 5 7 4 15 9
Explanation 0

The original list is 2->6->5->1->7->4->15->9.
After deleting the node at position 3, the list is 2->6->5->7->4->15->9.
*/

//
// Created by SRI VISHNU JSB on 2023/08/30
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct SLLNode {
    int data;
    SLLNode* next;
};

class SinglyLinkedList {
private:
    SLLNode* head;

public:
    SinglyLinkedList() : head(NULL) {}

    void append(int data) {
        SLLNode* newNode = new SLLNode;
        newNode->data = data;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
        } else {
            SLLNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteAtPosition(int pos) {
        if (!head || pos < 0) {
            cout << "Invalid Position" << endl;
            exit(0);  // Exit the program if position is invalid
        }
        
        if (pos == 0) {
            SLLNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        SLLNode* curr = head;
        SLLNode* prev = NULL;
        int count = 0;
        while (curr && count < pos) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (!curr) {
            cout << "Invalid Position" << endl;
            exit(0);  // Exit the program if position is invalid
        }

        prev->next = curr->next;
        delete curr;
    }

    void display() {
        if (!head) {
            cout << "SLL is Empty" << endl;
            return;
        }

        SLLNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
     int n, data, position;
    cin >> n;
    
    if (n < 0 || n > 1000) {
        cout << "Invalid list size" << endl;
        return 0;
    }
    
    SinglyLinkedList sll;
    for (int i = 0; i < n; i++) {
        cin >> data;
        if (data < 0 || data > 1000) {
            cout << "Invalid data" << endl;
            return 0;
        }
        sll.append(data);
    }

    cin >> position;
    sll.deleteAtPosition(position);
    sll.display();
    return 0;
}

