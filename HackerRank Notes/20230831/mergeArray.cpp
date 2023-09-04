/*
You are given two integers representing the size of two different sized arrays. Take the elements of the arrays from the user in the non-increasing order. If the elements are not in sorted order in any array, display the message “Incorrect Array Elements”. Merge the elements of the given arrays in sorted order and display them. The size of the array should be greater than 0 and less than equal to 20. If array will not be in the given range then display the message “Invalid Array”.

Input Format

Your program should take the 4 types of inputs. The first input will represent the size of the first array (n1). Second inputs will represent the elements of the first array. Third input will represent the size of second array (n2). And fourth input will represent the elements of the second array.

Constraints

Size of the arrays should be 0 < n1 <= 20 and 0 < n2 <= 20. If the size will not be in the range, then it should not take the further inputs and display the message “Invalid Array”.
If the elements of the array will not be in the required order, it should not take the further inputs and display the message “Incorrect Array Elements”.
If the size of two arrays will be same, then do not take further inputs and display the message “Invalid Array”.
Output Format

Should display the elements of the merged array in non-increasing order.

Sample Input 0

4
40
30
20
10
5
15
11
6
4
1
Sample Output 0

40
30
20
15
11
10
6
4
1
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool isSorted(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n1, n2;
    cin >> n1;

    if(n1 <= 0 || n1 > 20) {
        cout << "Invalid Array" << endl;
        return 0;
    }

    int arr1[20];
    for(int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    if(!isSorted(arr1, n1)) {
        cout << "Incorrect Array Elements" << endl;
        return 0;
    }

    cin >> n2;

    if(n2 <= 0 || n2 > 20 || n1 == n2) {
        cout << "Invalid Array" << endl;
        return 0;
    }

    int arr2[20];
    for(int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    if(!isSorted(arr2, n2)) {
        cout << "Incorrect Array Elements" << endl;
        return 0;
    }

    int merged[40];
    for(int i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }
    for(int i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i];
    }

    sort(merged, merged + n1 + n2, greater<int>());

    for(int i = 0; i < n1 + n2; i++) {
        cout << merged[i] << endl;
    }

    return 0;
}
