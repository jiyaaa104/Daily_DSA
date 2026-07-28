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
int main(){
    vector<int>arr={1,2,4,3,1};
    nextGreaterElement2(arr);
    return 0;
}