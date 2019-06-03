Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order. 
Every node is considered as a path of length 1.

Input:

2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L

Output:

2
-1

Explanation:
Test case 1:

           1

        /     \

      2        3

For the above test case the longest sequence is : 1 2 

Test case 2:

            10

         /        \

     20          30

   /      \       /

40      60 90

For the above test case no sequence is possible: -1

/**********************************************


void longestConsecutiveUtil(Node* root, int curLen, int expect, int& res){
    if(root==NULL) return;
    
    if(root->data == expect) curLen++;
    else curLen = 1;
    
    if(res<curLen) res = curLen;
    
    longestConsecutiveUtil(root->left, curLen, root->data+1, res);
    longestConsecutiveUtil(root->right, curLen, root->data+1,res);
    
    
}
int longestConsecutive(Node* root)
{
    if(root==NULL) return -1;
    
    int res = 0;
    
    longestConsecutiveUtil(root, 0, root->data, res);
    if(res==1) res=-1;
    return res;
}

*********************************/
