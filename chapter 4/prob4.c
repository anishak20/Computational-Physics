#include<stdio.h>
#include<math.h>
#define pi 3.14159

float f(float x, float t);
float g(float x);

void main(){
    float x,t,f1,f2,h,acc=0.00001,r,c,x1,y1;
    FILE*fp=NULL;
    fp=fopen("prob4one.txt","w");

    for(t=0.001; t<=2*pi; t+=0.05){
        x=t;
        do{
            f1= f(x,t);
            f2= g(x);
            h=-f1/f2;
            x+=h;

        }while(fabs(h/x)>acc);
        r=2.0*(1-0.8*cos(x));
        c=(cos(x)-0.8)/(1-(0.8*cos(x)));
        x1=r*c;
        y1=r*sqrt(1.0-c*c);
        fprintf(fp,"%f\t%f\n", x1, y1);
        fprintf(fp,"%f\t%f\n", x1, -y1);


    }

}
float f(float x, float t){
    return (x-(0.8* sin(x))-t);
}
float g(float x){
    return 1-0.8*cos(x);
}