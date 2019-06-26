#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        stack<int> s1;
        int c=1,i;
        for(i=0;i<s.length();i++){
            if(s[i]=='('){
                cout<<c<<" ";
                s1.push(c);
                c++;
            }
            else if(s[i]==')'){
                int t = s1.top();
                s1.pop();
                cout<<t<<" ";
                
            }
        }
        cout<<endl;
    }

    return 0;
}
