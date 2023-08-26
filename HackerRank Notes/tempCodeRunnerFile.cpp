#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteLastOccurrence(int value) {
        Node* current = tail;
        while (current && current->data != value) {
            current = current->prev;
        }

        if (current) {
            if (current != tail) {
                current->prev->next = current->next;
            } else {
                tail = current->prev;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            delete current;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    int N;
    std::cout << "Enter the value of N (2 < N <= 20): ";
    std::cin >> N;

    if (N <= 2 || N > 20) {
        std::cout << "Invalid input for N. Exiting." << std::endl;
        return 1;
    }

    DoublyLinkedList list;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> value;
        list.insert(value);
    }

    std::cout << "Values in the list before deletion: ";
    list.display();

    int deleteValue;
    std::cout << "Enter the value to delete: ";
    std::cin >> deleteValue;

    list.deleteLastOccurrence(deleteValue);

    std::cout << "Values in the list after deletion: ";
    list.display();

    return 0;
}
