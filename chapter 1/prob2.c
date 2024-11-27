#include<stdio.h>
#include<math.h>

float f(float x, float y);

void main(){
    float x,y;
    FILE*fp=NULL;
    fp=fopen("prob2.txt","w");
    for(x=-1.0; x<=1.0; x+=0.25){
        for(y=-1.0; y<=1.0; y+=0.25){
            fprintf(fp, "%f\t%f\t%f\n", x, y, f(x,y));
        }
    }
    fclose(fp);
}

float f(float x, float y){
    if(fabs(x)>fabs(y)){
        return (pow(x,2)+pow(y,4));
    }
    else if(fabs(x)==fabs(y)){
        return x*x*(x*x+1);
    }else if(fabs(x)<fabs(y)){
        return y*y + pow(x,4);
    }
    }
