/* Periodic Function*/
#include <stdio.h>
#include <math.h>
#define pi 3.14159

void main(){
    float x,y,x1,z;
    int n;
    FILE *fp=NULL;
    fp=fopen("prob3.txt", "w");
    for(x=-6.0*pi; x<=6.0*pi; x+=0.001*pi){
        n = (int)(x/(2.0*pi));
        x1= x- 2.0*pi*n;
        z= fabs(x1);
        if(z>=0 && z<pi){
            y=z;
        }
        if(z>=pi && z<2*pi){
            y= 2*pi -z;
        }
        fprintf(fp, "%f \t %f\n", x, y);

    }

}