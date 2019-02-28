/******************************************************************************
Given a singly linked list, Write a function to remove all the nodes which have a greater value on right side.

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
void reverse(struct node** head){
  struct node *cur;
  cur=*head;
  struct node *p=NULL,*n;
  while(cur!=NULL){
    n=cur->next;
    cur->next=p;
    
    p=cur;
    cur=n;
  }
  *head=p;
}
void modify(struct node** head){
  reverse(head);
  
  struct node *p,*maxnode,*t;
  p=*head;
  maxnode=*head;
  while(p!=NULL && p->next!=NULL){
    if(p->next->val < maxnode->val){
      t=p->next;
      p->next=t->next;
      free(t);
    }
    else{
      p=p->next;
      maxnode=p;
    }
  }
  reverse(head);
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
  int n,d,i;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>d;
    insert(&head,d);
  }
  cout<<"Given linked list=";
  print(head);
  cout<<endl;
  modify(&head);
  cout<<"Modified Linked List=";
  print(head);
  
  
    return 0;
}