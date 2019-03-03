#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
template <class T>
struct node{
    T x;
    struct node* next;
};
template <class T>
void push(struct node<T>** stack,T d){
    struct node<T>* temp=(struct node<T>*)malloc(sizeof(struct node<T>));
    temp->x=d;
    temp->next=*stack;
    *stack=temp;
}
template <class T>
struct node<T>* pop(struct node<T>* stack){
    struct node<T>* p;
    p=stack;
    stack=stack->next;
    delete(p);
    p=NULL;
    return stack;
}
template <class T>
void print(struct node<T> *stack){
    struct node<T>* p;
    p=stack;
    while(p!=NULL){
        cout<<p->x<<" ";
        p=p->next;
    }
}
template <class T>
bool empty(struct node<T>* stack){
    if(stack==NULL) return true;
    
    return false;
}
template <class T>
T top(struct node<T>* stack){
    if(empty(stack)) return 0;
    else{
        T jj=stack->x;
        return(jj);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    struct node<int>* stack=NULL;
    
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    print(stack);
    cout<<endl<<top(stack);
    stack=pop(stack);
    cout<<endl<<top(stack);
    stack=pop(stack);
    cout<<endl<<top(stack);
    stack=pop(stack);
    
    struct node<double>* stack1=NULL;
    push(&stack1,1.2);
    push(&stack1,2.2);
    push(&stack1,3.2);
    cout<<endl;
    print(stack1);
    cout<<endl<<top(stack1);
    stack1=pop(stack1);
    cout<<endl<<top(stack1);
    stack1=pop(stack1);
    cout<<endl<<top(stack1);
    stack1=pop(stack1);
    
    struct node<char>* stack2=NULL;
    push(&stack2,'a');
    push(&stack2,'b');
    push(&stack2,'c');
    cout<<endl;
    print(stack2);
    cout<<endl<<top(stack2);
    stack2=pop(stack2);
    cout<<endl<<top(stack2);
    stack2=pop(stack2);
    cout<<endl<<top(stack2);
    stack2=pop(stack2);
    
    return 0;
}
