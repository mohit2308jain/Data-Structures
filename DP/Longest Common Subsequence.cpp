/********
Longest Common Subsequence

2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

***********/

#include <iostream>
using namespace std;
void LCS(string x,string y,int a,int b){
    int lcs[a+1][b+1],i,j;
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            if(i==0 || j==0){
                lcs[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else{
                if(lcs[i-1][j]>lcs[i][j-1]) lcs[i][j] = lcs[i-1][j];
                else lcs[i][j] = lcs[i][j-1];
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
	    LCS(s1,s2,n,m);
	}
	return 0;
}