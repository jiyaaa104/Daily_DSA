#include<bits/stdc++.h>
using namespace std;
int longestSubstring(string s){
    int n=s.size();
    vector<int>mpp(256,-1);
    int l=0,r=0,ans=0;
    while(r<n){
        if(mpp[s[r]]!=-1 && mpp[s[r]]>=l){
            l=mpp[s[r]]+1;
        }
        int len=r-l+1;
        ans=max(ans,len);
        mpp[s[r]]=r;
        r++;
    }return ans;
}
int main(){
    return 0;
}