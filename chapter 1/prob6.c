/*to calculate factorial of a given number*/
#include<stdio.h>
#include<math.h>

int fact(int n);

int main(){
    int n=6,result;
    if(n<0){
        printf("Factorial does not exist!");
    }else{
        result = fact(n);
        printf("Factorial is %d", result);
    }
    
    return 0;

}
int fact(int n){
    int i,facto=1;
    for(i=1; i<=n; i++){
        facto*=i;
    }
    return facto;
}