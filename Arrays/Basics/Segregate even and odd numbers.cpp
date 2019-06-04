
#include<iostream>
using namespace std;

// Time complexity = O(n/2) and space complexity = O(n) 
void seg(int arr[],int n){
	int b[n];

	int k=0,l=n-1,i,j;
	for(i=0,j=n-1;i<j;i++,j--){
		if(arr[i]%2==0){
			b[k++]=arr[i];
		}
		else{
			b[l--] = arr[i];
		}

		if(arr[j]%2==0){
			b[k++]=arr[j];
		}
		else{
			b[l--]=arr[j];
		}
	}

	// for odd length

	b[i]=arr[i];
	
	for(i=0;i<n;i++){
	    cout<<b[i]<<" ";
	}
	cout<<endl;
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

// Time complexity = O(n) and space complexity = O(1)
void seg1(int arr[],int n){
	int i=-1,j=0;
	while(j != n){
		if(arr[j]%2==0){
			i++;

			swap(arr[i],arr[j]);
		}
		j++;
	}
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
	
	print(arr,n);
	seg1(arr,n);
	print(arr,n);
}
