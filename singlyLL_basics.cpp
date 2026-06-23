// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data1,Node* next1){
//         data=data1;
//         next=next1;
//     }
//     Node(int data1){
//         data=data1;
//         next=nullptr;
//     }
// };
// int main()
// {
//     Node* y=new Node(2);
//     cout<<"Address pointed by the pointer y : "<<y<<endl;
//     cout<<"Address at which the pointer y is stored : "<<&y<<endl;
//     cout<<"Value of the data member of y : "<<y->data<<endl;
//     cout<<"Address of the data member of y : "<<&(y->data)<<endl;
//     cout<<"Value of the next pointer member of y : "<<y->next<<endl;
//     cout<<"Address of the next pointer member of y : "<<&(y->next)<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//    public: int data; Node* next;
//            Node(int data1,Node* next1){
//             data=data1;
//             next=next1;
//            }
//            Node(int data1){
//             data=data1;
//             next=nullptr;
//            }
// };
// int main()
// {
//     Node* y1=new Node(10);
//     // cout<<y1<<endl;
//     // cout<<y1->data<<endl;
//     // cout<<y1->next<<endl;
//     Node* y2=new Node(20);
//     y1->next=y2;
//     // cout<<"Address of node 1 : "<<y1<<endl;
//     // cout<<"Data of node 1 : "<<y1->data<<endl;
//     // cout<<"Next of node 1 : "<<y1->next<<endl;
//     // cout<<"Address of node 2 : "<<y2<<endl;
//     // cout<<"Data of node 2 : "<<y2->data<<endl;
//     // cout<<"Next of node 2 : "<<y2->next<<endl;
//     // cout<<y1->data<<" "<<y1->next->data<<endl;
//     Node* y3=new Node(30);
//     y2->next=y3;
//     cout<<y1->data<<" "<<y1->next->data<<" "<<y1->next->next->data<<endl;
//     return 0;
// }

//INSERTION AT THE HEAD OF THE LINKED LIST----------------------------------------------------------
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
// public:
//   int data;
//   Node* next;
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
//    public:
//     Node* insertAtHead(Node* head,int newData){
//         Node* newNode=new Node(newData,head);
//         return newNode;
//     } 
//     void printList(Node* head){
//         Node* temp=head;
//         while(temp!=nullptr){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }cout<<endl;
//     }
// };
// int main()
// {
//     Node* head=new Node(2);
//     head->next=new Node(3);
//     head->next->next=new Node(4);
//     cout<<"Original Linked List : "<<endl;
//     Solution sol;
//     sol.printList(head);
//     head=sol.insertAtHead(head,1);
//     cout<<"Modified Linked List : "<<endl;
//     sol.printList(head);
//     return 0;
// }

//DELTEING THE LAST NODE OF THE LL----------------------------------------------------------------------------
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//   public:
//      int data;
//      Node* next;
//      Node(int data1,Node* next1){
//       data=data1;
//       next=next1;
//      }
//      Node(int data1){
//       data=data1;
//       next=nullptr;
//      }
// };
// class Solution{
//   public: 
//    Node* removeEnd(Node* head){
//     if(head==nullptr){
//       return nullptr;
//     }
//     if(head->next==nullptr){
//        delete head;
//        return nullptr;
//      }
//      Node* temp=head;int count=0;
//      while(temp!=nullptr){
//        count++;
//        temp=temp->next;
//      }
//      int total=count;
//      count=0;
//      temp=head;
//      while(temp!=nullptr){
//       count++;
//           if(count==total-1){
//             Node* delnode=temp->next;
//             temp->next=nullptr;
//             delete delnode;
//             break;
//           }
//           temp=temp->next;
//      }return head;
//    }
//    void printList(Node* head){
//     Node* temp=head;
//     while(temp!=nullptr){
//       cout<<temp->data<<" ";
//       temp=temp->next;
//     }cout<<endl;
//    }
// };
// int main()
// {
//   Node* head=new Node(10);
//   // head->next=new Node(20);
//   // head->next->next=new Node(30);
//   // head->next->next->next=new Node(40);
//   Solution sol;
//   sol.printList(head);
//   head=sol.removeEnd(head);
//   sol.printList(head);
//   return 0;
// }

//---------------------------------LEETCODE:203(REMOVE LEMENTS FROM LL)---------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* temp=head;
//         if(head==nullptr){
//             return nullptr;
//         }
//         if(head->next==nullptr){
//             if(head->val==val){
//                 delete head;
//                 return nullptr;
//             }else{
//                 return head;
//             }
//         }
//         while(temp!=nullptr){
//             if(temp->val==val){
//                  ListNode* delNode=temp;
//                  temp=temp->next;
//                  delete delNode;
//                  continue;
//             }
//             if(temp->next!=nullptr){
//                 ListNode* x=temp->next;
//                 if(x->val==val){
//                 ListNode* delNode=x;
//                 temp->next=x->next;
//                 delete delNode;
//             }
//             }
//             temp=temp->next;
//         }return head;
//     }
// };
//---------------------RIGHT ANSWER--------------------------------------------------------------------
// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//   public:
//    int data;
//    Node* next;
//    Node(int data1,Node* next1){
//     data=data1;
//     next=next1;
//    }
//    Node(int data1){
//     data=data1;
//     next=nullptr;
//    }
// };
// class Solution{
//    Node* RemoveElements(Node* head, int val){
//     if(head==nullptr){
//       return nullptr;
//     }
//     Node* dummy=new Node(0);
//     dummy->next=head;
//     Node* temp=dummy;
//     while(temp->next!=nullptr){
//       Node* x=temp->next;
//       if(x->data==val){
//         temp->next=x->next;
//         delete x;
//       }else{
//         temp=temp->next;
//       }
//     }return dummy->next;
//    }
//    void printList(Node* head){
//     Node* temp=head;
//     while(temp!=nullptr){
//       cout<<temp->data<<" ";
//       temp=temp->next;
//     }cout<<endl;
//    }
// };
// int main(){
   
//   return 0;
// }

//REMOVE DUPLICATES FROM SINGLY LINKED LIST
#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
   int data;
   Node* next;
   Node(int data1,Node* next1){
    data=data1;
    next=next1;
   }
   Node(int data1){
    data=data1;
    next=nullptr;
   }
};
class Solution{
  public:
   Node* removeDuplicates(Node* head){
     Node* temp=head;
     if(head==nullptr){return nullptr;}
     if(head->next==nullptr){return head;}
     while(temp->next!=nullptr){
       Node* x=temp->next;
       if(x->data==temp->data){
         temp->next=x->next;
         delete x;
       }else{
        temp=temp->next;
       }
     }return head;
   }
};
int main(){
  return 0;
}