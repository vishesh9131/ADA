#include <iostream>

using namespace std;

void fib(int n){
    int res=1; 
    int ans[n];
    ans[0]=ans[1]=1;
    cout<<"1"<<" "<<"1"<<" ";
for(int i = 2; i<n ; i++){
    ans[i]=ans[i-1]+ans[i-2];
    cout<<ans[i]<<" ";
}
}

int fact(int n){
if(n<=0)return 1;
return n*fact(n-1);
}

void prime(int n) {
    for (int i = 1; i < n; i++) {
        if (!(n%i==0)) {  
            cout << i << " ";  
        }
    }
}

int main(){
    int n=50;
prime(n);

    return 0;
}
