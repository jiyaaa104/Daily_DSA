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
      void printList(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }cout<<endl;
      }
      Node* convertArr2SLL(vector<int>arr){
        Node* head=new Node(arr[0]);
        int n=arr.size();
        Node* prev=head;
        for(int i=1;i<n;i++){
            Node* newNode=new Node(arr[i]);
            prev->next=newNode;
            prev=newNode;
        }return head;
      }
        Node* middleEl(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
      }
      //REVERSE A LL (BRUTE)
    //   Node* ReverseLL(Node* head){
    //     stack<Node*>st;
    //     Node* temp=head;
    //     while(temp!=nullptr){
    //        st.push(temp);
    //        temp=temp->next;
    //     }
    //     Node* newH=st.top();
    //     Node* prev=newH;
    //     st.pop();
    //     while(!st.empty()){
    //         temp=st.top();
    //         st.pop();
    //         prev->next=temp;
    //         prev=temp;
    //     }
    //     prev->next=nullptr;
    //     return newH;
    //   }
    // OPTIMAL(REVERSE)(Iterative)
    // Node* revereseLL(Node* head){
    //    Node* prev=nullptr;
    //    Node* temp=head;
    //    while(temp!=nullptr){
    //     Node* front=temp->next;
    //     temp->next=prev;
    //     prev=temp;
    //     temp=front;
    //    }
    //      return prev;
    // }

    //optimal(RECURSIVE)(I WROTE THIS)
    // Node* reverseLL(Node* temp,Node* prev,Node* front){
    //     if(temp==nullptr){
    //         return prev;
    //     }
    //     front=temp->next;
    //     temp->next=prev;
    //     prev=temp;
    //     temp=front;
    //     return reverseLL(temp,prev,front);
    // }
    Node* reverseLL(Node* head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        Node* newHead=reverseLL(head->next);
        Node* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
    Node* startingNode(Node* head){
        Node* fast=head;
        Node* slow=head;
        bool state=false;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                state=true;
                break;
            }
        }if(state==false){
            return nullptr;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    void lengthLoop(Node* head){
        //BRUTE(SC(O(N)))
        // unordered_map<Node*,int>mpp;
        // Node* temp=head;
        // int count=0;int ans=0;
        // while(temp!=nullptr){
        //    if(mpp.find(temp)!=mpp.end()){
        //         count++;
        //         ans=count-mpp[temp];
        //         break;
        //    }else{
        //     count++;
        //     mpp[temp]=count;
        //    }
        //    temp=temp->next;
        // }
        // cout<<ans<<endl;
        //OPTIMAL
        Node* fast=head;
        Node* slow=head;bool check=false;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<"No loop exists!"<<endl;return;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        Node* start=slow;
        start=start->next;
        int count=1;
        while(start!=slow){
           start=start->next;
           count++;
        }
        cout<<count<<endl;
    }
    bool palindromeLL(Node* head){
        //BRUTE
        //(WHENEVER YOU ARE DEALING WITH REVERSAL ALWAYS->BRUTE-> STACK!!!)
        // Node* temp=head;
        // stack<int>st;
        // while(temp!=nullptr){
        //     st.push(temp->data);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(!st.empty()){
        //     int c=st.top();
        //     if(c==temp->data){
        //         temp=temp->next;
        //         st.pop();
        //     }else{
        //         return false;
        //     }
        // }return true;

        //OPTIMAL 
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* newH=reverseLL(slow->next);
        Node* first=head;
        Node* second=newH;
        while(second!=nullptr){
            if(first->data==second->data){
                first=first->next;
                second=second->next;
            }else{
                return false;
            }
        }return true;
    }
    Node* OddEven(Node* head){
    vector<int>arr;
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* odd=head;
    while(odd->next!=nullptr && odd->next->next!=nullptr){
      arr.push_back(odd->data);
      odd=odd->next->next;
    }
    if(odd!=nullptr){
      arr.push_back(odd->data);
    }
    Node* even=head->next;
    while(even->next!=nullptr && even->next->next!=nullptr){
      arr.push_back(even->data);
      even=even->next->next;
    }
    if(even!=nullptr){
      arr.push_back(even->data);
    }
    head=convertArr2SLL(arr);
    return head;
   }

   Node* deleteNFromLast(Node* head,int n){
      if(head==nullptr){
        return nullptr;
      }
      if(head->next==nullptr){
        delete head;
          return nullptr;
      }
    //   int count=0;
    //   Node* temp=head;
    //   while(temp!=nullptr){
    //     count++;
    //     temp=temp->next;
    //   }
    //   int m=count-n+1;
    //   int num=1;
    //   if(m==1){
    //     Node* newH=head->next;
    //     delete head;
    //     return newH;
    //   }
    //   Node* prev=nullptr;
    //    temp=head;
    //   Node* front=temp->next;
    //   while(m!=num){
    //     num++;
    //     prev=temp;
    //     temp=front;
    //     front=temp->next;
    //   }
    //  Node* delNode=temp;
    //  prev->next=front;
    //  delete delNode;
    //  return head;
    Node* fast=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    if(fast==nullptr){
       Node* newH=head->next;
       delete head;
       return newH;
    }
    Node* slow=head;
    while(fast->next!=nullptr){
       fast=fast->next;
       slow=slow->next;
    }
    Node* delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
   }
//    Node* SortList(Node* head){
//     Node* temp=head;
//     vector<int>arr;
//     while(temp!=nullptr){
//         arr.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(arr.begin(),arr.end());
//     temp=head;
//     for(int i=0;i<arr.size();i++){
//        temp->data=arr[i];
//        temp=temp->next;
//     }
//     return head;
//    }
   Node* merge2Sorted(Node* list1,Node* list2){
    Node* temp1=list1;Node* temp2=list2;Node* dummy=new Node(0);Node* temp=dummy;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<=temp2->data){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }else{
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=nullptr){
        temp->next=temp1;
        temp=temp->next;
        temp1=temp1->next;
    }
    while(temp2!=nullptr){
        temp->next=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }return dummy->next;
   }
   Node* SortList(Node* list){
    if(list==nullptr || list->next==nullptr){
        return list;
    }
     Node* mid=middleEl(list);
     Node* leftH=list;
     Node* right=mid->next;
     mid->next=nullptr;
     leftH=SortList(list);
     right=SortList(right);
     return merge2Sorted(leftH,right);
   }

   Node* sort012(Node* head){
    Node* dummy0=new Node(0);Node* t0=dummy0;
    Node* dummy1=new Node(0);Node* t1=dummy1;
    Node* dummy2=new Node(0);Node* t2=dummy2;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            t0->next=temp;
            t0=t0->next;
            
        }
        else if(temp->data==1){
            t1->next=temp;
            t1=t1->next;
        }else{
            t2->next=temp;
            t2=t2->next;
        }
        temp=temp->next;
    }
    t0->next=(dummy1->next)?dummy1->next:dummy2->next;
    t1->next=dummy2->next;
    t2->next=nullptr;
    return dummy0->next;
   }
   Node* intersection2Lists(Node* list1,Node* list2){
    //BETTER APPROACH : DIFFERENCE OF LENGTH
    // if(list1==nullptr || list2==nullptr){
    //     return nullptr;
    // }
    //  int n1=0,n2=0;
    //  Node* temp=list1;
    //  while(temp!=nullptr){
    //     n1++;
    //     temp=temp->next;
    //  }
    //  temp=list2;
    //  while(temp!=nullptr){
    //     n2++;
    //     temp=temp->next;
    //  }
    //  int diff;Node* t1=list1;Node* t2=list2;bool v2=false;bool v1=false;
    //  if(n1>n2){
    //     diff=n1-n2;
    //     temp=t2;
    //     v2=true;
    //  }else if(n2>n1){
    //     diff=n2-n1;
    //     temp=t1;
    //     v1=true;
    //  }else{
    //     diff=0;
    //  }
    //  while(diff!=0){
    //     diff--;
    //     temp=temp->next;
    //  }
    //  if(v1){
    //     t1=temp;
    //  }
    //  if(v2){
    //     t2=temp;
    //  }
    //  while(t1!=nullptr){
    //     if(t1==t2){
    //         return t1;
    //     }
    //     t1=t1->next;
    //     t2=t2->next;
    //  }
    //  return nullptr;

    //OPTIMAL APPROACH : KHATARNAAKAM
    if(list1==nullptr || list2==nullptr){
        return nullptr;
    }
    Node* temp1=list1;
    Node* temp2=list2;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2){
            return temp1;
        }
        if(temp1==nullptr){
            temp1=list2;
        }
        if(temp2==nullptr){
            temp2=list1;
        }
   }
   return temp1;
}
Node* increaseByOne(Node* head){
    Node* newH=reverseLL(head);
    if(newH->data<9){
        newH->data++;
        head=reverseLL(newH);
        return head;
    }
    Node* temp=newH;
    bool v=false;
    while(temp!=nullptr){
        if(temp->data==9){
            v=false;
            temp->data=0;
            temp=temp->next;
        }
        else{
            v=true;
            temp->data++;
            break;
        }
    }
    if(!v){
      Node* newHead=new Node(1);
      newHead->next=newH;
      return newHead;
    }
    head=reverseLL(newH);
    return head;
    
}
int helper(Node* temp){
    if(temp==nullptr){
        return 1;
    }
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* recursiveIncOne(Node* head){
    int carry=helper(head);
    if(carry==1){
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }else{
        return head;
    }
}
};
int main(){
    Node* head1=new Node(1);
    Node* a1=new Node(9);
    Node* b1=new Node(9);
    // Node* c1=new Node(9);
    // Node* d1=new Node(9);
    head1->next=a1;
    a1->next=b1;
    // b1->next=c1;
    // c1->next=d1;
    // Node* head2=new Node(10);
    // Node* a2=new Node(2);
    // head2->next=a2;
    // a2->next=b1;
    Solution s;
    Node* x=s.recursiveIncOne(head1);
    s.printList(x);
    
    return 0;
}