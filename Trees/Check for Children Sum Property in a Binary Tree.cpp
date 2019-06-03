/*******************

Check for Children Sum Property in a Binary Tree
Given a binary tree, write a function that returns true if the tree satisfies below property.
For every node, data value must be equal to sum of data values in left and right children. 

*********************************/

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

int isSumProp(struct node* root){
	int ldata=0,rdata=0;

	if(!root || (!root->l && !root->r)) return 1;
	else{
		if(root->l) ldata = root->l->x;
		if(root->r) rdata = root->r->x;

		if((root->x == ldata+rdata) && isSumProp(root->l) && isSumProp(root->r))
			return 1;
		else return 0;
	}
}

int main(){
    
	struct node *root  = newnod(10); 
    root->l         = newnod(8); 
    root->r        = newnod(2); 
    root->l->l   = newnod(3); 
    root->l->r  = newnod(5); 
    root->r->r = newnod(2);

	cout<<endl;

	if(isSumProp(root)) cout<<"yes";
	else cout<<"no";

	return 0;
}
