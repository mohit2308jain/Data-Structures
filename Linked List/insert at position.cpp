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
void insert(struct node** head,int d, int p){
    struct node *newnode = (struct node*)malloc(sizeof(struct node)),*pt=(*head),*temp;
    newnode->value=p;
    if(d==0){
        newnode->next=(*head);
        (*head)=newnode;
    }
    else{
        for(int i=0;i<d;i++){
            temp=pt;
            pt=pt->next;
        }
        newnode->next=pt;
        temp->next=newnode;
    }
}
void print(struct node* head){
    while(head!=NULL){
        if(head->next!=NULL)
            cout<<(head->value)<<"->";
        else
            cout<<(head->value);
        head=head->next;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    struct node *head=NULL;
    int n;
    cin>>n;
    int d,m;
    for(int i=0;i<n;i++){
        cin>>d>>m;
        insert(&head,d,m);
    }
    print(head);
    
    return 0;
}
