#include <iostream>

struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

SLLNode* deleteNodeAtPosition(SLLNode* head, int position) {
    if (!head) {
        std::cout << "SLL is Empty" << std::endl;
        return nullptr;
    }

    if (position == 0) {
        SLLNode* newHead = head->next;
        delete head;
        return newHead;
    }

    SLLNode* current = head;
    SLLNode* previous = nullptr;
    int currentPosition = 0;

    while (current && currentPosition != position) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (!current) {
        std::cout << "Invalid Position" << std::endl;
        exit(0);
    }

    previous->next = current->next;
    delete current;
    return head;
}

void printLinkedList(SLLNode* head) {
    SLLNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    SLLNode* head = nullptr;
    SLLNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        if (!head) {
            head = new SLLNode(val);
            tail = head;
        } else {
            tail->next = new SLLNode(val);
            tail = tail->next;
        }
    }

    int position;
    std::cin >> position;

    head = deleteNodeAtPosition(head, position);

    if (!head) {
        std::cout << "SLL is Empty" << std::endl;
    } else {
        printLinkedList(head);
    }

    return 0;
}
