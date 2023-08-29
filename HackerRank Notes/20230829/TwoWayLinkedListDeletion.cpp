/*
Create a two-way linked list of N integer elements. Enter a number to be deleted and delete the second last occurrence of the entered number. The number of elements should be greater than 2 and less than equal to 20. If size is not in the mention range than program should display “Invalid list size” without asking for the second input. If the number to be deleted is not present or present only one time, display the message “Deletion not possible”.

Input Format

Your program should take three types of inputs. First input will represent the number of elements in the two-way linked list. Second type input will be the elements of the linked list from the first elements till last element. And the third input should be the value to be deleted.

Constraints

The number of elements (N) in the list should be 2 < N <= 20

Output Format

Your program should display the elements of the linked list in backward direction after deleted element. If any condition fails, it should display the corresponding mentioned messages.

Sample Input 0

7
1
2
3
2
4
2
5
2
Sample Output 0

5
2
4
3
2
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

//
// Created by SRI VISHNU JSB on 2023/08/29
//

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
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteSecondLastOccurrence(int val) {
        Node* curr = head;
        int count = 0;
        
        // Count occurrences of the given value
        while (curr) {
            if (curr->data == val) {
                count++;
            }
            curr = curr->next;
        }
        
        // If the given value occurs less than 2 times, deletion is not possible
        if (count < 2) {
            cout << "Deletion not possible" << endl;
            exit(0);  // Exit the program if deletion is not possible
        }

        int target = count - 1;  // We need to delete the second last occurrence
        curr = head;
        count = 0;
        while (curr) {
            if (curr->data == val) {
                count++;
                if (count == target) {
                    // Delete the node
                    if (curr->prev) {
                        curr->prev->next = curr->next;
                    } else {
                        head = curr->next;
                    }
                    if (curr->next) {
                        curr->next->prev = curr->prev;
                    } else {
                        tail = curr->prev;
                    }
                    delete curr;
                    break;
                }
            }
            curr = curr->next;
        }
    }

    void displayBackward() {
        Node* curr = tail;
        while (curr) {
            cout << curr->data << endl;
            curr = curr->prev;
        }
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n, data;
    cin >> n;
    
    if (n <= 2 || n > 20) {
        cout << "Invalid list size" << endl;
        return 0;
    }
    
    DoublyLinkedList dll;
    for (int i = 0; i < n; i++) {
        cin >> data;
        dll.append(data);
    }

    cin >> data;
    dll.deleteSecondLastOccurrence(data);
    dll.displayBackward();
    
    return 0;
}