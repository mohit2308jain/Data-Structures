/*************************************************************************

Next greater element using stack.

*********************************************************************/

#include <iostream>
#include <stack>
using namespace std;

void next(long long arr[],long long n){
    long long nextg[n]={0},i;
    stack<long long> s;
    s.push(0);
    for(i=1;i<n;i++){
        while(!s.empty() && arr[i] > arr[s.top()]){
            nextg[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        nextg[s.top()] = -1;
        s.pop();
    }
    for(i=0;i<n;i++){
        cout<<nextg[i]<<" ";
    }
}
int main() {
    long long t,n,i;
	cin>>t;
	while(t--){
	    cin>>n;
	    long long arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    next(arr,n);
	    cout<<endl;
	}
	//code
	return 0;
}
