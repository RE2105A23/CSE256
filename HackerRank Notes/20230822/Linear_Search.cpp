#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int NUMBER[50];  // Assuming the maximum array size is 50
    int size, key;     // size is the number of elements in the array, key is the target value
    int comparisons = 0;  // To keep track of the number of comparisons

    // Input the array elements
    size = 0; // Initialize the number of elements to 0
    
    // Enter the array elements (between 10 and 50), one by one. Press Enter to stop.
    while (size < 50) {
        if (!(cin >> NUMBER[size])) {
            break; // Stop input on non-integer input or error
        }
        size++; // Increment the number of elements
        char c;
        cin.get(c); // Read the next character
        
        if (c == '\n') {
            break; // Stop input on Enter
        }
    }

    /*
    // Enter the array elements (between 10 and 50), separated by spaces. Press Enter to stop.
    string line;
    getline(cin, line);
    istringstream iss(line);
    
    int num;
    while (size < 50 && iss >> num) {
        NUMBER[size] = num;
        size++; // Increment the number of elements
    }
    */

    if (size < 10) {
        // Array size should be at least 10.
        return 1;  // Exit the program with an error code
    }

    // Input the value to search for
    cin >> key;

    // Linear search
    int found = 0; // Flag to check if the element is found
    for (int i = 0; i < size; i++) {
        comparisons++;  // Increment the comparison count for each iteration
        if (NUMBER[i] == key) {
            found = 1;
            break;
        }
    }

    // Output the result
    if (found) {
        cout << comparisons << endl;
    } else {
        cout << "ELEMENT NOT FOUND" << endl;
    }


    return 0;
}
