/*
Kartik asked his friend Ganesh to write a program to delete all nodes having consonant character in a given singly linked list. Where each node store one character. If no consonants found in linked list, then display "No consonant in linked list". In Linked list each node contains one character. The node will be defined:

class Node { public: char data; Node* next; }

Input Format

Enter a list of charater ending with '\0'(NULL).

Constraints

Linked list should not be empty

Output Format

Display resultant singly linked list after deletion of all nodes having consonantcharacter in a given singly linked list.

Sample Input 0

c
o
m
p
u
t
e
r
Sample Output 0

o-->u-->e
Explanation 0

Input: c o m p u t e r
Output: o-->u-->e

Sample Input 1

s
c
i
e
n
c
e
Sample Output 1

i-->e-->e
Explanation 1

Input: s c i e n c e Output: i-->e-->e
*/

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
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert(char data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteConsonants() {
        while (head != NULL && !isVowel(head->data)) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (!isVowel(curr->next->data)) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }

    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data;
            if (curr->next != NULL) {
                cout << "-->";
            }
            curr = curr->next;
        }
    }

private:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    LinkedList ll;
    char c;

    //cout << "Enter characters (Enter '.' to terminate input):" << endl;
    while (cin >> c && c != '.') {
        ll.insert(c);
    }

    ll.deleteConsonants();

    if (ll.head == NULL) {
        cout << "No consonant in linked list" << endl;
    } else {
        ll.display();
    }

    return 0;
}
