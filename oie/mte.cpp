#include <iostream>
#include <algorithm>
using namespace std;

int main(){
// int arr[5]={5,4,3,2,1};

// // selection sort
// for(int i = 0 ; i<5;i++){
//     int min=i;
//     for(int j = i+1 ; j<5;j++){
//         if(arr[j] < arr[min]){
//             swap(arr[j],arr[min]);
//         }
//     }
// }

// // insertion sort
// for(int i = 1 ; i<5;i++){
//     int j = i;
//     while(j>0 && arr[j-1]>arr[j]){
//         swap(arr[j-1],arr[j]);j--;
//     }
// }

// Bubble Sort
// for(int i = 1 ; i<5;i++){
//     for(int j = 0 ; j<5-i;j++)
//         if(arr[j] > arr[j+1])
//             swap(arr[j], arr[j+1]);
// }
int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int lakshya = 3; // Target value to search
    int low = 0;
    int high = n - 1;
    int ans = -1; // Initialize to -1 to indicate "not found"

    while(low <= high) {
        // Calculate mid to prevent potential overflow
        int mid = low + (high - low) / 2;

        if(arr[mid] == lakshya) {
            ans = mid; // Element found
            break;
        }
        else if(arr[mid] < lakshya) {
            low = mid + 1; // Search in the right half
        }
        else {
            high = mid - 1; // Search in the left half
        }
    }

    if(ans != -1) {
        cout << "Element found at index: " << ans << endl;
    }
    else {
        cout << "Element not found in the array." << endl;
    }
// print_module
// for(auto i : arr){
//     cout<<i<<" ";
// }
    
    return 0;
}