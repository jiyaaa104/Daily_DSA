#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
long long numConv(string &s,int i,int sign,long long num){
    int n=s.size();
    if(i>=n || !isdigit(s[i])){
        return sign*num;
    }
    int digit=s[i]-'0';
    if(num>INT_MAX/10 || num==INT_MAX/10 && digit > (sign==-1? 8 : 7)){
        return (sign==-1 ? INT_MIN : INT_MAX);
    }
    num=num*10+digit;
    return numConv(s,i+1,sign,num);
}
int myAtoi(string s){
    int n=s.size();
    long long num=0;
    int sign=1,i=0;
    while(i<n && s[i]==' '){
        i++;
    }
    if(i>=n) return 0;
    if(s[i]=='-'){
        sign=-1;i++;
    }else if(s[i]=='+'){
        i++;
    }
    if(i>=n) return 0;
    if(!isdigit(s[i])) return 0;
    return (int)numConv(s,i,sign,num);
}
double power(double x,long long n){
    if(n==0) return 1;
    double half= power(x,n/2);
    if(n%2==0) return half*half;
    return x* half* half;
}
double myPow(double x,int n){
    long long nn=n;
    if(nn<0){
        nn=-nn;
    }
    double ans=power(x,nn);
    if(n<0){
        return 1/ans;
    }
    return ans;
}
long long powerA(long long a,long long b){
    if(b==0) return 1;
    long long half=powerA(a,b/2)%MOD;
    if(b%2==0){
        return (half*half)%MOD;
    }return (a*half*half)%MOD;
}
int countGoodNumbers(long long n){
    long long evenPos=(n+1)/2;
    long long oddPos=(n)/2;
    long long ans=(powerA(5,evenPos) * powerA(4,oddPos))%MOD;
    return ans;
}
void insertInSortedStack(stack<int>&s,int t){
    if(s.empty() || t>s.top()){
        s.push(t);
        return ;
    }
    int temp=s.top();
    s.pop();
    insertInSortedStack(s,t);
    s.push(temp);
}
void sortTheStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int t=s.top();
    s.pop();
    sortTheStack(s);
    insertInSortedStack(s,t);
}
void insertAtTheBottom(stack<int>&s,int temp){
    if(s.empty()){
        s.push(temp);
        return;
    }
    int t=s.top();
    s.pop();
    insertAtTheBottom(s,temp);
    s.push(t);
}
void reverseTheStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseTheStack(s);
    insertAtTheBottom(s,temp);
}
int main(){

    return 0;
}