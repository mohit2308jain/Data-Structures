#include <bits/stdc++.h> 
using namespace std;

stack<int> s;

void insert(int c){
	if(s.empty()) s.push(c);

	else{
		int x=s.top();
		s.pop();

		insert(c);
		s.push(x);
	}
} 
void reverse(){
	if(s.size()>0){
		int c = s.top();
		s.pop();
		reverse();

		insert(c);
	}
}
int main()
{
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
  cout<<"Original"<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	reverse();

  cout<<endl<<"Reversed"<<endl;
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
	return 0;
}
