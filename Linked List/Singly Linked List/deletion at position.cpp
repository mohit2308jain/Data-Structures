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
void delete1(struct node* head,int p){\
    struct node *ptr;
    if(head==NULL)
        return;
    else{
        ptr=head;
        if(p==0){
            head=ptr->next;
            free(ptr);
            return;   
        }
        int i;
        for(i=0;ptr!=NULL&&i<p-1;i++){
            ptr=ptr->next;
        }
        if (ptr == NULL || ptr->next == NULL) 
         return; 
        
        struct node *next = ptr->next->next; 
        
        free(ptr->next);  // Free memory 
  
        ptr->next = next; 
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
