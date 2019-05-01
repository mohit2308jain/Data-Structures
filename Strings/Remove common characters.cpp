/*****************************************

Given two strings s1 and s2. 
Modify string s1 such that all the common characters of s1 and s2 is to be removed and
the uncommon characters of s1 and s2 is to be concatenated.

Example:
Input:
2
aacdb
gafd
abcs
cxzca

Output:
cbgf
bsxz

*****************************************************/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int i;
        string s1,s2,res="";
        cin>>s1>>s2;
        int c1[26]={0},c2[26]={0};
        for(i=0;i<s1.length();i++){
            c1[s1[i]-'a']++;
        }
        for(i=0;i<s2.length();i++){
            c2[s2[i]-'a']++;
        }
        
        for(i=0;i<s1.length();i++){
            if(c1[s1[i]-'a']>0 && c2[s1[i]-'a']==0){
                res += s1[i];
            }
        }
        
        for(i=0;i<s2.length();i++){
            if(c2[s2[i]-'a']>0 && c1[s2[i]-'a']==0){
                res += s2[i];
            }
        }
        
        if(res!=""){
            cout<<res;
        }
        else{
            cout<<"-1";
        }
        cout<<endl;
    }
    
	return 0;
}
