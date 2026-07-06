//L-1288 COVERED INTERVALS
#include<bits/stdc++.h>
using namespace std;
int coveredIntervals(vector<vector<int>>intervals){
    int n=intervals.size();
    sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
       if(a[0]==b[0]) return a[1]>b[1];
       return a[0]<b[0];
    });
    int answer=0;
    int maxEnd=intervals[0][1];
    for(int i=1;i<n;i++){
        int right=intervals[i][1];
        if(right<=maxEnd){
            continue;
        }else{
            answer++;
            maxEnd=right;
        }
    }return answer;
}
//MERGE INTERVALS L-56
vector<vector<int>> mergeIntervals(vector<vector<int>>intervals){
    int n=intervals.size();
    vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++){
        int left=intervals[i][0],right=intervals[i][1];
        if(!ans.empty() && ans.back()[1]>=right){
            continue;
        }
        for(int j=i+1;j<n;j++){
            int l=intervals[j][0],r=intervals[j][1];
            if(l<=right){
                left=min(left,l);
                right=max(right,r);
            }else{
                break;
            }
        }
        ans.push_back({left,right});
    }return ans;
}
//INSERT INERVALS L-57
// Lets say , we have an intervals array and new interval
// There will 3 types of people in intervals 1. that lie before the newIntervals and does not overlap the. 2. Those who overlap newIntervals 3. Those who lie after newInter. and does not overlap them 
//In the below example -> 1. [1,2] 2. [3,5],[6,7],[8,10]  3.[12,16]
// Condition for 
//1. intervals[i][1]<newInterval[0]
//2. intervals[i][1]>=newInterval[0]? 
//3. fill up everyone else
// We expect to get the right answer with this but we dont get the right answer we get [1,2][3,16] even though [12,16] was not an overlapping interval it still got overlapped.
//Hence, intervals[0]<=newInterval[1] ->2.
//  intervals=[[1,2],[3,5],[6,7],[8,10],[12,16]]  newIntervals=[4,8]
vector<vector<int>>insertIntervals(vector<vector<int>>intervals,vector<int>newInterval){
    vector<vector<int>>ans;
    int i=0,n=intervals.size();
    while(i<n && intervals[i][1]<newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=newInterval[1]){
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=max(newInterval[1],intervals[i][1]);
        i++;
    }
    ans.push_back({newInterval[0],newInterval[1]});
    while(i<n){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}
//L-3975 Filter Occupied Intervals
vector<vector<int>>filterOccupiedIntervals(vector<vector<int>>occupiedIntervals,int freeStart,int freeEnd){
    vector<vector<int>>ans;
    sort(occupiedIntervals.begin(),occupiedIntervals.end());
    int n=occupiedIntervals.size();
    for(int i=0;i<n;i++){
       int start=occupiedIntervals[i][0];
       int end=occupiedIntervals[i][1];
       if(!ans.empty() && ans.back()[1]>=end){
        continue;
       }
       for(int j=i+1;j<n;j++){
        int s=occupiedIntervals[j][0];
        int e=occupiedIntervals[j][1];
        if(s<=end || end+1==s){
          start=min(start,s);
          end=max(end,e);
        }else{
            break;
        }
       }
       if(start>=freeStart && start<=freeEnd){
        if(end<=freeEnd){
            continue;
        }else{
            start=freeEnd+1;
        }
       }else if(end>=freeStart && end<=freeEnd){
          end=freeStart-1;
       }
       if(freeStart>=start && freeStart<=end){
        ans.push_back({start,freeStart-1});
        ans.push_back({freeEnd+1,end});
        continue;
       }
       ans.push_back({start,end});
    }

}
int main(){
    return 0;
}