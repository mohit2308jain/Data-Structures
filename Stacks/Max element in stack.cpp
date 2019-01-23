#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

class StackWithMax 
{  
    stack<int> mainStack; 
    stack<int> trackStack; 
    public: 
    void push(int x){ 
        mainStack.push(x); 
        if (mainStack.size() == 1) 
        { 
            trackStack.push(x); 
            return; 
        } 
  
        if (x > trackStack.top()) 
            trackStack.push(x); 
        else
            trackStack.push(trackStack.top()); 
    } 
  
    int getMax(){ 
        return trackStack.top(); 
    } 
  
    int pop(){ 
        mainStack.pop(); 
        trackStack.pop(); 
        return 0;
    } 
}; 

int main() 
{
    StackWithMax s; 
    int n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b;
            s.push(b);
            
        }
        else if(a==2)
        {
            s.pop();
            
        }
        else if(a==3)
        {
            cout << s.getMax() << endl;
        }
    }
    
    
    return 0; 
} 

