/* Orbital Wavefunction */
#include<stdio.h>
#include<math.h>
#define pi 3.14159

float f(float theta, int m);

void main(){
    float x,y1,x1;
    //float f(float x, int n);
    int n=0;

    FILE *fp=NULL;
    fp=fopen("prob4.txt", "w");
    for(x=0.0001; x<2.0*pi; x+=0.0005*pi){
        x1= f(x,n)*f(x,n)*cos(x);
        y1= f(x,n)*f(x,n)*sin(x);
        fprintf(fp, "%f \t %f\n", x1, y1);
    }

}
float f(float theta, int m){
    float v1,v2,v3;
    if(m==0){
        v1=(3.0*sqrt(14.0))/4.0;
        v2=((5.0/3.0)*pow(cos(theta),3))- cos(theta);
        v3= v1*v2;
        return v3;
    }
    if(m==1 || m==-1){
        v1=(sqrt(42.0)/8.0)*sin(theta);
        v2=(5.0*pow(cos(theta),2))-1;
        v3=v1*v2;
        return v3;
    }
    if(m==2 || m==-2){
        v1=(sqrt(105.0)/4.0)*pow(sin(theta),2);
        v2=pow(cos(theta),2);
        v3=v1*v2;
        return v3;
    }
    if(m==3 || m==-3){
        v1=(sqrt(70.0)/8.0);
        v2=pow(sin(theta),3);
        v3=v1*v2;
        return v3;
    }
}