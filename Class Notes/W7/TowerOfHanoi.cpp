/*
Tower of Hanoi
*/
#include<iostream>
using namespace std;

// Recursive function to solve the Tower of Hanoi problem
void TOH(int n, char origin, char destination, char temp) {
    // Base case: if there's only one disk, move it directly
    if(n == 1) {
        cout << "Move disk 1 from " << origin << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from origin to temp peg, using destination as temporary peg
    TOH(n-1, origin, temp, destination);

    // Move nth disk from origin to destination peg
    cout << "Move disk " << n << " from " << origin << " to " << destination << endl;

    // Move n-1 disks from temp peg to destination, using origin as temporary peg
    TOH(n-1, temp, destination, origin);
}

int main() {
    TOH(5, 'L', 'R', 'C');
    return 0;
}