//IMPLEMENTAION OF STACK USING ARRAY
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public: 
   int top=-1;
   int stack[10];
   void push(int value){
    if(top==9){
        cout<<"Stack Overflow!"<<endl;
        return;
    }
    top++;
    stack[top]=value;
   }
   void pop(){
    if(top==-1){
        cout<<"Stack underflow!"<<endl;
        return;
    }
    top--;
   }
   void topEl(){
     if(top==-1){
        cout<<"Stack is empty. No element at top."<<endl;
        return;
     }
     cout<<"Top : "<<stack[top]<<endl;
   }
   void size(){
    cout<<"size : "<<top+1<<endl;
   }
};
int main(){
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.topEl();
  s.pop();
  s.topEl();
  s.pop();
  s.pop();
  s.topEl();
  s.pop();
  s.topEl();
}
