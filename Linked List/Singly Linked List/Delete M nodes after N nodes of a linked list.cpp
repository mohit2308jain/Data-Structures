/******************************************************

Delete M nodes after N nodes of a linked list.
***********************************************************/


#include <bits/stdc++.h>

using namespace std;
struct node{
    int f;
    struct node* next;
};
void push(struct node** head,int d){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->f=d;
    t->next=*head;
    *head=t;
}
struct node* modify(struct node* head,int n, int m){
    struct node *p = head,*t,*q;
    while(p){
        for(int c=0;c<n-1 && p!=NULL;c++){
            p=p->next;
        }
        if(p==NULL){
            return head;
        }
        t=p->next;
        for(int c=0;c<m && t!=NULL;c++){
            q=t;
            t=t->next;
            free(q);
        }
        p->next=t;
        p=t;
    }
    return head;
}
void print(struct node* h){
    struct node* j = h;
    while(j!=NULL){
        cout<<j->f<<" ";
        j=j->next;
    }
}
int main()
{
    int t,m,n,k;
    struct node* head = NULL;
    cin>>t>>n>>m;
    for(int i=0;i<t;i++){
        cin>>k;
        push(&head,k);
    }
    head = modify(head,n,m);
    print(head);
    
    return 0;
}
