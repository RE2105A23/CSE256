/*
Given an 1D integer array A of size N you have to find and return the B largest elements of the array A. NOTE: Return the largest B elements in any order you like.

Input Format

First argument is an 1D integer array A seperated by space Second argument is an integer B.

Constraints

Problem Constraints 1 <= N <= 10^5

1 <= B <= N

1 <= A[i] <= 10^3

Output Format

Return a 1D array of size B denoting the B largest elements separated by space.

Sample Input 0

11 3 4
2
Sample Output 0

11 4
Explanation 0

2-Largest elements are 11 and 4 so answer is 11 4
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findBLargestElements(vector<int>& A, int B) {
    sort(A.begin(), A.end(), greater<int>());
    vector<int> result(A.begin(), A.begin() + B);
    return result;
}

int main() {
    vector<int> A = {11, 3, 4};
    int B = 2;

    vector<int> result = findBLargestElements(A, B);
    
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}
*/

import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the input array
        String[] inputArray = sc.nextLine().split(" ");
        int N = inputArray.length;
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(inputArray[i]);
        }

        // Read the value of B
        int B = sc.nextInt();

        // Priority queue to keep track of B largest elements
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int num : arr) {
            pq.offer(num);
            if (pq.size() > B) {
                pq.poll();
            }
        }

        // Prepare the output array
        int[] output = new int[B];
        for (int i = B - 1; i >= 0; i--) {
            output[i] = pq.poll();
        }

        // Print the output array
        for (int i = 0; i < B; i++) {
            System.out.print(output[i]);
            if (i < B - 1) {
                System.out.print(" ");
            }
        }
    }
}
