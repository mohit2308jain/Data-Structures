#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int value;
    struct node* next;
};
void insert(struct node** head,int d){
    struct node *newnode=(struct node*)malloc(sizeof(struct node)),*ptr=*head;
    newnode->value=d;
    if(*head==NULL){
        newnode->next=*head;
        *head = newnode;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
}

void print(struct node *head){
    while(head!=NULL){
        if(head->next!=NULL)
            cout<<head->value<<"->";
        else
            cout<<head->value;
        head=head->next;
    }
}
void dele(struct node **head,int p){
    
    if(*head==NULL)
        return;
    
    struct node *ptr;
    
    ptr=(*head);
    *head = ptr -> next;
    delete ptr;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    struct node *head=NULL;
    int n,m,p,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        insert(&head,m);
    }
    cin>>p;
    for(i=0;i<p;i++){
        dele(&head,p);
    }
    
    print(head);
    
    
    return 0;
}
