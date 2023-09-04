/*
Write a program to create a stack for characters with push, pop functions having maximum capacity of 10 then you have to create a function to check whether given expression of '(' and ')' characters is balanced or not.

Input Format

Input line can be any expression having '(' and ')' characters.

Constraints

1≤n≤10

Output Format

If the parenthesis is balanced then it will display "Balanced" otherwise it will display "Not Balanced". If expression contains more than 10 symbols then display message of "Stack Full".

Sample Input 0

(())()
Sample Output 0

Balanced
Explanation 0

Every '(' have corresponding ')' at appropriate place

Sample Input 1

(()))
Sample Output 1

Not Balanced
Explanation 1

There are only two starting '(' and three ')' so it is not balanced
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 10;
char stack[SIZE];  // Array to store the stack elements
int top = -1;

bool isFull() {
    return top == SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(char ch) {
    if (!isFull()) {
        top++;
        stack[top] = ch;
    }
}

char pop() {
    if (!isEmpty()) {
        char temp = stack[top];
        top--;
        return temp;
    }
    return '\0';  // return null character if stack is empty
}

bool isBalanced(string exp) {
    for (size_t i = 0; i < exp.size(); i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty()) {
                return false;
            }
            pop();
        }
    }
    return isEmpty();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    string expression;
    getline(cin, expression);

    if (expression.size() > SIZE) {
        cout << "Stack Full" << endl;
        return 0;
    }

    if (isBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    
    return 0;
}
