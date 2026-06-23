#include<bits/stdc++.h>
using namespace std;
// class Node{
//   public: int data;Node* next;
//   Node(int data1,Node* next1){
//     data=data1;
//     next=next1;
//   }
//   Node(int data1){
//     data=data1;
//     next=nullptr;
//   }
// };
// class Solution{
//   public:
//     Node* convertArr2LL(vector<int>arr){
//         Node* head=new Node(arr[0]);
//         Node* prev=head;
//         for(int i=1;i<arr.size();i++){
//             Node* temp=new Node(arr[i]);
//             prev->next=temp;
//             prev=temp;
//         }return head;
//     }
//     void printList(Node* head){
//         Node* temp=head;
//         while(temp!=nullptr){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }cout<<endl;
//         return;
//     }
//     Node* reverseLL(Node* head){
//         Node* temp=head;
//         Node* prev=nullptr;
//         while(temp!=nullptr){
//             Node* front=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=front;
//         }return prev;
//     }
//     Node* findKthNode(Node* head,int k){
//         Node* temp=head;
//         for(int i=2;i<=k;i++){
//             temp=temp->next;
//             if(temp==nullptr){
//                 return nullptr;
//             }
//         }return temp;
//     }
//     Node* reverseKGroup(Node* head,int k){
//         if(k==1 || head==nullptr){
//             return head;
//         }
//         Node* temp=head;Node* prevHead=nullptr;
//         while(temp!=nullptr){
//           Node* kNode=findKthNode(temp,k);
//           if(kNode==nullptr){
//             if(prevHead==nullptr){
//                 return head;
//             }
//             prevHead->next=temp;
//             break;
//           }
//           Node* nextNode=kNode->next;
//           kNode->next=nullptr;
//           reverseLL(temp);
//           if(prevHead!=nullptr){
//             prevHead->next=kNode;
//           }else{
//             head=kNode;
//           }
//             prevHead=temp;
//             temp=nextNode;
//         }return head;
//     }
// };

//-----------------------------------FLATTEN A LINKED LIST-----------------------------------------------------------------------
// class Node{
//   public:
//     int data;
//     Node* next;
//     Node* child;
//     Node(int data1,Node* next1,Node* child1){
//        data=data1;
//        next=next1;
//        child=child1;
//     }
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//         child=nullptr;
//     }
//      Node(){
//         data=0;
//         next=nullptr;
//         child=nullptr;
//      }
// };
// class flatten{
//     public:
//    Node* convertArr2LL(vector<int>arr){
//      int n=arr.size();
//      if(arr.empty()){
//         return nullptr;
//      }
//      Node* head=new Node(arr[0]);
//      Node* temp=head;
//      for(int i=1;i<n;i++){
//        temp->child=new Node(arr[i]);
//        temp=temp->child;
//      }return head;
//    }
//    Node* brute(Node* head){
//      vector<int>arr;
//      Node* temp=head;
//      while(temp!=nullptr){
//         arr.push_back(temp->data);
//          Node* temp2=temp->child;
//          while(temp2!=nullptr){
//             arr.push_back(temp2->data);
//             temp2=temp2->child;
//          }
//          temp=temp->next;
//      }
//      sort(arr.begin(),arr.end());
//       head=convertArr2LL(arr);
//      return head;
//    }
//    void printList(Node* head){
//     Node* temp=head;
//     while(temp!=nullptr){
//         cout<<temp->data<<" ";
//         temp=temp->child;
//     }cout<<endl;
//     return;
//    }
//    Node* merge2Lists(Node* list1,Node* list2){
//      Node* dummy=new Node(-1);
//      Node* temp=dummy;
//      Node* temp1=list1;
//      Node* temp2=list2;
//      while(temp1!=nullptr && temp2!=nullptr){
//         if(temp1->data<=temp2->data){
//             temp->child=temp1;
//             temp1=temp1->child;
//         }else{
//             temp->child=temp2;
//             temp2=temp2->child;
//         }
//         temp=temp->child;
//      }
//      while(temp1!=nullptr){
//         temp->child=temp1;
//         temp1=temp1->child;
//         temp=temp->child;
//      }
//      while(temp2!=nullptr){
//         temp->child=temp2;
//         temp2=temp2->child;
//         temp=temp->child;
//      }return dummy->child;
//    }
//    Node* flattenLL(Node* head){
//     if(head==nullptr || head->next==nullptr){
//         return head;
//     }
//      Node* mergedHead=flattenLL(head->next);
//      return merge2Lists(head,mergedHead);
//    }  
// };
// int main(){
//     cout<<"Loading..........";
//     cerr<<"File Missing!";
    
//     return 0;
// }


//---------------------RANDOM POINTER----(COPY A LL)-----------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
   int data;
   Node* next;
   Node* random;
   Node(int data1,Node* next1,Node* random1){
      data=data1;
      next=next1;
      random=random1;
   }
   Node(int data1){
      data=data1;
      next=nullptr;
      random=nullptr;
   }
};
class Solution{
  public:
   void printList(Node* head){
      Node* temp=head;
      while(temp!=nullptr){
         cout<<"Data : "<<temp->data<<" "<<"Random : "<<temp->random->data<<endl;
         temp=temp->next;
      }return;
   }
    Node* copyListBrute(Node* head){
      map<Node*,Node*>mpp;
      Node* temp=head;
      while(temp!=nullptr){
         mpp[temp]=new Node(temp->data);
         temp=temp->next;
      }
      temp=head;
      while(temp!=nullptr){
         mpp[temp]->next=mpp[temp->next];
         mpp[temp]->random=mpp[temp->random];
         temp=temp->next;
      }
      return mpp[head];
    }
    Node* copyListOptimal(Node* head){
      Node* temp=head;
      while(temp!=nullptr){
         Node* copyNode=new Node(temp->data);
         Node* nextNode=temp->next;
         temp->next=copyNode;
         copyNode->next=nextNode;
         temp=temp->next->next;
      }
      temp=head;
      while(temp!=nullptr){
         Node* ran=temp->random;
         Node* copyNode=temp->next;
         if(ran==nullptr){
            copyNode->random=ran;
         }else{
            copyNode->random=ran->next;
         }
         temp=temp->next->next;
      }
      Node* dummy=new Node(0);
      temp=head;
      Node* res=dummy;
      while(temp!=nullptr){
         Node* copyNode=temp->next;
         res->next=copyNode;
         temp->next=temp->next->next;
         temp=temp->next;
         res=res->next;
      }return dummy->next;
    }
};
int main(){
   
   return 0;
}