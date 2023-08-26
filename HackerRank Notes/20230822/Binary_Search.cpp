#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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
    cin >> N;

    // Check the constraints to continue or not
    if (N > 1000000) {
        return 1;  // Exit the program with an error code
    }

    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    int key;
    cin >> key;

    int index = binarySearch(array, N, key);

    cout << index << endl;

    return 0;
}