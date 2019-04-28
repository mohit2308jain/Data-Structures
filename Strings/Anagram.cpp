/***********************************************************************

Given two strings a and b consisting of lowercase characters.
The task is to check whether two given strings are anagram of each other or not.
An anagram of a string is another string that contains same characters, only the order of characters can be different.
For example, “act” and “tac” are anagram of each other.

**************************************************************************/
#include<iostram>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        long long i,c[26]={0},f=0;
        for(i=0;i<s1.length();i++){
            c[s1[i]-'a']++;
        }
        for(i=0;i<s2.length();i++){
            c[s2[i]-'a']--;
        }
        for(i=0;i<26;i++){
            if(c[i]!=0){
                f=1;
                break;
            }
        }
        if(f==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    
	//code
	return 0;
}
