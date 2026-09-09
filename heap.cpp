#include<bits/stdc++.h>
using namespace std;
class BinaryHeap{
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
     arr[i]=val;
     while(i!=0 && arr[parent(i)]>arr[i]){
        swap(&arr[parent(i)],&arr[i]);
        i=parent(i);
     }
   }
   //10
   void Delete(int i){
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
int main(){
    return 0;
}