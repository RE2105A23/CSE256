#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* insert_character(Node* head, char new_char) {
    Node* new_node = new Node;
    new_node->data = new_char;
    new_node->next = nullptr;

    if (head == nullptr) {
        return new_node;
    }

    Node* current = head;
    Node* prev = nullptr;

    int consecutive_consonants = 0;
    bool suitable_position_found = false;

    while (current != nullptr) {
        if (!suitable_position_found &&
            (current->next == nullptr ||
             (current->next->data != 'A' && current->next->data != 'E' &&
              current->next->data != 'I' && current->next->data != 'O' &&
              current->next->data != 'U') &&
             (new_char != 'A' && new_char != 'E' && new_char != 'I' &&
              new_char != 'O' && new_char != 'U'))) {
            suitable_position_found = true;
            new_node->next = current->next;
            current->next = new_node;
            break;
        }

        if ((current->data == 'A' || current->data == 'E' || current->data == 'I' ||
             current->data == 'O' || current->data == 'U') &&
            (new_char == 'A' || new_char == 'E' || new_char == 'I' ||
             new_char == 'O' || new_char == 'U')) {
            prev = current;
            current = current->next;
            continue;
        }

        if (current->data != 'A' && current->data != 'E' && current->data != 'I' &&
            current->data != 'O' && current->data != 'U') {
            consecutive_consonants++;
            if (consecutive_consonants >= 3) {
                break;
            }
        } else {
            consecutive_consonants = 0;
        }

        prev = current;
        current = current->next;
    }

    if (suitable_position_found || consecutive_consonants < 3) {
        return head;
    } else {
        new_node->next = head;
        return new_node;
    }
}

void print_linked_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        std::cout << current << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        char data;
        std::cin >> data;

        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    char new_char;
    std::cin >> new_char;

    head = insert_character(head, new_char);

    if (head != nullptr) {
        print_linked_list(head);
    }

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}