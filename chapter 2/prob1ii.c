/*Circle*/
#include<stdio.h>
#include<math.h>
#define pi 3.14159

void main(){
    FILE*fp=NULL;
    fp=fopen("prob1ii.txt","w");
    float x0=5,y0=5,r=3,x,y,t;
    for(t=0; t<=2*pi; t+=pi/100){
        y=y0+r*sin(t);
        x=x0+r*cos(t);
        fprintf(fp,"%f\t%f\n",x,y);
    }
}