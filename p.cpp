#include<bits/stdc++.h>
using namespace std;
vector<int>slidingWindowMaximum(vector<int>&nums,int k){
    vector<int>ans;int n=nums.size();deque<int>dq;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(nums[dq.front()]);
        }
    }return ans;
}
int celebrityProblem(vector<vector<int>>&nums){
    int n=nums.size();
    int top=0,bottom=n-1;
    while(top<bottom){
        if(nums[top][bottom])top++;
        else if(nums[bottom][top])bottom--;
        else{
            top++;bottom--;
        }
    }
    if(top>bottom)return -1;
    for(int i=0;i<n;i++){
        if(i!=top){
            if(!(nums[i][top]==1 && nums[top][i]==0))return -1;
        }
    }return top;
}
// class Node{
//   public:  
//   int key,val;
//   Node* next;Node* prev;
//   Node(int k,int v){
//     key=k;
//     val=v;
//     next=nullptr;
//     prev=nullptr;
//   }
// };
// class LRUCache{
//    public:
//    Node* head;Node* tail;unordered_map<int,Node*>mpp;int size;
//    LRUCache(int capacity){
//     head=new Node(-1,-1);
//     tail=new Node(-1,-1);
//     head->next=tail;
//     tail->prev=head;
//     size=capacity;
//     mpp.clear();
//    }
//    void insertAtHead(Node* node){
//     Node* nextNode=head->next;
//     head->next=node;
//     node->prev=head;
//     node->next=nextNode;
//     nextNode->prev=node;
//    }
//    void deleteNode(Node* node){
//     Node* nextNode=node->next;
//     Node* prevNode=node->prev;
//     prevNode->next=nextNode;
//     nextNode->prev=prevNode;
//    }
//    int get(int key){
//     if(mpp.find(key)==mpp.end())return -1;
//     Node* node=mpp[key];
//     deleteNode(node);
//     insertAtHead(node);
//     return node->val;
//    }
//    void put(int key,int value){
//     if(mpp.find(key)!=mpp.end()){
//         Node* node=mpp[key];
//         node->val=value;
//         deleteNode(node);
//         insertAtHead(node);
//         return ;
//     }
//     if(size==mpp.size()){
//         Node* delNode=tail->prev;
//         deleteNode(delNode);
//         mpp.erase(delNode->key);
//         delete delNode;
//     }
//     Node* newNode=new Node(key,value);
//     insertAtHead(newNode);
//     mpp[key]=newNode;
//    }
// };
class Node{
    public:
    int key,val,count;
    Node* next;Node* prev;
    Node(int k,int v){
        key=k;
        val=v;
        count=1;
        next=nullptr;prev=nullptr;
    }
};
class List{
  public:
   Node* head;Node* tail;int size;
   List(){
    head=new Node(-1,-1);
    tail=new Node(-1,-1);
    head->next=tail;
    tail->prev=head;
    size=0;
   }
   void addFront(Node* node){
    Node* nextNode=head->next;
    head->next=node;
    node->prev=head;
    node->next=nextNode;
    nextNode->prev=node;
    size++;
   }
   void removeNode(Node* node){
    Node* nextNode=node->next;
    Node* prevNode=node->prev;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    size--;
   }
};
class LFUCache{
  public:
   unordered_map<int,Node*>mpp;
   unordered_map<int,List*>freqList;
   int minFreq,currCap,maxCap;
   LFUCache(int capacity){
    minFreq=0,currCap=0,maxCap=capacity;
   }
   void updateFreqList(Node* node){
     freqList[node->count]->removeNode(node);
     if(node->count==minFreq && freqList[node->count]->size==0) minFreq++;
     List* newList;
     if(freqList.find(node->count+1)!=freqList.end()){
        newList=freqList[node->count+1];
     }else{
        newList=new List();
     }
     node->count+=1;
     newList->addFront(node);
     freqList[node->count]=newList;
   }
   int get(int key){
    if(mpp.find(key)!=mpp.end()){
       Node* node=mpp[key];
       updateFreqList(node);
       return node->val;
    }return -1;
   }
   void put(int key,int value){
    if(maxCap==0)return;
    if(mpp.find(key)!=mpp.end()){
        Node* node=mpp[key];
        node->val=value;
        updateFreqList(node);
        return;
    }
    Node* node=new Node(key,value);
     
    if(currCap==maxCap){  
        List* list=freqList[minFreq];
       Node* delNode=list->tail->prev;
       list->removeNode(delNode);
       mpp.erase(delNode->key);
       delete delNode;
       currCap--;
    }
    currCap++;
    minFreq=1;
    List* list;
    if(freqList.find(minFreq)!=freqList.end()){
        list=freqList[minFreq];
    }else{
        list=new List();
    }  
    list->addFront(node);
    freqList[minFreq]=list;
    mpp[key]=node;
   }
};
int main(){
    return 0;
}