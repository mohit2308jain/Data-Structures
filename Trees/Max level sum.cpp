/*This is a function problem.You only need to complete the function given below*/
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */
int height(Node* root){
    if(!root) return 0;
    int h = height(root->left);
    int r = height(root->right);
    
    if(l>=r) return l+1;
    else return r+1;
}
void maxLevel(Node* root, int count[], int level){
    if(root){
        int t = root->data;
        count[level] += t;
        maxLevel(root->left,count,level+1);
        maxLevel(root->right,count,level+1);
    }
}
int maxLevelSum(Node * root)
{
    int i,h = height(root);
    int count[h+1];
    for(i=0;i<h+1;i++){
        count[i]=0;        
    }
    int level=0;
    maxLevel(root,count,level);
    
    int m = count[0];
    for(i=1;i<h+1;i++){
        if(count[i]>m) m = count[i];        
    }
    return m;
}

/*** maximum node level **/

void ll(Node *root,int count[],int level){
    if(root){
        count[level]++;
        ll(root->left,count,level+1);
        ll(root->right,count,level+1);
    }
}
int maxNodeLevel(Node *root)
{
    int h = height(root);
    int count[h+1];
    for(int i=0;i<=h+1;i++){
        count[i]=0;
    }
    
    int level=0;
    ll(root,count,level);
    
    int m = *max_element(count,count+(h+1));
    for(int i=0;i<=h+1;i++){
        if(count[i]==m){
            return i;
        }
    }
}
