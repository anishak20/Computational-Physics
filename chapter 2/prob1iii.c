/* Box */
#include<stdio.h>
#include<math.h>

void main(){
    float x,y;
    FILE *fp=NULL;
    fp= fopen("prob1iii.txt", "w");
    for(x=1; x<=5; x+=0.01){
        y=1;
        fprintf(fp, "%f \t %f \n", x, y);
    }
    for(y=1; y<=5; y+=0.01){
        x=5;
        fprintf(fp, "%f \t %f \n", x, y);
    }
    for(x=5; x>=1; x-=0.01){
        y=5;
        fprintf(fp, "%f \t %f \n", x, y);
    }
    for(y=5; y>=1; y-=0.01){
        x=1;
        fprintf(fp, "%f \t %f \n", x, y);
    }



}