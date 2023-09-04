/*
Mr. Rohan packed his books in a box having capacity to put 6 books. Now he wants to arrange the books in an another box. He is picking one book at time and then putting it in another box. Write a program that will display the books he popped out and insert in another box(reverse order). Create push and pop functions to implement it. If the first box is empty then display message of "Empty Box". If the number of box is not capable of storing the books then display a message of "Full Box".

Input Format

first line contains the number of books, i.e. n next n lines contains the name of books in the stack of box.

Constraints

0<n≤6

Output Format

Output contains the list of books popped out from the box and inserted to the other books.Two book names should be separeted by -> sign.

Sample Input 0

3
Let_us_C
Oracle
DBMS
Sample Output 0

DBMS->Oracle->Let_us_C
Explanation 0

first line is number of books i.e. 3
The order of books pushed in the first Box fom top is 1Let_us_C 2.Oracle 3. DBMS.
So if we pop out the books then the books are popped out in the reverse order(LIFO).
So the output will be DBMS->Oracle->Let_us_C.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_SIZE 6

vector<string> box;
int top = -1;

bool isFull() {
    return box.size() == MAX_SIZE;
}

bool isEmpty() {
    return top == -1;
}

void push(string book) {
    if (isFull()) {
        cout << "Full Box" << endl;
        return;
    }
    top++;
    box.push_back(book);
}

string pop() {
    if (isEmpty()) {
        cout << "Empty Box" << endl;
        return "";
    }
    top--;
    string book = box.back();
    box.pop_back();
    return book;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string book;
        getline(cin, book);
        push(book);
    }

    for (int i = 0; i < n - 1; i++) {
        cout << pop() << "->";
    }
    cout << pop() << endl;

    return 0;
}
