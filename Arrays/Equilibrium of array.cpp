/*****************************

Equilibrium of array

**********************************************/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i,s1=0,s2=0,a=-1;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	        s1 += arr[i];
	    }
	    
	    for(i=0;i<n;i++){
	        s1 -= arr[i];
	        
	        if(s1==s2){
	            a=i;
	            break;
	        }
	        
	        s2 += arr[i];
	    }
	    if(a==-1) cout<<"-1"<<endl;
	    else cout<<a+1<<endl;
	}
	return 0;
}