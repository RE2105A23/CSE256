#include <stdio.h>
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
        printf("%p ", current);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        char data;
        scanf(" %c", &data);

        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    char new_char;
    scanf(" %c", &new_char);

    head = insert_character(head, new_char);

    // After calling insert_character function and updating the linked list
    if (head != NULL) {
        print_linked_list(head);
        //print_linked_list_reverse(head);  // Uncomment this line if needed
        //printf("\n");
    }

    // Free memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
