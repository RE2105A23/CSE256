//
// Created by SRI VISHNU JSB on 8/23/2023.
//
/*
Given a M X N matrix, traverse the matrix in spiral form in clock-wise.

Input:
M = 4, N = 3
matrix[][] = {{1, 2, 3},
{4, 5, 6},
{7, 8, 9},
{10, 11, 12}}
Output:
1 2 3 6 9 12 11 10 7 4 5 8

Input Format

first line reads the M and N
Next M lines reads the elemnts of the matrix

Example:
2 3
1 2 3
4 5 6

Constraints

1 <= M < 100
1 <= N <100

Output Format

prints the spiral traversal of Matrix in 1 line

Example:

1 2 3 6 5 4

Sample Input 0

3 4
1 2 3 4
5 6 7 8
9 10 11 12
Sample Output 0

1 2 3 4 8 12 11 10 9 5 6 7
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int M, N;
    scanf("%d %d", &M, &N);

    int matrix[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Print bottom row if it exists
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Print left column if it exists
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}