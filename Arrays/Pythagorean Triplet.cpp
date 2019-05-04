/*************************************************************

Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Example:
Input:
1
5
3 2 4 6 5

Output:
Yes

*****************************************************/

#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],i,f=0;
        for(i=0;i<n;i++){
            cin>>arr[i];
            arr[i]=arr[i]*arr[i];
        }
        sort(arr,arr+n);
        for(i=n-1;i>=2;i--){
            int l=0;
            int r=i-1;
            while(l<r){
                if(arr[l]+arr[r]==arr[i]){
                    f=1;
                    break;
                }
                else if(arr[l]+arr[r]<arr[i]){
                    l++;
                }
                else{
                    r--;
                }
            }
            if(f==1){
                break;
            }
        }
        if(f==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
	return 0;
}
