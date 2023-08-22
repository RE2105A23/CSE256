#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* head) {
    struct node* ptrNode;
    for (ptrNode = head; ptrNode->next != NULL; ptrNode = ptrNode->next) {
        printf("%d->", ptrNode->data);
    }
    printf("%d\n", ptrNode->data);
}

struct node* pushElement(struct node* head, int new_data) {
    // Step 1 -> Allocate Memory
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Overflow\n");
    } else {
        // Step 2 -> Assign new data to data field
        new_node->data = new_data;
        // Step 3 -> Assign head to new node's next index
        new_node->next = head;
        // Step 4 -> Assign the index of new_node to head index
        head = new_node;
    }
    return head;
}

int main() {
    struct node* head = NULL;

    head = pushElement(head, 10);
    head = pushElement(head, 20);
    head = pushElement(head, 30);
    head = pushElement(head, 40);
    printf("Linked List\n");
    display(head);

    return 0;
}
