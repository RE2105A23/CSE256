/*
WAP to insert N Elements into the stack. Find the Middle element , then delete one element from the stack and again find the new middle element
Use integer division to find the mid element Example

let 6 elements are there in stack
5
8
6
4
7
middle element is 6
deleted element is 7 (as it is at top)
new middle element is 8

Input Format

First input : N ,the number of elements in the stack
Second input : accept N elements from the user into the stack

Constraints

N must be nonzero and >=1, if not then display "Invalid number"
second input must be positive integers

Output Format

Dispaly Middle Element
Display The New Midlle Element After Deleting One element From The Stack.

Sample Input 0

5
2 6 8 7 4
Sample Output 0

8
6
Sample Input 1

3
5 8 6
Sample Output 1

8
5
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Stack {
private:
    Node* top;
    Node* middle;
    int count;

public:
    Stack() : top(nullptr), middle(nullptr), count(0) {}

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = top;
        
        count++;

        if (!top) {
            top = newNode;
            middle = newNode;
        } else {
            top->prev = newNode;
            top = newNode;

            if (count & 1) { // update middle for odd count
                middle = middle->prev;
            }
        }
    }

    void pop() {
        if (!top) return;

        Node* temp = top;
        top = top->next;

        if (top) {
            top->prev = nullptr;
        }

        delete temp;
        count--;

        if (!(count & 1)) { // update middle for even count
            middle = middle->next;
        }
    }

    int findMiddle() {
        if (middle) {
            return middle->data;
        }
        return -1; // signifies empty stack
    }
};

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        cout << "Invalid number" << endl;
        return 0;
    }

    Stack s;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s.push(val);
    }

    cout << s.findMiddle() << endl;
    s.pop();
    cout << s.findMiddle() << endl;

    return 0;
}
