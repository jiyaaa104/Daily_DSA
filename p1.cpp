#include<bits/stdc++.h>
using namespace std;
class Heap{
  int capacity;
  int size;
  int * arr;
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
   void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
   }
   void print(){
     for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
     }cout<<endl;
   }
   void insert(int val){
      if(size==capacity){
        cout<<"Binary Heap Overflow"<<endl;
        return;
      }
      arr[size]=val;
      int k=size;
      size++;
      while(k!=0 && arr[parent(k)]>arr[k]){
        swap(&arr[parent(k)],&arr[k]);
        k=parent(k);
      }
   }
   void heapify(int ind){
    int smallest=ind;
    int li=left(ind);
    int ri=right(ind);
    if(li<size && arr[smallest]>arr[li]){
        smallest=li;
    }
    if(ri<size && arr[smallest]>arr[ri]){
        smallest=ri;
    }
    if(ind!=smallest){
        swap(&arr[ind],&arr[smallest]);
        heapify(smallest);
    }
   }
   int extractMin(){
     if(size<=0)return INT_MAX;
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
   void decreaseKey(int i,int val){
      if(i>=size){
        cout<<"No such index exists yet."<<endl;
        return ; 
      }
      int k=i;
      while(k!=0 && arr[parent(k)]>arr[k]){
        swap(&arr[parent(k)],&arr[k]);
        k=parent(k);
      }
   }
   void Delete(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
   }
   int getMin(){
    return arr[0];
   }
};
bool checkIfArrayIsMinHeap(vector<int>&arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        if(arr[(i-1)/2]>arr[i])return false;
    }
    return true;
}
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
void heapify(vector<int>&arr,int k){
   int n=arr.size();
   int largest=k;
   int li=2*k+1;
   int ri=2*k+2;
   if(li<n && arr[largest]<arr[li]){
    largest=li;
   }
   if(ri<n && arr[largest]<arr[ri]){
    largest=ri;
   }
   if(largest!=k){
    swap(&arr[largest],&arr[k]);
    heapify(arr,largest);
   }
}
void convertMinHeap2MaxHeap(vector<int>&arr){
   int n=arr.size();
   for(int i=(n/2)-1;i>=0;i--){
      heapify(arr,i);
   }
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }cout<<endl;
   return;
}
int main(){
    vector<int>arr={5,30,10,40,50,20,25};
    convertMinHeap2MaxHeap(arr);
    return 0;
}