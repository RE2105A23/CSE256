/*
In F1 race competition, a total of 5 cars participated and they have to complete a total of 3 laps. During the end of each lap the first car is pushed to the last and finally find the winner who comes first at the end of the 3rd lap

Input Format

5
Mercedes RedBull Ferrari McLaren Alpine

Constraints

F1 car names should be in the queue of Strings
During the end of each and every lap the first car needs to Popped outside and Pushed at the end
Output Format

RedBull Ferrari McLaren Alpine Mercedes
Ferrari McLaren Alpine Mercedes RedBull
McLaren Alpine Mercedes RedBull Ferrari
McLaren

Sample Input 0

5 
Alpha Aston Williams Alfa Haas
Sample Output 0

Aston Williams Alfa Haas Alpha 
Williams Alfa Haas Alpha Aston 
Alfa Haas Alpha Aston Williams 
Alfa
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<string> raceQueue;

    // Read the car names and push them into the queue
    for(int i = 0; i < n; i++) {
        string carName;
        cin >> carName;
        raceQueue.push(carName);
    }

    // Simulate 3 laps
    for(int lap = 0; lap < 3; lap++) {
        // Move the first car to the last
        string frontCar = raceQueue.front();
        raceQueue.pop();
        raceQueue.push(frontCar);

        // Print the current order of cars
        queue<string> tempQueue = raceQueue;
        for(int i = 0; i < n; i++) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }

    // The winner will be the car in front now
    cout << raceQueue.front() << endl;

    return 0;
}
