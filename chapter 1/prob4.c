/*Harshad numbers: Integers which are divisible by the sum of their digits*/
#include<stdio.h>
#include<math.h>

int sumofdigits(int n);

void main(){
    int a=50,b=70;
    for(int n=a; n<=b; n++){
        int sum=sumofdigits(n);
        if(n%sum==0){
            printf("Harshad No: %d\n",n);
        }
    }

}
int sumofdigits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
    
}