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
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
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
void preorder(struct node* eoot){
    if(eoot!=NULL){
        cout<<(eoot->x)<<" ";
        preorder(eoot->L);
        preorder(eoot->R);
    }
}
void inorder(struct node* eoot){
    if(eoot!=NULL){
        inorder(eoot->L);
        cout<<(eoot->x)<<" ";
        inorder(eoot->R);
    }
}
void postorder(struct node* eoot){
    if(eoot!=NULL){
        postorder(eoot->L);
        postorder(eoot->R);
        cout<<(eoot->x)<<" ";
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    struct node* root=NULL;
    int n,f,i,j;
    cin>>n;
    cin>>j;
    root=insert(root,j);
    for(i=1;i<n;i++){
        cin>>f;
        insert(root,f);
    }
    
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    
    return 0;
}
