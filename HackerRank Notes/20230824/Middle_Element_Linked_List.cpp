#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev_slow = nullptr;  // To track the previous slow pointer position

    while (fast != nullptr && fast->next != nullptr) {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr) {
        return prev_slow;
    } else {
        return slow;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i) {
        char data;
        std::cin >> data;

        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    Node* middle = findMiddle(head);

    std::cout << middle->data << std::endl;

    // Clean up the memory (deallocate nodes)
    Node* current = head;
    while (current) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }

    return 0;
}
