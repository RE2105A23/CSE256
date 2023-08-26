//
// Created by SRI VISHNU JSB on 8/21/2023.
//
/*


You need to find index (0-based) of a given key in a sorted array. Use only Binary Search.

Input Format

The first line contains N.
Next line contains N integers of the array.
The next line contains the key to be searched.
If element is not found print -1.

Constraints

N<=1000000

Output Format

Single Integer index or -1.

Sample Input 0

5
1 2 3 4 5
4
Sample Output 0

3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int binarySearch(int array[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    scanf("%d", &N);

    //Check the constraints to continue or not
    if (N > 1000000) {
        //printf("N should be <= 1000000.\n");
        return 1;  // Exit the program with an error code
    }

    int array[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int key;
    scanf("%d", &key);

    int index = binarySearch(array, N, key);

    printf("%d\n", index);

    return 0;
}