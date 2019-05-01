/****************************************************************

Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string S.

Output:
For each testcase, print the first non repeating character present in string. Print -1 if there is no non repeating character.

Constraints:
1 <= T <= 900
1 <= N <= 104

Example:
Input : 
3
5  
hello
12
zxvczbtxyzvy
6
xxyyzz

Output :
h
c
-1

***************************************************************/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int i,n,arr[26]={0};
	    string s,r="";
	    int f=0;
	    char g='$';
	    cin>>n;
	    cin>>s;
	    //reverse(s.begin(),s.end());
	    for(i=0;i<s.length();i++){
	        if(arr[s[i]-'a']==0){
	            r+=s[i];
	        }
	        arr[s[i]-'a']++;
	    }
	    for(i=0;i<r.length();i++){
	        if(arr[r[i]-'a']==1){
	            g=r[i];
	            break;
	        }
	    }
	    if(g=='$'){
	        cout<<"-1";
	    }
	    else{
	        cout<<g;
	    }
	    cout<<endl;
	}
	
	return 0;
}
