/*
Write a program to delete the first node from the circular linked list using pop() function. The list may be empty after you delete the node. In that case, print "CLL is Empty". If it is not possible to remove due to underflow the print a message of "Underflow". If number of elements is not valid then print a message of "Invalid Number"


Input Format

The first line of input contains the number of elements in the circular linked list.
The second line of input contains an space separeted node data values.

Constraints

0<=n<=1000, where n is number of elements in the linked list the data part of node also must be in between 0 to 1000.

Output Format

It will display the singly circular linked list after deleting the first node from it.
The list may be empty after you delete the node. In that case, print "CLL is Empty". If it is not possible to remove due to underflow the print a message of "Underflow". If number of elements is not valid then print a message of "Invalid Number"


Sample Input 0

5
1 2 3 4 5
Sample Output 0

2 3 4 5
*/

//
// Created by SRI VISHNU JSB on 2023/08/29
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() : last(NULL) {}

    void push(int data) {
        Node* temp = new Node;
        temp->data = data;

        if (!last) {
            last = temp;
            temp->next = last;
        } else {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    void pop() {
        if (!last) {
            cout << "Underflow" << endl;
            exit(0);  // Exit the program if underflow occurs
        }

        Node* temp = last->next;
        if (last == last->next) {
            delete last;
            last = NULL;
        } else {
            last->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (!last) {
            cout << "CLL is Empty" << endl;
            return;
        }

        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, data;
    cin >> n;
    
    if (n < 0 || n > 1000) {
        cout << "Invalid Number" << endl;
        return 0;
    }
    
    CircularLinkedList cll;
    for (int i = 0; i < n; i++) {
        cin >> data;
        if (data < 0 || data > 1000) {
            cout << "Invalid Number" << endl;
            return 0;
        }
        cll.push(data);
    }

    cll.pop();
    cll.display();       
    
    return 0;
}
