#include <bits/stdc++.h>
using namespace std;
bool prec(char c){
	if(c=='^' || c=='/' || c=='*' || c=='+' || c=='-') return true;
	else return false;

}
void converttopostfix(string s){
	stack<string> s1;
	int l=s.length();
	
	for(int i=0;i<l;i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			s1.push(string(1,s[i]));
		}
		else if(prec(s[i])){
			string op1 = s1.top();
			s1.pop();

			string op2 = s1.top();
			s1.pop();

			string res = "(" + op2 + s[i] + op1 + ")";
			s1.push(res);
		}
	}
	cout<<s1.top();
}


int main(){
	string exp = "ab*c+";
	converttopostfix(exp);

	return 0;
}