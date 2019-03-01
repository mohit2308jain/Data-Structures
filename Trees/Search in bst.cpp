/******************************************************************************
Question Name: Searching using Binary Search Tree
Problem Description

Write a program to search for an element of an unordered list using Binary Search Tree.

MANDATORY

1. The nodes of the tree must be defined as "node".
2. "search" function must be implemented to search for the element
Test Case 1

Input (stdin)
7

50 30 40 60 70 80 20 

30

Expected Output

element is found
Test Case 2

Input (stdin)
7

50 30 40 60 70 80 20

66

Expected Output

element not found

*******************************************************************************/

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
void search(struct node* node,int k){
  if(node==NULL)
    cout<<"element not found";
  else if(node->x==k) cout<<"element is found";
  else if(node->x < k){
    search(node->R,k);
  }
  else if(node->x > k){
    search(node->L,k);
  }
}
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
  struct node* root=NULL;
  int n,f,i,j,k;
  cin>>n;
  cin>>j;
  root=insert(root,j);
  for(i=1;i<n;i++){
    cin>>f;
    insert(root,f);
  }
  cin>>k;
  search(root,k);

  return 0;
}
