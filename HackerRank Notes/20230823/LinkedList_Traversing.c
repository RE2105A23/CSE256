//
// Created by SRI VISHNU JSB on 8/21/2023.
//
/*
Write a program to find the sum of odd nodes and even nodes from a linked list.

Input Format

Line 1: It contains number of nodes in the linked list
Line 2: It contains space separated integer values for linked list

Constraints

0<=n<=7
where n is the total number of nodes

Output Format

If the number of input values are in between 0 and 7 then It will print the space separated output as sum of all the odd values, then print the sum of all even values of the linked list.
Otherwise it will print "Invalid Range" message.

Sample Input 0

5
4 3 9 2 5
Sample Output 0

17 6 
Explanation 0

Sum of odd valued nodes= 3+9+5=17
Sum of even valued nodes=4+2=6
So, Output is 17 6

Sample Input 1

12
1 2 2 3 3 3 3 3 3 3 3 4 
Sample Output 1

Invalid Range
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Inserting a new node at the end of the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

     int n;
    scanf("%d", &n);

    if (n < 0 || n > 7) {
        printf("Invalid Range\n");
        return 0;
    }

    struct Node* head = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    int oddSum = 0, evenSum = 0;

    struct Node* current = head;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            evenSum += current->data;
        } else {
            oddSum += current->data;
        }
        current = current->next;
    }

    printf("%d %d\n", oddSum, evenSum);

    return 0;
}