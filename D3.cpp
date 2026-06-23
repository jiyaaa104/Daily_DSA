//--------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// int better(int arr[],int n){
//     sort(arr,arr+n);
//     return arr[n/2];
// }
// int best(int arr[],int n){
//     int major=arr[0];
//     int count=1;
//     for(int i=1;i<n;i++){
//         if(arr[i]==major){
//             count++;
//         }else{
//             count--;
//             if(count==0){
//                 major=arr[i];
//                 count=1;
//             }
//         }
//     }return major;
// } 
// int main()
// {
//     int arr[]={1,1,2,1,2,4,1,1,3,1};
//     cout<<best(arr,10);
//     return 0;
// }

//--------------------------2
// #include<bits/stdc++.h>
// using namespace std;
// int brute(int arr[],int n){
//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//            sum+=arr[j];
//            if(sum>maxi){
//             maxi=sum;
//            }
//         }
//     }return maxi;
// }
// int better(int arr[],int n){
//     int sum=0,maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum>maxi){
//             maxi=max(maxi,sum);
//         }
//         if(sum<0){
//             sum=0;
//         }
//     }return maxi;
// }
// void optimal(int arr[],int n){
//     int sum=0,maxi=INT_MIN;
//     int s=0,e,ansStart;
//     for(int i=0;i<n;i++){
//         if(sum==0){
//             s=i;
//         }
//         sum+=arr[i];
//         if(sum>maxi){
//             maxi=sum;
//             ansStart=s;
//             e=i;
//         }
//         if(sum<0){
//             sum=0;
//         }
//     }
//     cout<<"Maximum Sub-Array Sum : "<<maxi<<endl;
//     for(int i=ansStart;i<=e;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// void printMaxSub(int arr[],int n){
//     int s=0,e,ansStart;
//     int sum=0,maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         if(sum>maxi){
//             maxi=sum;
//             ansStart=s;
//             e=i;
//         }
//         if(sum<0){
//             sum=0;
//             s=i+1;
//         }
//     }
//     for(int i=ansStart;i<=e;i++){
//         cout<<arr[i]<<" ";
//     }
// }
// int main()
// {
//     int arr[]={1,-9,-3,-4,-8,5,6,2,-100,2};
//     printMaxSub(arr,10);
//     return 0;
// }

//----------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// int stockBuySell(int arr[],int n){
//     int buy=arr[0];
//     int bestBuy=arr[0],maxProfit=-1;
//     for(int i=1;i<n;i++){
//         int sell=arr[i];
//         int profit=sell-bestBuy;
//         if(profit>maxProfit){
//             maxProfit=profit;
//         }
//         bestBuy=min(bestBuy,sell);
//     }return maxProfit;
// }
// int main()
// {
//     int arr[]={7,1,5,3,6,4};
//     cout<<stockBuySell(arr,6);
//     return 0;
// }

//----------------------4
// #include<bits/stdc++.h>
// using namespace std;
// void brute(int arr[],int n){
//     vector<int>pos;
//     vector<int>neg;
//     for(int i=0;i<n;i++){
//         if(arr[i]>=0){
//             pos.push_back(arr[i]);
//         }else{
//             neg.push_back(arr[i]);
//         }
//     }
//     int k=0,j=0;
//     for(int i=0;i<n;i++){
//         if(i%2==0){
//             arr[i]=pos[k];
//             k++;
//         }else{
//             arr[i]=neg[j];
//             j++;
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
//     }
// void optimal(int arr[],int n){
//        vector<int>ans(n,0);
//        int pos=0,neg=1;
//        for(int i=0;i<n;i++){
//          if(arr[i]>=0){
//            ans[pos]=arr[i];
//            pos+=2;
//          }else{
//             ans[neg]=arr[i];
//             neg+=2;
//          }
//        }
//        for(int i=0;i<n;i++){
//         cout<<ans[i]<<" ";
//        }cout<<endl;
//     }
// int main()
// {
//     int arr[]={1,2,3,-9,-5,5,-2,-4};
//     optimal(arr,8);
//     return 0;
// }

//---------------------5
// #include<bits/stdc++.h>
// using namespace std;
// void revArr(int arr[],int s,int e){
//     while(s<e){
//         swap(arr[s],arr[e]);
//         s++;
//         e--;
//     }
// }
// void nextP(int arr[],int n){
//     int breakPoint=-1;
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]<arr[i+1]){
//             breakPoint=i;
//             break;
//         }
//     }
//     for(int i=n-1;i>breakPoint;i--){
//         if(arr[i]>arr[breakPoint]){
//             swap(arr[i],arr[breakPoint]);
//             break;
//         }
//     }
//     revArr(arr,breakPoint+1,n-1);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
// int main()
// {
//     int arr[]={0,1,2,3,4,5,6,7,8,9};
//     nextP(arr,10);
//     return 0;
// }

//---------------------6
// #include<bits/stdc++.h>
// using namespace std;
// void leader(int arr[],int n){
//     vector<int>ans;
//     ans.push_back(arr[n-1]);
//     int maxi=arr[n-1];
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]>maxi){
//             ans.push_back(arr[i]);
//             maxi=arr[i];
//         }
//     }
//     for(int i=ans.size()-1;i>=0;i--){
//         cout<<ans[i]<<" ";
//     }
// }
// int main(){
//     int arr[]={12,3,1,0,3,2,1};
//     leader(arr,7);
//     return 0;
// }

//-------------------7
// #include<bits/stdc++.h>
// using namespace std;
// int brute(int arr[],int n){
//     int count=1,maxi=-1;
//     sort(arr,arr+n);
//     for(int i=1;i<n;i++){
//         if(arr[i]==arr[i-1]+1){
//             count++;
//             maxi=max(maxi,count);
//         }else{
//            count=1;
//         }
//     }return maxi;
// }
// int optimal(int arr[],int n){
//     int maxi=-1;
//     unordered_set<int>s;
//     for(int i=0;i<n;i++){
//         s.insert(arr[i]);
//     }
//     for(auto it: s){
//        if(s.find(it-1)==s.end()){
//          int count=1;
//          int x=it;
//          while(s.find(x+1)!=s.end()){
//             count++;
//             x++;
//          }
//            maxi=max(maxi,count);
//        }
//     }return maxi;
// }
// int main()
// {
//     int arr[]={1,2,400,200,3,4,100};
//     cout<<optimal(arr,7);
//     return 0;
// }

//--------------------------8
#include<bits/stdc++.h>
using namespace std;
void printVec(vector<vector<int>>vec){
    int n=vec.size();
    int m=vec[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }cout<<endl;
    }
}
void makeRow(vector<vector<int>>&vec,int i){
    for(int j=0;j<vec[0].size();j++){
        vec[i][j]=0;
    }
}
void makeCol(vector<vector<int>>&vec,int j){
    for(int i=0;i<vec.size();i++){
        vec[i][j]=0;
    }
}
void brute(vector<vector<int>>&vec){
    int n=vec.size(),m=vec[0].size();
    vector<vector<int>>ans(n,vector<int>(m,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==0){
                makeRow(ans,i);
                makeCol(ans,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        vec[i][j]=ans[i][j];
    }
    }
    printVec(vec);
}
void better(vector<vector<int>>&vec){
   int n=vec.size(),m=vec[0].size();
   vector<int>row(n,0);
   vector<int>col(m,0);
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(vec[i][j]==0){
            row[i]=1;
            col[j]=1;
        }
    }
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(row[i]==1||col[j]==1){
          vec[i][j]=0;
        }
    }
   }
   printVec(vec);
}
void optimal(vector<vector<int>>vec){
    int col0=1;
    int n=vec.size();
    int m=vec[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vec[i][j]==0){
               vec[i][0]=0;
               if(j==0){
                 col0=0;
               }else{
                 vec[0][j]=0;
               }
            }
        }
    }
    //update
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(vec[i][j]!=0){
                if(vec[i][0]==0 ||vec[0][j]==0){
                    vec[i][j]=0;
                }
            }
        }
    }
    if(vec[0][0]==0){
      for(int j=1;j<m;j++){
        vec[0][j]=0;
      }
    }
    for(int i=0;i<n;i++){
        if(col0==0){
            vec[i][0]=0;
        }
    }
    printVec(vec);
}
int main()
{
    vector<vector<int>>arr={{1,1,1},{1,0,1},{1,1,1}};
    optimal(arr);
    return 0;
}