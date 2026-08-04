#include <bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int>&nums){
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
  }return ans;
}
vector<int> nse(vector<int>&nums){
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
  }return ans;
}
vector<int> pge(vector<int>&nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=0;i<n;i++){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first<= nums[i]){
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
vector<int> pse(vector<int>&nums){
  int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
  for(int i=0;i<n;i++){
    if(st.empty()){
      ans[i]=-1;
    }else{
      while(!st.empty() && st.top().first> nums[i]){
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
vector<int> prefixMax(vector<int>&nums){
  int n=nums.size();vector<int>ans(n);
  ans[0]=nums[0];
  for(int i=1;i<n;i++){
    ans[i]=max(ans[i-1],nums[i]);
  }return ans;
}
vector<int> suffixMax(vector<int>&nums){
  int n=nums.size();vector<int>ans(n);ans[n-1]=nums[n-1];
  for(int i=n-2;i>=0;i--){
    ans[i]=max(ans[i+1],nums[i]);
  }return ans;
}
int trappingRainWater(vector<int>&nums){
  // int n=nums.size();
  // int left=-1;
  // vector<int>right=prefixMax(nums);
  // int total=0;
  // for(int i=0;i<n;i++){
  //   left=max(left,nums[i]);
  //   int hWater=min(left,right[i])-nums[i];
  //   if(hWater>0){
  //     total+=hWater;
  //   }
  // }return total;
  int n=nums.size();int l=0,r=n-1,lMax=0,rMax=0,total=0;
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
  }return total; 
}
static int const MOD=1000000007;
int sumSubarrayMin(vector<int>&nums){
  int n=nums.size();
  vector<int>leftSmall=pse(nums);
  vector<int>rightSmall=nse(nums);int total=0;
  for(int i=0;i<n;i++){
    int ls=leftSmall[i];
    int rs=(rightSmall[i]==-1)?n:rightSmall[i];
    total=(total+(1LL*((((i-ls)*(rs-i))%MOD)*nums[i])%MOD))%MOD;
  }return total;
}
vector<int> asteroidCollision(vector<int>&asteroids){
  int n=asteroids.size();
  stack<int>st;
  vector<int>ans;
  for(int i=0;i<n;i++){
    if(asteroids[i]>=0){
      st.push(asteroids[i]);
    }else{
      if(!st.empty() && st.top()<0){
        st.push(asteroids[i]);continue;
      }
      while(!st.empty() && st.top()>=0 && st.top()<-asteroids[i]){
        st.pop();
      }
      if(!st.empty() && st.top()==-asteroids[i]){
        st.pop();
      }
      else if(!st.empty() && st.top()<0){
        st.push(asteroids[i]);
      }else if(st.empty()){
        st.push(asteroids[i]);
      }
    }
  }
  while(!st.empty()){
    ans.push_back(st.top());st.pop();
  }
  reverse(ans.begin(),ans.end());return ans;
}
string removeKDigits(string s,int k){
  stack<char>st;int n=s.size();string ans;
  if(k==n){
    return "0";
  }
  for(int i=0;i<n;i++){
    while(!st.empty() && st.top()>s[i] && k>0){
      st.pop();k--;
    }
    st.push(s[i]);
  }
  while(k!=0){
    st.pop();k--;
  }
  while(!st.empty()){ans.push_back(st.top());st.pop();}
  for(int i=ans.size()-1;i>=0;i--){
    if(ans[i]=='0'){
      ans.pop_back();
    }else{
      break;
    }
  }
  reverse(ans.begin(),ans.end());
  if(ans.empty())return "0";
  return ans;
}
int largestRectangleHistogram(vector<int>&nums){
  int n=nums.size();stack<int>st;int lArea=-1;
  for(int i=0;i<n;i++){
    while(!st.empty() && (nums[st.top()]>nums[i])){
      int len=nums[st.top()];st.pop();
      int ns=i;
      int ps=-1;
      if(!st.empty()){
        ps=st.top();
      }
      int area=len*(ns-ps-1);
      lArea=max(lArea,area);
    }
    st.push(i);
  }
  while(!st.empty()){
    int len=nums[st.top()];st.pop();
    int ns=n;
    int ps=-1;
    if(!st.empty()){ps=st.top();}
    int area=len*(ns-ps-1);
    lArea=max(lArea,area);
  }
  return lArea;
}
int largestRH(vector<int>&mat,int c){
  stack<int>st;int lArea=0;
  for(int i=0;i<c;i++){
    while(!st.empty() && mat[st.top()]>=mat[i]){
      int ns=i;
      int len=mat[st.top()];st.pop();
      int ps=-1;
      if(!st.empty()){ps=st.top();}
      int area=len*(ns-ps-1);
      lArea=max(lArea,area);
    }
    st.push(i);
  }
  while(!st.empty()){
    int ns=c;int ps=-1;
    int len=mat[st.top()];st.pop();
    if(!st.empty()){ps=st.top();}
    int area=len*(ns-ps-1);
    lArea=max(area,lArea);
  }return lArea;
}
int maximalRectangle(vector<vector<char>>&matrix){
    int r=matrix.size();int c=matrix[0].size(),lArea=0;
    vector<int>mat(c,0);
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(matrix[i][j]=='1'){
          mat[j]++;
        }else{
          mat[j]=0;
        }
      }
      lArea=max(lArea,largestRH(mat,c));
    }return lArea;
}
int main(){
  
  vector<int>nums={2,3,5};
  cout<<largestRectangleHistogram(nums);
  return 0;
}