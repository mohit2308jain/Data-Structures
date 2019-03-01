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
    
    cout<<height(root);
    
    return 0;
}
