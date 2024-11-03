#include<stdio.h>
#include<math.h>
#define pi 3.14159

void main(){
    float z,t,s,s1;
    float acc=0.00001;
    int k;
    FILE*fp=NULL;
    fp=fopen("res_3.txt","w");
    for(z=0;z<=1;z+=0.1){
        t=z;
        s=t;
        k=1;
        do{
            t*=(-pi*pi*pow(z,4))/(4*k+1);
            s+=t;
            k++;
        }while(fabs(t/s)>acc);
        s1=cos((pi*z*z)/2)*s;
        fprintf(fp,"%f\t%f\n",z,s1);

    }

}