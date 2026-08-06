#include<bits/stdc++.h>
using namespace std;
vector<int>nge(vector<int>&nums){
  int n=nums.size();vector<int>ans(n);stack<pair<int,int>>st;
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
  }return ans;
}
vector<int>nse(vector<int>&nums){
  int n=nums.size();vector<int>ans(n);stack<pair<int,int>>st;
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
  }return ans;
}
vector<int>pge(vector<int>&nums){
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
vector<int>pse(vector<int>&nums){
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
vector<int>prefixMax(vector<int>&nums){
  int n=nums.size();
  vector<int>ans(n);
  ans[0]=nums[0];
  for(int i=1;i<n;i++){
    ans[i]=max(nums[i],ans[i-1]);
  }return ans;
}
vector<int>suffixMax(vector<int>&nums){
  int n=nums.size();vector<int>ans(n);
  ans[n-1]=nums[n-1];
  for(int i=n-2;i>=0;i--){
    ans[i]=max(ans[i+1],nums[i]);
  }return ans;
}
int trappingRainWater(vector<int>&nums){
  int n=nums.size();
  vector<int>left=prefixMax(nums);
  vector<int>right=suffixMax(nums);
  int total=0;
  for(int i=0;i<n;i++){
    int hWater=min(left[i],right[i])-nums[i];
    if(hWater>0){
      total+=hWater;
    }
  }return total;
}
static int const MOD=1000000007;
int sumSubArrayMin(vector<int>&nums){
  int n=nums.size();
  int ans=0;
  vector<int>leftSmall=pse(nums);
  vector<int>rightSmall=nse(nums);
  for(int i=0;i<n;i++){
    int ls=leftSmall[i];
    int rs=(rightSmall[i]==-1)?n:rightSmall[i];
    ans=(ans+(1LL*(((((i-ls)*(rs-i))%MOD)*nums[i])%MOD)))%MOD;
  }return ans;
}
vector<int> asteroidCollision(vector<int>&asteroids){
  int n=asteroids.size();
  stack<int>st;vector<int>ans;
  for(int i=0;i<n;i++){
    if(asteroids[i]>=0){
      st.push(asteroids[i]);
    }else{
      while(!st.empty() && st.top()>=0 && st.top()<-asteroids[i]){
      st.pop();
    }
    if(st.empty() || st.top()<0){
      st.push(asteroids[i]);
    }
    else if(!st.empty() && st.top()==-asteroids[i]){
      st.pop();
    }
    }
  }
  while(!st.empty()){
    ans.push_back(st.top());st.pop();
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

int main(){
  return 0;
}