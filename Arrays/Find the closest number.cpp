/******************************

Given an array of sorted integers. The task is to find the closest value to the given number in array. Array may contain duplicate values.

Note: If the difference is same for two values print the value which is greater than the given number.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two integers N & K and the second line contains N space separated array elements.

Output:
For each test case, print the closest number in new line.

Constraints:
1<=T<=100
1<=N<=105
1<=K<=105
1<=A[i]<=105

Example:
Input:
2
4 4
1 3 6 7
7 4
1 2 3 5 6 8 9

Output:
3
5

*****************************/

#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n],i;
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        int a = arr[0];
        for(i=0;i<n;i++){
            if(abs(arr[i]-m) <= abs(a-m)){
                a = arr[i];
            }
        }
        cout<<a<<endl;
        
    }
    
	return 0;
}
