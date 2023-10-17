/*
Implement HeapSort algorithm to sort an integer array in an ascending, and try to make it faster as much as possible .

You are required to build the functionality of Heap Sort algorithm and use to sort the arrays.

Input Format

First line:the size of the array, i.e. n Second line:the array to be sorted(numbers seperated by spaces)

Constraints

0

Output Format

output between two brackets,and each two numbers seperated by comma .
Sample Input
6
1 9 3 5 4 7
Sample Output
[1,3,4,5,7,9]
If number of elements are not according to constraints then display a message "Not valid according to constraints"

Sample Input 0

6
1 9 3 5 4 7
Sample Output 0

[1,3,4,5,7,9]
Explanation 0

Array is converted into max heap then sort it using heapify method to sort it into ascending order
*/

#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Not valid according to constraints" << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr);

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}

/*
import java.util.Scanner;

public class Solution {

    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    public static void heapSort(int[] arr) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        if (n <= 0) {
            System.out.println("Not valid according to constraints");
            return;
        }

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        heapSort(arr);

        System.out.print("[");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]);
            if (i < n - 1) {
                System.out.print(",");
            }
        }
        System.out.println("]");
    }
}
*/

/*
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Not valid according to constraints" << endl;
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
*/