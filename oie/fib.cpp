#include <iostream>

using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
return fib(n-1)+fib(n-2);
}
int countways(int s){return fib(s+1);}

int main(){

int s =4;
cout<<countways(s)<<endl;
    
    return 0;
}