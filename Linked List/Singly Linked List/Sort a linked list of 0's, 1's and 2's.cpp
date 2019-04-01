/*********************************************
Sort a linked list of 0's, 1's and 2's.


************************************************/
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
struct node* modify(struct node* head){
    int co[3]={0};
    struct node *p = head;
    while(p!=NULL){
        co[p->f]++;
        p=p->next;
    }
    p=head;
    int i=0;
    while(p!=NULL){
        if(co[i]==0) i++;
        else{
            p->f = i;
            co[i]--;
            p=p->next;
        }
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
    int t,k;
    struct node* head = NULL;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>k;
        push(&head,k);
    }
    head = modify(head);
    print(head);
    
    return 0;
}
