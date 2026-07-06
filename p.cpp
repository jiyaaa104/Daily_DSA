#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string&s, int start,int end){
   string s1=s.substr(start,end-start+1);
   string s2=s1;
   start=0,end=s2.size()-1;
   while(start<end){
      swap(s2[start],s2[end]);
      start++;end--;
   }
   return (s2==s1);
}
int palindromePartition(int index,string& s){
   int cost=0,n=s.size();
    if(index==s.size()){
      return cost;
    }
    int leastCost=INT_MAX;
    for(int i=index;i<n;i++){
      bool check=checkPalindrome(s,index,i);
      if(check){
         cost=1+palindromePartition(i+1,s);
         leastCost=min(leastCost,cost);
      }
    }return leastCost;
}
void fun(int arr[]){
   cout<<sizeof(arr)<<endl;
   return;
}
int main(){
   //  int arr[]={1,2,3,4,5};
   //  fun(arr);
    int x=5;
    cout<<x++<<" "<<x;
   return 0;
}