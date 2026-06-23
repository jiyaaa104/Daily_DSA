#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
     int data;
     Node* next;
     Node* prev;
     Node(int data1,Node* next1,Node* prev1){
        data=data1; 
        next=next1;
        prev=prev1;
     }
     Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
     }
};
class Solution{public:
   void printList(Node* head){
     Node* temp=head;
     while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
     }cout<<endl;
   }
   Node* convertArr2DLL(vector<int>arr){
    int n=arr.size();
    if(n==0){
        return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<n;i++){
        Node* newNode=new Node(arr[i],nullptr,prev);
        prev->next=newNode;
        prev=newNode;
    }
    return head;
   }
    Node* insertAtTail(Node* head,int val){
        int n=0;
        Node* temp=head;
        if(head==nullptr){
            Node* newNode=new Node(val);
            return newNode;
        }
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* newNode=new Node(val,nullptr,temp);
        temp->next=newNode;
        return head;
    }
    Node* deleteTheTail(Node* head){
        if(head==nullptr){return nullptr;}
        if(head->next==nullptr){
            delete head;
            return nullptr;
        }
        Node* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        Node* delNode=temp->next;
        temp->next=nullptr;
        delete delNode;
        return head;
    }
    Node* deleteTheHead(Node* head){
        Node* newH=head->next;
        delete head;
        return newH;
    }
    Node* reverseDll(Node* head){
        Node* temp=head;
        Node* back=nullptr;
        while(temp!=nullptr){
           back=temp->prev;
           temp->prev=temp->next;
           temp->next=back;
           temp=temp->prev;
        }return back->prev;
    }
    void middleElement(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next;
            fast=fast->next;
            slow=slow->next;
        }
        cout<<slow->data<<" ";
        return;
    }
};
int main(){
    vector<int>arr={10,20,30,40,50,90};
    Solution s;
    Node* head=s.convertArr2DLL(arr);
    s.middleElement(head);
    return 0;
}