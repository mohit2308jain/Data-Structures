/**************************

Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

******************************************/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,sum,i;
        cin>>n>>sum;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int max1=arr[0],st=0,f=0;
        for(i=1;i<=n;i++){
            while(max1 > sum && st < i-1){
                max1 -= arr[st];
                st++;
            }
            
            if(max1==sum){
                cout<<st+1<<" "<<i<<endl;
                f=1;
                break;
            }
            
            if(i<n){
                max1 += arr[i];
            }
        }
        if(f==0){
            cout<<"-1"<<endl;
        }
        
    }
    
	return 0;
}
