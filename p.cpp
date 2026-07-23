#include<bits/stdc++.h>
using namespace std;
//IMPLEMENTING LINEAR STACK USING ARRAY
class Stack{
   public:
   int stack[10];int top=-1;
   void push(int value){
     if(top+1>=10){
        cout<<"Stack Overflow"<<endl;
        return;
     }
     top++;
     stack[top]=value;
   }
   void pop(){
    if(top==-1){
        cout<<"Stack Underflow!"<<endl;
        return;
    }
    top--;
   }
   void peek(){
     if(top==-1){
        cout<<"No element in stack"<<endl;
        return;
     }
     cout<<"Top : "<<stack[top]<<endl;
   }
   void size(){
    cout<<"size : "<<top+1<<endl;
   }
};
//IMPLEMENTING LINEAR QUEUE
class LinearQueue{
 public: 
   int q[5],front=-1,rear=-1,currSize=0;
   void push(int val){
    if(rear+1>=5){
        cout<<"Queue Overflow"<<endl;return;
    }
    if(front==-1){
        front=rear=0;
    }else{
        rear++;
    }
    currSize++;
    q[rear]=val;
   }
   void pop(){
    if(front==-1){
        cout<<"Queue Underflow"<<endl;
        return;
    }
    if(front==rear){
        front=rear=-1;
    }else{
         front++;
    }
    currSize--;
   }
   void peek(){
    if(front==-1){
        cout<<"No element at top"<<endl;
        return;
    }
    cout<<"Top : "<<q[front]<<endl;
   }
   void size(){
    cout<<"size : "<<currSize<<endl;
   }
};
class CircularQueue{
  int q[5],front=-1,rear=-1,currSize=0;
  void push(int val){
    if(currSize==5){
        cout<<"Queue Overflow"<<endl;return;
    }
    if(front==-1){
        front=rear=0;
    }else{
        rear=(rear+1)%5;
    }
    currSize++;
    q[rear]=val;
  }
  void pop(){
    if(currSize==0){
        cout<<"Queue Underflow"<<endl;return;
    }
    if(front==rear){
        front=rear=-1;
    }else{
        front=(front+1)%5;
    }
    currSize--;
  }
  void peek(){
    if(front==-1){
        cout<<"No element at top"<<endl;
        return;
    }
    cout<<"Front : "<<q[front]<<endl;
   }
   void size(){
    cout<<"size : "<<currSize<<endl;
   }
};
class Node{
public:
  int val;Node* next;
  Node(int val1,Node* next1){
    val=val1;
    next=next1;
  }
  Node(int val1){
    val=val1;
    next=nullptr;
  }
  Node(){
    val=0;
    next=nullptr;
  }
};
class StackLL{
  public:
   Node* top=nullptr;int currSize=0;
   void push(int value){
    Node* newNode=new Node(value);
    newNode->next=top;
    top=newNode;currSize++;
   }
   void pop(){
    if(top==nullptr){
        cout<<"Stack Underflow"<<endl;return;
    }
    Node* delNode=top;
    top=top->next;
    delete delNode;
    currSize--;
   }
   void peek(){
    if(top==nullptr){
        cout<<"Stack is empty!"<<endl;
        return;
    }
    cout<<"Top : "<<top->val<<endl;
   }
   void size(){
    cout<<"Size : "<<currSize<<endl;
   }
};
class Queue{
public:
  Node* front=nullptr;Node* rear=nullptr;
  int currSize=0;
  void push(int value){
    Node* newNode=new Node(value);
    if(front==nullptr){
     front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
    currSize++;
  }
  void pop(){
    if(currSize==0){
        cout<<"Queue Underflow"<<endl;
        return;
    } Node* delNode=front;
    if(currSize==1){
        front=rear=nullptr;
    }else{
        front=front->next;
    }
    delete delNode;
    currSize--;
  }
  void peek(){
    if(currSize==0){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Front : "<<front->val<<endl;
  }
  void size(){
    cout<<"size : "<<currSize<<endl;
  }
};
int main(){
    return 0;
}