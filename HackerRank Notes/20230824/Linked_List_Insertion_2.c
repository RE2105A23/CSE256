#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for the singly linked list
struct Node {
    char data;
    struct Node* next;
};

// Define the LinkedList structure
struct LinkedList {
    struct Node* head;
};

// Function to initialize a new LinkedList
void initLinkedList(struct LinkedList* list) {
    list->head = NULL;
}

// Function to insert a new element at the end of the list
void insertAtEnd(struct LinkedList* list, char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to print the linked list
void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

typedef struct Node Node;

Node* insert_character(Node* head, char new_char) {
    // Create a new node for the new character
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_char;
    new_node->next = NULL;

    // If the linked list is empty, just return the new node
    if (head == NULL) {
        return new_node;
    }

    // Find the last node in the linked list
    Node* last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    // Append the new character node to the end of the linked list
    last_node->next = new_node;

    // Check if the new character is a vowel
    int is_vowel = (new_char == 'A' || new_char == 'E' || new_char == 'I' ||
                   new_char == 'O' || new_char == 'U');

    // Check for 3 consecutive consonants condition
    Node* current = head;
    int consecutive_consonants = 0;

    while (current != NULL) {
        // Check for 3 consecutive consonants condition
        if (current->data != 'A' && current->data != 'E' && current->data != 'I' &&
            current->data != 'O' && current->data != 'U') {
            consecutive_consonants++;
            if (consecutive_consonants >= 3) {
                printf("Can't be inserted.\n");
                return head;
            }
        } else {
            consecutive_consonants = 0; // Reset count on encountering a vowel
        }

        current = current->next;
    }

    // Handle insertion at the beginning
    if (head == new_node || (is_vowel && (head->data != 'A' && head->data != 'E' &&
                                          head->data != 'I' && head->data != 'O' &&
                                          head->data != 'U'))) {
        return new_node;
    }

    // Find the correct position to insert
    current = head;
    Node* prev = NULL;

    while (current != NULL) {
        int is_current_vowel = (current->data == 'A' || current->data == 'E' ||
                                current->data == 'I' || current->data == 'O' || current->data == 'U');
        
        if (!is_vowel && is_current_vowel) {
            prev = current;
            current = current->next;
        } else {
            break;
        }
    }

    if (prev != NULL) {
        new_node->next = prev->next;
        prev->next = new_node;
    }

    return head;
}

// Function to free memory used by the linked list
void destroyLinkedList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct LinkedList list;
    initLinkedList(&list);

    int numCharacters;
    printf("Enter the number of characters: ");
    scanf("%d", &numCharacters);

    printf("Enter characters separated by whitespace: ");
    char character;
    for (int i = 0; i < numCharacters; ++i) {
        scanf(" %c", &character);
        insertAtEnd(&list, character);
    }

    printf("Linked List: ");
    display(&list);

    char new_char;
    scanf(" %c", &new_char);

    head = insert_character(head, new_char);

    destroyLinkedList(&list);

    return 0;
}
