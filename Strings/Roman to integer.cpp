/*********************************************************************************


Given an string in roman no format (s)  your task is to convert it to integer .

******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int rom(string s){
    map<char,int> roman;
    roman['I'] =1;
	roman['V'] =5;
	roman['X'] =10;
	roman['L'] =50;
	roman['C'] =100;
	roman['D'] =500;
	roman['M'] =1000;
	int n=0,i=0;
	if(s.length()<=1){
	    return roman[s.at(0)];
	}
	else{
	    while(i<s.size()){
	        if(roman[s[i]]<roman[s[i+1]]){
	            n += (roman[s[i+1]]-roman[s[i]]);
	            i += 2;
	        }
	        else{
	            n += roman[s[i]];
	            i++;
	        }
	    }
	    return n;
	}
}
int main() {
    int t;
    cin>>t;
    while(t!=0){
        string s;
        cin>>s;
        cout<<rom(s)<<endl;
        t--;
    }
    
	//code
	return 0;
}



