/******************************************************************************
Reverse a Linked List in groups of given size
Given a linked list, write a function to reverse every k nodes (where k is an input to the function).
Example:
Inputs: 1->2->3->4->5->6->7->8 and k = 3 
Output: 3->2->1->6->5->4->8->7

Inputs: 1->2->3->4->5->6->7->8 and k = 5
Output: 5->4->3->2->1->8->7->6

INPUT
First line contains the number of datas- N1
Second line contains N1 integers (linked list).
Third line contains Key K.
OUTPUT
Display Given Linked list.
Display Customized Linked list.
Test Case 1

Input (stdin)
6

1 2 3 4 5 6

3

Expected Output

Given linked list

->1->2->3->4->5->6

Reversed Linked list

->3->2->1->6->5->4
Test Case 2

Input (stdin)
7

1 3 7 8 9 6 5

5

Expected Output

Given linked list

->1->3->7->8->9->6->5

Reversed Linked list

->9->8->7->3->1->5->6

*******************************************************************************/
#include <iostream>
using namespace std;
struct node{
  int val;
  struct node* next;
};
void push(struct node** head,int d){
  struct node *newnode=(struct node*)malloc(sizeof(struct node)),*p;
  newnode->val=d;
  if(*head==NULL){
    newnode->next=*head;
    *head=newnode;
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
struct node* reverse(struct node* head,int k){
  struct node* cur=head;
  struct node* nex=NULL;
  struct node* pre=NULL;
  int co=0;
  while(cur!=NULL && co<k){
    nex=cur->next;
    cur->next=pre;
    
    pre=cur;
    cur=nex;
    
    co++;
  }
  if(nex!=NULL){
    head->next=reverse(nex,k);
  }
  return pre;
}
void print(struct node* head){
  struct node* p;
  p=head;
  while(p!=NULL){
    cout<<"->"<<p->val;
    p=p->next;
  }
}
int main()
{
  struct node* head=NULL;
  int n,d,i,k;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>d;
    push(&head,d);
  }
  cin>>k;
  
  cout<<"Given linked list"<<endl;
  print(head);
  
  head=reverse(head,k);
  cout<<endl<<"Reversed Linked list"<<endl;
  print(head);

  return 0;
}