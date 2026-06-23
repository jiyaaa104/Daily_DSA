//----------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// int SqRt(int n){
//     if(n==1 || n==0 ){
//         return n;
//     }
//     int s=1,e=n/2;
//     int ans=-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         if(mid*mid==n){
//             return mid;
//         }else if(mid*mid<n){
//             ans=mid;
//             s=mid+1;
//         }else{
//             e=mid-1;
//         }
//     }return ans;
// }
// long long Power(int mid,int n){
//     int ans=1;
//     for(int i=1;i<=n;i++){
//         ans*=mid;
//     }return ans;
// }
// int nRootM(int m,int n){
//    if(m<2){
//     return n;
//    }
//    int s=1,e=m,ans=-1;
//    while(s<=e){
//     int mid=(s+e)/2;
//     long long val=Power(mid,n);
//     if(val==m){
//         return mid;
//     }else if(val<m){
//         ans=mid;
//         s=mid+1;
//     }else{
//         e=mid-1;
//     }
//    }return ans;
// }
// int main()
// {
//     cout<<nRootM(27,3);
//     return 0;
// }

//----------------------------2
// #include<bits/stdc++.h>
// using namespace std;
// int hours(int arr[],int n,int mid){
//     int h=0;
//     for(int i=0;i<n;i++){
//         h+=ceil(double(arr[i])/mid);
//     }return h;
// }
// int koko(int arr[],int n,int h){
//     int e=INT_MIN;
//     for(int i=0;i<n;i++){
//         e=max(arr[i],e);
//     }
//     int s=1,ans=-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         int hour=hours(arr,n,mid);
//         if(hour<=h){
//             ans=mid;
//             e=mid-1;
//         }
//         else{
//             s=mid+1;
//         }
//     }return ans;
// }
// int main()
// {
//     int arr[]={7,15,6,3};
//     cout<<koko(arr,4,8);
//     return 0;
// }

//--------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// int bouquets(int arr[],int n,int k,int mid){
//     int count=0,b=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<=mid){
//               count++;
//               if(count==k){
//                 b++;
//                 count=0;
//               }
//             }else{
//                 count=0;
//             }
//     }return b;
// }
// int minDaysMBouquets(int arr[],int n,int m,int k){
//     if(n<m*k){
//         return -1;
//     }
//     int s=INT_MAX,e=INT_MIN;
//     for(int i=0;i<n;i++){
//         s=min(s,arr[i]);
//         e=max(e,arr[i]);
//     }
//     int ans=e;
//     while(s<=e){
//        int mid=(s+e)/2;
//        int b=bouquets(arr,n,k,mid);
//        if(b>=m){
//         ans=mid;
//         e=mid-1;
//        }else{
//         s=mid+1;
//        }
//     }return ans;
// }
// int main()
// {
//     int arr[]={7,7,7,7,13,11,12,7};
//     // cout<<bouquets(arr,8,3,7);
//     cout<<minDaysMBouquets(arr,8,2,3);
//     return 0;
// }

//------------------------4
// #include<bits/stdc++.h>
// using namespace std;
// long long totalVal(int arr[],int n,int mid){
//     long long a=0;
//     for(int i=0;i<n;i++){
//         a+=ceil((double)arr[i]/mid);
//     }return a;
// }
// int smallestDiv(int arr[],int n,int t){
//     int s=1,e=INT_MIN;
//     int k=0;
//     for(int i=0;i<n;i++){
//         e=max(arr[i],e);
//         k+=arr[i];
//     }
//     if(t>=k){
//         return s;
//     }
//     int ans=e;
//     while(s<=e){
//         int mid=(s+e)/2;
//         long long sum=totalVal(arr,n,mid);
//         if(sum<=t){
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
//     cout<<smallestDiv(arr,5,19);
//     return 0;
// }

//-------------------------5
// #include<bits/stdc++.h>
// using namespace std;
// int numOfDays(int arr[],int n,int mid){
//     int sum=0,d=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum>mid){
//             sum=arr[i];
//             d++;
//         }
//     }return d+1;
// }
// int minCapacityShip(int arr[],int n,int d){
//     int s=INT_MIN,e=0;
//     for(int i=0;i<n;i++){
//         e+=arr[i];
//         s=max(s,arr[i]);
//     }
//     if(d==1){
//         return e;
//     }
//     int ans=e;
//     while(s<=e){
//        int mid=(s+e)/2;
//        int days=numOfDays(arr,n,mid);
//        if(days<=d){
//         ans=mid;
//         e=mid-1;
//        }else{
//         s=mid+1;
//        }
//     }return ans;

// }
// int main()
// {
//     int arr[]={3,2,2,4,1,4};
//     cout<<minCapacityShip(arr,6,3);
//     return 0;
// }

//----------------------6
// #include<bits/stdc++.h>
// using namespace std;
// int KMiss(int arr[],int n,int k){
//     if(k<arr[0]){
//         return k;
//     }
//     if(k>(arr[n-1]-n)){
//         k+n;
//     }
//     int s=0,e=n-1,ans=-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         int missing=arr[mid]-(mid+1);
//         if(missing<k){
//             s=mid+1;
//         }else{ 
//            ans=mid;
//            e=mid-1;
//         }
//     }return s+k;
// }
// int main()
// {
//     int arr[]={2,3,4,7,10};
//     cout<<  KMiss(arr,5,3);
//     return 0;
// }

//----------------------7
// #include<bits/stdc++.h>
// using namespace std;
// bool maxPossDis(int arr[],int n,int mid,int k){
//     int count=1;
//     int initialPos=arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i]-initialPos>=mid){
//             count++;
//             initialPos=arr[i];
//             if(count==k){
//                 return true;
//             }
//         }
//     }return false;
// }
// int optimal(int arr[],int n,int k){
//     sort(arr,arr+n);
//     if(n<k){
//         return -1;
//     }
//     int s=INT_MAX,e=arr[n-1]-arr[0];
//     for(int i=0;i<n-1;i++){
//         s=min(s,arr[i+1]-arr[i]);
//     }
//     int ans=e;
//     while(s<=e){
//         int mid=(s+e)/2;
//         bool check=maxPossDis(arr,n,mid,k);
//         if(check==true){
//           ans=mid;
//           s=mid+1;
//         }else{
//             e=mid-1;
//         }
//     }
//     return ans;
// }
// int main()
// {
//     int arr[]={0,3,4,7,10,9};
//     cout<<optimal(arr,6,4);
//     return 0;
// }

//------------------------8
#include<bits/stdc++.h>
using namespace std;
bool possible(int arr[],int n,int mid,int m){
    int pageCount=0,student=1;
    for(int i=0;i<n;i++){
        pageCount+=arr[i];
        if(pageCount>mid){
           student++;
           pageCount=arr[i];
        }
    }return (student<=m);
}
int optimal(int arr[],int n,int m){
    int s=INT_MIN,e=0;
    for(int i=0;i<n;i++){
        s=max(s,arr[i]);
        e+=arr[i];
    }
    int ans=e;
    while(s<=e){
        int mid=(s+e)/2;
        bool p=possible(arr,n,mid,m);
        if(p){
           ans=mid;
           e=mid-1; 
        }else{
            s=mid+1;
        }
    }return ans;
}
int main()
{
    int arr[]={12,34,67,90};
    cout<<optimal(arr,4,2);
    return 0;
}