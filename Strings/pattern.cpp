#include <iostream>
using namespace std;

int main() {
    int i,j,n;
    cin>>n;
    if(n==1) cout<<"*";
    else{
        for(i=1;i<=n;i++){
            if(i==1){
                for(j=1;j<=(n-1);j++) cout<<" ";
                for(j=n;j<=(2*n-1);j++) cout<<"*";
            }
            else if(i==n){
                for(j=1;j<=n;j++){
                    cout<<"*";
                }
            }
            else{
                for(j=1;j<(n-i+1);j++) cout<<" ";
                for(j=(n-i+1);j<=(2*n-i);j++){
                    if(j==(n-i+1) || j==(2*n-i)) cout<<"*";
                    else cout<<" ";
                }
            }
            cout<<endl;
        }
    }
    
	return 0;
}

/***

7

      *******
     *     *
    *     *
   *     *
  *     *
 *     *
*******

****************/