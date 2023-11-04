/*
Write a program to remove element from the specific or provided location and after removing , print all the remaining other elements.

Input Format

In first line, it will take the total number of elements in array In second line, pollute the values in array In third Line, it will ask for the index number , from where you want to delete the element

Constraints

Enter the index value by considering the size of array as 0

Output Format

It will display the remaining elements after deletion

Sample Input 0

5
1 2 3 4 5
0
Sample Output 0

2345
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, index_to_remove;

    // Read the number of elements
    cin >> n;

    // Initialize the array and read its elements
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Read the index to remove
    cin >> index_to_remove;

    // Check if the index is valid
    if(index_to_remove < 0 || index_to_remove >= n) {
        cout << "Invalid index" << endl;
        return 1;
    }

    // Remove the element by shifting all elements to the right of index_to_remove to the left
    for(int i = index_to_remove; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    // Reduce the size of the array
    n--;

    // Print the remaining elements
    for(int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
