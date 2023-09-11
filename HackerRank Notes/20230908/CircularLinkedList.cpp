/*
Ayushi got a new problem in her subject. She was given a Circular Singly Linklist in which every node contains a pointer ‘next’ which points to the next node in the list. Last node ‘next’ pointer points to the first node in the linked list. Every node has a ‘data’ part that contains some integer positive. You have to delete the node in the linked list at the given position N.

Input Format

Assume all the indexing starts from Zero. N will be always less or equal to the nos. of node in the linked list.

Constraints

N>0 & N<50
Output Format

First line will contain N.
Second line will contain total nos. of element in the linklist before the operation.
Third line will contain space separated integer that depicts the data part from Linked List
Sample Input 0

3
7
2 5 7 8 9 10 12
Sample Output 0

2 5 7 9 10 12
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void append(int data) {
        if (!head) {
            head = new Node(data);
            head->next = head;
        } else {
            Node* temp = new Node(data);
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = temp;
            temp->next = head;
        }
    }

    void deleteAtPos(int pos) {
        if (!head) return;
        if (pos == 0) {
            Node* temp = head;
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            if (head->next == head) {
                head = NULL;
            } else {
                curr->next = head->next;
                head = head->next;
            }
            delete temp;
            return;
        }
        Node* curr = head;
        int count = 0;
        while (count < pos - 1 && curr->next != head) {
            curr = curr->next;
            count++;
        }
        if (curr->next == head) return;
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int pos, n, val;
    cin >> pos >> n;
    CircularLinkedList cll;

    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.append(val);
    }

    cll.deleteAtPos(pos);
    cll.display();

    return 0;
}
