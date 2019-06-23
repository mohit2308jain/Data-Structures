/*******

Binary representation

************/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    for(i=1<<13;i>0;i=i/2){
	        if(n&i) cout<<"1";
	        else cout<<"0";
	    }
	    cout<<endl;
	}
	return 0;
}

/**********************

Check whether K-th bit is set or not.

Example:
Input:
3
4
0
4
2
500
3

Output:
No
Yes
No

*****************/

#include<iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    n>>=k;
	    if(n & 1) cout<<"Yes"<<endl;
	    else cout<<"No"<<endl;
	}
	return 0;
}

/*******************

Toggle bits given range

Given a non-negative number N and two values L and R. The problem is to toggle the bits in the range L to R in the binary representation of N, i.e, to toggle bits from the rightmost Lth bit to the rightmost Rth bit. A toggle operation flips a bit 0 to 1 and a bit 1 to 0.

*******************/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i=0,j,k,l;
	    long long int arr[1000000];
	    cin>>n>>k>>l;
	    if(n==0) cout<<0;
	    else{
    	    int m=n;
    	    while(m>0){
    	        int r=m%2;
    	        arr[i++]=r;
    	        m=m/2;
    	    }
    	    int s=0;
    	    for(j=k-1;j<l;j++){
    	        if(arr[j]==1) arr[j]=0;
    	        else arr[j]=1;
    	    }
    	    
    	    for(j=0;j<i;j++){
    	        s += (arr[j]*pow(2,j));
    	    }
    	    cout<<s;
	    }
	    cout<<endl;
	}
	return 0;
}

/****************

Swap all odd and even bits

*****************/

#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i=0,j,s=0;
	    cin>>n;
	    int m=n,k;
	    int arr[10000];
	    while(m>0){
	        int r = m%2;
	        arr[i++]=r;
	        m=m/2;
	    }
	    if(i<8){
	        k = 8-i;
	    }
	    
	    for(j=0;j<k;j++){
	        arr[i++]=0;
	    }
	    
	    for(j=i-1;j>=0;j=j-2){
	        int r = arr[j];
	        arr[j]=arr[j-1];
	        arr[j-1]=r;
	    }
	    for(j=0;j<i;j++){
	        s += (arr[j]*pow(2,j));
	    }
	    cout<<s<<endl;
	}
	
	return 0;
}

/******************

Gray Code

***********/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<(n^(n>>1))<<endl;
	}
	
	return 0;
}

/*********************

Reverse Bits

****************/

#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,i,j=0;
	    cin>>n;
	    vector<int> v;
	    for(i=31;i>=0;i--){
	        long long int k = n>>i;
	        if(k&1) v.push_back(1);
	        else v.push_back(0);
	    }
	    for(i=0;i<v.size();i++){
	        j += (v[i]*pow(2,i));
	    }
	    cout<<j<<endl;
	}
	
	return 0;
}

/***********

Rightmost different bit

****************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,l,i,j=0,c;
	    cin>>n>>l;
	    vector<int> v1,v2;
	    for(i=10;i>=0;i--){
	        long long int k = n>>i;
	        if(k&1) v1.push_back(1);
	        else v1.push_back(0);
	    }
	    for(i=10;i>=0;i--){
	        long long int k = l>>i;
	        if(k&1) v2.push_back(1);
	        else v2.push_back(0);
	    }
	    reverse(v1.begin(),v1.end());
	    reverse(v2.begin(),v2.end());
	    for(i=0;i<11;i++){
	        if(v1[i]!=v2[i]){
	            c=i;
	            break;
	        }
	    }
	    cout<<c+1<<endl;
	}
	
	return 0;
}

/***************

Power of 8

************/
#include <cmath>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int b = log2(n)/3;
	    long double a = log2(n)/3;
        if((b-a)==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
	return 0;
}