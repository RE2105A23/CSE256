//
// Created by SRI VISHNU JSB on 2023/08/20.
//
/*
Rahul, Ramya, Vijay, Priya, Bindu and Adam went to supermarket and bought different products of different prices. Now they need to sort their products based on price in form of ascending order by using selection sort technique

Input Format

first line contains any positive number. second line contains the elements of an array. 6
30 60 20 50 40 10

Constraints

Size of Array can be any positive number
Sort the products price in ascending order using selection sort and display the result of each pass.
Output Format

10 60 20 50 40 30
10 20 60 50 40 30
10 20 30 50 40 60
10 20 30 40 50 60
10 20 30 40 50 60

Sample Input 0

6
3 6 2 5 4 1
Sample Output 0

1 6 2 5 4 3 
1 2 6 5 4 3
1 2 3 5 4 6 
1 2 3 4 5 6
1 2 3 4 5 6 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(&array[i], &array[minIndex]);
        
        // Display the result of each pass
        for (int k = 0; k < size; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
    }
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int size;
    scanf("%d", &size);
    
    int array[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    selectionSort(array, size);
    
    return 0;
}
