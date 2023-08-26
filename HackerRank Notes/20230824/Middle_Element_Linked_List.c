//
// Created by SRI VISHNU JSB on 8/24/2023.
//
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

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

typedef struct Node Node;

Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* find_middle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        char data;
        scanf(" %c", &data);

        Node* new_node = create_node(data);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    Node* middle = find_middle(head);

    printf("%c\n", middle->data);
    
    return 0;
}
