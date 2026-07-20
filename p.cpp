#include<bits/stdc++.h>
using namespace std;
int xor1N(int n){
    switch(n%4){
        case 0 : return n;
        case 1 : return 1;
        case 2 : return n+1;
        default : return 0;
    }
}
int xorRange(int l,int r){
    return xor1N(r)-xor1N(l-1);
}
int xor1486(int n,int start){
    int s=start>>1;
    return (xorRange(s,s+n-1)<<1) | ((start&1)&(n&1));
}
int divide(int dividend,int divisor){
    if(dividend==divisor)return 1;
    if(dividend==0)return 0;
    if(divisor==1)return dividend;
    bool sign = (dividend<0) == (divisor<0);
    long long n=llabs((long long)dividend);
    long long d=llabs((long long)divisor);
    long long ans=0;
    while(n>=d){
        int count=0;
        while(n>=(d<<(count+1))){
            count++;
        }
        n-=(d<<count);
        ans+=(1<<count);
    }
    if(ans==1<<31 && sign){
        return INT_MAX;
    }
    if(ans==1<<31 && !sign){
        return INT_MAX;
    }
    return sign?ans:-ans;
}
int add(int a,int b){
    while(b){
        int carry=a&b;
        a^=b;
        b=carry<<1;
    }return a;
}
int main(){
    int a=1;
    string s;
    s.push_back(a+'0');
    cout<<s;
    return 0;
}