//1. LEETCODE->3
// #include<bits/stdc++.h>
// using namespace std;
// int longestSubstringLength(string s){
//     int n=s.size();
//     int l=0,r=0,ans=0;
//     vector<int>mpp(256,-1);
//     while(r<n){
//         if(mpp[s[r]]!=-1 && mpp[s[r]]>=l){
//             l=mpp[s[r]]+1;
//         }
//         mpp[s[r]]=r;
//         int len=r-l+1;
//         ans=max(ans,len);
//         r++;
//     }return ans;
// }
//L-2401
//APPROACH: We maintain a used variable where we store the used bit positions which we try not find again.If we do then we reduce the window size from the left till used&new no.== 0.
// int longestNiceSubArray(vector<int>&nums){
//     int n=nums.size();
//     int l=0,r=0,ans=0,used=0;
//     while(r<n){
//         //When are we not inside the window-> as long as we dont find a number which doesnot have the bit 1 at same positions => (konsa bit set hai already)&naye no. agar not equal to zero aaya.that means we need to reduce the window size!
//         while((used&nums[r])!=0)
//         {
//         //purana set bits ko zero karte jaao!    
//             used^=nums[l];
//             l++;
//         //at max jaise hi r==l used=0    
//         }
//         //konsa positions occupied hai
//         used|=nums[r];
//         ans=max(ans,r-l+1);
//         r++;
//     }return ans;
// }
// int main(){
//     vector<int>nums={3,7,9};
//     int lower=1,upper=12;int l=lower;
//     vector<int>missing;int index=0;int n=nums.size();
//     while(l<=upper){
//            if(index<n && l<nums[index]){
//                missing.push_back(l);
//                l++;
//            }else if(index<n && l==nums[index]){
//                l++;index++;
//            }else{
//                missing.push_back(l);
//                l++;
//            }
//         }
//         for(int i=0;i<missing.size();i++){
//             cout<<missing[i]<<" ";
//         }
// }

//L-713
#include<bits/stdc++.h>
using namespace std;
//NUMBER OF SUBARRAY PRODUCT (STRICTLY!) LESSER THAN K
//->WHEN DO WE KNOW IF WHILE{WHILE} IS GOING TO WORK OR WHILE{IF-ELSE} IS GOING TO WORK?
//WHEN WE ARE SURE THAT ON REMOVING JUST ONE PERSON FROM THE SUBARRAY GIVES ME THE VALID SUBARRAY WE USE IF-ELSE INSIDE WHILE ELSE WE KEEP ON REMOVING FROM THE LEFT UNTIL WE ARE LEFT WITH A VALID SUBARRAY!
//EX=> {10,10,5,10000} K=5000 DO A DRY RUN
int function(vector<int>&nums,int k){
    int n=nums.size(),l=0,r=0,ans=0,product=1;
    while(r<n){
        product*=nums[r];
        while(l<n && product>=k){
            product/=nums[l];
            l++;
        }
        ans+=r-l+1;
        r++;
    }
    return ans;
}
int main(){
    return 0;
}