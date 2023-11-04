/*
Akash got a new coin game. In the coin game, Akash will only win the game if the total count is 56. Each coin will have value inscribed. Write a programming solution, to help Akash in counting total value of coins at the end of the game. Coin Game is played N times.

Note: Player will have exactly K coins at the end of the game.
Input Format

1st line contain N(integers) 2nd line contain space separated values from K coins

Constraints

N>0 & N<=5
K=7
Output Format

One integer – 1 in case of win, 0 in case of loss

Sample Input 0

2
10 12 5 7 8 9 5
5 7 6 9 6 3 4
Sample Output 0

1
0
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // Number of games
    cin >> N;

    // Constraints specify K=7
    const int K = 7;
    const int target = 56; // Akash will win if the total count is 56

    for (int i = 0; i < N; ++i) {
        int sum = 0;
        vector<int> coins(K);

        // Read K coins for this game
        for (int j = 0; j < K; ++j) {
            cin >> coins[j];
            sum += coins[j];
        }

        // Check if Akash wins or loses this game
        if (sum == target) {
            cout << "1" << endl; // Win
        } else {
            cout << "0" << endl; // Loss
        }
    }

    return 0;
}
