#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int value;
    struct node *next;
};

void insert(struct node **head,int d){
    struct node* newnode=(struct node*)malloc(sizeof(struct node)),*ptr=(*head);
    newnode->value=d;
    if(*head==NULL){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
}

void search(struct node *head, int d){
    int f=0;
    while(head!=NULL){
        if(head->value==d){
            f=1;
            break;
        }
        head=head->next;
    }
    if(f==1)
        cout<<"yes";
    else
        cout<<"no";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    struct node *head=NULL;
    int n,m,l;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        insert(&head,m);
    }
    cin>>l;
    search(head,l);
    
    return 0;
}
