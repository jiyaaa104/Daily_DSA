#include<bits/stdc++.h>
using namespace std;
vector<int> slidingWindowMaximum(vector<int>&nums,int k){
    int n=nums.size();vector<int>ans;
    deque<int>dq;
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
//L-17-> THE CELEBRITY PROBLEM
int celebrityProblem(vector<vector<int>>&mat){
    int r=mat.size();
    int top=0,down=r-1;
    while(top<down){
        //does top know down ?
        if(mat[top][down]){
            top++;
        }else if(mat[down][top]){
            down--;
        }else{
            top++;down--;
        }
    }
    if(top>down) return -1;
    for(int i=0;i<r;i++){
        if(mat[top][i]) return -1;
        if(i!=top && (mat[i][top]==1)){
          return -1;
        }
    } 
    return top;
}
// class Node{
//  public: 
//    int key,val;Node* next;Node* prev;
//    Node(int k,int v){
//     key=k;
//     val=v;
//     next=nullptr;
//     prev=nullptr;
//    }
// };
// class LRUCache{
//     public: 
//     int size;Node* head;Node* tail;unordered_map<int,Node*>mpp;
//     LRUCache(int capacity){
//         head=new Node(-1,-1);
//         tail=new Node(-1,-1);
//         head->next=tail;
//         tail->prev=head;
//         mpp.clear();
//         size=capacity;
//     }
//     void insertAtHead(Node* node){
//         Node* nextNode=head->next;
//         head->next=node;
//         node->prev=head;
//         node->next=nextNode;
//         nextNode->prev=node;
//     }
//     void deleteNode(Node* node){
//         Node* nextNode=node->next;
//         Node* prevNode=node->prev;
//         prevNode->next=nextNode;
//         nextNode->prev=prevNode;
//     }
//     int get(int key){
//         if(mpp.find(key)==mpp.end()){
//             return -1;
//         }
//         Node* node=mpp[key];
//         deleteNode(node);
//         insertAtHead(node);
//         return node->val;
//     }
//     void put(int key,int val){
//         if(mpp.find(key)!=mpp.end()){
//             mpp[key]->val=val;
//             deleteNode(mpp[key]);
//             insertAtHead(mpp[key]);
//             return;
//         }
//         if(mpp.size()==size){
//             Node* del=tail->prev;
//             deleteNode(del);
//             mpp.erase(del->key);
//             delete del;
//         }
//         Node* node=new Node(key,val);
//         mpp[key]=node;
//         insertAtHead(node);
//     }
// };
class Node{
    public:
  int key,val,count;
  Node* next;Node* prev;
  Node(int k,int v){
    key=k;
    val=v;
    count=1;
    next=nullptr;
    prev=nullptr;
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
    unordered_map<int,Node*>keyNode;
    unordered_map<int,List*>freqList;
    int minFreq,maxCap,currCap;
    LFUCache(int capacity){
        minFreq=0,maxCap=capacity,currCap=0;
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
            updateFreqList(keyNode[key]);
            return keyNode[key]->val;
        }
        return -1;
    }
    void put(int key,int value){
        if(maxCap==0)return ;
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val=value;
            updateFreqList(node);
        }
        else {
            if(maxCap==currCap){
                List* list=freqList[minFreq];
                Node* node=list->tail->prev;
                freqList[minFreq]->removeNode(node);
                keyNode.erase(node->key);
                currCap--;
            }
            Node* node=new Node(key,value);
            currCap++;
            minFreq=1;
            List* list=new List();
            if(freqList.find(minFreq)!=freqList.end()){
                list=freqList[minFreq];
            }
            list->addFront(node);
            keyNode[key]=node;
            freqList[minFreq]=list;
        }
    }
};
int main(){

}