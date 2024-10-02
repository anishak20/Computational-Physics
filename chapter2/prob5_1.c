/*Spherical Bessel Functions*/
#include <stdio.h>
#include <math.h>

double Q0(double z);
double Q1(double z);
double Qn(double z,int n);

void main(){

    FILE *fp=NULL;
    fp=fopen("res1.txt", "w");
    double z;
    int n;
    for(z=0.01;z<=7;z=z+0.01){
        fprintf(fp,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %lf \n",z, Qn(z,0), Qn(z,1), Qn(z,2), Qn(z,3), Qn(z,4), Qn(z,5));
    }
     
}
//Define Q0(z) 
double Q0(double z){
    return sin(z)/z;
}
 
//Define Q1(z) 
double Q1(double z){
    return sin(z)/(z*z)-cos(z)/z;
}
 
//Define Qn(z) 
double Qn(double z,int n){
    double out;
    if (n==0){
        out = Q0(z);
    }
    else if(n==1){
        out = Q1(z);
    }
    //Using recurrence relation 
    else{
        out = (2*n-1)*Qn(z,n-1)/z-Qn(z,n-2);
    }
    return out;
}
