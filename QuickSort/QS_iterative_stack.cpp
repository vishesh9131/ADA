#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

// /* This function takes last element as pivot, 
// places the pivot element at its correct 
// position in sorted array, and places 
// all smaller (smaller than pivot) to left 
// of pivot and all greater elements to 
// right of pivot */
// int partition(int arr[], int l, int h) 
// { 
//     int x = arr[h]; 
//     int i = (l - 1); 

//     for (int j = l; j <= h - 1; j++) { 
//         if (arr[j] <= x) { 
//             i++; 
//             swap(arr[i], arr[j]); 
//         } 
//     } 
//     swap(arr[i + 1], arr[h]); 
//     return (i + 1); 
// } 

// /* A[] --> Array to be sorted, 
// l --> Starting index, 
// h --> Ending index */
// void quickSort(int A[], int l, int h) 
// { 
//     if (l < h) { 
//         /* Partitioning index */
//         int p = partition(A, l, h); 
//         quickSort(A, l, p - 1); 
//         quickSort(A, p + 1, h); 
//     } 
// } 

// Driver code 
int main() 
{ 

char arr[5]={'a','b','c','d','\0'};
for(int k=0;k<strlen(arr);k++)
cout<<arr[k];
cout<<strlen(arr);

    return 0; 
} 