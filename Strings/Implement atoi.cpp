//*********************************************************

Implement atoi

*************************************************************************/
int atoi(string str)
{
    //Your code here
    int i,f=0,dig=0,g=1;
    for(i=0;i<str.length();i++){
        if(str[i]=='-'){
            g=0;
            continue;
        }
        else if(isdigit(str[i])){
            dig = dig*10 + (str[i]-'0');
        }
        else{
            f=1;
            break;
        }
    }
    if(f==1) return -1;
    else if(f==0 && g==0) return (dig-(2*dig));
    else return dig;
}
