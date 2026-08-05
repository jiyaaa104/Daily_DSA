#include<bits/stdc++.h>
using namespace std;
//1. NEXT GREATER ELEMENT
void nextGreaterElement1(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=-1;
        }else{
            while(!st.empty() && st.top()<=arr[i]){
               st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
        }
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}
//L-503
void nextGreaterElement2(vector<int>arr){
    int n=arr.size();
   vector<int>ans(n);stack<int>st;
   for(int i=2*n-1;i>=0;i--){
    if(st.empty()){
      ans[i%n]=-1;
    }else{
        while(!st.empty() && st.top()<=arr[i%n]){
            st.pop();
        }
        if(st.empty()){
            ans[i%n]=-1;
        }else{
            ans[i%n]=st.top();
        }
    }
    st.push(arr[i%n]);
   }
   for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
   }
}
int nextGreaterElement3(int n){
    string s=to_string(n);
    int l=s.size();
    int breakIndex=-1;
    for(int i=l-2;i>=0;i--){
       if(s[i]<s[i+1]){
        breakIndex=i;
        break;
       }
    }
    if(breakIndex==-1){
        return -1;
    }
    for(int i=l-1;i>=breakIndex;i--){
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
    if(ans>INT_MAX)return -1;
    return (int)ans;
}
void nextSmallerElement(vector<int>arr){
    int n=arr.size();stack<int>st;vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=-1;
        }else{
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
        }
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void numberOfNextGreaterElements(vector<int>arr){
    int n=arr.size();vector<int>ans(n);stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=0;
        }else{
            while(!st.empty() && st.top()<=arr[i]){
              st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }else{
                ans[i]=st.size();
            }
        }
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}
vector<int>prefixMax(vector<int>nums){
    int n=nums.size();vector<int>ans(n);
    ans[0]=nums[0];
    for(int i=1;i<n;i++){
        ans[i]=max(ans[i-1],nums[i]);
    }
    return ans;
}
vector<int>suffixMax(vector<int>nums){
    int n=nums.size();
    vector<int>ans(n);
    ans[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i]=max(nums[i],ans[i+1]);
    }return ans;
}
int trappingRainWater(vector<int>nums){
    //TAKES SPACE O(2N)
    // int n=nums.size();
    // vector<int>left(n);
    // vector<int>right(n);
    // left=prefixMax(nums);
    // right=suffixMax(nums);
    // int total=0;
    // for(int i=0;i<n;i++){
    //   int heightWater=min(left[i],right[i]);
    //   if(heightWater>nums[i]){
    //        total+=(heightWater-nums[i]);
    //   }
    // }return total;

    //TAKES SC=>0(N)
    // int n=nums.size();
    // vector<int>right(n);
    // right=suffixMax(nums);
    // int left=-1,total=0;
    // for(int i=0;i<n;i++){
    //     left=max(left,nums[i]);
    //     int hWater=min(left,right[i]);
    //     if(hWater>nums[i]){
    //         total+=(hWater-nums[i]);
    //     }
    // }return total;

    int n=nums.size();
    int l=0,r=n-1,lMax=0,rMax=0,total=0;
    while(l<r){
        if(nums[l]<=nums[r]){
            if(lMax>nums[l]){
                total+=lMax-nums[l];
            }else{
                lMax=nums[l];
            }
            l++;
        }else{
            if(rMax>nums[r]){
                total+=rMax-nums[r];
            }else{
                rMax=nums[r];
            }
            r--;
        }
    }return total;
}
vector<int> nse(vector<int>&nums){
    int n=nums.size();
    stack<pair<int,int>>st;vector<int>ans(n);
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
vector<int> nge(vector<int>&nums){
    int n=nums.size();
    stack<pair<int,int>>st;vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
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
vector<int> pse(vector<int>&nums){
    int n=nums.size();stack<pair<int,int>>st;vector<int>ans(n);
    for(int i=0;i<n;i++){
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
vector<int> pge(vector<int>&nums){
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
    }
    return ans;
}
int sumSubArrayMinimum(vector<int>&nums){
  int n=nums.size();
  vector<int>left=pse(nums);
  vector<int>right=nse(nums);
  long long ans=0;
  for(int i=0;i<n;i++){
    int l=-1,r=n;
    if(left[i]!=-1){
        l=left[i];
    }
    if(right[i]!=-1){
       r= right[i];
    }
    ans+=(i-l)*(r-i)*nums[i];
  }
  int a=ans%(1000000007);
  return a;
}
long long sumSubarrayRange(vector<int>&nums){
    long long ans=0;int n=nums.size();
    vector<int>lsmall=pse(nums);
    vector<int>lgreat=pge(nums);
    vector<int>rsmall=nse(nums);
    vector<int>rgreat=nge(nums);
    for(int i=0;i<n;i++){
        int ls=(lsmall[i]==-1)?-1:lsmall[i];
        int lg=(lgreat[i]==-1)?n:lgreat[i];
        int rs=(rsmall[i]==-1)?-1:rsmall[i];
        int rg=(rgreat[i]==-1)?n:rgreat[i];
        ans=(ans+1LL*(i-lg)*(rg-i)*nums[i]);
        ans=(ans-1LL*(i-ls)*(rs-i)*nums[i]);
    }return ans;
}
vector<int> asteroidCollision(vector<int>asteroids){
    stack<int>st;vector<int>ans;int n=asteroids.size();
    for(int i=0;i<n;i++){
        if(asteroids[i]>=0){
            st.push(asteroids[i]);
        }else{
            if(!st.empty() && st.top()<0){
                st.push(asteroids[i]);continue;
            }
            while(!st.empty() && st.top() >=0 && st.top()<-asteroids[i]){st.pop();}
            if(!st.empty() && st.top()==-asteroids[i]){st.pop();continue;}
            if(st.empty() || st.top()<0){
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
int largestRectangleHistogram(vector<int>&heights){
    // int n=heights.size();
    // vector<int>prevSmall=pse(heights);
    // vector<int>nextSmall=nse(heights);
    // int largestArea=-1;
    // for(int i=0;i<n;i++){
    //    int ps=prevSmall[i];
    //    int ns=(nextSmall[i]==-1)?n:nextSmall[i];
    //    int breadth=(ns-(ps+1));
    //    int area=heights[i]*breadth;
    //    largestArea=max(area,largestArea);
    // }return largestArea;

    int n=heights.size();
    stack<int>st;int lArea=-1;
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int len=heights[st.top()];st.pop();
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
        int len=heights[st.top()];st.pop();
        int ns=n;
        int ps=-1;
        if(!st.empty()){
            ps=st.top();
        }
        int area=len*(ns-ps-1);
        lArea=max(lArea,area);
    }return lArea;
}
int largestHistogram(vector<int>&nums){
    int n=nums.size();
    stack<int>st;int lArea=0;
    for(int i=0;i<n;i++){
      while(!st.empty() && nums[st.top()]>=nums[i]){
        int ns=i,ps=-1,len=nums[st.top()];st.pop();
        if(!st.empty()){
            ps=st.top();
        }
        int area=len*(ns-ps-1);
        lArea=max(lArea,area);
      }
      st.push(i);
    }
    while(!st.empty()){
        int ns=n,ps=-1,len=nums[st.top()];st.pop();
        if(!st.empty()){
            ps=st.top();
        }
        lArea=max(lArea,len*(ns-ps-1));
    }return lArea;
}
int maximalRectangle(vector<vector<char>>&matrix){
    int r=matrix.size(),c=matrix[0].size();
    vector<int>height(c,0);
    int lArea=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]=='1'){
                height[j]++;
            }else{
                height[j]=0;
            }
        }
        lArea=max(lArea,largestHistogram(height));
    }return lArea;
}
int main(){
   vector<int>arr={2,3,5};
   cout<<largestRectangleHistogram(arr);
    return 0;
}