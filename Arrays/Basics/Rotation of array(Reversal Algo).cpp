#include<iostream>
using namespace std;
void reverse(int arr[], int s, int e){
	while(s<e){
		int t = arr[s];
		arr[s] = arr[e];
		arr[e] = t;
		s++;
		e--;
	}
}

 void lrotate(int arr[],int n,int k){
 	reverse(arr,0,k-1);
 	reverse(arr,k,n-1);
 	reverse(arr,0,n-1);
 }

 void rrotate(int arr[] ,int n ,int k){
 	reverse(arr,0,n-k-1);
 	reverse(arr,n-k,n-1);
 	reverse(arr,0,n-1);
 }

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
	cin>>k;
	
	k = k%n;
	
	print(arr,n);
	lrotate(arr,n,k);
	print(arr,n);

	rrotate(arr,n,k);
	print(arr,n);

}
