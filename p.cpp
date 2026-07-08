#include<bits/stdc++.h>
using namespace std;
bool twoSum(vector<int>arr,int target){
   int n=arr.size();
   unordered_map<int,int>mpp;
   for(int i=0;i<n;i++){
      int complement=target-arr[i];
      if(mpp.find(complement)!=mpp.end()){
         return true;
      }
      mpp[arr[i]]=i;
   }return false;
}
void sort012(vector<int>arr){
   int n=arr.size();
   int low=0,mid=0,high=n-1;
   while(mid<=high){
      if(arr[mid]==0){
         swap(arr[low],arr[mid]);
         low++;mid++;
      }else if(arr[mid]==1){
         mid++;
      }else{
         swap(arr[mid],arr[high]);
         high--;
      }
   }
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }cout<<endl;
   return;
}
int majorityElement(vector<int>arr){
   int n=arr.size();
   int count=1,el=arr[0];
   for(int i=1;i<n;i++){
      if(count==0){
         el=arr[i];
      }
      if(el==arr[i]){
         count++;
      }else{
         count--;
      }
   }
   int c=0;
   for(int i=0;i<n;i++){
      if(el==arr[i])c++;
   }
   if(c>n/2)return el;
   return -1;
}
int maxSubArraySum(vector<int>arr){
   int sum=0,maxi=INT_MIN;
   int n=arr.size();
   for(int i=0;i<n;i++){
     sum+=arr[i];
     if(sum>maxi){
      maxi=sum;
     }
     if(sum<0){
      sum=0;
     }
   }return maxi;
}
void printKadane(vector<int>arr){
   int n=arr.size();
   int sum=0,maxi=INT_MIN;
   int left=-1,right=-1,bestLeft=-1;
   for(int i=0;i<n;i++){
      sum+=arr[i];
      if(sum<0){
         sum=0;
         left=i+1;
      }
      if(sum>maxi){
         maxi=sum;
         bestLeft=left;
         right=i;
      }
   }
   for(int i=bestLeft;i<=right;i++){
     cout<<arr[i]<<" ";
   }cout<<endl;
   return;
}
int stockBuyAndSell(vector<int>arr){
   int n=arr.size(),bestBuy=arr[0],maxProfit=INT_MIN;
   for(int i=1;i<n;i++){
      bestBuy=min(bestBuy,arr[i]);
      maxProfit=max(maxProfit,arr[i]-bestBuy);
   }return maxProfit;
}
void rearrange(vector<int>arr){
   int s=arr.size();
   vector<int>pos;vector<int>neg;
   for(int i=0;i<s;i++){
     if(arr[i]>=0){
      pos.push_back(arr[i]);
     }else{
      neg.push_back(arr[i]);
     }
   }
   int p=0,n=0,i=0;
   while(p!=pos.size() && n!=neg.size()){
      if(i%2==0){
         arr[i]=pos[p];
         i++;p++;
      }else{
         arr[i]=neg[n];
         i++;n++;
      }
   }
   while(p!=pos.size()){
      arr[i]=pos[p];
      i++;p++;
   }
   while(n!=neg.size()){
      arr[i]=neg[n];
      i++;n++;
   }
   for(int i=0;i<s;i++){
      cout<<arr[i]<<" ";
   }cout<<endl;
   return;
}
int main(){
   // vector<int>a1={1,2,3,4,5,6,7,8,9,10};
   // cout<<twoSum(a1,18);
   // vector<int>a2={1,1,1,1,2,2,2,2,0,0,0};
   // sort012(a2);
   // vector<int>a3={1,2,4,4,2,4,4,4,3,4,4};
   // cout<<majorityElement(a3);
   // vector<int>a4={1,-2,3,3,4,5,-2,6};
   // cout<<maxSubArraySum(a4);
   // vector<int>a5={1,-2,3,3,4,5,-2,6};
   // printKadane(a5);
   // vector<int>a6={1,7,2,5,6,8,1};
   // cout<<stockBuyAndSell(a6);
   vector<int>a7={1,2,3,4,-1,-2,-3,8,9};
   rearrange(a7);
   return 0;
}