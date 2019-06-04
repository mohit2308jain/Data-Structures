#include <bits/stdc++.h>

using namespace std;

void rrotate(long long arr[], long long n){
    long long t = arr[n-1],i;
    for(i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=t;
}
void lrotate(long long arr[], long long n){
    long long t = arr[0],i;
    for(i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=t;
}
int main()
{
    long long n,i,k,l;
    cin>>n>>k;
    long long arr[n+1];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    
    k = k%n;
    
    l=(n-k);
    if(l>k){
        for(i=0;i<k;i++){
            lrotate(arr,n);
        }
    }
    else{
        for(i=0;i<l;i++){
            rrotate(arr,n);
        }
    }

    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
