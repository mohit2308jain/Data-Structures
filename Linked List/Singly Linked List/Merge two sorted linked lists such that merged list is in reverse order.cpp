/******************************************************************

Merge two sorted linked lists such that merged list is in reverse order

*************************************************************/


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
struct node* merge(struct node* a,struct node* b){
    if(a==NULL && b==NULL) return NULL;
    
    struct node *res=NULL;
    while(a!=NULL && b!=NULL){
        if(a->f <= b->f){
            struct node *tr = a->next;
            a->next=res;
            res = a;
            a = tr;
        }
        else{
            struct node *tr = b->next;
            b->next=res;
            res=b;
            b = tr;
        }
    }
    while(a!=NULL){
        struct node *tr = a->next;
        a->next=res;
        res = a;
        a = tr;
    }
    while(b!=NULL){
        struct node *tr = b->next;
        b->next=res;
        res = b;
        b = tr;
    }
    return res;
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
    struct node *a=NULL,*b=NULL,*c=NULL;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        push(&a,k);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        push(&b,k);
    }
    print(a);
    cout<<endl;
    print(b);
    cout<<endl;
    c = merge(a,b);
    print(c);
    
    return 0;
}
