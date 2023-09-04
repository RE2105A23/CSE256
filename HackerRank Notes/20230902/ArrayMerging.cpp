/*
Consider there are N number of employees in Programming domain sitting in one room and have their unique emp_id and M number of employees of Automata domain sitting in an another room with their unique emp_id. As per new guidelines, sitting arrangements have been updated and now all members of Automata domain are shifted in Programming domain. Now as per new sitting arrangement firstly programming domain employees will occupy the cubicle and then automata domain employee will occupy the cubicle .

Input Format

First line consists of total number of employees in N array
Values inside N arrays
Second line consists of total number of employees in M array
Values inside M arrays

Constraints

emp_id must be of one digit

Output Format

Display Merged Array of size m+n.

Sample Input 0

5
3 4 1 5 6
7
7 8 9 1 2 3 4
Sample Output 0

3 4 1 5 6 7 8 9 1 2 3 4
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
int main() {
    int N, M;

    // Declare arrays with maximum size as per constraints
    int programming[50], automata[50];

    // Input for Programming domain employees
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> programming[i];
    }

    // Input for Automata domain employees
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> automata[i];
    }

    // Printing merged arrays
    for (int i = 0; i < N; i++) {
        cout << programming[i] << " ";
    }
    for (int i = 0; i < M; i++) {
        cout << automata[i] << " ";
    }
    
    return 0;
}
