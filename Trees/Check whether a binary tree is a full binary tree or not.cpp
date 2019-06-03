/******************

Check whether a binary tree is a full binary tree or not
A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes. 
Conversely, there is no node in a full binary tree, which has one child node.

To check whether a binary tree is a full binary tree we need to test the following cases:-

1) If a binary tree node is NULL then it is a full binary tree.
2) If a binary tree node does have empty left and right sub-trees, then it is a full binary tree by definition.
3) If a binary tree node has left and right sub-trees, then it is a part of a full binary tree by definition. In this case recursively check if the left and right sub-trees are also binary trees themselves.
4) In all other combinations of right and left sub-trees, the binary tree is not a full binary tree.

***********************/

#include <iostream>
using namespace std;

struct node{
	int x;
	struct node *left;
	struct node *right;
};

struct node* newNode(int d){
    struct node* newno=(struct node*)malloc(sizeof(struct node));
    newno->x=d;
    newno->left=newno->right=NULL;
    return newno;
}

int isFull(node* root){
	if(!root) return 1;

	if(!root->left && !root->right) return 1;

	if((root->left) && (root->right)){
		return (isFull(root->left) && isFull(root->right));
	}

	return 0;
}

int main(){
    
	struct node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->right = newNode(40); 
    root->left->left = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    root->left->left->left = newNode(80); 
    root->left->left->right = newNode(90); 
    root->left->right->left = newNode(80); 
    root->left->right->right = newNode(90); 
    root->right->left->left = newNode(80); 
    root->right->left->right = newNode(90); 
    root->right->right->left = newNode(80); 
    root->right->right->right = newNode(90); 


	if(isFull(root)) cout<<"yes";
	else cout<<"no";

	return 0;
}
