//
// Created by SRI VISHNU JSB on 8/24/2023.
//
/*
After discussing the concepts of One-way Linked List, Professor Samuel asked his students to implement a function for inserting a node in the singly linked list such that the charcters present in the linked list nodes follow the given condition:

A vowel must not be present adjacent to another vowel
3 consecutive consonants must not be there in the list
Students were supposed to implement a function to insert the node with given charater in the very first suitable position of the list.

Example: C -> B -> E -> K -> A

Now If the character X is to be inserted in the list then, it must be inserted between E and K.

C -> B -> E -> X -> K -> A

In the above example, if A is to be inserted then, It can be inserted in the beginning only.

A -> C -> B -> E -> K -> A

If there is no suitable position available then print Can't be inserted

Input Format

First line contains the total number of nodes in the list and second line contains the characters present on those nodes.

Third line contains the Character to be inserted.

5
P A G E K
S

Constraints

All the characters in the node are in UPPERCASE.

Output Format

Prints all the Characters of the linked list (seperated by SPACE) after insertion

S P A G E K

Sample Input 0

5
A C P O T
B
Sample Output 0

B A C P O T
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

Node* insert_character(Node* head, char new_char) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_char;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    Node* current = head;
    Node* prev = NULL;

    // Check for adjacent vowels and 3 consecutive consonants conditions
    int consecutive_consonants = 0;
    while (current != NULL) {
        // Check for adjacent vowels condition
        if ((current->data == 'A' || current->data == 'E' || current->data == 'I' ||
             current->data == 'O' || current->data == 'U') &&
            (new_char == 'A' || new_char == 'E' || new_char == 'I' ||
             new_char == 'O' || new_char == 'U')) {
            prev = current;
            current = current->next;
            continue;
        }

        // Check for 3 consecutive consonants condition
        if (current->data != 'A' && current->data != 'E' && current->data != 'I' &&
            current->data != 'O' && current->data != 'U') {
            consecutive_consonants++;
            if (consecutive_consonants >= 3) {
                break; // Found 3 consecutive consonants
            }
        } else {
            consecutive_consonants = 0; // Reset count on encountering a vowel
        }

        prev = current;
        current = current->next;
    }

    if (consecutive_consonants >= 3) {
        // We have found 3 consecutive consonants, so insert after the last consecutive consonant
        new_node->next = current;
        if (prev != NULL) {
            prev->next = new_node;
        } else {
            head = new_node;
        }
    } else {
        // Insert at the beginning if no 3 consecutive consonants found
        new_node->next = head;
        head = new_node;
    }

    return head;
}

void print_linked_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d", &n);

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        char data;
        scanf(" %c", &data);

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    char new_char;
    scanf(" %c", &new_char);

    head = insert_character(head, new_char);

    print_linked_list(head);

    return 0;

}
