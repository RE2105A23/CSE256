//
// Created by SRI VISHNU JSB on 8/25/2023.
//
/*
Create a two-way linked list of N integer elements. Delete all the occurrences of the elements from the first occurrence till second last occurrence of the entered specific value. The number of elements should be greater than 2 and less than equal to 20 in the list. If size is not in the mention range than program should display “Invalid list size” without asking for the second input. If the number to be deleted is not present or present only one time, display the message “Deletion not possible”.

Input Format

Your program should take three types of inputs. First input will represent the number of elements in the two-way linked list. Second type input will be the elements of the linked list from the first elements till last element. And the third input should be the value to be deleted.

Constraints

The number of elements (N) in the list should be 2 < N <=20

Output Format

Your program should display the elements of the linked list in backward direction after deleted elements. If any condition fails, it should display the corresponding mentioned messages.

Sample Input 0

4
1
2
3
2
2
Sample Output 0

2
3
1
Sample Input 1

3
1
2
3
2
Sample Output 1

Deletion not possible
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void deleteOccurrences(int value) {
        if (!head || !head->next) {
            std::cout << "Deletion not possible" << std::endl;
            return;
        }
        
        Node* curr = head;
        Node* lastOccurrence = nullptr;
        int count = 0;
        
        while (curr) {
            if (curr->data == value) {
                count++;
                if (count == 1) {
                    curr = curr->next;
                    continue;
                }
                lastOccurrence = curr;
            }
            curr = curr->next;
        }
        
        if (count < 2) {
            std::cout << "Deletion not possible" << std::endl;
            return;
        }
        
        Node* temp = lastOccurrence->next;
        
        if (temp) {
            lastOccurrence->next = nullptr;
            while (temp) {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
        }
        
        printBackward();
    }
    
    void printBackward() {
        Node* curr = tail;
        while (curr) {
            std::cout << curr->data << std::endl;
            curr = curr->prev;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
     int N;
    std::cin >> N;
    
    if (N <= 2 || N > 20) {
        std::cout << "Invalid list size" << std::endl;
        return 0;
    }
    
    DoublyLinkedList list;
    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        list.insert(value);
    }
    
    int valueToDelete;
    std::cin >> valueToDelete;
    
    list.deleteOccurrences(valueToDelete);
    
    return 0;
}
