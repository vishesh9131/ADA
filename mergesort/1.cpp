#include <iostream>
using namespace std;

void m(int arr[],int l,int m, int r);
void ms(int arr[], int l, int r){
	if(l<r){
	int mid = l+(r-l)/2;
	ms(arr, l, mid);
	ms(arr,mid+1,r);
	m(arr,l,mid,r);

	}
}
void m(int arr[],int l,int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int arr1[n1],arr2[n2];
	for(int i = 0 ; i < n1 ; i++){arr1[i]=arr[ l+i ]; }
	for(int i = 0 ; i < n2 ; i++){arr2[i]=arr[m+i+1]; }

	int i = 0, j = 0; int k = l;
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			arr[k]=arr1[i];
			i+=1;
		}else{
			arr[k]=arr2[j];
			j+=1;
		}
	 k+=1;
	}
	while(i<n1){
	arr[k]=arr1[i];
	i+=1;
	k+=1;
	}
	while(j<n2){
	arr[k]=arr2[j];
	j+=1;k+=1;
	}
}
void pa(int arr[],int size){
	for(int i=0; i<size; i++){ cout<<arr[i]<<" , ";}
	cout<<endl;
}

int main(){
	// main body
	int n=0;
	cout<<"cardin of arr : ";
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++){
		cout<<"enter "<<i<<" element : ";
		cin>>arr[i];
	}
	ms(arr,0,n-1);
	pa(arr,n);

	return 0;
}

