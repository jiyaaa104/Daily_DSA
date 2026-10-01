#include<bits/stdc++.h>
using namespace std;
class Heap{
   public:
   int* arr;int size,capacity;
   Heap(int cap){
      capacity=cap;
      size=0;
      arr=new int[capacity];
   }
   int parent(int i){
      return (i-1)/2;
   }
   int left(int i){
      return 2*i+1;
   }
   int right(int i){
      return 2*i+2;
   }
   void printHeap(){
      for(int i=0;i<size;i++){
         cout<<arr[i]<<" ";
      }
      cout<<endl;
   }
   void swap(int *x,int * y){
      int temp=*x;
      *x=*y;
      *y=temp;
   }
   void insert(int x){
      if(size==capacity){
         cout<<"No space left in heap"<<endl;
         return;
      }
      arr[size]=x;
      int k=size;
      size++;
      while(k!=0 && arr[parent(k)]>arr[k]){
         swap(&arr[parent(k)],&arr[k]);
         k=parent(k);
      }
   }
   void heapify(int i){
      int smallest=i,li=2*i+1,ri=2*i+2;
      if(li<size && arr[li]<arr[smallest])smallest=li;
      if(ri<size && arr[ri]<arr[smallest])smallest=ri;
      if(i!=smallest){
         swap(&arr[i],&arr[smallest]);
         heapify(smallest);
      }
   }
   int getMin(){
      if(size==0){
         cout<<"Heap is empty"<<endl;
         return INT_MAX;
      }
      return arr[0];
   }
   int extractMin(){
      if(size==0){
         cout<<"Heap is empty"<<endl;
         return INT_MAX;
      }
      if(size==1){
         size--;
         return arr[0];
      }
      int mini=arr[0];
      arr[0]=arr[size-1];
      size--;
      heapify(0);
      return mini;
   }
   int decreaseKey(int i,int val){
      if(i>=size || i<0){
         cout<<"Invalid index passed!"<<endl;
         return;
      }
      arr[i]=val;
      int k=i;
      while(k!=0 && arr[parent(k)]>arr[k]){
         swap(&arr[k],&arr[parent(k)]);
         k=parent(k);
      }
   }
   void Delete(int i){
      decreaseKey(i,INT_MIN);
      extractMin();
   }
};
bool checkIfArrayIsAHeap(vector<int>&arr){
   int n=arr.size();
   for(int i=1;i<n;i++){
      if(arr[i]<arr[(i-1)/2])return false;
   }return true;
}
// void heapifyDown(vector<int>&nums,int n,int i){
//    int largest=i,li=2*i+1,ri=2*i+2;
//    if(li<n && nums[largest]<nums[li])largest=li;
//    if(ri<n && nums[largest]<nums[ri])largest=ri;
//    if(largest!=i){
//       swap(nums[largest],nums[i]);
//       heapifyDown(nums,n,largest);
//    }
// }
// void heapify(vector<int>&nums,int n){
//    for(int i=n/2-1;i>=0;i--){
//       heapifyDown(nums,n,i);
//    }
// }
// void heapSort(vector<int>&nums){
//    int n=nums.size();
//    int size=n;
//    heapify(nums,size);
//    for(int i=0;i<n;i++){
//       swap(nums[0],nums[size-1]);
//       size--;
//       heapifyDown(nums,size,0);
//    }
// }
// int kthLargestElement(vector<int>&nums,int k){
//    int n=nums.size();
//    int size=n;
//    heapify(nums,n);
//    for(int i=0;i<k-1;i++){
//       swap(nums[0],nums[size-1]);
//       size--;
//       heapifyDown(nums,size,0);
//    }return nums[0];
// }
//Kth largest INTEGER in an array of strings
bool largerString(string &a,string &b){
   if(a.size()>b.size())return true;
   if(a.size()<b.size())return false;
   int i=0;
   for(int i=0;i<a.size();i++){
      if(a[i]>=b[i])return true;
   }return false;
}
// void heapifyDown(vector<string>&nums,int n,int i){
//    int largest=i,li=2*i+1,ri=2*i+2;
//    if(li<n && largerString(nums[li],nums[largest]))largest=li;
//    if(ri<n && largerString(nums[ri],nums[largest]))largest=ri;
//    if(largest!=i){
//       swap(nums[largest],nums[i]);
//       heapifyDown(nums,n,largest);
//    }
// }
// void heapify(vector<string>&nums,int n){
//    for(int i=n/2-1;i>=0;i--){
//       heapifyDown(nums,n,i);
//    }
// }
// void kthlargestInteger(vector<string>&nums,int k){
//    int n=nums.size();
//    heapify(nums,n);
//    int size=n;
//    for(int i=0;i<k-1;i++){
//       swap(nums[0],nums[size-1]);
//       size--;
//       heapifyDown(nums,size,0);
//    }
// }
// //TOP K FREQUENT ELEMENTs
// vector<int> kMostFrequent(vector<int>&nums,int k){
//    int n=nums.size();
//    vector<int>ans;
//    unordered_map<int,int>mpp;
//    for(int i=0;i<n;i++){
//       mpp[nums[i]]++;
//    }
//    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//    for(auto it:mpp){
//       pq.push({it.second,it.first});
//       if(pq.size()>k)pq.pop();
//    }
//    while(!pq.empty()){
//       ans.push_back(pq.top().first);
//       pq.pop();
//    }
// }


int main(){
   return 0;
}