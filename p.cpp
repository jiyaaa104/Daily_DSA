#include<bits/stdc++.h>
using namespace std;
void generate(int n,string &current){
   if(current.size()==n){
      for(char ch: current){
         cout<<ch;
      }cout<<endl;
      return;
   }
   //pick 0
   current.push_back('0');
   generate(n,current);
   current.pop_back();

   //pick 1
   current.push_back('1');
   generate(n,current);
   current.pop_back();
}
void noConsecOnes(int n,string& current){
   if(current.size() == n){
      for(char ch: current){
         cout<<ch;
      }cout<<endl;
      return;
   }
   //pick 0
   current.push_back('0');
   noConsecOnes(n,current);
   current.pop_back();

   //pick 1
   if(current.empty() || current.back()!='1'){
      current.push_back('1');
      noConsecOnes(n,current);
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
   if(open>close){
      current.push_back(')');
      generateParenthesis(n,open,close+1,current);
      current.pop_back();
   }
}
void letterCasePerm(int index,string &s,string& current){
    if(s.size()==current.size()){
      cout<<current<<endl;
      return;
    }
    if(isdigit(s[index])){
      current.push_back(s[index]);
      letterCasePerm(index+1,s,current);
      current.pop_back();
    }else{
        current.push_back(tolower(s[index]));
      letterCasePerm(index+1,s,current);
      current.pop_back();

      current.push_back(toupper(s[index]));
      letterCasePerm(index+1,s,current);
      current.pop_back();
    }
}
void phoneNumber(int index,string &s,string &current,vector<string>&mapping){
   if(index==s.size()){
      cout<<current<<endl;
      return;
   }
   int d=s[index]-'0';
   string str=mapping[d];
   for(int i=0;i<str.size();i++){
      current.push_back(str[i]);
      phoneNumber(index+1,s,current,mapping);
      current.pop_back();
   }
}
void combinationSum1(int index,vector<int>&candidates,int target,vector<int>&current,int sum){
   if(index==candidates.size()){
      if(target==0){
      for(int x:current){
         cout<<x<<" ";
      }cout<<endl;
   }
   return;
   }
   if(candidates[index]<=target){
      current.push_back(candidates[index]);
      target-=candidates[index];
      sum+=candidates[index];
      combinationSum1(index,candidates,target,current,sum);
      sum-=candidates[index];
      target+=candidates[index];
      current.pop_back();
   }
   combinationSum1(index+1,candidates,target,current,sum);
}
void combinationSum2(int index,vector<int>&candidates,int target,vector<int>&current,int sum){
   if(target==0){
      for(int x:current){
         cout<<x<<" ";
      }cout<<endl;
      return;
   }
   for(int i=index;i<candidates.size();i++){
      if(i>index && candidates[i]==candidates[i-1]) continue;
      if(candidates[i]>target) break;
      if(candidates[i]<=target){
        current.push_back(candidates[i]);
      target-=candidates[i];
      sum+=candidates[i];
      combinationSum1(i+1,candidates,target,current,sum);
      sum-=candidates[i];
      target+=candidates[i];
      current.pop_back();
      }
   }
}
int main(){
   vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
   vector<int>current;
   string s="23";
   vector<int>a={2,3,5,6,7};
   combinationSum2(0,a,7,current,0);
   return 0;
}