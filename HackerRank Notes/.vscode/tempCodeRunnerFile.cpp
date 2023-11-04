#include<iostream>
#include<vector>
using namespace std;

const int TOTAL_DISKS = 5;

void printTower(const vector<int>& tower, int height) {
    for (int i = 0; i < height; ++i) {
        if (i < tower.size()) {
            for (int j = 0; j < TOTAL_DISKS - tower[i]; ++j)
                cout << " ";
            for (int j = 0; j < 2 * tower[i] - 1; ++j)
                cout << "#";
            for (int j = 0; j < TOTAL_DISKS - tower[i]; ++j)
                cout << " ";
        } else {
            for (int j = 0; j < 2 * TOTAL_DISKS - 1; ++j)
                cout << " ";
        }
        cout << " ";
    }
    cout << endl;
}

void displayTowers(const vector<int>& tower1, const vector<int>& tower2, const vector<int>& tower3) {
    int height = TOTAL_DISKS;
    for (int i = 0; i < height; ++i) {
        printTower(tower1, height);
        printTower(tower2, height);
        printTower(tower3, height);
        cout << endl;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2 * TOTAL_DISKS - 1; ++j)
            cout << "=";
        cout << " ";
    }
    cout << endl;
    cout << "L   C   R" << endl;
    cout << endl;
}

void TOH(int n, char origin, char temp, char destination, vector<int>& tower1, vector<int>& tower2, vector<int>& tower3) {
    if (n == 0) {
        return;
    } else {
        TOH(n-1, origin, destination, temp, tower1, tower2, tower3);

        if (origin == 'L') {
            tower2.push_back(tower1.back());
            tower1.pop_back();
        } else if (origin == 'C') {
            tower3.push_back(tower2.back());
            tower2.pop_back();
        } else if (origin == 'R') {
            tower1.push_back(tower3.back());
            tower3.pop_back();
        }
        
        displayTowers(tower1, tower2, tower3);

        TOH(n-1, temp, origin, destination, tower1, tower2, tower3);
    }
}

int main() {
    vector<int> towerL = {1, 2, 3, 4, 5};  // left tower initially has all the disks
    vector<int> towerC;  // center tower starts empty
    vector<int> towerR;  // right tower starts empty

    displayTowers(towerL, towerC, towerR);
    TOH(TOTAL_DISKS, 'L', 'C', 'R', towerL, towerC, towerR);

    return 0;
}
