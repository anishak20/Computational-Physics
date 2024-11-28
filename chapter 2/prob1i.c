/*Right Angled Triangle with vertices at (0,0), (4,0) and (4,3)*/

#include<stdio.h>
#include<math.h>

void main(){
    float x,y;
    FILE*fp=NULL;
    fp=fopen("prob1i.txt","w");
    for(x=0; x<=4; x+=0.01){
        y=0;
        fprintf(fp,"%f\t%f\n", x, y);
    }
    for(y=0; y<=3; y+=0.01){
        x=4;
        fprintf(fp,"%f\t%f\n", x, y);
    }
    for(x=4; x>=0; x-=0.01){
        y=0.75*x;
        fprintf(fp,"%f\t%f\n", x, y);
    }
}
