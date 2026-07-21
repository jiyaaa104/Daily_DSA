#include<bits/stdc++.h>
using namespace std;
string convert2Binary(int n){
    string ans;
    while(n){
        int rem=n%2;
        if(rem) ans+='1';
        else ans+='0';
        n>>=1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string convert2Decimal(string bin){
    string ans;
    int num=0,place=1;
    for(int i=bin.size()-1;i>=0;i--){
      num=num+place*(bin[i]-'0');
      place*=2;
    }
    ans=to_string(num);
    return ans;
}
void swapNumbers(int a,int b){
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    return;
}
bool checkiThBitSet(int n,int i){
    //RIGHT OPERATOR
    // return ((n>>i)&1);
    //LEFT OPERATOR
    return ((1<<i)&n);
}
int setiThBit(int n,int i){
    n=n|(1<<i);
    return n;
}
int cleariThBit(int n,int i){
    n=n&~(1<<i);
    return n;
}
int toggleiThBit(int n,int i){
    n=n^(1<<i);
    return n;
}
int removeLastSetBit(int n){
    return n&(n-1);
}
bool checkPower2(int n){
    return (n&(n-1))==0;
}
int countSetBits(int n){
    //Conventional method
    // int m=n,count=0;
    // while(m){
    //     if(m&1)count++;
    //     m>>=1;
    // }return count;
    //Better Method
    // int m=n,count=0;
    // while(m){
    //     m=m&(m-1);
    //    count++;
    // }return count;
    //Best Method
    return __builtin_popcount(n);
}
int minimumBitFlips(int a,int b){
    return __builtin_popcount(a^b);
}
void printSubsets(vector<int>nums){
    vector<vector<int>>ans;
    int n=nums.size();
    int subset=1<<n;
    for(int i=0;i<subset;i++){
        vector<int>a;
        for(int index=0;index<n;index++){
            if(i&(1<<index))a.push_back(nums[index]);
        }
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }return;
}
int singleNumber2(vector<int>nums){
    int n=nums.size(),place=1,ans=0;
    // for(int bit=0;bit<32;bit++){
    //      int count=0;
    //      for(int index=0;index<nums.size();index++){
    //         if(nums[index]&(1<<bit))count++;
    //      }
    //      int rem=0;
    //      if(count%3!=0){
    //         rem=1;
    //      }
    //      ans=ans+place*rem;
    //      place*=2;
    // }return ans;
    //METHOD 2
    // sort(nums.begin(),nums.end());
    // int index=1;
    // while(index<n){
    //    if(nums[index]!=nums[index-1])return nums[index-1];
    //    index+=3;
    // }
    // return nums[n-1];
    //METHOD 3
    int once=0,twice=0;
    for(int i=0;i<n;i++){
        once=once^nums[i] & (~twice);
        twice=twice^nums[i] & (~once);
    }return once;
}
void singleNumber3(vector<int>nums){
    int Xor=0,n=nums.size();
    for(int i=0;i<n;i++){
       Xor^=nums[i];
    }
    int once=0,twice=0,val=((Xor&(Xor-1))^Xor);
    for(int i=0;i<n;i++){
        if(val&nums[i])once^=nums[i];
        else twice^=nums[i];
    }
    cout<<once<<" "<<twice; 
}
int xor1N(int n){
    switch(n%4){
        case 0: return 4;
        case 1: return 1;
        case 2: return n+1;
        default: return 0;
    }
}
int xorRange(int l,int r){
    return xor1N(r)^xor1N(l-1);
}
int xor1486(int start,int n){
    int s=start>>1;
    return (xorRange(s,s+n-1)<<2) | (n&1)&(start&1);
}
int divide(int dividend,int divisor){
    bool sign = (dividend<0)==(divisor<0);
    long long n=llabs((long long)dividend);
    long long d=llabs((long long)divisor);
    long long ans=0;
    while(n>=d){
        int count=0;
        while(n>=(d<<count+1)){
            count++;
        }
        ans+=1<<count;
        n-=d<<count;
    }
    if(ans==(1<<31) && sign)return INT_MAX;
    if(ans==(1<<31) && !sign) return INT_MIN;
    return sign?ans:-ans;
}
int add(int a,int b){
    int carry=0;
    while(b){
        carry=a&b;
        a^=b;
        b=carry<<1;
    }return a;
}
int main(){
   cout<<add(7,3);
    return 0;
}