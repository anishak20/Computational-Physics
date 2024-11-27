/*Quadratic Equation*/
#include<stdio.h>
#include<math.h>

int main(){
    float a=1,b=2,c=6,r1,r2,d;
    d= b*b - 4*a*c;
    if(d>0){
        r1=(-b+sqrt(d))/(2*a);
        r2=(-b-sqrt(d))/(2*a);
        printf("Roots are %f and %f", r1, r2);
    }else if(d==0){
        r1=r2=-b/(2*a);
        printf("Roots are %f",r1);
    }else{
        printf("Roots are imaginary and determinant is negative!");
    }

    return 0;
}