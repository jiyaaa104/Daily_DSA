// #include<bits/stdc++.h>
// using namespace std;
// int sLargestEl(vector<int>&nums){
//     int n=nums.size();
//     int l=-1,sl=-1;
//     for(int i=0;i<n;i++){
//         if(nums[i]>l){
//             sl=l;
//             l=nums[i];
//         }else{
//             if(nums[i]>sl && l!=nums[i]){
//                 sl=nums[i];
//             }
//         }
//     }return sl;
// }
// int maximumConsecutiveOnes(vector<int>&nums){
//     int n=nums.size();
//     int ans=0,count=0;
//     for(int i=0;i<n;i++){
//         if(nums[i]==1){
//             count++;
//             if(count>ans){
//             ans=count;
//             }
//         }else count=0;
//     }return ans;
// }
// void leftRotateBy1(vector<int>&nums){
//     int n=nums.size();
//     int start=nums[0];
//     vector<int>copy(n);
//     for(int i=0;i<n-1;i++){
//         copy[i]=nums[i+1];
//     }
//     copy[n-1]=start;
//     for(int i=0;i<n;i++){
//         nums[i]=copy[i];
//     }
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }cout<<endl;
//     return;
// }
// void revArr(vector<int>&nums,int l,int r){
//     while(l<r){
//         swap(nums[l++],nums[r--]);
//     }return;
// }
// void leftRotateByKPlaces(vector<int>&nums,int k){
//     int n=nums.size();
//     k=k%n;
//     revArr(nums,0,k-1);
//     revArr(nums,k,n-1);
//     revArr(nums,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }cout<<endl;
//     return;
// }
// void moveZeroesToEnd(vector<int>&nums){
//     int n=nums.size();
//     int l=0,r=0;
//     while(r<n){
//         if(nums[l]!=0){l++;r++;}
//         else{
//             if(nums[r]==0)r++;
//             else{
//                 swap(nums[r],nums[l]);
//                 l++;r++;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }cout<<endl;
//     return;
// }
// void unionSortedArrays(vector<int>&a,vector<int>&b){
//     int n1=a.size(),n2=b.size(),left=0,right=0;
//     vector<int>ans;
//     while(left<n1 && right<n2){
//         if(a[left]<b[right]){
//            if(ans.empty() || ans.back()!=a[left]){
//               ans.push_back(a[left]);
//            }
//            left++;
//         }else{
//             if(ans.empty() || ans.back()!=b[right]){
//               ans.push_back(b[right]);
//            }
//            right++;
//         }
//     }
//     while(left<n1){
//         if(ans.empty() || ans.back()!=a[left]){
//               ans.push_back(a[left]);
//            }
//            left++;
//     }
//     while(right<n2){
//         if(ans.empty() || ans.back()!=b[right]){
//               ans.push_back(b[right]);
//            }
//            right++;
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }cout<<endl;
//     return;
// }
// void intersectionOfTwoSortedArrays(vector<int>&a,vector<int>&b){
//     int n1=a.size(),n2=b.size();
//     int left=0,right=0;
//     vector<int>ans;
//     while(left<n1 && right<n2){
//         if(a[left]==b[right]){
//             if(ans.empty() || ans.back()!=a[left]){
//                 ans.push_back(a[left]);
//             }
//             left++;right++;
//         }
//         else if(a[left]<b[right])left++;
//         else right++;
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }cout<<endl;
//     return;
// }
// int majorityElement(vector<int>&nums){
//     int n=nums.size();
//     int count=0,maxi=0,maxEl=-1;
//     for(int i=0;i<n;i++){
//         if(count==0){
//             maxEl=nums[i];
//         }
//         if(nums[i]==maxEl){
//             count++;
//         }else{
//             count--;
//         }
//     }return maxEl;
// }
// void spiralMatrix(vector<vector<int>>&matrix){
//     int n=matrix.size(),m=matrix[0].size();
//     int top=0,bottom=n-1,left=0,right=m-1;
//     while(top<=bottom && left<=right){
//         for(int i=left;i<=right;i++){
//             cout<<matrix[top][i]<<" ";
//         }
//         top++;
//         for(int i=top;i<=bottom;i++){
//             cout<<matrix[i][right]<<" ";
//         }
//         right--;
//         if(top<=bottom){
//             for(int i=right;i>=left;i--){
//                cout<<matrix[bottom][i]<<" ";
//             }
//             bottom--;
//         }
//         if(left<=right){
//             for(int i=bottom;i>=top;i--){
//                 cout<<matrix[i][left]<<" ";
//             }
//             left++;
//         }
//     }
// }
// int pascal1(int r,int c){
//    r--;c--;
//    int mini=min(c,r-c);
//    int ans=1;
//    for(int i=1;i<=mini;i++){
//     ans*=r-(i-1);
//     ans/=i;
//    }return ans;
// }
// void pascal2(int r){
//     for(int i=1;i<=r;i++){
//         cout<<pascal1(r,i)<<" ";
//     }cout<<endl;
// }
// void pascal3(int r){
//     for(int i=1;i<=r;i++){
//         pascal2(i);
//         cout<<endl;
//     }
// }
// void transposeMatrix(vector<vector<int>>&matrix){
//     int n=matrix.size(),m=matrix[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<i;j++){
//             swap(matrix[i][j],matrix[j][i]);
//         }
//     }
// }
// void rotateMatrix(vector<vector<int>>&matrix){
//     int n=matrix.size(),m=matrix[0].size();
//     transposeMatrix(matrix);
//     for(int i=0;i<n;i++){
//         int l=0,r=m-1;
//         while(l<r){
//             swap(matrix[i][l],matrix[i][r]);
//             l++;r--;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<matrix[i][j]<<" ";
//         }cout<<endl;
//     }
// }
// int longestSubArrayWithSumK(vector<int>&nums,int k){
//     //both +,-
//     // int n=nums.size();
//     // unordered_map<int,int>mpp;
//     // int sum=0,maxi=-1;
//     // for(int i=0;i<n;i++){
//     //   sum+=nums[i];
//     //   if(sum==k){
//     //     maxi=max(maxi,i+1);
//     //   }
//     //   int rem=sum-k;
//     //   if(mpp.find(rem)!=mpp.end()){
//     //     maxi=max(maxi,i-mpp[rem]);
//     //   }
//     //   if(mpp.find(sum)==mpp.end()){
//     //     mpp[sum]=i;
//     //   }
//     // }
//     // return maxi;

//     //only +
//     int l=0,r=0,n=nums.size(),sum=0,maxi=0;
//     while(r<n){
//       sum+=nums[r];
//       if(sum>k){
//         sum-=nums[l];
//         l++;
//       }
//       if(sum==k){
//         maxi=max(maxi,r-l+1);
//       }
//       r++;
//     }return maxi;
// }
// int countSubArrayWithSumK(vector<int>&nums,int k){
//     unordered_map<int,int>mpp;
//     mpp[0]++;
//     int sum=0,n=nums.size(),ans=0;
//     for(int i=0;i<n;i++){
//       sum+=nums[i];
//       int rem=sum-k;
//       ans+=mpp[rem];
//       mpp[sum]++;
//     }return ans;
// }
// int countSubArrayWithXORk(vector<int>&nums,int k){
//     unordered_map<int,int>mpp;
//     mpp[0]++;
//     int sum=0,n=nums.size(),ans=0;
//     for(int i=0;i<n;i++){
//       sum^=nums[i];
//       int rem=sum^k;
//       ans+=mpp[rem];
//       mpp[sum]++;
//     }return ans;
// }
// class Node{
//   public:  
//   int val;Node* next;
//   Node(int v,Node* n){
//     val=v;
//     next=n;
//   }
//   Node(int v){
//     val=v;
//     next=nullptr;
//   }
//   Node(){
//     val=0;
//     next=nullptr;
//   }
// };
// void traversalLL(Node* head){
//     Node* temp=head;
//     while(temp!=nullptr){
//         cout<<temp->val<<" -> ";
//         temp=temp->next;
//     }return;
// }
// Node* convertArr2LL(vector<int>&nums){
//     int n=nums.size();
//     if(n==0)return nullptr;
//     Node* head=new Node(nums[0]);
//     Node* temp=head;
//     for(int i=1;i<n;i++){
//        temp->next=new Node(nums[i]);
//        temp=temp->next;
//     }
//     return head;
// }
// int main()
// {
//     // vector<int>nums1={2,2,2,12,12,12,12,5,10,12,12,12};
//         vector<int>nums2={1,2,3,4,5};
//         Node* list=convertArr2LL(nums2);
//         traversalLL(list);
//         // vector<int>nums={1,0,0,0,2,0,0,3,0,0,0,4,5};
//         // moveZeroesToEnd(nums);
//         // leftRotateByKPlaces(nums,3);
//         // unionSortedArrays(nums1,nums2);
//         // intersectionOfTwoSortedArrays(nums1,nums2);
//     // cout<<sLargestEl(nums);
//     // cout<<majorityElement(nums1);
//     // vector<vector<int>>mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
//     // spiralMatrix(mat);
// //    pascal3(5);
//     //  rotateMatrix(mat);
//     // vector<int>nums={1,2,3,6,0};
//     // cout<<countSubArrayWithXORk(nums,6);
//     return 0;
// }


//HEAPSSS---------
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
   void Insert(int x){
    if(size==capacity){
        cout<<"Heap Overflow!"<<endl;
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
   void Heapify(int i){
     int smallest=i;
     int ri=right(i),li=left(i);
     if(ri<size && arr[smallest]>arr[ri]){
        smallest=ri;
     }
     if(li<size && arr[smallest]>arr[li]){
        smallest=li;
     }
     if(smallest!=i){
        swap(&arr[smallest],&arr[i]);
        Heapify(smallest);
     }
   }
   int getMin(){
     if(size==0){
        cout<<"Heap is Empty. No element present.";
        cout<<endl;
     }
     return arr[0];
   }
   int extractMin(){
    if(size<=0){
        cout<<"Heap underflow"<<endl;
        return INT_MAX;
    }
    if(size==1){
        size--;return arr[0];
    }
    int mini=arr[0];
    arr[0]=arr[size-1];
    Heapify(0);
    size--;
    return mini;
   }
   void DecreaseKey(int i,int val){
    if(i<=0 || i>=size){
        cout<<"Wrong Index Passed!"<<endl;
        return;
    }
    arr[i]=val;
    while(i!=0 && arr[parent(i)]>arr[i]){
        swap(&arr[parent(i)],&arr[i]);
        i=parent(i);
    }
   }
   int Delete(int i){
    if(i<=0 || i>=size){
        cout<<"Wrong Index Passed!"<<endl;
        return INT_MAX;
    }
    DecreaseKey(i,INT_MIN);
    return extractMin();
   }
};
bool checkIfArrayIsMinHeap(vector<int>&nums){
    int n=nums.size();
    for(int i=n/2-1;i>=0;i--){
       int ri=2*i+2,li=2*i+1;
       if(ri<n){
          if(nums[ri]<nums[i])return false;
       }
       if(li<n){
        if(nums[li]<nums[i])return false;
       }
    }return true;
}
//HEAP SORT
// void heapifyDown(vector<int>&nums,int n,int i){
//     int smallest=i;
//     int li=2*i+1,ri=2*i+2;
//     if(li<n && nums[li]<nums[smallest]){
//         smallest=li;
//     }
//     if(ri<n && nums[ri]<nums[smallest]){
//         smallest=ri;
//     }
//     if(smallest!=i){
//         swap(nums[smallest],nums[i]);
//         heapifyDown(nums,n,smallest);
//     }
// }
// void heapify(vector<int>&nums,int n){
//     for(int i=n/2-1;i>=0;i--){
//        heapifyDown(nums,n,i);
//     }
// }
// void heapSort(vector<int>&nums){
//     int n=nums.size();
//     heapify(nums,n);
//     int size=n;
//     for(int i=0;i<n-1;i++){
//        swap(nums[0],nums[size-1]);
//        size--;
//        heapifyDown(nums,size,0);
//     }
//     for(int i=0;i<n;i++){
//         cout<<nums[i]<<" ";
//     }
// }
//KTH LARGEST ELEMENT
// void heapifyDown(vector<int>&nums,int n,int i){
//     int smallest=i,ri=2*i+2,li=2*i+1;
//     if(ri<n && nums[smallest]>nums[ri])smallest=ri;
//     if(li<n && nums[smallest]>nums[li])smallest=li;
//     if(smallest!=i){
//         swap(nums[smallest],nums[i]);
//         heapifyDown(nums,n,smallest);
//     }
// }
// void heapify(vector<int>&nums,int n){
//     for(int i=n/2-1;i>=0;i--){
//         heapifyDown(nums,n,i);
//     }
// }
// int ktSmallestElement(vector<int>&nums,int k){
//     int n=nums.size();
//     int size=n;
//     heapify(nums,n);
//     for(int i=0;i<k-1;i++){
//        swap(nums[0],nums[size-1]);
//        size--;
//        heapifyDown(nums,size,0);
//     }return nums[0];
// }
//KTHLARGESTINTEGER
bool largerString(string &a,string &b){
    if(a.size()>b.size())return true;
    if(a.size()<b.size())return false;
    int i=0;
    while(i!=a.size()){
        if(a[i]>b[i])return true;
        if(a[i]<b[i])return false;
        i++;
    }
    return false;
}
void heapifyDown(vector<string>&nums,int n,int i){
    int largest=i;
    int li=2*i+1,ri=2*i+2;
    if(li<n && largerString(nums[li],nums[largest]))largest=li;
    if(ri<n && largerString(nums[ri],nums[largest]))largest=ri;
    if(largest!=i){
        swap(nums[largest],nums[i]);
        heapifyDown(nums,n,largest);
    }
}
void heapify(vector<string>&nums,int n){
    for(int i=n/2-1;i>=0;i--){
        heapifyDown(nums,n,i);
    }
}
string kthLargestNum(vector<string>&nums,int k){
    int n=nums.size();
    int size=n;
    heapify(nums,size);
    for(int i=0;i<k-1;i++){
        swap(nums[0],nums[size-1]);
        size--;
        heapifyDown(nums,size,0);
    }return nums[0];
}
vector<int> topKFrequentElements(vector<int>&nums,int k){
    int n=nums.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto it:mpp){
        pq.push({it.second,it.first});
        if(pq.size()>k)pq.pop();
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }return ans;
}
struct Compare{
   bool operator()(const pair<int,string>&a,const pair<int,string>&b){
      if(a.first!=b.first)return a.first>b.first;
      return a.second<b.second;
   }
};
vector<string> topKFrequentStrings(vector<string>&str,int k){
    int n=str.size();
    unordered_map<string,int>mpp;
    for(int i=0;i<n;i++){
        mpp[str[i]]++;
    }
    priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>pq;
    for(auto it:mpp){
       pq.push({it.second,it.first});
       if(pq.size()>k)pq.pop();
    }
    vector<string>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end(),[&](const string&a,const string&b){
        if(mpp[a]!=mpp[b])return mpp[a]>mpp[b];
        return a<b;
    });
    return ans;
}
vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>>&points,int k){
    int n=points.size();
    unordered_map<int,int>mpp;
    priority_queue<pair<int,int>>pq;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        int distance=points[i][0]*points[i][0]+points[i][1]*points[i][1];
        mpp[i]=distance;
    }
    for(auto it: mpp){
        pq.push({it.second,it.first});
        if(pq.size()>k)pq.pop();
    }
    while(!pq.empty()){
        ans.push_back({points[pq.top().second][0],points[pq.top().second][1]});
        pq.pop();
    }
    return ans;
}
class kthLargestElement{
  public:
   priority_queue<int,vector<int>,greater<int>>pq;
   int K;
   kthLargestElement(int k,vector<int>&nums){
     K=k;
     int n=nums.size();
     for(int i=0;i<n;i++){
        pq.push(nums[i]);
        if(pq.size()>k)pq.pop();
     }
   }
   int add(int x){
    pq.push(x);
    if(pq.size()>K)pq.pop();
    return pq.top();
   }
};
bool checkKSortedArray(vector<int>&nums,int k){
//     int n=nums.size();
//   if(k>=n)return true;
//     //create a min-heap of size K+1 
//     // Because if k=3, an element at index=0, can be at indices={0,1,2,3} ->k+1
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     for(int i=0;i<k+1;i++){
//        pq.push({nums[i],i});
//     }
//     vector<int>arr; //we put the valid & sorted people into this array
//     int index=0;
//     for(int i=k+1;i<n;i++){
//         arr.push_back(pq.top().first);
//         if(abs(index-pq.top().second)>k)return false;
//         pq.pop();
//         index++;
//         pq.push({nums[i],i});
//     }
// //after this loop only n-k+1 peopele were checked we need to check the remaining people left in pq
//     while(!pq.empty()){
//         arr.push_back(pq.top().first);
//         if(abs(index-pq.top().second)>k)return false;
//         pq.pop();
//         index++;
//     }
//     return true;

   int n=nums.size();
      if(k>=n)return true;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   for(int i=0;i<k+1;i++){
    pq.push({nums[i],i});
   }
   int index=0;
   for(int i=k+1;i<n;i++){
    if(abs(index-pq.top().second)>k)return false;
    index++;
    pq.pop();
    pq.push({nums[i],i});
   }
   while(!pq.empty()){
      if(abs(index-pq.top().second)>k)return false;
      index++;
      pq.pop();
   }
   return true;
}   
vector<vector<int>>kthSmallestPairsWithSmallestSum(vector<int>&nums1,vector<int>&nums2,int k){
    int n1=nums1.size(),n2=nums2.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    if(n1==0 || n2==0 || k<=0)return {};
    for(int i=0;i<n1;i++){
        pq.push({nums1[i]+nums2[0],{i,0}});
    }
    vector<vector<int>>ans;
    while(k-- && !pq.empty()){
        auto t=pq.top();
        pq.pop();
        int i=t.second.first,j=t.second.second;
            ans.push_back({nums1[i],nums2[j]});
        if(j+1<n2){
            pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
    }return ans;
}
vector<int> kthSmallestFraction(vector<int>&nums,int k){
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        pq.push({double(nums[i])/nums[n-1],{i,n-1}});
    }
    while(k--){
        auto t=pq.top();
        pq.pop();
        int i=t.second.first,j=t.second.second;
        if(k==0){
            return {nums[i],nums[j]};
        }
        if(j-1>i){
            pq.push({double(nums[i])/nums[j-1],{i,j-1}});
        }
    }
    return {};
} 
class Node{
    public:
     int val;
     Node* next;
     Node(int val1,Node* next1){
        val=val1;
        next=next1;
     }
     Node(){
        val=0;
        next=nullptr;
     }
     Node(int val1){
        val=val1;
        next=nullptr;
     }
};
class mergeKSortedLists{
   public:
     struct Compare{
           bool operator()(const Node* list1, const Node* list2){
              return list1->val>list2->val;
           }
     };
     Node* mergeList(vector<Node*>lists,int k){
        priority_queue<Node*,vector<Node*>,Compare>pq;
        for(auto list:lists){
            if(list==nullptr)continue;
            pq.push(list);
        }
        Node* dummy=new Node();
        Node* temp=dummy;
        while(!pq.empty()){
            Node* l=pq.top();
            pq.pop();
            temp->next=l;
            temp=temp->next;
            if(l->next)pq.push(l->next);
        }return dummy->next;  
     }
};
int taskScheduler(vector<int>&tasks,int n){
    // int time=0;
    // vector<int>freq(26,0);
    // vector<int>availableAt(26,0);
    // for(int i=0;i<tasks.size();i++){
    //     freq[tasks[i]-'A']++;
    // }
    // int remaining=tasks.size();
    // while(remaining--){
    //     int chosen=-1;
    //     for(int i=0;i<26;i++){
    //     //who is available
    //     if(freq[i]>0 && availableAt[i]<=time){
    //         //who is the best candidate
    //         if(chosen==-1 || freq[i]>freq[chosen]){
    //             chosen=i;
    //         }
    //     }
    //     }
    //    if(chosen==-1){
    //     time++;
    //     continue;
    //    }
    //    freq[chosen]--;
    //    availableAt[chosen]=time+n+1;
    //    time++;
    // }return time;

    int time=0;
    vector<int>freq(26,0);
    for(int i=0;i<tasks.size();i++){
        freq[tasks[i]-'A']++;
    }
    priority_queue<int>pq;
    for(int i=0;i<26;i++){
        if(freq[i]>0)pq.push(freq[i]);
    }
    while(!pq.empty()){
        int used=0,slots=n+1;
        vector<int>pending;
        while(slots>0 && !pq.empty()){
            int count=pq.top();pq.pop();
            count--;used++;slots--;
            if(count>0)pending.push_back(count);
        }
        for(int i=0;i<pending.size();i++){
            pq.push(pending[i]);
        }
        if(pq.empty())time+=used;
        else time+=n+1;
    }return time;
}
int main(){
    // vector<int>nums={1,2,3,4,5,6};
    // heapSort(nums);
    // cout<<ktSmallestElement(nums,3);
    // vector<string>nums={"123","234","56","6","90"};
    // cout<<kthLargestNum(nums,3);
    string x="a";
    string y="p";
    if(x<y){
        cout<<"Alice is small";
    }else{
        cout<<"Alice is large";
    }
    return 0;
}