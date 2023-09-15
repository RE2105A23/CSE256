/*
Create a node with a name as Node. A Node object has an integer data field, and a Node forwd pointer, pointing to forward node (i.e.: the next node in a list) and a Node back pointer ,pointing to previous node(i.e,: the previous node in a list). In this node builder is inserting N house numbers at the end of list. A node is used to store N House Numbers .Create a program to help a builder to remove the last house number from colony and then print the list in both forward and backward direction.If N>=5 && N<15 condition is not satisfied then print Invalid Input.

Input Format

First line will contain one integer value reprenting the value of N(total number of houses).
N lines each contains one integer value which is representing house number which is inserted at end of list.

Constraints

N>=5 && N<15

Output Format

After deleting last house number traverse the list in forward direction.
After deleting last house number traverse the list in backward direction.

Sample Input 0

5
4
5
6
7
8
Sample Output 0

4 5 6 7
7 6 5 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* forwd;
    struct Node* back;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->forwd = NULL;
    newNode->back = NULL;

    if (!head) {
        head = tail = newNode;
    } else {
        tail->forwd = newNode;
        newNode->back = tail;
        tail = newNode;
    }
}

void deleteEnd() {
    if (!head) return;

    if (head == tail) {
        free(head);
        head = tail = NULL;
        return;
    }

    Node* temp = tail;
    tail = tail->back;
    tail->forwd = NULL;
    free(temp);
}

void displayForward() {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->forwd;
    }
    printf("\n");
}

void displayBackward() {
    Node* current = tail;
    while (current) {
        printf("%d ", current->data);
        current = current->back;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 5 || n >= 15) {
        printf("Invalid Input\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int houseNum;
        scanf("%d", &houseNum);
        insertEnd(houseNum);
    }

    deleteEnd();
    displayForward();
    displayBackward();

    return 0;
}
