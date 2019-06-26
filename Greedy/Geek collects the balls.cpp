/***********
Geek collects the balls

There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. The buckets on both roads are kept in such a way that they are sorted according to the number of balls in them. Geek starts from the end of the road which has the bucket with a lower number of balls(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).
The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads). Now you need to help Geek to collect the maximum number of balls.

Example:
Input:
1
5 5
1 4 5 6 8
2 3 4 6 9

Output:
29
********************/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m,i,j;
	    cin>>n>>m;
	    int a[n],b[m];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(i=0;i<m;i++){
	        cin>>b[i];
	    }
	    i=0;
	    j=0;
	    int f=0,s=0,res=0;
	    while(i<n && j<m){
	        if(a[i]<b[j]){
	            f+=a[i++];
	        }
	        else if(a[i]>b[j]){
	            s+=b[j++];
	        }
	        else{
	            res+=max(f,s)+a[i];
	            f=0;
	            s=0;
	            int te = a[i];
	            i++;
	            j++;
	            while(i<n && a[i]==te){
	                res+=a[i++];
	            }
	            while(j<m && b[j]==te){
	                res+=b[j++];
	            }
	       }
	    }
       while(i<n){
           f+=a[i++];
       }
       while(j<m){
           s+=b[j++];
       }
       res += max(f,s);
       cout<<res<<endl;
	    
	}
	
	return 0;
}