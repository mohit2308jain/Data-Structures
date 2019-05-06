/*****************************************************

Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

***************************************************/

#include<iostream>
using namespace std;

int main() {
	//code
	int t,n,k,i;
	cin>>t;
	while(t--){
	    int co[3]={0};
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>k;
	        arr[i] = k;
	        co[k]++;
	    }
	    k=0;
	    for(i=0;i<n;){
	        if(co[k]==0) k++;
	        else{
	            arr[i]=k;
	            co[k]--;
	            i++;
	        }
	    }
	    for(i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
