/*******************

Check whether a given binary tree is perfect or not
Given a Binary Tree, write a function to check whether the given Binary Tree is a prefect Binary Tree or not.

A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.

Examples:
The following tree is a perfect binary tree

               10
           /       \  
         20         30  
        /  \        /  \
      40    50    60   70


               18
           /       \  
         15         30  
The following tree is not a perfect binary tree

      1
    /    \
   2       3
    \     /  \   
     4   5    6
     
   **************************/

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

int depth(node* node){
	int d=0;
	while(node){
		d++;
		node=node->l;
	}
	return d;
}

int isPerfectUtil(struct node* root, int d, int level){
	if(!root) return 1;

	if(!root->l && !root->r) return (d==level+1);

	if(!root->l || !root->r) return 0;

	return isPerfectUtil(root->l,d,level+1) && isPerfectUtil(root->r,d,level+1);

}

int isPerfect(node* root){
	int d = depth(root);

	return isPerfectUtil(root,d,0);
}

int main(){
    
	struct node *root  = newnod(10); 
    root->l = newnod(20); 
    root->r = newnod(30); 
    root->l->l = newnod(40); 
    root->r->l = newnod(60); 
    root->r->r = newnod(70);


	if(isPerfect(root)) cout<<"yes";
	else cout<<"no";

	return 0;
}
