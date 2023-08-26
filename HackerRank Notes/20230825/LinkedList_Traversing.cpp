//
// Created by SRI VISHNU JSB on 8/25/2023.
//
/*
Write a program to find the count of prime numbers in the linked list.

Input Format

Line 1: it contains number of nodes in the linked list
Line 2: It contains space separated values in the linked list.

Constraints

n must be more than zero

Output Format

Output contains the count of prime numbers in the linked list.

Sample Input 0

5
1 2 3 4 5
Sample Output 0

3
Explanation 0

In the above sample input data 2,3, and 5 are prime numbers so the count of prime number in the linked list is 3

Sample Input 1

-1
4
Sample Output 1

Invalid Number
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Node of the singly linked list 
struct Node { 
  int data; 
  Node* next; 
}; 
void push(Node** head_ref, int new_data) 
{ 
  Node* new_node = new Node; 
  new_node->data = new_data; 
  new_node->next = (*head_ref); 
  (*head_ref) = new_node; 
} 
// Function to check if a number is prime 
int isPrime(int n) 
{ 
  // Corner cases 
  if ((n == 2) || (n == 3)) 
    return n;  
 
  if (n == 1 || n % 2 == 0 || n % 3 == 0) 
    return -1; 
  for (int i = 5; i * i <= n; i = i + 6) 
    if (n % i == 0 || n % (i + 2) == 0) 
      return -1; 
  return n; 
} 
 
void getPrime(Node** head_ref) 
{ 
  Node* ptr = *head_ref; 
  int count = 0;
  while(ptr != NULL) { 
    int p = isPrime(ptr->data);
      if (p != -1) { 
        count++;
      }
      ptr = ptr->next; 
  }

  cout << count << " ";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    // Empty Linked List 
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cin >> n;
    if(n<=0) {
        cout<<"Invalid Number"<<endl;
        return 0;
    }

    // Push elements into linked list 
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Call the function to print require answer 
    //cout << "Prime nodes are: ";
    getPrime(&head);

    
    return 0;
}
