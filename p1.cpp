#include<bits/stdc++.h>
using namespace std;
class Stack{
   int top=-1;int arr[10];
   void push(int x){
    if(top==9){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    arr[top]=x;
   }
   void pop(){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    top--;
   }
};
class Queue{
  public:
  int front=-1,rear=-1,currSize=0;int q[5];
  void push(int x){
    if(currSize==5){
        cout<<"Queue Overflow"<<endl;
        return;
    }
    if(front==-1){
        front=rear=0;
    }else{
        rear=(rear+1)%5;
    }
    currSize++;q[rear]=x;
  }
  void pop(){
    if(front==-1){
        cout<<"Queue Underflow"<<endl;
        return;
    }
    if(front==rear){
        front=rear=-1;
    }else{
        front=(front+1)%5;
    }
    currSize--;
  }
};
class Node{
    public:
   int val;Node* next;
   Node( int v,Node* n){
    val=v;
    next=n;
   }
   Node(int v){
    val=v;
    next=nullptr;
   }
};
class StackLL{
    public:
    Node* top=nullptr;int size=0;
    void push(int x){
        Node* newNode=new Node(x);
        if(top==nullptr){
            top=newNode;
        }else{
        top->next=newNode;
        top=newNode;
        }
        size++;
    }
    void pop(){
        if(top==nullptr){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* del=top;
        top=top->next;
        delete del;
        size--;
    }
};
class QueueLL{
   public:
    int size=0;Node* front=nullptr;Node* rear=nullptr;
    void push(int x){
        Node* newNode=new Node(x);
        if(front==nullptr){
            front=newNode;
            rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
        size++;
    }
    void pop(){
        if(front==nullptr){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* delNode=front;
        if(front->next==nullptr){
            front=nullptr;
            rear=nullptr;
        }else{
            front=front->next;
        }
         delete delNode;
        size--;
    }
};
class minStack{
   public: 
   stack<long long>st;int mini;
   void push(int x){
     if(st.empty()){
        st.push(x);mini=x;
     }else{
        if(x>=mini){
            st.push(x);
        }else{
            st.push(2LL*x-mini);
            mini=x;
        }
     }
   }
   void pop(){
     int x=st.top();
     if(x>=mini){
        st.pop();
     }else{
        mini=2LL*mini-x;
        st.pop();
     }
   }
   int Top(){
    int x=st.top();
    if(x>=mini)return x;
    return mini;
   }
};
int priority(char ch){
    if(ch=='^')return 3;
    if(ch=='*' || ch=='/')return 2;
    if(ch=='+' || ch=='-')return 1;
    return 0;
}
string infixToPostfix(string s){
    string ans;int n=s.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))ans+=s[i];
        else if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && ((priority(s[i])<priority(st.top())) || (priority(s[i])==priority(st.top())) && s[i]!='^')){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();st.pop();
    }
    return ans;
}
string infixToPrefix(string s){
    int n=s.size();string ans;stack<char>st;
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
      if(s[i]=='('){
        s[i]=')';
      }else if(s[i]==')'){
        s[i]='(';
      }
    }
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))ans+=s[i];
        else if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && ((priority(s[i])<priority(st.top())) || (priority(s[i])==priority(st.top())) && s[i]=='^')){
                ans+=st.top();st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string postfixToInfix(string s){
    stack<string>st;string ans;int n=s.size();
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string x;
            x+=s[i];
            st.push(x);
        }else{
            string b=st.top();st.pop();
            string a=st.top();st.pop();
            string x="("+a+s[i]+b+")";
            st.push(x);
        }
    }
    return st.top();
}
string prefixToInfix(string s){
    string ans;stack<string>st;int n=s.size();
    for(int i=n-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string x;
            x+=s[i];
            st.push(x);
        }else{
            string a=st.top();st.pop();
            string b=st.top();st.pop();
            string x="("+a+s[i]+b+")";
            st.push(x);
        }
    }return st.top();
}
string postfixToPrefix(string s){
    int n=s.size();stack<string>st;
    for(int i=0;i<n;i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string x;
            x+=s[i];
            st.push(x);
        }else{
            string b=st.top();st.pop();
            string a=st.top();st.pop();
            string x=s[i]+a+b;
            st.push(x);
        }
    }return st.top();
}
string prefixToPostfix(string s){
    int n=s.size();stack<string>st;
    for(int i=n-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string x;
            x+=s[i];
            st.push(x);
        }else{
            string a=st.top();st.pop();
            string b=st.top();st.pop();
            string x=a+b+s[i];
            st.push(x);
        }
    }return st.top();
}
int main(){
    cout<<prefixToPostfix("/-AB*+DEF");
    return 0;
}