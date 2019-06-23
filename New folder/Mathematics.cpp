/********

Trailing zeros in factorial

************/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int i,n,c=0;
	    cin>>n;
	    for(i=5;n/i>=1;i*=5){
	        c+=(n/i);
	    }
	    cout<<c<<endl;
	}
	
	return 0;
}

/***********

GCD AND LCM

***********/
#include<iostream>
using namespace std;

int main() {
    long long int t;
    scanf("%d", &t);
    while(t--){
    	long long int c,v;
    	cin>>c>>v;
    	long long int a=c,b=v;
    	while(b!=0){
    	    long long int t = b;
    	    b = a%b;
    	    a = t; 
    	}
    	long long int l = (c*v)/a;
    	cout<<l<<" "<<a<<endl;
    	
    }
	return 0;
}

/**********

Count possible triangles

*************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,i,c=0,l,r;
	    cin>>n;
	    long long int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    sort(arr,arr+n);
	    
	    for(i=n-1;i>=1;i--){
	        l=0,r=i-1;
	        while(l<r){
	            if(arr[l]+arr[r]>arr[i]){
	                c+=(r-l);
	                
	                r--;
	            }
	            else l++;
	        }
	    }
	    cout<<c<<endl;
	}
	return 0;
}


/************

Squares in a Matrix

********************/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n,i,c=0,l,r;
	    cin>>n>>r;
	    while(n>0 && r>0){
	        c += (n*r);
	        n--;
	        r--;
	    }
	    
	    cout<<c<<endl;
	}
	return 0;
}

/**********

Element that appears once where every element occurs twice

*************/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i;
	    cin>>n;
	    int arr[n];
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int r = arr[0];
	    for(i=1;i<n;i++){
	        r = r ^ arr[i];
	    }
	    cout<<r<<endl;
	}
	return 0;
}

/**********

Angle between hour and minute hand

***********/
#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        double n,m;
        cin>>n>>m;
        if(n==12) n=0;
        if(m==60) m=0;
        
        double h = (n*60 + m)*0.5;
        double k = m*6;
        
        double ang = abs(h-k);
        double ang2 = (360-ang);
        if(ang<ang2) cout<<(int)ang;
        else cout<<(int)ang2;
        cout<<endl;
    }
	return 0;
}

/***************

Sieve of Eratosthenes & Return two prime numbers

Given an even number (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only first such pair.

**********/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,p,i;
        cin>>n;
        int check[n+1];

        //sieve
        for(i=2;i<=n;i++){
            check[i]=1;
        }
        
        for(p=2;p*p<=n;p++){
            if(check[p]==1){
                for(i=p*p;i<=n;i+=p){
                    check[i]=0;
                }
            }
        }
        
        //2 no
        for(i=2;i<n;i++){
            if(check[i] && check[n-i]){
                cout<<i<<" "<<(n-i)<<endl;
                break;
            }
        }
        
    }
    
	return 0;
}