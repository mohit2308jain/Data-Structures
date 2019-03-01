/******************************************************************************
Question Name: Binary Search Tree
Problem Description

Program Construct a Balanced Binary Tree using Sorted Array. Input: n=number of elements ," elements should be in sorted order"
Test Case 1

Input (stdin)
5

10 20 30 40 50

Expected Output

Given sorted array is

10 20 30 40 50 

The preorder traversal of binary search tree is as follows

30->10->20->40->50->

*******************************************************************************/

#include <iostream>
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
struct node* insert(int arr[], int s,int e){
  
  if(s>e) return NULL;
  
  int mid = (s+e)/2;
  struct node* root = newnod(arr[mid]);
  root->L=insert(arr,s,mid-1);
  root->R=insert(arr,mid+1,e);
  
  return root;
  
}
void preorder(struct node* eoot){
    if(eoot!=NULL){
        cout<<(eoot->x)<<"->";
        preorder(eoot->L);
        preorder(eoot->R);
    }
}
int main() {
    int n,f,i,j;
    cin>>n;
    int arr[n];
    cout<<"Given sorted array is"<<endl;
    for(i=0;i<n;i++){
      cin>>arr[i];
      cout<<arr[i]<<" ";
    }
    cout<<endl<<"The preorder traversal of binary search tree is as follows"<<endl;
    struct node* root=insert(arr,0,n-1);
    preorder(root);
    
    return 0;
}
