/******************************************************

Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
The result is going to be very large, hence return the result in the form of a string.


Example:
Input:
2
5
3 30 34 5 9
4
54 546 548 60

Output:
9534330
6054854654

***************************************************/


#include <iostream>
#include <algorithm>
using namespace std;
int com(string a,string b){
    string x = a+b;
    string y = b+a;
    
    if(x>y) return 1;
    else return 0;
}
int main() {
	int t,i;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s[n];
	    for(i=0;i<n;i++){
	        cin>>s[i];
	    }
	    sort(s,s+n,com);
	    for(i=0;i<n;i++){
	        cout<<s[i];
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}
