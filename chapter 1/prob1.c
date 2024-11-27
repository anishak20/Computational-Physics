/*table for tan x*/
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main(){
    float x;
    FILE*fp=NULL;
    fp=fopen("prob1.txt","w");
    for(x=0; x<=pi/4.0; x+=pi/100){
        fprintf(fp,"%f\t%f\n", x, tan(x));
    }
    fclose(fp);
    return 0;
}