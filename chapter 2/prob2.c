/* Lissajous Figures */
#include <stdio.h>
#include <math.h>
#define pi 3.14159

void main(){
   float x,y;
   float A=1; // change values acc to the ques
   float n=2; // change values acc to the ques
   float delta = pi; // change values acc to the ques
   float theta;
   FILE *fp=NULL;
   fp=fopen("prob2.txt", "w");
   for(theta=0; theta<=4*pi; theta+=pi/100.0){
    x= sin(theta);
    y= A*sin(n*theta + delta);
    fprintf(fp, "%f \t %f\n", x, y);
   }

}