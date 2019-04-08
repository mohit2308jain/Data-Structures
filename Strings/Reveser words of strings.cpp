#include<bits/stdc++.h> 
using namespace std;
string reversewords(string s){
    int i,n=s.length(),k=0,c=0,max=0;
    for(i=0;i<n;i++){
        if(s[i]!=' ') c++;
        if(s[i]==' '){
            k++;
            if(max==0) max = c;
            if(max<c) max=c;
            c=0;
        }
    }
    k++;
    int j=0,l=0;
    string d;
    char r[k][max+1];
    for(i=0;i<n;i++){
        if(s[i]==' '){
            r[j][l]='\0';
            j++;
            l=0;
        }
        else{
            r[j][l]=s[i];
            l++;
        }
    }
    r[j][l]='\0';
    for(i=k-1;i>=0;i--){
        d += r[i];
        if(i!=0) d += ' ';
    }
    return d;
}
int main() {
    int t;
    cin>>t;
    string s;
    
    for(int i=0;i<=t;i++){
    	getline(cin,s,'\n');
    	if(s.length()!=0) cout<<reversewords(s)<<endl;
    }
    
	
	return 0;
}