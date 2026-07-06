#include<bits/stdc++.h>
using namespace std;
bool isItSafe(int row,int col,int n,vector<string>&board){
   int r=row;
   int c=col;
   while(row>=0 && col>=0){
      if(board[row][col]=='Q') return false;
      row--;col--;
   }
   row=r;
   col=c;
   while(col>=0){
      if(board[row][col]=='Q') return false;
      col--;
   }
   col=c;
   while(row<n && col>=0){
      if(board[row][col]=='Q') return false;
      row++;col--;
   }
   return true;
}
void nQueens(int col,vector<vector<string>>&ans,vector<string>&board,int n){
   if(col==n){
      ans.push_back(board);
      return;
   }
   for(int i=0;i<n;i++){
      if(isItSafe(i,col,n,board)){
         board[i][col]='Q';
         nQueens(col+1,ans,board,n);
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