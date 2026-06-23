// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int n=arr.size();
//         int s=0,e=n-1;
//         if(k<arr[0]){
//             return k;
//         }
//         if(k>(arr[n-1]-n)){
//             return k+n;
//         }
//         int ans=-1;
//         while(s<=e){
//             int mid=s+(e-s)/2;
//             int miss=arr[mid]-(mid+1);
//             if(miss<k){
//                 s=mid+1;
//             }else{
//                 ans=mid;
//                 e=mid-1;
//             }
//         }return s+k;
//     }
// };