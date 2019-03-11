#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int x;
    struct node* L;
    struct node* R;
};
struct node* newnod(int d){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->x=d;
    newnode->L=newnode->R=NULL;
    return newnode;
}
struct node* insert(struct node* root,int d){
    if(root==NULL){
        return newnod(d);
    }
    else if(d <= root->x){
        root->L=insert(root->L,d);
    }
    else if(d > root->x){
        root->R=insert(root->R,d);
    }
    return root;
}
struct node* minVal(struct node* node){
    struct node* c = node;
    while(c->L){
        c=c->L;
    }
    return c;
}
struct node* height(struct node* Root,int k){
    if(Root==NULL) return Root;

    else if(k < Root->x){
        Root->L=height(Root->L,k);
    }
    else if(k > Root->x){
        Root->R=height(Root->R,k);
    }
    else{
        // if 1 or no chid
        if(Root->L==NULL){
            struct node* temp = Root->R;
            free(Root);
            return temp;
        }
        else if(Root->R==NULL){
            struct node* temp = Root->L;
            free(Root);
            return temp;
        }
        
        // for 2 children
        struct node* temp = minVal(Root->R);
        Root->x=temp->x;
        Root->R = height(Root->R,temp->x);
    }
    return Root;
    
}
void inorder(struct node* n){
    if(n){
        inorder(n->L);
        cout<<n->x<<" ";
        inorder(n->R);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    struct node* root=NULL;
    int n,i,j,k,a,b,c;
    cin>>n;
    cin>>j;
    root=insert(root,j);
    for(i=1;i<n;i++){
        cin>>k;
        insert(root,k);
    }
    inorder(root);
    cout<<endl;
    cin>>a>>b>>c;
    root=height(root,a);
    inorder(root);
    cout<<endl;
    root=height(root,b);
    inorder(root);
    cout<<endl;
    root=height(root,c);
    inorder(root);
    cout<<endl;
    
    return 0;
}