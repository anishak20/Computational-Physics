#include<stdio.h>
#include<math.h>

void main(){
    float z,t,s,s1;
    int i;
    float acc=0.00001;

    FILE*fp=NULL;
    fp=fopen("res_5.txt","w");
    for(z=-10.0;z<=0.0;z+=0.05){
        t=1;
        s=t;
        i=1;
        do{
            t*=(pow(z,3))/(3*i*(i-1));
            s+=t;
            i++;
        }while(fabs(t/s)>acc);
        s1=0.35503*s;
        fprintf(fp,"%f\t%f\n",z,s1);

    }

}