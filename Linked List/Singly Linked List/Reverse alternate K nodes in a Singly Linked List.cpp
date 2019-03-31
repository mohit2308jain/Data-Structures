/*******************************************************************************

Reverse alternate K nodes in a Singly Linked List

************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct node{
    int d;
    struct node* next;
};
struct node* rever(struct node* head,int k){
    struct node *c,*t,*p;
    t=NULL,p=NULL,c=head;
    int co=0;
    while(c && co<k){
        t=c->next;
        c->next=p;
        
        p=c;
        c=t;
        
        co++;
    }
    if(c!=NULL){
        head->next=c;
    }
    co=0;
    while(co<k-1 && c!=NULL){
        c=c->next;
        co++;
    }
    if(c!=NULL){
        c->next=rever(c->next,k);
    }
    return p;
}
void print(struct node* head){
    struct node *p=head;
    while(p!=NULL){
        cout<<p->d<<" ";
        p=p->next;
    }
    cout<<endl;
}
void push(struct node **head,int f){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->d=f;
    t->next=*head;
    *head = t;
}
int main() {
    struct node *head2=NULL;
    
    int n,k,t,i;
    cin>>n>>k;
    int arr;
    for(i=0;i<n;i++){
        cin>>arr;
        push(&head2,arr);
    }
    print(head2);
    head2=rever(head2,k);
    print(head2);
    
	
	return 0;
}
