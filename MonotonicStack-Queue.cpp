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

int main(){
   vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<trappingRainWater(arr);
    return 0;
}