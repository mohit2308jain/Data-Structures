stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    int mid = sizeOfStack/2;
    if(current == mid){
        s.pop();
        return s;
    }
    int t = s.top();
    s.pop();
    s=deleteMid(s,sizeOfStack,current+1);
    s.push(t);
    return s;
}