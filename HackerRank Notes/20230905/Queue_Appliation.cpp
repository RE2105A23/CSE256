/*
Analyse the following scenario and use appropriate data structure and functions to implement it. In a library, students are standing in a line to issue books. When a new student arrives he/she join at the end of the line. Librarian is issuing the books in the order in which the student arrives there in the line. Display the registration number of students in the order of books issued to them. The maximum capacity to stand in the queue is 20.

Input Format

First line contains number of students standing in the line
Second line contains the registration number of students separated by space, in the order they arrived there.
Sample Input
5
101 505 401 701 915

Constraints

0<=n<=20

Output Format

In output display the registration number of students in the order of books issued to them.
If there is no student in the line then display "Empty Line".
If the line exceeds the max limit then display "Overflow" message.

Sample Output
101 505 401 701 915

Sample Input 0

5
101 505 401 701 915
Sample Output 0

101 505 401 701 915
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 20;

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = MAX_SIZE - 1;
        size = 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull())
            return;

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty())
            return -1;

        int item = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;

        return item;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin >> n;

    if (n == 0) {
        cout << "Empty Line" << endl;
        return 0;
    }
    
    if (n > 20) {
        cout << "Overflow" << endl;
        return 0;
    }

    Queue studentQueue;

    for (int i = 0; i < n; i++) {
        int regNo;
        cin >> regNo;
        studentQueue.enqueue(regNo);
    }

    while (!studentQueue.isEmpty()) {
        cout << studentQueue.dequeue();
        if (!studentQueue.isEmpty()) {
            cout << " ";
        }
    }
    
    return 0;
}
