#include<bits/stdc++.h>
using namespace std;
//PROBLEM 1 : SWAP TWO NUMBERS WITHOUT TAKING THIRD VARIABLE
void swap(int a,int b){
    a=a^b;
    b=a^b;
    a=a^b;
 cout<<"A = "<<a<<endl;
 cout<<"B = "<<b<<endl;
}
//PROBLEM 2: CHECK IF THE iTH BIT IS SET OR NOT
bool iBitSet(int n,int i){
    //Method 1 : Left Shift Operator
    // return(n&(1<<i))!=0;
    //Method 2: Right Shift Operator
    return (n>>i)%2!=0;
}
//PROBLEM 3: SET THE iTH BIT
void setiBit(int n,int i){
    n=n|(1<<i);
    cout<<n<<endl;
    return;
}
//PROBLEM 4: CLEAR THE iTh BIT
void cleariBit(int n,int i){
    n=n&~(1<<i);
    cout<<n<<endl;
    return;
}
//PROBLEM 5: TOGGLE THE ith BIT
void toggleiBit(int n,int i){
    n=n^(1<<i);
    cout<<n<<endl;
    return;
}
//PROBLEM 6: REMOVE THE LAST SET BIT
void removeLastSetBit(int n){
    n=n&(n-1);
    cout<<n<<endl;
    return;
}
//PROBLEM 7:CHECKING IF A NUMBER IS POWER OF TWO
bool checkPowerOfTWo(int n){
    return (n&(n-1))==0;
}
//PROBLEM 8: COUNT THE NUMBER OF SET BITS
void countSetBits(int n){
    //METHOD 1:
    // int count=0;
    // while(n!=0){
    //  if(n&1){
    //     count++;
    //  }
    //  n>>=1;
    // }
    //METHOD 2:
    // int count=__builtin_popcount(n);
    //METHOD 3:
    int count=0;
    while(n){
        count++;
        n&=(n-1);
    }
    cout<<count<<endl;
    return;
}
//PROBLEM 9: MINIMUM NUMBER OF BIT FLIPS TO CONVERT A NUMBER
int minimumBitFlips(int start,int goal){
    return __builtin_popcount(start^goal);
}
void printSubSets(vector<int>nums){
    vector<vector<int>>ans;
    int n=nums.size(),subsets=1<<n;
    for(int num=0;num<subsets;num++){
        vector<int>a;
        for(int i=0;i<n;i++){
           if(num&(1<<i)){
            a.push_back(nums[i]);
           }
        }
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
//SINGLE NUMBER 2 
//APPROACH : Basically, we expand every number (integer) (32 bit places) Since a number always appears 3 and just one f them appears once. therefore For the answer's bit position at that particular index will be set if the number of set bits in that index is not a multiple of three otherwise it'll be 0
int singleNumber2(vector<int>nums){
    //METHOD 1:
    // int n=nums.size();
    // int place=1,ans=0;
    // for(int i=0;i<31;i++){
    //     int count=0;
    //     for(int index=0;index<n;index++){
    //       if(nums[index]&(1<<i))count++;
    //     }
    //     int rem=0;
    //     if(count%3!=0){
    //      rem=1;
    //     }
    //     ans=ans+place*rem;
    //     place*=2;
    // }
    // return ans;
    //METHOD 2:
    // int n=nums.size();
    // sort(nums.begin(),nums.end());
    // int index=1,ans=nums[n-1];
    // while(index<n){
    //     if(nums[index]!=nums[index-1]){
    //       ans=nums[index-1];
    //       break;
    //     }else{
    //         index+=3;
    //     }
    // }
    // return ans;
    int once=0,twice=0,n=nums.size();
    for(int i=0;i<n;i++){
      once=(once^nums[i])&(~twice);
      twice=(twice^nums[i])&(~once);
    }return once;
}
void singleNumber3(vector<int>nums){
    int n=nums.size();
    long long x=0;
    for(int i=0;i<n;i++){
      x^=nums[i];
    }
    int value=(x&(x-1))^x;
    int b1=0,b2=0;
    for(int i=0;i<n;i++){
        if(nums[i]&value){
            b1^=nums[i];
        }else{
            b2^=nums[i];
        }
    }
    cout<<b1<<" "<<b2<<endl;
}
int xor1N(int n){
    switch(n%4){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        default: return 0;
    }
}
int xorRange(int l,int r){
    return xor1N(r)^xor1N(l-1);
}
int xor1486(int n,int start){
    int s=start>>1;
    return (xorRange(s,s+n-1)<<1)|((start&1)&(n&1));
}
int main(){
//     vector<int>nums={1,2,1,3,2,5};
//    singleNumber3(nums);5^7^9^11^13
cout<<xor1486(5,12);
    return 0;
}