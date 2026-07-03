// #include<bits/stdc++.h>
// using namespace std;
// bool isPalindrome(string s){
//     string rev=s;
//     int start=0,end=s.size()-1;
//     while(start<end){
//         swap(rev[start],rev[end]);
//         start++;end--;
//     }
//     return (rev==s);
// }
// //This method is called front partitioning.. In this method at each index we go till the end and find the cost then return the least cost.This code returns the number of partitions, if you want to return the minimum number of cuts do partitions-1.
// int palindromePartition2(int index,string &s){
//     if(index==s.size()){
//         return 0;
//     }
//     int minCost=INT_MAX;
//     for(int j=index;j<s.size();j++){
//         string  temp=s.substr(index,j-index+1);
//         if(isPalindrome(temp)){
//             int cost=1+palindromePartition2(j+1,s);
//           minCost=min(cost,minCost);
//         }
//     }
//     return minCost;
// }
// int main(){
//     string s="bababcbadcede";
//     string temp;
//     cout<<palindromePartition2(0,s);
//     return 0;
// }

//WORD SEARCH
//LEETCODE -79
// #include<bits/stdc++.h>
// using namespace std;
// bool wordSearch(int index,int x,int y,string& word,vector<vector<char>>&matrix){
//     if(index==word.size()){
//         return true;
//     }
//     if(x<0 || y<0 || x>=matrix.size() || y>=matrix[0].size() || matrix[x][y]!=word[index]){
//         return false;
//     }
//     char temp=matrix[x][y];
//     matrix[x][y]='1';//visited
//     if(wordSearch(index+1,x+1,y,word,matrix)||wordSearch(index+1,x,y+1,word,matrix)||wordSearch(index+1,x-1,y,word,matrix)||wordSearch(index+1,x,y-1,word,matrix)){matrix[x][y]=temp;return true;} 
//     matrix[x][y]=temp;
//     return false;
// }
// int main(){
//  vector<vector<char>>matrix={{'A','B','C'},{'D','E','F'},{'G','H','I'}};
//  string word="ABCFIH";
//  cout<<wordSearch(0,0,0,word,matrix);
// }

//LEETCODE 51 : N QUEENS 
#include<bits/stdc++.h>
using namespace std;
bool isItSafe(int row,int col,vector<string>&board,int n){
    int r=row;
    int c=col;
    //uper tirchha
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=r;
    col=c;
    //peeche
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }

    col=c;
    //neeche tirchha
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row++;
    }
    return true;
}
void nqueen(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int i=0;i<n;i++){
        if(isItSafe(i,col,board,n)){
            board[i][col]='Q';
            nqueen(col+1,board,ans,n);
            board[i][col]='.';
        }
    }
}
int main(){
    vector<vector<string>>ans;
    int n=4;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    return 0;
}
