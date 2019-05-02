/*******************************

Leaders in an array.


Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. 
Also, the rightmost element is always a leader. 

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

********************************/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int a[n],k=1;
	    a[0]=arr[n-1];
	    int max=arr[n-1];
	    for(i=n-2;i>=0;i--){
	        if(max<=arr[i]) {
	            max=arr[i];
	            a[k]=max;
	            k++;
	        }
	    }
	    
	    
	    for(i=k-1;i>=0;i--){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}

