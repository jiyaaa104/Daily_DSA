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
class Node{
 public: 
   int key,val;Node* next;Node* prev;
   Node(int k,int v){
    key=k;
    val=v;
    next=nullptr;
    prev=nullptr;
   }
};
class LRUCache{
    public: 
    int size;Node* head;Node* tail;unordered_map<int,Node*>mpp;
    LRUCache(int capacity){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        mpp.clear();
        size=capacity;
    }
    void insertAtHead(Node* node){
        Node* nextNode=head->next;
        head->next=node;
        node->prev=head;
        node->next=nextNode;
        nextNode->prev=node;
    }
    void deleteNode(Node* node){
        Node* nextNode=node->next;
        Node* prevNode=node->prev;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    int get(int key){
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node* node=mpp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->val;
    }
    void put(int key,int val){
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->val=val;
            deleteNode(mpp[key]);
            insertAtHead(mpp[key]);
            return;
        }
        if(mpp.size()==size){
            Node* del=tail->prev;
            deleteNode(del);
            mpp.erase(del->key);
            delete del;
        }
        Node* node=new Node(key,val);
        mpp[key]=node;
        insertAtHead(node);
    }
};
int main(){

}