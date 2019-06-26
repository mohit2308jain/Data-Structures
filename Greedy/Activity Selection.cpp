/********************

Activity Selection

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6
******************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct job{
    int deadline;
    int start;
};
bool com(job a, job b){
    return (a.deadline<b.deadline);
}
int main() {
    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        struct job jj[n];
        for(i=0;i<n;i++){
            cin>>jj[i].start;
        }
        for(i=0;i<n;i++){
            cin>>jj[i].deadline;
        }
        sort(jj,jj+n,com);
        int c=1,j;
        i=0;
        for(j=1;j<n;j++){
            if(jj[j].start>=jj[i].deadline){
                i=j;
                c++;
            }
        }
        cout<<c<<endl;
    }
    
    return 0;
}