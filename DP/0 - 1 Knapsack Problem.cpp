/***********
0 - 1 Knapsack Problem

Example:
Input:
2
3
4
1 2 3
4 5 1
2
3
1 2 3
4 5 6
Output:
3
1

*************/

#include <iostream>
using namespace std;
void knap(int val[],int we[], int n, int W){
    int k[n+1][W+1],i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0){
                k[i][j]=0;
            }
            else if(we[i-1] <= j){
                k[i][j]=max(val[i-1]+k[i-1][j-we[i-1]],k[i-1][j]);
            }
            else{
                k[i][j]=k[i-1][j];
            }
        }
    }
    cout<<k[n][W]<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,W,i,j;
	    cin>>n>>W;
	    int val[n],we[n];
	    for(i=0;i<n;i++){
	        cin>>val[i];
	    }
	    for(i=0;i<n;i++){
	        cin>>we[i];
	    }
	    knap(val,we,n,W);
	}
	return 0;
}