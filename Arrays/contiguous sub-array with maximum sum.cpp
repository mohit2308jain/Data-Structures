/**********************************

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

*********************/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,sum,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int t,sum1=arr[0],sum2=arr[0];
        for(i=1;i<n;i++){
            t = sum1 + arr[i];
            if(arr[i]<t){
                sum1=t;
            }
            else{
                sum1=arr[i];
            }
            
            if(sum1>sum2){
                sum2=sum1;
            }
        }
        cout<<sum2<<endl;
    }
    
	return 0;
}
