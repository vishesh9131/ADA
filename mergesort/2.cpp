#include<iostream>
using namespace std;

void m(int arr[],int l,int mid, int r){
	int n1= mid-l+1;
	int n2= r-mid;
	int arrL[n1],arrR[n2];

	//copying arr to temp arry
	for(int i =0 ; i<n1;i++){arrL[i]=arr[l+i];}
	for(int i =0 ; i<n2;i++){arrR[i]=arr[mid+1+i];}

	//merging <-- main part of conquer
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(arrL[i]<arrR[j]){
			arr[k]=arrL[i];
			i+=1;
		}else{
			arr[k]=arrR[j];
			j+=1;
		}k+=1;
	}

	//now we write code for remaining element...
	while(i<n1){
	arr[k]=arrL[i]; i+=1;k+=1;	
	}
	while(j<n2){
	arr[k]=arrR[j]; j+=1;k+=1;	
	}	
}

int pa(int arr[], int size){
	for(int i = 0 ; i<size; i++){
		if(i>=1){
			cout<<" , ";}
	        cout<<arr[i];
	}cout<<" ; ";cout<<endl;
	return 1;
}

void ms(int arr[], int l,int r){
    if(l<r){
	int mid = l + (r-l)/2;
	ms(arr,l,mid);
	ms(arr,mid+1,r);
	m(arr,l,mid,r); //used for merging         
    }

}

int main(){
	int list[10]={123,2134,2345,2134,1,3,4,24,12,45};
	ms(list,0,9);
	pa(list,10);

	return 0;
}
