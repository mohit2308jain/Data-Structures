#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,i,j;
        cin>>n>>m;
        int arr[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        int k=0;
        int l=0;
        
        while(k<n && l<m){
            for(i=k;i<m;i++){
                cout<<arr[k][i]<<" ";
            }
            k++;
            for(i=k;i<n;i++){
                cout<<arr[i][m-1]<<" ";
            }
            m--;
            if(k<n){
                for(i=m-1;i>=l;i--){
                    cout<<arr[n-1][i]<<" ";
                }
                n--;
            }
            if(l<m){
                for(i=n-1;i>=k;i--){
                    cout<<arr[i][l]<<" ";
                }
                l++;
            }
        }
        cout<<endl;
    }
    
	return 0;
}
