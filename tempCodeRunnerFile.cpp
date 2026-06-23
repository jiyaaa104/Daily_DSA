}
bool possible(vector<string>&strs,int left,char c){
  for(int i=0;i<strs.size();i++){
    if(strs[i][left]!=c){
      return false;
    }
  }return true;
}
void longestCommon(vector<string>&strs){
  int n=strs.size();
  int mini=INT_MAX;
  for(int i=0;i<n;i++){int p=strs[i].size();
      mini=min(mini,p);
  }int left=0;
  while(left<=mini){
    char c=strs[0][left];
    bool check=possible(strs,left,c);
    if(check){left++;}else{
      break;
    }
  }
  for(int i=0;i<left;i++){