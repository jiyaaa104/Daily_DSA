#include<bits/stdc++.h>
using namespace std;
class StackA{
  public:
  int top=-1;
  static int const size=5;
  int stack[size];
  void push(int x){
    if(top+1>=size){
      cout<<"Stack Overflow"<<endl;
      return;
    }
    top++;
    stack[top]=x;
  }
  void pop(){
    if(top==-1){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    top--;
  }
};
class QueueLA{
  public:
 int front=-1,rear=-1,currSize=0;
 static int const size=5;
 int q[size];
 void push(int x){
  if(rear+1>=size){
    cout<<"Queue Overflow"<<endl;
    return;
  }
  if(front==-1){
    front=rear=0;
  }
  else{
    rear++;
  }
  currSize++;
  q[rear]=x;
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
};
class QueueCA{
  public:
  int front=-1,rear=-1,currSize=0;
  static int const size=5;
  int q[size];
  void push(int x){
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
    q[rear]=x;
  }
  void pop(){
    if(currSize==0){
      cout<<"Queue UnderFlow"<<endl;
      return;
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
  void push(int x){
    Node* newNode=new Node(x);
    newNode->next=top;
    top=newNode;
    currSize++;
  }
  void pop(){
    if(top==nullptr){
      cout<<"Stack UnderFlow"<<endl;
      return;
    }
    Node* delNode=top;
    if(top->next==nullptr){
     top=nullptr;
    }
    else{
      top=top->next;
    }
    delete delNode;
    currSize--;
  }
};
class QueueLL{
  public:
  Node* front=nullptr;Node* rear=nullptr;
  int currSize=0;
  void push(int x){
    Node* newNode=new Node(x);
    if(currSize==0){
      front=rear=newNode;
    }else{
      rear->next=newNode;
      rear=rear->next;
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
};
class StackQ{
  public:
  queue<int>q;
  void push(int x){
    int s=q.size();
    q.push(x);
    for(int i=0;i<s;i++){
      q.push(q.front());
      q.pop();
    }
  }
  void pop(){
    if(q.empty()){
      cout<<"Stack Underflow"<<endl;
      return;
    }
    q.pop();
  }
};
class QueueS1{
 public:
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
    cout<<"Queue Underflow"<<endl;
    return;
  }
  s1.pop();
 }
};
class QueueS2{
public:
  stack<int>s1,s2;
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
class Minstack1{
public:
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
int top(){
  return s.top().first;
}
int getMin(){
  return s.top().second;
}
};
class MinStack2{
public:
stack<long long>s;int mini;
void push(int x){
  if(s.empty()){
    s.push(x);
    mini=x;
  }else{
    if(x>=mini){
      s.push(x);
    }else{
      s.push(2LL*x-mini);
      mini=x;
    }
  }
}
void pop(){
  if(s.top()>mini){
    s.pop();
  }else{
    mini=2*mini-s.top();
    s.pop();
  }
}
int top(){
  if(mini>=s.top()){
    return mini;
  }
  return s.top();
}
int getMin(){
  return mini;
}
};
int priority(char ch){
  if(ch=='^')return 3;
  else if(ch=='*' || ch=='/')return 2;
  else if(ch=='+' || ch=='-')return 1;
  return -1;
}
string infixToPostFix(string s){
  string ans;int i=0,n=s.size();
  stack<char>st;
  while(i<n){
    if((s[i]>='A'&& s[i]<='Z') || (s[i]>='a'&& s[i]<='z') || (s[i]>='0'&& s[i]<='9')){
      ans+=s[i];
    }else if(s[i]=='('){
      st.push(s[i]);
    }else if(s[i]==')'){
      while(!st.empty() && st.top()!='('){
        ans+=st.top();
        st.pop();
      }
      st.pop();
    }else{
      while(!st.empty() && ((priority(s[i])<priority(st.top())) || ((priority(s[i])==priority(st.top())) && s[i]!='^'))){
        ans+=st.top();st.pop();
      }
      st.push(s[i]);
    }
    i++;
  }
  while(!st.empty()){
    ans+=st.top();st.pop();
  }
  return ans;
}
string infixToPrefix(string s){
  string ans;int i=0,n=s.size();stack<char>st;
  reverse(s.begin(),s.end());
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      s[i]=')';
    }
    else if(s[i]==')'){
      s[i]='(';
    }
  }
  while(i<n){
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
      ans+=s[i];
    }else if(s[i]=='('){
      st.push(s[i]);
    }else if(s[i]==')'){
      while(!st.empty() && st.top()!='('){
        ans+=st.top();st.pop();
      }
      st.pop();
    }else{
      while(!st.empty() && ((priority(s[i])<priority(st.top())) || ((priority(s[i])==priority(st.top()))&&s[i]=='^'))){
        ans+=st.top();st.pop();
      }
      st.push(s[i]);
    }
   i++;
  }
  while(!st.empty()){
    ans+=st.top();st.pop();
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){
  string s="a^b^c";
  cout<<infixToPrefix(s);
  return 0;
}