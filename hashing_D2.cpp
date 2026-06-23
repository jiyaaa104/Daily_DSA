//------------------------------NUMBER HASHING
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m,q;
//     cout<<"Enter the number of elements in the array : "<<endl;
//     cin>>n;
//     cout<<"Enter the maximum allowed value of array : "<<endl;
//     cin>>m;
//     int arr[n];
//     int hash[m+1]={0};
//     for(int i=0;i<n;i++){
//         cout<<"Enter element "<<i+1<<" : ";
//         cin>>arr[i];
//     }
//     for(int i=0;i<n;i++){
//         hash[arr[i]]++;
//     }
//     cout<<"Enter the number of elements you want to check occurances of : "<<endl;
//     cin>>q;
//     int p;
//     while(q--){
//         cout<<"Enter element : ";
//         cin>>p;
//         cout<<"Occurance of "<<p<<" = "<<hash[p]<<endl;
//     }
//     return 0;
// }

//--------------------------CHARACTER HASHING
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Enter the string : ";
//     cin>>s;
//     int hash[26]={0};
//     for(int i=0;i<s.length();i++){
//       hash[s[i]-'a']++;
//     }
//     int q;
//     cout<<"Enter the number of characters you want to check the occurances of : ";
//     cin>>q;
//     char c;
//     while(q--){
//         cout<<"Enter character : ";
//         cin>>c;
//         cout<<"Occurance of "<<c<<" = "<<hash[c-'a']<<endl;
//     }
    
//     return 0;
// }

//----------------------------Number Hashing using map data structure
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element : "<<i+1<<" : ";
        cin>>arr[i];
    }
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    int q,p;
    cout<<"Enter the number of elements you want to check the occurances for : "<<endl;
    cin>>q;
    while(q--){
        cout<<"Enter element : ";
        cin>>p;
        cout<<"Occurance of "<<p<<" = "<<mpp[p]<<endl;
    }
    for(auto it : mpp){
      cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}