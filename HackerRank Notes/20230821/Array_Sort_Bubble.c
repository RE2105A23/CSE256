//
// Created by SRI VISHNU JSB on 8/21/2023.
//
/*
Rahul, Ramya, Vijay, Priya, Bindu and Adam went to supermarket and bought different products of different prices. Now they need to sort their products based on price in form of ascending order by using bubble sort technique

Input Format

6
30 60 20 50 40 10

Constraints

Size of Array should be 6
Sort the products price in ascending order using selection sort and repeat for n-1 passes. For each pass the output should be displayed
Output Format

Output contains the result after each iteration separated by a new line. if input array is 10 60 20 50 40 30 then out put will be as :
10 20 50 40 30 60
10 20 40 30 50 60
10 20 30 40 50 60
10 20 30 40 50 60
10 20 30 40 50 60

Sample Input 0

6
30 60 20 50 40 10
Sample Output 0

30 20 50 40 10 60
20 30 40 10 50 60
20 30 10 40 50 60
20 10 30 40 50 60
10 20 30 40 50 60
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int array[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - pass - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        printArray(array, size);  // Display the array after each pass
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int n;
    scanf("%d", &n);

    const int maxSize = 6;
    int array[maxSize];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, n);

    return 0;
}
