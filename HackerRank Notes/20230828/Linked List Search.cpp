//
// Created by SRI VISHNU JSB on 2023/08/28
//
/*

To store the grades of Contest-1 of Data Structures, Dr. Max has created a linked list where each node is storing the roll number of the student and grade. Students are supposed to get any of the 3 grades: A, B or C

Dr. Max has to complete the code of the following functions:

void add_node() where the details of a new student is to be added in the beginning of the linked list.

void search(int roll) where he wants to find the grade of the student with the given roll number.

As a student, you have to complete the codes in the above functions and help Dr. Max to get the task completed such that if any student asks for his/her grade then just by asking the roll number of the student, he should be able to tell the grade.

If the roll number of the student is not present in the list then print You have not appeared for the Contest-1.

Input Format

First line should read the number of students who appeared for the contest N
Next N lines should read the roll number and grade of the students
Last line should read the roll number of the student whose grade is to be checked

Example:
3
19 B
31 A
7 C
31

Constraints

N >= 0 where N is the number of students

Output Format

Output must be the grade of the student if the roll number is found in the list otherwise print You have not appeared for the Contest-1

Example:

You have secured A grade

Sample Input 0

4
19 B
32 B
11 A
41 C
32
Sample Output 0

You have secured B grade
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* start;

public:
    LinkedList() : start(NULL) {}

    bool insert(int num) {
        Node* curr = start;
        while (curr) {
            if (curr->data == num) {
                return false;
            }
            curr = curr->next;
        }

        Node* new_node = new Node;
        new_node->data = num;
        new_node->next = NULL;

        if (!start) {
            start = new_node;
            return true;
        }

        // Handle the insertion at the beginning
        if ((num % 2 == 1 && num < start->data) || (start->data % 2 == 0 && num > start->data)) {
            new_node->next = start;
            start = new_node;
            return true;
        }

        curr = start;
        Node* prev = NULL;
        while (curr) {
            if (num % 2 == 1) {  // For odd numbers
                if (curr->data % 2 == 0 || (curr->data % 2 == 1 && curr->data > num)) {
                    new_node->next = curr;
                    if (prev) {
                        prev->next = new_node;
                    }
                    return true;
                }
            } else {  // For even numbers
                if (curr->data % 2 == 0 && curr->data < num) {
                    new_node->next = curr;
                    if (prev) {
                        prev->next = new_node;
                    }
                    return true;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new_node;
        return true;
    }

    void display() {
        Node* curr = start;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, num;
    cin >> N;
    LinkedList ll;
    for (int i = 0; i < N; i++) {
        cin >> num;
        ll.insert(num);
    }
    cin >> num;
    if (!ll.insert(num)) {
        cout << "Duplicates are not allowed" << endl;
        return 0;
    }
    ll.display();
    return 0;
}

