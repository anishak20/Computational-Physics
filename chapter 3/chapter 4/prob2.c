#include<stdio.h>
#include<math.h>

float f(float x);

void main(){
    float x,x1,x2,xm,xl,xr,z;
    float inc=0.5;
    float acc=0.0001;
    int n,i;
    
    for(x=0.01;x<=4.0;x+=0.1){
        printf("%f\t%f\n",x,f(x));
    }
    printf("\n enter number of roots:");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
        printf("\n enter x1:");
        scanf("%f",&x1);
        printf("\n enter x2:");
        scanf("%f",&x2);
        for(x=x1;x<=x2;x+=inc){
            if(f(x)*f(x+inc)<0){
                xl=x;
                xr=x+inc;
                do{
                    xm=(xl+xr)/2.0;
                    if(f(xl)*f(xm)>0){
                        xl=xm;
                    }
                    if(f(xl)*f(xm)<0){
                        xr=xm;
                    }
                    z=fabs((xl-xr)/(xl+xr));
                }while(z>acc);
                printf("xm=%f f(xm)=%f z=%f acc=%f\n",xm,f(xm),z,acc);
                break;
        
            }
        }

    }


}
float f(float x){
    float t;
    int n,k;
    float s=1;
    t=s;
    n=0;
    k=0;

    do{
        k++;
        t*=(-x*x)/(4*k*(n+k));
        s+=t;

    }while((t/s)>0.0001);
    return s;
}