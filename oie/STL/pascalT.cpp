#include <iostream>
using namespace std;

// fact
int fact(int n) {
    if (n < 0) {
        return -1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// nCr
int comb(int n,int r){
    if(n<r) cout<<"";
    return (fact(n)/(fact(r)*fact(n-r)));
}

// pascalT
void pascal_T(int l){
    cout<<"1"<<endl;
    for(int i =1; i<=(l-1); i++){
         for (int j = 1; j <= l - i; j++) {
                cout << " ";
            }
        for(int j =0; j<=(l-1); j++){
            cout<<comb(i,j);
        }cout<<endl;
    }
}

int main(){
    pascal_T(5);
return 0;
}