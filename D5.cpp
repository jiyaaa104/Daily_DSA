//------------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// int merge(int arr[],int low,int mid,int high){
//     vector<int>temp;
//     int left=low,right=mid+1;
//     int count=0;
//     while(left<=mid && right<=high){
//         if(arr[left]<=arr[right]){
//            temp.push_back(arr[left]);
//            left++;
//         }else{
//             count+=mid-left+1;
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i=low;i<=high;i++){
//         arr[i]=temp[i-low];
//     }
//     return count;
// }
// int mergeSort(int arr[],int low,int high){
//     int c=0;
//     int mid=low+(high-low)/2;
//     if(low<high){
//         c+=mergeSort(arr,low,mid);
//         c+=mergeSort(arr,mid+1,high);
//         c+=merge(arr,low,mid,high);
//     }return c;
// }
// int main()
// {
//     int arr[]={5,3,2,1,4,6,0};
//     cout<<mergeSort(arr,0,6);
//     return 0;
// }

//------------------------------2
// #include<bits/stdc++.h>
// using namespace std;
// int countPairs(int arr[],int low,int mid,int high){
//     int right=mid+1,count=0;
//     for(int i=low;i<=mid;i++){
//         while(right<=high && arr[i]>2LL*arr[right]){
//             right++;
//         }
//         count+=right-(mid+1);
//     }return count;
// }
// void merge(int arr[],int low,int mid,int high){
//     vector<int>temp;
//     int left=low,right=mid+1;
//     while(left<=mid && right<=high){
//         if(arr[left]<=arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i=low;i<=high;i++)
//     {
//         arr[i]=temp[i-low];
//     }
// }
// int mergeSort(int arr[],int low,int high){
//     int c=0;
//     if(low<high){
//         int mid=low+(high-low)/2;
//         c+=mergeSort(arr,low,mid);
//         c+=mergeSort(arr,mid+1,high);
//         c+=countPairs(arr,low,mid,high);
//         merge(arr,low,mid,high);
//     }return c;
// }
// int main()
// {
//     int arr[]={40,25,19,12,9,6,2};
//     cout<<mergeSort(arr,0,6);
//     return 0;
// }

//-----------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// int maxProduct(int arr[],int n){
//     int p=1,s=1,maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             p=1;
//             continue;
//         }
//        else{
//         p*=arr[i];
//        }
//        maxi=max(maxi,p);
//     }
//     for(int i=n-1;i>=0;i--){
//         if(arr[i]==0){
//             s=1;
//             continue;
//         }else{
//             s*=arr[i];
//         }
//         maxi=max(maxi,s);
//     }return maxi;
// }
// int main()
// {
//     int arr[]={0,0,0,0};
//     cout<<maxProduct(arr,4);
//     return 0;
// }

//-----------------------------4
// #include<bits/stdc++.h>
// using namespace std;
// int binarySearch(int arr[],int n,int t){
//     sort(arr,arr+n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
//     int s=0,e=n-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//     if(arr[mid]>t){
//         e=mid-1;
//     }else if(arr[mid]<t){
//         s=mid+1;
//     }else{
//         return mid;
//     }
//     }
//     return -1;
// }
// int main()
// {
//     int arr[]={12,31,56,82,35,3,43,90,100,1};
//     cout<<binarySearch(arr,10,12);
//     return 0;
// }

//----------------------------5,6,7
// #include<bits/stdc++.h>
// using namespace std;
// int lowerbound(int arr[],int n,int t){
//     int ans=n;
//     int s=0,e=n-1;
//     while(s<=e){
//        int mid=(s+e)/2;
//        if(arr[mid]<t){
//          s=mid+1;
//        }
//        else{
//          ans=mid;
//          e=mid-1;
//        }
//     }return ans;
// }
// int upperbound(int arr[],int n,int t){
//     int s=0,e=n-1,ans=n;
//     while(s<=e){
//         int mid=(s+e)/2;
//         if(arr[mid]<=t){
//             s=mid+1;
//         }else{
//            ans=mid;
//            e=mid-1;
//         }
//     }return ans;
// }
// int insertPos(int arr[],int n,int t){
//     int ans=n,s=0,e=n-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         if(arr[mid]>=t){
//             ans=mid;
//             e=mid-1;
//         }else{
//             s=mid+1;
//         }
//     }return ans;

// }
// int main()
// {
//     int arr[]={1,3,4,7,9,13,26,28,30,35};
//     cout<<insertPos(arr,10,23);
//     return 0;
// }

//-------------------------8
// #include<bits/stdc++.h>
// using namespace std;
// void floorCeil(int arr[],int n,int t){
//     int floor=-1,ceil=-1;
//     int s=0,e=n-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         if(arr[mid]==t){
//             floor=arr[mid];
//             ceil=arr[mid];
//             break;
//         }else if(arr[mid]<t){
//             floor=arr[mid];
//             s=mid+1;
//         }else{
//             ceil=arr[mid];
//             e=mid-1;
//         }
//     }
//     cout<<"Floor : "<<floor<<endl;
//     cout<<"Ceil : "<<ceil<<endl;
// }
// int main()
// {
//     int arr[]={1,3,4,7,9,13,26,28,30,35};
//     floorCeil(arr,10,12);
//     return 0;
// }

//------------------------9,10
// #include<bits/stdc++.h>
// using namespace std;
// int lastOccur(int arr[],int n,int t){
//    int ans=-1;
//    int s=0,e=n-1;
//    while(s<=e){
//     int mid=(s+e)/2;
//     if(arr[mid]<t){
//         s=mid+1;
//     }else if(arr[mid]>t){
//         e=mid-1;
//     }else{
//         ans=mid;
//         s=mid+1;
//     }
//    }return ans;
// }
// int startOccur(int arr[],int n,int t){
//    int ans=-1;
//    int s=0,e=n-1;
//    while(s<=e){
//     int mid=(s+e)/2;
//     if(arr[mid]<t){
//         s=mid+1;
//     }else if(arr[mid]>t){
//         e=mid-1;
//     }else{
//         ans=mid;
//         e=mid-1;
//     }
//    }return ans;
// }
// int main()
// {
//     int arr[]={1,3,3,3,3,13,26,28,30,35};
//     int occurance=lastOccur(arr,10,3)-startOccur(arr,10,3)+1;
//     cout<<occurance<<" ";
//     return 0;
// }

//------------------------11,12
// #include<bits/stdc++.h>
// using namespace std;
// int rotatedSorted(int arr[],int n,int t){
//     int s=0,e=n-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         if(arr[mid]==t){
//             return mid;
//         }
//         else if(arr[s]<=arr[mid]){
//             if(arr[s]<=t && t<=arr[mid]){
//                 e=mid-1;
//             }else{
//                 s=mid+1;
//             }
//         }else{
//             if(arr[mid]<=t && t<=arr[e]){
//                 s=mid+1;
//             }else{
//                 e=mid-1;
//             }
//         }
//     }return -1;
// }
// bool rSorted(int arr[],int n,int t){
//     int s=0,e=n-1;
//     while(s<=e){
//         int mid=(s+e)/2;
//         if(arr[mid]==t){
//             return true;
//         }
//         if(arr[s]==arr[mid] && arr[mid]==arr[e]){
//             s++;
//             e--;
//             continue;
//         }
//         if(arr[s]<=arr[mid]){
//             if(arr[s]<=t && t<=arr[mid]){
//                 e=mid-1;
//             }else{
//                 s=mid+1;
//             }
//         }
//         else{
//             if(arr[mid]<=t && t<=arr[e]){
//                 s=mid+1;
//             }else{
//                 e=mid-1;
//             }
//         }

//     }return false;
// }
// int main()
// {
//     int arr[]={4,4,5,6,6,7,1,2,2,2,2,2,2,3,3,3,3,3,4};
//     cout<<rotatedSorted(arr,19,4);
//     return 0;
// }

//---------------------------13
// #include<bits/stdc++.h>
// using namespace std;
// int minimumR(int arr[],int n){
//     int s=0,e=n-1,ans=INT_MAX;
//     while(s<=e){
//        int mid=s+(e-s)/2;
//        if(arr[s]<=arr[mid]){
//         ans=min(arr[s],ans);
//         s=mid+1;
//        }else{
//         ans=min(arr[mid],ans);
//         e=mid-1;
//        }
//     }return ans;
// }
// int numberRotated(int arr[],int n){
//     int ans=INT_MAX,id=-1;
//     int s=0,e=n-1;
//     while(s<=e){
//         int mid=s+(e-s)/2;
//         if(arr[s]<=arr[mid]){
//             if(arr[s]<ans){
//               ans=arr[s];
//               id=s;
//             }
//             s=mid+1;
//         }else{
//             if(arr[mid]<ans){
//                 ans=arr[mid];
//                 id=mid;
//             }
//             e=mid-1;
//         }
//     }return id;
// }
// int main()
// {
//     int arr[]={5,8,9,1,2,3};
//     cout<<numberRotated(arr,6);
//     return 0;
// }

//----------------------------14
#include<bits/stdc++.h>
using namespace std;
int singleEl(int arr[],int n){
    int s=0,e=n-1;
    while(s<=e){
      int mid=s+(e-s)/2;
      if(mid==0){
        if(arr[mid]!=arr[mid+1]){
             return arr[mid];
        }
        s=mid+1;
      }
      if(mid!=n-1){
        if(arr[mid]!=arr[mid-1]){
            return arr[mid];
        }
        e=mid-1;
      }
      if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
           return arr[mid];
      }
      else if(arr[mid]==arr[mid-1]){
        if(mid%2==0){
            e=mid-1;
        }else{
            s=mid+1;
        }
      }else{
        if(mid%2==0){
            s=mid+1;
        }else{
            e=mid-1;
        }
      }
    }return -1;
}
int peakEl(int arr[],int n){
    int s=1,e=n-2;
        if(arr[0]>arr[1]){
            return 0;
        }
        if(arr[n-1]>arr[n-2]){
            return n-1;
        }
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }return -1;
}
int main()
{
    int arr[]={1,2,3,6,5,6,7,8,5,1};
    cout<<peakEl(arr,10);
    return 0;
}