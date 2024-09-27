#include <iostream>
#include<vector>
using namespace std;
// Problem Statement: Write a C++ function that reverses 
// the elements of a vector of integers in place. The function 
// should not use any additional vectors or arrays.
int main(){
vector<int> arr;
arr.push_back(1);
arr.push_back(11);
arr.push_back(111);
arr.push_back(1111);
arr.push_back(11111);

int size = arr.size();

for(int i=size; i>0; i--){
    cout<<arr[i]<<endl;
}
    return 0;
}
