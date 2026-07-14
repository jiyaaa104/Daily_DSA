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
int main(){
   countSetBits(13);
    return 0;
}