/*
In this challenge, you must first implement a queue using two stacks. Then process queries, where each query is one of the following 3 types:

1 x: Enqueue element x into the end of the queue. 2: Dequeue the element at the front of the queue. 3: Print the element at the front of the queue.

Input Format

The first line contains a single integer, q, denoting the number of queries. Each line i of the q subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query type, but only query 1 is followed by an additional space-separated value,x, denoting the value to be enqueued.

Output Format

For each query of type 3 , print the value of the element at the front of the queue on a new line.
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int q, type, x;
    cin >> q;
    
    stack<int> stack1, stack2;
    
    for (int i = 0; i < q; ++i) {
        cin >> type;
        
        if (type == 1) {
            cin >> x;
            stack1.push(x);
        } 
        else {
            if (stack2.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            
            if (!stack2.empty()) {
                if (type == 2) {
                    stack2.pop();
                }
                
                if (type == 3) {
                    cout << stack2.top() << endl;
                }
            }
        }
    }
    
    return 0;
}

/*
Test Cases
9
1 3
1 7
3
2
1 5
3
2
3
2
*/