#include<iostream>
using namespace std;
int main(){
	string s;
	int i,j,n = s.length();
	if(n%2==0) cout<<"not possible";
	else{
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j || j+i==n-1) cout<<s[i];
				else cout<<" ";
			}
		}
	}
	return 0;
}