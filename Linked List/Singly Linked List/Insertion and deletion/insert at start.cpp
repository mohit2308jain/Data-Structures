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
void insert(struct node *head, int d){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value=d;
    newnode->next=(head);
    (head)=newnode;
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
    int d;
    for(int i=0;i<n;i++){
        cin>>d;
        insert(&head,d);
    }
    print(head);
    
    return 0;
}
