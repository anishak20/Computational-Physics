#include<stdio.h>
#include<math.h>

int main(){

    float x,t,s,f;
    int n;
    for(x=0.1;x<=2.0;x+=0.01){
        t=1.0/(x*x);
        s=t;
        n=1;
        do{
            t*=1/x;
            s+=t;
            n++;
        }while(n<=18);
        s=1+s;
        f=(x*x-x+1)/(x*(x-1));
        printf("%d \t %f \t %f \t %f\n",n+1, x, s, f);
    }
   
   
}