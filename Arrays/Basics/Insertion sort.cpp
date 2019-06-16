#include<iostream>
using namespace std;

void print(int arr[], int n){
 	for(int i=0;i<n;i++){
 		cout<<arr[i]<<" ";
 	}
 	cout<<endl;
 }

int main(){
	int n,k,i;
	cin>>n;
	int arr[n];
	
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for(i=1;i<n;i++){
		int t = arr[i];
		for(j=i-1;j>=0 && t<arr[j];j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=t;
	}

	print(arr,n);
}