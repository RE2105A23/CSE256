/*
Write a program to implement the Tower of Hanoi game. Tower of Hanoi is a game in which three pegs are available, i.e one is left peg(L), second is center peg(C) and third is right peg(R). Our target is to move all rings from left peg(L) to right peg(R). The objective of the game is to move the entire stack of rings from left peg(L) to the right peg(R), obeying the following rules:
1. Only one disk may be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty peg.
3. No disk may be placed on top of a disk that is smaller than it.

Input Format

Input contains number of rings required for Tower of Hanoi game.

Constraints

Number of rings must be in between 0 to 10.

Output Format

Output contains all steps of movement in the following format
Move ring # from ? to ?
Where # is the ring number, and ? is the peg name(i.e. L, R, or C)
If number of rings are out of the limit of constraints then display "Out of limit" message

Sample Input 0

2
Sample Output 0

Move ring 1 from L to C
Move ring 2 from L to R
Move ring 1 from C to R

*/

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        cout << "Move ring 1 from " << from_peg << " to " << to_peg << endl;
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    cout << "Move ring " << n << " from " << from_peg << " to " << to_peg << endl;
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main() {
    int n;
    //cout << "Enter the number of rings: ";
    cin >> n;

    if (n < 0 || n > 10) {
        cout << "Out of limit" << endl;
        return 1;
    }

    towerOfHanoi(n, 'L', 'R', 'C');
    return 0;
}
