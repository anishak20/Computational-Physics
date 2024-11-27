/*program to find distinct set of pythagorean numbers less than 100
a^2 + b^2 = c^2 */
#include<stdio.h>
#include<math.h>

void main(){
    int n=20;
    int a,b,c,d;
    for(a=1; a<=n; a++){
        for(b=a+1; b<=n; b++){
            d= a*a + b*b;
            c= sqrt((float)(d));
            if(c*c==d && c<=n){
                printf("%d\t%d\t%d\n", a, b, c);
            }
        }
    }
}