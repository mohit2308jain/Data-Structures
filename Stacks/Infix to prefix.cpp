#include <bits/stdc++.h>
using namespace std;
int prec(char c){
	if(c=='^') return 2;
	else if(c=='/' || c=='*') return 1;
	else if(c=='+' || c=='-') return 0;
	else return -1;

}
string converttopost(string s){
	stack<char> s1;
	int l=s.length();
	string res;
	s1.push('$');
	for(int i=0;i<l;i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
			res += s[i];

		else if(s[i]=='(')
			s1.push('(');

		else if(s[i]==')'){
			while(s1.top()!='$' && s1.top()!='('){
				char c = s1.top();
				s1.pop();
				res += c;
			}
			if(s1.top() == '(')
				s1.pop();
		}
		else{
			while(s1.top()!='$' && prec(s[i]) <= prec(s1.top())){
				char c = s1.top();
				s1.pop();
				res += c;
			}
			s1.push(s[i]);
		}
	}
	while(s1.top()!='$'){
		char c = s1.top();
		s1.pop();
		res += c;
	}
	return res;
}

void converttopre(string s){
    cout<<s<<endl;
    int l=s.length();
	reverse(s.begin(),s.end());
	
	for(int i=0;i<l;i++){
		if(s[i]=='('){ 
		    s[i]=')';
		    continue;
		}
		else if(s[i]==')'){
		    s[i]='(';
		    continue;
		}
 	}

 	cout<<s<<endl;

 	string res = converttopost(s);
 	reverse(res.begin(),res.end());

 	cout<<"Prefix = "<<res;
}
int main(){
	string exp = "(a-b/c)*(a/k-l)";
	converttopre(exp);

	return 0;
}
