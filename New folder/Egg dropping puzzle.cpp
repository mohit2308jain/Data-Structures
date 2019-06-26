#include <iostream>
using namespace std;
int bino(int a,int b){
    int s=0,t=1;
    for(int i=1;i<=b;i++){
        t *= (a-i+1);
        t/=i;
        s+=t;
    }
    return s;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int l=1,h=k;
	    while(l<h){
	        int m = (l+h)/2;
	        if(bino(m,n)<k){
	            l=m+1;
	        }
	        else{
	            h=m;
	        }
	    }
	    cout<<l<<endl;
	}
	return 0;
}