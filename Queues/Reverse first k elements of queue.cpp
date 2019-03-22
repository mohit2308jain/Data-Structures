#include<iostream>
#include <stack>
#include<queue>
using namespace std;
void print(queue<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}
void reverse(int k, queue<int> &q){
	if(k>q.size() || q.empty() || k<=0){
		return;
	}
	stack<int> s;
	for(int i=0;i<k;i++){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}

	for(int i=0;i<q.size()-k;i++){
		q.push(q.front());
		q.pop();
	}
}
int main(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	q.push(8);

	int k;
	cin>>k;
	reverse(k,q);
	print(q);

	return 0;
}