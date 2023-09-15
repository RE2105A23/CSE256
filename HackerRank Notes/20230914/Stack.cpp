/*
Construct a stack using two queues (q1, q2), you need to simulate the stack operations by using queue operations. You are required to complete the three methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack, pop() which poped out from the stack and display() which display the resultant stack(-1 if the stack is empty).

Input Format

Enter the sequence of stack operation, 1 for push(), 2 for pop() and 3 for display().

Constraints

Maximum size of stack in 20

Output Format

Display result according to sequence of operations

Sample Input 0

1
2
1
3
2
1
4
2
1
5
3
Sample Output 0

2 5
Sample Input 1

1
2
2
3
Sample Output 1

-1
*/

#include <iostream>
#include <queue>

class Stack {
    std::queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty() && q2.empty()) {
            std::cout << "-1" << std::endl;
            return;
        }

        if (q1.empty()) std::swap(q1, q2);

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        std::swap(q1, q2);
    }

    void display() {
        if (q1.empty() && q2.empty()) {
            std::cout << "-1" << std::endl;
            return;
        }

        std::queue<int> temp = (q1.empty()) ? q2 : q1;
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    int t;
    Stack s;

    while (std::cin >> t) {
        switch (t) {
            case 1:
                int x;
                std::cin >> x;
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
        }
    }

    return 0;
}
