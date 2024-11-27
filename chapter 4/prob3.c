#include<stdio.h>
#include<math.h>

void main(){
    float x,y,f,g,f1,f2,xinc=0.5,yinc=0.5,h,acc=0.00001;

    FILE*fp=NULL;
    fp=fopen("prob3one.txt","w");
    for(x=-1.5; x<=1.5; x+=xinc){
        for(y=-2.0; y<=2.0; y+=yinc){
            f= pow(x,3)+x*y+pow(y,3)+1;
            g=pow((x+xinc),3) + (x+xinc)*y + pow(y,3)+1;
            if(f*g<0){
                do{
                    f1= pow(x,3)+x*y+pow(y,3)+1;
                    f2= 3*x*x + y;
                    h= -f1/f2;
                    x+=h;
                }while(fabs(h/x)>acc);
                fprintf(fp, "%f\t%f\t%f\n", y, x, f1);

            }

        }
    }

}
