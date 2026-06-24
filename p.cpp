// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//   public: int data;
//   Node* next;
//   Node( int data1,Node* next1){
//     next=next1;
//     data=data1;
//   }
//   Node(int data1){
//     data=data1;
//     next=nullptr;
//   }
// };
// class Solution{
//   public:
//      Node* convertArr2LL(vector<int>arr){
//       int n=arr.size();
//       Node* head=new Node(arr[0]);
//       Node* prev=head;
//       for(int i=1;i<n;i++){
//         Node* temp=new Node(arr[i]);
//         prev->next=temp;
//         prev=temp;
//       }return head;
//      }
//      void printList(Node* head){
//       Node* temp=head;
//       while(temp!=nullptr){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//       }cout<<endl;
//       return;
//      }
//      Node* reverseI(Node* head){
//       Node* temp=head;
//       Node* prev=nullptr;
//       while(temp!=nullptr){
//         Node* front=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=front;
//       }return prev;
//      }
//      Node* reverseR(Node* head){
//       if(head==nullptr || head->next==nullptr){
//         return head;
//       }
//       Node* newHead=reverseR(head->next);
//       Node* front=head->next;
//       front->next=head;
//       head->next=nullptr;
//       return newHead;
//      }
//      Node* middleNode(Node* head){
//       Node* fast=head;Node* slow=head;
//       while(fast->next!=nullptr &&  fast->next->next!=nullptr){
//         fast=fast->next->next;
//         slow=slow->next;
//       }return slow;
//      }
//      bool detectLoop(Node* head){
//       Node* fast=head;
//       Node* slow=head;
//       while(fast!=nullptr && fast->next!=nullptr){
//         fast=fast->next->next;
//         slow=slow->next;
//         if(slow==fast){
//           return true;
//         }
//       }return false;
//      }
//      Node* startPoint(Node* head){
//       Node* fast=head;
//       Node* slow=head;bool loop=false;
//       while(fast!=nullptr && fast->next!=nullptr){
//         fast=fast->next->next;
//         slow=slow->next;
//         if(slow==fast){
//           loop=true;
//           break;
//         }
//       }
//       if(!loop){
//         return nullptr;
//       }
//       slow=head;
//       while(slow!=fast){
//         fast=fast->next;
//         slow=slow->next;
//       }
//       return slow;
//      }
//      int lengthLoop(Node* head){
//       Node* fast=head;
//       Node* slow=head;bool loop=false;
//       while(fast!=nullptr && fast->next!=nullptr){
//         fast=fast->next->next;
//         slow=slow->next;
//         if(slow==fast){
//           loop=true;
//           break;
//         }
//       }
//       if(!loop){
//         return 0;
//       }
//       Node* start=fast;
//       Node* temp=start->next;
//       int count=1;
//       while(temp!=start){
//         count++;
//         temp=temp->next;
//       }
//        return count;
//      }
//      bool palindrome(Node* head){
//       if(head==nullptr || head->next==nullptr){
//         return true;
//       }
//        Node* mid=middleNode(head);
//        Node* second=mid->next;
//        mid->next=nullptr;
//        second=reverseI(second);
//        Node* first=head;
//        while(second!=nullptr){
//          if(first->data!=second->data){
//           return false;
//          }
//          first=first->next;
//          second=second->next;
//        }return true;
//      }
//      Node* oddEvenLL(Node* head){
//       if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
//         return head;
//       }
//       Node* todd=head;
//       Node* eveHead=todd->next;
//       Node* teve=todd->next;
//       while(teve!=nullptr && teve->next!=nullptr){
//         todd->next=todd->next->next;
//         teve->next=teve->next->next;
//         todd=todd->next;
//         teve=teve->next;
//       }
//       todd->next=eveHead;
//       return head;
//      }
//      Node* deleteNBack(Node* head,int n){
//       if(head==nullptr || head->next==nullptr){
//         return nullptr;
//       }
//        Node* fast=head;Node* slow=head;
//        for(int i=1;i<=n;i++){
//          fast=fast->next;
//         }
//         if(fast==nullptr){
//           return head->next;
//         }
//         while(fast->next!=nullptr){
//           slow=slow->next;
//           fast=fast->next;
//         }
//         Node* delNode=slow->next;
//         slow->next=slow->next->next;
//         delete delNode;
//         return head;
//      }
//      Node* deleteMiddle(Node* head){
//       if(head==nullptr){
//         return nullptr;
//       }
//       if(head->next==nullptr){
//         delete head;
//         return nullptr;
//       }
//       Node* slow=head;
//       Node* fast=head;
//       Node* prev=nullptr;
//       while(fast!=nullptr && fast->next!=nullptr){
//         prev=slow;
//         fast=fast->next->next;
//         slow=slow->next;
//       }
//       Node* delNode=prev->next;
//       prev->next=prev->next->next;
//       delete delNode;
//       return head;
//      }
//      Node* merge2SortedLists(Node* list1,Node* list2){
//       Node* dummy=new Node(0);
//       Node* temp=dummy;
//       Node* temp1=list1;
//       Node* temp2=list2;
//       while(temp1!=nullptr && temp2!=nullptr){
//         if(temp1->data <= temp2->data){
//            temp->next=temp1;
//            temp1=temp1->next;
//         }else{
//           temp->next=temp2;
//           temp2=temp2->next;
//         }
//         temp=temp->next;
//       }
//       while(temp1!=nullptr){
//         temp->next=temp1;
//         temp=temp->next;
//         temp1=temp1->next;
//       }
//       while(temp2!=nullptr){
//         temp->next=temp2;
//         temp=temp->next;
//         temp2=temp2->next;
//       }
//       return dummy->next;
//      }
//      Node* sortLL(Node* head){
//       if(head==nullptr || head->next==nullptr){
//         return head;
//       }
//       Node* midNode=middleNode(head);
//       Node* nextNode=midNode->next;
//       midNode->next=nullptr;
//       Node* leftH=sortLL(head);
//       Node* rightH=sortLL(nextNode);
//       return merge2SortedLists(leftH,rightH);
//      }
//      Node* sort012(Node* head){
//       Node* dummy0=new Node(-1);
//       Node* dummy1=new Node(-1);
//       Node* dummy2=new Node(-1);
//       Node* temp0=dummy0;
//       Node* temp1=dummy1;
//       Node* temp2=dummy2;
//       Node* temp=head;
//       while(temp!=nullptr){
//         if(temp->data==0){
//           temp0->next=temp;
//           temp0=temp0->next;
//         }else if(temp->data==1){
//           temp1->next=temp;
//           temp1=temp1->next;
//         }else{
//           temp2->next=temp;
//           temp2=temp2->next;
//         }
//        temp=temp->next;
//       }
//       temp0->next=(dummy1->next)?dummy1->next:dummy2->next;
//       temp1->next=dummy2->next;
//       temp2->next=nullptr;
//       return dummy0->next;
//      }
//      Node* intersectionLists(Node* list1,Node* list2){
//       Node* temp1=list1;
//       Node* temp2=list2;
//       while(temp1!=temp2){
//         temp1=(temp1==nullptr)?list2:temp1->next;
//         temp2=(temp2==nullptr)?list1:temp2->next;
//       }return temp1;
//      }
//      int helper(Node* list){
//        if(list==nullptr){
//         return 1;
//        }
//        int carry=helper(list->next);
//        list->data=list->data+carry;
//        if(list->data<10){
//           return 0;
//        }
//        list->data=0;
//        return 1;
//      }
//      Node* addOne(Node* list){
//         int carry=helper(list);
//         if(carry==0){
//           return list;
//         }else{
//           Node* newNode=new Node(1);
//           newNode->next=list;
//           return newNode;
//         }
//      }

//      Node* add2Nums(Node* head1,Node* head2){
//       Node* l1=head1;
//       Node* l2=head2;int carry=0;Node* dummy3=new Node(-1);Node* l3=dummy3;
//       while(carry!=0 || l1!=nullptr ||l2!=nullptr){
//         int sum=0;
//         if(l1!=nullptr){
//           sum+=l1->data;
//           l1=l1->next;
//         }
//         if(l2!=nullptr){
//           sum+=l2->data;
//           l2=l2->next;
//         }
//         sum+=carry;
//         if(sum<10){
//           carry=0;
//           l3->next=new Node(sum);
//         }else{
//           carry=1;
//           int p=sum%10;
//           l3->next=new Node(p);
//         }
//         l3=l3->next;
//       }return dummy3->next;
//      }
// };
// int main(){
//   Node* list1=new Node(0);
//   list1->next=new Node(1);
//   list1->next->next=new Node(2);
//   list1->next->next->next=new Node(3);
//   list1->next->next->next->next=new Node(4);
//   list1->next->next->next->next->next=new Node(5);

//   Node* list2=new Node(0);
//   list2->next=new Node(1);
//   list2->next->next=new Node(2);
  
//   Solution s;
//   Node* inter=s.add2Nums(list1,list2);
//   s.printList(inter);
  
//   return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>arr(10,0);
   for(int i=0;i<10;i++){
    cin>>arr[i];
   }
}
