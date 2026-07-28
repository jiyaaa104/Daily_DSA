#include<bits/stdc++.h>
using namespace std;
//1. NEXT GREATER ELEMENT
void nextGreaterElement(vector<int>arr){
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
int main(){
    vector<int>arr={4,12,5,3,1,2,5,3,1,2,4,6};
    nextGreaterElement(arr);
    return 0;
}