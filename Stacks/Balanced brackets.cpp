#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> s1;
    long l = s.length(),i;
    for(i=0;i<l;i++){
      if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
          s1.push(s[i]);
          continue;
      }
      if(s1.empty()) {return "NO";}

      else if (s[i] == ')'){
          char x = s1.top();
          s1.pop();
          if(x=='[' || x=='{') {return "NO";}
      }
      else if (s[i] == '}') {
        char x = s1.top();
        s1.pop();
        if (x == '[' || x == '(') {return "NO";}
      } 
      else if (s[i] == ']') {
        char x = s1.top();
        s1.pop();
        if (x == '{' || x == '(') {return "NO";}
      }
    }
    string rs;
    if(s1.empty()){
        rs =  "YES";
    }
    else rs = "NO";
    return rs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
