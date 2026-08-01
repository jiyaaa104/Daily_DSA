#include<bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int>nums){
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
vector<int> nse(vector<int>nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=n-1;i>=0;i--){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first>=nums[i]){
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
vector<int> pge(vector<int>nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=0;i<n;i++){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first<nums[i]){
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
vector<int> pse(vector<int>nums){
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
  }
  return ans;
}
void nextGreaterEl2(vector<int>nums){
  int n=nums.size();stack<int>st;vector<int>ans(n);
  for(int i=2*n-1;i>=0;i--){
    if(st.empty()){
      ans[i%n]=i;
    }else{
      while(!st.empty() && st.top()<=nums[i%n]){
        st.pop();
      }
      if(st.empty()){
        ans[i%n]=-1;
      }else{
        ans[i%n]=st.top();
      }
    }
    st.push(nums[i%n]);
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
}
int nextGreaterEl3(int n){
  string s=to_string(n);
  int l=s.size(),bIndex=-1;
  if(l==1){
    return -1;
  }
  for(int i=l-2;i>=0;i--){
    if(s[i]<s[i+1]){
      bIndex=i;
      break;
    }
  }
  if(bIndex==-1){
    return -1;
  }
  for(int i=l-1;i>bIndex;i--){
    if(s[i]>s[bIndex]){
      swap(s[i],s[bIndex]);
      break;
    }
  }
  reverse(s.begin()+bIndex+1,s.end());
  long long ans=0;
  for(int i=0;i<l;i++){
    ans=10*ans+(s[i]-'0');
  }
  if(ans>INT_MAX){
    return -1;
  }
  return ans;
}
static int const MOD=1000000007;
int subArrayMinimumSum(vector<int>nums){
  int n=nums.size();
  vector<int>leftGreat=pse(nums);
  vector<int>rightGreat=nse(nums);
  int total=0;
  for(int i=0;i<n;i++){
    int lg=(leftGreat[i]==-1)?-1:leftGreat[i];
    int rg=(rightGreat[i]==-1)?n:rightGreat[i];
    total=(total+(1LL*(((i-lg)*(rg-i))%MOD)*nums[i])%MOD)%MOD;
  }return total;
}
int trappingRainWater(vector<int>nums){
  int n=nums.size();
  int l=0,r=n-1,lMax=0,rMax=0,total=0;
  while(l<r){
    if(nums[l]<nums[r]){
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
string removeKdigits(string s,int k){
  int n=s.size();string ans;stack<char>st;
  if(k==n){
    return "0";
  }
  for(int i=0;i<n;i++){
    if(st.empty() || k==0 || st.top()<=s[i]){
      st.push(s[i]);
    }else{
      while(k>0 && !st.empty() && st.top()>s[i]){
        st.pop();k--;
      }st.push(s[i]);
    }
  }
  while(k>0 && !st.empty()){
    st.pop();k--;
  }
  while(!st.empty()){
    ans.push_back(st.top());st.pop();
  }
  for(int i=ans.size()-1;i>=0;i--){
    if(ans[i]=='0'){
      ans.pop_back();
    }else{
      break;
    }
  }
  if(ans.size()==0){
    return "0";
  }
  reverse(ans.begin(),ans.end());
  return ans;
}
int main(){
  // vector<int>arr={1,2,3,4,3,2,1};
  // nextGreaterEl2(arr);
  // int num=1232340;
  // cout<<nextGreaterEl3(num);
  string s="1422319";
  cout<<removeKdigits(s,3);
  return 0;
}