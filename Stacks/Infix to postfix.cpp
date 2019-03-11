#include<iostream>
#include<stack>
using namespace std;
int prec(char c){
	if(c=='^') return 2;
	else if(c=='/' || c=='*') return 1;
	else if(c=='+' || c=='-') return 0;
	else return -1;

}
void convert(string s){
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
	cout<<"Postfix = "<<res;
}
int main(){
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	convert(exp);

	return 0;
}