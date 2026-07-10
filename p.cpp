#include<bits/stdc++.h>
using namespace std;
void subsets(int index,vector<int>&arr,vector<int>&current){
   if(index==arr.size()){
      for(int i: current){
         cout<<i<<" ";
      }cout<<endl;
      return;
   }
   current.push_back(arr[index]);
   subsets(index+1,arr,current);

   current.pop_back();
   subsets(index+1,arr,current);
}
int main(){
   vector<int>arr={1,2,3};
   vector<int>current;
   subsets(0,arr,current);
   return 0;
}