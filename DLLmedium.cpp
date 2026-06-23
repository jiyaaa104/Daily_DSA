#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    int data;
    Node* prev;
    Node* next;
    Node(int data1,Node* prev1,Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
class Solution{
   public:
    Node* convertArr2DLL(vector<int>arr){
        Node* head=new Node(arr[0],nullptr,nullptr);
        Node* prev=head;
        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],prev,nullptr);
            prev->next=temp;
            prev=temp;
        }
        return head;
    }
    void printList(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
        return;
    }
    Node* deleteAllOccurances(Node* head,int val){
        if(head==nullptr){
           return nullptr;
        }
        Node* dummy=new Node(-1,nullptr,head);
        head->prev=dummy;
        Node* temp=dummy;
        while(temp->next!=nullptr){
            if(temp->next->data==val){
                Node* delNode=temp->next;
                temp->next=temp->next->next;
                if(temp->next!=nullptr){
                    temp->next->prev=temp;
                }
                delete delNode;
            }else{
                temp=temp->next;
            }
        }
        head=dummy->next;
        if(head!=nullptr){
            head->prev=nullptr;
        }delete dummy;
        return head;
    }
    void pairsWithSum(Node* head,int k){
        if(head==nullptr || head->next==nullptr){
            cout<<"NO Pair Possible!"<<endl;
            return;
        }
        vector<pair<int,int>>vec;
        Node* start=head;
        Node* end=head->next;
        while(end->next!=nullptr){
            end=end->next;
        }
        while(start!=end && start->prev!=end){
            int sum=start->data+end->data;
            if(sum==k){
              vec.push_back({start->data,end->data});
              start=start->next;
              end=end->prev;
            }
            else if(sum<k){
                start=start->next;
            }else{
                end=end->prev;
            }
        }
        if(vec.empty()){
            cout<<"NAAH!"<<endl;
            return;
        }
        for(int i=0;i<vec.size();i++){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }return;
    }
    Node* removeDuplicates(Node* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            if(temp->next->data==temp->data){
                Node* delNode=temp->next;
                temp->next=temp->next->next;
                delete delNode;
                if(temp->next!=nullptr){
                    temp->next->prev=temp;
                }
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};
int main(){
    vector<int>arr={10,10,30,30,50,50};
    Solution s;
    Node* head=s.convertArr2DLL(arr);
    s.printList(head);
    head=s.removeDuplicates(head);
    s.printList(head);
    return 0;
}