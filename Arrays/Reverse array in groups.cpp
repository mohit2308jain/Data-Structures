/**********************************************************

Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

Example:
Input
1
5 3
1 2 3 4 5

Output
3 2 1 5 4


**********************************************************************/

#include <iostream>
using namespace std;
void reverse(int arr[],int n, int a,int b){
    if(b>n){
        b=n;
    }
    while(a<b){
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
        a++;
        b--;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n],i;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int f = n/k;
	    if((f*k)<n){
	        f++;
	    }
	    for(i=0;i<f;i++){
	        reverse(arr,n-1,(i*k),((i+1)*k)-1);
	    }
	    
	    for(i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
