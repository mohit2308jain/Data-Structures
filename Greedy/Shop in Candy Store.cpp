/**********************
Shop in Candy Store

In a candy store there are N different types of candies available  and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get atmost K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to tell what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to tell what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Example:
Input    
 1
 4  2
 3 2 1 4

Output 
 3 7

***************************/

#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,i;
	    cin>>n>>m;
	    int a[n];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    int k = n,min=0,max=0;
	    for(i=0;i<k;i++){
	        min += a[i];
	        k = (k-m);
	    }
	    cout<<min<<" ";
	    int j=0;
	    for(i=n-1;i>=j;i--){
	        max += a[i];
	        j = (j+m);
	    }
	    cout<<max<<endl;
	}
	
	return 0;
}