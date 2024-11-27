/* Calculate Ncr and Npr */
#include<stdio.h>
#include<math.h>

int fact(int n);

int main(){
    int comb,perm,n=4,r=2;
    comb= fact(n)/(fact(n-r)*fact(r));
    perm= fact(n)/(fact(n-r));
    printf("%d\t%d\n", comb, perm);

}
int fact(int n){
    int i,facto=1;
    for(i=1; i<=n; i++){
        facto*=i;
    }
    return facto;
}