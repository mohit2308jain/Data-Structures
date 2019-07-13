#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i,j,k,n = s.length();
	if(n%2==0) cout<<"not possible";
	else{
		for(i=0;i<n;i++){
		    k = n-1-i;
			for(j=0;j<n;j++){
				if(j==i || j==k) cout<<s[i];
				else cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
/**********************

Example - 
program

p     p
 r   r 
  o o  
   g   
  r r  
 a   a 
m     m

*******************/


#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i,j,k,n = s.length();
	if(n%2==0) cout<<"not possible";
	else{
		for(i=0;i<n;i++){
		    k = n-1-i;
			for(j=0;j<n;j++){
				if(j==i || j==k) cout<<s[j];
				else cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}

/**********************

Example - 
program

p     m
 r   a 
  o r  
   g   
  o r  
 r   a 
p     m

***************/

#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i,j,k,n = s.length();
	if(n%2==0) cout<<"not possible";
	else{
		for(i=0;i<n;i++){
		    k = n-1-i;
			for(j=0;j<n;j++){
				if(j==i || j==k) cout<<s[k];
				else cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
/**********************

Example - 
program

m     m
 a   a 
  r r  
   g   
  o o  
 r   r 
p     p

***************/
