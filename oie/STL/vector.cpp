#include <iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);
    arr.push_back(10);

    for(auto i:arr)
    cout<<i+2<<"  ";
    
    return 0;
}