#include<bits/stdc++.h>
using namespace std;
void permute(int index,string&s,string&current){
    if(index==s.size()){
        cout<<current<<" ";
        return;
    }
    if(isdigit(s[index])){
        current.push_back(s[index]);
        permute(index+1,s,current);
        current.pop_back();
    }
    else{
        current.push_back(tolower(s[index]));
        permute(index+1,s,current);
        current.pop_back();
        current.push_back(toupper(s[index]));
        permute(index+1,s,current);
        current.pop_back();
    }
}
void combination(int index,string&digits,string & current,vector<string>&phone){
    if(index==digits.size()){
        cout<<current<<endl;
        return;
    }
    int i=digits[index]-'0';
    string p=phone[i];
    for(int i=0;i<p.size();i++){
        current.push_back(p[i]);
        combination(index+1,digits,current,phone);
        current.pop_back();
    }
}
void cSum(int index,vector<int>&candidates,int target,vector<int>&current,int sum){
    if(index==candidates.size()){
        if(target==0){
            for(int x: current){
                cout<<x<<" ";
            }cout<<endl;
        }
        return;
    }
    if(candidates[index]<=target){
        sum+=candidates[index];
        target-=candidates[index];
        current.push_back(candidates[index]);
        cSum(index,candidates,target,current,sum);
        current.pop_back();
        target+=candidates[index];
        sum-=candidates[index];
    }
    cSum(index+1,candidates,target,current,sum);
}
void cSum2(int index,vector<int>&candidates,int target,vector<int>&current,int sum){
    if(target==0){
        for(int x: current){
            cout<<x<<" ";
        }cout<<endl;
        return;
    }
    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target){
            break;
        }
        sum+=candidates[i];
        target-=candidates[i];
        current.push_back(candidates[i]);
        cSum2(i+1,candidates,target,current,sum);
        current.pop_back();
        target+=candidates[i];
        sum-=candidates[i];
    }
}
void cSum3(int index,vector<int>&current,int target,int k){
    if(current.size()>k) return;
    if(current.size()==k){
        if(target==0){
            for(int x: current){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=index;i<=9;i++){
        if(i>target) break;
        target-=i;
        current.push_back(i);
        cSum3(i+1,current,target,k);
        target+=i;
        current.pop_back();
    }
}
int main(){
    vector<string>phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s="a1b2";
   vector<int>current;
    string digits="23";
    vector<int>candidates={2,2,2,1,3,6,7};
    int sum=0,target=7;
    // cSum2(0,candidates,target,current,sum);
    cSum3(1,current,9,3);
    // cSum(0,candidates,target,current,sum);
    // combination(0,digits,current,phone);
    return 0;
}