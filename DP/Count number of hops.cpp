/*********
Count number of hops

A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

***********/

#include <iostream>
using namespace std;
void ll(int n){
    int res[n+1];
    res[0]=1;
    res[1]=1;
    res[2]=2;
    for(int  i=3;i<=n;i++){
        res[i]=res[i-1]+res[i-2]+res[i-3];
    }
    cout<<res[n]<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll(n);
	}
	return 0;
}