/*
Misha is traversing a linked list and got to know that list is containing same data multiple time in adjacent nodes which makes her difficult to understand the data. She decided to add a number between two adjacent same values which will be equal to the sum of data in the node before the first node of adjacent nodes and data of node which is after the second node of adjacent node. Help her by writing a program.

Input Format

First line will contain an Integer N representing number of nodes in list.
N lines each containing an integer

Constraints

N>5 and N<10

Output Format

N space seperated integers representing data of list.
List of integeres not conatining same value at adjacent nodes.

Sample Input 0

6
5 2 2 3 3 4
Sample Output 0

5 2 8 2 3 6 3 4
Sample Input 1

2
Sample Output 1

Invalid Input
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int value) {
    if (!head) {
        head = new Node(value);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(value);
}

void processList(Node* head) {
    if (!head || !head->next || !head->next->next) {
        cout << "Invalid Input";
        return;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            int sum = 0;
            
            // Add value from the next of the duplicate node
            if (current->next->next) {
                sum += current->next->next->data;
            }

            // Add value from the node before the current node
            Node* prev = head;
            if (current != head) {
                while (prev->next != current) {
                    prev = prev->next;
                }
                sum += prev->data;
            }

            Node* newNode = new Node(sum);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next->next; // Skip the duplicate node
        } else {
            current = current->next;
        }
    }
}

void display(Node* head) {
    if (!head || !head->next || !head->next->next) {
        return; // We've already printed "Invalid Input" in processList
    }
    
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertEnd(head, value);
    }

    processList(head);
    display(head);

    return 0;
}
