//-------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// void printArr(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// void revArr(int arr[],int s,int e){
//     if(s>=e){
//         return;
//     }
//     swap(arr[s],arr[e]);
//     s++;e--;
//     revArr(arr,s,e);
// }
// int main()
// {
//     int arr[]={1,2,3,4,5};
//     revArr(arr,0,4);
//     printArr(arr,5);
//     return 0;
// }

//------------------------------2
// #include<bits/stdc++.h>
// using namespace std;
// int fib(int n){
//     if(n==0||n==1){
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
// }
// int main()
// {
//     cout<<fib(6);
//     return 0;
// }

//-----------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[]={1,1,1,1,2,4,4,5,5,4};
//     unordered_map<int,int>mpp;
//     for(int i=0;i<10;i++){
//         mpp[arr[i]]++;
//     }
//     int maxi=-1,maxEl=-1;
//     for(auto it:mpp){
//         if(it.second>maxi){
//             maxi=it.second;
//             maxEl=it.first;
//         }
//     }
//     cout<<maxi<<endl;
//     return 0;
// }

//--------------------------4
// #include<bits/stdc++.h>
// using namespace std;
// void selectionSort(int arr[],int n){
//     for(int i=0;i<=n-2;i++){
//         int mini=i;
//         for(int j=i;j<=n-1;j++){
//             if(arr[j]<arr[mini]){
//                mini=j;
//             }
//         }swap(arr[i],arr[mini]);
//     }
// }
// void bubbleSort(int arr[],int n){
//     for(int i=0;i<=n-2;i++){
//         for(int j=0;j<n-1;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j],arr[j+1]);
//             }
//         }
//     }
// }
// void insertionSort(int arr[],int n){
//     for(int i=0;i<=n-1;i++){
//         int j=i;
//         while(j>0 && arr[j]<arr[j-1]){
//             swap(arr[j],arr[j-1]);
//             j--;
//         }
//     }
// }
// void printArr(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
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
//     for(int i=low;i<=high;i++){
//         arr[i]=temp[i-low];
//     }
// }
// void mergeSort(int arr[],int low, int high){
//     if(low<high){
//     int mid=low+(high-low)/2;
//     mergeSort(arr,low,mid);
//     mergeSort(arr,mid+1,high);
//     merge(arr,low,mid,high);
//     }else{
//         return;
//     }
// }
// int f(int arr[],int low,int high){
//     int pivot=arr[low];
//     int i=low,j=high;
//     while(i<j){
//         while(arr[i]<=pivot && i<high){
//             i++;
//         }
//         while(arr[j]>pivot && j>low){
//             j--;
//         }
//         if(i<j){
//             swap(arr[i],arr[j]);
//         }
//     }swap(arr[j],arr[low]);
//     return j;
// }
// void quickSort(int arr[],int low,int high){
//     if(low<high){
//         int pIdx=f(arr,low,high);
//         quickSort(arr,low,pIdx-1);
//         quickSort(arr,pIdx+1,high);
//     }
// }
// int main()
// {
//     int arr[]={10,2,34,92,35,71,12,83,90,100};
//     printArr(arr,10);
//     quickSort(arr,0,9);
//     printArr(arr,10);
//     return 0;
// }

//-------------------------5
// #include<bits/stdc++.h>
// using namespace std;
// int largest(int arr[],int n){
//     int largest=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>largest){
//             largest=arr[i];
//         }
//     }return largest;
// }
// int sLargest(int arr[],int n){
//     int largest=-1,slargest=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]>largest){
//             slargest=largest;
//             largest=arr[i];
//         }else if(arr[i]<largest && arr[i]>slargest){
//             slargest=largest;
//         }
//     }return slargest;
// }
// bool checkRotatedSorted(int arr[],int n){
//     int count=0;
//     for(int i=0;i<n-1;i++){
//         if(arr[i]>arr[i+1]){
//             count++;
//         }
//     }if(count==0){
//         return true;
//     }else if(count==1 && arr[0]>=arr[n-1]){
//         return true;
//     }else {
//         return false;
//     }
// }
// int removeDuplicates(int arr[],int n){
//     int i=0,j=1;
//     while(j<n){
//         if(arr[i]==arr[j]){
//             j++;
//             continue;
//         }else{
//             arr[i+1]=arr[j];
//             i++;j++;
//         }
//     }return i+1;
// }
// void rotateBy1(int arr[],int n){
//     int s=arr[0];
//     for(int i=0;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     arr[n-1]=s;
// }
// void revArr(int arr[],int s,int e){
//     while(s<=e){
//         swap(arr[s],arr[e]);
//         s++;e--;
//     }
// }
// void rotateKBrute(int arr[],int n,int k){
//     k=k%n;
//     int vec[k];
//     for(int i=n-k;i<n;i++){
//         vec[i-(n-k)]=arr[i];
//     }
//     for(int i=k;i<n;i++){
//        arr[i]=arr[(i+k)%n];
//     }
//     for(int i=0;i<k;i++){
//         arr[i]=vec[i];
//     }
// }
// void rotateKOpt(int arr[],int n,int k){
//     k=k%n;
//     revArr(arr,0,k-1);
//     revArr(arr,k,n-1);
//     revArr(arr,0,n-1);
// }
// void printArr(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// void moveZeroes(int arr[],int n){
//     int i=0,j=1;
//     while(j<n){
//         if(arr[i]==0){
//             if(arr[j]!=0){
//                 swap(arr[j],arr[i]);i++;j++;
//             }else{
//                 j++;
//             }
//         }else{
//             i++;j++;
//         }
//     }
// }
// void unionArray(int arr1[],int arr2[],int n1,int n2){
//    vector<int>ans;
//    int left=0,right=0;
//    while(left<n1 && right<n2){
//      if(arr1[left]<=arr2[right]){
//         if(ans.empty() ||ans.back()!=arr1[left]){
//             ans.push_back(arr1[left]);
//         }
//         left++;
//      }else{
//         if(ans.empty() || ans.back()!=arr2[right]){
//             ans.push_back(arr2[right]);
//         }
//         right++;
//      }
//    }
//    while(left<n1){
//     if(ans.empty() || ans.back()!=arr1[left]){
//         ans.push_back(arr1[left]);
//     }
//     left++;
//    }
//    while(right<n2){
//     if(ans.empty() || ans.back()!=arr2[right]){
//         ans.push_back(arr2[right]);
//     }
//     right++;
//    }
//    for(auto it : ans){
//     cout<<it<<" ";
//    }cout<<endl;
// }
// int MissNum(int arr[],int n){
//     int size=n+1;
//     int sum=((size+1)*(size))/2;
//     int t=0;
//     for(int i=0;i<n;i++){
//         t+=arr[i];
//     }
//     return sum-t;
// }
// int maxOnes(int arr[],int n){
//     int count=0,max=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==1){
//             count++;
//             if(count>max){
//                 max=count;
//             }
//         }else{
//             count=0;
//         }
//     }return max;
// }
// int main()
// {
//     // int arr[]={10,2,34,92,35,71,12,83,90,100};
//     // int arr1[]={4,5,6,7,8,1,2,3,3,3};
//     // cout<<checkRotatedSorted(arr1,10);
//     // int arr[]={1,0,0,0,1,9,0,9,0,1};
//     // cout<<removeDuplicates(arr,10);
//     // rotateBy1(arr,10);
//     // rotateKOpt(arr,7,3);
//     // moveZeroes(arr,10);
//     // printArr(arr,10);
//     // int arr1[]={1,2,3,3,4};
//     // int arr2[]={3,3,4,5,5};
//     // unionArray(arr1,arr2,5,5);
//     int arr[]={1,0,1,1,1,1,0,0,0,0};
//     cout<<maxOnes(arr,10);
//     return 0;
// }

//-------------------------6
// #include<bits/stdc++.h>
// using namespace std;
// int brute(int arr[],int n,int k){
//     int count=0,maxi=-1,sum;
//     for(int i=0;i<n;i++){
//         sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             if(sum==k){
//                 count=j-i+1;
//                 if(count>maxi){
//                     maxi=count;
//                 }
//             }
//         }
//     }return maxi;
// }
// int optimal(int arr[],int n,int k){
//     map<int,int>mpp;
//     int sum=0,maxLen=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum==k){
//             maxLen=max(maxLen,i+1);
//         }
//         int rem=sum-k;
//         if(mpp.find(rem)!=mpp.end()){
//             int len=i-mpp[rem];
//             maxLen=max(maxLen,len);
//         }
//         if(mpp.find(sum)==mpp.end()){
//             mpp[sum]=i;
//         }
//     }return maxLen;
// }
// int best(int arr[],int n,int k){
//     int l=0,r=0,sum=0,maxLen=0;
//     while(r<n){
//        sum+=arr[r];
//        if(sum==k){
//          maxLen=max(maxLen,r-l+1);
//        }
//        r++;
//        while(sum>=k && l<=r){
//           sum-=arr[l];
//           l++;
//        }
//     }return maxLen;
// }
// int pn(int arr[],int n){
//     map<int,int>mpp;
//     int sum=0,maxLen=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum==0){
//             maxLen=max(maxLen,i+1);
//         }
//         int rem=sum;
//         if(mpp.find(rem)!=mpp.end()){
//             maxLen=max(maxLen,i-mpp[rem]);
//         }
//         if(mpp.find(sum)==mpp.end()){
//             mpp[sum]=i;
//         }
//     }return maxLen;
// }
// int main()
// {
//     int arr[]={1,2,0,0,0,6,7,8,9,10};
//     cout<<pn(arr,10);
//     return 0;
// }

//------------------------7
// #include<bits/stdc++.h>
// using namespace std;
// bool app1(int arr[],int n,int k){
//     sort(arr,arr+n);
//     int s=0,e=n-1;
//     while(s<e){
//         int sum=arr[s]+arr[e];
//         if(sum>k){
//            e--;
//         }else if(sum<k){
//             s++;
//         }else{
//             return true;
//         }
//     }return false;
// }
// bool app2(int arr[],int n,int k){
//     map<int,int>mpp;
//     for(int i=0;i<n;i++){
//         int complement=k-arr[i];
//         if(mpp.find(complement)!=mpp.end()){
//             return true;
//         }
//         mpp[arr[i]]=i;
//     }return false;
// }
// int main()
// {
//     int arr[]={10,12,31,1,2,65,4,28,91,100};
//     cout<<app2(arr,10,3);
//     return 0;
// }

//-----------------------8
// #include<bits/stdc++.h>
// using namespace std;
// void sortDNF(int arr[],int n){
//     //0 (0 - low-1) 1 (low - mid-1) unsorted (mid - high) 2(high+1 - n-1)
//     int low=0,mid=0,high=n-1;
//     while(mid<=high){
//         if(arr[mid]==0){
//             swap(arr[mid],arr[low]);
//             low++;
//             mid++;
//         }else if(arr[mid]==1){
//            mid++;
//         }else{
//             swap(arr[mid],arr[high]);
//             high--;
//         }
//     }
// }
// void printArr(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// int main()
// {
//     int arr[]={1,1,2,1,1,2,1,0,0,0};
//     sortDNF(arr,10);
//     printArr(arr,10);
//     return 0;
// }