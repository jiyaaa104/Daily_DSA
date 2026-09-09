//l-3090
#include<bits/stdc++.h>
using namespace std;
int maxLenAtmost2Occurance(string s){
    int n=s.size();
    int l=0,r=0,maxLen=0;
    unordered_map<char,int>mpp;
    while(r<n){
        mpp[s[r]]++;
        while(mpp[s[r]]>2){
            mpp[s[l]]--;
            l++;
        }
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
//L-3702 Longest subsequence with non zero bitwise xor
//There are only 3 ans that can exist -> 0(when every number is 0), n(xor of all no.s of array are non zero), n-1
int longestSubseqNonZeroXOR(vector<int>&nums){
    int n=nums.size();
    int x=0;
    for(int i=0;i<n;i++){
        x^=nums[i];
    }
    if(x!=0) return n;
//after this stage x= xor(all no.s present)
//we reacjh at this part of code only if xor=0   
//x=0-> x^nums[i] (remove nums[i]) 0^nums[i]=nums[i] if(nums[i]>0) on removing 1 , we get xor >0 
    for(int i=0;i<n;i++){
        x^=nums[i];
    //removing one person at a time
    if(x!=0)return n-1;
    //adding the person for future use
    x^=nums[i];  
    }
//if till now xor has been zero that only means , all no.s were zero   
return 0; 
}
//L-80
int removeDuplicates2(vector<int>&nums){
    int n=nums.size();
    int left=0;
    for(int right=0;right<n;right++){
        if(left<2 || nums[left-2]!=nums[right]){
            nums[left]=nums[right];
            left++;
        }
    }
    return left;
}
//L-3
int longestSubstringWithoutRepeatingCharacters(string s){
    int n=s.size();
    unordered_map<char,int>mpp;
    int l=0,r=0,maxLen=0;
    while(r<n){
//the first thing we do before adding in the valid window is do I already have it in my existing valid window. If I do my window needs to be updated. The next beginning would be the previous occurance at i+1        
        if(mpp[s[r]]>=l){
            l=mpp[s[r]]+1;
        }
        mpp[s[r]]=r;
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
//L-2260
//there is no window that I need.therefore no need of L
int minimumConsecutiveCardsPick(vector<int>&nums){
    int n=nums.size();
    int l=0,r=0,minLen=INT_MAX;
    unordered_map<int,int>mpp;
    while(r<n){
        if(mpp.find(nums[r])!=mpp.end()){
            minLen=min(minLen,r-mpp[nums[r]]+1);
        }
        mpp[nums[r]]=r;
        r++;
    }return minLen;
}
//L-1695
//   1,2,3,4,1,3,5,6
int maximumErasureVal(vector<int>&nums){
    int sum=0,n=nums.size(),l=0,r=0,ans=0;
    unordered_map<int,int>mpp;
    while(r<n){
        sum+=nums[r];
        mpp[nums[r]]++;
        while(mpp[nums[r]]>1){
            sum-=nums[l];
            mpp[nums[l]]--;
            l++;
        }
        ans=max(ans,sum);
        r++;
    }return ans;
}
//L-2401
//BASICALLY I need to find the longest subarray such that each pair of that subarray has BITWISE &=0
//WHEN IS XOR = 0? when all the bits at same bit position do not match/collide. therefore I will keep a track of all the used bit positions which must not collide later.and If they do I'll reduce the window. used bits-> used|=nums[i], reduce window size-> used^=nums[i].How will I know if a particular number collides with the previously occupied bit positions? used&nums[i]==0 => no collision
int longestNiceSubArray(vector<int>&nums){
    int n=nums.size();
    int used=0,l=0,r=0,maxLen=0;
    while(r<n){
        while((used&nums[r])!=0){
//The new person should bring new bits if they dont, remove the previous people.            
           used^=nums[l];
           l++;
        }
        used|=nums[r];
//store the bits brought by new people        
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
//L-2405
//OPTIMAL PARTION
int optimalPartion(string s){
    int n=s.size();
    int l=0,r=0,count=0;
    vector<int>mpp(26,-1);
    while(r<n){
      if(mpp[s[r]-'a']>=l){
        count++;
        l=r;
      }
      mpp[s[r]-'a']=r;
      r++;
    }
    return count+1;
}
//L-1004
//MAXIMUM CONSECUTIVE ONES
int maximumConsecutiveOnes(vector<int>&nums,int k){
    int n=nums.size();
    int l=0,r=0,maxLen=0,zeroes=0;
    while(r<n){
        if(nums[r]==0)zeroes++;
        if(zeroes>k){
            if(nums[l]==0)zeroes--;
            l++;
        }
       else{
         maxLen=max(maxLen,r-l+1);
       }
        r++;
    }return maxLen;
}
//L-2461
int maximumSumDistinctSubarray(vector<int>&nums,int k){
    int n=nums.size(),l=0,r=0,sum=0,maxSum=0;
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
int maximiseConfusion(string s,int k){
    int n=s.size(),l=0,r=0,maxLen=0,tCount=0,fCount=0;
    while(r<n){
        if(s[r]=='T')tCount++;
        else fCount++;
        int minFlips=min(tCount,fCount);
        if(minFlips<=k){
            maxLen=max(maxLen,r-l+1);
        }else{
            if(s[l]=='T')tCount--;
            else fCount--;
            l++;
        }
        r++;
    }return maxLen;
}
int longestRepeatingCharacterReplacement(string s,int k){
    int n=s.size(),l=0,r=0,maxi=0,maxlen=0;
    unordered_map<char,int>mpp;
    while(r<n){
       mpp[s[r]]++;
       if(mpp[s[r]]>maxi){
        maxi=mpp[s[r]];
       }
       if(r-l+1-maxi<=k){
         maxlen=max(maxlen,r-l+1);
       }else{
          mpp[s[l]]--;
          l++;
       }
       r++;
    }return maxlen;
}  
int fruitsIntoBaskets(vector<int>&nums){
    int n=nums.size();
    int l=0,r=0,maxLen=0;
    unordered_map<int,int>mpp;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>2){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        maxLen=max(maxLen,r-l+1);
        r++;
    }return maxLen;
}
int main(){
    vector<int>a={1,5,4,2,9,9,9};
    cout<<fruitsIntoBaskets(a);
    // cout<<longestRepeatingCharacterReplacement("TTFFTTFFF",2);
    return 0;
}