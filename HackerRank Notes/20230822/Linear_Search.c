//
// Created by SRI VISHNU JSB on 8/21/2023.
//
/*
Consider the numeric linear array NUMBER[],using the linear search approach ,how many comparisons are used to locate element X in array

Input Format

you have to take two input lines: first line takes the array element
second line takes the value of key

Sample Input 1
10 20 80 30 60 50 110 100 130 170
110

Sample Output 1
7

Sample Input 2
10 20 80 30 60 50 110 100 130 170
175

Sample Output 1
"ELEMENT NOT FOUND"

Constraints

Array size should be between 10-50 elements

Output Format

The program prints the number of comparisons made to find the element else print "ELEMENT NOT FOUND",if element is not present

Sample Input 0

10 20 80 30 60 50 110 100 130 170
110
Sample Output 0

7
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int NUMBER[50];  // Assuming the maximum array size is 50
    int size, key;     // size is the number of elements in the array, key is the target value
    int comparisons = 0;  // To keep track of the number of comparisons

    // Input the array elements
    size = 0; // Initialize the number of elements to 0
    
    // Enter the array elements (between 10 and 50), one by one. Press Enter to stop.
    while (size < 50) {
        if (scanf("%d", &NUMBER[size]) != 1) {
            break; // Stop input on non-integer input or error
        }
        size++; // Increment the number of elements
        char c = getchar(); // Read the next character
        
        if (c == '\n') {
            break; // Stop input on Enter
        }
    }

    if (size < 10) {
        //Array size should be at least 10.
        return 1;  // Exit the program with an error code
    }

    // Input the value to search for
    scanf("%d", &key);

    // Linear search
    int found = 0; // Flag to check if the element is found
    for (int i = 0; i < size; i++) {
        comparisons++;  // Increment the comparison count for each iteration
        if (NUMBER[i] == key) {
            found = 1;
            break;
        }
    }

    // Output the result
    if (found) {
        printf("%d\n", comparisons);
    } else {
        printf("ELEMENT NOT FOUND\n");
    }

    return 0;
}
