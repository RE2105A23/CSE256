//
// Created by SRI VISHNU JSB on 8/19/2023.
//
/*
Suraj is playing a card game. Every card has a number P on it. At end of the game, He has Z cards in his hand. Write a programming solution to help suraj, to arrange the card in increasing order with respect of P. Note: Use Insertion Sort

Input Format

1st line contain an integer, i.e nos. of card
2nd line contain space separated values from Z cards

Constraints

P>0 & P<100
Z>0 & Z<25
Output Format

space separated sorted values from Z cards

Sample Input 0

5
10 12 8 4 2
Sample Output 0

2 4 8 10 12 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n;
    scanf("%d", &n);
    
    int cards[25];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    insertionSort(cards, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n");

    return 0;
}
