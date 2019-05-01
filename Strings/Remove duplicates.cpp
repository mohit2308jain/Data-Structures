/****************************************************

Remove duplicates.

Example:
Input:
2
geeksforgeeks
geeks for geeks

Output:
geksfor
geks for

*******************************************************/

#include<iostream>
using namespace std;
void remove(string s){
    int c[26]={0},n=s.length(),i;
    int f=0;
    string r = "";
    for(i=0;i<n;i++){
        if(s[i]==' ' && f==0){
            r+=s[i];
            f=1;
        }
        else if(s[i]==' ' && f==1){
            continue;
        }
        else if(c[s[i]-'a']==0){
            r+= s[i];
            c[s[i]-'a']++;
        }
        else if(c[s[i]-'a']>0){
            continue;
        }
    }
    cout<<r<<endl;;
}
int main() {
    int t;
    cin>>t;
    while(t>-1){
        string s;
        getline(cin,s,'\n');
        if(s.length()!=0) remove(s);
        t--;
    }
    
	//code
	return 0;
}
