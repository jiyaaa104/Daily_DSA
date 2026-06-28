#include<bits/stdc++.h>
using namespace std;
//1. 
void printSubSeq(int index,vector<int>&arr,vector<int>&current){
   //base case
   if(index==arr.size()){
      for(int x:current){
         cout<<x<<" ";
      }cout<<endl;
      return;
   }

   //pick item
   current.push_back(arr[index]);
   printSubSeq(index+1,arr,current);

   //skip item
   current.pop_back();
   printSubSeq(index+1,arr,current);
}
void sumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   //base case
   if(arr.size()==index){
      if(sum==k){
         for(int x: current){
            cout<<x<<" ";
         }cout<<endl;
      }
      return;
   }

   //pick
   current.push_back(arr[index]);
   sum+=arr[index];
   sumK(index+1,k,sum,arr,current);

   //skip
   sum-=arr[index];
   current.pop_back();
   sumK(index+1,k,sum,arr,current);
}
bool checksumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   //base case
   if(index==arr.size()){
      if(sum==k){
         for(int x:current){
            cout<<x<<" ";
         }cout<<endl;
         return true;
      }
      return false;
   }

   //pick
   current.push_back(arr[index]);
   sum+=arr[index];
   if(checksumK(index+1,k,sum,arr,current)) return true;

   //skip]
   sum-=arr[index];
   current.pop_back();
   if(checksumK(index+1,k,sum,arr,current)) return true;

   return false;
}

int countsumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
   //bc
   if(index==arr.size()){
      if(sum==k){
         return 1;
      }
      return 0;
   }

   //pick
   current.push_back(arr[index]);
   sum+=arr[index];
   int left = countsumK(index+1,k,sum,arr,current);

   //skip
   sum-=arr[index];
   current.pop_back();
   int right=countsumK(index+1,k,sum,arr,current);
   return left+right;
}

void printBinaryStr(int index,int n,string& current){
   //base case
   if(index==n){
      cout<<current<<endl;
      return;
   }

   //pick 0
   current.push_back('0');
   printBinaryStr(index+1,n,current);
   current.pop_back();

   //pick 1
   current.push_back('1');
   printBinaryStr(index+1,n,current);
   current.pop_back();
}

void printBinaryNoConsecutive1(int index,int n,string&current){
   //base case
   if(index==n){
      cout<<current<<endl;
      return;
   }

    //pick 0
   current.push_back('0');
   printBinaryNoConsecutive1(index+1,n,current);
   current.pop_back();

   //pick 1
   if(current.empty() || current.back()!='1'){
      current.push_back('1');
      printBinaryNoConsecutive1(index+1,n,current);
      current.pop_back();
   }
   
}

void generateParenthesis(int open,int close,int n,string&current){
   //base case
   if(open==n && close==n){
      cout<<current<<endl;
      return;
   }

   if(open<n){
      current.push_back('(');
      generateParenthesis(open+1,close,n,current);
      current.pop_back();
   }

   if(close<open){
      current.push_back(')');
      generateParenthesis(open,close+1,n,current);
      current.pop_back();
   }
}

void letterCasePermutation(int index,string& s,string &current){
   //base
   if(s.size()==index){
      cout<<current<<endl;
      return;
   }

   if(isdigit(s[index])){
      current.push_back(s[index]);
      letterCasePermutation(index+1,s,current);
      current.pop_back();
   }else{
      current.push_back(tolower(s[index]));
      letterCasePermutation(index+1,s,current);
      current.pop_back();

      current.push_back(toupper(s[index]));
      letterCasePermutation(index+1,s,current);
      current.pop_back();
   }
}
 void printVector(vector<vector<int>>arr){
   for(int i=0;i<arr.size();i++){
      for(int j=0;j<2;j++){
         cout<<arr[i][j]<<" ";
      }cout<<endl;
   }return;
 }
vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>>ans;
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        int n=occupiedIntervals.size();
        for(int i=0;i<n;i++){
            int start=occupiedIntervals[i][0],end=occupiedIntervals[i][1];
            if(!ans.empty() && ans.back()[1]>=start){
                continue;
            }
            for(int j=i+1;j<n;j++){
            if(occupiedIntervals[j][0]<=end || occupiedIntervals[j][0]==end+1){
                end=max(end,occupiedIntervals[j][1]);
            }else{
                break;
            }
            }
            if(start>=freeStart && start<=freeEnd){
                    if(end<=freeEnd){
                        continue;
                    }else{
                        start=freeEnd+1;
                    }
                }else if(end>=freeStart && end<=freeEnd){
                    end=freeStart-1;
                }
                cout << "i = " << i << endl;
cout << "start = " << start << " end = " << end << endl;

if(freeStart>=start && freeEnd<=end){
    cout << "splitting\n";
    ans.push_back({start,freeStart-1});
    ans.push_back({freeStart+1,end});
    continue;
}
            ans.push_back({start,end});
        }return ans;
    }
int main(){
   vector<vector<int>>occupiedIntervals={{1,3},{4,6}};
   int fs=3,fe=4;
   vector<vector<int>>ans=filterOccupiedIntervals(occupiedIntervals,fs,fe);
   printVector(ans);
   return 0;
}
