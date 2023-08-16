//
// Created by SRI VISHNU JSB on 8/16/2023.
//
/*
 During the get together party, Liza asked all her friends to play a game where all the N friends have been asked to arrange themselves in a row and assigned some unique number.

As per the rule of the game, Liza will show a number and the friend with that number needs to get out of the row and the vacant space should be occupied by all the friends on the right side such that the sequence is not disturbed.

Example:

If there are 5 friends with the numbers 4, 8, 3, 6, 2 and Liza has shown the number 8 then the remaining friends should have the numbers: 4, 3, 6, and 2.

Input Format

First line will be the number of friends N. Second Line will be the numbers assigned to the friends from left to right. Third Line will be the number shown by Liza.

Sample Input 1:

5

4 8 3 6 2

8

Sample Output 1:

4 3 6 2

Sample Input 2:

6

7 8 5 3 1 4

4

Sample Output 2:

7 8 5 3 1

Sample Input 3:

4

2 5 3 4

6

Sample Output 3:

2 5 3 4

Constraints

All the inpouts are positive integers and numbers entered in the second line of input are non-duplicate

Output Format

Prints all the numbers after removing the number from the list

Sample Input 0

5
4 2 8 3 5
2
Sample Output 0

4 8 3 5
Explanation 0

2 is removed and the elements to the right of 2 are shifted to the left to occupy the vacant positions
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf("%d", &N);

    int friends[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &friends[i]);
    }

    int numberShown;
    scanf("%d", &numberShown);

    // Find the position of the friend with the shown number
    int position = -1;
    for (int i = 0; i < N; i++) {
        if (friends[i] == numberShown) {
            position = i;
            break;
        }
    }

    // If the number was found, remove it and shift remaining elements
    if (position != -1) {
        for (int i = position; i < N - 1; i++) {
            friends[i] = friends[i + 1];
        }
        N--; // Decrease the count of friends
    }

    // Print the updated list of friends
    for (int i = 0; i < N; i++) {
        printf("%d", friends[i]);
        if (i != N - 1) {
            printf(" ");
        }
    }

    return 0;
}
