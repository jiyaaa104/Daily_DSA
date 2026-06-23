//----------------------------1
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"Enter a number : "<<endl;
//     cin>>n;
//     cout<<"The number entered : "<<n<<endl;
//     return 0;
// }

//------------------------------2
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int marks;
//     cout<<"Enter the marks obtained : "<<endl;
//     cin>>marks;
//     if(marks>100){
//         cout<<"WRONG MARKS GIVEN!"<<endl;
//     }
//     else if(marks>=90 && marks<=100){
//         cout<<"GRADE A!"<<endl;
//     }else if(marks>=70){
//         cout<<"GRADE B!"<<endl;
//     }else if(marks>=50){
//         cout<<"Grade C!"<<endl;
//     }else if(marks>=35){
//         cout<<"GRADE D!"<<endl;
//     }else{
//         cout<<"FAIL!"<<endl;
//     }
//     return 0;
// }

//-----------------------------3
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int day;
//     cout<<"Enter the day number : ";
//     cin>>day;
//     cout<<"It's ";
//     switch(day){
//         case 1: cout<<"Monday!";
//         break;
//         case 2: cout<<"Tuesday!";
//         break;
//         case 3: cout<<"Wednesday!";
//         break;
//         case 4: cout<<"Thursday!";
//         break;
//         case 5: cout<<"Friday!";
//         break;
//         case 6: cout<<"Saturday!";
//         break;
//         case 7: cout<<"Sunday!";
//         break;
//         default: cout<<"Wrong number entered!";
//     }
//     return 0;
// }

//-----------------------------4
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int low,high,sum=0;
//     cout<<"Enter the lower number : "<<endl;
//     cin>>low;
//     cout<<"Enter the higher number : "<<endl;
//     cin>>high;
//     for(int i=low;i<=high;i++){
//       sum+=i;
//     }
//     cout<<sum<<endl;
//     return 0;
// }

//---------------------------------5
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int d,count=50,sum=0;
//     cout<<"Enter the end digit(0-9) : "<<endl;
//     cin>>d;
//     while(count>0){
//        sum+=d;
//        d+=10;
//        count--;
//     }
//     cout<<"Sum : "<<sum<<endl;
//     return 0;
// }

//---------------------------------6
// #include<bits/stdc++.h>
// using namespace std;
// void revArr(int arr[],int n){
//   for(int i=0;i<n/2;i++){
//     swap(arr[i],arr[n-1-i]);
//   }
// }
// void printArr(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// int main()
// {
//     int arr[]={1,2,3,4,5};
//     printArr(arr,5);
//     revArr(arr,5);
//     printArr(arr,5);
//     return 0;
// }

//---------------------------------7
// #include<bits/stdc++.h>
// using namespace std;
// int distance(int i,int j){
//     int mid=3;
//     int r=max(mid,i)-min(mid,i);
//     int c=max(mid,j)-min(mid,j);
//     return max(r+1,c+1);
// }
// int main(){
    //1
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<"*";
    //     }cout<<endl;
    // }

    //2
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }cout<<endl;
    // }

    //3
    // for(int i=1;i<=5;i++){
    //     int p=1;
    //     for(int j=1;j<=i;j++){
    //         cout<<p;
    //         p++;
    //     }cout<<endl;
    // }

    //4
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=i;j++){
    //       cout<<i;
    //     }cout<<endl;
    // }

    //5
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5+1-i;j++){
    //         cout<<"*";
    //     }cout<<endl;
    // }

    //6
    // for(int i=1;i<=5;i++){
    //     int p=1;
    //     for(int j=1;j<=5+1-i;j++){
    //         cout<<p;
    //         p++;
    //     }cout<<endl;
    // }

    //7
    // for(int i=1;i<=5;i++){
    //     for(int sp=1;sp<=5-i;sp++){
    //         cout<<" ";
    //     }
    //     for(int s=1;s<=2*i-1;s++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //8
    // for(int i=1;i<=5;i++){
    //     for(int sp=1;sp<=i-1;sp++){
    //         cout<<" ";
    //     }
    //     for(int s=1;s<=9-2*(i-1);s++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //9
    // for(int i=1;i<=5;i++){
    //     for(int sp=1;sp<=5-i;sp++){
    //         cout<<" ";
    //     }
    //     for(int s=1;s<=2*i-1;s++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=1;i<=5;i++){
    //     for(int sp=1;sp<=i-1;sp++){
    //         cout<<" ";
    //     }
    //     for(int s=1;s<=9-2*(i-1);s++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //10
    //     for(int i=1;i<=4;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<"*";
    //     }cout<<endl;
    // }
    //    for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5+1-i;j++){
    //         cout<<"*";
    //     }cout<<endl;
    // }

    //11
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=i;j++){
    //         if((i+j)%2!=0){
    //             cout<<"0";
    //         }else{
    //             cout<<"1";
    //         }
    //     }cout<<endl;
    // }

    //12
    // for(int i=1;i<=4;i++){
    //     for(int n=1;n<=i;n++){
    //         cout<<n;
    //     }
    //     for(int sp=1;sp<=6-2*(i-1);sp++){
    //         cout<<" ";
    //     }
    //     for(int m=i;m>=1;m--){
    //         cout<<m;
    //     }
    //     cout<<endl;
    // }

    //13
    // int p=1;
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=i;j++){
    //        cout<<" "<<p<<" ";
    //        p++;
    //     }cout<<endl;
    // }

    //14
    // for(int i=1;i<=5;i++){
    //     char ch=65;
    //     for(int j=1;j<=i;j++){
    //       cout<<ch;
    //       ch++;
    //     }cout<<endl;
    // }

    //15
    // for(int i=1;i<=5;i++){
    //     char ch=65;
    //     for(int j=1;j<=5+1-i;j++){
    //         cout<<ch;
    //         ch++;
    //     }cout<<endl;
    // }

    //16
    // for(int i=1;i<=5;i++){
    //     char ch=64+i;
    //     for(int j=1;j<=i;j++){
    //       cout<<ch;
    //     }cout<<endl;
    // }

    //17
    // for(int i=1;i<=5;i++){
    //     for(int sp=1;sp<=5-i;sp++){
    //         cout<<" ";
    //     }
    //     char ch=65;
    //     for(int p=1;p<=i;p++){
    //       cout<<ch;
    //       ch++;
    //     }
    //     char ch1=63+i;
    //     if(i!=1){
    //       for(int q=1;q<=(i-1);q++){
    //         cout<<ch1;
    //         ch1--;
    //       }
    //     }
    //     cout<<endl;
    // }

    //18
    // for(int i=5;i>0;i--){
    //     char ch=64+i;
    //     for(int j=1;j<=6-i;j++){
    //         cout<<ch;
    //         ch++;
    //     }cout<<endl;
    // }

    //19
    // for(int i=1;i<=5;i++){
    //     for(int s1=1;s1<=6-i;s1++){
    //         cout<<"*";
    //     }
    //     for(int sp=1;sp<=2*(i-1)-1;sp++){
    //         if(sp>0){
    //             cout<<" ";
    //         }
    //     }
    //     if(i==1){
    //         for(int sp=1;sp<=5-i;sp++){
    //             cout<<"*";
    //         }
    //     }else{
    //         for(int sp=1;sp<=6-i;sp++){
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }

    //20
    // for(int i=1;i<=4;i++){
    //     for(int n=1;n<=i;n++){
    //         cout<<"*";
    //     }
    //     for(int sp=1;sp<=6-2*(i-1);sp++){
    //         cout<<" ";
    //     }
    //     for(int m=i;m>=1;m--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=1;i<=3;i++){
    //     for(int s1=1;s1<=4-i;s1++){
    //         cout<<"*";
    //     }
    //     for(int sp=1;sp<=2*i;sp++){
    //         cout<<" ";
    //     }
    //     for(int s1=1;s1<=4-i;s1++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //21
    // for(int i=1;i<=4;i++){
    //     for(int j=1;j<=4;j++){
    //         if(i==1 || i==4 || j==1 || j==4){
    //             cout<<"*";
    //         }else{
    //             cout<<" ";
    //         }
    //     }cout<<endl;
    // }

    //22
//     for(int i=0;i<=6;i++){
//         for(int j=0;j<=6;j++){
//             int dis=distance(i,j);
//             cout<<dis;
//         }cout<<endl;
//     }
//     return 0;
// }

//------------------------------8,9,10,11
// #include<bits/stdc++.h>
// using namespace std;
// int countDigits(int n){
//     int c=0;
//     while(n!=0){
//         n/=10;
//         c++;
//     }return c;
// }
// int revNum(int n){
//     int ans=0;
//     int m=n;
//     int rem=0;
//     while(m!=0){
//        rem=m%10;
//        ans=10*ans+rem;
//        m=m/10;
//     }
//     return ans;
// }
// bool pallindrome(int n){
//    int m=n,rem=0,ans=0;
//    while(m!=0){
//      rem=m%10;
//      ans=10*ans+rem;
//      m/=10;
//    }
//    return (ans==n);
// }
// int gcdBrute(int a,int b){
//     int ans=min(a,b);
//     for(int i=ans;i>=1;i--){
//         if(a%i==0 && b%i==0){
//             ans=i;
//             break;
//         }
//     }return ans;
// }
// int gcdOptimal(int a,int b){
//     if(a==0){
//         return b;
//     }
//     else if(b==0){
//         return a;
//     }
//     else if(a>b){
//         return gcdOptimal(a-b,b);
//     }else{
//         return gcdOptimal(a,b-a);
//     }
// }
// int Topower(int n,int p){
//     int ans=1;
//     for(int i=p;i>0;i--){
//       ans*=n;
//     }return ans;
// }
// bool Armstrong(int n){
//     int dig=countDigits(n);
//     int sum=0,rem;
//     int m=n;
//     while(m!=0){
//         rem=m%10;
//         sum+=Topower(rem,dig);
//         m/=10;
//     }
//     return(n==sum);
// }
// void divisors(int n){
//     for(int i=1;i<=n/i;i++){
//         if(n%i==0){
//             cout<<i<<" ";
//             if(i*i!=n){
//                 cout<<n/i<<" ";
//             }
//         }
//     }
// }
// bool prime(int n){
//     for(int i=2;i<sqrt(n);i++){
//         if(n%i==0){
//             return false;
//         }
//     }return true;
// }
// int main()
// {
//     // int n,m;
//     // cout<<"Enter number : "<<endl;
//     // cin>>n;
//     // cout<<"The number of digits : "<<countDigits(n);
//     // cout<<"Reversed Num : "<<revNum(n);
//     // cout<<pallindrome(n)<<endl;
//     // cout<<"GCD : "<<gcdOptimal(n,m);
//     // cout<<Armstrong(n);
//     // divisors(90);
//     cout<<prime(19);
//     return 0;
// }

// smthg
#include<bits/stdc++.h>
using namespace std;
void rec(int n){
    if(n==0){
        return;
    }
    cout<<"Aka is Cute !"<<endl;
    n--;
    rec(n);
}
void ascN(int n,int i){
    cout<<i<<" ";
    if(i==n){
        return;
    }
    ascN(n,++i);
}
void dscN(int n){
    if(n==0){
        return;
    }
    cout<<n;
    dscN(--n);
}
int sum(int n){
    if(n==0 || n==1){
        return n;
    }
    return sum(n-1)+n;
}
int fact(int n){
    if(n==0 ||n==1){
        return 1;
    }
    return fact(n-1)*n;
}
int main()
{
    // rec(2);
    // ascN(3,1);
    // dscN(3);
    cout<<fact(5);
    return 0;
}