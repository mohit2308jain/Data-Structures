#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
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
            printf("%d->",head->value);
        else
            printf("%d",head->value);
        head=head->next;
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    struct node* head=NULL;
    int n;
    scanf("%d",&n);
    int m;
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        insert(head,m);
        
    }
    print(head);
    
    return 0;
}
