/*Chebyshev Polynomials*/
#include<stdio.h>
#include<math.h>

float Un(int n, float x);

void main(){
    float x,xinc=0.05,x1,x2,x3,f1,f2,acc=0.00001;

    FILE*fp=NULL;
    fp=fopen("prob5one.txt","w");
    for(x=-1.0; x<=1.0; x+=xinc){
        fprintf(fp,"%f\t%f\n", x, Un(4, x));
    }
    //secant method to find roots
    for(x=-1.0; x<=1.0; x+=xinc){
        if(Un(4,x)==0){
                printf("Root: %f\n", x);
            }
        if(Un(4,x)*Un(4,x+xinc)<0)
        {
        x1=x;
        x2=x+xinc;
            do{
            f1= Un(4,x1);
            f2= Un(4,x2);
            if(fabs(f2-f1)<1e-10){
                printf("Secant Method: Division by small number or zero detected\n");
                break;
            }
            x3=(x1*f2-x2*f1)/(f2-f1);
            x1=x2;
            x2=x3;
            }while(fabs(f2)>acc);
            printf("Root: %f\n", x2);
        }
    }
}

float Un(int n, float x){
    if(n==0){
        return 1;
    }else if(n==1){
        return 2*x;
    } else{
        return 2*x*Un(n-1,x)- Un(n-2, x);
    }
}

