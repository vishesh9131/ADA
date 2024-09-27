#include <iostream>
#include<stack>
using namespace std;
class Queue{
private:
        stack <int> s1;    
        stack <int> s2;

public:
    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"kahli hai";
        }
        if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop(); 
    }            
        }

        int x = s2.top();
        s2.pop();
        return x;

    }

    void enqueue(int x){
        s1.push(x);
    }
};


int main()
{
Queue q;
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
cout<<q.dequeue()<<endl <<q.dequeue()<<endl<<q.dequeue()<<endl ;
return 0;
}