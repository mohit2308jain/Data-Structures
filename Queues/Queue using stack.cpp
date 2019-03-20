/* enqueue operation costlt of O(n) */

#include<iostream>
#include<stack>
using namespace std;
class Queue{
	stack<int> s1,s2;
	public:
	void enqueue(int x){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dequeue(){
		if(s1.empty()){
			return -1;
		}
		int x = s1.top();
		s1.pop();
		return x;
	}
};
int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	cout<<q.dequeue()<<endl;
	cout<<q.dequeue();
}

/* dequeue operation costlt of O(n) */

#include<iostream>
#include<stack>
using namespace std;
class Queue{
	stack<int> s1,s2;
	public:
	void enqueue(int x){
		s1.push(x);
	}
	int dequeue(){
		if(s1.empty() && s2.empty()){
			cout<<"Q is empty";
			return -1;
		}

		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}

		int x = s2.top();
		s2.pop();
		return x;
	}
};
int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(3);
	q.enqueue(2);
	q.enqueue(4);

	cout<<q.dequeue();
	cout<<q.dequeue();
	
	return 0;
}