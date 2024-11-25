#include<stdio.h>
#include<math.h>
#define pi 3.14159

float g(float x, float t);
float f(float x);
float simpson(float x);
float secant(float x1, float x2);

void main(){

    float acc=0.00001,x,root;
    float lroot;
    int i=0;
    for(x=0; x<=10; x+=0.5){
        if(f(x)*f(x+0.5)<0){
            root= secant(x, x+0.5);
            if(i == 0){
                lroot = root;
            } else if(root < lroot){
                lroot = root;
            }
            i++;
        }
        
    }  
    printf("total roots=%d\n", i);
    printf("lowest root=%f\n", lroot);

}

float g(float x, float t){
    return cos(pow(x,1.5)*cos(t))*pow(sin(t),3)*t;
}

float simpson(float x){
    float h,s;
    float a=0,b=pi;
    s=0.0;
    int i,N=10000;
    h=(b-a)/N;

    for(i=1; i<=N; i+=2){
        s+=4*g(x,a+i*h)+2*g(x,a+(i+1)*h);
    }
        s+=s+g(x,a)+g(x,b);
        s*=(h/(3*2*pi));
        return s;
}
float f(float x){
    return simpson(x);
}

float secant(float x1, float x2){
    float f1,f2,x3,t,acc=0.00001;
   
        do{ 
            f1 = f(x1);
            f2 = f(x2);

        // Check for small denominator
        if (fabs(f2 - f1) < 1e-10) {
            printf("Secant method: Small difference detected. Stopping iteration.\n");
            break;
        }
            x3= (x1*f2-f1*x2)/(f2-f1);
            x1=x2;
            x2=x3;
            t=fabs(f2); 
        }while(t>acc);
    return x2;

}
