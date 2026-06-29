#include<bits/stdc++.h>
using namespace std;
int exponentiation(int a,int b){
   if(b==0) return 1;
   int half=exponentiation(a,b/2);
   if(b%2==0){
     return half*half;
   }
   return a*half*half;
}
int power(int a,int b){
   int ans=1;
   while(b!=0){
      if(b&1){
         ans=ans*a;
      }
      a=a*a;
      b=b>>1;
   }return ans;
}
void insertAtCorrectPlace(stack<int>&s,int t){
   if(s.empty() || t<s.top()){
      s.push(t);
      return;
   }
   int temp=s.top();
   s.pop();
   insertAtCorrectPlace(s,t);
   s.push(temp);
}
void sortTheStack(stack<int>&s){
   if(s.empty()){
      return;
   }
   int t=s.top();
   s.pop();
   sortTheStack(s);
   insertAtCorrectPlace(s,t);
}
void printStack(stack<int>&s){
   while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
   }return;
}
void insertAtTheBottom(stack<int>&s,int t){
   if(s.empty()){
      s.push(t);
      return;
   }
   int temp=s.top();
   s.pop();
   insertAtTheBottom(s,t);
   s.push(temp);
}
void reverseTheStack(stack<int>&s){
   if(s.empty()){
      return;
   }
   int t=s.top();
   s.pop();
   reverseTheStack(s);
   insertAtTheBottom(s,t);
}
int main(){
   stack<int>s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   reverseTheStack(s);
   printStack(s);
   return 0;
}