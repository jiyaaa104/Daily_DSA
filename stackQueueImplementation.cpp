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
// #include<bits/stdc++.h>
// using namespace std;
// class LinearQueue{
//     public:
//   int front=-1,rear=-1,currSize=0;
//   int q[5];
//   void push(int value){
//     if(rear==4){
//         cout<<"Queue Overflow!"<<endl;
//         return;
//     }
//     if(front==-1){
//         front=rear=0;
//     }else{
//         rear++;
//     }
//     currSize++;
//     q[rear]=value;
//   }
//   void pop(){
//     if(front==-1){
//         cout<<"Queue underflow!"<<endl;
//         return;
//     }
//     front++;
//     currSize--;
//     if(front>rear){
//         front=rear=-1;
//     }
//   }
//   void top(){
//     if(front==-1) {
//         cout<<"Queue is empty. No element at top!"<<endl;
//         return;
//     }
//     cout<<"Top : "<<q[front]<<endl;
//   }
//   void size(){
//     cout<<"Size : "<<currSize<<endl;
//   }
// };
// class CircularQueue{
//     public:
//    int front=-1,rear=-1,currSize=0;
//    int q[5];
//    void push(int value){
//       if(((rear+1)%5)==front){
//          cout<<"Queue Overflow!"<<endl;
//          return;
//       }
//       if(front==-1){
//         front=rear=0;
//       }else{
//         rear=(rear+1)%5;
//       }
//       q[rear]=value;currSize++;
//    }
//    void pop(){
//      if(front==-1){
//         cout<<"Oueue Underflow"<<endl;
//         return;
//      }else if(front == rear){
//         front=rear=-1;
//      }else{
//         front=(front+1)%5;
//      }
//      currSize--;
//    }
//    void top(){
//     if(front==-1){
//         cout<<"No element in the queue!"<<endl;return;
//     }
//     cout<<"Top : "<<q[front]<<endl;
//    }
//    void size(){
//     cout<<"size : "<<currSize<<endl;
//    }
// };
// int main(){
//   CircularQueue q;
//    q.push(1);
//    q.push(21);
//    q.push(12);
//    q.push(13);
//    q.push(123);
// //    q.push(90);
//    q.top();
//    q.size();
//    q.pop();
//    q.pop();
//     q.top();
//    q.size();
//    q.pop();
//    q.pop();
//    q.top();
//    q.pop();
//    q.top();
//    q.pop();
// }


//IMPLEMENTATION OF STACK USING LINKED LIST
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int val;
//     Node* next;
//     Node(int val1,Node* next1){
//         val=val1;
//         next=next1;
//     }
//     Node(int val1){
//         val=val1;
//         next=nullptr;
//     }
//     Node(){
//         val=0;
//         next=nullptr;
//     }
// };
// class Stack{
//   public:
//   Node* top=nullptr;
//   int size=0;
//   void push(int value){
//     Node* newNode=new Node(value);
//     newNode->next=top;
//     top=newNode;
//     size++;
//   }
//   void pop(){
//     if(top==nullptr){
//         cout<<"Queue Underflow!"<<endl;
//         return;
//     }
//     Node* deleteNode=top;
//     top=top->next;
//     delete deleteNode;
//     size--;
//   }
//   void peek(){
//     if(top==nullptr){
//         cout<<"No element in queue!"<<endl;
//         return;
//     }
//     cout<<"Top : "<<top->val<<endl;
//   }
//   void Size(){
//     cout<<"Size : "<<size<<endl;
//   }
//   bool empty(){
//     if(top==nullptr){
//         cout<<"TRUE!"<<endl;
//     }else{
//         cout<<"FALSE!"<<endl;
//     }
//   }
// };
// class Queue{
//     public:
//   Node* front =nullptr;
//   Node* rear= nullptr;int size=0;
//   void push(int value){
//     Node* newNode=new Node(value);
//     if(front==nullptr){
//       front=newNode;
//       rear=newNode;
//     }else{
//         Node* prev=rear;
//         prev->next=newNode;
//         rear=newNode;
//     }
//     size++;
//   }
//   void pop(){
//     if(front==nullptr){
//         cout<<"Queue underflow"<<endl;
//         return;
//     }
//     Node* delNode=front;
//     if(front->next==nullptr){
//        front=nullptr;
//        rear=nullptr;
//     }else{
//         front=front->next;
//     }
//     delete delNode;
//     size--;
//   }
//   void peek(){
//     if(front==nullptr){
//         cout<<"No element in queue!"<<endl;return;
//     }
//     cout<<"Top : "<<front->val<<endl;
//   }
//   void Size(){
//     cout<<"Size : "<<size<<endl;
//   }
// };
// int main(){
//     Queue q;
//    q.push(10);
//    q.push(20);
//    q.push(30);
//    q.pop();
//    q.Size();
//    q.peek();
//     return 0;
// }

//IMPLEMENTING STACK USING QUEUE
#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
   queue<int>q;
   void push(int value){
    int s=q.size();
    q.push(value);
    for(int i=0;i<s;i++){
      q.push(q.front());
      q.pop();
    }
   }
   void pop(){
    if(q.empty()){
      cout<<"Stack Underflow "<<endl;
      return;
    }
    q.pop();
   }
   void top(){
    if(q.size()==0){
      cout<<"No element in queue"<<endl;
      return;
    }
    cout<<"Front : "<<q.front()<<endl;
   }
   void size(){
    cout<<"Size : "<<q.size()<<endl;
   }
};
//IMPLEMENTNG QUEUE USING 2 STACKS
//APPROACH 1 : IN THIS THE PUSH OPERATION IS COSTLIER WHEN COMAPARED TO TOP,POP,ETC
class Queue1{
  public:
  stack<int>s1;
  stack<int>s2;
  void push(int val){
    while(s1.size()){
      s2.push(s1.top());s1.pop();
    }
    s1.push(val);
    while(s2.size()){
      s1.push(s2.top());
      s2.pop();
    }
  }
  int pop(){
    if(s1.empty()){
      cout<<"Queue Underflow"<<endl;return -1;
    }
    int t=s1.top();
    s1.pop();
    return t;
  }
  int Top(){
   if(s1.empty()){
    cout<<"Queue is empty"<<endl;return -1;
   }
   return s1.top();
  }
  void Size(){
    cout<<"Size : "<<s1.size()<<endl;
  }
};
int main(){
  return 0;
}