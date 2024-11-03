/*evaluate cos x using the series*/
#include<stdio.h>
#include<math.h>
#define pi 3.14159

void main(){
    float x,t,sum;
    float acc=0.00001;
    int i;

    FILE*fp=NULL;
    fp=fopen("res_1.txt", "w");
    for(x=0; x<=(2*pi); x+=0.02){
        sum=1;
        t=1;
        i=1;
        do{
            t*=-x*x/(2.0*i*(2.0*i-1));
            sum+=t;
            i++;
        }while(fabs(t/sum)>acc);
        fprintf(fp,"%f\t%f\t%f\n",x, sum, cos(x));

    }

}