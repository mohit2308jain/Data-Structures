/***********************************************************

Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. 
Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet with maximum chocolates 
   and student having packet with minimum chocolates is minimum.
   
   
Example:
Input:
2
8
3 4 1 9 56 7 9 12
5
7
7 3 2 4 9 12 56
3

Output:
6
2

**************************************************/

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
        cin>>m;
        sort(arr,arr+n);
        int dif = INT_MAX;
        for(i=0;i+m-1<n;i++){
            int d = arr[i+m-1]-arr[i];
            if(d<dif){
                dif=d;
            }
        }
        cout<<dif<<endl;
        
    }
    
	return 0;
}
