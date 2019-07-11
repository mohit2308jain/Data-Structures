#include <iostream>
#include <algorithm>
using namespace std;
void merge(int arr[],int l,int m,int n,int r){
	int i=l;
	int j=n;
	int k=0;

	int temp[50];

	while(i<=m && j<=r){
		if(arr[i]<arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}

	while(i<=m){
		temp[k++]=arr[i++];
	}
	while(j<=r){
		temp[k++]=arr[j++];
	}

	for(i=l,j=0;i<=r;i++,j++){
		arr[i]=temp[j];
	}
}
void mergeSort(int arr[],int l,int r){
	int m,n;
	if(l<r){
		m = (l+r)/2;
		n=m+1;
		mergeSort(arr,l,m);
		mergeSort(arr,n,r);

		merge(arr,l,m,n,r);
	}
}
int main() {
	int n,i;
	cin>>n;
	int arr[n+1];
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}