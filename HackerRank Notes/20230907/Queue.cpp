/*
Implement a Queue as mentioned:

An operation Z is of 2 Types.

1 p (operation of this type means you need to add p in queue)
0 (operation of this type means you need to pop in queue and print the popped element)
Input Format

First line tell the nos. of operation
Second line depicts the operation
Constraints

Explanation:

n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2 poped element will be 2 the queue will be {3}
1 4 the queue will be {3 4}
2 poped element will be 3
Output Format

Print popped elements

Sample Input 0

5
1 2 1 3 0 1 4 0
Sample Output 0

2 3
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

const int MAX_SIZE = 1000;  // Define a maximum size for the queue

class Queue {
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void push(int val) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = val;
    }

    int pop() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front++];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    Queue q;
    for(int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if(op == 1) {
            int val;
            cin >> val;
            q.push(val);
        } else if(op == 0) {
            if(!q.isEmpty()) {
                cout << q.pop() << " ";
            }
        }
    }

    return 0;
}
