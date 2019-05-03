/*********************************

K'th Smallest in array.

**************************************/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k,i;
        cin>>n;
        int arr[n],m=0;
        for(i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>m) m=arr[i];
        }
        cin>>k;
        int a[m+1]={0};
        for(i=0;i<n;i++){
            a[arr[i]]=1;
        }
        
        for(i=0;i<=m;i++){
            if(k!=0){
                if(a[i]==1){
                    k--;
                }
            }
            else{
                break;
            }
        }
        cout<<i-1<<endl;
        
    }
    
	return 0;
}
