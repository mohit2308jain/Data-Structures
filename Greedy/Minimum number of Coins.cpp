/************

Minimum number of Coins

Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the change for Rs N.
*********/

#include <iostream>
#include <vector>
using namespace std;
int d[] = {1,2,5,10,20,50,100,200,500,2000};
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    vector<int> v;
	    cin>>n;
	    for(i=9;i>=0;i--){
	        while(n>=d[i]){
	            n -= d[i];
	            v.push_back(d[i]);
	        }
	    }
	    for(i=0;i<v.size();i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}