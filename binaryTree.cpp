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
vector<int>postOrderTraversal2(TreeNode* root){
    stack<TreeNode*>st1,st2;
    vector<int>ans;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* node=st1.top();st1.pop();
        st2.push(node);
        if(node->left)st1.push(node->left);
        if(node->right)st1.push(node->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->val);st2.pop();
    }return ans;
}
vector<int>postOrderTraversal1(TreeNode* root){
    TreeNode* curr=root;
    stack<TreeNode*>st;
    vector<int>ans;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr=curr->left;
        }else{
            TreeNode* temp=st.top()->right;
            if(temp)curr=temp;
            else{
                temp=st.top();st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();st.pop();
                    ans.push_back(temp->val);
                }
            }
        }
    }return ans;
}
void preInPostOrderTraversal(TreeNode* root){
    vector<int>pre,in,post;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    if(root==nullptr)return;
    while(!st.empty()){
        auto it=st.top();st.pop();
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push({it.first,it.second});
            if(it.first->left)st.push({it.first->left,1});
        }else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push({it.first,it.second});
            if(it.first->right)st.push({it.first->right,1});
        }else{
            post.push_back(it.first->val);
        }
    }
}
//MAXIMUM DEPTH OF A TREE
int maxDepth(TreeNode* root){
    //BFS :
    int depth=0;queue<TreeNode*>q;
    if(root==nullptr)return depth;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        depth++;
    }return depth;

    //DFS (RECURSIVE) : 
    // if(root==nullptr)return 0;
    // int left=maxDepth(root->left);
    // int right=maxDepth(root->right);
    // return max(left,right)+1;

    //DFS (ITERATIVE) : 
    // int depth=0;stack<pair<TreeNode*,int>>st;
    // if(root==nullptr)return 0;
    // st.push({root,1});
    // while(!st.empty()){
    //     auto [node,d]=st.top();st.pop();
    //     depth=max(depth,d);
    //     if(node->left){
    //         st.push({node->left,1});
    //     }
    //     if(node->right){
    //         st.push({node->right,1});
    //     }
    // }return depth;
}
int checkHeight1(TreeNode* root){
    if(root==nullptr)return 0;
    int leftH=checkHeight1(root->left);
    if(leftH==-1)return -1;
    int rightH=checkHeight1(root->right);
    if(rightH==-1)return -1;
    if(abs(leftH-rightH)>1)return -1;
    return 1+max(leftH,rightH);
}
bool isBalancedTree(TreeNode* root){
  return checkHeight1(root)!=-1;
}
int checkHeight2(TreeNode* root,int &ans){
    if(root==nullptr)return 0;
    int leftH=checkHeight2(root->left,ans);
    int rightH=checkHeight2(root->right,ans);
    ans=max(ans,leftH+rightH);
    return 1+max(leftH,rightH);
}
int diameterOfBinaryTree(TreeNode* root){
  int ans=0;
  checkHeight2(root,ans);
  return ans;
}
bool pathSum1(TreeNode* root,int &targetSum){
    if(root==nullptr)return false;
    if(root->left==nullptr && root->right==nullptr){
        if(targetSum==root->val){
            return true;
        }
        return false;
    }
    int t=targetSum-root->val;
    bool left=pathSum1(root->left,t);
    bool right=pathSum1(root->right,t);
    return left||right;
}
void checkHeight3(TreeNode* root,int &targetSum,vector<int>&current,vector<vector<int>>&ans){
  if(root==nullptr)return;
  current.push_back(root->val);
  if(root->left==nullptr && root->right==nullptr){
    if(targetSum==root->val){
        ans.push_back(current);
    }
    current.pop_back();
    return;
  }
  int t=targetSum-root->val;
  checkHeight3(root->left,t,current,ans);
  checkHeight3(root->right,t,current,ans);
  current.pop_back();
}
vector<vector<int>>pathSum2(TreeNode* root,int &targetSum){
   vector<int>current;
   vector<vector<int>>ans;
   checkHeight3(root,targetSum,current,ans);
   return ans;
}
void checkHeight4(TreeNode* root,long long &targetSum,int &count){
    if(root==nullptr)return;
    if(targetSum==root->val) count++;
    long long t=targetSum-root->val;
    checkHeight4(root->left,t,count);
    checkHeight4(root->right,t,count);
}
int pathSum3(TreeNode* root,int targetSum){
    if(root==nullptr)return 0;
    queue<TreeNode*>q;
    q.push(root);
    int count=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();q.pop();
            int c=0;long long target=targetSum;
            checkHeight4(node,target,c);
            count+=c;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return count;
}
int solve(TreeNode* root,int &ans){
    if(root==nullptr)return 0;
    int left=solve(root->left,ans);
    int right=solve(root->right,ans);
    int leftPath=0,rightPath=0;
    if(root->left && root->left->val==root->val){
        leftPath=left;
    }
    if(root->right && root->right->val==root->val){
       rightPath=right;
    }
    ans=max(ans,leftPath+rightPath);
    return 1+max(leftPath,rightPath);
}
bool SymmetryCheck(TreeNode* left,TreeNode* right){
    if(left==nullptr && right==nullptr)return true;
    if(left==nullptr || right==nullptr)return false;
    if(left->val!=right->val)return false;
    return SymmetryCheck(left->left,right->right) && SymmetryCheck(left->right,right->left);
}
bool isSymmetric(TreeNode* root){
    if(root==nullptr) return true;
    return SymmetryCheck(root->left,root->right);
}
int main(){
    return 0;
}