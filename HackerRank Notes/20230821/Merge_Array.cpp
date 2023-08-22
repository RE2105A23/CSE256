#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void getArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];

        if (i > 0 && array[i] < array[i - 1]) {
            cout << "Incorrect Array Elements" << endl;
            exit(0);
        }
    }
}

/*
void getArray(vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        cin >> array[i];

        if (i > 0 && array[i] < array[i - 1]) {
            cout << "Incorrect Array Elements" << endl;
            exit(0);
        }
    }
}
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n1, n2;

    cin >> n1;

    if (n1 <= 0 || n1 > 20) {
        cout << "Invalid Array" << endl;
        return 0;
    }

    int array1[n1];
    // vector<int> array1(n1);
    getArray(array1, n1);

    cin >> n2;

    if (n2 <= 0 || n2 > 20) {
        cout << "Invalid Array" << endl;
        return 0;
    }

    int array2[n2];
    //vector<int> array2(n2);
    getArray(array2, n2);

    if (n1 == n2) {
        cout << "Invalid Array" << endl;
        return 0;
    }

    int mergedArray[n1 + n2];
    //vector<int> mergedArray(n1 + n2);
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
        cout << mergedArray[index] << endl;
    }

    return 0;
}
