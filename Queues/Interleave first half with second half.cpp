/********************************
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Only a stack can be used as an auxiliary space.

Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20
**************************************************/



#include<iostream>
#include<stack>
#include <queue>
using namespace std;
void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
void interleave(queue<int> &q){
	stack<int> s;
	if(q.size()%2 != 0)
		cout<<"Queue shoule be of even length";
	else{
		int k = q.size()/2;
		for(int i=0;i<k;i++){
			s.push(q.front());
			q.pop();
		}
		while(!s.empty()){
			q.push(s.top());
			s.pop();
		}
		for(int i=0;i<k;i++){
			q.push(q.front());
			q.pop();
		}
		for(int i=0;i<k;i++){
			s.push(q.front());
			q.pop();
		}
		while(!s.empty()){
			q.push(s.top());
			s.pop();
			q.push(q.front());
			q.pop();
		}
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

	interleave(q);
	print(q);

	return 0;
}