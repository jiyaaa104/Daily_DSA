#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
  if(ch=='^')return 3;
  if(ch=='*'|| ch=='/')return 2;
  if(ch=='+' || ch=='-')return 1;
  return -1;
}
string infixToPostfix(string s){
  string ans;stack<char>st;int i=0,n=s.size();
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
  string ans;stack<char>st;int i=0,n=s.size();
  reverse(s.begin(),s.end());
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      s[i]=')';
    }else if(s[i]==')'){
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
      while(!st.empty() && ((priority(s[i])<priority(st.top())) || ((priority(s[i])==priority(st.top())) && s[i]=='^'))){
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
string postfixToInfix(string s){
  int i=0,n=s.size();stack<string>st;string ans;
  while(i<n){
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
      string x;x+=s[i];st.push(x);
    }
    else{
      string b=st.top();st.pop();
      string a=st.top();st.pop();
      string x="("+a+s[i]+b+")";
      st.push(x);
    }
    i++;
  }
  ans+=st.top();
  return ans;
}
string prefixToInfix(string s){
int n=s.size();int i=n-1;string ans;stack<string>st;
while(i>=0){
   if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
      string x;x+=s[i];st.push(x);
    }else{
      string a=st.top();st.pop();
      string b=st.top();st.pop();
      string x="("+a+s[i]+b+")";
      st.push(x);
    }
    i--;
}
return st.top();
}
string postfixToPrefix(string s){
  int i=0,n=s.size();string ans;stack<string>st;
  while(i<n){
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
      string x;x+=s[i];st.push(x);
    }else{
      string b=st.top();st.pop();
      string a=st.top();st.pop();
      string x=s[i]+a+b;
      st.push(x);
    }
    i++;
  }
  ans+=st.top();
  return ans;
}
string prefixToPostfix(string s){
  int n=s.size();string ans;stack<string>st;int i=n-1;
  while(i>=0){
    if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
      string x;x+=s[i];st.push(x);
    }else{
      string a=st.top();st.pop();
      string b=st.top();st.pop();
      string x=a+b+s[i];
      st.push(x);
    }
    i--;
  }
  return st.top();
}
int main(){
  string s="*+PQ-MN";
  cout<<prefixToPostfix(s);
  return 0;
}