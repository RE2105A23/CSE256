#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int array[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - pass - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
        printArray(array, size);  // Display the array after each pass
    }
}
*/

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i != size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void bubbleSort(int array[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - pass - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
        printArray(array, size);  // Display the array after each pass
    }
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
        printArray(array, size);  // Display the array after each pass
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int n;
    cin >> n;

    const int maxSize = 6;
    int array[maxSize];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    //bubbleSort(array, n);
    selectionSort(array, n);
 
    return 0;
}
