/*
Given a singly linked list, find the middle of the linked list. For example, if the given linked list is A->B->C->D->E then the output should be C. If there are even nodes, then there would be two middle nodes, we need to print the first middle element. For example, if the given linked list is A->B->C->D->E->F then the output should be C.

Input Format

first line reads the number of elements N and
second line reads N elements of linked list

Example
5
A B C D E

Constraints

1<= N <= 20

Output Format

Prints the middle element of the linked list

Example:

C

Sample Input 0

5
A B C D E
Sample Output 0

C
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Function to push a new element to the linked list
void push(Node** head, char new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to find and print the middle element
void printMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    if (head != nullptr) {
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        cout << slow->data;
    }
}

int main() {
    int N;
    cin >> N;

    // Check constraints
    if (N < 1 || N > 20) {
        cout << "Invalid input" << endl;
        return 0;
    }

    Node* head = nullptr;
    char element;
    
    // Read elements and construct the linked list
    for (int i = 0; i < N; ++i) {
        cin >> element;
        push(&head, element);
    }

    // Print the middle element
    printMiddle(head);
    cout << endl;

    return 0;
}
