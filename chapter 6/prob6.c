#include<stdio.h>
#include<math.h>
#define pi 3.14159
#define acc 0.00001

float g(float z, float theta);
float simpson(float z);
float f(float z);
float secant(float z1, float z2);

void main(){
    float z,root,zinc=0.5;
    for(z=0; z<10; z+=zinc){
            if(f(z)==0){ //to check exact root
                printf("Root: %f\n",z);
            }else if(f(z)*f(z+zinc)<0){
            root= secant(z, z+zinc);
            printf("Root: %f\n", root);
            }
        }
    }

float g(float z, float theta){
    return cos(z* cos(theta))*(pow(sin(theta),3));
}
float simpson(float z){
    float a=0,b=pi;
    float h,s;
    int i,N=10000;
    h=(b-a)/N;
    s=0;
    s= s+ g(z, a)+ g(z, b);
    for(i=1; i<=N; i+=2){
        s+=4*g(z, a+i*h) + 2*g(z, a+(i+1)*h);
    }
    s*=z*h/(3*4);
    
    return s;

}
float f(float z){
    return simpson(z);
}
float secant(float z1, float z2){
    float f1,f2,x3,t;
    f1= f(z1);
    f2= f(z2);
    do{
        f1=f(z1);
        f2=f(z2);
        if(fabs(f2-f1)<1e-10){
            printf("Secant method: Division by zero or small number detected\n");
            break;
        }
        x3=(z1*f2-z2*f1)/(f2-f1);
        z1=z2;
        z2=x3;
        t=fabs(f2);
    }while(t>acc);
    return z2;
}