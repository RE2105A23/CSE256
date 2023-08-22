//
// Created by SRI VISHNU JSB on 8/21/2023.
//
/*
You are given two integers representing the size of two different sized arrays. Take the elements of the arrays from the user in the non-decreasing order. If the elements are not in sorted order in any array, display the message “Incorrect Array Elements”. Merge the elements of the given arrays in sorted order and display them. The size of the array should be greater than 0 and less than equal to 20. If array will not be in the given range then display the message “Invalid Array”.

Input Format

Your program should take the 4 types of inputs. The first input will represent the size of the first array (n1). Second input will represent the elements of the first array. Third input will represent the size of second array (n2). And fourth input will represent the elements of the second array.

Constraints

Size of the arrays should be 0 < n1 <= 20 and 0 < n2 <= 20. If the size will not be in the range, then it should not take the further inputs and display the message “Invalid Array”.
If the elements of the array will not be in the required order, it should not take the further inputs and display the message “Incorrect Array Elements”.
If the size of two arrays will be same, then do not take further inputs and display the message “Invalid Array”.
Output Format

Should display the elements of the merged array in non-decreasing order.

Sample Input 0

4
10
20
30
40
5
1
5
7
11
15
Sample Output 0

1
5
7
10
11
15
20
30
40
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void getArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);

        if (i > 0 && array[i] < array[i - 1]) {
            printf("Incorrect Array Elements\n");
            exit(0);
        }
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int n1, n2;

    scanf("%d", &n1);

    if (n1 <= 0 || n1 > 20) {
        printf("Invalid Array\n");
        return 0;
    }

    int array1[n1];
    getArray(array1, n1);

    scanf("%d", &n2);

    if (n2 <= 0 || n2 > 20) {
        printf("Invalid Array\n");
        return 0;
    }

    int array2[n2];
    getArray(array2, n2);

    if (n1 == n2) {
        printf("Invalid Array\n");
        return 0;
    }

    int mergedArray[n1 + n2];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (array1[i] <= array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    while (i < n1) {
        mergedArray[k++] = array1[i++];
    }

    while (j < n2) {
        mergedArray[k++] = array2[j++];
    }

    for (int index = 0; index < n1 + n2; index++) {
        printf("%d\n", mergedArray[index]);
    }

    return 0;
}
