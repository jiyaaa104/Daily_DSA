#include<bits/stdc++.h>
using namespace std;
void nextGreaterElement1(vector<int>nums){
  int n=nums.size();stack<int>st;vector<int>ans(n);
  for(int i=n-1;i>=0;i--){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top()<=nums[i]){
        st.pop();
      }
      if(st.empty()){
        ans[i]=-1;
      }else{
        ans[i]=st.top();
      }
    }
    st.push(nums[i]);
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
}
void nextGreaterElement2(vector<int>nums){
  stack<int>st;int n=nums.size();vector<int>ans(n);
  for(int i=2*n-1;i>=0;i--){
    if(st.empty()){
      ans[i%n]=-1;
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
  }
}
int nextGreaterElement3(int n){
  string s=to_string(n);
  int l=s.size();
  int breakIndex=-1;
  if(l==1){
    return -1;
  }
  for(int i=l-2;i>=0;i--){
    if(s[i]<s[i+1]){
      breakIndex=i;
      break;
    }
  }
  if(breakIndex==-1){
    return -1;
  }
  for(int i=l-1;i>breakIndex;i--){
    if(s[i]>s[breakIndex]){
      swap(s[i],s[breakIndex]);
      break;
    }
  }
  reverse(s.begin()+breakIndex+1,s.end());
  long long ans=0;
  for(int i=0;i<l;i++){
    ans=ans*10+(s[i]-'0');
  }
  if(ans>INT_MAX){
    return -1;
  }else{
    return ans;
  }
}
vector<int>prefixMax(vector<int>nums){
  int n=nums.size();
  vector<int>ans(n);
  ans[0]=nums[0];
  for(int i=1;i<n;i++){
    ans[i]=max(ans[i-1],nums[i]);
  }return ans;
}
vector<int>suffixMax(vector<int>nums){
  int n=nums.size();
  vector<int>ans(n);
  ans[n-1]=nums[n-1];
  for(int i=n-2;i>=0;i--){
    ans[i]=max(ans[i+1],nums[i]);
  }return ans;
}
int trappingRainWater(vector<int>nums){
  int n=nums.size();
  int l=0,r=n-1,lMax=0,rMax=0,total=0;
  while(l<r){
     if(nums[l]<nums[r]){
      if(nums[l]<lMax){
        total+=(lMax-nums[l]);
      }else{
        lMax=nums[l];
      }
      l++;
     }else{
      if(nums[r]<rMax){
        total+=(rMax-nums[r]);
      }else{
        rMax=nums[r];
      }
      r--;
     }
  }return total;
}
int main(){
  vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<trappingRainWater(arr);
  return 0;
}