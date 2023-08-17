//
// Created by SRI VISHNU JSB on 8/17/2023.
//
/*
Count the number of lower case characters from the array of characters having alphanumeric symbol. The size of array should be greater than 0 and less than equal to 20. If size is not in the mention range than program should display “Invalid array size” without asking for the second input. And if no lower case character is present then display -1.

Input Format

Your program should take two types of inputs. First will represent size of array and second will represent elements of array. Sample Input: 6 H e L L O 2

Constraints

The length of array (L) should be 0 < L <=20

Output Format

Should display the number of lower case characters in ‘int’ form. If no such character is present then display -1. Sample Output: 1

Sample Input 0

6
H
e
L
L
O
2
Sample Output 0

1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int size;
    scanf("%d", &size);

    // Check if the array size is valid
    if (size <= 0 || size > 20) {
        printf("Invalid array size\n");
        return 0;
    }

    char array[size];
    int lowercaseCount = 0;

    for (int i = 0; i < size; i++) {
        scanf(" %c", &array[i]);

        // Check if the character is alphanumeric and lowercase
        if (isalnum(array[i]) && islower(array[i])) {
            lowercaseCount++;
        }
    }

    if (lowercaseCount > 0) {
        printf("%d\n", lowercaseCount);
    } else {
        printf("-1\n");
    }

    return 0;
}
