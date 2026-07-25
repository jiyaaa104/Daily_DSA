#include<bits/stdc++.h>
using namespace std;
class StackA{
  int top=-1;
  static int const size=5;
  int stack[size];
  void push(int x){
    if(top+1>=size){
      cout<<"Stack Overflow"<<endl;return;
    }
    top++;
    stack[top]=x;
  }
  void pop(){
    if(top==-1){
      cout<<"Stack Underflow"<<endl;return;
    }
    top--;
  }
  };

  class QueueLA{
    int front=-1,rear=-1,currSize=0;
    static int const size=5;
    int q[size];
    void push(int x){
      if(rear+1>=size){
        cout<<"Queue Overflow"<<endl;return;
      }
      if(currSize==0){
        front=rear=0;
      }else{
        rear++;
      }
      currSize++;
      q[rear]=x;
    }
    void pop(){
      if(currSize==0){
        cout<<"Queue Underflow"<<endl;return;
      }
      if(front==rear){
        front=rear=-1;
      }else{
        front++;
      }
      currSize--;
    }
  };
  class QueueCA{
    int front=-1,rear=-1,currSize=0;
    static int const size=5;int q[size];
    void push(int x){
      if(currSize==size){
        cout<<"Queue Overflow"<<endl;
        return;
      }
      if(front==-1){
        front=rear=0;
      }else{
        rear=(rear+1)%size;
      }
      currSize++;
      q[rear]=x;
    }
    void pop(){
      if(currSize==0){
        cout<<"Queue Underflow"<<endl;return;
      }
      if(currSize==1){
        front=rear=-1;
      }else{
        front=(front+1)%size;
      }
      currSize--;
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
    val=val1;next=nullptr;
   }
   Node(){
    val=0;next=nullptr;
   }
  };
  class StackL{
   Node* top=nullptr;int currSize=0;
   void push(int x){
    Node* newNode=new Node(x);
    newNode->next=top;
    top=newNode;
    currSize++;
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
  };
  class QueueL{
    Node* front=nullptr;Node* rear=nullptr;int currSize=0;
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
        cout<<"Queue Underflow"<<endl;return;
      }
      Node* delNode=front;
      if(currSize==1){
        front=rear=nullptr;
      }
      else {front=front->next;}
      delete delNode;
      currSize--;
    }
  };
  class StackQ{
    queue<int>q;
    void push(int x){
      int s=q.size();
      q.push(x);
      for(int i=0;i<s;i++){
        q.push(q.front());q.pop();
      }
    }
    void pop(){
      if(q.empty()){
        cout<<"Stack UnderFlow"<<endl;return;
      }
      q.pop();
    }
  };
  class QueueS1{
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
    void pop(){
      if(s1.empty()){
        cout<<"Queue Underflow"<<endl;return;
      }
      s1.pop();
    }
  };
  class QueueS2{
    stack<int>s1;stack<int>s2;
    void push(int x){
      s1.push(x);
    }
    void pop(){
      if(!s2.empty()){
        s2.pop();
      }else{
        while(s1.size()){
          s2.push(s1.top());s1.pop();
        }
        s2.pop();
      }
    }
  };
  class MinStack1{
    stack<pair<int,int>>s;
    void push(int x){
      if(s.empty()){
        s.push({x,x});
      }else{
        s.push({x,min(x,s.top().second)});
      }
    }
    void pop(){
      s.pop();
    }
    int getMin(){
      return s.top().second;
    }
    int top(){
      return s.top().first;
    }
  };
  class MinStack2{
    stack<int>st;
    int mini;
    void push(int x){
      if(st.empty()){
        mini=x;
        st.push(x);
      }else{
        if(x>=mini){
          st.push(x);
        }else{
          st.push(2*x-mini);
          mini=x;
        }
      }
    }
    void pop(){
      if(st.top()<mini){
        mini=2*mini-st.top();
      }
      st.pop();
    }
     int top(){
      if(mini>=st.top()){
        return mini;
      }
      return st.top();
     }
     int getMini(){
      return mini;
     }
  };
int main(){

}