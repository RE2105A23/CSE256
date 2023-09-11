/*
Given a doubly linked list containing N nodes. In N nodes the data part represents the roll no's of students. The task is to delete all the odd roll no's from the list.Create a program to insert N rollno's from the tail of doubly linked list,

Input:
5 15 <=> 16 <=> 6 <=> 7 <=> 17 Output: 16 <=> 6 Explanation: 15,7 and 17 are odd rollno's. So we need to delete them.

Input: 4 6 <=> 8 <=> 4 <=> 2 Output: No student is having odd roll number.

Input: 18 Wrong Input.

Input Format

First line will contain one integer value reprenting the value of N(total number of roll no's).
N lines each contains one integer value which is representing roll no's which is inserted at the end of list.

Constraints

N>=3 && N<12

Output Format

After deleting last house number traverse the list in forward direction.

Sample Input 0

4
1
2
3
4
Sample Output 0

2 4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteOddNodes() {
        Node* curr = head;
        while (curr) {
            if (curr->data % 2 != 0) {
                if (curr->prev) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                if (curr->next) {
                    curr->next->prev = curr->prev;
                }
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N, rollno;
    cin >> N;

    if (N < 3 || N >= 12) {
        cout << "Wrong Input." << endl;
        return 0;
    }

    DoublyLinkedList dll;
    for (int i = 0; i < N; i++) {
        cin >> rollno;
        dll.append(rollno);
    }

    dll.deleteOddNodes();
    dll.display();

    return 0;
}
