/*
Assume 9 spectators are standing in a ticket counter to take a ticket to watch a T20 match.In a queue enter n names of spectators and then some gifts will be given to odd ticket number spectators who came to watch match.Note index is ticket number and values in queues are name of spectators.Create a user interactive program where 1 will be for insertion and 2 will display names of odd ticket spectators who will get some gifts.

Input Format

First Input will represent the operation
Second Input will represent how many names to be inserted in case operation is insertion .
Third Input will be n names in a ticket counters.
Fourth Input is to call display operation

Constraints

If the size of the queue will be full, display “No other spectator is allowed”.

Output Format

Display names of spectator shortlisted for gifts.

Sample Input 0

1
3
Aryan
Piyush
Rahul
2
Sample Output 0

Piyush
*/

#include <iostream>
#include <string>
using namespace std;

class SpectatorQueue {
private:
    string arr[9];
    int front, rear, maxSize;

public:
    SpectatorQueue() {
        front = -1;
        rear = -1;
        maxSize = 9;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insert(string name) {
        if (isFull()) {
            cout << "No other spectator is allowed." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }
        arr[rear] = name;
    }

    void displayGiftReceivers() {
        if (isEmpty()) {
            return;
        }
        int count = 1;
        int i = front;
        while (true) {
            if (count % 2 == 0) {
                cout << arr[i] << endl;
            }
            if (i == rear) break;
            i = (i + 1) % maxSize;
            count++;
        }
    }
};

int main() {
    SpectatorQueue sq;
    int operation, n;
    cin >> operation;

    while (operation != 0) {
        if (operation == 1) {
            cin >> n;
            for (int i = 0; i < n; i++) {
                string name;
                cin >> name;
                sq.insert(name);
            }
        } else if (operation == 2) {
            sq.displayGiftReceivers();
        }
        cin >> operation;
    }

    return 0;
}
