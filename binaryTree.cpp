#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
   int val;
   TreeNode* left;TreeNode* right;
   TreeNode(int v){
    val=v;
    left=right=nullptr;
   }
};
vector<vector<int>> breadthFirstSearch(TreeNode* root){
    vector<vector<int>>ans;
    if(root==nullptr)return ans;
    queue<TreeNode*>q;
    q.push(root);
     while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
     }
     return ans;
}
vector<int> preOrderTraversal(TreeNode* root){
    vector<int>ans;
    if(root==nullptr)return ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();st.pop();
        if(node->right)st.push(node->right);
        if(node->left)st.push(node->left);
        ans.push_back(node->val);
    }
    return ans;
}
vector<int>inOrderTraversal(TreeNode* root){
      vector<int>ans;
      stack<TreeNode*>st;
      TreeNode* node=root;
      while(true){
        if(node){
            st.push(node);
            node=node->left;
        }else{
            if(st.empty())break;
            node=st.top();st.pop();
            ans.push_back(node->val);
            node=node->right;
        }
      }return ans;
}
int main()
{
    
    return 0;
}