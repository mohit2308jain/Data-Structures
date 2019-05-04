/********************************************************************

The cost of stock on each day is given in an array A[] of size N. 
Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Example
Input:
2
7
100 180 260 310 40 535 695
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
(1 4) (5 9)

**********************************************************/
#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        int arr[n],i;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        int currbuy=0;
        int currsell=0,f=0;
        
        for(i=1;i<n;i++){
            if(arr[currsell]<arr[i]){
                currsell=i;
                if(i==n-1){
                    cout<<"("<<currbuy<<" "<<currsell<<") ";
                    f=1;
                }
            }
            else{
                if(arr[currsell]-arr[currbuy]>0){
                    cout<<"("<<currbuy<<" "<<currsell<<") ";
                    f=1;
                }
                currbuy=i;
                currsell=i;
            }
        }
        if(f==0) cout<<"No Profit";
        cout<<endl;
        
        
        
    }
    
	return 0;
}
