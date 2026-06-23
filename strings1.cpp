//REMOVE OUTER PARENTHESIS----------
// #include<bits/stdc++.h>
// using namespace std;
// //brute-> stack based approach
// // void removeP(string s){
// //     string ans;
// //     int n=s.size();
// //     stack<char> st;
// //     for(int i=0;i<n;i++){
// //         if(s[i]=='('){
// //             if(st.empty()){
// //                 st.push(s[i]);
// //             }else{
// //                 st.push(s[i]);
// //                 ans.push_back(s[i]);
// //             }
// //         }
// //         else{
// //             st.pop();
// //             if(st.empty()){
// //                 continue;
// //             }else{
// //                 ans.push_back(s[i]);
// //             }
// //         }
// //     }
// //     for(int i=0;i<ans.size();i++){
// //         cout<<ans[i]<<" ";
// //     }
// // }
// //optimal
// void removeP(string s){
//     int n=s.size();
//     string ans;
//     int depth=0;
//     for(int i=0;i<n;i++){
//         if(s[i]=='('){
//             if(depth==0){
//                 depth++;
//             }else{
//                 depth++;
//                 ans.push_back(s[i]);
//             }
//         }else{
//             depth--;
//             if(depth==0){
//                 continue;
//             }else{
//                 ans.push_back(s[i]);
//             }
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i];
//     }
// }
// // Largest Odd Number in a String---------------
// void largestOdd(string num){
//     int n=num.size();
//     string ans;
//     int ind=-1;
//     for(int i=n-1;i>=0;i--){
//         if(num[i]%2!=0){
//           ind=i;
//           break;
//         }
//     }
//     if(ind==-1){
//         cout<<"NO ODDS FOUND!"<<endl;
//         return;
//     }
//     for(int i=0;i<=ind;i++){
//         ans.push_back(num[i]);
//     }
//    for(int i=0;i<ans.size();i++){
//     cout<<ans[i];
//    }
// }
// int main()
// {
//     string s="413456";
//    largestOdd(s);
//     return 0;
// }

//REVERSE WORDS IN A STRING---------------------
// #include<bits/stdc++.h>
// using namespace std;
// string pushString(string s, int l,int r){
//     string ans;
//     for(int i=l;i<=r;i++){
//       ans.push_back(s[i]);
//     }return ans;
// }
// void reverseWords(string s){
//     string ans;
//     int n=s.size();
//     int l=n-1,r=n-1;
//     while(l>=0){
//         while(l>=0 && !isalnum(s[l])){
//             l--;
//         }
//         if(l<0){
//             break;
//         }
//         r=l;
//         while(l>=0 && isalnum(s[l])){
//             l--;
//         }
//         ans+=pushString(s,l+1,r);
//         if(l>0){
//             ans+=" ";
//         }
//     }
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i];
//     }
// }
// int main()
// {
//     // string s="AKA is GOOD";
//     vector<string>s={"","juhi"};
//     int r=0;
//     cout<<s[0].size();
//     // reverseWords(s);
//     return 0;
// }

//LONGEST COMMON PREFIX
// #include<bits/stdc++.h>
// using namespace std;
// bool possible(vector<string>&strs,int r,char c){
//     int n=strs.size();
//     for(int i=0;i<n;i++){
//         if(strs[i][r]!=c){
//             return false;
//         }
//     }return true;
// }
// void commonPrefix(vector<string>&strs){
//     int n=strs.size();
//     string ans;
//     int len=INT_MAX;
//     for(int i=0;i<n;i++){
//         int p=strs[i].size();
//         len=min(len,p);
//     }
//     if(len==0){
//         cout<<"NO COMMON PREFIX!"<<endl;
//         return;
//     }
//     int l=0,r=0;
//     while(r<len){
//         char c=strs[0][r];
//         bool check=possible(strs,r,c);
//         if(check){
//             r++;
//         }else break;
//     }
//     if(r==0){
//         cout<<"NO COMMON PREFIX!";
//         return;
//     }
//     for(int i=0;i<r;i++){
//         cout<<strs[0][i];
//     }return;
// }
// int main()
// {
//     vector<string>strs={"aka","akanksha","akash","akahat"};
//     commonPrefix(strs);
//     return 0;
// }

//ISOMORPHIC STRINGS-----------------------
// #include<bits/stdc++.h>
// using namespace std;
// bool isomorph(string s,string t){
//     unordered_map<char,char>st;
//     unordered_map<char,char>ts;
//     for(int i=0;i<s.size();i++){
//         char a=s[i],b=t[i];
//         if(st.count(a)){
//            if(st[a]!=b){
//             return false;
//            }
//         }else{
//             st[a]=b;
//         }
//         if(ts.count(b)){
//             if(ts[b]!=a){
//                 return false;
//             }
//         }else{
//             ts[b]=a;
//         }
//     }return true;
// }
// int main()
// {
//     cout<<isomorph("aks","pat");
//     return 0;
// }

//ROTATE STRING-------------------------
// #include<bits/stdc++.h>
// using namespace std;
//  string revStr(string &s,int st,int e){
//         while(st<e){
//             swap(s[st],s[e]);
//             st++;e--;
//         }return s;
//     }

// void printStr(string s){
//     for(int i=0;i<s.size();i++){
//         cout<<s[i];
//     }return;
// }
//     bool rotateString(string s, string goal) {
//         int n=s.size();
//         if(s==goal){
//             return true;
//         }
//         for(int i=0;i<=n-2;i++){
//             revStr(s,0,i);
//             revStr(s,i+1,n-1);
//             revStr(s,0,n-1);
//             if(s==goal){
//                 return true;
//             }
//         }return false;
//     }
// int main()
// {
//     string s="abcdef";
//     cout<<rotateString(s,"cdefab");
//     return 0;
// }

//VALID ANAGRAM--------------------------
// #include<bits/stdc++.h>
// using namespace std;
// bool anagram(string s,string t){
//     if(s.size()!=t.size()){
//         return false;
//     }
//     unordered_map<char,int>mpp;
//     int n=s.size();
//     for(int i=0;i<n;i++){
//         mpp[s[i]]++;
//     }
//     for(int i=0;i<n;i++){
//         mpp[t[i]]--;
//     }
//     for(int i=0;i<n;i++){
//         if(mpp[s[i]]!=0){
//             return false;
//         }
//         if(mpp[t[i]]!=0){
//             return false;
//         }
//     }return true;
// }
// int main()
// {
//     cout<<anagram("anagram","naagram");
//     return 0;
// }

//SORT CHARACTERS BY FREQUENCY----------------
// #include<bits/stdc++.h>
// using namespace std;
// void sortStr(string s){
//     unordered_map<char,int>mpp;
//     int n=s.size();
//     for(int i=0;i<n;i++){
//         mpp[s[i]]++;
//     }
//     priority_queue<pair<int,char>>pq;
//     for(auto it: mpp){
//         pq.push({it.second,it.first});
//     }
//     string ans;
//     while(!pq.empty()){
//         char c=pq.top().second;
//         int freq=pq.top().first;
//         while(freq--){
//             ans.push_back(c);
//         }
//         pq.pop();
//     }
//     for(int i=0;i<n;i++){
//         cout<<ans[i];
//     }return;
// }
// int main()
// {
//     sortStr("tree");
//     return 0;
// }

//MAXIMUM NESTING DEPTH OF STRING
// #include<bits/stdc++.h>
// using namespace std;
// void maxDepth(string s){
//     int n=s.size(),depth=0,maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         if(s[i]=='('){
//             depth++;
//             maxi=max(depth,maxi);
//         }else if(s[i]==')'){
//             depth--;
//         }
//     }
//     cout<<"MAX DEPTH : "<<maxi<<endl;
//     return;
// }
// int main()
// {
//     maxDepth("(1+(2*3)+((8)/4))+1");
//     return 0;
// }

//LEETCODE 13-> ROMAN TO INTEGER (CHECK THE ANSWER ON LEETCODE DIRECTLY EASY IF-ELSE PROBLEM!)

//STRING TO INTEGER (LEETCODE(8))
//CHECKOUT THE LEETCODE SOLUTION!
// #include<bits/stdc++.h>
// using namespace std;
// void stringToNum(string s){
//     int n=s.size(),l=0,st=-1,e=-1;
//     long long num=0;
//     bool negative=false,start=false;
//     while(l<n && s[l]==' '){
//         l++;
//     }
//     if(l>=n){
//         cout<<"0"<<endl;
//         return;
//     }
//     if(s[l]=='-'){
//       negative=true;
//       l++;
//     }else if(s[l]=='+'){
//         l++;
//     }
//     if(l>=n){
//         cout<<"0"<<endl;
//         return;
//     }
//     while(l<n && isdigit(s[l])){
//      if(!start){
//         st=l;
//         start=true;
//      }
//      l++;
//     }
//     e=l-1;
//     if(st==-1){
//         cout<<"0"<<endl;
//         return;
//     }
//     long long place=1;
//     for(int i=e;i>=st;i--){
//         int k=s[i]-'0';
//         num=num+place*k;
//         place*=10;
//     }
//     if(negative){
//         num*=-1;
//     }
//     if(num<INT_MIN ||num>INT_MAX){
//         cout<<"0";
//         return;
//     }
//     cout<<num<<endl;
// }
// int main()
// {
//     stringToNum("12-3abs");
//     return 0;
// }

//NUMBER OF SUBSTRINGS WITH K DISTINCT CHARACTERS
// #include<bits/stdc++.h>
// using namespace std;
// int atmostK(string s,int k){
//     int n=s.size(),left=0,res=0;
//     unordered_map<char,int>freq;
//     for(int right=0;right<n;right++){
//        freq[s[right]]++;
//        while(freq.size()>k){
//         freq[s[left]]--;
//         if(freq[s[left]]==0) freq.erase(s[left]);
//         left++;
//        }
//        res+=right-left+1;
//     }return res;
// }
// int main()
// {
//     int x=atmostK("pqpqs",2)-atmostK("pqpqs",1);
//     cout<<x<<endl;
//     return 0;
// }

//LONGEST PALINDROME-------------------------------
// #include<bits/stdc++.h>
// using namespace std;
//-------------------------------------------------------------BRUTE-------------------------------------------------------------
// bool possible(string s,int st,int e){
//     while(st<=e){
//         if(s[st]==s[e]){
//             st++;e--;
//         }else{
//             return false;
//         }
//     }return true;
// }
// void longestP(string s){
//     int n=s.size();
//     int len=INT_MIN;
//     int ansS=-1,ansE=-1;
//     for(int st=0;st<n;st++){
//         for(int e=n-1;e>=st;e--){
//             if(s[st]==s[e]){
//              bool check=possible(s,st,e);
//             if(check){
//             int l=e-st+1;
//             if(l>len){
//                 len=l;
//                 ansS=st;
//                 ansE=e;
//             }
//             }else{
//                 continue;
//             }
//             }
//         }
       
//     }
//     for(int i=ansS;i<=ansE;i++){
//         cout<<s[i];
//     }return;
// }
//--------------------------------------------------------------------------------------------------------------
// pair<int,int> substr(string s,int l,int r){
//     int n=s.size(),len=0,bestLen=0;
//     while(l>=0 && r<n && s[l]==s[r]){
//         len=r-l+1;
//         l--;r++;
//     }return {r-l-1,l+1};
// }
// void longestP(string s){
//     int n=s.size();string ans;
//     int bestStart=0,bestL=0;
//     for(int i=0;i<n;i++){
//      //odd
//       pair<int,int>p1=substr(s,i,i);
//       int l1=p1.first;
//       int st1=p1.second;
//       if(l1>bestL){
//         bestL=l1;
//         bestStart=st1;
//       }
//      //even
//      if(i<n-1){
//         pair<int,int>p2=substr(s,i,i+1);
//         int l2=p2.first;
//         int st2=p2.second;
//         if(l2>bestL){
//         bestL=l2;
//         bestStart=st2;
//       }
//      }
//     }
//     ans=s.substr(bestStart,bestL);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i];
//     }
// }
// int main()
// {
//     longestP("asaspsasas");
//     return 0;
// }

//SUM OF BEAUTY OF ALL SUBSTRINGS
#include<bits/stdc++.h>
using namespace std;
pair<int,int>maxminF(int freq[],int n){
    int maxi=-1,mini=n;
    for(int i=0;i<n;i++){
        if(freq[i]>0){
            maxi=max(maxi,freq[i]);
            mini=min(mini,freq[i]);
        }
    }return{maxi,mini};
}
void sumBeauty(string s){
    int n=s.size(),sum=0;
    for(int left=0;left<n;left++){
        int freq[26]={0};
        int mostN=0,minN=n;
        for(int right=left;right<n;right++){
           freq[s[right]-'a']++;
           pair<int,int>p=maxminF(freq,26);
           mostN=p.first;
           minN=p.second;
           sum+=mostN-minN;
        }
    }cout<<sum<<endl;
    return;
}
int main()
{
    sumBeauty("aabcb");
    return 0;
}
