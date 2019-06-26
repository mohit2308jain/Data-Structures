/********
Coin Change

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5

Explanation:
Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2}.
*************/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k,i,j;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>k;
	    
	    int tab[k+1];
	    memset(tab, 0, sizeof(tab)); 
	    tab[0]=1;
	    for(i=0;i<n;i++){
	        for(j=arr[i];j<=k;j++){
	            tab[j] += tab[j-arr[i]];
	        }
	    }
	    cout<<tab[k]<<endl;
	}
	return 0;
}