/************************

Group Anagrams Together

Given an array of words, print the count of all anagrams together in sorted order (increasing order of counts).
For example, if the given array is {“cat”, “dog”, “tac”, “god”, “act”}, 
then grouped anagrams are “(dog, god) (cat, tac, act)”. So the output will be 2 3.
******************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int i,n,max=0;
	    cin>>n;
	    map<string,int> m;
	    vector<int> v;
	    string s[n];
	    for(i=0;i<n;i++){
	        cin>>s[i];
	        sort(s[i].begin(),s[i].end());
	        m[s[i]]++;
	    }
	    map<string,int>:: iterator it;
	    for(it=m.begin();it!=m.end();it++){
	        v.push_back(it->second);
	    }
	    sort(v.begin(),v.end());
	    for(i=0;i<v.size();i++){
	        cout<<v[i]<<" ";
	    }
	    cout<<endl;
	    
	    
	}
	return 0;
}

/***********************

Lucky Number

A n digit number has n*(n+1)/2 sub-numbers.  For example, all possible sub-numbers of 975 are 9 7 5 97 75 975.
 A number is called Lucky if all sub-numbers have different digit product.  Digit product of a number is product of its digits.  

For example, the number 23 is Lucky.  Subsequences of it are 2, 3 and 23 and digit products are 2, 3 and 6 respectively 
(All digit products are different). 975 is also lucky.

 
****************/

#include <iostream>
#include<map>
using namespace std;

int main() {
	long long int t;
	cin>>t;
	while(t--){
	    long long int n,m,a=1;
	    cin>>n;
	    m=n;
	    map<long long int,long long int> mp;
	    while(m!=0){
	        long long int f = m,p=1;
	        while(f!=0){
	            int r = f%10;
	            p = p*r;
	            if(mp[p]){
	                a=0;
	                break;
	            }
	            mp[p]++;
	            f/=10;
	        }
	        if(a==0){
	            break;
	        }
	        m/=10;
	    }
	    cout<<a<<endl;
	}
	return 0;
}

/*********************

Winner of the election

Given an array of names (consisting of lowercase characters) of candidates in an election.
A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. 
If there is tie, print lexicographically smaller name.

******************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int i,n,max=0;
	    cin>>n;
	    map<string,int> m;
	    vector<string> v;
	    string s[n];
	    for(i=0;i<n;i++){
	        cin>>s[i];
	        m[s[i]]++;
	        if(m[s[i]]>max) max = m[s[i]];
	    }
	    map<string,int>:: iterator it;
	    for(it=m.begin();it!=m.end();it++){
	        if(it->second == max){
	            v.push_back(it->first);
	        }
	    }
	    if(v.size()==1) cout<<v[0]<<" "<<m[v[0]]<<endl;
	    else{
	        string as = v[0];
    	    for(i=1;i<v.size();i++){
    	        if(as.compare(v[i])>0){
    	            as=v[i];
    	        }
    	    }
    	    cout<<as<<" "<<m[as]<<endl;
	    }
	    
	    
	}
	return 0;
}

/***************

Array Subset of another array

*****************/

#include<iostream>
#include <map>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int k,n,i;
	    cin>>n>>k;
	    long long int a[n],b[k];
	    map<long long int ,long long int> m;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        m[a[i]]++;
	    }
	    for(i=0;i<k;i++){
	        cin>>b[i];
	        m[b[i]]--;
	    }
	    int f=1;
	    for(i=0;i<k;i++){
	        if(m[b[i]]<0){
	            f=0;
	            break;
	        }
	    }
	    if(f==1) cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	}
	return 0;
}

/***********

Given an array arr[] of N numbers. The task is to print only those numbers whose digits are from set {1,2,3}.

***********/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long int t,i;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int arr[n];
	    vector<long long int> v;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(i=0;i<n;i++){
	        long long int e=arr[i];
	        while(e!=0){
	            long long int r = e%10;
	            if(r!=1 && r!=2 && r!=3){
	                break;
	            }
	            e/=10;
	        }
	        if(e==0){
	            v.push_back(arr[i]);
	        }
	    }
	    if(v.size()==0) cout<<"-1"<<endl;
	    else{
	        sort(v.begin(),v.end());
    	    for(i=0;i<v.size();i++){
    	        cout<<v[i]<<" ";
    	    }
    	    cout<<endl;
	    }
	}
	return 0;
}

/******************

Check if array contains contiguous integers with duplicates allowed

 Example:

 2
8
5  2  3  6  4  4  6  6
7
10  14  10  12  12  13  15

Output :
 Yes
 No

***********/

#include <iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	long long int t,i;
	cin>>t;
	while(t--){
	    long long int n,f=0;
	    cin>>n;
	    map<int,int> m;
	    long long int arr[n];
	    cin>>arr[0];
	    m[arr[0]]++;
	    int max=arr[0],min=arr[0];
	    for(i=1;i<n;i++){
	        cin>>arr[i];
	        m[arr[i]]++;
	        if(max<arr[i]) max=arr[i];
	        if(min>arr[i]) min=arr[i];
	    }
	    for(i=min;i<=max;i++){
	        if(m[i]<1){
	            f=1;
	            break;
	        }
	    }
	    if(f==1) cout<<"No"<<endl;
	    else cout<<"Yes"<<endl;
	}
	return 0;
}


/*****************

Find the Odd Occurence

****************/

#include<iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    cin>>arr[0];
	    int s = arr[0];
	    for(i=1;i<n;i++){
	        cin>>arr[i];
	        s = s ^ arr[i];
	    }
	    cout<<s<<endl;
	    
	}
	return 0;
}

/********************

Find the first non-repeating element in a given array A of N integers.

Example:
Input:
4
5
-1 2 -1 3 2
6
9 4 9 6 7 4
3
1 1 1
2
-3 2
Output:
3
6
0
-3
*****************/

#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,i;
	    cin>>n;
	    long long int arr[n],f=0;
	    unordered_map<long long int,long long int> m;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	        m[arr[i]]++;
	    }
	    for(i=0;i<n;i++){
	        if(m[arr[i]]==1){
	            cout<<arr[i]<<endl;
	            f=1;
	            break;
	        }
	    }
	    if(f==0) cout<<f<<endl;
	}
	
	return 0;
}

/***************

In given range, print all numbers having unique digits. e.g. In range 1 to 20 should print all numbers except 11.

**************/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long int t,i,j;
	cin>>t;
	while(t--){
	    long long int n,m;
	    cin>>n>>m;
	    for(i=n;i<=m;i++){
	        int s = i,f=1;
	        int vis[10]={0};
	        while(s!=0){
	            int r = s%10;
	            vis[r]++;
	            if(vis[r]>1){
	                f=0;
	                break;
	            }
	            s/=10;
	        }
	        if(f==1) cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
