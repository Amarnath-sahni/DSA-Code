#include<iostream>
#include<stack>
using namespace std;

int main(){
   stack<int>st;
   st.push(1);
   st.push(2);
   st.push(4);
   cout<<st.top()<<endl;
   st.push(23);
   st.push(6);
   cout<<st.top()<<endl;
   st.pop();
   st.pop();
   st.pop();
   cout<<st.top()<<"\n";
   cout<<st.empty()<<"\n";


    return 0;
}


#include<iostream>
#define n 100
using namespace std;
class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr = new int[n];
        top=-1;    
    }

    void push(int x){
        if(top==n-1){
            cout<<"stack arre overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"elemet are underflow\n";
            return;
        }
        top--;
    }

    int gettop(){
       if(top==-1){
            cout<<"elemet are underflow or no elment in stack\n";
            return -1;
        } 
        return arr[top];

    }
    bool empty(){
        return top==-1;
    }
};

int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.gettop()<<endl;
    st.pop();
    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.gettop()<<endl;
    st.pop();
    cout<<st.gettop()<<endl;
    st.pop();
    cout<<st.gettop()<<endl;
    return 0;
    
}
//output 
// 3
// 0
// 1
// elemet are underflow or no elment in stack
// -1
// elemet are underflow
// elemet are underflow or no elment in stack
// -1

//prefix evaluation ans=25
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
int prefixEvalution(string s){
    stack<int>st;
    for (int i=s.length()-1; i>=0; i--)
    {
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
            st.push(op1+op2);
                break;

             case '-':
            st.push(op1-op2);
                break;

            case '*':
            st.push(op1*op2);
                break;

            case '/':
            st.push(op1/op2);
                break;
            
            case '^':
            st.push(pow(op1,op2));
                break;
            }
        }
    }
 return st.top(); 
}
int main(){
    cout<<prefixEvalution("-+7*45+20")<<endl;
    return 0;
}

//infix to postfix
#include<iostream>
#include<stack>
using namespace std;

int prec(char c){
    if (c=='^')
    {
       return 3;
    }
    else if(c=='*'|| c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }else{
        return -1;
    } 
}

string infixToPostfix(string s){
    stack<char>st;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]>='a' && s[i]<='z'|| s[i]>='A' && s[i]<='Z'){
            res+=s[i];
        }
        else if(s[i]=='('){
         st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
        
        }
        else{
            while (!st.empty() && prec(st.top())>prec(s[i])){
             res+=st.top();
             st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res+= st.top();
        st.pop();
    }
   return res;
    
}
int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}
//output -> abc/-ak/l-(*(