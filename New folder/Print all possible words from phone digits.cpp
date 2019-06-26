#include <iostream>
#include <cstring>
using namespace std;
const char ll[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
void printutil(int arr[],int c,char res[],int n){
    int i;
    if(c==n){
        cout<<res<<" ";
        return;
    }
    for(i=0;i<strlen(ll[arr[c]]);i++){
        res[c] = ll[arr[c]][i];
        printutil(arr,c+1,res,n);
        
        if(arr[c]==0 || arr[c]==1) return;
    }
}

void print(int arr[],int n){
    char res[n+1];
    res[n]='\0';
    printutil(arr,0,res,n);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
        print(arr,n);
        cout<<endl;
    }
    
	return 0;
}