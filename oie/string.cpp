#include <iostream>
#include<string>

using namespace std;

void rev(string s){
int size= s.size();
for(int i=size; i>=0;i--){
    cout<<s[i];
}cout<<endl;
}

int value(char s){
    if(s=='I'){
        return 1;
    }else if(s=='V'){
        return 5;
    }else if(s=='X'){
        return 10;
    }else if(s=='C'){
        return 100;
    }else if(s=='D'){
        return 500;
    }else if(s=='M'){
        return 1000;
    }return -1;
}

int R2I(string& s){
    int res=0;
    for(int i=0;i<s.length();i++){
        int s1 = value(s[i]);
        if(i+1 < s.length()){
            int s2=value(s[i+1]);
            if(s1>=s2){
                res+=s1;
            }else{
                res+= s2-s1;
                i++;
            }
        }else{
        res+=s1;
    }
    }
    return res;
}


int main(){
//roman to int 
string str="IX";
cout<<R2I(str);

    return 0;
}