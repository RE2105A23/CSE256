#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Inserting a new node at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = new struct Node;
    newNode->data = data;
    newNode->next = nullptr;
    
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    std::cin >> n;

    if (n < 0 || n > 7) {
        std::cout << "Invalid Range" << std::endl;
        return 0;
    }

    struct Node* head = nullptr;
    int value;

    for (int i = 0; i < n; i++) {
        std::cin >> value;
        insert(&head, value);
    }

    int oddSum = 0, evenSum = 0;

    struct Node* current = head;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            evenSum += current->data;
        } else {
            oddSum += current->data;
        }
        current = current->next;
    }

    std::cout << oddSum << " " << evenSum << std::endl;

    return 0;
}
