// //IMPLEMENTAION OF STACK USING ARRAY
// #include<bits/stdc++.h>
// using namespace std;
// class Stack{
//     public: 
//    int top=-1;
//    int stack[10];
//    void push(int value){
//     if(top==9){
//         cout<<"Stack Overflow!"<<endl;
//         return;
//     }
//     top++;
//     stack[top]=value;
//    }
//    void pop(){
//     if(top==-1){
//         cout<<"Stack underflow!"<<endl;
//         return;
//     }
//     top--;
//    }
//    void topEl(){
//      if(top==-1){
//         cout<<"Stack is empty. No element at top."<<endl;
//         return;
//      }
//      cout<<"Top : "<<stack[top]<<endl;
//    }
//    void size(){
//     cout<<"size : "<<top+1<<endl;
//    }
// };
// int main(){
//   Stack s;
//   s.push(10);
//   s.push(20);
//   s.push(30);
//   s.push(40);
//   s.topEl();
//   s.pop();
//   s.topEl();
//   s.pop();
//   s.pop();
//   s.topEl();
//   s.pop();
//   s.topEl();
// }

//IMPLEMENTATION OF LINEAR AND CIRCULAR QUEUE  USING ARRAY
#include<bits/stdc++.h>
using namespace std;
class LinearQueue{
    public:
  int front=-1,rear=-1,currSize=0;
  int q[5];
  void push(int value){
    if(rear==4){
        cout<<"Queue Overflow!"<<endl;
        return;
    }
    if(front==-1){
        front=rear=0;
    }else{
        rear++;
    }
    currSize++;
    q[rear]=value;
  }
  void pop(){
    if(front==-1){
        cout<<"Queue underflow!"<<endl;
        return;
    }
    front++;
    currSize--;
    if(front>rear){
        front=rear=-1;
    }
  }
  void top(){
    if(front==-1) {
        cout<<"Queue is empty. No element at top!"<<endl;
        return;
    }
    cout<<"Top : "<<q[front]<<endl;
  }
  void size(){
    cout<<"Size : "<<currSize<<endl;
  }
};
class CircularQueue{
    public:
   int front=-1,rear=-1,currSize=0;
   int q[5];
   void push(int value){
      if(((rear+1)%5)==front){
         cout<<"Queue Overflow!"<<endl;
         return;
      }
      if(front==-1){
        front=rear=0;
      }else{
        rear=(rear+1)%5;
      }
      q[rear]=value;currSize++;
   }
   void pop(){
     if(front==-1){
        cout<<"Oueue Underflow"<<endl;
        return;
     }else if(front == rear){
        front=rear=-1;
     }else{
        front=(front+1)%5;
     }
     currSize--;
   }
   void top(){
    if(front==-1){
        cout<<"No element in the queue!"<<endl;return;
    }
    cout<<"Top : "<<q[front]<<endl;
   }
   void size(){
    cout<<"size : "<<currSize<<endl;
   }
};
int main(){
  CircularQueue q;
   q.push(1);
   q.push(21);
   q.push(12);
   q.push(13);
   q.push(123);
//    q.push(90);
   q.top();
   q.size();
   q.pop();
   q.pop();
    q.top();
   q.size();
   q.pop();
   q.pop();
   q.top();
   q.pop();
   q.top();
   q.pop();
}
