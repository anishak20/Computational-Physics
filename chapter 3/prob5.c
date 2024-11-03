#include<stdio.h>
#include<math.h>
#define pi 3.14159

void main(){
    float z,t,s;
    float acc=0.00001;
    int n,k;

    FILE*fp=NULL;
    fp=fopen("res_4.txt","w");
    for(z=0;z<=5;z+=0.1){
        t=1/(2*sqrt(pi));
        s=t;
        n=2;
        k=2;
        do{
            t*=(-2*z*z*(n-k+1))/(k*(k-1));
            s+=t;
            k+=2;

        }while(fabs(t/s)>acc);
        fprintf(fp,"%f\t%f",z,s);

    }
    fclose(fp);

}