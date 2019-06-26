/**************
Largest number possible

Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.

Example 

Input
2
2 9
3 20

Output 

90
992 

**************************/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    if(m==0 || m > (9*n)){
	        cout<<-1<<endl;
	    }
	    else{
	        int res[n],i;
	        for(i=0;i<n;i++){
	            if(m>=9){
	                m-=9;
	                res[i]=9;
	            }
	            else{
	                res[i]=m;
	                m=0;
	            }
	            cout<<res[i];
	        }
	        cout<<endl;
	    }
	}
	return 0;
}