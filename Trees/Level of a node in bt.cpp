/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node
int gee(Node* root, int target,int level){
    if(!root) return 0;
    int a,b;
    if(root->data==target) return (++level);
    else{
        level++;
        a = gee(root->left,target,level);
        if(a>=level) return a;
        
        b = gee(root->right,target,level);
        if(b>=level) return b;
    }
}
int getLevel(struct Node *node, int target)
{
    int level = 0;
    return gee(node,target,level);
}
