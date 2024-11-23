#include<stdio.h>
#include<math.h>

//function declaration
float f(float x);

void main(){
    //gauss hermite for n=10
    float w[20],x[20],s,s1,s2;
    int i,n;
    n=10;
    s=0.0;

    #include "hermite.c"
    for(i=0;i<n/2;i++){
        s1=x[i];
        s2=-x[i];
        s+=((f(s1)+f(s2))*w[i]);
    
    }
    printf("%f\n",s);

}

//function definition
float f(float x){
    return log(1+pow(x,2));
}