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
int main(){

}