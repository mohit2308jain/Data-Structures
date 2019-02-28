/******************************************************************************
Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.


INPUT
First line contains the number of datas- N
Second line contains N integers (linked list )
Third line contains rotation key K
OUTPUT
Display rotated linked list.
Test Case 1

Input (stdin)
5

6 7 9 8 1

1

Expected Output

->7->9->8->1->6
Test Case 2

Input (stdin)
5

1 2 6 4 5

4

Expected Output

->5->1->2->6->4

*******************************************************************************/

#include <iostream>
using namespace std;
struct node{
  int val;
  struct node* next;
};
void insert(struct node **head, int d){
  struct node* newnode = (struct node*)malloc(sizeof(struct node));
  struct node *p;
  newnode->val=d;
  if(*head==NULL){
    newnode->next=(*head);
    (*head)=newnode;
  }
  else{
    p=*head;
    while(p->next!=NULL){
      p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
  }
}

/*
for right rotation of list*/
/**
void modify(struct node** head){
  struct node *p,*q;
  p=*head;
  q=*head;
  while(p->next!=NULL){
    q=p;
    p=p->next;
  }
  p->next=*head;
  *head=p;
  q->next=NULL;
  
}
**/

/** for left rotation of list*/
void modify(struct node** head){
  struct node *t,*p;
  t=*head;
  p=*head;
  while(p->next!=NULL){
    p=p->next;
  }
  *head=(*head)->next;
  t->next=NULL;
  p->next=t;
  
}

void print(struct node *head){
  struct node *p=head;
  while(p!=NULL){
    cout<<"->"<<p->val;
    p=p->next;
  }
}
int main()
{
  struct node* head= NULL;
  int n,d,i,j;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>d;
    insert(&head,d);
  }
  cin>>j;
  for(i=0;i<j;i++){
    modify(&head);
  }
  print(head);
  
  
  return 0;
}