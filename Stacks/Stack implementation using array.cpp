#include<bits/stdc++.h> 
using namespace std; 
#define MAX 1000 
template <class T>
class Stack 
{ 
	int top; 
    public: 
	T a[MAX]; //Maximum size of Stack 

	Stack() { top = -1; } 
    
	bool push(T x){
      if(top>=(MAX-1)){
        cout<<"Stack Overflow";
      }
      else{
        a[++top] = x;
        cout<<x<<" pushed to the stack"<<endl;
        return true;
      }
    }
    
	T pop(){
      if(top<0){
        cout<<"Stack Underflow";
      }
      else{
        T c = a[top--];
        return c;
      }
    }
    
	bool isEmpty(){
      return (top<0);
    } 
}; 
 
int main() 
{ 
	class Stack<int> s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	cout<<s.pop() << " Popped from stack\n"; 
    
    class Stack<double> s1; 
	s1.push(10.1); 
	s1.push(20.1); 
	s1.push(30.1); 
	cout<<s1.pop() << " Popped from stack\n"; 
    
    class Stack<char> s2; 
	s2.push('a'); 
	s2.push('b'); 
	s2.push('c'); 
	cout<<s2.pop() << " Popped from stack\n"; 

	return 0; 
} 
