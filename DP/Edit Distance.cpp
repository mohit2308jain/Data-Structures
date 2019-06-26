/*************
Edit Distance

Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Example:
Input:
1
4 5
geek gesek

Output:
1

**************/

#include <iostream>
using namespace std;
void edit(string x,string y,int a,int b){
    int lcs[a+1][b+1],i,j;
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            if(i==0){
                lcs[i][j]=j;
            }
            else if(j==0){
                lcs[i][j]=i;
            }
            else if(x[i-1]==y[j-1]){
                lcs[i][j] = lcs[i-1][j-1];
            }
            else{
                lcs[i][j] = 1 + min(lcs[i][j-1],min(lcs[i-1][j],lcs[i-1][j-1]));
            }
        }
    }
    cout<<lcs[a][b]<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    edit(s1,s2,n,m);
	}
	return 0;
}