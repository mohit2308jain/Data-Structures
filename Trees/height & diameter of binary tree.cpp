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

int diameter(Node* node)
{
    if(node==NULL) return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);
    
    int ld = diameter(node->left);
    int rd = diameter(node->right);
    
    int m;
    if(ld>=rd) m=ld;
    else m=rd;
    
    
    if((lh+rh)>=m) return (lh+rh+1);
    else return m;
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



/***  O(n) solution for diameter
Optimized implementation: 
The above implementation can be optimized by calculating the height in the same recursion rather than calling a height() separately.  
This optimization reduces time complexity to O(n).
***/
int diameter(struct node* root, int& height){
	int lh = 0,rh = 0;

	int ld = 0, rd = 0;
	if(!root){
		height = 0;
		return 0;
	}

	ld = diameter(root->left,lh);
	rd = diameter(root->right,rh);

	if(lh>=rh) height = lh+1;
	else height = rh+1;

	int r,l = (lh+rh+1);
	if(ld>=rd) r = ld;
	else r = rd;

	if(l>=r) return l;
	else return r;

} 

