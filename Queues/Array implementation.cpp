#include<bits/stdc++.h> 
using namespace std; 
#define MAX 1000 
template <class T>
class Queue 
{ 
  int front, rear; 
  
  public: 
  T a[MAX]; //Maximum size of Stack 

  Queue() { 
    front = -1;
    rear = -1;
  } 
    
  bool enqueue(T x){

      if(front==-1){
        front++;
      }
      if(rear>=(MAX-1)){
        cout<<"Queue Overflow";
      }
      else{
        a[++rear] = x;
        cout<<x<<" pushed to the queue"<<endl;
        return true;
      }
    }
    
  T dequeue(){
      T d = a[front];
      front++;
      return (d);
    }

  void disp(){
    for(int i=front;i<=rear;i++){
      cout<<a[i]<<" ";
    }
  }
    
}; 
 
int main() 
{ 
  class Queue<int> s; 
  s.enqueue(10); 
  s.enqueue(20); 
  s.enqueue(30); 
  cout<<s.dequeue() << " Popped from stack\n"; 
  s.disp();
  cout<<endl;
    
    class Queue<double> s1; 
  s1.enqueue(10.1); 
  s1.enqueue(20.1); 
  s1.enqueue(30.1); 
  cout<<s1.dequeue() << " Popped from stack\n"; 
  s1.disp();
  cout<<endl;
    
    class Queue<char> s2; 
  s2.enqueue('a'); 
  s2.enqueue('b'); 
  s2.enqueue('c'); 
  cout<<s2.dequeue() << " Popped from stack\n"; 
  s2.disp();
  cout<<endl;

  return 0; 
} 