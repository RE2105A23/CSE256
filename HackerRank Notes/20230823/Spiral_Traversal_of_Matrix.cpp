#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int M, N;
    std::cin >> M >> N;

    int matrix[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++) {
            std::cout << matrix[top][i] << " ";
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            std::cout << matrix[i][right] << " ";
        }
        right--;

        // Print bottom row if it exists
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                std::cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Print left column if it exists
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                std::cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    return 0;
}
