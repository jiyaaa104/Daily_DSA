#include<bits/stdc++.h>
using namespace std;
vector<int>nge(vector<int>nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=n-1;i>=0;i--){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first<=nums[i]){
        st.pop();
      }
      if(st.empty()){
        ans[i]=-1;
      }else{
        ans[i]=st.top().second;
      }
    }
    st.push({nums[i],i});
  }
  return ans;
}
vector<int>nse(vector<int>nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=n-1;i>=0;i--){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first>nums[i]){
        st.pop();
      }
      if(st.empty()){
        ans[i]=-1;
      }else{
        ans[i]=st.top().second;
      }
    }
    st.push({nums[i],i});
  }
  return ans;
}
vector<int>pge(vector<int>nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=0;i<n;i++){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first<=nums[i]){
        st.pop();
      }
      if(st.empty()){
        ans[i]=-1;
      }else{
        ans[i]=st.top().second;
      }
    }
    st.push({nums[i],i});
  }return ans;
}
vector<int>pse(vector<int>nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=0;i<n;i++){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first>nums[i]){
        st.pop();
      }
      if(st.empty()){
        ans[i]=-1;
      }else{
        ans[i]=st.top().second;
      }
    }
    st.push({nums[i],i});
  }return ans;
}
int trappingRainwater(vector<int>nums){
  int n=nums.size();
  int l=0,r=n-1,lMax=0,rMax=0,total=0;
  while(l<r){
    if(nums[l]<=nums[r]){
      if(nums[l]<lMax){
        total+=lMax-nums[l];
      }else{
        lMax=nums[l];
      }
      l++;
    }else{
      if(nums[r]<rMax){
        total+=rMax-nums[r];
      }else{
        rMax=nums[r];
      }
      r--;
    }
  }
  return total;
}
static int const MOD=1000000007;
int subarrayMinSum(vector<int>nums){
  int total=0,n=nums.size();
  vector<int>left=pse(nums);
  vector<int>right=nse(nums);
  for(int i=0;i<n;i++){
    int ls=left[i];
    int rs=(right[i]==-1)?n:right[i];
    total=(total+(1LL*((((i-ls)*(rs-i))%MOD)*nums[i])%MOD))%MOD;
  }return total;
}
vector<int>asteroidCollision(vector<int>asteroids){
  int n=asteroids.size();
  stack<int>st;vector<int>ans;
  for(int i=0;i<n;i++){
    if(asteroids[i]>=0){
      st.push(asteroids[i]);
    }else{
      if(!st.empty() && st.top()<0){
        st.push(asteroids[i]);
        continue;
      }
      while(!st.empty() && st.top()>=0 && st.top()<-asteroids[i]){
        st.pop();
      }
      if(st.empty()){
        st.push(asteroids[i]);
      }else if(!st.empty() && st.top()==-asteroids[i]){
        st.pop();
        continue;
      }else if(!st.empty() && st.top()<0){
        st.push(asteroids[i]);
      }
    }
  }
  while(!st.empty()){
    ans.push_back(st.top());st.pop();
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
string removeKdigits(string s,int k){
   int n=s.size();
   if(k==n){
    return "0";
   }
   stack<char>st;string ans;
   for(int i=0;i<n;i++){
    if(st.empty() || st.top()<=s[i] || k==0){
      st.push(s[i]);
    }else{
      while(!st.empty() && st.top()>s[i] && k>0){
        st.pop();
        k--;
      }
      st.push(s[i]);
    }
   }
   while(k!=0){
    st.pop();k--;
     }
   while(!st.empty()){
    ans.push_back(st.top());st.pop();
   }
   while(!ans.empty() && ans.back()=='0'){
    ans.pop_back();
   }
   if(ans.empty())return "0";
   reverse(ans.begin(),ans.end());
   return ans;
}
int main(){
  string s="10203456";
  cout<<removeKdigits(s,3);
  return 0;
}