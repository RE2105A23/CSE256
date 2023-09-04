/*
Consider there are N number of employees in Programming domain sitting in one room and have their unique emp_id and M number of employees of Automata domain sitting in an another room with their unique emp_id. As per new guidelines, sitting arrangements have been updated and now all members of Automata domain are shifted in Programming domain. Now as per new sitting arrangement firstly programming domain employees will occupy the cubicle and then automata domain employee will occupy the cubicle(index begins from 0) .Also find the cubicle of employees having even emp_id.If there is no employee with even emp_id then print -1.

Input Format

First line consists of total number of employees in N array
Values inside N arrays
Second line consists of total number of employees in M array
Values inside M arrays

Constraints

-

Output Format

Merged Array
Cubicle of employees after merging who have even emp_id’s

Sample Input 0

3
1 3 2
4
6 8 1 3
Sample Output 0

1 3 2 6 8 1 3
2 3 4
Sample Input 1

3
1 3 5
2
7 9
Sample Output 1

1 3 5 7 9
-1
*/

//
// Created by SRI VISHNU JSB on 2023/08/30
//



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    size_t N, M;
    cin >> N;
    vector<int> prog(N);
    for(size_t i = 0; i < N; i++) {
        cin >> prog[i];
    }

    cin >> M;
    vector<int> autoM(M);
    for(size_t i = 0; i < M; i++) {
        cin >> autoM[i];
    }

    // Merging the two lists
    vector<int> merged = prog;
    merged.insert(merged.end(), autoM.begin(), autoM.end());

    // Displaying the merged list
    for(size_t i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    // Finding the cubicles of employees with even emp_ids
    bool foundEven = false;
    for(size_t i = 0; i < merged.size(); i++) {
        if(merged[i] % 2 == 0) {
            foundEven = true;
            cout << i << " ";
        }
    }
    if(!foundEven) {
        cout << "-1" << endl;
    }
    return 0;
}