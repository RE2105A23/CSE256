/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they are all the same height, then return the height.

Example

There are and cylinders in the three stacks, with their heights in the three arrays. Remove the top 2 cylinders from (heights = [1, 2]) and from (heights = [1, 1]) so that the three stacks all are 2 units tall. Return as the answer.

Note: An empty stack is still a stack.

Input Format

The first line contains three space-separated integers, , , and , the numbers of cylinders in stacks , , and . The subsequent lines describe the respective heights of each cylinder in a stack from top to bottom:

The second line contains space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.

The third line contains space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.

The fourth line contains space-separated integers, the cylinder heights in stack . The first element is the top cylinder of the stack.

Samlple Input:

STDIN Function ----- -------- 5 3 4 h1[] size n1 = 5, h2[] size n2 = 3, h3[] size n3 = 4
3 2 1 1 1 h1 = [3, 2, 1, 1, 1] 4 3 2 h2 = [4, 3, 2] 1 1 4 1 h3 = [1, 1, 4, 1]

Sample output:

5

Constraints

0 < n1,n2,n3 < 10 0 < height of Cylinder <100

Output Format

the height of the stacks when they are equalized
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> h1(n1), h2(n2), h3(n3);

    for (int i = 0; i < n1; i++) cin >> h1[i];
    for (int i = 0; i < n2; i++) cin >> h2[i];
    for (int i = 0; i < n3; i++) cin >> h3[i];

    int sum1 = accumulate(h1.begin(), h1.end(), 0);
    int sum2 = accumulate(h2.begin(), h2.end(), 0);
    int sum3 = accumulate(h3.begin(), h3.end(), 0);

    int i1 = 0, i2 = 0, i3 = 0;

    while (sum1 != sum2 || sum1 != sum3) {
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= h1[i1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= h2[i2++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= h3[i3++];
        }
    }

    cout << sum1 << endl;

    return 0;
}

//Custom Inputs
/*
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1
*/
