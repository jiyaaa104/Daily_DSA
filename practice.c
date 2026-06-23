#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the year you want to check : ");
    scanf("%d",&a);
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                printf("The Year is leap Year!");
            }else{
                printf("The Year is NOT A leap Year!");
            }
        }else{
            printf("The Year is leap Year!");
        }
    }else{ 
        printf("The Year is NOT A leap Year!");
    }
        
    return 0;
}