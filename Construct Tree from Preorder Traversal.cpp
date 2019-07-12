/******************

Construct Tree from Preorder Traversal

Given an array pre[] that represents Preorder traversal of a binary tree. One more array preLN[] is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in preLN[] indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node.

Input:
There will be T, test cases and for each test case the function will be called separately.
The function takes three arguments as input, first an integer N, denoting the size of both the array, second an array pre[] that represents Preorder traversal of the binary tree and the last argument a character array preLN[] which indicates that the corresponding node in Binary Tree is a leaf node or a normal node.

Output:
The output will be the inorder traversal of the resultant tree.

Constraints:
1 <=T <= 75
1 <= N <= 100
1 <= pre[i] <= 100
preLN[i]: {'N', 'L'}

User Task:
Your task is to complete the function constructTree(), that constructs the tree from the given two arrays and return the root pointer to new binary tree formed.

Example:
Input:
3
5
10 30 20 5 15 
N N L L L 
4
1 2 4 3 
N N L L 
6
1 2 4 6 5 3 
N N N L L L

Output:
20 30 5 10 15 
4 2 3 1 
6 4 5 2 3 1
******************/

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* newNode (int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}
Node* constructTree(int n, int pre[], char preLN[]);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node *constructTreeUtil(int pre[],char preLN[],int *i,int n){
    if(*i>=n) return NULL;
    
    Node* root=NULL;
    if(preLN[*i]=='L'){
        root=newNode(pre[*i]);
    }
    else{
        root=newNode(pre[*i]);
        *i = *i + 1;
        root->left=constructTreeUtil(pre,preLN,i,n);
        *i = *i + 1;
        root->right=constructTreeUtil(pre,preLN,i,n);
    }
    
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i=0;
    return constructTreeUtil(pre,preLN,&i,n);
}
