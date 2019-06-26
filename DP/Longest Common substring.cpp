/***************************************************************************************************
Longest Common substring

**************************************************************************/

#include<iostream>
using namespace std;
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int LongestString(string s1,string s2,int n,int m){
    int i,j,res=0;
    int LC[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0){
                LC[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                LC[i][j]=LC[i-1][j-1]+1;
                res = max(res,LC[i][j]);
            }
            else{
                LC[i][j]=0;
            }
        }
    }
    return res;
}
int main() {
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        cout<<LongestString(s1,s2,n,m)<<endl;
    }
    
	//code
	return 0;
}
