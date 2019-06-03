/*****************

Check if a given Binary Tree is SumTree
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3
  
**************************************************/

#include <iostream>
using namespace std;

struct node{
	int x;
	struct node *l;
	struct node *r;
};

struct node* newnod(int d){
    struct node* newno=(struct node*)malloc(sizeof(struct node));
    newno->x=d;
    newno->l=newno->r=NULL;
    return newno;
}

int sum(struct node* root){
	if(!root) return 0;

	return (sum(root->l) + root->x + sum(root->r));
}

int isSumTree(struct node* root){
	int ls,rs;

	if(root==NULL || (!root->l)&&(!root->r)){
		return 1;
	}

	ls = sum(root->l);
	rs = sum(root->r);

	if((root->x == ls+rs) && isSumTree(root->l) && (root->r)){
		return 1;
	} 

	return 0;
}

void inorder(struct node* eoot){
    if(eoot!=NULL){
        inorder(eoot->l);
        cout<<(eoot->x)<<" ";
        inorder(eoot->r);
    }
}

int main(){
    
	struct node *root  = newnod(26); 
    root->l         = newnod(10); 
    root->r        = newnod(3); 
    root->l->l   = newnod(4); 
    root->l->r  = newnod(6); 
    root->r->r = newnod(3);

	inorder(root);
	cout<<endl;

	if(isSumTree(root)) cout<<"yes";
	else cout<<"no";

	return 0;
}
