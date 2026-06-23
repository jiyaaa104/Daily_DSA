//-----------------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// bool largestSum(int arr[],int n,int mid,int k){
//     int sum=0,sub=1;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum>mid){
//             sub++;
//             sum=arr[i];
//         }
//     }return (sub<=k);
// }
// int optimal(int arr[],int n,int k){
//     int s=INT_MIN,e=0;
//     for(int i=0;i<n;i++){
//         s=max(s,arr[i]);
//         e+=arr[i];
//     }
//     if(k==1){
//         return e;
//     }
//     int ans=e;
//     while(s<=e){
//         int mid=(s+e)/2;
//         bool check=largestSum(arr,n,mid,k);
//         if(check){
//            ans=mid;
//            e=mid-1;
//         }else{
//             s=mid+1;
//         }
//     }return ans;
// }
// int main()
// {
//     int arr[]={1,2,3,4,5};
//     // cout<<largestSum(arr,6,5,3);
//     cout<<optimal(arr,5,3);
//     return 0;
// }

//----------------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// bool possible(int arr[],int n,long double mid,int k){
//     int count=0;
//     for(int i=0;i<n-1;i++){
//       count+=ceil((arr[i+1]-arr[i])/mid)-1;
//     }return (count<=k);
// }
// long double optimal(int arr[],int n,int k){
//     long double s=0,e=-1;
//     for(int i=0;i<n-1;i++){
//         if(arr[i+1]-arr[i]>e){
//             e=arr[i+1]-arr[i];
//         }
//     }
//     long double ans=e;
//     while(e-s>1e-6){
//          long double mid=e-(e-s)/2;
//         bool check=possible(arr,n,mid,k);
//         if(check){
//             ans=mid;
//             e=mid;
//         }else{
//             s=mid;
//         }
//     }return ans;
// }
// int main()
// {
//     int arr[]={1,2,3,4,5};
//     cout<<optimal(arr,5,4);
//     return 0;
// }

//---------------------------------4
// #include<bits/stdc++.h>
// using namespace std;
// int medianSortedArrays(int arr1[],int n1,int arr2[],int n2){
//   if(n1>n2){
//     return medianSortedArrays(arr2,n2,arr1,n1);
//   }
//   int left=(n1+n2+1)/2;
//   int s=0,e=n1;
//   int n=n1+n2;
//   while(s<=e){
//     int mid1=(s+e)/2;
//     int mid2=left-mid1;
//     int l1=INT_MIN,l2=INT_MIN;
//     int r1=INT_MAX,r2=INT_MAX;
//     if(mid1<n1){
//         r1=arr1[mid1];
//     }
//     if(mid2<n2){
//         r2=arr2[mid2];
//     }
//     if(mid1-1>=0){
//         l1=arr1[mid1-1];
//     }
//     if(mid2-1>=0){
//         l2=arr2[mid2-1];        
//     }
//     if(l1<=r2 && l2<=r1){
//         if(n%2==1){
//             return max(l1,l2);
//         }else{
//             return ((max(l1,l2)+min(r1,r2))/2.0);
//         }
//     }else if(l1>r2){
//         e=mid1-1;
//     }else{
//         s=mid1+1;
//     }
//   }return -1;
// }
// int main()
// {
//     int arr1[]={0,2,6};
//     int arr2[]={1,3,5,7,9};
//     cout<<medianSortedArrays(arr1,3,arr2,5);
//     return 0;
// }

//--------------------------------5
// #include<bits/stdc++.h>
// using namespace std;
// int KElement(int arr1[],int n1,int arr2[],int n2,int k){
//     if(n1>n2){
//     return KElement(arr2,n2,arr1,n1,k);
// }
// int left=k;
// int s=0,e=n1;
// while(s<=e){
//     int mid1=e-(e-s)/2;
//     int mid2=left-mid1;
//     int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
//     if(mid1<n1){
//         r1=arr1[mid1];
//     }
//     if(mid2<n2){
//         r2=arr2[mid2];
//     }
//     if(mid1-1>=0){
//         l1=arr1[mid1-1];
//     }
//     if(mid2-1>=0){
//         l2=arr2[mid2-1];
//     }
//     if(l2<=r1 && l1<=r2){
//         return max(l1,l2);
//     }else if(l1>r2){
//         e=mid1-1;
//     }else{
//         s=mid1+1;
//     }
// }return -1;
// }

// int main()
// {
//     int arr1[]={2,3,6,7,9};
//     int arr2[]={1,4,8,10};
//     cout<<KElement(arr1,5,arr2,4,3);
//     return 0;
// }

//-----------------------6
// #include<bits/stdc++.h>
// using namespace std;
// int maxOne(vector<vector<int>>arr){
//     int n=arr.size();
//     int row=-1,maxi=-1;
//     int m=arr[0].size();
//     for(int i=0;i<n;i++){
//         int s=0,e=m-1,count=0,val=-1;
//         while(s<=e){
//             int mid=e-(e-s)/2;
//             if(arr[i][mid]==1){
//                 val=mid;
//                 e=mid-1;                
//             }else{
//                 s=mid+1;
//             }
//         }
//         if(val==-1){
//             continue;
//         }
//         count=m-val;
//         if(count>maxi){
//             maxi=count;
//             row=i;
//         }
//     }return row;
// }
// int main()
// {
//     vector<vector<int>>arr={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
//     cout<<maxOne(arr);
//     return 0;
// }

//----------------------7
// #include<bits/stdc++.h>
// using namespace std;
// bool searchEl(vector<vector<int>>vec,int t){
//    int n=vec.size();
//    int m=vec[0].size();
//    int top=0,bottom=n-1;
//    while(top<=bottom){
//      int midRow=bottom-(bottom-top)/2;
//      if(vec[midRow][0]==t || vec[midRow][m-1]==t){
//         return true;
//      }else if(vec[midRow][0]<t && t<vec[midRow][m-1]){
//         int left=0,right=m-1;
//         while(left<=right){
//             int mid=(left+right)/2;
//             if(vec[midRow][mid]==t){
//                 return true;
//             }else if(vec[midRow][mid]<t){
//                 left=mid+1;
//             }else{
//                 right=mid-1;
//             }
//         }return false;
//      }else if(t>vec[midRow][m-1]){
//         top=midRow+1;
//      }else{
//         bottom=midRow-1;
//      }
//    }return false;
// }
// int main()
// {
//     vector<vector<int>>arr={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//     cout<<searchEl(arr,1);
//     return 0;
// }

//------------------------8
// #include<bits/stdc++.h>
// using namespace std;
// bool searchSorted(vector<vector<int>>arr,int target){
//     int n=arr.size(),m=arr[0].size();
//     int row=0,col=m-1;
//     while(row<=n-1 && col>=0){
//         if(arr[row][col]==target){
//             return true;
//         }else if(arr[row][col]<target){
//             row++;
//         }else{
//             col--;
//         }
//     }return false;

// }
// int main()
// {
//     vector<vector<int>>arr={{1,3,5,7,9},{2,4,6,8,10},{3,9,11,12,16}};
//     cout<<searchSorted(arr,1);
//     return 0;
// }

//---------------------9
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> maxCol(vector<vector<int>>arr,int mid){
//     int m=arr.size();
//     int maxi=-1,row=-1;
//     for(int i=0;i<m;i++){
//        if(arr[i][mid]>maxi){
//         maxi=arr[i][mid];
//         row=i;
//        }
//     }return {maxi,row};
// }
// vector<int>peakEl(vector<vector<int>>arr){
//     int n=arr.size(),m=arr[0].size();
//     int s=0,e=m-1;
//     while(s<=e){
//         int mid=e-(e-s)/2;
//         vector<int> temp=maxCol(arr,mid);
//         int maxi=temp[0];
//         int row=temp[1];
//         int left=(mid-1>=0)?arr[row][mid-1]:INT_MIN;
//         int right=(mid+1<m)?arr[row][mid+1]:INT_MIN;
//         if(arr[row][mid]>left && arr[row][mid]>right){
//             return {row,mid};
//         }else if(arr[row][mid]<left){
//             e=mid-1;
//         }else{
//             s=mid+1;
//         }
//     }return{-1,-1};
// }
// int main()
// {
//     vector<vector<int>>arr={{1,3,5,7,9},{2,4,6,8,10},{3,9,11,12,16}};
//     cout<<peakEl(arr)[0]<<" "<<peakEl(arr)[1]<<endl;
//     return 0;
// }

//---------------------------10


#include<bits/stdc++.h>
using namespace std;
int lesserThanEqual(vector<vector<int>>arr,int mid1){
    int n=arr.size(),m=arr[0].size(),count=0;
    for(int i=0;i<n;i++){
       int s=0,e=m-1,ans=m;
       while(s<=e){
          int mid=e-(e-s)/2;
          if(arr[i][mid]<=mid1){
            s=mid+1;
          }else{
            ans=mid;
            e=mid-1;
          }
       }count+=ans;
    }return count;
}
int median(vector<vector<int>>arr){
    int n=arr.size();
    int m=arr[0].size();
    int s=INT_MAX,e=INT_MIN;
    for(int i=0;i<n;i++){
       s=min(s,arr[i][0]);
       e=max(e,arr[i][m-1]);
    }
    int ans=-1;
    while(s<=e){
        int mid=e-(e-s)/2;
        int num=lesserThanEqual(arr,mid);
        if(num<=(m*n)/2){
            s=mid+1;
        }else{
            ans=mid;
            e=mid-1;
        }
    }return ans;
}
int main()
{
    vector<vector<int>>arr={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
    cout<<median(arr);
    return 0;
}