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
Explanation 0

number of elements =4 elements are 1 2 3 2 delete 2

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
// Created by SRI VISHNU JSB on 2023/09/07
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert at the end of the list
Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(!head) {
        return newNode;
    }

    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to delete occurrences except last
Node* deleteElement(Node* head, int value) {
    Node* temp = head;
    int count = 0;

    // Count occurrences of value
    while(temp) {
        if(temp->data == value) {
            count++;
        }
        temp = temp->next;
    }
    
    // If value occurs only once or not present
    if(count <= 1) {
        cout << "Deletion not possible" << endl;
        return NULL;
    }

    // Delete all occurrences except last
    temp = head;
    for(int i = 1; i < count; i++) {
        while(temp && temp->data != value) {
            temp = temp->next;
        }
        if(temp->prev) {
            temp->prev->next = temp->next;
        }
        if(temp->next) {
            temp->next->prev = temp->prev;
        }
        Node* delNode = temp;
        temp = temp->next;
        delete delNode;
    }
    if(head->data == value) {
        head = head->next;
    }
    return head;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, val;
    cin >> n;
    if(n <= 2 || n > 20) {
        cout << "Invalid list size" << endl;
        return 0;
    }
    Node* head = NULL;
    for(int i = 0; i < n; i++) {
        cin >> val;
        head = insertEnd(head, val);
    }
    int delVal;
    cin >> delVal;

    head = deleteElement(head, delVal);
    Node* temp = head;
    while(temp && temp->next) {
        temp = temp->next;
    }
    while(temp) {
        cout << temp->data << endl;
        temp = temp->prev;
    }

    return 0;
}
