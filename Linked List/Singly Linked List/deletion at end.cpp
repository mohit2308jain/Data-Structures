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
void delete1(struct node* head,int p){
    struct node *ptr,*pre;
    if(head==NULL)
        return;
    else{
        for(int i=0;i<p;i++){
            ptr=head;
            pre=head;
            while(ptr->next!=NULL){
                pre=ptr;
                ptr=ptr->next;
            }
            if(ptr==head)
                head==NULL;
            else
                pre->next=NULL;
            
            free(ptr);
        }
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    struct node *head=NULL;
    int n,m,p;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        insert(&head,m);
    }
    cin>>p;
    delete1(head,p);
    
    print(head);
    
    
    return 0;
}
