#include <iostream>
using namespace std;

void m(int arr[], int l , int mid, int r){
	int n0=mid - l+1;
	int n1= r-mid;
	int arrL[n0],arrR[n1];

	//copy elements
	for(int i = 0 ; i < n0 ; i++){arrL[i]=arr[l+i];}
	for(int i = 0 ; i< n1 ; i++){arrR[i]=arr[mid+1+i];}

	//merging ie conquering here...
	int i=0,j=0,k=l;
	while(i<n0 && j<n1){
		if(arrL[i]<= arrR[j]){
		arr[k]=arrL[i];
		i+=1;
		}else{
		arr[k]=arrR[j];
		j+=1;
		}k+=1;
	} 
	


	// Copy remaining elements
	while(i < n0) {
		arr[k] = arrL[i];
		i++;
		k++;
	}

	while(j < n1) {
		arr[k] = arrR[j];
		j++;
		k++;
	}


}
void ms(int arr[], int l, int r){
	if(l>=r) return;
	
	int mid = l+(r-l)/2;
	ms(arr, l, mid);
	ms(arr, mid+1, r);
	m(arr,l, mid, r);
}

void pa(int arr[],int size){
	for(int i = 0 ; i< size; i++){
	 cout<<arr[i]<<" ";	
	}cout<<endl;
}

int main(){
	int n=5;
	int arr[5]={12,324,43,1231,32543};
	ms(arr,0,n-1);
	pa(arr,n);

	return 0;
}
