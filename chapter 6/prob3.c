#include<stdio.h>
#include<math.h>

//function declaration
float V(float r);
float f(float r, float E);


void main(){
    //gauss legendre 
    float x[20],w[20],c,d,z,z1,a,b,s,E,r,h;
    FILE*fp=NULL;
    fp=fopen("prob3.txt","w");
    a=0.5;
    b=5;
    int i;
    int n=6;
    #include "gauss.c"
    c=0.5*(b+a);
    d=0.5*(b-a);
    s=0.0;
    //h=(b-a)/2000;
    for(r=a;r<=b;r+=0.1){
    for(i=0;i<n/2;i++){
        E=0;
        z=c+d*x[i];
        z1=c-d*x[i];
        s+=w[i]*(f(z,E)+f(z1,E));
        s*=d;
        fprintf(fp,"%f\t%f\n",3.4*cos(s),3.4*sin(s));
        }
        
    } 
}

//function definition
float V(float r){
    return -1/r;

}

float f(float r, float E){
    return 1/(pow(r,2)*sqrt((2*E)-(2*V(r))-(1/(r*r))));
}