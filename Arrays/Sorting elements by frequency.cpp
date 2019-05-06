/******************************************

Given an array A[] of integers, sort the array according to frequency of elements. 
That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5
******************************/


#include <iostream>
#include <algorithm>
#include<map>
using namespace std;
bool comp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second>p2.second;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    map<int,int> m;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	        m[arr[i]]++;
	    }
	    
	    int size = m.size();
	    pair<int, int> p[size];
	    
	    int j=0;
	    for(auto i = m.begin();i!=m.end();i++){
	        p[j++] = make_pair(i->first,i->second);
	    }
	    
	    sort(p,p+size,comp);
	    
	    for(i=0;i<size;i++){
	        int f = p[i].second;
	        while(f--){
	            cout<<p[i].first<<" ";
	        }
	    }
	    cout<<endl;
	    
	}
	
	
	return 0;
}
