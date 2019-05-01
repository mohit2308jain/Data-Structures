/**************************************************

Given a array of N strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer N. Next line has space separated N strings.

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).


Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

***************************************************/

#include <iostream>
using namespace std;
string check(string s,string t){
    int i;
    string a="";
    for(i=0;i<t.length();i++){
        if(s[i]==t[i]){
            a += s[i];
        }
        else{
            break;
        }
    }
    return a;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    string s[n];
	    for(i=0;i<n;i++){
	        cin>>s[i];
	    }
	    string ans="";
	    if(n==1){
	        ans=s[0];
	    }
	    else{
	        ans=check(s[0],s[1]);
	        for(i=2;i<n;i++){
	            ans=check(ans,s[i]);
	        }
	    }
	    if(ans.length()==0){
	        cout<<"-1"<<endl;
	    }
	    else{
	        cout<<ans<<endl;
	    }
	    
	}
	
	return 0;
}
