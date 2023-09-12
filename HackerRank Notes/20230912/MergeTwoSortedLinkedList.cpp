/*
Given pointers to the heads of two sorted linked lists, merge them into a single, sorted linked list. Either head pointer may be null meaning that the corresponding list is empty.

Example headA refers to 1->3->7 ->NULL headB refers to 1-2->NULL

The new list is 1->1->2->3->7->NULL

Function Description

Complete the mergeLists function in the editor below.

mergeLists has the following parameters: 1. SinglyLinkedListNode pointer headA: a reference to the head of a list 2. SinglyLinkedListNode pointer headB: a reference to the head of a list Returns 1. SinglyLinkedListNode pointer: a reference to the head of the merged list

If the size of linked list is not in between 1 and 1000 then display "Invalid List Size" message.

Input Format

The format for each test case is as follows: 1. The first line contains an integer n, the length of the first linked list(list1). 2. The second line contain n integer elements of the first linked list separated by space. 3. The third line contains an integer m, the length of the second linked list(list2). 4. The fourth line contain m integer elements of the second linked list separated by space.

Constraints

1<=n<=1000 1<=m<=1000 1<=list1[i]<=1000, where list1[i] is the ith element of list1 1<=list2[i]<=1000, where list2[i] is the ith element of list2

Output Format

Output contains list of single sorted linked list elements separated by -> sign If the size of linked list is not in between 1 and 1000 then display "Invalid List Size" message.

Sample Input 0

3
1 4 6
4
2 3 4 5
Sample Output 0

1->2->3->4->4->5->6->NULL
Explanation 0

The first linked list of 3 elements is: 1->4->6

The second linked list of 4 elements is: 2->3->4->5

Hence, the merged linked list is: 1->2->3->4->4->5->6->NULL

Sample Input 1

-1
0
2
1 2
Sample Output 1

Invalid List Size
Explanation 1

size of element is not valid
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {
    if (!headA) return headB;
    if (!headB) return headA;

    if (headA->data < headB->data) {
        headA->next = mergeLists(headA->next, headB);
        return headA;
    } else {
        headB->next = mergeLists(headA, headB->next);
        return headB;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
     int n, m, value;
    cin >> n;
    if (n < 1 || n > 1000) {
        cout << "Invalid List Size" << endl;
        return 0;
    }

    cin >> value;
    SinglyLinkedListNode* headA = new SinglyLinkedListNode(value);
    SinglyLinkedListNode* currA = headA;
    for (int i = 1; i < n; i++) {
        cin >> value;
        currA->next = new SinglyLinkedListNode(value);
        currA = currA->next;
    }

    cin >> m;
    if (m < 1 || m > 1000) {
        cout << "Invalid List Size" << endl;
        return 0;
    }

    cin >> value;
    SinglyLinkedListNode* headB = new SinglyLinkedListNode(value);
    SinglyLinkedListNode* currB = headB;
    for (int i = 1; i < m; i++) {
        cin >> value;
        currB->next = new SinglyLinkedListNode(value);
        currB = currB->next;
    }

    SinglyLinkedListNode* result = mergeLists(headA, headB);
    while (result) {
        cout << result->data;
        result = result->next;
        if (result) cout << "->";
        else cout << "->NULL";
    }

    return 0;
}
