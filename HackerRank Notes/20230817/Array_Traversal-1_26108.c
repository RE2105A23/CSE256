//
// Created by SRI VISHNU JSB on 8/17/2023.
//
/*
Assume a student is having 8 lectures on Monday of different courses listed as JAVA, Python, DBMS and DataStructures. Find out how many times JAVA lecture is repeated on Monday.

Constraints: 1. Size of the array should be 8

Output: JAVA lecture is repeating 3 times

Sample Case 1: Input: Total 8 lectures on Monday JAVA JAVA DataStructures DBMS JAVA JAVA Python DataStructures Output: JAVA lecture is repeating 4 times

Sample Case 2: Input: Total 8 lectures on Monday JAVA JAVA DataStructures DBMS JAVA JAVA Python JAVA Output: JAVA lecture is repeating 5 times

Sample Case 3: Input: Total 8 lectures on Monday Python Python DataStructures DBMS Python Python DBMS Python Output: No JAVA Lecture

Input Format

Example:

Input: Total 8 lectures on Monday JAVA Python DataStructures DBMS JAVA JAVA Python DataStructures

Constraints

Constraints: 1. Size of the array should be 8 2. All subjects should be listed atleast once

Output Format

Output:

JAVA lecture is repeating 3 times

Sample Case 1: Input: Total 8 lectures on Monday JAVA JAVA DataStructures DBMS JAVA JAVA Python DataStructures

Output: JAVA lecture is repeating 4 times

Sample Input 0

Total 8 lectures on Monday 
JAVA JAVA DataStructures DBMS JAVA JAVA Python DataStructures 
Sample Output 0

JAVA lecture is repeating 4 times 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char lectures[8][15];  // Assuming each lecture name is at most 15 characters long
    int count = 0;

    char search[] = "JAVA";

    // Skip the initial input line
    char line[50];  // Assuming the input line won't exceed 50 characters
    fgets(line, sizeof(line), stdin);

    // Read the list of lectures on Monday
    for (int i = 0; i < 8; i++) {
        scanf("%s", lectures[i]);
    }

    // Count how many times "JAVA" lecture is repeated
    for (int i = 0; i < 8; i++) {
        if (strcmp(lectures[i], search) == 0) {
            count++;
        }
    }

    // Print the result
    if (count > 0) {
        printf("JAVA lecture is repeating %d times\n", count);
    } else {
        printf("No JAVA Lecture\n");
    }

    return 0;

}