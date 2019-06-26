/************
Maximum sum increasing subsequence

Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.
Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10
*****************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i,j;
        cin>>n;
        int arr[n];
        int ll[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
            ll[i]=arr[i];
        }
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(arr[i]>arr[j] && ll[i]<ll[j]+arr[i]){
                    ll[i] = ll[j]+arr[i];
                }
            }
        }
        cout<<*max_element(ll,ll+n)<<endl;
    }
	return 0;
}