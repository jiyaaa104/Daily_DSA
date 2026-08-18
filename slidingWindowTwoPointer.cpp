//1. LEETCODE->3
#include<bits/stdc++.h>
using namespace std;
int longestSubstringLength(string s){
    int n=s.size();
    int l=0,r=0,ans=0;
    vector<int>mpp(256,-1);
    while(r<n){
        if(mpp[s[r]]!=-1 && mpp[s[r]]>=l){
            l=mpp[s[r]]+1;
        }
        mpp[s[r]]=r;
        int len=r-l+1;
        ans=max(ans,len);
        r++;
    }return ans;
}
int main(){
    return 0;
}