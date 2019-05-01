/**************************************************
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Example:
Input:
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa

Output:
bbb
for

****************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void secondMost(){
    unordered_map<string,int>m;
    int n,i,k;
    cin>>n;
    string s[n];
    for(i=0;i<n;i++){
        cin>>s[i];
        m[s[i]]++;
    }
    k=0;
    int j=0,max;
    while(j++ < 2){
        max=0;
        for(i=0;i<n;i++){
            if(m[s[i]]>max){
                max=m[s[i]];
                k=i;
            }    
        }
        m[s[k]]=0;
    }
    cout<<s[k]<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    secondMost();
	}
	

	return 0;
}
