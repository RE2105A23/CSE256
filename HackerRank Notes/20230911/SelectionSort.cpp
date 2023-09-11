/*
Bob considered an array of Strings and he sorted the Strings in alphabetical order

Input Format

5
paper true soap floppy flower

Constraints

Array size should be 5
Implement selection sort for sorting the strings in alphabetical order and repeat for n-1 passes. For each pass the output should be displayed
Output Format

floppy true soap paper flower
floppy flower soap paper true
floppy flower paper soap true
floppy flower paper soap true

Sample Input 0

5
paper true soap floppy flower
Sample Output 0

floppy true soap paper flower
floppy flower soap paper true
floppy flower paper soap true
floppy flower paper soap true
*/

#include <iostream>
#include <string>
using namespace std;

void swap(string &str1, string &str2) {
    string temp = str1;
    str1 = str2;
    str2 = temp;
}

void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        
        // Display the array after each pass
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    string arr[5];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    return 0;
}
