#include<bits/stdc++.h>
using namespace std;
class BinaryHeap{
    public:
   int capacity;
   int size;
   int* arr;
   BinaryHeap(int cap){
    capacity=cap;
    size=0;
    arr=new int[capacity];
   }
   //1
   int parent(int i){
    return (i-1)/2;
   }
   //2
   int right(int i){
    return 2*i+2;
   }
   //3
   int left(int i){
    return 2*i+1;
   }
   //4
   int getMin(){
    return arr[0];
   }
   //5
   void swap(int *x,int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
   }
   //6
   void insert(int x){
     if(size==capacity){
        cout<<"Binary Heap Overflow!"<<endl;
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
   //7
   void Heapify(int ind){
     int li=left(ind);
     int ri=right(ind);
     int smallest=arr[ind];
     if(li<size && arr[li]<arr[smallest]){
        smallest=li;
     }
     if(ri<size && arr[ri]<arr[smallest]){
        smallest=ri;
     }
     if(smallest!=ind){
        swap(&arr[smallest],&arr[ind]);
        Heapify(smallest);
     }
   }
   //8
   int ExtractMin(){
       if(size<=0) return INT_MAX;
       if(size==1){
        size--;
        return arr[0];
       }
       int mini=arr[0];
       arr[0]=arr[size-1];
       Heapify(0);
       return mini;
   }
   //9
   void decreaseKey(int i,int val){
      if(i<0 || i>=size)return;
     arr[i]=val;
     while(i!=0 && arr[parent(i)]>arr[i]){
        swap(&arr[parent(i)],&arr[i]);
        i=parent(i);
     }
   }
   //10
   void Delete(int i){
      if(i<0 || i>=size)return;
    decreaseKey(i,INT_MIN);
    ExtractMin();
   }
   //11
   void print(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   }
};
bool checkIfArrayIsMinHeap(vector<int>&nums){
   int n=nums.size();
   for(int i=1;i<n;i++){
      int parent=(i-1)/2;
      if(nums[parent]>nums[i])return false;
   }return true;
}
void swap(int *x,int *y){
   int temp=*x;
   *x=*y;
   *y=temp;
}
// void heapify(vector<int>&arr,int i){
//    int n=arr.size();
//    int largest=i;
//    int li=2*i+1,ri=2*i+2;
//    if(li<n && arr[largest]<arr[li]){
//       largest=li;
//    }
//    if(ri<n && arr[largest]<arr[ri]){
//       largest=ri;
//    }
//    if(i!=largest){
//       swap(&arr[i],&arr[largest]);
//       heapify(arr,largest);
//    }
// }
// void convertMinHeap2MaxHeap(vector<int>&arr){
//    int n=arr.size();
//    for(int i=(n/2)-1;i>=0;i--){
//       heapify(arr,i);
//    }
//    for(int i=0;i<n;i++){
//       cout<<arr[i]<<" ";
//    }cout<<endl;
//    return;
// }
void heapifyDown(vector<int>&nums,int n,int i){
   int largest=i,li=2*i+1,ri=2*i+2;
   if(li<n && nums[largest]<nums[li])largest=li;
   if(ri<n && nums[largest]<nums[ri])largest=ri;
   if(largest!=i){
      swap(nums[largest],nums[i]);
      heapifyDown(nums,n,largest);
   }
}
void heapify(vector<int>&nums,int n){
   for(int i=n/2;i>=0;i--){
      heapifyDown(nums,n,i);
   }
}
void heapSort(vector<int>&nums){
   int n=nums.size();
   int size=n;
   heapify(nums,size);
   for(int i=0;i<n;i++){
      swap(nums[0],nums[size-1]);
      size--;
      heapifyDown(nums,size,0);
   }
   for(int i=0;i<n;i++){
      cout<<nums[i]<<" ";
   }cout<<endl;
}
void kthLargestEl(vector<int>&nums,int k){
   int n=nums.size();
   int size=n;
   heapify(nums,size);
   for(int i=0;i<k-1;i++){
      swap(nums[0],nums[size-1]);
      size--;
      heapifyDown(nums,size,0);
   }
   cout<<k<<"th Largest El : "<<nums[0]<<endl;
}
bool checkKSorted(vector<int>&nums,int k){
   int n=nums.size();
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   for(int i=0;i<k+1;i++){
      pq.push({nums[i],i});
   }
   vector<int>a;
   int index=0;
   for(int i=k+1;i<n;i++){
     a.push_back(pq.top().first);
     if(abs(index-pq.top().second)>k)return false;
     index++;
     pq.pop();
     pq.push({nums[i],i});
   }
   while(!pq.empty()){
      a.push_back(pq.top().first);
      if(abs(index-pq.top().second)>2)return false;
      index++;
      pq.pop();
   }
   return true;
}
int main(){
     vector<int>arr={5,30,10,40,50,20,25};
   //  kthLargestEl(arr,1);
    return 0;
}