#include<stdio.h>
#include<math.h>


float f(float A, float x);

void main(){
    float h;
    int i,n=1000;
    float A,b,a,s,r,P;
    float pi=3.14159;
    FILE*fp=NULL;
    fp=fopen("prob2.txt","w");

    //simpson method
    for(A=0.1;A<pi;A+=0.1){
        b=pi/2.0;
        a=0;
        h=(b-a)/n;
        s=0;
        for(i=0;i<=n-1;i+=2){
            s+=4*f(A,a+i*h)+2*f(A,a+(i+1)*h);
        }
        s=s+f(A,a)+f(A,b);
        s*=4*h/3.0;
        r=2.0*pi*(1+(A/4.0)*(A/4.0));
        P=(s-r)/s;
        fprintf(fp,"%f\t%f\t%f\t%f\n",A,s,r,P);

    }

}

float f(float A, float x){
    return 1.0/(1.0-sin(A/2)*sin(A/2)*sin(x)*sin(x));
}