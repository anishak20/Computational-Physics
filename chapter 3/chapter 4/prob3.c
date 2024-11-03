/*plot of f(x,y)=x*x*x + y*y*y + x*y +1 */
#include<stdio.h>
#include<math.h>
float f(float x, float y);
float secant(float x, float y);

void main(){
    float x,y,root;
    
    FILE*fp=NULL;
    fp=fopen("res_1.txt","w");
    for(x=-1.5;x<=1.5;x+=0.1){
        for(y=-2;y<=2;y+=0.1){
            root=secant(x,y);
            //fprintf(fp,"%f\t%f\n",y,f(x,y));
            fprintf(fp,"%f\t%f\n",root,f(root,y));
        }
    }

}
float f(float x, float y){
    return (x*x*x + y*y*y + x*y +1);
}

float secant(float x, float y){
    int i;
    float f1,x1,x2,f2,y1,y2,x3,t;
    x1=x;
    x2=x+0.1;
    y1=y;
    y2=y+0.1;
    int n=3;
    for(i=1;i<=n;i++){

        do{
            f1=f(x1,y1);
            f2=f(x2,y2);
            x3=(x1*f2-x2*f1)/(f2-f1);
            x1=x2;
            x2=x3;
            t=fabs(f2);
        }while(t>0.00001);
    }return x2;
}
