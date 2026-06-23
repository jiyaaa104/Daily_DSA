#include<bits/stdc++.h>
using namespace std;
long long countFairPairs(vector<int>&nums,int lower,int upper){
    int n=nums.size();
    long long lesserEqualToUpper=0;
    sort(nums.begin(),nums.end());
    int left=0,right=n-1;
    while(left<right){
      int sum=nums[left]+nums[right];
      if(sum>upper){
        right--;
      }else{
        lesserEqualToUpper+=right-left;
        left++;
      }
    }
    long long lesserToLower=0;
 left=0,right=n-1;
    while(left<right){
        int sum=nums[left]+nums[right];
        if(sum>=lower){
            right--;
        }else{
           lesserToLower+=right-left;
           left++;
        }
    }
    return lesserEqualToUpper-lesserToLower;


}
int main(){
    vector<int>nums={-1,-2,0,1,3,5,5,5,7,9};
    cout<<countFairPairs(nums,4,6);
    return 0;
}