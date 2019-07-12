{
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("
");
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
struct node* makeUnion(struct node* head1, struct node* head2);
int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(makeUnion(a, b));
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* Union1(struct node* head1, struct node* head2)
{
    if(!head1) return head2;
    if(!head2) return head1;
    
    node *res=NULL;
    if(head1->data<=head2->data){
        res = head1;
        res->next=Union1(head1->next,head2);
    }
    else{
        res = head2;
        res->next=Union1(head1,head2->next);
    }
    return res;
}
void split(node* root,node** a,node** b){
    node *s = root;
    node *f = root->next;
    while(f){
        f=f->next;
        if(f){
            s=s->next;
            f=f->next;
        }
    }
    *a=root;
    *b=s->next;
    s->next=NULL;
}

struct node* merge(struct node* root)
{
    node *a,*b,*h=root;
    if(!root || !root->next) return root;
    
    split(h,&a,&b);
    a=merge(a);
    b=merge(b);
    
    return Union1(a,b);
}
node* dup(node* root){
    node *p = root,*q;
    while(p->next){
        if(p->data==p->next->data){
            q = p->next->next;
            free(p->next);
            p->next=q;
        }
        else p=p->next;
    }
    return root;
}
struct node* makeUnion(struct node* head1, struct node* head2)
{
    node* res = NULL;
    res = Union1(head1,head2);
    res = merge(res);
    res = dup(res);
    return res;
}
