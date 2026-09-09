#include<bits/stdc++.h>
using namespace std;
int function1(string s){
    int n=s.size();
    int l=0,r=0,maxLen=0;
    vector<int>mpp(26,0);
    while(r<n){
        mpp[s[r]-'a']++;
        while(mpp[s[r]-'a']>2){
            mpp[s[l]-'a']--;
            l++;
        }
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
int function2(vector<int>&nums){
    int n=nums.size();
    int x=0;
    for(int i=0;i<n;i++){
        x^=nums[i];
    }
    if(x!=0)return n;
    //x==0->
    for(int i=0;i<n;i++){
        x^=nums[i];
        //remove one person 0^y=y if(y>0) 
        if(x!=0)return n-1;
        x^=nums[i];
    }
    return 0;
}
int function3(vector<int>&nums){
    int n=nums.size();
    int left=0;
    for(int right=0;right<n;right++){
        if(left<2 || nums[right]!=nums[left-2]){
            nums[left]=nums[right];
            left++;
        }
    }return left;
}
int function4(string s){
    int n=s.size();
    int l=0,r=0,maxLen=0;
    unordered_map<char,int>mpp;
    while(r<n){
        if((mpp.find(s[r])!=mpp.end()) && mpp[s[r]]>=l){
           l=mpp[s[r]]+1;
        }
        mpp[s[r]]=r;
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
int function5(vector<int>&nums){
    int n=nums.size();
    int l=0,r=0,minLen=INT_MAX;
    unordered_map<int,int>mpp;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp[nums[r]]==2){
           minLen=min(minLen,r-l+1);
           mpp[nums[l]]--;
           l++;
        }
        r++;
    }return minLen==INT_MAX?-1:minLen;
}
int function6(vector<int>&nums){
    int n=nums.size();
    int l=0,r=0,sum=0,maxSum=0;
    unordered_map<int,int>mpp;
    while(r<n){
        sum+=nums[r];
        mpp[nums[r]]++;
        while(mpp[nums[r]]>1){
            sum-=nums[l];
            mpp[nums[l]]--;
            l++;
        }
        maxSum=max(maxSum,sum);
        r++;
    }return maxSum;
}
int function7(vector<int>&nums){
    int used=0,n=nums.size();
    int l=0,r=0,maxLen=0;
    while(r<n){
        while((used&nums[r])!=0){
            used^=nums[l];
            l++;
        }
        used|=nums[r];
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
int function8(string s){
    int count=0,n=s.size(),l=0,r=0;
    unordered_map<char,int>mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp[s[r]]>1)count++;
     while(mpp[s[r]]>1){
        mpp[s[l]]--;
        l++;
     }
     r++;
    }return count+1;
}
int function9(vector<int>&nums,int k){
    int n=nums.size();
    int l=0,r=0,maxLen=0,z=0;
    while(r<n){
       if(nums[r]==0)z++;
       if(z>k){
         if(nums[l]==0)z--;
         l++;
       }
       else{
        maxLen=max(maxLen,r-l+1);
       }
       r++;
    }return maxLen;
}
int function10(vector<int>&nums,int k){
    int n=nums.size(),sum=0,maxSum=0,l=0,r=0;
    unordered_map<int,int>mpp;
    while(r<n){
        sum+=nums[r];
        mpp[nums[r]]++;
        while(mpp[nums[r]]>1 || r-l+1>k){
            mpp[nums[l]]--;
            sum-=nums[l];
            l++;
        }
        if(r-l+1==k){
            maxSum=max(maxSum,sum);
        }
        r++;
    }return maxSum;
}
int main(){
    vector<int>nums={1,5,4,2,9,9,9};
    cout<<function10(nums,3);
    return 0;
}