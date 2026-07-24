#include<bits/stdc++.h>
using namespace std;
class Stack1{
  public:
  int top=-1;
  static int const size=5;
  int stack[size];
  void push(int val){
    if(top+1>=size){
      cout<<"Stack Overflow"<<endl;
      return;
    }
    top++;
    stack[top]=val;
  }
  void pop(){
    if(top==-1){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    top--;
  }
  void peek(){
    if(top==-1){
      cout<<"Empty"<<endl;
      return;
    }
    cout<<"Top : "<<stack[top]<<endl;
  }
  void size(){
    cout<<"size : "<<top+1<<endl;
  }
};
class LQueue{
 public:
 int front=-1,rear=-1,currSize=0;
 static int const size=5;
 int q[size];
 void push(int val){
  if(rear+1>=size){
    cout<<"Queue Overflow"<<endl;
    return;
  }else if(front=rear=-1){
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
  front++;
  if(front>rear){
    front=rear=-1;
  }
  currSize--;
 }
   void peek(){
    if(front==-1){
      cout<<"Empty"<<endl;
      return;
    }
    cout<<"Top : "<<q[front]<<endl;
  }
  void size(){
    cout<<"size : "<<currSize<<endl;
  }
};
class CQueue{
 public:
  int front=-1,rear=-1,currSize=0;
  static int const size=5;
  int q[size];
  void push(int val){
    if(currSize==size){
      cout<<"Queue Overflow"<<endl;
      return;
    }
    if(currSize==0){
      front=rear=0;
    }else{
      rear=(rear+1)%size;
    }
    currSize++;
    q[rear]=val;
  }
  void pop(){
    if(currSize==0){
      cout<<"Queue Underflow"<<endl;
      return;
    }
    if(currSize==1){
      front=rear=-1;
    }
    front=(front+1)%size;
    currSize--;
  }
  void peek(){
    if(front==-1){
      cout<<"Empty"<<endl;
      return;
    }
    cout<<"Top : "<<q[front]<<endl;
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
class Stack2{
  Node* top=nullptr;int currSize=0;
  void push(int x){
    Node* newNode=new Node(x);
    newNode->next=top;
    top=newNode;
    currSize++;
  }
  void pop(){
    if(top==nullptr){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    Node* delNode=top;
    top=top->next;
    delete delNode;
    currSize--;
  }
  void peek(){
    if(top==nullptr){
      cout<<"Stack is empty"<<endl;
      return;
    }
    cout<<"Top : "<<top->val<<endl;
  }
  void size(){
    cout<<"Size : "<<currSize<<endl;
  }
};
class Queue2{
public:
  Node* front=nullptr;
  Node* rear=nullptr;
  int currSize=0;
  void push(int x){
    Node* newNode=new Node(x);
    if(currSize==0){
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
    }
    Node* delNode=front;
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
      cout<<"Empty !"<<endl;
      return;
    }
    cout<<"Front : "<<front->val<<endl;
  }
  void size(){
    cout<<"Size: "<<currSize<<endl;
  }
};
class Stack{
queue<int>q;
void push(int x){
  int s=q.size();
  q.push(x);
  for(int i=0;i<s;i++){
    q.push(q.front());q.pop();
  }
}
int pop(){
  int t=q.front();
  q.pop();
  return t;
}
int top(){
  return q.front();
}
void size(){
  cout<<"Size : "<<q.size()<<endl;
}
};
class Queue11{
stack<int>s1;stack<int>s2;
void push(int x){
  while(s1.size()){
    s2.push(s1.top());s1.pop();
  }
  s1.push(x);
  while(s2.size()){
    s1.push(s2.top());s2.pop();
  }
}
int pop(){
  int t=s1.top();
  s1.pop();
  return t;
}
int top(){
  return s1.top();
}
void size(){
  cout<<s1.size()<<endl;
}
};
class Queue12{
public:
stack<int>s1;stack<int>s2;
void push(int x){
  s1.push(x);
}
void pop(){
  if(!s2.empty()){
    s2.pop();
  }else{
    while(s1.size()){
      s2.push(s1.top());
      s1.pop();
    }
    s2.pop();
  }
}
void top(){
  if(!s2.empty()){
    cout<<s2.top()<<endl;
  }else{
    while(s1.size()){
      s2.push(s1.top());
      s1.pop();
    }
    cout<<s2.top()<<endl;
  }
}
};
int main(){
  return 0;
}