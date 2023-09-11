/*
Take an array of integers nums of size N from user which is sorted in ascending order, and an integer target, write a program to search target in nums. If target exists, then return its index. Otherwise, return -1. You must write a program with O(log n) runtime complexity.

Input Format

The first line contains N.
Next line contains N integers of the array.
The next line contains the key to be searched.

Constraints

• 1 <= nums.length <= 104 • -104 < nums[i], target < 104 • All the integers in nums are unique. • nums is sorted in ascending order

Output Format

Single Interger index or -1.

Sample Input 0

5
1 2 3 4 5
2
Sample Output 0

1
*/

//
// Created by SRI VISHNU JSB on 2023/09/07
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2; // Find the middle index
        
        if (arr[mid] == target) {
            return mid; // Return the index if the target is found
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Move to the right half
        }
        else {
            high = mid - 1; // Move to the left half
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, target;
    
    // Read the size of the array
    cin >> n;
    
    // Initialize the array
    int arr[n];
    
    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Read the target value
    cin >> target;
    
    // Call the binarySearch function
    int result = binarySearch(arr, n, target);
    
    // Print the result
    cout << result << endl;

    return 0;
}
