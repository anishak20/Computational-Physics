/*to find zeros of the bessel function*/
#include<stdio.h>
#include<math.h>
#define pi 3.14159
#define acc 0.00001

float g(float z, float x);
float simpson(float z);
float secant(float x1, float x2);
float f(float z);

void main(){
    float z,root;
    for(z=0; z<=12; z+=0.5){
        if(f(z)*f(z+0.5)<0){
            root= secant(z, z+0.5);
            printf("Root : %f\n", root); 
        } 
    }
}

float g(float z, float x){
    return cos(z*cos(x));
}
float simpson(float z){
    float a=0,b=pi;
    float h,s;
    int i,N=10000;
    h=(b-a)/N;
    s=0;
    for(i=1; i<=N; i+=2){
        s+=4*g(z, a+i*h)+2*g(z, a+(i+1)*h);
    }
    s=s+g(z, a)+ g(z, b);
    s*=(h/(3*2*pi));
    return s;
}
float f(float z){
    return simpson(z);
}

float secant(float x1, float x2){
    float f1,f2,x3,t;

        do{
           f1= f(x1);
           f2= f(x2);
           if (fabs(f2 - f1) < 1e-10) {
                printf("Secant method: Division by zero or small difference detected.\n");
                break;
            }
           x3= (x1*f2-f1*x2)/(f2-f1);
           x1=x2;
           x2=x3;
           t=fabs(f2);
        }while(t>acc);
    
    return x2;
}
