//1. FINDING ALL SUBSEQUENCES
// #include<bits/stdc++.h>
// using namespace std;
// void printSubsequences(int index,vector<int>arr,vector<int>current){
//     //BASE CASE
//     if(index==arr.size()){
//         cout<<"CASE : ";
//         for(auto x: current){
//             cout<<x<<" ";
//         }cout<<endl;
//         return;
//     }

//     //PUSH THE CURRENT
//     current.push_back(arr[index]);
//     printSubsequences(index+1,arr,current);
//     //POP THE CURRENT
//     current.pop_back();
//     printSubsequences(index+1,arr,current);
// }
// int main(){
//     vector<int>arr={1,2,3};
//     vector<int>current;
//     printSubsequences(0,arr,current);
//     return 0;
// }

//2. PRINT ALL SUBSEQUENCE WHOSE SUM EQUALS TO K
//MY WAY - I END UP CALCULATING SUM FOR ALL THE SEQUENCES 1 EXTRA O(N) each time
// #include<bits/stdc++.h>
// using namespace std;
// void printSubseqSumK(int index,int k,vector<int>arr,vector<int>current){
//     //base case
//     if(arr.size()==index){
//         int sum=0;
//        for(auto x: current){
//           sum+=x;
//        }
//        if(sum==k){
//         cout<<"CASE : ";
//          for(auto x: current){
//             cout<<x<<" ";
//          }cout<<endl;
//        }
//        return;
//     }
//     //push current element
//     current.push_back(arr[index]);
//     printSubseqSumK(index+1,k,arr,current);
//     //pop current element
//     current.pop_back();
//     printSubseqSumK(index+1,k,arr,current);
// }
// int main()
// {
//     vector<int>arr={1,2,3};
//     vector<int>current;
//     printSubseqSumK(0,3,arr,current);
//     return 0;
// }
// OPTIMAL WAY
// #include<bits/stdc++.h>
// using namespace std;
// void printSubseqSumK(int index,int k,int sum,vector<int>arr,vector<int>current){
//     //base case
//     if(index==arr.size()){
//         if(sum==k){
//             cout<<"CASE : ";
//         for(auto x: current){
//             cout<<x<<" ";
//         }cout<<endl;
//         }
//         return;
//     }
//     //push current
//     current.push_back(arr[index]);
//     sum+=arr[index];
//     printSubseqSumK(index+1,k,sum,arr,current);

//     sum-=arr[index];
//     current.pop_back();
//     printSubseqSumK(index+1,k,sum,arr,current);
// }
// int main()
// {
//         vector<int>arr={1,2,3};
//     vector<int>current;
//     printSubseqSumK(0,3,0,arr,current);
//     return 0;
// }



//3. PRINT ONLY 1 SUBSEQUENCE WITH THE SUM K
// #include<bits/stdc++.h>
// using namespace std;
//MY WAY--- THIS WONT WORK BECAUSE USING JUST RETURN INSIDE MY CONDITION WILL JUST MAKE MY RETURN FASTER. IT WONT STOP THE RECURSION. NOW I WANT MY RECURSION TO STOP AFTER SOMETHING HAPPENS ELSE CONTINUE TILL THAT SOMETHING HAPPENS TILL I HAVE EXPLORED ALL SUBSEQUENCES.
// void printSubseqSumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
//     //base case
//     if(arr.size()==index){
//         if(sum==k){
//             for(int x: current){
//                 cout<<x<<" ";
//             }cout<<endl;
//             return;
//         }
//         return;
//     }

//     current.push_back(arr[index]);
//     sum+=arr[index];
//     printSubseqSumK(index+1,k,sum,arr,current);

//     sum-=arr[index];
//     current.pop_back();
//     printSubseqSumK(index+1,k,sum,arr,current);
// }
// int main(){
//         vector<int>arr={1,2,3};
//     vector<int>current;
//     printSubseqSumK(0,3,0,arr,current);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// bool printSubseqWithSumK(int index,int k,int sum,vector<int>&arr,vector<int>&current){
//     //base case
//     if(index==arr.size()){
//         if(sum==k){
//             for(int x: current){
//                 cout<<x<<" ";
//             }cout<<endl;
//             return true;
//         }
//         return false;
//     }

//     //pick
//     current.push_back(arr[index]);
//     sum+=arr[index];
//     if(printSubseqWithSumK(index+1,k,sum,arr,current)) return true;

//     //skip
//     sum-=arr[index];
//     current.pop_back();
//     if(printSubseqWithSumK(index+1,k,sum,arr,current)) return true;

//     return false;
// }
// int main(){
//             vector<int>arr={1,2,3};
//     vector<int>current;
//     printSubseqWithSumK(0,3,0,arr,current);
//     return 0;
// }

//4. Count Number Of Subsequences with sum = k
// #include<bits/stdc++.h>
// using namespace std;
//I'm taking the count variable when I dont even need it in reality
// int countNumberOfSub(int index,int k,int sum,int count,vector<int>&arr,vector<int>&current){
//     if(arr.size()==index){
//         if(sum==k){
//             count++;
//         }
//         return count;
//     }

//     current.push_back(arr[index]);
//     sum+=arr[index];
//     int c= countNumberOfSub(index+1,k,sum,count,arr,current);

//     sum-=arr[index];
//     current.pop_back();
//     int b= countNumberOfSub(index+1,k,sum,count,arr,current);
//     return c+b;
// }


// int countNumberOfSub(int index,int k,int sum,vector<int>&arr,vector<int>&current){
//     //base case
//     if(arr.size()==index){
//         if(sum==k) return 1;
//         return 0;
//     }

//     //left case : pick
//     current.push_back(arr[index]);
//     sum+=arr[index];
//     int left=countNumberOfSub(index+1,k,sum,arr,current);

//     //right case : skip
//     sum-=arr[index];
//     current.pop_back();
//     int right=countNumberOfSub(index+1,k,sum,arr,current);
//     return left+right;
// }
// int main(){
//     vector<int>arr={1,2,3};
//     vector<int>current;
//     cout<<countNumberOfSub(0,3,0,arr,current);
//     return 0;
// }

//5. Count subsequences with even sum
// #include<bits/stdc++.h>
// using namespace std;
// int countEvenSubseq(int index,int sum,vector<int>&arr,vector<int>&current){
//     //base case
//     if(arr.size()==index){
//         if(sum%2==0){return 1;}
//         return 0;
//     }

//     //left case: pick
//     current.push_back(arr[index]);
//     sum+=arr[index];
//     int left=countEvenSubseq(index+1,sum,arr,current);

//     //right case: skip
//     sum-=arr[index];
//     current.pop_back();
//     int right=countEvenSubseq(index+1,sum,arr,current);
    
//     return left+right;
// }
// int main()
// {
//     vector<int>arr={1,2,3};
//     vector<int>current;
//     cout<<countEvenSubseq(0,0,arr,current);   
//     return 0;
// }


//6.Power Set
// #include<bits/stdc++.h>
// using namespace std;
// void powerSet(int index,string& str,string& current){
//     //base case
//     if(index==str.size()){
//        if(current.size()){
//         for(char ch: current){
//          cout<<ch;
//        }cout<<endl;
//        }
//        return;
//     }

//     //pick:
//     current.push_back(str[index]);
//     powerSet(index+1,str,current);

//     //skip
//     current.pop_back();
//     powerSet(index+1,str,current);
// }
// int main(){
//     string s="abc";
//     string current;
//     powerSet(0,s,current);
//     return 0;
// }

//7.Generating Binary Strings of a particular length
// #include<bits/stdc++.h>
// using namespace std;
// void generateBinaryStrings(int index,int n,string& current){
//     //base case
//     if(index==n){
//         cout<<current<<endl;
//         return;
//     }
//     current.push_back('0');
//     generateBinaryStrings(index+1,n,current);
//     current.pop_back();

//     current.push_back('1');
//     generateBinaryStrings(index+1,n,current);
//     current.pop_back();
// }
// int main(){
//     string current;
//     generateBinaryStrings(0,3,current);
//     return 0;
// }

//8. Generate Binary Strings of a particular length without any consecutive ones
// #include<bits/stdc++.h>
// using namespace std;

//MY WAY: I end up checking 2 to the power n cases. Then reject if any problem arises.
//But using backtracking I can create the exact cases without encountering a problem.
// void generateStrings(int index,int n,string& current){
//     //base case
//     if(n==index){
//         bool check=false;
//         for(int i=0;i<current.size()-1;i++){
//             if(current[i]=='1' && current[i+1]=='1'){
//                check=true;
//                break;
//             }
//         }
//         if(check){return;}
//         cout<<current<<endl;
//         return;
//     }

//     //pick 0
//     current.push_back('0');
//     generateStrings(index+1,n,current);
//     current.pop_back();

//     //pick 1
//     current.push_back('1');
//     generateStrings(index+1,n,current);
//     current.pop_back();
// }
// int main()
// { 
//     string current="";
//     generateStrings(0,3,current);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// void generateStrings(int index,int n,string &current){
//     if(index==n){
//         cout<<current<<endl;
//         return;
//     }

//     // NO RESTRICTION ON PRINTING 0
//     current.push_back('0');
//     generateStrings(index+1,n,current);
//     current.pop_back();

//     //There is a restriction ON 1. PRINT 1 ONLY IF EITHER THE STRING IS EMPTY OR THE LAST CHARACTER OF STRING IS NOT 1
//     if(current.empty() || current.back()!='1'){
//         current.push_back('1');
//         generateStrings(index+1,n,current);
//         current.pop_back();
//     }
// }
// int main(){
//         string current="";
//     generateStrings(0,3,current);
//     return 0;
// }

// 9. Generating all combinations of Well formed parenthesis of a particular length
#include<bits/stdc++.h>
using namespace std;
//My approach -I was creating for n=3, 2^6 strings. But didnt understand how to remove the invalid cases from my answer. The approach itself was wrong Instead of first creating all possiblities and the removing the unrequired ones. I should have not created the unrequired ones in the first place. Just like binary strings with no consecutive ones.

//But what exactly are the non required cases -> I want to insert open bracket if : the current number of open <n .Because the moment the number of open brackets become equal to n.Do I need to insert more? No.

//What about close brackets. At any point if the count of close brackets increases open That case is surely the unrequired case.

//What about the base case? the moment the number of open becomes equal to n and close also to n. Thats the required string
// bool printParenthesis(int index,int n,string& current){
//     //base case
//     if(index==n){
//         cout<<current<<endl;
//         return ;
//     }

//     current.push_back('(');
//     printParenthesis(index+1,n,current);

//     current.push_back(')');
//     printParenthesis(index+1,n,current);

//     current.pop_back();
//     current.pop_back();
// }

// #include<bits/stdc++.h>
// using namespace std;
// void printParenthesis(int open,int close,int n,string& current){
//     //base case
//     if(open==n && close==n){
//         cout<<current<<endl;
//         return;
//     }

//     if(open<n){
//         current.push_back('(');
//         printParenthesis(open+1,close,n,current);
//         current.pop_back();
//     }
//     if(close<open){
//         current.push_back(')');
//         printParenthesis(open,close+1,n,current);
//         current.pop_back();
//     }
// }
// int main(){
//     string current="";
//     printParenthesis(0,0,3,current);
//     return 0;
// }


//10. L-784. LETTER CASE PERMUTATION
// #include<bits/stdc++.h>
// using namespace std;
// void generate(int index,string&s,string& current,vector<string>&ans){
//     if(index==s.size()){
//         ans.push_back(current);
//         cout<<current<<endl;
//         return;
//     }
//     if(isdigit(s[index])){
//         current.push_back(s[index]);
//         generate(index+1,s,current,ans);
//         current.pop_back();
//     }
//     else{
//         current.push_back(tolower(s[index]));
//     generate(index+1,s,current,ans);
//     current.pop_back();

//     current.push_back(toupper(s[index]));
//     generate(index+1,s,current,ans);
//     current.pop_back();
//     }
// }
// int main(){
//     string current="";
//     string s="a1b2";
//     vector<string>ans;
//     generate(0,s,current,ans);
//     return 0;
// }

//11. L-17 PHONE NUMBERS
// #include<bits/stdc++.h>
// using namespace std;
// void phone(int index,string& digits,vector<string>&mapping,string& current){
//     //base case;
//     if(index==digits.size()){
//         cout<<current<<endl;
//         return;
//     }
//     int d=digits[index]-'0';
//     string k=mapping[d];
//     for(int i=0;i<k.size();i++){
//         current.push_back(k[i]);
//         phone(index+1,digits,mapping,current);
//         current.pop_back();
//     }
// }
// int main(){
//     vector<string>mapping={
//         "",             //0
//         "",             //1
//         "abc",          //2
//         "def",          //3
//         "ghi",          //4
//         "jkl",          //5
//         "mno"           //6
//         "pqrs",         //7
//         "tuv"           //8
//         "wxyz"          //9
//     };
//     string current;
//     string digits="23";
//     phone(0,digits,mapping,current);
//     return 0;
// }

//12. COMBINATION SUM 1 & 2
// #include<bits/stdc++.h>
// using namespace std;
// void combinationSum(int index,vector<int>&candidates,int target,vector<int>&current,int sum){
//     //base case
//         if(index==candidates.size()){
//             if(target==0){
//             for(int x: current){
//                 cout<<x<<" ";
//             }cout<<endl;
//         }
//         return;
//         }

//     //case 1 Either keep picking the index that you are at currently
//     if(candidates[index]<=target){
//         current.push_back(candidates[index]);
//         sum+=candidates[index];
//         target-=candidates[index];
//         combinationSum(index,candidates,target,current,sum);
//         sum-=candidates[index];
//         target+=candidates[index];
//         current.pop_back();
//     }
//     combinationSum(index+1,candidates,target,current,sum);
// }
// void combinationSum2(int index,vector<int>&candidates,int target,vector<int>&current,int sum,vector<vector<int>>&ans){
//     //base case

//         if(target==0){
//             ans.push_back(current);
//             for(int x: current){
//                 cout<<x<<" ";
//             }cout<<endl;
//                return;
//         }
     

//     //pick the number
//     for(int i=index;i<candidates.size();i++){
//         if(i>index && candidates[i]==candidates[i-1]) continue;
//         if(candidates[i]>target){
//             break;
//         }
//         if(candidates[i]<=target){
//             current.push_back(candidates[i]);
//             sum+=candidates[i];
//             target-=candidates[i];
//             combinationSum2(i+1,candidates,target,current,sum,ans);
//             sum-=candidates[i];
//             target+=candidates[i];
//             current.pop_back();
//         }
//     }
// }
// int main(){
//     vector<int>candidates={1,2,2,2,5};
//     int target=5;
//     vector<int>current;
//     vector<vector<int>>ans;
//     combinationSum2(0,candidates,target,current,0,ans);
//     return 0;
// }

//Leetcode Subsets 1 & 2
// #include<bits/stdc++.h>
// using namespace std;
// void subsets(int index,vector<int>&nums,vector<int>&current){
//     if(index==nums.size()){
//         for(int x: current){
//             cout<<x<<" ";
//         }cout<<endl;
//         return;
//     }

//     //pick
//     current.push_back(nums[index]);
//     subsets(index+1,nums,current);

//     //skip
//     current.pop_back();
//     subsets(index+1,nums,current);
// }

// void noduplicateSubsets(int index,vector<int>&nums,vector<int>&current){
//         for(int x: current){
//             cout<<x<<" ";
//         }cout<<endl;
//     for(int i=index;i<nums.size();i++){
//         if(i>index && (nums[i]==nums[i-1])) continue;
//         current.push_back(nums[i]);
//         noduplicateSubsets(i+1,nums,current);
//         current.pop_back();
//     }

// }
// int main(){
//     vector<int>nums={1,1,2};
//     vector<int>current;
//     noduplicateSubsets(0,nums,current);
//     return 0;
// }

//Leetcode Combination Sum 3
// #include<bits/stdc++.h>
// using namespace std;
// void combination(int index,int k,int target,vector<int>&current,int sum){
//     if(current.size()==k){
//         if(target==0){
//             for(int x: current){
//                 cout<<x<<" ";
//             }cout<<endl;
//         }
//         return;
//     }

//     for(int i=index;i<=9;i++){
//         if(i>target) break;
//         current.push_back(i);
//         sum+=i;
//         target-=i;
//         combination(i+1,k,target,current,sum);
//         target+=i;
//         sum-=i;
//         current.pop_back();
//     }
// }
// int main(){
//     vector<int>current;
//     combination(1,3,7,current,0);
//     return 0;
// }

//Leetcode - 46 (PERMUTATIONS)
#include<bits/stdc++.h>
using namespace std;
void permutations(vector<int>&arr,vector<int>&current,vector<int>&used){
   if(current.size()==arr.size()){
      for(int x: current){
         cout<<x<<" ";
      }cout<<endl;
      return;
   }
   for(int i=0;i<arr.size();i++){
      if(used[i]) continue;
      current.push_back(arr[i]);
      used[i]=true;
      permutations(arr,current,used);
      used[i]=false;
      current.pop_back();
   }
}
int main(){
    vector<int>arr={1,2,3};
    vector<int>current;
    vector<int>used={0,0,0};
    permutations(arr,current,used);
    return 0;
}