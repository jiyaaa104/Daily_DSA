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
int main(){
   vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<trappingRainWater(arr);
    return 0;
}