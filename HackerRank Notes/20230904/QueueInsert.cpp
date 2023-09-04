/*
Write a program to create the queue of N elements in increasing order. Size of the queue should be greater than 2 and less than equal to 10. All the elements of the queue should be in increasing order. Element will not inserted in the queue if it new value is not in the ascending order then it will not insert it. If the size of the queue will not be in the mentioned range then it should display the message “Invalid size” with taking any elements for input.

Input Format

First line contains take the N that represent the number of elements in the queue second line contains the elements of queue in the increasing order.

Constraints

Size (N) of the queue should be 2 < N <= 10.
All the elements should be in increasing order.
Output Format

Your program should display the elements of the queue from front to rear. But if the size will be invalid then display the message “Invalid size”.

Sample Input 0

4
2 3 1 4 
Sample Output 0

2 3 4
Explanation 0

First line: N=4
Second line: Values to insert in the queue are 2 3 1 and 4
first it will insert 2 in queue,
then it will insert 3 in queue,
then it will not insert 1 in the queue as it is not in ascending order,
then it will insert 4 in the queue,
So, finally in the queue the elements are 2 3 and 4.
So, the output is 2 3 4.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


const int SIZE = 10;
int q[SIZE];  // Array to store the queue elements
int front = 0;
int rear = -1;
int prevValue = -1;  // To track the previous value

void enqueue(int value) {
    // Check if the current value is greater than the previous value
    // If it's the first value or it's in increasing order, add it to the queue
    if (rear == -1 || value > prevValue) {
        rear++;
        q[rear] = value;
        prevValue = value;
    }
}

void displayQueue() {
    // Display the queue's elements
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;
    cin >> N;

    // Check if the size is in the valid range
    if (N <= 2 || N > 10) {
        cout << "Invalid size" << endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        enqueue(value);
    }

    displayQueue();
    
    
    return 0;
}
