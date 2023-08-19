//
// Created by SRI VISHNU JSB on 8/19/2023.
//
/*
In a conference hall some persons are sitting on the chairs on the front row from left to right. Suddenly a person wants to sit near his friend. He requested other persons who are sitting on that position and the right side of that position to shift on right side so that he can sit at specified position.

Persons are represented by alphabets like A, B, C, D, etc

If in the beginning A, B, C, and D are sitting on 1st , 2nd ,3rd and 4th chair and a new person E wants to sit at 2nd chair, then the new array should be A, E, B, C, D will be your output.

In this program you have to take input n for number of elements at beginning, then read all person names as Alphabets, read the chair number for insertion, and read the alphabet representing new person. If invalid position is there then print message of “Invalid Position” .

Input Format

First line: It contains number of persons(i.e n) sitting on an array in the beginning Second Line: It contains the tab separated person name. where person name can be selected as any capital letter of alphabet (like A, B, C, D etc)
Third Line : It is the chair number where a new person wants to sit.
Fourth Line : It is the capital alphabet representing the new person.
Sample Input1
4
A B C D
2
E
Sample Output1 **
A E B C D

**Sample Input2
4
A B C D
1
X
Sample Output2
X A B C D
Sample Input3
4
A B C D
0
X
Sample Output3
Invalid Position


Constraints

Number of Persons :n>=0 position of person to insert must be non zero positive numbers

Output Format

Output is list of persons after insertion at the specified position, separated by tab. there is no tab after last element is printed. If position is invalid then display a message "Invalid Position"
Sample Input1
4
A B C D
2
E
Sample Output1 **
A E B C D

**Sample Input2
4
A B C D
1
X
Sample Output2
X A B C D
Sample Input3
4
A B C D
0
X
Sample Output3
Invalid Position


Sample Input 0

4
A    B    C    D
2
E
Sample Output 0

A    E    B    C    D
Sample Input 1

4
A    B    C    D
0
X
Sample Output 1

Invalid Position
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void shiftRight(char array[], int position, int n) {
    for (int i = n - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n;
    scanf("%d", &n);

    char persons[26];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &persons[i]);
    }

    int newPosition;
    scanf("%d", &newPosition);

    if (newPosition < 1 || newPosition > n + 1) {
        printf("Invalid Position\n");
        return 0;
    }

    char newPerson;
    scanf(" %c", &newPerson);

    shiftRight(persons, newPosition - 1, n);
    
    persons[newPosition - 1] = newPerson;

    for (int i = 0; i <= n; i++) {
        printf("%c", persons[i]);
        if (i != n) {
            printf("\t");
        }
    }
    printf("\n");

    return 0;
}
