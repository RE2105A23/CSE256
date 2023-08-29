//
// Created by SRI VISHNU JSB on 2023/08/26
//
/*

Boby was asked to write a function for inserting a number in the linked list such that:

All the Odd Numbers are in the ascending order and all the even numbers are in descending order in the linked list.
Duplicate Number should not be inserted in the linked list.
Odd numbers are always placed before the even numbers in the list.

Example:

If the linked list is: 3 -> 7 -> 6 -> 4 -> 2 and 5 is to be inserted then it must be inserted between 3 and 7 and if 4 is to be inserted then it should not be allowed and Duplicates are not allowed must be printed.

Input Format

First line contains the number of nodes N in the list and second line contains N integers i.e. elements present in the nodes.

Third line contains the integer number to be inserted.

5
3 7 6 4 2
5

Constraints

N>0 and N<10

Output Format

Prints all the elements of the list after inserting the given element
3 5 7 6 4 2

Sample Input 0

5
3 7 9 6 2
4
Sample Output 0

3 7 9 6 4 2
Sample Input 1

5
1 3 5 6 2
2
Sample Output 1

Duplicates are not allowed
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node* &head, int data) {
    // If data already exists, return
    Node* temp = head;
    while (temp) {
        if (temp->data == data) {
            cout << "Duplicates are not allowed" << endl;
            return;
        }
        temp = temp->next;
    }
    
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    // If head is null, or new node should be placed before head
    if (!head || (data % 2 != 0 && data < head->data) || (data % 2 == 0 && data > head->data)) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    Node* prev = NULL;
    while (temp) {
        bool isTempEven = (temp->data % 2 == 0);
        bool isDataOdd = (data % 2 != 0);
        
        // Position to insert odd number
        if (isDataOdd && data < temp->data) break;

        // Position to insert even number
        if (!isDataOdd && isTempEven && data > temp->data) break;

        // Remember the previous node to help in insertion
        prev = temp;
        temp = temp->next;
    }

    newNode->next = temp;
    if (prev) prev->next = newNode;  // Insertion in between or at the end
    else head = newNode;             // Insertion at the beginning
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(head, val);
    }

    int numberToInsert;
    cin >> numberToInsert;
    insert(head, numberToInsert);

    printList(head);

    // Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
