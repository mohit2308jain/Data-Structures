/******
Longest Increasing Subsequence

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

****/

#include <iostream>
#include <algorithm>
using namespace std;
void LIS(int arr[],int n){
    int lis[n],i,j;
    lis[0]=1;
    for(i=1;i<n;i++){
        lis[i]=1;
        for(j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i]=lis[j]+1;
            }
        }
    }
    cout<<*max_element(lis,lis+n)<<endl;
}
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
	    LIS(arr,n);
	}
	return 0;
}