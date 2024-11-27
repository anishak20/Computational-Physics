/*Program to generate fibonacci numbers till 200
fib(n)= fib(n-1)+fib(n-2) */
#include<stdio.h>
#include<math.h>

int fib(int n);

int main(){
    int n=200;
    while(fib(n)<=n){
        printf("%d",fib(n));
    }
    return 0;
}

int fib(int n){
    int t1=0,t2=1,next,f1;
    next=t1+t2;
    while(next<=n){
        printf("%d\n",next);
        t1=t2;
        t2=next;
        next=t1+t2;
    }
}