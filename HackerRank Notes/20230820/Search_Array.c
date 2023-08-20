//
// Created by SRI VISHNU JSB on 2023/08/20.
//
/*
A data structure competition has been conducted and the marks of all students are stored in random order in an array. Suppose the scored marks by the students in non-increasing order is K1, K2,….KN. Write to program to find the third highest scored marks by the student. The size of array should be greater than 0 and less than equal to 20. If size is not in the mention range than program should display “Invalid array size” without asking for the other inputs.

Input Format

Your program should take the three types of inputs. First will represent size of array, second will represent elements of array and third will be the 3rd largest element.

Constraints

The length of array (L) should be 0 < L <=20

Output Format

Should display the 3rd largest element or “Not sufficient elements” if number of elements will be less than 3.

Sample Input 0

5
4
8
3
2
1
Sample Output 0

3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int find_third_highest(int arr[], int size) {
    // Sort the array in non-increasing order using bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    if (size < 3) {
        return -1; // Not sufficient elements
    } else {
        return arr[2];
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int size;
    scanf("%d", &size);
    
    // Check if size is within the valid range
    if (size <= 0 || size > 20) {
        printf("Invalid array size\n");
        return 0;
    }
    
    // Read the array elements
    int marks[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &marks[i]);
    }

    // Find the third highest scored marks
    int result = find_third_highest(marks, size);
    if (result == -1) {
        printf("Not sufficient elements\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

