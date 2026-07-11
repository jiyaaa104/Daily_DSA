#include<bits/stdc++.h>
using namespace std;
//1.Find All Subsequences / POWER-SET
void subsequences(int index,vector<int>&arr,vector<int>&current){
   if(index==arr.size()){
      for(int x:current){
         cout<<x<<" ";
      }cout<<endl;
      return;
   }

   //pick
   current.push_back(arr[index]);
   subsequences(index+1,arr,current);

   //dont pick
   current.pop_back();
   subsequences(index+1,arr,current);
}
//Print all Subsequence with sum K
void subseqSumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   if(index==arr.size()){
      if(sum==k){
         for(int x: current){
            cout<<x<<" ";
         }cout<<endl;
      }
      return;
   }
   current.push_back(arr[index]);
   sum+=arr[index];
   subseqSumK(index+1,k,sum,arr,current);

   sum-=arr[index];
   current.pop_back();
   subseqSumK(index+1,k,sum,arr,current);
}
bool subseqSumKExists(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   if(index==arr.size()){
      if(sum==k){
         for(int x:current){
            cout<<x<<" ";
         }cout<<endl;
         return true;
      }
      return false;
   }

   //pick
   current.push_back(arr[index]);
   sum+=arr[index];
   if(subseqSumKExists(index+1,k,sum,arr,current)) return true;
   //not pick
   sum-=arr[index];
   current.pop_back();
   if(subseqSumKExists(index+1,k,sum,arr,current)) return true;
   return false;
}
int subseqSumKCount(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   if(index==arr.size()){
      if(sum==k){
         for(int x:current){
            cout<<x<<" ";
         }cout<<endl;
         return 1;
      }
      return 0;
   }
   sum+=arr[index];
   current.push_back(arr[index]);
   int left=subseqSumKCount(index+1,k,sum,arr,current);

   sum-=arr[index];
   current.pop_back();
   int right=subseqSumKCount(index+1,k,sum,arr,current);
   return left+right;
}
//subsequence with even sum
int countEvenSumSubseq(int index,int sum,vector<int>&arr,vector<int>&current){
   if(index==arr.size()){
      if(sum%2==0){
         for(int x: current){
            cout<<x<<" "; 
         }cout<<endl;
         return 1;
      }
      return 0;
   }
   sum+=arr[index];
   current.push_back(arr[index]);
   int left=countEvenSumSubseq(index+1,sum,arr,current);
   sum-=arr[index];
   current.pop_back();
   int right=countEvenSumSubseq(index+1,sum,arr,current);
   return left+right;
}
void generateBin(int index,int n,string &current){
   if(index==n){
     cout<<current<<endl;
     return;
   }
   //pick
   current.push_back('0');
   generateBin(index+1,n,current);
   current.pop_back();

   current.push_back('1');
   generateBin(index+1,n,current);
   current.pop_back();
}
void BinaryNoConsecutiveOnes(int index,int n,string&current){
   if(index==n){
      cout<<current<<endl;
      return ;
   }
   current.push_back('0');
   BinaryNoConsecutiveOnes(index+1,n,current);
   current.pop_back();

   if(current.empty() || current.back()!='1'){
      current.push_back('1');
   BinaryNoConsecutiveOnes(index+1,n,current);
   current.pop_back();
   }
}
void generateParenthesis(int n,int open,int close,string& current){
   if(open==n && close==n){
      cout<<current<<endl;
      return;
   }
   if(open<n){
      current.push_back('(');
      generateParenthesis(n,open+1,close,current);
      current.pop_back();
   }
   if(close<open){
      current.push_back(')');
      generateParenthesis(n,open,close+1,current);
      current.pop_back();
   }
}
int main(){
   vector<int>arr={1,2,3};
   string current;
   // subsequences(0,arr,current);
   // subseqSumK(0,3,0,arr,current);
   // cout<<subseqSumKExists(0,13,0,arr,current);
   // cout<<subseqSumKCount(0,3,0,arr,current);
   // cout<<countEvenSumSubseq(0,0,arr,current);
   // generateBin(0,3,current);
   // BinaryNoConsecutiveOnes(0,3,current);
   generateParenthesis(3,0,0,current);
   return 0;
}