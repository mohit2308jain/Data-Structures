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