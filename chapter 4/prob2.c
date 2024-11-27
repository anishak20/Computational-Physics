#include<stdio.h>
#include<math.h>

float f(float x);
void main(){
    float x,xl,xr,xm,acc=0.00001,xinc=0.5,z;
    for(x=0.01; x<=4; x+=xinc){
        if(f(x)*f(x+xinc)<0){
            xl=x;
            xr=x+xinc;
            do{
                xm=(xl+xr)/2.0;
                if(f(xm)*f(xl)>0){
                    xl=xm;

                }else{
                    xr=xm;

                }
                z=fabs((xl-xr)/(xl+xr));

            }while(z>acc);
            printf("%f\t%f\n", xm , f(xm));
        }  
    }
    
}
float f(float x){
    float t,s;
    s=1.0;
    t=s;
    int k=0;

    do{
        k++;
        t*=-(x*x)/(4*k*k);
        s+=t;
        
    }while(fabs(t/s)>0.0001);
    return s;
}