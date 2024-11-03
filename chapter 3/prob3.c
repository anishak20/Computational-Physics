#include<stdio.h>
#include<math.h>

int fact(int n);
void main(){
    float x, sum, t;
    float acc=0.001;
    int k,n;

    FILE*fp=NULL;
    fp=fopen("res_2.txt","w");
    for(n=0;n<=2;n++){
        for(x=0; x<=10.0; x+=0.1){
            k=0;
            sum=1.0/fact(n);
            t=sum;
            do{
                k++;
                t*=(-x*x)/(4.0*k*(n+k));
                sum+=t;
            }
            while(fabs(t/sum)>acc);
            sum*=pow((x/2),n);
            printf("n = %d, fact(n) = %d, x = %f, sum = %f\n", n, fact(n), x, sum);
            fprintf(fp,"%d \t %f \t %f \t %f \n", n,fact(n),x,sum);
        }
    }

}

int fact(int n){
    int i=1;
    int fac=1;
    if(n==0){
        fac=1;
    } else{
        for(i=1; i<=n; i++){
            fac*=i;
        }

    }
    return fac;
} 