/**********************************************

IMPLEMENT STRSTR

****************************************/

int strstr(string s, string x)
{
     //Your code here
     int i,j=0,a=-1;
     int n=x.length();
     for(i=0;i<s.length();i++){
         if(s[i]==x[0]){
             for(j=0;j<n;j++){
                 if(s[i+j]!=x[j]){
                    break;
                 }
             }
             if(j==n){
                 a=i;
                 break;
             }
         }
     }
     if(a!=-1){
         return a;
     }else{
         return -1;
     }
     
}
