#include<bits/stdc++.h>
using namespace std;
//1. 
void printSubSeq(int index,vector<int>&arr,vector<int>&current){
   //base case
   if(index==arr.size()){
      for(int x:current){
         cout<<x<<" ";
      }cout<<endl;
      return;
   }

   //pick item
   current.push_back(arr[index]);
   printSubSeq(index+1,arr,current);

   //skip item
   current.pop_back();
   printSubSeq(index+1,arr,current);
}
void sumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   //base case
   if(arr.size()==index){
      if(sum==k){
         for(int x: current){
            cout<<x<<" ";
         }cout<<endl;
      }
      return;
   }

   //pick
   current.push_back(arr[index]);
   sum+=arr[index];
   sumK(index+1,k,sum,arr,current);

   //skip
   sum-=arr[index];
   current.pop_back();
   sumK(index+1,k,sum,arr,current);
}
bool checksumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   //base case
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
   if(checksumK(index+1,k,sum,arr,current)) return true;

   //skip]
   sum-=arr[index];
   current.pop_back();
   if(checksumK(index+1,k,sum,arr,current)) return true;

   return false;
}

int countsumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   //bc
   if(index==arr.size()){
      if(sum==k){
         return 1;
      }
      return 0;
   }

   //pick
   current.push_back(arr[index]);
   sum+=arr[index];
   int left = countsumK(index+1,k,sum,arr,current);

   //skip
   sum-=arr[index];
   current.pop_back();
   int right=countsumK(index+1,k,sum,arr,current);
   return left+right;
}

void printBinaryStr(int index,int n,string& current){
   //base case
   if(index==n){
      cout<<current<<endl;
      return;
   }

   //pick 0
   current.push_back('0');
   printBinaryStr(index+1,n,current);
   current.pop_back();

   //pick 1
   current.push_back('1');
   printBinaryStr(index+1,n,current);
   current.pop_back();
}

void printBinaryNoConsecutive1(int index,int n,string&current){
   //base case
   if(index==n){
      cout<<current<<endl;
      return;
   }

    //pick 0
   current.push_back('0');
   printBinaryNoConsecutive1(index+1,n,current);
   current.pop_back();

   //pick 1
   if(current.empty() || current.back()!='1'){
      current.push_back('1');
      printBinaryNoConsecutive1(index+1,n,current);
      current.pop_back();
   }
   
}

void generateParenthesis(int open,int close,int n,string&current){
   //base case
   if(open==n && close==n){
      cout<<current<<endl;
      return;
   }

   if(open<n){
      current.push_back('(');
      generateParenthesis(open+1,close,n,current);
      current.pop_back();
   }

   if(close<open){
      current.push_back(')');
      generateParenthesis(open,close+1,n,current);
      current.pop_back();
   }
}

void letterCasePermutation(int index,string& s,string &current){
   //base
   if(s.size()==index){
      cout<<current<<endl;
      return;
   }

   if(isdigit(s[index])){
      current.push_back(s[index]);
      letterCasePermutation(index+1,s,current);
      current.pop_back();
   }else{
      current.push_back(tolower(s[index]));
      letterCasePermutation(index+1,s,current);
      current.pop_back();

      current.push_back(toupper(s[index]));
      letterCasePermutation(index+1,s,current);
      current.pop_back();
   }
}
int main(){
   string s="a1bc";
   string current;
   letterCasePermutation(0,s,current);
   return 0;
}
