#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        string st;
        cin>>st;
        int res;
        stack<int> s;
        int a,b;
        for(int i=0;i<st.length();i++)
        {
            if(st[i]>='0'&&st[i]<='9')
            s.push(st[i]-'0');
            else if(st[i]=='+')
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = a+b;
                s.push(res);
            }
            else if(st[i]=='-')
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = b-a;
                s.push(res);
            }
            else if(st[i]=='*')
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = a*b;
                s.push(res);
            }
            else if(st[i]=='/')
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                res = b/a;
                s.push(res);
            }
        }
        cout<<s.top()<<endl;
    }
    return 0;
}