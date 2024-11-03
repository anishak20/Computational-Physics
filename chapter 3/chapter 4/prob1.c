#include<stdio.h>
#include<math.h>

float acc=0.00001;
float x1,x2,z,t,v; //global variables


/*Function declaration*/
float f(float x);
float g(float x);
float bisection(float x);
float secant(float x);
float newtonraphson(float x);


void main(){
    float x,root,xm,f2;
    float xinc=0.5;
    float c=-1;
    float d=1;
    int n,i,m;

    for(x=c;x<=d;x+=0.1){
        printf("%f\t%f\n",x,f(x));

    }
    printf("\n Enter 1 for bisection, 2 for secant, 3 for newton raphson\n");
    scanf("%d",&m);
    
    printf("\n enter no of roots:");
    scanf("%d",&n);
   
    for(i=1;i<=n;i++){
        if(m==1){
            printf("\n enter x1:");
            scanf("%f",&x1);
            printf("\n enter x2:");
            scanf("%f",&x2);
            for(x=x1;x<=x2;x+=xinc){
            root=bisection(x);
        }
        printf("root = %f\tf(x) = %f\t%f\t%f\n",root,f(root),z,acc);
        }
        else if(m==2)
	{
	   printf("\n enter x1:");
       scanf("%f",&x1);
       printf("\n enter x2:");
       scanf("%f",&x2);
	   root = secant(x);
	  printf("root = %f\tf(x) = %f\t%f\t%f\n",root,f(root),t,acc);
	}
    else if(m==3)
	{
	  printf("Enter x:\n");
	  scanf("%f",&x);
	  root = newtonraphson(x);
	  printf("root = %f\tf(x) = %f\t%f\t%f\n",root,f(root),v,acc);
	}          
    }

}
/*Function Definitions*/
float f(float x){
    float a=1.0;
    float b=1.5;
    return (exp(a*x)-(b*x*x));

}
float g(float x){
    float a=1.0;
    float b=1.5;
    return (a*exp(a*x)-(2*b*x));
}
float bisection(float x){
    float xm,xl,xr,z;
    float xinc=0.5;

     if(f(x)*f(x+xinc)<0){
        xl=x;
        xr=x+xinc;
            do{
                xm=(xl+xr)/2.0;
                if(f(xm)*f(xl)>0){
                    xl=xm;
                    }
                else if(f(xm)*f(xl)<0){
                    xr=xm;
                    }
                z=fabs((xl-xr)/(xl+xr));
                }while(z>acc);
            }
            return xm;
        }
    float secant(float x){
        float f1,f2,x3;
        do{
            f1=f(x1);
            f2=f(x2);
            x3=((x1*f2-x2*f1)/(f2-f1));
            x1=x2;
            x2=x3;
            t=fabs(f2);
        }while(t>acc);
        return x2;


    }
    float newtonraphson(float x){
        float f3,f4;
        float h;

        do{
            f3=f(x);
            f4=g(x);
            h=-f3/f4;
            x=x+h;
            v=fabs(h/x);

        }while(v>acc);
        return x;

    }