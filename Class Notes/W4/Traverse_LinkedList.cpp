#include <iostream>
using namespace std;

struct node {

    int data;
    struct node *next;

};

void display(struct node* head) {

    struct node* ptrNode;
    for(ptrNode=head; ptrNode->next!=NULL;ptrNode=ptrNode->next)
    {
        cout<<ptrNode->data<<"->";
    };
    cout<<ptrNode->data<<endl;
}

struct node* pushElement(struct node* head, int new_data) {

    //Step 1 -> Allocate the Memory
    //struct node* new_node=(struct node*)malloc(sizeof(struct node)) //for c program
    struct node* new_node=new node;

    if(new_node==NULL)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        //Step 2 -> Assign the new data to data field
        new_node->data=new_data;
        //Step 3 -> Assign the head to new node's next index
        new_node->next=head;
        //Step 4 -> Assign the index of new_node to head index
        head=new_node;
    }
    return head;
}

int main() {

    struct node* head=NULL;

    head=pushElement(head,10);
    head=pushElement(head,20);
    head=pushElement(head,30);
    head=pushElement(head,40);
    cout<<"Linked List"<<endl;
    display(head);

    return 0;
}