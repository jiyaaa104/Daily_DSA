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
int main(){
    return 0;
}