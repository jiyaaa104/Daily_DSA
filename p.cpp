#include<bits/stdc++.h>
using namespace std;
void subsets(vector<int>nums){
    int n=nums.size();
    int subset=1<<n;
    vector<vector<int>>ans;
    for(int i=0;i<subset;i++){
        vector<int>a;
        for(int index=0;index<n;index++){
            if(i&(1<<index)){
              a.push_back(nums[index]);
            }
        }
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
}
int singleNumber(vector<int>nums){
    // int n=nums.size();
    // long long ans=0,place=1;
    // for(int i=0;i<32;i++){
    //     int count=0;
    //     for(int index=0;index<n;index++){
    //         if(nums[index]&(1<<i))count++;
    //     }
    //     int rem=0;
    //     if(count%3!=0){
    //         rem=1;
    //     }
    //     ans=ans+place*rem;
    //     place*=2;
    // }
    // return ans;
    // sort(nums.begin(),nums.end());
    // int n=nums.size();
    // int ans=nums[n-1];
    // int index=1;
    // while(index<n){
    //     if(nums[index]!=nums[index-1]){
    //         ans=nums[index];
    //         break;
    //     }
    //     index+=3;
    // }return ans;
    int once=0,twice=0;
    for(int i=0;i<nums.size();i++){
        once=(once^nums[i])&(~twice);
        twice=(twice^nums[i])&(~once);
    }return once;
}
int main(){
    vector<int>nums={1,2,3,1,2,1,2};
    cout<<singleNumber(nums);
    return 0;
}