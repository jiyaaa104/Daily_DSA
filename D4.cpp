//-----------------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// void printVec(vector<vector<int>>vec){
//     int n=vec.size();
//     int m=vec[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<vec[i][j]<<" ";
//         }cout<<endl;
//     }
// }
// void transpose(vector<vector<int>>&vec){
//     int n=vec.size();
//     int m=vec[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//           swap(vec[i][j],vec[j][i]);
//         }
//     }
// }
// void revRow(vector<vector<int>>&vec){
//     int n=vec.size();
//     int m=vec[0].size();
//     for(int i=0;i<n;i++){
//         int s=0,e=m-1;
//         while(s<e){
//           swap(vec[i][s],vec[i][e]);
//           s++;e--;
//         }
//     }
// }
// void rotate90(vector<vector<int>>&vec){
//     transpose(vec);
//     revRow(vec);
// }
// int main()
// {
//     vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};
//     rotate90(matrix);
//     printVec(matrix);
//     return 0;
// }

//-----------------------------------2
// #include<bits/stdc++.h>
// using namespace std;
// void spiral(vector<vector<int>>&vec){
//     int n=vec.size();
//     int m=vec[0].size();
//     int left=0,top=0,right=m-1,bottom=n-1;
//     while(top<=bottom && left<=right){
//         for(int i=left;i<=right;i++){
//             cout<<vec[top][i]<<" ";
//         }
//         top++;
//         for(int i=top;i<=bottom;i++){
//             cout<<vec[i][right]<<" ";
//         }
//         right--;
//         if(top<=bottom){
//             for(int i=right;i>=left;i--){
//                 cout<<vec[bottom][i]<<" ";
//             }
//             bottom--;
//         }
//         if(left<=right){
//             for(int i=bottom;i>=top;i--){
//                 cout<<vec[i][left]<<" ";
//             }
//             left++;
//         }
//     }
// }
// int main()
// {
//     vector<vector<int>>vec={ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } };
//     spiral(vec);
//     return 0;
// }

//----------------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// int countSubSum(vector<int>&vec,int k){
//     int n=vec.size();
//     map<int,int>mpp;
//     mpp[0]++;
//     int prefix=0,count=0;
//     for(int i=0;i<n;i++){
//        prefix+=vec[i];
//        int rem=prefix-k;
//        count+=mpp[rem];
//        mpp[prefix]++;
//     }return count;
// }
// int main()
// {
//     vector<int>arr={1,2,3,-3,4,5,-6,3,3,3};
//     cout<<countSubSum(arr,3);
//     return 0;
// }

//----------------------------------4
// #include<bits/stdc++.h>
// using namespace std;
// int fact(int n){
//     if(n==0||n==1){
//         return n;
//     }
//         return n*fact(n-1);
// }
// int brute(int r,int c){
//     int num=fact(r-1);
//     int den=fact(c-1)*fact(r-c);
//     return num/den;
// }
// int better(int r,int c){
//     r--;
//     c--;
//     int a=c;
//     int b=r-c;
//     int mini=min(a,b);
//     int ans=1;
//     for(int i=1;i<=mini;i++){
//       ans*=(r-(i-1));
//       ans/=i;
//     }return ans;
// }
// int main()
// {
//     cout<<better(5,3);
//     return 0;
// }

//---------------------------------5
// #include<bits/stdc++.h>
// using namespace std;
// void optimal(int arr[],int n){
//     int c1=0,c2=0,e1=INT_MIN,e2=INT_MIN;
//     vector<int>v;
//     for(int i=0;i<n;i++){
//         if(c1==0 && arr[i]!=e2){
//            e1=arr[i];
//         }
//         else if(c2==0 && arr[i]!=e1){
//             e2=arr[i];
//         }
//         if(e1==arr[i]){
//             c1++;
//         }
//         else if(arr[i]==e2){
//             c2++;
//         }
//         else{
//             c1--;c2--;
//         }
//     }
//     int a1=0,a2=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==e1){
//             a1++;
//         }else if(arr[i]==e2){
//             a2++;
//         }
//     }
//     if(a1>n/3){
//         cout<<e1<<" ";
//     }
//     if(a2>n/3){
//         cout<<e2<<" ";
//     }
// }
// int main()
// {
//     int arr[]={1,1,1,2,2};
//     optimal(arr,6);
//     return 0;
// }

//--------------------------------6
// #include<bits/stdc++.h>
// using namespace std;
// void ThreeSum(int arr[],int n){
//     sort(arr,arr+n);
//     vector<vector<int>>ans;
//     for(int i=0;i<n;i++){
//         if(i>0 && arr[i]==arr[i-1]) continue;
//         int j=i+1;
//         int k=n-1;
//         vector<int>r;
//         while(j<k){
//             int sum=arr[i]+arr[j]+arr[k];
//             if(sum==0){
//               r={arr[i],arr[j],arr[k]};
//               ans.push_back(r);
//               j++;
//               k--;
//               while(j<k &&arr[j]==arr[j-1]){
//                 j++;
//             }
//             while(j<k && arr[k]==arr[k+1]){
//                 k--;
//             }
//             }
//             else if(sum<0){
//                 j++;
//             }else{
//                 k--;
//             }
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
// }
// int main()
// {
//     int arr[]={1,0,-1,2,2,-3,-4,5,-5,7};
//     ThreeSum(arr,10);
    
//     return 0;
// }

//-------------------------------7
// #include<bits/stdc++.h>
// using namespace std;
// void quadSum(int arr[],int n,int t){
//     sort(arr,arr+n);
//     vector<vector<int>>ans;
//     for(int i=0;i<n;i++){
//         if(i>0 && arr[i]==arr[i-1]) continue;
//         for(int j=i+1;j<n;j++){
//            if(j>i+1 && arr[j]==arr[j-1]) continue;
//            int k=j+1;
//            int l=n-1;
//            while(k<l){
//             int sum=arr[i]+arr[j]+arr[k]+arr[l];
//             if(sum<t){
//                k++;
//             }else if(sum>t){
//                 l--;
//             }else{
//                 ans.push_back({arr[i],arr[j],arr[k],arr[l]});
//                 k++;
//                 l--;
//                 while(k<l && arr[k]==arr[k-1]){
//                   k++;
//                 }while(k<l && arr[l]==arr[l+1]){
//                     l--;
//                 }
//             }
//            }
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//            cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
// }
// int main()
// {
//     int arr[]={1,0,-1,2,2,-3,-4,5,-5,7};
//     quadSum(arr,10,0);
//     return 0;
// }

//------------------------------8
// #include<bits/stdc++.h>
// using namespace std;
// int brute(int arr[],int n){
//     int maxi=-1;
//     for(int i=0;i<n;i++){
//         int sum=0;
//        for(int j=i;j<n;j++){
//          sum+=arr[j];
//          if(sum==0){
//             int count=j-i+1;
//             maxi=max(maxi,count);
//          }
//        }
//     }return maxi;
// }
// int optimal(int arr[],int n){
//     map<int,int>mpp;
//     int sum=0,maxi=-1;
//     for(int i=0;i<n;i++){
//      sum+=arr[i];
//      if(sum==0){
//        maxi=max(maxi,i+1);
//      }
//      int rem=sum;
//      if(mpp.find(rem)!=mpp.end()){
//         int len=i-mpp[rem];
//         maxi=max(maxi,len);
//      }
//      if(mpp.find(sum)==mpp.end()){
//         mpp[sum]=i;
//      }
//     }return maxi;
// }
// int main()
// {
//     int arr[]={6, -2, 2, -8, 1, 7, 4, -10};
//     cout<<brute(arr,8);
//     return 0;
// }

// //-----------------------------9
// #include<bits/stdc++.h>
// using namespace std;
// int optimal(int arr[],int n,int k){
//     map<int,int>mpp;
//     mpp[0]++;
//     int prefixXor=0,count=0;
//     for(int i=0;i<n;i++){
//         prefixXor^=arr[i];
//         int rem=prefixXor^k;
//         count+=mpp[rem];
//         mpp[prefixXor]++;
//     }return count;
// }
// int main()
// {
    
//     return 0;
// }

//-------------------------------10
// #include<bits/stdc++.h>
// using namespace std;
// void brute(vector<vector<int>>vec){
//     int n=vec.size();
//     int m=vec[0].size();
//     vector<vector<int>>ans;
//     sort(vec.begin(),vec.end());
//     ans.push_back({vec[0][0],vec[0][1]});
//     for(int i=1;i<n;i++){
//         int left=ans.back()[0],right=ans.back()[1];
//         int l=vec[i][0],r=vec[i][1];
//         if(right>=l){
//             ans.pop_back();
//             ans.push_back({min(left,l),max(right,r)});
//         }else{
//             ans.push_back({l,r});
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
// }
// int main()
// {
//     vector<vector<int>>vec={{1,3},{2,6},{8,10},{15,18}};
//     brute(vec);
//     return 0;
// }

//------------------------------11
// #include<bits/stdc++.h>
// using namespace std;
// void merge(int arr1[],int m,int arr2[],int n){
//     int left=m-1,right=n-1;
//     int t=m+n-1;
//     while(left>=0 && right>=0 &&t>=0){
//         if(arr1[left]<=arr2[right]){
//           arr1[t]=arr2[right];
//           right--;
//           t--;
//         }else{
//             arr1[t]=arr1[left];
//             left--;
//             t--;
//         }
//     }
//     while(right>=0){
//         arr1[t]=arr2[right];
//         right--;
//         t--;
//     }
//     for(int i=0;i<m+n;i++){
//         cout<<arr1[i]<<" ";
//     }cout<<endl;
// }
// int main()
// {
//     int arr1[]={5,6,7,0,0,0};
//     int arr2[]={1,2,3};
//     merge(arr1,3,arr2,3);
//     return 0;
// }

//----------------------------12
#include<bits/stdc++.h>
using namespace std;
void optimal(int arr[],int n){
    int os=(n*(n+1))/2;
    int osq=(n*(n+1)*(2*n+1))/6;
    int s=0,sq=0;
    for(int i=0;i<n;i++){
      s+=arr[i];
      sq+=arr[i]*arr[i];
    }
    int ymx=os-s;
    int y2mx2=osq-sq;
    int ypx=y2mx2/ymx;
    int miss=(ymx+ypx)/2;
    int repeat=ypx-miss;
    cout<<"Missing : "<<miss<<endl<<"Repeating : "<<repeat<<endl;
}
int main()
{ 
    int arr[]={1,2,3,4,1};
    optimal(arr,5);
    return 0;
}