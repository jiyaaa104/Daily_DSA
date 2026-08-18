#include<bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMaximum(vector<int>&nums,int k){
   vector<int>ans;deque<int>dq;int n=nums.size();
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
   }
   return ans;
}
int celebrityProblem(vector<vector<int>>&mat){
    int n=mat.size();
    int top=0,bottom=n-1;
    while(top<bottom){
        if(mat[top][bottom]){
            top++;
        }else if(mat[bottom][top]){
            bottom--;
        }else{
            top++;bottom--;
        }
    }
    if(top>bottom)return -1;
    for(int i=0;i<n;i++){
        if(i!=top){
            if(!(mat[top][i]==0 && mat[i][top]==1))return -1;
        }
    }return top;
}
// class Node{
// public:
//   int key,val;
//   Node* prev;Node* next;
//   Node(int k,int v){
//     key=k;
//     val=v;
//     next=nullptr;
//     prev=nullptr;
//   }
// };
// class LRUCache{
//    Node* head;Node* tail;int size;unordered_map<int,Node*>mpp;
//    LRUCache(int capacity){
//     size=capacity;
//     head=new Node(-1,-1);
//     tail=new Node(-1,-1);
//     head->next=tail;
//     tail->prev=head;
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
//     if(mpp.find(key)!=mpp.end()){
//         Node*  node=mpp[key];
//         deleteNode(node);
//         insertAtHead(node);
//         return node->val;
//     }
//     return -1;
//    }
//    void put(int key,int value){
//     if(mpp.find(key)!=mpp.end()){
//         Node* node=mpp[key];
//         node->val=value;
//         deleteNode(node);
//         insertAtHead(node);
//     }else{
//         if(mpp.size()==size){
//             Node* delNode=tail->prev;
//             deleteNode(delNode);
//             mpp.erase(delNode->key);
//             delete delNode;
//         }
//         Node* newNode=new Node(key,value);
//         insertAtHead(newNode);
//         mpp[newNode->key]=newNode;
//     }
//    }
// };
class Node{
  public:
  int key,val,count;
  Node* next;Node* prev;
  Node(int k,int v){
    key=k;
    val=v;
    next=nullptr;
    prev=nullptr;
    count=1;
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
    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqList;
    int minFreq,maxCap,currCap;
    LFUCache(int capacity){
         minFreq=0;maxCap=capacity;currCap=0;
    }
    void updateFreqList(Node* node){
       freqList[node->count]->removeNode(node);
       if(node->count==minFreq && freqList[node->count]->size==0){
        minFreq++;
       }
       List* list=new List();
       if(freqList.find(node->count+1)!=freqList.end()){
         list=freqList[node->count+1];
       }
       list->addFront(node);
       node->count+=1;
       freqList[node->count]=list;
    }
    int get(int key){
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            updateFreqList(node);
            return node->val;
        }return -1;
    }
    void put(int key,int value){
        if(maxCap==0)return;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val=value;
            updateFreqList(node);
        }else{
          if(currCap==maxCap){
            List* list=freqList[minFreq];
            list->removeNode(freqList[minFreq]->tail->prev);
            keyNode.erase(freqList[minFreq]->tail->prev->key);
            currCap--;
          }
          Node* newNode=new Node(key,value);
          minFreq=1;
          currCap++;
          List* list=new List();
          if(freqList.find(minFreq)!=freqList.end()){
            list=freqList[minFreq];
        }
        list->addFront(newNode);
        keyNode[key]=newNode;
        freqList[minFreq]=list;
        }
    }
};
int main(){
    return 0;
}