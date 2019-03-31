/*****************************************************

Check if linked list is palindrome or not.

*******************************************************/

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
void rever(struct node* head){
    struct node *c,*t,*p;
    t=NULL,p=NULL,c=head;
    while(c){
        t=c->next;
        c->next=p;
        
        p=c;
        c=t;
    }
    head=p;
}
string pal(struct node* head){
    struct node *p1,*p2,*mid;
    p1=head;
    p2=head;
    while(p2){
        p2=p2->next;
        if(p2) p2=p2->next;
        if(p1) p1=p1->next;
    }
    mid=p1;
    rever(mid->next);
    p1=head;
    p2=mid->next;
    int f=1;
    while(p2){
        if(p1->d != p2->d){
            f=0;
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }
    rever(mid->next);
    if(f==0) return "No";
    return "Yes";
}
void push(struct node **head,int f){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->d=f;
    t->next=*head;
    *head = t;
}
int main() {
    struct node* head=NULL;
    int n,k,t,i;
    cin>>n;
    int arr;
    for(i=0;i<n;i++){
        cin>>arr;
        push(&head,arr);
    }
    cout<<pal(head);
    
	
	return 0;
}
