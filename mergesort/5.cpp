#include<iostream>
using namespace std;
void m(int arr[],int l,int r, int m){
	int s1= m-l+1;
	int s2= r-m;
	int n1[s1];  //partition1
	int n2[s2];  //partition2
	
	int k =l;

	//fill elem in n1 and n2
	for(int i = 0 ; i<s1 ; i++){
		n1[i]=arr[k];
		k++;
	}
	for(int i = 0 ; i < s2 ; i++){
		n2[i]=arr[k];
		k++;
	}

	//sort
	int i = 0, j=0;
    k=l;
	while(i<s1 && j<s2){
		if(n1[i] <= n2[j]){arr[k]=n1[i]; i++;}
		else{arr[k]=n2[j]; j++;}
		k++;
	}
	while(i < s1){arr[k]=n1[i]; k++; i++;}
	while(j < s2){arr[k]=n2[j]; k++; j++;}

}

void ms(int arr[], int l, int r){
   if(l==r){return;} 
   if(l<r){
        int mid= l + (r-l)/2;
        ms(arr,l,mid);    //trust
        ms(arr,mid+1,r); //trust
        m(arr,l,r,mid);
    }
}

int main(){
    int i=0;
    int arr[5]={3,4,52,2,5};
    ms(arr, 0, 4);
    while(i<=4){	cout<<arr[i]<<" ";i++;	}
    return 0;
    }
