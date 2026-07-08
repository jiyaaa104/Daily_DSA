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
// #include<bits/stdc++.h>
// using namespace std;
// bool isItSafe(int row,int col,vector<string>&board,int n){
//     int r=row;
//     int c=col;
//     //uper tirchha
//     while(row>=0 && col>=0){
//         if(board[row][col]=='Q') return false;
//         row--;
//         col--;
//     }

//     row=r;
//     col=c;
//     //peeche
//     while(col>=0){
//         if(board[row][col]=='Q') return false;
//         col--;
//     }

//     col=c;
//     //neeche tirchha
//     while(row<n && col>=0){
//         if(board[row][col]=='Q') return false;
//         col--;
//         row++;
//     }
//     return true;
// }
// void nqueen(int col,vector<string>&board,vector<vector<string>>&ans,int n){
//     if(col==n){
//         ans.push_back(board);
//         return;
//     }
//     for(int i=0;i<n;i++){
//         if(isItSafe(i,col,board,n)){
//             board[i][col]='Q';
//             nqueen(col+1,board,ans,n);
//             board[i][col]='.';
//         }
//     }
// }

// int main(){
//     vector<vector<string>>ans;
//     int n=4;
//     vector<string>board(n);
//     string s(n,'.');
//     for(int i=0;i<n;i++){
//         board[i]=s;
//     }
//     return 0;
// }

//Rat In A Maze
// #include<bits/stdc++.h>
// using namespace std;
// bool isSafe(int row,int col,vector<vector<int>>&maze,int n){
//     if(row<0 || col<0 || row>=n || col>=n || maze[row][col]==0 || maze[row][col]==-1){
//     return false;
//    }return true;
// }
// void ratInAMaze(int row,int col,vector<vector<int>>&maze,vector<string>&ans,string& s,int n){
//    if(row==n-1 && col==n-1){
//      ans.push_back(s);
//      return;
//    }
// int temp=maze[row][col];
// maze[row][col]=-1;
//    //Down
//    if(isSafe(row+1,col,maze,n)){
//       s.push_back('D');
//        ratInAMaze(row+1,col,maze,ans,s,n);
//       s.pop_back();
//    }
   
//     //Left
//    if(isSafe(row,col-1,maze,n)){
//     s.push_back('L');
//    ratInAMaze(row,col-1,maze,ans,s,n);
//    s.pop_back();
//    }
//     //right
//    if(isSafe(row,col+1,maze,n)){
//     s.push_back('R');
//    ratInAMaze(row,col+1,maze,ans,s,n);
//    s.pop_back();
//    }
//    //UP
//    if(isSafe(row-1,col,maze,n)){
//     s.push_back('U');
//    ratInAMaze(row-1,col,maze,ans,s,n);
//    s.pop_back(); 
//    }
//    maze[row][col]=temp;
// }
// int main(){
//     vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
//     string s="";
//     vector<string>ans;
//     if(maze[0][0]!=0 && maze[3][3]!=0){
//         ratInAMaze(0,0,maze,ans,s,4);
//     } 
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j];
//         }cout<<endl;
//     }
//     return 0;
// }

//LEETCODE - 37
// #include<bits/stdc++.h>
// using namespace std;
// bool isItSafe(int row,int col,char c,vector<vector<char>>&sudoku){
//     for(int i=0;i<9;i++){
//         if(sudoku[row][i]==c)return false;
//         if(sudoku[i][col]==c)return false;
//         if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
//     }
//     return true;
// }
// bool sudoku(vector<vector<char>>&board){
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             if(board[i][j]=='.'){
//               for(char c='1';c<='9';c++){
//                 if(isItSafe(i,j,c,board)){
//                     board[i][j]=c;
//                     if(sudoku(board)) return true;
//                     else{
//                         board[i][j]='.';
//                     }
//                 }
//               }return false;
//             }
//         }
//     }
//     return true;
// }
// void solve(vector<vector<char>>&board){
//     sudoku(board);
// }
// int main(){
//     return 0;
// }

//L-36 VALID SUDOKU
#include<bits/stdc++.h>
using namespace std;
bool validSudoku(vector<vector<char>>&board){
    bool rows[9][9]={};
    bool cols[9][9]={};
    bool box[9][9]={};
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')continue;
            int num=board[i][j]-'1';
            int bval=3*(i/3)+(j/3);
            if(rows[i][num] || cols[j][num] || box[bval][num]) return false;
            rows[i][num]=true;
            cols[j][num]=true;
            box[bval][num]=true;
        }
    }return true;
}
int main(){

    return 0;
}