void SortedStack :: sort()
{
    stack<int> ttt;
    while(!s.empty()){
        int t = s.top();
        s.pop();
        while(!ttt.empty() && ttt.top()>t){
            s.push(ttt.top());
            ttt.pop();
        }
        ttt.push(t);
    }
    while(!ttt.empty()){
        cout<<ttt.top()<<" ";
        ttt.pop();
    }
}