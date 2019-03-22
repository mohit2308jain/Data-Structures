#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void print(queue<int> q){
	while(!q.empty()){
	    cout<<q.front()<<" ";
	    q.pop();
	}
}

/* mormal approach */
void reverse(queue<int> &q){
	stack<int> s;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

/* recursive approach */
void reverse(queue<int> &q){
	if(q.empty()) return;

	int d = q.front();
	q.pop();

	reverse(q);

	q.push(d);
}

int main(){
	queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	reverse(q1);
	print(q1);
}
