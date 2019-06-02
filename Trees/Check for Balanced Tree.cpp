/**********************


Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

**************************************/

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
int height(struct node* Root){
    if(Root==NULL) return 0;
    
    int l=height(Root->L);
    int r=height(Root->R);
    
    if(l>=r) return (l+1);
    else return (r+1);
}

bool isBalanced(Node *root)
{
    if(root==NULL) return 1;
    
    int l = height(root->left);
    int r = height(root->right);
    
    if(abs(r-l) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return 1;
    }
    
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    struct node* root=NULL;
    int n,i,j,k;
    cin>>n;
    cin>>j;
    root=insert(root,j);
    for(i=1;i<n;i++){
        cin>>k;
        insert(root,k);
    }
    
    if(isBalanced(root)) cout<<"Balanced";
    else cout<<"Not Balanced";
    
    return 0;
}
