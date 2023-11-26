#include<iostream>
#define n 100
using namespace std;

class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr=new int[n];
        front = -1;
        back =-1;

    }
    void push(int x){
     if(back==n-1){
        cout<<"queue overflow"<<endl;
        return;
     }
     back++;
     arr[back]=x;

     if(front==-1){
        front++;
     }
    }

    void pop(){
        if(front==-1 || front>back){
            cout<<"underflow"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
         cout<<"no element in queue"<<endl;
         return -1;
        }
        return arr[front];
        
    }

    bool empty(){
        if(front==-1 || front>back){
            cout<<"no element in queue"<<endl;
            return true;
        }

        return false;
    }
};
int main(){
    queue a;
   a.push(1);
   a.push(2);a.push(3);a.push(4);a.push(5);
   a.pop();
   a.pop();
    cout<< a.peek()<<" ";
   cout<<a.empty();
 
    return 0;
}
