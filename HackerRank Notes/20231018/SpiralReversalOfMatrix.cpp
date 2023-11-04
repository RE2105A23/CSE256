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

#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>> &matrix, int M, int N) {
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        // Print the top row
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        ++top;

        // Print the rightmost column
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        --right;

        // Print the bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            --bottom;
        }

        // Print the leftmost column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            ++left;
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    // Read the matrix elements
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Print the matrix in spiral form
    printSpiral(matrix, M, N);
    cout << endl;

    return 0;
}
