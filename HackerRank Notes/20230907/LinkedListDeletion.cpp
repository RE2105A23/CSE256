/*
WAP to accept N Numbers into to an Singly Link list and delete the largest Number from the Link list.

For Example if 5 numbers are 3 5 8 6 4 then as 8 is largest Number, delete 8 then the output will be 3 5 6 4

Input Format

First line will be the number N. Second Line will accect N numbers from the user.

Sample Input 1: 5
4 8 3 6 2

Sample Output 1: 4 3 6 2

Sample Input 2: 6
7 5 3 9 1 4

Sample Output 2:

7 5 3 1 4

Constraints

All the inputs are positive integers and numbers entered in the second line of input are non-duplicate

Output Format

Prints all the numbers after removing the number from the Linked List

Sample Input 0

5
2 8 7 9 3
Sample Output 0

2 8 7 3
*/

//
// Created by SRI VISHNU JSB on 2023/09/07
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    // Insert new node at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if(!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Delete the largest element from the linked list
    void deleteLargest() {
        if(!head) return;

        Node* temp = head;
        int maxVal = temp->data;

        // Find the largest value in the list
        while(temp) {
            maxVal = max(maxVal, temp->data);
            temp = temp->next;
        }

        // Special case for head
        while(head && head->data == maxVal) {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        }

        if(!head) return;

        temp = head;
        while(temp->next) {
            if(temp->next->data == maxVal) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                delete nodeToDelete;
            } else {
                temp = temp->next;
            }
        }
    }
    
    // Display the linked list
    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    LinkedList ll;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        ll.insert(num);
    }

    ll.deleteLargest();
    ll.display();

    return 0;
}
