int _stack :: getMin()
{
   //Your code here
   if(s.empty()){
       return -1;
   }
   else{ 
       return minEle;
   }
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty()){
       return -1;
   }
   int i,to = s.top();
   s.pop();
   if(to < minEle){
       i=minEle;
       minEle = 2*minEle - to;
   }
   else{
       i=to;
   }
   return i;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
       s.push(x);
       minEle = x;
   }
   else if(x < minEle){
       s.push(2*x - minEle);
       minEle = x;
   }
   else s.push(x);
}
