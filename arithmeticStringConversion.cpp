#include<bits/stdc++.h>
using namespace std;
//1. INFIX TO POSTFIX
//RULES :
//i. If operand -> dont push in stack, push in answer only
//ii. If open bracket -> push in stack
//iii. If closing bracket -> pop out every operator from stack and put it into answer until you find opening bracket.Finally pop out the open bracket as well
//iv. If the operators priority is greater than the operator at the top of the stack,push it into the stack. else if the op priority is < op at top pop out every thing from stack into ans until the operator has graeter priority then push the op into stack.
//v. Push all the remaining people from stack into ans
int priority(char c){
    switch(c){
        case '^': return 3;
        case '*':return 2;
        case '/':return 2;
        case '+':return 1;
        case '-':return 1;
        default:return -1;
    }
}
string infixToPostfix(string s){
    int i=0,n=s.size();
    stack<char>st;string ans;
    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
               ans+=st.top();
               st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && ((priority(s[i])<priority(st.top()))||((priority(s[i])==priority(st.top()))&&
            s[i]!='^'))){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
string infixToPrefix(string s){
    int i=0,n=s.size();
    stack<char>st;
    string ans;
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            s[i]='(';
        }else if(s[i]=='('){
            s[i]=')';
        }
    }
    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && ((priority(s[i])<priority(st.top())) || ((priority(s[i])==priority(st.top())) && s[i]=='^'))){
                ans+=st.top();
                st.pop();
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
    stack<string>st;string ans;
    int i=0,n=s.size();
    while(i<n){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            string x="";
            x+=s[i];
            st.push(x);
        }else{
            string b=st.top();st.pop();
            string a=st.top();st.pop();
            string x="("+a+s[i]+b+")";
            st.push(x);
        }
      i++;
    }
    ans+=st.top();st.pop();
    return ans;
}
string prefixToInfix(string s){
    string ans;stack<string>st;int n=s.size();int i=n-1;
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
    ans+=st.top();
    return ans;
}
string postfixToPrefix(string s){
    stack<string>st;string ans;int i=0,n=s.size();
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
    string ans;stack<string>st;int n=s.size();int i=n-1;
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
    ans+=st.top();
    return ans;
}
int main(){
    string s="AB-DE+F*/";
    string x=postfixToPrefix(s);
    cout<<prefixToPostfix(x);
    return 0;
}