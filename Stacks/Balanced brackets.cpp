#include <iostream>
#include <stack>
using namespace std;

string isBalanced(string s) {
    stack<char> s1;
    long l = s.length(),i;
    for(i=0;i<l;i++){
      if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
          s1.push(s[i]);
          continue;
      }
      if(s1.empty()) {return "not balanced";}

      else if (s[i] == ')'){
          char x = s1.top();
          s1.pop();
          if(x=='[' || x=='{') {return "not balanced";}
      }
      else if (s[i] == '}') {
        char x = s1.top();
        s1.pop();
        if (x == '[' || x == '(') {return "not balanced";}
      } 
      else if (s[i] == ']') {
        char x = s1.top();
        s1.pop();
        if (x == '{' || x == '(') {return "not balanced";}
      }
    }
    string rs;
    if(s1.empty()){
        rs =  "balanced";
    }
    else rs = "not balanced";
    return rs;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }

    return 0;
}
